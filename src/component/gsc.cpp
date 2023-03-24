#include <stdinc.hpp>
#include "loader/component_loader.hpp"

#include <json.hpp>
#include <utils/io.hpp>
#include <utils/hook.hpp>

namespace gsc
{
	std::unordered_map<unsigned int, std::pair<std::string, void*>> functions;

	namespace
	{
		void* original_scr_get_gsc_funcs_jump_loc;

		void* original_scr_get_method_funcs_call_loc;

		void ebic_func()
		{
			game::Com_PrintF(game::CON_CHANNEL_SERVER, "Oof \n");
		}

		game::BuiltinFunction plutonium_scr_get_gsc_funcs_stub(const char** pName, int* type)
		{
			//printf( "%s %d\n", * pName, * type);
			/*
			if (*pName == "isdefined"s)
			{
				return &ebic_func;
			}
			*/
			return 0;
		}

		game::BuiltinMethod plutonium_scr_get_gsc_methods_stub(const char** pName, int* type)
		{
			printf("%s %d\n", *pName, *type);
			/*
			if (*pName == "isdefined"s)
			{
				return &ebic_func;
			}
			*/
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
				call plutonium_scr_get_gsc_funcs_stub;
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
				call plutonium_scr_get_gsc_methods_stub;
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

	unsigned int find_function(const std::string& name)
	{
		for (const auto& function : functions)
		{
			if (function.second.first == name)
			{
				return function.first;
			}
		}

		return 0;
	}

	namespace function
	{
		void add(const std::string& name, const void*& function)
		{
			const auto id = functions.size() + 1;
			//functions[id] = std::make_pair(name, function);
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
		}

	private:
	};
}

REGISTER_COMPONENT(gsc::component)

