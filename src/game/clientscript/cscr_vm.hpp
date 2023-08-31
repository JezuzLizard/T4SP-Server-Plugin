#pragma once

namespace game
{
	WEAK symbol<void(scriptInstance_t inst)>Scr_VM_Init{ 0x0, 0x693B20 };
	WEAK symbol<void(scriptInstance_t inst, unsigned int startLocalId, VariableStackBuffer* stackValue)>VM_UnarchiveStack{ 0x0, 0x697BB0 };
	WEAK symbol<unsigned int(scriptInstance_t inst)>VM_ExecuteInternal{ 0x0, 0x693E80 };
	WEAK symbol<unsigned int(scriptInstance_t inst, unsigned int localId, const char* pos, unsigned int paramcount)>VM_Execute{ 0x0, 0x6992E0 };
	WEAK symbol<void(scriptInstance_t inst, int bComplete)>Scr_ShutdownSystem{ 0x0, 0x699930 };
	WEAK symbol<BOOL()>Scr_IsSystemActive{ 0x0, 0x699C30 };
	WEAK symbol<scr_animtree_t()>Scr_GetAnimTree{ 0x0, 0x699DD0 };
	WEAK symbol<unsigned int()>Scr_GetFunc{ 0x0, 0x69A2C0 };
	WEAK symbol<void(VariableUnion value)>Scr_AddAnim{ 0x0, 0x69A6D0 };
	WEAK symbol<void(scriptInstance_t inst)>Scr_AddArray{ 0x0, 0x69AA50 };

