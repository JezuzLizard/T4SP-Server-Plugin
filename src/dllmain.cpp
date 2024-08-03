#include <stdinc.hpp>

PLUTONIUM_API plutonium::sdk::plugin* PLUTONIUM_CALLBACK on_initialize()
{
	return plugin::get();
}

BOOL APIENTRY DllMain(HMODULE /*module_*/, DWORD /*ul_reason_for_call*/, LPVOID /*reserved_*/)
{
	return TRUE;
}