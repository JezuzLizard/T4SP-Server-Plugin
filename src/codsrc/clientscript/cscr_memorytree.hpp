#pragma once

namespace codsrc
{
	game::RefVector* GetRefVector(game::scriptInstance_t inst, unsigned int id);
	int MT_GetSubTreeSize(game::scriptInstance_t inst, int nodeNum);
	void MT_DumpTree(game::scriptInstance_t inst);
	void MT_InitBits(game::scriptInstance_t inst);
	int MT_GetScore(game::scriptInstance_t inst, int num);
	void MT_AddMemoryNode(game::scriptInstance_t inst, int newNode, int size);
	char MT_RemoveMemoryNode(game::scriptInstance_t inst, int oldNode, int size);
	void MT_RemoveHeadMemoryNode(game::scriptInstance_t inst, int size);
	void MT_Init(game::scriptInstance_t inst);
	void MT_Error(game::scriptInstance_t inst, const char* funcName, int numBytes);
	int MT_GetSize(int numBytes, game::scriptInstance_t inst);
	unsigned __int16 MT_AllocIndex(game::scriptInstance_t inst, int numBytes);
	void MT_FreeIndex(int numBytes, game::scriptInstance_t inst, int nodeNum);
	char* MT_Alloc(int numBytes, game::scriptInstance_t inst);
	void MT_Free(void* p, int numBytes, game::scriptInstance_t inst);
	const char* MT_NodeInfoString(game::scriptInstance_t inst, unsigned int nodeNum);
}
