#pragma once

namespace game
{
	WEAK symbol<void(scriptInstance_t inst)>Scr_InitAllocNode{ 0x0, 0x68B870};
	WEAK symbol<sval_u()>node0{ 0x0, 0x68B900};
	WEAK symbol<sval_u(scr_enum_t type, sval_u val1)>node1{ 0x0, 0x68B920};
	WEAK symbol<sval_u(scr_enum_t type, sval_u val1, sval_u val2)>node2{ 0x0, 0x68B950};
	WEAK symbol<sval_u(scr_enum_t type, sval_u val1, sval_u val2, sval_u val3)>node3{ 0x0, 0x68B980};
	WEAK symbol<sval_u(scr_enum_t type, sval_u val1, sval_u val2, sval_u val3, sval_u val4)>node4{ 0x0, 0x68B9C0};
	WEAK symbol<sval_u(scr_enum_t type, sval_u val1, sval_u val2, sval_u val3, sval_u val4, sval_u val5)>node5{ 0x0, 0x68BA00};
	WEAK symbol<sval_u(sval_u val1, sval_u val2, sval_u val3, sval_u val4, sval_u val5, sval_u val6)>node6{ 0x0, 0x68BA50};
	WEAK symbol<sval_u(sval_u val1, sval_u val2, sval_u val3, sval_u val4, sval_u val5, sval_u val6, sval_u val7)>node7{ 0x0, 0x68BAA0};
	WEAK symbol<sval_u(sval_u val1, sval_u val2, sval_u val3, sval_u val4, sval_u val5, sval_u val6, sval_u val7, sval_u val8)>node8{ 0x0, 0x68BB00};
	WEAK symbol<sval_u(sval_u val1)>linked_list_end{ 0x0, 0x68BB60};
	WEAK symbol<sval_u(sval_u val1, sval_u val2)>prepend_node{ 0x0, 0x68BBB0};
	WEAK symbol<sval_u(sval_u val1, sval_u val2)>append_node{ 0x0, 0x68BBE0};

	sval_u* Scr_AllocNode(scriptInstance_t inst, int size);
}
