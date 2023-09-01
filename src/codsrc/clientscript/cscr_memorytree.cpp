#include <stdinc.hpp>
#include "clientscript_public.hpp"

namespace codsrc
{
	// Restored
	game::RefVector* GetRefVector(game::scriptInstance_t inst, unsigned int id)
	{
		assert(id);

		assert((id * MT_NODE_SIZE) < MT_SIZE);

		return (game::RefVector*)&game::gScrMemTreePub[inst].mt_buffer->nodes[id];
	}

	// Decomp Status: Tested, Completed
	int MT_GetSubTreeSize(game::scriptInstance_t inst, int nodeNum)
	{
		int treeSize;

		if (nodeNum)
		{
			treeSize = game::MT_GetSubTreeSize(inst, game::gScrMemTreeGlob[inst].nodes[nodeNum].next);
			return treeSize + game::MT_GetSubTreeSize(inst, game::gScrMemTreeGlob[inst].nodes[nodeNum].prev) + 1;
		}
		else
		{
			return 0;
		}
	}

	// Decomp Status: Tested, Completed
	void MT_DumpTree(game::scriptInstance_t inst)
	{
		int size;

		//assert(game::gScrMemTreeGlob[inst].totalAlloc == totalAlloc);
		//assert(game::gScrMemTreeGlob[inst].totalAllocBuckets == totalAllocBuckets);

		game::Com_Printf(game::CON_CHANNEL_PARSERSCRIPT, "********************************\n");
		for (int i = 0; i <= MT_NODE_BITS; ++i)
		{
			size = game::MT_GetSubTreeSize(inst, game::gScrMemTreeGlob[inst].head[i]);
			game::Com_Printf(game::CON_CHANNEL_PARSERSCRIPT, "%d subtree has %d * %d = %d free buckets\n", i, size, 1 << i, size << i);
		}
		game::Com_Printf(game::CON_CHANNEL_PARSERSCRIPT, "********************************\n");
		game::Com_Printf(game::CON_CHANNEL_PARSERSCRIPT, "********************************\n");
		game::Com_Printf(game::CON_CHANNEL_PARSERSCRIPT, "********************************\n");

		//assert(totalBuckets == (1 << MEMORY_NODE_BITS) - 1);
	}

	// Decomp Status: Tested, Completed
	void MT_InitBits(game::scriptInstance_t inst)
	{
		char bits;
		int temp;
		int i;

		for (i = 0; i < MT_NUM_BUCKETS; ++i)
		{
			bits = 0;

			for (temp = i; temp; temp >>= 1)
			{
				if (temp & 1)
				{
					++bits;
				}
			}

			game::gScrMemTreeGlob[inst].numBits[i] = bits;

			for (bits = 8; i & ((1 << bits) - 1); --bits);

			game::gScrMemTreeGlob[inst].leftBits[i] = bits;
			bits = 0;

			for (temp = i; temp; temp >>= 1)
			{
				++bits;
			}

			game::gScrMemTreeGlob[inst].logBits[i] = bits;
		}
	}

	// Decomp Status: Tested, Completed
	int MT_GetScore(game::scriptInstance_t inst, int num)
	{
		char bits;

		union MTnum_t
		{
			int i;
			uint8_t b[4];
		};

		assert(num);

		assert(MT_NODE_COUNT - num);

		MTnum_t mtnum;

		mtnum.i = MT_NODE_COUNT - num;

		bits = game::gScrMemTreeGlob[inst].leftBits[mtnum.b[0]];

		if (!mtnum.b[0])
		{
			bits += game::gScrMemTreeGlob[inst].leftBits[mtnum.b[1]];
		}

		return mtnum.i - (game::gScrMemTreeGlob[inst].numBits[mtnum.b[1]] + game::gScrMemTreeGlob[inst].numBits[mtnum.b[0]]) + (1 << bits);
	}

