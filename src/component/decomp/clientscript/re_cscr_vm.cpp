#include <stdinc.hpp>
#include "loader/component_loader.hpp"
#include "utils/hook.hpp"
#include "codsrc/clientscript/cscr_vm.hpp"

#ifndef DISABLE_RE_CSCR_VM
namespace re_cscr_vm
{
	utils::hook::detour Scr_VM_Init_hook;
	utils::hook::detour Scr_Init_hook;
	utils::hook::detour Scr_Shutdown_hook;
	utils::hook::detour Scr_ErrorInternal_hook;
	utils::hook::detour Scr_ClearOutParams_hook;
	utils::hook::detour GetDummyObject_hook;
	utils::hook::detour GetDummyFieldValue_hook;
	utils::hook::detour VM_ExecuteInternal_hook;
	utils::hook::detour VM_CancelNotifyInternal_hook;
	utils::hook::detour VM_CancelNotify_hook;
	utils::hook::detour VM_ArchiveStack_hook;
	utils::hook::detour Scr_AddLocalVars_hook;
	utils::hook::detour VM_UnarchiveStack_hook;
	utils::hook::detour VM_TerminateStack_hook;
	utils::hook::detour VM_TrimStack_hook;
	utils::hook::detour Scr_TerminateRunningThread_hook;
	utils::hook::detour Scr_TerminateWaitThread_hook;
	utils::hook::detour Scr_CancelWaittill_hook;
	utils::hook::detour Scr_TerminateWaittillThread_hook;
	utils::hook::detour Scr_TerminateThread_hook;
	utils::hook::detour VM_Notify_hook;
	utils::hook::detour Scr_NotifyNum_Internal_hook;
	utils::hook::detour Scr_CancelNotifyList_hook;
	utils::hook::detour VM_TerminateTime_hook;
	utils::hook::detour VM_Resume_hook;
	utils::hook::detour VM_Execute_hook;
	utils::hook::detour Scr_ExecThread_hook;
	utils::hook::detour Scr_ExecEntThread_hook;
	utils::hook::detour Scr_AddExecThread_hook;
	utils::hook::detour VM_SetTime_hook;
	utils::hook::detour Scr_InitSystem_hook;
	utils::hook::detour Scr_ShutdownSystem_hook;
	utils::hook::detour Scr_IsSystemActive_hook;
	utils::hook::detour Scr_GetInt_hook;
	utils::hook::detour Scr_GetAnim_hook;
	utils::hook::detour Scr_GetAnimTree_hook;
	utils::hook::detour Scr_GetFloat_hook;
	utils::hook::detour Scr_GetConstString_hook;
	utils::hook::detour Scr_GetConstLowercaseString_hook;
	utils::hook::detour Scr_GetString_hook;
	utils::hook::detour Scr_GetConstStringIncludeNull_hook;
	utils::hook::detour Scr_GetDebugString_hook;
	utils::hook::detour Scr_GetConstIString_hook;
	utils::hook::detour Scr_GetVector_hook;
	utils::hook::detour Scr_GetFunc_hook;
	utils::hook::detour Scr_GetEntityRef_hook;
	utils::hook::detour Scr_GetObject_hook;
	utils::hook::detour Scr_GetType_hook;
	utils::hook::detour Scr_GetTypeName_hook;
	utils::hook::detour Scr_GetPointerType_hook;
	utils::hook::detour Scr_AddInt_hook;
	utils::hook::detour Scr_AddFloat_hook;
	utils::hook::detour Scr_AddAnim_hook;
	utils::hook::detour Scr_AddUndefined_hook;
	utils::hook::detour Scr_AddObject_hook;
	utils::hook::detour Scr_AddString_hook;
	utils::hook::detour Scr_AddIString_hook;
	utils::hook::detour Scr_AddConstString_hook;
	utils::hook::detour Scr_AddVector_hook;
	utils::hook::detour Scr_MakeArray_hook;
	utils::hook::detour Scr_AddArray_hook;
	utils::hook::detour Scr_AddArrayStringIndexed_hook;
	utils::hook::detour Scr_Error_hook;
	utils::hook::detour Scr_TerminalError_hook;
	utils::hook::detour Scr_ParamError_hook;
	utils::hook::detour Scr_ObjectError_hook;
	utils::hook::detour SetEntityFieldValue_hook;
	utils::hook::detour GetEntityFieldValue_hook;
	utils::hook::detour Scr_SetStructField_hook;
	utils::hook::detour Scr_IncTime_hook;
	utils::hook::detour Scr_RunCurrentThreads_hook;
	utils::hook::detour Scr_ResetTimeout_hook;

	namespace
	{

		void Scr_VM_Init_stub(game::scriptInstance_t inst)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			Scr_VM_Init_hook.invoke<void>(inst);
#else
			codsrc::Scr_VM_Init(inst);
#endif
		}

