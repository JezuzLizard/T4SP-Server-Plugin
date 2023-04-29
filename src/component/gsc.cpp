#include <stdinc.hpp>
#include "loader/component_loader.hpp"

#include "scheduler.hpp"

#include <json.hpp>
#include <utils/io.hpp>
#include <utils/hook.hpp>
#include <utils/string.hpp>

namespace gsc
{
	std::unordered_map<std::string, game::BuiltinFunction> functions;
	std::unordered_map<std::string, game::BuiltinMethod> methods;

	utils::hook::detour scr_getmethod_hook;
	void* scr_getfunction_stub_ret_loc;

	namespace
	{
		game::BuiltinFunction scr_getfunction_call(const char** pName, int* pType)
		{
			auto itr = functions.find(*pName);

			if (itr == functions.end())
			{
				return nullptr;
			}

			*pType = 0;
			return itr->second;
		}

		game::BuiltinFunction __declspec(naked) scr_getfunction_stub()
		{
			__asm
			{
				push eax;
				pushad;

				lea eax, [esp + 0x24 + 0x2C - 0x1C];
				push eax;
				push edx;
				call scr_getfunction_call;
				add esp, 8;
				mov [esp + 0x20], eax;

				popad;
				pop eax;

				test eax, eax;
				jnz just_ret;

				// go do original code
				push scr_getfunction_stub_ret_loc;
				ret;

			just_ret:
				add esp, 4;
				push 0x682DC8;
				ret;
			}
		}

		game::BuiltinMethod scr_getmethod_call(const char** pName, int* pType)
		{
			auto itr = methods.find(*pName);

			if (itr == methods.end())
			{
				// call og
				const auto og_addr = scr_getmethod_hook.get_original();
				game::BuiltinMethod answer;

				__asm
				{
					mov edi, pType;
					mov esi, pName;
					call og_addr;
					mov answer, eax;
				}

				return answer;
			}

			*pType = 0;
			return itr->second;
		}

		game::BuiltinMethod __declspec(naked) scr_getmethod_stub()
		{
			__asm
			{
				push edi;
				push esi;
				call scr_getmethod_call;
				add esp, 8;

				ret;
			}
		}

		int hudelem_spawned_callback_handle = 0;

		game::game_hudelem_s* hudelem_alloc_codecallback(game::game_hudelem_s* hud)
		{
			static const auto call_addr = SELECT(0x0, 0x4FA310);

			game::game_hudelem_s* answer;

			__asm
			{
				mov eax, hud;
				call call_addr;
				mov answer, eax;
			}

			if (hudelem_spawned_callback_handle)
			{
				auto id = game::Scr_ExecEntThread(game::SCRIPTINSTANCE_SERVER, hud - game::g_hudelems, hudelem_spawned_callback_handle, 0, game::CLASS_NUM_HUDELEM);
				game::RemoveRefToObject(game::SCRIPTINSTANCE_SERVER, id);
			}

			return answer;
		}
	}

	namespace function
	{
		void add(const std::string& name, const game::BuiltinFunction function)
		{
			functions.insert_or_assign(name, function);
		}
	}

	namespace method
	{
		void add(const std::string& name, const game::BuiltinMethod method)
		{
			methods.insert_or_assign(name, method);
		}
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			// custom gsc methods
			scr_getmethod_hook.create(utils::hook::get_displacement_addr(SELECT(0x0, 0x683043)), scr_getmethod_stub);
			
			// custom gsc funcs
			scr_getfunction_stub_ret_loc = utils::hook::get_displacement_addr(SELECT(0x0, 0x682D99));
			utils::hook::jump(SELECT(0x0, 0x682D99), scr_getfunction_stub);


			//Add support for codecallback_hudelemspawned GSC callback
			//utils::hook::call(0x4FA40B, hudelem_alloc_stub);
			//HudElem_Alloc_hook.create(0x4FA3E0, hudelem_alloc_stub2);
			//Handle for codecallback_hudelemspawned
			scheduler::on_postloadscripts([]()
				{
					auto found_script = game::Scr_LoadScript("scripts/sp/callbacks_ext", game::SCRIPTINSTANCE_SERVER);
					if (found_script)
					{
						hudelem_spawned_callback_handle = game::Scr_GetFunctionHandle(game::SCRIPTINSTANCE_SERVER, "scripts/sp/callbacks_ext", "codecallback_hudelemspawned");
					}
					else
					{
						printf("Couldn't load script scripts/sp/callbacks_ext.gsc\n");
					}
				});

			function::add("funny_func", []()
				{
					printf("How funny\n");
					printf("You found the funny monkey funkey\n");
				});

			method::add("is_monkey", [](game::scr_entref_s ent)
				{
					printf("Monkey number %d\n", ent.entnum);

				});

