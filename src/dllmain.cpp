#include <stdinc.hpp>
#include "loader/component_loader.hpp"
#include "component/signatures.hpp"

#include <utils/hook.hpp>

BOOL APIENTRY DllMain(HMODULE /*module_*/, DWORD ul_reason_for_call, LPVOID /*reserved_*/)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		if (game::environment::t4sp())
		{
			if (!signatures::process())
			{
				MessageBoxA(NULL,
					"This version of t4sp-server-plugin is outdated.\n" \
					"Download the latest dll from here: https://github.com/JezuzLizard/T4SP-Server-Plugin/releases",
					"ERROR", MB_ICONERROR);

				return FALSE;
			}

			if (game::plutonium::printf.get() != nullptr)
			{
				utils::hook::jump(reinterpret_cast<uintptr_t>(&printf), game::plutonium::printf);
			}

			component_loader::post_unpack();
		}
		else
		{
			MessageBoxA(nullptr, "Unsupported game executable. (t4sp is only supported)", "ERROR, BRO!", 0);

			return FALSE;
		}
	}

	return TRUE;
}