		void Scr_Init_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_Init(a1, Scr_Init_hook.get_original());
#else
			codsrc::Scr_Init(a1);
#endif
		}

		NAKED void Scr_Init_stub()
		{
			_asm
			{
				push eax;
				call Scr_Init_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_Shutdown_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_Shutdown(a1, Scr_Shutdown_hook.get_original());
#else
			codsrc::Scr_Shutdown(a1);
#endif
		}

		NAKED void Scr_Shutdown_stub()
		{
			_asm
			{
				push edi;
				call Scr_Shutdown_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_ErrorInternal_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_ErrorInternal(a1, Scr_ErrorInternal_hook.get_original());
#else
			codsrc::Scr_ErrorInternal(a1);
#endif
		}

		NAKED void Scr_ErrorInternal_stub()
		{
			_asm
			{
				push eax;
				call Scr_ErrorInternal_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_ClearOutParams_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_ClearOutParams(a1, Scr_ClearOutParams_hook.get_original());
#else
			codsrc::Scr_ClearOutParams(a1);
#endif
		}

		NAKED void Scr_ClearOutParams_stub()
		{
			_asm
			{
				push edi;
				call Scr_ClearOutParams_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int GetDummyObject_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::GetDummyObject(a1, GetDummyObject_hook.get_original());
#else
			return codsrc::GetDummyObject(a1);
#endif
		}

		NAKED unsigned int GetDummyObject_stub/*@<eax>*/()
		{
			_asm
			{
				push edi;
				call GetDummyObject_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int GetDummyFieldValue_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::GetDummyFieldValue(a1, GetDummyFieldValue_hook.get_original());
#else
			return codsrc::GetDummyFieldValue(a1);
#endif
		}

		NAKED unsigned int GetDummyFieldValue_stub/*@<eax>*/()
		{
			_asm
			{
				push eax;
				call GetDummyFieldValue_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int VM_ExecuteInternal_stub(game::scriptInstance_t inst)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return VM_ExecuteInternal_hook.invoke<unsigned int>(inst);
#else
			return codsrc::VM_ExecuteInternal(inst);
#endif
		}

		void VM_CancelNotifyInternal_call(game::scriptInstance_t inst, unsigned int notifyListOwnerId, [[maybe_unused]] void* caller_addr, unsigned int startLocalId, unsigned int notifyListId, unsigned int notifyNameListId, unsigned int stringValue)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::VM_CancelNotifyInternal(inst, notifyListOwnerId, startLocalId, notifyListId, notifyNameListId, stringValue, VM_CancelNotifyInternal_hook.get_original());
#else
			codsrc::VM_CancelNotifyInternal(inst, notifyListOwnerId, startLocalId, notifyListId, notifyNameListId, stringValue);
#endif
		}

		NAKED void VM_CancelNotifyInternal_stub()
		{
			_asm
			{
				push eax;
				push ecx;
				call VM_CancelNotifyInternal_call;
				add esp, 0x8;
				ret;
			}
		}

		void VM_CancelNotify_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, unsigned int a2, unsigned int a3)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::VM_CancelNotify(a1, a2, a3, VM_CancelNotify_hook.get_original());
#else
			codsrc::VM_CancelNotify(a1, a2, a3);
#endif
		}

		NAKED void VM_CancelNotify_stub()
		{
			_asm
			{
				push edi;
				call VM_CancelNotify_call;
				add esp, 0x4;
				ret;
			}
		}

		game::VariableStackBuffer* VM_ArchiveStack_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::VM_ArchiveStack(inst, VM_ArchiveStack_hook.get_original());
#else
			return codsrc::VM_ArchiveStack(inst);
#endif
		}

		NAKED game::VariableStackBuffer * VM_ArchiveStack_stub/*@<eax>*/()
		{
			_asm
			{
				push eax;
				call VM_ArchiveStack_call;
				add esp, 0x4;
				ret;
			}
		}

		int Scr_AddLocalVars_call(game::scriptInstance_t a1, unsigned int a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::Scr_AddLocalVars(a1, a2, Scr_AddLocalVars_hook.get_original());
#else
			return codsrc::Scr_AddLocalVars(a1, a2);
#endif
		}

		NAKED int Scr_AddLocalVars_stub/*@<eax>*/()
		{
			_asm
			{
				push edx;
				push eax;
				call Scr_AddLocalVars_call;
				add esp, 0x8;
				ret;
			}
		}

		void VM_UnarchiveStack_stub(game::scriptInstance_t inst, unsigned int startLocalId, game::VariableStackBuffer* stackValue)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			VM_UnarchiveStack_hook.invoke<void>(inst, startLocalId, stackValue);
#else
			codsrc::VM_UnarchiveStack(inst, startLocalId, stackValue);
#endif
		}

		void VM_TerminateStack_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, unsigned int a2, unsigned int a3, game::VariableStackBuffer* name)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::VM_TerminateStack(a1, a2, a3, name, VM_TerminateStack_hook.get_original());
#else
			codsrc::VM_TerminateStack(a1, a2, a3, name);
#endif
		}

		NAKED void VM_TerminateStack_stub()
		{
			_asm
			{
				push esi;
				call VM_TerminateStack_call;
				add esp, 0x4;
				ret;
			}
		}

		void VM_TrimStack_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, unsigned int parentId, game::VariableStackBuffer* a3, int fromEndon)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::VM_TrimStack(a1, parentId, a3, fromEndon, VM_TrimStack_hook.get_original());
#else
			codsrc::VM_TrimStack(a1, parentId, a3, fromEndon);
