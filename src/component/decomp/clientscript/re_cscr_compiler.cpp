#include <stdinc.hpp>
#include "loader/component_loader.hpp"
#include "utils/hook.hpp"
#include "codsrc/clientscript/cscr_compiler.hpp"

#ifndef DISABLE_RE_CSCR_COMPILER
namespace re_cscr_compiler
{
	utils::hook::detour RemoveRefToValue_hook;
	utils::hook::detour Scr_CompileRemoveRefToString_hook;
	utils::hook::detour EmitCanonicalString_hook;
	utils::hook::detour CompileTransferRefToString_hook;
	utils::hook::detour EmitOpcode_hook;
	utils::hook::detour EmitEnd_hook;
	utils::hook::detour EmitReturn_hook;
	utils::hook::detour EmitCodepos_hook;
	utils::hook::detour EmitShort_hook;
	utils::hook::detour EmitByte_hook;
	utils::hook::detour EmitGetInteger_hook;
	utils::hook::detour EmitGetFloat_hook;
	utils::hook::detour EmitAnimTree_hook;
	utils::hook::detour Scr_FindLocalVarIndex_hook;
	utils::hook::detour EmitCreateLocalVars_hook;
	utils::hook::detour EmitRemoveLocalVars_hook;
	utils::hook::detour EmitNOP2_hook;
	utils::hook::detour Scr_InitFromChildBlocks_hook;
	utils::hook::detour Scr_AppendChildBlocks_hook;
	utils::hook::detour Scr_MergeChildBlocks_hook;
	utils::hook::detour Scr_TransferBlock_hook;
	utils::hook::detour EmitSafeSetVariableField_hook;
	utils::hook::detour EmitSafeSetWaittillVariableField_hook;
	utils::hook::detour EmitGetString_hook;
	utils::hook::detour EmitGetIString_hook;
	utils::hook::detour EmitGetVector_hook;
	utils::hook::detour EmitValue_hook;
	utils::hook::detour Scr_PushValue_hook;
	utils::hook::detour EmitCastBool_hook;
	utils::hook::detour EmitBoolNot_hook;
	utils::hook::detour EmitBoolComplement_hook;
	utils::hook::detour EmitSize_hook;
	utils::hook::detour EmitSelf_hook;
	utils::hook::detour EmitLevel_hook;
	utils::hook::detour EmitGame_hook;
	utils::hook::detour EmitAnim_hook;
	utils::hook::detour EmitSelfObject_hook;
	utils::hook::detour EmitLevelObject_hook;
	utils::hook::detour EmitAnimObject_hook;
	utils::hook::detour EmitLocalVariable_hook;
	utils::hook::detour EmitLocalVariableRef_hook;
	utils::hook::detour Scr_RegisterLocalVar_hook;
	utils::hook::detour EmitGameRef_hook;
	utils::hook::detour EmitClearArray_hook;
	utils::hook::detour EmitEmptyArray_hook;
	utils::hook::detour EmitAnimation_hook;
	utils::hook::detour EmitFieldVariable_hook;
	utils::hook::detour EmitClearFieldVariable_hook;
	utils::hook::detour EmitObject_hook;
	utils::hook::detour EmitDecTop_hook;
	utils::hook::detour EmitCastFieldObject_hook;
	utils::hook::detour EmitArrayVariable_hook;
	utils::hook::detour EmitArrayVariableRef_hook;
	utils::hook::detour EmitClearArrayVariable_hook;
	utils::hook::detour EmitVariableExpression_hook;
	utils::hook::detour EmitExpressionList_hook;
	utils::hook::detour AddExpressionListOpcodePos_hook;
	utils::hook::detour AddFilePrecache_hook;
	utils::hook::detour EmitFunction_hook;
	utils::hook::detour EmitGetFunction_hook;
	utils::hook::detour AddFunction_hook;
	utils::hook::detour EmitPostScriptFunction_hook;
	utils::hook::detour EmitPostScriptFunctionPointer_hook;
	utils::hook::detour EmitPostScriptThread_hook;
	utils::hook::detour EmitPostScriptThreadPointer_hook;
	utils::hook::detour EmitPostScriptFunctionCall_hook;
	utils::hook::detour EmitPostScriptThreadCall_hook;
	utils::hook::detour EmitPreFunctionCall_hook;
	utils::hook::detour EmitPostFunctionCall_hook;
	utils::hook::detour Scr_BeginDevScript_hook;
	utils::hook::detour Scr_EndDevScript_hook;
	utils::hook::detour EmitCallBuiltinOpcode_hook;
	utils::hook::detour EmitCallBuiltinMethodOpcode_hook;
	utils::hook::detour EmitCall_hook;
	utils::hook::detour EmitMethod_hook;
	utils::hook::detour LinkThread_hook;
	utils::hook::detour LinkFile_hook;
	utils::hook::detour CheckThreadPosition_hook;
	utils::hook::detour EmitCallExpression_hook;
	utils::hook::detour EmitCallExpressionFieldObject_hook;
	utils::hook::detour Scr_CreateVector_hook;
	utils::hook::detour EvalPrimitiveExpressionList_hook;
	utils::hook::detour EmitOrEvalPrimitiveExpressionList_hook;
	utils::hook::detour EmitExpressionListFieldObject_hook;
	utils::hook::detour EvalPrimitiveExpression_hook;
	utils::hook::detour EmitOrEvalPrimitiveExpression_hook;
	utils::hook::detour EmitBoolOrExpression_hook;
	utils::hook::detour EmitBoolAndExpression_hook;
	utils::hook::detour EvalBinaryOperatorExpression_hook;
	utils::hook::detour EmitOrEvalBinaryOperatorExpression_hook;
	utils::hook::detour EmitBinaryEqualsOperatorExpression_hook;
	utils::hook::detour Scr_CalcLocalVarsVariableExpressionRef_hook;
	utils::hook::detour EvalExpression_hook;
	utils::hook::detour EmitOrEvalExpression_hook;
	utils::hook::detour EmitExpression_hook;
	utils::hook::detour EmitVariableExpressionRef_hook;
	utils::hook::detour EmitArrayPrimitiveExpressionRef_hook;
	utils::hook::detour Scr_CalcLocalVarsArrayVariableRef_hook;
	utils::hook::detour EmitPrimitiveExpressionFieldObject_hook;
	utils::hook::detour ConnectBreakStatements_hook;
	utils::hook::detour ConnectContinueStatements_hook;
	utils::hook::detour EmitClearVariableExpression_hook;
	utils::hook::detour EmitAssignmentStatement_hook;
	utils::hook::detour EmitCallExpressionStatement_hook;
	utils::hook::detour EmitReturnStatement_hook;
	utils::hook::detour EmitWaitStatement_hook;
	utils::hook::detour EmitWaittillFrameEnd_hook;
	utils::hook::detour EmitIfStatement_hook;
	utils::hook::detour Scr_CalcLocalVarsIfStatement_hook;
	utils::hook::detour EmitIfElseStatement_hook;
	utils::hook::detour Scr_CalcLocalVarsIfElseStatement_hook;
	utils::hook::detour Scr_AddBreakBlock_hook;
	utils::hook::detour Scr_AddContinueBlock_hook;
	utils::hook::detour EmitWhileStatement_hook;
	utils::hook::detour Scr_CalcLocalVarsWhileStatement_hook;
	utils::hook::detour EmitForStatement_hook;
	utils::hook::detour Scr_CalcLocalVarsForStatement_hook;
	utils::hook::detour EmitIncStatement_hook;
	utils::hook::detour EmitDecStatement_hook;
	utils::hook::detour Scr_CalcLocalVarsFormalParameterListInternal_hook;
	utils::hook::detour EmitWaittillStatement_hook;
	utils::hook::detour EmitWaittillmatchStatement_hook;
	utils::hook::detour EmitNotifyStatement_hook;
	utils::hook::detour EmitEndOnStatement_hook;
	utils::hook::detour CompareCaseInfo_hook;
	utils::hook::detour EmitCaseStatement_hook;
	utils::hook::detour EmitSwitchStatementList_hook;
	utils::hook::detour Scr_CalcLocalVarsSwitchStatement_hook;
	utils::hook::detour EmitSwitchStatement_hook;
	utils::hook::detour EmitCaseStatementInfo_hook;
	utils::hook::detour EmitBreakStatement_hook;
	utils::hook::detour EmitContinueStatement_hook;
	utils::hook::detour EmitProfStatement_hook;
	utils::hook::detour EmitStatement_hook;
	utils::hook::detour Scr_CalcLocalVarsStatement_hook;
	utils::hook::detour EmitStatementList_hook;
	utils::hook::detour Scr_CalcLocalVarsStatementList_hook;
	utils::hook::detour Scr_CalcLocalVarsDeveloperStatementList_hook;
	utils::hook::detour EmitDeveloperStatementList_hook;
	utils::hook::detour EmitFormalParameterList_hook;
	utils::hook::detour SpecifyThread_hook;
	utils::hook::detour EmitThreadInternal_hook;
	utils::hook::detour Scr_CalcLocalVarsThread_hook;
	utils::hook::detour InitThread_hook;
	utils::hook::detour EmitNormalThread_hook;
	utils::hook::detour EmitDeveloperThread_hook;
	utils::hook::detour EmitThread_hook;
	utils::hook::detour EmitThreadList_hook;
	utils::hook::detour EmitInclude_hook;
	utils::hook::detour ScriptCompile_hook;

	void* RemoveRefToValue_original;
	void* Scr_CompileRemoveRefToString_original;
	void* EmitCanonicalString_original;
	void* CompileTransferRefToString_original;
	void* EmitOpcode_original;
	void* EmitEnd_original;
	void* EmitReturn_original;
	void* EmitCodepos_original;
	void* EmitShort_original;
	void* EmitByte_original;
	void* EmitGetInteger_original;
	void* EmitGetFloat_original;
	void* EmitAnimTree_original;
	void* Scr_FindLocalVarIndex_original;
	void* EmitCreateLocalVars_original;
	void* EmitRemoveLocalVars_original;
	void* EmitNOP2_original;
	void* Scr_InitFromChildBlocks_original;
	void* Scr_AppendChildBlocks_original;
	void* Scr_MergeChildBlocks_original;
	void* Scr_TransferBlock_original;
	void* EmitSafeSetVariableField_original;
	void* EmitSafeSetWaittillVariableField_original;
	void* EmitGetString_original;
	void* EmitGetIString_original;
	void* EmitGetVector_original;
	void* EmitValue_original;
	void* Scr_PushValue_original;
	void* EmitCastBool_original;
	void* EmitBoolNot_original;
	void* EmitBoolComplement_original;
	void* EmitSize_original;
	void* EmitSelf_original;
	void* EmitLevel_original;
	void* EmitGame_original;
	void* EmitAnim_original;
	void* EmitSelfObject_original;
	void* EmitLevelObject_original;
	void* EmitAnimObject_original;
	void* EmitLocalVariable_original;
	void* EmitLocalVariableRef_original;
	void* Scr_RegisterLocalVar_original;
	void* EmitGameRef_original;
	void* EmitClearArray_original;
	void* EmitEmptyArray_original;
	void* EmitAnimation_original;
	void* EmitFieldVariable_original;
	void* EmitClearFieldVariable_original;
	void* EmitObject_original;
	void* EmitDecTop_original;
	void* EmitCastFieldObject_original;
	void* EmitArrayVariable_original;
	void* EmitArrayVariableRef_original;
	void* EmitClearArrayVariable_original;
	void* EmitVariableExpression_original;
	void* EmitExpressionList_original;
	void* AddExpressionListOpcodePos_original;
	void* AddFilePrecache_original;
	void* EmitFunction_original;
	void* EmitGetFunction_original;
	void* AddFunction_original;
	void* EmitPostScriptFunction_original;
	void* EmitPostScriptFunctionPointer_original;
	void* EmitPostScriptThread_original;
	void* EmitPostScriptThreadPointer_original;
	void* EmitPostScriptFunctionCall_original;
	void* EmitPostScriptThreadCall_original;
	void* EmitPreFunctionCall_original;
	void* EmitPostFunctionCall_original;
	void* Scr_BeginDevScript_original;
	void* Scr_EndDevScript_original;
	void* EmitCallBuiltinOpcode_original;
	void* EmitCallBuiltinMethodOpcode_original;
	void* EmitCall_original;
	void* EmitMethod_original;
	void* LinkThread_original;
	void* LinkFile_original;
	void* CheckThreadPosition_original;
	void* EmitCallExpression_original;
	void* EmitCallExpressionFieldObject_original;
	void* Scr_CreateVector_original;
	void* EvalPrimitiveExpressionList_original;
	void* EmitOrEvalPrimitiveExpressionList_original;
	void* EmitExpressionListFieldObject_original;
	void* EvalPrimitiveExpression_original;
	void* EmitOrEvalPrimitiveExpression_original;
	void* EmitBoolOrExpression_original;
	void* EmitBoolAndExpression_original;
	void* EvalBinaryOperatorExpression_original;
	void* EmitOrEvalBinaryOperatorExpression_original;
	void* EmitBinaryEqualsOperatorExpression_original;
	void* Scr_CalcLocalVarsVariableExpressionRef_original;
	void* EvalExpression_original;
	void* EmitOrEvalExpression_original;
	void* EmitExpression_original;
	void* EmitVariableExpressionRef_original;
	void* EmitArrayPrimitiveExpressionRef_original;
	void* Scr_CalcLocalVarsArrayVariableRef_original;
	void* EmitPrimitiveExpressionFieldObject_original;
	void* ConnectBreakStatements_original;
	void* ConnectContinueStatements_original;
	void* EmitClearVariableExpression_original;
	void* EmitAssignmentStatement_original;
	void* EmitCallExpressionStatement_original;
	void* EmitReturnStatement_original;
	void* EmitWaitStatement_original;
	void* EmitWaittillFrameEnd_original;
	void* EmitIfStatement_original;
	void* Scr_CalcLocalVarsIfStatement_original;
	void* EmitIfElseStatement_original;
	void* Scr_CalcLocalVarsIfElseStatement_original;
	void* Scr_AddBreakBlock_original;
	void* Scr_AddContinueBlock_original;
	void* EmitWhileStatement_original;
	void* Scr_CalcLocalVarsWhileStatement_original;
	void* EmitForStatement_original;
	void* Scr_CalcLocalVarsForStatement_original;
	void* EmitIncStatement_original;
	void* EmitDecStatement_original;
	void* Scr_CalcLocalVarsFormalParameterListInternal_original;
	void* EmitWaittillStatement_original;
	void* EmitWaittillmatchStatement_original;
	void* EmitNotifyStatement_original;
	void* EmitEndOnStatement_original;
	void* CompareCaseInfo_original;
	void* EmitCaseStatement_original;
	void* EmitSwitchStatementList_original;
	void* Scr_CalcLocalVarsSwitchStatement_original;
	void* EmitSwitchStatement_original;
	void* EmitCaseStatementInfo_original;
	void* EmitBreakStatement_original;
	void* EmitContinueStatement_original;
	void* EmitProfStatement_original;
	void* EmitStatement_original;
	void* Scr_CalcLocalVarsStatement_original;
	void* EmitStatementList_original;
	void* Scr_CalcLocalVarsStatementList_original;
	void* Scr_CalcLocalVarsDeveloperStatementList_original;
	void* EmitDeveloperStatementList_original;
	void* EmitFormalParameterList_original;
	void* SpecifyThread_original;
	void* EmitThreadInternal_original;
	void* Scr_CalcLocalVarsThread_original;
	void* InitThread_original;
	void* EmitNormalThread_original;
	void* EmitDeveloperThread_original;
	void* EmitThread_original;
	void* EmitThreadList_original;
	void* EmitInclude_original;
	void* ScriptCompile_original;

