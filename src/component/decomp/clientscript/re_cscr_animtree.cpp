#include <stdinc.hpp>
#include "loader/component_loader.hpp"
#include "utils/hook.hpp"
//#include "codsrc/clientscript/cscr_animtree.hpp"

#ifndef DISABLE_RE_CSCR_YACC
namespace re_cscr_animtree
{
	utils::hook::detour AnimTreeCompileError_hook;
	utils::hook::detour GetAnimTreeParseProperties_hook;
	utils::hook::detour Scr_EmitAnimationInternal_hook;
	utils::hook::detour AnimTreeParseInternal_hook;
	utils::hook::detour Scr_AnimTreeParse_hook;
	utils::hook::detour Scr_GetAnimTreeSize_hook;
	utils::hook::detour ConnectScriptToAnim_hook;
	utils::hook::detour Scr_GetAnimsIndex_hook;
	utils::hook::detour Scr_CreateAnimationTree_hook;
	utils::hook::detour Scr_CheckAnimsDefined_hook;
	utils::hook::detour Scr_PrecacheAnimationTree_hook;
	utils::hook::detour Scr_UsingTreeInternal_hook;
	utils::hook::detour Scr_UsingTree_hook;
	utils::hook::detour Scr_SetAnimTreeConfigstring_hook;
	utils::hook::detour Scr_LoadAnimTreeInternal_hook;
	utils::hook::detour Scr_LoadAnimTreeAtIndex_hook;
	utils::hook::detour Scr_FindAnimTree_hook;
	utils::hook::detour Scr_FindAnim_hook;

	namespace
	{

		void AnimTreeCompileError_stub(game::scriptInstance_t inst, const char * errorMsg)
		{
#ifdef RE_CSCR_ANIMTREE_USE_WRAPPERS
			return AnimTreeCompileError_hook.invoke<void>(inst, errorMsg);
#else
			return cscr_animtree::AnimTreeCompileError(inst, errorMsg);
#endif
		}

		int GetAnimTreeParseProperties_stub(game::scriptInstance_t inst)
		{
#ifdef RE_CSCR_ANIMTREE_USE_WRAPPERS
			return GetAnimTreeParseProperties_hook.invoke<int>(inst);
#else
			return cscr_animtree::GetAnimTreeParseProperties(inst);
#endif
		}

		void Scr_EmitAnimationInternal_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, const char * pos, unsigned int animName, unsigned int names)
		{
#ifdef RE_CSCR_ANIMTREE_USE_WRAPPERS
			game::Scr_EmitAnimationInternal(inst, pos, animName, names, Scr_EmitAnimationInternal_hook.get_original());
#else
			cscr_animtree::Scr_EmitAnimationInternal(inst, pos, animName, names);
#endif
		}

		// void __usercall Scr_EmitAnimationInternal(game::scriptInstance_t inst@<edi>, const char *pos, unsigned int animName, unsigned int names)
		NAKED void Scr_EmitAnimationInternal_stub()
		{
			_asm
			{
				push edi;
				call Scr_EmitAnimationInternal_call;
				add esp, 0x4;
				ret;
			}
		}

		char AnimTreeParseInternal_stub(game::scriptInstance_t inst, int parentId, int names, int bIncludeParent, int bLoop, int bComplete)
		{
#ifdef RE_CSCR_ANIMTREE_USE_WRAPPERS
			return AnimTreeParseInternal_hook.invoke<char>(inst, parentId, names, bIncludeParent, bLoop, bComplete);
#else
			return cscr_animtree::AnimTreeParseInternal(inst, parentId, names, bIncludeParent, bLoop, bComplete);
#endif
		}

		void Scr_AnimTreeParse_call(game::scriptInstance_t inst, const char * pos, [[maybe_unused]] void* caller_addr, unsigned int parentNode, unsigned int names)
		{
#ifdef RE_CSCR_ANIMTREE_USE_WRAPPERS
			game::Scr_AnimTreeParse(inst, pos, parentNode, names, Scr_AnimTreeParse_hook.get_original());
#else
			cscr_animtree::Scr_AnimTreeParse(inst, pos, parentNode, names);
#endif
		}

