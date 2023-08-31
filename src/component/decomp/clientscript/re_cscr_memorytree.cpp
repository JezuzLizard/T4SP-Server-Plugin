#include <stdinc.hpp>
#include "loader/component_loader.hpp"
#include "utils/hook.hpp"
//#include "codsrc/clientscript/cscr_memorytree.hpp"

#define RE_CSCR_MEMORYTREE_USE_WRAPPERS

namespace re_cscr_memorytree
{
	utils::hook::detour MT_GetSubTreeSize_hook;
	utils::hook::detour MT_DumpTree_hook;
	utils::hook::detour MT_InitBits_hook;
	utils::hook::detour MT_GetScore_hook;
	utils::hook::detour MT_AddMemoryNode_hook;
	utils::hook::detour MT_RemoveMemoryNode_hook;
	utils::hook::detour MT_RemoveHeadMemoryNode_hook;
	utils::hook::detour MT_Init_hook;
	utils::hook::detour MT_Error_hook;
	utils::hook::detour MT_GetSize_hook;
	utils::hook::detour MT_AllocIndex_hook;
	utils::hook::detour MT_FreeIndex_hook;
	utils::hook::detour MT_Alloc_hook;
	utils::hook::detour MT_Free_hook;

	void* MT_GetSubTreeSize_original;
	void* MT_DumpTree_original;
	void* MT_InitBits_original;
	void* MT_GetScore_original;
	void* MT_AddMemoryNode_original;
	void* MT_RemoveMemoryNode_original;
	void* MT_RemoveHeadMemoryNode_original;
	void* MT_Init_original;
	void* MT_Error_original;
	void* MT_GetSize_original;
	void* MT_AllocIndex_original;
	void* MT_FreeIndex_original;
	void* MT_Alloc_original;
	void* MT_Free_original;

	namespace
	{
		int MT_GetSubTreeSize_stub(game::scriptInstance_t inst, int nodeNum, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_MEMORYTREE_USE_WRAPPERS
			return MT_GetSubTreeSize_hook.invoke<int>(inst, nodeNum);
#else
			return codsrc::MT_GetSubTreeSize(inst, nodeNum);
#endif
		}

		void MT_DumpTree_stub(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_MEMORYTREE_USE_WRAPPERS
			MT_DumpTree_hook.invoke<void>(a1);
#else
			codsrc::MT_DumpTree(a1);
#endif
		}

		void MT_InitBits_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_MEMORYTREE_USE_WRAPPERS
			game::MT_InitBits(a1, MT_InitBits_original);
#else
			codsrc::MT_InitBits(a1);
#endif
		}

		// void __usercall MT_InitBits(scriptInstance_t a1@<ecx>)
		NAKED void MT_InitBits_stub()
		{
			_asm
			{
				push ecx;
				call MT_InitBits_call;
				add esp, 0x4;
				ret;
			}
		}

		int MT_GetScore_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, int num)
		{
#ifdef RE_CSCR_MEMORYTREE_USE_WRAPPERS
			return game::MT_GetScore(a1, num, MT_GetScore_original);
#else
			return codsrc::MT_GetScore(a1, num);
#endif
		}


		// int __usercall MT_GetScore@<eax>(scriptInstance_t a1@<edx>, int num)
		NAKED int MT_GetScore_stub()
		{
			_asm
			{
				push edx;
				call MT_GetScore_call;
				add esp, 0x4;
				ret;
			}
		}

		void MT_AddMemoryNode_stub(game::scriptInstance_t inst, int newNode, int size, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_MEMORYTREE_USE_WRAPPERS
			MT_AddMemoryNode_hook.invoke<void>(inst, newNode, size);
#else
			codsrc::MT_AddMemoryNode(inst, newNode, size);
#endif
	}

		char MT_RemoveMemoryNode_stub(game::scriptInstance_t inst, int oldNode, int size, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_MEMORYTREE_USE_WRAPPERS
			return MT_RemoveMemoryNode_hook.invoke<char>(inst, oldNode, size);
#else
			return codsrc::MT_RemoveMemoryNode(inst, oldNode, size);
#endif
		}

		void MT_RemoveHeadMemoryNode_stub(game::scriptInstance_t inst, int size, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_MEMORYTREE_USE_WRAPPERS
			MT_RemoveHeadMemoryNode_hook.invoke<void>(inst, size);
#else
			codsrc::MT_RemoveHeadMemoryNode(inst, size);
#endif
		}

		void MT_Init_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_MEMORYTREE_USE_WRAPPERS
			game::MT_Init(a1, MT_Init_original);
#else
			codsrc::MT_Init(a1);
