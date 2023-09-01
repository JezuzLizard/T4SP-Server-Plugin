#include <stdinc.hpp>
#include "clientscript_public.hpp"

namespace codsrc
{
	// Restored
	unsigned int FindVariableIndexInternal(game::scriptInstance_t inst, unsigned int parentId, unsigned int name)
	{
		game::VariableValueInternal* parentValue;

		assert(parentId);

		parentValue = &game::gScrVarGlob[inst].parentVariables[parentId + 1];

		assert((parentValue->w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL);

		assert((parentValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(IsObject(parentValue));

		return game::FindVariableIndexInternal2(inst, name, (parentId + name) % 0xFFFD + 1);
	}

	// Decomp Status: Tested, Completed
	unsigned int FindVariableIndexInternal2(game::scriptInstance_t inst, unsigned int name, unsigned int index)
	{
		unsigned int newIndex;
		game::VariableValueInternal* newEntryValue;
		game::VariableValueInternal* entryValue;
		game::Variable* entry;

		entry = &game::gScrVarGlob[inst].childVariables[index].hash;

		entryValue = &game::gScrVarGlob[inst].childVariables[entry->id];

		assert((name & VAR_NAME_LOW_MASK) == 0);

		assert(index < VARIABLELIST_CHILD_SIZE);

		assert(entry->id < VARIABLELIST_CHILD_SIZE);

		if ((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_HEAD)
		{
			return 0;
		}

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(!IsObject(entryValue));

		if (entryValue->w.status >> VAR_NAME_BIT_SHIFT == name)
		{
			return index;
		}

		newIndex = entryValue->v.next;

		for (entryValue = &game::gScrVarGlob[inst].childVariables[newIndex];
			entryValue != &game::gScrVarGlob[inst].childVariables[index];
			entryValue = &game::gScrVarGlob[inst].childVariables[newIndex])
		{
			newEntryValue = &game::gScrVarGlob[inst].childVariables[entryValue->hash.id];

			assert((newEntryValue->w.status & VAR_STAT_MASK) == VAR_STAT_MOVABLE);

			assert((newEntryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

			assert(!IsObject(newEntryValue));

			if (newEntryValue->w.status >> VAR_NAME_BIT_SHIFT == name)
			{
				return newIndex;
			}

			newIndex = newEntryValue->v.next;
		}

		return 0;
	}

	// Decomp Status: Tested, Completed
	unsigned int FindLastSibling(unsigned int parentId, game::scriptInstance_t inst)
	{
		game::VariableValueInternal* parentValue;
		unsigned int nextParentVarIndex;
		unsigned int id;
		unsigned int childVarName;
		unsigned int index;

		assert(parentId);

		parentValue = &game::gScrVarGlob[inst].parentVariables[parentId + 1];

		assert((parentValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(IsObject(parentValue));

		assert(((parentValue->w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL));

		nextParentVarIndex = parentValue->v.next + 1;

		id = game::gScrVarGlob[inst].parentVariables[nextParentVarIndex].hash.u.prev;

		if (!id)
		{
			return 0;
		}

		childVarName = game::gScrVarGlob[inst].childVariables[id].w.status >> VAR_NAME_BIT_SHIFT;

		index = game::FindVariableIndexInternal(inst, parentId, childVarName);

		assert(index);

		return index;
	}
}