#endif
		}

		NAKED void VM_TrimStack_stub()
		{
			_asm
			{
				push eax;
				call VM_TrimStack_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_TerminateRunningThread_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, unsigned int a2)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_TerminateRunningThread(a1, a2, Scr_TerminateRunningThread_hook.get_original());
#else
			codsrc::Scr_TerminateRunningThread(a1, a2);
#endif
		}

		NAKED void Scr_TerminateRunningThread_stub()
		{
			_asm
			{
				push edx;
				call Scr_TerminateRunningThread_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_TerminateWaitThread_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, unsigned int a2, unsigned int a3)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_TerminateWaitThread(a1, a2, a3, Scr_TerminateWaitThread_hook.get_original());
#else
			codsrc::Scr_TerminateWaitThread(a1, a2, a3);
#endif
		}

		NAKED void Scr_TerminateWaitThread_stub()
		{
			_asm
			{
				push eax;
				call Scr_TerminateWaitThread_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_CancelWaittill_call(game::scriptInstance_t inst, unsigned int startLocalId, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_CancelWaittill(inst, startLocalId, Scr_CancelWaittill_hook.get_original());
#else
			codsrc::Scr_CancelWaittill(inst, startLocalId);
#endif
		}

		NAKED void Scr_CancelWaittill_stub()
		{
			_asm
			{
				push eax;
				push ecx;
				call Scr_CancelWaittill_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_TerminateWaittillThread_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, unsigned int a2, unsigned int a3)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_TerminateWaittillThread(a1, a2, a3, Scr_TerminateWaittillThread_hook.get_original());
#else
			codsrc::Scr_TerminateWaittillThread(a1, a2, a3);
#endif
		}

		NAKED void Scr_TerminateWaittillThread_stub()
		{
			_asm
			{
				push eax;
				call Scr_TerminateWaittillThread_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_TerminateThread_call(unsigned int a2, game::scriptInstance_t a3, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_TerminateThread(a2, a3, Scr_TerminateThread_hook.get_original());
#else
			codsrc::Scr_TerminateThread(a2, a3);
#endif
		}

		NAKED void Scr_TerminateThread_stub()
		{
			_asm
			{
				push esi;
				push edi;
				call Scr_TerminateThread_call;
				add esp, 0x8;
				ret;
			}
		}

		void VM_Notify_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, int notifyListOwnerId, unsigned int stringValue, game::VariableValue* top)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::VM_Notify(inst, notifyListOwnerId, stringValue, top, VM_Notify_hook.get_original());
#else
			codsrc::VM_Notify(inst, notifyListOwnerId, stringValue, top);
#endif
		}

		NAKED void VM_Notify_stub()
		{
			_asm
			{
				push eax;
				call VM_Notify_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_NotifyNum_Internal_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, int entNum, int entClass, unsigned int notifStr, int numParams)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_NotifyNum_Internal(inst, entNum, entClass, notifStr, numParams, Scr_NotifyNum_Internal_hook.get_original());
#else
			codsrc::Scr_NotifyNum_Internal(inst, entNum, entClass, notifStr, numParams);
#endif
		}

		NAKED void Scr_NotifyNum_Internal_stub()
		{
			_asm
			{
				push eax;
				call Scr_NotifyNum_Internal_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_CancelNotifyList_call(unsigned int notifyListOwnerId, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_CancelNotifyList(notifyListOwnerId, inst, Scr_CancelNotifyList_hook.get_original());
#else
			codsrc::Scr_CancelNotifyList(notifyListOwnerId, inst);
#endif
		}

		NAKED void Scr_CancelNotifyList_stub()
		{
			_asm
			{
				push eax;
				call Scr_CancelNotifyList_call;
				add esp, 0x4;
				ret;
			}
		}

		void VM_TerminateTime_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, unsigned int parentId)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::VM_TerminateTime(a1, parentId, VM_TerminateTime_hook.get_original());
#else
			codsrc::VM_TerminateTime(a1, parentId);
#endif
		}

		NAKED void VM_TerminateTime_stub()
		{
			_asm
			{
				push eax;
				call VM_TerminateTime_call;
				add esp, 0x4;
				ret;
			}
		}

		void VM_Resume_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, unsigned int timeId)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::VM_Resume(inst, timeId, VM_Resume_hook.get_original());
#else
			codsrc::VM_Resume(inst, timeId);
#endif
		}

		NAKED void VM_Resume_stub()
		{
			_asm
			{
				push eax;
				call VM_Resume_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int VM_Execute_stub(game::scriptInstance_t inst, unsigned int localId, const char* pos, unsigned int paramcount)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return VM_Execute_hook.invoke<unsigned int>(inst, localId, pos, paramcount);
#else
			return codsrc::VM_Execute(inst, localId, pos, paramcount);
#endif
		}

		unsigned __int16 Scr_ExecThread_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, unsigned int handle, unsigned int paramCount)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::Scr_ExecThread(inst, handle, paramCount, Scr_ExecThread_hook.get_original());
#else
			return codsrc::Scr_ExecThread(inst, handle, paramCount);
#endif
		}

		NAKED unsigned __int16 Scr_ExecThread_stub/*@<ax>*/()
		{
			_asm
			{
				push edi;
				call Scr_ExecThread_call;
				add esp, 0x4;
				ret;
			}
		}
		unsigned __int16 Scr_ExecEntThread_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, int entNum, unsigned int handle, int numParams, unsigned int entClass)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::Scr_ExecEntThreadNum(inst, entNum, handle, numParams, entClass, Scr_ExecEntThread_hook.get_original());
#else
			return codsrc::Scr_ExecEntThreadNum(inst, entNum, handle, numParams, entClass);
