#include <stdinc.hpp>
#include "loader/component_loader.hpp"
#include "utils/hook.hpp"
//#include "codsrc/clientscript/cscr_variable.hpp"

#define RE_CSCR_VARIABLE_USE_WRAPPERS


namespace re_cscr_variable
{
	utils::hook::detour ThreadInfoCompare_hook;
	utils::hook::detour Scr_DumpScriptThreads_hook;
	utils::hook::detour Scr_InitVariableRange_hook;
	utils::hook::detour Scr_InitClassMap_hook;
	utils::hook::detour GetNewVariableIndexInternal3_hook;
	utils::hook::detour GetNewVariableIndexInternal2_hook;
	utils::hook::detour GetNewVariableIndexReverseInternal2_hook;
	utils::hook::detour MakeVariableExternal_hook;
	utils::hook::detour FreeChildValue_hook;
	utils::hook::detour ClearObjectInternal_hook;
	utils::hook::detour ClearObject_hook;
	utils::hook::detour Scr_StopThread_hook;
	utils::hook::detour GetSafeParentLocalId_hook;
	utils::hook::detour GetStartLocalId_hook;
	utils::hook::detour Scr_KillThread_hook;
	utils::hook::detour AllocVariable_hook;
	utils::hook::detour FreeVariable_hook;
	utils::hook::detour AllocValue_hook;
	utils::hook::detour AllocEntity_hook;
	utils::hook::detour Scr_AllocArray_hook;
	utils::hook::detour AllocChildThread_hook;
	utils::hook::detour FreeValue_hook;
	utils::hook::detour RemoveRefToObject_hook;
	utils::hook::detour Scr_AllocVector_hook;
	utils::hook::detour RemoveRefToVector_hook;
	utils::hook::detour AddRefToValue_hook;
	utils::hook::detour RemoveRefToValueInternal_hook;
	utils::hook::detour FindArrayVariable_hook;
	utils::hook::detour FindVariable_hook;
	utils::hook::detour GetArrayVariableIndex_hook;
	utils::hook::detour Scr_GetVariableFieldIndex_hook;
	utils::hook::detour Scr_FindVariableField_hook;
	utils::hook::detour ClearVariableField_hook;
	utils::hook::detour GetVariable_hook;
	utils::hook::detour GetNewVariable_hook;
	utils::hook::detour GetObjectVariable_hook;
	utils::hook::detour GetNewObjectVariable_hook;
	utils::hook::detour RemoveVariable_hook;
	utils::hook::detour RemoveNextVariable_hook;
	utils::hook::detour SafeRemoveVariable_hook;
	utils::hook::detour CopyArray_hook;
	utils::hook::detour SetVariableValue_hook;
	utils::hook::detour SetVariableEntityFieldValue_hook;
	utils::hook::detour Scr_EvalVariable_hook;
	utils::hook::detour Scr_EvalVariableObject_hook;
	utils::hook::detour Scr_EvalVariableEntityField_hook;
	utils::hook::detour Scr_EvalVariableField_hook;
	utils::hook::detour Scr_EvalSizeValue_hook;
	utils::hook::detour GetObject_hook;
	utils::hook::detour GetArray_hook;
	utils::hook::detour Scr_EvalBoolComplement_hook;
	utils::hook::detour Scr_CastBool_hook;
	utils::hook::detour Scr_CastString_hook;
	utils::hook::detour Scr_CastDebugString_hook;
	utils::hook::detour Scr_ClearVector_hook;
	utils::hook::detour Scr_CastVector_hook;
	utils::hook::detour Scr_EvalFieldObject_hook;
	utils::hook::detour Scr_UnmatchingTypesError_hook;
	utils::hook::detour Scr_CastWeakerPair_hook;
	utils::hook::detour Scr_CastWeakerStringPair_hook;
	utils::hook::detour Scr_EvalOr_hook;
	utils::hook::detour Scr_EvalExOr_hook;
	utils::hook::detour Scr_EvalAnd_hook;
	utils::hook::detour Scr_EvalEquality_hook;
	utils::hook::detour Scr_EvalLess_hook;
	utils::hook::detour Scr_EvalGreaterEqual_hook;
	utils::hook::detour Scr_EvalGreater_hook;
	utils::hook::detour Scr_EvalLessEqual_hook;
	utils::hook::detour Scr_EvalShiftLeft_hook;
	utils::hook::detour Scr_EvalShiftRight_hook;
	utils::hook::detour Scr_EvalPlus_hook;
	utils::hook::detour Scr_EvalMinus_hook;
	utils::hook::detour Scr_EvalMultiply_hook;
	utils::hook::detour Scr_EvalDivide_hook;
	utils::hook::detour Scr_EvalMod_hook;
	utils::hook::detour Scr_EvalBinaryOperator_hook;
	utils::hook::detour Scr_FreeEntityNum_hook;
	utils::hook::detour Scr_FreeEntityList_hook;
	utils::hook::detour Scr_FreeObjects_hook;
	utils::hook::detour Scr_SetClassMap_hook;
	utils::hook::detour Scr_RemoveClassMap_hook;
	utils::hook::detour Scr_AddClassField_hook;
	utils::hook::detour Scr_GetOffset_hook;
	utils::hook::detour FindEntityId_hook;
	utils::hook::detour Scr_GetEntityId_hook;
	utils::hook::detour Scr_FindArrayIndex_hook;
	utils::hook::detour Scr_EvalArray_hook;
	utils::hook::detour Scr_EvalArrayRef_hook;
	utils::hook::detour ClearArray_hook;
	utils::hook::detour SetEmptyArray_hook;
	utils::hook::detour Scr_AddArrayKeys_hook;
	utils::hook::detour Scr_GetEntityIdRef_hook;
	utils::hook::detour CopyEntity_hook;
	utils::hook::detour Scr_GetEndonUsage_hook;
	utils::hook::detour Scr_GetObjectUsage_hook;
	utils::hook::detour Scr_GetThreadUsage_hook;
	utils::hook::detour Scr_FindField_hook;
	utils::hook::detour Scr_GetSourceFile_LoadObj_hook;
	utils::hook::detour Scr_GetSourceFile_FastFile_hook;
	utils::hook::detour Scr_AddFieldsForFile_hook;
	utils::hook::detour Scr_AddFields_LoadObj_hook;
	utils::hook::detour Scr_AddFields_FastFile_hook;
	utils::hook::detour Scr_MakeValuePrimitive_hook;
	utils::hook::detour Scr_FreeGameVariable_hook;
	utils::hook::detour Scr_SLHasLowercaseString_hook;

	void* ThreadInfoCompare_original;
	void* Scr_DumpScriptThreads_original;
	void* Scr_InitVariableRange_original;
	void* Scr_InitClassMap_original;
	void* GetNewVariableIndexInternal3_original;
	void* GetNewVariableIndexInternal2_original;
	void* GetNewVariableIndexReverseInternal2_original;
	void* MakeVariableExternal_original;
	void* FreeChildValue_original;
	void* ClearObjectInternal_original;
	void* ClearObject_original;
	void* Scr_StopThread_original;
	void* GetSafeParentLocalId_original;
	void* GetStartLocalId_original;
	void* Scr_KillThread_original;
	void* AllocVariable_original;
	void* FreeVariable_original;
	void* AllocValue_original;
	void* AllocEntity_original;
	void* Scr_AllocArray_original;
	void* AllocChildThread_original;
	void* FreeValue_original;
	void* RemoveRefToObject_original;
	void* Scr_AllocVector_original;
	void* RemoveRefToVector_original;
	void* AddRefToValue_original;
	void* RemoveRefToValueInternal_original;
	void* FindArrayVariable_original;
	void* FindVariable_original;
	void* GetArrayVariableIndex_original;
	void* Scr_GetVariableFieldIndex_original;
	void* Scr_FindVariableField_original;
	void* ClearVariableField_original;
	void* GetVariable_original;
	void* GetNewVariable_original;
	void* GetObjectVariable_original;
	void* GetNewObjectVariable_original;
	void* RemoveVariable_original;
	void* RemoveNextVariable_original;
	void* SafeRemoveVariable_original;
	void* CopyArray_original;
	void* SetVariableValue_original;
	void* SetVariableEntityFieldValue_original;
	void* Scr_EvalVariable_original;
	void* Scr_EvalVariableObject_original;
	void* Scr_EvalVariableEntityField_original;
	void* Scr_EvalVariableField_original;
	void* Scr_EvalSizeValue_original;
	void* GetObject_original;
	void* GetArray_original;
	void* Scr_EvalBoolComplement_original;
	void* Scr_CastBool_original;
	void* Scr_CastString_original;
	void* Scr_CastDebugString_original;
	void* Scr_ClearVector_original;
	void* Scr_CastVector_original;
	void* Scr_EvalFieldObject_original;
	void* Scr_UnmatchingTypesError_original;
	void* Scr_CastWeakerPair_original;
	void* Scr_CastWeakerStringPair_original;
	void* Scr_EvalOr_original;
	void* Scr_EvalExOr_original;
	void* Scr_EvalAnd_original;
	void* Scr_EvalEquality_original;
	void* Scr_EvalLess_original;
	void* Scr_EvalGreaterEqual_original;
	void* Scr_EvalGreater_original;
	void* Scr_EvalLessEqual_original;
	void* Scr_EvalShiftLeft_original;
	void* Scr_EvalShiftRight_original;
	void* Scr_EvalPlus_original;
	void* Scr_EvalMinus_original;
	void* Scr_EvalMultiply_original;
	void* Scr_EvalDivide_original;
	void* Scr_EvalMod_original;
	void* Scr_EvalBinaryOperator_original;
	void* Scr_FreeEntityNum_original;
	void* Scr_FreeEntityList_original;
	void* Scr_FreeObjects_original;
	void* Scr_SetClassMap_original;
	void* Scr_RemoveClassMap_original;
	void* Scr_AddClassField_original;
	void* Scr_GetOffset_original;
	void* FindEntityId_original;
	void* Scr_GetEntityId_original;
	void* Scr_FindArrayIndex_original;
	void* Scr_EvalArray_original;
	void* Scr_EvalArrayRef_original;
	void* ClearArray_original;
	void* SetEmptyArray_original;
	void* Scr_AddArrayKeys_original;
	void* Scr_GetEntityIdRef_original;
	void* CopyEntity_original;
	void* Scr_GetEndonUsage_original;
	void* Scr_GetObjectUsage_original;
	void* Scr_GetThreadUsage_original;
	void* Scr_FindField_original;
	void* Scr_GetSourceFile_LoadObj_original;
	void* Scr_GetSourceFile_FastFile_original;
	void* Scr_AddFieldsForFile_original;
	void* Scr_AddFields_LoadObj_original;
	void* Scr_AddFields_FastFile_original;
	void* Scr_MakeValuePrimitive_original;
	void* Scr_FreeGameVariable_original;
	void* Scr_SLHasLowercaseString_original;

