#include <stdinc.hpp>
#include "codsrc/clientscript/cscr_main.hpp"

namespace game
{
	// bool __usercall Scr_IsIdentifier@<al>(char *token@<ecx>)
	bool Scr_IsIdentifier(char* token, void* call_addr)
	{
		bool answer;

		__asm
		{
			mov ecx, token;
			call call_addr;
			mov answer, al;
		}

		return answer;
	}

	// unsigned int __usercall Scr_GetFunctionHandle@<eax>(const char *file@<eax>, scriptInstance_t inst@<ecx>, const char *handle)
	unsigned int Scr_GetFunctionHandle(const char* file, scriptInstance_t inst, const char* handle, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			push handle;
			mov eax, file;
			mov ecx, inst;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}

		return answer;
	}

	// unsigned int __usercall SL_TransferToCanonicalString@<eax>(scriptInstance_t inst@<eax>, unsigned int stringValue@<edi>)
	unsigned int SL_TransferToCanonicalString(scriptInstance_t inst, unsigned int stringValue, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			mov eax, inst;
			mov edi, stringValue;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	// unsigned int __usercall SL_GetCanonicalString@<eax>(char *token@<eax>, scriptInstance_t inst@<esi>)
	unsigned int SL_GetCanonicalString(const char* token, scriptInstance_t inst, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			mov eax, token;
			mov esi, inst;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	// void __usercall Scr_BeginLoadScripts(scriptInstance_t inst@<edi>, int user)
	void Scr_BeginLoadScripts(scriptInstance_t inst, int user, void* call_addr)
	{
		__asm
		{
			push user;
			mov edi, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall Scr_BeginLoadAnimTrees(scriptInstance_t inst@<ecx>, int user@<eax>)
	void Scr_BeginLoadAnimTrees(scriptInstance_t inst, int user, void* call_addr)
	{
		__asm
		{
			mov ecx, inst;
			mov eax, user;
			call call_addr;
		}
	}

	// int __usercall Scr_ScanFile@<eax>(int max_size@<edi>, char *buf)
	int Scr_ScanFile(int max_size, char* buf, void* call_addr)
	{
		int answer;

		__asm
		{
			push buf;
			mov edi, max_size;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}

		return answer;
	}

	// unsigned int __usercall Scr_LoadScript@<eax>(const char *file@<ecx>, scriptInstance_t inst@<edx>)
	unsigned int Scr_LoadScript(const char* file, scriptInstance_t inst, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			mov ecx, file;
			mov edx, inst;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	// void __usercall Scr_FreeScripts(scriptInstance_t a1@<eax>)
	void Scr_FreeScripts(scriptInstance_t inst, void* call_addr)
	{
		__asm
		{
			mov eax, inst;
			call call_addr;
		}
	}

	int Scr_IsInOpcodeMemory(scriptInstance_t inst, const char* pos)
	{
		return codsrc::Scr_IsInOpcodeMemory(inst, pos);
	}

	void SL_BeginLoadScripts(scriptInstance_t inst)
	{
		codsrc::SL_BeginLoadScripts(inst);
	}

	void Scr_SetLoadedImpureScript(bool loadedImpureScript)
	{
		codsrc::Scr_SetLoadedImpureScript(loadedImpureScript);
	}
}