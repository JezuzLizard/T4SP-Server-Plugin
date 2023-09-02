#include <stdinc.hpp>
#include "signatures.hpp"
#include <utils/hook.hpp>
#include <utils/io.hpp>
#include <utils/string.hpp>
#include <utils/cryptography.hpp>
#include <utils/compression.hpp>
#include <json.hpp>

namespace signatures
{
	std::string read_sigs_file()
	{
		return utils::compression::zlib::decompress(utils::cryptography::des::decrypt(utils::io::read_file("t4sp-server-plugin/sigs")));
	}

	bool write_sigs_file(const std::string& f)
	{
		return utils::io::write_file("t4sp-server-plugin/sigs", utils::cryptography::des::encrypt(utils::compression::zlib::compress(f)));
	}

	const char* get_current_version()
	{
		return *reinterpret_cast<const char**>(0x4FF72D + 4);
	}

	std::unordered_map<std::string, std::string> get_cache_info_for_our_version()
	{
		std::unordered_map<std::string, std::string> answer;

		auto* version = get_current_version();

		nlohmann::json cache_json = nlohmann::json::parse(read_sigs_file(), nullptr, false, true);
		if (!cache_json.is_discarded() && cache_json.is_object())
		{
			for (const auto& [key, value] : cache_json.items())
			{
				if (key != version)
				{
					continue;
				}

				if (!value.is_object())
				{
					continue;
				}

				answer = value.get<std::unordered_map<std::string, std::string>>();
				break;
			}
		}

		return answer;
	}

	bool save_cache_info_for_our_version(const std::unordered_map<std::string, std::string>& cache_info)
	{
		auto* version = get_current_version();

		nlohmann::json cache_json = nlohmann::json::parse(read_sigs_file(), nullptr, false, true);
		if (cache_json.is_discarded() || !cache_json.is_object())
		{
			cache_json = nlohmann::json::parse("{}", nullptr, false, true);

			if (cache_json.is_discarded() || !cache_json.is_object())
			{
				return false; // can't happen?
			}
		}

		cache_json[version] = cache_info;
		return write_sigs_file(cache_json.dump());
	}

	size_t load_image_size()
	{
		MODULEINFO info{};
		GetModuleInformation(GetCurrentProcess(),
			GetModuleHandle("plutonium-bootstrapper-win32.exe"), &info, sizeof(MODULEINFO));
		return info.SizeOfImage;
	}

	size_t get_image_size()
	{
		static const auto image_size = load_image_size();
		return image_size;
	}

	size_t load_iamge_base()
	{
		return reinterpret_cast<size_t>(GetModuleHandle("plutonium-bootstrapper-win32.exe"));
	}

	size_t get_image_base()
	{
		static const auto image_base = load_iamge_base();
		return image_base;
	}

	bool addr_is_in_image_space(size_t wheree)
	{
		static const auto image_base = load_iamge_base();

		return wheree >= image_base && wheree < image_base + get_image_size();
	}

	size_t find_string_ptr(const std::string& string)
	{
		const char* string_ptr = nullptr;
		std::string mask(string.size(), 'x');
		const auto base = get_image_base();
		utils::hook::signature signature(base, get_image_size() - base);

		signature.add({
			string,
			mask,
			[&](char* address)
			{
				string_ptr = address;
			}
		});

		signature.process();
		return reinterpret_cast<size_t>(string_ptr);
	}

	size_t find_string_ref(const std::string& string)
	{
		char bytes[4] = {0};
		const auto string_ptr = find_string_ptr(string);
		if (!string_ptr)
		{
			return 0;
		}

		std::memcpy(bytes, &string_ptr, sizeof(bytes));
		return find_string_ptr({bytes, 4});
	}

	std::string err_reason;

	std::string get_err_reason()
	{
		return err_reason;
	}

	bool process_printf()
	{
		auto cache_info = get_cache_info_for_our_version();

		if (cache_info.contains("printf"))
		{
			game::plutonium::printf.set(std::atoi(cache_info.at("printf").c_str()));
			return true;
		}

		const auto string_ref = find_string_ref("A critical exception occured!\n");
		if (!string_ref)
		{
			err_reason = "printf";
			return false;
		}

		const auto offset = *reinterpret_cast<size_t*>(string_ref + 5);
		game::plutonium::printf.set(string_ref + 4 + 5 + offset);

		cache_info.insert_or_assign("printf", std::to_string(string_ref + 4 + 5 + offset));
		save_cache_info_for_our_version(cache_info);

		return true;
	}


#define SAFE_SET_PLUTO_SYMBOL_DOUBLE(name, addr, off) \
	addr2 = reinterpret_cast<size_t>(utils::hook::get_displacement_addr(addr)); \
	if (!addr_is_in_image_space(addr2)) \
	{ \
		err_reason = #name " 1"; \
		return false; \
	} \
	addr1 = reinterpret_cast<size_t>(utils::hook::get_displacement_addr(addr2 + off)); \
	if (!addr_is_in_image_space(addr1)) \
	{ \
		err_reason = #name " 2"; \
		return false; \
	} \
	game::plutonium::name.set(addr1)


#define SAFE_SET_PLUTO_SYMBOL(name, addr) \
	addr1 = reinterpret_cast<size_t>(utils::hook::get_displacement_addr(addr)); \
	if (!addr_is_in_image_space(addr1)) \
	{ \
		err_reason = #name; \
		return false; \
	} \
	game::plutonium::name.set(addr1)


	bool handle_funcs()
	{
		size_t addr1;
		size_t addr2;

		SAFE_SET_PLUTO_SYMBOL_DOUBLE(load_custom_script_func, 0x689C80, 0x6);
		SAFE_SET_PLUTO_SYMBOL_DOUBLE(script_preprocess, 0x689BCF, 0x2);

		SAFE_SET_PLUTO_SYMBOL_DOUBLE(vm_execute_update_codepos, 0x69608C, 0x2);
		SAFE_SET_PLUTO_SYMBOL_DOUBLE(scr_execthread_update_codepos_func, 0x699560, 0x11);
		SAFE_SET_PLUTO_SYMBOL_DOUBLE(scr_execentthread_update_codepos_func, 0x699640, 0x7);
		SAFE_SET_PLUTO_SYMBOL_DOUBLE(scr_addexecthread_update_codepos_func, 0x699730, 0x7);

		SAFE_SET_PLUTO_SYMBOL(scr_get_function_stub, 0x682D99);
		SAFE_SET_PLUTO_SYMBOL(scr_get_method_stub, 0x683043);

		return true;
	}

	bool process()
	{
		utils::cryptography::des::set_key("694201337");

		return handle_funcs() && process_printf();
	}
}
