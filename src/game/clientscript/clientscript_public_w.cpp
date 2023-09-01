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

	int CScr_SetEntityField/*@<eax>*/(int ofs/*@<edx>*/, int entnum/*@<ecx>*/, unsigned int clientnum, void* call_addr)
	{
		int answer;

		__asm
		{
			push clientnum;
			mov edx, ofs;
			mov ecx, entnum;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}

		return answer;
	}

	int Scr_SetObjectField/*@<eax>*/(int ofs/*@<eax>*/, int entnum/*@<edx>*/, classNum_e classnum, scriptInstance_t inst, void* call_addr)
	{
		int answer;

		__asm
		{
			push inst;
			push classnum;
			mov eax, ofs;
			mov edx, entnum;
			call call_addr;
			mov answer, eax;
			add esp, 0x8;
		}

		return answer;
	}

	void CScr_GetEntityField(int ofs/*@<edx>*/, int entnum/*@<ecx>*/, unsigned int clientnum, void* call_addr)
	{
		__asm
		{
			push clientnum;
			mov edx, ofs;
			mov ecx, entnum;
			call call_addr;
			add esp, 0x4;
		}
	}

	void Scr_GetObjectField(int ofs/*@<eax>*/, int inst/*@<edx>*/, classNum_e classnum, int entnum, void* call_addr)
	{
		__asm
		{
			push entnum;
			push classnum;
			mov eax, ofs;
			mov edx, inst;
			call call_addr;
			add esp, 0x8;
		}
	}
}