#endif
		}

		NAKED unsigned __int16 Scr_ExecEntThread_stub/*@<ax>*/()
		{
			_asm
			{
				push edi;
				call Scr_ExecEntThread_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_AddExecThread_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, unsigned int handle)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_AddExecThread(a1, handle, Scr_AddExecThread_hook.get_original());
#else
			codsrc::Scr_AddExecThread(a1, handle);
#endif
		}

		NAKED void Scr_AddExecThread_stub()
		{
			_asm
			{
				push edi;
				call Scr_AddExecThread_call;
				add esp, 0x4;
				ret;
			}
		}

		void VM_SetTime_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::VM_SetTime(a1, VM_SetTime_hook.get_original());
#else
			codsrc::VM_SetTime(a1);
#endif
		}

		NAKED void VM_SetTime_stub()
		{
			_asm
			{
				push eax;
				call VM_SetTime_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_InitSystem_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_InitSystem(a1, Scr_InitSystem_hook.get_original());
#else
			codsrc::Scr_InitSystem(a1);
#endif
		}

		NAKED void Scr_InitSystem_stub()
		{
			_asm
			{
				push edi;
				call Scr_InitSystem_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_ShutdownSystem_stub(game::scriptInstance_t inst, int bComplete)
		{
#if USE_SCHEDULER_FUNCTION_OVERRIDES == 1
			scheduler::Scr_ShutdownSystem_Override(inst, bComplete);
			return;
#endif

#ifdef RE_CSCR_VM_USE_WRAPPERS
			Scr_ShutdownSystem_hook.invoke<void>(inst, bComplete);
#else
			codsrc::Scr_ShutdownSystem(inst, bComplete);
#endif
		}

		BOOL Scr_IsSystemActive_stub()
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return Scr_IsSystemActive_hook.invoke<BOOL>();
#else
			return codsrc::Scr_IsSystemActive();
#endif
		}

		int Scr_GetInt_call(game::scriptInstance_t inst, unsigned int index, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::Scr_GetInt(inst, index, Scr_GetInt_hook.get_original());
#else
			return codsrc::Scr_GetInt(inst, index);
#endif
		}

		NAKED int Scr_GetInt_stub/*@<eax>*/()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_GetInt_call;
				add esp, 0x8;
				ret;
			}
		}

		game::scr_anim_s Scr_GetAnim_call(unsigned int index, game::XAnimTree_s* a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::Scr_GetAnim(index, a2, Scr_GetAnim_hook.get_original());
#else
			return codsrc::Scr_GetAnim(index, a2);
#endif
		}

		NAKED game::scr_anim_s Scr_GetAnim_stub/*@<eax>*/()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_GetAnim_call;
				add esp, 0x8;
				ret;
			}
		}

		game::scr_animtree_t Scr_GetAnimTree_stub()
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return Scr_GetAnimTree_hook.invoke<game::scr_animtree_t>();
#else
			return codsrc::Scr_GetAnimTree();
#endif
		}

		float Scr_GetFloat_call(game::scriptInstance_t inst, unsigned int index, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::Scr_GetFloat(inst, index, Scr_GetFloat_hook.get_original());
#else
			return codsrc::Scr_GetFloat(inst, index);
#endif
		}

		NAKED float Scr_GetFloat_stub/*@<xmm0>*/()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_GetFloat_call;
				add esp, 0x8;

				sub esp, 4;

				fstp dword ptr[esp];
				movsd xmm0, dword ptr[esp];
				add esp, 4;

				ret;
			}
		}

		unsigned int Scr_GetConstString_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, unsigned int index)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::Scr_GetConstString(inst, index, Scr_GetConstString_hook.get_original());
#else
			return codsrc::Scr_GetConstString(inst, index);
#endif
		}

		NAKED unsigned int Scr_GetConstString_stub/*@<eax>*/()
		{
			_asm
			{
				push eax;
				call Scr_GetConstString_call;
				add esp, 0x4;
				ret;
			}
		}

		unsigned int Scr_GetConstLowercaseString_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, unsigned int index)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::Scr_GetConstLowercaseString(inst, index, Scr_GetConstLowercaseString_hook.get_original());
#else
			return codsrc::Scr_GetConstLowercaseString(inst, index);
#endif
		}

		NAKED const char * Scr_GetConstLowercaseString_stub/*@<eax>*/()
		{
			_asm
			{
				push ecx;
				call Scr_GetConstLowercaseString_call;
				add esp, 0x4;
				ret;
			}
		}

		const char* Scr_GetString_call(unsigned int index, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::Scr_GetString(index, inst, Scr_GetString_hook.get_original());
#else
			return codsrc::Scr_GetString(index, inst);
#endif
		}

		NAKED const char * Scr_GetString_stub/*@<eax>*/()
		{
			_asm
			{
				push esi;
				push eax;
				call Scr_GetString_call;
				add esp, 0x8;
				ret;
			}
		}

		unsigned int Scr_GetConstStringIncludeNull_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::Scr_GetConstStringIncludeNull(a1, Scr_GetConstStringIncludeNull_hook.get_original());
#else
			return codsrc::Scr_GetConstStringIncludeNull(a1);
