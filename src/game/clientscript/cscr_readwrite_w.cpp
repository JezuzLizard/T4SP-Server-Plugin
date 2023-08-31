#include <stdinc.hpp>

namespace game
{
	// unsigned int __usercall FindVariableIndexInternal2@<eax>(scriptInstance_t inst@<eax>, unsigned int name, unsigned int index)
	unsigned int FindVariableIndexInternal2(scriptInstance_t inst, unsigned int name, unsigned int index, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			push index;
			push name;
			mov eax, inst;
			call call_addr;
			mov answer, eax;
			add esp, 0x8;
		}

		return answer;
	}

	// unsigned int __usercall FindLastSibling@<eax>(unsigned int parentId@<edx>, scriptInstance_t inst@<esi>)
	unsigned int FindLastSibling(unsigned int parentId, scriptInstance_t inst, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			mov edx, parentId;
			mov esi, inst;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	unsigned int FindVariableIndexInternal(scriptInstance_t inst, unsigned int parentId, unsigned int name)
	{
		//return cscr_readwrite::FindVariableIndexInternal(inst, parentId, name);
		return 0;
	}
}