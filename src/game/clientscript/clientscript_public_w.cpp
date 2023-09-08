#include <stdinc.hpp>

namespace game
{
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