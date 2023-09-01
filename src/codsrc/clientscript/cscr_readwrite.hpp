#pragma once

namespace codsrc
{
	unsigned int FindVariableIndexInternal2(game::scriptInstance_t inst, unsigned int name, unsigned int index);
	unsigned int FindLastSibling(unsigned int parentId, game::scriptInstance_t inst);
	unsigned int FindVariableIndexInternal(game::scriptInstance_t inst, unsigned int parentId, unsigned int name);
}