#endif
		}

		NAKED unsigned int Scr_GetConstStringIncludeNull_stub/*@<eax>*/()
		{
			_asm
			{
				push eax;
				call Scr_GetConstStringIncludeNull_call;
				add esp, 0x4;
				ret;
			}
		}

		char* Scr_GetDebugString_call(game::scriptInstance_t a1, unsigned int a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::Scr_GetDebugString(a1, a2, Scr_GetDebugString_hook.get_original());
#else
			return codsrc::Scr_GetDebugString(a1, a2);
#endif
		}

		NAKED char * Scr_GetDebugString_stub/*@<eax>*/()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_GetDebugString_call;
				add esp, 0x8;
				ret;
			}
		}

		unsigned int Scr_GetConstIString_call(unsigned int index, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::Scr_GetConstIString(index, Scr_GetConstIString_hook.get_original());
#else
			return codsrc::Scr_GetConstIString(index);
#endif
		}

		NAKED unsigned int Scr_GetConstIString_stub/*@<eax>*/()
		{
			_asm
			{
				push eax;
				call Scr_GetConstIString_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_GetVector_call(game::scriptInstance_t inst, float* value, [[maybe_unused]] void* caller_addr, unsigned int index)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_GetVector(inst, value, index, Scr_GetVector_hook.get_original());
#else
			codsrc::Scr_GetVector(inst, value, index);
#endif
		}

		NAKED void Scr_GetVector_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_GetVector_call;
				add esp, 0x8;
				ret;
			}
		}

		unsigned int Scr_GetFunc_stub()
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return Scr_GetFunc_hook.invoke<unsigned int>();
#else
			return codsrc::Scr_GetFunc();
#endif
		}

		game::scr_entref_t* Scr_GetEntityRef_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, game::scr_entref_t* retstr, unsigned int index)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::Scr_GetEntityRef(inst, retstr, index, Scr_GetEntityRef_hook.get_original());
#else
			return codsrc::Scr_GetEntityRef(inst, retstr, index);
#endif
		}

		NAKED game::scr_entref_t * Scr_GetEntityRef_stub/*@<eax>*/()
		{
			_asm
			{
				push eax;
				call Scr_GetEntityRef_call;
				add esp, 0x4;
				ret;
			}
		}

		game::VariableUnion Scr_GetObject_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::Scr_GetObject(a1, Scr_GetObject_hook.get_original());
#else
			return codsrc::Scr_GetObject(a1);
#endif
		}

		NAKED game::VariableUnion Scr_GetObject_stub/*@<eax>*/()
		{
			_asm
			{
				push eax;
				call Scr_GetObject_call;
				add esp, 0x4;
				ret;
			}
		}

		game::VariableType Scr_GetType_call(game::scriptInstance_t inst, unsigned int index, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::Scr_GetType(inst, index, Scr_GetType_hook.get_original());
#else
			return codsrc::Scr_GetType(inst, index);
#endif
		}

		NAKED game::VariableType Scr_GetType_stub/*@<eax>*/()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_GetType_call;
				add esp, 0x8;
				ret;
			}
		}

		const char* Scr_GetTypeName_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::Scr_GetTypeName(a1, Scr_GetTypeName_hook.get_original());
#else
			return codsrc::Scr_GetTypeName(a1);
#endif
		}

		NAKED char * Scr_GetTypeName_stub/*@<eax>*/()
		{
			_asm
			{
				push eax;
				call Scr_GetTypeName_call;
				add esp, 0x4;
				ret;
			}
		}

		game::VariableType Scr_GetPointerType_call(game::scriptInstance_t a1, unsigned int a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::Scr_GetPointerType(a1, a2, Scr_GetPointerType_hook.get_original());
#else
			return codsrc::Scr_GetPointerType(a1, a2);
#endif
		}

		NAKED game::VariableType Scr_GetPointerType_stub/*@<eax>*/()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_GetPointerType_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_AddInt_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, int value)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_AddInt(inst, value, Scr_AddInt_hook.get_original());
#else
			codsrc::Scr_AddInt(inst, value);
