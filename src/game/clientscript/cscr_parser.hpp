#pragma once

namespace game
{
	WEAK symbol<char* (scriptInstance_t inst, int unused, char* filename, const char* codepos, int archive)>Scr_ReadFile_FastFile{ 0x0, 0x68AE30 };
	WEAK symbol<char* (scriptInstance_t inst, int unused_arg1, const char* filename, const char* codepos, int archive)>Scr_ReadFile_LoadObj{ 0x0, 0x68AED0 };
	WEAK symbol<void(scriptInstance_t inst, unsigned int codePos, const char* msg, ...)>CompileError{ 0x0, 0x68B470 };

	inline void* Scr_InitOpcodeLookup_ADDR() { return CALL_ADDR(0x0, 0x68A840); }
	void Scr_InitOpcodeLookup(scriptInstance_t inst, void* call_addr = Scr_InitOpcodeLookup_ADDR());
	inline void* Scr_ShutdownOpcodeLookup_ADDR() { return CALL_ADDR(0x0, 0x68A950); }
	void Scr_ShutdownOpcodeLookup(scriptInstance_t inst, void* call_addr = Scr_ShutdownOpcodeLookup_ADDR());
	inline void* AddOpcodePos_ADDR() { return CALL_ADDR(0x0, 0x68A9A0); }
	void AddOpcodePos(scriptInstance_t inst, unsigned int sourcePos, int type_, void* call_addr = AddOpcodePos_ADDR());
	inline void* RemoveOpcodePos_ADDR() { return CALL_ADDR(0x0, 0x68AB80); }
	void RemoveOpcodePos(scriptInstance_t inst, void* call_addr = RemoveOpcodePos_ADDR());
	inline void* AddThreadStartOpcodePos_ADDR() { return CALL_ADDR(0x0, 0x68ABF0); }
	void AddThreadStartOpcodePos(scriptInstance_t inst, unsigned int sourcePos, void* call_addr = AddThreadStartOpcodePos_ADDR());
	inline void* Scr_GetSourceBuffer_ADDR() { return CALL_ADDR(0x0, 0x68B270); }
	unsigned int Scr_GetSourceBuffer(scriptInstance_t inst, const char* codePos, void* call_addr = Scr_GetSourceBuffer_ADDR());
	inline void* Scr_GetLineNumInternal_ADDR() { return CALL_ADDR(0x0, 0x68AC90); }
	unsigned int Scr_GetLineNumInternal(const char** startLine, const char* buf, const char* sourcePos, int* col, void* call_addr = Scr_GetLineNumInternal_ADDR());
	inline void* Scr_GetNewSourceBuffer_ADDR() { return CALL_ADDR(0x0, 0x68ACC0); }
	SourceBufferInfo* Scr_GetNewSourceBuffer(scriptInstance_t inst, void* call_addr = Scr_GetNewSourceBuffer_ADDR());
	inline void* Scr_AddSourceBufferInternal_ADDR() { return CALL_ADDR(0x0, 0x68AD50); }
	void Scr_AddSourceBufferInternal(const char* filename, scriptInstance_t inst, const char* codepos, char* buffer, int len, int archive, void* call_addr = Scr_AddSourceBufferInternal_ADDR());
	inline void* Scr_ReadFile_ADDR() { return CALL_ADDR(0x0, 0x68AFA0); }
	char* Scr_ReadFile(const char* codepos, char* filename, scriptInstance_t inst, int unused, void* call_addr = Scr_ReadFile_ADDR());
	inline void* Scr_AddSourceBuffer_ADDR() { return CALL_ADDR(0x0, 0x68B040); }
	char* Scr_AddSourceBuffer(scriptInstance_t inst, int unused_arg1, char* filename, const char* codepos, void* call_addr = Scr_AddSourceBuffer_ADDR());
	inline void* Scr_CopyFormattedLine_ADDR() { return CALL_ADDR(0x0, 0x68B0E0); }
	void Scr_CopyFormattedLine(const char* rawLine, char* line, void* call_addr = Scr_CopyFormattedLine_ADDR());
	inline void* Scr_GetLineInfo_ADDR() { return CALL_ADDR(0x0, 0x68B140); }
	unsigned int Scr_GetLineInfo(int* col, const char* buf, unsigned int sourcePos, char* line, void* call_addr = Scr_GetLineInfo_ADDR());
	inline void* Scr_PrintSourcePos_ADDR() { return CALL_ADDR(0x0, 0x68B190); }
	void Scr_PrintSourcePos(unsigned int sourcePos, const char* buf, con_channel_e channel, scriptInstance_t inst, const char* file, void* call_addr = Scr_PrintSourcePos_ADDR());
	inline void* Scr_GetPrevSourcePosOpcodeLookup_ADDR() { return CALL_ADDR(0x0, 0x68AC40); }
	OpcodeLookup* Scr_GetPrevSourcePosOpcodeLookup(scriptInstance_t inst, const char* codePos, void* call_addr = Scr_GetPrevSourcePosOpcodeLookup_ADDR());
	inline void* Scr_GetTextSourcePos_ADDR() { return CALL_ADDR(0x0, 0x68B2B0); }
	void Scr_GetTextSourcePos(char* line, const char* codePos, scriptInstance_t inst, void* call_addr = Scr_GetTextSourcePos_ADDR());
	inline void* Scr_PrintPrevCodePos_ADDR() { return CALL_ADDR(0x0, 0x68B340); }
	void Scr_PrintPrevCodePos(const char* codepos, scriptInstance_t scriptInstance, con_channel_e channel, unsigned int index, void* call_addr = Scr_PrintPrevCodePos_ADDR());
	inline void* CompileError2_ADDR() { return CALL_ADDR(0x0, 0x68B600); }
	void CompileError2(const char* codePos, scriptInstance_t a2, void* call_addr, const char* msg, ...);
	inline void* RuntimeErrorInternal_ADDR() { return CALL_ADDR(0x0, 0x68B6D0); }
	void RuntimeErrorInternal(const char* msg, scriptInstance_t inst, con_channel_e channel, const char* codepos, int index, void* call_addr = RuntimeErrorInternal_ADDR());
	inline void* RuntimeError_ADDR() { return CALL_ADDR(0x0, 0x68B790); }
	void RuntimeError(scriptInstance_t inst, const char* pos, int error_index, const char* err, const char* err2, void* call_addr = RuntimeError_ADDR());

	unsigned int Scr_GetPrevSourcePos(scriptInstance_t inst, const char* codePos, unsigned int index);
	void Scr_ShutdownAllocNode(scriptInstance_t inst);
}