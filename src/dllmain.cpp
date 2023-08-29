#include <stdinc.hpp>
#include "loader/component_loader.hpp"

#include <utils/hook.hpp>

BOOL APIENTRY DllMain(HMODULE /*module_*/, DWORD ul_reason_for_call, LPVOID /*reserved_*/)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		if (game::environment::t4sp())
		{
			component_loader::post_unpack();
		}
		else
		{
			// MessageBoxA(nullptr, "Unsupported game executable. (t4sp is only supported)", "ERROR, BRO!", 0);
		}
	}

	return TRUE;
}