		// void __usercall Scr_AnimTreeParse(game::scriptInstance_t inst@<eax>, const char *pos@<edi>, unsigned int parentNode, unsigned int names)
		NAKED void Scr_AnimTreeParse_stub()
		{
			_asm
			{
				push edi;
				push eax;
				call Scr_AnimTreeParse_call;
				add esp, 0x8;
				ret;
			}
		}

		int Scr_GetAnimTreeSize_stub(game::scriptInstance_t inst, unsigned int parentNode)
		{
#ifdef RE_CSCR_ANIMTREE_USE_WRAPPERS
			return Scr_GetAnimTreeSize_hook.invoke<int>(inst, parentNode);
#else
			return cscr_animtree::Scr_GetAnimTreeSize(inst, parentNode);
#endif
		}

		void ConnectScriptToAnim_call(unsigned int name, unsigned int names, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, int index, unsigned int filename, int treeIndex)
		{
#ifdef RE_CSCR_ANIMTREE_USE_WRAPPERS
			game::ConnectScriptToAnim(name, names, inst, index, filename, treeIndex, ConnectScriptToAnim_hook.get_original());
#else
			cscr_animtree::ConnectScriptToAnim(name, names, inst, index, filename, treeIndex);
#endif
		}

		// void __usercall ConnectScriptToAnim(unsigned int name@<eax>, unsigned int names@<edi>, game::scriptInstance_t inst, int index, unsigned int filename, int treeIndex)
		NAKED void ConnectScriptToAnim_stub()
		{
			_asm
			{
				push edi;
				push eax;
				call ConnectScriptToAnim_call;
				add esp, 0x8;
				ret;
			}
		}

		int Scr_GetAnimsIndex_call(game::XAnim_s * anim, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_ANIMTREE_USE_WRAPPERS
			return game::Scr_GetAnimsIndex(anim, Scr_GetAnimsIndex_hook.get_original());
#else
			return cscr_animtree::Scr_GetAnimsIndex(anim);
#endif
		}

		// int __usercall Scr_GetAnimsIndex@<eax>(game::XAnim_s *anim@<ecx>)
		NAKED int Scr_GetAnimsIndex_stub()
		{
			_asm
			{
				push ecx;
				call Scr_GetAnimsIndex_call;
				add esp, 0x4;
				ret;
			}
		}

		int Scr_CreateAnimationTree_stub(game::scriptInstance_t inst, unsigned int parentNode, unsigned int rootData, game::XAnim_s* animtree, unsigned int childIndex, const char* name, unsigned int parentIndex, unsigned int filename, int treeIndex, int flags)
		{
#ifdef RE_CSCR_ANIMTREE_USE_WRAPPERS
			return Scr_CreateAnimationTree_hook.invoke<int>(inst, parentNode, rootData, animtree, childIndex, name, parentIndex, filename, treeIndex, flags);
#else
			return cscr_animtree::Scr_CreateAnimationTree(inst, parentNode, rootData, animtree, childIndex, name, parentIndex, filename, treeIndex, flags);
#endif
		}

		void Scr_CheckAnimsDefined_call(unsigned int names, game::scriptInstance_t a2, [[maybe_unused]] void* caller_addr, unsigned int filename)
		{
#ifdef RE_CSCR_ANIMTREE_USE_WRAPPERS
			game::Scr_CheckAnimsDefined(names, a2, filename, Scr_CheckAnimsDefined_hook.get_original());
#else
			cscr_animtree::Scr_CheckAnimsDefined(names, a2, filename);
#endif
		}

		// void __usercall Scr_CheckAnimsDefined(unsigned int names@<eax>, game::scriptInstance_t a2@<ecx>, unsigned int filename)
		NAKED void Scr_CheckAnimsDefined_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_CheckAnimsDefined_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_PrecacheAnimationTree_stub(game::scriptInstance_t inst, unsigned int parentNode)
		{
#ifdef RE_CSCR_ANIMTREE_USE_WRAPPERS
			Scr_PrecacheAnimationTree_hook.invoke<void>(inst, parentNode);
#else
			cscr_animtree::Scr_PrecacheAnimationTree(inst, parentNode);
#endif
		}

