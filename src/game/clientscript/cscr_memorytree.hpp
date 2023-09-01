#pragma once

namespace game
{
	WEAK symbol<int(scriptInstance_t inst, int nodeNum)>MT_GetSubTreeSize{ 0x0, 0x689EF0 };
	WEAK symbol<void(scriptInstance_t inst)>MT_DumpTree{ 0x0, 0x689F40 };
	WEAK symbol<void(scriptInstance_t inst, int newNode, int size)>MT_AddMemoryNode{ 0x0, 0x68A0E0 };
	WEAK symbol<char(scriptInstance_t inst, int oldNode, int size)>MT_RemoveMemoryNode{ 0x0, 0x68A280 };
	WEAK symbol<void(scriptInstance_t inst, int size)>MT_RemoveHeadMemoryNode{ 0x0, 0x68A3E0 };
	WEAK symbol<void(void* p, int numBytes, scriptInstance_t inst)>MT_Free{ 0x0, 0x68A800 };

	inline void* MT_InitBits_ADDR() { return CALL_ADDR(0x0, 0x68A010); }
	void MT_InitBits(scriptInstance_t inst, void* call_addr = MT_InitBits_ADDR());
	inline void* MT_GetScore_ADDR() { return CALL_ADDR(0x0, 0x68A080); }
	int MT_GetScore(scriptInstance_t inst, int num, void* call_addr = MT_GetScore_ADDR());
	inline void* MT_Init_ADDR() { return CALL_ADDR(0x0, 0x68A4F0); }
	void MT_Init(scriptInstance_t inst, void* call_addr = MT_Init_ADDR());
	inline void* MT_Error_ADDR() { return CALL_ADDR(0x0, 0x68A580); }
	void MT_Error(scriptInstance_t inst, const char* funcName, int numBytes, void* call_addr = MT_Error_ADDR());
	inline void* MT_GetSize_ADDR() { return CALL_ADDR(0x0, 0x68A5D0); }
	int MT_GetSize(int numBytes, scriptInstance_t inst, void* call_addr = MT_GetSize_ADDR());
	inline void* MT_AllocIndex_ADDR() { return CALL_ADDR(0x0, 0x68A630); }
	unsigned __int16 MT_AllocIndex(scriptInstance_t inst, int size_, void* call_addr = MT_AllocIndex_ADDR());
	inline void* MT_FreeIndex_ADDR() { return CALL_ADDR(0x0, 0x68A750); }
	void MT_FreeIndex(int numBytes, scriptInstance_t inst, int nodeNum, void* call_addr = MT_FreeIndex_ADDR());
	inline void* MT_Alloc_ADDR() { return CALL_ADDR(0x0, 0x68A7D0); }
	char* MT_Alloc(int numBytes, scriptInstance_t inst, void* call_addr = MT_Alloc_ADDR());

	RefVector* GetRefVector(scriptInstance_t inst, unsigned int id);
}