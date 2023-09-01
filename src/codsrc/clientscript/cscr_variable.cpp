#include <stdinc.hpp>
#include "clientscript_public.hpp"

#pragma warning(push)
#pragma warning(disable: 4244)

namespace codsrc
{
	// Decomp Status: Completed
	int ThreadInfoCompare(const void* a1, const void* a2)
	{
		const char* pos1;
		int i;
		const char* pos2;
		game::ThreadDebugInfo* info1, * info2;
		info1 = (game::ThreadDebugInfo*)a1;
		info2 = (game::ThreadDebugInfo*)a2;

		for (i = 0; ; ++i)
		{
			if (i >= info1->posSize || i >= info2->posSize)
			{
				return info1->posSize - info2->posSize;
			}
			pos1 = info1->pos[i];
			pos2 = info2->pos[i];
			if (pos1 != pos2)
			{
				break;
			}
		}
		return pos1 - pos2;
	}

	// Restored
	unsigned int FindFirstSibling(game::scriptInstance_t inst, unsigned int id)
	{
		game::VariableValueInternal* entryValue;

		entryValue = &game::gScrVarGlob[inst].parentVariables[id + 1];

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(IsObject(entryValue));

		return entryValue->nextSibling;
	}

	// Restored
	unsigned int FindNextSibling(game::scriptInstance_t inst, unsigned int id)
	{
		unsigned int nextSibling;
		game::VariableValueInternal* list;
		unsigned int childId;
		game::VariableValueInternal* entryValue;
		game::VariableValueInternal* childValue;

		list = game::gScrVarGlob[inst].childVariables;
		entryValue = &list[id];

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(!IsObject(entryValue));

		nextSibling = entryValue->nextSibling;

		if (!nextSibling)
		{
			return 0;
		}

		childId = list[nextSibling].hash.id;

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		childValue = &list[childId];

		assert(!IsObject(childValue));

		return childId;
	}

