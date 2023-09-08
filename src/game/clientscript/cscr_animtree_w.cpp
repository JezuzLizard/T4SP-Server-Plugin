#include <stdinc.hpp>
//#include "codsrc/clientscript/cscr_animtree.hpp"

namespace game
{
	// void __usercall Scr_EmitAnimationInternal(scriptInstance_t inst@<edi>, const char *pos, unsigned int animName, unsigned int names)
	void Scr_EmitAnimationInternal(scriptInstance_t inst, const char * pos, unsigned int animName, unsigned int names, void* call_addr)
	{
		__asm
		{
			push names;
			push animName;
			push pos;
			mov edi, inst;
			call call_addr;
			add esp, 0xC;
		}
	}

	// void __usercall Scr_AnimTreeParse(scriptInstance_t inst@<eax>, const char *pos@<edi>, unsigned int parentNode, unsigned int names)
	void Scr_AnimTreeParse(scriptInstance_t inst, const char * pos, unsigned int parentNode, unsigned int names, void* call_addr)
	{
		__asm
		{
			push names;
			push parentNode;
			mov eax, inst;
			mov edi, pos;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall ConnectScriptToAnim(unsigned int name@<eax>, unsigned int names@<edi>, scriptInstance_t inst, int index, unsigned int filename, int treeIndex)
	void ConnectScriptToAnim(unsigned int name, unsigned int names, scriptInstance_t inst, int index, unsigned int filename, int treeIndex, void* call_addr)
	{
		__asm
		{
			push treeIndex;
			push filename;
			push index;
			push inst;
			mov eax, name;
			mov edi, names;
			call call_addr;
			add esp, 0x10;
		}
	}

	// int __usercall Scr_GetAnimsIndex@<eax>(XAnim_s *anim@<ecx>)
	int Scr_GetAnimsIndex(XAnim_s * anim, void* call_addr)
	{
		int answer;
		
		__asm
		{
			mov ecx, anim;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	// void __usercall Scr_CheckAnimsDefined(unsigned int names@<eax>, scriptInstance_t a2@<ecx>, unsigned int filename)
	void Scr_CheckAnimsDefined(unsigned int names, scriptInstance_t a2, unsigned int filename, void* call_addr)
	{
		__asm
		{
			push filename;
			mov eax, names;
			mov ecx, a2;
			call call_addr;
			add esp, 0x4;
		}
	}

	// unsigned int __usercall Scr_UsingTreeInternal@<eax>(const char *filename@<eax>, int user@<ecx>, scriptInstance_t inst, unsigned int *index)
	unsigned int Scr_UsingTreeInternal(const char * filename, int user, scriptInstance_t inst, unsigned int * index, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			push index;
			push inst;
			mov eax, filename;
			mov ecx, user;
			call call_addr;
			mov answer, eax;
			add esp, 0x8;
		}
		
		return answer;
	}

	// void __usercall Scr_UsingTree(scriptInstance_t a1@<edi>, const char *filename, unsigned int sourcePos)
	void Scr_UsingTree(scriptInstance_t a1, const char * filename, unsigned int sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push filename;
			mov edi, a1;
			call call_addr;
			add esp, 0x8;
		}
	}

	// bool __usercall Scr_LoadAnimTreeInternal@<al>(const char *animtreeName@<eax>, scriptInstance_t inst@<ecx>, unsigned int parentNode, unsigned int names)
	bool Scr_LoadAnimTreeInternal(const char * animtreeName, scriptInstance_t inst, unsigned int parentNode, unsigned int names, void* call_addr)
	{
		bool answer;
		
		__asm
		{
			push names;
			push parentNode;
			mov eax, animtreeName;
			mov ecx, inst;
			call call_addr;
			mov answer, al;
			add esp, 0x8;
		}
		
		return answer;
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

	// XAnim_s *__usercall Scr_FindAnimTree@<eax>(const char *filename@<eax>)
	scr_animtree_t Scr_FindAnimTree(const char * filename, void* call_addr)
	{
		scr_animtree_t answer;
		
		__asm
		{
			mov eax, filename;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	// void __usercall Scr_FindAnim(const char *animName@<edx>, scr_anim_s a2, int user)
	void Scr_FindAnim(const char * animName, scr_anim_s a2, int user, void* call_addr)
	{
		__asm
		{
			push user;
			push a2;
			mov edx, animName;
			call call_addr;
			add esp, 0x8;
		}
	}

}