	namespace
	{

		int ThreadInfoCompare_stub(game::ThreadDebugInfo * a1, game::ThreadDebugInfo * a2)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return ThreadInfoCompare_hook.invoke<int>(a1, a2);
#else
			return codsrc::ThreadInfoCompare(a1, a2);
#endif
		}

		void Scr_DumpScriptThreads_stub(game::scriptInstance_t scriptInstance)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			Scr_DumpScriptThreads_hook.invoke<void>(scriptInstance);
#else
			codsrc::Scr_DumpScriptThreads(scriptInstance);
#endif
		}

		void Scr_InitVariableRange_call(unsigned int a1, unsigned int a2, [[maybe_unused]] void* caller_addr, game::scriptInstance_t a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_InitVariableRange(a1, a2, a3, Scr_InitVariableRange_original);
#else
			codsrc::Scr_InitVariableRange(a1, a2, a3);
#endif
		}

		// void __usercall Scr_InitVariableRange(unsigned int a1@<edi>, unsigned int a2@<esi>, game::scriptInstance_t a3)
		NAKED void Scr_InitVariableRange_stub()
		{
			_asm
			{
				push esi;
				push edi;
				call Scr_InitVariableRange_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_InitClassMap_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_InitClassMap(a1, Scr_InitClassMap_original);
#else
			codsrc::Scr_InitClassMap(a1);
#endif
		}

		// void __usercall Scr_InitClassMap(game::scriptInstance_t a1@<eax>)
		NAKED void Scr_InitClassMap_stub()
		{
			_asm
			{
				push eax;
				call Scr_InitClassMap_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int GetNewVariableIndexInternal3_stub(game::scriptInstance_t inst, unsigned int parentId, unsigned int name, unsigned int index)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return GetNewVariableIndexInternal3_hook.invoke<unsigned int>(inst, parentId, name, index);
#else
			return codsrc::GetNewVariableIndexInternal3(inst, parentId, name, index);
#endif
		}

		unsigned int GetNewVariableIndexInternal2_call(unsigned int name, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, unsigned int parentId, unsigned int index)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::GetNewVariableIndexInternal2(name, inst, parentId, index, GetNewVariableIndexInternal2_original);
#else
			return codsrc::GetNewVariableIndexInternal2(name, inst, parentId, index);
#endif
		}

		// unsigned int __usercall GetNewVariableIndexInternal2@<eax>(unsigned int name@<ecx>, game::scriptInstance_t inst, unsigned int parentId, unsigned int index)
		NAKED unsigned int GetNewVariableIndexInternal2_stub()
		{
			_asm
			{
				push ecx;
				call GetNewVariableIndexInternal2_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int GetNewVariableIndexReverseInternal2_call(unsigned int name, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, unsigned int parentId, unsigned int index)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::GetNewVariableIndexReverseInternal2(name, inst, parentId, index, GetNewVariableIndexReverseInternal2_original);
#else
			return codsrc::GetNewVariableIndexReverseInternal2(name, inst, parentId, index);
#endif
		}

		// unsigned int __usercall GetNewVariableIndexReverseInternal2@<eax>(unsigned int name@<ecx>, game::scriptInstance_t inst, unsigned int parentId, unsigned int index)
		NAKED unsigned int GetNewVariableIndexReverseInternal2_stub()
		{
			_asm
			{
				push ecx;
				call GetNewVariableIndexReverseInternal2_call;
				add esp, 0x4;
				ret;
			}
		}

		void MakeVariableExternal_call(game::VariableValueInternal * parentValue, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, unsigned int index)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::MakeVariableExternal(parentValue, inst, index, MakeVariableExternal_original);
#else
			codsrc::MakeVariableExternal(parentValue, inst, index);
#endif
		}

		// void __usercall MakeVariableExternal(game::VariableValueInternal *parentValue@<eax>, game::scriptInstance_t inst, unsigned int index)
		NAKED void MakeVariableExternal_stub()
		{
			_asm
			{
				push eax;
				call MakeVariableExternal_call;
				add esp, 0x4;
				ret;
			}
		}

		void FreeChildValue_call(unsigned int id, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, unsigned int parentId)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::FreeChildValue(id, inst, parentId, FreeChildValue_original);
#else
			codsrc::FreeChildValue(id, inst, parentId);
#endif
		}

		// void __usercall FreeChildValue(unsigned int id@<eax>, game::scriptInstance_t inst, unsigned int parentId)
		NAKED void FreeChildValue_stub()
		{
			_asm
			{
				push eax;
				call FreeChildValue_call;
				add esp, 0x4;
				ret;
			}
		}

		void ClearObjectInternal_stub(game::scriptInstance_t inst, unsigned int parentId)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			ClearObjectInternal_hook.invoke<void>(inst, parentId);
#else
			codsrc::ClearObjectInternal(inst, parentId);
#endif
		}

		void ClearObject_call(unsigned int a1, [[maybe_unused]] void* caller_addr, game::scriptInstance_t a2)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::ClearObject(a1, a2, ClearObject_original);
#else
			codsrc::ClearObject(a1, a2);
#endif
		}

		// void __usercall ClearObject(unsigned int a1@<edi>, game::scriptInstance_t a2)
		NAKED void ClearObject_stub()
		{
			_asm
			{
				push edi;
				call ClearObject_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_StopThread_call(game::scriptInstance_t inst, unsigned int a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_StopThread(inst, a2, Scr_StopThread_original);
#else
			codsrc::Scr_StopThread(inst, a2);
#endif
		}

		// void __usercall Scr_StopThread(game::scriptInstance_t inst@<ecx>, unsigned int a2@<eax>)
		NAKED void Scr_StopThread_stub()
		{
			_asm
			{
				push eax;
				push ecx;
				call Scr_StopThread_call;
				add esp, 0x8;
				ret;
			}
		}

		unsigned int GetSafeParentLocalId_call(game::scriptInstance_t a1, [[maybe_unused]] unsigned int localId, [[maybe_unused]] void* caller_addr, unsigned int a2)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::GetSafeParentLocalId(a1, a2, GetSafeParentLocalId_original);
#else
			return codsrc::GetSafeParentLocalId(a1, a2);
#endif
		}

		// unsigned int __usercall __spoils<eax,ecx> GetSafeParentLocalId@<eax>(game::scriptInstance_t inst@<eax>, unsigned int parentId)
		NAKED unsigned int GetSafeParentLocalId_stub()
		{
			_asm
			{
				push edx;

				push eax;
				call GetSafeParentLocalId_call;
				add esp, 0x4;

				pop edx;

				ret;
			}
		}

		unsigned int GetStartLocalId_call(unsigned int result, game::scriptInstance_t a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::GetStartLocalId(result, a2, GetStartLocalId_original);
#else
			return codsrc::GetStartLocalId(result, a2);
#endif
		}

		// unsigned int __usercall GetStartLocalId@<eax>(unsigned int result@<eax>, game::scriptInstance_t a2@<ecx>)
		NAKED unsigned int GetStartLocalId_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call GetStartLocalId_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_KillThread_call(game::scriptInstance_t inst, unsigned int parentId_1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_KillThread(inst, parentId_1, Scr_KillThread_original);
#else
			codsrc::Scr_KillThread(inst, parentId_1);
#endif
		}

		// void __usercall Scr_KillThread(game::scriptInstance_t inst@<ecx>, unsigned int parentId_1@<eax>)
		NAKED void Scr_KillThread_stub()
		{
			_asm
			{
				push eax;
				push ecx;
				call Scr_KillThread_call;
				add esp, 0x8;
				ret;
			}
		}

		unsigned __int16 AllocVariable_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::AllocVariable(inst, AllocVariable_original);
#else
			return codsrc::AllocVariable(inst);
#endif
		}

		// unsigned __int16 __usercall AllocVariable@<ax>(game::scriptInstance_t inst@<eax>)
		NAKED unsigned __int16 AllocVariable_stub()
		{
			_asm
			{
				push eax;
				call AllocVariable_call;
				add esp, 0x4;
				ret;
			}
		}

		void FreeVariable_call(unsigned int a1, game::scriptInstance_t a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::FreeVariable(a1, a2, FreeVariable_original);
#else
			codsrc::FreeVariable(a1, a2);
#endif
		}

		// int __usercall FreeVariable@<eax>(int a1@<eax>, game::scriptInstance_t a2@<edx>)
		NAKED int FreeVariable_stub()
		{
			_asm
			{
				push edx;
				push eax;
				call FreeVariable_call;
				add esp, 0x8;
				ret;
			}
		}

		unsigned int AllocValue_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::AllocValue(inst, AllocValue_original);
#else
			return codsrc::AllocValue(inst);
#endif
		}

		// unsigned int __usercall AllocValue@<eax>(game::scriptInstance_t inst@<eax>)
		NAKED unsigned int AllocValue_stub()
		{
			_asm
			{
				push eax;
				call AllocValue_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int AllocEntity_call(int classnum, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, int entnum, unsigned int clientnum)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::AllocEntity(classnum, inst, entnum, clientnum, AllocEntity_original);
#else
			return codsrc::AllocEntity(classnum, inst, entnum, clientnum);
#endif
		}

		// unsigned int __usercall AllocEntity@<eax>(int classnum@<eax>, game::scriptInstance_t inst@<ecx>, int entnum, unsigned int clientnum)
		NAKED unsigned int AllocEntity_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call AllocEntity_call;
				add esp, 0x8;
				ret;
			}
		}

		unsigned int Scr_AllocArray_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::Scr_AllocArray(a1, Scr_AllocArray_original);
#else
			return codsrc::Scr_AllocArray(a1);
#endif
		}

		// unsigned int __usercall Scr_AllocArray@<eax>(game::scriptInstance_t a1@<eax>)
		NAKED unsigned int Scr_AllocArray_stub()
		{
			_asm
			{
				push eax;
				call Scr_AllocArray_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int AllocChildThread_call(game::scriptInstance_t inst, unsigned int a2, [[maybe_unused]] void* caller_addr, unsigned int a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::AllocChildThread(inst, a2, a3, AllocChildThread_original);
#else
			return codsrc::AllocChildThread(inst, a2, a3);
#endif
		}

		// unsigned int __usercall AllocChildThread@<eax>(game::scriptInstance_t inst@<ecx>, unsigned int a2@<eax>, unsigned int a3)
		NAKED unsigned int AllocChildThread_stub()
		{
			_asm
			{
				push eax;
				push ecx;
				call AllocChildThread_call;
				add esp, 0x8;
				ret;
			}
		}

		void FreeValue_call(unsigned int id, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::FreeValue(id, inst, FreeValue_original);
#else
			codsrc::FreeValue(id, inst);
#endif
		}

		// void __usercall FreeValue(unsigned int id@<eax>, game::scriptInstance_t inst)
		NAKED void FreeValue_stub()
		{
			_asm
			{
				push eax;
				call FreeValue_call;
				add esp, 0x4;
				ret;
			}
		}

		void RemoveRefToObject_call(unsigned int id, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::RemoveRefToObject(id, inst, RemoveRefToObject_original);
#else
			codsrc::RemoveRefToObject(id, inst);
#endif
		}

		// void __usercall RemoveRefToObject(unsigned int id@<eax>, game::scriptInstance_t inst@<ecx>)
		NAKED void RemoveRefToObject_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call RemoveRefToObject_call;
				add esp, 0x8;
				ret;
			}
		}

		float * Scr_AllocVector_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::Scr_AllocVector(a1, Scr_AllocVector_original);
