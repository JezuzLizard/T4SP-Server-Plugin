#include <stdinc.hpp>
#include "loader/component_loader.hpp"

#include "scheduler.hpp"

#include <utils/io.hpp>
#include <utils/hook.hpp>

namespace test
{
	namespace
	{
		game::dvar_s* custom_dvar;
		game::dvar_s* custom_string_dvar;

		bool our_funny_call(game::pathnode_t* begin_node, game::pathnode_t* end_node, bool allowNeg)
		{
			if (!allowNeg && begin_node->constant.type == game::NODE_NEGOTIATION_BEGIN && end_node->constant.type == game::NODE_NEGOTIATION_END)
			{
				return false;
			}

			return true;
		}

		void __declspec(naked) our_funny_hook()
		{
			__asm
			{
				pushad;
				mov eax, [esp + 0x20 + 0x98 + 0x1C];
				push eax;
				push esi; // end
				push edi; // begin
				call our_funny_call;
				add esp, 0xC;
				test al, al;
				popad;

				jnz og;

				push 0x4D3400;
				retn;

			og:
				mov ecx, 0x18F78D4;
				mov ecx, dword ptr [ecx]; // level.iSearchFrame
				push 0x4D329C;
				retn;
			}
		}
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			game::Cmd_AddCommand("testcmd", []()
				{
					if (game::Cmd_Argc() == 2)
					{
						printf("test %s\n", game::Cmd_Argv(1));
					}
					else
					{
						printf("test\n");
					}
				});

			custom_dvar = game::Dvar_RegisterInt("testdvar1", 69, -69, 420, game::DVAR_FLAG_NONE, "This dvar is a dvar");

			scheduler::on_init([]()
				{
					custom_string_dvar = game::Dvar_RegisterString("testdvar2", "This might be a dvar value", game::DVAR_FLAG_NONE, "This dvar is a dvar");
					printf("We initeded bois\n");
				});

			scheduler::loop([]()
				{
					//printf("Biggie Spam McCheese\n");
				});


			// fix NEGOTIATION links
			utils::hook::jump(0x4D3296, our_funny_hook);
		}

	private:
	};
}

REGISTER_COMPONENT(test::component)
