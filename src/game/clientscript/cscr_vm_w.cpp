#include <stdinc.hpp>
#include "codsrc/clientscript/cscr_vm.hpp"

namespace game
{
	//custom made don't replace VariableValue __usercall GetEntityFieldValue@<edx:eax>(int offset@<eax>, int entnum@<ecx>, scriptInstance_t inst, int classnum, int clientNum)
	VariableValue GetEntityFieldValue/*@<eax>*/(int offset_, int entnum, scriptInstance_t inst, int classnum, int clientNum, void* call_addr)
	{
		VariableValue answer;
		VariableUnion u;
		VariableType typ;

		__asm
		{
			push clientNum;
			push classnum;
			push inst;
			mov ecx, entnum;
			mov eax, offset_;
			call call_addr;

			mov u, eax;
			mov typ, edx;

			add esp, 0xC;
		}
		answer.u = u;
		answer.type = typ;
		return answer;
	}

	void Scr_Init(scriptInstance_t a1/*@<eax>*/, void* call_addr)
	{
		__asm
		{
			mov eax, a1;
			call call_addr;
		}
	}

	void Scr_Shutdown(scriptInstance_t a1/*@<edi>*/, void* call_addr)
	{
		__asm
		{
			mov edi, a1;
			call call_addr;
		}
	}

	void Scr_ErrorInternal(scriptInstance_t a1/*@<eax>*/, void* call_addr)
	{
		__asm
		{
			mov eax, a1;
			call call_addr;
		}
	}

	void Scr_ClearOutParams(scriptInstance_t a1/*@<edi>*/, void* call_addr)
	{
		__asm
		{
			mov edi, a1;
			call call_addr;
		}
	}

