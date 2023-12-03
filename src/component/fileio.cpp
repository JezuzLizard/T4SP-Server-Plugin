#include <stdinc.hpp>
#include "loader/component_loader.hpp"
#include "gsc.hpp"
#include "scheduler.hpp"
#include <utils/memory.hpp>
#include <utils/string.hpp>

namespace fileio
{
	namespace
	{
		static constexpr size_t max_fhs = 10;
		static constexpr size_t max_gsc_string = 0x10000 - 1;

		enum class scr_fh_type_e
		{
			UNUSED,
			READ,
			WRITE,
			APPEND
		};

		struct scr_fh_t
		{
			scr_fh_type_e type;
			std::unique_ptr<char[]> file_buff;
			int file_length;
			int seek;
			std::filesystem::path full_path;
			std::string base_path;
		};

		std::array<scr_fh_t, max_fhs> scr_fhs = {};

		bool validate_scr_path(const std::string& fpath)
		{
			if (fpath.empty())
			{
				return false;
			}

			constexpr static std::array bad_strings { R"(..)", R"(../)", R"(..\)" };
			for (auto i = 0u; i < bad_strings.size(); i++)
			{
				if (fpath.find(bad_strings[i]) != std::string::npos)
				{
					return false;
				}
			}

			return true;
		}

		std::string build_base_path(const std::string& path)
		{
			if (!validate_scr_path(path))
			{
				game::Scr_Error(utils::string::va("Invalid path: %s", path.c_str()), game::SCRIPTINSTANCE_SERVER, false);
			}

			return path.starts_with("scriptdata/") ? path : "scriptdata/" + path;
		}

		std::filesystem::path build_full_path(const std::string& path)
		{
			static game::dvar_s* fs_localAppData = nullptr;
			static game::dvar_s* fs_gamedir = nullptr;

			if (!fs_localAppData)
			{
				fs_localAppData = game::Dvar_FindVar("fs_localAppData");
			}

			if (!fs_gamedir)
			{
				fs_gamedir = game::Dvar_FindVar("fs_game");
			}

			return std::filesystem::path(fs_localAppData->current.string) / (*fs_gamedir->current.string ? fs_gamedir->current.string : "raw") / path;
		}

		void free_scr_fh(scr_fh_t& scr_fh)
		{
#ifdef DEBUG
			printf("free_scr_fh: closing %s\n", scr_fh.base_path.c_str());
#endif

			scr_fh = {};
			scr_fh.type = scr_fh_type_e::UNUSED;
		}

		void close_all_scr_fh()
		{
			for (auto& fh : scr_fhs)
			{
				if (fh.type == scr_fh_type_e::UNUSED)
				{
					continue;
				}

				free_scr_fh(fh);
			}
		}

		void fwrite_to_file(bool append_newline)
		{
			auto fh = game::Scr_GetInt(game::SCRIPTINSTANCE_SERVER, 0) - 1;

			if (fh < 0 || fh >= max_fhs)
			{
				game::Scr_Error("fs_fwrite: invalid filehandle", game::SCRIPTINSTANCE_SERVER, false);
			}

			if (scr_fhs[fh].type != scr_fh_type_e::WRITE && scr_fhs[fh].type != scr_fh_type_e::APPEND)
			{
				game::Scr_Error("File not opened for writing", game::SCRIPTINSTANCE_SERVER, false);
			}

			std::string to_write = game::Scr_GetString(1, game::SCRIPTINSTANCE_SERVER);
			if (append_newline)
			{
				to_write += '\n';
			}

			if (!utils::io::write_file(scr_fhs[fh].full_path.string(), to_write, true))
			{
				game::Com_PrintWarning(game::CON_CHANNEL_SCRIPT, "Failed to write file: %s\n", scr_fhs[fh].base_path.c_str());
				game::Scr_AddInt(game::SCRIPTINSTANCE_SERVER, 0);
				return;
			}

			game::Scr_AddInt(game::SCRIPTINSTANCE_SERVER, 1);
		}

