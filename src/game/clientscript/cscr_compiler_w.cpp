#include <stdinc.hpp>

namespace game
{
	// void __usercall Scr_CompileRemoveRefToString(scriptInstance_t inst@<eax>, unsigned int stringVal@<edx>)
	void Scr_CompileRemoveRefToString(scriptInstance_t inst, unsigned int stringVal, void* call_addr)
	{
		__asm
		{
			mov eax, inst;
			mov edx, stringVal;
			call call_addr;
		}
	}

	// void __usercall EmitCanonicalString(scriptInstance_t inst@<ecx>, unsigned int stringVal@<eax>)
	void EmitCanonicalString(scriptInstance_t inst, unsigned int stringVal, void* call_addr)
	{
		__asm
		{
			mov ecx, inst;
			mov eax, stringVal;
			call call_addr;
		}
	}

	// void __usercall CompileTransferRefToString(unsigned int stringValue@<eax>, scriptInstance_t inst@<ecx>, unsigned int user)
	void CompileTransferRefToString(unsigned int stringValue, scriptInstance_t inst, unsigned int user, void* call_addr)
	{
		__asm
		{
			push user;
			mov eax, stringValue;
			mov ecx, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitEnd(scriptInstance_t inst@<eax>)
	void EmitEnd(scriptInstance_t inst, void* call_addr)
	{
		__asm
		{
			mov eax, inst;
			call call_addr;
		}
	}

	// void __usercall EmitReturn(scriptInstance_t inst@<eax>)
	void EmitReturn(scriptInstance_t inst, void* call_addr)
	{
		__asm
		{
			mov eax, inst;
			call call_addr;
		}
	}

	// void __usercall EmitCodepos(scriptInstance_t inst@<eax>, int codepos)
	void EmitCodepos(scriptInstance_t inst, int codepos, void* call_addr)
	{
		__asm
		{
			push codepos;
			mov eax, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitShort(scriptInstance_t inst@<eax>, int value)
	void EmitShort(scriptInstance_t inst, int value, void* call_addr)
	{
		__asm
		{
			push value;
			mov eax, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitByte(scriptInstance_t inst@<eax>, int value)
	void EmitByte(scriptInstance_t inst, int value, void* call_addr)
	{
		__asm
		{
			push value;
			mov eax, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitGetInteger(scriptInstance_t inst@<eax>, int value, sval_u sourcePos)
	void EmitGetInteger(scriptInstance_t inst, int value, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push value;
			mov eax, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitGetFloat(scriptInstance_t inst@<eax>, float value, sval_u sourcePos)
	void EmitGetFloat(scriptInstance_t inst, float value, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push value;
			mov eax, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitAnimTree(scriptInstance_t inst@<eax>, sval_u sourcePos)
	void EmitAnimTree(scriptInstance_t inst, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			mov eax, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitRemoveLocalVars(scriptInstance_t inst@<eax>, scr_block_s *outerBlock@<ecx>, scr_block_s *block)
	void EmitRemoveLocalVars(scriptInstance_t inst, scr_block_s* outerBlock, scr_block_s* block, void* call_addr)
	{
		__asm
		{
			push block;
			mov eax, inst;
			mov ecx, outerBlock;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitNOP2(scr_block_s *block@<ecx>, scriptInstance_t inst@<edi>, int lastStatement, unsigned int endSourcePos)
	void EmitNOP2(scr_block_s* block, scriptInstance_t inst, int lastStatement, unsigned int endSourcePos, void* call_addr)
	{
		__asm
		{
			push endSourcePos;
			push lastStatement;
			mov ecx, block;
			mov edi, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall Scr_AppendChildBlocks(scr_block_s *block@<edi>, scr_block_s **childBlocks, int childCount)
	void Scr_AppendChildBlocks(scr_block_s* block, scr_block_s** childBlocks, int childCount, void* call_addr)
	{
		__asm
		{
			push childCount;
			push childBlocks;
			mov edi, block;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall Scr_TransferBlock(scr_block_s *to@<esi>, scr_block_s *from)
	void Scr_TransferBlock(scr_block_s* to, scr_block_s* from, void* call_addr)
	{
		__asm
		{
			push from;
			mov esi, to;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitSafeSetVariableField(scr_block_s *block@<eax>, scriptInstance_t inst@<esi>, sval_u expr, sval_u sourcePos)
	void EmitSafeSetVariableField(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push expr;
			mov eax, block;
			mov esi, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitSafeSetWaittillVariableField(scr_block_s *block@<eax>, scriptInstance_t inst@<edi>, sval_u expr, sval_u sourcePos)
	void EmitSafeSetWaittillVariableField(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push expr;
			mov eax, block;
			mov edi, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitGetString(unsigned int value@<edi>, scriptInstance_t inst@<esi>, sval_u sourcePos)
	void EmitGetString(unsigned int value, scriptInstance_t inst, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			mov edi, value;
			mov esi, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitGetIString(unsigned int value@<edi>, scriptInstance_t inst@<esi>, sval_u sourcePos)
	void EmitGetIString(unsigned int value, scriptInstance_t inst, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			mov edi, value;
			mov esi, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitGetVector(const float *value@<eax>, scriptInstance_t inst, sval_u sourcePos)
	void EmitGetVector(const float* value, scriptInstance_t inst, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push inst;
			mov eax, value;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall Scr_PushValue(scriptInstance_t inst@<eax>, VariableCompileValue *constValue@<esi>)
	void Scr_PushValue(scriptInstance_t inst, VariableCompileValue* constValue, void* call_addr)
	{
		__asm
		{
			mov eax, inst;
			mov esi, constValue;
			call call_addr;
		}
	}

	// void __usercall EmitCastBool(scriptInstance_t inst@<edi>, sval_u sourcePos)
	void EmitCastBool(scriptInstance_t inst, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			mov edi, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitBoolNot(scriptInstance_t inst@<edi>, sval_u sourcePos)
	void EmitBoolNot(scriptInstance_t inst, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			mov edi, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitBoolComplement(scriptInstance_t inst@<edi>, sval_u sourcePos)
	void EmitBoolComplement(scriptInstance_t inst, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			mov edi, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitSize(scr_block_s *block@<eax>, scriptInstance_t inst@<edi>, sval_u expr, sval_u sourcePos)
	void EmitSize(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push expr;
			mov eax, block;
			mov edi, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitSelf(scriptInstance_t inst@<edi>, sval_u sourcePos)
	void EmitSelf(scriptInstance_t inst, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			mov edi, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitLevel(scriptInstance_t inst@<edi>, sval_u sourcePos)
	void EmitLevel(scriptInstance_t inst, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			mov edi, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitGame(scriptInstance_t inst@<edi>, sval_u sourcePos)
	void EmitGame(scriptInstance_t inst, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			mov edi, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitAnim(scriptInstance_t inst@<edi>, sval_u sourcePos)
	void EmitAnim(scriptInstance_t inst, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			mov edi, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitSelfObject(scriptInstance_t inst@<edi>, sval_u sourcePos)
	void EmitSelfObject(scriptInstance_t inst, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			mov edi, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitLevelObject(scriptInstance_t inst@<edi>, sval_u sourcePos)
	void EmitLevelObject(scriptInstance_t inst, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			mov edi, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitAnimObject(scriptInstance_t inst@<edi>, sval_u sourcePos)
	void EmitAnimObject(scriptInstance_t inst, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			mov edi, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitLocalVariable(scr_block_s *block@<eax>, scriptInstance_t inst@<esi>, sval_u expr, sval_u sourcePos)
	void EmitLocalVariable(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push expr;
			mov eax, block;
			mov esi, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitLocalVariableRef(scr_block_s *block@<eax>, scriptInstance_t inst@<esi>, sval_u expr, sval_u sourcePos)
	void EmitLocalVariableRef(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push expr;
			mov eax, block;
			mov esi, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitGameRef(scriptInstance_t inst@<edi>, sval_u sourcePos)
	void EmitGameRef(scriptInstance_t inst, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			mov edi, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitClearArray(scriptInstance_t inst@<edi>, sval_u sourcePos, sval_u indexSourcePos)
	void EmitClearArray(scriptInstance_t inst, sval_u sourcePos, sval_u indexSourcePos, void* call_addr)
	{
		__asm
		{
			push indexSourcePos;
			push sourcePos;
			mov edi, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitEmptyArray(scriptInstance_t inst@<edi>, sval_u sourcePos)
	void EmitEmptyArray(scriptInstance_t inst, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			mov edi, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitAnimation(scriptInstance_t inst@<eax>, sval_u anim, sval_u sourcePos)
	void EmitAnimation(scriptInstance_t inst, sval_u anim, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push anim;
			mov eax, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitFieldVariable(scr_block_s *block@<eax>, scriptInstance_t inst@<esi>, sval_u expr, sval_u field, sval_u sourcePos)
	void EmitFieldVariable(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u field, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push field;
			push expr;
			mov eax, block;
			mov esi, inst;
			call call_addr;
			add esp, 0xC;
		}
	}

	// void __usercall EmitClearFieldVariable(scr_block_s *block@<eax>, scriptInstance_t inst@<esi>, sval_u expr, sval_u field, sval_u sourcePos)
	void EmitClearFieldVariable(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u field, sval_u sourcePos, sval_u rhsSourcePos, void* call_addr)
	{
		__asm
		{
			push rhsSourcePos;
			push sourcePos;
			push field;
			push expr;
			mov eax, block;
			mov esi, inst;
			call call_addr;
			add esp, 0x10;
		}
	}

	// void __usercall EmitObject(scriptInstance_t inst@<edi>, sval_u expr, sval_u sourcePos)
	void EmitObject(scriptInstance_t inst, sval_u expr, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push expr;
			mov edi, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitDecTop(scriptInstance_t inst@<eax>)
	void EmitDecTop(scriptInstance_t inst, void* call_addr)
	{
		__asm
		{
			mov eax, inst;
			call call_addr;
		}
	}

	// void __usercall EmitArrayVariable(scr_block_s *block@<edi>, scriptInstance_t inst@<esi>, sval_u expr, sval_u index, sval_u sourcePos, sval_u indexSourcePos)
	void EmitArrayVariable(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u index, sval_u sourcePos, sval_u indexSourcePos, void* call_addr)
	{
		__asm
		{
			push indexSourcePos;
			push sourcePos;
			push index;
			push expr;
			mov edi, block;
			mov esi, inst;
			call call_addr;
			add esp, 0x10;
		}
	}

	// void __usercall EmitArrayVariableRef(scr_block_s *block@<eax>, scriptInstance_t inst@<esi>, sval_u expr, sval_u index, sval_u sourcePos, sval_u indexSourcePos)
	void EmitArrayVariableRef(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u index, sval_u sourcePos, sval_u indexSourcePos, void* call_addr)
	{
		__asm
		{
			push indexSourcePos;
			push sourcePos;
			push index;
			push expr;
			mov eax, block;
			mov esi, inst;
			call call_addr;
			add esp, 0x10;
		}
	}

	// void __usercall EmitClearArrayVariable(scr_block_s *block@<eax>, scriptInstance_t inst@<ecx>, sval_u expr, sval_u index, sval_u sourcePos, sval_u indexSourcePos)
	void EmitClearArrayVariable(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u index, sval_u sourcePos, sval_u indexSourcePos, void* call_addr)
	{
		__asm
		{
			push indexSourcePos;
			push sourcePos;
			push index;
			push expr;
			mov eax, block;
			mov ecx, inst;
			call call_addr;
			add esp, 0x10;
		}
	}

	// void __usercall AddExpressionListOpcodePos(scriptInstance_t inst@<edi>, sval_u exprlist)
	void AddExpressionListOpcodePos(scriptInstance_t inst, sval_u exprlist, void* call_addr)
	{
		__asm
		{
			push exprlist;
			mov edi, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall AddFilePrecache(scriptInstance_t inst@<eax>, unsigned int filename, unsigned int sourcePos, bool include, unsigned int *filePosId, unsigned int *fileCountId)
	void AddFilePrecache(scriptInstance_t inst, unsigned int filename, unsigned int sourcePos, int include, unsigned int* filePosId, unsigned int* fileCountId, void* call_addr)
	{
		__asm
		{
			push fileCountId;
			push filePosId;
			push include;
			push sourcePos;
			push filename;
			mov eax, inst;
			call call_addr;
			add esp, 0x14;
		}
	}

	// void __usercall EmitFunction(scriptInstance_t inst@<eax>, sval_u func, sval_u sourcePos)
	void EmitFunction(scriptInstance_t inst, sval_u func, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push func;
			mov eax, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitGetFunction(scriptInstance_t inst@<edi>, sval_u func, sval_u sourcePos)
	void EmitGetFunction(scriptInstance_t inst, sval_u func, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push func;
			mov edi, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitPostScriptFunctionPointer(scr_block_s *block@<eax>, scriptInstance_t inst@<edi>, sval_u expr, int param_count, int bMethod, sval_u nameSourcePos, sval_u sourcePos)
	void EmitPostScriptFunctionPointer(scr_block_s* block, scriptInstance_t inst, sval_u expr, int param_count, int bMethod, sval_u nameSourcePos, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push nameSourcePos;
			push bMethod;
			push param_count;
			push expr;
			mov eax, block;
			mov edi, inst;
			call call_addr;
			add esp, 0x14;
		}
	}

	// void __usercall EmitPostScriptThread(scriptInstance_t inst@<edi>, sval_u func, int param_count, int bMethod, sval_u sourcePos)
	void EmitPostScriptThread(scriptInstance_t inst, sval_u func, int param_count, int bMethod, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push bMethod;
			push param_count;
			push func;
			mov edi, inst;
			call call_addr;
			add esp, 0x10;
		}
	}

	// void __usercall EmitPostScriptThreadPointer(scr_block_s *block@<eax>, scriptInstance_t inst@<edi>, sval_u expr, int param_count, int bMethod, sval_u sourcePos)
	void EmitPostScriptThreadPointer(scr_block_s* block, scriptInstance_t inst, sval_u expr, int param_count, int bMethod, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push bMethod;
			push param_count;
			push expr;
			mov eax, block;
			mov edi, inst;
			call call_addr;
			add esp, 0x10;
		}
	}

	// void __usercall EmitPostScriptFunctionCall(scriptInstance_t inst@<eax>, char bMethod@<dl>, int param_count@<esi>, sval_u func_name, sval_u nameSourcePos, scr_block_s *block)
	void EmitPostScriptFunctionCall(scriptInstance_t inst, int bMethod, int param_count, sval_u func_name, sval_u nameSourcePos, scr_block_s* block, void* call_addr)
	{
		__asm
		{
			push block;
			push nameSourcePos;
			push func_name;
			mov eax, inst;
			mov edx, bMethod;
			mov esi, param_count;
			call call_addr;
			add esp, 0xC;
		}
	}

	// void __usercall EmitPostScriptThreadCall(scriptInstance_t inst@<eax>, char isMethod@<dl>, int param_count@<esi>, sval_u func_name, sval_u sourcePos, sval_u nameSourcePos, scr_block_s *block)
	void EmitPostScriptThreadCall(scriptInstance_t inst, int isMethod, int param_count, sval_u func_name, sval_u sourcePos, sval_u nameSourcePos, scr_block_s* block, void* call_addr)
	{
		__asm
		{
			push block;
			push nameSourcePos;
			push sourcePos;
			push func_name;
			mov eax, inst;
			mov edx, isMethod;
			mov esi, param_count;
			call call_addr;
			add esp, 0x10;
		}
	}

	// void __usercall EmitPreFunctionCall(scriptInstance_t inst@<eax>)
	void EmitPreFunctionCall(scriptInstance_t inst, void* call_addr)
	{
		__asm
		{
			mov eax, inst;
			call call_addr;
		}
	}

	// void __usercall EmitPostFunctionCall(scriptInstance_t inst@<eax>, char bMethod@<dl>, sval_u func_name, int param_count, scr_block_s *block)
	void EmitPostFunctionCall(scriptInstance_t inst, int bMethod, sval_u func_name, int param_count, scr_block_s* block, void* call_addr)
	{
		__asm
		{
			push block;
			push param_count;
			push func_name;
			mov eax, inst;
			mov edx, bMethod;
			call call_addr;
			add esp, 0xC;
		}
	}

	// void __usercall Scr_BeginDevScript(scriptInstance_t isnt@<eax>, int *type@<edi>, char **savedPos)
	void Scr_BeginDevScript(scriptInstance_t isnt, int* type_, char** savedPos, void* call_addr)
	{
		__asm
		{
			push savedPos;
			mov eax, isnt;
			mov edi, type_;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall Scr_EndDevScript(scriptInstance_t inst@<eax>, char **savedPos@<edx>)
	void Scr_EndDevScript(scriptInstance_t inst, char** savedPos, void* call_addr)
	{
		__asm
		{
			mov eax, inst;
			mov edx, savedPos;
			call call_addr;
		}
	}

	// void __usercall EmitCallBuiltinOpcode(scriptInstance_t inst@<eax>, int param_count, sval_u sourcePos)
	void EmitCallBuiltinOpcode(scriptInstance_t inst, int param_count, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push param_count;
			mov eax, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitCallBuiltinMethodOpcode(int inst@<eax>, int param_count, sval_u sourcePos)
	void EmitCallBuiltinMethodOpcode(scriptInstance_t inst, int param_count, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push param_count;
			mov eax, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitCall(scriptInstance_t inst@<eax>, sval_u func_name, sval_u params, int bStatement, scr_block_s *block)
	void EmitCall(scriptInstance_t inst, sval_u func_name, sval_u params, int bStatement, scr_block_s* block, void* call_addr)
	{
		__asm
		{
			push block;
			push bStatement;
			push params;
			push func_name;
			mov eax, inst;
			call call_addr;
			add esp, 0x10;
		}
	}

	// void __usercall LinkThread(scriptInstance_t inst@<ecx>, unsigned int threadCountId@<eax>, VariableValue *pos, int allowFarCall)
	void LinkThread(scriptInstance_t inst, unsigned int threadCountId, VariableValue* pos, int allowFarCall, void* call_addr)
	{
		__asm
		{
			push allowFarCall;
			push pos;
			mov ecx, inst;
			mov eax, threadCountId;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall LinkFile(scriptInstance_t inst@<eax>, unsigned int filePosId, unsigned int fileCountId)
	void LinkFile(scriptInstance_t inst, unsigned int filePosId, unsigned int fileCountId, void* call_addr)
	{
		__asm
		{
			push fileCountId;
			push filePosId;
			mov eax, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitCallExpression(scriptInstance_t inst@<eax>, scr_block_s *block@<esi>, sval_u expr, int bStatement)
	void EmitCallExpression(scriptInstance_t inst, scr_block_s* block, sval_u expr, int bStatement, void* call_addr)
	{
		__asm
		{
			push bStatement;
			push expr;
			mov eax, inst;
			mov esi, block;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitCallExpressionFieldObject(scr_block_s *block@<ecx>, scriptInstance_t inst@<edi>, sval_u expr)
	void EmitCallExpressionFieldObject(scr_block_s* block, scriptInstance_t inst, sval_u expr, void* call_addr)
	{
		__asm
		{
			push expr;
			mov ecx, block;
			mov edi, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall Scr_CreateVector(scriptInstance_t inst@<eax>, VariableCompileValue *constValue, VariableValue *value)
	void Scr_CreateVector(scriptInstance_t inst, VariableCompileValue* constValue, VariableValue* value, void* call_addr)
	{
		__asm
		{
			push value;
			push constValue;
			mov eax, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// bool __usercall EmitOrEvalPrimitiveExpressionList@<al>(scriptInstance_t inst@<eax>, sval_u exprlist, sval_u sourcePos, VariableCompileValue *constValue, scr_block_s *a5)
	bool EmitOrEvalPrimitiveExpressionList(scriptInstance_t inst, sval_u exprlist, sval_u sourcePos, VariableCompileValue* constValue, scr_block_s* a5, void* call_addr)
	{
		bool answer;

		__asm
		{
			push a5;
			push constValue;
			push sourcePos;
			push exprlist;
			mov eax, inst;
			call call_addr;
			mov answer, al;
			add esp, 0x10;
		}

		return answer;
	}

	// void __usercall EmitExpressionListFieldObject(scriptInstance_t inst@<edx>, sval_u exprlist, sval_u sourcePos, scr_block_s *block)
	void EmitExpressionListFieldObject(scriptInstance_t inst, sval_u exprlist, sval_u sourcePos, scr_block_s* block, void* call_addr)
	{
		__asm
		{
			push block;
			push sourcePos;
			push exprlist;
			mov edx, inst;
			call call_addr;
			add esp, 0xC;
		}
	}

	// void __usercall EmitBoolOrExpression(scriptInstance_t inst@<eax>, sval_u expr1, sval_u expr2, sval_u expr1sourcePos, sval_u expr2sourcePos, scr_block_s *block)
	void EmitBoolOrExpression(scriptInstance_t inst, sval_u expr1, sval_u expr2, sval_u expr1sourcePos, sval_u expr2sourcePos, scr_block_s* block, void* call_addr)
	{
		__asm
		{
			push block;
			push expr2sourcePos;
			push expr1sourcePos;
			push expr2;
			push expr1;
			mov eax, inst;
			call call_addr;
			add esp, 0x14;
		}
	}

	// void __usercall EmitBoolAndExpression(scriptInstance_t inst@<eax>, sval_u expr1, sval_u expr2, sval_u expr1sourcePos, sval_u expr2sourcePos, scr_block_s *a6)
	void EmitBoolAndExpression(scriptInstance_t inst, sval_u expr1, sval_u expr2, sval_u expr1sourcePos, sval_u expr2sourcePos, scr_block_s* a6, void* call_addr)
	{
		__asm
		{
			push a6;
			push expr2sourcePos;
			push expr1sourcePos;
			push expr2;
			push expr1;
			mov eax, inst;
			call call_addr;
			add esp, 0x14;
		}
	}

	// bool __usercall EmitOrEvalBinaryOperatorExpression@<al>(scriptInstance_t inst@<edi>, sval_u expr1, sval_u expr2, sval_u opcode, sval_u sourcePos, VariableCompileValue *constValue, scr_block_s *a8)
	bool EmitOrEvalBinaryOperatorExpression(scriptInstance_t inst, sval_u expr1, sval_u expr2, sval_u opcode, sval_u sourcePos, VariableCompileValue* constValue, scr_block_s* a8, void* call_addr)
	{
		bool answer;

		__asm
		{
			push a8;
			push constValue;
			push sourcePos;
			push opcode;
			push expr2;
			push expr1;
			mov edi, inst;
			call call_addr;
			mov answer, al;
			add esp, 0x18;
		}

		return answer;
	}

	// void __usercall EmitBinaryEqualsOperatorExpression(scr_block_s *block@<edi>, scriptInstance_t inst@<esi>, sval_u lhs, sval_u rhs, sval_u opcode, sval_u sourcePos)
	void EmitBinaryEqualsOperatorExpression(scr_block_s* block, scriptInstance_t inst, sval_u lhs, sval_u rhs, sval_u opcode, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push opcode;
			push rhs;
			push lhs;
			mov edi, block;
			mov esi, inst;
			call call_addr;
			add esp, 0x10;
		}
	}

	// void __usercall Scr_CalcLocalVarsVariableExpressionRef(scr_block_s *block@<edx>, sval_u expr)
	void Scr_CalcLocalVarsVariableExpressionRef(scr_block_s* block, sval_u expr, void* call_addr)
	{
		__asm
		{
			push expr;
			mov edx, block;
			call call_addr;
			add esp, 0x4;
		}
	}

	// bool __usercall EvalExpression@<al>(VariableCompileValue *constValue@<edx>, scriptInstance_t inst@<esi>, sval_u expr)
	bool EvalExpression(VariableCompileValue* constValue, scriptInstance_t inst, sval_u expr, void* call_addr)
	{
		bool answer;

		__asm
		{
			push expr;
			mov edx, constValue;
			mov esi, inst;
			call call_addr;
			mov answer, al;
			add esp, 0x4;
		}

		return answer;
	}

	// void __usercall EmitArrayPrimitiveExpressionRef(scriptInstance_t inst@<eax>, sval_u expr, sval_u sourcePos, scr_block_s *block)
	void EmitArrayPrimitiveExpressionRef(scriptInstance_t inst, sval_u expr, sval_u sourcePos, scr_block_s* block, void* call_addr)
	{
		__asm
		{
			push block;
			push sourcePos;
			push expr;
			mov eax, inst;
			call call_addr;
			add esp, 0xC;
		}
	}

	// void __usercall ConnectBreakStatements(scriptInstance_t inst@<eax>)
	void ConnectBreakStatements(scriptInstance_t inst, void* call_addr)
	{
		__asm
		{
			mov eax, inst;
			call call_addr;
		}
	}

	// void __usercall ConnectContinueStatements(scriptInstance_t inst@<eax>)
	void ConnectContinueStatements(scriptInstance_t inst, void* call_addr)
	{
		__asm
		{
			mov eax, inst;
			call call_addr;
		}
	}

	// bool __usercall EmitClearVariableExpression@<al>(scr_block_s *block@<eax>, scriptInstance_t inst@<ecx>, sval_u expr, sval_u rhsSourcePos)
	bool EmitClearVariableExpression(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u rhsSourcePos, void* call_addr)
	{
		bool answer;

		__asm
		{
			push rhsSourcePos;
			push expr;
			mov eax, block;
			mov ecx, inst;
			call call_addr;
			mov answer, al;
			add esp, 0x8;
		}

		return answer;
	}

	// void __usercall EmitAssignmentStatement(scriptInstance_t inst@<esi>, sval_u lhs, sval_u rhs, sval_u sourcePos, sval_u rhsSourcePos, scr_block_s *block)
	void EmitAssignmentStatement(scriptInstance_t inst, sval_u lhs, sval_u rhs, sval_u sourcePos, sval_u rhsSourcePos, scr_block_s* block, void* call_addr)
	{
		__asm
		{
			push block;
			push rhsSourcePos;
			push sourcePos;
			push rhs;
			push lhs;
			mov esi, inst;
			call call_addr;
			add esp, 0x14;
		}
	}

	// void __usercall EmitCallExpressionStatement(scriptInstance_t inst@<eax>, scr_block_s *block@<esi>, sval_u expr)
	void EmitCallExpressionStatement(scriptInstance_t inst, scr_block_s* block, sval_u expr, void* call_addr)
	{
		__asm
		{
			push expr;
			mov eax, inst;
			mov esi, block;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitReturnStatement(scr_block_s *block@<eax>, scriptInstance_t inst@<esi>, sval_u expr, sval_u sourcePos)
	void EmitReturnStatement(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push expr;
			mov eax, block;
			mov esi, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitWaitStatement(scr_block_s *block@<eax>, scriptInstance_t inst@<edi>, sval_u expr, sval_u sourcePos, sval_u waitSourcePos)
	void EmitWaitStatement(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u sourcePos, sval_u waitSourcePos, void* call_addr)
	{
		__asm
		{
			push waitSourcePos;
			push sourcePos;
			push expr;
			mov eax, block;
			mov edi, inst;
			call call_addr;
			add esp, 0xC;
		}
	}

	// void __usercall EmitWaittillFrameEnd(scriptInstance_t inst@<edi>, sval_u sourcePos)
	void EmitWaittillFrameEnd(scriptInstance_t inst, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			mov edi, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitIfStatement(scriptInstance_t inst@<eax>, sval_u expr, sval_u stmt, sval_u sourcePos, int lastStatement, unsigned int endSourcePos, scr_block_s *block, sval_u *ifStatBlock)
	void EmitIfStatement(scriptInstance_t inst, sval_u expr, sval_u stmt, sval_u sourcePos, int lastStatement, unsigned int endSourcePos, scr_block_s* block, sval_u* ifStatBlock, void* call_addr)
	{
		__asm
		{
			push ifStatBlock;
			push block;
			push endSourcePos;
			push lastStatement;
			push sourcePos;
			push stmt;
			push expr;
			mov eax, inst;
			call call_addr;
			add esp, 0x1C;
		}
	}

	// void __usercall Scr_AddBreakBlock(scriptInstance_t inst@<eax>, scr_block_s *block@<edi>)
	void Scr_AddBreakBlock(scriptInstance_t inst, scr_block_s* block, void* call_addr)
	{
		__asm
		{
			mov eax, inst;
			mov edi, block;
			call call_addr;
		}
	}

	// void __usercall Scr_AddContinueBlock(scriptInstance_t inst@<eax>, scr_block_s *block@<edi>)
	void Scr_AddContinueBlock(scriptInstance_t inst, scr_block_s* block, void* call_addr)
	{
		__asm
		{
			mov eax, inst;
			mov edi, block;
			call call_addr;
		}
	}

	// void __usercall EmitIncStatement(scr_block_s *block@<eax>, scriptInstance_t inst@<edi>, sval_u expr, sval_u sourcePos)
	void EmitIncStatement(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push expr;
			mov eax, block;
			mov edi, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitDecStatement(scr_block_s *block@<eax>, scriptInstance_t inst@<edi>, sval_u expr, sval_u sourcePos)
	void EmitDecStatement(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push expr;
			mov eax, block;
			mov edi, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall Scr_CalcLocalVarsFormalParameterListInternal(sval_u *node@<eax>, scr_block_s *block@<esi>)
	void Scr_CalcLocalVarsFormalParameterListInternal(sval_u* node, scr_block_s* block, void* call_addr)
	{
		__asm
		{
			mov eax, node;
			mov esi, block;
			call call_addr;
		}
	}

	// void __usercall EmitWaittillStatement(scriptInstance_t inst@<eax>, sval_u obj, sval_u exprlist, sval_u sourcePos, sval_u waitSourcePos, scr_block_s *block)
	void EmitWaittillStatement(scriptInstance_t inst, sval_u obj, sval_u exprlist, sval_u sourcePos, sval_u waitSourcePos, scr_block_s* block, void* call_addr)
	{
		__asm
		{
			push block;
			push waitSourcePos;
			push sourcePos;
			push exprlist;
			push obj;
			mov eax, inst;
			call call_addr;
			add esp, 0x14;
		}
	}

	// void __usercall EmitWaittillmatchStatement(scriptInstance_t inst@<edi>, sval_u obj, sval_u exprlist, sval_u sourcePos, sval_u waitSourcePos, scr_block_s *block)
	void EmitWaittillmatchStatement(scriptInstance_t inst, sval_u obj, sval_u exprlist, sval_u sourcePos, sval_u waitSourcePos, scr_block_s* block, void* call_addr)
	{
		__asm
		{
			push block;
			push waitSourcePos;
			push sourcePos;
			push exprlist;
			push obj;
			mov edi, inst;
			call call_addr;
			add esp, 0x14;
		}
	}

	// void __usercall EmitNotifyStatement(scriptInstance_t inst@<edi>, sval_u obj, sval_u exprlist, sval_u sourcePos, sval_u notifySourcePos, scr_block_s *block)
	void EmitNotifyStatement(scriptInstance_t inst, sval_u obj, sval_u exprlist, sval_u sourcePos, sval_u notifySourcePos, scr_block_s* block, void* call_addr)
	{
		__asm
		{
			push block;
			push notifySourcePos;
			push sourcePos;
			push exprlist;
			push obj;
			mov edi, inst;
			call call_addr;
			add esp, 0x14;
		}
	}

	// void __usercall EmitEndOnStatement(scr_block_s *block@<eax>, scriptInstance_t inst@<edi>, sval_u obj, sval_u expr, sval_u sourcePos, sval_u exprSourcePos)
	void EmitEndOnStatement(scr_block_s* block, scriptInstance_t inst, sval_u obj, sval_u expr, sval_u sourcePos, sval_u exprSourcePos, void* call_addr)
	{
		__asm
		{
			push exprSourcePos;
			push sourcePos;
			push expr;
			push obj;
			mov eax, block;
			mov edi, inst;
			call call_addr;
			add esp, 0x10;
		}
	}

	// void __usercall EmitCaseStatement(scriptInstance_t inst@<edi>, sval_u expr, sval_u sourcePos)
	void EmitCaseStatement(scriptInstance_t inst, sval_u expr, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push expr;
			mov edi, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitCaseStatementInfo(scriptInstance_t inst@<eax>, unsigned int name, sval_u sourcePos)
	void EmitCaseStatementInfo(scriptInstance_t inst, unsigned int name, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push name;
			mov eax, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitBreakStatement(scr_block_s *block@<eax>, scriptInstance_t inst, sval_u sourcePos)
	void EmitBreakStatement(scr_block_s* block, scriptInstance_t inst, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push inst;
			mov eax, block;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitContinueStatement(scr_block_s *block@<eax>, scriptInstance_t inst, sval_u sourcePos)
	void EmitContinueStatement(scr_block_s* block, scriptInstance_t inst, sval_u sourcePos, void* call_addr)
	{
		__asm
		{
			push sourcePos;
			push inst;
			mov eax, block;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitProfStatement(scriptInstance_t inst@<eax>, sval_u profileName, sval_u sourcePos, OpcodeVM op)
	void EmitProfStatement(scriptInstance_t inst, sval_u profileName, sval_u sourcePos, OpcodeVM op, void* call_addr)
	{
		__asm
		{
			push op;
			push sourcePos;
			push profileName;
			mov eax, inst;
			call call_addr;
			add esp, 0xC;
		}
	}

	// void __usercall Scr_CalcLocalVarsStatementList(scr_block_s *block@<edi>, scriptInstance_t inst, sval_u val)
	void Scr_CalcLocalVarsStatementList(scr_block_s* block, scriptInstance_t inst, sval_u val, void* call_addr)
	{
		__asm
		{
			push val;
			push inst;
			mov edi, block;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitFormalParameterList(scriptInstance_t inst@<eax>, sval_u exprlist, sval_u sourcePos, scr_block_s *block)
	void EmitFormalParameterList(scriptInstance_t inst, sval_u exprlist, sval_u sourcePos, scr_block_s* block, void* call_addr)
	{
		__asm
		{
			push block;
			push sourcePos;
			push exprlist;
			mov eax, inst;
			call call_addr;
			add esp, 0xC;
		}
	}

	// void __usercall SpecifyThread(scriptInstance_t inst@<eax>, sval_u val)
	void SpecifyThread(scriptInstance_t inst, sval_u val, void* call_addr)
	{
		__asm
		{
			push val;
			mov eax, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitThreadInternal(scriptInstance_t inst@<esi>, sval_u val, sval_u sourcePos, sval_u endSourcePos, scr_block_s *block)
	void EmitThreadInternal(scriptInstance_t inst, sval_u val, sval_u sourcePos, sval_u endSourcePos, scr_block_s* block, void* call_addr)
	{
		__asm
		{
			push block;
			push endSourcePos;
			push sourcePos;
			push val;
			mov esi, inst;
			call call_addr;
			add esp, 0x10;
		}
	}

	// void __usercall Scr_CalcLocalVarsThread(sval_u *stmttblock@<eax>, scriptInstance_t inst, sval_u exprlist, sval_u stmtlist)
	void Scr_CalcLocalVarsThread(sval_u* stmttblock, scriptInstance_t inst, sval_u exprlist, sval_u stmtlist, void* call_addr)
	{
		__asm
		{
			push stmtlist;
			push exprlist;
			push inst;
			mov eax, stmttblock;
			call call_addr;
			add esp, 0xC;
		}
	}

	// void __usercall InitThread(int type@<ecx>, scriptInstance_t inst@<esi>)
	void InitThread(int type_, scriptInstance_t inst, void* call_addr)
	{
		__asm
		{
			mov ecx, type_;
			mov esi, inst;
			call call_addr;
		}
	}

	// void __usercall EmitNormalThread(scriptInstance_t inst@<eax>, sval_u val, sval_u *stmttblock)
	void EmitNormalThread(scriptInstance_t inst, sval_u val, sval_u* stmttblock, void* call_addr)
	{
		__asm
		{
			push stmttblock;
			push val;
			mov eax, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitDeveloperThread(scriptInstance_t inst@<eax>, sval_u val, sval_u *stmttblock)
	void EmitDeveloperThread(scriptInstance_t inst, sval_u val, sval_u* stmttblock, void* call_addr)
	{
		__asm
		{
			push stmttblock;
			push val;
			mov eax, inst;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall EmitThread(scriptInstance_t inst@<eax>, sval_u val)
	void EmitThread(scriptInstance_t inst, sval_u val, void* call_addr)
	{
		__asm
		{
			push val;
			mov eax, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall EmitInclude(scriptInstance_t inst@<eax>, sval_u val)
	void EmitInclude(scriptInstance_t inst, sval_u val, void* call_addr)
	{
		__asm
		{
			push val;
			mov eax, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall ScriptCompile(scriptInstance_t inst@<eax>, sval_u val, unsigned int filePosId, unsigned int fileCountId, unsigned int scriptId, PrecacheEntry *entries, int entriesCount)
	void ScriptCompile(scriptInstance_t inst, sval_u val, unsigned int filePosId, unsigned int fileCountId, unsigned int scriptId, PrecacheEntry* entries, int entriesCount, void* call_addr)
	{
		__asm
		{
			push entriesCount;
			push entries;
			push scriptId;
			push fileCountId;
			push filePosId;
			push val;
			mov eax, inst;
			call call_addr;
			add esp, 0x18;
		}
	}

	void EmitFloat(scriptInstance_t inst, float value)
	{
		game::gScrCompileGlob[inst].codePos = game::TempMalloc(4);
		*(float*)game::gScrCompileGlob[inst].codePos = value;
	}

	void EmitCanonicalStringConst(scriptInstance_t inst, unsigned int stringValue)
	{
		bool bConstRefCount;

		bConstRefCount = game::gScrCompileGlob[inst].bConstRefCount;
		game::gScrCompileGlob[inst].bConstRefCount = 1;
		game::EmitCanonicalString(inst, stringValue);
		game::gScrCompileGlob[inst].bConstRefCount = bConstRefCount;
	}

	int Scr_FindLocalVar(scr_block_s* block, int startIndex, unsigned int name)
	{
		while (startIndex < block->localVarsCount)
		{
			if (block->localVars[startIndex].name == name)
			{
				return startIndex;
			}

			++startIndex;
		}

		return -1;
	}

	void Scr_CheckLocalVarsCount(int localVarsCount)
	{
		if (localVarsCount >= 64)
		{
			game::Com_Error(game::ERR_DROP, "LOCAL_game::VAR_STACK_SIZE exceeded");
		}
	}

	void EmitGetUndefined(scriptInstance_t inst, sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_GetUndefined, 1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
	}

	void EmitPrimitiveExpression(scriptInstance_t inst, sval_u expr, scr_block_s* block)
	{
		game::VariableCompileValue constValue;

		if (game::EmitOrEvalPrimitiveExpression(inst, expr, &constValue, block))
		{
			game::EmitValue(inst, &constValue);
		}
	}

	void Scr_EmitAnimation(scriptInstance_t inst, char* pos, unsigned int animName, unsigned int sourcePos)
	{
		if (game::gScrAnimPub[inst].animTreeNames)
		{
			game::Scr_EmitAnimationInternal(inst, pos, animName, game::gScrAnimPub[inst].animTreeNames);
		}
		else
		{
			game::CompileError(inst, sourcePos, "#using_animtree was not specified");
		}
	}

	void EmitEvalArray(scriptInstance_t inst, sval_u sourcePos, sval_u indexSourcePos)
	{
		game::EmitOpcode(inst, game::OP_EvalArray, -1, 0);
		game::AddOpcodePos(inst, indexSourcePos.stringValue, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
	}

	void EmitEvalArrayRef(scriptInstance_t inst, sval_u sourcePos, sval_u indexSourcePos)
	{
		game::EmitOpcode(inst, game::OP_EvalArrayRef, -1, 0);
		game::AddOpcodePos(inst, indexSourcePos.stringValue, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
	}

	unsigned int Scr_GetBuiltin(scriptInstance_t inst, sval_u func_name)
	{
		game::sval_u func_namea;
		game::sval_u func_nameb;

		if (func_name.node[0].type != game::ENUM_script_call)
		{
			return 0;
		}

		func_namea = func_name.node[1];
		if (func_namea.node[0].type != game::ENUM_function)
		{
			return 0;
		}

		func_nameb = func_namea.node[1];
		if (func_nameb.node[0].type != game::ENUM_local_function)
		{
			return 0;
		}

		if ( /*game::gScrCompilePub[inst].developer_statement == 3 ||*/ !game::FindVariable(func_nameb.node[1].stringValue, game::gScrCompileGlob[inst].filePosId, inst))
		{
			return func_nameb.node[1].stringValue;
		}

		return 0;
	}

	int Scr_GetUncacheType(int type)
	{
		if (type == game::VAR_CODEPOS)
		{
			return 0;
		}

		assert(type == game::VAR_DEVELOPER_CODEPOS);
		return 1;
	}

	int Scr_GetCacheType(int type)
	{
		if (!type)
		{
			return game::VAR_CODEPOS;
		}

		assert(type == 1);  // BUILTIN_DEVELOPER_ONLY

		return game::VAR_DEVELOPER_CODEPOS;
	}

	BuiltinFunction Scr_GetFunction(const char** pName, int* type)
	{
		game::BuiltinFunction answer;

		answer = game::Sentient_GetFunction(pName);

		if (answer)
		{
			return answer;
		}

		return game::BuiltIn_GetFunction(pName, type);
	}

	BuiltinFunction GetFunction(scriptInstance_t inst, const char** pName, int* type)
	{
		if (inst)
		{
			return game::CScr_GetFunction(pName, type);
		}

		return game::Scr_GetFunction(pName, type);
	}

	BuiltinMethod GetMethod(scriptInstance_t inst, const char** pName, int* type)
	{
		if (inst)
		{
			return game::CScr_GetMethod(pName, type);
		}

		return game::Scr_GetMethod(type, pName);
	}

	unsigned int GetVariableName(scriptInstance_t inst, unsigned int id)
	{
		game::VariableValueInternal* entryValue;

		entryValue = &game::gScrVarGlob[inst].childVariables[id];

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);
		assert(!IsObject(entryValue));

		return entryValue->w.status >> 8;
	}

	int GetExpressionCount(sval_u exprlist)
	{
		game::sval_u* node;
		int expr_count;

		expr_count = 0;
		for (node = exprlist.node->node;
			node;
			node = node[1].node)
		{
			++expr_count;
		}

		return expr_count;
	}

	sval_u* GetSingleParameter(sval_u exprlist)
	{
		if (!exprlist.node->node)
		{
			return 0;
		}

		if (exprlist.node->node[1].node)
		{
			return 0;
		}

		return exprlist.node->node;
	}

	void EmitExpressionFieldObject(scriptInstance_t inst, sval_u expr, sval_u sourcePos, scr_block_s* block)
	{
		if (expr.node[0].type == game::ENUM_primitive_expression)
		{
			game::EmitPrimitiveExpressionFieldObject(inst, expr.node[1], expr.node[2], block);
		}
		else
		{
			game::CompileError(inst, sourcePos.stringValue, "not an object");
		}
	}

	void EvalInteger(int value, sval_u sourcePos, VariableCompileValue* constValue)
	{
		assert(constValue);

		constValue->value.type = game::VAR_INTEGER;
		constValue->value.u.intValue = value;
		constValue->sourcePos = sourcePos;
	}

	void EvalFloat(float value, sval_u sourcePos, VariableCompileValue* constValue)
	{
		assert(constValue);

		constValue->value.type = game::VAR_FLOAT;
		constValue->value.u.floatValue = value;
		constValue->sourcePos = sourcePos;
	}

	void EvalString(unsigned int value, sval_u sourcePos, VariableCompileValue* constValue)
	{
		assert(constValue);

		constValue->value.type = game::VAR_STRING;
		constValue->value.u.stringValue = value;
		constValue->sourcePos = sourcePos;
	}

	void EvalIString(unsigned int value, sval_u sourcePos, VariableCompileValue* constValue)
	{
		assert(constValue);

		constValue->value.type = game::VAR_ISTRING;
		constValue->value.u.stringValue = value;
		constValue->sourcePos = sourcePos;
	}

	void EvalUndefined(sval_u sourcePos, VariableCompileValue* constValue)
	{
		assert(constValue);

		constValue->value.type = game::VAR_UNDEFINED;
		constValue->sourcePos = sourcePos;
	}

	void Scr_PopValue(scriptInstance_t inst)
	{
		assert(game::gScrCompilePub[inst].value_count);
		--game::gScrCompilePub[inst].value_count;
	}

	void EmitSetVariableField(scriptInstance_t inst, sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_SetVariableField, -1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
		// game::EmitAssignmentPos(inst);
	}

	void EmitFieldVariableRef(scriptInstance_t inst, sval_u expr, sval_u field, sval_u sourcePos, scr_block_s* block)
	{
		game::EmitPrimitiveExpressionFieldObject(inst, expr, sourcePos, block);
		game::EmitOpcode(inst, game::OP_EvalFieldVariableRef, 0, 0);
		game::EmitCanonicalString(inst, field.stringValue);
	}

	void Scr_CalcLocalVarsArrayPrimitiveExpressionRef(sval_u expr, scr_block_s* block)
	{
		if (expr.node[0].type == game::ENUM_variable)
		{
			game::Scr_CalcLocalVarsVariableExpressionRef(block, expr.node[1]);
		}
	}

	BOOL IsUndefinedPrimitiveExpression(sval_u expr)
	{
		return expr.node[0].type == game::ENUM_undefined;
	}

	bool IsUndefinedExpression(sval_u expr)
	{
		if (expr.node[0].type == game::ENUM_primitive_expression)
		{
			return game::IsUndefinedPrimitiveExpression(expr.node[1]);
		}

		return 0;
	}

	void Scr_CopyBlock(scr_block_s* from, scr_block_s** to)
	{
		if (!*to)
		{
			*to = (game::scr_block_s*)game::Hunk_AllocateTempMemoryHigh(sizeof(game::scr_block_s));
		}

		memcpy(*to, from, sizeof(game::scr_block_s));
		(*to)->localVarsPublicCount = 0;
	}

	void Scr_CheckMaxSwitchCases(int count)
	{
		if (count >= 512)
		{
			game::Com_Error(game::ERR_DROP, "MAX_SWITCH_CASES exceeded");
		}
	}

	void Scr_CalcLocalVarsSafeSetVariableField(sval_u expr, sval_u sourcePos, scr_block_s* block)
	{
		game::Scr_RegisterLocalVar(expr.stringValue, sourcePos, block);
	}

	void EmitFormalWaittillParameterListRefInternal(scriptInstance_t inst, sval_u* node, scr_block_s* block)
	{
		while (1)
		{
			node = node[1].node;
			if (!node)
			{
				break;
			}

			game::EmitSafeSetWaittillVariableField(block, inst, *node->node, node->node[1]);
		}
	}

	void EmitDefaultStatement(scriptInstance_t inst, sval_u sourcePos)
	{
		game::EmitCaseStatementInfo(inst, 0, sourcePos);
	}

	char Scr_IsLastStatement(scriptInstance_t inst, sval_u* node)
	{
		if (!node)
		{
			return 1;
		}

		if (game::gScrVarPub[inst].developer_script)
		{
			return 0;
		}

		while (node)
		{
			if (node->node[0].type != game::ENUM_developer_statement_list)
			{
				return 0;
			}

			node = node[1].node;
		}

		return 1;
	}

	void EmitEndStatement(scriptInstance_t inst, sval_u sourcePos, scr_block_s* block)
	{
		if (!block->abortLevel)
		{
			block->abortLevel = 3;
		}

		game::EmitEnd(inst);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
	}

	void EmitProfBeginStatement(scriptInstance_t inst, sval_u profileName, sval_u sourcePos)
	{
		game::EmitProfStatement(inst, profileName, sourcePos, game::OP_prof_begin);
	}

	void EmitProfEndStatement(scriptInstance_t inst, sval_u profileName, sval_u sourcePos)
	{
		game::EmitProfStatement(inst, profileName, sourcePos, game::OP_prof_end);
	}

	void Scr_CalcLocalVarsIncStatement(sval_u expr, scr_block_s* block)
	{
		game::Scr_CalcLocalVarsVariableExpressionRef(block, expr);
	}

	void Scr_CalcLocalVarsWaittillStatement(sval_u exprlist, scr_block_s* block)
	{
		game::sval_u* node;

		node = exprlist.node->node[1].node;
		assert(node);
		game::Scr_CalcLocalVarsFormalParameterListInternal(node, block);
	}

	void EmitFormalParameterListInternal(scriptInstance_t inst, sval_u* node, scr_block_s* block)
	{
		while (1)
		{
			node = node[1].node;
			if (!node)
			{
				break;
			}

			game::EmitSafeSetVariableField(block, inst, *node->node, node->node[1]);
		}
	}

	unsigned int SpecifyThreadPosition(scriptInstance_t inst, unsigned int posId, unsigned int name, unsigned int sourcePos, int type)
	{
		game::VariableValue pos;

		game::CheckThreadPosition(inst, posId, name, sourcePos);
		pos.type = (game::VariableType)type;
		pos.u.intValue = 0;
		game::SetNewVariableValue(inst, posId, &pos);
		return posId;
	}

	void Scr_CalcLocalVarsFormalParameterList(sval_u exprlist, scr_block_s* block)
	{
		game::Scr_CalcLocalVarsFormalParameterListInternal(exprlist.node->node, block);
	}

	void SetThreadPosition(scriptInstance_t inst, unsigned int posId)
	{
		game::GetVariableValueAddress(inst, posId)->u.intValue = (unsigned int)game::TempMalloc(0);
	}

	void EmitIncludeList(scriptInstance_t inst, sval_u val)
	{
		game::sval_u* node;

		for (node = val.node->node[1].node;
			node;
			node = node[1].node)
		{
			game::EmitInclude(inst, *node);
		}
	}
}