	inline void* Scr_Init_ADDR() { return CALL_ADDR(0x0, 0x693C20); }
	void Scr_Init(scriptInstance_t inst, void* call_addr = Scr_Init_ADDR());
	inline void* Scr_Shutdown_ADDR() { return CALL_ADDR(0x0, 0x693C90); }
	void Scr_Shutdown(scriptInstance_t inst, void* call_addr = Scr_Shutdown_ADDR());
	inline void* Scr_ErrorInternal_ADDR() { return CALL_ADDR(0x0, 0x693CF0); }
	void Scr_ErrorInternal(scriptInstance_t inst, void* call_addr = Scr_ErrorInternal_ADDR());
	inline void* Scr_ClearOutParams_ADDR() { return CALL_ADDR(0x0, 0x693DA0); }
	void Scr_ClearOutParams(scriptInstance_t inst, void* call_addr = Scr_ClearOutParams_ADDR());
	inline void* GetDummyObject_ADDR() { return CALL_ADDR(0x0, 0x693DE0); }
	unsigned int GetDummyObject(scriptInstance_t inst, void* call_addr = GetDummyObject_ADDR());
	inline void* GetDummyFieldValue_ADDR() { return CALL_ADDR(0x0, 0x693E30); }
	unsigned int GetDummyFieldValue(scriptInstance_t inst, void* call_addr = GetDummyFieldValue_ADDR());
	inline void* VM_CancelNotifyInternal_ADDR() { return CALL_ADDR(0x0, 0x6978C0); }
	void VM_CancelNotifyInternal(scriptInstance_t inst, unsigned int notifyListOwnerId, unsigned int startLocalId, unsigned int notifyListId, unsigned int notifyNameListId, unsigned int stringValue, void* call_addr = VM_CancelNotifyInternal_ADDR());
	inline void* VM_CancelNotify_ADDR() { return CALL_ADDR(0x0, 0x697950); }
	void VM_CancelNotify(scriptInstance_t inst, unsigned int a2, unsigned int a3, void* call_addr = VM_CancelNotify_ADDR());
	inline void* VM_ArchiveStack_ADDR() { return CALL_ADDR(0x0, 0x697A00); }
	VariableStackBuffer * VM_ArchiveStack(scriptInstance_t inst, void* call_addr = VM_ArchiveStack_ADDR());
	inline void* Scr_AddLocalVars_ADDR() { return CALL_ADDR(0x0, 0x697B60); }
	int Scr_AddLocalVars(scriptInstance_t inst, unsigned int a2, void* call_addr = Scr_AddLocalVars_ADDR());
	inline void* VM_TerminateStack_ADDR() { return CALL_ADDR(0x0, 0x697D80); }
	void VM_TerminateStack(scriptInstance_t inst, unsigned int endLocalId, unsigned int startLocalId, VariableStackBuffer* name, void* call_addr = VM_TerminateStack_ADDR());
	inline void* VM_TrimStack_ADDR() { return CALL_ADDR(0x0, 0x697F20); }
	void VM_TrimStack(scriptInstance_t inst, unsigned int parentId, VariableStackBuffer * a3, int fromEndon, void* call_addr = VM_TrimStack_ADDR());
	inline void* Scr_TerminateRunningThread_ADDR() { return CALL_ADDR(0x0, 0x698150); }
	void Scr_TerminateRunningThread(scriptInstance_t inst, unsigned int a2, void* call_addr = Scr_TerminateRunningThread_ADDR());
	inline void* Scr_TerminateWaitThread_ADDR() { return CALL_ADDR(0x0, 0x698200); }
	void Scr_TerminateWaitThread(scriptInstance_t inst, unsigned int a2, unsigned int a3, void* call_addr = Scr_TerminateWaitThread_ADDR());
	inline void* Scr_CancelWaittill_ADDR() { return CALL_ADDR(0x0, 0x698310); }
	void Scr_CancelWaittill(scriptInstance_t inst, unsigned int startLocalId, void* call_addr = Scr_CancelWaittill_ADDR());
	inline void* Scr_TerminateWaittillThread_ADDR() { return CALL_ADDR(0x0, 0x698400); }
	void Scr_TerminateWaittillThread(scriptInstance_t inst, unsigned int a2, unsigned int a3, void* call_addr = Scr_TerminateWaittillThread_ADDR());
	inline void* Scr_TerminateThread_ADDR() { return CALL_ADDR(0x0, 0x698610); }
	void Scr_TerminateThread(unsigned int a2, scriptInstance_t inst, void* call_addr = Scr_TerminateThread_ADDR());
	inline void* VM_Notify_ADDR() { return CALL_ADDR(0x0, 0x698670); }
	void VM_Notify(scriptInstance_t inst, int notifyListOwnerId, unsigned int stringValue, VariableValue * top, void* call_addr = VM_Notify_ADDR());
	inline void* Scr_NotifyNum_Internal_ADDR() { return CALL_ADDR(0x0, 0x698CC0); }
	void Scr_NotifyNum_Internal(scriptInstance_t inst, int entNum, int entClass, unsigned int notifStr, int numParams, void* call_addr = Scr_NotifyNum_Internal_ADDR());
	inline void* Scr_CancelNotifyList_ADDR() { return CALL_ADDR(0x0, 0x698DE0); }
	void Scr_CancelNotifyList(unsigned int notifyListOwnerId, scriptInstance_t inst, void* call_addr = Scr_CancelNotifyList_ADDR());
	inline void* VM_TerminateTime_ADDR() { return CALL_ADDR(0x0, 0x698FE0); }
	void VM_TerminateTime(scriptInstance_t inst, unsigned int parentId, void* call_addr = VM_TerminateTime_ADDR());
	inline void* VM_Resume_ADDR() { return CALL_ADDR(0x0, 0x6990E0); }
	void VM_Resume(scriptInstance_t inst, unsigned int timeId, void* call_addr = VM_Resume_ADDR());
	inline void* Scr_ExecThread_ADDR() { return CALL_ADDR(0x0, 0x699560); }
	unsigned short Scr_ExecThread(scriptInstance_t inst, unsigned int handle, unsigned int paramCount, void* call_addr = Scr_ExecThread_ADDR());
	inline void* Scr_ExecEntThread_ADDR() { return CALL_ADDR(0x0, 0x699640); }
	unsigned short Scr_ExecEntThreadNum(scriptInstance_t inst, int entNum, unsigned int handle, int numParams, unsigned int clientNum, void* call_addr = Scr_ExecEntThread_ADDR());
	inline void* Scr_AddExecThread_ADDR() { return CALL_ADDR(0x0, 0x699730); }
	void Scr_AddExecThread(scriptInstance_t inst, unsigned int handle, void* call_addr = Scr_AddExecThread_ADDR());
	inline void* VM_SetTime_ADDR() { return CALL_ADDR(0x0, 0x6997E0); }
	void VM_SetTime(scriptInstance_t inst, void* call_addr = VM_SetTime_ADDR());
	inline void* Scr_InitSystem_ADDR() { return CALL_ADDR(0x0, 0x699860); }
	void Scr_InitSystem(scriptInstance_t inst, void* call_addr = Scr_InitSystem_ADDR());
	inline void* Scr_GetInt_ADDR() { return CALL_ADDR(0x0, 0x699C50); }
	int Scr_GetInt(scriptInstance_t inst, unsigned int index, void* call_addr = Scr_GetInt_ADDR());
	inline void* Scr_GetAnim_ADDR() { return CALL_ADDR(0x0, 0x699CE0); }
	scr_anim_s Scr_GetAnim(unsigned int index, XAnimTree_s * anims, void* call_addr = Scr_GetAnim_ADDR());
	inline void* Scr_GetFloat_ADDR() { return CALL_ADDR(0x0, 0x699E90); }
	float Scr_GetFloat(scriptInstance_t inst, unsigned int index, void* call_addr = Scr_GetFloat_ADDR());
	inline void* Scr_GetConstString_ADDR() { return CALL_ADDR(0x0, 0x699F30); }
	unsigned int Scr_GetConstString(scriptInstance_t inst, unsigned int index, void* call_addr = Scr_GetConstString_ADDR());
	inline void* Scr_GetConstLowercaseString_ADDR() { return CALL_ADDR(0x0, 0x699FB0); }
	unsigned int Scr_GetConstLowercaseString(scriptInstance_t inst, unsigned int index, void* call_addr = Scr_GetConstLowercaseString_ADDR());
	inline void* Scr_GetString_ADDR() { return CALL_ADDR(0x0, 0x69A0D0); }
	const char * Scr_GetString(unsigned int index, scriptInstance_t inst, void* call_addr = Scr_GetString_ADDR());
	inline void* Scr_GetConstStringIncludeNull_ADDR() { return CALL_ADDR(0x0, 0x69A100); }
	unsigned int Scr_GetConstStringIncludeNull(scriptInstance_t inst, void* call_addr = Scr_GetConstStringIncludeNull_ADDR());
	inline void* Scr_GetDebugString_ADDR() { return CALL_ADDR(0x0, 0x69A130); }
	char * Scr_GetDebugString(scriptInstance_t inst, unsigned int index, void* call_addr = Scr_GetDebugString_ADDR());
	inline void* Scr_GetConstIString_ADDR() { return CALL_ADDR(0x0, 0x69A1A0); }
	unsigned int Scr_GetConstIString(unsigned int index, void* call_addr = Scr_GetConstIString_ADDR());
	inline void* Scr_GetVector_ADDR() { return CALL_ADDR(0x0, 0x69A220); }
	void Scr_GetVector(scriptInstance_t inst, float * value, unsigned int index, void* call_addr = Scr_GetVector_ADDR());
	inline void* Scr_GetEntityRef_ADDR() { return CALL_ADDR(0x0, 0x69A330); }
	scr_entref_t * Scr_GetEntityRef(scriptInstance_t inst, scr_entref_t * retstr, unsigned int index, void* call_addr = Scr_GetEntityRef_ADDR());
	inline void* Scr_GetObject_ADDR() { return CALL_ADDR(0x0, 0x69A460); }
	VariableUnion Scr_GetObject(scriptInstance_t inst, void* call_addr = Scr_GetObject_ADDR());
	inline void* Scr_GetType_ADDR() { return CALL_ADDR(0x0, 0x69A4E0); }
	VariableType Scr_GetType(scriptInstance_t inst, unsigned int index, void* call_addr = Scr_GetType_ADDR());
	inline void* Scr_GetTypeName_ADDR() { return CALL_ADDR(0x0, 0x69A530); }
	char * Scr_GetTypeName(scriptInstance_t inst, void* call_addr = Scr_GetTypeName_ADDR());
	inline void* Scr_GetPointerType_ADDR() { return CALL_ADDR(0x0, 0x69A580); }
	VariableType Scr_GetPointerType(scriptInstance_t inst, unsigned int a2, void* call_addr = Scr_GetPointerType_ADDR());
	inline void* Scr_AddInt_ADDR() { return CALL_ADDR(0x0, 0x69A610); }
	void Scr_AddInt(scriptInstance_t inst, int value, void* call_addr = Scr_AddInt_ADDR());
	inline void* Scr_AddFloat_ADDR() { return CALL_ADDR(0x0, 0x69A670); }
	void Scr_AddFloat(scriptInstance_t inst, float value, void* call_addr = Scr_AddFloat_ADDR());
	inline void* Scr_AddUndefined_ADDR() { return CALL_ADDR(0x0, 0x69A720); }
	void Scr_AddUndefined(scriptInstance_t inst, void* call_addr = Scr_AddUndefined_ADDR());
	inline void* Scr_AddObject_ADDR() { return CALL_ADDR(0x0, 0x69A770); }
	void Scr_AddObject(scriptInstance_t inst, unsigned int entid, void* call_addr = Scr_AddObject_ADDR());
	inline void* Scr_AddString_ADDR() { return CALL_ADDR(0x0, 0x69A7E0); }
	void Scr_AddString(scriptInstance_t inst, const char * string, void* call_addr = Scr_AddString_ADDR());
	inline void* Scr_AddIString_ADDR() { return CALL_ADDR(0x0, 0x69A860); }
	void Scr_AddIString(char * string, void* call_addr = Scr_AddIString_ADDR());
	inline void* Scr_AddConstString_ADDR() { return CALL_ADDR(0x0, 0x69A8D0); }
	void Scr_AddConstString(scriptInstance_t inst, unsigned int id, void* call_addr = Scr_AddConstString_ADDR());
	inline void* Scr_AddVector_ADDR() { return CALL_ADDR(0x0, 0x69A940); }
	void Scr_AddVector(scriptInstance_t inst, float * value, void* call_addr = Scr_AddVector_ADDR());
	inline void* Scr_MakeArray_ADDR() { return CALL_ADDR(0x0, 0x69A9D0); }
	void Scr_MakeArray(scriptInstance_t inst, void* call_addr = Scr_MakeArray_ADDR());
	inline void* Scr_AddArrayStringIndexed_ADDR() { return CALL_ADDR(0x0, 0x69AAF0); }
	void Scr_AddArrayStringIndexed(unsigned int id, scriptInstance_t inst, void* call_addr = Scr_AddArrayStringIndexed_ADDR());
	inline void* Scr_Error_ADDR() { return CALL_ADDR(0x0, 0x69AB70); }
	void Scr_Error(const char * err, scriptInstance_t inst, int is_terminal, void* call_addr = Scr_Error_ADDR());
	inline void* Scr_TerminalError_ADDR() { return CALL_ADDR(0x0, 0x69ABD0); }
	void Scr_TerminalError(scriptInstance_t inst, const char * Source, void* call_addr = Scr_TerminalError_ADDR());
	inline void* Scr_ParamError_ADDR() { return CALL_ADDR(0x0, 0x69AC00); }
	void Scr_ParamError(int a1, scriptInstance_t a2, const char * Source, void* call_addr = Scr_ParamError_ADDR());
	inline void* Scr_ObjectError_ADDR() { return CALL_ADDR(0x0, 0x69AC30); }
	void Scr_ObjectError(scriptInstance_t inst, const char * a2, void* call_addr = Scr_ObjectError_ADDR());
	inline void* SetEntityFieldValue_ADDR() { return CALL_ADDR(0x0, 0x69AC50); }
	bool SetEntityFieldValue(scriptInstance_t inst, int offset, int entnum, classNum_e classnum, int clientNum, VariableValue * value, void* call_addr = SetEntityFieldValue_ADDR());
	inline void* GetEntityFieldValue_ADDR() { return CALL_ADDR(0x0, 0x69ACE0); }
	VariableValue GetEntityFieldValue(int offset, int entnum, scriptInstance_t inst, int classnum, int clientNum, void* call_addr = GetEntityFieldValue_ADDR());
	inline void* Scr_SetStructField_ADDR() { return CALL_ADDR(0x0, 0x69AD50); }
	void Scr_SetStructField(unsigned int a1, unsigned int a2, scriptInstance_t inst, void* call_addr = Scr_SetStructField_ADDR());
	inline void* Scr_IncTime_ADDR() { return CALL_ADDR(0x0, 0x69ADE0); }
	void Scr_IncTime(scriptInstance_t inst, void* call_addr = Scr_IncTime_ADDR());
	inline void* Scr_RunCurrentThreads_ADDR() { return CALL_ADDR(0x0, 0x69AE30); }
	void Scr_RunCurrentThreads(scriptInstance_t inst, void* call_addr = Scr_RunCurrentThreads_ADDR());
	inline void* Scr_ResetTimeout_ADDR() { return CALL_ADDR(0x0, 0x69AE60); }
	void Scr_ResetTimeout(scriptInstance_t inst, void* call_addr = Scr_ResetTimeout_ADDR());