	namespace
	{

		void RemoveRefToValue_stub(game::scriptInstance_t inst, game::VariableValue* value)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			RemoveRefToValue_hook.invoke<void>(inst, value);
#else
			codsrc::RemoveRefToValue(inst, value);
#endif
		}

		void Scr_CompileRemoveRefToString_call(game::scriptInstance_t inst, unsigned int stringVal, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::Scr_CompileRemoveRefToString(inst, stringVal, Scr_CompileRemoveRefToString_original);
#else
			codsrc::Scr_CompileRemoveRefToString(inst, stringVal);
#endif
		}

		// void __usercall Scr_CompileRemoveRefToString(game::scriptInstance_t inst@<eax>, unsigned int stringVal@<edx>)
		NAKED void Scr_CompileRemoveRefToString_stub()
		{
			_asm
			{
				push edx;
				push eax;
				call Scr_CompileRemoveRefToString_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitCanonicalString_call(game::scriptInstance_t inst, unsigned int stringVal, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitCanonicalString(inst, stringVal, EmitCanonicalString_original);
#else
			codsrc::EmitCanonicalString(inst, stringVal);
#endif
		}

		// void __usercall EmitCanonicalString(game::scriptInstance_t inst@<ecx>, unsigned int stringVal@<eax>)
		NAKED void EmitCanonicalString_stub()
		{
			_asm
			{
				push eax;
				push ecx;
				call EmitCanonicalString_call;
				add esp, 0x8;
				ret;
			}
		}

		void CompileTransferRefToString_call(unsigned int stringValue, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, unsigned int user)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::CompileTransferRefToString(stringValue, inst, user, CompileTransferRefToString_original);
#else
			codsrc::CompileTransferRefToString(stringValue, inst, user);
#endif
		}

		// void __usercall CompileTransferRefToString(unsigned int stringValue@<eax>, game::scriptInstance_t inst@<ecx>, unsigned int user)
		NAKED void CompileTransferRefToString_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call CompileTransferRefToString_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitOpcode_stub(game::scriptInstance_t inst, game::OpcodeVM op, int offset, int callType)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			EmitOpcode_hook.invoke<void>(inst, op, offset, callType);
#else
			codsrc::EmitOpcode(inst, op, offset, callType);
#endif
		}

