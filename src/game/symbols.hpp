#pragma once

namespace game
{
	// Functions
	WEAK symbol<void(con_channel_e channel, const char* fmt, ...)> Com_Printf{ 0x0, 0x59A2C0 };

	// Variables
	WEAK symbol<char> tempServerCommandBuf{ 0x0, 0x2FCDC00 };

	namespace plutonium
	{
		WEAK symbol<int(const char* fmt, ...)> printf{0x0, 0x0};

		WEAK symbol<void(game::scriptInstance_t)> load_custom_script_func{0x0, 0x0};
	}
}
