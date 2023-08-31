#include <stdinc.hpp>

namespace game
{
	// void __usercall Scr_InitOpcodeLookup(scriptInstance_t a1@<eax>)
	void Scr_InitOpcodeLookup(scriptInstance_t a1, void* call_addr)
	{
		__asm
		{
			mov eax, a1;
			call call_addr;
		}
	}

	// void __usercall Scr_ShutdownOpcodeLookup(scriptInstance_t a1@<ecx>)
	void Scr_ShutdownOpcodeLookup(scriptInstance_t a1, void* call_addr)
	{
		__asm
		{
			mov ecx, a1;
			call call_addr;
		}
	}

	// void __usercall AddOpcodePos(scriptInstance_t a1@<eax>, unsigned int sourcePos, int type)
	void AddOpcodePos(scriptInstance_t a1, unsigned int sourcePos, int type_, void* call_addr)
	{
		__asm
		{
			push type_;
			push sourcePos;
			mov eax, a1;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall RemoveOpcodePos(scriptInstance_t result@<eax>)
	void RemoveOpcodePos(scriptInstance_t result, void* call_addr)
	{
		__asm
		{
			mov eax, result;
			call call_addr;
		}
	}

	// void __usercall AddThreadStartOpcodePos(scriptInstance_t result@<eax>, unsigned int sourcePos)
	void AddThreadStartOpcodePos(scriptInstance_t result, unsigned int sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			mov eax, result;
			call call_addr;
			add esp, 0x4;
		}
	}

	// unsigned int __usercall Scr_GetSourceBuffer@<eax>(scriptInstance_t inst@<eax>, const char *codePos@<esi>)
	unsigned int Scr_GetSourceBuffer(scriptInstance_t a1, const char* codePos, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			mov eax, a1;
			mov esi, codePos;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	// unsigned int __usercall Scr_GetLineNumInternal@<eax>(const char **startLine@<edx>, const char *buf@<ecx>, const char *sourcePos, int *col)
	unsigned int Scr_GetLineNumInternal(const char** startLine, const char* buf, const char* sourcePos, int* col, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			push col;
			push sourcePos;
			mov edx, startLine;
			mov ecx, buf;
			call call_addr;
			mov answer, eax;
			add esp, 0x8;
		}

		return answer;
	}

	// SourceBufferInfo *__usercall Scr_GetNewSourceBuffer@<eax>(scriptInstance_t a1@<eax>)
	SourceBufferInfo* Scr_GetNewSourceBuffer(scriptInstance_t a1, void* call_addr)
	{
		SourceBufferInfo* answer;

		__asm
		{
			mov eax, a1;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	// void __usercall Scr_AddSourceBufferInternal(const char *filename@<eax>, scriptInstance_t inst, const char *codepos, char *buffer, int len, int archive)
	void Scr_AddSourceBufferInternal(const char* filename, scriptInstance_t inst, const char* codepos, char* buffer, int len, int archive, void* call_addr)
	{
		__asm
		{
			push archive;
			push len;
			push buffer;
			push codepos;
			push inst;
			mov eax, filename;
			call call_addr;
			add esp, 0x14;
		}
	}

	// char *__usercall Scr_ReadFile@<eax>(const char *codepos@<edi>, char *filename@<esi>, scriptInstance_t inst, int unused)
	char* Scr_ReadFile(const char* codepos, char* filename, scriptInstance_t inst, int unused, void* call_addr)
	{
		char* answer;

		__asm
		{
			push unused;
			push inst;
			mov edi, codepos;
			mov esi, filename;
			call call_addr;
			mov answer, eax;
			add esp, 0x8;
		}

		return answer;
	}

	// char *__usercall Scr_AddSourceBuffer@<eax>(scriptInstance_t inst@<eax>, int unused_arg1, char *filename, const char *codepos)
	char* Scr_AddSourceBuffer(scriptInstance_t inst, int unused_arg1, char* filename, const char* codepos, void* call_addr)
	{
		char* answer;

		__asm
		{
			push codepos;
			push filename;
			push unused_arg1;
			mov eax, inst;
			call call_addr;
			mov answer, eax;
			add esp, 0xC;
		}

		return answer;
	}

	// void __usercall Scr_CopyFormattedLine(const char *rawLine@<eax>, char *line)
	void Scr_CopyFormattedLine(const char* rawLine, char* line, void* call_addr)
	{
		__asm
		{
			push line;
			mov eax, rawLine;
			call call_addr;
			add esp, 0x4;
		}
	}

	// unsigned int __usercall Scr_GetLineInfo@<eax>(int *col@<edx>, _BYTE *buf@<ecx>, unsigned int sourcePos, char *line)
	unsigned int Scr_GetLineInfo(int* col, const char* buf, unsigned int sourcePos, char* line, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			push line;
			push sourcePos;
			mov edx, col;
			mov ecx, buf;
			call call_addr;
			mov answer, eax;
			add esp, 0x8;
		}

		return answer;
	}

	// void __usercall Scr_PrintSourcePos(unsigned int sourcePos@<edx>, const char *buf@<ecx>, con_channel_e channel@<esi>, scriptInstance_t a4, const char *file)
	void Scr_PrintSourcePos(unsigned int sourcePos, const char* buf, con_channel_e channel, scriptInstance_t a4, const char* file, void* call_addr)
	{
		__asm
		{
			push file;
			push a4;
			mov edx, sourcePos;
			mov ecx, buf;
			mov esi, channel;
			call call_addr;
			add esp, 0x8;
		}
	}

	// OpcodeLookup *__usercall Scr_GetPrevSourcePosOpcodeLookup@<eax>(scriptInstance_t a1@<eax>, const char *codePos@<edi>)
	OpcodeLookup* Scr_GetPrevSourcePosOpcodeLookup(scriptInstance_t a1, const char* codePos, void* call_addr)
	{
		OpcodeLookup* answer;

		__asm
		{
			mov eax, a1;
			mov edi, codePos;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	// void __usercall Scr_GetTextSourcePos(char *line@<edx>, const char *codePos@<ecx>, scriptInstance_t a3)
	void Scr_GetTextSourcePos(char* line, const char* codePos, scriptInstance_t a3, void* call_addr)
	{
		__asm
		{
			push a3;
			mov edx, line;
			mov ecx, codePos;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall Scr_PrintPrevCodePos(const char *codepos@<eax>, scriptInstance_t scriptInstance, con_channel_e channel, unsigned int index)
	void Scr_PrintPrevCodePos(const char* codepos, scriptInstance_t scriptInstance, con_channel_e channel, unsigned int index, void* call_addr)
	{
		__asm
		{
			push index;
			push channel;
			push scriptInstance;
			mov eax, codepos;
			call call_addr;
			add esp, 0xC;
		}
	}

	//void __usercall CompileError2(const char *codePos@<edi>, scriptInstance_t a2@<esi>, char *msg, ...)
	void CompileError2(const char* codePos, scriptInstance_t a2, void* call_addr, const char* msg, ...)
	{
		char Buffer[1024];
		char* Buf = Buffer;
		const char* str_ = "%s";
		va_list ArgList;

		va_start(ArgList, msg);
		vsnprintf(Buffer, 0x400u, msg, ArgList);
		va_end(ArgList);

		__asm
		{
			push Buf;
			push str_;
			mov esi, a2;
			mov edi, codePos;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall RuntimeErrorInternal(const char *msg@<eax>, scriptInstance_t inst@<edi>, con_channel_e channel, const char *codepos, int index)
	void RuntimeErrorInternal(const char* msg, scriptInstance_t inst, con_channel_e channel, const char* codepos, int index, void* call_addr)
	{
		__asm
		{
			push index;
			push codepos;
			push channel;
			mov eax, msg;
			mov edi, inst;
			call call_addr;
			add esp, 0xC;
		}
	}

	// void __usercall RuntimeError(scriptInstance_t inst@<eax>, const char *pos, int error_index, const char *err, const char *err2)
	void RuntimeError(scriptInstance_t inst, const char* pos, int error_index, const char* err, const char* err2, void* call_addr)
	{
		__asm
		{
			push err2;
			push err;
			push error_index;
			push pos;
			mov eax, inst;
			call call_addr;
			add esp, 0x10;
		}
	}

	unsigned int Scr_GetPrevSourcePos(scriptInstance_t inst, const char* codePos, unsigned int index)
	{
		//return cscr_parser::Scr_GetPrevSourcePos(inst, codePos, index);
		return 0;
	}

	void Scr_ShutdownAllocNode(scriptInstance_t inst)
	{
		//cscr_parser::Scr_ShutdownAllocNode(inst);
	}
}