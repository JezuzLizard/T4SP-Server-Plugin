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

		game::BuiltinFunction NAKED scr_getfunction_stub()
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

		game::BuiltinMethod NAKED scr_getmethod_stub()
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
		}

	private:
	};
}

REGISTER_COMPONENT(gsc::component)

