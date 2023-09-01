#pragma once

namespace codsrc
{
	void Scr_InitOpcodeLookup(game::scriptInstance_t a1);
	void Scr_ShutdownOpcodeLookup(game::scriptInstance_t a1);
	void AddOpcodePos(game::scriptInstance_t a1, unsigned int sourcePos, int type);
	void RemoveOpcodePos(game::scriptInstance_t result);
	void AddThreadStartOpcodePos(game::scriptInstance_t result, unsigned int sourcePos);
	unsigned int Scr_GetSourceBuffer(game::scriptInstance_t a1, const char* codePos);
	unsigned int Scr_GetLineNumInternal(const char** startLine, const char* buf, const char* sourcePos, int* col);
	game::SourceBufferInfo* Scr_GetNewSourceBuffer(game::scriptInstance_t a1);
	void Scr_AddSourceBufferInternal(const char* filename, game::scriptInstance_t inst, const char* codepos, char* buffer, int len, int archive);
	char* Scr_ReadFile_FastFile(game::scriptInstance_t inst, int unused, char* filename, const char* codepos, int archive);
	char* Scr_ReadFile_LoadObj(game::scriptInstance_t inst, int unused_arg1, const char* filename, const char* codepos, int archive);
	char* Scr_ReadFile(const char* codepos, char* filename, game::scriptInstance_t inst, int unused);
	char* Scr_AddSourceBuffer(game::scriptInstance_t inst, int unused_arg1, char* filename, const char* codepos);
	void Scr_CopyFormattedLine(const char* rawLine, char* line);
	unsigned int Scr_GetLineInfo(int* col, const char* buf, unsigned int sourcePos, char* line);
	void Scr_PrintSourcePos(unsigned int sourcePos, const char* buf, game::con_channel_e channel, game::scriptInstance_t a4, const char* file);
	game::OpcodeLookup * Scr_GetPrevSourcePosOpcodeLookup(game::scriptInstance_t a1, const char* codePos);
	void Scr_GetTextSourcePos(char* line, const char* codePos, game::scriptInstance_t a3);
	void Scr_PrintPrevCodePos(const char* codepos, game::scriptInstance_t scriptInstance, game::con_channel_e channel, unsigned int index);
	void CompileError(game::scriptInstance_t a1, unsigned int codePos, const char* msg, ...);
	void CompileError2(const char* codePos, game::scriptInstance_t a2, const char* msg, ...);
	void RuntimeErrorInternal(const char* msg, game::scriptInstance_t inst, game::con_channel_e channel, const char* codepos, int index);
	void RuntimeError(game::scriptInstance_t inst, const char* pos, int error_index, const char* err, const char* err2);

	unsigned int Scr_GetPrevSourcePos(game::scriptInstance_t inst, const char* codePos, unsigned int index);
	void Scr_ShutdownAllocNode(game::scriptInstance_t inst);
}