#else
			return codsrc::Scr_AllocVector(a1);
#endif
		}

		// float *__usercall Scr_AllocVector@<eax>(game::scriptInstance_t a1@<eax>)
		NAKED float * Scr_AllocVector_stub()
		{
			_asm
			{
				push eax;
				call Scr_AllocVector_call;
				add esp, 0x4;
				ret;
			}
		}

		void RemoveRefToVector_call(const float* vecVal, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::RemoveRefToVector(vecVal, inst, RemoveRefToVector_original);
#else
			codsrc::RemoveRefToVector(vecVal, inst);
#endif
		}

		// void __usercall RemoveRefToVector(int vecVal@<eax>, game::scriptInstance_t inst)
		NAKED void RemoveRefToVector_stub()
		{
			_asm
			{
				push eax;
				call RemoveRefToVector_call;
				add esp, 0x4;
				ret;
			}
		}

		void AddRefToValue_call(game::scriptInstance_t inst, game::VariableType type_, [[maybe_unused]] void* caller_addr, game::VariableUnion u)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::AddRefToValue(inst, type_, u, AddRefToValue_original);
#else
			codsrc::AddRefToValue(inst, type_, u);
#endif
		}

		// void __usercall AddRefToValue(game::scriptInstance_t inst@<eax>, game::VariableType type@<ecx>, game::VariableUnion u)
		NAKED void AddRefToValue_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call AddRefToValue_call;
				add esp, 0x8;
				ret;
			}
		}

		void RemoveRefToValueInternal_stub(game::scriptInstance_t inst, game::VariableType type, game::VariableUnion a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			RemoveRefToValueInternal_hook.invoke<void>(inst, type, a3);
#else
			codsrc::RemoveRefToValueInternal(inst, type, a3);
#endif
		}

		int FindArrayVariable_call(unsigned int id, unsigned int intvalue, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::FindArrayVariable(id, intvalue, inst, FindArrayVariable_original);
#else
			return codsrc::FindArrayVariable(id, intvalue, inst);
#endif
		}

		// int __usercall FindArrayVariable@<eax>(unsigned int id@<eax>, unsigned int intvalue@<ecx>, game::scriptInstance_t inst)
		NAKED int FindArrayVariable_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call FindArrayVariable_call;
				add esp, 0x8;
				ret;
			}
		}

		int FindVariable_call(int name, int a2, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::FindVariable(name, a2, inst, FindVariable_original);
#else
			return codsrc::FindVariable(name, a2, inst);
#endif
		}

		// int __usercall FindVariable@<eax>(int name@<ecx>, int a2@<eax>, game::scriptInstance_t inst)
		NAKED int FindVariable_stub()
		{
			_asm
			{
				push eax;
				push ecx;
				call FindVariable_call;
				add esp, 0x8;
				ret;
			}
		}

		unsigned int GetArrayVariableIndex_call(unsigned int unsignedValue, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, unsigned int parentId)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::GetArrayVariableIndex(unsignedValue, inst, parentId, GetArrayVariableIndex_original);
#else
			return codsrc::GetArrayVariableIndex(unsignedValue, inst, parentId);
#endif
		}

		// unsigned int __usercall GetArrayVariableIndex@<eax>(unsigned int unsignedValue@<eax>, game::scriptInstance_t inst, unsigned int parentId)
		NAKED unsigned int GetArrayVariableIndex_stub()
		{
			_asm
			{
				push eax;
				call GetArrayVariableIndex_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int Scr_GetVariableFieldIndex_call(game::scriptInstance_t a1, unsigned int name, [[maybe_unused]] void* caller_addr, unsigned int parentId)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::Scr_GetVariableFieldIndex(a1, name, parentId, Scr_GetVariableFieldIndex_original);
#else
			return codsrc::Scr_GetVariableFieldIndex(a1, name, parentId);
#endif
		}

		// unsigned int __usercall Scr_GetVariableFieldIndex@<eax>(game::scriptInstance_t a1@<eax>, unsigned int name@<esi>, unsigned int parentId)
		NAKED unsigned int Scr_GetVariableFieldIndex_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call Scr_GetVariableFieldIndex_call;
				add esp, 0x8;
				ret;
			}
		}

		game::VariableValue Scr_FindVariableField_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, unsigned int parentId, unsigned int name)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::Scr_FindVariableField(inst, parentId, name, Scr_FindVariableField_original);
#else
			return codsrc::Scr_FindVariableField(inst, parentId, name);
#endif
		}

		// game::VariableValue __usercall Scr_FindVariableField@<edx:eax>(game::scriptInstance_t inst@<edi>, unsigned int parentId, unsigned int name)
		NAKED game::VariableValue Scr_FindVariableField_stub()
		{
			_asm
			{
				push edi;
				call Scr_FindVariableField_call;
				add esp, 4;
				ret;
			}
		}

		void ClearVariableField_call(game::scriptInstance_t inst, unsigned int id, [[maybe_unused]] void* caller_addr, unsigned int name, game::VariableValue * value)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::ClearVariableField(inst, id, name, value, ClearVariableField_original);
#else
			codsrc::ClearVariableField(inst, id, name, value);
#endif
		}

		// void __usercall ClearVariableField(game::scriptInstance_t inst@<ecx>, unsigned int id@<eax>, unsigned int name, game::VariableValue *value)
		NAKED void ClearVariableField_stub()
		{
			_asm
			{
				push eax;
				push ecx;
				call ClearVariableField_call;
				add esp, 0x8;
				ret;
			}
		}

		unsigned int GetVariable_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, unsigned int parentId, unsigned int name)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::GetVariable(a1, parentId, name, GetVariable_original);
#else
			return codsrc::GetVariable(a1, parentId, name);
#endif
		}

		// unsigned int __usercall GetVariable@<eax>(game::scriptInstance_t a1@<eax>, unsigned int parentId, unsigned int name)
		NAKED unsigned int GetVariable_stub()
		{
			_asm
			{
				push eax;
				call GetVariable_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int GetNewVariable_call(game::scriptInstance_t a1, unsigned int a2, unsigned int a3, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::GetNewVariable(a1, a2, a3, GetNewVariable_original);
#else
			return codsrc::GetNewVariable(a1, a2, a3);
#endif
		}

		// unsigned int __usercall GetNewVariable@<eax>(game::scriptInstance_t a1@<eax>, unsigned int a2@<ecx>, unsigned int a3@<edi>)
		NAKED unsigned int GetNewVariable_stub()
		{
			_asm
			{
				push edi;
				push ecx;
				push eax;
				call GetNewVariable_call;
				add esp, 0xC;
				ret;
			}
		}

		unsigned int GetObjectVariable_call(unsigned int a1, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, unsigned int parentId)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::GetObjectVariable(a1, inst, parentId, GetObjectVariable_original);
#else
			return codsrc::GetObjectVariable(a1, inst, parentId);
#endif
		}

		// unsigned int __usercall GetObjectVariable@<eax>(unsigned int a1@<eax>, game::scriptInstance_t inst, unsigned int parentId)
		NAKED unsigned int GetObjectVariable_stub()
		{
			_asm
			{
				push eax;
				call GetObjectVariable_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int GetNewObjectVariable_call(game::scriptInstance_t inst, unsigned int name, unsigned int parentId, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::GetNewObjectVariable(inst, name, parentId, GetNewObjectVariable_original);
#else
			return codsrc::GetNewObjectVariable(inst, name, parentId);
#endif
		}

		// unsigned int __usercall GetNewObjectVariable@<eax>(game::scriptInstance_t inst@<eax>, unsigned int name@<ecx>, unsigned int parentId@<edi>)
		NAKED unsigned int GetNewObjectVariable_stub()
		{
			_asm
			{
				push edi;
				push ecx;
				push eax;
				call GetNewObjectVariable_call;
				add esp, 0xC;
				ret;
			}
		}

		void RemoveVariable_call(unsigned int name, unsigned int a2, game::scriptInstance_t a3, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::RemoveVariable(name, a2, a3, RemoveVariable_original);
#else
			codsrc::RemoveVariable(name, a2, a3);
#endif
		}

		// void __usercall RemoveVariable(unsigned int name@<ecx>, unsigned int a2@<edi>, game::scriptInstance_t a3@<esi>)
		NAKED void RemoveVariable_stub()
		{
			_asm
			{
				push esi;
				push edi;
				push ecx;
				call RemoveVariable_call;
				add esp, 0xC;
				ret;
			}
		}

		void RemoveNextVariable_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, unsigned int parentId)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::RemoveNextVariable(a1, parentId, RemoveNextVariable_original);
#else
			codsrc::RemoveNextVariable(a1, parentId);
#endif
		}

		// void __usercall RemoveNextVariable(game::scriptInstance_t a1@<edi>, unsigned int parentId)
		NAKED void RemoveNextVariable_stub()
		{
			_asm
			{
				push edi;
				call RemoveNextVariable_call;
				add esp, 0x4;
				ret;
			}
		}

		void SafeRemoveVariable_call(unsigned int unsignedValue, unsigned int parentId, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::SafeRemoveVariable(unsignedValue, parentId, inst, SafeRemoveVariable_original);
#else
			codsrc::SafeRemoveVariable(unsignedValue, parentId, inst);
#endif
		}

		// void __usercall SafeRemoveVariable(unsigned int unsignedValue@<ecx>, unsigned int parentId@<edi>, game::scriptInstance_t inst@<esi>)
		NAKED void SafeRemoveVariable_stub()
		{
			_asm
			{
				push esi;
				push edi;
				push ecx;
				call SafeRemoveVariable_call;
				add esp, 0xC;
				ret;
			}
		}

		void CopyArray_stub(game::scriptInstance_t inst, unsigned int parentId, unsigned int newParentId)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			CopyArray_hook.invoke<void>(inst, parentId, newParentId);
#else
			codsrc::CopyArray(inst, parentId, newParentId);
#endif
		}

		void SetVariableValue_call(game::scriptInstance_t a1, game::VariableValue * a2, [[maybe_unused]] void* caller_addr, unsigned int a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::SetVariableValue(a1, a2, a3, SetVariableValue_original);
#else
			codsrc::SetVariableValue(a1, a2, a3);
#endif
		}

		// void __usercall SetVariableValue(game::scriptInstance_t a1@<eax>, game::VariableValue *a2@<edi>, unsigned int a3)
		NAKED void SetVariableValue_stub()
		{
			_asm
			{
				push edi;
				push eax;
				call SetVariableValue_call;
				add esp, 0x8;
				ret;
			}
		}

		void SetVariableEntityFieldValue_stub(game::scriptInstance_t inst, unsigned int parentId, unsigned int name, game::VariableValue * a4)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			SetVariableEntityFieldValue_hook.invoke<void>(inst, parentId, name, a4);
