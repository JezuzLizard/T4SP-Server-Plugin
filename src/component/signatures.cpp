#include <stdinc.hpp>
#include "signatures.hpp"
#include <utils/hook.hpp>
#include <utils/io.hpp>
#include <utils/string.hpp>
#include <utils/cryptography.hpp>
#include <utils/compression.hpp>
#include <json.hpp>

namespace signatures
{
	bool addr_is_in_image_space_of_pluto(size_t wheree)
	{
		MODULEINFO info{};
		GetModuleInformation(GetCurrentProcess(),
			GetModuleHandle("plutonium-bootstrapper-win32.exe"), &info, sizeof(MODULEINFO));

		static const auto image_base = reinterpret_cast<size_t>(GetModuleHandle("plutonium-bootstrapper-win32.exe"));

		return wheree >= image_base && wheree < image_base + info.SizeOfImage;
	}

	std::string err_reason;
	const std::string& get_err_reason()
	{
		return err_reason;
	}

#define SAFE_SET_PLUTO_SYMBOL_DOUBLE(name, addr, off) \
	addr2 = reinterpret_cast<size_t>(utils::hook::get_displacement_addr(addr)); \
	if (!addr_is_in_image_space_of_pluto(addr2)) \
	{ \
		err_reason = #name " 1"; \
		return false; \
	} \
	addr1 = reinterpret_cast<size_t>(utils::hook::get_displacement_addr(addr2 + off)); \
	if (!addr_is_in_image_space_of_pluto(addr1)) \
	{ \
		err_reason = #name " 2"; \
		return false; \
	} \
	game::plutonium::name.set(addr1)


#define SAFE_SET_PLUTO_SYMBOL(name, addr) \
	addr1 = reinterpret_cast<size_t>(utils::hook::get_displacement_addr(addr)); \
	if (!addr_is_in_image_space_of_pluto(addr1)) \
	{ \
		err_reason = #name; \
		return false; \
	} \
	game::plutonium::name.set(addr1)


	bool handle_funcs()
	{
		size_t addr1;
		size_t addr2;

		SAFE_SET_PLUTO_SYMBOL_DOUBLE(load_custom_script_func, 0x689C80, 0x6);
		SAFE_SET_PLUTO_SYMBOL_DOUBLE(script_preprocess, 0x689BCF, 0x2);

		SAFE_SET_PLUTO_SYMBOL_DOUBLE(vm_execute_update_codepos, 0x69608C, 0x2);
		SAFE_SET_PLUTO_SYMBOL_DOUBLE(scr_execthread_update_codepos_func, 0x699560, 0x11);
		SAFE_SET_PLUTO_SYMBOL_DOUBLE(scr_execentthread_update_codepos_func, 0x699640, 0x7);
		SAFE_SET_PLUTO_SYMBOL_DOUBLE(scr_addexecthread_update_codepos_func, 0x699730, 0x7);
		SAFE_SET_PLUTO_SYMBOL_DOUBLE(at_codepose_va, 0x68B3A5, 0xA);
		SAFE_SET_PLUTO_SYMBOL_DOUBLE(store_func_codepos, 0x688909, 0x3);

		SAFE_SET_PLUTO_SYMBOL(cscr_get_function_hook, 0x682DC0);
		SAFE_SET_PLUTO_SYMBOL(cscr_get_method_hook, 0x68305C);
		SAFE_SET_PLUTO_SYMBOL_DOUBLE(scr_get_method_hook, 0x683043, 0x4);
		SAFE_SET_PLUTO_SYMBOL_DOUBLE(scr_get_function_hook, 0x682D99, 0x8);

		return true;
	}

	bool process()
	{
		return handle_funcs();
	}
}