#endif
		}

		// void __usercall MT_Init(scriptInstance_t a1@<edi>)
		NAKED void MT_Init_stub()
		{
			_asm
			{
				push edi;
				call MT_Init_call;
				add esp, 0x4;
				ret;
			}
		}

		void MT_Error_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, const char* funcName, int numBytes)
		{
#ifdef RE_CSCR_MEMORYTREE_USE_WRAPPERS
			game::MT_Error(a1, funcName, numBytes, MT_Error_original);
#else
			codsrc::MT_Error(a1, funcName, numBytes);
#endif
		}

		// void __usercall MT_Error(scriptInstance_t a1@<eax>, const char *funcName, int numBytes)
		NAKED void MT_Error_stub()
		{
			_asm
			{
				push eax;
				call MT_Error_call;
				add esp, 0x4;
				ret;
			}
		}

		int MT_GetSize_call(int numBytes, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_MEMORYTREE_USE_WRAPPERS
			return game::MT_GetSize(numBytes, inst, MT_GetSize_original);
#else
			return codsrc::MT_GetSize(numBytes, inst);
#endif
		}

		// int __usercall MT_GetSize@<eax>(int numBytes@<eax>, scriptInstance_t inst@<ecx>)
		NAKED int MT_GetSize_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call MT_GetSize_call;
				add esp, 0x8;
				ret;
			}
		}

		unsigned __int16 MT_AllocIndex_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, int size_)
		{
#ifdef RE_CSCR_MEMORYTREE_USE_WRAPPERS
			return game::MT_AllocIndex(inst, size_, MT_AllocIndex_original);
#else
			return codsrc::MT_AllocIndex(inst, size_);
#endif
		}

		// unsigned __int16 __usercall MT_AllocIndex@<ax>(scriptInstance_t inst@<edi>, int size)
		NAKED unsigned __int16 MT_AllocIndex_stub()
		{
			_asm
			{
				push edi;
				call MT_AllocIndex_call;
				add esp, 0x4;
				ret;
			}
		}

		void MT_FreeIndex_call(int numBytes, [[maybe_unused]] void* caller_addr, game::scriptInstance_t a1, int nodeNum)
		{
#ifdef RE_CSCR_MEMORYTREE_USE_WRAPPERS
			game::MT_FreeIndex(numBytes, a1, nodeNum, MT_FreeIndex_original);
#else
			codsrc::MT_FreeIndex(numBytes, a1, nodeNum);
#endif
		}

		// void __usercall MT_FreeIndex(int numBytes@<eax>, scriptInstance_t a1, int nodeNum)
		NAKED void MT_FreeIndex_stub()
		{
			_asm
			{
				push eax;
				call MT_FreeIndex_call;
				add esp, 0x4;
				ret;
			}
		}

		char* MT_Alloc_call(int numBytes, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_MEMORYTREE_USE_WRAPPERS
			return game::MT_Alloc(numBytes, inst, MT_Alloc_original);
#else
			return codsrc::MT_Alloc(numBytes, inst);
#endif
		}

		// char *__usercall MT_Alloc@<eax>(int numBytes@<eax>, scriptInstance_t a2@<ecx>)
		NAKED char * MT_Alloc_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call MT_Alloc_call;
				add esp, 0x8;
				ret;
			}
		}

		void MT_Free_stub(void* p, int numBytes, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_MEMORYTREE_USE_WRAPPERS
			MT_Free_hook.invoke<void>(p, numBytes, inst);
#else
			codsrc::MT_Free(p, numBytes, inst);
#endif
		}
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			MT_GetSubTreeSize_hook.create(game::MT_GetSubTreeSize.get(), MT_GetSubTreeSize_stub);
			MT_DumpTree_hook.create(game::MT_DumpTree.get(), MT_DumpTree_stub);
			MT_InitBits_hook.create(game::MT_InitBits_ADDR(), MT_InitBits_stub);
			MT_GetScore_hook.create(game::MT_GetScore_ADDR(), MT_GetScore_stub);
			MT_AddMemoryNode_hook.create(game::MT_AddMemoryNode.get(), MT_AddMemoryNode_stub);
			MT_RemoveMemoryNode_hook.create(game::MT_RemoveMemoryNode.get(), MT_RemoveMemoryNode_stub);
			MT_RemoveHeadMemoryNode_hook.create(game::MT_RemoveHeadMemoryNode.get(), MT_RemoveHeadMemoryNode_stub);
			MT_Init_hook.create(game::MT_Init_ADDR(), MT_Init_stub);
			MT_Error_hook.create(game::MT_Error_ADDR(), MT_Error_stub);
			MT_GetSize_hook.create(game::MT_GetSize_ADDR(), MT_GetSize_stub);
			MT_AllocIndex_hook.create(game::MT_AllocIndex_ADDR(), MT_AllocIndex_stub);
			MT_FreeIndex_hook.create(game::MT_FreeIndex_ADDR(), MT_FreeIndex_stub);
			MT_Alloc_hook.create(game::MT_Alloc_ADDR(), MT_Alloc_stub);
			MT_Free_hook.create(game::MT_Free.get(), MT_Free_stub);

			//Original hook function addresses
			MT_GetSubTreeSize_original = MT_GetSubTreeSize_hook.get_original();
			MT_DumpTree_original = MT_DumpTree_hook.get_original();
			MT_InitBits_original = MT_InitBits_hook.get_original();
			MT_GetScore_original = MT_GetScore_hook.get_original();
			MT_AddMemoryNode_original = MT_AddMemoryNode_hook.get_original();
			MT_RemoveMemoryNode_original = MT_RemoveMemoryNode_hook.get_original();
			MT_RemoveHeadMemoryNode_original = MT_RemoveHeadMemoryNode_hook.get_original();
			MT_Init_original = MT_Init_hook.get_original();
			MT_Error_original = MT_Error_hook.get_original();
			MT_GetSize_original = MT_GetSize_hook.get_original();
			MT_AllocIndex_original = MT_AllocIndex_hook.get_original();
			MT_FreeIndex_original = MT_FreeIndex_hook.get_original();
			MT_Alloc_original = MT_Alloc_hook.get_original();
			MT_Free_original = MT_Free_hook.get_original();
		}

	private:
	};
}
REGISTER_COMPONENT(re_cscr_memorytree::component)