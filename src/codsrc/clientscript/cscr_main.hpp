#pragma once

namespace codsrc
{
	int Scr_IsInOpcodeMemory(game::scriptInstance_t inst, const char* pos);
	bool Scr_IsIdentifier(char * token);
	unsigned int Scr_GetFunctionHandle(const char * file, game::scriptInstance_t inst, const char * handle);
	unsigned int SL_TransferToCanonicalString(game::scriptInstance_t inst, unsigned int stringValue);
	unsigned int SL_GetCanonicalString(char * token, game::scriptInstance_t inst);
	void Scr_BeginLoadScripts(game::scriptInstance_t inst, int user);
	void Scr_BeginLoadAnimTrees(game::scriptInstance_t inst, int user);
	int Scr_ScanFile(int max_size, char * buf);
	unsigned int Scr_LoadScriptInternal(game::scriptInstance_t inst, const char * file, game::PrecacheEntry * entries, int entriesCount);
	unsigned int Scr_LoadScript(const char * file, game::scriptInstance_t inst);
	void Scr_EndLoadScripts(game::scriptInstance_t inst);
	void Scr_EndLoadAnimTrees(game::scriptInstance_t inst);
	void Scr_FreeScripts(game::scriptInstance_t inst);
	void Scr_PrecacheAnimTrees(game::scriptInstance_t inst, void* (__cdecl* Alloc)(int), int user, int modChecksum);
	void Scr_SetLoadedImpureScript(bool loadedImpureScript);
	void SL_BeginLoadScripts(game::scriptInstance_t inst);
}