#else
			codsrc::SetVariableEntityFieldValue(inst, parentId, name, a4);
#endif
		}

		game::VariableValue Scr_EvalVariable_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, unsigned int a2)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::Scr_EvalVariable(a1, a2, Scr_EvalVariable_original);
#else
			return codsrc::Scr_EvalVariable(a1, a2);
#endif
		}

		// game::VariableValue __usercall Scr_EvalVariable@<edx:eax>(game::scriptInstance_t a1@<eax>, unsigned int a2)
		NAKED game::VariableValue Scr_EvalVariable_stub()
		{
			_asm
			{
				push eax;
				call Scr_EvalVariable_call;
				add esp, 4;
				ret;
			}
		}

		unsigned int Scr_EvalVariableObject_call(game::scriptInstance_t inst, int a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::Scr_EvalVariableObject(inst, a2, Scr_EvalVariableObject_original);
#else
			return codsrc::Scr_EvalVariableObject(inst, a2);
#endif
		}

		// unsigned int __usercall Scr_EvalVariableObject@<eax>(game::scriptInstance_t inst@<ecx>, int a2@<eax>)
		NAKED unsigned int Scr_EvalVariableObject_stub()
		{
			_asm
			{
				push eax;
				push ecx;
				call Scr_EvalVariableObject_call;
				add esp, 0x8;
				ret;
			}
		}

		game::VariableValue Scr_EvalVariableEntityField_call(unsigned int entId, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, unsigned int name)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::Scr_EvalVariableEntityField(entId, inst, name, Scr_EvalVariableEntityField_original);
#else
			return codsrc::Scr_EvalVariableEntityField(entId, inst, name);
