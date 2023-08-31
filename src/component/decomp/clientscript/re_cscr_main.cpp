#include <stdinc.hpp>
#include "loader/component_loader.hpp"
#include "utils/hook.hpp"
#include "codsrc/clientscript/cscr_main.hpp"

#define RE_CSCR_MAIN_USE_WRAPPERS


namespace re_cscr_main
{
	utils::hook::detour Scr_IsIdentifier_hook;
	utils::hook::detour Scr_GetFunctionHandle_hook;
	utils::hook::detour SL_TransferToCanonicalString_hook;
	utils::hook::detour SL_GetCanonicalString_hook;
	utils::hook::detour Scr_BeginLoadScripts_hook;
	utils::hook::detour Scr_BeginLoadAnimTrees_hook;
	utils::hook::detour Scr_ScanFile_hook;
	utils::hook::detour Scr_LoadScriptInternal_hook;
	utils::hook::detour Scr_LoadScript_hook;
	utils::hook::detour Scr_EndLoadScripts_hook;
	utils::hook::detour Scr_PrecacheAnimTrees_hook;
	utils::hook::detour Scr_EndLoadAnimTrees_hook;
	utils::hook::detour Scr_FreeScripts_hook;

	void* Scr_IsIdentifier_original;
	void* Scr_GetFunctionHandle_original;
	void* SL_TransferToCanonicalString_original;
	void* SL_GetCanonicalString_original;
	void* Scr_BeginLoadScripts_original;
	void* Scr_BeginLoadAnimTrees_original;
	void* Scr_ScanFile_original;
	void* Scr_LoadScriptInternal_original;
	void* Scr_LoadScript_original;
	void* Scr_EndLoadScripts_original;
	void* Scr_PrecacheAnimTrees_original;
	void* Scr_EndLoadAnimTrees_original;
	void* Scr_FreeScripts_original;

	namespace
	{
		bool Scr_IsIdentifier_call(char * token, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_MAIN_USE_WRAPPERS
			return game::Scr_IsIdentifier(token, Scr_IsIdentifier_original);
#else
			return codsrc::Scr_IsIdentifier(token);
#endif
		}

		// bool __usercall Scr_IsIdentifier@<al>(char *token@<ecx>)
		NAKED bool Scr_IsIdentifier_stub()
		{
			_asm
			{
				push ecx;
				call Scr_IsIdentifier_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int Scr_GetFunctionHandle_call(const char * file, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, const char * handle)
		{
#ifdef RE_CSCR_MAIN_USE_WRAPPERS
			return game::Scr_GetFunctionHandle(file, inst, handle, Scr_GetFunctionHandle_original);
#else
			return codsrc::Scr_GetFunctionHandle(file, inst, handle);
#endif
		}

		// unsigned int __usercall Scr_GetFunctionHandle@<eax>(const char *file@<eax>, scriptInstance_t inst@<ecx>, const char *handle)
		NAKED unsigned int Scr_GetFunctionHandle_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_GetFunctionHandle_call;
				add esp, 0x8;
				ret;
			}
		}

		unsigned int SL_TransferToCanonicalString_call(game::scriptInstance_t inst, unsigned int stringValue, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_MAIN_USE_WRAPPERS
			return game::SL_TransferToCanonicalString(inst, stringValue, SL_TransferToCanonicalString_original);
#else
			return codsrc::SL_TransferToCanonicalString(inst, stringValue);
#endif
		}

		// unsigned int __usercall SL_TransferToCanonicalString@<eax>(scriptInstance_t inst@<eax>, unsigned int stringValue@<edi>)
		NAKED unsigned int SL_TransferToCanonicalString_stub()
		{
			_asm
			{
				push edi;
				push eax;
				call SL_TransferToCanonicalString_call;
				add esp, 0x8;
				ret;
			}
		}

