#include <stdinc.hpp>
#include "loader/component_loader.hpp"

#include "scheduler.hpp"

#include <utils/io.hpp>
#include <utils/hook.hpp>
#include <utils/string.hpp>

namespace test
{
	utils::hook::detour gscr_spawn_hook;

	namespace
	{
		game::dvar_s* custom_dvar;
		game::dvar_s* custom_string_dvar;

		void print_script_callstack(const char* msg, game::scriptInstance_t inst)
		{
			int i; // [esp+4h] [ebp-4h]
			printf("******* Callstack for %s *******\n", msg);
			game::Scr_PrintPrevCodePos(game::function_stack[inst].pos, inst, game::CON_CHANNEL_DONT_FILTER, 0);
			auto function_count = game::gScrVmPub[inst].function_count;
			if (function_count)
			{
				for (i = function_count - 1; i >= 1; --i)
				{
					printf("Info: called from:\n");
					game::Scr_PrintPrevCodePos(
						game::gScrVmPub[inst].function_frame_start[i].fs.pos,
						inst,
						game::CON_CHANNEL_DONT_FILTER,
						game::gScrVmPub[inst].function_frame_start[i].fs.localId == 0);
				}
				printf("started from:\n");
				game::Scr_PrintPrevCodePos(game::gScrVmPub[inst].function_frame_start[0].fs.pos, inst, game::CON_CHANNEL_DONT_FILTER, 1u);
			}
			printf("************************************\n");
		}

		void gscr_spawn_stub()
		{
			auto classname = game::Scr_GetConstString(game::SCRIPTINSTANCE_SERVER, 0);

			float origin[3] = {};

			game::Scr_GetVector(game::SCRIPTINSTANCE_SERVER, 1, origin);

			if (classname == game::scr_const->script_origin)
			{
				print_script_callstack(utils::string::va("GScr_Spawn() classname: script_origin at: (%f, %f, %f)", origin[0], origin[1], origin[2]), game::SCRIPTINSTANCE_SERVER);
			}

			gscr_spawn_hook.invoke<void>();
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

			gscr_spawn_hook.create(0x517630, gscr_spawn_stub);

			//Disable AI print spam
			utils::hook::nop(0x4BAB7D, 5);
			utils::hook::nop(0x4BAAFA, 5);

			//Disable asset loading print spam
			utils::hook::nop(0x48D9D9, 5);

			//Disable unknown dvar spam
			utils::hook::nop(0x5F04AF, 5);
		}

	private:
	};
}

REGISTER_COMPONENT(test::component)
