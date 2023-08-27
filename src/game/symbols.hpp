#pragma once

#define WEAK __declspec(selectany)
#define NAKED __declspec(naked)

namespace game
{
	// Functions
	WEAK symbol<void(con_channel_e channel, const char* fmt, ...)> Com_Printf{ 0x0, 0x59A2C0 };

	// Variables
	WEAK symbol<char> tempServerCommandBuf{ 0x0, 0x2FCDC00 };

	namespace plutonium
	{
	}
}
