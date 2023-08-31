#pragma once

namespace game
{
	WEAK symbol<unsigned int(scriptInstance_t inst, const char* file, PrecacheEntry* entries, int entriesCount)> Scr_LoadScriptInternal { 0x0, 0x689980 };
	WEAK symbol<void(scriptInstance_t inst)>Scr_EndLoadScripts { 0x0, 0x689C80 };
	WEAK symbol<void(scriptInstance_t inst, void *(__cdecl *Alloc)(int), int user, int modChecksum)> Scr_PrecacheAnimTrees { 0x0, 0x689D60 };
	WEAK symbol<void(scriptInstance_t inst)>Scr_EndLoadAnimTrees { 0x0, 0x689DC0 };

	inline void* Scr_IsIdentifier_ADDR() { return CALL_ADDR(0x0, 0x689470); }
	bool Scr_IsIdentifier(char* token, void* call_addr = Scr_IsIdentifier_ADDR());
	inline void* Scr_GetFunctionHandle_ADDR() { return CALL_ADDR(0x0, 0x6894B0); }
	unsigned int Scr_GetFunctionHandle(const char* file, scriptInstance_t inst, const char* handle, void* call_addr = Scr_GetFunctionHandle_ADDR());
	inline void* SL_TransferToCanonicalString_ADDR() { return CALL_ADDR(0x0, 0x6895A0); }
	unsigned int SL_TransferToCanonicalString(scriptInstance_t inst, unsigned int stringValue, void* call_addr = SL_TransferToCanonicalString_ADDR());
	inline void* SL_GetCanonicalString_ADDR() { return CALL_ADDR(0x0, 0x6895F0); }
	unsigned int SL_GetCanonicalString(const char* token, scriptInstance_t inst, void* call_addr = SL_GetCanonicalString_ADDR());
	inline void* Scr_BeginLoadScripts_ADDR() { return CALL_ADDR(0x0, 0x689660); }
	void Scr_BeginLoadScripts(scriptInstance_t inst, int user, void* call_addr = Scr_BeginLoadScripts_ADDR());
	inline void* Scr_BeginLoadAnimTrees_ADDR() { return CALL_ADDR(0x0, 0x689880); }
	void Scr_BeginLoadAnimTrees(scriptInstance_t inst, int user, void* call_addr = Scr_BeginLoadAnimTrees_ADDR());
	inline void* Scr_ScanFile_ADDR() { return CALL_ADDR(0x0, 0x689900); }
	int Scr_ScanFile(int max_size, char* buf, void* call_addr = Scr_ScanFile_ADDR());
	inline void* Scr_LoadScript_ADDR() { return CALL_ADDR(0x0, 0x689C60); }
	unsigned int Scr_LoadScript(const char* file, scriptInstance_t inst, void* call_addr = Scr_LoadScript_ADDR());
	inline void* Scr_FreeScripts_ADDR() { return CALL_ADDR(0x0, 0x689E50); }
	void Scr_FreeScripts(scriptInstance_t inst, void* call_addr = Scr_FreeScripts_ADDR());

	int Scr_IsInOpcodeMemory(scriptInstance_t inst, const char* pos);
	void SL_BeginLoadScripts(scriptInstance_t inst);
	void Scr_SetLoadedImpureScript(bool loadedImpureScript);
}