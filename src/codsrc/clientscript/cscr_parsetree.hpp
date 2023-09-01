#pragma once

namespace codsrc
{
	void Scr_InitAllocNode(game::scriptInstance_t inst);
	game::sval_u* Scr_AllocNode(game::scriptInstance_t inst, int size);
	game::sval_u node0();
	game::sval_u node1(game::scr_enum_t type, game::sval_u val1);
	game::sval_u node2(game::scr_enum_t type, game::sval_u val1, game::sval_u val2);
	game::sval_u node3(game::scr_enum_t type, game::sval_u val1, game::sval_u val2, game::sval_u val3);
	game::sval_u node4(game::scr_enum_t type, game::sval_u val1, game::sval_u val2, game::sval_u val3, game::sval_u val4);
	game::sval_u node5(game::scr_enum_t type, game::sval_u val1, game::sval_u val2, game::sval_u val3, game::sval_u val4, game::sval_u val5);
	game::sval_u node6(game::sval_u val1, game::sval_u val2, game::sval_u val3, game::sval_u val4, game::sval_u val5, game::sval_u val6);
	game::sval_u node7(game::sval_u val1, game::sval_u val2, game::sval_u val3, game::sval_u val4, game::sval_u val5, game::sval_u val6, game::sval_u val7);
	game::sval_u node8(game::sval_u val1, game::sval_u val2, game::sval_u val3, game::sval_u val4, game::sval_u val5, game::sval_u val6, game::sval_u val7, game::sval_u val8);
	game::sval_u linked_list_end(game::sval_u val1);
	game::sval_u prepend_node(game::sval_u val1, game::sval_u val2);
	game::sval_u append_node(game::sval_u val1, game::sval_u val2);
}