	void SetVariableFieldValue(scriptInstance_t inst, unsigned int id, VariableValue* value);
	void SetNewVariableValue(scriptInstance_t inst, unsigned int id, VariableValue* value);
	void Scr_ClearErrorMessage(scriptInstance_t inst);
	void VM_Shutdown(scriptInstance_t inst);
	void Scr_ShutdownVariables(scriptInstance_t inst);
	void ClearVariableValue(scriptInstance_t inst, unsigned int id);
	unsigned int Scr_GetThreadNotifyName(scriptInstance_t inst, unsigned int startLocalId);
	void Scr_RemoveThreadNotifyName(scriptInstance_t inst, unsigned int startLocalId);
	unsigned int GetArraySize(scriptInstance_t inst, unsigned int id);
	void IncInParam(scriptInstance_t inst);
	unsigned int GetParentLocalId(scriptInstance_t inst, unsigned int threadId);
	void Scr_ClearWaitTime(scriptInstance_t inst, unsigned int startLocalId);
	void Scr_SetThreadWaitTime(scriptInstance_t inst, unsigned int startLocalId, unsigned int waitTime);
	void Scr_SetThreadNotifyName(scriptInstance_t inst, unsigned int startLocalId, unsigned int stringValue);
	void Scr_DebugTerminateThread(scriptInstance_t inst, int topThread);
	unsigned int Scr_GetThreadWaitTime(scriptInstance_t inst, unsigned int startLocalId);
	const char* Scr_GetStackThreadPos(scriptInstance_t inst, unsigned int endLocalId, VariableStackBuffer* stackValue, bool killThread);
	unsigned int Scr_GetSelf(scriptInstance_t inst, unsigned int threadId);
	unsigned int GetVariableKeyObject(scriptInstance_t inst, unsigned int id);
	int MT_Realloc(scriptInstance_t inst, int oldNumBytes, int newNumbytes);
	void CScr_GetObjectField(classNum_e classnum, int entnum, int clientNum, int offset);
	int CScr_SetObjectField(classNum_e classnum, int entnum, int clientNum, int offset);
	void Scr_SetErrorMessage(scriptInstance_t inst, const char* error);
	bool Scr_IsStackClear(scriptInstance_t inst);
	void SL_CheckExists(scriptInstance_t inst, unsigned int stringValue);
	const char* Scr_ReadCodePos(scriptInstance_t inst, const char** pos);
	unsigned int Scr_ReadUnsignedInt(scriptInstance_t inst, const char** pos);
	unsigned short Scr_ReadUnsignedShort(scriptInstance_t inst, const char** pos);
	unsigned char Scr_ReadUnsignedByte(scriptInstance_t inst, const char** pos);
	float Scr_ReadFloat(scriptInstance_t inst, const char** pos);
	const float* Scr_ReadVector(scriptInstance_t inst, const char** pos);
	BOOL IsFieldObject(scriptInstance_t inst, unsigned int id);
	void RemoveVariableValue(scriptInstance_t inst, unsigned int parentId, unsigned int index);
	VariableStackBuffer* GetRefVariableStackBuffer(scriptInstance_t inst, int id);
	unsigned int GetNewObjectVariableReverse(scriptInstance_t inst, unsigned int parentId, unsigned int id);
	unsigned int GetNewVariableIndexReverseInternal(scriptInstance_t inst, unsigned int parentId, unsigned int name);
	unsigned int Scr_GetLocalVar(scriptInstance_t inst, int pos);
	void Scr_EvalBoolNot(scriptInstance_t inst, VariableValue* value);
	unsigned int GetInternalVariableIndex(scriptInstance_t inst, unsigned int unsignedValue);
	const char* Scr_ReadData(scriptInstance_t inst, const char** pos, unsigned int count);
}