#include <stdinc.hpp>
#include "loader/component_loader.hpp"
#include "utils/hook.hpp"
#include "codsrc/clientscript/cscr_parsetree.hpp"

#ifndef DISABLE_RE_CSCR_PARSETREE
namespace re_cscr_parsetree
{
	utils::hook::detour Scr_InitAllocNode_hook;
	utils::hook::detour node0_hook;
	utils::hook::detour node1_hook;
	utils::hook::detour node2_hook;
	utils::hook::detour node3_hook;
	utils::hook::detour node4_hook;
	utils::hook::detour node5_hook;
	utils::hook::detour node6_hook;
	utils::hook::detour node7_hook;
	utils::hook::detour node8_hook;
	utils::hook::detour linked_list_end_hook;
	utils::hook::detour prepend_node_hook;
	utils::hook::detour append_node_hook;

	namespace
	{

		void Scr_InitAllocNode_stub(game::scriptInstance_t inst)
		{
#ifdef RE_CSCR_PARSETREE_USE_WRAPPERS
			Scr_InitAllocNode_hook.invoke<void>(inst);
#else
			codsrc::Scr_InitAllocNode(inst);
#endif
		}

		game::sval_u node0_stub()
		{
#ifdef RE_CSCR_PARSETREE_USE_WRAPPERS
			return node0_hook.invoke<game::sval_u>();
#else
			return codsrc::node0();
#endif
		}

		game::sval_u node1_stub(game::scr_enum_t type, game::sval_u val1)
		{
#ifdef RE_CSCR_PARSETREE_USE_WRAPPERS
			return node1_hook.invoke<game::sval_u>(type, val1);
#else
			return codsrc::node1(type, val1);
#endif
		}

		game::sval_u node2_stub(game::scr_enum_t type, game::sval_u val1, game::sval_u val2)
		{
#ifdef RE_CSCR_PARSETREE_USE_WRAPPERS
			return node2_hook.invoke<game::sval_u>(type, val1, val2);
#else
			return codsrc::node2(type, val1, val2);
#endif
		}

		game::sval_u node3_stub(game::scr_enum_t type, game::sval_u val1, game::sval_u val2, game::sval_u val3)
		{
#ifdef RE_CSCR_PARSETREE_USE_WRAPPERS
			return node3_hook.invoke<game::sval_u>(type, val1, val2, val3);
#else
			return codsrc::node3(type, val1, val2, val3);
#endif
		}

		game::sval_u node4_stub(game::scr_enum_t type, game::sval_u val1, game::sval_u val2, game::sval_u val3, game::sval_u val4)
		{
#ifdef RE_CSCR_PARSETREE_USE_WRAPPERS
			return node4_hook.invoke<game::sval_u>(type, val1, val2, val3, val4);
#else
			return codsrc::node4(type, val1, val2, val3, val4);
#endif
		}

		game::sval_u node5_stub(game::scr_enum_t type, game::sval_u val1, game::sval_u val2, game::sval_u val3, game::sval_u val4, game::sval_u val5)
		{
#ifdef RE_CSCR_PARSETREE_USE_WRAPPERS
			return node5_hook.invoke<game::sval_u>(type, val1, val2, val3, val4, val5);
#else
			return codsrc::node5(type, val1, val2, val3, val4, val5);
#endif
		}

		game::sval_u node6_stub(game::sval_u val1, game::sval_u val2, game::sval_u val3, game::sval_u val4, game::sval_u val5, game::sval_u val6)
		{
#ifdef RE_CSCR_PARSETREE_USE_WRAPPERS
			return node6_hook.invoke<game::sval_u>(val1, val2, val3, val4, val5, val6);
#else
			return codsrc::node6(val1, val2, val3, val4, val5, val6);
#endif
		}

		game::sval_u node7_stub(game::sval_u val1, game::sval_u val2, game::sval_u val3, game::sval_u val4, game::sval_u val5, game::sval_u val6, game::sval_u val7)
		{
#ifdef RE_CSCR_PARSETREE_USE_WRAPPERS
			return node7_hook.invoke<game::sval_u>(val1, val2, val3, val4, val5, val6, val7);
#else
			return codsrc::node7(val1, val2, val3, val4, val5, val6, val7);
#endif
		}

		game::sval_u node8_stub(game::sval_u val1, game::sval_u val2, game::sval_u val3, game::sval_u val4, game::sval_u val5, game::sval_u val6, game::sval_u val7, game::sval_u val8)
		{
#ifdef RE_CSCR_PARSETREE_USE_WRAPPERS
			return node8_hook.invoke<game::sval_u>(val1, val2, val3, val4, val5, val6, val7, val8);
#else
			return codsrc::node8(val1, val2, val3, val4, val5, val6, val7, val8);
#endif
		}

		game::sval_u linked_list_end_stub(game::sval_u val1)
		{
#ifdef RE_CSCR_PARSETREE_USE_WRAPPERS
			return linked_list_end_hook.invoke<game::sval_u>(val1);
#else
			return codsrc::linked_list_end(val1);
#endif
		}

		game::sval_u prepend_node_stub(game::sval_u val1, game::sval_u val2)
		{
#ifdef RE_CSCR_PARSETREE_USE_WRAPPERS
			return prepend_node_hook.invoke<game::sval_u>(val1, val2);
#else
			return codsrc::prepend_node(val1, val2);
#endif
		}

		game::sval_u append_node_stub(game::sval_u val1, game::sval_u val2)
		{
#ifdef RE_CSCR_PARSETREE_USE_WRAPPERS
			return append_node_hook.invoke<game::sval_u>(val1, val2);
#else
			return codsrc::append_node(val1, val2);
#endif
		}
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			bool quick = true;
#ifdef RE_CSCR_PARSETREE_USE_WRAPPERS
			quick = false;
#endif

			Scr_InitAllocNode_hook.create(game::Scr_InitAllocNode.get(), Scr_InitAllocNode_stub, quick);
			node0_hook.create(game::node0.get(), node0_stub, quick);
			node1_hook.create(game::node1.get(), node1_stub, quick);
			node2_hook.create(game::node2.get(), node2_stub, quick);
			node3_hook.create(game::node3.get(), node3_stub, quick);
			node4_hook.create(game::node4.get(), node4_stub, quick);
			node5_hook.create(game::node5.get(), node5_stub, quick);
			node6_hook.create(game::node6.get(), node6_stub, quick);
			node7_hook.create(game::node7.get(), node7_stub, quick);
			node8_hook.create(game::node8.get(), node8_stub, quick);
			linked_list_end_hook.create(game::linked_list_end.get(), linked_list_end_stub, quick);
			prepend_node_hook.create(game::prepend_node.get(), prepend_node_stub, quick);
			append_node_hook.create(game::append_node.get(), append_node_stub, quick);
		}

	private:
	};
}
REGISTER_COMPONENT(re_cscr_parsetree::component)
#endif
