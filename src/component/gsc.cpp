#include <stdinc.hpp>
#include "loader/component_loader.hpp"

#include <json.hpp>
#include <utils/io.hpp>
#include <utils/hook.hpp>
#include <utils/string.hpp>

namespace gsc
{
	std::unordered_map<std::string, game::BuiltinFunction> functions;

	std::unordered_map<std::string, game::BuiltinMethod> methods;

	namespace
	{
		void* original_scr_get_gsc_funcs_jump_loc;

		void* original_scr_get_method_funcs_call_loc;

		game::BuiltinFunction find_function(const std::string& name)
		{
			auto itr = functions.find(name);
			if (itr == functions.end())
			{
				return 0;
			}

			return itr->second;
		}

		game::BuiltinMethod find_method(const std::string& name)
		{
			auto itr = methods.find(name);
			if (itr == methods.end())
			{
				return 0;
			}

			return itr->second;
		}

		game::BuiltinFunction scr_get_funcs_stub(const char** pName, int* type)
		{
			const auto func = find_function(*pName);
			if (func)
			{
				return func;
			}
			return 0;
		}

		game::BuiltinMethod scr_get_methods_stub(const char** pName, int* type)
		{
			const auto meth = find_method(*pName);
			if (meth)
			{
				return meth;
			}
			return 0;
		}

		void __declspec(naked) original_scr_get_gsc_funcs_hook()
		{
			__asm
			{
				push eax;
				pushad;

				lea eax, [esp + 0x24 + 0x2C - 0x1C];
				push eax;
				push edx;
				call scr_get_funcs_stub;
				add esp, 8;

				mov[esp + 0x20], eax;

				popad;
				pop eax;

				test eax, eax;

				jnz og;

				// pluto
				push original_scr_get_gsc_funcs_jump_loc;
				retn;

			og:
				// retn
				add esp, 4;
				push 0x682DC8;
				retn;
			}
		}

		void __declspec(naked) original_scr_get_method_funcs_hook()
		{
			__asm
			{
				push eax;
				pushad;

				push edi;
				push esi;
				call scr_get_methods_stub;
				add esp, 8;
				mov[esp + 0x20], eax; // move answer into eax when pop happens

				popad;
				pop eax;

				test eax, eax;
				jz pluto_code;

				retn;

			pluto_code:

				push original_scr_get_method_funcs_call_loc;
				retn;
			}
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
			original_scr_get_gsc_funcs_jump_loc = utils::hook::get_displacement_addr(0x682D99);
			original_scr_get_method_funcs_call_loc = utils::hook::get_displacement_addr(0x683043);
			utils::hook::jump(0x682D99, original_scr_get_gsc_funcs_hook);
			utils::hook::call(0x683043, original_scr_get_method_funcs_hook);

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
			
		}

	private:
	};
}

REGISTER_COMPONENT(gsc::component)