		unsigned int Scr_UsingTreeInternal_call(const char * filename, int user, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, unsigned int * index)
		{
#ifdef RE_CSCR_ANIMTREE_USE_WRAPPERS
			return game::Scr_UsingTreeInternal(filename, user, inst, index, Scr_UsingTreeInternal_hook.get_original());
#else
			return cscr_animtree::Scr_UsingTreeInternal(filename, user, inst, index);
#endif
		}

		// unsigned int __usercall Scr_UsingTreeInternal@<eax>(const char *filename@<eax>, int user@<ecx>, game::scriptInstance_t inst, unsigned int *index)
		NAKED unsigned int Scr_UsingTreeInternal_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_UsingTreeInternal_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_UsingTree_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, const char * filename, unsigned int sourcePos)
		{
#ifdef RE_CSCR_ANIMTREE_USE_WRAPPERS
			game::Scr_UsingTree(a1, filename, sourcePos, Scr_UsingTree_hook.get_original());
#else
			cscr_animtree::Scr_UsingTree(a1, filename, sourcePos);
#endif
		}

		// void __usercall Scr_UsingTree(game::scriptInstance_t a1@<edi>, const char *filename, unsigned int sourcePos)
		NAKED void Scr_UsingTree_stub()
		{
			_asm
			{
				push edi;
				call Scr_UsingTree_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_SetAnimTreeConfigstring_stub(const char * animtreeName)
		{
#ifdef RE_CSCR_ANIMTREE_USE_WRAPPERS
			Scr_SetAnimTreeConfigstring_hook.invoke<void>(animtreeName);
#else
			cscr_animtree::Scr_SetAnimTreeConfigstring(animtreeName);
#endif
		}

		bool Scr_LoadAnimTreeInternal_call(const char * animtreeName, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, unsigned int parentNode, unsigned int names)
		{
#ifdef RE_CSCR_ANIMTREE_USE_WRAPPERS
			return game::Scr_LoadAnimTreeInternal(animtreeName, inst, parentNode, names, Scr_LoadAnimTreeInternal_hook.get_original());
#else
			return cscr_animtree::Scr_LoadAnimTreeInternal(animtreeName, inst, parentNode, names);
#endif
		}

		// bool __usercall Scr_LoadAnimTreeInternal@<al>(const char *animtreeName@<eax>, game::scriptInstance_t inst@<ecx>, unsigned int parentNode, unsigned int names)
		NAKED bool Scr_LoadAnimTreeInternal_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_LoadAnimTreeInternal_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_LoadAnimTreeAtIndex_call(game::scriptInstance_t inst, int user, [[maybe_unused]] void* caller_addr, unsigned int index, void *(__cdecl * Alloc)(int), int modCheckSum)
		{
#ifdef RE_CSCR_ANIMTREE_USE_WRAPPERS
			return game::Scr_LoadAnimTreeAtIndex(inst, user, index, Alloc, modCheckSum, Scr_LoadAnimTreeAtIndex_hook.get_original());
#else
			return cscr_animtree::Scr_LoadAnimTreeAtIndex(inst, user, index, Alloc, modCheckSum);
#endif
		}

		// void __usercall Scr_LoadAnimTreeAtIndex(game::scriptInstance_t inst@<ecx>, int user@<eax>, unsigned int index, void *(__cdecl *Alloc)(int), int modCheckSum)
		NAKED void Scr_LoadAnimTreeAtIndex_stub()
		{
			_asm
			{
				push eax;
				push ecx;
				call Scr_LoadAnimTreeAtIndex_call;
				add esp, 0x8;
				ret;
			}
		}

		game::scr_animtree_t Scr_FindAnimTree_call(const char * filename, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_ANIMTREE_USE_WRAPPERS
			return game::Scr_FindAnimTree(filename, Scr_FindAnimTree_hook.get_original());
#else
			return cscr_animtree::Scr_FindAnimTree(filename);
#endif
		}

		// game::XAnim_s *__usercall Scr_FindAnimTree@<eax>(const char *filename@<eax>)
		NAKED game::XAnim_s * Scr_FindAnimTree_stub()
		{
			_asm
			{
				push eax;
				call Scr_FindAnimTree_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_FindAnim_call(const char * animName, [[maybe_unused]] void* caller_addr, game::scr_anim_s a2, int user)
		{
#ifdef RE_CSCR_ANIMTREE_USE_WRAPPERS
			game::Scr_FindAnim(animName, a2, user, Scr_FindAnim_hook.get_original());
#else
			cscr_animtree::Scr_FindAnim(animName, a2, user);
#endif
		}

		// void __usercall Scr_FindAnim(const char *animName@<edx>, game::scr_anim_s a2, int user)
		NAKED void Scr_FindAnim_stub()
		{
			_asm
			{
				push edx;
				call Scr_FindAnim_call;
				add esp, 0x4;
				ret;
			}
		}
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			bool quick = true;
#ifdef RE_CSCR_ANIMTREE_USE_WRAPPERS
			quick = false;
#endif

			AnimTreeCompileError_hook.create(game::AnimTreeCompileError.get(), AnimTreeCompileError_stub, quick);
			GetAnimTreeParseProperties_hook.create(game::GetAnimTreeParseProperties.get(), GetAnimTreeParseProperties_stub, quick);
			Scr_EmitAnimationInternal_hook.create(game::Scr_EmitAnimationInternal_ADDR(), Scr_EmitAnimationInternal_stub, quick);
			AnimTreeParseInternal_hook.create(game::AnimTreeParseInternal.get(), AnimTreeParseInternal_stub, quick);
			Scr_AnimTreeParse_hook.create(game::Scr_AnimTreeParse_ADDR(), Scr_AnimTreeParse_stub, quick);
			Scr_GetAnimTreeSize_hook.create(game::Scr_GetAnimTreeSize.get(), Scr_GetAnimTreeSize_stub, quick);
			ConnectScriptToAnim_hook.create(game::ConnectScriptToAnim_ADDR(), ConnectScriptToAnim_stub, quick);
			Scr_GetAnimsIndex_hook.create(game::Scr_GetAnimsIndex_ADDR(), Scr_GetAnimsIndex_stub, quick);
			Scr_CreateAnimationTree_hook.create(game::Scr_CreateAnimationTree.get(), Scr_CreateAnimationTree_stub, quick);
			Scr_CheckAnimsDefined_hook.create(game::Scr_CheckAnimsDefined_ADDR(), Scr_CheckAnimsDefined_stub, quick);
			Scr_PrecacheAnimationTree_hook.create(game::Scr_PrecacheAnimationTree.get(), Scr_PrecacheAnimationTree_stub, quick);
			Scr_UsingTreeInternal_hook.create(game::Scr_UsingTreeInternal_ADDR(), Scr_UsingTreeInternal_stub, quick);
			Scr_UsingTree_hook.create(game::Scr_UsingTree_ADDR(), Scr_UsingTree_stub, quick);
			Scr_SetAnimTreeConfigstring_hook.create(game::Scr_SetAnimTreeConfigstring.get(), Scr_SetAnimTreeConfigstring_stub, quick);
			Scr_LoadAnimTreeInternal_hook.create(game::Scr_LoadAnimTreeInternal_ADDR(), Scr_LoadAnimTreeInternal_stub, quick);
			Scr_LoadAnimTreeAtIndex_hook.create(game::Scr_LoadAnimTreeAtIndex_ADDR(), Scr_LoadAnimTreeAtIndex_stub, quick);
			Scr_FindAnimTree_hook.create(game::Scr_FindAnimTree_ADDR(), Scr_FindAnimTree_stub, quick);
			Scr_FindAnim_hook.create(game::Scr_FindAnim_ADDR(), Scr_FindAnim_stub, quick);
		}

	private:
	};
}
REGISTER_COMPONENT(re_cscr_animtree::component)
#endif