		void EmitEnd_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitEnd(inst, EmitEnd_original);
#else
			codsrc::EmitEnd(inst);
#endif
		}

		// void __usercall EmitEnd(game::scriptInstance_t inst@<eax>)
		NAKED void EmitEnd_stub()
		{
			_asm
			{
				push eax;
				call EmitEnd_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitReturn_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitReturn(inst, EmitReturn_original);
#else
			codsrc::EmitReturn(inst);
#endif
		}

		// void __usercall EmitReturn(game::scriptInstance_t inst@<eax>)
		NAKED void EmitReturn_stub()
		{
			_asm
			{
				push eax;
				call EmitReturn_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitCodepos_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, int codepos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitCodepos(inst, codepos, EmitCodepos_original);
#else
			codsrc::EmitCodepos(inst, codepos);
#endif
		}

		// void __usercall EmitCodepos(game::scriptInstance_t inst@<eax>, int codepos)
		NAKED void EmitCodepos_stub()
		{
			_asm
			{
				push eax;
				call EmitCodepos_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitShort_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, int value)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitShort(inst, value, EmitShort_original);
#else
			codsrc::EmitShort(inst, value);
#endif
		}

		// void __usercall EmitShort(game::scriptInstance_t inst@<eax>, int value)
		NAKED void EmitShort_stub()
		{
			_asm
			{
				push eax;
				call EmitShort_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitByte_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, int value)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitByte(inst, value, EmitByte_original);
#else
			codsrc::EmitByte(inst, value);
#endif
		}

		// void __usercall EmitByte(game::scriptInstance_t inst@<eax>, int value)
		NAKED void EmitByte_stub()
		{
			_asm
			{
				push eax;
				call EmitByte_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitGetInteger_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, int value, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitGetInteger(inst, value, sourcePos, EmitGetInteger_original);
#else
			codsrc::EmitGetInteger(inst, value, sourcePos);
#endif
		}

		// void __usercall EmitGetInteger(game::scriptInstance_t inst@<eax>, int value, game::sval_u sourcePos)
		NAKED void EmitGetInteger_stub()
		{
			_asm
			{
				push eax;
				call EmitGetInteger_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitGetFloat_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, float value, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitGetFloat(inst, value, sourcePos, EmitGetFloat_original);
#else
			codsrc::EmitGetFloat(inst, value, sourcePos);
#endif
		}

		// void __usercall EmitGetFloat(game::scriptInstance_t inst@<eax>, float value, game::sval_u sourcePos)
		NAKED void EmitGetFloat_stub()
		{
			_asm
			{
				push eax;
				call EmitGetFloat_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitAnimTree_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitAnimTree(inst, sourcePos, EmitAnimTree_original);
#else
			codsrc::EmitAnimTree(inst, sourcePos);
#endif
		}

		// void __usercall EmitAnimTree(game::scriptInstance_t inst@<eax>, game::sval_u sourcePos)
		NAKED void EmitAnimTree_stub()
		{
			_asm
			{
				push eax;
				call EmitAnimTree_call;
				add esp, 0x4;
				ret;
			}
		}

		int Scr_FindLocalVarIndex_stub(game::scriptInstance_t inst, unsigned int name, game::sval_u sourcePos, int create, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			return Scr_FindLocalVarIndex_hook.invoke<int>(inst, name, sourcePos, create, block);
#else
			return codsrc::Scr_FindLocalVarIndex(inst, name, sourcePos, create, block);
#endif
		}

		void EmitCreateLocalVars_stub(game::scriptInstance_t inst, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			EmitCreateLocalVars_hook.invoke<void>(inst, block);
#else
			codsrc::EmitCreateLocalVars(inst, block);
#endif
		}

		void EmitRemoveLocalVars_call(game::scriptInstance_t inst, game::scr_block_s* outerBlock, [[maybe_unused]] void* caller_addr, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitRemoveLocalVars(inst, outerBlock, block, EmitRemoveLocalVars_original);
#else
			codsrc::EmitRemoveLocalVars(inst, outerBlock, block);
#endif
		}

		// void __usercall EmitRemoveLocalVars(game::scriptInstance_t inst@<eax>, game::scr_block_s *outerBlock@<ecx>, game::scr_block_s *block)
		NAKED void EmitRemoveLocalVars_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call EmitRemoveLocalVars_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitNOP2_call(game::scr_block_s* block, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, int lastStatement, unsigned int endSourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitNOP2(block, inst, lastStatement, endSourcePos, EmitNOP2_original);
#else
			codsrc::EmitNOP2(block, inst, lastStatement, endSourcePos);
#endif
		}

		// void __usercall EmitNOP2(game::scr_block_s *block@<ecx>, game::scriptInstance_t inst@<edi>, int lastStatement, unsigned int endSourcePos)
		NAKED void EmitNOP2_stub()
		{
			_asm
			{
				push edi;
				push ecx;
				call EmitNOP2_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_InitFromChildBlocks_stub(game::scr_block_s** childBlocks, int childCount, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			Scr_InitFromChildBlocks_hook.invoke<void>(childBlocks, childCount, block);
#else
			codsrc::Scr_InitFromChildBlocks(childBlocks, childCount, block);
#endif
		}

		void Scr_AppendChildBlocks_call(game::scr_block_s* block, [[maybe_unused]] void* caller_addr, game::scr_block_s** childBlocks, int childCount)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::Scr_AppendChildBlocks(block, childBlocks, childCount, Scr_AppendChildBlocks_original);
#else
			codsrc::Scr_AppendChildBlocks(block, childBlocks, childCount);
#endif
		}

		// void __usercall Scr_AppendChildBlocks(game::scr_block_s *block@<edi>, game::scr_block_s **childBlocks, int childCount)
		NAKED void Scr_AppendChildBlocks_stub()
		{
			_asm
			{
				push edi;
				call Scr_AppendChildBlocks_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_MergeChildBlocks_stub(game::scr_block_s** childBlocks, int childCount, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			Scr_MergeChildBlocks_hook.invoke<void>(childBlocks, childCount, block);
#else
			codsrc::Scr_MergeChildBlocks(childBlocks, childCount, block);
#endif
		}

		void Scr_TransferBlock_call(game::scr_block_s* to, [[maybe_unused]] void* caller_addr, game::scr_block_s* from)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::Scr_TransferBlock(to, from, Scr_TransferBlock_original);
#else
			codsrc::Scr_TransferBlock(to, from);
#endif
		}

		// void __usercall Scr_TransferBlock(game::scr_block_s *to@<esi>, game::scr_block_s *from)
		NAKED void Scr_TransferBlock_stub()
		{
			_asm
			{
				push esi;
				call Scr_TransferBlock_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitSafeSetVariableField_call(game::scr_block_s* block, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitSafeSetVariableField(block, inst, expr, sourcePos, EmitSafeSetVariableField_original);
#else
			codsrc::EmitSafeSetVariableField(block, inst, expr, sourcePos);
#endif
		}

		// void __usercall EmitSafeSetVariableField(game::scr_block_s *block@<eax>, game::scriptInstance_t inst@<esi>, game::sval_u expr, game::sval_u sourcePos)
		NAKED void EmitSafeSetVariableField_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call EmitSafeSetVariableField_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitSafeSetWaittillVariableField_call(game::scr_block_s* block, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitSafeSetWaittillVariableField(block, inst, expr, sourcePos, EmitSafeSetWaittillVariableField_original);
#else
			codsrc::EmitSafeSetWaittillVariableField(block, inst, expr, sourcePos);
#endif
		}

		// void __usercall EmitSafeSetWaittillVariableField(game::scr_block_s *block@<eax>, game::scriptInstance_t inst@<edi>, game::sval_u expr, game::sval_u sourcePos)
		NAKED void EmitSafeSetWaittillVariableField_stub()
		{
			_asm
			{
				push edi;
				push eax;
				call EmitSafeSetWaittillVariableField_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitGetString_call(unsigned int value, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitGetString(value, inst, sourcePos, EmitGetString_original);
#else
			codsrc::EmitGetString(value, inst, sourcePos);
#endif
		}

		// void __usercall EmitGetString(unsigned int value@<edi>, game::scriptInstance_t inst@<esi>, game::sval_u sourcePos)
		NAKED void EmitGetString_stub()
		{
			_asm
			{
				push esi;
				push edi;
				call EmitGetString_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitGetIString_call(unsigned int value, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitGetIString(value, inst, sourcePos, EmitGetIString_original);
#else
			codsrc::EmitGetIString(value, inst, sourcePos);
#endif
		}

		// void __usercall EmitGetIString(unsigned int value@<edi>, game::scriptInstance_t inst@<esi>, game::sval_u sourcePos)
		NAKED void EmitGetIString_stub()
		{
			_asm
			{
				push esi;
				push edi;
				call EmitGetIString_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitGetVector_call(const float* value, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitGetVector(value, inst, sourcePos, EmitGetVector_original);
#else
			codsrc::EmitGetVector(value, inst, sourcePos);
#endif
		}

		// void __usercall EmitGetVector(const float *value@<eax>, game::scriptInstance_t inst, game::sval_u sourcePos)
		NAKED void EmitGetVector_stub()
		{
			_asm
			{
				push eax;
				call EmitGetVector_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitValue_stub(game::scriptInstance_t inst, game::VariableCompileValue* constValue)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			EmitValue_hook.invoke<void>(inst, constValue);
#else
			codsrc::EmitValue(inst, constValue);
#endif
		}

		void Scr_PushValue_call(game::scriptInstance_t inst, game::VariableCompileValue* constValue, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::Scr_PushValue(inst, constValue, Scr_PushValue_original);
#else
			codsrc::Scr_PushValue(inst, constValue);
#endif
		}

		// void __usercall Scr_PushValue(game::scriptInstance_t inst@<eax>, game::VariableCompileValue *constValue@<esi>)
		NAKED void Scr_PushValue_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call Scr_PushValue_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitCastBool_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitCastBool(inst, sourcePos, EmitCastBool_original);
#else
			codsrc::EmitCastBool(inst, sourcePos);
#endif
		}

		// void __usercall EmitCastBool(game::scriptInstance_t inst@<edi>, game::sval_u sourcePos)
		NAKED void EmitCastBool_stub()
		{
			_asm
			{
				push edi;
				call EmitCastBool_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitBoolNot_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitBoolNot(inst, sourcePos, EmitBoolNot_original);
#else
			codsrc::EmitBoolNot(inst, sourcePos);
#endif
		}

		// void __usercall EmitBoolNot(game::scriptInstance_t inst@<edi>, game::sval_u sourcePos)
		NAKED void EmitBoolNot_stub()
		{
			_asm
			{
				push edi;
				call EmitBoolNot_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitBoolComplement_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitBoolComplement(inst, sourcePos, EmitBoolComplement_original);
#else
			codsrc::EmitBoolComplement(inst, sourcePos);
#endif
		}

		// void __usercall EmitBoolComplement(game::scriptInstance_t inst@<edi>, game::sval_u sourcePos)
		NAKED void EmitBoolComplement_stub()
		{
			_asm
			{
				push edi;
				call EmitBoolComplement_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitSize_call(game::scr_block_s* block, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitSize(block, inst, expr, sourcePos, EmitSize_original);
#else
			codsrc::EmitSize(block, inst, expr, sourcePos);
#endif
		}

		// void __usercall EmitSize(game::scr_block_s *block@<eax>, game::scriptInstance_t inst@<edi>, game::sval_u expr, game::sval_u sourcePos)
		NAKED void EmitSize_stub()
		{
			_asm
			{
				push edi;
				push eax;
				call EmitSize_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitSelf_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitSelf(inst, sourcePos, EmitSelf_original);
#else
			codsrc::EmitSelf(inst, sourcePos);
#endif
		}

		// void __usercall EmitSelf(game::scriptInstance_t inst@<edi>, game::sval_u sourcePos)
		NAKED void EmitSelf_stub()
		{
			_asm
			{
				push edi;
				call EmitSelf_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitLevel_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitLevel(inst, sourcePos, EmitLevel_original);
#else
			codsrc::EmitLevel(inst, sourcePos);
#endif
		}

		// void __usercall EmitLevel(game::scriptInstance_t inst@<edi>, game::sval_u sourcePos)
		NAKED void EmitLevel_stub()
		{
			_asm
			{
				push edi;
				call EmitLevel_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitGame_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitGame(inst, sourcePos, EmitGame_original);
#else
			codsrc::EmitGame(inst, sourcePos);
#endif
		}

		// void __usercall EmitGame(game::scriptInstance_t inst@<edi>, game::sval_u sourcePos)
		NAKED void EmitGame_stub()
		{
			_asm
			{
				push edi;
				call EmitGame_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitAnim_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitAnim(inst, sourcePos, EmitAnim_original);
#else
			codsrc::EmitAnim(inst, sourcePos);
#endif
		}

		// void __usercall EmitAnim(game::scriptInstance_t inst@<edi>, game::sval_u sourcePos)
		NAKED void EmitAnim_stub()
		{
			_asm
			{
				push edi;
				call EmitAnim_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitSelfObject_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitSelfObject(inst, sourcePos, EmitSelfObject_original);
#else
			codsrc::EmitSelfObject(inst, sourcePos);
#endif
		}

		// void __usercall EmitSelfObject(game::scriptInstance_t inst@<edi>, game::sval_u sourcePos)
		NAKED void EmitSelfObject_stub()
		{
			_asm
			{
				push edi;
				call EmitSelfObject_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitLevelObject_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitLevelObject(inst, sourcePos, EmitLevelObject_original);
#else
			codsrc::EmitLevelObject(inst, sourcePos);
#endif
		}

		// void __usercall EmitLevelObject(game::scriptInstance_t inst@<edi>, game::sval_u sourcePos)
		NAKED void EmitLevelObject_stub()
		{
			_asm
			{
				push edi;
				call EmitLevelObject_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitAnimObject_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitAnimObject(inst, sourcePos, EmitAnimObject_original);
#else
			codsrc::EmitAnimObject(inst, sourcePos);
#endif
		}

		// void __usercall EmitAnimObject(game::scriptInstance_t inst@<edi>, game::sval_u sourcePos)
		NAKED void EmitAnimObject_stub()
		{
			_asm
			{
				push edi;
				call EmitAnimObject_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitLocalVariable_call(game::scr_block_s* block, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitLocalVariable(block, inst, expr, sourcePos, EmitLocalVariable_original);
#else
			codsrc::EmitLocalVariable(block, inst, expr, sourcePos);
#endif
		}

		// void __usercall EmitLocalVariable(game::scr_block_s *block@<eax>, game::scriptInstance_t inst@<esi>, game::sval_u expr, game::sval_u sourcePos)
		NAKED void EmitLocalVariable_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call EmitLocalVariable_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitLocalVariableRef_call(game::scr_block_s* block, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitLocalVariableRef(block, inst, expr, sourcePos, EmitLocalVariableRef_original);
#else
			codsrc::EmitLocalVariableRef(block, inst, expr, sourcePos);
#endif
		}

		// void __usercall EmitLocalVariableRef(game::scr_block_s *block@<eax>, game::scriptInstance_t inst@<esi>, game::sval_u expr, game::sval_u sourcePos)
		NAKED void EmitLocalVariableRef_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call EmitLocalVariableRef_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_RegisterLocalVar_stub(unsigned int name, game::sval_u sourcePos, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			Scr_RegisterLocalVar_hook.invoke<void>(name, sourcePos, block);
#else
			codsrc::Scr_RegisterLocalVar(name, sourcePos, block);
#endif
		}

		void EmitGameRef_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitGameRef(inst, sourcePos, EmitGameRef_original);
#else
			codsrc::EmitGameRef(inst, sourcePos);
#endif
		}

		// void __usercall EmitGameRef(game::scriptInstance_t inst@<edi>, game::sval_u sourcePos)
		NAKED void EmitGameRef_stub()
		{
			_asm
			{
				push edi;
				call EmitGameRef_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitClearArray_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u sourcePos, game::sval_u indexSourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitClearArray(inst, sourcePos, indexSourcePos, EmitClearArray_original);
#else
			codsrc::EmitClearArray(inst, sourcePos, indexSourcePos);
#endif
		}

		// void __usercall EmitClearArray(game::scriptInstance_t inst@<edi>, game::sval_u sourcePos, game::sval_u indexSourcePos)
		NAKED void EmitClearArray_stub()
		{
			_asm
			{
				push edi;
				call EmitClearArray_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitEmptyArray_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitEmptyArray(inst, sourcePos, EmitEmptyArray_original);
#else
			codsrc::EmitEmptyArray(inst, sourcePos);
#endif
		}

		// void __usercall EmitEmptyArray(game::scriptInstance_t inst@<edi>, game::sval_u sourcePos)
		NAKED void EmitEmptyArray_stub()
		{
			_asm
			{
				push edi;
				call EmitEmptyArray_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitAnimation_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u anim, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitAnimation(inst, anim, sourcePos, EmitAnimation_original);
#else
			codsrc::EmitAnimation(inst, anim, sourcePos);
#endif
		}

		// void __usercall EmitAnimation(game::scriptInstance_t inst@<eax>, game::sval_u anim, game::sval_u sourcePos)
		NAKED void EmitAnimation_stub()
		{
			_asm
			{
				push eax;
				call EmitAnimation_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitFieldVariable_call(game::scr_block_s* block, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr, game::sval_u field, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitFieldVariable(block, inst, expr, field, sourcePos, EmitFieldVariable_original);
#else
			codsrc::EmitFieldVariable(block, inst, expr, field, sourcePos);
#endif
		}

		// void __usercall EmitFieldVariable(game::scr_block_s *block@<eax>, game::scriptInstance_t inst@<esi>, game::sval_u expr, game::sval_u field, game::sval_u sourcePos)
		NAKED void EmitFieldVariable_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call EmitFieldVariable_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitClearFieldVariable_call(game::scr_block_s* block, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr, game::sval_u field, game::sval_u sourcePos, game::sval_u rhsSourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitClearFieldVariable(block, inst, expr, field, sourcePos, rhsSourcePos, EmitClearFieldVariable_original);
#else
			codsrc::EmitClearFieldVariable(block, inst, expr, field, sourcePos, rhsSourcePos);
#endif
		}

		// void __usercall EmitClearFieldVariable(game::scr_block_s *block@<eax>, game::scriptInstance_t inst@<esi>, game::sval_u expr, game::sval_u field, game::sval_u sourcePos)
		NAKED void EmitClearFieldVariable_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call EmitClearFieldVariable_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitObject_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitObject(inst, expr, sourcePos, EmitObject_original);
#else
			codsrc::EmitObject(inst, expr, sourcePos);
#endif
		}

		// void __usercall EmitObject(game::scriptInstance_t inst@<edi>, game::sval_u expr, game::sval_u sourcePos)
		NAKED void EmitObject_stub()
		{
			_asm
			{
				push edi;
				call EmitObject_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitDecTop_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitDecTop(inst, EmitDecTop_original);
#else
			codsrc::EmitDecTop(inst);
#endif
		}

		// void __usercall EmitDecTop(game::scriptInstance_t inst@<eax>)
		NAKED void EmitDecTop_stub()
		{
			_asm
			{
				push eax;
				call EmitDecTop_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitCastFieldObject_stub(game::scriptInstance_t inst, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			EmitCastFieldObject_hook.invoke<void>(inst, sourcePos);
#else
			codsrc::EmitCastFieldObject(inst, sourcePos);
#endif
		}

		void EmitArrayVariable_call(game::scr_block_s* block, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr, game::sval_u index, game::sval_u sourcePos, game::sval_u indexSourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitArrayVariable(block, inst, expr, index, sourcePos, indexSourcePos, EmitArrayVariable_original);
#else
			codsrc::EmitArrayVariable(block, inst, expr, index, sourcePos, indexSourcePos);
#endif
		}

		// void __usercall EmitArrayVariable(game::scr_block_s *block@<edi>, game::scriptInstance_t inst@<esi>, game::sval_u expr, game::sval_u index, game::sval_u sourcePos, game::sval_u indexSourcePos)
		NAKED void EmitArrayVariable_stub()
		{
			_asm
			{
				push esi;
				push edi;
				call EmitArrayVariable_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitArrayVariableRef_call(game::scr_block_s* block, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr, game::sval_u index, game::sval_u sourcePos, game::sval_u indexSourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitArrayVariableRef(block, inst, expr, index, sourcePos, indexSourcePos, EmitArrayVariableRef_original);
#else
			codsrc::EmitArrayVariableRef(block, inst, expr, index, sourcePos, indexSourcePos);
#endif
		}

		// void __usercall EmitArrayVariableRef(game::scr_block_s *block@<eax>, game::scriptInstance_t inst@<esi>, game::sval_u expr, game::sval_u index, game::sval_u sourcePos, game::sval_u indexSourcePos)
		NAKED void EmitArrayVariableRef_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call EmitArrayVariableRef_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitClearArrayVariable_call(game::scr_block_s* block, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr, game::sval_u index, game::sval_u sourcePos, game::sval_u indexSourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitClearArrayVariable(block, inst, expr, index, sourcePos, indexSourcePos, EmitClearArrayVariable_original);
#else
			codsrc::EmitClearArrayVariable(block, inst, expr, index, sourcePos, indexSourcePos);
#endif
		}

		// void __usercall EmitClearArrayVariable(game::scr_block_s *block@<eax>, game::scriptInstance_t inst@<ecx>, game::sval_u expr, game::sval_u index, game::sval_u sourcePos, game::sval_u indexSourcePos)
		NAKED void EmitClearArrayVariable_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call EmitClearArrayVariable_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitVariableExpression_stub(game::scriptInstance_t inst, game::sval_u expr, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			EmitVariableExpression_hook.invoke<void>(inst, expr, block);
#else
			codsrc::EmitVariableExpression(inst, expr, block);
#endif
		}

		int EmitExpressionList_stub(game::scriptInstance_t inst, game::sval_u exprlist, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			return EmitExpressionList_hook.invoke<int>(inst, exprlist, block);
#else
			return codsrc::EmitExpressionList(inst, exprlist, block);
#endif
		}

		void AddExpressionListOpcodePos_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u exprlist)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::AddExpressionListOpcodePos(inst, exprlist, AddExpressionListOpcodePos_original);
#else
			codsrc::AddExpressionListOpcodePos(inst, exprlist);
#endif
		}

		// void __usercall AddExpressionListOpcodePos(game::scriptInstance_t inst@<edi>, game::sval_u exprlist)
		NAKED void AddExpressionListOpcodePos_stub()
		{
			_asm
			{
				push edi;
				call AddExpressionListOpcodePos_call;
				add esp, 0x4;
				ret;
			}
		}

		void AddFilePrecache_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, unsigned int filename, unsigned int sourcePos, int include, unsigned int* filePosId, unsigned int* fileCountId)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::AddFilePrecache(inst, filename, sourcePos, include, filePosId, fileCountId, AddFilePrecache_original);
#else
			codsrc::AddFilePrecache(inst, filename, sourcePos, include, filePosId, fileCountId);
#endif
		}

		// void __usercall AddFilePrecache(game::scriptInstance_t inst@<eax>, unsigned int filename, unsigned int sourcePos, bool include, unsigned int *filePosId, unsigned int *fileCountId)
		NAKED void AddFilePrecache_stub()
		{
			_asm
			{
				push eax;
				call AddFilePrecache_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitFunction_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u func, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitFunction(inst, func, sourcePos, EmitFunction_original);
#else
			codsrc::EmitFunction(inst, func, sourcePos);
#endif
		}

		// void __usercall EmitFunction(game::scriptInstance_t inst@<eax>, game::sval_u func, game::sval_u sourcePos)
		NAKED void EmitFunction_stub()
		{
			_asm
			{
				push eax;
				call EmitFunction_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitGetFunction_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u func, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitGetFunction(inst, func, sourcePos, EmitGetFunction_original);
#else
			codsrc::EmitGetFunction(inst, func, sourcePos);
#endif
		}

		// void __usercall EmitGetFunction(game::scriptInstance_t inst@<edi>, game::sval_u func, game::sval_u sourcePos)
		NAKED void EmitGetFunction_stub()
		{
			_asm
			{
				push edi;
				call EmitGetFunction_call;
				add esp, 0x4;
				ret;
			}
		}

		int AddFunction_stub(game::scriptInstance_t inst, int func)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			return AddFunction_hook.invoke<int>(inst, func);
#else
			return codsrc::AddFunction(inst, func);
#endif
		}

		void EmitPostScriptFunction_stub(game::scriptInstance_t inst, game::sval_u func, int param_count, int bMethod, game::sval_u nameSourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			EmitPostScriptFunction_hook.invoke<void>(inst, func, param_count, bMethod, nameSourcePos);
#else
			codsrc::EmitPostScriptFunction(inst, func, param_count, bMethod, nameSourcePos);
#endif
		}

		void EmitPostScriptFunctionPointer_call(game::scr_block_s* block, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr, int param_count, int bMethod, game::sval_u nameSourcePos, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitPostScriptFunctionPointer(block, inst, expr, param_count, bMethod, nameSourcePos, sourcePos, EmitPostScriptFunctionPointer_original);
#else
			codsrc::EmitPostScriptFunctionPointer(block, inst, expr, param_count, bMethod, nameSourcePos, sourcePos);
#endif
		}

		// void __usercall EmitPostScriptFunctionPointer(game::scr_block_s *block@<eax>, game::scriptInstance_t inst@<edi>, game::sval_u expr, int param_count, int bMethod, game::sval_u nameSourcePos, game::sval_u sourcePos)
		NAKED void EmitPostScriptFunctionPointer_stub()
		{
			_asm
			{
				push edi;
				push eax;
				call EmitPostScriptFunctionPointer_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitPostScriptThread_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u func, int param_count, int bMethod, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitPostScriptThread(inst, func, param_count, bMethod, sourcePos, EmitPostScriptThread_original);
#else
			codsrc::EmitPostScriptThread(inst, func, param_count, bMethod, sourcePos);
#endif
		}

		// void __usercall EmitPostScriptThread(game::scriptInstance_t inst@<edi>, game::sval_u func, int param_count, int bMethod, game::sval_u sourcePos)
		NAKED void EmitPostScriptThread_stub()
		{
			_asm
			{
				push edi;
				call EmitPostScriptThread_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitPostScriptThreadPointer_call(game::scr_block_s* block, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr, int param_count, int bMethod, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitPostScriptThreadPointer(block, inst, expr, param_count, bMethod, sourcePos, EmitPostScriptThreadPointer_original);
#else
			codsrc::EmitPostScriptThreadPointer(block, inst, expr, param_count, bMethod, sourcePos);
#endif
		}

		// void __usercall EmitPostScriptThreadPointer(game::scr_block_s *block@<eax>, game::scriptInstance_t inst@<edi>, game::sval_u expr, int param_count, int bMethod, game::sval_u sourcePos)
		NAKED void EmitPostScriptThreadPointer_stub()
		{
			_asm
			{
				push edi;
				push eax;
				call EmitPostScriptThreadPointer_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitPostScriptFunctionCall_call(game::scriptInstance_t inst, int bMethod, int param_count, [[maybe_unused]] void* caller_addr, game::sval_u func_name, game::sval_u nameSourcePos, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitPostScriptFunctionCall(inst, bMethod, param_count, func_name, nameSourcePos, block, EmitPostScriptFunctionCall_original);
#else
			codsrc::EmitPostScriptFunctionCall(inst, bMethod, param_count, func_name, nameSourcePos, block);
#endif
		}

		// void __usercall EmitPostScriptFunctionCall(game::scriptInstance_t inst@<eax>, char bMethod@<dl>, int param_count@<esi>, game::sval_u func_name, game::sval_u nameSourcePos, game::scr_block_s *block)
		NAKED void EmitPostScriptFunctionCall_stub()
		{
			_asm
			{
				push esi;
				push edx;
				push eax;
				call EmitPostScriptFunctionCall_call;
				add esp, 0xC;
				ret;
			}
		}

		void EmitPostScriptThreadCall_call(game::scriptInstance_t inst, int isMethod, int param_count, [[maybe_unused]] void* caller_addr, game::sval_u func_name, game::sval_u sourcePos, game::sval_u nameSourcePos, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitPostScriptThreadCall(inst, isMethod, param_count, func_name, sourcePos, nameSourcePos, block, EmitPostScriptThreadCall_original);
#else
			codsrc::EmitPostScriptThreadCall(inst, isMethod, param_count, func_name, sourcePos, nameSourcePos, block);
#endif
		}

		// void __usercall EmitPostScriptThreadCall(game::scriptInstance_t inst@<eax>, char isMethod@<dl>, int param_count@<esi>, game::sval_u func_name, game::sval_u sourcePos, game::sval_u nameSourcePos, game::scr_block_s *block)
		NAKED void EmitPostScriptThreadCall_stub()
		{
			_asm
			{
				push esi;
				push edx;
				push eax;
				call EmitPostScriptThreadCall_call;
				add esp, 0xC;
				ret;
			}
		}

		void EmitPreFunctionCall_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitPreFunctionCall(inst, EmitPreFunctionCall_original);
#else
			codsrc::EmitPreFunctionCall(inst);
#endif
		}

		// void __usercall EmitPreFunctionCall(game::scriptInstance_t inst@<eax>)
		NAKED void EmitPreFunctionCall_stub()
		{
			_asm
			{
				push eax;
				call EmitPreFunctionCall_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitPostFunctionCall_call(game::scriptInstance_t inst, int bMethod, [[maybe_unused]] void* caller_addr, game::sval_u func_name, int param_count, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitPostFunctionCall(inst, bMethod, func_name, param_count, block, EmitPostFunctionCall_original);
#else
			codsrc::EmitPostFunctionCall(inst, bMethod, func_name, param_count, block);
#endif
		}

		// void __usercall EmitPostFunctionCall(game::scriptInstance_t inst@<eax>, char bMethod@<dl>, game::sval_u func_name, int param_count, game::scr_block_s *block)
		NAKED void EmitPostFunctionCall_stub()
		{
			_asm
			{
				push edx;
				push eax;
				call EmitPostFunctionCall_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_BeginDevScript_call(game::scriptInstance_t isnt, int* type_, [[maybe_unused]] void* caller_addr, char** savedPos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::Scr_BeginDevScript(isnt, type_, savedPos, Scr_BeginDevScript_original);
#else
			codsrc::Scr_BeginDevScript(isnt, type_, savedPos);
#endif
		}

		// void __usercall Scr_BeginDevScript(game::scriptInstance_t isnt@<eax>, int *type@<edi>, char **savedPos)
		NAKED void Scr_BeginDevScript_stub()
		{
			_asm
			{
				push edi;
				push eax;
				call Scr_BeginDevScript_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_EndDevScript_call(game::scriptInstance_t inst, char** savedPos, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::Scr_EndDevScript(inst, savedPos, Scr_EndDevScript_original);
#else
			codsrc::Scr_EndDevScript(inst, savedPos);
#endif
		}

		// void __usercall Scr_EndDevScript(game::scriptInstance_t inst@<eax>, char **savedPos@<edx>)
		NAKED void Scr_EndDevScript_stub()
		{
			_asm
			{
				push edx;
				push eax;
				call Scr_EndDevScript_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitCallBuiltinOpcode_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, int param_count, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitCallBuiltinOpcode(inst, param_count, sourcePos, EmitCallBuiltinOpcode_original);
#else
			codsrc::EmitCallBuiltinOpcode(inst, param_count, sourcePos);
#endif
		}

		// void __usercall EmitCallBuiltinOpcode(game::scriptInstance_t inst@<eax>, int param_count, game::sval_u sourcePos)
		NAKED void EmitCallBuiltinOpcode_stub()
		{
			_asm
			{
				push eax;
				call EmitCallBuiltinOpcode_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitCallBuiltinMethodOpcode_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, int param_count, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitCallBuiltinMethodOpcode(inst, param_count, sourcePos, EmitCallBuiltinMethodOpcode_original);
#else
			codsrc::EmitCallBuiltinMethodOpcode(inst, param_count, sourcePos);
#endif
		}

		// void __usercall EmitCallBuiltinMethodOpcode(int inst@<eax>, int param_count, game::sval_u sourcePos)
		NAKED void EmitCallBuiltinMethodOpcode_stub()
		{
			_asm
			{
				push eax;
				call EmitCallBuiltinMethodOpcode_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitCall_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u func_name, game::sval_u params, int bStatement, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitCall(inst, func_name, params, bStatement, block, EmitCall_original);
#else
			codsrc::EmitCall(inst, func_name, params, bStatement, block);
#endif
		}

		// void __usercall EmitCall(game::scriptInstance_t inst@<eax>, game::sval_u func_name, game::sval_u params, int bStatement, game::scr_block_s *block)
		NAKED void EmitCall_stub()
		{
			_asm
			{
				push eax;
				call EmitCall_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitMethod_stub(game::scriptInstance_t inst, game::sval_u expr, game::sval_u func_name, game::sval_u params, game::sval_u methodSourcePos, int bStatement, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			EmitMethod_hook.invoke<void>(inst, expr, func_name, params, methodSourcePos, bStatement, block);
#else
			codsrc::EmitMethod(inst, expr, func_name, params, methodSourcePos, bStatement, block);
#endif
		}

		void LinkThread_call(game::scriptInstance_t inst, unsigned int threadCountId, [[maybe_unused]] void* caller_addr, game::VariableValue* pos, int allowFarCall)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::LinkThread(inst, threadCountId, pos, allowFarCall, LinkThread_original);
#else
			codsrc::LinkThread(inst, threadCountId, pos, allowFarCall);
#endif
		}

		// void __usercall LinkThread(game::scriptInstance_t inst@<ecx>, unsigned int threadCountId@<eax>, game::VariableValue *pos, int allowFarCall)
		NAKED void LinkThread_stub()
		{
			_asm
			{
				push eax;
				push ecx;
				call LinkThread_call;
				add esp, 0x8;
				ret;
			}
		}

		void LinkFile_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, unsigned int filePosId, unsigned int fileCountId)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::LinkFile(inst, filePosId, fileCountId, LinkFile_original);
#else
			codsrc::LinkFile(inst, filePosId, fileCountId);
#endif
		}

		// void __usercall LinkFile(game::scriptInstance_t inst@<eax>, unsigned int filePosId, unsigned int fileCountId)
		NAKED void LinkFile_stub()
		{
			_asm
			{
				push eax;
				call LinkFile_call;
				add esp, 0x4;
				ret;
			}
		}

		void CheckThreadPosition_stub(game::scriptInstance_t inst, unsigned int posId, unsigned int name, unsigned int sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			CheckThreadPosition_hook.invoke<void>(inst, posId, name, sourcePos);
#else
			codsrc::CheckThreadPosition(inst, posId, name, sourcePos);
#endif
		}

		void EmitCallExpression_call(game::scriptInstance_t inst, game::scr_block_s* block, [[maybe_unused]] void* caller_addr, game::sval_u expr, int bStatement)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitCallExpression(inst, block, expr, bStatement, EmitCallExpression_original);
#else
			codsrc::EmitCallExpression(inst, block, expr, bStatement);
#endif
		}

		// void __usercall EmitCallExpression(game::scriptInstance_t inst@<eax>, game::scr_block_s *block@<esi>, game::sval_u expr, int bStatement)
		NAKED void EmitCallExpression_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call EmitCallExpression_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitCallExpressionFieldObject_call(game::scr_block_s* block, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitCallExpressionFieldObject(block, inst, expr, EmitCallExpressionFieldObject_original);
#else
			codsrc::EmitCallExpressionFieldObject(block, inst, expr);
#endif
		}

		// void __usercall EmitCallExpressionFieldObject(game::scr_block_s *block@<ecx>, game::scriptInstance_t inst@<edi>, game::sval_u expr)
		NAKED void EmitCallExpressionFieldObject_stub()
		{
			_asm
			{
				push edi;
				push ecx;
				call EmitCallExpressionFieldObject_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_CreateVector_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::VariableCompileValue* constValue, game::VariableValue* value)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::Scr_CreateVector(inst, constValue, value, Scr_CreateVector_original);
#else
			codsrc::Scr_CreateVector(inst, constValue, value);
#endif
		}

		// void __usercall Scr_CreateVector(game::scriptInstance_t inst@<eax>, game::VariableCompileValue *constValue, game::VariableValue *value)
		NAKED void Scr_CreateVector_stub()
		{
			_asm
			{
				push eax;
				call Scr_CreateVector_call;
				add esp, 0x4;
				ret;
			}
		}

		bool EvalPrimitiveExpressionList_stub(game::scriptInstance_t inst, game::sval_u exprlist, game::sval_u sourcePos, game::VariableCompileValue* constValue)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			return EvalPrimitiveExpressionList_hook.invoke<bool>(inst, exprlist, sourcePos, constValue);
#else
			return codsrc::EvalPrimitiveExpressionList(inst, exprlist, sourcePos, constValue);
#endif
		}

		bool EmitOrEvalPrimitiveExpressionList_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u exprlist, game::sval_u sourcePos, game::VariableCompileValue* constValue, game::scr_block_s* a5)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			return game::EmitOrEvalPrimitiveExpressionList(inst, exprlist, sourcePos, constValue, a5, EmitOrEvalPrimitiveExpressionList_original);
#else
			return codsrc::EmitOrEvalPrimitiveExpressionList(inst, exprlist, sourcePos, constValue, a5);
#endif
		}

		// bool __usercall EmitOrEvalPrimitiveExpressionList@<al>(game::scriptInstance_t inst@<eax>, game::sval_u exprlist, game::sval_u sourcePos, game::VariableCompileValue *constValue, game::scr_block_s *a5)
		NAKED bool EmitOrEvalPrimitiveExpressionList_stub()
		{
			_asm
			{
				push eax;
				call EmitOrEvalPrimitiveExpressionList_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitExpressionListFieldObject_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u exprlist, game::sval_u sourcePos, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitExpressionListFieldObject(inst, exprlist, sourcePos, block, EmitExpressionListFieldObject_original);
#else
			codsrc::EmitExpressionListFieldObject(inst, exprlist, sourcePos, block);
#endif
		}

		// void __usercall EmitExpressionListFieldObject(game::scriptInstance_t inst@<edx>, game::sval_u exprlist, game::sval_u sourcePos, game::scr_block_s *block)
		NAKED void EmitExpressionListFieldObject_stub()
		{
			_asm
			{
				push edx;
				call EmitExpressionListFieldObject_call;
				add esp, 0x4;
				ret;
			}
		}

		bool EvalPrimitiveExpression_stub(game::scriptInstance_t inst, game::sval_u expr, game::VariableCompileValue* constValue)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			return EvalPrimitiveExpression_hook.invoke<bool>(inst, expr, constValue);
#else
			return codsrc::EvalPrimitiveExpression(inst, expr, constValue);
#endif
		}

		bool EmitOrEvalPrimitiveExpression_stub(game::scriptInstance_t inst, game::sval_u expr, game::VariableCompileValue* constValue, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			return EmitOrEvalPrimitiveExpression_hook.invoke<bool>(inst, expr, constValue, block);
#else
			return codsrc::EmitOrEvalPrimitiveExpression(inst, expr, constValue, block);
#endif
		}

		void EmitBoolOrExpression_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr1, game::sval_u expr2, game::sval_u expr1sourcePos, game::sval_u expr2sourcePos, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitBoolOrExpression(inst, expr1, expr2, expr1sourcePos, expr2sourcePos, block, EmitBoolOrExpression_original);
#else
			codsrc::EmitBoolOrExpression(inst, expr1, expr2, expr1sourcePos, expr2sourcePos, block);
#endif
		}

		// void __usercall EmitBoolOrExpression(game::scriptInstance_t inst@<eax>, game::sval_u expr1, game::sval_u expr2, game::sval_u expr1sourcePos, game::sval_u expr2sourcePos, game::scr_block_s *block)
		NAKED void EmitBoolOrExpression_stub()
		{
			_asm
			{
				push eax;
				call EmitBoolOrExpression_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitBoolAndExpression_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr1, game::sval_u expr2, game::sval_u expr1sourcePos, game::sval_u expr2sourcePos, game::scr_block_s* a6)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitBoolAndExpression(inst, expr1, expr2, expr1sourcePos, expr2sourcePos, a6, EmitBoolAndExpression_original);
#else
			codsrc::EmitBoolAndExpression(inst, expr1, expr2, expr1sourcePos, expr2sourcePos, a6);
#endif
		}

		// void __usercall EmitBoolAndExpression(game::scriptInstance_t inst@<eax>, game::sval_u expr1, game::sval_u expr2, game::sval_u expr1sourcePos, game::sval_u expr2sourcePos, game::scr_block_s *a6)
		NAKED void EmitBoolAndExpression_stub()
		{
			_asm
			{
				push eax;
				call EmitBoolAndExpression_call;
				add esp, 0x4;
				ret;
			}
		}

		bool EvalBinaryOperatorExpression_stub(game::scriptInstance_t inst, game::sval_u expr1, game::sval_u expr2, game::sval_u opcode, game::sval_u sourcePos, game::VariableCompileValue* constValue)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			return EvalBinaryOperatorExpression_hook.invoke<bool>(inst, expr1, expr2, opcode, sourcePos, constValue);
#else
			return codsrc::EvalBinaryOperatorExpression(inst, expr1, expr2, opcode, sourcePos, constValue);
#endif
		}

		bool EmitOrEvalBinaryOperatorExpression_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr1, game::sval_u expr2, game::sval_u opcode, game::sval_u sourcePos, game::VariableCompileValue* constValue, game::scr_block_s* a8)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			return game::EmitOrEvalBinaryOperatorExpression(inst, expr1, expr2, opcode, sourcePos, constValue, a8, EmitOrEvalBinaryOperatorExpression_original);
#else
			return codsrc::EmitOrEvalBinaryOperatorExpression(inst, expr1, expr2, opcode, sourcePos, constValue, a8);
#endif
		}

		// bool __usercall EmitOrEvalBinaryOperatorExpression@<al>(game::scriptInstance_t inst@<edi>, game::sval_u expr1, game::sval_u expr2, game::sval_u opcode, game::sval_u sourcePos, game::VariableCompileValue *constValue, game::scr_block_s *a8)
		NAKED bool EmitOrEvalBinaryOperatorExpression_stub()
		{
			_asm
			{
				push edi;
				call EmitOrEvalBinaryOperatorExpression_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitBinaryEqualsOperatorExpression_call(game::scr_block_s* block, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u lhs, game::sval_u rhs, game::sval_u opcode, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitBinaryEqualsOperatorExpression(block, inst, lhs, rhs, opcode, sourcePos, EmitBinaryEqualsOperatorExpression_original);
#else
			codsrc::EmitBinaryEqualsOperatorExpression(block, inst, lhs, rhs, opcode, sourcePos);
#endif
		}

		// void __usercall EmitBinaryEqualsOperatorExpression(game::scr_block_s *block@<edi>, game::scriptInstance_t inst@<esi>, game::sval_u lhs, game::sval_u rhs, game::sval_u opcode, game::sval_u sourcePos)
		NAKED void EmitBinaryEqualsOperatorExpression_stub()
		{
			_asm
			{
				push esi;
				push edi;
				call EmitBinaryEqualsOperatorExpression_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_CalcLocalVarsVariableExpressionRef_call(game::scr_block_s* block, [[maybe_unused]] void* caller_addr, game::sval_u expr)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::Scr_CalcLocalVarsVariableExpressionRef(block, expr, Scr_CalcLocalVarsVariableExpressionRef_original);
#else
			codsrc::Scr_CalcLocalVarsVariableExpressionRef(block, expr);
#endif
		}

		// void __usercall Scr_CalcLocalVarsVariableExpressionRef(game::scr_block_s *block@<edx>, game::sval_u expr)
		NAKED void Scr_CalcLocalVarsVariableExpressionRef_stub()
		{
			_asm
			{
				push edx;
				call Scr_CalcLocalVarsVariableExpressionRef_call;
				add esp, 0x4;
				ret;
			}
		}

		bool EvalExpression_call(game::VariableCompileValue* constValue, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			return game::EvalExpression(constValue, inst, expr, EvalExpression_original);
#else
			return codsrc::EvalExpression(constValue, inst, expr);
#endif
		}

		// bool __usercall EvalExpression@<al>(game::VariableCompileValue *constValue@<edx>, game::scriptInstance_t inst@<esi>, game::sval_u expr)
		NAKED bool EvalExpression_stub()
		{
			_asm
			{
				push esi;
				push edx;
				call EvalExpression_call;
				add esp, 0x8;
				ret;
			}
		}

		bool EmitOrEvalExpression_stub(game::scriptInstance_t inst, game::sval_u expr, game::VariableCompileValue* constValue, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			return EmitOrEvalExpression_hook.invoke<bool>(inst, expr, constValue, block);
#else
			return codsrc::EmitOrEvalExpression(inst, expr, constValue, block);
#endif
		}

		void EmitExpression_stub(game::scriptInstance_t inst, game::sval_u expr, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			EmitExpression_hook.invoke<void>(inst, expr, block);
#else
			codsrc::EmitExpression(inst, expr, block);
#endif
		}

		void EmitVariableExpressionRef_stub(game::scriptInstance_t inst, game::sval_u expr, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			EmitVariableExpressionRef_hook.invoke<void>(inst, expr, block);
#else
			codsrc::EmitVariableExpressionRef(inst, expr, block);
#endif
		}

		void EmitArrayPrimitiveExpressionRef_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr, game::sval_u sourcePos, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitArrayPrimitiveExpressionRef(inst, expr, sourcePos, block, EmitArrayPrimitiveExpressionRef_original);
#else
			codsrc::EmitArrayPrimitiveExpressionRef(inst, expr, sourcePos, block);
#endif
		}

		// void __usercall EmitArrayPrimitiveExpressionRef(game::scriptInstance_t inst@<eax>, game::sval_u expr, game::sval_u sourcePos, game::scr_block_s *block)
		NAKED void EmitArrayPrimitiveExpressionRef_stub()
		{
			_asm
			{
				push eax;
				call EmitArrayPrimitiveExpressionRef_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_CalcLocalVarsArrayVariableRef_stub(game::sval_u expr, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			Scr_CalcLocalVarsArrayVariableRef_hook.invoke<void>(expr, block);
#else
			codsrc::Scr_CalcLocalVarsArrayVariableRef(expr, block);
#endif
		}

		void EmitPrimitiveExpressionFieldObject_stub(game::scriptInstance_t inst, game::sval_u expr, game::sval_u sourcePos, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			EmitPrimitiveExpressionFieldObject_hook.invoke<void>(inst, expr, sourcePos, block);
#else
			codsrc::EmitPrimitiveExpressionFieldObject(inst, expr, sourcePos, block);
#endif
		}

		void ConnectBreakStatements_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::ConnectBreakStatements(inst, ConnectBreakStatements_original);
#else
			codsrc::ConnectBreakStatements(inst);
#endif
		}

		// void __usercall ConnectBreakStatements(game::scriptInstance_t inst@<eax>)
		NAKED void ConnectBreakStatements_stub()
		{
			_asm
			{
				push eax;
				call ConnectBreakStatements_call;
				add esp, 0x4;
				ret;
			}
		}

		void ConnectContinueStatements_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::ConnectContinueStatements(inst, ConnectContinueStatements_original);
#else
			codsrc::ConnectContinueStatements(inst);
#endif
		}

		// void __usercall ConnectContinueStatements(game::scriptInstance_t inst@<eax>)
		NAKED void ConnectContinueStatements_stub()
		{
			_asm
			{
				push eax;
				call ConnectContinueStatements_call;
				add esp, 0x4;
				ret;
			}
		}

		bool EmitClearVariableExpression_call(game::scr_block_s* block, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr, game::sval_u rhsSourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			return game::EmitClearVariableExpression(block, inst, expr, rhsSourcePos, EmitClearVariableExpression_original);
#else
			return codsrc::EmitClearVariableExpression(block, inst, expr, rhsSourcePos);
#endif
		}

		// bool __usercall EmitClearVariableExpression@<al>(game::scr_block_s *block@<eax>, game::scriptInstance_t inst@<ecx>, game::sval_u expr, game::sval_u rhsSourcePos)
		NAKED bool EmitClearVariableExpression_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call EmitClearVariableExpression_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitAssignmentStatement_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u lhs, game::sval_u rhs, game::sval_u sourcePos, game::sval_u rhsSourcePos, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitAssignmentStatement(inst, lhs, rhs, sourcePos, rhsSourcePos, block, EmitAssignmentStatement_original);
#else
			codsrc::EmitAssignmentStatement(inst, lhs, rhs, sourcePos, rhsSourcePos, block);
#endif
		}

		// void __usercall EmitAssignmentStatement(game::scriptInstance_t inst@<esi>, game::sval_u lhs, game::sval_u rhs, game::sval_u sourcePos, game::sval_u rhsSourcePos, game::scr_block_s *block)
		NAKED void EmitAssignmentStatement_stub()
		{
			_asm
			{
				push esi;
				call EmitAssignmentStatement_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitCallExpressionStatement_call(game::scriptInstance_t inst, game::scr_block_s* block, [[maybe_unused]] void* caller_addr, game::sval_u expr)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitCallExpressionStatement(inst, block, expr, EmitCallExpressionStatement_original);
#else
			codsrc::EmitCallExpressionStatement(inst, block, expr);
#endif
		}

		// void __usercall EmitCallExpressionStatement(game::scriptInstance_t inst@<eax>, game::scr_block_s *block@<esi>, game::sval_u expr)
		NAKED void EmitCallExpressionStatement_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call EmitCallExpressionStatement_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitReturnStatement_call(game::scr_block_s* block, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitReturnStatement(block, inst, expr, sourcePos, EmitReturnStatement_original);
#else
			codsrc::EmitReturnStatement(block, inst, expr, sourcePos);
#endif
		}

		// void __usercall EmitReturnStatement(game::scr_block_s *block@<eax>, game::scriptInstance_t inst@<esi>, game::sval_u expr, game::sval_u sourcePos)
		NAKED void EmitReturnStatement_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call EmitReturnStatement_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitWaitStatement_call(game::scr_block_s* block, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr, game::sval_u sourcePos, game::sval_u waitSourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitWaitStatement(block, inst, expr, sourcePos, waitSourcePos, EmitWaitStatement_original);
#else
			codsrc::EmitWaitStatement(block, inst, expr, sourcePos, waitSourcePos);
#endif
		}

		// void __usercall EmitWaitStatement(game::scr_block_s *block@<eax>, game::scriptInstance_t inst@<edi>, game::sval_u expr, game::sval_u sourcePos, game::sval_u waitSourcePos)
		NAKED void EmitWaitStatement_stub()
		{
			_asm
			{
				push edi;
				push eax;
				call EmitWaitStatement_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitWaittillFrameEnd_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitWaittillFrameEnd(inst, sourcePos, EmitWaittillFrameEnd_original);
#else
			codsrc::EmitWaittillFrameEnd(inst, sourcePos);
#endif
		}

		// void __usercall EmitWaittillFrameEnd(game::scriptInstance_t inst@<edi>, game::sval_u sourcePos)
		NAKED void EmitWaittillFrameEnd_stub()
		{
			_asm
			{
				push edi;
				call EmitWaittillFrameEnd_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitIfStatement_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr, game::sval_u stmt, game::sval_u sourcePos, int lastStatement, unsigned int endSourcePos, game::scr_block_s* block, game::sval_u* ifStatBlock)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitIfStatement(inst, expr, stmt, sourcePos, lastStatement, endSourcePos, block, ifStatBlock, EmitIfStatement_original);
#else
			codsrc::EmitIfStatement(inst, expr, stmt, sourcePos, lastStatement, endSourcePos, block, ifStatBlock);
#endif
		}

		// void __usercall EmitIfStatement(game::scriptInstance_t inst@<eax>, game::sval_u expr, game::sval_u stmt, game::sval_u sourcePos, int lastStatement, unsigned int endSourcePos, game::scr_block_s *block, game::sval_u *ifStatBlock)
		NAKED void EmitIfStatement_stub()
		{
			_asm
			{
				push eax;
				call EmitIfStatement_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_CalcLocalVarsIfStatement_stub(game::scriptInstance_t inst, game::sval_u stmt, game::scr_block_s* block, game::sval_u* ifStatBlock)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			Scr_CalcLocalVarsIfStatement_hook.invoke<void>(inst, stmt, block, ifStatBlock);
#else
			codsrc::Scr_CalcLocalVarsIfStatement(inst, stmt, block, ifStatBlock);
#endif
		}

		void EmitIfElseStatement_stub(game::scriptInstance_t inst, game::sval_u expr, game::sval_u stmt1, game::sval_u stmt2, game::sval_u sourcePos, game::sval_u elseSourcePos, int lastStatement, unsigned int endSourcePos, game::scr_block_s* block, game::sval_u* ifStatBlock, game::sval_u* elseStatBlock)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			EmitIfElseStatement_hook.invoke<void>(inst, expr, stmt1, stmt2, sourcePos, elseSourcePos, lastStatement, endSourcePos, block, ifStatBlock, elseStatBlock);
#else
			codsrc::EmitIfElseStatement(inst, expr, stmt1, stmt2, sourcePos, elseSourcePos, lastStatement, endSourcePos, block, ifStatBlock, elseStatBlock);
#endif
		}

		void Scr_CalcLocalVarsIfElseStatement_stub(game::scriptInstance_t inst, game::sval_u stmt1, game::sval_u stmt2, game::scr_block_s* block, game::sval_u* ifStatBlock, game::sval_u* elseStatBlock)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			Scr_CalcLocalVarsIfElseStatement_hook.invoke<void>(inst, stmt1, stmt2, block, ifStatBlock, elseStatBlock);
#else
			codsrc::Scr_CalcLocalVarsIfElseStatement(inst, stmt1, stmt2, block, ifStatBlock, elseStatBlock);
#endif
		}

		void Scr_AddBreakBlock_call(game::scriptInstance_t inst, game::scr_block_s* block, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::Scr_AddBreakBlock(inst, block, Scr_AddBreakBlock_original);
#else
			codsrc::Scr_AddBreakBlock(inst, block);
#endif
		}

		// void __usercall Scr_AddBreakBlock(game::scriptInstance_t inst@<eax>, game::scr_block_s *block@<edi>)
		NAKED void Scr_AddBreakBlock_stub()
		{
			_asm
			{
				push edi;
				push eax;
				call Scr_AddBreakBlock_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_AddContinueBlock_call(game::scriptInstance_t inst, game::scr_block_s* block, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::Scr_AddContinueBlock(inst, block, Scr_AddContinueBlock_original);
#else
			codsrc::Scr_AddContinueBlock(inst, block);
#endif
		}

		// void __usercall Scr_AddContinueBlock(game::scriptInstance_t inst@<eax>, game::scr_block_s *block@<edi>)
		NAKED void Scr_AddContinueBlock_stub()
		{
			_asm
			{
				push edi;
				push eax;
				call Scr_AddContinueBlock_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitWhileStatement_stub(game::scriptInstance_t inst, game::sval_u expr, game::sval_u stmt, game::sval_u sourcePos, game::sval_u whileSourcePos, game::scr_block_s* block, game::sval_u* whileStatBlock)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			EmitWhileStatement_hook.invoke<void>(inst, expr, stmt, sourcePos, whileSourcePos, block, whileStatBlock);
#else
			codsrc::EmitWhileStatement(inst, expr, stmt, sourcePos, whileSourcePos, block, whileStatBlock);
#endif
		}

		void Scr_CalcLocalVarsWhileStatement_stub(game::scriptInstance_t inst, game::sval_u expr, game::sval_u stmt, game::scr_block_s* block, game::sval_u* whileStatBlock)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			Scr_CalcLocalVarsWhileStatement_hook.invoke<void>(inst, expr, stmt, block, whileStatBlock);
#else
			codsrc::Scr_CalcLocalVarsWhileStatement(inst, expr, stmt, block, whileStatBlock);
#endif
		}

		void EmitForStatement_stub(game::scriptInstance_t inst, game::sval_u stmt1, game::sval_u expr, game::sval_u stmt2, game::sval_u stmt, game::sval_u sourcePos, game::sval_u forSourcePos, game::scr_block_s* block, game::sval_u* forStatBlock, game::sval_u* forStatPostBlock)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			EmitForStatement_hook.invoke<void>(inst, stmt1, expr, stmt2, stmt, sourcePos, forSourcePos, block, forStatBlock, forStatPostBlock);
#else
			codsrc::EmitForStatement(inst, stmt1, expr, stmt2, stmt, sourcePos, forSourcePos, block, forStatBlock, forStatPostBlock);
#endif
		}

		void Scr_CalcLocalVarsForStatement_stub(game::scriptInstance_t inst, game::sval_u stmt1, game::sval_u expr, game::sval_u stmt2, game::sval_u stmt, game::scr_block_s* block, game::sval_u* forStatBlock, game::sval_u* forStatPostBlock)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			Scr_CalcLocalVarsForStatement_hook.invoke<void>(inst, stmt1, expr, stmt2, stmt, block, forStatBlock, forStatPostBlock);
#else
			codsrc::Scr_CalcLocalVarsForStatement(inst, stmt1, expr, stmt2, stmt, block, forStatBlock, forStatPostBlock);
#endif
		}

		void EmitIncStatement_call(game::scr_block_s* block, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitIncStatement(block, inst, expr, sourcePos, EmitIncStatement_original);
#else
			codsrc::EmitIncStatement(block, inst, expr, sourcePos);
#endif
		}

		// void __usercall EmitIncStatement(game::scr_block_s *block@<eax>, game::scriptInstance_t inst@<edi>, game::sval_u expr, game::sval_u sourcePos)
		NAKED void EmitIncStatement_stub()
		{
			_asm
			{
				push edi;
				push eax;
				call EmitIncStatement_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitDecStatement_call(game::scr_block_s* block, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitDecStatement(block, inst, expr, sourcePos, EmitDecStatement_original);
#else
			codsrc::EmitDecStatement(block, inst, expr, sourcePos);
#endif
		}

		// void __usercall EmitDecStatement(game::scr_block_s *block@<eax>, game::scriptInstance_t inst@<edi>, game::sval_u expr, game::sval_u sourcePos)
		NAKED void EmitDecStatement_stub()
		{
			_asm
			{
				push edi;
				push eax;
				call EmitDecStatement_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_CalcLocalVarsFormalParameterListInternal_call(game::sval_u* node, game::scr_block_s* block, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::Scr_CalcLocalVarsFormalParameterListInternal(node, block, Scr_CalcLocalVarsFormalParameterListInternal_original);
#else
			codsrc::Scr_CalcLocalVarsFormalParameterListInternal(node, block);
#endif
		}

		// void __usercall Scr_CalcLocalVarsFormalParameterListInternal(game::sval_u *node@<eax>, game::scr_block_s *block@<esi>)
		NAKED void Scr_CalcLocalVarsFormalParameterListInternal_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call Scr_CalcLocalVarsFormalParameterListInternal_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitWaittillStatement_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u obj, game::sval_u exprlist, game::sval_u sourcePos, game::sval_u waitSourcePos, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitWaittillStatement(inst, obj, exprlist, sourcePos, waitSourcePos, block, EmitWaittillStatement_original);
#else
			codsrc::EmitWaittillStatement(inst, obj, exprlist, sourcePos, waitSourcePos, block);
#endif
		}

		// void __usercall EmitWaittillStatement(game::scriptInstance_t inst@<eax>, game::sval_u obj, game::sval_u exprlist, game::sval_u sourcePos, game::sval_u waitSourcePos, game::scr_block_s *block)
		NAKED void EmitWaittillStatement_stub()
		{
			_asm
			{
				push eax;
				call EmitWaittillStatement_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitWaittillmatchStatement_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u obj, game::sval_u exprlist, game::sval_u sourcePos, game::sval_u waitSourcePos, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitWaittillmatchStatement(inst, obj, exprlist, sourcePos, waitSourcePos, block, EmitWaittillmatchStatement_original);
#else
			codsrc::EmitWaittillmatchStatement(inst, obj, exprlist, sourcePos, waitSourcePos, block);
#endif
		}

		// void __usercall EmitWaittillmatchStatement(game::scriptInstance_t inst@<edi>, game::sval_u obj, game::sval_u exprlist, game::sval_u sourcePos, game::sval_u waitSourcePos, game::scr_block_s *block)
		NAKED void EmitWaittillmatchStatement_stub()
		{
			_asm
			{
				push edi;
				call EmitWaittillmatchStatement_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitNotifyStatement_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u obj, game::sval_u exprlist, game::sval_u sourcePos, game::sval_u notifySourcePos, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitNotifyStatement(inst, obj, exprlist, sourcePos, notifySourcePos, block, EmitNotifyStatement_original);
#else
			codsrc::EmitNotifyStatement(inst, obj, exprlist, sourcePos, notifySourcePos, block);
#endif
		}

		// void __usercall EmitNotifyStatement(game::scriptInstance_t inst@<edi>, game::sval_u obj, game::sval_u exprlist, game::sval_u sourcePos, game::sval_u notifySourcePos, game::scr_block_s *block)
		NAKED void EmitNotifyStatement_stub()
		{
			_asm
			{
				push edi;
				call EmitNotifyStatement_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitEndOnStatement_call(game::scr_block_s* block, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u obj, game::sval_u expr, game::sval_u sourcePos, game::sval_u exprSourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitEndOnStatement(block, inst, obj, expr, sourcePos, exprSourcePos, EmitEndOnStatement_original);
#else
			codsrc::EmitEndOnStatement(block, inst, obj, expr, sourcePos, exprSourcePos);
#endif
		}

		// void __usercall EmitEndOnStatement(game::scr_block_s *block@<eax>, game::scriptInstance_t inst@<edi>, game::sval_u obj, game::sval_u expr, game::sval_u sourcePos, game::sval_u exprSourcePos)
		NAKED void EmitEndOnStatement_stub()
		{
			_asm
			{
				push edi;
				push eax;
				call EmitEndOnStatement_call;
				add esp, 0x8;
				ret;
			}
		}

		int CompareCaseInfo_stub(const void* elem1, const void* elem2)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			return CompareCaseInfo_hook.invoke<int>(elem1, elem2);
#else
			return codsrc::CompareCaseInfo(elem1, elem2);
#endif
		}

		void EmitCaseStatement_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u expr, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitCaseStatement(inst, expr, sourcePos, EmitCaseStatement_original);
#else
			codsrc::EmitCaseStatement(inst, expr, sourcePos);
#endif
		}

		// void __usercall EmitCaseStatement(game::scriptInstance_t inst@<edi>, game::sval_u expr, game::sval_u sourcePos)
		NAKED void EmitCaseStatement_stub()
		{
			_asm
			{
				push edi;
				call EmitCaseStatement_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitSwitchStatementList_stub(game::scriptInstance_t inst, game::sval_u val, int lastStatement, unsigned int endSourcePos, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			EmitSwitchStatementList_hook.invoke<void>(inst, val, lastStatement, endSourcePos, block);
#else
			codsrc::EmitSwitchStatementList(inst, val, lastStatement, endSourcePos, block);
#endif
		}

		void Scr_CalcLocalVarsSwitchStatement_stub(game::scriptInstance_t inst, game::sval_u stmtlist, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			Scr_CalcLocalVarsSwitchStatement_hook.invoke<void>(inst, stmtlist, block);
#else
			codsrc::Scr_CalcLocalVarsSwitchStatement(inst, stmtlist, block);
#endif
		}

		void EmitSwitchStatement_stub(game::scriptInstance_t inst, game::sval_u expr, game::sval_u stmtlist, game::sval_u sourcePos, int lastStatement, unsigned int endSourcePos, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			EmitSwitchStatement_hook.invoke<void>(inst, expr, stmtlist, sourcePos, lastStatement, endSourcePos, block);
#else
			codsrc::EmitSwitchStatement(inst, expr, stmtlist, sourcePos, lastStatement, endSourcePos, block);
#endif
		}

		void EmitCaseStatementInfo_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, unsigned int name, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitCaseStatementInfo(inst, name, sourcePos, EmitCaseStatementInfo_original);
#else
			codsrc::EmitCaseStatementInfo(inst, name, sourcePos);
#endif
		}

		// void __usercall EmitCaseStatementInfo(game::scriptInstance_t inst@<eax>, unsigned int name, game::sval_u sourcePos)
		NAKED void EmitCaseStatementInfo_stub()
		{
			_asm
			{
				push eax;
				call EmitCaseStatementInfo_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitBreakStatement_call(game::scr_block_s* block, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitBreakStatement(block, inst, sourcePos, EmitBreakStatement_original);
#else
			codsrc::EmitBreakStatement(block, inst, sourcePos);
#endif
		}

		// void __usercall EmitBreakStatement(game::scr_block_s *block@<eax>, game::scriptInstance_t inst, game::sval_u sourcePos)
		NAKED void EmitBreakStatement_stub()
		{
			_asm
			{
				push eax;
				call EmitBreakStatement_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitContinueStatement_call(game::scr_block_s* block, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, game::sval_u sourcePos)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitContinueStatement(block, inst, sourcePos, EmitContinueStatement_original);
#else
			codsrc::EmitContinueStatement(block, inst, sourcePos);
#endif
		}

		// void __usercall EmitContinueStatement(game::scr_block_s *block@<eax>, game::scriptInstance_t inst, game::sval_u sourcePos)
		NAKED void EmitContinueStatement_stub()
		{
			_asm
			{
				push eax;
				call EmitContinueStatement_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitProfStatement_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u profileName, game::sval_u sourcePos, game::OpcodeVM op)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitProfStatement(inst, profileName, sourcePos, op, EmitProfStatement_original);
#else
			codsrc::EmitProfStatement(inst, profileName, sourcePos, op);
#endif
		}

		// void __usercall EmitProfStatement(game::scriptInstance_t inst@<eax>, game::sval_u profileName, game::sval_u sourcePos, game::OpcodeVM op)
		NAKED void EmitProfStatement_stub()
		{
			_asm
			{
				push eax;
				call EmitProfStatement_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitStatement_stub(game::scriptInstance_t inst, game::sval_u val, int lastStatement, unsigned int endSourcePos, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			EmitStatement_hook.invoke<void>(inst, val, lastStatement, endSourcePos, block);
#else
			codsrc::EmitStatement(inst, val, lastStatement, endSourcePos, block);
#endif
		}

		void Scr_CalcLocalVarsStatement_stub(game::scriptInstance_t inst, game::sval_u val, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			Scr_CalcLocalVarsStatement_hook.invoke<void>(inst, val, block);
#else
			codsrc::Scr_CalcLocalVarsStatement(inst, val, block);
#endif
		}

		void EmitStatementList_stub(game::scriptInstance_t inst, game::sval_u val, int lastStatement, unsigned int endSourcePos, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			EmitStatementList_hook.invoke<void>(inst, val, lastStatement, endSourcePos, block);
#else
			codsrc::EmitStatementList(inst, val, lastStatement, endSourcePos, block);
#endif
		}

		void Scr_CalcLocalVarsStatementList_call(game::scr_block_s* block, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, game::sval_u val)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::Scr_CalcLocalVarsStatementList(block, inst, val, Scr_CalcLocalVarsStatementList_original);
#else
			codsrc::Scr_CalcLocalVarsStatementList(block, inst, val);
#endif
		}

		// void __usercall Scr_CalcLocalVarsStatementList(game::scr_block_s *block@<edi>, game::scriptInstance_t inst, game::sval_u val)
		NAKED void Scr_CalcLocalVarsStatementList_stub()
		{
			_asm
			{
				push edi;
				call Scr_CalcLocalVarsStatementList_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_CalcLocalVarsDeveloperStatementList_stub(game::scriptInstance_t inst, game::sval_u val, game::scr_block_s* block, game::sval_u* devStatBlock)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			Scr_CalcLocalVarsDeveloperStatementList_hook.invoke<void>(inst, val, block, devStatBlock);
#else
			codsrc::Scr_CalcLocalVarsDeveloperStatementList(inst, val, block, devStatBlock);
#endif
		}

		void EmitDeveloperStatementList_stub(game::scriptInstance_t inst, game::sval_u val, game::sval_u sourcePos, game::scr_block_s* block, game::sval_u* devStatBlock)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			EmitDeveloperStatementList_hook.invoke<void>(inst, val, sourcePos, block, devStatBlock);
#else
			codsrc::EmitDeveloperStatementList(inst, val, sourcePos, block, devStatBlock);
#endif
		}

		void EmitFormalParameterList_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u exprlist, game::sval_u sourcePos, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitFormalParameterList(inst, exprlist, sourcePos, block, EmitFormalParameterList_original);
#else
			codsrc::EmitFormalParameterList(inst, exprlist, sourcePos, block);
#endif
		}

		// void __usercall EmitFormalParameterList(game::scriptInstance_t inst@<eax>, game::sval_u exprlist, game::sval_u sourcePos, game::scr_block_s *block)
		NAKED void EmitFormalParameterList_stub()
		{
			_asm
			{
				push eax;
				call EmitFormalParameterList_call;
				add esp, 0x4;
				ret;
			}
		}

		void SpecifyThread_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u val)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::SpecifyThread(inst, val, SpecifyThread_original);
#else
			codsrc::SpecifyThread(inst, val);
#endif
		}

		// void __usercall SpecifyThread(game::scriptInstance_t inst@<eax>, game::sval_u val)
		NAKED void SpecifyThread_stub()
		{
			_asm
			{
				push eax;
				call SpecifyThread_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitThreadInternal_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u val, game::sval_u sourcePos, game::sval_u endSourcePos, game::scr_block_s* block)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitThreadInternal(inst, val, sourcePos, endSourcePos, block, EmitThreadInternal_original);
#else
			codsrc::EmitThreadInternal(inst, val, sourcePos, endSourcePos, block);
#endif
		}

		// void __usercall EmitThreadInternal(game::scriptInstance_t inst@<esi>, game::sval_u val, game::sval_u sourcePos, game::sval_u endSourcePos, game::scr_block_s *block)
		NAKED void EmitThreadInternal_stub()
		{
			_asm
			{
				push esi;
				call EmitThreadInternal_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_CalcLocalVarsThread_call(game::sval_u* stmttblock, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, game::sval_u exprlist, game::sval_u stmtlist)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::Scr_CalcLocalVarsThread(stmttblock, inst, exprlist, stmtlist, Scr_CalcLocalVarsThread_original);
#else
			codsrc::Scr_CalcLocalVarsThread(stmttblock, inst, exprlist, stmtlist);
#endif
		}

		// void __usercall Scr_CalcLocalVarsThread(game::sval_u *stmttblock@<eax>, game::scriptInstance_t inst, game::sval_u exprlist, game::sval_u stmtlist)
		NAKED void Scr_CalcLocalVarsThread_stub()
		{
			_asm
			{
				push eax;
				call Scr_CalcLocalVarsThread_call;
				add esp, 0x4;
				ret;
			}
		}

		void InitThread_call(int type_, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::InitThread(type_, inst, InitThread_original);
#else
			codsrc::InitThread(type_, inst);
#endif
		}

		// void __usercall InitThread(int type@<ecx>, game::scriptInstance_t inst@<esi>)
		NAKED void InitThread_stub()
		{
			_asm
			{
				push esi;
				push ecx;
				call InitThread_call;
				add esp, 0x8;
				ret;
			}
		}

		void EmitNormalThread_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u val, game::sval_u* stmttblock)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitNormalThread(inst, val, stmttblock, EmitNormalThread_original);
#else
			codsrc::EmitNormalThread(inst, val, stmttblock);
#endif
		}

		// void __usercall EmitNormalThread(game::scriptInstance_t inst@<eax>, game::sval_u val, game::sval_u *stmttblock)
		NAKED void EmitNormalThread_stub()
		{
			_asm
			{
				push eax;
				call EmitNormalThread_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitDeveloperThread_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u val, game::sval_u* stmttblock)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitDeveloperThread(inst, val, stmttblock, EmitDeveloperThread_original);
#else
			codsrc::EmitDeveloperThread(inst, val, stmttblock);
#endif
		}

		// void __usercall EmitDeveloperThread(game::scriptInstance_t inst@<eax>, game::sval_u val, game::sval_u *stmttblock)
		NAKED void EmitDeveloperThread_stub()
		{
			_asm
			{
				push eax;
				call EmitDeveloperThread_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitThread_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u val)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitThread(inst, val, EmitThread_original);
#else
			codsrc::EmitThread(inst, val);
#endif
		}

		// void __usercall EmitThread(game::scriptInstance_t inst@<eax>, game::sval_u val)
		NAKED void EmitThread_stub()
		{
			_asm
			{
				push eax;
				call EmitThread_call;
				add esp, 0x4;
				ret;
			}
		}

		void EmitThreadList_stub(game::scriptInstance_t inst, game::sval_u val)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			EmitThreadList_hook.invoke<void>(inst, val);
#else
			codsrc::EmitThreadList(inst, val);
#endif
		}

		void EmitInclude_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u val)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::EmitInclude(inst, val, EmitInclude_original);
#else
			codsrc::EmitInclude(inst, val);
#endif
		}

		// void __usercall EmitInclude(game::scriptInstance_t inst@<eax>, game::sval_u val)
		NAKED void EmitInclude_stub()
		{
			_asm
			{
				push eax;
				call EmitInclude_call;
				add esp, 0x4;
				ret;
			}
		}

		void ScriptCompile_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::sval_u val, unsigned int filePosId, unsigned int fileCountId, unsigned int scriptId, game::PrecacheEntry* entries, int entriesCount)
		{
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			game::ScriptCompile(inst, val, filePosId, fileCountId, scriptId, entries, entriesCount, ScriptCompile_original);
#else
			codsrc::ScriptCompile(inst, val, filePosId, fileCountId, scriptId, entries, entriesCount);
#endif
		}

		// void __usercall ScriptCompile(game::scriptInstance_t inst@<eax>, game::sval_u val, unsigned int filePosId, unsigned int fileCountId, unsigned int scriptId, game::PrecacheEntry *entries, int entriesCount)
		NAKED void ScriptCompile_stub()
		{
			_asm
			{
				push eax;
				call ScriptCompile_call;
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
			bool quick = true;
#ifdef RE_CSCR_COMPILER_USE_WRAPPERS
			quick = false;
#endif

			RemoveRefToValue_hook.create(game::RemoveRefToValue.get(), RemoveRefToValue_stub, quick);
			Scr_CompileRemoveRefToString_hook.create(game::Scr_CompileRemoveRefToString_ADDR(), Scr_CompileRemoveRefToString_stub, quick);
			EmitCanonicalString_hook.create(game::EmitCanonicalString_ADDR(), EmitCanonicalString_stub, quick);
			CompileTransferRefToString_hook.create(game::CompileTransferRefToString_ADDR(), CompileTransferRefToString_stub, quick);
			EmitOpcode_hook.create(game::EmitOpcode.get(), EmitOpcode_stub, quick);
			EmitEnd_hook.create(game::EmitEnd_ADDR(), EmitEnd_stub, quick);
			EmitReturn_hook.create(game::EmitReturn_ADDR(), EmitReturn_stub, quick);
			EmitCodepos_hook.create(game::EmitCodepos_ADDR(), EmitCodepos_stub, quick);
			EmitShort_hook.create(game::EmitShort_ADDR(), EmitShort_stub, quick);
			EmitByte_hook.create(game::EmitByte_ADDR(), EmitByte_stub, quick);
			EmitGetInteger_hook.create(game::EmitGetInteger_ADDR(), EmitGetInteger_stub, quick);
			EmitGetFloat_hook.create(game::EmitGetFloat_ADDR(), EmitGetFloat_stub, quick);
			EmitAnimTree_hook.create(game::EmitAnimTree_ADDR(), EmitAnimTree_stub, quick);
			Scr_FindLocalVarIndex_hook.create(game::Scr_FindLocalVarIndex.get(), Scr_FindLocalVarIndex_stub, quick);
			EmitCreateLocalVars_hook.create(game::EmitCreateLocalVars.get(), EmitCreateLocalVars_stub, quick);
			EmitRemoveLocalVars_hook.create(game::EmitRemoveLocalVars_ADDR(), EmitRemoveLocalVars_stub, quick);
			EmitNOP2_hook.create(game::EmitNOP2_ADDR(), EmitNOP2_stub, quick);
			Scr_InitFromChildBlocks_hook.create(game::Scr_InitFromChildBlocks.get(), Scr_InitFromChildBlocks_stub, quick);
			Scr_AppendChildBlocks_hook.create(game::Scr_AppendChildBlocks_ADDR(), Scr_AppendChildBlocks_stub, quick);
			Scr_MergeChildBlocks_hook.create(game::Scr_MergeChildBlocks.get(), Scr_MergeChildBlocks_stub, quick);
			Scr_TransferBlock_hook.create(game::Scr_TransferBlock_ADDR(), Scr_TransferBlock_stub, quick);
			EmitSafeSetVariableField_hook.create(game::EmitSafeSetVariableField_ADDR(), EmitSafeSetVariableField_stub, quick);
			EmitSafeSetWaittillVariableField_hook.create(game::EmitSafeSetWaittillVariableField_ADDR(), EmitSafeSetWaittillVariableField_stub, quick);
			EmitGetString_hook.create(game::EmitGetString_ADDR(), EmitGetString_stub, quick);
			EmitGetIString_hook.create(game::EmitGetIString_ADDR(), EmitGetIString_stub, quick);
			EmitGetVector_hook.create(game::EmitGetVector_ADDR(), EmitGetVector_stub, quick);
			EmitValue_hook.create(game::EmitValue.get(), EmitValue_stub, quick);
			Scr_PushValue_hook.create(game::Scr_PushValue_ADDR(), Scr_PushValue_stub, quick);
			EmitCastBool_hook.create(game::EmitCastBool_ADDR(), EmitCastBool_stub, quick);
			EmitBoolNot_hook.create(game::EmitBoolNot_ADDR(), EmitBoolNot_stub, quick);
			EmitBoolComplement_hook.create(game::EmitBoolComplement_ADDR(), EmitBoolComplement_stub, quick);
			EmitSize_hook.create(game::EmitSize_ADDR(), EmitSize_stub, quick);
			EmitSelf_hook.create(game::EmitSelf_ADDR(), EmitSelf_stub, quick);
			EmitLevel_hook.create(game::EmitLevel_ADDR(), EmitLevel_stub, quick);
			EmitGame_hook.create(game::EmitGame_ADDR(), EmitGame_stub, quick);
			EmitAnim_hook.create(game::EmitAnim_ADDR(), EmitAnim_stub, quick);
			EmitSelfObject_hook.create(game::EmitSelfObject_ADDR(), EmitSelfObject_stub, quick);
			EmitLevelObject_hook.create(game::EmitLevelObject_ADDR(), EmitLevelObject_stub, quick);
			EmitAnimObject_hook.create(game::EmitAnimObject_ADDR(), EmitAnimObject_stub, quick);
			EmitLocalVariable_hook.create(game::EmitLocalVariable_ADDR(), EmitLocalVariable_stub, quick);
			EmitLocalVariableRef_hook.create(game::EmitLocalVariableRef_ADDR(), EmitLocalVariableRef_stub, quick);
			Scr_RegisterLocalVar_hook.create(game::Scr_RegisterLocalVar.get(), Scr_RegisterLocalVar_stub, quick);
			EmitGameRef_hook.create(game::EmitGameRef_ADDR(), EmitGameRef_stub, quick);
			EmitClearArray_hook.create(game::EmitClearArray_ADDR(), EmitClearArray_stub, quick);
			EmitEmptyArray_hook.create(game::EmitEmptyArray_ADDR(), EmitEmptyArray_stub, quick);
			EmitAnimation_hook.create(game::EmitAnimation_ADDR(), EmitAnimation_stub, quick);
			EmitFieldVariable_hook.create(game::EmitFieldVariable_ADDR(), EmitFieldVariable_stub, quick);
			EmitClearFieldVariable_hook.create(game::EmitClearFieldVariable_ADDR(), EmitClearFieldVariable_stub, quick);
			EmitObject_hook.create(game::EmitObject_ADDR(), EmitObject_stub, quick);
			EmitDecTop_hook.create(game::EmitDecTop_ADDR(), EmitDecTop_stub, quick);
			EmitCastFieldObject_hook.create(game::EmitCastFieldObject.get(), EmitCastFieldObject_stub, quick);
			EmitArrayVariable_hook.create(game::EmitArrayVariable_ADDR(), EmitArrayVariable_stub, quick);
			EmitArrayVariableRef_hook.create(game::EmitArrayVariableRef_ADDR(), EmitArrayVariableRef_stub, quick);
			EmitClearArrayVariable_hook.create(game::EmitClearArrayVariable_ADDR(), EmitClearArrayVariable_stub, quick);
			EmitVariableExpression_hook.create(game::EmitVariableExpression.get(), EmitVariableExpression_stub, quick);
			EmitExpressionList_hook.create(game::EmitExpressionList.get(), EmitExpressionList_stub, quick);
			AddExpressionListOpcodePos_hook.create(game::AddExpressionListOpcodePos_ADDR(), AddExpressionListOpcodePos_stub, quick);
			AddFilePrecache_hook.create(game::AddFilePrecache_ADDR(), AddFilePrecache_stub, quick);
			EmitFunction_hook.create(game::EmitFunction_ADDR(), EmitFunction_stub, quick);
			EmitGetFunction_hook.create(game::EmitGetFunction_ADDR(), EmitGetFunction_stub, quick);
			AddFunction_hook.create(game::AddFunction.get(), AddFunction_stub, quick);
			EmitPostScriptFunction_hook.create(game::EmitPostScriptFunction.get(), EmitPostScriptFunction_stub, quick);
			EmitPostScriptFunctionPointer_hook.create(game::EmitPostScriptFunctionPointer_ADDR(), EmitPostScriptFunctionPointer_stub, quick);
			EmitPostScriptThread_hook.create(game::EmitPostScriptThread_ADDR(), EmitPostScriptThread_stub, quick);
			EmitPostScriptThreadPointer_hook.create(game::EmitPostScriptThreadPointer_ADDR(), EmitPostScriptThreadPointer_stub, quick);
			EmitPostScriptFunctionCall_hook.create(game::EmitPostScriptFunctionCall_ADDR(), EmitPostScriptFunctionCall_stub, quick);
			EmitPostScriptThreadCall_hook.create(game::EmitPostScriptThreadCall_ADDR(), EmitPostScriptThreadCall_stub, quick);
			EmitPreFunctionCall_hook.create(game::EmitPreFunctionCall_ADDR(), EmitPreFunctionCall_stub, quick);
			EmitPostFunctionCall_hook.create(game::EmitPostFunctionCall_ADDR(), EmitPostFunctionCall_stub, quick);
			Scr_BeginDevScript_hook.create(game::Scr_BeginDevScript_ADDR(), Scr_BeginDevScript_stub, quick);
			Scr_EndDevScript_hook.create(game::Scr_EndDevScript_ADDR(), Scr_EndDevScript_stub, quick);
			EmitCallBuiltinOpcode_hook.create(game::EmitCallBuiltinOpcode_ADDR(), EmitCallBuiltinOpcode_stub, quick);
			EmitCallBuiltinMethodOpcode_hook.create(game::EmitCallBuiltinMethodOpcode_ADDR(), EmitCallBuiltinMethodOpcode_stub, quick);
			EmitCall_hook.create(game::EmitCall_ADDR(), EmitCall_stub, quick);
			EmitMethod_hook.create(game::EmitMethod.get(), EmitMethod_stub, quick);
			LinkThread_hook.create(game::LinkThread_ADDR(), LinkThread_stub, quick);
			LinkFile_hook.create(game::LinkFile_ADDR(), LinkFile_stub, quick);
			CheckThreadPosition_hook.create(game::CheckThreadPosition.get(), CheckThreadPosition_stub, quick);
			EmitCallExpression_hook.create(game::EmitCallExpression_ADDR(), EmitCallExpression_stub, quick);
			EmitCallExpressionFieldObject_hook.create(game::EmitCallExpressionFieldObject_ADDR(), EmitCallExpressionFieldObject_stub, quick);
			Scr_CreateVector_hook.create(game::Scr_CreateVector_ADDR(), Scr_CreateVector_stub, quick);
			EvalPrimitiveExpressionList_hook.create(game::EvalPrimitiveExpressionList.get(), EvalPrimitiveExpressionList_stub, quick);
			EmitOrEvalPrimitiveExpressionList_hook.create(game::EmitOrEvalPrimitiveExpressionList_ADDR(), EmitOrEvalPrimitiveExpressionList_stub, quick);
			EmitExpressionListFieldObject_hook.create(game::EmitExpressionListFieldObject_ADDR(), EmitExpressionListFieldObject_stub, quick);
			EvalPrimitiveExpression_hook.create(game::EvalPrimitiveExpression.get(), EvalPrimitiveExpression_stub, quick);
			EmitOrEvalPrimitiveExpression_hook.create(game::EmitOrEvalPrimitiveExpression.get(), EmitOrEvalPrimitiveExpression_stub, quick);
			EmitBoolOrExpression_hook.create(game::EmitBoolOrExpression_ADDR(), EmitBoolOrExpression_stub, quick);
			EmitBoolAndExpression_hook.create(game::EmitBoolAndExpression_ADDR(), EmitBoolAndExpression_stub, quick);
			EvalBinaryOperatorExpression_hook.create(game::EvalBinaryOperatorExpression.get(), EvalBinaryOperatorExpression_stub, quick);
			EmitOrEvalBinaryOperatorExpression_hook.create(game::EmitOrEvalBinaryOperatorExpression_ADDR(), EmitOrEvalBinaryOperatorExpression_stub, quick);
			EmitBinaryEqualsOperatorExpression_hook.create(game::EmitBinaryEqualsOperatorExpression_ADDR(), EmitBinaryEqualsOperatorExpression_stub, quick);
			Scr_CalcLocalVarsVariableExpressionRef_hook.create(game::Scr_CalcLocalVarsVariableExpressionRef_ADDR(), Scr_CalcLocalVarsVariableExpressionRef_stub, quick);
			EvalExpression_hook.create(game::EvalExpression_ADDR(), EvalExpression_stub, quick);
			EmitOrEvalExpression_hook.create(game::EmitOrEvalExpression.get(), EmitOrEvalExpression_stub, quick);
			EmitExpression_hook.create(game::EmitExpression.get(), EmitExpression_stub, quick);
			EmitVariableExpressionRef_hook.create(game::EmitVariableExpressionRef.get(), EmitVariableExpressionRef_stub, quick);
			EmitArrayPrimitiveExpressionRef_hook.create(game::EmitArrayPrimitiveExpressionRef_ADDR(), EmitArrayPrimitiveExpressionRef_stub, quick);
			Scr_CalcLocalVarsArrayVariableRef_hook.create(game::Scr_CalcLocalVarsArrayVariableRef.get(), Scr_CalcLocalVarsArrayVariableRef_stub, quick);
			EmitPrimitiveExpressionFieldObject_hook.create(game::EmitPrimitiveExpressionFieldObject.get(), EmitPrimitiveExpressionFieldObject_stub, quick);
			ConnectBreakStatements_hook.create(game::ConnectBreakStatements_ADDR(), ConnectBreakStatements_stub, quick);
			ConnectContinueStatements_hook.create(game::ConnectContinueStatements_ADDR(), ConnectContinueStatements_stub, quick);
			EmitClearVariableExpression_hook.create(game::EmitClearVariableExpression_ADDR(), EmitClearVariableExpression_stub, quick);
			EmitAssignmentStatement_hook.create(game::EmitAssignmentStatement_ADDR(), EmitAssignmentStatement_stub, quick);
			EmitCallExpressionStatement_hook.create(game::EmitCallExpressionStatement_ADDR(), EmitCallExpressionStatement_stub, quick);
			EmitReturnStatement_hook.create(game::EmitReturnStatement_ADDR(), EmitReturnStatement_stub, quick);
			EmitWaitStatement_hook.create(game::EmitWaitStatement_ADDR(), EmitWaitStatement_stub, quick);
			EmitWaittillFrameEnd_hook.create(game::EmitWaittillFrameEnd_ADDR(), EmitWaittillFrameEnd_stub, quick);
			EmitIfStatement_hook.create(game::EmitIfStatement_ADDR(), EmitIfStatement_stub, quick);
			Scr_CalcLocalVarsIfStatement_hook.create(game::Scr_CalcLocalVarsIfStatement.get(), Scr_CalcLocalVarsIfStatement_stub, quick);
			EmitIfElseStatement_hook.create(game::EmitIfElseStatement.get(), EmitIfElseStatement_stub, quick);
			Scr_CalcLocalVarsIfElseStatement_hook.create(game::Scr_CalcLocalVarsIfElseStatement.get(), Scr_CalcLocalVarsIfElseStatement_stub, quick);
			Scr_AddBreakBlock_hook.create(game::Scr_AddBreakBlock_ADDR(), Scr_AddBreakBlock_stub, quick);
			Scr_AddContinueBlock_hook.create(game::Scr_AddContinueBlock_ADDR(), Scr_AddContinueBlock_stub, quick);
			EmitWhileStatement_hook.create(game::EmitWhileStatement.get(), EmitWhileStatement_stub, quick);
			Scr_CalcLocalVarsWhileStatement_hook.create(game::Scr_CalcLocalVarsWhileStatement.get(), Scr_CalcLocalVarsWhileStatement_stub, quick);
			EmitForStatement_hook.create(game::EmitForStatement.get(), EmitForStatement_stub, quick);
			Scr_CalcLocalVarsForStatement_hook.create(game::Scr_CalcLocalVarsForStatement.get(), Scr_CalcLocalVarsForStatement_stub, quick);
			EmitIncStatement_hook.create(game::EmitIncStatement_ADDR(), EmitIncStatement_stub, quick);
			EmitDecStatement_hook.create(game::EmitDecStatement_ADDR(), EmitDecStatement_stub, quick);
			Scr_CalcLocalVarsFormalParameterListInternal_hook.create(game::Scr_CalcLocalVarsFormalParameterListInternal_ADDR(), Scr_CalcLocalVarsFormalParameterListInternal_stub, quick);
			EmitWaittillStatement_hook.create(game::EmitWaittillStatement_ADDR(), EmitWaittillStatement_stub, quick);
			EmitWaittillmatchStatement_hook.create(game::EmitWaittillmatchStatement_ADDR(), EmitWaittillmatchStatement_stub, quick);
			EmitNotifyStatement_hook.create(game::EmitNotifyStatement_ADDR(), EmitNotifyStatement_stub, quick);
			EmitEndOnStatement_hook.create(game::EmitEndOnStatement_ADDR(), EmitEndOnStatement_stub, quick);
			CompareCaseInfo_hook.create(game::CompareCaseInfo.get(), CompareCaseInfo_stub, quick);
			EmitCaseStatement_hook.create(game::EmitCaseStatement_ADDR(), EmitCaseStatement_stub, quick);
			EmitSwitchStatementList_hook.create(game::EmitSwitchStatementList.get(), EmitSwitchStatementList_stub, quick);
			Scr_CalcLocalVarsSwitchStatement_hook.create(game::Scr_CalcLocalVarsSwitchStatement.get(), Scr_CalcLocalVarsSwitchStatement_stub, quick);
			EmitSwitchStatement_hook.create(game::EmitSwitchStatement.get(), EmitSwitchStatement_stub, quick);
			EmitCaseStatementInfo_hook.create(game::EmitCaseStatementInfo_ADDR(), EmitCaseStatementInfo_stub, quick);
			EmitBreakStatement_hook.create(game::EmitBreakStatement_ADDR(), EmitBreakStatement_stub, quick);
			EmitContinueStatement_hook.create(game::EmitContinueStatement_ADDR(), EmitContinueStatement_stub, quick);
			EmitProfStatement_hook.create(game::EmitProfStatement_ADDR(), EmitProfStatement_stub, quick);
			EmitStatement_hook.create(game::EmitStatement.get(), EmitStatement_stub, quick);
			Scr_CalcLocalVarsStatement_hook.create(game::Scr_CalcLocalVarsStatement.get(), Scr_CalcLocalVarsStatement_stub, quick);
			EmitStatementList_hook.create(game::EmitStatementList.get(), EmitStatementList_stub, quick);
			Scr_CalcLocalVarsStatementList_hook.create(game::Scr_CalcLocalVarsStatementList_ADDR(), Scr_CalcLocalVarsStatementList_stub, quick);
			Scr_CalcLocalVarsDeveloperStatementList_hook.create(game::Scr_CalcLocalVarsDeveloperStatementList.get(), Scr_CalcLocalVarsDeveloperStatementList_stub, quick);
			EmitDeveloperStatementList_hook.create(game::EmitDeveloperStatementList.get(), EmitDeveloperStatementList_stub, quick);
			EmitFormalParameterList_hook.create(game::EmitFormalParameterList_ADDR(), EmitFormalParameterList_stub, quick);
			SpecifyThread_hook.create(game::SpecifyThread_ADDR(), SpecifyThread_stub, quick);
			EmitThreadInternal_hook.create(game::EmitThreadInternal_ADDR(), EmitThreadInternal_stub, quick);
			Scr_CalcLocalVarsThread_hook.create(game::Scr_CalcLocalVarsThread_ADDR(), Scr_CalcLocalVarsThread_stub, quick);
			InitThread_hook.create(game::InitThread_ADDR(), InitThread_stub, quick);
			EmitNormalThread_hook.create(game::EmitNormalThread_ADDR(), EmitNormalThread_stub, quick);
			EmitDeveloperThread_hook.create(game::EmitDeveloperThread_ADDR(), EmitDeveloperThread_stub, quick);
			EmitThread_hook.create(game::EmitThread_ADDR(), EmitThread_stub, quick);
			EmitThreadList_hook.create(game::EmitThreadList.get(), EmitThreadList_stub, quick);
			EmitInclude_hook.create(game::EmitInclude_ADDR(), EmitInclude_stub, quick);
			ScriptCompile_hook.create(game::ScriptCompile_ADDR(), ScriptCompile_stub, quick);

			//Original hook function addresses
			RemoveRefToValue_original = RemoveRefToValue_hook.get_original();
			Scr_CompileRemoveRefToString_original = Scr_CompileRemoveRefToString_hook.get_original();
			EmitCanonicalString_original = EmitCanonicalString_hook.get_original();
			CompileTransferRefToString_original = CompileTransferRefToString_hook.get_original();
			EmitOpcode_original = EmitOpcode_hook.get_original();
			EmitEnd_original = EmitEnd_hook.get_original();
			EmitReturn_original = EmitReturn_hook.get_original();
			EmitCodepos_original = EmitCodepos_hook.get_original();
			EmitShort_original = EmitShort_hook.get_original();
			EmitByte_original = EmitByte_hook.get_original();
			EmitGetInteger_original = EmitGetInteger_hook.get_original();
			EmitGetFloat_original = EmitGetFloat_hook.get_original();
			EmitAnimTree_original = EmitAnimTree_hook.get_original();
			Scr_FindLocalVarIndex_original = Scr_FindLocalVarIndex_hook.get_original();
			EmitCreateLocalVars_original = EmitCreateLocalVars_hook.get_original();
			EmitRemoveLocalVars_original = EmitRemoveLocalVars_hook.get_original();
			EmitNOP2_original = EmitNOP2_hook.get_original();
			Scr_InitFromChildBlocks_original = Scr_InitFromChildBlocks_hook.get_original();
			Scr_AppendChildBlocks_original = Scr_AppendChildBlocks_hook.get_original();
			Scr_MergeChildBlocks_original = Scr_MergeChildBlocks_hook.get_original();
			Scr_TransferBlock_original = Scr_TransferBlock_hook.get_original();
			EmitSafeSetVariableField_original = EmitSafeSetVariableField_hook.get_original();
			EmitSafeSetWaittillVariableField_original = EmitSafeSetWaittillVariableField_hook.get_original();
			EmitGetString_original = EmitGetString_hook.get_original();
			EmitGetIString_original = EmitGetIString_hook.get_original();
			EmitGetVector_original = EmitGetVector_hook.get_original();
			EmitValue_original = EmitValue_hook.get_original();
			Scr_PushValue_original = Scr_PushValue_hook.get_original();
			EmitCastBool_original = EmitCastBool_hook.get_original();
			EmitBoolNot_original = EmitBoolNot_hook.get_original();
			EmitBoolComplement_original = EmitBoolComplement_hook.get_original();
			EmitSize_original = EmitSize_hook.get_original();
			EmitSelf_original = EmitSelf_hook.get_original();
			EmitLevel_original = EmitLevel_hook.get_original();
			EmitGame_original = EmitGame_hook.get_original();
			EmitAnim_original = EmitAnim_hook.get_original();
			EmitSelfObject_original = EmitSelfObject_hook.get_original();
			EmitLevelObject_original = EmitLevelObject_hook.get_original();
			EmitAnimObject_original = EmitAnimObject_hook.get_original();
			EmitLocalVariable_original = EmitLocalVariable_hook.get_original();
			EmitLocalVariableRef_original = EmitLocalVariableRef_hook.get_original();
			Scr_RegisterLocalVar_original = Scr_RegisterLocalVar_hook.get_original();
			EmitGameRef_original = EmitGameRef_hook.get_original();
			EmitClearArray_original = EmitClearArray_hook.get_original();
			EmitEmptyArray_original = EmitEmptyArray_hook.get_original();
			EmitAnimation_original = EmitAnimation_hook.get_original();
			EmitFieldVariable_original = EmitFieldVariable_hook.get_original();
			EmitClearFieldVariable_original = EmitClearFieldVariable_hook.get_original();
			EmitObject_original = EmitObject_hook.get_original();
			EmitDecTop_original = EmitDecTop_hook.get_original();
			EmitCastFieldObject_original = EmitCastFieldObject_hook.get_original();
			EmitArrayVariable_original = EmitArrayVariable_hook.get_original();
			EmitArrayVariableRef_original = EmitArrayVariableRef_hook.get_original();
			EmitClearArrayVariable_original = EmitClearArrayVariable_hook.get_original();
			EmitVariableExpression_original = EmitVariableExpression_hook.get_original();
			EmitExpressionList_original = EmitExpressionList_hook.get_original();
			AddExpressionListOpcodePos_original = AddExpressionListOpcodePos_hook.get_original();
			AddFilePrecache_original = AddFilePrecache_hook.get_original();
			EmitFunction_original = EmitFunction_hook.get_original();
			EmitGetFunction_original = EmitGetFunction_hook.get_original();
			AddFunction_original = AddFunction_hook.get_original();
			EmitPostScriptFunction_original = EmitPostScriptFunction_hook.get_original();
			EmitPostScriptFunctionPointer_original = EmitPostScriptFunctionPointer_hook.get_original();
			EmitPostScriptThread_original = EmitPostScriptThread_hook.get_original();
			EmitPostScriptThreadPointer_original = EmitPostScriptThreadPointer_hook.get_original();
			EmitPostScriptFunctionCall_original = EmitPostScriptFunctionCall_hook.get_original();
			EmitPostScriptThreadCall_original = EmitPostScriptThreadCall_hook.get_original();
			EmitPreFunctionCall_original = EmitPreFunctionCall_hook.get_original();
			EmitPostFunctionCall_original = EmitPostFunctionCall_hook.get_original();
			Scr_BeginDevScript_original = Scr_BeginDevScript_hook.get_original();
			Scr_EndDevScript_original = Scr_EndDevScript_hook.get_original();
			EmitCallBuiltinOpcode_original = EmitCallBuiltinOpcode_hook.get_original();
			EmitCallBuiltinMethodOpcode_original = EmitCallBuiltinMethodOpcode_hook.get_original();
			EmitCall_original = EmitCall_hook.get_original();
			EmitMethod_original = EmitMethod_hook.get_original();
			LinkThread_original = LinkThread_hook.get_original();
			LinkFile_original = LinkFile_hook.get_original();
			CheckThreadPosition_original = CheckThreadPosition_hook.get_original();
			EmitCallExpression_original = EmitCallExpression_hook.get_original();
			EmitCallExpressionFieldObject_original = EmitCallExpressionFieldObject_hook.get_original();
			Scr_CreateVector_original = Scr_CreateVector_hook.get_original();
			EvalPrimitiveExpressionList_original = EvalPrimitiveExpressionList_hook.get_original();
			EmitOrEvalPrimitiveExpressionList_original = EmitOrEvalPrimitiveExpressionList_hook.get_original();
			EmitExpressionListFieldObject_original = EmitExpressionListFieldObject_hook.get_original();
			EvalPrimitiveExpression_original = EvalPrimitiveExpression_hook.get_original();
			EmitOrEvalPrimitiveExpression_original = EmitOrEvalPrimitiveExpression_hook.get_original();
			EmitBoolOrExpression_original = EmitBoolOrExpression_hook.get_original();
			EmitBoolAndExpression_original = EmitBoolAndExpression_hook.get_original();
			EvalBinaryOperatorExpression_original = EvalBinaryOperatorExpression_hook.get_original();
			EmitOrEvalBinaryOperatorExpression_original = EmitOrEvalBinaryOperatorExpression_hook.get_original();
			EmitBinaryEqualsOperatorExpression_original = EmitBinaryEqualsOperatorExpression_hook.get_original();
			Scr_CalcLocalVarsVariableExpressionRef_original = Scr_CalcLocalVarsVariableExpressionRef_hook.get_original();
			EvalExpression_original = EvalExpression_hook.get_original();
			EmitOrEvalExpression_original = EmitOrEvalExpression_hook.get_original();
			EmitExpression_original = EmitExpression_hook.get_original();
			EmitVariableExpressionRef_original = EmitVariableExpressionRef_hook.get_original();
			EmitArrayPrimitiveExpressionRef_original = EmitArrayPrimitiveExpressionRef_hook.get_original();
			Scr_CalcLocalVarsArrayVariableRef_original = Scr_CalcLocalVarsArrayVariableRef_hook.get_original();
			EmitPrimitiveExpressionFieldObject_original = EmitPrimitiveExpressionFieldObject_hook.get_original();
			ConnectBreakStatements_original = ConnectBreakStatements_hook.get_original();
			ConnectContinueStatements_original = ConnectContinueStatements_hook.get_original();
			EmitClearVariableExpression_original = EmitClearVariableExpression_hook.get_original();
			EmitAssignmentStatement_original = EmitAssignmentStatement_hook.get_original();
			EmitCallExpressionStatement_original = EmitCallExpressionStatement_hook.get_original();
			EmitReturnStatement_original = EmitReturnStatement_hook.get_original();
			EmitWaitStatement_original = EmitWaitStatement_hook.get_original();
			EmitWaittillFrameEnd_original = EmitWaittillFrameEnd_hook.get_original();
			EmitIfStatement_original = EmitIfStatement_hook.get_original();
			Scr_CalcLocalVarsIfStatement_original = Scr_CalcLocalVarsIfStatement_hook.get_original();
			EmitIfElseStatement_original = EmitIfElseStatement_hook.get_original();
			Scr_CalcLocalVarsIfElseStatement_original = Scr_CalcLocalVarsIfElseStatement_hook.get_original();
			Scr_AddBreakBlock_original = Scr_AddBreakBlock_hook.get_original();
			Scr_AddContinueBlock_original = Scr_AddContinueBlock_hook.get_original();
			EmitWhileStatement_original = EmitWhileStatement_hook.get_original();
			Scr_CalcLocalVarsWhileStatement_original = Scr_CalcLocalVarsWhileStatement_hook.get_original();
			EmitForStatement_original = EmitForStatement_hook.get_original();
			Scr_CalcLocalVarsForStatement_original = Scr_CalcLocalVarsForStatement_hook.get_original();
			EmitIncStatement_original = EmitIncStatement_hook.get_original();
			EmitDecStatement_original = EmitDecStatement_hook.get_original();
			Scr_CalcLocalVarsFormalParameterListInternal_original = Scr_CalcLocalVarsFormalParameterListInternal_hook.get_original();
			EmitWaittillStatement_original = EmitWaittillStatement_hook.get_original();
			EmitWaittillmatchStatement_original = EmitWaittillmatchStatement_hook.get_original();
			EmitNotifyStatement_original = EmitNotifyStatement_hook.get_original();
			EmitEndOnStatement_original = EmitEndOnStatement_hook.get_original();
			CompareCaseInfo_original = CompareCaseInfo_hook.get_original();
			EmitCaseStatement_original = EmitCaseStatement_hook.get_original();
			EmitSwitchStatementList_original = EmitSwitchStatementList_hook.get_original();
			Scr_CalcLocalVarsSwitchStatement_original = Scr_CalcLocalVarsSwitchStatement_hook.get_original();
			EmitSwitchStatement_original = EmitSwitchStatement_hook.get_original();
			EmitCaseStatementInfo_original = EmitCaseStatementInfo_hook.get_original();
			EmitBreakStatement_original = EmitBreakStatement_hook.get_original();
			EmitContinueStatement_original = EmitContinueStatement_hook.get_original();
			EmitProfStatement_original = EmitProfStatement_hook.get_original();
			EmitStatement_original = EmitStatement_hook.get_original();
			Scr_CalcLocalVarsStatement_original = Scr_CalcLocalVarsStatement_hook.get_original();
			EmitStatementList_original = EmitStatementList_hook.get_original();
			Scr_CalcLocalVarsStatementList_original = Scr_CalcLocalVarsStatementList_hook.get_original();
			Scr_CalcLocalVarsDeveloperStatementList_original = Scr_CalcLocalVarsDeveloperStatementList_hook.get_original();
			EmitDeveloperStatementList_original = EmitDeveloperStatementList_hook.get_original();
			EmitFormalParameterList_original = EmitFormalParameterList_hook.get_original();
			SpecifyThread_original = SpecifyThread_hook.get_original();
			EmitThreadInternal_original = EmitThreadInternal_hook.get_original();
			Scr_CalcLocalVarsThread_original = Scr_CalcLocalVarsThread_hook.get_original();
			InitThread_original = InitThread_hook.get_original();
			EmitNormalThread_original = EmitNormalThread_hook.get_original();
			EmitDeveloperThread_original = EmitDeveloperThread_hook.get_original();
			EmitThread_original = EmitThread_hook.get_original();
			EmitThreadList_original = EmitThreadList_hook.get_original();
			EmitInclude_original = EmitInclude_hook.get_original();
			ScriptCompile_original = ScriptCompile_hook.get_original();
		}

	private:
	};
}
REGISTER_COMPONENT(re_cscr_compiler::component)
#endif
