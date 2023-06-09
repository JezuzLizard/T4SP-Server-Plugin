#include <stdinc.hpp>
#include "loader/component_loader.hpp"

#include "scheduler.hpp"
#include "gsc.hpp"

#include <utils/io.hpp>
#include <utils/hook.hpp>
#include <utils/string.hpp>

namespace test
{
	utils::hook::detour gscr_spawn_hook;

	// a __usercall detour! :o
	utils::hook::detour scr_getentityid_hook;

	utils::hook::detour sv_clientthink_hook;

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

		unsigned int scr_getentityid_call(unsigned int entnum, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, game::classNum_e classnum, unsigned int clientnum)
		{
			// minhook allocated space for the original asm, we want to execute that instead because the original gamecode has the jump from the detour
			return game::Scr_GetEntityId(inst, entnum, classnum, clientnum, scr_getentityid_hook.get_original());
		}

		unsigned int __declspec(naked) scr_getentityid_stub()
		{
			// 00692520 unsigned int __usercall Scr_GetEntityId@<eax>(unsigned int entnum@<eax>, scriptInstance_t inst, classNum_e classnum, unsigned int clientnum)
			__asm
			{
				// eax is a param, lets push it!
				push eax;

				// ok so scr_getentityid_call intentionally has more params than it should, so we can access everything on the stack
				call scr_getentityid_call;

				// clean up and return
				add esp, 4;
				ret;
			}
		}

		void sv_clientthink_call(game::client_s* client, [[maybe_unused]] void* caller_addr, game::usercmd_s* cmd)
		{
			const auto og_addr = sv_clientthink_hook.get_original();

			if (client->bIsTestClient && client->gentity && client->gentity->client)
			{
				auto gclient = client->gentity->client;
				
				cmd->wiimoteGunPitch = static_cast<unsigned short>((gclient->ps.viewangles[0]) * (65536 / 360.f)) & 0xFFFF;
				cmd->wiimoteGunYaw = static_cast<unsigned short>((gclient->ps.viewangles[1]) * (65536 / 360.f)) & 0xFFFF;
			}

			__asm
			{
				push cmd;
				mov eax, client; 
				call og_addr;
				add esp, 0x4;
			}
		}

		void __declspec(naked) sv_clientthink_stub()
		{
			__asm
			{
				push eax;

				call sv_clientthink_call;

				add esp, 0x4;

				ret;
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

			gsc::function::add("getarraytest", []()
				{
					auto parent_id = game::Scr_GetObject(0, game::SCRIPTINSTANCE_SERVER).pointerValue;

					auto script_array_size = GetArraySize(game::SCRIPTINSTANCE_SERVER, parent_id);
					for (auto i = 0u; i < script_array_size; ++i)
					{
						auto id = game::GetArrayVariable(game::SCRIPTINSTANCE_SERVER, parent_id, i);
						auto entry_value = &game::gScrVarGlob[0].childVariables[id];
						if ((entry_value->w.type & 0x1F) != game::VAR_STRING)
						{
							game::Scr_Error(utils::string::va("index %d in array is not a string", i), game::SCRIPTINSTANCE_SERVER, false);
						}
						printf("%s\n", game::SL_ConvertToString(game::SCRIPTINSTANCE_SERVER, entry_value->u.u.stringValue));
					}
				});

			gscr_spawn_hook.create(0x517630, gscr_spawn_stub);

			//Disable AI print spam
			utils::hook::nop(0x4BAB7D, 5);
			utils::hook::nop(0x4BAAFA, 5);

			//Disable asset loading print spam
			utils::hook::nop(0x48D9D9, 5);

			//Disable unknown dvar spam
			utils::hook::nop(0x5F04AF, 5);

			// fix NEGOTIATION links
			//utils::hook::jump(0x4D3296, our_funny_hook);

			// test usercall detour!
			scr_getentityid_hook.create(game::Scr_GetEntityId(), scr_getentityid_stub);
			// scr_getentityid_hook.create(game::SL_GetStringOfSize.get(), sl_getstringofsize_stub);

			sv_clientthink_hook.create(0x630BF0, sv_clientthink_stub);
		}

	private:
	};
}

REGISTER_COMPONENT(test::component)