#endif
		}

		// game::VariableValue __usercall Scr_EvalVariableEntityField@<edx:eax>(unsigned int entId@<ecx>, game::scriptInstance_t inst, unsigned int name)
		NAKED game::VariableValue Scr_EvalVariableEntityField_stub()
		{
			_asm
			{
				push ecx;
				call Scr_EvalVariableEntityField_call;
				add esp, 0x4;
				ret;
			}
		}

		game::VariableValue Scr_EvalVariableField_call(game::scriptInstance_t inst, unsigned int id, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::Scr_EvalVariableField(inst, id, Scr_EvalVariableField_original);
#else
			return codsrc::Scr_EvalVariableField(inst, id);
#endif
		}

		// game::VariableValue __usercall Scr_EvalVariableField@<edx:eax>(game::scriptInstance_t inst@<eax>, unsigned int id@<edx>)
		NAKED game::VariableValue Scr_EvalVariableField_stub()
		{
			_asm
			{
				push edx;
				push eax;
				call Scr_EvalVariableField_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_EvalSizeValue_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, game::VariableValue * value)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_EvalSizeValue(a1, value, Scr_EvalSizeValue_original);
#else
			codsrc::Scr_EvalSizeValue(a1, value);
#endif
		}

		// void __usercall Scr_EvalSizeValue(game::scriptInstance_t a1@<eax>, game::VariableValue *value)
		NAKED void Scr_EvalSizeValue_stub()
		{
			_asm
			{
				push eax;
				call Scr_EvalSizeValue_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int GetObject_call(game::scriptInstance_t a1, unsigned int a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::GetObject(a1, a2, GetObject_original);
#else
			return codsrc::GetObject(a1, a2);
#endif
		}

		// VariableValueInternal_u __usercall GetObject@<eax>(game::scriptInstance_t a1@<eax>, unsigned int a2@<ecx>)
		NAKED unsigned int GetObject_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call GetObject_call;
				add esp, 0x8;
				ret;
			}
		}

		unsigned int GetArray_call(game::scriptInstance_t inst, unsigned int a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::GetArray(inst, a2, GetArray_original);
#else
			return codsrc::GetArray(inst, a2);
#endif
		}

		// unsigned int __usercall GetArray@<eax>(game::scriptInstance_t inst@<eax>, unsigned int a2@<ecx>)
		NAKED unsigned int GetArray_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call GetArray_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_EvalBoolComplement_call(game::scriptInstance_t a1, game::VariableValue * a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_EvalBoolComplement(a1, a2, Scr_EvalBoolComplement_original);
#else
			codsrc::Scr_EvalBoolComplement(a1, a2);
#endif
		}

		// void __usercall Scr_EvalBoolComplement(game::scriptInstance_t a1@<eax>, game::VariableValue *a2@<esi>)
		NAKED void Scr_EvalBoolComplement_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call Scr_EvalBoolComplement_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_CastBool_call(game::scriptInstance_t a1, game::VariableValue * a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_CastBool(a1, a2, Scr_CastBool_original);
#else
			codsrc::Scr_CastBool(a1, a2);
#endif
		}

		// void __usercall Scr_CastBool(game::scriptInstance_t a1@<eax>, game::VariableValue *a2@<esi>)
		NAKED void Scr_CastBool_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call Scr_CastBool_call;
				add esp, 0x8;
				ret;
			}
		}

		char Scr_CastString_call(game::scriptInstance_t a1, game::VariableValue * a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::Scr_CastString(a1, a2, Scr_CastString_original);
#else
			return codsrc::Scr_CastString(a1, a2);
#endif
		}

		// char __usercall Scr_CastString@<al>(game::scriptInstance_t a1@<edi>, game::VariableValue *a2@<esi>)
		NAKED char Scr_CastString_stub()
		{
			_asm
			{
				push esi;
				push edi;
				call Scr_CastString_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_CastDebugString_call(game::scriptInstance_t a1, game::VariableValue * a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_CastDebugString(a1, a2, Scr_CastDebugString_original);
#else
			codsrc::Scr_CastDebugString(a1, a2);
#endif
		}

		// void __usercall Scr_CastDebugString(game::scriptInstance_t a1@<ecx>, game::VariableValue *a2@<eax>)
		NAKED void Scr_CastDebugString_stub()
		{
			_asm
			{
				push eax;
				push ecx;
				call Scr_CastDebugString_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_ClearVector_stub(game::scriptInstance_t inst, game::VariableValue * a2)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			Scr_ClearVector_hook.invoke<void>(inst, a2);
#else
			codsrc::Scr_ClearVector(inst, a2);
#endif
		}

		void Scr_CastVector_call(game::scriptInstance_t a1, game::VariableValue * a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_CastVector(a1, a2, Scr_CastVector_original);
#else
			codsrc::Scr_CastVector(a1, a2);
#endif
		}

		// void __usercall Scr_CastVector(game::scriptInstance_t a1@<eax>, game::VariableValue *a2@<esi>)
		NAKED void Scr_CastVector_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call Scr_CastVector_call;
				add esp, 0x8;
				ret;
			}
		}

		game::VariableUnion Scr_EvalFieldObject_call(game::VariableValue * a1, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, int a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::Scr_EvalFieldObject(a1, inst, a3, Scr_EvalFieldObject_original);
#else
			return codsrc::Scr_EvalFieldObject(a1, inst, a3);
#endif
		}

		// game::VariableUnion __usercall Scr_EvalFieldObject@<eax>(game::VariableValue *a1@<eax>, game::scriptInstance_t inst, int a3)
		NAKED game::VariableUnion Scr_EvalFieldObject_stub()
		{
			_asm
			{
				push eax;
				call Scr_EvalFieldObject_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_UnmatchingTypesError_call(game::scriptInstance_t a1, game::VariableValue * a2, [[maybe_unused]] void* caller_addr, game::VariableValue * value)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_UnmatchingTypesError(a1, a2, value, Scr_UnmatchingTypesError_original);
#else
			codsrc::Scr_UnmatchingTypesError(a1, a2, value);
#endif
		}

		// void __usercall Scr_UnmatchingTypesError(game::scriptInstance_t a1@<eax>, game::VariableValue *a2@<esi>, game::VariableValue *value)
		NAKED void Scr_UnmatchingTypesError_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call Scr_UnmatchingTypesError_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_CastWeakerPair_call(game::VariableValue * a1, game::VariableValue * a2, game::scriptInstance_t a3, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_CastWeakerPair(a1, a2, a3, Scr_CastWeakerPair_original);
#else
			codsrc::Scr_CastWeakerPair(a1, a2, a3);
#endif
		}

		// void __usercall Scr_CastWeakerPair(game::VariableValue *a1@<ecx>, game::VariableValue *a2@<edi>, game::scriptInstance_t a3@<eax>)
		NAKED void Scr_CastWeakerPair_stub()
		{
			_asm
			{
				push eax;
				push edi;
				push ecx;
				call Scr_CastWeakerPair_call;
				add esp, 0xC;
				ret;
			}
		}

		void Scr_CastWeakerStringPair_call(game::VariableValue * a1, game::VariableValue * a2, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_CastWeakerStringPair(a1, a2, inst, Scr_CastWeakerStringPair_original);
#else
			codsrc::Scr_CastWeakerStringPair(a1, a2, inst);
#endif
		}

		// void __usercall Scr_CastWeakerStringPair(game::VariableValue *a1@<eax>, game::VariableValue *a2@<ecx>, game::scriptInstance_t inst)
		NAKED void Scr_CastWeakerStringPair_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_CastWeakerStringPair_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_EvalOr_call(game::VariableValue * result, game::VariableValue * a2, [[maybe_unused]] void* caller_addr, game::scriptInstance_t a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_EvalOr(result, a2, a3, Scr_EvalOr_original);
#else
			codsrc::Scr_EvalOr(result, a2, a3);
#endif
		}

		// void __usercall Scr_EvalOr(game::VariableValue *result@<eax>, game::VariableValue *a2@<ecx>, game::scriptInstance_t a3)
		NAKED void Scr_EvalOr_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_EvalOr_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_EvalExOr_call(game::VariableValue * result, game::VariableValue * a2, [[maybe_unused]] void* caller_addr, game::scriptInstance_t a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_EvalExOr(result, a2, a3, Scr_EvalExOr_original);
#else
			codsrc::Scr_EvalExOr(result, a2, a3);
#endif
		}

		// void __usercall Scr_EvalExOr(game::VariableValue *result@<eax>, game::VariableValue *a2@<ecx>, game::scriptInstance_t a3)
		NAKED void Scr_EvalExOr_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_EvalExOr_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_EvalAnd_call(game::VariableValue * result, game::VariableValue * a2, [[maybe_unused]] void* caller_addr, game::scriptInstance_t a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_EvalAnd(result, a2, a3, Scr_EvalAnd_original);
#else
			codsrc::Scr_EvalAnd(result, a2, a3);
#endif
		}

		// void __usercall Scr_EvalAnd(game::VariableValue *result@<eax>, game::VariableValue *a2@<ecx>, game::scriptInstance_t a3)
		NAKED void Scr_EvalAnd_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_EvalAnd_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_EvalEquality_call(game::VariableValue * a1, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, game::VariableValue * a4)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_EvalEquality(a1, inst, a4, Scr_EvalEquality_original);
#else
			codsrc::Scr_EvalEquality(a1, inst, a4);
#endif
		}

		// void __usercall Scr_EvalEquality(game::VariableValue *a1@<eax>, game::scriptInstance_t inst, game::VariableValue *a4)
		NAKED void Scr_EvalEquality_stub()
		{
			_asm
			{
				push eax;
				call Scr_EvalEquality_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_EvalLess_call(game::VariableValue * a1, game::VariableValue * a2, [[maybe_unused]] void* caller_addr, game::scriptInstance_t a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_EvalLess(a1, a2, a3, Scr_EvalLess_original);
#else
			codsrc::Scr_EvalLess(a1, a2, a3);
#endif
		}

		// void __usercall Scr_EvalLess(game::VariableValue *a1@<eax>, game::VariableValue *a2@<ecx>, game::scriptInstance_t a3)
		NAKED void Scr_EvalLess_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_EvalLess_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_EvalGreaterEqual_call(game::scriptInstance_t a1, game::VariableValue * a2, [[maybe_unused]] void* caller_addr, game::VariableValue * a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_EvalGreaterEqual(a1, a2, a3, Scr_EvalGreaterEqual_original);
#else
			codsrc::Scr_EvalGreaterEqual(a1, a2, a3);
#endif
		}

		// void __usercall Scr_EvalGreaterEqual(game::scriptInstance_t a1@<eax>, game::VariableValue *a2@<esi>, game::VariableValue *a3)
		NAKED void Scr_EvalGreaterEqual_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call Scr_EvalGreaterEqual_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_EvalGreater_call(game::VariableValue * a1, game::VariableValue * a2, [[maybe_unused]] void* caller_addr, game::scriptInstance_t a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_EvalGreater(a1, a2, a3, Scr_EvalGreater_original);
#else
			codsrc::Scr_EvalGreater(a1, a2, a3);
#endif
		}

		// void __usercall Scr_EvalGreater(game::VariableValue *a1@<eax>, game::VariableValue *a2@<ecx>, game::scriptInstance_t a3)
		NAKED void Scr_EvalGreater_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_EvalGreater_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_EvalLessEqual_call(game::scriptInstance_t a1, game::VariableValue * a2, [[maybe_unused]] void* caller_addr, game::VariableValue * a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_EvalLessEqual(a1, a2, a3, Scr_EvalLessEqual_original);
#else
			codsrc::Scr_EvalLessEqual(a1, a2, a3);
#endif
		}

		// void __usercall Scr_EvalLessEqual(game::scriptInstance_t a1@<eax>, game::VariableValue *a2@<esi>, game::VariableValue *a3)
		NAKED void Scr_EvalLessEqual_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call Scr_EvalLessEqual_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_EvalShiftLeft_call(game::VariableValue * result, game::VariableValue * a2, [[maybe_unused]] void* caller_addr, game::scriptInstance_t a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_EvalShiftLeft(result, a2, a3, Scr_EvalShiftLeft_original);
#else
			codsrc::Scr_EvalShiftLeft(result, a2, a3);
#endif
		}

		// void __usercall Scr_EvalShiftLeft(game::VariableValue *result@<eax>, game::VariableValue *a2@<ecx>, game::scriptInstance_t a3)
		NAKED void Scr_EvalShiftLeft_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_EvalShiftLeft_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_EvalShiftRight_call(game::VariableValue * result, game::VariableValue * a2, [[maybe_unused]] void* caller_addr, game::scriptInstance_t a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_EvalShiftRight(result, a2, a3, Scr_EvalShiftRight_original);
#else
			codsrc::Scr_EvalShiftRight(result, a2, a3);
#endif
		}

		// void __usercall Scr_EvalShiftRight(game::VariableValue *result@<eax>, game::VariableValue *a2@<ecx>, game::scriptInstance_t a3)
		NAKED void Scr_EvalShiftRight_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_EvalShiftRight_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_EvalPlus_call(game::scriptInstance_t a, [[maybe_unused]] void* caller_addr, game::VariableValue * a1, game::VariableValue * a2)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_EvalPlus(a, a1, a2, Scr_EvalPlus_original);
#else
			codsrc::Scr_EvalPlus(a, a1, a2);
#endif
		}

		// void __usercall Scr_EvalPlus(game::scriptInstance_t a@<ecx>, game::VariableValue *a1, game::VariableValue *a2)
		NAKED void Scr_EvalPlus_stub()
		{
			_asm
			{
				push ecx;
				call Scr_EvalPlus_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_EvalMinus_call(game::VariableValue * a1, [[maybe_unused]] void* caller_addr, game::scriptInstance_t a2, game::VariableValue * a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_EvalMinus(a1, a2, a3, Scr_EvalMinus_original);
#else
			codsrc::Scr_EvalMinus(a1, a2, a3);
#endif
		}

		// void __usercall Scr_EvalMinus(game::VariableValue *a1@<eax>, game::scriptInstance_t a2, game::VariableValue *a3)
		NAKED void Scr_EvalMinus_stub()
		{
			_asm
			{
				push eax;
				call Scr_EvalMinus_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_EvalMultiply_call(game::VariableValue * a1, [[maybe_unused]] void* caller_addr, game::scriptInstance_t a2, game::VariableValue * a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_EvalMultiply(a1, a2, a3, Scr_EvalMultiply_original);
#else
			codsrc::Scr_EvalMultiply(a1, a2, a3);
#endif
		}

		// void __usercall Scr_EvalMultiply(game::VariableValue *a1@<eax>, game::scriptInstance_t a2, game::VariableValue *a3)
		NAKED void Scr_EvalMultiply_stub()
		{
			_asm
			{
				push eax;
				call Scr_EvalMultiply_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_EvalDivide_call(game::VariableValue * a1, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, game::VariableValue * a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_EvalDivide(a1, inst, a3, Scr_EvalDivide_original);
#else
			codsrc::Scr_EvalDivide(a1, inst, a3);
#endif
		}

		// void __usercall Scr_EvalDivide(game::VariableValue *a1@<eax>, game::scriptInstance_t inst, game::VariableValue *a3)
		NAKED void Scr_EvalDivide_stub()
		{
			_asm
			{
				push eax;
				call Scr_EvalDivide_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_EvalMod_call(game::scriptInstance_t a1, game::VariableValue * a2, [[maybe_unused]] void* caller_addr, game::VariableValue * a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_EvalMod(a1, a2, a3, Scr_EvalMod_original);
#else
			codsrc::Scr_EvalMod(a1, a2, a3);
#endif
		}

		// void __usercall Scr_EvalMod(game::scriptInstance_t a1@<eax>, game::VariableValue *a2@<ecx>, game::VariableValue *a3)
		NAKED void Scr_EvalMod_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_EvalMod_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_EvalBinaryOperator_call(game::scriptInstance_t a1, game::VariableValue * a2, [[maybe_unused]] void* caller_addr, game::OpcodeVM a4, game::VariableValue * a5)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_EvalBinaryOperator(a1, a2, a4, a5, Scr_EvalBinaryOperator_original);
#else
			codsrc::Scr_EvalBinaryOperator(a1, a2, a4, a5);
#endif
		}

		// void __usercall Scr_EvalBinaryOperator(game::scriptInstance_t a1@<eax>, game::VariableValue *a2@<ecx>, OpcodeVM a4, game::VariableValue *a5)
		NAKED void Scr_EvalBinaryOperator_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_EvalBinaryOperator_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_FreeEntityNum_call(game::scriptInstance_t inst, unsigned int classnum, [[maybe_unused]] void* caller_addr, unsigned int entnum)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_FreeEntityNum(inst, classnum, entnum, Scr_FreeEntityNum_original);
#else
			codsrc::Scr_FreeEntityNum(inst, classnum, entnum);
#endif
		}

		// void __usercall Scr_FreeEntityNum(game::scriptInstance_t inst@<ecx>, unsigned int result@<eax>, unsigned int a3)
		NAKED void Scr_FreeEntityNum_stub()
		{
			_asm
			{
				push eax;
				push ecx;
				call Scr_FreeEntityNum_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_FreeEntityList_stub(game::scriptInstance_t inst)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			Scr_FreeEntityList_hook.invoke<void>(inst);
#else
			codsrc::Scr_FreeEntityList(inst);
#endif
		}

		void Scr_FreeObjects_stub(game::scriptInstance_t a2)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			Scr_FreeObjects_hook.invoke<void>(a2);
#else
			codsrc::Scr_FreeObjects(a2);
#endif
		}

		void Scr_SetClassMap_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, unsigned int a2)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_SetClassMap(a1, a2, Scr_SetClassMap_original);
#else
			codsrc::Scr_SetClassMap(a1, a2);
#endif
		}

		// void __usercall Scr_SetClassMap(game::scriptInstance_t a1@<esi>, unsigned int a2)
		NAKED void Scr_SetClassMap_stub()
		{
			_asm
			{
				push esi;
				call Scr_SetClassMap_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_RemoveClassMap_call(unsigned int result, game::scriptInstance_t a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_RemoveClassMap(result, a2, Scr_RemoveClassMap_original);
#else
			codsrc::Scr_RemoveClassMap(result, a2);
#endif
		}

		// void __usercall Scr_RemoveClassMap(unsigned int result@<eax>, game::scriptInstance_t a2@<edi>)
		NAKED void Scr_RemoveClassMap_stub()
		{
			_asm
			{
				push edi;
				push eax;
				call Scr_RemoveClassMap_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_AddClassField_call(game::scriptInstance_t inst, unsigned int a2, [[maybe_unused]] void* caller_addr, const char * name, unsigned int a4)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_AddClassField(inst, a2, name, a4, Scr_AddClassField_original);
#else
			codsrc::Scr_AddClassField(inst, a2, name, a4);
#endif
		}

		// void __usercall Scr_AddClassField(game::scriptInstance_t inst@<ecx>, unsigned int a2@<eax>, char *name, unsigned int a4)
		NAKED void Scr_AddClassField_stub()
		{
			_asm
			{
				push eax;
				push ecx;
				call Scr_AddClassField_call;
				add esp, 0x8;
				ret;
			}
		}

		game::VariableUnion Scr_GetOffset_call(const char* name, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::classNum_e classNum)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::Scr_GetOffset(name, inst, classNum, Scr_GetOffset_original);
#else
			return codsrc::Scr_GetOffset(name, inst, classNum);
#endif
		}

		// int __usercall Scr_GetOffset@<eax>(char *name@<eax>, game::scriptInstance_t inst@<edi>, classNum_e classNum)
		NAKED game::VariableUnion Scr_GetOffset_stub()
		{
			_asm
			{
				push edi;
				push eax;
				call Scr_GetOffset_call;
				add esp, 0x8;
				ret;
			}
		}

		unsigned int FindEntityId_call(unsigned int entClass, int entNum, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::FindEntityId(entClass, entNum, inst, FindEntityId_original);
#else
			return codsrc::FindEntityId(entClass, entNum, inst);
#endif
		}

		// unsigned int __usercall FindEntityId@<eax>(unsigned int entClass@<eax>, int entNum@<ecx>, game::scriptInstance_t inst@<edi>)
		NAKED unsigned int FindEntityId_stub()
		{
			_asm
			{
				push edi;
				push ecx;
				push eax;
				call FindEntityId_call;
				add esp, 0xC;
				ret;
			}
		}

		unsigned int Scr_GetEntityId_call(int entNum, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, game::classNum_e classnum, int clientnum)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::Scr_GetEntityId(entNum, inst, classnum, clientnum, Scr_GetEntityId_original);
#else
			return codsrc::Scr_GetEntityId(entNum, inst, classnum, clientnum);
#endif
		}

		// unsigned int __usercall Scr_GetEntityId@<eax>(int entNum@<eax>, game::scriptInstance_t inst, classNum_e classnum, int clientnum)
		NAKED unsigned int Scr_GetEntityId_stub()
		{
			_asm
			{
				push eax;
				call Scr_GetEntityId_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int Scr_FindArrayIndex_call(game::scriptInstance_t a1, game::VariableValue * a2, [[maybe_unused]] void* caller_addr, int a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::Scr_FindArrayIndex(a1, a2, a3, Scr_FindArrayIndex_original);
#else
			return codsrc::Scr_FindArrayIndex(a1, a2, a3);
#endif
		}

		// unsigned int __usercall Scr_FindArrayIndex@<eax>(game::scriptInstance_t a1@<eax>, game::VariableValue *a2@<ecx>, int a3)
		NAKED unsigned int Scr_FindArrayIndex_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_FindArrayIndex_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_EvalArray_call(game::scriptInstance_t a2, game::VariableValue * eax0, [[maybe_unused]] void* caller_addr, game::VariableValue * a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_EvalArray(a2, eax0, a3, Scr_EvalArray_original);
#else
			codsrc::Scr_EvalArray(a2, eax0, a3);
#endif
		}

		// void __usercall Scr_EvalArray(game::scriptInstance_t a2@<ecx>, game::VariableValue *eax0@<eax>, game::VariableValue *a3)
		NAKED void Scr_EvalArray_stub()
		{
			_asm
			{
				push eax;
				push ecx;
				call Scr_EvalArray_call;
				add esp, 0x8;
				ret;
			}
		}

		unsigned int Scr_EvalArrayRef_call(game::scriptInstance_t a2, unsigned int eax0, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::Scr_EvalArrayRef(a2, eax0, Scr_EvalArrayRef_original);
#else
			return codsrc::Scr_EvalArrayRef(a2, eax0);
#endif
		}

		// unsigned int __usercall Scr_EvalArrayRef@<eax>(game::scriptInstance_t a2@<ecx>, unsigned int eax0@<eax>)
		NAKED unsigned int Scr_EvalArrayRef_stub()
		{
			_asm
			{
				push eax;
				push ecx;
				call Scr_EvalArrayRef_call;
				add esp, 0x8;
				ret;
			}
		}

		void ClearArray_call(unsigned int parentId, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::VariableValue * value)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::ClearArray(parentId, inst, value, ClearArray_original);
#else
			codsrc::ClearArray(parentId, inst, value);
#endif
		}

		// void __usercall ClearArray(unsigned int parentId@<eax>, game::scriptInstance_t inst@<ecx>, game::VariableValue *value)
		NAKED void ClearArray_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call ClearArray_call;
				add esp, 0x8;
				ret;
			}
		}

		void SetEmptyArray_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, unsigned int a2)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::SetEmptyArray(a1, a2, SetEmptyArray_original);
#else
			codsrc::SetEmptyArray(a1, a2);
#endif
		}

		// unsigned int __usercall SetEmptyArray@<eax>(game::scriptInstance_t a1@<edi>, unsigned int a2)
		NAKED unsigned int SetEmptyArray_stub()
		{
			_asm
			{
				push edi;
				call SetEmptyArray_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_AddArrayKeys_stub(unsigned int array, game::scriptInstance_t inst)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			Scr_AddArrayKeys_hook.invoke<void>(array, inst);
#else
			codsrc::Scr_AddArrayKeys(array, inst);
#endif
		}

		game::scr_entref_t * Scr_GetEntityIdRef_call(game::scr_entref_t * result, game::scriptInstance_t a2, [[maybe_unused]] void* caller_addr, unsigned int a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::Scr_GetEntityIdRef(result, a2, a3, Scr_GetEntityIdRef_original);
#else
			return codsrc::Scr_GetEntityIdRef(result, a2, a3);
#endif
		}

		// scr_entref_t *__usercall Scr_GetEntityIdRef@<eax>(scr_entref_t *result@<eax>, game::scriptInstance_t a2@<ecx>, unsigned int a3)
		NAKED game::scr_entref_t * Scr_GetEntityIdRef_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_GetEntityIdRef_call;
				add esp, 0x8;
				ret;
			}
		}

		void CopyEntity_call(unsigned int parentId, [[maybe_unused]] void* caller_addr, unsigned int newParentId)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::CopyEntity(parentId, newParentId, CopyEntity_original);
#else
			codsrc::CopyEntity(parentId, newParentId);
#endif
		}

		// void __usercall Scr_CopyEntityNum(unsigned int a1@<eax>, unsigned int parentId)
		NAKED void CopyEntity_stub()
		{
			_asm
			{
				push eax;
				call CopyEntity_call;
				add esp, 0x4;
				ret;
			}
		}

		float Scr_GetEndonUsage_call(unsigned int a1, game::scriptInstance_t a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::Scr_GetEndonUsage(a1, a2, Scr_GetEndonUsage_original);
#else
			return codsrc::Scr_GetEndonUsage(a1, a2);
#endif
		}

		// float __usercall Scr_GetEndonUsage@<st0>(unsigned int a1@<ecx>, game::scriptInstance_t a2@<edi>)
		NAKED float Scr_GetEndonUsage_stub()
		{
			_asm
			{
				push edi;
				push ecx;
				call Scr_GetEndonUsage_call;
				add esp, 0x8;
				ret;
			}
		}

		float Scr_GetObjectUsage_stub(game::scriptInstance_t a1, unsigned int parentId)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return Scr_GetObjectUsage_hook.invoke<float>(a1, parentId);
#else
			return codsrc::Scr_GetObjectUsage(a1, parentId);
#endif
		}

		float Scr_GetThreadUsage_call(game::VariableStackBuffer * a1, game::scriptInstance_t a2, [[maybe_unused]] void* caller_addr, float * a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::Scr_GetThreadUsage(a1, a2, a3, Scr_GetThreadUsage_original);
#else
			return codsrc::Scr_GetThreadUsage(a1, a2, a3);
#endif
		}

		// float __usercall Scr_GetThreadUsage@<xmm0>(VariableStackBuffer *a1@<eax>, game::scriptInstance_t a2@<ecx>, float *a3)
		NAKED float Scr_GetThreadUsage_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_GetThreadUsage_call;
				add esp, 0x8;

				sub esp, 4;

				fstp dword ptr[esp];
				movsd xmm0, dword ptr[esp];
				add esp, 4;

				ret;
			}
		}

		int Scr_FindField_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, const char * name, int * type)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::Scr_FindField(inst, name, type, Scr_FindField_original);