			function::add("inttest", []()
				{
					int answer = game::Scr_GetInt(game::SCRIPTINSTANCE_SERVER, 0);
					answer += 69;
					game::Scr_AddInt(game::SCRIPTINSTANCE_SERVER, answer);
				});
			function::add("floattest", []()
				{
					float answer = game::Scr_GetFloat(game::SCRIPTINSTANCE_SERVER, 0);
					answer *= 69.0f;
					game::Scr_AddFloat(game::SCRIPTINSTANCE_SERVER, answer);
				});
			function::add("stringtest", []()
				{
					char* answer = game::Scr_GetString(game::SCRIPTINSTANCE_SERVER, 0);

					std::string string(answer);

					string += " haha funny"s;
					game::Scr_AddString(game::SCRIPTINSTANCE_SERVER, string.data());
				});
			function::add("istringtest", []()
				{
					const char* answer = game::Scr_GetIString(game::SCRIPTINSTANCE_SERVER, 0);

					std::string string(answer);

					string += " haha funny"s;
					game::Scr_AddIString(game::SCRIPTINSTANCE_SERVER, string.data());
				});

			function::add("vectortest", []()
				{
					float answer[3] = {};
					game::Scr_GetVector(game::SCRIPTINSTANCE_SERVER, 0, answer);

					answer[0] += 69.0f;
					game::Scr_AddVector(game::SCRIPTINSTANCE_SERVER, answer);
				});

			function::add("undefinedtest", []()
				{
					game::Scr_AddUndefined(game::SCRIPTINSTANCE_SERVER);
				});

			function::add("pathnodetest", []()
				{
					game::pathnode_t* node = game::Scr_GetPathnode(game::SCRIPTINSTANCE_SERVER);

					game::Scr_AddPathnode(game::SCRIPTINSTANCE_SERVER, node);
				});

			function::add("numberindexedarraytest", []()
				{
					game::Scr_MakeArray(game::SCRIPTINSTANCE_SERVER);

					game::Scr_AddFloat(game::SCRIPTINSTANCE_SERVER, 69.0f);
					game::Scr_AddArray(game::SCRIPTINSTANCE_SERVER);

					game::Scr_AddInt(game::SCRIPTINSTANCE_SERVER, 420);
					game::Scr_AddArray(game::SCRIPTINSTANCE_SERVER);

					game::Scr_AddString(game::SCRIPTINSTANCE_SERVER, "ree");
					game::Scr_AddArray(game::SCRIPTINSTANCE_SERVER);
				});

			function::add("stringindexedarraytest", []()
				{
					game::Scr_MakeArray(game::SCRIPTINSTANCE_SERVER);

					std::string key1("key1");

					game::Scr_AddFloat(game::SCRIPTINSTANCE_SERVER, 69.0f);
					game::Scr_AddArrayStringIndexed(game::SCRIPTINSTANCE_SERVER, game::SL_GetStringOfSize(game::SCRIPTINSTANCE_SERVER, key1.data(), 0, key1.length() + 1));

					std::string key2("key2");

					game::Scr_AddInt(game::SCRIPTINSTANCE_SERVER, 420);
					game::Scr_AddArrayStringIndexed(game::SCRIPTINSTANCE_SERVER, game::SL_GetStringOfSize(game::SCRIPTINSTANCE_SERVER, key2.data(), 0, key2.length() + 1));

					std::string key3("key3");

					game::Scr_AddString(game::SCRIPTINSTANCE_SERVER, "ree");
					game::Scr_AddArrayStringIndexed(game::SCRIPTINSTANCE_SERVER, game::SL_GetStringOfSize(game::SCRIPTINSTANCE_SERVER, key3.data(), 0, key3.length() + 1));
				});

			method::add("entitytest", [](game::scr_entref_s ent)
				{
					if (ent.classnum != game::CLASS_NUM_ENTITY)
					{
						game::Scr_Error("Not an entity", game::SCRIPTINSTANCE_SERVER, false);
						return;
					}

					game::gentity_s* ent2 = &game::g_entities[ent.entnum];

					game::Scr_AddEntity(game::SCRIPTINSTANCE_SERVER, ent2);
				});
			
			function::add("writefile", []()
				{
					const auto path = game::Scr_GetString(game::SCRIPTINSTANCE_SERVER, 0);
					const auto data = game::Scr_GetString(game::SCRIPTINSTANCE_SERVER, 1);

					auto append = false;
					if (game::Scr_GetNumParam(game::SCRIPTINSTANCE_SERVER) > 2)
					{
						append = game::Scr_GetInt(game::SCRIPTINSTANCE_SERVER, 2);
					}

					game::Scr_AddInt(game::SCRIPTINSTANCE_SERVER, utils::io::write_file(path, data, append));
				});

			function::add("readfile", []()
				{
					const auto path = game::Scr_GetString(game::SCRIPTINSTANCE_SERVER, 0);
					game::Scr_AddString(game::SCRIPTINSTANCE_SERVER, utils::io::read_file(path).c_str());
				});
		}

	private:
	};
}

REGISTER_COMPONENT(gsc::component)

