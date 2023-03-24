#pragma once

#define WEAK __declspec(selectany)

namespace game
{
	// Functions

	// Variables

	namespace plutonium
	{
		WEAK symbol<int(const char* fmt, ...)> printf{0, 0};
	}
}
