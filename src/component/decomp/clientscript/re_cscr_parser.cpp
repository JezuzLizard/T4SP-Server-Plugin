#include <stdinc.hpp>
#include "loader/component_loader.hpp"
#include "utils/hook.hpp"
#include "codsrc/clientscript/cscr_parser.hpp"

//#define RE_CSCR_PARSER_USE_WRAPPERS

namespace re_cscr_parser
{
	utils::hook::detour Scr_InitOpcodeLookup_hook;
	utils::hook::detour Scr_ShutdownOpcodeLookup_hook;
	utils::hook::detour AddOpcodePos_hook;
	utils::hook::detour RemoveOpcodePos_hook;
	utils::hook::detour AddThreadStartOpcodePos_hook;
	utils::hook::detour Scr_GetSourceBuffer_hook;
	utils::hook::detour Scr_GetLineNumInternal_hook;
	utils::hook::detour Scr_GetNewSourceBuffer_hook;
	utils::hook::detour Scr_AddSourceBufferInternal_hook;
	utils::hook::detour Scr_ReadFile_FastFile_hook;
	utils::hook::detour Scr_ReadFile_LoadObj_hook;
	utils::hook::detour Scr_ReadFile_hook;
	utils::hook::detour Scr_AddSourceBuffer_hook;
	utils::hook::detour Scr_CopyFormattedLine_hook;
	utils::hook::detour Scr_GetLineInfo_hook;
	utils::hook::detour Scr_PrintSourcePos_hook;
	utils::hook::detour Scr_GetPrevSourcePosOpcodeLookup_hook;
	utils::hook::detour Scr_GetTextSourcePos_hook;
	utils::hook::detour Scr_PrintPrevCodePos_hook;
	utils::hook::detour CompileError_hook;
	utils::hook::detour CompileError2_hook;
	utils::hook::detour RuntimeErrorInternal_hook;
	utils::hook::detour RuntimeError_hook;

	void* Scr_InitOpcodeLookup_original;
	void* Scr_ShutdownOpcodeLookup_original;
	void* AddOpcodePos_original;
	void* RemoveOpcodePos_original;
	void* AddThreadStartOpcodePos_original;
	void* Scr_GetSourceBuffer_original;
	void* Scr_GetLineNumInternal_original;
	void* Scr_GetNewSourceBuffer_original;
	void* Scr_AddSourceBufferInternal_original;
	void* Scr_ReadFile_FastFile_original;
	void* Scr_ReadFile_LoadObj_original;
	void* Scr_ReadFile_original;
	void* Scr_AddSourceBuffer_original;
	void* Scr_CopyFormattedLine_original;
	void* Scr_GetLineInfo_original;
	void* Scr_PrintSourcePos_original;
	void* Scr_GetPrevSourcePosOpcodeLookup_original;
	void* Scr_GetTextSourcePos_original;
	void* Scr_PrintPrevCodePos_original;
	void* CompileError_original;
	void* CompileError2_original;
	void* RuntimeErrorInternal_original;
	void* RuntimeError_original;

	namespace
	{

		void Scr_InitOpcodeLookup_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			game::Scr_InitOpcodeLookup(a1, Scr_InitOpcodeLookup_original);
#else
			codsrc::Scr_InitOpcodeLookup(a1);
#endif
		}

		// void __usercall Scr_InitOpcodeLookup(game::scriptInstance_t a1@<eax>)
		NAKED void Scr_InitOpcodeLookup_stub()
		{
			_asm
			{
				push eax;
				call Scr_InitOpcodeLookup_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_ShutdownOpcodeLookup_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			game::Scr_ShutdownOpcodeLookup(a1, Scr_ShutdownOpcodeLookup_original);
#else
			codsrc::Scr_ShutdownOpcodeLookup(a1);
#endif
		}

		// void __usercall Scr_ShutdownOpcodeLookup(game::scriptInstance_t a1@<ecx>)
		NAKED void Scr_ShutdownOpcodeLookup_stub()
		{
			_asm
			{
				push ecx;
				call Scr_ShutdownOpcodeLookup_call;
				add esp, 0x4;
				ret;
			}
		}

		void AddOpcodePos_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, unsigned int sourcePos, int type_)
		{
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			game::AddOpcodePos(a1, sourcePos, type_, AddOpcodePos_original);
#else
			codsrc::AddOpcodePos(a1, sourcePos, type_);
#endif
		}

