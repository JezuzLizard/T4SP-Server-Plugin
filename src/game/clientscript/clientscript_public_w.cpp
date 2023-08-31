#include <stdinc.hpp>

namespace game
{
	// void __usercall ScriptParse(scriptInstance_t a1@<eax>, sval_u *parseData)
	void ScriptParse(scriptInstance_t inst, sval_u* parseData, void* call_addr)
	{
		__asm
		{
			push parseData;
			mov eax, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall ScriptCompile(scriptInstance_t inst@<eax>, sval_u a2, unsigned int filePosId, unsigned int fileCountId, unsigned int scriptId, PrecacheEntry *entries, int entriesCount)
	void ScriptCompile(scriptInstance_t inst, sval_u val, unsigned int filePosId, unsigned int fileCountId, unsigned int scriptId, PrecacheEntry * entries, int entriesCount, void* call_addr)
	{
		__asm
		{
			push entriesCount;
			push entries;
			push scriptId;
			push fileCountId;
			push filePosId;
			push val;
			mov eax, inst;
			call call_addr;
			add esp, 0x18;
		}
	}

	// void __usercall Scr_LoadAnimTreeAtIndex(scriptInstance_t inst@<ecx>, int a2@<eax>, int a3, int (__cdecl *a4)(int), int a5)
	void Scr_LoadAnimTreeAtIndex(scriptInstance_t inst, int user, unsigned int index, void* (__cdecl* Alloc)(int), int modCheckSum, void* call_addr)
	{
		__asm
		{
			push modCheckSum;
			push Alloc;
			push index;
			mov eax, user;
			mov ecx, inst;
			call call_addr;
			add esp, 0xC;
		}
	}

	// HunkUser* __usercall Hunk_UserCreate@<eax>(signed int maxSize@<edi>, char* name, char fixed, char tempMem, char debugMem, int type);
	HunkUser* Hunk_UserCreate(signed int maxSize, const char* name, int fixed, int tempMem, int debugMem, int typ, void* call_addr)
	{
		HunkUser* answer;

		__asm
		{
			push typ;
			push debugMem;
			push tempMem;
			push fixed;
			push name;
			mov edi, maxSize;
			call call_addr;
			add esp, 0x14;
			mov answer, eax;
		}

		return answer;
	}
}