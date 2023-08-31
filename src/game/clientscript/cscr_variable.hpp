#pragma once

namespace game
{
	WEAK symbol<int(const void * info1, const void * info2)>ThreadInfoCompare{ 0x0, 0x68EB50};
	WEAK symbol<void(scriptInstance_t scriptInstance)>Scr_DumpScriptThreads{ 0x0, 0x68EBA0};
	WEAK symbol<unsigned int(scriptInstance_t inst, unsigned int parentId, unsigned int name, unsigned int index)>GetNewVariableIndexInternal3{ 0x0, 0x68F090};
	WEAK symbol<void(scriptInstance_t inst, unsigned int parentId)>ClearObjectInternal{ 0x0, 0x68F910};
	WEAK symbol<void(scriptInstance_t inst, VariableType type, VariableUnion a3)>RemoveRefToValueInternal{ 0x0, 0x6901C0};
	WEAK symbol<void(scriptInstance_t inst, unsigned int parentId, unsigned int newParentId)>CopyArray{ 0x0, 0x690770};
	WEAK symbol<void(scriptInstance_t inst, unsigned int parentId, unsigned int name, VariableValue * value)>SetVariableEntityFieldValue{ 0x0, 0x690910};
	WEAK symbol<void(scriptInstance_t inst, VariableValue * a2)>Scr_ClearVector{ 0x0, 0x691000};
	WEAK symbol<void(scriptInstance_t inst)>Scr_FreeEntityList{ 0x0, 0x692160};
	WEAK symbol<void(scriptInstance_t inst)>Scr_FreeObjects{ 0x0, 0x6921E0};
	WEAK symbol<void(unsigned int arrayId, scriptInstance_t inst)>Scr_AddArrayKeys{ 0x0, 0x692DE0};
	WEAK symbol<float(scriptInstance_t inst, unsigned int parentId)>Scr_GetObjectUsage{ 0x0, 0x693030};
	WEAK symbol<char *(const char * filename)>Scr_GetSourceFile_LoadObj{ 0x0, 0x6932C0};
	WEAK symbol<char *(const char * filename)>Scr_GetSourceFile_FastFile{ 0x0, 0x693350};
	WEAK symbol<void(scriptInstance_t inst, char * Format)>Scr_AddFieldsForFile{ 0x0, 0x693390};
	WEAK symbol<void(scriptInstance_t inst, const char * path, const char * extension)>Scr_AddFields_LoadObj{ 0x0, 0x6936B0};
	WEAK symbol<void(scriptInstance_t inst, const char * path, const char * extension)>Scr_AddFields_FastFile{ 0x0, 0x693830};
	WEAK symbol<int(scriptInstance_t inst, unsigned int parentId)>Scr_MakeValuePrimitive{ 0x0, 0x6938B0};

