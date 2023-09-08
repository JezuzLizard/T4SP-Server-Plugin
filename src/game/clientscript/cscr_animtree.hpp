#pragma once

namespace game
{
	WEAK symbol<void(scriptInstance_t inst, const char * errorMsg)>AnimTreeCompileError{ 0x0, 0x67D4B0};
	WEAK symbol<int(scriptInstance_t inst)>GetAnimTreeParseProperties{ 0x0, 0x67D510};
	WEAK symbol<char(scriptInstance_t inst, int parentId, int names, int bIncludeParent, int bLoop, int bComplete)>AnimTreeParseInternal{ 0x0, 0x67D770};
	WEAK symbol<int(scriptInstance_t inst, unsigned int parentNode)>Scr_GetAnimTreeSize{ 0x0, 0x67DE20};
	WEAK symbol<int(scriptInstance_t inst, unsigned int parentNode, unsigned int rootData, XAnim_s* animtree, unsigned int childIndex, const char* name, unsigned int parentIndex, unsigned int filename, int treeIndex, int flags)>Scr_CreateAnimationTree{ 0x0, 0x67DFB0};
	WEAK symbol<void(scriptInstance_t inst, unsigned int parentNode)>Scr_PrecacheAnimationTree{ 0x0, 0x67E360};
	WEAK symbol<void(const char * animtreeName)>Scr_SetAnimTreeConfigstring{ 0x0, 0x67E670};

	inline void* Scr_EmitAnimationInternal_ADDR() { return CALL_ADDR(0x0, 0x67D6B0); }
	void Scr_EmitAnimationInternal(scriptInstance_t inst, const char * pos, unsigned int animName, unsigned int names, void* call_addr = Scr_EmitAnimationInternal_ADDR());
	inline void* Scr_AnimTreeParse_ADDR() { return CALL_ADDR(0x0, 0x67DDA0); }
	void Scr_AnimTreeParse(scriptInstance_t inst, const char * pos, unsigned int parentNode, unsigned int names, void* call_addr = Scr_AnimTreeParse_ADDR());
	inline void* ConnectScriptToAnim_ADDR() { return CALL_ADDR(0x0, 0x67DEC0); }
	void ConnectScriptToAnim(unsigned int name, unsigned int names, scriptInstance_t inst, int index, unsigned int filename, int treeIndex, void* call_addr = ConnectScriptToAnim_ADDR());
	inline void* Scr_GetAnimsIndex_ADDR() { return CALL_ADDR(0x0, 0x67DF90); }
	int Scr_GetAnimsIndex(XAnim_s * anim, void* call_addr = Scr_GetAnimsIndex_ADDR());
	inline void* Scr_CheckAnimsDefined_ADDR() { return CALL_ADDR(0x0, 0x67E260); }
	void Scr_CheckAnimsDefined(unsigned int names, scriptInstance_t a2, unsigned int filename, void* call_addr = Scr_CheckAnimsDefined_ADDR());
	inline void* Scr_UsingTreeInternal_ADDR() { return CALL_ADDR(0x0, 0x67E420); }
	unsigned int Scr_UsingTreeInternal(const char * filename, int user, scriptInstance_t inst, unsigned int * index, void* call_addr = Scr_UsingTreeInternal_ADDR());
	inline void* Scr_UsingTree_ADDR() { return CALL_ADDR(0x0, 0x67E5F0); }
	void Scr_UsingTree(scriptInstance_t a1, const char * filename, unsigned int sourcePos, void* call_addr = Scr_UsingTree_ADDR());
	inline void* Scr_LoadAnimTreeInternal_ADDR() { return CALL_ADDR(0x0, 0x67E710); }
	bool Scr_LoadAnimTreeInternal(const char * animtreeName, scriptInstance_t inst, unsigned int parentNode, unsigned int names, void* call_addr = Scr_LoadAnimTreeInternal_ADDR());
	inline void* Scr_LoadAnimTreeAtIndex_ADDR() { return CALL_ADDR(0x0, 0x67E7D0); }
	void Scr_LoadAnimTreeAtIndex(scriptInstance_t inst, int user, unsigned int index, void *(__cdecl * Alloc)(int), int modCheckSum, void* call_addr = Scr_LoadAnimTreeAtIndex_ADDR());
	inline void* Scr_FindAnimTree_ADDR() { return CALL_ADDR(0x0, 0x67EA70); }
	scr_animtree_t Scr_FindAnimTree(const char * filename, void* call_addr = Scr_FindAnimTree_ADDR());
	inline void* Scr_FindAnim_ADDR() { return CALL_ADDR(0x0, 0x67EB10); }
	void Scr_FindAnim(const char * animName, scr_anim_s a2, int user, void* call_addr = Scr_FindAnim_ADDR());
}