	// Decomp Status: Completed
	void Scr_DumpScriptThreads(game::scriptInstance_t inst)
	{
		float objectUsage;
		int j;
		int ja;
		unsigned int classnum;
		const char* pos;
		int info[32];
		int infoIndex;
		float infoArrayVarUsage;
		float infoArrayEndonUsage;
		const char* buf;
		int size;
		game::VariableValueInternal* entryValue;
		game::ThreadDebugInfo* pInfo;
		int num;
		char type;
		game::VariableUnion u;
		int i;
		game::VariableStackBuffer* stackBuf;
		unsigned int entId;
		game::ThreadDebugInfo* infoArray;
		int count;
		float endonUsage;
		unsigned int id;
		float varUsage;

		num = 0;
		for (id = 1;
			id < VARIABLELIST_CHILD_SIZE - 1;
			++id)
		{
			entryValue = &game::gScrVarGlob[inst].childVariables[id];
			if ((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE && (entryValue->w.status & VAR_MASK) == game::VAR_STACK)
			{
				++num;
			}
		}

		if (num)
		{
			infoArray = (game::ThreadDebugInfo*)game::Z_TryVirtualAlloc(sizeof(game::ThreadDebugInfo) * num);
			if (infoArray)
			{
				num = 0;
				for (id = 1;
					id < VARIABLELIST_CHILD_SIZE - 1;
					++id)
				{
					entryValue = &game::gScrVarGlob[inst].childVariables[id];
					if ((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE && (entryValue->w.status & VAR_MASK) == game::VAR_STACK)
					{
						pInfo = &infoArray[num++];
						infoIndex = 0;
						stackBuf = entryValue->u.u.stackValue;
						size = stackBuf->size;
						pos = stackBuf->pos;
						buf = stackBuf->buf;

						while (size)
						{
							--size;
							type = *buf++;
							u.intValue = *(int*)buf;
							buf += 4;
							if (type == game::VAR_CODEPOS)
							{
								info[infoIndex++] = u.intValue;
							}
						}

						info[infoIndex++] = (int)pos;
						pInfo->varUsage = game::Scr_GetThreadUsage(stackBuf, inst, &pInfo->endonUsage);
						pInfo->posSize = infoIndex--;

						for (j = 0;
							j < pInfo->posSize;
							++j)
						{
							pInfo->pos[j] = (const char*)info[infoIndex - j];
						}
					}
				}

				qsort(infoArray, num, sizeof(game::ThreadDebugInfo), game::ThreadInfoCompare);
				game::Com_Printf(game::CON_CHANNEL_PARSERSCRIPT, "********************************\n");
				varUsage = 0.0f;
				endonUsage = 0.0f;
				i = 0;

				while (i < num)
				{
					pInfo = &infoArray[i];
					count = 0;
					infoArrayVarUsage = 0.0f;
					infoArrayEndonUsage = 0.0f;

					do
					{
						++count;
						infoArrayVarUsage = infoArrayVarUsage + infoArray[i].varUsage;
						infoArrayEndonUsage = infoArrayEndonUsage + infoArray[i++].endonUsage;
					} while (i < num && !game::ThreadInfoCompare(pInfo, &infoArray[i]));

					varUsage = varUsage + infoArrayVarUsage;
					endonUsage = endonUsage + infoArrayEndonUsage;
					game::Com_Printf(game::CON_CHANNEL_PARSERSCRIPT, "count: %d, var usage: %d, endon usage: %d\n", count, (int)infoArrayVarUsage, (int)infoArrayEndonUsage);
					game::Scr_PrintPrevCodePos(pInfo->pos[0], inst, game::CON_CHANNEL_PARSERSCRIPT, 0);

					for (ja = 1;
						ja < pInfo->posSize;
						++ja)
					{
						game::Com_Printf(game::CON_CHANNEL_PARSERSCRIPT, "called from:\n");
						game::Scr_PrintPrevCodePos(pInfo->pos[ja], inst, game::CON_CHANNEL_PARSERSCRIPT, 0);
					}
				}

				VirtualFree(infoArray, 0, 0x8000u); // Z_VirtualFree Z_VirtualFreeInternal
				game::Com_Printf(game::CON_CHANNEL_PARSERSCRIPT, "********************************\n");
				game::Com_Printf(game::CON_CHANNEL_PARSERSCRIPT, "var usage: %d, endon usage: %d\n", (int)varUsage, (int)endonUsage);
				game::Com_Printf(game::CON_CHANNEL_PARSERSCRIPT, "\n");

				for (classnum = 0;
					classnum < game::CLASS_NUM_COUNT;
					++classnum)
				{
					if (game::gScrClassMap[inst][classnum].entArrayId)
					{
						infoArrayVarUsage = 0.0f;
						count = 0;
						for (entId = game::FindFirstSibling(inst, game::gScrClassMap[inst][classnum].entArrayId);
							entId;
							entId = game::FindNextSibling(inst, entId))
						{
							++count;
							if ((game::gScrVarGlob[inst].childVariables[entId].w.status & VAR_MASK) == game::VAR_POINTER)
							{
								objectUsage = game::Scr_GetObjectUsage(inst, game::gScrVarGlob[inst].childVariables[entId].u.u.intValue);
								infoArrayVarUsage = objectUsage + infoArrayVarUsage;
							}
						}

						game::Com_Printf(game::CON_CHANNEL_PARSERSCRIPT, "ent type '%s'... count: %d, var usage: %d\n", game::gScrClassMap[inst][classnum].name, count, (int)infoArrayVarUsage);
					}
				}

				game::Com_Printf(game::CON_CHANNEL_PARSERSCRIPT, "********************************\n");
			}
			else
			{
				game::Com_Printf(game::CON_CHANNEL_PARSERSCRIPT, "Cannot dump script threads: out of memory\n");
			}
		}
	}

	// Decomp Status: Completed
	void Scr_InitVariableRange(unsigned int begin, unsigned int end, game::scriptInstance_t inst)
	{
		unsigned int index;
		game::VariableValueInternal* value;
		game::VariableValueInternal* valuea;

		for (index = begin + 1;
			index < end;
			++index)
		{
			value = &game::gScrVarGlob[inst].parentVariables[index];
			value->w.status = 0;

			assert(!(value->w.type & VAR_MASK));

			value->hash.id = index - begin;
			value->v.next = index - begin;
			value->u.next = index - begin + 1;
			value->hash.u.prev = index - begin - 1;
		}

		valuea = &game::gScrVarGlob[inst].parentVariables[begin];
		valuea->w.status = 0;

		assert(!(valuea->w.type & VAR_MASK));

		valuea->w.status = valuea->w.status;
		valuea->hash.id = 0;
		valuea->v.next = 0;
		valuea->u.next = 1;
		game::gScrVarGlob[inst].parentVariables[begin + 1].hash.u.prev = 0;
		valuea->hash.u.prev = end - begin - 1;
		game::gScrVarGlob[inst].parentVariables[end - 1].u.next = 0;
	}

	// Decomp Status: Completed
	void Scr_InitClassMap(game::scriptInstance_t inst)
	{
		game::gScrClassMap[inst][game::CLASS_NUM_ENTITY].entArrayId = 0;
		game::gScrClassMap[inst][game::CLASS_NUM_ENTITY].id = 0;
		game::gScrClassMap[inst][game::CLASS_NUM_HUDELEM].entArrayId = 0;
		game::gScrClassMap[inst][game::CLASS_NUM_HUDELEM].id = 0;
		game::gScrClassMap[inst][game::CLASS_NUM_PATHNODE].entArrayId = 0;
		game::gScrClassMap[inst][game::CLASS_NUM_PATHNODE].id = 0;
		game::gScrClassMap[inst][game::CLASS_NUM_VEHICLENODE].entArrayId = 0;
		game::gScrClassMap[inst][game::CLASS_NUM_VEHICLENODE].id = 0;
	}

	// Restored
	game::VariableValue Scr_GetArrayIndexValue([[maybe_unused]] game::scriptInstance_t inst, unsigned int name)
	{
		game::VariableValue value;

		assert(name);

		if (name >= SL_MAX_STRING_INDEX)
		{
			if (name >= OBJECT_STACK)
			{
				value.type = game::VAR_INTEGER;
				value.u.intValue = name - 0x800000;
			}
			else
			{
				value.type = game::VAR_POINTER;
				value.u.intValue = name - SL_MAX_STRING_INDEX;
			}
		}
		else
		{
			value.type = game::VAR_STRING;
			value.u.intValue = (unsigned short)name;
		}

		return value;
	}

	// Decomp Status: Completed
	unsigned int GetNewVariableIndexInternal3(game::scriptInstance_t inst, unsigned int parentId, unsigned int name, unsigned int index)
	{
		game::VariableValueInternal* parentValue;
		game::VariableValueInternal* entry;
		unsigned int newIndex;
		unsigned int newIndexb;
		unsigned int newIndexa;
		unsigned int prevId;
		unsigned int nextSiblingIndex;
		unsigned int prevSiblingIndex;
		unsigned int next;
		unsigned int nexta;
		unsigned int nextb;
		unsigned int nextc;
		unsigned int nextd;
		game::VariableValueInternal* entryValue;
		unsigned int prev;
		unsigned int preva;
		unsigned int prevb;
		game::VariableValueInternal* newEntryValue;
		int type;
		game::VariableValueInternal* newEntrya;
		game::VariableValueInternal* newEntry;
		game::VariableValue value;
		unsigned int id;

		assert((name & VAR_NAME_LOW_MASK) == 0);

		entry = &game::gScrVarGlob[inst].childVariables[index];
		entryValue = &game::gScrVarGlob[inst].childVariables[entry->hash.id];
		type = entryValue->w.status & VAR_STAT_MASK;
		if (type)
		{
			if (type == VAR_STAT_HEAD)
			{
				if ((entry->w.status & VAR_STAT_MASK) != VAR_STAT_FREE)
				{
					index = game::gScrVarGlob[inst].childVariables[0].u.next;
					if (!index)
					{
						game::Scr_TerminalError(inst, "exceeded maximum number of script variables");
					}

					entry = &game::gScrVarGlob[inst].childVariables[index];
					newEntryValue = &game::gScrVarGlob[inst].childVariables[entry->hash.id];

					assert((newEntryValue->w.status & VAR_STAT_MASK) == VAR_STAT_FREE);

					nextb = newEntryValue->u.next;
					game::gScrVarGlob[inst].childVariables[0].u.next = nextb;
					game::gScrVarGlob[inst].childVariables[nextb].hash.u.prev = 0;
					newEntryValue->w.status = VAR_STAT_MOVABLE;
					newEntryValue->v.next = entryValue->v.next;
					entryValue->v.next = index;
				}
				else
				{
					newIndexb = entry->v.next;
					newEntrya = &game::gScrVarGlob[inst].childVariables[newIndexb];
					newEntryValue = &game::gScrVarGlob[inst].childVariables[index];
					preva = newEntrya->hash.u.prev;
					nexta = entry->u.next;
					game::gScrVarGlob[inst].childVariables[game::gScrVarGlob[inst].childVariables[preva].hash.id].u.next = nexta;
					game::gScrVarGlob[inst].childVariables[nexta].hash.u.prev = preva;
					newEntrya->hash.id = entry->hash.id;
					entry->hash.id = index;
					newEntrya->hash.u.prev = entry->hash.u.prev;
					game::gScrVarGlob[inst].childVariables[game::gScrVarGlob[inst].childVariables[newEntrya->hash.u.prev].hash.id].nextSibling = newIndexb;
					game::gScrVarGlob[inst].childVariables[entryValue->nextSibling].hash.u.prev = newIndexb;
					entryValue->w.status = entryValue->w.status & ~VAR_STAT_HEAD | VAR_STAT_MOVABLE;
					entry->w.status = VAR_STAT_HEAD;
				}
			}
			else
			{
				assert(type == VAR_STAT_MOVABLE || type == VAR_STAT_EXTERNAL);

				if ((entry->w.status & VAR_STAT_MASK) != VAR_STAT_FREE)
				{
					newIndexa = game::gScrVarGlob[inst].childVariables[0].u.next;
					if (!newIndexa)
					{
						game::Scr_TerminalError(inst, "exceeded maximum number of script variables");
					}

					newEntry = &game::gScrVarGlob[inst].childVariables[newIndexa];
					newEntryValue = &game::gScrVarGlob[inst].childVariables[newEntry->hash.id];

					assert((newEntryValue->w.status & VAR_STAT_MASK) == VAR_STAT_FREE);

					nextd = newEntryValue->u.next;
					game::gScrVarGlob[inst].childVariables[0].u.next = nextd;
					game::gScrVarGlob[inst].childVariables[nextd].hash.u.prev = 0;
				}
				else
				{
					assert(entry != entryValue);

					newIndexa = entry->v.next;
					newEntry = &game::gScrVarGlob[inst].childVariables[newIndexa];
					newEntryValue = entry;
					prevb = newEntry->hash.u.prev;
					nextc = entry->u.next;
					game::gScrVarGlob[inst].childVariables[game::gScrVarGlob[inst].childVariables[prevb].hash.id].u.next = nextc;
					game::gScrVarGlob[inst].childVariables[nextc].hash.u.prev = prevb;
				}

				prevSiblingIndex = entry->hash.u.prev;
				if (prevSiblingIndex)
				{
					game::gScrVarGlob[inst].childVariables[game::gScrVarGlob[inst].childVariables[prevSiblingIndex].hash.id].nextSibling = newIndexa;
				}

				nextSiblingIndex = entryValue->nextSibling;
				if (nextSiblingIndex)
				{
					game::gScrVarGlob[inst].childVariables[nextSiblingIndex].hash.u.prev = newIndexa;
				}

				if (type == VAR_STAT_MOVABLE)
				{
					prevId = game::gScrVarGlob[inst].childVariables[entryValue->v.next].hash.id;

					assert((game::gScrVarGlob[inst].childVariables[prevId].w.status & VAR_STAT_MASK) == VAR_STAT_MOVABLE ||
						(game::gScrVarGlob[inst].childVariables[prevId].w.status & VAR_STAT_MASK) == VAR_STAT_HEAD);

					while (game::gScrVarGlob[inst].childVariables[prevId].v.next != index)
					{
						prevId = game::gScrVarGlob[inst].childVariables[game::gScrVarGlob[inst].childVariables[prevId].v.next].hash.id;

						assert((game::gScrVarGlob[inst].childVariables[prevId].w.status & VAR_STAT_MASK) == VAR_STAT_MOVABLE ||
							(game::gScrVarGlob[inst].childVariables[prevId].w.status & VAR_STAT_MASK) == VAR_STAT_HEAD);
					}

					game::gScrVarGlob[inst].childVariables[prevId].v.next = newIndexa;
				}
				else
				{
					assert(type == VAR_STAT_EXTERNAL);

					entryValue->v.next = newIndexa;
				}

				newEntry->hash.u.prev = entry->hash.u.prev;
				id = newEntry->hash.id;
				newEntry->hash.id = entry->hash.id;
				entry->hash.id = id;
				newEntryValue->w.status = VAR_STAT_HEAD;
				newEntryValue->v.next = index;
			}
		}
		else
		{
			newIndex = entry->v.next;
			next = entryValue->u.next;
			if (newIndex == entry->hash.id || (entry->w.status & VAR_STAT_MASK) != VAR_STAT_FREE)
			{
				newEntryValue = &game::gScrVarGlob[inst].childVariables[entry->hash.id];
			}
			else
			{
				game::gScrVarGlob[inst].childVariables[newIndex].hash.id = entry->hash.id;
				entry->hash.id = index;
				entryValue->v.next = newIndex;
				entryValue->u.next = entry->u.next;
				newEntryValue = entry;
			}

			prev = entry->hash.u.prev;

			if (game::gScrVarGlob[inst].childVariables[prev].hash.id)
			{
				if ((game::gScrVarGlob[inst].childVariables[game::gScrVarGlob[inst].childVariables[prev].hash.id].w.status & VAR_STAT_MASK) != VAR_STAT_FREE)
				{
					//v4 = va(
					//	"%d, %d, %d",
					//	prev,
					//	gScrVarGlob[inst].variableList[prev + 0x8000].hash.id,
					//	gScrVarGlob[inst].variableList[gScrVarGlob[inst].variableList[prev + 0x8000].hash.id + 0x8000].w.status & 0x60);

					assert(!game::gScrVarGlob[inst].childVariables[prev].hash.id ||
						(game::gScrVarGlob[inst].childVariables[game::gScrVarGlob[inst].childVariables[prev].hash.id].w.status & VAR_STAT_MASK) == VAR_STAT_FREE);
				}
			}
			if (game::gScrVarGlob[inst].childVariables[next].hash.id)
			{
				if ((game::gScrVarGlob[inst].childVariables[game::gScrVarGlob[inst].childVariables[next].hash.id].w.status & VAR_STAT_MASK) != VAR_STAT_FREE)
				{
					//v5 = va(
					//	"%d, %d, %d",
					//	next,
					//	gScrVarGlob[inst].variableList[next + 0x8000].hash.id,
					//	gScrVarGlob[inst].variableList[gScrVarGlob[inst].variableList[next + 0x8000].hash.id + 0x8000].w.status & 0x60);

					assert(!game::gScrVarGlob[inst].childVariables[next].hash.id ||
						(game::gScrVarGlob[inst].childVariables[game::gScrVarGlob[inst].childVariables[next].hash.id].w.status & VAR_STAT_MASK) == VAR_STAT_FREE);
				}
			}

			game::gScrVarGlob[inst].childVariables[game::gScrVarGlob[inst].childVariables[prev].hash.id].u.next = next;
			game::gScrVarGlob[inst].childVariables[next].hash.u.prev = prev;
			newEntryValue->w.status = VAR_STAT_HEAD;
			newEntryValue->v.next = index;
		}

		assert(entry == &game::gScrVarGlob[inst].childVariables[index]);

		assert(newEntryValue == &game::gScrVarGlob[inst].childVariables[entry->hash.id]);

		assert((newEntryValue->w.type & VAR_MASK) == game::VAR_UNDEFINED);

		newEntryValue->w.status = (name << VAR_NAME_BIT_SHIFT) | (unsigned char)newEntryValue->w.status;

		assert((entry->hash.id > 0) && (entry->hash.id < VARIABLELIST_CHILD_SIZE));

		parentValue = &game::gScrVarGlob[inst].parentVariables[parentId + 1];

		assert((parentValue->w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL);

		assert((parentValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(IsObject(parentValue));

		if ((parentValue->w.status & VAR_MASK) != game::VAR_ARRAY)
		{
			return index;
		}

		++parentValue->u.o.u.size;
		value = game::Scr_GetArrayIndexValue(inst, name);
		game::AddRefToValue(inst, value.type, value.u);
		return index;
	}

	// Decomp Status: Completed
	unsigned int GetNewVariableIndexInternal2(unsigned int name, game::scriptInstance_t inst, unsigned int parentId, unsigned int index)
	{
		unsigned int siblingId;
		game::VariableValueInternal* parentValue;
		game::VariableValueInternal* entry;
		game::VariableValueInternal* siblingValue;
		unsigned int siblingIndex;
		unsigned int id;
		unsigned int indexa;

		indexa = game::GetNewVariableIndexInternal3(inst, parentId, name, index);
		parentValue = &game::gScrVarGlob[inst].parentVariables[parentId + 1];

		assert(((parentValue->w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL));

		entry = &game::gScrVarGlob[inst].childVariables[indexa];
		id = entry->hash.id;
		siblingId = parentValue->nextSibling;

		if (siblingId)
		{
			siblingValue = &game::gScrVarGlob[inst].childVariables[siblingId];

			assert((siblingValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

			assert(!IsObject(siblingValue));

			siblingIndex = game::FindVariableIndexInternal(inst, parentId, siblingValue->w.status >> VAR_NAME_BIT_SHIFT);

			assert(siblingIndex);

			game::gScrVarGlob[inst].childVariables[siblingIndex].hash.u.prev = indexa;
		}
		else
		{
			siblingIndex = 0;
			game::gScrVarGlob[inst].parentVariables[parentValue->v.next + 1].hash.u.prev = id;
		}

		parentValue->nextSibling = id;
		entry->hash.u.prev = 0;
		game::gScrVarGlob[inst].childVariables[id].nextSibling = siblingIndex;
		return indexa;
	}

	// Decomp Status: Completed
	unsigned int GetNewVariableIndexReverseInternal2(unsigned int name, game::scriptInstance_t inst, unsigned int parentId, unsigned int index)
	{
		game::VariableValueInternal* parentValue;
		unsigned int siblingId;
		game::VariableValueInternal* entry;
		unsigned int siblingIndex;
		game::VariableValueInternal* siblingValue;
		game::VariableValueInternal* parent;
		unsigned int id;
		unsigned int indexa;

		indexa = game::GetNewVariableIndexInternal3(inst, parentId, name, index);
		parentValue = &game::gScrVarGlob[inst].parentVariables[parentId + 1];

		assert(((parentValue->w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL));

		parent = &game::gScrVarGlob[inst].parentVariables[parentValue->v.next + 1];
		entry = &game::gScrVarGlob[inst].childVariables[indexa];
		id = entry->hash.id;
		siblingId = parent->hash.u.prev;

		if (siblingId)
		{
			siblingValue = &game::gScrVarGlob[inst].childVariables[siblingId];

			assert((siblingValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

			assert(!IsObject(siblingValue));

			siblingValue->nextSibling = indexa;
			siblingIndex = game::FindVariableIndexInternal(inst, parentId, siblingValue->w.status >> VAR_NAME_BIT_SHIFT);

			assert(siblingIndex);
		}
		else
		{
			siblingIndex = 0;
			parentValue->nextSibling = id;
		}

		parent->hash.u.prev = id;
		entry->hash.u.prev = siblingIndex;
		game::gScrVarGlob[inst].childVariables[id].nextSibling = 0;
		return indexa;
	}

	// Decomp Status: Completed
	void MakeVariableExternal(game::VariableValueInternal* parentValue, game::scriptInstance_t inst, unsigned int index)
	{
		game::VariableValueInternal* entry;
		unsigned int oldPrevSiblingIndex;
		unsigned int nextSiblingIndex;
		unsigned int prevSiblingIndex;
		unsigned int oldIndex;
		game::VariableValueInternal* entryValue;
		game::Variable tempEntry;
		game::VariableValueInternal* oldEntry;
		game::VariableValueInternal* oldEntrya;
		game::Variable* prev;
		unsigned int oldNextSiblingIndex;
		game::VariableValue value;
		game::VariableValueInternal* oldEntryValue;
		game::VariableValueInternal* oldEntryValuea;

		entry = &game::gScrVarGlob[inst].childVariables[index];
		entryValue = &game::gScrVarGlob[inst].childVariables[entry->hash.id];

		assert((entryValue->w.status & VAR_STAT_MASK) == VAR_STAT_MOVABLE || (entryValue->w.status & VAR_STAT_MASK) == VAR_STAT_HEAD);

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(!IsObject(entryValue));

		if ((parentValue->w.status & VAR_MASK) == game::VAR_ARRAY)
		{
			--parentValue->u.o.u.size;

			assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

			assert(!IsObject(entryValue));

			value = game::Scr_GetArrayIndexValue(inst, entryValue->w.status >> VAR_NAME_BIT_SHIFT);
			game::RemoveRefToValueInternal(inst, value.type, value.u);
		}

		if ((entryValue->w.status & VAR_STAT_MASK) == VAR_STAT_HEAD)
		{
			oldIndex = entryValue->v.next;
			oldEntry = &game::gScrVarGlob[inst].childVariables[oldIndex];
			oldEntryValue = &game::gScrVarGlob[inst].childVariables[oldEntry->hash.id];

			if (oldEntry != entry)
			{
				assert((oldEntryValue->w.status & VAR_STAT_MASK) == VAR_STAT_MOVABLE);

				oldEntryValue->w.status = oldEntryValue->w.status & ~VAR_STAT_MOVABLE | VAR_STAT_HEAD;
				prevSiblingIndex = entry->hash.u.prev;
				nextSiblingIndex = entryValue->nextSibling;
				oldPrevSiblingIndex = oldEntry->hash.u.prev;
				oldNextSiblingIndex = oldEntryValue->nextSibling;

				if (oldNextSiblingIndex)
				{
					game::gScrVarGlob[inst].childVariables[oldNextSiblingIndex].hash.u.prev = index;
				}

				if (oldPrevSiblingIndex)
				{
					game::gScrVarGlob[inst].childVariables[game::gScrVarGlob[inst].childVariables[oldPrevSiblingIndex].hash.id].nextSibling = index;
				}

				if (nextSiblingIndex)
				{
					game::gScrVarGlob[inst].childVariables[nextSiblingIndex].hash.u.prev = oldIndex;
				}

				if (prevSiblingIndex)
				{
					game::gScrVarGlob[inst].childVariables[game::gScrVarGlob[inst].childVariables[prevSiblingIndex].hash.id].nextSibling = oldIndex;
				}

				tempEntry = entry->hash;
				entry->hash = oldEntry->hash;
				oldEntry->hash = tempEntry;
				entryValue->w.status |= VAR_STAT_EXTERNAL;
				entryValue->v.next = oldIndex;
			}
			else
			{
				entryValue->w.status |= VAR_STAT_EXTERNAL;
				entryValue->v.next = index;
			}
		}
		else
		{
			oldEntrya = entry;
			oldEntryValuea = entryValue;

			do
			{
				assert((oldEntryValuea->w.status & VAR_STAT_MASK) == VAR_STAT_MOVABLE || (oldEntryValuea->w.status & VAR_STAT_MASK) == VAR_STAT_HEAD);

				prev = &oldEntrya->hash;
				oldEntrya = &game::gScrVarGlob[inst].childVariables[oldEntryValuea->v.next];
				oldEntryValuea = &game::gScrVarGlob[inst].childVariables[oldEntrya->hash.id];
			} while (oldEntrya != entry);

			game::gScrVarGlob[inst].childVariables[prev->id].v.next = entryValue->v.next;

			assert(entryValue == &game::gScrVarGlob[inst].childVariables[entry->hash.id]);

			entryValue->w.status |= VAR_STAT_EXTERNAL;
			entryValue->v.next = index;
		}
	}

	// Decomp Status: Completed
	void FreeChildValue(unsigned int id, game::scriptInstance_t inst, unsigned int parentId)
	{
		game::VariableValueInternal* entry;
		unsigned int nextSiblingIndex;
		unsigned int prevSiblingIndex;
		unsigned int parentIndex;
		game::VariableValueInternal* entryValue;
		unsigned int index;

		entryValue = &game::gScrVarGlob[inst].childVariables[id];

		assert(((entryValue->w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL));

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(!IsObject(entryValue));

		assert(game::gScrVarGlob[inst].childVariables[entryValue->v.index].hash.id == id);

		game::RemoveRefToValueInternal(inst, (game::VariableType)(entryValue->w.status & VAR_MASK), entryValue->u.u);

		assert(id > 0 && id < VARIABLELIST_CHILD_SIZE);

		assert(((entryValue->w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL));

		index = entryValue->v.next;
		entry = &game::gScrVarGlob[inst].childVariables[index];

		assert(entry->hash.id == id);

		nextSiblingIndex = entryValue->nextSibling;
		prevSiblingIndex = entry->hash.u.prev;

		if (prevSiblingIndex)
		{
			game::gScrVarGlob[inst].childVariables[game::gScrVarGlob[inst].childVariables[prevSiblingIndex].hash.id].nextSibling = nextSiblingIndex;
		}
		else
		{
			assert(!game::gScrVarGlob[inst].childVariables[0].hash.id);

			game::gScrVarGlob[inst].parentVariables[parentId + 1].nextSibling = game::gScrVarGlob[inst].childVariables[nextSiblingIndex].hash.id;
		}

		if (nextSiblingIndex)
		{
			game::gScrVarGlob[inst].childVariables[nextSiblingIndex].hash.u.prev = prevSiblingIndex;
		}
		else
		{
			assert(!game::gScrVarGlob[inst].childVariables[0].hash.id);

			parentIndex = game::gScrVarGlob[inst].parentVariables[parentId + 1].v.next;
			game::gScrVarGlob[inst].parentVariables[parentIndex + 1].hash.u.prev = game::gScrVarGlob[inst].childVariables[prevSiblingIndex].hash.id;
		}

		entryValue->w.status = 0;
		entryValue->u.next = game::gScrVarGlob[inst].childVariables[0].u.next;
		entry->hash.u.prev = 0;
		game::gScrVarGlob[inst].childVariables[game::gScrVarGlob[inst].childVariables[0].u.next].hash.u.prev = index;
		game::gScrVarGlob[inst].childVariables[0].u.next = index;
	}

	// Decomp Status: Completed
	void ClearObjectInternal(game::scriptInstance_t inst, unsigned int parentId)
	{
		unsigned int nextId;
		unsigned int nextSibling;
		unsigned int nextSiblinga;
		game::VariableValueInternal* parentValue;
		game::VariableValueInternal* entryValue;
		unsigned int id;
		unsigned int ida;

		parentValue = &game::gScrVarGlob[inst].parentVariables[parentId + 1];

		assert((parentValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(IsObject(parentValue));

		if (parentValue->nextSibling)
		{
			entryValue = &game::gScrVarGlob[inst].childVariables[parentValue->nextSibling];

			assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

			assert(!IsObject(entryValue));

			nextSibling = game::FindVariableIndexInternal(inst, parentId, entryValue->w.status >> VAR_NAME_BIT_SHIFT);

			assert(nextSibling);

			do
			{
				id = game::gScrVarGlob[inst].childVariables[nextSibling].hash.id;
				game::MakeVariableExternal(parentValue, inst, nextSibling);
				nextSibling = game::gScrVarGlob[inst].childVariables[id].nextSibling;
			} while (nextSibling);

			nextId = parentValue->nextSibling;
			do
			{
				ida = nextId;
				nextSiblinga = game::gScrVarGlob[inst].childVariables[nextId].nextSibling;
				nextId = game::gScrVarGlob[inst].childVariables[nextSiblinga].hash.id;
				game::FreeChildValue(ida, inst, parentId);
			} while (nextSiblinga);
		}
	}

	// Restored
	void AddRefToObject(game::scriptInstance_t inst, unsigned int id)
	{
		game::VariableValueInternal* entryValue;

		assert(id >= 1 && id < VARIABLELIST_CHILD_BEGIN);

		assert((game::gScrVarGlob[inst].parentVariables[id + 1].w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		entryValue = &game::gScrVarGlob[inst].parentVariables[id + 1];

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(IsObject(entryValue));

		++entryValue->u.o.refCount;

		assert(entryValue->u.o.refCount);
	}

	// Restored
	void RemoveRefToEmptyObject(game::scriptInstance_t inst, unsigned int id)
	{
		game::VariableValueInternal* entryValue;

		entryValue = &game::gScrVarGlob[inst].parentVariables[id + 1];

		assert(((entryValue->w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL));

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(IsObject(entryValue));

		assert(!entryValue->nextSibling);

		if (entryValue->u.o.refCount)
		{
			assert(id >= 1 && id < VARIABLELIST_CHILD_BEGIN);

			--entryValue->u.o.refCount;
		}
		else
		{
			game::FreeVariable(id, inst);
		}
	}

	// Decomp Status: Completed
	void ClearObject(unsigned int parentId, game::scriptInstance_t inst)
	{
		assert((game::gScrVarGlob[inst].parentVariables[parentId + 1].w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		game::AddRefToObject(inst, parentId);
		game::ClearObjectInternal(inst, parentId);
		game::RemoveRefToEmptyObject(inst, parentId);
	}

	// Restored
	void Scr_ClearThread(game::scriptInstance_t inst, unsigned int parentId)
	{
		game::VariableValueInternal* parentValue;

		assert(parentId);

		parentValue = &game::gScrVarGlob[inst].parentVariables[parentId + 1];

		assert((parentValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(((parentValue->w.type & VAR_MASK) >= game::VAR_THREAD) && ((parentValue->w.type & VAR_MASK) <= game::VAR_CHILD_THREAD));

		assert(!game::FindVariable(OBJECT_STACK, parentId, inst));

		if (parentValue->nextSibling)
		{
			game::ClearObjectInternal(inst, parentId);
		}

		game::RemoveRefToObject(parentValue->u.o.u.nextEntId, inst);
	}

	// Decomp Status: Completed
	void Scr_StopThread(game::scriptInstance_t inst, unsigned int threadId)
	{
		assert(threadId);

		game::Scr_ClearThread(inst, threadId);
		game::gScrVarGlob[inst].parentVariables[threadId + 1].u.o.u.nextEntId = game::gScrVarPub[inst].levelId;
		game::AddRefToObject(inst, game::gScrVarPub[inst].levelId);
	}

	// Decomp Status: Completed
	unsigned int GetSafeParentLocalId(game::scriptInstance_t inst, unsigned int threadId)
	{
		unsigned int id;

		id = 0;

		if ((game::gScrVarGlob[inst].parentVariables[threadId + 1].w.status & VAR_STAT_MASK) == VAR_STAT_FREE)
		{
			return id;
		}

		assert((game::gScrVarGlob[inst].parentVariables[threadId + 1].w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL);

		assert((game::gScrVarGlob[inst].parentVariables[threadId + 1].w.type & VAR_MASK) >= game::VAR_THREAD &&
			(game::gScrVarGlob[inst].parentVariables[threadId + 1].w.type & VAR_MASK) <= game::VAR_CHILD_THREAD);

		if ((game::gScrVarGlob[inst].parentVariables[threadId + 1].w.status & VAR_MASK) == game::VAR_CHILD_THREAD)
		{
			id = game::gScrVarGlob[inst].parentVariables[threadId + 1].w.parentLocalId >> VAR_PARENTID_BIT_SHIFT;
		}

		return id;
	}

	// Decomp Status: Completed
	unsigned int GetStartLocalId(unsigned int threadId, game::scriptInstance_t inst)
	{
		assert((game::gScrVarGlob[inst].parentVariables[threadId + 1].w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL);

		assert((game::gScrVarGlob[inst].parentVariables[threadId + 1].w.type & VAR_MASK) >= game::VAR_THREAD &&
			(game::gScrVarGlob[inst].parentVariables[threadId + 1].w.type & VAR_MASK) <= game::VAR_CHILD_THREAD);

		while ((game::gScrVarGlob[inst].parentVariables[threadId + 1].w.status & VAR_MASK) == game::VAR_CHILD_THREAD)
		{
			threadId = game::gScrVarGlob[inst].parentVariables[threadId + 1].w.parentLocalId >> VAR_PARENTID_BIT_SHIFT;
		}

		assert((game::gScrVarGlob[inst].parentVariables[threadId + 1].w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL);

		assert((game::gScrVarGlob[inst].parentVariables[threadId + 1].w.type & VAR_MASK) >= game::VAR_THREAD &&
			(game::gScrVarGlob[inst].parentVariables[threadId + 1].w.type & VAR_MASK) <= game::VAR_TIME_THREAD);

		return threadId;
	}

	// Restored
	unsigned int FindObjectVariable(game::scriptInstance_t inst, unsigned int parentId, unsigned int id)
	{
		return game::gScrVarGlob[inst].childVariables[game::FindVariableIndexInternal(inst, parentId, id + SL_MAX_STRING_INDEX)].hash.id;
	}

	// Restored
	void RemoveObjectVariable(game::scriptInstance_t inst, unsigned int parentId, unsigned int id)
	{
		assert((game::gScrVarGlob[inst].parentVariables[parentId + 1].w.type & VAR_MASK) == game::VAR_ARRAY);

		game::RemoveVariable(id + SL_MAX_STRING_INDEX, parentId, inst);
	}

	// Restored
	game::VariableValueInternal_u* GetVariableValueAddress(game::scriptInstance_t inst, unsigned int id)
	{
		game::VariableValueInternal* entryValue;

		assert(id);

		entryValue = &game::gScrVarGlob[inst].childVariables[id];

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert((entryValue->w.type & VAR_MASK) != game::VAR_UNDEFINED);

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(!IsObject(entryValue));

		return &entryValue->u;
	}

	// Restored
	void Scr_KillEndonThread(game::scriptInstance_t inst, unsigned int threadId)
	{
		game::VariableValueInternal* parentValue;

		parentValue = &game::gScrVarGlob[inst].parentVariables[threadId + 1];

		assert((parentValue->w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL);

		assert((parentValue->w.type & VAR_MASK) == game::VAR_THREAD);

		assert(!parentValue->nextSibling);

		game::RemoveRefToObject(parentValue->u.o.u.nextEntId, inst);

		assert(!game::FindObjectVariable(inst, game::gScrVarPub[inst].pauseArrayId, threadId));

		parentValue->w.status &= ~0xAu;
		parentValue->w.status |= game::VAR_DEAD_THREAD;
	}

	// Decomp Status: Completed
	void Scr_KillThread(game::scriptInstance_t inst, unsigned int parentId)
	{
		game::VariableValueInternal* parentValue;
		unsigned int selfNameId;
		unsigned int name;
		unsigned int id;
		unsigned int notifyListEntry;
		game::VariableValueInternal_u* address;
		unsigned int objectVariableId;

		assert(parentId);

		parentValue = &game::gScrVarGlob[inst].parentVariables[parentId + 1];

		assert((parentValue->w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL);

		assert(((parentValue->w.type & VAR_MASK) >= game::VAR_THREAD) && ((parentValue->w.type & VAR_MASK) <= game::VAR_CHILD_THREAD));

		game::Scr_ClearThread(inst, parentId);
		id = game::FindObjectVariable(inst, game::gScrVarPub[inst].pauseArrayId, parentId);

		if (id)
		{
			for (selfNameId = game::FindObject(inst, id);
				;
				game::RemoveObjectVariable(inst, selfNameId, name - SL_MAX_STRING_INDEX))
			{
				notifyListEntry = game::FindFirstSibling(inst, selfNameId);
				if (!notifyListEntry)
				{
					break;
				}

				assert((game::gScrVarGlob[inst].childVariables[notifyListEntry].w.type & VAR_MASK) == game::VAR_POINTER);

				name = game::gScrVarGlob[inst].childVariables[notifyListEntry].w.status >> VAR_NAME_BIT_SHIFT;

				assert((name - SL_MAX_STRING_INDEX) < SL_MAX_STRING_INDEX);

				objectVariableId = game::FindObjectVariable(inst, selfNameId, name - SL_MAX_STRING_INDEX);
				address = game::GetVariableValueAddress(inst, objectVariableId);
				game::VM_CancelNotify(inst, address->u.stringValue, name - SL_MAX_STRING_INDEX);
				game::Scr_KillEndonThread(inst, name - SL_MAX_STRING_INDEX);
			}

			assert(!game::GetArraySize(inst, selfNameId));

			game::RemoveObjectVariable(inst, game::gScrVarPub[inst].pauseArrayId, parentId);
		}

		parentValue->w.status &= ~VAR_MASK;
		parentValue->w.status |= game::VAR_DEAD_THREAD;
	}

	// Decomp Status: Completed
	unsigned __int16 AllocVariable(game::scriptInstance_t inst)
	{
		game::VariableValueInternal* entry;
		unsigned int newIndex;
		unsigned int next;
		unsigned int index;
		game::VariableValueInternal* entryValue;

		index = game::gScrVarGlob[inst].parentVariables[1].u.next;
		if (!index)
		{
			game::Scr_TerminalError(inst, "exceeded maximum number of script variables");
		}

		entry = &game::gScrVarGlob[inst].parentVariables[index + 1];
		entryValue = &game::gScrVarGlob[inst].parentVariables[entry->hash.id + 1];

		assert((entryValue->w.status & VAR_STAT_MASK) == VAR_STAT_FREE);

		next = entryValue->u.next;

		if (entry != entryValue && (entry->w.status & VAR_STAT_MASK) == VAR_STAT_FREE)
		{
			newIndex = entry->v.next;

			assert(newIndex != index);

			game::gScrVarGlob[inst].parentVariables[newIndex + 1].hash.id = entry->hash.id;
			entry->hash.id = index;
			entryValue->v.next = newIndex;
			entryValue->u.next = entry->u.next;
			entryValue = entry;
		}

		game::gScrVarGlob[inst].parentVariables[1].u.next = next;
		game::gScrVarGlob[inst].parentVariables[next + 1].hash.u.prev = 0;
		entryValue->v.next = index;
		entryValue->nextSibling = 0;
		entry->hash.u.prev = 0;

		assert(entry->hash.id > 0 && entry->hash.id < VARIABLELIST_CHILD_BEGIN);

		return entry->hash.id;
	}

	// Decomp Status: Completed
	void FreeVariable(unsigned int id, game::scriptInstance_t inst)
	{
		game::VariableValueInternal* entry;
		game::VariableValueInternal* entryValue;
		unsigned int index;

		assert(id > 0 && id < VARIABLELIST_CHILD_BEGIN);

		entryValue = &game::gScrVarGlob[inst].parentVariables[id + 1];

		assert(((entryValue->w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL));

		index = entryValue->v.next;
		entry = &game::gScrVarGlob[inst].parentVariables[index + 1];

		assert(entry->hash.id == id);

		assert(!entry->hash.u.prev);

		assert(!entryValue->nextSibling);

		entryValue->w.status = 0;
		entryValue->u.next = game::gScrVarGlob[inst].parentVariables[1].u.next;
		entry->hash.u.prev = 0;
		game::gScrVarGlob[inst].parentVariables[game::gScrVarGlob[inst].parentVariables[1].u.next + 1].hash.u.prev = index;
		game::gScrVarGlob[inst].parentVariables[1].u.next = index;
	}

	// Decomp Status: Tested, Needs cleaning
	// unsigned int __usercall AllocValue@<eax>(game::scriptInstance_t inst@<eax>)
	unsigned int AllocValue(game::scriptInstance_t inst)
	{
		game::VariableValueInternal* entry;
		unsigned int newIndex;
		unsigned int next;
		game::VariableValueInternal* entryValue;
		unsigned int index;

		index = game::gScrVarGlob[inst].childVariables[0].u.next;
		if (!index)
		{
			game::Scr_TerminalError(inst, "exceeded maximum number of script variables");
		}

		entry = &game::gScrVarGlob[inst].childVariables[index];
		entryValue = &game::gScrVarGlob[inst].childVariables[entry->hash.id];

		assert((entryValue->w.status & VAR_STAT_MASK) == VAR_STAT_FREE);

		next = entryValue->u.next;
		if (entry != entryValue && (entry->w.status & VAR_STAT_MASK) == VAR_STAT_FREE)
		{
			newIndex = entry->v.next;

			assert(newIndex != index);

			game::gScrVarGlob[inst].childVariables[newIndex].hash.id = entry->hash.id;
			entry->hash.id = index;
			entryValue->v.next = newIndex;
			entryValue->u.next = entry->u.next;
			entryValue = entry;
		}

		game::gScrVarGlob[inst].childVariables[0].u.next = next;
		game::gScrVarGlob[inst].childVariables[next].hash.u.prev = 0;
		entryValue->v.next = index;
		entryValue->nextSibling = 0;
		entry->hash.u.prev = 0;
		entryValue->w.status = VAR_STAT_EXTERNAL;

		assert((entryValue->w.type & VAR_MASK) == game::VAR_UNDEFINED);

		return entry->hash.id;
	}

	// Decomp Status: Completed
	unsigned int AllocEntity(game::classNum_e classnum, game::scriptInstance_t inst, int entnum, int clientnum)
	{
		game::VariableValueInternal* entryValue;
		unsigned int id;

		id = game::AllocVariable(inst);
		entryValue = &game::gScrVarGlob[inst].parentVariables[id + 1];
		entryValue->w.status = VAR_STAT_EXTERNAL;

		assert((entryValue->w.type & VAR_MASK) == game::VAR_UNDEFINED);

		entryValue->w.status |= game::VAR_ENTITY;

		assert(!(entryValue->w.status & VAR_NAME_HIGH_MASK));

		entryValue->w.status |= classnum << VAR_NAME_BIT_SHIFT;
		entryValue->u.o.refCount = 0;
		entryValue->u.o.u.entnum = (unsigned short)entnum;
		entryValue->u.o.u.entnum |= (unsigned char)clientnum << VAR_CLIENT_MASK;
		return id;
	}

	// Decomp Status: Completed
	unsigned int Scr_AllocArray(game::scriptInstance_t inst)
	{
		game::VariableValueInternal* entryValue;
		unsigned int id;

		id = game::AllocVariable(inst);
		entryValue = &game::gScrVarGlob[inst].parentVariables[id + 1];
		entryValue->w.status = VAR_STAT_EXTERNAL;

		assert((entryValue->w.type & VAR_MASK) == game::VAR_UNDEFINED);

		entryValue->w.status |= game::VAR_ARRAY;
		entryValue->u.o.refCount = 0;
		entryValue->u.o.u.size = 0;
		return id;
	}

	unsigned int AllocThread(game::scriptInstance_t inst, unsigned int self)
	{
		game::VariableValueInternal* entryValue;
		unsigned int id;

		id = game::AllocVariable(inst);
		entryValue = &game::gScrVarGlob[inst].parentVariables[id + 1];
		entryValue->w.status = VAR_STAT_EXTERNAL;

		assert((entryValue->w.type & VAR_MASK) == game::VAR_UNDEFINED);

		entryValue->w.status |= game::VAR_THREAD;
		entryValue->u.o.refCount = 0;
		entryValue->u.o.u.self = self;
		return id;
	}

	// Decomp Status: Completed
	unsigned int AllocChildThread(game::scriptInstance_t inst, unsigned int parentLocalId, unsigned int self)
	{
		game::VariableValueInternal* entryValue;
		unsigned int id;

		id = game::AllocVariable(inst);
		entryValue = &game::gScrVarGlob[inst].parentVariables[id + 1];
		entryValue->w.status = VAR_STAT_EXTERNAL;

		assert((entryValue->w.type & VAR_MASK) == game::VAR_UNDEFINED);

		entryValue->w.type |= game::VAR_CHILD_THREAD;

		assert(!(entryValue->w.status & VAR_NAME_HIGH_MASK));

		entryValue->w.parentLocalId |= parentLocalId << VAR_NAME_BIT_SHIFT;
		entryValue->u.o.refCount = 0;
		entryValue->u.o.u.self = self;
		return id;
	}

	// Decomp Status: Completed
	void FreeValue(unsigned int id, game::scriptInstance_t inst)
	{
		game::VariableValueInternal* entry;
		game::VariableValueInternal* entryValue;
		unsigned int index;

		entryValue = &game::gScrVarGlob[inst].childVariables[id];

		assert(((entryValue->w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL));

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(!IsObject(entryValue));

		assert(game::gScrVarGlob[inst].childVariables[entryValue->v.next].hash.id == id);

		game::RemoveRefToValueInternal(inst, (game::VariableType)(entryValue->w.status & VAR_MASK), entryValue->u.u);

		assert(id > 0 && id < VARIABLELIST_CHILD_SIZE);

		assert(((entryValue->w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL));

		index = entryValue->v.next;
		entry = &game::gScrVarGlob[inst].childVariables[index];

		assert(entry->hash.id == id);

		assert(!entry->hash.u.prev);

		assert(!entryValue->nextSibling);

		entryValue->w.status = 0;
		entryValue->u.next = game::gScrVarGlob[inst].childVariables[0].u.next;
		entry->hash.u.prev = 0;
		game::gScrVarGlob[inst].childVariables[game::gScrVarGlob[inst].childVariables[0].u.next].hash.u.prev = index;
		game::gScrVarGlob[inst].childVariables[0].u.next = index;
	}

	// Restored
	void RemoveArrayVariable(game::scriptInstance_t inst, unsigned int parentId, unsigned int unsignedValue)
	{
		assert(game::IsValidArrayIndex(inst, unsignedValue));

		game::RemoveVariable((unsignedValue + 0x800000) & 0xFFFFFF, parentId, inst);
	}

	// Restored inlined function
	unsigned int FindObject(game::scriptInstance_t inst, unsigned int id)
	{
		game::VariableValueInternal* entryValue;

		assert(id);

		entryValue = &game::gScrVarGlob[inst].childVariables[id];

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert((entryValue->w.type & VAR_MASK) == game::VAR_POINTER);

		return entryValue->u.u.pointerValue;
	}

	// Decomp Status: Completed
	void RemoveRefToObject(unsigned int id, game::scriptInstance_t inst)
	{
		int unsignedValue;
		game::classNum_e classnum;
		unsigned int entArrayId;
		game::VariableValueInternal* entryValue;

		assert(id >= 1 && id < VARIABLELIST_CHILD_BEGIN);

		entryValue = &game::gScrVarGlob[inst].parentVariables[id + 1];

		assert(((entryValue->w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL));

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(IsObject(entryValue));

		if (entryValue->u.o.refCount)
		{
			if (!--entryValue->u.o.refCount && (entryValue->w.status & VAR_MASK) == game::VAR_ENTITY && !entryValue->nextSibling)
			{
				entryValue->w.status &= ~VAR_MASK;
				entryValue->w.status |= game::VAR_DEAD_ENTITY;
				classnum = (game::classNum_e)(entryValue->w.status >> VAR_NAME_BIT_SHIFT);

				assert(classnum < game::CLASS_NUM_COUNT);

				entArrayId = game::gScrClassMap[inst][classnum].entArrayId;

				assert(entArrayId);

				unsignedValue = entryValue->u.o.u.entnum & 0x3FFF;
				if (inst == game::SCRIPTINSTANCE_CLIENT && (entryValue->u.o.u.entnum & 0xC000) != 0)
				{
					unsignedValue += entryValue->u.o.u.entnum >> 14 << 11;
				}

				game::RemoveArrayVariable(inst, entArrayId, unsignedValue);
			}
		}
		else
		{
			if (entryValue->nextSibling)
			{
				game::ClearObject(id, inst);
			}

			game::FreeVariable(id, inst);
		}
	}

	// Decomp Status: Completed
	float* Scr_AllocVector(game::scriptInstance_t inst)
	{
		game::RefVector* result;

		result = (game::RefVector*)game::MT_Alloc(sizeof(game::RefVector), inst);
		result->u.head = 0;
		return &result->vec[0];
	}

	// Decomp Status: Completed
	void RemoveRefToVector(const float* vectorValue, game::scriptInstance_t inst)
	{
		game::RefVector* ref = (game::RefVector*)((char*)vectorValue - 4);

		if (!ref->u.s.length)
		{
			if (ref->u.s.refCount)
			{
				ref->u.s.refCount--;
			}
			else
			{
				game::MT_Free(ref, sizeof(game::RefVector), inst);
			}
		}
	}

	// Restored
	void AddRefToVector([[maybe_unused]] game::scriptInstance_t inst, const float* floatVal)
	{
		game::RefVector* rf = (game::RefVector*)(floatVal - 1);

		if (!rf->u.s.length)
		{
			++rf->u.s.refCount;

			assert(rf->u.s.refCount);
		}
	}

	// Completed
	void AddRefToValue(game::scriptInstance_t inst, game::VariableType type, game::VariableUnion u)
	{
		if (type > game::VAR_ISTRING)
		{
			//assert(type == game::VAR_VECTOR);

			if (type == game::VAR_VECTOR)
			{
				game::AddRefToVector(inst, u.vectorValue);
			}
		}
		else if (type >= game::VAR_STRING)
		{
			game::SL_AddRefToString(inst, u.stringValue);
		}
		else if (type == game::VAR_POINTER)
		{
			game::AddRefToObject(inst, u.pointerValue);
		}
	}

	// Completed
	void RemoveRefToValueInternal(game::scriptInstance_t inst, game::VariableType type, game::VariableUnion u)
	{
		if (type > game::VAR_ISTRING)
		{
			//assert(type == game::VAR_VECTOR);

			if (type == game::VAR_VECTOR)
			{
				game::RemoveRefToVector(u.vectorValue, inst);
			}
		}
		else if (type >= game::VAR_STRING)
		{
			game::SL_RemoveRefToString(u.stringValue, inst);
		}
		else if (type == game::VAR_POINTER)
		{
			game::RemoveRefToObject(u.pointerValue, inst);
		}
	}

	// restored
	unsigned int FindArrayVariableIndex(game::scriptInstance_t inst, unsigned int parentId, unsigned int unsignedValue)
	{
		assert(game::IsValidArrayIndex(inst, unsignedValue));

		return game::FindVariableIndexInternal(inst, parentId, (unsignedValue + 0x800000) & 0xFFFFFF); // - ??
	}

	// Completed
	unsigned int FindArrayVariable(unsigned int parentId, unsigned int intValue, game::scriptInstance_t inst)
	{
		return game::gScrVarGlob[inst].childVariables[game::FindArrayVariableIndex(inst, parentId, intValue)].hash.id;
	}

	// Completed
	unsigned int FindVariable(unsigned int name, unsigned int parentId, game::scriptInstance_t inst)
	{
		return game::gScrVarGlob[inst].childVariables[game::FindVariableIndexInternal(inst, parentId, name)].hash.id;
	}

	// Restored
	unsigned int GetVariableIndexInternal(game::scriptInstance_t inst, unsigned int parentId, unsigned int name)
	{
		unsigned int newIndex;
		game::VariableValueInternal* parentValue;

		assert(parentId);

		parentValue = &game::gScrVarGlob[inst].parentVariables[parentId + 1];

		assert((parentValue->w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL);

		assert((parentValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(IsObject(parentValue));

		newIndex = game::FindVariableIndexInternal2(inst, name, (parentId + name) % 0xFFFD + 1);
		if (newIndex)
		{
			return newIndex;
		}

		return game::GetNewVariableIndexInternal2(name, inst, parentId, (parentId + name) % 0xFFFD + 1);
	}

	// Completed
	unsigned int GetArrayVariableIndex(unsigned int unsignedValue, game::scriptInstance_t inst, unsigned int parentId)
	{
		assert(game::IsValidArrayIndex(inst, unsignedValue));

		return game::GetVariableIndexInternal(inst, parentId, (unsignedValue + 0x800000) & 0xFFFFFF);
	}

	// Completed
	unsigned int Scr_GetVariableFieldIndex(game::scriptInstance_t inst, unsigned int name, unsigned int parentId)
	{
		unsigned int index;
		game::VariableType type;
		game::VariableValueInternal* parentValue;

		assert(parentId);

		parentValue = &game::gScrVarGlob[inst].parentVariables[parentId + 1];

		assert((parentValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(IsObject(parentValue));

		type = (game::VariableType)(parentValue->w.status & VAR_MASK);

		if (type <= game::VAR_OBJECT)
		{
			return game::GetVariableIndexInternal(inst, parentId, name);
		}

		if (type != game::VAR_ENTITY)
		{
			game::Scr_Error(game::va("cannot set field of %s", game::var_typename[type]), inst, 0);
		}

		index = game::FindVariableIndexInternal(inst, parentId, name);
		if (index)
		{
			return index;
		}

		game::gScrVarPub[inst].entId = parentId;
		game::gScrVarPub[inst].entFieldName = name;
		return 0;
	}

	// Completed
	game::VariableValue Scr_FindVariableField(game::scriptInstance_t inst, unsigned int parentId, unsigned int name)
	{
		game::VariableValue result;
		unsigned int id;
		game::VariableValueInternal* parentValue;

		assert(parentId);

		parentValue = &game::gScrVarGlob[inst].parentVariables[parentId + 1];

		assert((parentValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(IsObject(parentValue));

		assert(((parentValue->w.type & VAR_MASK) >= game::FIRST_OBJECT && (parentValue->w.type & VAR_MASK) < game::FIRST_NONFIELD_OBJECT) ||
			((parentValue->w.type & VAR_MASK) >= game::FIRST_DEAD_OBJECT));

		id = game::FindVariable(name, parentId, inst);

		if (id)
		{
			return game::Scr_EvalVariable(inst, id);
		}

		if ((game::gScrVarGlob[inst].parentVariables[parentId + 1].w.status & VAR_MASK) == game::VAR_ENTITY)
		{
			return game::Scr_EvalVariableEntityField(parentId, inst, name);
		}

		result.u.intValue = 0;
		result.type = game::VAR_UNDEFINED;
		return result;
	}

	// Completed
	void ClearVariableField(game::scriptInstance_t inst, unsigned int parentId, unsigned int name, game::VariableValue* value)
	{
		game::classNum_e classnum;
		game::VariableValueInternal* parentValue;
		game::VariableValueInternal* parentValue1;
		unsigned int fieldId;
		game::VariableValue* valuea;

		parentValue1 = &game::gScrVarGlob[inst].parentVariables[parentId + 1];

		assert((parentValue1->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(IsObject(parentValue1));

		assert(((parentValue1->w.type & VAR_MASK) >= game::FIRST_OBJECT && (parentValue1->w.type & VAR_MASK) < game::FIRST_NONFIELD_OBJECT) ||
			((parentValue1->w.type & VAR_MASK) >= game::FIRST_DEAD_OBJECT));

		if (game::FindVariableIndexInternal(inst, parentId, name))
		{
			game::RemoveVariable(name, parentId, inst);
		}
		else
		{
			parentValue = &game::gScrVarGlob[inst].parentVariables[parentId + 1];
			if ((parentValue->w.status & VAR_MASK) == game::VAR_ENTITY)
			{
				classnum = (game::classNum_e)(parentValue->w.status >> VAR_NAME_BIT_SHIFT);
				fieldId = game::FindArrayVariable(game::gScrClassMap[inst][classnum].id, name, inst);
				if (fieldId)
				{
					valuea = value + 1;
					valuea->type = game::VAR_UNDEFINED;
					game::SetEntityFieldValue(inst, game::gScrVarGlob[inst].childVariables[fieldId].u.u.intValue, parentValue->u.o.u.entnum & VAR_ENT_MASK, classnum, parentValue->u.o.u.entnum >> VAR_CLIENT_MASK, valuea);
				}
			}
		}
	}

	// Completed
	unsigned int GetVariable(game::scriptInstance_t inst, unsigned int parentId, unsigned int unsignedValue)
	{
		return game::gScrVarGlob[inst].childVariables[game::GetVariableIndexInternal(inst, parentId, unsignedValue)].hash.id;
	}

	// Restored
	unsigned int GetNewVariableIndexInternal(game::scriptInstance_t inst, unsigned int parentId, unsigned int name)
	{
		assert(!game::FindVariableIndexInternal(inst, parentId, name));

		return game::GetNewVariableIndexInternal2(name, inst, parentId, (parentId + name) % 0xFFFD + 1);
	}

	// Completed
	unsigned int GetNewVariable(game::scriptInstance_t inst, unsigned int unsignedValue, unsigned int parentId)
	{
		return game::gScrVarGlob[inst].childVariables[game::GetNewVariableIndexInternal(inst, parentId, unsignedValue)].hash.id;
	}

	// Completed
	unsigned int GetObjectVariable(unsigned int id, game::scriptInstance_t inst, unsigned int parentId)
	{
		assert((game::gScrVarGlob[inst].parentVariables[parentId + 1].w.type & VAR_MASK) == game::VAR_ARRAY);

		return game::gScrVarGlob[inst].childVariables[game::GetVariableIndexInternal(inst, parentId, id + 0x10000)].hash.id;
	}

	// Completed
	unsigned int GetNewObjectVariable(game::scriptInstance_t inst, unsigned int id, unsigned int parentId)
	{
		assert((game::gScrVarGlob[inst].parentVariables[parentId + 1].w.type & VAR_MASK) == game::VAR_ARRAY);

		return game::gScrVarGlob[inst].childVariables[game::GetNewVariableIndexInternal(inst, parentId, id + 0x10000)].hash.id;
	}

	// Completed
	void RemoveVariable(unsigned int unsignedValue, unsigned int parentId, game::scriptInstance_t inst)
	{
		unsigned int index;
		unsigned int id;

		index = game::FindVariableIndexInternal(inst, parentId, unsignedValue);

		assert(index);

		id = game::gScrVarGlob[inst].childVariables[index].hash.id;
		game::MakeVariableExternal(&game::gScrVarGlob[inst].parentVariables[parentId + 1], inst, index);
		game::FreeChildValue(id, inst, parentId);
	}

	// Completed
	void RemoveNextVariable(game::scriptInstance_t inst, unsigned int parentId)
	{
		unsigned int index;
		unsigned int id;

		assert((game::gScrVarGlob[inst].parentVariables[parentId + 1].w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		id = game::gScrVarGlob[inst].parentVariables[parentId + 1].nextSibling;

		assert(id);

		index = game::FindVariableIndexInternal(inst, parentId, game::gScrVarGlob[inst].childVariables[id].w.status >> VAR_NAME_BIT_SHIFT);

		assert(index);

		assert(id == game::gScrVarGlob[inst].childVariables[index].hash.id);

		game::MakeVariableExternal(&game::gScrVarGlob[inst].parentVariables[parentId + 1], inst, index);
		game::FreeChildValue(id, inst, parentId);
	}

	// Completed
	void SafeRemoveVariable(unsigned int unsignedValue, unsigned int parentId, game::scriptInstance_t inst)
	{
		unsigned int index;
		unsigned int id;
		game::VariableValueInternal* entryValue;

		index = game::FindVariableIndexInternal(inst, parentId, unsignedValue);
		if (index)
		{
			id = (unsigned int)game::gScrVarGlob[inst].childVariables[index].hash.id;

			entryValue = &game::gScrVarGlob[inst].childVariables[id];

			assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

			assert(!IsObject(entryValue));

			game::MakeVariableExternal(&game::gScrVarGlob[inst].parentVariables[parentId + 1], inst, index);
			game::FreeChildValue(id, inst, parentId);
		}
	}

	// Completed
	void CopyArray(game::scriptInstance_t inst, unsigned int parentId, unsigned int newParentId)
	{
		unsigned int nextSibling;
		game::VariableValueInternal* parentValue;
		game::VariableValueInternal* entryValue;
		game::VariableType type;
		game::VariableValueInternal* newEntryValue;
		unsigned int id;

		parentValue = &game::gScrVarGlob[inst].parentVariables[parentId + 1];

		assert((parentValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(IsObject(parentValue));

		assert((parentValue->w.type & VAR_MASK) == game::VAR_ARRAY);

		id = game::gScrVarGlob[inst].parentVariables[parentId + 1].nextSibling;
		if (id)
		{
			while (true)
			{
				entryValue = &game::gScrVarGlob[inst].childVariables[id];

				assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

				assert(!IsObject(entryValue));

				type = (game::VariableType)(entryValue->w.status & VAR_MASK);
				newEntryValue = &game::gScrVarGlob[inst].childVariables[game::gScrVarGlob[inst].childVariables[game::GetVariableIndexInternal(inst, newParentId, entryValue->w.status >> VAR_NAME_BIT_SHIFT)].hash.id];

				assert((newEntryValue->w.type & VAR_MASK) == game::VAR_UNDEFINED);

				newEntryValue->w.status |= type;

				if (type == game::VAR_POINTER)
				{
					if ((game::gScrVarGlob[inst].parentVariables[entryValue->u.u.intValue + 1].w.status & VAR_MASK) == game::VAR_ARRAY)
					{
						newEntryValue->u.u.pointerValue = game::Scr_AllocArray(inst);
						game::CopyArray(inst, entryValue->u.u.pointerValue, newEntryValue->u.u.pointerValue);
					}
					else
					{
						newEntryValue->u.u.pointerValue = entryValue->u.u.pointerValue;
						game::AddRefToObject(inst, entryValue->u.u.pointerValue);
					}
				}
				else
				{
					assert(type != game::VAR_STACK);

					auto tmp = entryValue->u.o.u;
					newEntryValue->u.u.stackValue = entryValue->u.u.stackValue;
					newEntryValue->u.o.u = tmp;
					game::AddRefToValue(inst, type, entryValue->u.u);
				}

				nextSibling = game::gScrVarGlob[inst].childVariables[id].nextSibling;
				if (!nextSibling)
				{
					break;
				}

				id = game::gScrVarGlob[inst].childVariables[nextSibling].hash.id;

				assert(id);
			}
		}
	}

	// Completed
	void SetVariableValue(game::scriptInstance_t inst, game::VariableValue* value, unsigned int id)
	{
		game::VariableValueInternal* entryValue;

		assert(id);

		assert(value->type < game::VAR_THREAD);

		assert(value->type >= game::VAR_UNDEFINED && value->type < game::VAR_COUNT);

		assert(value->type != game::VAR_STACK);

		entryValue = &game::gScrVarGlob[inst].childVariables[id];

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(!IsObject(entryValue));

		assert((entryValue->w.type & VAR_MASK) != game::VAR_STACK);

		game::RemoveRefToValueInternal(inst, (game::VariableType)(entryValue->w.status & VAR_MASK), entryValue->u.u);
		entryValue->w.status &= ~VAR_MASK;
		entryValue->w.status |= value->type;
		entryValue->u.u.intValue = value->u.intValue;
	}

	// Completed
	void SetVariableEntityFieldValue(game::scriptInstance_t inst, unsigned int entId, unsigned int fieldName, game::VariableValue* value)
	{
		game::VariableValueInternal* entValue;
		game::VariableValueInternal* entryValue;
		unsigned int fieldId;

		assert(value->type < game::VAR_THREAD);

		assert(value->type != game::VAR_STACK);

		entValue = &game::gScrVarGlob[inst].parentVariables[entId + 1];

		assert((entValue->w.type & VAR_MASK) == game::VAR_ENTITY);

		assert((entValue->w.classnum >> VAR_NAME_BIT_SHIFT) < game::CLASS_NUM_COUNT);

		fieldId = game::FindArrayVariable(game::gScrClassMap[inst][entValue->w.status >> VAR_NAME_BIT_SHIFT].id, fieldName, inst);
		if (!fieldId || !game::SetEntityFieldValue(inst, game::gScrVarGlob[inst].childVariables[fieldId].u.u.intValue, entValue->u.o.u.entnum & VAR_ENT_MASK, (game::classNum_e)(entValue->w.status >> VAR_NAME_BIT_SHIFT), entValue->u.o.u.entnum >> VAR_CLIENT_MASK, value))
		{
			entryValue = &game::gScrVarGlob[inst].childVariables[game::GetNewVariable(inst, fieldName, entId)];

			assert((entryValue->w.type & VAR_MASK) == game::VAR_UNDEFINED);

			entryValue->w.status |= value->type;
			entryValue->u.u.intValue = value->u.intValue;
		}
	}

	// Completed
	game::VariableValue Scr_EvalVariable(game::scriptInstance_t inst, unsigned int id)
	{
		game::VariableValueInternal* entryValue;
		game::VariableValue value;

		entryValue = &game::gScrVarGlob[inst].childVariables[id];

		assert(((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE) || !id);

		value.type = (game::VariableType)(entryValue->w.status & VAR_MASK);

		assert(value.type < game::VAR_THREAD);

		value.u.intValue = entryValue->u.u.intValue;
		game::AddRefToValue(inst, value.type, value.u);
		return value;
	}

	// Completed
	unsigned int Scr_EvalVariableObject(game::scriptInstance_t inst, unsigned int id)
	{
		game::VariableValueInternal* entryValue;
		game::VariableType type;

		entryValue = &game::gScrVarGlob[inst].childVariables[id];

		assert(((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE) || !id);

		type = (game::VariableType)(entryValue->w.status & VAR_MASK);
		if (type == game::VAR_POINTER && (type = (game::VariableType)(game::gScrVarGlob[inst].parentVariables[entryValue->u.u.stringValue + 1].w.status & VAR_MASK), (int)type < (int)game::FIRST_NONFIELD_OBJECT))
		{
			assert((int)type >= (int)game::FIRST_OBJECT);

			return entryValue->u.u.stringValue;
		}
		else
		{
			game::Scr_Error(game::va("%s is not a field object", game::var_typename[type]), inst, false);
		}

		return 0;
	}

	// Completed
	game::VariableValue Scr_EvalVariableEntityField(unsigned int entId, game::scriptInstance_t inst, unsigned int fieldName)
	{
		game::VariableValue result;
		game::VariableValueInternal* entValue;
		unsigned int fieldId;

		entValue = &game::gScrVarGlob[inst].parentVariables[entId + 1];

		assert((entValue->w.type & VAR_MASK) == game::VAR_ENTITY);

		assert((entValue->w.classnum >> VAR_NAME_BIT_SHIFT) < game::CLASS_NUM_COUNT);

		fieldId = game::FindArrayVariable(game::gScrClassMap[inst][entValue->w.status >> 8].id, fieldName, inst);

		if (!fieldId)
		{
			result.u.intValue = 0;
			result.type = game::VAR_UNDEFINED;
			return result;
		}

		result = game::GetEntityFieldValue(game::gScrVarGlob[inst].childVariables[fieldId].u.u.intValue, entValue->u.o.u.entnum & VAR_ENT_MASK, inst, entValue->w.status >> VAR_NAME_BIT_SHIFT, entValue->u.o.u.entnum >> VAR_CLIENT_MASK);

		if (result.type == game::VAR_POINTER)
		{
			// t5 doesnt do this
			auto parentId = result.u.intValue;
			auto newParentId = result.u.intValue;
			auto parentValue = &game::gScrVarGlob[inst].parentVariables[result.u.intValue + 1];

			if ((parentValue->w.status & VAR_MASK) == game::VAR_ARRAY)
			{
				if (parentValue->u.next)
				{
					game::RemoveRefToObject(result.u.stringValue, inst);
					newParentId = game::Scr_AllocArray(inst);
					game::CopyArray(inst, parentId, newParentId);
				}

				result.u.intValue = newParentId;
				result.type = game::VAR_POINTER;
			}
		}

		return result;
	}

	// Completed
	game::VariableValue Scr_EvalVariableField(game::scriptInstance_t inst, unsigned int id)
	{
		if (id)
		{
			return game::Scr_EvalVariable(inst, id);
		}

		return game::Scr_EvalVariableEntityField(game::gScrVarPub[inst].entId, inst, game::gScrVarPub[inst].entFieldName);
	}

	// Completed
	void Scr_EvalSizeValue(game::scriptInstance_t inst, game::VariableValue* value)
	{
		game::VariableValueInternal* entryValue;
		const char* error_message;
		unsigned int id;

		if (value->type == game::VAR_POINTER)
		{
			id = value->u.intValue;
			entryValue = &game::gScrVarGlob[inst].parentVariables[id + 1];
			value->type = game::VAR_INTEGER;

			if ((entryValue->w.status & VAR_MASK) == game::VAR_ARRAY)
			{
				value->u.intValue = entryValue->u.o.u.size;
			}
			else
			{
				value->u.intValue = 1;
			}

			game::RemoveRefToObject(id, inst);
		}
		else if (value->type == game::VAR_STRING)
		{
			value->type = game::VAR_INTEGER;
			id = value->u.stringValue;
			value->u.intValue = strlen(game::SL_ConvertToString(id, inst));
			game::SL_RemoveRefToString(id, inst);
		}
		else
		{
			assert(value->type != game::VAR_STACK);

			error_message = game::va("size cannot be applied to %s", game::var_typename[value->type]);
			game::RemoveRefToValueInternal(inst, value->type, value->u);
			value->type = game::VAR_UNDEFINED;
			game::Scr_Error(error_message, inst, 0);
		}
	}

	// Restored
	unsigned int AllocObject(game::scriptInstance_t inst)
	{
		game::VariableValueInternal* entryValue;
		unsigned int id;

		id = game::AllocVariable(inst);
		entryValue = &game::gScrVarGlob[inst].parentVariables[id + 1];
		entryValue->w.status = VAR_STAT_EXTERNAL;

		assert((entryValue->w.type & VAR_MASK) == game::VAR_UNDEFINED);

		entryValue->w.status |= game::VAR_OBJECT;
		entryValue->u.o.refCount = 0;
		return id;
	}

	// Completed
	unsigned int GetObject(game::scriptInstance_t inst, unsigned int id)
	{
		game::VariableValueInternal* entryValue;

		assert(id);

		entryValue = &game::gScrVarGlob[inst].childVariables[id];

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert((entryValue->w.type & VAR_MASK) == game::VAR_UNDEFINED || (entryValue->w.type & VAR_MASK) == game::VAR_POINTER);

		if ((entryValue->w.status & VAR_MASK) == game::VAR_UNDEFINED)
		{
			entryValue->w.status |= game::VAR_POINTER;
			entryValue->u.u.pointerValue = game::AllocObject(inst);
		}

		assert((entryValue->w.type & VAR_MASK) == game::VAR_POINTER);

		return entryValue->u.u.pointerValue;
	}

	// Completed
	unsigned int GetArray(game::scriptInstance_t inst, unsigned int id)
	{
		game::VariableValueInternal* entryValue;

		assert(id);

		entryValue = &game::gScrVarGlob[inst].childVariables[id];

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert((entryValue->w.type & VAR_MASK) == game::VAR_UNDEFINED || (entryValue->w.type & VAR_MASK) == game::VAR_POINTER);

		if ((entryValue->w.status & VAR_MASK) == game::VAR_UNDEFINED)
		{
			entryValue->w.status |= game::VAR_POINTER;
			entryValue->u.u.pointerValue = game::Scr_AllocArray(inst);
		}

		assert((entryValue->w.type & VAR_MASK) == game::VAR_POINTER);

		return entryValue->u.u.pointerValue;
	}

	// Completed
	void Scr_EvalBoolComplement(game::scriptInstance_t inst, game::VariableValue* value)
	{
		game::VariableType type;

		if (value->type == game::VAR_INTEGER)
		{
			value->u.intValue = ~value->u.intValue;
		}
		else
		{
			type = value->type;
			game::RemoveRefToValueInternal(inst, type, value->u);
			value->type = game::VAR_UNDEFINED;
			game::Scr_Error(game::va("~ cannot be applied to \"%s\"", game::var_typename[type]), inst, 0);
		}
	}

	// Completed
	void Scr_CastBool(game::scriptInstance_t inst, game::VariableValue* value)
	{
		game::VariableType type;

		if (value->type == game::VAR_INTEGER)
		{
			value->u.intValue = value->u.intValue != 0;
		}
		else if (value->type == game::VAR_FLOAT)
		{
			value->type = game::VAR_INTEGER;
			value->u.intValue = value->u.floatValue != 0.0;
		}
		else
		{
			type = value->type;
			game::RemoveRefToValueInternal(inst, type, value->u);
			value->type = game::VAR_UNDEFINED;
			game::Scr_Error(game::va("cannot cast %s to bool", game::var_typename[type]), inst, 0);
		}
	}

	// Completed
	char Scr_CastString(game::scriptInstance_t inst, game::VariableValue* value)
	{
		const float* constTempVector;

		switch (value->type)
		{
		case game::VAR_STRING:
			return 1;
		case game::VAR_INTEGER:
			value->type = game::VAR_STRING;
			value->u.stringValue = game::SL_GetStringForInt(value->u.intValue, inst);
			return 1;
		case game::VAR_FLOAT:
			value->type = game::VAR_STRING;
			value->u.stringValue = game::SL_GetStringForFloat(value->u.floatValue, inst);
			return 1;
		case game::VAR_VECTOR:
			value->type = game::VAR_STRING;
			constTempVector = value->u.vectorValue;
			value->u.stringValue = game::SL_GetStringForVector((float*)value->u.vectorValue, inst);
			game::RemoveRefToVector(constTempVector, inst);
			return 1;
		default:
			game::gScrVarPub[inst].error_message = (char*)game::va("cannot cast %s to string", game::var_typename[value->type]);
			game::RemoveRefToValueInternal(inst, value->type, value->u);
			value->type = game::VAR_UNDEFINED;
			return 0;
		}
	}

	// Restored
	game::VariableType GetValueType(game::scriptInstance_t inst, unsigned int id)
	{
		assert((game::gScrVarGlob[inst].childVariables[id].w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		return (game::VariableType)(game::gScrVarGlob[inst].childVariables[id].w.status & VAR_MASK);
	}

	// Restored
	game::VariableType GetObjectType(game::scriptInstance_t inst, unsigned int id)
	{
		assert((game::gScrVarGlob[inst].parentVariables[id + 1].w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		return (game::VariableType)(game::gScrVarGlob[inst].parentVariables[id + 1].w.status & VAR_MASK);
	}

	// Almost completed
	void Scr_CastDebugString(game::scriptInstance_t inst, game::VariableValue* value)
	{
		unsigned int stringValue;
		const char* s;
		const char* sa;

		switch (value->type)
		{
		case game::VAR_POINTER:
			sa = game::var_typename[game::GetObjectType(inst, value->u.intValue)];
			stringValue = game::SL_GetString_(sa, inst, 0);
			break;
		case game::VAR_STRING:
		case game::VAR_VECTOR:
		case game::VAR_FLOAT:
		case game::VAR_INTEGER:
			game::Scr_CastString(inst, value);
			return;
		case game::VAR_ISTRING:
			value->type = game::VAR_STRING;
			return;
		case game::VAR_ANIMATION:
			//s = game::XAnimGetAnimDebugName(game::Scr_GetAnims(HIWORD(value->u.intValue), game::SCRIPTINSTANCE_SERVER), value->u.intValue);
			s = ""; // TODO
			stringValue = game::SL_GetString_(s, inst, 0);
			break;
		default:
			stringValue = game::SL_GetString_(game::var_typename[value->type], inst, 0);
			break;
		}

		game::RemoveRefToValueInternal(inst, value->type, value->u);
		value->type = game::VAR_STRING;
		value->u.intValue = stringValue;
	}

	// Completed
	void Scr_ClearVector(game::scriptInstance_t inst, game::VariableValue* value)
	{
		int i;

		for (i = 2;
			i >= 0;
			--i)
		{
			game::RemoveRefToValueInternal(inst, value[i].type, value[i].u);
		}
		value->type = game::VAR_UNDEFINED;
	}

	// Restored
	float* Scr_AllocVector_(game::scriptInstance_t inst, const float* v)
	{
		float* vectorValue;

		vectorValue = game::Scr_AllocVector(inst);
		vectorValue[0] = v[0];
		vectorValue[1] = v[1];
		vectorValue[2] = v[2];
		return vectorValue;
	}

	// Completed
	void Scr_CastVector(game::scriptInstance_t inst, game::VariableValue* value)
	{
		int type;
		int i;
		float vec[3];

		for (i = 2;
			i >= 0;
			--i)
		{
			type = value[i].type;
			if (type == game::VAR_FLOAT)
			{
				vec[2 - i] = value[i].u.floatValue;
			}
			else
			{
				if (type != game::VAR_INTEGER)
				{
					game::gScrVarPub[inst].error_index = i + 1;
					game::Scr_ClearVector(inst, value);
					game::Scr_Error(game::va("type %s is not a float", game::var_typename[type]), inst, 0);
					return;
				}
				vec[2 - i] = value[i].u.intValue;
			}
		}

		value->type = game::VAR_VECTOR;
		value->u.vectorValue = game::Scr_AllocVector_(inst, vec);
	}

	// Completed
	game::VariableUnion Scr_EvalFieldObject(game::VariableValue* value, game::scriptInstance_t inst, unsigned int tempVariable)
	{
		game::VariableUnion result;
		unsigned int type;
		game::VariableValue tempValue;

		type = value->type;

		if (type == game::VAR_POINTER && (type = game::gScrVarGlob[inst].parentVariables[value->u.intValue + 1].w.status & VAR_MASK, type < game::FIRST_NONFIELD_OBJECT))
		{
			assert(type >= game::FIRST_OBJECT);

			tempValue.type = game::VAR_POINTER;
			tempValue.u.intValue = value->u.intValue;
			game::SetVariableValue(inst, &tempValue, tempVariable);
			result.intValue = tempValue.u.intValue;
		}
		else
		{
			game::RemoveRefToValueInternal(inst, value->type, value->u);
			game::Scr_Error(game::va("%s is not a field object", game::var_typename[type]), inst, 0);
			result.intValue = 0;
		}

		return result;
	}

	// Completed
	void Scr_UnmatchingTypesError(game::scriptInstance_t inst, game::VariableValue* value2, game::VariableValue* value1)
	{
		int type1;
		int type2;
		char* error_message;

		if (game::gScrVarPub[inst].error_message)
		{
			error_message = 0;
		}
		else
		{
			type1 = value1->type;
			type2 = value2->type;
			game::Scr_CastDebugString(inst, value1);
			game::Scr_CastDebugString(inst, value2);

			assert(value1->type == game::VAR_STRING);

			assert(value2->type == game::VAR_STRING);

			error_message = (char*)game::va("pair '%s' and '%s' has unmatching types '%s' and '%s'", game::SL_ConvertToString(value1->u.intValue, inst), game::SL_ConvertToString(value2->u.intValue, inst), game::var_typename[type1], game::var_typename[type2]);
		}

		game::RemoveRefToValueInternal(inst, value1->type, value1->u);
		value1->type = game::VAR_UNDEFINED;
		game::RemoveRefToValueInternal(inst, value2->type, value2->u);
		value2->type = game::VAR_UNDEFINED;
		game::Scr_Error(error_message, inst, 0);
	}

	// Completed
	void Scr_CastWeakerPair(game::VariableValue* value2, game::VariableValue* value1, game::scriptInstance_t inst)
	{
		game::VariableType type1;
		float* tempVector;
		float* tempVectora;
		float* tempVectorb;
		game::VariableType type2;
		float* tempVectorc;

		type1 = value1->type;
		type2 = value2->type;

		if (type1 != type2)
		{
			if (type1 == game::VAR_FLOAT && type2 == game::VAR_INTEGER)
			{
				value2->type = game::VAR_FLOAT;
				value2->u.floatValue = value2->u.intValue;
				return;
			}

			if (type1 == game::VAR_INTEGER && type2 == game::VAR_FLOAT)
			{
				value1->type = game::VAR_FLOAT;
				value1->u.floatValue = value1->u.intValue;
				return;
			}

			if (type1 == game::VAR_VECTOR)
			{
				if (type2 == game::VAR_FLOAT)
				{
					tempVector = game::Scr_AllocVector(inst);
					tempVector[0] = value2->u.floatValue;
					tempVector[1] = value2->u.floatValue;
					tempVector[2] = value2->u.floatValue;
					value2->u.vectorValue = tempVector;
					value2->type = game::VAR_VECTOR;
					return;
				}

				if (type2 == game::VAR_INTEGER)
				{
					tempVectorc = game::Scr_AllocVector(inst);
					tempVectorc[0] = value2->u.intValue;
					tempVectorc[1] = value2->u.intValue;
					tempVectorc[2] = value2->u.intValue;
					value2->u.vectorValue = tempVectorc;
					value2->type = game::VAR_VECTOR;
					return;
				}
			}
			if (type2 != game::VAR_VECTOR)
			{
				game::Scr_UnmatchingTypesError(inst, value2, value1);
				return;
			}

			if (type1 == game::VAR_FLOAT)
			{
				tempVectora = game::Scr_AllocVector(inst);
				tempVectora[0] = value1->u.floatValue;
				tempVectora[1] = value1->u.floatValue;
				tempVectora[2] = value1->u.floatValue;
				value1->u.vectorValue = tempVectora;
				value1->type = game::VAR_VECTOR;
				return;
			}

			if (type1 == game::VAR_INTEGER)
			{
				tempVectorb = game::Scr_AllocVector(inst);
				tempVectorb[0] = value1->u.intValue;
				tempVectorb[1] = value1->u.intValue;
				tempVectorb[2] = value1->u.intValue;
				value1->u.vectorValue = tempVectorb;
				value1->type = game::VAR_VECTOR;
			}
			else
			{
				game::Scr_UnmatchingTypesError(inst, value2, value1);
			}
		}
	}


	// Completed
	void Scr_CastWeakerStringPair(game::VariableValue* value2, game::VariableValue* value1, game::scriptInstance_t inst)
	{
		game::VariableType type1;
		game::VariableType type2;
		const float* constTempVector;
		const float* constTempVectora;

		type1 = value1->type;
		type2 = value2->type;

		if (type1 != type2)
		{
			if (type1 < type2)
			{
				if (type1 == game::VAR_STRING)
				{
					switch (type2)
					{
					case game::VAR_VECTOR:
						value2->type = game::VAR_STRING;
						constTempVector = value2->u.vectorValue;
						value2->u.stringValue = game::SL_GetStringForVector((float*)value2->u.vectorValue, inst);
						game::RemoveRefToVector(constTempVector, inst);
						return;
					case game::VAR_FLOAT:
						value2->type = game::VAR_STRING;
						value2->u.intValue = game::SL_GetStringForFloat(value2->u.floatValue, inst);
						return;
					case game::VAR_INTEGER:
						value2->type = game::VAR_STRING;
						value2->u.intValue = game::SL_GetStringForInt(value2->u.intValue, inst);
						return;
					}
				}
				else if (type1 != game::VAR_FLOAT)
				{
					game::Scr_UnmatchingTypesError(inst, value2, value1);
					return;
				}

				if (type2 == game::VAR_INTEGER)
				{
					value2->type = game::VAR_FLOAT;
					value2->u.floatValue = value2->u.intValue;
					return;
				}

				game::Scr_UnmatchingTypesError(inst, value2, value1);
				return;
			}

			if (type2 == game::VAR_STRING)
			{
				switch (type1)
				{
				case game::VAR_VECTOR:
					value1->type = game::VAR_STRING;
					constTempVectora = value1->u.vectorValue;
					value1->u.stringValue = game::SL_GetStringForVector((float*)value1->u.vectorValue, inst);
					game::RemoveRefToVector(constTempVectora, inst);
					return;
				case game::VAR_FLOAT:
					value1->type = game::VAR_STRING;
					value1->u.intValue = game::SL_GetStringForFloat(value1->u.floatValue, inst);
					return;
				case game::VAR_INTEGER:
					value1->type = game::VAR_STRING;
					value1->u.intValue = game::SL_GetStringForInt(value1->u.intValue, inst);
					return;
				}
			}
			else if (type2 != game::VAR_FLOAT)
			{
				game::Scr_UnmatchingTypesError(inst, value2, value1);
				return;
			}

			if (type1 == game::VAR_INTEGER)
			{
				value1->type = game::VAR_FLOAT;
				value1->u.floatValue = value1->u.intValue;
				return;
			}

			game::Scr_UnmatchingTypesError(inst, value2, value1);
			return;
		}
	}

	// Completed
	void Scr_EvalOr(game::VariableValue* value1, game::VariableValue* value2, game::scriptInstance_t inst)
	{
		if (value1->type == game::VAR_INTEGER && value2->type == game::VAR_INTEGER)
		{
			value1->u.intValue |= value2->u.intValue;
		}
		else
		{
			game::Scr_UnmatchingTypesError(inst, value2, value1);
		}
	}

	// Completed
	void Scr_EvalExOr(game::VariableValue* value1, game::VariableValue* value2, game::scriptInstance_t inst)
	{
		if (value1->type == game::VAR_INTEGER && value2->type == game::VAR_INTEGER)
		{
			value1->u.intValue ^= value2->u.intValue;
		}
		else
		{
			game::Scr_UnmatchingTypesError(inst, value2, value1);
		}
	}

	// Completed
	void Scr_EvalAnd(game::VariableValue* value1, game::VariableValue* value2, game::scriptInstance_t inst)
	{
		if (value1->type == game::VAR_INTEGER && value2->type == game::VAR_INTEGER)
		{
			value1->u.intValue &= value2->u.intValue;
		}
		else
		{
			game::Scr_UnmatchingTypesError(inst, value2, value1);
		}
	}

	// Completed
	void Scr_EvalEquality(game::VariableValue* value1, game::scriptInstance_t inst, game::VariableValue* value2)
	{
		int tempInt;
		int tempInta;

		game::Scr_CastWeakerPair(value2, value1, inst);

		assert(value1->type == value2->type);

		switch (value1->type)
		{
		case game::VAR_UNDEFINED:
			value1->type = game::VAR_INTEGER;
			value1->u.intValue = 1; // undefined evals to true??
			break;
		case game::VAR_POINTER:
			if (((game::gScrVarGlob[inst].childVariables[value1->u.intValue].w.status & VAR_MASK) == game::VAR_ARRAY || (game::gScrVarGlob[inst].childVariables[value2->u.intValue].w.status & VAR_MASK) == game::VAR_ARRAY) && !game::gScrVarPub[inst].evaluate)
			{
				game::Scr_UnmatchingTypesError(inst, value2, value1);
				break;
			}
			value1->type = game::VAR_INTEGER;
			tempInta = value1->u.pointerValue == value2->u.pointerValue;
			game::RemoveRefToObject(value1->u.intValue, inst);
			game::RemoveRefToObject(value2->u.intValue, inst);
			value1->u.intValue = tempInta;
			break;
		case game::VAR_STRING:
		case game::VAR_ISTRING:
			value1->type = game::VAR_INTEGER;
			tempInt = value1->u.stringValue == value2->u.stringValue;
			game::SL_RemoveRefToString(value1->u.intValue, inst);
			game::SL_RemoveRefToString(value2->u.intValue, inst);
			value1->u.intValue = tempInt;
			break;
		case game::VAR_VECTOR:
		{
			value1->type = game::VAR_INTEGER;
			auto isEqual = *value1->u.vectorValue == *value2->u.vectorValue && *(value1->u.vectorValue + 1) == *(value2->u.vectorValue + 1) && *(value1->u.vectorValue + 2) == *(value2->u.vectorValue + 2);
			game::RemoveRefToVector(value1->u.vectorValue, inst);
			game::RemoveRefToVector(value2->u.vectorValue, inst);
			value1->u.intValue = isEqual;
			break;
		}
		case game::VAR_FLOAT:
			value1->type = game::VAR_INTEGER;
			value1->u.intValue = (fabs(value2->u.floatValue - value1->u.floatValue) < 0.000001f);
			break;
		case game::VAR_INTEGER:
			value1->u.intValue = value1->u.intValue == value2->u.intValue;
			break;
		case game::VAR_FUNCTION:
			value1->type = game::VAR_INTEGER;
			value1->u.intValue = value1->u.codePosValue == value2->u.codePosValue;
			break;
		case game::VAR_ANIMATION:
			value1->type = game::VAR_INTEGER;
			value1->u.intValue = value1->u.intValue == value2->u.intValue;
			break;
		default:
			game::Scr_UnmatchingTypesError(inst, value2, value1);
			break;
		}
	}

	// Completed
	void Scr_EvalLess(game::VariableValue* value2, game::VariableValue* value1, game::scriptInstance_t inst)
	{
		game::Scr_CastWeakerPair(value2, value1, inst);

		assert(value1->type == value2->type);

		if (value1->type == game::VAR_FLOAT)
		{
			value1->type = game::VAR_INTEGER;
			value1->u.intValue = value2->u.floatValue > value1->u.floatValue;
		}
		else if (value1->type == game::VAR_INTEGER)
		{
			value1->u.intValue = value1->u.intValue < value2->u.intValue;
		}
		else
		{
			game::Scr_UnmatchingTypesError(inst, value2, value1);
		}
	}

	// Completed
	void Scr_EvalGreaterEqual(game::scriptInstance_t inst, game::VariableValue* value1, game::VariableValue* value2)
	{
		game::Scr_EvalLess(value2, value1, inst);

		assert((value1->type == game::VAR_INTEGER) || (value1->type == game::VAR_UNDEFINED));

		value1->u.intValue = value1->u.intValue == 0;
	}

	// Completed
	void Scr_EvalGreater(game::VariableValue* value2, game::VariableValue* value1, game::scriptInstance_t inst)
	{
		game::Scr_CastWeakerPair(value2, value1, inst);

		assert(value1->type == value2->type);

		if (value1->type == game::VAR_FLOAT)
		{
			value1->type = game::VAR_INTEGER;
			value1->u.intValue = value1->u.floatValue > value2->u.floatValue;
		}
		else if (value1->type == game::VAR_INTEGER)
		{
			value1->u.intValue = value1->u.intValue > value2->u.intValue;
		}
		else
		{
			game::Scr_UnmatchingTypesError(inst, value2, value1);
		}
	}

	// Completed
	void Scr_EvalLessEqual(game::scriptInstance_t inst, game::VariableValue* value1, game::VariableValue* value2)
	{
		game::Scr_EvalGreater(value2, value1, inst);

		assert((value1->type == game::VAR_INTEGER) || (value1->type == game::VAR_UNDEFINED));

		value1->u.intValue = value1->u.intValue == 0;
	}

	// Completed
	void Scr_EvalShiftLeft(game::VariableValue* value1, game::VariableValue* value2, game::scriptInstance_t inst)
	{
		if (value1->type == game::VAR_INTEGER && value2->type == game::VAR_INTEGER)
		{
			value1->u.intValue <<= value2->u.intValue;
		}
		else
		{
			game::Scr_UnmatchingTypesError(inst, value2, value1);
		}
	}

	// Completed
	void Scr_EvalShiftRight(game::VariableValue* value1, game::VariableValue* value2, game::scriptInstance_t inst)
	{
		if (value1->type == game::VAR_INTEGER && value2->type == game::VAR_INTEGER)
		{
			value1->u.intValue >>= value2->u.intValue;
		}
		else
		{
			game::Scr_UnmatchingTypesError(inst, value2, value1);
		}
	}

	// Completed
	void Scr_EvalPlus(game::scriptInstance_t inst, game::VariableValue* value1, game::VariableValue* value2)
	{
		unsigned int stringValue;
		unsigned int str1Len;
		char* str1;
		char* str2;
		char str[8192];
		unsigned int len;

		game::Scr_CastWeakerStringPair(value2, value1, inst);

		assert(value1->type == value2->type);

		switch (value1->type)
		{
		case game::VAR_STRING:
			str1 = game::SL_ConvertToString(value1->u.intValue, inst);
			str2 = game::SL_ConvertToString(value2->u.intValue, inst);
			str1Len = game::SL_GetStringLen(value1->u.intValue, inst);
			len = str1Len + game::SL_GetStringLen(value2->u.intValue, inst) + 1;
			if (len <= 0x2000)
			{
				strncpy(str, str1, str1Len);
				str[str1Len] = '\0';
				strncat(str, str2, len);
				str[len - 1] = '\0';

				stringValue = game::SL_GetStringOfSize(inst, str, 0, len);
				game::SL_RemoveRefToString(value1->u.intValue, inst);
				game::SL_RemoveRefToString(value2->u.intValue, inst);
				value1->u.stringValue = stringValue;
			}
			else
			{
				game::SL_RemoveRefToString(value1->u.intValue, inst);
				game::SL_RemoveRefToString(value2->u.intValue, inst);
				value1->type = game::VAR_UNDEFINED;
				value2->type = game::VAR_UNDEFINED;
				game::Scr_Error(game::va("cannot concat \"%s\" and \"%s\" - max string length exceeded", str1, str2), inst, 0);
			}
			break;
		case game::VAR_VECTOR:
		{
			auto vectorValue = game::Scr_AllocVector(inst);
			vectorValue[0] = *value1->u.vectorValue + *value2->u.vectorValue;
			vectorValue[1] = *(value1->u.vectorValue + 1) + *(value2->u.vectorValue + 1);
			vectorValue[2] = *(value1->u.vectorValue + 2) + *(value2->u.vectorValue + 2);
			game::RemoveRefToVector(value1->u.vectorValue, inst);
			game::RemoveRefToVector(value2->u.vectorValue, inst);
			value1->u.vectorValue = vectorValue;
			break;
		}
		case game::VAR_FLOAT:
			value1->u.floatValue = value1->u.floatValue + value2->u.floatValue;
			break;
		case game::VAR_INTEGER:
			value1->u.intValue += value2->u.intValue;
			break;
		default:
			game::Scr_UnmatchingTypesError(inst, value2, value1);
			break;
		}
	}

	// Completed
	void Scr_EvalMinus(game::VariableValue* value2, game::scriptInstance_t inst, game::VariableValue* value1)
	{
		float* tempVector;

		game::Scr_CastWeakerPair(value2, value1, inst);

		assert(value1->type == value2->type);

		switch (value1->type)
		{
		case game::VAR_VECTOR:
			tempVector = game::Scr_AllocVector(inst);
			tempVector[0] = *value1->u.vectorValue - *value2->u.vectorValue;
			tempVector[1] = *(value1->u.vectorValue + 1) - *(value2->u.vectorValue + 1);
			tempVector[2] = *(value1->u.vectorValue + 2) - *(value2->u.vectorValue + 2);
			game::RemoveRefToVector(value1->u.vectorValue, inst);
			game::RemoveRefToVector(value2->u.vectorValue, inst);
			value1->u.vectorValue = tempVector;
			break;
		case game::VAR_FLOAT:
			value1->u.floatValue = value1->u.floatValue - value2->u.floatValue;
			break;
		case game::VAR_INTEGER:
			value1->u.intValue -= value2->u.intValue;
			break;
		default:
			game::Scr_UnmatchingTypesError(inst, value2, value1);
			break;
		}
	}

	// Completed
	void Scr_EvalMultiply(game::VariableValue* value2, game::scriptInstance_t inst, game::VariableValue* value1)
	{
		float* tempVector;

		game::Scr_CastWeakerPair(value2, value1, inst);

		assert(value1->type == value2->type);

		switch (value1->type)
		{
		case game::VAR_VECTOR:
			tempVector = game::Scr_AllocVector(inst);
			tempVector[0] = *value1->u.vectorValue * *value2->u.vectorValue;
			tempVector[1] = *(value1->u.vectorValue + 1) * *(value2->u.vectorValue + 1);
			tempVector[2] = *(value1->u.vectorValue + 2) * *(value2->u.vectorValue + 2);
			game::RemoveRefToVector(value2->u.vectorValue, inst);
			game::RemoveRefToVector(value1->u.vectorValue, inst);
			value1->u.vectorValue = tempVector;
			break;
		case game::VAR_FLOAT:
			value1->u.floatValue = value1->u.floatValue * value2->u.floatValue;
			break;
		case game::VAR_INTEGER:
			value1->u.intValue *= value2->u.intValue;
			break;
		default:
			game::Scr_UnmatchingTypesError(inst, value2, value1);
			break;
		}
	}

	// Completed
	void Scr_EvalDivide(game::VariableValue* value2, game::scriptInstance_t inst, game::VariableValue* value1)
	{
		float* tempVector;

		game::Scr_CastWeakerPair(value2, value1, inst);

		assert(value1->type == value2->type);

		switch (value1->type)
		{
		case game::VAR_VECTOR:
			tempVector = game::Scr_AllocVector(inst);

			if (*value2->u.vectorValue == 0.0f || *(value2->u.vectorValue + 1) == 0.0f || *(value2->u.vectorValue + 2) == 0.0f)
			{
				tempVector[0] = 0.0f;
				tempVector[1] = 0.0f;
				tempVector[2] = 0.0f;
				game::RemoveRefToVector(value1->u.vectorValue, inst);
				game::RemoveRefToVector(value2->u.vectorValue, inst);
				value1->u.vectorValue = tempVector;
				game::Scr_Error("divide by 0", inst, 0);
				return;
			}
			else
			{
				tempVector[0] = *value1->u.vectorValue / *value2->u.vectorValue;
				tempVector[1] = *(value1->u.vectorValue + 1) / *(value2->u.vectorValue + 1);
				tempVector[2] = *(value1->u.vectorValue + 2) / *(value2->u.vectorValue + 2);
				game::RemoveRefToVector(value1->u.vectorValue, inst);
				game::RemoveRefToVector(value2->u.vectorValue, inst);
				value1->u.vectorValue = tempVector;
			}
			break;
		case game::VAR_FLOAT:
			if (value2->u.floatValue == 0.0)
			{
				value1->u.floatValue = 0.0f;
				game::Scr_Error("divide by 0", inst, 0);
				return;
			}

			value1->u.floatValue = value1->u.floatValue / value2->u.floatValue;
			break;
		case game::VAR_INTEGER:
			value1->type = game::VAR_FLOAT;
			if (value2->u.intValue)
			{
				value1->u.floatValue = (float)(value1->u.intValue) / value2->u.intValue;
				return;
			}

			game::Scr_Error("divide by 0", inst, 0);
			return;
		default:
			game::Scr_UnmatchingTypesError(inst, value2, value1);
			break;
		}
	}

	// Completed
	void Scr_EvalMod(game::scriptInstance_t inst, game::VariableValue* value1, game::VariableValue* value2)
	{
		if (value1->type == game::VAR_INTEGER && value2->type == game::VAR_INTEGER)
		{
			if (value2->u.intValue)
			{
				value1->u.intValue %= value2->u.intValue;
			}
			else
			{
				value1->u.intValue = 0;
				game::Scr_Error("divide by 0", inst, 0);
			}
		}
		else
		{
			game::Scr_UnmatchingTypesError(inst, value2, value1);
		}
	}

	// Restored
	void Scr_EvalInequality(game::scriptInstance_t inst, game::VariableValue* value1, game::VariableValue* value2)
	{
		game::Scr_EvalEquality(value1, inst, value2);

		assert((value1->type == game::VAR_INTEGER) || (value1->type == game::VAR_UNDEFINED));

		value1->u.intValue = value1->u.intValue == 0;
	}

	// Completed
	void Scr_EvalBinaryOperator(game::scriptInstance_t inst, game::VariableValue* value2, game::OpcodeVM op, game::VariableValue* value1)
	{
		switch (op)
		{
		case game::OP_bit_or:
			game::Scr_EvalOr(value1, value2, inst);
			break;
		case game::OP_bit_ex_or:
			game::Scr_EvalExOr(value1, value2, inst);
			break;
		case game::OP_bit_and:
			game::Scr_EvalAnd(value1, value2, inst);
			break;
		case game::OP_equality:
			game::Scr_EvalEquality(value1, inst, value2);
			break;
		case game::OP_inequality:
			game::Scr_EvalInequality(inst, value1, value2);
			break;
		case game::OP_less:
			game::Scr_EvalLess(value2, value1, inst);
			break;
		case game::OP_greater:
			game::Scr_EvalGreater(value2, value1, inst);
			break;
		case game::OP_less_equal:
			game::Scr_EvalLessEqual(inst, value1, value2);
			break;
		case game::OP_greater_equal:
			game::Scr_EvalGreaterEqual(inst, value1, value2);
			break;
		case game::OP_shift_left:
			game::Scr_EvalShiftLeft(value1, value2, inst);
			break;
		case game::OP_shift_right:
			game::Scr_EvalShiftRight(value1, value2, inst);
			break;
		case game::OP_plus:
			game::Scr_EvalPlus(inst, value1, value2);
			break;
		case game::OP_minus:
			game::Scr_EvalMinus(value2, inst, value1);
			break;
		case game::OP_multiply:
			game::Scr_EvalMultiply(value2, inst, value1);
			break;
		case game::OP_divide:
			game::Scr_EvalDivide(value2, inst, value1);
			break;
		case game::OP_mod:
			game::Scr_EvalMod(inst, value1, value2);
			break;
		default:
			return;
		}
	}

	// Completed
	void Scr_FreeEntityNum(game::scriptInstance_t inst, game::classNum_e classnum, unsigned int entnum)
	{
		unsigned int entArrayId;
		unsigned int entnumId;
		game::VariableValueInternal* entryValue;
		unsigned int entId;

		if (game::gScrVarPub[inst].bInited)
		{
			entArrayId = game::gScrClassMap[inst][classnum].entArrayId;

			assert(entArrayId);

			entnumId = game::FindArrayVariable(entArrayId, entnum, inst);
			if (entnumId)
			{
				entId = game::FindObject(inst, entnumId);

				assert(entId);

				entryValue = &game::gScrVarGlob[inst].parentVariables[entId + 1];

				assert((entryValue->w.type & VAR_MASK) == game::VAR_ENTITY);

				assert((game::classNum_e)(entryValue->w.classnum >> VAR_NAME_BIT_SHIFT) == classnum);

				entryValue->w.status &= ~VAR_MASK;
				entryValue->w.status |= game::VAR_DEAD_ENTITY;
				game::AddRefToObject(inst, entId);
				entryValue->u.o.u.nextEntId = game::gScrVarPub[inst].freeEntList;
				game::gScrVarPub[inst].freeEntList = entId;
				game::RemoveArrayVariable(inst, entArrayId, entnum);
			}
		}
	}

	// Completed
	void Scr_FreeEntityList(game::scriptInstance_t inst)
	{
		game::VariableValueInternal* entryValue;
		unsigned int entId;

		while (game::gScrVarPub[inst].freeEntList)
		{
			entId = game::gScrVarPub[inst].freeEntList;
			entryValue = &game::gScrVarGlob[inst].parentVariables[entId + 1];
			game::gScrVarPub[inst].freeEntList = entryValue->u.o.u.nextEntId;
			entryValue->u.o.u.nextEntId = 0;
			game::Scr_CancelNotifyList(entId, inst);

			if (entryValue->nextSibling)
			{
				game::ClearObjectInternal(inst, entId);
			}

			game::RemoveRefToObject(entId, inst);
		}
	}

	// Completed
	void Scr_FreeObjects(game::scriptInstance_t inst)
	{
		game::VariableValueInternal* entryValue;
		unsigned int id;

		for (id = 1;
			id < (VARIABLELIST_CHILD_BEGIN - 2);
			++id)
		{
			entryValue = &game::gScrVarGlob[inst].parentVariables[id + 1];
			if ((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE && ((entryValue->w.status & VAR_MASK) == game::VAR_OBJECT || (entryValue->w.status & VAR_MASK) == game::VAR_DEAD_ENTITY))
			{
				game::Scr_CancelNotifyList(id, inst);
				game::ClearObject(id, inst);
			}
		}
	}

	// Completed
	void Scr_SetClassMap(game::scriptInstance_t inst, game::classNum_e classnum)
	{
		assert(!game::gScrClassMap[inst][classnum].entArrayId);

		assert(!game::gScrClassMap[inst][classnum].id);

		game::gScrClassMap[inst][classnum].entArrayId = game::Scr_AllocArray(inst);
		game::gScrClassMap[inst][classnum].id = game::Scr_AllocArray(inst);
	}

	// Completed
	void Scr_RemoveClassMap(game::classNum_e classnum, game::scriptInstance_t inst)
	{
		if (game::gScrVarPub[inst].bInited)
		{
			if (game::gScrClassMap[inst][classnum].entArrayId)
			{
				game::RemoveRefToObject(game::gScrClassMap[inst][classnum].entArrayId, inst);
				game::gScrClassMap[inst][classnum].entArrayId = 0;
			}
			if (game::gScrClassMap[inst][classnum].id)
			{
				game::RemoveRefToObject(game::gScrClassMap[inst][classnum].id, inst);
				game::gScrClassMap[inst][classnum].id = 0;
			}
		}
	}

	// Restored
	unsigned int GetNewArrayVariableIndex(game::scriptInstance_t inst, unsigned int parentId, unsigned int unsignedValue)
	{
		assert(game::IsValidArrayIndex(inst, unsignedValue));

		return game::GetNewVariableIndexInternal(inst, parentId, (unsignedValue + 0x800000) & 0xFFFFFF);
	}

	// Restored
	unsigned int GetNewArrayVariable(game::scriptInstance_t inst, unsigned int parentId, unsigned int unsignedValue)
	{
		return game::gScrVarGlob[inst].childVariables[game::GetNewArrayVariableIndex(inst, parentId, unsignedValue)].hash.id;
	}

	// Completed
	void Scr_AddClassField(game::scriptInstance_t inst, game::classNum_e classnum, const char* name, unsigned int offset)
	{
		unsigned int str;
		unsigned int stra;
		unsigned int classId;
		game::VariableValueInternal* entryValue;
		game::VariableValueInternal* entryValuea;
		unsigned int fieldId;
		const char* namePos;

		assert(offset < VARIABLELIST_CHILD_SIZE);

		for (namePos = name; *namePos; ++namePos)
		{
			assert((*namePos < 'A' || *namePos > 'Z'));
		}

		classId = game::gScrClassMap[inst][classnum].id;
		str = game::SL_GetCanonicalString(name, inst);

		assert(!game::FindArrayVariable(classId, str, inst));

		entryValue = &game::gScrVarGlob[inst].childVariables[game::GetNewArrayVariable(inst, classId, str)];
		entryValue->w.status &= ~VAR_MASK;
		entryValue->w.status |= game::VAR_INTEGER;
		entryValue->u.u.intValue = offset;
		stra = game::SL_GetString_(name, inst, 0);

		assert(!game::FindVariable(stra, classId, inst));

		fieldId = game::GetNewVariable(inst, stra, classId);
		game::SL_RemoveRefToString(stra, inst);
		entryValuea = &game::gScrVarGlob[inst].childVariables[fieldId];
		entryValuea->w.status &= ~VAR_MASK;
		entryValuea->w.status |= game::VAR_INTEGER;
		entryValuea->u.u.intValue = offset;
	}

	// Decomp Status: Untested
	// game::VariableUnion __usercall Scr_GetOffset@<eax>(const char *name@<eax>, game::scriptInstance_t inst@<edi>, game::classNum_e classNum)
	game::VariableUnion Scr_GetOffset(const char* name, game::scriptInstance_t inst, game::classNum_e classnum)
	{
		game::VariableUnion result;
		unsigned int classId;
		unsigned int fieldId;

		classId = game::gScrClassMap[inst][classnum].id;
		fieldId = game::FindVariable(game::SL_ConvertFromString(inst, name), classId, inst);

		if (fieldId)
		{
			result.intValue = game::gScrVarGlob[inst].childVariables[fieldId].u.u.intValue;
		}
		else
		{
			result.intValue = -1;
		}

		return result;
	}

	// Decomp Status: Untested
	// unsigned int __usercall FindEntityId@<eax>(unsigned int entClass@<eax>, int entNum@<ecx>, game::scriptInstance_t inst@<edi>)
	unsigned int FindEntityId(unsigned int classnum, int entNum, game::scriptInstance_t inst)
	{
		unsigned int entArrayId;
		game::VariableValueInternal* entryValue;
		unsigned int id;
		unsigned int clientNum = 0;

		if (clientNum && inst == game::SCRIPTINSTANCE_CLIENT)
		{
			entNum += 1536 * clientNum;
		}

		assert(entNum < VARIABLELIST_CHILD_SIZE);

		entArrayId = game::gScrClassMap[inst][classnum].entArrayId;

		assert(entArrayId);

		id = game::FindArrayVariable(entArrayId, entNum, inst);
		if (!id)
		{
			return 0;
		}

		entryValue = &game::gScrVarGlob[inst].childVariables[id];

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert((entryValue->w.type & VAR_MASK) == game::VAR_POINTER);

		assert(entryValue->u.u.pointerValue);

		return entryValue->u.u.pointerValue;
	}

	//Restored function
	unsigned int GetArrayVariable(game::scriptInstance_t inst, unsigned int parentId, unsigned int unsignedValue)
	{
		return game::gScrVarGlob[inst].childVariables[game::GetArrayVariableIndex(unsignedValue, inst, parentId)].hash.id;
	}

	// Decomp Status: Tested, Completed
	// this is the first function i made a usercall detour for  -INeedGames
	// unsigned int __usercall Scr_GetEntityId@<eax>(int entNum@<eax>, game::scriptInstance_t inst, game::classNum_e classnum, int clientnum)
	unsigned int Scr_GetEntityId(int entNum, game::scriptInstance_t inst, game::classNum_e classnum, int clientnum)
	{
		unsigned int result;
		unsigned int entArrayId;
		unsigned __int16 actualEntNum;
		game::VariableValueInternal* entryValue;
		unsigned int entId;
		unsigned int id;

		actualEntNum = entNum;
		if (clientnum && inst == game::SCRIPTINSTANCE_CLIENT)
		{
			entNum += 1536 * clientnum;
		}

		assert(entNum < VARIABLELIST_CHILD_SIZE);

		entArrayId = game::gScrClassMap[inst][classnum].entArrayId;

		assert(entArrayId);

		id = game::GetArrayVariable(inst, entArrayId, entNum);

		assert(id);

		entryValue = &game::gScrVarGlob[inst].childVariables[id];

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		if ((entryValue->w.status & VAR_MASK) != game::VAR_UNDEFINED)
		{
			assert((entryValue->w.type & VAR_MASK) == game::VAR_POINTER);

			result = entryValue->u.u.intValue;
		}
		else
		{
			entId = game::AllocEntity(classnum, inst, actualEntNum, clientnum);

			assert((entryValue->w.type & VAR_MASK) == game::VAR_UNDEFINED);

			entryValue->w.status |= game::VAR_POINTER;
			entryValue->u.u.intValue = entId;
			result = entId;
		}
		return result;
	}

	// Decomp Status: Untested
	// unsigned int __usercall Scr_FindArrayIndex@<eax>(game::scriptInstance_t a1@<eax>, game::VariableValue *a2@<ecx>, unsigned int a3)
	unsigned int Scr_FindArrayIndex(game::scriptInstance_t inst, game::VariableValue* index, unsigned int parentId)
	{
		unsigned int result;
		const char* errorMsg;
		unsigned int id;

		if (index->type == game::VAR_INTEGER)
		{
			if (game::IsValidArrayIndex(inst, index->u.intValue))
			{
				result = game::FindArrayVariable(parentId, index->u.intValue, inst);
			}
			else
			{
				errorMsg = game::va("array index %d out of range", index->u.intValue);
				game::Scr_Error(errorMsg, inst, false);
				game::AddRefToObject(inst, parentId);
				result = 0;
			}
		}
		else if (index->type == game::VAR_STRING)
		{
			id = game::FindVariable(index->u.intValue, parentId, inst);
			game::SL_RemoveRefToString(index->u.intValue, inst);
			result = id;
		}
		else
		{
			errorMsg = game::va("%s is not an array index", game::var_typename[index->type]);
			game::Scr_Error(errorMsg, inst, false);
			game::AddRefToObject(inst, parentId);
			result = 0;
		}
		return result;
	}

	// Decomp Status: Tested, Completed
	// void __usercall Scr_EvalArray(game::scriptInstance_t a2@<ecx>, game::VariableValue *eax0@<eax>, game::VariableValue *a3)
	void Scr_EvalArray(game::scriptInstance_t inst, game::VariableValue* index, game::VariableValue* value)
	{
		const char* errorMsg;
		game::VariableType arrayType;
		char c[4];
		const char* s;
		game::VariableValueInternal* entryValue;

		assert(value != index);

		arrayType = value->type;
		switch (arrayType)
		{
		case game::VAR_POINTER:
			entryValue = &game::gScrVarGlob[inst].parentVariables[value->u.intValue + 1];

			assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

			assert(IsObject(entryValue));

			if ((entryValue->w.status & VAR_MASK) == game::VAR_ARRAY)
			{
				*index = game::Scr_EvalVariable(inst, game::Scr_FindArrayIndex(inst, index, value->u.intValue));
				game::RemoveRefToObject(value->u.intValue, inst);
			}
			else
			{
				game::gScrVarPub[inst].error_index = 1;
				errorMsg = game::va("%s is not an array", game::var_typename[entryValue->w.status & VAR_MASK]);
				game::Scr_Error(errorMsg, inst, false);
			}
			break;
		case game::VAR_STRING:
			if (index->type == game::VAR_INTEGER)
			{
				s = game::SL_ConvertToString(value->u.intValue, inst);
				if (index->u.intValue < 0 || (index->u.intValue >= (int)strlen(s)))
				{
					errorMsg = game::va("string index %d out of range", index->u.intValue);
					game::Scr_Error(errorMsg, inst, false);
				}
				else
				{
					index->type = game::VAR_STRING;
					c[0] = s[index->u.intValue];
					c[1] = 0;
					index->u.intValue = game::SL_GetStringOfSize(inst, c, 0, 2u);
					game::SL_RemoveRefToString(value->u.intValue, inst);
				}
			}
			else
			{
				errorMsg = game::va("%s is not a string index", game::var_typename[index->type]);
				game::Scr_Error(errorMsg, inst, false);
			}
			break;
		case game::VAR_VECTOR:
			if (index->type == game::VAR_INTEGER)
			{
				if (index->u.intValue >= 3u)
				{
					errorMsg = game::va("vector index %d out of range", index->u.intValue);
					game::Scr_Error(errorMsg, inst, false);
				}
				else
				{
					index->type = game::VAR_FLOAT;
					index->u.floatValue = *(float*)(value->u.intValue + 4 * index->u.intValue);
					game::RemoveRefToVector(value->u.vectorValue, inst);
				}
			}
			else
			{
				errorMsg = game::va("%s is not a vector index", game::var_typename[index->type]);
				game::Scr_Error(errorMsg, inst, false);
			}
			break;
		default:

			assert(value->type != game::VAR_STACK);

			game::gScrVarPub[inst].error_index = 1;
			errorMsg = game::va("%s is not an array, string, or vector", game::var_typename[value->type]);
			game::Scr_Error(errorMsg, inst, false);
			break;
		}
	}

	//Custom function added to remove goto
	unsigned int Scr_EvalArrayRefInternal(game::scriptInstance_t inst, game::VariableValue* varValue, game::VariableValueInternal* parentValue)
	{
		game::VariableValueInternal* entryValue;
		unsigned int result;
		unsigned int id;

		if (varValue->type == game::VAR_POINTER)
		{
			entryValue = &game::gScrVarGlob[inst].parentVariables[varValue->u.intValue + 1];

			assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

			assert(IsObject(entryValue));

			if ((entryValue->w.status & VAR_MASK) == game::VAR_ARRAY)
			{
				if (entryValue->u.o.refCount)
				{
					id = varValue->u.intValue;
					game::RemoveRefToObject(varValue->u.stringValue, inst);
					varValue->u.intValue = game::Scr_AllocArray(inst);
					game::CopyArray(inst, id, varValue->u.stringValue);
					parentValue->u.u.intValue = varValue->u.intValue;
				}
				result = varValue->u.intValue;
			}
			else
			{
				game::gScrVarPub[inst].error_index = 1;
				game::Scr_Error(game::va("%s is not an array", game::var_typename[entryValue->w.status & VAR_MASK]), inst, 0);
				result = 0;
			}
		}
		else
		{
			assert(varValue->type != game::VAR_STACK);

			game::gScrVarPub[inst].error_index = 1;
			if (varValue->type == game::VAR_STRING)
			{
				game::Scr_Error("string characters cannot be individually changed", inst, 0);
				result = 0;
			}
			else
			{
				if (varValue->type == game::VAR_VECTOR)
				{
					game::Scr_Error("vector components cannot be individually changed", inst, 0);
				}
				else
				{
					game::Scr_Error(game::va("%s is not an array", game::var_typename[varValue->type]), inst, 0);
				}
				result = 0;
			}
		}
		return result;
	}

	// Decomp Status: Tested, Completed
	unsigned int Scr_EvalArrayRef(game::scriptInstance_t inst, unsigned int parentId)
	{
		game::VariableValueInternal* parentValue;
		game::VariableValueInternal* entValue;
		game::VariableValue varValue;
		unsigned int fieldId;

		if (parentId)
		{
			parentValue = &game::gScrVarGlob[inst].childVariables[parentId];
			varValue.type = (game::VariableType)(parentValue->w.status & VAR_MASK);
			if (varValue.type != game::VAR_UNDEFINED)
			{
				varValue.u.intValue = parentValue->u.u.intValue;
				return game::Scr_EvalArrayRefInternal(inst, &varValue, parentValue);
			}
		}
		else
		{
			entValue = &game::gScrVarGlob[inst].parentVariables[game::gScrVarPub[inst].entId + 1];

			assert((entValue->w.type & VAR_MASK) == game::VAR_ENTITY);

			assert((entValue->w.classnum >> VAR_NAME_BIT_SHIFT) < game::CLASS_NUM_COUNT);

			fieldId = game::FindArrayVariable(game::gScrClassMap[inst][entValue->w.status >> VAR_NAME_BIT_SHIFT].id, game::gScrVarPub[inst].entFieldName, inst);
			if (fieldId)
			{
				varValue = game::GetEntityFieldValue(game::gScrVarGlob[inst].childVariables[fieldId].u.u.intValue, entValue->u.o.u.entnum & VAR_ENT_MASK, inst, entValue->w.status >> VAR_NAME_BIT_SHIFT, entValue->u.o.u.entnum >> VAR_CLIENT_MASK);
				if (varValue.type)
				{
					if (varValue.type == game::VAR_POINTER && !game::gScrVarGlob[inst].parentVariables[varValue.u.intValue + 1].u.o.refCount)
					{
						game::RemoveRefToValueInternal(inst, game::VAR_POINTER, varValue.u);
						game::gScrVarPub[inst].error_index = 1;
						game::Scr_Error("read-only array cannot be changed", inst, 0);
						return 0;
					}
					game::RemoveRefToValueInternal(inst, varValue.type, varValue.u);

					assert((varValue.type != game::VAR_POINTER) || !game::gScrVarGlob[inst].parentVariables[varValue.u.intValue + 1].u.o.refCount);

					parentValue = 0;
					return game::Scr_EvalArrayRefInternal(inst, &varValue, parentValue);
				}
			}
			parentValue = &game::gScrVarGlob[inst].childVariables[game::GetNewVariable(inst, game::gScrVarPub[inst].entFieldName, game::gScrVarPub[inst].entId)];
		}

		assert((parentValue->w.type & VAR_MASK) == game::VAR_UNDEFINED);

		parentValue->w.status |= game::VAR_POINTER;
		parentValue->u.u.intValue = game::Scr_AllocArray(inst);
		return parentValue->u.u.intValue;
	}

	//Restored function
	BOOL IsValidArrayIndex([[maybe_unused]] game::scriptInstance_t inst, unsigned int unsignedValue)
	{
		return (unsignedValue + 0x7EA002) <= 0xFEA001;
	}

	//Restored function
	void SafeRemoveArrayVariable(game::scriptInstance_t inst, unsigned int parentId, unsigned int unsignedValue)
	{
		assert(game::IsValidArrayIndex(inst, unsignedValue));

		game::SafeRemoveVariable((unsignedValue + 0x800000) & 0xFFFFFF, parentId, inst);
	}

	// Decomp Status:Tested, Completed
	void ClearArray(unsigned int parentId, game::scriptInstance_t inst, game::VariableValue* value)
	{
		game::VariableValueInternal* entValue;
		int fieldId;
		game::VariableValue entFieldValue;
		game::VariableType type;
		game::VariableUnion indexValue;
		game::VariableValueInternal* parentValue;
		const char* errorMsg;
		game::VariableValueInternal* entryValue;
		unsigned int varValue;
		game::VariableType indexType;

		if (parentId)
		{
			parentValue = &game::gScrVarGlob[inst].childVariables[parentId];

			assert((parentValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

			indexValue.intValue = parentValue->u.u.intValue;
			type = (game::VariableType)(parentValue->w.status & VAR_MASK);
			entFieldValue.type = type;
			entFieldValue.u = indexValue;
		}
		else
		{
			entValue = &game::gScrVarGlob[inst].parentVariables[game::gScrVarPub[inst].entId + 1];

			assert((entValue->w.type & VAR_MASK) == game::VAR_ENTITY);

			assert((entValue->w.classnum >> VAR_NAME_BIT_SHIFT) < game::CLASS_NUM_COUNT);

			fieldId = game::FindArrayVariable(game::gScrClassMap[inst][entValue->w.status >> VAR_PARENTID_BIT_SHIFT].id, game::gScrVarPub[inst].entFieldName, inst);
			entFieldValue = game::GetEntityFieldValue(
				game::gScrVarGlob[inst].childVariables[fieldId].u.u.intValue,
				entValue->u.o.u.entnum & VAR_ENT_MASK,
				inst,
				entValue->w.status >> VAR_PARENTID_BIT_SHIFT,
				entValue->u.o.u.entnum >> VAR_CLIENT_MASK);
			if (!fieldId || (entFieldValue.type == game::VAR_UNDEFINED))
			{
				game::gScrVarPub[inst].error_index = 1;
				errorMsg = game::va("%s is not an array", game::var_typename[game::VAR_UNDEFINED]);
				game::Scr_Error(errorMsg, inst, false);
				return;
			}
			if (entFieldValue.type == game::VAR_POINTER && !game::gScrVarGlob[inst].parentVariables[entFieldValue.u.intValue + 1].u.o.refCount)
			{
				game::RemoveRefToValue(inst, &entFieldValue);
				game::gScrVarPub[inst].error_index = 1;
				game::Scr_Error("read-only array cannot be changed", inst, false);
				return;
			}
			game::RemoveRefToValueInternal(inst, entFieldValue.type, entFieldValue.u);

			assert((entFieldValue.type != game::VAR_POINTER) || !game::gScrVarGlob[inst].parentVariables[entFieldValue.u.intValue + 1].u.o.refCount);

			type = entFieldValue.type;
			indexValue.intValue = entFieldValue.u.intValue;
			parentValue = 0;
		}
		if (type != game::VAR_POINTER)
		{
			assert(type != game::VAR_STACK);

			game::gScrVarPub[inst].error_index = 1;
			errorMsg = game::va("%s is not an array", game::var_typename[entFieldValue.type]);
			game::Scr_Error(errorMsg, inst, false);
			return;
		}
		entryValue = &game::gScrVarGlob[inst].parentVariables[indexValue.intValue + 1];

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(IsObject(entryValue));

		type = (game::VariableType)(entryValue->w.status & VAR_MASK);
		if (type == game::VAR_ARRAY)
		{
			if (entryValue->u.o.refCount)
			{
				game::RemoveRefToObject(indexValue.stringValue, inst);
				varValue = game::Scr_AllocArray(inst);
				entFieldValue.u.intValue = varValue;
				game::CopyArray(inst, indexValue.intValue, varValue);

				assert(parentValue);

				parentValue->u.u.intValue = varValue;
				indexValue.intValue = varValue;
			}
			indexType = value->type;
			if (indexType == game::VAR_INTEGER)
			{
				if (!game::IsValidArrayIndex(inst, value->u.intValue))
				{
					errorMsg = game::va("array index %d out of range", value->u.intValue);
					game::Scr_Error(errorMsg, inst, false);
				}
				else
				{
					game::SafeRemoveArrayVariable(inst, indexValue.stringValue, value->u.intValue);
				}
			}
			else if (indexType == game::VAR_STRING)
			{
				game::SL_RemoveRefToString(value->u.intValue, inst);
				game::SafeRemoveVariable(value->u.intValue, entFieldValue.u.stringValue, inst);
			}
			else
			{
				errorMsg = game::va("%s is not an array index", game::var_typename[indexType]);
				game::Scr_Error(errorMsg, inst, false);
			}
		}
		else
		{
			game::gScrVarPub[inst].error_index = 1;
			errorMsg = game::va("%s is not an array", game::var_typename[type]);
			game::Scr_Error(errorMsg, inst, false);
		}
	}

	// Decomp Status: Tested, Completed
	void SetEmptyArray(game::scriptInstance_t inst, unsigned int parentId)
	{
		game::VariableValue tempValue;

		tempValue.type = game::VAR_POINTER;
		tempValue.u.intValue = game::Scr_AllocArray(inst);
		game::SetVariableValue(inst, &tempValue, parentId);
	}

	// Decomp Status: Tested, Completed
	// this is what started JezuzLizard to want to decomp the VM
	void Scr_AddArrayKeys(unsigned int parentId, game::scriptInstance_t inst)
	{
		game::VariableValue indexValue;
		game::VariableValueInternal* entryValue;
		unsigned int id;

		assert(parentId);

		assert(game::GetObjectType(inst, parentId) == game::VAR_ARRAY);

		game::Scr_MakeArray(inst);
		for (id = game::FindFirstSibling(inst, parentId); id; id = game::FindNextSibling(inst, id))
		{
			entryValue = &game::gScrVarGlob[inst].childVariables[id];

			assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE && (entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_EXTERNAL);

			assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

			assert(!IsObject(entryValue));

			indexValue = game::Scr_GetArrayIndexValue(inst, entryValue->w.status >> 8);
			if (indexValue.type == game::VAR_STRING)
			{
				game::Scr_AddConstString(inst, indexValue.u.stringValue);
			}
			else if (indexValue.type == game::VAR_INTEGER)
			{
				game::Scr_AddInt(inst, indexValue.u.intValue);
			}
			else
			{
				assert(false);
				//assertMsg("bad case");
			}
			game::Scr_AddArray(inst);
		}
	}

	// Decomp Status: Tested, Completed
	game::scr_entref_t* Scr_GetEntityIdRef(game::scr_entref_t* retstr, game::scriptInstance_t inst, unsigned int entId)
	{
		game::VariableValueInternal* entValue;
		game::ObjectInfo_u entref;

		entValue = &game::gScrVarGlob[inst].parentVariables[entId + 1];

		assert((entValue->w.type & VAR_MASK) == game::VAR_ENTITY);

		assert((entValue->w.name >> VAR_NAME_BIT_SHIFT) < game::CLASS_NUM_COUNT);

		entref = entValue->u.o.u;
		retstr->entnum = entref.entnum & VAR_ENT_MASK;
		retstr->classnum = entValue->w.status >> VAR_NAME_BIT_SHIFT;
		retstr->client = entref.entnum >> VAR_CLIENT_MASK;
		return retstr;
	}

	// Decomp Status: Tested, Completed
	void CopyEntity(unsigned int parentId, unsigned int newParentId)
	{
		unsigned int name;
		game::VariableValueInternal* parentValue;
		game::VariableValueInternal* newParentValue;
		game::VariableValueInternal* entryValue;
		game::VariableValueInternal* newEntryValue;
		game::VariableType type;
		unsigned int id;
		game::scriptInstance_t inst = game::SCRIPTINSTANCE_SERVER;

		assert(parentId);

		assert(newParentId);

		parentValue = &game::gScrVarGlob[inst].parentVariables[parentId + 1];

		assert((parentValue->w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL);

		assert((parentValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(IsObject(parentValue));

		assert((parentValue->w.type & VAR_MASK) == game::VAR_ENTITY);

		assert((game::gScrVarGlob[inst].parentVariables[newParentId + 1].w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL);

		newParentValue = &game::gScrVarGlob[inst].parentVariables[newParentId + 1];

		assert((newParentValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(IsObject(newParentValue));

		assert((newParentValue->w.status & VAR_MASK) == game::VAR_ENTITY);

		for (id = game::FindFirstSibling(inst, parentId); id; id = game::FindNextSibling(inst, id))
		{
			entryValue = &game::gScrVarGlob[inst].childVariables[id];

			assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE && (entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_EXTERNAL);

			assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

			assert(!IsObject(entryValue));

			name = entryValue->w.status >> VAR_NAME_BIT_SHIFT;

			//assert(name != OBJECT_STACK);

			if (name != OBJECT_STACK)
			{
				assert(!game::FindVariableIndexInternal(inst, newParentId, name));

				newEntryValue = &game::gScrVarGlob[inst].childVariables[game::GetVariable(inst, newParentId, name)];

				assert((newEntryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE && (newEntryValue->w.status & VAR_STAT_MASK) != VAR_STAT_EXTERNAL);

				assert((newEntryValue->w.status & VAR_MASK) == game::VAR_UNDEFINED);

				type = (game::VariableType)(entryValue->w.status & VAR_MASK);

				assert((newEntryValue->w.status & VAR_MASK) == game::VAR_UNDEFINED);

				newEntryValue->w.status |= type;

				assert((newEntryValue->w.name >> VAR_NAME_BIT_SHIFT) == name);

				newEntryValue->u.u.intValue = entryValue->u.u.intValue;
				game::AddRefToValue(inst, type, newEntryValue->u.u);
			}
		}
	}

	// Decomp Status: Tested, Completed
	float Scr_GetEndonUsage(unsigned int parentId, game::scriptInstance_t inst)
	{
		game::VariableValueInternal* parentValue;
		unsigned int id;

		parentValue = &game::gScrVarGlob[inst].parentVariables[parentId + 1];

		assert((parentValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(IsObject(parentValue));

		id = game::FindObjectVariable(inst, game::gScrVarPub[inst].pauseArrayId, parentId);
		if (!id)
		{
			return 0.0f;
		}

		return game::Scr_GetObjectUsage(inst, game::FindObject(inst, id));
	}

	//Restored inlined function
	float Scr_GetEntryUsageInternal(game::scriptInstance_t inst, unsigned int type, game::VariableUnion u)
	{
		float result;
		game::VariableValueInternal* parentValue;

		if (type != game::VAR_POINTER)
		{
			return 0.0f;
		}

		parentValue = &game::gScrVarGlob[inst].parentVariables[u.intValue + 1];

		assert((parentValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(IsObject(parentValue));

		if ((parentValue->w.status & VAR_MASK) == game::VAR_ARRAY)
		{
			result = game::Scr_GetObjectUsage(inst, u.stringValue) / ((float)parentValue->u.o.refCount + 1.0);
		}
		else
		{
			result = 0.0f;
		}
		return result;
	}

	//Restored inlined function
	float Scr_GetEntryUsage(game::scriptInstance_t inst, game::VariableValueInternal* entryValue)
	{
		return game::Scr_GetEntryUsageInternal(inst, entryValue->w.status & 0x1F, entryValue->u.u) + 1.0;
	}

	// Decomp Status: Tested, Completed
	float Scr_GetObjectUsage(game::scriptInstance_t inst, unsigned int parentId)
	{
		game::VariableValueInternal* parentValue;
		float usage;
		unsigned int id;

		parentValue = &game::gScrVarGlob[inst].parentVariables[parentId + 1];

		assert((parentValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(IsObject(parentValue));

		usage = 1.0;
		for (id = game::FindFirstSibling(inst, parentId); id; id = game::FindNextSibling(inst, id))
			usage = game::Scr_GetEntryUsage(inst, &game::gScrVarGlob[inst].childVariables[id]) + usage;
		return usage;
	}

	// Decomp Status: Tested, Completed
	float Scr_GetThreadUsage(game::VariableStackBuffer* stackBuf, game::scriptInstance_t inst, float* endonUsage)
	{
		int size;
		char* buf_1;
		unsigned int parentId;
		char* bufa;
		char buf;
		game::VariableValueInternal* parentValue;
		float threadUsageCount;
		unsigned int parentId2;

		size = stackBuf->size;
		buf_1 = &stackBuf->buf[4 * size + size];
		threadUsageCount = game::Scr_GetObjectUsage(inst, stackBuf->localId);
		*endonUsage = game::Scr_GetEndonUsage(stackBuf->localId, inst);
		parentId2 = stackBuf->localId;
		while (size)
		{
			parentId = *((int*)buf_1 - 1);
			bufa = buf_1 - 4;
			buf = *(bufa - 1);
			buf_1 = bufa - 1;
			--size;
			parentValue = &game::gScrVarGlob[inst].parentVariables[parentId + 1];
			if (buf == game::VAR_CODEPOS)
			{
				parentId2 = game::gScrVarGlob[inst].parentVariables[parentId2 + 1].w.status >> VAR_NAME_BIT_SHIFT;
				threadUsageCount = game::Scr_GetObjectUsage(inst, parentId2) + threadUsageCount;
				*endonUsage = game::Scr_GetEndonUsage(parentId2, inst) + *endonUsage;
			}
			else if (buf == game::VAR_POINTER && (parentValue->w.status & VAR_MASK) == game::VAR_ARRAY)
			{
				threadUsageCount = game::Scr_GetObjectUsage(inst, parentId) / (parentValue->u.o.refCount + 1.0f) + threadUsageCount;
			}
			else
			{
				threadUsageCount = threadUsageCount + 0.0f;
			}
		}
		return threadUsageCount;
	}

	// Decomp Status: Tested, Completed
	unsigned int Scr_FindField(game::scriptInstance_t inst, const char* name, int* type)
	{
		const char* pos;
		const char* posa;
		int len;
		unsigned int index;

		assert(game::gScrVarPub[inst].fieldBuffer);

		for (pos = game::gScrVarPub[inst].fieldBuffer; *pos; pos += len + 3)
		{
			len = strlen(pos) + 1;
			if (!game::I_stricmp(0x7FFFFFFF, (char*)name, pos))
			{
				posa = &pos[len];
				index = *(unsigned short*)posa;
				*type = posa[2];
				return index;
			}
		}
		return 0;
	}

	// Decomp Status: Untested, Completed
	char* Scr_GetSourceFile_LoadObj(const char* filename)
	{
		int len;
		int h;
		char* sourceBuffer;

		len = game::FS_FOpenFileRead(filename, &h); // FS_FOpenFileByMode
		if (h)
		{
			game::fsh[h].fileSize = len;
			game::fsh[h].streamed = 0;
		}
		game::fsh[h].handleSync = 0;
		if (len < 0)
		{
			game::Com_Error(game::ERR_DROP, game::va("\x15" "cannot find '%s'", filename));
			return (char*)0;
		}
		sourceBuffer = (char*)game::Hunk_AllocateTempMemoryHigh(len + 1);
		game::FS_Read(sourceBuffer, len, h);
		sourceBuffer[len] = 0;
		game::FS_FCloseFile(h);
		return sourceBuffer;
	}

	// Decomp Status: Tested, Completed
	char* Scr_GetSourceFile_FastFile(const char* filename)
	{
		game::RawFile* file; // esi

		file = game::DB_FindXAssetHeader(game::ASSET_TYPE_RAWFILE, filename, 1, -1).rawfile;
		if (file)
		{
			return file->buffer;
		}
		game::Com_Error(game::ERR_DROP, game::va("\x15" "cannot find '%s'", filename));
		return nullptr;
	}

	// Decomp Status: Tested, Completed
	void Scr_AddFieldsForFile(game::scriptInstance_t inst, const char* filename)
	{
		char* i;
		game::parseInfo_t* parseInfo;
		unsigned int tokenLen;
		int j;
		char character;
		__int16 slStrOfToken;
		char* token;
		char* targetPos;
		const char* data_p;
		int type;
		int tempType;

		if (!(*game::useFastFile)->current.enabled)
		{
			data_p = game::Scr_GetSourceFile_LoadObj(filename);
		}
		else
		{
			data_p = game::Scr_GetSourceFile_FastFile((char*)filename);
		}
		game::Com_BeginParseSession("Scr_AddFields");
		for (i = (char*)game::Hunk_UserAlloc(*game::g_user, 0, 1); ; *i = 0)
		{
			parseInfo = game::Com_Parse(&data_p);
			if (!data_p)
			{
				break;
			}
			if (!strcmp(parseInfo->token, "float"))
			{
				type = 5;
			}
			else if (!strcmp(parseInfo->token, "int"))
			{
				type = 6;
			}
			else if (!strcmp(parseInfo->token, "string"))
			{
				type = 2;
			}
			else
			{
				if (strcmp(parseInfo->token, "vector"))
				{
					game::Com_Error(game::ERR_DROP, game::va("\x15" "unknown type '%s' in '%s'", parseInfo->token, filename));
					return;
				}
				type = 4;
			}
			parseInfo = game::Com_Parse(&data_p);
			if (!data_p)
			{
				game::Com_Error(game::ERR_DROP, game::va("\x15" "missing field name in '%s'", filename));
				return;
			}
			tokenLen = strlen(parseInfo->token);
			for (j = tokenLen; j >= 0; parseInfo->token[j + 1] = character)
			{
				character = tolower(parseInfo->token[j--]);
			}
			slStrOfToken = game::SL_GetCanonicalString(parseInfo->token, inst);
			if (game::Scr_FindField(inst, parseInfo->token, &tempType))
			{
				game::Com_Error(game::ERR_DROP, "\x15" "duplicate key '%s' in '%s'", parseInfo->token, filename);
				return;
			}

			//assert(i == (game::TempMalloc(0) - 1));

			game::TempMemorySetPos(i);
			token = (char*)game::Hunk_UserAlloc(*game::g_user, tokenLen + 1 + 4, 1);
			strcpy(token, parseInfo->token);
			targetPos = &token[tokenLen + 1];
			*(short*)targetPos = slStrOfToken;
			targetPos += 2;
			*targetPos = type;
			i = targetPos + 1;
		}
		game::Com_EndParseSession();
		game::Hunk_ClearTempMemoryHigh();
	}

	// Decomp Status: Untested, Completed
	void Scr_AddFields_LoadObj(game::scriptInstance_t inst, const char* path, const char* extension)
	{
		const char** files;
		char* v4;
		int numFiles;
		const char** v19;
		char filename[64];
		int i;

		files = game::FS_ListFilteredFiles((*game::fs_searchpaths), path, extension, 0, game::FS_LIST_PURE_ONLY, &numFiles);
		v19 = files;
		v4 = (char*)game::Hunk_UserAlloc(*game::g_user, 0, 1);    // TempMallocAlignStrict
		game::gScrVarPub[inst].fieldBuffer = v4;
		for (i = 0; i < numFiles; ++i)
		{
			if ((inst == game::SCRIPTINSTANCE_CLIENT || strlen(files[i]) <= 6 || game::I_strncmp(files[i], "client", 6))
				&& (inst == game::SCRIPTINSTANCE_SERVER || strlen(files[i]) > 6 && !game::I_strncmp(files[i], "client", 6)))
			{
				sprintf_s(filename, "%s/%s", path, files[i]);

				assert(strlen(filename) < 0x40);

				game::Scr_AddFieldsForFile(inst, filename);
			}
		}
		if (files)
		{
			game::Hunk_UserDestroy((game::HunkUser*)*(files - 1)); // FS_FreeFileList
		}
		*(char*)game::Hunk_UserAlloc(*game::g_user, 1, 1) = 0;
	}

	// Decomp Status: Tested, Completed
	void Scr_AddFields_FastFile(game::scriptInstance_t inst, const char* path, const char* extension)
	{
		char* fieldBuffer;
		const char* radiantKeysName;
		char Buffer[64];

		fieldBuffer = (char*)game::Hunk_UserAlloc(*game::g_user, 0, 1);
		game::gScrVarPub[inst].fieldBuffer = fieldBuffer;
		*fieldBuffer = 0;
		radiantKeysName = "keys";
		if (inst)
		{
			radiantKeysName = "clientkeys";
		}
		sprintf_s(Buffer, "%s/%s.%s", path, radiantKeysName, extension);
		game::Scr_AddFieldsForFile(inst, Buffer);
		*(char*)game::Hunk_UserAlloc(*game::g_user, 1, 1) = 0;
	}

	// Decomp Status: Tested, Completed
	int Scr_MakeValuePrimitive(game::scriptInstance_t inst, unsigned int parentId)
	{
		int id;
		game::VariableValueInternal* entryValue;
		unsigned int varType;
		unsigned int varName;
		game::VariableValueInternal* parentValue;

		parentValue = &game::gScrVarGlob[inst].parentVariables[parentId + 1];

		assert((parentValue->w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL);

		assert((parentValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(IsObject(parentValue));

		assert((parentValue->w.type & VAR_MASK) != game::VAR_THREAD);

		assert((parentValue->w.type & VAR_MASK) != game::VAR_NOTIFY_THREAD);

		assert((parentValue->w.type & VAR_MASK) != game::VAR_TIME_THREAD);

		assert((parentValue->w.type & VAR_MASK) != game::VAR_CHILD_THREAD);

		if ((parentValue->w.status & VAR_MASK) != game::VAR_ARRAY)
		{
			return 0;
		}

		id = game::FindFirstSibling(inst, parentId);
		while (id)
		{
			entryValue = &game::gScrVarGlob[inst].childVariables[id];

			assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE && (entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_EXTERNAL);

			assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

			assert(!IsObject(entryValue));

			varType = entryValue->w.status & VAR_MASK;
			varName = entryValue->w.status >> VAR_NAME_BIT_SHIFT;

			if (varType == game::VAR_POINTER)
			{
				if (!game::Scr_MakeValuePrimitive(inst, entryValue->u.u.intValue))
				{
					game::RemoveVariable(varName, parentId, inst);
					id = game::gScrVarGlob[inst].parentVariables[parentId + 1].nextSibling;
					continue;
				}
			}
			else if (varType > game::VAR_INTEGER && varType <= game::VAR_ANIMATION)
			{
				game::RemoveVariable(varName, parentId, inst);
				id = game::gScrVarGlob[inst].parentVariables[parentId + 1].nextSibling;
				continue;
			}
			else
			{
				assert(varType < game::VAR_UNDEFINED || varType > game::VAR_ANIMATION);
			}

			id = game::FindNextSibling(inst, id);
		}

		return 1;
	}

	// Decomp Status: Tested, Completed
	void Scr_FreeGameVariable(game::scriptInstance_t inst, int bComplete)
	{
		unsigned int* gameId;
		game::VariableValueInternal* entryValue;

		assert(game::gScrVarPub[inst].gameId);

		if (bComplete)
		{
			gameId = &game::gScrVarPub[inst].gameId;
			game::FreeValue(*gameId, inst);
			*gameId = 0;
		}
		else
		{
			entryValue = &game::gScrVarGlob[inst].childVariables[game::gScrVarPub[inst].gameId];

			assert((entryValue->w.type & VAR_MASK) == game::VAR_POINTER);

			game::Scr_MakeValuePrimitive(inst, game::gScrVarGlob[inst].childVariables[game::gScrVarPub[inst].gameId].u.u.intValue);
		}
	}

	// Decomp Status: Tested, Completed
	bool Scr_SLHasLowercaseString(unsigned int parentId, const char* str)
	{
		unsigned int slStr;
		game::VariableValueInternal* childVar;
		unsigned int childVarIndex;
		game::scriptInstance_t inst = game::SCRIPTINSTANCE_SERVER;

		slStr = game::SL_GetLowercaseStringOfLen(inst, str, 0, strlen(str) + 1);
		childVarIndex = game::FindVariableIndexInternal(inst, parentId, slStr);
		if (game::gScrVarGlob[inst].childVariables[childVarIndex].hash.id)
		{
			game::SL_RemoveRefToString(slStr, inst);
			return false;
		}
		else
		{
			childVarIndex = game::GetVariable(inst, parentId, slStr);
			game::SL_RemoveRefToString(slStr, inst);
			childVar = &game::gScrVarGlob[inst].childVariables[childVarIndex];
			game::RemoveRefToValueInternal(inst, (game::VariableType)(childVar->w.status & VAR_MASK), childVar->u.u); // RemoveRefToValue
			childVar->w.status = childVar->w.status & 0xFFFFFFE6 | 6;
			childVar->u.u.intValue = 0;
			return true;
		}
	}
}
#pragma warning(pop)