	unsigned int GetDummyObject/*@<eax>*/(scriptInstance_t a1/*@<edi>*/, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			mov edi, a1;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	unsigned int GetDummyFieldValue/*@<eax>*/(scriptInstance_t a1/*@<eax>*/, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			mov eax, a1;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	void VM_CancelNotifyInternal(scriptInstance_t inst/*@<ecx>*/, unsigned int notifyListOwnerId/*@<eax>*/, unsigned int startLocalId, unsigned int notifyListId, unsigned int notifyNameListId, unsigned int stringValue, void* call_addr)
	{
		__asm
		{
			push stringValue;
			push notifyNameListId;
			push notifyListId;
			push startLocalId;
			mov ecx, inst;
			mov eax, notifyListOwnerId;
			call call_addr;
			add esp, 0x10;
		}
	}

	void VM_CancelNotify(scriptInstance_t a1/*@<edi>*/, unsigned int a2, unsigned int a3, void* call_addr)
	{
		__asm
		{
			push a3;
			push a2;
			mov edi, a1;
			call call_addr;
			add esp, 0x8;
		}
	}

	VariableStackBuffer * VM_ArchiveStack/*@<eax>*/(scriptInstance_t inst/*@<eax>*/, void* call_addr)
	{
		VariableStackBuffer * answer;
		
		__asm
		{
			mov eax, inst;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	int Scr_AddLocalVars/*@<eax>*/(scriptInstance_t a1/*@<eax>*/, unsigned int a2/*@<edx>*/, void* call_addr)
	{
		int answer;
		
		__asm
		{
			mov eax, a1;
			mov edx, a2;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	void VM_TerminateStack(scriptInstance_t inst/*@<esi>*/, unsigned int endLocalId, unsigned int startLocalId, VariableStackBuffer * name, void* call_addr)
	{
		__asm
		{
			push name;
			push startLocalId;
			push endLocalId;
			mov esi, inst;
			call call_addr;
			add esp, 0xC;
		}
	}

	void VM_TrimStack(scriptInstance_t a1/*@<eax>*/, unsigned int parentId, VariableStackBuffer * a3, int fromEndon, void* call_addr)
	{
		__asm
		{
			push fromEndon;
			push a3;
			push parentId;
			mov eax, a1;
			call call_addr;
			add esp, 0xC;
		}
	}

	void Scr_TerminateRunningThread(scriptInstance_t a1/*@<edx>*/, unsigned int a2, void* call_addr)
	{
		__asm
		{
			push a2;
			mov edx, a1;
			call call_addr;
			add esp, 0x4;
		}
	}

	void Scr_TerminateWaitThread(scriptInstance_t a1/*@<eax>*/, unsigned int a2, unsigned int a3, void* call_addr)
	{
		__asm
		{
			push a3;
			push a2;
			mov eax, a1;
			call call_addr;
			add esp, 0x8;
		}
	}

	void Scr_CancelWaittill(scriptInstance_t inst/*@<ecx>*/, unsigned int startLocalId/*@<eax>*/, void* call_addr)
	{
		__asm
		{
			mov ecx, inst;
			mov eax, startLocalId;
			call call_addr;
		}
	}

	void Scr_TerminateWaittillThread(scriptInstance_t a1/*@<eax>*/, unsigned int a2, unsigned int a3, void* call_addr)
	{
		__asm
		{
			push a3;
			push a2;
			mov eax, a1;
			call call_addr;
			add esp, 0x8;
		}
	}

	void Scr_TerminateThread(unsigned int a2/*@<edi>*/, scriptInstance_t a3/*@<esi>*/, void* call_addr)
	{
		__asm
		{
			mov edi, a2;
			mov esi, a3;
			call call_addr;
		}
	}

	void VM_Notify(scriptInstance_t inst/*@<eax>*/, int notifyListOwnerId, unsigned int stringValue, VariableValue * top, void* call_addr)
	{
		__asm
		{
			push top;
			push stringValue;
			push notifyListOwnerId;
			mov eax, inst;
			call call_addr;
			add esp, 0xC;
		}
	}

	void Scr_NotifyNum_Internal(scriptInstance_t inst/*@<eax>*/, int entNum, int entClass, unsigned int notifStr, int numParams, void* call_addr)
	{
		__asm
		{
			push numParams;
			push notifStr;
			push entClass;
			push entNum;
			mov eax, inst;
			call call_addr;
			add esp, 0x10;
		}
	}

	void Scr_CancelNotifyList(unsigned int notifyListOwnerId/*@<eax>*/, scriptInstance_t inst, void* call_addr)
	{
		__asm
		{
			push inst;
			mov eax, notifyListOwnerId;
			call call_addr;
			add esp, 0x4;
		}
	}

	void VM_TerminateTime(scriptInstance_t a1/*@<eax>*/, unsigned int parentId, void* call_addr)
	{
		__asm
		{
			push parentId;
			mov eax, a1;
			call call_addr;
			add esp, 0x4;
		}
	}

	void VM_Resume(scriptInstance_t inst/*@<eax>*/, unsigned int timeId, void* call_addr)
	{
		__asm
		{
			push timeId;
			mov eax, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	unsigned short Scr_ExecThread/*@<ax>*/(scriptInstance_t inst/*@<edi>*/, unsigned int handle, unsigned int paramCount, void* call_addr)
	{
		unsigned __int16 answer;
		
		__asm
		{
			push paramCount;
			push handle;
			mov edi, inst;
			call call_addr;
			mov answer, ax;
			add esp, 0x8;
		}
		
		return answer;
	}

	unsigned short Scr_ExecEntThreadNum/*@<ax>*/(scriptInstance_t inst/*@<edi>*/, int entNum, unsigned int handle, int numParams, unsigned int clientNum, void* call_addr)
	{
		unsigned __int16 answer;
		
		__asm
		{
			push clientNum;
			push numParams;
			push handle;
			push entNum;
			mov edi, inst;
			call call_addr;
			mov answer, ax;
			add esp, 0x10;
		}
		
		return answer;
	}

	void Scr_AddExecThread(scriptInstance_t a1/*@<edi>*/, unsigned int handle, void* call_addr)
	{
		__asm
		{
			push handle;
			mov edi, a1;
			call call_addr;
			add esp, 0x4;
		}
	}

	void VM_SetTime(scriptInstance_t a1/*@<eax>*/, void* call_addr)
	{
		__asm
		{
			mov eax, a1;
			call call_addr;
		}
	}

	void Scr_InitSystem(scriptInstance_t a1/*@<edi>*/, void* call_addr)
	{
		__asm
		{
			mov edi, a1;
			call call_addr;
		}
	}

	int Scr_GetInt/*@<eax>*/(scriptInstance_t inst/*@<eax>*/, unsigned int index/*@<ecx>*/, void* call_addr)
	{
		int answer;
		
		__asm
		{
			mov eax, inst;
			mov ecx, index;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	scr_anim_s Scr_GetAnim/*@<eax>*/(unsigned int index/*@<eax>*/, XAnimTree_s * a2/*@<ecx>*/, void* call_addr)
	{
		scr_anim_s answer;
		
		__asm
		{
			mov eax, index;
			mov ecx, a2;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	float Scr_GetFloat/*@<xmm0>*/(scriptInstance_t inst/*@<eax>*/, unsigned int index/*@<ecx>*/, void* call_addr)
	{
		float answer;
		
		__asm
		{
			mov eax, inst;
			mov ecx, index;
			call call_addr;
			movss answer, xmm0;
		}
		
		return answer;
	}

	unsigned int Scr_GetConstString/*@<eax>*/(scriptInstance_t inst/*@<eax>*/, unsigned int index, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			push index;
			mov eax, inst;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}
		
		return answer;
	}

	unsigned int Scr_GetConstLowercaseString/*@<eax>*/(scriptInstance_t inst/*@<ecx>*/, unsigned int index, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			push index;
			mov ecx, inst;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}
		
		return answer;
	}

	const char * Scr_GetString/*@<eax>*/(unsigned int index/*@<eax>*/, scriptInstance_t inst/*@<esi>*/, void* call_addr)
	{
		const char * answer;
		
		__asm
		{
			mov eax, index;
			mov esi, inst;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	unsigned int Scr_GetConstStringIncludeNull/*@<eax>*/(scriptInstance_t a1/*@<eax>*/, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			mov eax, a1;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	char * Scr_GetDebugString/*@<eax>*/(scriptInstance_t a1/*@<eax>*/, unsigned int a2/*@<ecx>*/, void* call_addr)
	{
		char * answer;
		
		__asm
		{
			mov eax, a1;
			mov ecx, a2;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	unsigned int Scr_GetConstIString/*@<eax>*/(unsigned int index/*@<eax>*/, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			mov eax, index;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	void Scr_GetVector(scriptInstance_t inst/*@<eax>*/, float * value/*@<ecx>*/, unsigned int index, void* call_addr)
	{
		__asm
		{
			push index;
			mov eax, inst;
			mov ecx, value;
			call call_addr;
			add esp, 0x4;
		}
	}

	scr_entref_t * Scr_GetEntityRef/*@<eax>*/(scriptInstance_t inst/*@<eax>*/, scr_entref_t * retstr, unsigned int index, void* call_addr)
	{
		scr_entref_t * answer;
		
		__asm
		{
			push index;
			push retstr;
			mov eax, inst;
			call call_addr;
			mov answer, eax;
			add esp, 0x8;
		}
		
		return answer;
	}

	VariableUnion Scr_GetObject/*@<eax>*/(scriptInstance_t a1/*@<eax>*/, void* call_addr)
	{
		VariableUnion answer;
		
		__asm
		{
			mov eax, a1;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	VariableType Scr_GetType/*@<eax>*/(scriptInstance_t inst/*@<eax>*/, unsigned int index/*@<ecx>*/, void* call_addr)
	{
		VariableType answer;
		
		__asm
		{
			mov eax, inst;
			mov ecx, index;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	char * Scr_GetTypeName/*@<eax>*/(scriptInstance_t a1/*@<eax>*/, void* call_addr)
	{
		char * answer;
		
		__asm
		{
			mov eax, a1;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	VariableType Scr_GetPointerType/*@<eax>*/(scriptInstance_t a1/*@<eax>*/, unsigned int a2/*@<ecx>*/, void* call_addr)
	{
		VariableType answer;
		
		__asm
		{
			mov eax, a1;
			mov ecx, a2;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	void Scr_AddInt(scriptInstance_t inst/*@<eax>*/, int value, void* call_addr)
	{
		__asm
		{
			push value;
			mov eax, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	void Scr_AddFloat(scriptInstance_t inst/*@<eax>*/, float value, void* call_addr)
	{
		__asm
		{
			push value;
			mov eax, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	void Scr_AddUndefined(scriptInstance_t inst/*@<eax>*/, void* call_addr)
	{
		__asm
		{
			mov eax, inst;
			call call_addr;
		}
	}

	void Scr_AddObject(scriptInstance_t inst/*@<eax>*/, unsigned int entid/*@<esi>*/, void* call_addr)
	{
		__asm
		{
			mov eax, inst;
			mov esi, entid;
			call call_addr;
		}
	}

	void Scr_AddString(scriptInstance_t inst/*@<eax>*/, const char * string, void* call_addr)
	{
		__asm
		{
			push string;
			mov eax, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	void Scr_AddIString(char * string/*@<esi>*/, void* call_addr)
	{
		__asm
		{
			mov esi, string;
			call call_addr;
		}
	}

	void Scr_AddConstString(scriptInstance_t inst/*@<eax>*/, unsigned int id/*@<esi>*/, void* call_addr)
	{
		__asm
		{
			mov eax, inst;
			mov esi, id;
			call call_addr;
		}
	}

	void Scr_AddVector(scriptInstance_t inst/*@<eax>*/, float * value, void* call_addr)
	{
		__asm
		{
			push value;
			mov eax, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	void Scr_MakeArray(scriptInstance_t a1/*@<eax>*/, void* call_addr)
	{
		__asm
		{
			mov eax, a1;
			call call_addr;
		}
	}

	void Scr_AddArrayStringIndexed(unsigned int id/*@<ecx>*/, scriptInstance_t inst/*@<edi>*/, void* call_addr)
	{
		__asm
		{
			mov ecx, id;
			mov edi, inst;
			call call_addr;
		}
	}

	void Scr_Error(const char * err/*@<ecx>*/, scriptInstance_t inst/*@<edi>*/, int is_terminal, void* call_addr)
	{
		__asm
		{
			push is_terminal;
			mov ecx, err;
			mov edi, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	void Scr_TerminalError(scriptInstance_t a1/*@<eax>*/, const char * Source, void* call_addr)
	{
		__asm
		{
			push Source;
			mov eax, a1;
			call call_addr;
			add esp, 0x4;
		}
	}

	void Scr_ParamError(int a1/*@<eax>*/, scriptInstance_t a2/*@<ecx>*/, const char * Source, void* call_addr)
	{
		__asm
		{
			push Source;
			mov eax, a1;
			mov ecx, a2;
			call call_addr;
			add esp, 0x4;
		}
	}

	void Scr_ObjectError(scriptInstance_t a1/*@<eax>*/, const char * a2/*@<ecx>*/, void* call_addr)
	{
		__asm
		{
			mov eax, a1;
			mov ecx, a2;
			call call_addr;
		}
	}

	bool SetEntityFieldValue/*@<al>*/(scriptInstance_t inst/*@<edi>*/, int offset_/*@<eax>*/, int entnum/*@<ecx>*/, classNum_e classnum, int clientNum, VariableValue * value, void* call_addr)
	{
		bool answer;
		
		__asm
		{
			push value;
			push clientNum;
			push classnum;
			mov edi, inst;
			mov eax, offset_;
			mov ecx, entnum;
			call call_addr;
			mov answer, al;
			add esp, 0xC;
		}
		
		return answer;
	}

	void Scr_SetStructField(unsigned int a1/*@<eax>*/, unsigned int a2/*@<ecx>*/, scriptInstance_t a3, void* call_addr)
	{
		__asm
		{
			push a3;
			mov eax, a1;
			mov ecx, a2;
			call call_addr;
			add esp, 0x4;
		}
	}

	void Scr_IncTime(scriptInstance_t a1/*@<eax>*/, void* call_addr)
	{
		__asm
		{
			mov eax, a1;
			call call_addr;
		}
	}

	void Scr_RunCurrentThreads(scriptInstance_t a1/*@<esi>*/, void* call_addr)
	{
		__asm
		{
			mov esi, a1;
			call call_addr;
		}
	}

	void Scr_ResetTimeout(scriptInstance_t a1/*@<eax>*/, void* call_addr)
	{
		__asm
		{
			mov eax, a1;
			call call_addr;
		}
	}

	void SetVariableFieldValue(scriptInstance_t inst, unsigned int id, VariableValue* value)
	{
		codsrc::SetVariableFieldValue(inst, id, value);
	}

	void SetNewVariableValue(scriptInstance_t inst, unsigned int id, VariableValue* value)
	{
		codsrc::SetNewVariableValue(inst, id, value);
	}

	void Scr_ClearErrorMessage(scriptInstance_t inst)
	{
		codsrc::Scr_ClearErrorMessage(inst);
	}

	void VM_Shutdown(scriptInstance_t inst)
	{
		codsrc::VM_Shutdown(inst);
	}

	void Scr_ShutdownVariables(scriptInstance_t inst)
	{
		codsrc::Scr_ShutdownVariables(inst);
	}

	void ClearVariableValue(scriptInstance_t inst, unsigned int id)
	{
		codsrc::ClearVariableValue(inst, id);
	}

	unsigned int Scr_GetThreadNotifyName(scriptInstance_t inst, unsigned int startLocalId)
	{
		return codsrc::Scr_GetThreadNotifyName(inst, startLocalId);
	}

	void Scr_RemoveThreadNotifyName(scriptInstance_t inst, unsigned int startLocalId)
	{
		codsrc::Scr_RemoveThreadNotifyName(inst, startLocalId);
	}

	unsigned int GetArraySize(scriptInstance_t inst, unsigned int id)
	{
		return codsrc::GetArraySize(inst, id);
	}

	void IncInParam(scriptInstance_t inst)
	{
		codsrc::IncInParam(inst);
	}

	unsigned int GetParentLocalId(scriptInstance_t inst, unsigned int threadId)
	{
		return codsrc::GetParentLocalId(inst, threadId);
	}

	void Scr_ClearWaitTime(scriptInstance_t inst, unsigned int startLocalId)
	{
		codsrc::Scr_ClearWaitTime(inst, startLocalId);
	}

	void Scr_SetThreadWaitTime(scriptInstance_t inst, unsigned int startLocalId, unsigned int waitTime)
	{
		codsrc::Scr_SetThreadWaitTime(inst, startLocalId, waitTime);
	}

	void Scr_SetThreadNotifyName(scriptInstance_t inst, unsigned int startLocalId, unsigned int stringValue)
	{
		codsrc::Scr_SetThreadNotifyName(inst, startLocalId, stringValue);
	}

	void Scr_DebugTerminateThread(scriptInstance_t inst, int topThread)
	{
		codsrc::Scr_DebugTerminateThread(inst, topThread);
	}

	unsigned int Scr_GetThreadWaitTime(scriptInstance_t inst, unsigned int startLocalId)
	{
		return codsrc::Scr_GetThreadWaitTime(inst, startLocalId);
	}

	const char* Scr_GetStackThreadPos(scriptInstance_t inst, unsigned int endLocalId, VariableStackBuffer* stackValue, bool killThread)
	{
		return codsrc::Scr_GetStackThreadPos(inst, endLocalId, stackValue, killThread);
	}

	unsigned int Scr_GetSelf(scriptInstance_t inst, unsigned int threadId)
	{
		return codsrc::Scr_GetSelf(inst, threadId);
	}

	unsigned int GetVariableKeyObject(scriptInstance_t inst, unsigned int id)
	{
		return codsrc::GetVariableKeyObject(inst, id);
	}

	int MT_Realloc(scriptInstance_t inst, int oldNumBytes, int newNumbytes)
	{
		return codsrc::MT_Realloc(inst, oldNumBytes, newNumbytes);
	}

	void CScr_GetObjectField(classNum_e classnum, int entnum, int clientNum, int offset)
	{
		codsrc::CScr_GetObjectField(classnum, entnum, clientNum, offset);
	}

	int CScr_SetObjectField(classNum_e classnum, int entnum, int clientNum, int offset)
	{
		return codsrc::CScr_SetObjectField(classnum, entnum, clientNum, offset);
	}

	void Scr_SetErrorMessage(scriptInstance_t inst, const char* error)
	{
		codsrc::Scr_SetErrorMessage(inst, error);
	}

	bool Scr_IsStackClear(scriptInstance_t inst)
	{
		return codsrc::Scr_IsStackClear(inst);
	}

	void SL_CheckExists(scriptInstance_t inst, unsigned int stringValue)
	{
		codsrc::SL_CheckExists(inst, stringValue);
	}

	const char* Scr_ReadCodePos(scriptInstance_t inst, const char** pos)
	{
		return codsrc::Scr_ReadCodePos(inst, pos);
	}

	unsigned int Scr_ReadUnsignedInt(scriptInstance_t inst, const char** pos)
	{
		return codsrc::Scr_ReadUnsignedInt(inst, pos);
	}

	unsigned short Scr_ReadUnsignedShort(scriptInstance_t inst, const char** pos)
	{
		return codsrc::Scr_ReadUnsignedShort(inst, pos);
	}

	unsigned char Scr_ReadUnsignedByte(scriptInstance_t inst, const char** pos)
	{
		return codsrc::Scr_ReadUnsignedByte(inst, pos);
	}

	float Scr_ReadFloat(scriptInstance_t inst, const char** pos)
	{
		return codsrc::Scr_ReadFloat(inst, pos);
	}

	const float* Scr_ReadVector(scriptInstance_t inst, const char** pos)
	{
		return codsrc::Scr_ReadVector(inst, pos);
	}

	BOOL IsFieldObject(scriptInstance_t inst, unsigned int id)
	{
		return codsrc::IsFieldObject(inst, id);
	}

	void RemoveVariableValue(scriptInstance_t inst, unsigned int parentId, unsigned int index)
	{
		codsrc::RemoveVariableValue(inst, parentId, index);
	}

	VariableStackBuffer* GetRefVariableStackBuffer(scriptInstance_t inst, int id)
	{
		return codsrc::GetRefVariableStackBuffer(inst, id);
	}

	unsigned int GetNewVariableIndexReverseInternal(scriptInstance_t inst, unsigned int parentId, unsigned int name)
	{
		return codsrc::GetNewVariableIndexReverseInternal(inst, parentId, name);
	}

	unsigned int GetNewObjectVariableReverse(scriptInstance_t inst, unsigned int parentId, unsigned int id)
	{
		return codsrc::GetNewObjectVariableReverse(inst, parentId, id);
	}

	unsigned int Scr_GetLocalVar(scriptInstance_t inst, int pos)
	{
		return codsrc::Scr_GetLocalVar(inst, pos);
	}

	void Scr_EvalBoolNot(scriptInstance_t inst, VariableValue* value)
	{
		codsrc::Scr_EvalBoolNot(inst, value);
	}

	unsigned int GetInternalVariableIndex(scriptInstance_t inst, unsigned int unsignedValue)
	{
		return codsrc::GetInternalVariableIndex(inst, unsignedValue);
	}

	const char* Scr_ReadData(scriptInstance_t inst, const char** pos, unsigned int count)
	{
		return codsrc::Scr_ReadData(inst, pos, count);
	}
}