#else
			return codsrc::Scr_FindField(inst, name, type);
#endif
		}

		// int __usercall Scr_FindField@<eax>(game::scriptInstance_t a1@<eax>, unsigned __int8 *a2, _DWORD *a3)
		NAKED int Scr_FindField_stub()
		{
			_asm
			{
				push eax;
				call Scr_FindField_call;
				add esp, 0x4;
				ret;
			}
		}

		char * Scr_GetSourceFile_LoadObj_stub(const char * a1)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return Scr_GetSourceFile_LoadObj_hook.invoke<char *>(a1);
#else
			return codsrc::Scr_GetSourceFile_LoadObj(a1);
#endif
		}

		char * Scr_GetSourceFile_FastFile_stub(char * a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return Scr_GetSourceFile_FastFile_hook.invoke<char *>(a3);
#else
			return codsrc::Scr_GetSourceFile_FastFile(a3);
#endif
		}

		void Scr_AddFieldsForFile_stub(game::scriptInstance_t a1, char * Format)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			Scr_AddFieldsForFile_hook.invoke<void>(a1, Format);
#else
			codsrc::Scr_AddFieldsForFile(a1, Format);
#endif
		}

		void Scr_AddFields_LoadObj_stub(game::scriptInstance_t a1, const char * edx0, CHAR * a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			Scr_AddFields_LoadObj_hook.invoke<void>(a1, edx0, a3);
#else
			codsrc::Scr_AddFields_LoadObj(a1, edx0, a3);
#endif
		}

		void Scr_AddFields_FastFile_stub(game::scriptInstance_t a1, const char * a2, const char * a3)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			Scr_AddFields_FastFile_hook.invoke<void>(a1, a2, a3);
#else
			codsrc::Scr_AddFields_FastFile(a1, a2, a3);
#endif
		}

		int Scr_MakeValuePrimitive_stub(game::scriptInstance_t inst, unsigned int parentId)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return Scr_MakeValuePrimitive_hook.invoke<int>(inst, parentId);
#else
			return codsrc::Scr_MakeValuePrimitive(inst, parentId);
#endif
		}

		void Scr_FreeGameVariable_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, int bComplete)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			game::Scr_FreeGameVariable(a1, bComplete, Scr_FreeGameVariable_original);
#else
			codsrc::Scr_FreeGameVariable(a1, bComplete);