	inline void* Scr_InitVariableRange_ADDR() { return CALL_ADDR(0x0, 0x68EF90); }
	void Scr_InitVariableRange(unsigned int begin, unsigned int end, scriptInstance_t inst, void* call_addr = Scr_InitVariableRange_ADDR());
	inline void* Scr_InitClassMap_ADDR() { return CALL_ADDR(0x0, 0x68F030); }
	void Scr_InitClassMap(scriptInstance_t inst, void* call_addr = Scr_InitClassMap_ADDR());
	inline void* GetNewVariableIndexInternal2_ADDR() { return CALL_ADDR(0x0, 0x68F4A0); }
	unsigned int GetNewVariableIndexInternal2(unsigned int name, scriptInstance_t inst, unsigned int parentId, unsigned int index, void* call_addr = GetNewVariableIndexInternal2_ADDR());
	inline void* GetNewVariableIndexReverseInternal2_ADDR() { return CALL_ADDR(0x0, 0x68F560); }
	unsigned int GetNewVariableIndexReverseInternal2(unsigned int name, scriptInstance_t inst, unsigned int parentId, unsigned int index, void* call_addr = GetNewVariableIndexReverseInternal2_ADDR());
	inline void* MakeVariableExternal_ADDR() { return CALL_ADDR(0x0, 0x68F620); }
	void MakeVariableExternal(VariableValueInternal * parentValue, scriptInstance_t inst, unsigned int index, void* call_addr = MakeVariableExternal_ADDR());
	inline void* FreeChildValue_ADDR() { return CALL_ADDR(0x0, 0x68F800); }
	void FreeChildValue(unsigned int id, scriptInstance_t inst, unsigned int parentId, void* call_addr = FreeChildValue_ADDR());
	inline void* ClearObject_ADDR() { return CALL_ADDR(0x0, 0x68F9E0); }
	void ClearObject(unsigned int parentId, scriptInstance_t inst, void* call_addr = ClearObject_ADDR());
	inline void* Scr_StopThread_ADDR() { return CALL_ADDR(0x0, 0x68FA30); }
	void Scr_StopThread(scriptInstance_t inst, unsigned int threadId, void* call_addr = Scr_StopThread_ADDR());
	inline void* GetSafeParentLocalId_ADDR() { return CALL_ADDR(0x0, 0x68FAA0); }
	unsigned int GetSafeParentLocalId(scriptInstance_t inst, unsigned int threadId, void* call_addr = GetSafeParentLocalId_ADDR());
	inline void* GetStartLocalId_ADDR() { return CALL_ADDR(0x0, 0x68FAD0); }
	unsigned int GetStartLocalId(unsigned int threadId, scriptInstance_t inst, void* call_addr = GetStartLocalId_ADDR());
	inline void* Scr_KillThread_ADDR() { return CALL_ADDR(0x0, 0x68FB10); }
	void Scr_KillThread(scriptInstance_t inst, unsigned int parentId, void* call_addr = Scr_KillThread_ADDR());
	inline void* AllocVariable_ADDR() { return CALL_ADDR(0x0, 0x68FCE0); }
	unsigned __int16 AllocVariable(scriptInstance_t inst, void* call_addr = AllocVariable_ADDR());
	inline void* FreeVariable_ADDR() { return CALL_ADDR(0x0, 0x68FDC0); }
	void FreeVariable(unsigned int id, scriptInstance_t inst, void* call_addr = FreeVariable_ADDR());
	inline void* AllocValue_ADDR() { return CALL_ADDR(0x0, 0x68FE20); }
	unsigned int AllocValue(scriptInstance_t inst, void* call_addr = AllocValue_ADDR());
	inline void* AllocEntity_ADDR() { return CALL_ADDR(0x0, 0x68FF10); }
	unsigned int AllocEntity(unsigned int classnum, scriptInstance_t inst, int entnum, int clientnum, void* call_addr = AllocEntity_ADDR());
	inline void* Scr_AllocArray_ADDR() { return CALL_ADDR(0x0, 0x68FF60); }
	unsigned int Scr_AllocArray(scriptInstance_t inst, void* call_addr = Scr_AllocArray_ADDR());
	inline void* AllocChildThread_ADDR() { return CALL_ADDR(0x0, 0x68FF90); }
	unsigned int AllocChildThread(scriptInstance_t inst, unsigned int parentLocalId, unsigned int self, void* call_addr = AllocChildThread_ADDR());
	inline void* FreeValue_ADDR() { return CALL_ADDR(0x0, 0x68FFD0); }
	void FreeValue(unsigned int id, scriptInstance_t inst, void* call_addr = FreeValue_ADDR());
	inline void* RemoveRefToObject_ADDR() { return CALL_ADDR(0x0, 0x690040); }
	void RemoveRefToObject(unsigned int id, scriptInstance_t inst, void* call_addr = RemoveRefToObject_ADDR());
	inline void* Scr_AllocVector_ADDR() { return CALL_ADDR(0x0, 0x690100); }
	float * Scr_AllocVector(scriptInstance_t inst, void* call_addr = Scr_AllocVector_ADDR());
	inline void* RemoveRefToVector_ADDR() { return CALL_ADDR(0x0, 0x690130); }
	void RemoveRefToVector(const float* vectorValue, scriptInstance_t inst, void* call_addr = RemoveRefToVector_ADDR());
	inline void* AddRefToValue_ADDR() { return CALL_ADDR(0x0, 0x690160); }
	void AddRefToValue(scriptInstance_t inst, VariableType type_, VariableUnion u, void* call_addr = AddRefToValue_ADDR());
	inline void* FindArrayVariable_ADDR() { return CALL_ADDR(0x0, 0x690210); }
	int FindArrayVariable(unsigned int id, unsigned int intvalue, scriptInstance_t inst, void* call_addr = FindArrayVariable_ADDR());
	inline void* FindVariable_ADDR() { return CALL_ADDR(0x0, 0x690260); }
	unsigned int FindVariable(unsigned int unsignedValue, unsigned int parentId, scriptInstance_t inst, void* call_addr = FindVariable_ADDR());
	inline void* GetArrayVariableIndex_ADDR() { return CALL_ADDR(0x0, 0x6902A0); }
	unsigned int GetArrayVariableIndex(unsigned int unsignedValue, scriptInstance_t inst, unsigned int parentId, void* call_addr = GetArrayVariableIndex_ADDR());
	inline void* Scr_GetVariableFieldIndex_ADDR() { return CALL_ADDR(0x0, 0x6902F0); }
	unsigned int Scr_GetVariableFieldIndex(scriptInstance_t inst, unsigned int name, unsigned int parentId, void* call_addr = Scr_GetVariableFieldIndex_ADDR());
	inline void* Scr_FindVariableField_ADDR() { return CALL_ADDR(0x0, 0x6903B0); }
	VariableValue Scr_FindVariableField(scriptInstance_t inst, unsigned int parentId, unsigned int name, void* call_addr = Scr_FindVariableField_ADDR());
	inline void* ClearVariableField_ADDR() { return CALL_ADDR(0x0, 0x690450); }
	void ClearVariableField(scriptInstance_t inst, unsigned int id, unsigned int name, VariableValue * value, void* call_addr = ClearVariableField_ADDR());
	inline void* GetVariable_ADDR() { return CALL_ADDR(0x0, 0x690510); }
	unsigned int GetVariable(scriptInstance_t inst, unsigned int parentId, unsigned int name, void* call_addr = GetVariable_ADDR());
	inline void* GetNewVariable_ADDR() { return CALL_ADDR(0x0, 0x690570); }
	unsigned int GetNewVariable(scriptInstance_t inst, unsigned int unsignedValue, unsigned int parentId, void* call_addr = GetNewVariable_ADDR());
	inline void* GetObjectVariable_ADDR() { return CALL_ADDR(0x0, 0x6905B0); }
	unsigned int GetObjectVariable(unsigned int id, scriptInstance_t inst, unsigned int parentId, void* call_addr = GetObjectVariable_ADDR());
	inline void* GetNewObjectVariable_ADDR() { return CALL_ADDR(0x0, 0x690610); }
	unsigned int GetNewObjectVariable(scriptInstance_t inst, unsigned int name, unsigned int parentId, void* call_addr = GetNewObjectVariable_ADDR());
	inline void* RemoveVariable_ADDR() { return CALL_ADDR(0x0, 0x690650); }
	void RemoveVariable(unsigned int name, unsigned int parentId, scriptInstance_t inst, void* call_addr = RemoveVariable_ADDR());
	inline void* RemoveNextVariable_ADDR() { return CALL_ADDR(0x0, 0x6906A0); }
	void RemoveNextVariable(scriptInstance_t inst, unsigned int parentId, void* call_addr = RemoveNextVariable_ADDR());
	inline void* SafeRemoveVariable_ADDR() { return CALL_ADDR(0x0, 0x690710); }
	void SafeRemoveVariable(unsigned int unsignedValue, unsigned int parentId, scriptInstance_t inst, void* call_addr = SafeRemoveVariable_ADDR());
	inline void* SetVariableValue_ADDR() { return CALL_ADDR(0x0, 0x6908D0); }
	void SetVariableValue(scriptInstance_t inst, VariableValue * value, unsigned int id, void* call_addr = SetVariableValue_ADDR());
	inline void* Scr_EvalVariable_ADDR() { return CALL_ADDR(0x0, 0x690A10); }
	VariableValue Scr_EvalVariable(scriptInstance_t inst, unsigned int id, void* call_addr = Scr_EvalVariable_ADDR());
	inline void* Scr_EvalVariableObject_ADDR() { return CALL_ADDR(0x0, 0x690A50); }
	unsigned int Scr_EvalVariableObject(scriptInstance_t inst, int id, void* call_addr = Scr_EvalVariableObject_ADDR());
	inline void* Scr_EvalVariableEntityField_ADDR() { return CALL_ADDR(0x0, 0x690AB0); }
	VariableValue Scr_EvalVariableEntityField(unsigned int entId, scriptInstance_t inst, unsigned int name, void* call_addr = Scr_EvalVariableEntityField_ADDR());
	inline void* Scr_EvalVariableField_ADDR() { return CALL_ADDR(0x0, 0x690BB0); }
	VariableValue Scr_EvalVariableField(scriptInstance_t inst, unsigned int id, void* call_addr = Scr_EvalVariableField_ADDR());
	inline void* Scr_EvalSizeValue_ADDR() { return CALL_ADDR(0x0, 0x690C10); }
	void Scr_EvalSizeValue(scriptInstance_t inst, VariableValue * value, void* call_addr = Scr_EvalSizeValue_ADDR());
	inline void* GetObject_ADDR() { return CALL_ADDR(0x0, 0x690CF0); }
	unsigned int GetObject(scriptInstance_t inst, unsigned int id, void* call_addr = GetObject_ADDR());
	inline void* GetArray_ADDR() { return CALL_ADDR(0x0, 0x690D50); }
	unsigned int GetArray(scriptInstance_t inst, unsigned int id, void* call_addr = GetArray_ADDR());
	inline void* Scr_EvalBoolComplement_ADDR() { return CALL_ADDR(0x0, 0x690DB0); }
	void Scr_EvalBoolComplement(scriptInstance_t inst, VariableValue * value, void* call_addr = Scr_EvalBoolComplement_ADDR());
	inline void* Scr_CastBool_ADDR() { return CALL_ADDR(0x0, 0x690E00); }
	void Scr_CastBool(scriptInstance_t inst, VariableValue* value, void* call_addr = Scr_CastBool_ADDR());
	inline void* Scr_CastString_ADDR() { return CALL_ADDR(0x0, 0x690E80); }
	char Scr_CastString(scriptInstance_t inst, VariableValue* value, void* call_addr = Scr_CastString_ADDR());
	inline void* Scr_CastDebugString_ADDR() { return CALL_ADDR(0x0, 0x690F30); }
	void Scr_CastDebugString(scriptInstance_t inst, VariableValue* value, void* call_addr = Scr_CastDebugString_ADDR());
	inline void* Scr_CastVector_ADDR() { return CALL_ADDR(0x0, 0x691040); }
	void Scr_CastVector(scriptInstance_t inst, VariableValue* value, void* call_addr = Scr_CastVector_ADDR());
	inline void* Scr_EvalFieldObject_ADDR() { return CALL_ADDR(0x0, 0x691110); }
	VariableUnion Scr_EvalFieldObject(VariableValue * value, scriptInstance_t inst, int a3, void* call_addr = Scr_EvalFieldObject_ADDR());
	inline void* Scr_UnmatchingTypesError_ADDR() { return CALL_ADDR(0x0, 0x6911B0); }
	void Scr_UnmatchingTypesError(scriptInstance_t inst, VariableValue * value2, VariableValue * value1, void* call_addr = Scr_UnmatchingTypesError_ADDR());
	inline void* Scr_CastWeakerPair_ADDR() { return CALL_ADDR(0x0, 0x691270); }
	void Scr_CastWeakerPair(VariableValue * value2, VariableValue * value1, scriptInstance_t inst, void* call_addr = Scr_CastWeakerPair_ADDR());
	inline void* Scr_CastWeakerStringPair_ADDR() { return CALL_ADDR(0x0, 0x691370); }
	void Scr_CastWeakerStringPair(VariableValue * value2, VariableValue * value1, scriptInstance_t inst, void* call_addr = Scr_CastWeakerStringPair_ADDR());
	inline void* Scr_EvalOr_ADDR() { return CALL_ADDR(0x0, 0x6914E0); }
	void Scr_EvalOr(VariableValue * value1, VariableValue * value2, scriptInstance_t inst, void* call_addr = Scr_EvalOr_ADDR());
	inline void* Scr_EvalExOr_ADDR() { return CALL_ADDR(0x0, 0x691510); }
	void Scr_EvalExOr(VariableValue * value1, VariableValue * value2, scriptInstance_t inst, void* call_addr = Scr_EvalExOr_ADDR());
	inline void* Scr_EvalAnd_ADDR() { return CALL_ADDR(0x0, 0x691540); }
	void Scr_EvalAnd(VariableValue * value1, VariableValue * value2, scriptInstance_t inst, void* call_addr = Scr_EvalAnd_ADDR());
	inline void* Scr_EvalEquality_ADDR() { return CALL_ADDR(0x0, 0x691570); }
	void Scr_EvalEquality(VariableValue * value1, scriptInstance_t inst, VariableValue * value2, void* call_addr = Scr_EvalEquality_ADDR());
	inline void* Scr_EvalLess_ADDR() { return CALL_ADDR(0x0, 0x691760); }
	void Scr_EvalLess(VariableValue * value1, VariableValue * value2, scriptInstance_t a3, void* call_addr = Scr_EvalLess_ADDR());
	inline void* Scr_EvalGreaterEqual_ADDR() { return CALL_ADDR(0x0, 0x6917D0); }
	void Scr_EvalGreaterEqual(scriptInstance_t inst, VariableValue * value1, VariableValue * value2, void* call_addr = Scr_EvalGreaterEqual_ADDR());
	inline void* Scr_EvalGreater_ADDR() { return CALL_ADDR(0x0, 0x6917F0); }
	void Scr_EvalGreater(VariableValue * value1, VariableValue * value2, scriptInstance_t inst, void* call_addr = Scr_EvalGreater_ADDR());
	inline void* Scr_EvalLessEqual_ADDR() { return CALL_ADDR(0x0, 0x691860); }
	void Scr_EvalLessEqual(scriptInstance_t inst, VariableValue * value1, VariableValue * value2, void* call_addr = Scr_EvalLessEqual_ADDR());
	inline void* Scr_EvalShiftLeft_ADDR() { return CALL_ADDR(0x0, 0x691880); }
	void Scr_EvalShiftLeft(VariableValue * value1, VariableValue * value2, scriptInstance_t inst, void* call_addr = Scr_EvalShiftLeft_ADDR());
	inline void* Scr_EvalShiftRight_ADDR() { return CALL_ADDR(0x0, 0x6918B0); }
	void Scr_EvalShiftRight(VariableValue * value1, VariableValue * value2, scriptInstance_t inst, void* call_addr = Scr_EvalShiftRight_ADDR());
	inline void* Scr_EvalPlus_ADDR() { return CALL_ADDR(0x0, 0x6918E0); }
	void Scr_EvalPlus(scriptInstance_t inst, VariableValue* value1, VariableValue* value2, void* call_addr = Scr_EvalPlus_ADDR());
	inline void* Scr_EvalMinus_ADDR() { return CALL_ADDR(0x0, 0x691B00); }
	void Scr_EvalMinus(VariableValue * value1, scriptInstance_t inst, VariableValue * value2, void* call_addr = Scr_EvalMinus_ADDR());
	inline void* Scr_EvalMultiply_ADDR() { return CALL_ADDR(0x0, 0x691C20); }
	void Scr_EvalMultiply(VariableValue * value1, scriptInstance_t inst, VariableValue * value2, void* call_addr = Scr_EvalMultiply_ADDR());
	inline void* Scr_EvalDivide_ADDR() { return CALL_ADDR(0x0, 0x691D40); }
	void Scr_EvalDivide(VariableValue * value1, scriptInstance_t inst, VariableValue * value2, void* call_addr = Scr_EvalDivide_ADDR());
	inline void* Scr_EvalMod_ADDR() { return CALL_ADDR(0x0, 0x691F00); }
	void Scr_EvalMod(scriptInstance_t inst, VariableValue * value1, VariableValue * value2, void* call_addr = Scr_EvalMod_ADDR());
	inline void* Scr_EvalBinaryOperator_ADDR() { return CALL_ADDR(0x0, 0x691F50); }
	void Scr_EvalBinaryOperator(scriptInstance_t inst, VariableValue * value1, OpcodeVM op, VariableValue * value2, void* call_addr = Scr_EvalBinaryOperator_ADDR());
	inline void* Scr_FreeEntityNum_ADDR() { return CALL_ADDR(0x0, 0x692090); }
	void Scr_FreeEntityNum(scriptInstance_t inst, unsigned int result, unsigned int entnum, void* call_addr = Scr_FreeEntityNum_ADDR());
	inline void* Scr_SetClassMap_ADDR() { return CALL_ADDR(0x0, 0x692260); }
	void Scr_SetClassMap(scriptInstance_t inst, unsigned int classnum, void* call_addr = Scr_SetClassMap_ADDR());
	inline void* Scr_RemoveClassMap_ADDR() { return CALL_ADDR(0x0, 0x6922E0); }
	void Scr_RemoveClassMap(unsigned int classnum, scriptInstance_t inst, void* call_addr = Scr_RemoveClassMap_ADDR());
	inline void* Scr_AddClassField_ADDR() { return CALL_ADDR(0x0, 0x692350); }
	void Scr_AddClassField(scriptInstance_t inst, unsigned int classnum, const char * name, unsigned int offset, void* call_addr = Scr_AddClassField_ADDR());
	inline void* Scr_GetOffset_ADDR() { return CALL_ADDR(0x0, 0x692440); }
	VariableUnion Scr_GetOffset(const char * name, scriptInstance_t inst, classNum_e classNum, void* call_addr = Scr_GetOffset_ADDR());
	inline void* FindEntityId_ADDR() { return CALL_ADDR(0x0, 0x6924C0); }
	unsigned int FindEntityId(unsigned int entClass, int entNum, scriptInstance_t inst, void* call_addr = FindEntityId_ADDR());
	inline void* Scr_GetEntityId_ADDR() { return CALL_ADDR(0x0, 0x692520); }
	unsigned int Scr_GetEntityId(int entNum, scriptInstance_t inst, classNum_e classnum, int clientnum, void* call_addr = Scr_GetEntityId_ADDR());
	inline void* Scr_FindArrayIndex_ADDR() { return CALL_ADDR(0x0, 0x6925B0); }
	unsigned int Scr_FindArrayIndex(scriptInstance_t inst, VariableValue* index, unsigned int parentId, void* call_addr = Scr_FindArrayIndex_ADDR());
	inline void* Scr_EvalArray_ADDR() { return CALL_ADDR(0x0, 0x692680); }
	void Scr_EvalArray(scriptInstance_t inst, VariableValue * index, VariableValue * value, void* call_addr = Scr_EvalArray_ADDR());
	inline void* Scr_EvalArrayRef_ADDR() { return CALL_ADDR(0x0, 0x692850); }
	unsigned int Scr_EvalArrayRef(scriptInstance_t inst, unsigned int parentId, void* call_addr = Scr_EvalArrayRef_ADDR());
	inline void* ClearArray_ADDR() { return CALL_ADDR(0x0, 0x692AF0); }
	void ClearArray(unsigned int parentId, scriptInstance_t inst, VariableValue * value, void* call_addr = ClearArray_ADDR());
	inline void* SetEmptyArray_ADDR() { return CALL_ADDR(0x0, 0x692D70); }
	void SetEmptyArray(scriptInstance_t inst, unsigned int parentId, void* call_addr = SetEmptyArray_ADDR());
	inline void* Scr_GetEntityIdRef_ADDR() { return CALL_ADDR(0x0, 0x692EC0); }
	scr_entref_t * Scr_GetEntityIdRef(scr_entref_t * retstr, scriptInstance_t inst, unsigned int entId, void* call_addr = Scr_GetEntityIdRef_ADDR());
	inline void* CopyEntity_ADDR() { return CALL_ADDR(0x0, 0x692F00); }
	void CopyEntity(unsigned int parentId, unsigned int newParentId, void* call_addr = CopyEntity_ADDR());
	inline void* Scr_GetEndonUsage_ADDR() { return CALL_ADDR(0x0, 0x692FC0); }
	float Scr_GetEndonUsage(unsigned int parentId, scriptInstance_t inst, void* call_addr = Scr_GetEndonUsage_ADDR());
	inline void* Scr_GetThreadUsage_ADDR() { return CALL_ADDR(0x0, 0x693130); }
	float Scr_GetThreadUsage(VariableStackBuffer * stackBuf, scriptInstance_t inst, float * endonUsage, void* call_addr = Scr_GetThreadUsage_ADDR());
	inline void* Scr_FindField_ADDR() { return CALL_ADDR(0x0, 0x693250); }
	unsigned int Scr_FindField(scriptInstance_t inst, const char * name, int * type, void* call_addr = Scr_FindField_ADDR());
	inline void* Scr_FreeGameVariable_ADDR() { return CALL_ADDR(0x0, 0x693A10); }
	void Scr_FreeGameVariable(scriptInstance_t inst, int bComplete, void* call_addr = Scr_FreeGameVariable_ADDR());
	inline void* Scr_SLHasLowercaseString_ADDR() { return CALL_ADDR(0x0, 0x693A70); }
	bool Scr_SLHasLowercaseString(unsigned int parentId, const char * str, void* call_addr = Scr_SLHasLowercaseString_ADDR());

