#include <stdinc.hpp>
#include "clientscript_public.hpp"

namespace codsrc
{
	// Decomp Status: Tested, Completed
	void Scr_InitAllocNode(game::scriptInstance_t inst)
	{
		game::HunkUser* nodeUser;

		assert(!game::g_allocNodeUser[inst]);

		nodeUser = game::Hunk_UserCreate(0x10000, "Scr_InitAllocNode", false, true, false, 7);
		game::g_allocNodeUser[inst] = nodeUser;
	}

	// Restored function
	game::sval_u* Scr_AllocNode(game::scriptInstance_t inst, int size)
	{
		assert(game::g_allocNodeUser[inst]);

		return (game::sval_u*)game::Hunk_UserAlloc(game::g_allocNodeUser[inst], 4 * size, 4);
	}

	// Decomp Status: Tested, Completed
	game::sval_u node0()
	{
		game::sval_u result;

		result.node = game::Scr_AllocNode(*game::gInst, 1);
		result.node[0].intValue = game::ENUM_NOP;
		return result;
	}

	// Decomp Status: Tested, Completed
	game::sval_u node1(game::scr_enum_t type, game::sval_u val1)
	{
		game::sval_u result;

		result.node = game::Scr_AllocNode(*game::gInst, 2);
		result.node[0].intValue = type;
		result.node[1].node = val1.node;
		return result;
	}

	// Decomp Status: Tested, Completed
	game::sval_u node2(game::scr_enum_t type, game::sval_u val1, game::sval_u val2)
	{
		game::sval_u result;

		result.node = game::Scr_AllocNode(*game::gInst, 3);
		result.node[0].intValue = type;
		result.node[1].node = val1.node;
		result.node[2].node = val2.node;
		return result;
	}

	// Decomp Status: Tested, Completed
	game::sval_u node3(game::scr_enum_t type, game::sval_u val1, game::sval_u val2, game::sval_u val3)
	{
		game::sval_u result;

		result.node = game::Scr_AllocNode(*game::gInst,4);
		result.node[0].intValue = type;
		result.node[1].node = val1.node;
		result.node[2].node = val2.node;
		result.node[3].node = val3.node;
		return result;
	}

	// Decomp Status: Tested, Completed
	game::sval_u node4(game::scr_enum_t type, game::sval_u val1, game::sval_u val2, game::sval_u val3, game::sval_u val4)
	{
		game::sval_u result;

		result.node = game::Scr_AllocNode(*game::gInst, 5);
		result.node[0].intValue = type;
		result.node[1].node = val1.node;
		result.node[2].node = val2.node;
		result.node[3].node = val3.node;
		result.node[4].node = val4.node;
		return result;
	}

	// Decomp Status: Tested, Completed
	game::sval_u node5(game::scr_enum_t type, game::sval_u val1, game::sval_u val2, game::sval_u val3, game::sval_u val4, game::sval_u val5)
	{
		game::sval_u result;

		result.node = game::Scr_AllocNode(*game::gInst, 6);
		result.node[0].intValue = type;
		result.node[1].node = val1.node;
		result.node[2].node = val2.node;
		result.node[3].node = val3.node;
		result.node[4].node = val4.node;
		result.node[5].node = val5.node;
		return result;
	}

	// Decomp Status: Tested, Completed
	game::sval_u node6(game::sval_u val1, game::sval_u val2, game::sval_u val3, game::sval_u val4, game::sval_u val5, game::sval_u val6)
	{
		game::sval_u result;

		result.node = game::Scr_AllocNode(*game::gInst, 7);
		result.node[0].intValue = game::ENUM_thread;
		result.node[1].node = val1.node;
		result.node[2].node = val2.node;
		result.node[3].node = val3.node;
		result.node[4].node = val4.node;
		result.node[5].node = val5.node;
		result.node[6].node = val6.node;
		return result;
	}

	// Decomp Status: Tested, Completed
	game::sval_u node7(game::sval_u val1, game::sval_u val2, game::sval_u val3, game::sval_u val4, game::sval_u val5, game::sval_u val6, game::sval_u val7)
	{
		game::sval_u result;

		result.node = game::Scr_AllocNode(*game::gInst, 8);
		result.node[0].intValue = game::ENUM_if_else;
		result.node[1].node = val1.node;
		result.node[2].node = val2.node;
		result.node[3].node = val3.node;
		result.node[4].node = val4.node;
		result.node[5].node = val5.node;
		result.node[6].node = val6.node;
		result.node[7].node = val7.node;
		return result;
	}

	// Decomp Status: Tested, Completed
	game::sval_u node8(game::sval_u val1, game::sval_u val2, game::sval_u val3, game::sval_u val4, game::sval_u val5, game::sval_u val6, game::sval_u val7, game::sval_u val8)
	{
		game::sval_u result;

		result.node = game::Scr_AllocNode(*game::gInst, 9);
		result.node[0].intValue = game::ENUM_for;
		result.node[1].node = val1.node;
		result.node[2].node = val2.node;
		result.node[3].node = val3.node;
		result.node[4].node = val4.node;
		result.node[5].node = val5.node;
		result.node[6].node = val6.node;
		result.node[7].node = val7.node;
		result.node[8].node = val8.node;
		return result;
	}

	// Decomp Status: Tested, Completed
	game::sval_u linked_list_end(game::sval_u val1)
	{
		game::sval_u* node;
		game::sval_u result;

		node = game::Scr_AllocNode(*game::gInst, 2);
		node[0].node = val1.node;
		node[1].stringValue = 0;
		result.node = game::Scr_AllocNode(*game::gInst, 2);
		result.node[0].node = node;
		result.node[1].node = node;
		return result;
	}

	// Decomp Status: Tested, Completed
	game::sval_u prepend_node(game::sval_u val1, game::sval_u val2)
	{
		game::sval_u* node;

		node = game::Scr_AllocNode(*game::gInst, 2);
		node[0] = val1;
		node[1] = *val2.node;
		val2.node->node = node;
		return val2;
	}

	// Decomp Status: Tested, Completed
	game::sval_u append_node(game::sval_u val1, game::sval_u val2)
	{
		game::sval_u* node;

		node = game::Scr_AllocNode(*game::gInst, 2);
		node[0] = val2;
		node[1].stringValue = 0;
		val1.node[1].node[1].stringValue = (unsigned int)node;
		val1.node[1].node = node;
		return val1;
	}

}