	// Decomp Status: Tested, Completed
	void MT_AddMemoryNode(game::scriptInstance_t inst, int newNode, int size)
	{
		int node;
		int nodeNum;
		int newScore;
		uint16_t* parentNode;
		int level;
		int score;

		assert(size >= 0 && size <= MT_NODE_BITS);

		parentNode = &game::gScrMemTreeGlob[inst].head[size];
		node = game::gScrMemTreeGlob[inst].head[size];
		if (game::gScrMemTreeGlob[inst].head[size])
		{
			newScore = game::MT_GetScore(inst, newNode);
			nodeNum = 0;
			level = MT_NODE_COUNT;
			do
			{
				assert(newNode != node);

				score = game::MT_GetScore(inst, node);

				assert(score != newScore);

				if (score < newScore)
				{
					while (1)
					{
						*parentNode = (short)newNode;
						game::gScrMemTreeGlob[inst].nodes[newNode] = game::gScrMemTreeGlob[inst].nodes[node];
						if (!node)
						{
							break;
						}
						level >>= 1;

						assert(node != nodeNum);

						if (node >= nodeNum)
						{
							parentNode = &game::gScrMemTreeGlob[inst].nodes[newNode].next;
							nodeNum += level;
						}
						else
						{
							parentNode = &game::gScrMemTreeGlob[inst].nodes[newNode].prev;
							nodeNum -= level;
						}

						newNode = node;
						node = *parentNode;
					}
					return;
				}
				level >>= 1;

				assert(newNode != nodeNum);

				if (newNode >= nodeNum)
				{
					parentNode = &game::gScrMemTreeGlob[inst].nodes[node].next;
					nodeNum += level;
				}
				else
				{
					parentNode = &game::gScrMemTreeGlob[inst].nodes[node].prev;
					nodeNum -= level;
				}

				node = *parentNode;
			} while (node);
		}

		*parentNode = (short)newNode;

		game::gScrMemTreeGlob[inst].nodes[newNode].prev = 0;
		game::gScrMemTreeGlob[inst].nodes[newNode].next = 0;
	}

	// Decomp Status: Tested, Completed
	char MT_RemoveMemoryNode(game::scriptInstance_t inst, int oldNode, int size)
	{
		game::MemoryNode tempNodeValue;
		int node;
		game::MemoryNode oldNodeValue;
		int nodeNum;
		uint16_t* parentNode;
		int prevScore;
		int nextScore;
		int level;

		assert(size >= 0 && size <= MT_NODE_BITS);

		nodeNum = 0;
		level = MT_NODE_COUNT;
		parentNode = &game::gScrMemTreeGlob[inst].head[size];

		for (node = *parentNode; node; node = *parentNode)
		{
			if (oldNode == node)
			{
				oldNodeValue = game::gScrMemTreeGlob[inst].nodes[oldNode];

				while (1)
				{
					if (oldNodeValue.prev)
					{
						if (oldNodeValue.next)
						{
							prevScore = game::MT_GetScore(inst, oldNodeValue.prev);
							nextScore = game::MT_GetScore(inst, oldNodeValue.next);

							assert(prevScore != nextScore);

							if (prevScore >= nextScore)
							{
								oldNode = oldNodeValue.prev;
								*parentNode = oldNodeValue.prev;
								parentNode = &game::gScrMemTreeGlob[inst].nodes[oldNodeValue.prev].prev;
							}
							else
							{
								oldNode = oldNodeValue.next;
								*parentNode = oldNodeValue.next;
								parentNode = &game::gScrMemTreeGlob[inst].nodes[oldNodeValue.next].next;
							}
						}
						else
						{
							oldNode = oldNodeValue.prev;
							*parentNode = oldNodeValue.prev;
							parentNode = &game::gScrMemTreeGlob[inst].nodes[oldNodeValue.prev].prev;
						}
					}
					else
					{
						oldNode = oldNodeValue.next;
						*parentNode = oldNodeValue.next;

						if (!oldNodeValue.next)
						{
							return true;
						}

						parentNode = &game::gScrMemTreeGlob[inst].nodes[oldNodeValue.next].next;
					}

					assert(oldNode);

					tempNodeValue = oldNodeValue;
					oldNodeValue = game::gScrMemTreeGlob[inst].nodes[oldNode];
					game::gScrMemTreeGlob[inst].nodes[oldNode] = tempNodeValue;
				}
			}

			if (oldNode == nodeNum)
			{
				return false;
			}

			level >>= 1;

			if (oldNode >= nodeNum)
			{
				parentNode = &game::gScrMemTreeGlob[inst].nodes[node].next;
				nodeNum += level;
			}
			else
			{
				parentNode = &game::gScrMemTreeGlob[inst].nodes[node].prev;
				nodeNum -= level;
			}
		}

		return false;
	}

