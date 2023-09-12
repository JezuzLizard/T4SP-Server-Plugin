#pragma once

namespace game
{
	WEAK symbol<void(scriptInstance_t inst, VariableValue* value)>RemoveRefToValue{ 0x0, 0x67EB70 };
	WEAK symbol<void(scriptInstance_t inst, OpcodeVM op, int offset, int callType)>EmitOpcode{ 0x0, 0x67ECA0 };
	WEAK symbol<int(scriptInstance_t inst, unsigned int name, sval_u sourcePos, int create, scr_block_s* block)>Scr_FindLocalVarIndex{ 0x0, 0x67F500 };
	WEAK symbol<void(scriptInstance_t inst, scr_block_s* block)>EmitCreateLocalVars{ 0x0, 0x67F730 };
	WEAK symbol<void(scr_block_s** childBlocks, int childCount, scr_block_s* block)>Scr_InitFromChildBlocks{ 0x0, 0x67FA00 };
	WEAK symbol<void(scr_block_s** childBlocks, int childCount, scr_block_s* block)>Scr_MergeChildBlocks{ 0x0, 0x67FB80 };
	WEAK symbol<void(scriptInstance_t inst, VariableCompileValue* constValue)>EmitValue{ 0x0, 0x680050 };
	WEAK symbol<void(unsigned int name, sval_u sourcePos, scr_block_s* block)>Scr_RegisterLocalVar{ 0x0, 0x680D10 };
	WEAK symbol<void(scriptInstance_t inst, sval_u sourcePos)>EmitCastFieldObject{ 0x0, 0x681720 };
	WEAK symbol<void(scriptInstance_t inst, sval_u expr, scr_block_s* block)>EmitVariableExpression{ 0x0, 0x681990 };
	WEAK symbol<int(scriptInstance_t inst, sval_u exprlist, scr_block_s* block)>EmitExpressionList{ 0x0, 0x681AD0 };
	WEAK symbol<int(scriptInstance_t inst, int func)>AddFunction{ 0x0, 0x682040 };
	WEAK symbol<void(scriptInstance_t inst, sval_u func, int param_count, int bMethod, sval_u nameSourcePos)>EmitPostScriptFunction{ 0x0, 0x6820B0 };
	WEAK symbol<void(scriptInstance_t inst, sval_u expr, sval_u func_name, sval_u params, sval_u methodSourcePos, int bStatement, scr_block_s* block)>EmitMethod{ 0x0, 0x682F40 };
	WEAK symbol<void(scriptInstance_t inst, unsigned int posId, unsigned int name, unsigned int sourcePos)>CheckThreadPosition{ 0x0, 0x683580 };
	WEAK symbol<bool(scriptInstance_t inst, sval_u exprlist, sval_u sourcePos, VariableCompileValue* constValue)>EvalPrimitiveExpressionList{ 0x0, 0x6837C0 };
	WEAK symbol<bool(scriptInstance_t inst, sval_u expr, VariableCompileValue* constValue)>EvalPrimitiveExpression{ 0x0, 0x683B50 };
	WEAK symbol<bool(scriptInstance_t inst, sval_u expr, VariableCompileValue* constValue, scr_block_s* block)>EmitOrEvalPrimitiveExpression{ 0x0, 0x683CF0 };
	WEAK symbol<bool(scriptInstance_t inst, sval_u expr1, sval_u expr2, sval_u opcode, sval_u sourcePos, VariableCompileValue* constValue)>EvalBinaryOperatorExpression{ 0x0, 0x684220 };
	WEAK symbol<bool(scriptInstance_t inst, sval_u expr, VariableCompileValue* constValue, scr_block_s* block)>EmitOrEvalExpression{ 0x0, 0x684590 };
	WEAK symbol<void(scriptInstance_t inst, sval_u expr, scr_block_s* block)>EmitExpression{ 0x0, 0x684750 };
	WEAK symbol<void(sval_u expr, scr_block_s* block)>Scr_CalcLocalVarsArrayVariableRef{ 0x0, 0x684950 };
	WEAK symbol<void(scriptInstance_t inst, sval_u expr, sval_u sourcePos, scr_block_s* block)>EmitPrimitiveExpressionFieldObject{ 0x0, 0x6849A0 };
	WEAK symbol<void(scriptInstance_t inst, sval_u stmt, scr_block_s* block, sval_u* ifStatBlock)>Scr_CalcLocalVarsIfStatement{ 0x0, 0x685170 };
	WEAK symbol<void(scriptInstance_t inst, sval_u expr, sval_u stmt1, sval_u stmt2, sval_u sourcePos, sval_u elseSourcePos, int lastStatement, unsigned int endSourcePos, scr_block_s* block, sval_u* ifStatBlock, sval_u* elseStatBlock)>EmitIfElseStatement{ 0x0, 0x6851D0 };
	WEAK symbol<void(scriptInstance_t inst, sval_u stmt1, sval_u stmt2, scr_block_s* block, sval_u* ifStatBlock, sval_u* elseStatBlock)>Scr_CalcLocalVarsIfElseStatement{ 0x0, 0x685590 };
	WEAK symbol<void(scriptInstance_t inst, sval_u expr, sval_u stmt, sval_u sourcePos, sval_u whileSourcePos, scr_block_s* block, sval_u* whileStatBlock)>EmitWhileStatement{ 0x0, 0x685760 };
	WEAK symbol<void(scriptInstance_t inst, sval_u expr, sval_u stmt, scr_block_s* block, sval_u* whileStatBlock)>Scr_CalcLocalVarsWhileStatement{ 0x0, 0x685C30 };
	WEAK symbol<void(scriptInstance_t inst, sval_u stmt1, sval_u expr, sval_u stmt2, sval_u stmt, sval_u sourcePos, sval_u forSourcePos, scr_block_s* block, sval_u* forStatBlock, sval_u* forStatPostBlock)>EmitForStatement{ 0x0, 0x685DF0 };
	WEAK symbol<void(scriptInstance_t inst, sval_u stmt1, sval_u expr, sval_u stmt2, sval_u stmt, scr_block_s* block, sval_u* forStatBlock, sval_u* forStatPostBlock)>Scr_CalcLocalVarsForStatement{ 0x0, 0x686330 };
	WEAK symbol<int(const void* elem1, const void* elem2)>CompareCaseInfo{ 0x0, 0x6870E0 };
	WEAK symbol<void(scriptInstance_t inst, sval_u val, int lastStatement, unsigned int endSourcePos, scr_block_s* block)>EmitSwitchStatementList{ 0x0, 0x6871A0 };
	WEAK symbol<void(scriptInstance_t inst, sval_u stmtlist, scr_block_s* block)>Scr_CalcLocalVarsSwitchStatement{ 0x0, 0x6873D0 };
	WEAK symbol<void(scriptInstance_t inst, sval_u expr, sval_u stmtlist, sval_u sourcePos, int lastStatement, unsigned int endSourcePos, scr_block_s* block)>EmitSwitchStatement{ 0x0, 0x6875F0 };
	WEAK symbol<void(scriptInstance_t inst, sval_u val, int lastStatement, unsigned int endSourcePos, scr_block_s* block)>EmitStatement{ 0x0, 0x687DB0 };
	WEAK symbol<void(scriptInstance_t inst, sval_u val, scr_block_s* block)>Scr_CalcLocalVarsStatement{ 0x0, 0x688210 };
	WEAK symbol<void(scriptInstance_t inst, sval_u val, int lastStatement, unsigned int endSourcePos, scr_block_s* block)>EmitStatementList{ 0x0, 0x688470 };
	WEAK symbol<void(scriptInstance_t inst, sval_u val, scr_block_s* block, sval_u* devStatBlock)>Scr_CalcLocalVarsDeveloperStatementList{ 0x0, 0x688530 };
	WEAK symbol<void(scriptInstance_t inst, sval_u val, sval_u sourcePos, scr_block_s* block, sval_u* devStatBlock)>EmitDeveloperStatementList{ 0x0, 0x6885A0 };
	WEAK symbol<void(scriptInstance_t inst, sval_u val)>EmitThreadList{ 0x0, 0x688D40 };
	WEAK symbol<void(scriptInstance_t inst, sval_u expr, scr_block_s* block)>EmitVariableExpressionRef{ 0x0, 0x684790 };

