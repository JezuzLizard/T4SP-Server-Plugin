#include <stdinc.hpp>
#include "loader/component_loader.hpp"
#include "utils/hook.hpp"
#include "codsrc/clientscript/cscr_readwrite.hpp"

#ifndef DISABLE_RE_CSCR_READWRITE
namespace re_cscr_readwrite
{
	utils::hook::detour FindVariableIndexInternal2_hook;
	utils::hook::detour FindLastSibling_hook;

	namespace
	{

		unsigned int FindVariableIndexInternal2_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, unsigned int name, unsigned int index)
		{
#ifdef RE_CSCR_READWRITE_USE_WRAPPERS
			return game::FindVariableIndexInternal2(inst, name, index, FindVariableIndexInternal2_hook.get_original());
#else
			return codsrc::FindVariableIndexInternal2(inst, name, index);
#endif
		}

		// unsigned int __usercall FindVariableIndexInternal2@<eax>(scriptInstance_t inst@<eax>, unsigned int name, unsigned int index)
		NAKED unsigned int FindVariableIndexInternal2_stub()
		{
			_asm
			{
				push eax;
				call FindVariableIndexInternal2_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int FindLastSibling_call(unsigned int parentId, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_READWRITE_USE_WRAPPERS
			return game::FindLastSibling(parentId, inst, FindLastSibling_hook.get_original());
#else
			return codsrc::FindLastSibling(parentId, inst);
#endif
		}

		// unsigned int __usercall FindLastSibling@<eax>(unsigned int parentId@<edx>, scriptInstance_t inst@<esi>)
		NAKED unsigned int FindLastSibling_stub()
		{
			_asm
			{
				push esi;
				push edx;
				call FindLastSibling_call;
				add esp, 0x8;
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
#ifdef RE_CSCR_READWRITE_USE_WRAPPERS
			quick = false;
#endif

			FindVariableIndexInternal2_hook.create(game::FindVariableIndexInternal2_ADDR(), FindVariableIndexInternal2_stub, quick);
			FindLastSibling_hook.create(game::FindLastSibling_ADDR(), FindLastSibling_stub, quick);
		}

	private:
	};
}
REGISTER_COMPONENT(re_cscr_readwrite::component)
#endif
