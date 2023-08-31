#pragma once

namespace game
{
	inline void* FindVariableIndexInternal2_ADDR() { return CALL_ADDR(0x0, 0x68BC20); }
	unsigned int FindVariableIndexInternal2(scriptInstance_t inst, unsigned int name, unsigned int index, void* call_addr = FindVariableIndexInternal2_ADDR());
	inline void* FindLastSibling_ADDR() { return CALL_ADDR(0x0, 0x68BCA0); }
	unsigned int FindLastSibling(unsigned int parentId, scriptInstance_t inst, void* call_addr = FindLastSibling_ADDR());

	unsigned int FindVariableIndexInternal(scriptInstance_t inst, unsigned int parentId, unsigned int name);
}