		// void __usercall AddOpcodePos(game::scriptInstance_t a1@<eax>, unsigned int sourcePos, int type)
		NAKED void AddOpcodePos_stub()
		{
			_asm
			{
				push eax;
				call AddOpcodePos_call;
				add esp, 0x4;
				ret;
			}
		}

		void RemoveOpcodePos_call(game::scriptInstance_t result, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			game::RemoveOpcodePos(result, RemoveOpcodePos_original);
#else
			codsrc::RemoveOpcodePos(result);
#endif
		}

		// void __usercall RemoveOpcodePos(game::scriptInstance_t result@<eax>)
		NAKED void RemoveOpcodePos_stub()
		{
			_asm
			{
				push eax;
				call RemoveOpcodePos_call;
				add esp, 0x4;
				ret;
			}
		}

		void AddThreadStartOpcodePos_call(game::scriptInstance_t result, [[maybe_unused]] void* caller_addr, unsigned int sourcePos)
		{
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			game::AddThreadStartOpcodePos(result, sourcePos, AddThreadStartOpcodePos_original);
#else
			codsrc::AddThreadStartOpcodePos(result, sourcePos);
#endif
		}

		// void __usercall AddThreadStartOpcodePos(game::scriptInstance_t result@<eax>, unsigned int sourcePos)
		NAKED void AddThreadStartOpcodePos_stub()
		{
			_asm
			{
				push eax;
				call AddThreadStartOpcodePos_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int Scr_GetSourceBuffer_call(game::scriptInstance_t a1, const char * codePos, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			return game::Scr_GetSourceBuffer(a1, codePos, Scr_GetSourceBuffer_original);
#else
			return codsrc::Scr_GetSourceBuffer(a1, codePos);
#endif
		}

		// unsigned int __usercall Scr_GetSourceBuffer@<eax>(game::scriptInstance_t inst@<eax>, const char *codePos@<esi>)
		NAKED unsigned int Scr_GetSourceBuffer_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call Scr_GetSourceBuffer_call;
				add esp, 0x8;
				ret;
			}
		}

		unsigned int Scr_GetLineNumInternal_call(const char ** startLine, const char * buf, [[maybe_unused]] void* caller_addr, const char * sourcePos, int * col)
		{
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			return game::Scr_GetLineNumInternal(startLine, buf, sourcePos, col, Scr_GetLineNumInternal_original);
#else
			return codsrc::Scr_GetLineNumInternal(startLine, buf, sourcePos, col);
#endif
		}

		// unsigned int __usercall Scr_GetLineNumInternal@<eax>(const char **startLine@<edx>, const char *buf@<ecx>, const char *sourcePos, int *col)
		NAKED unsigned int Scr_GetLineNumInternal_stub()
		{
			_asm
			{
				push ecx;
				push edx;
				call Scr_GetLineNumInternal_call;
				add esp, 0x8;
				ret;
			}
		}