	unsigned int FindObject(scriptInstance_t inst, unsigned int id);
	unsigned int FindFirstSibling(scriptInstance_t inst, unsigned int id);
	unsigned int FindNextSibling(scriptInstance_t inst, unsigned int id);
	VariableValue Scr_GetArrayIndexValue(scriptInstance_t inst, unsigned int name);
	float Scr_GetEntryUsageInternal(scriptInstance_t inst, unsigned int type, VariableUnion u);
	float Scr_GetEntryUsage(scriptInstance_t inst, VariableValueInternal* entryValue);
	void AddRefToObject(scriptInstance_t inst, unsigned int id);
	void RemoveRefToEmptyObject(scriptInstance_t inst, unsigned int id);
	void Scr_ClearThread(scriptInstance_t inst, unsigned int parentId);
	unsigned int FindObjectVariable(scriptInstance_t inst, unsigned int parentId, unsigned int id);
	void RemoveObjectVariable(scriptInstance_t inst, unsigned int parentId, unsigned int id);
	VariableValueInternal_u* GetVariableValueAddress(scriptInstance_t inst, unsigned int id);
	void Scr_KillEndonThread(scriptInstance_t inst, unsigned int threadId);
	BOOL IsValidArrayIndex(scriptInstance_t inst, unsigned int unsignedValue);
	void RemoveArrayVariable(scriptInstance_t inst, unsigned int parentId, unsigned int unsignedValue);
	void SafeRemoveArrayVariable(scriptInstance_t inst, unsigned int parentId, unsigned int unsignedValue);
	void AddRefToVector(scriptInstance_t inst, const float* floatVal);
	unsigned int FindArrayVariableIndex(scriptInstance_t inst, unsigned int parentId, unsigned int unsignedValue);
	unsigned int GetVariableIndexInternal(scriptInstance_t inst, unsigned int parentId, unsigned int name);
	unsigned int GetNewVariableIndexInternal(scriptInstance_t inst, unsigned int parentId, unsigned int name);
	unsigned int AllocObject(scriptInstance_t inst);
	VariableType GetValueType(scriptInstance_t inst, unsigned int id);
	VariableType GetObjectType(scriptInstance_t inst, unsigned int id);
	float* Scr_AllocVector_(scriptInstance_t inst, const float* v);
	void Scr_EvalInequality(scriptInstance_t inst, VariableValue* value1, VariableValue* value2);
	unsigned int Scr_EvalArrayRefInternal(scriptInstance_t inst, VariableValue* varValue, VariableValueInternal* parentValue);
	unsigned int GetNewArrayVariableIndex(scriptInstance_t inst, unsigned int parentId, unsigned int unsignedValue);
	unsigned int GetNewArrayVariable(scriptInstance_t inst, unsigned int parentId, unsigned int unsignedValue);
	unsigned int GetArrayVariable(scriptInstance_t inst, unsigned int parentId, unsigned int unsignedValue);
	unsigned int AllocThread(scriptInstance_t inst, unsigned int self);
}