#endif
		}

		// void __usercall Scr_FreeGameVariable(game::scriptInstance_t a1@<eax>, int bComplete)
		NAKED void Scr_FreeGameVariable_stub()
		{
			_asm
			{
				push eax;
				call Scr_FreeGameVariable_call;
				add esp, 0x4;
				ret;
			}
		}

		bool Scr_SLHasLowercaseString_call(unsigned int a1, const char * a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VARIABLE_USE_WRAPPERS
			return game::Scr_SLHasLowercaseString(a1, a2, Scr_SLHasLowercaseString_original);
#else
			return codsrc::Scr_SLHasLowercaseString(a1, a2);
#endif
		}

		// char __usercall Scr_SLHasLowercaseString@<al>(int a1@<eax>, const char *a2@<edx>)
		NAKED bool Scr_SLHasLowercaseString_stub()
		{
			_asm
			{
				push edx;
				push eax;
				call Scr_SLHasLowercaseString_call;
				add esp, 0x8;
				ret;
			}
		}
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			ThreadInfoCompare_hook.create(game::ThreadInfoCompare.get(), ThreadInfoCompare_stub);
			Scr_DumpScriptThreads_hook.create(game::Scr_DumpScriptThreads.get(), Scr_DumpScriptThreads_stub);
			Scr_InitVariableRange_hook.create(game::Scr_InitVariableRange_ADDR(), Scr_InitVariableRange_stub);
			Scr_InitClassMap_hook.create(game::Scr_InitClassMap_ADDR(), Scr_InitClassMap_stub);
			GetNewVariableIndexInternal3_hook.create(game::GetNewVariableIndexInternal3.get(), GetNewVariableIndexInternal3_stub);
			GetNewVariableIndexInternal2_hook.create(game::GetNewVariableIndexInternal2_ADDR(), GetNewVariableIndexInternal2_stub);
			GetNewVariableIndexReverseInternal2_hook.create(game::GetNewVariableIndexReverseInternal2_ADDR(), GetNewVariableIndexReverseInternal2_stub);
			MakeVariableExternal_hook.create(game::MakeVariableExternal_ADDR(), MakeVariableExternal_stub);
			FreeChildValue_hook.create(game::FreeChildValue_ADDR(), FreeChildValue_stub);
			ClearObjectInternal_hook.create(game::ClearObjectInternal.get(), ClearObjectInternal_stub);
			ClearObject_hook.create(game::ClearObject_ADDR(), ClearObject_stub);
			Scr_StopThread_hook.create(game::Scr_StopThread_ADDR(), Scr_StopThread_stub);
			GetSafeParentLocalId_hook.create(game::GetSafeParentLocalId_ADDR(), GetSafeParentLocalId_stub);
			GetStartLocalId_hook.create(game::GetStartLocalId_ADDR(), GetStartLocalId_stub);
			Scr_KillThread_hook.create(game::Scr_KillThread_ADDR(), Scr_KillThread_stub);
			AllocVariable_hook.create(game::AllocVariable_ADDR(), AllocVariable_stub);
			FreeVariable_hook.create(game::FreeVariable_ADDR(), FreeVariable_stub);
			AllocValue_hook.create(game::AllocValue_ADDR(), AllocValue_stub);
			AllocEntity_hook.create(game::AllocEntity_ADDR(), AllocEntity_stub);
			Scr_AllocArray_hook.create(game::Scr_AllocArray_ADDR(), Scr_AllocArray_stub);

			AllocChildThread_hook.create(game::AllocChildThread_ADDR(), AllocChildThread_stub);
			FreeValue_hook.create(game::FreeValue_ADDR(), FreeValue_stub);
			RemoveRefToObject_hook.create(game::RemoveRefToObject_ADDR(), RemoveRefToObject_stub);
			Scr_AllocVector_hook.create(game::Scr_AllocVector_ADDR(), Scr_AllocVector_stub);
			RemoveRefToVector_hook.create(game::RemoveRefToVector_ADDR(), RemoveRefToVector_stub);

			AddRefToValue_hook.create(game::AddRefToValue_ADDR(), AddRefToValue_stub);
			RemoveRefToValueInternal_hook.create(game::RemoveRefToValueInternal.get(), RemoveRefToValueInternal_stub);
			FindArrayVariable_hook.create(game::FindArrayVariable_ADDR(), FindArrayVariable_stub);
			FindVariable_hook.create(game::FindVariable_ADDR(), FindVariable_stub);

			GetArrayVariableIndex_hook.create(game::GetArrayVariableIndex_ADDR(), GetArrayVariableIndex_stub);
			Scr_GetVariableFieldIndex_hook.create(game::Scr_GetVariableFieldIndex_ADDR(), Scr_GetVariableFieldIndex_stub);
			Scr_FindVariableField_hook.create(game::Scr_FindVariableField_ADDR(), Scr_FindVariableField_stub);
			ClearVariableField_hook.create(game::ClearVariableField_ADDR(), ClearVariableField_stub);
			GetVariable_hook.create(game::GetVariable_ADDR(), GetVariable_stub);

			GetNewVariable_hook.create(game::GetNewVariable_ADDR(), GetNewVariable_stub);
			GetObjectVariable_hook.create(game::GetObjectVariable_ADDR(), GetObjectVariable_stub);
			GetNewObjectVariable_hook.create(game::GetNewObjectVariable_ADDR(), GetNewObjectVariable_stub);
			RemoveVariable_hook.create(game::RemoveVariable_ADDR(), RemoveVariable_stub);
			RemoveNextVariable_hook.create(game::RemoveNextVariable_ADDR(), RemoveNextVariable_stub);
			SafeRemoveVariable_hook.create(game::SafeRemoveVariable_ADDR(), SafeRemoveVariable_stub);

			CopyArray_hook.create(game::CopyArray.get(), CopyArray_stub);
			SetVariableValue_hook.create(game::SetVariableValue_ADDR(), SetVariableValue_stub);
			SetVariableEntityFieldValue_hook.create(game::SetVariableEntityFieldValue.get(), SetVariableEntityFieldValue_stub);
			Scr_EvalVariable_hook.create(game::Scr_EvalVariable_ADDR(), Scr_EvalVariable_stub);

			Scr_EvalVariableObject_hook.create(game::Scr_EvalVariableObject_ADDR(), Scr_EvalVariableObject_stub);
			Scr_EvalVariableEntityField_hook.create(game::Scr_EvalVariableEntityField_ADDR(), Scr_EvalVariableEntityField_stub);
			Scr_EvalVariableField_hook.create(game::Scr_EvalVariableField_ADDR(), Scr_EvalVariableField_stub);
			Scr_EvalSizeValue_hook.create(game::Scr_EvalSizeValue_ADDR(), Scr_EvalSizeValue_stub);

			GetObject_hook.create(game::GetObject_ADDR(), GetObject_stub);
			GetArray_hook.create(game::GetArray_ADDR(), GetArray_stub);
			Scr_EvalBoolComplement_hook.create(game::Scr_EvalBoolComplement_ADDR(), Scr_EvalBoolComplement_stub);
			Scr_CastBool_hook.create(game::Scr_CastBool_ADDR(), Scr_CastBool_stub);
			Scr_CastString_hook.create(game::Scr_CastString_ADDR(), Scr_CastString_stub);
			Scr_CastDebugString_hook.create(game::Scr_CastDebugString_ADDR(), Scr_CastDebugString_stub);
			Scr_ClearVector_hook.create(game::Scr_ClearVector.get(), Scr_ClearVector_stub);
			Scr_CastVector_hook.create(game::Scr_CastVector_ADDR(), Scr_CastVector_stub);

			Scr_EvalFieldObject_hook.create(game::Scr_EvalFieldObject_ADDR(), Scr_EvalFieldObject_stub);
			Scr_UnmatchingTypesError_hook.create(game::Scr_UnmatchingTypesError_ADDR(), Scr_UnmatchingTypesError_stub);
			Scr_CastWeakerPair_hook.create(game::Scr_CastWeakerPair_ADDR(), Scr_CastWeakerPair_stub);
			Scr_CastWeakerStringPair_hook.create(game::Scr_CastWeakerStringPair_ADDR(), Scr_CastWeakerStringPair_stub);
			Scr_EvalOr_hook.create(game::Scr_EvalOr_ADDR(), Scr_EvalOr_stub);
			Scr_EvalExOr_hook.create(game::Scr_EvalExOr_ADDR(), Scr_EvalExOr_stub);
			Scr_EvalAnd_hook.create(game::Scr_EvalAnd_ADDR(), Scr_EvalAnd_stub);
			Scr_EvalEquality_hook.create(game::Scr_EvalEquality_ADDR(), Scr_EvalEquality_stub);
			Scr_EvalLess_hook.create(game::Scr_EvalLess_ADDR(), Scr_EvalLess_stub);
			Scr_EvalGreaterEqual_hook.create(game::Scr_EvalGreaterEqual_ADDR(), Scr_EvalGreaterEqual_stub);
			Scr_EvalGreater_hook.create(game::Scr_EvalGreater_ADDR(), Scr_EvalGreater_stub);
			Scr_EvalLessEqual_hook.create(game::Scr_EvalLessEqual_ADDR(), Scr_EvalLessEqual_stub);
			Scr_EvalShiftLeft_hook.create(game::Scr_EvalShiftLeft_ADDR(), Scr_EvalShiftLeft_stub);
			Scr_EvalShiftRight_hook.create(game::Scr_EvalShiftRight_ADDR(), Scr_EvalShiftRight_stub);
			Scr_EvalPlus_hook.create(game::Scr_EvalPlus_ADDR(), Scr_EvalPlus_stub);
			Scr_EvalMinus_hook.create(game::Scr_EvalMinus_ADDR(), Scr_EvalMinus_stub);
			Scr_EvalMultiply_hook.create(game::Scr_EvalMultiply_ADDR(), Scr_EvalMultiply_stub);
			
			Scr_EvalDivide_hook.create(game::Scr_EvalDivide_ADDR(), Scr_EvalDivide_stub);
			Scr_EvalMod_hook.create(game::Scr_EvalMod_ADDR(), Scr_EvalMod_stub);

			Scr_EvalBinaryOperator_hook.create(game::Scr_EvalBinaryOperator_ADDR(), Scr_EvalBinaryOperator_stub);

			Scr_FreeEntityNum_hook.create(game::Scr_FreeEntityNum_ADDR(), Scr_FreeEntityNum_stub);

			Scr_FreeEntityList_hook.create(game::Scr_FreeEntityList.get(), Scr_FreeEntityList_stub);
			Scr_FreeObjects_hook.create(game::Scr_FreeObjects.get(), Scr_FreeObjects_stub);
			Scr_SetClassMap_hook.create(game::Scr_SetClassMap_ADDR(), Scr_SetClassMap_stub);

			Scr_RemoveClassMap_hook.create(game::Scr_RemoveClassMap_ADDR(), Scr_RemoveClassMap_stub);
			Scr_AddClassField_hook.create(game::Scr_AddClassField_ADDR(), Scr_AddClassField_stub);
			Scr_GetOffset_hook.create(game::Scr_GetOffset_ADDR(), Scr_GetOffset_stub);
			FindEntityId_hook.create(game::FindEntityId_ADDR(), FindEntityId_stub);
			Scr_GetEntityId_hook.create(game::Scr_GetEntityId_ADDR(), Scr_GetEntityId_stub);
			Scr_FindArrayIndex_hook.create(game::Scr_FindArrayIndex_ADDR(), Scr_FindArrayIndex_stub);
			Scr_EvalArray_hook.create(game::Scr_EvalArray_ADDR(), Scr_EvalArray_stub);

			Scr_EvalArrayRef_hook.create(game::Scr_EvalArrayRef_ADDR(), Scr_EvalArrayRef_stub);
			ClearArray_hook.create(game::ClearArray_ADDR(), ClearArray_stub);

			SetEmptyArray_hook.create(game::SetEmptyArray_ADDR(), SetEmptyArray_stub);
			Scr_AddArrayKeys_hook.create(game::Scr_AddArrayKeys.get(), Scr_AddArrayKeys_stub);
			Scr_GetEntityIdRef_hook.create(game::Scr_GetEntityIdRef_ADDR(), Scr_GetEntityIdRef_stub);
			CopyEntity_hook.create(game::CopyEntity_ADDR(), CopyEntity_stub);

			Scr_GetEndonUsage_hook.create(game::Scr_GetEndonUsage_ADDR(), Scr_GetEndonUsage_stub);
			Scr_GetObjectUsage_hook.create(game::Scr_GetObjectUsage.get(), Scr_GetObjectUsage_stub);
			Scr_GetThreadUsage_hook.create(game::Scr_GetThreadUsage_ADDR(), Scr_GetThreadUsage_stub);

			Scr_FindField_hook.create(game::Scr_FindField_ADDR(), Scr_FindField_stub);
			Scr_GetSourceFile_LoadObj_hook.create(game::Scr_GetSourceFile_LoadObj.get(), Scr_GetSourceFile_LoadObj_stub);
			Scr_GetSourceFile_FastFile_hook.create(game::Scr_GetSourceFile_FastFile.get(), Scr_GetSourceFile_FastFile_stub);
			Scr_AddFieldsForFile_hook.create(game::Scr_AddFieldsForFile.get(), Scr_AddFieldsForFile_stub);
			Scr_AddFields_LoadObj_hook.create(game::Scr_AddFields_LoadObj.get(), Scr_AddFields_LoadObj_stub);
			Scr_AddFields_FastFile_hook.create(game::Scr_AddFields_FastFile.get(), Scr_AddFields_FastFile_stub);
			Scr_MakeValuePrimitive_hook.create(game::Scr_MakeValuePrimitive.get(), Scr_MakeValuePrimitive_stub);
			Scr_FreeGameVariable_hook.create(game::Scr_FreeGameVariable_ADDR(), Scr_FreeGameVariable_stub);
			Scr_SLHasLowercaseString_hook.create(game::Scr_SLHasLowercaseString_ADDR(), Scr_SLHasLowercaseString_stub);

			//Original hook function addresses
			ThreadInfoCompare_original = ThreadInfoCompare_hook.get_original();
			Scr_DumpScriptThreads_original = Scr_DumpScriptThreads_hook.get_original();
			Scr_InitVariableRange_original = Scr_InitVariableRange_hook.get_original();
			Scr_InitClassMap_original = Scr_InitClassMap_hook.get_original();
			GetNewVariableIndexInternal3_original = GetNewVariableIndexInternal3_hook.get_original();
			GetNewVariableIndexInternal2_original = GetNewVariableIndexInternal2_hook.get_original();
			GetNewVariableIndexReverseInternal2_original = GetNewVariableIndexReverseInternal2_hook.get_original();
			MakeVariableExternal_original = MakeVariableExternal_hook.get_original();
			FreeChildValue_original = FreeChildValue_hook.get_original();
			ClearObjectInternal_original = ClearObjectInternal_hook.get_original();
			ClearObject_original = ClearObject_hook.get_original();
			Scr_StopThread_original = Scr_StopThread_hook.get_original();
			GetSafeParentLocalId_original = GetSafeParentLocalId_hook.get_original();
			GetStartLocalId_original = GetStartLocalId_hook.get_original();
			Scr_KillThread_original = Scr_KillThread_hook.get_original();
			AllocVariable_original = AllocVariable_hook.get_original();
			FreeVariable_original = FreeVariable_hook.get_original();
			AllocValue_original = AllocValue_hook.get_original();
			AllocEntity_original = AllocEntity_hook.get_original();
			Scr_AllocArray_original = Scr_AllocArray_hook.get_original();
			AllocChildThread_original = AllocChildThread_hook.get_original();
			FreeValue_original = FreeValue_hook.get_original();
			RemoveRefToObject_original = RemoveRefToObject_hook.get_original();
			Scr_AllocVector_original = Scr_AllocVector_hook.get_original();
			RemoveRefToVector_original = RemoveRefToVector_hook.get_original();
			AddRefToValue_original = AddRefToValue_hook.get_original();
			RemoveRefToValueInternal_original = RemoveRefToValueInternal_hook.get_original();
			FindArrayVariable_original = FindArrayVariable_hook.get_original();
			FindVariable_original = FindVariable_hook.get_original();
			GetArrayVariableIndex_original = GetArrayVariableIndex_hook.get_original();
			Scr_GetVariableFieldIndex_original = Scr_GetVariableFieldIndex_hook.get_original();
			Scr_FindVariableField_original = Scr_FindVariableField_hook.get_original();
			ClearVariableField_original = ClearVariableField_hook.get_original();
			GetVariable_original = GetVariable_hook.get_original();
			GetNewVariable_original = GetNewVariable_hook.get_original();
			GetObjectVariable_original = GetObjectVariable_hook.get_original();
			GetNewObjectVariable_original = GetNewObjectVariable_hook.get_original();
			RemoveVariable_original = RemoveVariable_hook.get_original();
			RemoveNextVariable_original = RemoveNextVariable_hook.get_original();
			SafeRemoveVariable_original = SafeRemoveVariable_hook.get_original();
			CopyArray_original = CopyArray_hook.get_original();
			SetVariableValue_original = SetVariableValue_hook.get_original();
			SetVariableEntityFieldValue_original = SetVariableEntityFieldValue_hook.get_original();
			Scr_EvalVariable_original = Scr_EvalVariable_hook.get_original();
			Scr_EvalVariableObject_original = Scr_EvalVariableObject_hook.get_original();
			Scr_EvalVariableEntityField_original = Scr_EvalVariableEntityField_hook.get_original();
			Scr_EvalVariableField_original = Scr_EvalVariableField_hook.get_original();
			Scr_EvalSizeValue_original = Scr_EvalSizeValue_hook.get_original();
			GetObject_original = GetObject_hook.get_original();
			GetArray_original = GetArray_hook.get_original();
			Scr_EvalBoolComplement_original = Scr_EvalBoolComplement_hook.get_original();
			Scr_CastBool_original = Scr_CastBool_hook.get_original();
			Scr_CastString_original = Scr_CastString_hook.get_original();
			Scr_CastDebugString_original = Scr_CastDebugString_hook.get_original();
			Scr_ClearVector_original = Scr_ClearVector_hook.get_original();
			Scr_CastVector_original = Scr_CastVector_hook.get_original();
			Scr_EvalFieldObject_original = Scr_EvalFieldObject_hook.get_original();
			Scr_UnmatchingTypesError_original = Scr_UnmatchingTypesError_hook.get_original();
			Scr_CastWeakerPair_original = Scr_CastWeakerPair_hook.get_original();
			Scr_CastWeakerStringPair_original = Scr_CastWeakerStringPair_hook.get_original();
			Scr_EvalOr_original = Scr_EvalOr_hook.get_original();
			Scr_EvalExOr_original = Scr_EvalExOr_hook.get_original();
			Scr_EvalAnd_original = Scr_EvalAnd_hook.get_original();
			Scr_EvalEquality_original = Scr_EvalEquality_hook.get_original();
			Scr_EvalLess_original = Scr_EvalLess_hook.get_original();
			Scr_EvalGreaterEqual_original = Scr_EvalGreaterEqual_hook.get_original();
			Scr_EvalGreater_original = Scr_EvalGreater_hook.get_original();
			Scr_EvalLessEqual_original = Scr_EvalLessEqual_hook.get_original();
			Scr_EvalShiftLeft_original = Scr_EvalShiftLeft_hook.get_original();
			Scr_EvalShiftRight_original = Scr_EvalShiftRight_hook.get_original();
			Scr_EvalPlus_original = Scr_EvalPlus_hook.get_original();
			Scr_EvalMinus_original = Scr_EvalMinus_hook.get_original();
			Scr_EvalMultiply_original = Scr_EvalMultiply_hook.get_original();
			Scr_EvalDivide_original = Scr_EvalDivide_hook.get_original();
			Scr_EvalMod_original = Scr_EvalMod_hook.get_original();
			Scr_EvalBinaryOperator_original = Scr_EvalBinaryOperator_hook.get_original();
			Scr_FreeEntityNum_original = Scr_FreeEntityNum_hook.get_original();
			Scr_FreeEntityList_original = Scr_FreeEntityList_hook.get_original();
			Scr_FreeObjects_original = Scr_FreeObjects_hook.get_original();
			Scr_SetClassMap_original = Scr_SetClassMap_hook.get_original();
			Scr_RemoveClassMap_original = Scr_RemoveClassMap_hook.get_original();
			Scr_AddClassField_original = Scr_AddClassField_hook.get_original();
			Scr_GetOffset_original = Scr_GetOffset_hook.get_original();
			FindEntityId_original = FindEntityId_hook.get_original();
			Scr_GetEntityId_original = Scr_GetEntityId_hook.get_original();
			Scr_FindArrayIndex_original = Scr_FindArrayIndex_hook.get_original();
			Scr_EvalArray_original = Scr_EvalArray_hook.get_original();
			Scr_EvalArrayRef_original = Scr_EvalArrayRef_hook.get_original();
			ClearArray_original = ClearArray_hook.get_original();
			SetEmptyArray_original = SetEmptyArray_hook.get_original();
			Scr_AddArrayKeys_original = Scr_AddArrayKeys_hook.get_original();
			Scr_GetEntityIdRef_original = Scr_GetEntityIdRef_hook.get_original();
			CopyEntity_original = CopyEntity_hook.get_original();
			Scr_GetEndonUsage_original = Scr_GetEndonUsage_hook.get_original();
			Scr_GetObjectUsage_original = Scr_GetObjectUsage_hook.get_original();
			Scr_GetThreadUsage_original = Scr_GetThreadUsage_hook.get_original();
			Scr_FindField_original = Scr_FindField_hook.get_original();
			Scr_GetSourceFile_LoadObj_original = Scr_GetSourceFile_LoadObj_hook.get_original();
			Scr_GetSourceFile_FastFile_original = Scr_GetSourceFile_FastFile_hook.get_original();
			Scr_AddFieldsForFile_original = Scr_AddFieldsForFile_hook.get_original();
			Scr_AddFields_LoadObj_original = Scr_AddFields_LoadObj_hook.get_original();
			Scr_AddFields_FastFile_original = Scr_AddFields_FastFile_hook.get_original();
			Scr_MakeValuePrimitive_original = Scr_MakeValuePrimitive_hook.get_original();
			Scr_FreeGameVariable_original = Scr_FreeGameVariable_hook.get_original();
			Scr_SLHasLowercaseString_original = Scr_SLHasLowercaseString_hook.get_original();
		}

	private:
	};
}
REGISTER_COMPONENT(re_cscr_variable::component)