		unsigned int SL_GetCanonicalString_call(char * token, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_MAIN_USE_WRAPPERS
			return game::SL_GetCanonicalString(token, inst, SL_GetCanonicalString_original);
#else
			return codsrc::SL_GetCanonicalString(token, inst);
#endif
		}

		// unsigned int __usercall SL_GetCanonicalString@<eax>(char *token@<eax>, scriptInstance_t inst@<esi>)
		NAKED unsigned int SL_GetCanonicalString_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call SL_GetCanonicalString_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_BeginLoadScripts_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, int user)
		{
#ifdef RE_CSCR_MAIN_USE_WRAPPERS
			game::Scr_BeginLoadScripts(inst, user, Scr_BeginLoadScripts_original);
#else
			codsrc::Scr_BeginLoadScripts(inst, user);
#endif
		}

		// void __usercall Scr_BeginLoadScripts(scriptInstance_t inst@<edi>, int user)
		NAKED void Scr_BeginLoadScripts_stub()
		{
			_asm
			{
				push edi;
				call Scr_BeginLoadScripts_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_BeginLoadAnimTrees_call(game::scriptInstance_t inst, int user, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_MAIN_USE_WRAPPERS
			game::Scr_BeginLoadAnimTrees(inst, user, Scr_BeginLoadAnimTrees_original);
#else
			codsrc::Scr_BeginLoadAnimTrees(inst, user);
#endif
		}

		// void __usercall Scr_BeginLoadAnimTrees(scriptInstance_t inst@<ecx>, int user@<eax>)
		NAKED void Scr_BeginLoadAnimTrees_stub()
		{
			_asm
			{
				push eax;
				push ecx;
				call Scr_BeginLoadAnimTrees_call;
				add esp, 0x8;
				ret;
			}
		}

		int Scr_ScanFile_call(int max_size, [[maybe_unused]] void* caller_addr, char * buf)
		{
#ifdef RE_CSCR_MAIN_USE_WRAPPERS
			return game::Scr_ScanFile(max_size, buf, Scr_ScanFile_original);
#else
			return codsrc::Scr_ScanFile(max_size, buf);
#endif
		}

		// int __usercall Scr_ScanFile@<eax>(int max_size@<edi>, char *buf)
		NAKED int Scr_ScanFile_stub()
		{
			_asm
			{
				push edi;
				call Scr_ScanFile_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int Scr_LoadScriptInternal_stub(game::scriptInstance_t inst, const char * file, game::PrecacheEntry * entries, int entriesCount)
		{
#ifdef RE_CSCR_MAIN_USE_WRAPPERS
			return Scr_LoadScriptInternal_hook.invoke<unsigned int>(inst, file, entries, entriesCount);
#else
			return codsrc::Scr_LoadScriptInternal(inst, file, entries, entriesCount);
#endif
		}

		unsigned int Scr_LoadScript_call(const char * file, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_MAIN_USE_WRAPPERS
			return game::Scr_LoadScript(file, inst, Scr_LoadScript_original);
#else
			return codsrc::Scr_LoadScript(file, inst);
#endif
		}

		// unsigned int __usercall Scr_LoadScript@<eax>(const char *file@<ecx>, scriptInstance_t inst@<edx>)
		NAKED unsigned int Scr_LoadScript_stub()
		{
			_asm
			{
				push edx;
				push ecx;
				call Scr_LoadScript_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_EndLoadScripts_stub(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_MAIN_USE_WRAPPERS
			Scr_EndLoadScripts_hook.invoke<void>(inst);
#else
			codsrc::Scr_EndLoadScripts(inst);
#endif
		}

		void Scr_PrecacheAnimTrees_stub(game::scriptInstance_t inst, void *(__cdecl *Alloc)(int), int user, int modChecksum, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_MAIN_USE_WRAPPERS
			return Scr_PrecacheAnimTrees_hook.invoke<void>(inst, Alloc, user, modChecksum);
#else
			return codsrc::Scr_PrecacheAnimTrees(inst, Alloc, user, modChecksum);
#endif
		}

		void Scr_EndLoadAnimTrees_stub(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_MAIN_USE_WRAPPERS
			Scr_EndLoadAnimTrees_hook.invoke<void>(inst);
#else
			codsrc::Scr_EndLoadAnimTrees(inst);
#endif
		}

		void Scr_FreeScripts_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_MAIN_USE_WRAPPERS
			game::Scr_FreeScripts(inst, Scr_FreeScripts_original);
#else
			codsrc::Scr_FreeScripts(inst);
#endif
		}

		// void __usercall Scr_FreeScripts(scriptInstance_t a1@<eax>)
		NAKED void Scr_FreeScripts_stub()
		{
			_asm
			{
				push eax;
				call Scr_FreeScripts_call;
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
			Scr_IsIdentifier_hook.create(game::Scr_IsIdentifier_ADDR(), Scr_IsIdentifier_stub);
			Scr_GetFunctionHandle_hook.create(game::Scr_GetFunctionHandle_ADDR(), Scr_GetFunctionHandle_stub);
			SL_TransferToCanonicalString_hook.create(game::SL_TransferToCanonicalString_ADDR(), SL_TransferToCanonicalString_stub);
			SL_GetCanonicalString_hook.create(game::SL_GetCanonicalString_ADDR(), SL_GetCanonicalString_stub);
			Scr_BeginLoadScripts_hook.create(game::Scr_BeginLoadScripts_ADDR(), Scr_BeginLoadScripts_stub);
			Scr_BeginLoadAnimTrees_hook.create(game::Scr_BeginLoadAnimTrees_ADDR(), Scr_BeginLoadAnimTrees_stub);
			Scr_ScanFile_hook.create(game::Scr_ScanFile_ADDR(), Scr_ScanFile_stub);
			Scr_LoadScriptInternal_hook.create(game::Scr_LoadScriptInternal.get(), Scr_LoadScriptInternal_stub);
			Scr_LoadScript_hook.create(game::Scr_LoadScript_ADDR(), Scr_LoadScript_stub);
			Scr_EndLoadScripts_hook.create(game::Scr_EndLoadScripts.get(), Scr_EndLoadScripts_stub);
			Scr_PrecacheAnimTrees_hook.create(game::Scr_PrecacheAnimTrees.get(), Scr_PrecacheAnimTrees_stub);
			Scr_EndLoadAnimTrees_hook.create(game::Scr_EndLoadAnimTrees.get(), Scr_EndLoadAnimTrees_stub);
			Scr_FreeScripts_hook.create(game::Scr_FreeScripts_ADDR(), Scr_FreeScripts_stub);

			//Original hook function addresses
			Scr_IsIdentifier_original = Scr_IsIdentifier_hook.get_original();
			Scr_GetFunctionHandle_original = Scr_GetFunctionHandle_hook.get_original();
			SL_TransferToCanonicalString_original = SL_TransferToCanonicalString_hook.get_original();
			SL_GetCanonicalString_original = SL_GetCanonicalString_hook.get_original();
			Scr_BeginLoadScripts_original = Scr_BeginLoadScripts_hook.get_original();
			Scr_BeginLoadAnimTrees_original = Scr_BeginLoadAnimTrees_hook.get_original();
			Scr_ScanFile_original = Scr_ScanFile_hook.get_original();
			Scr_LoadScriptInternal_original = Scr_LoadScriptInternal_hook.get_original();
			Scr_LoadScript_original = Scr_LoadScript_hook.get_original();
			Scr_EndLoadScripts_original = Scr_EndLoadScripts_hook.get_original();
			Scr_PrecacheAnimTrees_original = Scr_PrecacheAnimTrees_hook.get_original();
			Scr_EndLoadAnimTrees_original = Scr_EndLoadAnimTrees_hook.get_original();
			Scr_FreeScripts_original = Scr_FreeScripts_hook.get_original();
		}

	private:
	};
}
REGISTER_COMPONENT(re_cscr_main::component)