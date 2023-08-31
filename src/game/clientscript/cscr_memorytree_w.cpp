#include <stdinc.hpp>

namespace game
{
	// void __usercall MT_InitBits(scriptInstance_t a1@<ecx>)
	void MT_InitBits(scriptInstance_t inst, void* call_addr)
	{
		__asm
		{
			mov ecx, inst;
			call call_addr;
		}
	}

	// int __usercall MT_GetScore@<eax>(scriptInstance_t a1@<edx>, int num)
	int MT_GetScore(scriptInstance_t inst, int num, void* call_addr)
	{
		int answer;

		__asm
		{
			push num;
			mov edx, inst;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}

		return answer;
	}

	// void __usercall MT_Init(scriptInstance_t a1@<edi>)
	void MT_Init(scriptInstance_t inst, void* call_addr)
	{
		__asm
		{
			mov edi, inst;
			call call_addr;
		}
	}

	// void __usercall MT_Error(scriptInstance_t a1@<eax>, const char *funcName, int numBytes)
	void MT_Error(scriptInstance_t inst, const char* funcName, int numBytes, void* call_addr)
	{
		__asm
		{
			push numBytes;
			push funcName;
			mov eax, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// int __usercall MT_GetSize@<eax>(int numBytes@<eax>, scriptInstance_t inst@<ecx>)
	int MT_GetSize/*@<eax>*/(int numBytes/*@<eax>*/, scriptInstance_t inst/*@<ecx>*/, void* call_addr)
	{
		int answer;

		__asm
		{
			mov eax, numBytes;
			mov ecx, inst;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	// unsigned __int16 __usercall MT_AllocIndex@<ax>(scriptInstance_t inst@<edi>, int size)
	unsigned __int16 MT_AllocIndex/*@<ax>*/(scriptInstance_t inst/*@<edi>*/, int size_, void* call_addr)
	{
		unsigned __int16 answer;

		__asm
		{
			push size_;
			mov edi, inst;
			call call_addr;
			mov answer, ax;
			add esp, 0x4;
		}

		return answer;
	}

	// void __usercall MT_FreeIndex(int numBytes@<eax>, scriptInstance_t a1, int nodeNum)
	void MT_FreeIndex(int numBytes/*@<eax>*/, scriptInstance_t inst, int nodeNum, void* call_addr)
	{
		__asm
		{
			push nodeNum;
			push inst;
			mov eax, numBytes;
			call call_addr;
			add esp, 0x8;
		}
	}

	// char *__usercall MT_Alloc@<eax>(int numBytes@<eax>, scriptInstance_t a2@<ecx>)
	char* MT_Alloc(int numBytes, scriptInstance_t inst, void* call_addr)
	{
		char* answer;

		__asm
		{
			mov eax, numBytes;
			mov ecx, inst;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}
	
	RefVector* GetRefVector(scriptInstance_t inst, unsigned int id)
	{
		//return cscr_memorytree::GetRefVector(inst, id);
		return nullptr;
	}

	const char* MT_NodeInfoString(scriptInstance_t inst, unsigned int nodeNum)
	{
		//return cscr_memorytree::MT_NodeInfoString(inst, nodeNum);
		return nullptr;
	}
}