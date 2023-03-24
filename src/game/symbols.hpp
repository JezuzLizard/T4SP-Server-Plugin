#pragma once

#define WEAK __declspec(selectany)

namespace game
{
	// Functions

	WEAK symbol<void(con_channel_e channel, const char* fmt, ...)> Com_PrintF{ 0x0, 0x59A2C0 };
	WEAK symbol<dvar_s*(const char* name, dvarType_t type, DvarFlags flags, DvarValue dval, DvarLimits dom, const char* desc)> Dvar_RegisterVariant{ 0x0, 0x5EED90 };

	// Variables

	WEAK symbol<cmd_function_s*> cmd_functions{ 0x0, 0x1F416F4 };
	WEAK symbol<CmdArgs> cmd_args{ 0x0, 0x1F41670 };

	namespace plutonium
	{
	}
}