		game::SourceBufferInfo * Scr_GetNewSourceBuffer_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			return game::Scr_GetNewSourceBuffer(a1, Scr_GetNewSourceBuffer_original);
#else
			return codsrc::Scr_GetNewSourceBuffer(a1);
#endif
		}

		// SourceBufferInfo *__usercall Scr_GetNewSourceBuffer@<eax>(game::scriptInstance_t a1@<eax>)
		NAKED game::SourceBufferInfo * Scr_GetNewSourceBuffer_stub()
		{
			_asm
			{
				push eax;
				call Scr_GetNewSourceBuffer_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_AddSourceBufferInternal_call(const char * filename, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, const char * codepos, char * buffer, int len, int archive)
		{
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			game::Scr_AddSourceBufferInternal(filename, inst, codepos, buffer, len, archive, Scr_AddSourceBufferInternal_original);
#else
			codsrc::Scr_AddSourceBufferInternal(filename, inst, codepos, buffer, len, archive);
#endif
		}

		// void __usercall Scr_AddSourceBufferInternal(const char *filename@<eax>, game::scriptInstance_t inst, const char *codepos, char *buffer, int len, int archive)
		NAKED void Scr_AddSourceBufferInternal_stub()
		{
			_asm
			{
				push eax;
				call Scr_AddSourceBufferInternal_call;
				add esp, 0x4;
				ret;
			}
		}

		char * Scr_ReadFile_FastFile_stub(game::scriptInstance_t inst, int unused, char * filename, const char * codepos, int archive)
		{
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			return Scr_ReadFile_FastFile_hook.invoke<char *>(inst, unused, filename, codepos, archive);
#else
			return codsrc::Scr_ReadFile_FastFile(inst, unused, filename, codepos, archive);
#endif
		}

		char * Scr_ReadFile_LoadObj_stub(game::scriptInstance_t inst, int unused_arg1, const char * filename, const char * codepos, int archive)
		{
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			return Scr_ReadFile_LoadObj_hook.invoke<char *>(inst, unused_arg1, filename, codepos, archive);
#else
			return codsrc::Scr_ReadFile_LoadObj(inst, unused_arg1, filename, codepos, archive);
#endif
		}

		char * Scr_ReadFile_call(const char * codepos, char * filename, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, int unused)
		{
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			return game::Scr_ReadFile(codepos, filename, inst, unused, Scr_ReadFile_original);
#else
			return codsrc::Scr_ReadFile(codepos, filename, inst, unused);
#endif
		}

		// char *__usercall Scr_ReadFile@<eax>(const char *codepos@<edi>, char *filename@<esi>, game::scriptInstance_t inst, int unused)
		NAKED char * Scr_ReadFile_stub()
		{
			_asm
			{
				push esi;
				push edi;
				call Scr_ReadFile_call;
				add esp, 0x8;
				ret;
			}
		}

		char * Scr_AddSourceBuffer_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, int unused_arg1, char * filename, const char * codepos)
		{
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			return game::Scr_AddSourceBuffer(inst, unused_arg1, filename, codepos, Scr_AddSourceBuffer_original);
#else
			return codsrc::Scr_AddSourceBuffer(inst, unused_arg1, filename, codepos);
#endif
		}

		// char *__usercall Scr_AddSourceBuffer@<eax>(game::scriptInstance_t inst@<eax>, int unused_arg1, char *filename, const char *codepos)
		NAKED char * Scr_AddSourceBuffer_stub()
		{
			_asm
			{
				push eax;
				call Scr_AddSourceBuffer_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_CopyFormattedLine_call(const char * rawLine, [[maybe_unused]] void* caller_addr, char * line)
		{
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			game::Scr_CopyFormattedLine(rawLine, line, Scr_CopyFormattedLine_original);
#else
			codsrc::Scr_CopyFormattedLine(rawLine, line);
#endif
		}

		// void __usercall Scr_CopyFormattedLine(const char *rawLine@<eax>, char *line)
		NAKED void Scr_CopyFormattedLine_stub()
		{
			_asm
			{
				push eax;
				call Scr_CopyFormattedLine_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int Scr_GetLineInfo_call(int * col, const char * buf, [[maybe_unused]] void* caller_addr, unsigned int sourcePos, char * line)
		{
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			return game::Scr_GetLineInfo(col, buf, sourcePos, line, Scr_GetLineInfo_original);
#else
			return codsrc::Scr_GetLineInfo(col, buf, sourcePos, line);
#endif
		}

		// unsigned int __usercall Scr_GetLineInfo@<eax>(int *col@<edx>, _BYTE *buf@<ecx>, unsigned int sourcePos, char *line)
		NAKED unsigned int Scr_GetLineInfo_stub()
		{
			_asm
			{
				push ecx;
				push edx;
				call Scr_GetLineInfo_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_PrintSourcePos_call(unsigned int sourcePos, const char * buf, game::con_channel_e channel, [[maybe_unused]] void* caller_addr, game::scriptInstance_t a4, const char * file)
		{
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			game::Scr_PrintSourcePos(sourcePos, buf, channel, a4, file, Scr_PrintSourcePos_original);
#else
			codsrc::Scr_PrintSourcePos(sourcePos, buf, channel, a4, file);
#endif
		}

		// void __usercall Scr_PrintSourcePos(unsigned int sourcePos@<edx>, const char *buf@<ecx>, con_channel_e channel@<esi>, game::scriptInstance_t a4, const char *file)
		NAKED void Scr_PrintSourcePos_stub()
		{
			_asm
			{
				push esi;
				push ecx;
				push edx;
				call Scr_PrintSourcePos_call;
				add esp, 0xC;
				ret;
			}
		}

		game::OpcodeLookup * Scr_GetPrevSourcePosOpcodeLookup_call(game::scriptInstance_t a1, const char * codePos, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			return game::Scr_GetPrevSourcePosOpcodeLookup(a1, codePos, Scr_GetPrevSourcePosOpcodeLookup_original);
#else
			return codsrc::Scr_GetPrevSourcePosOpcodeLookup(a1, codePos);
#endif
		}

		// OpcodeLookup *__usercall Scr_GetPrevSourcePosOpcodeLookup@<eax>(game::scriptInstance_t a1@<eax>, const char *codePos@<edi>)
		NAKED game::OpcodeLookup * Scr_GetPrevSourcePosOpcodeLookup_stub()
		{
			_asm
			{
				push edi;
				push eax;
				call Scr_GetPrevSourcePosOpcodeLookup_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_GetTextSourcePos_call(char * line, const char * codePos, [[maybe_unused]] void* caller_addr, game::scriptInstance_t a3)
		{
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			game::Scr_GetTextSourcePos(line, codePos, a3, Scr_GetTextSourcePos_original);
#else
			codsrc::Scr_GetTextSourcePos(line, codePos, a3);
#endif
		}

		// void __usercall Scr_GetTextSourcePos(char *line@<edx>, const char *codePos@<ecx>, game::scriptInstance_t a3)
		NAKED void Scr_GetTextSourcePos_stub()
		{
			_asm
			{
				push ecx;
				push edx;
				call Scr_GetTextSourcePos_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_PrintPrevCodePos_call(const char * codepos, [[maybe_unused]] void* caller_addr, game::scriptInstance_t scriptInstance, game::con_channel_e channel, unsigned int index)
		{
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			game::Scr_PrintPrevCodePos(codepos, scriptInstance, channel, index, Scr_PrintPrevCodePos_original);
#else
			codsrc::Scr_PrintPrevCodePos(codepos, scriptInstance, channel, index);
#endif
		}

		// void __usercall Scr_PrintPrevCodePos(const char *codepos@<eax>, game::scriptInstance_t scriptInstance, con_channel_e channel, unsigned int index)
		NAKED void Scr_PrintPrevCodePos_stub()
		{
			_asm
			{
				push eax;
				call Scr_PrintPrevCodePos_call;
				add esp, 0x4;
				ret;
			}
		}

		void CompileError_stub(game::scriptInstance_t a1, unsigned int codePos, const char * msg, ...)
		{
			char Buffer[1024];
			va_list ArgList;
			va_start(ArgList, msg);

			_vsnprintf(Buffer, 0x400u, msg, ArgList);
			va_end(ArgList);
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			CompileError_hook.invoke<void>(a1, codePos, "%s", Buffer);
#else
			codsrc::CompileError(a1, codePos, "%s", Buffer);
#endif
		}

		void CompileError2_call(const char * codePos, game::scriptInstance_t a2, [[maybe_unused]] void* caller_addr, const char * msg, ...)
		{
			char Buffer[1024];
			va_list ArgList;
			va_start(ArgList, msg);

			_vsnprintf(Buffer, 0x400u, msg, ArgList);
			va_end(ArgList);
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			game::CompileError2(codePos, a2, CompileError2_original, "%s", Buffer);
#else
			codsrc::CompileError2(codePos, a2, "%s", Buffer);
#endif
			
		}

		// void __usercall CompileError2(const char *codePos@<edi>, game::scriptInstance_t a2@<esi>, char *msg, ...)
		NAKED void CompileError2_stub()
		{
			_asm
			{
				push esi;
				push edi;
				call CompileError2_call;
				add esp, 0x8;
				ret;
			}
		}

		void RuntimeErrorInternal_call(const char * msg, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::con_channel_e channel, const char * codepos, int index)
		{
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			game::RuntimeErrorInternal(msg, inst, channel, codepos, index, RuntimeErrorInternal_original);
#else
			codsrc::RuntimeErrorInternal(msg, inst, channel, codepos, index);
#endif
		}

		// void __usercall RuntimeErrorInternal(const char *msg@<eax>, game::scriptInstance_t inst@<edi>, con_channel_e channel, const char *codepos, int index)
		NAKED void RuntimeErrorInternal_stub()
		{
			_asm
			{
				push edi;
				push eax;
				call RuntimeErrorInternal_call;
				add esp, 0x8;
				ret;
			}
		}

		void RuntimeError_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, const char * pos, int error_index, const char * err, const char * err2)
		{
#ifdef RE_CSCR_PARSER_USE_WRAPPERS
			game::RuntimeError(inst, pos, error_index, err, err2, RuntimeError_original);
#else
			codsrc::RuntimeError(inst, pos, error_index, err, err2);
#endif
		}

		// void __usercall RuntimeError(game::scriptInstance_t inst@<eax>, const char *pos, int error_index, const char *err, const char *err2)
		NAKED void RuntimeError_stub()
		{
			_asm
			{
				push eax;
				call RuntimeError_call;
				add esp, 0x4;
				ret;
			}
		}
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			Scr_InitOpcodeLookup_hook.create(game::Scr_InitOpcodeLookup_ADDR(), Scr_InitOpcodeLookup_stub);
			Scr_ShutdownOpcodeLookup_hook.create(game::Scr_ShutdownOpcodeLookup_ADDR(), Scr_ShutdownOpcodeLookup_stub);
			AddOpcodePos_hook.create(game::AddOpcodePos_ADDR(), AddOpcodePos_stub);
			RemoveOpcodePos_hook.create(game::RemoveOpcodePos_ADDR(), RemoveOpcodePos_stub);
			AddThreadStartOpcodePos_hook.create(game::AddThreadStartOpcodePos_ADDR(), AddThreadStartOpcodePos_stub);
			Scr_GetSourceBuffer_hook.create(game::Scr_GetSourceBuffer_ADDR(), Scr_GetSourceBuffer_stub);
			Scr_GetLineNumInternal_hook.create(game::Scr_GetLineNumInternal_ADDR(), Scr_GetLineNumInternal_stub);
			Scr_GetNewSourceBuffer_hook.create(game::Scr_GetNewSourceBuffer_ADDR(), Scr_GetNewSourceBuffer_stub);
			Scr_AddSourceBufferInternal_hook.create(game::Scr_AddSourceBufferInternal_ADDR(), Scr_AddSourceBufferInternal_stub);
			Scr_ReadFile_FastFile_hook.create(game::Scr_ReadFile_FastFile.get(), Scr_ReadFile_FastFile_stub);
			Scr_ReadFile_LoadObj_hook.create(game::Scr_ReadFile_LoadObj.get(), Scr_ReadFile_LoadObj_stub);
			Scr_ReadFile_hook.create(game::Scr_ReadFile_ADDR(), Scr_ReadFile_stub);
			Scr_AddSourceBuffer_hook.create(game::Scr_AddSourceBuffer_ADDR(), Scr_AddSourceBuffer_stub);
			Scr_CopyFormattedLine_hook.create(game::Scr_CopyFormattedLine_ADDR(), Scr_CopyFormattedLine_stub);
			Scr_GetLineInfo_hook.create(game::Scr_GetLineInfo_ADDR(), Scr_GetLineInfo_stub);
			Scr_PrintSourcePos_hook.create(game::Scr_PrintSourcePos_ADDR(), Scr_PrintSourcePos_stub);
			Scr_GetPrevSourcePosOpcodeLookup_hook.create(game::Scr_GetPrevSourcePosOpcodeLookup_ADDR(), Scr_GetPrevSourcePosOpcodeLookup_stub);
			Scr_GetTextSourcePos_hook.create(game::Scr_GetTextSourcePos_ADDR(), Scr_GetTextSourcePos_stub);
			Scr_PrintPrevCodePos_hook.create(game::Scr_PrintPrevCodePos_ADDR(), Scr_PrintPrevCodePos_stub);
			CompileError_hook.create(game::CompileError.get(), CompileError_stub);
			CompileError2_hook.create(game::CompileError2_ADDR(), CompileError2_stub);
			RuntimeErrorInternal_hook.create(game::RuntimeErrorInternal_ADDR(), RuntimeErrorInternal_stub);
			RuntimeError_hook.create(game::RuntimeError_ADDR(), RuntimeError_stub);

			//Original hook function addresses
			Scr_InitOpcodeLookup_original = Scr_InitOpcodeLookup_hook.get_original();
			Scr_ShutdownOpcodeLookup_original = Scr_ShutdownOpcodeLookup_hook.get_original();
			AddOpcodePos_original = AddOpcodePos_hook.get_original();
			RemoveOpcodePos_original = RemoveOpcodePos_hook.get_original();
			AddThreadStartOpcodePos_original = AddThreadStartOpcodePos_hook.get_original();
			Scr_GetSourceBuffer_original = Scr_GetSourceBuffer_hook.get_original();
			Scr_GetLineNumInternal_original = Scr_GetLineNumInternal_hook.get_original();
			Scr_GetNewSourceBuffer_original = Scr_GetNewSourceBuffer_hook.get_original();
			Scr_AddSourceBufferInternal_original = Scr_AddSourceBufferInternal_hook.get_original();
			Scr_ReadFile_FastFile_original = Scr_ReadFile_FastFile_hook.get_original();
			Scr_ReadFile_LoadObj_original = Scr_ReadFile_LoadObj_hook.get_original();
			Scr_ReadFile_original = Scr_ReadFile_hook.get_original();
			Scr_AddSourceBuffer_original = Scr_AddSourceBuffer_hook.get_original();
			Scr_CopyFormattedLine_original = Scr_CopyFormattedLine_hook.get_original();
			Scr_GetLineInfo_original = Scr_GetLineInfo_hook.get_original();
			Scr_PrintSourcePos_original = Scr_PrintSourcePos_hook.get_original();
			Scr_GetPrevSourcePosOpcodeLookup_original = Scr_GetPrevSourcePosOpcodeLookup_hook.get_original();
			Scr_GetTextSourcePos_original = Scr_GetTextSourcePos_hook.get_original();
			Scr_PrintPrevCodePos_original = Scr_PrintPrevCodePos_hook.get_original();
			CompileError_original = CompileError_hook.get_original();
			CompileError2_original = CompileError2_hook.get_original();
			RuntimeErrorInternal_original = RuntimeErrorInternal_hook.get_original();
			RuntimeError_original = RuntimeError_hook.get_original();
		}

	private:
	};
}
REGISTER_COMPONENT(re_cscr_parser::component)