		void add_file_io()
		{
			scheduler::on_pre_scr_init_system([]([[maybe_unused]] game::scriptInstance_t inst)
				{
					if (inst != game::SCRIPTINSTANCE_SERVER)
					{
						return;
					}

					close_all_scr_fh();
				});

			gsc::function::add("fs_testfile", []()
				{
					auto fpath = build_base_path(game::Scr_GetString(0, game::SCRIPTINSTANCE_SERVER));

					auto fd = 0;
					auto file_length = game::FS_FOpenFileRead(fpath.c_str(), &fd);

					if (!fd || file_length < 0)
					{
						game::Scr_AddInt(game::SCRIPTINSTANCE_SERVER, 0);
						return;
					}

					game::FS_FCloseFile(fd);
					game::Scr_AddInt(game::SCRIPTINSTANCE_SERVER, 1);
				});

			gsc::function::add("fs_fopen", []()
				{
					auto fpath = build_base_path(game::Scr_GetString(0, game::SCRIPTINSTANCE_SERVER));

					// check for dupes
					for (const auto& scr_fd : scr_fhs)
					{
						if (scr_fd.type != scr_fh_type_e::UNUSED && scr_fd.base_path == fpath)
						{
							game::Scr_Error("File already opened", game::SCRIPTINSTANCE_SERVER, false);
						}
					}

					// check for avail slot
					auto i = 0;
					for (; i < max_fhs; i++)
					{
						if (scr_fhs[i].type == scr_fh_type_e::UNUSED)
						{
							break;
						}
					}

					if (i >= max_fhs)
					{
						game::Scr_Error("Too many files opened", game::SCRIPTINSTANCE_SERVER, false);
					}

					// check mode
					auto mode = game::Scr_GetString(1, game::SCRIPTINSTANCE_SERVER);
					if (mode == "read"s)
					{
						auto fd = 0;
						auto file_length = game::FS_FOpenFileRead(fpath.c_str(), &fd);

						if (!fd || file_length < 0)
						{
							game::Com_PrintWarning(game::CON_CHANNEL_SCRIPT, "Failed to open file for reading: %s\n", fpath.c_str());
							game::Scr_AddInt(game::SCRIPTINSTANCE_SERVER, 0);
							return;
						}

						scr_fhs[i].file_buff = std::make_unique<char[]>(file_length + 1);
						auto bytes_read = game::FS_Read(scr_fhs[i].file_buff.get(), file_length, fd);
						scr_fhs[i].file_buff[file_length] = '\0';
						game::FS_FCloseFile(fd);

						assert(bytes_read == file_length);

						if (bytes_read < 0)
						{
							scr_fhs[i].file_buff = {};
							game::Com_PrintWarning(game::CON_CHANNEL_SCRIPT, "Failed to read file: %s\n", fpath.c_str());
							game::Scr_AddInt(game::SCRIPTINSTANCE_SERVER, 0);
							return;
						}

						scr_fhs[i].type = scr_fh_type_e::READ;
						scr_fhs[i].file_length = bytes_read;
						scr_fhs[i].seek = 0;
						scr_fhs[i].base_path = fpath;
					}
					else if (mode == "write"s || mode == "append"s)
					{
						auto full_path = build_full_path(fpath);

						if (!utils::io::write_file(full_path.string(), "", (mode == "append"s)))
						{
							game::Com_PrintWarning(game::CON_CHANNEL_SCRIPT, "Failed to open file for writing: %s\n", fpath.c_str());
							game::Scr_AddInt(game::SCRIPTINSTANCE_SERVER, 0);
							return;
						}

						scr_fhs[i].type = scr_fh_type_e::WRITE;
						scr_fhs[i].base_path = fpath;
						scr_fhs[i].full_path = full_path;
					}
					else
					{
						game::Scr_Error(utils::string::va("Invalid mode: %s", mode), game::SCRIPTINSTANCE_SERVER, false);
					}

#ifdef DEBUG
					printf("gscr_fs_fopen: opening %s, mode %s\n", fpath.c_str(), mode);
#endif
					game::Scr_AddInt(game::SCRIPTINSTANCE_SERVER, i + 1);
				});

			gsc::function::add("fs_write", []()
				{
					fwrite_to_file(false);
				});

			gsc::function::add("fs_writeline", []()
				{
					fwrite_to_file(true);
				});

			gsc::function::add("fs_readline", []()
				{
					auto fh = game::Scr_GetInt(game::SCRIPTINSTANCE_SERVER, 0) - 1;

					if (fh < 0 || fh >= max_fhs)
					{
						game::Scr_Error("Invalid filehandle", game::SCRIPTINSTANCE_SERVER, false);
					}

					if (scr_fhs[fh].type != scr_fh_type_e::READ)
					{
						game::Scr_Error("File not opened for reading", game::SCRIPTINSTANCE_SERVER, false);
					}

					// file is completed being read
					if (scr_fhs[fh].seek >= scr_fhs[fh].file_length)
					{
						game::Scr_AddUndefined(game::SCRIPTINSTANCE_SERVER);
						return;
					}

					// count how many bytes until the newline
					auto bytes_to_read = 0;
					auto found_nl = false;

					for (auto i = scr_fhs[fh].seek; i < scr_fhs[fh].file_length; bytes_to_read++, i++)
					{
						if (scr_fhs[fh].file_buff[i] == '\n')
						{
							bytes_to_read++;
							found_nl = true;
							break;
						}
					}

					if (bytes_to_read > max_gsc_string)
					{
						found_nl = false;
						bytes_to_read = max_gsc_string;

						game::Com_PrintWarning(game::CON_CHANNEL_SCRIPT, "Line was too long in file %s, truncating\n", scr_fhs[fh].base_path.c_str());
					}

					auto scr_str = std::string(&scr_fhs[fh].file_buff[scr_fhs[fh].seek], bytes_to_read);
					scr_fhs[fh].seek += bytes_to_read;

					// remove all '\r'
					scr_str.erase(std::remove(scr_str.begin(), scr_str.end(), '\r'), scr_str.end());

					// chop the newline char off
					if (found_nl)
					{
						scr_str.pop_back();
					}

					game::Scr_AddString(game::SCRIPTINSTANCE_SERVER, scr_str.c_str());
				});

			gsc::function::add("fs_read", []()
				{
					auto fh = game::Scr_GetInt(game::SCRIPTINSTANCE_SERVER, 0) - 1;

					if (fh < 0 || fh >= max_fhs)
					{
						game::Scr_Error("Invalid filehandle", game::SCRIPTINSTANCE_SERVER, false);
					}

					if (scr_fhs[fh].type != scr_fh_type_e::READ)
					{
						game::Scr_Error("File not opened for reading", game::SCRIPTINSTANCE_SERVER, false);
					}

					// file is completed being read
					if (scr_fhs[fh].seek >= scr_fhs[fh].file_length)
					{
						game::Scr_AddUndefined(game::SCRIPTINSTANCE_SERVER);
						return;
					}

					auto bytes_to_read = scr_fhs[fh].file_length - scr_fhs[fh].seek;
					if (game::Scr_GetNumParam(game::SCRIPTINSTANCE_SERVER) >= 2)
					{
						bytes_to_read = std::clamp(game::Scr_GetInt(game::SCRIPTINSTANCE_SERVER, 1), 0, bytes_to_read);

						if (bytes_to_read <= 0)
						{
							game::Scr_Error("Trying to read <1 bytes", game::SCRIPTINSTANCE_SERVER, false);
						}
					}

					if (bytes_to_read > max_gsc_string)
					{
						bytes_to_read = max_gsc_string;

						game::Com_PrintWarning(game::CON_CHANNEL_SCRIPT, "Line was too long in file %s, truncating\n", scr_fhs[fh].base_path.c_str());
					}

					auto scr_str = std::string(&scr_fhs[fh].file_buff[scr_fhs[fh].seek], bytes_to_read);
					scr_fhs[fh].seek += bytes_to_read;

					game::Scr_AddString(game::SCRIPTINSTANCE_SERVER, scr_str.c_str());
				});

			gsc::function::add("fs_fcloseall", []()
				{
					close_all_scr_fh();
					game::Scr_AddInt(game::SCRIPTINSTANCE_SERVER, 1);
				});

			gsc::function::add("fs_fclose", []()
				{
					auto fh = game::Scr_GetInt(game::SCRIPTINSTANCE_SERVER, 0) - 1;

					if (fh < 0 || fh >= max_fhs)
					{
						game::Scr_Error("Invalid filehandle", game::SCRIPTINSTANCE_SERVER, false);
					}

					if (scr_fhs[fh].type == scr_fh_type_e::UNUSED)
					{
						game::Scr_Error("File not opened", game::SCRIPTINSTANCE_SERVER, false);
					}

					free_scr_fh(scr_fhs[fh]);

					game::Scr_AddInt(game::SCRIPTINSTANCE_SERVER, 1);
				});

			gsc::function::add("fs_remove", []()
				{
					auto fpath = build_base_path(game::Scr_GetString(0, game::SCRIPTINSTANCE_SERVER));
					auto full_path = build_full_path(fpath);

					if (!utils::io::remove_file(full_path.string()))
					{
						game::Com_PrintWarning(game::CON_CHANNEL_SCRIPT, "Failed to delete file: %s\n", fpath.c_str());
						game::Scr_AddInt(game::SCRIPTINSTANCE_SERVER, 0);
						return;
					}

					game::Scr_AddInt(game::SCRIPTINSTANCE_SERVER, 1);
				});

			gsc::function::add("fs_listfiles", []()
				{
					auto fpath = build_base_path(game::Scr_GetString(0, game::SCRIPTINSTANCE_SERVER));

					int numfiles;
					auto* files = game::FS_ListFiles(fpath.c_str(), "", game::FS_LIST_ALL, &numfiles);

					game::Scr_MakeArray(game::SCRIPTINSTANCE_SERVER);
					for (int i = 0; i < numfiles; i++)
					{
						game::Scr_AddString(game::SCRIPTINSTANCE_SERVER, files[i]);
						game::Scr_AddArray(game::SCRIPTINSTANCE_SERVER);
					}

					game::FS_FreeFileList(files);
				});
		}
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			add_file_io();
		}

	private:
	};
}

REGISTER_COMPONENT(fileio::component)