	inline void* Scr_CompileRemoveRefToString_ADDR() { return CALL_ADDR(0x0, 0x67EB90); }
	void Scr_CompileRemoveRefToString(scriptInstance_t inst, unsigned int stringVal, void* call_addr = Scr_CompileRemoveRefToString_ADDR());
	inline void* EmitCanonicalString_ADDR() { return CALL_ADDR(0x0, 0x67EBB0); }
	void EmitCanonicalString(scriptInstance_t inst, unsigned int stringVal, void* call_addr = EmitCanonicalString_ADDR());
	inline void* CompileTransferRefToString_ADDR() { return CALL_ADDR(0x0, 0x67EC30); }
	void CompileTransferRefToString(unsigned int stringValue, scriptInstance_t inst, unsigned int user, void* call_addr = CompileTransferRefToString_ADDR());
	inline void* EmitEnd_ADDR() { return CALL_ADDR(0x0, 0x67F0C0); }
	void EmitEnd(scriptInstance_t inst, void* call_addr = EmitEnd_ADDR());
	inline void* EmitReturn_ADDR() { return CALL_ADDR(0x0, 0x67F1A0); }
	void EmitReturn(scriptInstance_t inst, void* call_addr = EmitReturn_ADDR());
	inline void* EmitCodepos_ADDR() { return CALL_ADDR(0x0, 0x67F290); }
	void EmitCodepos(scriptInstance_t inst, int codepos, void* call_addr = EmitCodepos_ADDR());
	inline void* EmitShort_ADDR() { return CALL_ADDR(0x0, 0x67F2C0); }
	void EmitShort(scriptInstance_t inst, int value, void* call_addr = EmitShort_ADDR());
	inline void* EmitByte_ADDR() { return CALL_ADDR(0x0, 0x67F2F0); }
	void EmitByte(scriptInstance_t inst, int value, void* call_addr = EmitByte_ADDR());
	inline void* EmitGetInteger_ADDR() { return CALL_ADDR(0x0, 0x67F320); }
	void EmitGetInteger(scriptInstance_t inst, int value, sval_u sourcePos, void* call_addr = EmitGetInteger_ADDR());
	inline void* EmitGetFloat_ADDR() { return CALL_ADDR(0x0, 0x67F470); }
	void EmitGetFloat(scriptInstance_t inst, float value, sval_u sourcePos, void* call_addr = EmitGetFloat_ADDR());
	inline void* EmitAnimTree_ADDR() { return CALL_ADDR(0x0, 0x67F4C0); }
	void EmitAnimTree(scriptInstance_t inst, sval_u sourcePos, void* call_addr = EmitAnimTree_ADDR());
	inline void* EmitRemoveLocalVars_ADDR() { return CALL_ADDR(0x0, 0x67F880); }
	void EmitRemoveLocalVars(scriptInstance_t inst, scr_block_s* outerBlock, scr_block_s* block, void* call_addr = EmitRemoveLocalVars_ADDR());
	inline void* EmitNOP2_ADDR() { return CALL_ADDR(0x0, 0x67F9A0); }
	void EmitNOP2(scr_block_s* block, scriptInstance_t inst, int lastStatement, unsigned int endSourcePos, void* call_addr = EmitNOP2_ADDR());
	inline void* Scr_AppendChildBlocks_ADDR() { return CALL_ADDR(0x0, 0x67FAA0); }
	void Scr_AppendChildBlocks(scr_block_s* block, scr_block_s** childBlocks, int childCount, void* call_addr = Scr_AppendChildBlocks_ADDR());
	inline void* Scr_TransferBlock_ADDR() { return CALL_ADDR(0x0, 0x67FC60); }
	void Scr_TransferBlock(scr_block_s* to, scr_block_s* from, void* call_addr = Scr_TransferBlock_ADDR());
	inline void* EmitSafeSetVariableField_ADDR() { return CALL_ADDR(0x0, 0x67FD50); }
	void EmitSafeSetVariableField(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u sourcePos, void* call_addr = EmitSafeSetVariableField_ADDR());
	inline void* EmitSafeSetWaittillVariableField_ADDR() { return CALL_ADDR(0x0, 0x67FDC0); }
	void EmitSafeSetWaittillVariableField(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u sourcePos, void* call_addr = EmitSafeSetWaittillVariableField_ADDR());
	inline void* EmitGetString_ADDR() { return CALL_ADDR(0x0, 0x67FEE0); }
	void EmitGetString(unsigned int value, scriptInstance_t inst, sval_u sourcePos, void* call_addr = EmitGetString_ADDR());
	inline void* EmitGetIString_ADDR() { return CALL_ADDR(0x0, 0x67FF30); }
	void EmitGetIString(unsigned int value, scriptInstance_t inst, sval_u sourcePos, void* call_addr = EmitGetIString_ADDR());
	inline void* EmitGetVector_ADDR() { return CALL_ADDR(0x0, 0x67FF80); }
	void EmitGetVector(const float* value, scriptInstance_t inst, sval_u sourcePos, void* call_addr = EmitGetVector_ADDR());
	inline void* Scr_PushValue_ADDR() { return CALL_ADDR(0x0, 0x680120); }
	void Scr_PushValue(scriptInstance_t inst, VariableCompileValue* constValue, void* call_addr = Scr_PushValue_ADDR());
	inline void* EmitCastBool_ADDR() { return CALL_ADDR(0x0, 0x680180); }
	void EmitCastBool(scriptInstance_t inst, sval_u sourcePos, void* call_addr = EmitCastBool_ADDR());
	inline void* EmitBoolNot_ADDR() { return CALL_ADDR(0x0, 0x680270); }
	void EmitBoolNot(scriptInstance_t inst, sval_u sourcePos, void* call_addr = EmitBoolNot_ADDR());
	inline void* EmitBoolComplement_ADDR() { return CALL_ADDR(0x0, 0x680360); }
	void EmitBoolComplement(scriptInstance_t inst, sval_u sourcePos, void* call_addr = EmitBoolComplement_ADDR());
	inline void* EmitSize_ADDR() { return CALL_ADDR(0x0, 0x680450); }
	void EmitSize(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u sourcePos, void* call_addr = EmitSize_ADDR());
	inline void* EmitSelf_ADDR() { return CALL_ADDR(0x0, 0x680560); }
	void EmitSelf(scriptInstance_t inst, sval_u sourcePos, void* call_addr = EmitSelf_ADDR());
	inline void* EmitLevel_ADDR() { return CALL_ADDR(0x0, 0x680660); }
	void EmitLevel(scriptInstance_t inst, sval_u sourcePos, void* call_addr = EmitLevel_ADDR());
	inline void* EmitGame_ADDR() { return CALL_ADDR(0x0, 0x680760); }
	void EmitGame(scriptInstance_t inst, sval_u sourcePos, void* call_addr = EmitGame_ADDR());
	inline void* EmitAnim_ADDR() { return CALL_ADDR(0x0, 0x680860); }
	void EmitAnim(scriptInstance_t inst, sval_u sourcePos, void* call_addr = EmitAnim_ADDR());
	inline void* EmitSelfObject_ADDR() { return CALL_ADDR(0x0, 0x680960); }
	void EmitSelfObject(scriptInstance_t inst, sval_u sourcePos, void* call_addr = EmitSelfObject_ADDR());
	inline void* EmitLevelObject_ADDR() { return CALL_ADDR(0x0, 0x680A50); }
	void EmitLevelObject(scriptInstance_t inst, sval_u sourcePos, void* call_addr = EmitLevelObject_ADDR());
	inline void* EmitAnimObject_ADDR() { return CALL_ADDR(0x0, 0x680B40); }
	void EmitAnimObject(scriptInstance_t inst, sval_u sourcePos, void* call_addr = EmitAnimObject_ADDR());
	inline void* EmitLocalVariable_ADDR() { return CALL_ADDR(0x0, 0x680C30); }
	void EmitLocalVariable(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u sourcePos, void* call_addr = EmitLocalVariable_ADDR());
	inline void* EmitLocalVariableRef_ADDR() { return CALL_ADDR(0x0, 0x680CA0); }
	void EmitLocalVariableRef(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u sourcePos, void* call_addr = EmitLocalVariableRef_ADDR());
	inline void* EmitGameRef_ADDR() { return CALL_ADDR(0x0, 0x680D60); }
	void EmitGameRef(scriptInstance_t inst, sval_u sourcePos, void* call_addr = EmitGameRef_ADDR());
	inline void* EmitClearArray_ADDR() { return CALL_ADDR(0x0, 0x680E50); }
	void EmitClearArray(scriptInstance_t inst, sval_u sourcePos, sval_u indexSourcePos, void* call_addr = EmitClearArray_ADDR());
	inline void* EmitEmptyArray_ADDR() { return CALL_ADDR(0x0, 0x680F50); }
	void EmitEmptyArray(scriptInstance_t inst, sval_u sourcePos, void* call_addr = EmitEmptyArray_ADDR());
	inline void* EmitAnimation_ADDR() { return CALL_ADDR(0x0, 0x681050); }
	void EmitAnimation(scriptInstance_t inst, sval_u anim, sval_u sourcePos, void* call_addr = EmitAnimation_ADDR());
	inline void* EmitFieldVariable_ADDR() { return CALL_ADDR(0x0, 0x6811C0); }
	void EmitFieldVariable(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u field, sval_u sourcePos, void* call_addr = EmitFieldVariable_ADDR());
	inline void* EmitFieldVariableRef_ADDR() { return CALL_ADDR(0x0, 0x681200); }
	void EmitFieldVariableRef(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u field, sval_u sourcePos, sval_u rhsSourcePos, void* call_addr = EmitFieldVariableRef_ADDR());
	inline void* EmitObject_ADDR() { return CALL_ADDR(0x0, 0x681310); }
	void EmitObject(scriptInstance_t inst, sval_u expr, sval_u sourcePos, void* call_addr = EmitObject_ADDR());
	inline void* EmitDecTop_ADDR() { return CALL_ADDR(0x0, 0x681630); }
	void EmitDecTop(scriptInstance_t inst, void* call_addr = EmitDecTop_ADDR());
	inline void* EmitArrayVariable_ADDR() { return CALL_ADDR(0x0, 0x681840); }
	void EmitArrayVariable(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u index, sval_u sourcePos, sval_u indexSourcePos, void* call_addr = EmitArrayVariable_ADDR());
	inline void* EmitArrayVariableRef_ADDR() { return CALL_ADDR(0x0, 0x6818C0); }
	void EmitArrayVariableRef(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u index, sval_u sourcePos, sval_u indexSourcePos, void* call_addr = EmitArrayVariableRef_ADDR());
	inline void* EmitClearArrayVariable_ADDR() { return CALL_ADDR(0x0, 0x681930); }
	void EmitClearArrayVariable(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u index, sval_u sourcePos, sval_u indexSourcePos, void* call_addr = EmitClearArrayVariable_ADDR());
	inline void* AddExpressionListOpcodePos_ADDR() { return CALL_ADDR(0x0, 0x681B30); }
	void AddExpressionListOpcodePos(scriptInstance_t inst, sval_u exprlist, void* call_addr = AddExpressionListOpcodePos_ADDR());
	inline void* AddFilePrecache_ADDR() { return CALL_ADDR(0x0, 0x681B70); }
	void AddFilePrecache(scriptInstance_t inst, unsigned int filename, unsigned int sourcePos, int include, unsigned int* filePosId, unsigned int* fileCountId, void* call_addr = AddFilePrecache_ADDR());
	inline void* EmitFunction_ADDR() { return CALL_ADDR(0x0, 0x681C30); }
	void EmitFunction(scriptInstance_t inst, sval_u func, sval_u sourcePos, void* call_addr = EmitFunction_ADDR());
	inline void* EmitGetFunction_ADDR() { return CALL_ADDR(0x0, 0x681F30); }
	void EmitGetFunction(scriptInstance_t inst, sval_u func, sval_u sourcePos, void* call_addr = EmitGetFunction_ADDR());
	inline void* EmitPostScriptFunctionPointer_ADDR() { return CALL_ADDR(0x0, 0x6822F0); }
	void EmitPostScriptFunctionPointer(scr_block_s* block, scriptInstance_t inst, sval_u expr, int param_count, int bMethod, sval_u nameSourcePos, sval_u sourcePos, void* call_addr = EmitPostScriptFunctionPointer_ADDR());
	inline void* EmitPostScriptThread_ADDR() { return CALL_ADDR(0x0, 0x682500); }
	void EmitPostScriptThread(scriptInstance_t inst, sval_u func, int param_count, int bMethod, sval_u sourcePos, void* call_addr = EmitPostScriptThread_ADDR());
	inline void* EmitPostScriptThreadPointer_ADDR() { return CALL_ADDR(0x0, 0x682730); }
	void EmitPostScriptThreadPointer(scr_block_s* block, scriptInstance_t inst, sval_u expr, int param_count, int bMethod, sval_u sourcePos, void* call_addr = EmitPostScriptThreadPointer_ADDR());
	inline void* EmitPostScriptFunctionCall_ADDR() { return CALL_ADDR(0x0, 0x682950); }
	void EmitPostScriptFunctionCall(scriptInstance_t inst, int bMethod, int param_count, sval_u func_name, sval_u nameSourcePos, scr_block_s* block, void* call_addr = EmitPostScriptFunctionCall_ADDR());
	inline void* EmitPostScriptThreadCall_ADDR() { return CALL_ADDR(0x0, 0x6829A0); }
	void EmitPostScriptThreadCall(scriptInstance_t inst, int isMethod, int param_count, sval_u func_name, sval_u sourcePos, sval_u nameSourcePos, scr_block_s* block, void* call_addr = EmitPostScriptThreadCall_ADDR());
	inline void* EmitPreFunctionCall_ADDR() { return CALL_ADDR(0x0, 0x6829F0); }
	void EmitPreFunctionCall(scriptInstance_t inst, void* call_addr = EmitPreFunctionCall_ADDR());
	inline void* EmitPostFunctionCall_ADDR() { return CALL_ADDR(0x0, 0x682AE0); }
	void EmitPostFunctionCall(scriptInstance_t inst, int bMethod, sval_u func_name, int param_count, scr_block_s* block, void* call_addr = EmitPostFunctionCall_ADDR());
	inline void* Scr_BeginDevScript_ADDR() { return CALL_ADDR(0x0, 0x682B30); }
	void Scr_BeginDevScript(scriptInstance_t isnt, int* type_, char** savedPos, void* call_addr = Scr_BeginDevScript_ADDR());
	inline void* Scr_EndDevScript_ADDR() { return CALL_ADDR(0x0, 0x682BA0); }
	void Scr_EndDevScript(scriptInstance_t inst, char** savedPos, void* call_addr = Scr_EndDevScript_ADDR());
	inline void* EmitCallBuiltinOpcode_ADDR() { return CALL_ADDR(0x0, 0x682BD0); }
	void EmitCallBuiltinOpcode(scriptInstance_t inst, int param_count, sval_u sourcePos, void* call_addr = EmitCallBuiltinOpcode_ADDR());
	inline void* EmitCallBuiltinMethodOpcode_ADDR() { return CALL_ADDR(0x0, 0x682C40); }
	void EmitCallBuiltinMethodOpcode(int inst, int param_count, sval_u sourcePos, void* call_addr = EmitCallBuiltinMethodOpcode_ADDR());
	inline void* EmitCall_ADDR() { return CALL_ADDR(0x0, 0x682CA0); }
	void EmitCall(scriptInstance_t inst, sval_u func_name, sval_u params, int bStatement, scr_block_s* block, void* call_addr = EmitCall_ADDR());
	inline void* LinkThread_ADDR() { return CALL_ADDR(0x0, 0x683250); }
	void LinkThread(scriptInstance_t inst, unsigned int threadCountId, VariableValue* pos, int allowFarCall, void* call_addr = LinkThread_ADDR());
	inline void* LinkFile_ADDR() { return CALL_ADDR(0x0, 0x6833F0); }
	void LinkFile(scriptInstance_t inst, unsigned int filePosId, unsigned int fileCountId, void* call_addr = LinkFile_ADDR());
	inline void* EmitCallExpression_ADDR() { return CALL_ADDR(0x0, 0x683640); }
	void EmitCallExpression(scriptInstance_t inst, scr_block_s* block, sval_u expr, int bStatement, void* call_addr = EmitCallExpression_ADDR());
	inline void* EmitCallExpressionFieldObject_ADDR() { return CALL_ADDR(0x0, 0x683690); }
	void EmitCallExpressionFieldObject(scr_block_s* block, scriptInstance_t inst, sval_u expr, void* call_addr = EmitCallExpressionFieldObject_ADDR());
	inline void* Scr_CreateVector_ADDR() { return CALL_ADDR(0x0, 0x6836F0); }
	void Scr_CreateVector(scriptInstance_t inst, VariableCompileValue* constValue, VariableCompileValue* value, void* call_addr = Scr_CreateVector_ADDR());
	inline void* EmitOrEvalPrimitiveExpressionList_ADDR() { return CALL_ADDR(0x0, 0x6838D0); }
	bool EmitOrEvalPrimitiveExpressionList(scriptInstance_t inst, sval_u exprlist, sval_u sourcePos, VariableCompileValue* constValue, scr_block_s* a5, void* call_addr = EmitOrEvalPrimitiveExpressionList_ADDR());
	inline void* EmitExpressionListFieldObject_ADDR() { return CALL_ADDR(0x0, 0x683AF0); }
	void EmitExpressionListFieldObject(scriptInstance_t inst, sval_u exprlist, sval_u sourcePos, scr_block_s* block, void* call_addr = EmitExpressionListFieldObject_ADDR());
	inline void* EmitBoolOrExpression_ADDR() { return CALL_ADDR(0x0, 0x683F00); }
	void EmitBoolOrExpression(scriptInstance_t inst, sval_u expr1, sval_u expr2, sval_u expr1sourcePos, sval_u expr2sourcePos, scr_block_s* block, void* call_addr = EmitBoolOrExpression_ADDR());
	inline void* EmitBoolAndExpression_ADDR() { return CALL_ADDR(0x0, 0x684090); }
	void EmitBoolAndExpression(scriptInstance_t inst, sval_u expr1, sval_u expr2, sval_u expr1sourcePos, sval_u expr2sourcePos, scr_block_s* a6, void* call_addr = EmitBoolAndExpression_ADDR());
	inline void* EmitOrEvalBinaryOperatorExpression_ADDR() { return CALL_ADDR(0x0, 0x684350); }
	bool EmitOrEvalBinaryOperatorExpression(scriptInstance_t inst, sval_u expr1, sval_u expr2, sval_u opcode, sval_u sourcePos, VariableCompileValue* constValue, scr_block_s* a8, void* call_addr = EmitOrEvalBinaryOperatorExpression_ADDR());
	inline void* EmitBinaryEqualsOperatorExpression_ADDR() { return CALL_ADDR(0x0, 0x684460); }
	void EmitBinaryEqualsOperatorExpression(scr_block_s* block, scriptInstance_t inst, sval_u lhs, sval_u rhs, sval_u opcode, sval_u sourcePos, void* call_addr = EmitBinaryEqualsOperatorExpression_ADDR());
	inline void* Scr_CalcLocalVarsVariableExpressionRef_ADDR() { return CALL_ADDR(0x0, 0x684500); }
	void Scr_CalcLocalVarsVariableExpressionRef(scr_block_s* block, sval_u expr, void* call_addr = Scr_CalcLocalVarsVariableExpressionRef_ADDR());
	inline void* EvalExpression_ADDR() { return CALL_ADDR(0x0, 0x684540); }
	bool EvalExpression(VariableCompileValue* constValue, scriptInstance_t inst, sval_u expr, void* call_addr = EvalExpression_ADDR());
	inline void* EmitArrayPrimitiveExpressionRef_ADDR() { return CALL_ADDR(0x0, 0x684900); }
	void EmitArrayPrimitiveExpressionRef(scriptInstance_t inst, sval_u expr, sval_u sourcePos, scr_block_s* block, void* call_addr = EmitArrayPrimitiveExpressionRef_ADDR());
	inline void* ConnectBreakStatements_ADDR() { return CALL_ADDR(0x0, 0x684AC0); }
	void ConnectBreakStatements(scriptInstance_t inst, void* call_addr = ConnectBreakStatements_ADDR());
	inline void* ConnectContinueStatements_ADDR() { return CALL_ADDR(0x0, 0x684B00); }
	void ConnectContinueStatements(scriptInstance_t inst, void* call_addr = ConnectContinueStatements_ADDR());
	inline void* EmitClearVariableExpression_ADDR() { return CALL_ADDR(0x0, 0x684B40); }
	bool EmitClearVariableExpression(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u rhsSourcePos, void* call_addr = EmitClearVariableExpression_ADDR());
	inline void* EmitAssignmentStatement_ADDR() { return CALL_ADDR(0x0, 0x684C40); }
	void EmitAssignmentStatement(scriptInstance_t inst, sval_u lhs, sval_u rhs, sval_u sourcePos, sval_u rhsSourcePos, scr_block_s* block, void* call_addr = EmitAssignmentStatement_ADDR());
	inline void* EmitCallExpressionStatement_ADDR() { return CALL_ADDR(0x0, 0x684CD0); }
	void EmitCallExpressionStatement(scriptInstance_t inst, scr_block_s* block, sval_u expr, void* call_addr = EmitCallExpressionStatement_ADDR());
	inline void* EmitReturnStatement_ADDR() { return CALL_ADDR(0x0, 0x684D20); }
	void EmitReturnStatement(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u sourcePos, void* call_addr = EmitReturnStatement_ADDR());
	inline void* EmitWaitStatement_ADDR() { return CALL_ADDR(0x0, 0x684D80); }
	void EmitWaitStatement(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u sourcePos, sval_u waitSourcePos, void* call_addr = EmitWaitStatement_ADDR());
	inline void* EmitWaittillFrameEnd_ADDR() { return CALL_ADDR(0x0, 0x684EB0); }
	void EmitWaittillFrameEnd(scriptInstance_t inst, sval_u sourcePos, void* call_addr = EmitWaittillFrameEnd_ADDR());
	inline void* EmitIfStatement_ADDR() { return CALL_ADDR(0x0, 0x684FB0); }
	void EmitIfStatement(scriptInstance_t inst, sval_u expr, sval_u stmt, sval_u sourcePos, int lastStatement, unsigned int endSourcePos, scr_block_s* block, sval_u* ifStatBlock, void* call_addr = EmitIfStatement_ADDR());
	inline void* Scr_AddBreakBlock_ADDR() { return CALL_ADDR(0x0, 0x6856A0); }
	void Scr_AddBreakBlock(scriptInstance_t inst, scr_block_s* block, void* call_addr = Scr_AddBreakBlock_ADDR());
	inline void* Scr_AddContinueBlock_ADDR() { return CALL_ADDR(0x0, 0x685700); }
	void Scr_AddContinueBlock(scriptInstance_t inst, scr_block_s* block, void* call_addr = Scr_AddContinueBlock_ADDR());
	inline void* EmitIncStatement_ADDR() { return CALL_ADDR(0x0, 0x686570); }
	void EmitIncStatement(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u sourcePos, void* call_addr = EmitIncStatement_ADDR());
	inline void* EmitDecStatement_ADDR() { return CALL_ADDR(0x0, 0x686690); }
	void EmitDecStatement(scr_block_s* block, scriptInstance_t inst, sval_u expr, sval_u sourcePos, void* call_addr = EmitDecStatement_ADDR());
	inline void* Scr_CalcLocalVarsFormalParameterListInternal_ADDR() { return CALL_ADDR(0x0, 0x6867B0); }
	void Scr_CalcLocalVarsFormalParameterListInternal(sval_u* node, scr_block_s* block, void* call_addr = Scr_CalcLocalVarsFormalParameterListInternal_ADDR());
	inline void* EmitWaittillStatement_ADDR() { return CALL_ADDR(0x0, 0x686810); }
	void EmitWaittillStatement(scriptInstance_t inst, sval_u obj, sval_u exprlist, sval_u sourcePos, sval_u waitSourcePos, scr_block_s* block, void* call_addr = EmitWaittillStatement_ADDR());
	inline void* EmitWaittillmatchStatement_ADDR() { return CALL_ADDR(0x0, 0x686A60); }
	void EmitWaittillmatchStatement(scriptInstance_t inst, sval_u obj, sval_u exprlist, sval_u sourcePos, sval_u waitSourcePos, scr_block_s* block, void* call_addr = EmitWaittillmatchStatement_ADDR());
	inline void* EmitNotifyStatement_ADDR() { return CALL_ADDR(0x0, 0x686D30); }
	void EmitNotifyStatement(scriptInstance_t inst, sval_u obj, sval_u exprlist, sval_u sourcePos, sval_u notifySourcePos, scr_block_s* block, void* call_addr = EmitNotifyStatement_ADDR());
	inline void* EmitEndOnStatement_ADDR() { return CALL_ADDR(0x0, 0x686F90); }
	void EmitEndOnStatement(scr_block_s* block, scriptInstance_t inst, sval_u obj, sval_u expr, sval_u sourcePos, sval_u exprSourcePos, void* call_addr = EmitEndOnStatement_ADDR());
	inline void* EmitCaseStatement_ADDR() { return CALL_ADDR(0x0, 0x687100); }
	void EmitCaseStatement(scriptInstance_t inst, sval_u expr, sval_u sourcePos, void* call_addr = EmitCaseStatement_ADDR());
	inline void* EmitCaseStatementInfo_ADDR() { return CALL_ADDR(0x0, 0x687990); }
	void EmitCaseStatementInfo(scriptInstance_t inst, unsigned int name, sval_u sourcePos, void* call_addr = EmitCaseStatementInfo_ADDR());
	inline void* EmitBreakStatement_ADDR() { return CALL_ADDR(0x0, 0x6879F0); }
	void EmitBreakStatement(scr_block_s* block, scriptInstance_t inst, sval_u sourcePos, void* call_addr = EmitBreakStatement_ADDR());
	inline void* EmitContinueStatement_ADDR() { return CALL_ADDR(0x0, 0x687B90); }
	void EmitContinueStatement(scr_block_s* block, scriptInstance_t inst, sval_u sourcePos, void* call_addr = EmitContinueStatement_ADDR());
	inline void* EmitProfStatement_ADDR() { return CALL_ADDR(0x0, 0x687D30); }
	void EmitProfStatement(scriptInstance_t inst, sval_u profileName, sval_u sourcePos, OpcodeVM op, void* call_addr = EmitProfStatement_ADDR());
	inline void* Scr_CalcLocalVarsStatementList_ADDR() { return CALL_ADDR(0x0, 0x6884F0); }
	void Scr_CalcLocalVarsStatementList(scr_block_s* block, scriptInstance_t inst, sval_u val, void* call_addr = Scr_CalcLocalVarsStatementList_ADDR());
	inline void* EmitFormalParameterList_ADDR() { return CALL_ADDR(0x0, 0x6886A0); }
	void EmitFormalParameterList(scriptInstance_t inst, sval_u exprlist, sval_u sourcePos, scr_block_s* block, void* call_addr = EmitFormalParameterList_ADDR());
	inline void* SpecifyThread_ADDR() { return CALL_ADDR(0x0, 0x6887C0); }
	void SpecifyThread(scriptInstance_t inst, sval_u val, void* call_addr = SpecifyThread_ADDR());
	inline void* EmitThreadInternal_ADDR() { return CALL_ADDR(0x0, 0x6888D0); }
	void EmitThreadInternal(scriptInstance_t inst, sval_u val, sval_u sourcePos, sval_u endSourcePos, scr_block_s* block, void* call_addr = EmitThreadInternal_ADDR());
	inline void* Scr_CalcLocalVarsThread_ADDR() { return CALL_ADDR(0x0, 0x688990); }
	void Scr_CalcLocalVarsThread(sval_u* stmttblock, scriptInstance_t inst, sval_u exprlist, sval_u stmtlist, void* call_addr = Scr_CalcLocalVarsThread_ADDR());
	inline void* InitThread_ADDR() { return CALL_ADDR(0x0, 0x688A00); }
	void InitThread(int type_, scriptInstance_t inst, void* call_addr = InitThread_ADDR());
	inline void* EmitNormalThread_ADDR() { return CALL_ADDR(0x0, 0x688A70); }
	void EmitNormalThread(scriptInstance_t inst, sval_u val, sval_u* stmttblock, void* call_addr = EmitNormalThread_ADDR());
	inline void* EmitDeveloperThread_ADDR() { return CALL_ADDR(0x0, 0x688B00); }
	void EmitDeveloperThread(scriptInstance_t inst, sval_u val, sval_u* stmttblock, void* call_addr = EmitDeveloperThread_ADDR());
	inline void* EmitThread_ADDR() { return CALL_ADDR(0x0, 0x688C40); }
	void EmitThread(scriptInstance_t inst, sval_u val, void* call_addr = EmitThread_ADDR());
	inline void* EmitInclude_ADDR() { return CALL_ADDR(0x0, 0x688DD0); }
	void EmitInclude(scriptInstance_t inst, sval_u val, void* call_addr = EmitInclude_ADDR());
	inline void* ScriptCompile_ADDR() { return CALL_ADDR(0x0, 0x688E70); }
	void ScriptCompile(scriptInstance_t inst, sval_u val, unsigned int filePosId, unsigned int fileCountId, unsigned int scriptId, PrecacheEntry* entries, int entriesCount, void* call_addr = ScriptCompile_ADDR());
}