#endif
		}

		NAKED void Scr_AddInt_stub()
		{
			_asm
			{
				push eax;
				call Scr_AddInt_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_AddFloat_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, float value)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_AddFloat(inst, value, Scr_AddFloat_hook.get_original());
#else
			codsrc::Scr_AddFloat(inst, value);
#endif
		}

		NAKED void Scr_AddFloat_stub()
		{
			_asm
			{
				push eax;
				call Scr_AddFloat_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_AddAnim_stub(game::scr_anim_s a1)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			Scr_AddAnim_hook.invoke<game::VariableUnion>(a1);
#else
			codsrc::Scr_AddAnim(a1);
#endif
		}

		void Scr_AddUndefined_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_AddUndefined(inst, Scr_AddUndefined_hook.get_original());
#else
			codsrc::Scr_AddUndefined(inst);
#endif
		}

		NAKED void Scr_AddUndefined_stub()
		{
			_asm
			{
				push eax;
				call Scr_AddUndefined_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_AddObject_call(game::scriptInstance_t inst, unsigned int entid, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_AddObject(inst, entid, Scr_AddObject_hook.get_original());
#else
			codsrc::Scr_AddObject(inst, entid);
#endif
		}

		NAKED void Scr_AddObject_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call Scr_AddObject_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_AddString_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, char* string)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_AddString(inst, string, Scr_AddString_hook.get_original());
#else
			codsrc::Scr_AddString(inst, string);
#endif
		}

		NAKED void Scr_AddString_stub()
		{
			_asm
			{
				push eax;
				call Scr_AddString_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_AddIString_call(char* string, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_AddIString(string, Scr_AddIString_hook.get_original());
#else
			codsrc::Scr_AddIString(string);
#endif
		}

		NAKED void Scr_AddIString_stub()
		{
			_asm
			{
				push esi;
				call Scr_AddIString_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_AddConstString_call(game::scriptInstance_t inst, unsigned int id, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_AddConstString(inst, id, Scr_AddConstString_hook.get_original());
#else
			codsrc::Scr_AddConstString(inst, id);
#endif
		}

		NAKED void Scr_AddConstString_stub()
		{
			_asm
			{
				push esi;
				push eax;
				call Scr_AddConstString_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_AddVector_call(game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, float* value)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_AddVector(inst, value, Scr_AddVector_hook.get_original());
#else
			codsrc::Scr_AddVector(inst, value);
#endif
		}

		NAKED void Scr_AddVector_stub()
		{
			_asm
			{
				push eax;
				call Scr_AddVector_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_MakeArray_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_MakeArray(a1, Scr_MakeArray_hook.get_original());
#else
			codsrc::Scr_MakeArray(a1);
#endif
		}

		NAKED void Scr_MakeArray_stub()
		{
			_asm
			{
				push eax;
				call Scr_MakeArray_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_AddArray_stub(game::scriptInstance_t inst)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			Scr_AddArray_hook.invoke<void>(inst);
#else
			codsrc::Scr_AddArray(inst);
#endif
		}

		void Scr_AddArrayStringIndexed_call(unsigned int id, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_AddArrayStringIndexed(id, inst, Scr_AddArrayStringIndexed_hook.get_original());
#else
			codsrc::Scr_AddArrayStringIndexed(id, inst);
#endif
		}

		NAKED void Scr_AddArrayStringIndexed_stub()
		{
			_asm
			{
				push edi;
				push ecx;
				call Scr_AddArrayStringIndexed_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_Error_call(const char* err, game::scriptInstance_t inst, [[maybe_unused]] void* caller_addr, int is_terminal)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_Error(err, inst, is_terminal, Scr_Error_hook.get_original());
#else
			codsrc::Scr_Error(err, inst, is_terminal);
#endif
		}

		NAKED void Scr_Error_stub()
		{
			_asm
			{
				push edi;
				push ecx;
				call Scr_Error_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_TerminalError_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr, char* Source)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_TerminalError(a1, Source, Scr_TerminalError_hook.get_original());
#else
			codsrc::Scr_TerminalError(a1, Source);
#endif
		}

		NAKED void Scr_TerminalError_stub()
		{
			_asm
			{
				push eax;
				call Scr_TerminalError_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_ParamError_call(int a1, game::scriptInstance_t a2, [[maybe_unused]] void* caller_addr, char* Source)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_ParamError(a1, a2, Source, Scr_ParamError_hook.get_original());
#else
			codsrc::Scr_ParamError(a1, a2, Source);
#endif
		}

		NAKED void Scr_ParamError_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_ParamError_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_ObjectError_call(game::scriptInstance_t a1, const char* a2, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_ObjectError(a1, a2, Scr_ObjectError_hook.get_original());
#else
			codsrc::Scr_ObjectError(a1, a2);
#endif
		}

		NAKED void Scr_ObjectError_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_ObjectError_call;
				add esp, 0x8;
				ret;
			}
		}

		bool SetEntityFieldValue_call(game::scriptInstance_t inst, int offset_, int entnum, [[maybe_unused]] void* caller_addr, game::classNum_e classnum, int clientNum, game::VariableValue* value)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::SetEntityFieldValue(inst, offset_, entnum, classnum, clientNum, value, SetEntityFieldValue_hook.get_original());
#else
			return codsrc::SetEntityFieldValue(inst, offset_, entnum, classnum, clientNum, value);
#endif
		}

		NAKED bool SetEntityFieldValue_stub/*@<al>*/()
		{
			_asm
			{
				push ecx;
				push eax;
				push edi;
				call SetEntityFieldValue_call;
				add esp, 0xC;
				ret;
			}
		}

		game::VariableValue GetEntityFieldValue_call(int offset_, int entnum, [[maybe_unused]] void* caller_addr, game::scriptInstance_t inst, game::classNum_e classnum, int clientNum)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			return game::GetEntityFieldValue(offset_, entnum, inst, classnum, clientNum, GetEntityFieldValue_hook.get_original());
#else
			return codsrc::GetEntityFieldValue(offset_, entnum, inst, classnum, clientNum);
#endif
		}

		NAKED game::VariableValue GetEntityFieldValue_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call GetEntityFieldValue_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_SetStructField_call(unsigned int a1, unsigned int a2, [[maybe_unused]] void* caller_addr, game::scriptInstance_t a3)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_SetStructField(a1, a2, a3, Scr_SetStructField_hook.get_original());
#else
			codsrc::Scr_SetStructField(a1, a2, a3);
#endif
		}

		NAKED void Scr_SetStructField_stub()
		{
			_asm
			{
				push ecx;
				push eax;
				call Scr_SetStructField_call;
				add esp, 0x8;
				ret;
			}
		}

		void Scr_IncTime_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_IncTime(a1, Scr_IncTime_hook.get_original());
#else
			codsrc::Scr_IncTime(a1);
#endif
		}

		NAKED void Scr_IncTime_stub()
		{
			_asm
			{
				push eax;
				call Scr_IncTime_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_RunCurrentThreads_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_RunCurrentThreads(a1, Scr_RunCurrentThreads_hook.get_original());
#else
			codsrc::Scr_RunCurrentThreads(a1);
#endif
		}

		NAKED void Scr_RunCurrentThreads_stub()
		{
			_asm
			{
				push esi;
				call Scr_RunCurrentThreads_call;
				add esp, 0x4;
				ret;
			}
		}

		void Scr_ResetTimeout_call(game::scriptInstance_t a1, [[maybe_unused]] void* caller_addr)
		{
#ifdef RE_CSCR_VM_USE_WRAPPERS
			game::Scr_ResetTimeout(a1, Scr_ResetTimeout_hook.get_original());
#else
			codsrc::Scr_ResetTimeout(a1);
#endif
		}

		NAKED void Scr_ResetTimeout_stub()
		{
			_asm
			{
				push eax;
				call Scr_ResetTimeout_call;
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
#ifdef RE_CSCR_VM_USE_WRAPPERS
			quick = false;
#endif

			Scr_VM_Init_hook.create(game::Scr_VM_Init.get(), Scr_VM_Init_stub, quick);
			Scr_Init_hook.create(game::Scr_Init_ADDR(), Scr_Init_stub, quick);
			Scr_Shutdown_hook.create(game::Scr_Shutdown_ADDR(), Scr_Shutdown_stub, quick);
			Scr_ErrorInternal_hook.create(game::Scr_ErrorInternal_ADDR(), Scr_ErrorInternal_stub, quick);
			Scr_ClearOutParams_hook.create(game::Scr_ClearOutParams_ADDR(), Scr_ClearOutParams_stub, quick);
			GetDummyObject_hook.create(game::GetDummyObject_ADDR(), GetDummyObject_stub, quick);
			GetDummyFieldValue_hook.create(game::GetDummyFieldValue_ADDR(), GetDummyFieldValue_stub, quick);
			VM_ExecuteInternal_hook.create(game::VM_ExecuteInternal.get(), VM_ExecuteInternal_stub, quick);
			VM_CancelNotifyInternal_hook.create(game::VM_CancelNotifyInternal_ADDR(), VM_CancelNotifyInternal_stub, quick);
			VM_CancelNotify_hook.create(game::VM_CancelNotify_ADDR(), VM_CancelNotify_stub, quick);
			VM_ArchiveStack_hook.create(game::VM_ArchiveStack_ADDR(), VM_ArchiveStack_stub, quick);
			Scr_AddLocalVars_hook.create(game::Scr_AddLocalVars_ADDR(), Scr_AddLocalVars_stub, quick);
			VM_UnarchiveStack_hook.create(game::VM_UnarchiveStack.get(), VM_UnarchiveStack_stub, quick);
			VM_TerminateStack_hook.create(game::VM_TerminateStack_ADDR(), VM_TerminateStack_stub, quick);
			VM_TrimStack_hook.create(game::VM_TrimStack_ADDR(), VM_TrimStack_stub, quick);
			Scr_TerminateRunningThread_hook.create(game::Scr_TerminateRunningThread_ADDR(), Scr_TerminateRunningThread_stub, quick);
			Scr_TerminateWaitThread_hook.create(game::Scr_TerminateWaitThread_ADDR(), Scr_TerminateWaitThread_stub, quick);
			Scr_CancelWaittill_hook.create(game::Scr_CancelWaittill_ADDR(), Scr_CancelWaittill_stub, quick);
			Scr_TerminateWaittillThread_hook.create(game::Scr_TerminateWaittillThread_ADDR(), Scr_TerminateWaittillThread_stub, quick);
			Scr_TerminateThread_hook.create(game::Scr_TerminateThread_ADDR(), Scr_TerminateThread_stub, quick);
			VM_Notify_hook.create(game::VM_Notify_ADDR(), VM_Notify_stub, quick);
			Scr_NotifyNum_Internal_hook.create(game::Scr_NotifyNum_Internal_ADDR(), Scr_NotifyNum_Internal_stub, quick);
			Scr_CancelNotifyList_hook.create(game::Scr_CancelNotifyList_ADDR(), Scr_CancelNotifyList_stub, quick);
			VM_TerminateTime_hook.create(game::VM_TerminateTime_ADDR(), VM_TerminateTime_stub, quick);
			VM_Resume_hook.create(game::VM_Resume_ADDR(), VM_Resume_stub, quick);
			VM_Execute_hook.create(game::VM_Execute.get(), VM_Execute_stub, quick);
			Scr_ExecThread_hook.create(game::Scr_ExecThread_ADDR(), Scr_ExecThread_stub, quick);
			Scr_ExecEntThread_hook.create(game::Scr_ExecEntThread_ADDR(), Scr_ExecEntThread_stub, quick);
			Scr_AddExecThread_hook.create(game::Scr_AddExecThread_ADDR(), Scr_AddExecThread_stub, quick);
			VM_SetTime_hook.create(game::VM_SetTime_ADDR(), VM_SetTime_stub, quick);
			Scr_InitSystem_hook.create(game::Scr_InitSystem_ADDR(), Scr_InitSystem_stub, quick);
			Scr_ShutdownSystem_hook.create(game::Scr_ShutdownSystem.get(), Scr_ShutdownSystem_stub, quick);
			Scr_IsSystemActive_hook.create(game::Scr_IsSystemActive.get(), Scr_IsSystemActive_stub, quick);
			Scr_GetInt_hook.create(game::Scr_GetInt_ADDR(), Scr_GetInt_stub, quick);
			Scr_GetAnim_hook.create(game::Scr_GetAnim_ADDR(), Scr_GetAnim_stub, quick);
			Scr_GetAnimTree_hook.create(game::Scr_GetAnimTree.get(), Scr_GetAnimTree_stub, quick);
			Scr_GetFloat_hook.create(game::Scr_GetFloat_ADDR(), Scr_GetFloat_stub, quick);
			Scr_GetConstString_hook.create(game::Scr_GetConstString_ADDR(), Scr_GetConstString_stub, quick);
			Scr_GetConstLowercaseString_hook.create(game::Scr_GetConstLowercaseString_ADDR(), Scr_GetConstLowercaseString_stub, quick);
			Scr_GetString_hook.create(game::Scr_GetString_ADDR(), Scr_GetString_stub, quick);
			Scr_GetConstStringIncludeNull_hook.create(game::Scr_GetConstStringIncludeNull_ADDR(), Scr_GetConstStringIncludeNull_stub, quick);
			Scr_GetDebugString_hook.create(game::Scr_GetDebugString_ADDR(), Scr_GetDebugString_stub, quick);
			Scr_GetConstIString_hook.create(game::Scr_GetConstIString_ADDR(), Scr_GetConstIString_stub, quick);
			Scr_GetVector_hook.create(game::Scr_GetVector_ADDR(), Scr_GetVector_stub, quick);
			Scr_GetFunc_hook.create(game::Scr_GetFunc.get(), Scr_GetFunc_stub, quick);
			Scr_GetEntityRef_hook.create(game::Scr_GetEntityRef_ADDR(), Scr_GetEntityRef_stub, quick);
			Scr_GetObject_hook.create(game::Scr_GetObject_ADDR(), Scr_GetObject_stub, quick);
			Scr_GetType_hook.create(game::Scr_GetType_ADDR(), Scr_GetType_stub, quick);
			Scr_GetTypeName_hook.create(game::Scr_GetTypeName_ADDR(), Scr_GetTypeName_stub, quick);
			Scr_GetPointerType_hook.create(game::Scr_GetPointerType_ADDR(), Scr_GetPointerType_stub, quick);
			Scr_AddInt_hook.create(game::Scr_AddInt_ADDR(), Scr_AddInt_stub, quick);
			Scr_AddFloat_hook.create(game::Scr_AddFloat_ADDR(), Scr_AddFloat_stub, quick);
			Scr_AddAnim_hook.create(game::Scr_AddAnim.get(), Scr_AddAnim_stub, quick);
			Scr_AddUndefined_hook.create(game::Scr_AddUndefined_ADDR(), Scr_AddUndefined_stub, quick);
			Scr_AddObject_hook.create(game::Scr_AddObject_ADDR(), Scr_AddObject_stub, quick);
			Scr_AddString_hook.create(game::Scr_AddString_ADDR(), Scr_AddString_stub, quick);
			Scr_AddIString_hook.create(game::Scr_AddIString_ADDR(), Scr_AddIString_stub, quick);
			Scr_AddConstString_hook.create(game::Scr_AddConstString_ADDR(), Scr_AddConstString_stub, quick);
			Scr_AddVector_hook.create(game::Scr_AddVector_ADDR(), Scr_AddVector_stub, quick);
			Scr_MakeArray_hook.create(game::Scr_MakeArray_ADDR(), Scr_MakeArray_stub, quick);
			Scr_AddArray_hook.create(game::Scr_AddArray.get(), Scr_AddArray_stub, quick);
			Scr_AddArrayStringIndexed_hook.create(game::Scr_AddArrayStringIndexed_ADDR(), Scr_AddArrayStringIndexed_stub, quick);
			Scr_Error_hook.create(game::Scr_Error_ADDR(), Scr_Error_stub, quick);
			Scr_TerminalError_hook.create(game::Scr_TerminalError_ADDR(), Scr_TerminalError_stub, quick);
			Scr_ParamError_hook.create(game::Scr_ParamError_ADDR(), Scr_ParamError_stub, quick);
			Scr_ObjectError_hook.create(game::Scr_ObjectError_ADDR(), Scr_ObjectError_stub, quick);
			SetEntityFieldValue_hook.create(game::SetEntityFieldValue_ADDR(), SetEntityFieldValue_stub, quick);
			GetEntityFieldValue_hook.create(game::GetEntityFieldValue_ADDR(), GetEntityFieldValue_stub, quick);
			Scr_SetStructField_hook.create(game::Scr_SetStructField_ADDR(), Scr_SetStructField_stub, quick);
			Scr_IncTime_hook.create(game::Scr_IncTime_ADDR(), Scr_IncTime_stub, quick);
			Scr_RunCurrentThreads_hook.create(game::Scr_RunCurrentThreads_ADDR(), Scr_RunCurrentThreads_stub, quick);
			Scr_ResetTimeout_hook.create(game::Scr_ResetTimeout_ADDR(), Scr_ResetTimeout_stub, quick);
		}

	private:
	};
}
REGISTER_COMPONENT(re_cscr_vm::component)
#endif