	// Decomp Status: Tested, Completed
	void MT_RemoveHeadMemoryNode(game::scriptInstance_t inst, int size)
	{
		game::MemoryNode tempNodeValue;
		int oldNode;
		game::MemoryNode oldNodeValue;
		uint16_t* parentNode;
		int prevScore;
		int nextScore;

		assert(size >= 0 && size <= MT_NODE_BITS);

		parentNode = &game::gScrMemTreeGlob[inst].head[size];
		oldNodeValue = game::gScrMemTreeGlob[inst].nodes[*parentNode];

		while (1)
		{
			if (!oldNodeValue.prev)
			{
				oldNode = oldNodeValue.next;
				*parentNode = oldNodeValue.next;
				if (!oldNode)
				{
					break;
				}
				parentNode = &game::gScrMemTreeGlob[inst].nodes[oldNode].next;
			}
			else
			{
				if (oldNodeValue.next)
				{
					prevScore = game::MT_GetScore(inst, oldNodeValue.prev);
					nextScore = game::MT_GetScore(inst, oldNodeValue.next);

					assert(prevScore != nextScore);

					if (prevScore >= nextScore)
					{
						oldNode = oldNodeValue.prev;
						*parentNode = (short)oldNode;
						parentNode = &game::gScrMemTreeGlob[inst].nodes[oldNode].prev;
					}
					else
					{
						oldNode = oldNodeValue.next;
						*parentNode = (short)oldNode;
						parentNode = &game::gScrMemTreeGlob[inst].nodes[oldNode].next;
					}
				}
				else
				{
					oldNode = oldNodeValue.prev;
					*parentNode = (short)oldNode;
					parentNode = &game::gScrMemTreeGlob[inst].nodes[oldNode].prev;
				}
			}
			assert(oldNode != 0);

			tempNodeValue = oldNodeValue;
			oldNodeValue = game::gScrMemTreeGlob[inst].nodes[oldNode];
			game::gScrMemTreeGlob[inst].nodes[oldNode] = tempNodeValue;
		}
	}

	// Decomp Status: Tested, Completed
	void MT_Init(game::scriptInstance_t inst)
	{
		game::Sys_EnterCriticalSection(game::CRITSECT_MEMORY_TREE);

		game::scrMemTreeGlob_t* memTreeBuffer = &game::gScrMemTreeGlob[inst];
		game::gScrMemTreePub[inst].mt_buffer = memTreeBuffer;

		game::MT_InitBits(inst);

		for (int i = 0; i <= MT_NODE_BITS; ++i)
		{
			memTreeBuffer->head[i] = 0;
		}

		memTreeBuffer->nodes[0].next = 0;
		memTreeBuffer->nodes[0].prev = 0;

		for (int i = 0; i < MT_NODE_BITS; ++i)
		{
			game::MT_AddMemoryNode(inst, 1 << i, i);
		}

		game::Sys_LeaveCriticalSection(game::CRITSECT_MEMORY_TREE);
	}

	// Decomp Status: Tested, Completed
	void MT_Error(game::scriptInstance_t inst, const char* funcName, int numBytes)
	{
		game::MT_DumpTree(inst);
		game::Com_Printf(game::CON_CHANNEL_PARSERSCRIPT, "%s: failed memory allocation of %d bytes for script usage\n", funcName, numBytes);
		game::Scr_DumpScriptThreads(inst);
		game::gScrVmPub[inst].terminal_error = 1;
		game::Scr_Error("failed memory allocation for script usage", inst, 0);
	}

	// Decomp Status: Tested, Completed
	int MT_GetSize(int numBytes, game::scriptInstance_t inst)
	{
		int numBuckets;
		int result;

		assert(numBytes > 0);

		if (numBytes >= MT_NODE_COUNT)
		{
			game::MT_Error(inst, "MT_GetSize: max allocation exceeded", numBytes);
			result = 0;
		}
		else
		{
			numBuckets = (numBytes + MT_NODE_SIZE - 1) / MT_NODE_SIZE - 1;
			if (numBuckets > MT_NUM_BUCKETS - 1)
			{
				result = game::gScrMemTreeGlob[inst].logBits[numBuckets >> 8] + 8;
			}
			else
			{
				result = game::gScrMemTreeGlob[inst].logBits[numBuckets];
			}
		}
		return result;
	}

	// Decomp Status: Tested, Completed
	unsigned __int16 MT_AllocIndex(game::scriptInstance_t inst, int numBytes)
	{
		int nodeNum;
		int size = game::MT_GetSize(numBytes, inst);
		int newSize;

		assert(size >= 0 && size <= MT_NODE_BITS);

		game::Sys_EnterCriticalSection(game::CRITSECT_MEMORY_TREE);

		for (newSize = size; ; ++newSize)
		{
			if (newSize > MT_NODE_BITS)
			{
				game::Sys_LeaveCriticalSection(game::CRITSECT_MEMORY_TREE);
				game::MT_Error(inst, "MT_AllocIndex", numBytes);
				return 0;
			}
			nodeNum = game::gScrMemTreeGlob[inst].head[newSize];
			if (game::gScrMemTreeGlob[inst].head[newSize])
			{
				break;
			}
		}

		game::MT_RemoveHeadMemoryNode(inst, newSize);

		while (newSize != size)
		{
			--newSize;
			game::MT_AddMemoryNode(inst, nodeNum + (1 << newSize), newSize);
		}

		//assert(type);

		//assert(!game::gScrMemTreeDebugGlob[inst].mt_usage[nodeNum]);

		//assert(!game::gScrMemTreeDebugGlob[inst].mt_usage_size[nodeNum]);

		game::Sys_LeaveCriticalSection(game::CRITSECT_MEMORY_TREE);
		return (short)nodeNum;
	}

	// Decomp Status: Tested, Completed
	void MT_FreeIndex(int numBytes, game::scriptInstance_t inst, int nodeNum)
	{
		int size = game::MT_GetSize(numBytes, inst);

		assert(size >= 0 && size <= MT_NODE_BITS);

		assert(nodeNum > 0 && nodeNum < MT_NODE_COUNT);

		game::Sys_EnterCriticalSection(game::CRITSECT_MEMORY_TREE);

		//assert(game::gScrMemTreeDebugGlob[inst].mt_usage[nodeNum]);

		//assert(game::gScrMemTreeDebugGlob[inst].mt_usage_size[nodeNum] == size);

		for (int i = 1 << size; size != MT_NODE_BITS; i = 1 << ++size)
		{
			assert(size <= MT_NODE_BITS);

			assert(nodeNum == (nodeNum & ~((1 << size) - 1)));

			if (!game::MT_RemoveMemoryNode(inst, nodeNum ^ i, size))
			{
				break;
			}
			nodeNum &= ~i;
		}
		game::MT_AddMemoryNode(inst, nodeNum, size);

		game::Sys_LeaveCriticalSection(game::CRITSECT_MEMORY_TREE);
	}

	// Decomp Status: Tested, Completed
	char* MT_Alloc(int numBytes, game::scriptInstance_t inst)
	{
		return (char*)(game::gScrMemTreeGlob[inst].nodes + game::MT_AllocIndex(inst, numBytes));
	}

	// Decomp Status: Tested, Completed
	void MT_Free(void* p, int numBytes, game::scriptInstance_t inst)
	{
		assert((game::MemoryNode*)p - game::gScrMemTreeGlob[inst].nodes >= 0 && (game::MemoryNode*)p - game::gScrMemTreeGlob[inst].nodes < MT_NODE_COUNT);

		game::MT_FreeIndex(numBytes, inst, (game::MemoryNode*)p - game::gScrMemTreeGlob[inst].nodes);
	}

	// Restored inlined function
	char* MT_GetRefByIndex(game::scriptInstance_t inst, int index)
	{
		if (index > MT_NODE_COUNT)
		{
			game::MT_Error(inst, "MT_GetRefByIndex: out of bounds index", index);
			return NULL;
		}
		return (char*)&game::gScrMemTreeGlob[inst].nodes[index];
	}
}