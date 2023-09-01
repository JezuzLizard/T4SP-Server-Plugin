#include <stdinc.hpp>
#include "clientscript_public.hpp"

#pragma warning(push)
#pragma warning(disable: 4244)
#pragma warning(disable: 4146)

namespace codsrc
{
	// Restored
	void Scr_ClearErrorMessage(game::scriptInstance_t inst)
	{
		game::gScrVarPub[inst].error_message = 0;
		game::gScrVmGlob[inst].dialog_error_message = 0;
		game::gScrVarPub[inst].error_index = 0;
	}

	// Completed
	void Scr_VM_Init(game::scriptInstance_t inst)
	{
		game::gScrVmPub[inst].maxstack = &game::gScrVmPub[inst].stack[2047];
		game::gScrVmPub[inst].top = game::gScrVmPub[inst].stack;
		game::gScrVmPub[inst].function_count = 0;
		game::gScrVmPub[inst].function_frame = game::gScrVmPub[inst].function_frame_start;
		game::gScrVmPub[inst].localVars = game::gScrVmGlob[inst].localVarsStack - 1;
		game::gScrVarPub[inst].evaluate = 0;
		game::gScrVmPub[inst].debugCode = 0;
		game::Scr_ClearErrorMessage(inst);
		game::gScrVmPub[inst].terminal_error = 0;
		game::gScrVmPub[inst].outparamcount = 0;
		game::gScrVmPub[inst].inparamcount = 0;
		game::gScrVarPub[inst].tempVariable = game::AllocValue(inst);
		game::gScrVarPub[inst].timeArrayId = 0;
		game::gScrVarPub[inst].pauseArrayId = 0;
		game::gScrVarPub[inst].levelId = 0;
		game::gScrVarPub[inst].gameId = 0;
		game::gScrVarPub[inst].animId = 0;
		game::gScrVarPub[inst].freeEntList = 0;
		game::gScrVmPub[inst].stack[0].type = game::VAR_CODEPOS;
		game::gScrVmGlob[inst].loading = 0;

		if ( inst == game::SCRIPTINSTANCE_SERVER )
		{
			*game::sv_clientside = game::Dvar_RegisterBool(
				0,
				"sv_clientside",
				game::DVAR_FLAG_NONE,
				"Used to toggle systems in script on and off on the server.");
		}
	}

	// Completed
	void Scr_Init(game::scriptInstance_t inst)
	{
		assert(!game::gScrVarPub[inst].bInited);

		game::Scr_InitClassMap(inst);
		game::Scr_VM_Init(inst);
		game::gScrCompilePub[inst].script_loading = 0;
		game::gScrAnimPub[inst].animtree_loading = 0;
		game::gScrCompilePub[inst].scriptsPos = 0;
		game::gScrCompilePub[inst].scriptsCount = 0;
		game::gScrCompilePub[inst].loadedscripts = 0;
		game::gScrAnimPub[inst].animtrees = 0;
		game::gScrCompilePub[inst].builtinMeth = 0;
		game::gScrCompilePub[inst].builtinFunc = 0;
		game::gScrVarPub[inst].bInited = 1;
	}

	// Resotred
	void VM_Shutdown(game::scriptInstance_t inst)
	{
		if ( game::gScrVarPub[inst].tempVariable )
		{
			game::FreeValue(game::gScrVarPub[inst].tempVariable, inst);
			game::gScrVarPub[inst].tempVariable = 0;
		}
	}

	// Restored
	void Scr_ShutdownVariables(game::scriptInstance_t inst)
	{
		if ( game::gScrVarPub[inst].gameId )
		{
			game::FreeValue(game::gScrVarPub[inst].gameId, inst);
			game::gScrVarPub[inst].gameId = 0;
		}
	}

	// Completed
	void Scr_Shutdown(game::scriptInstance_t inst)
	{
		if ( game::gScrVarPub[inst].bInited )
		{
			game::gScrVarPub[inst].bInited = 0;
			game::VM_Shutdown(inst);
			game::Scr_ShutdownVariables(inst);
		}
	}

	jmp_buf g_script_error[2][33];

	// Completed
	void Scr_ErrorInternal(game::scriptInstance_t inst)
	{
		assert(game::gScrVarPub[inst].error_message);

		if ( !game::gScrVarPub[inst].evaluate && !game::gScrCompilePub[inst].script_loading )
		{
			if ( game::gScrVmPub[inst].function_count || game::gScrVmPub[inst].debugCode )
			{
				game::Com_PrintMessage(game::CON_CHANNEL_LOGFILEONLY, "throwing script exception: ", 0);
				game::Com_PrintMessage(game::CON_CHANNEL_LOGFILEONLY, game::gScrVarPub[inst].error_message, 0);
				game::Com_PrintMessage(game::CON_CHANNEL_LOGFILEONLY, "\n", 0);

				assert(game::g_script_error_level[inst] < 33);

				//game::longjmp((int*)game::g_script_error.get() + 0x10 * (0x21 * inst + game::g_script_error_level[inst]), -1);
				longjmp(g_script_error[inst][game::g_script_error_level[inst]], -1);
			}

			game::Sys_Error("%s", game::gScrVarPub[inst].error_message);
		}
		if ( game::gScrVmPub[inst].terminal_error )
		{
			game::Sys_Error("%s", game::gScrVarPub[inst].error_message);
		}
	}

	// Completed
	void Scr_ClearOutParams(game::scriptInstance_t inst)
	{
		while ( game::gScrVmPub[inst].outparamcount )
		{
			game::RemoveRefToValueInternal(inst, game::gScrVmPub[inst].top->type, game::gScrVmPub[inst].top->u);
			--game::gScrVmPub[inst].top;
			--game::gScrVmPub[inst].outparamcount;
		}
	}

	// Restored
	void ClearVariableValue(game::scriptInstance_t inst, unsigned int id)
	{
		game::VariableValueInternal *entryValue;

		assert(id);

		entryValue = &game::gScrVarGlob[inst].childVariables[id];

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(!IsObject(entryValue));

		assert((entryValue->w.type & VAR_MASK) != game::VAR_STACK);

		game::RemoveRefToValueInternal(inst, (game::VariableType)(entryValue->w.status & VAR_MASK), entryValue->u.u);
		entryValue->w.status &= ~VAR_MASK;

		assert((entryValue->w.type & VAR_MASK) == game::VAR_UNDEFINED);
	}

	// Completed
	unsigned int GetDummyObject(game::scriptInstance_t inst)
	{
		game::ClearVariableValue(inst, game::gScrVarPub[inst].tempVariable);
		return game::GetObject(inst, game::gScrVarPub[inst].tempVariable);
	}

	// Completed
	unsigned int GetDummyFieldValue(game::scriptInstance_t inst)
	{
		game::ClearVariableValue(inst, game::gScrVarPub[inst].tempVariable);
		return game::gScrVarPub[inst].tempVariable;
	}

	// Restored
	BOOL IsFieldObject(game::scriptInstance_t inst, unsigned int id)
	{
		game::VariableValueInternal *entryValue;

		assert(id);

		entryValue = &game::gScrVarGlob[inst].parentVariables[id + 1];

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);
		assert(IsObject(entryValue));

		return (game::VariableType)(entryValue->w.status & VAR_MASK) < game::VAR_ARRAY;
	}

	// Restored
	void RemoveVariableValue(game::scriptInstance_t inst, unsigned int parentId, unsigned int index)
	{
		unsigned int id;

		assert(index);
		id = game::gScrVarGlob[inst].childVariables[index].hash.id;

		assert(id);

		game::MakeVariableExternal(&game::gScrVarGlob[inst].parentVariables[parentId + 1], inst, index);
		game::FreeChildValue(id, inst, parentId);
	}

	// Restored
	unsigned int GetNewVariableIndexReverseInternal(game::scriptInstance_t inst, unsigned int parentId, unsigned int name)
	{
		assert(!game::FindVariableIndexInternal(inst, parentId, name));

		return game::GetNewVariableIndexReverseInternal2(name, inst, parentId, (parentId + name) % 0xFFFD + 1);
	}

	// Restored
	unsigned int GetNewObjectVariableReverse(game::scriptInstance_t inst, unsigned int parentId, unsigned int id)
	{
		assert((game::gScrVarGlob[inst].parentVariables[parentId + 1].w.status & VAR_MASK) == game::VAR_ARRAY);

		return game::gScrVarGlob[inst].childVariables[game::GetNewVariableIndexReverseInternal(inst, parentId, id + 0x10000)].hash.id;
	}

	// Restored
	unsigned int Scr_GetLocalVar(game::scriptInstance_t inst, int pos)
	{
		return game::gScrVmPub[inst].localVars[-pos];
	}

	// Restored
	void Scr_EvalBoolNot(game::scriptInstance_t inst, game::VariableValue *value)
	{
		game::Scr_CastBool(inst, value);

		if ( value->type == game::VAR_INTEGER )
		{
			value->u.intValue = value->u.intValue == 0;
		}
	}

	// Restored
	unsigned int GetInternalVariableIndex([[maybe_unused]] game::scriptInstance_t inst, unsigned int unsignedValue)
	{
		assert(game::IsValidArrayIndex(inst, unsignedValue));
		return (unsignedValue + 0x800000) & 0xFFFFFF;
	}

	// Restored
	const char * Scr_ReadCodePos([[maybe_unused]] game::scriptInstance_t inst, const char **pos)
	{
		int ans;

		ans = *(int *)*pos;
		*pos += 4;
		return (const char *)ans;
	}

	// Restored
	unsigned int Scr_ReadUnsignedInt([[maybe_unused]] game::scriptInstance_t inst, const char **pos)
	{
		unsigned int ans;

		ans = *(unsigned int *)*pos;
		*pos += 4;
		return ans;
	}

	// Restored
	unsigned short Scr_ReadUnsignedShort([[maybe_unused]] game::scriptInstance_t inst, const char **pos)
	{
		unsigned short ans;

		ans = *(unsigned short *)*pos;
		*pos += 2;
		return ans;
	}

	// Restored
	unsigned char Scr_ReadUnsignedByte([[maybe_unused]] game::scriptInstance_t inst, const char **pos)
	{
		unsigned char ans;

		ans = *(unsigned char *)*pos;
		*pos += 1;
		return ans;
	}

	// Restored
	float Scr_ReadFloat([[maybe_unused]] game::scriptInstance_t inst, const char **pos)
	{
		float ans;

		ans = *(float *)*pos;
		*pos += 4;
		return ans;
	}
	
	// Restored
	const float* Scr_ReadVector([[maybe_unused]] game::scriptInstance_t inst, const char **pos)
	{
		float* ans;

		ans = (float *)*pos;
		*pos += 12;
		return ans;
	}

	// Restored
	const char* Scr_ReadData([[maybe_unused]] game::scriptInstance_t inst, const char** pos, unsigned int count)
	{
		const char* result;

		result = *pos;
		*pos += count;
		return result;
	}

	// Restored
	namespace VM
	{
		bool OP_End(game::scriptInstance_t inst)
		{
			game::function_stack_t localFs = game::gFs[inst];
			unsigned int parentLocalId = game::GetSafeParentLocalId(inst, localFs.localId);

			game::Scr_KillThread(inst, localFs.localId);
			game::gScrVmPub[inst].localVars -= localFs.localVarCount;

			assert(localFs.top->type != game::VAR_PRECODEPOS);

			while (localFs.top->type != game::VAR_CODEPOS)
			{
				game::RemoveRefToValueInternal(inst, localFs.top->type, localFs.top->u);
				--localFs.top;
				assert(localFs.top->type != game::VAR_PRECODEPOS);
			}
			--game::gScrVmPub[inst].function_count;
			--game::gScrVmPub[inst].function_frame;

			if (!parentLocalId)
			{
				assert(localFs.top == localFs.startTop);

				localFs.startTop[1].type = game::VAR_UNDEFINED;

				if (game::gThreadCount[inst])
				{
					--game::gThreadCount[inst];
					game::RemoveRefToObject(localFs.localId, inst);
					localFs = game::gScrVmPub[inst].function_frame->fs;
					localFs.top->type = (game::VariableType)game::gScrVmPub[inst].function_frame->topType;
					++localFs.top;
					game::gFs[inst] = localFs;
					return true;
				}

				assert(game::g_script_error_level[inst] >= 0);

				--game::g_script_error_level[inst];
				game::gFs[inst] = localFs;
				return false;
			}

			assert(localFs.top->type == game::VAR_CODEPOS);
			localFs.top->type = game::VAR_UNDEFINED;
			assert(localFs.top != localFs.startTop);

			game::RemoveRefToObject(localFs.localId, inst);
			localFs.pos = game::gScrVmPub[inst].function_frame->fs.pos;

			assert(localFs.pos);

			localFs.localVarCount = game::gScrVmPub[inst].function_frame->fs.localVarCount;
			localFs.localId = parentLocalId;

			game::gFs[inst] = localFs;
			return true;
		}

		bool OP_Return(game::scriptInstance_t inst)
		{
			game::VariableValue tempValue;
			game::function_stack_t localFs = game::gFs[inst];
			unsigned int parentLocalId = game::GetSafeParentLocalId(inst, localFs.localId);

			game::Scr_KillThread(inst, localFs.localId);
			game::gScrVmPub[inst].localVars -= localFs.localVarCount;
			tempValue.u.intValue = localFs.top->u.intValue;
			tempValue.type = localFs.top->type;
			--localFs.top;
			assert(localFs.top->type != game::VAR_PRECODEPOS);

			while ( localFs.top->type != game::VAR_CODEPOS )
			{
				game::RemoveRefToValueInternal(inst, localFs.top->type, localFs.top->u);
				--localFs.top;
				assert(localFs.top->type != game::VAR_PRECODEPOS);
			}

			--game::gScrVmPub[inst].function_count;
			--game::gScrVmPub[inst].function_frame;
			if ( parentLocalId )
			{
				assert(localFs.top->type == game::VAR_CODEPOS);
				*localFs.top = tempValue;
				assert(localFs.top != localFs.startTop);
				game::RemoveRefToObject(localFs.localId, inst);

				localFs.pos = game::gScrVmPub[inst].function_frame->fs.pos;
				assert(localFs.pos);
				localFs.localVarCount = game::gScrVmPub[inst].function_frame->fs.localVarCount;
				localFs.localId = parentLocalId;

				game::gFs[inst] = localFs;
				return true;
			}

			assert(localFs.top == localFs.startTop);
			localFs.top[1] = tempValue;

			if ( game::gThreadCount[inst] )
			{
				--game::gThreadCount[inst];
				game::RemoveRefToObject(localFs.localId, inst);
				localFs = game::gScrVmPub[inst].function_frame->fs;
				localFs.top->type = (game::VariableType)game::gScrVmPub[inst].function_frame->topType;
				++localFs.top;

				game::gFs[inst] = localFs;
				return true;
			}

			assert(game::g_script_error_level[inst] >= 0);

			--game::g_script_error_level[inst];
			game::gFs[inst] = localFs;
			return false;
		}
	
		void OP_GetUndefined(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			++game::gFs[inst].top;
			game::gFs[inst].top->type = game::VAR_UNDEFINED;
		}
		
		void OP_GetZero(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			++game::gFs[inst].top;
			game::gFs[inst].top->type = game::VAR_INTEGER;
			game::gFs[inst].top->u.intValue = 0;
		}

		void OP_GetByte(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			++game::gFs[inst].top;
			game::gFs[inst].top->type = game::VAR_INTEGER;
			game::gFs[inst].top->u.intValue = game::Scr_ReadUnsignedByte(inst, &game::gFs[inst].pos);
		}

		void OP_GetNegByte(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			++game::gFs[inst].top;
			game::gFs[inst].top->type = game::VAR_INTEGER;
			game::gFs[inst].top->u.intValue = -game::Scr_ReadUnsignedByte(inst, &game::gFs[inst].pos);
		}

		void OP_GetUnsignedShort(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			++game::gFs[inst].top;
			game::gFs[inst].top->type = game::VAR_INTEGER;
			game::gFs[inst].top->u.intValue = game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos);
		}

		void OP_GetNegUnsignedShort(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			++game::gFs[inst].top;
			game::gFs[inst].top->type = game::VAR_INTEGER;
			game::gFs[inst].top->u.intValue = -game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos);
		}

		void OP_GetInteger(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			++game::gFs[inst].top;
			game::gFs[inst].top->type = game::VAR_INTEGER;
			game::gFs[inst].top->u.intValue = game::Scr_ReadUnsignedInt(inst, &game::gFs[inst].pos);
		}

		void OP_GetFloat(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			++game::gFs[inst].top;
			game::gFs[inst].top->type = game::VAR_FLOAT;
			game::gFs[inst].top->u.floatValue = game::Scr_ReadFloat(inst, &game::gFs[inst].pos);
		}

		void OP_GetString(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			++game::gFs[inst].top;
			game::gFs[inst].top->type = game::VAR_STRING;
			game::gFs[inst].top->u.stringValue = game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos);
			game::SL_CheckExists(inst, game::gFs[inst].top->u.stringValue);
			game::SL_AddRefToString(inst, game::gFs[inst].top->u.stringValue);
		}

		void OP_GetIString(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			++game::gFs[inst].top;
			game::gFs[inst].top->type = game::VAR_ISTRING;
			game::gFs[inst].top->u.stringValue = game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos);
			game::SL_CheckExists(inst, game::gFs[inst].top->u.stringValue);
			game::SL_AddRefToString(inst, game::gFs[inst].top->u.stringValue);
		}

		void OP_GetVector(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			++game::gFs[inst].top;
			game::gFs[inst].top->type = game::VAR_VECTOR;
			game::gFs[inst].top->u.vectorValue = game::Scr_ReadVector(inst, &game::gFs[inst].pos);
		}

		void OP_GetLevelObject(game::scriptInstance_t inst, unsigned int* objectId)
		{
			assert(game::gScrVarPub[inst].levelId);

			*objectId = game::gScrVarPub[inst].levelId;
		}

		void OP_GetAnimObject(game::scriptInstance_t inst, unsigned int* objectId)
		{
			assert(game::gScrVarPub[inst].animId);

			*objectId = game::gScrVarPub[inst].animId;
		}

		void OP_GetSelf(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			++game::gFs[inst].top;
			game::gFs[inst].top->type = game::VAR_POINTER;
			game::gFs[inst].top->u.pointerValue = game::Scr_GetSelf(inst, game::gFs[inst].localId);
			game::AddRefToObject(inst, game::gFs[inst].top->u.pointerValue);
		}

		void OP_GetLevel(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			++game::gFs[inst].top;
			game::gFs[inst].top->type = game::VAR_POINTER;
			game::gFs[inst].top->u.pointerValue = game::gScrVarPub[inst].levelId;
			game::AddRefToObject(inst, game::gScrVarPub[inst].levelId);
		}

		void OP_GetGame(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			++game::gFs[inst].top;
			*game::gFs[inst].top = game::Scr_EvalVariable(inst, game::gScrVarPub[inst].gameId);
		}

		void OP_GetAnim(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			++game::gFs[inst].top;
			game::gFs[inst].top->type = game::VAR_POINTER;
			game::gFs[inst].top->u.pointerValue = game::gScrVarPub[inst].animId;
			game::AddRefToObject(inst, game::gScrVarPub[inst].animId);
		}

		void OP_GetAnimation(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			++game::gFs[inst].top;
			game::gFs[inst].top->type = game::VAR_ANIMATION;
			game::gFs[inst].top->u.codePosValue = game::Scr_ReadCodePos(inst, &game::gFs[inst].pos);
		}

		void OP_GetGameRef(game::scriptInstance_t inst, unsigned int* fieldValueIndex, unsigned int* fieldValueId)
		{
			*fieldValueIndex = 0;
			*fieldValueId = game::gScrVarPub[inst].gameId;
		}

		void OP_GetFunction(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			++game::gFs[inst].top;
			game::gFs[inst].top->type = game::VAR_FUNCTION;
			game::gFs[inst].top->u.codePosValue = game::Scr_ReadCodePos(inst, &game::gFs[inst].pos);
		}

		void OP_CreateLocalVariable(game::scriptInstance_t inst)
		{
			++game::gFs[inst].localVarCount;
			++game::gScrVmPub[inst].localVars;

			unsigned short pos = game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos);
			*game::gScrVmPub[inst].localVars = game::GetNewVariable(inst, pos, game::gFs[inst].localId);
		}

		void OP_RemoveLocalVariables(game::scriptInstance_t inst)
		{
			unsigned char removeCount = game::Scr_ReadUnsignedByte(inst, &game::gFs[inst].pos);
			game::gFs[inst].localVarCount -= removeCount;
			game::gScrVmPub[inst].localVars -= removeCount;

			while ( removeCount )
			{
				game::RemoveNextVariable(inst, game::gFs[inst].localId);
				--removeCount;
			}
		}

		void OP_EvalLocalVariableCached(game::scriptInstance_t inst, int num)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			if (num < 0)
			{
				num = game::Scr_ReadUnsignedByte(inst, &game::gFs[inst].pos);
			}

			++game::gFs[inst].top;
			*game::gFs[inst].top = game::Scr_EvalVariable(inst, game::gScrVmPub[inst].localVars[-num]);
		}

		void OP_EvalArray(game::scriptInstance_t inst)
		{
			game::Scr_EvalArray(inst, game::gFs[inst].top - 1, game::gFs[inst].top);
			--game::gFs[inst].top;
		}

		void OP_EvalLocalArrayCached(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			++game::gFs[inst].top;
			*game::gFs[inst].top = game::Scr_EvalVariable(inst, game::gScrVmPub[inst].localVars[-game::Scr_ReadUnsignedByte(inst, &game::gFs[inst].pos)]);

			OP_EvalArray(inst);
		}

		void OP_EvalArrayRef(game::scriptInstance_t inst, unsigned int* fieldValueId, unsigned int* fieldValueIndex, unsigned int* objectId)
		{
			game::function_stack_t localFs = game::gFs[inst];

			*objectId = game::Scr_EvalArrayRef(inst, *fieldValueId);
			if ( localFs.top->type == game::VAR_INTEGER )
			{
				if ( !game::IsValidArrayIndex(inst, localFs.top->u.stringValue) )
				{
					game::gFs[inst] = localFs;
					game::Scr_Error(game::va("array index %d out of range", localFs.top->u.intValue), inst, false);
				}

				*fieldValueIndex = game::GetArrayVariableIndex(localFs.top->u.stringValue, inst, *objectId);
			}
			else if ( localFs.top->type == game::VAR_STRING )
			{
				*fieldValueIndex = game::GetVariableIndexInternal(inst, *objectId, localFs.top->u.stringValue);
				game::SL_RemoveRefToString(localFs.top->u.stringValue, inst);
			}
			else
			{
				game::gFs[inst] = localFs;
				game::Scr_Error(game::va("%s is not an array index", game::var_typename[localFs.top->type]), inst, false);
			}

			game::gFs[inst] = localFs;
			--game::gFs[inst].top;

			*fieldValueId = game::gScrVarGlob[inst].childVariables[*fieldValueIndex].hash.id;
			assert(fieldValueId);
		}

		void OP_EvalLocalArrayRefCached(game::scriptInstance_t inst, int num, unsigned int* fieldValueId, unsigned int* fieldValueIndex, unsigned int* objectId)
		{
			if (num < 0)
			{
				num = game::Scr_ReadUnsignedByte(inst, &game::gFs[inst].pos);
			}

			*fieldValueId = game::gScrVmPub[inst].localVars[-num];

			OP_EvalArrayRef(inst, fieldValueId, fieldValueIndex, objectId);
		}

		void OP_ClearArray(game::scriptInstance_t inst, unsigned int *fieldValueId)
		{
			game::ClearArray(*fieldValueId, inst, game::gFs[inst].top);
			--game::gFs[inst].top;
		}

		void OP_EmptyArray(game::scriptInstance_t inst)
		{
			++game::gFs[inst].top;
			game::gFs[inst].top->type = game::VAR_POINTER;
			game::gFs[inst].top->u.pointerValue = game::Scr_AllocArray(inst);
		}

		void OP_GetSelfObject(game::scriptInstance_t inst, unsigned int *objectId)
		{
			game::function_stack_t localFs = game::gFs[inst];
			game::VariableType type;

			*objectId = game::Scr_GetSelf(inst, localFs.localId);

			if (!game::IsFieldObject(inst, *objectId))
			{
				type = game::GetObjectType(inst, *objectId);
				game::gFs[inst] = localFs;
				game::Scr_Error(game::va("%s is not an object", game::var_typename[type]), inst, false);
			}

			game::gFs[inst] = localFs;
		}

		void OP_EvalLevelAnimFieldVariable(game::scriptInstance_t inst, bool isLevel, unsigned int *objectId)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			game::function_stack_t localFs = game::gFs[inst];

			if (isLevel)
			{
				*objectId = game::gScrVarPub[inst].levelId;
			}
			else
			{
				*objectId = game::gScrVarPub[inst].animId;
			}

			++localFs.top;
			*localFs.top = game::Scr_EvalVariable(inst, game::FindVariable(game::Scr_ReadUnsignedShort(inst, &localFs.pos), *objectId, inst));

			game::gFs[inst] = localFs;
		}

		void OP_EvalFieldVariable(game::scriptInstance_t inst, unsigned int* objectId)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			game::gFs[inst].top[1] = game::Scr_FindVariableField(inst, *objectId, game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos));
			++game::gFs[inst].top;
		}

		void OP_EvalSelfFieldVariable(game::scriptInstance_t inst, unsigned int *objectId)
		{
			game::function_stack_t localFs = game::gFs[inst];
			game::VariableType type;

			*objectId = game::Scr_GetSelf(inst, localFs.localId);
			if (!game::IsFieldObject(inst, *objectId))
			{
				assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
				assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

				++localFs.top;
				game::Scr_ReadUnsignedShort(inst, &localFs.pos);

				type = game::GetObjectType(inst, *objectId);
				game::gFs[inst] = localFs;
				game::Scr_Error(game::va("%s is not an object", game::var_typename[type]), inst, false);
			}

			game::gFs[inst] = localFs;
			OP_EvalFieldVariable(inst, objectId);
		}

		void OP_EvalFieldVariableRef(game::scriptInstance_t inst, unsigned int *objectId, unsigned int *fieldValueIndex, unsigned int *fieldValueId)
		{
			*fieldValueIndex = game::Scr_GetVariableFieldIndex(inst, game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos), *objectId);
			*fieldValueId = game::gScrVarGlob[inst].childVariables[*fieldValueIndex].hash.id;
		}
		
		void OP_EvalLevelFieldVariableRef(game::scriptInstance_t inst, unsigned int *objectId, unsigned int *fieldValueIndex, unsigned int *fieldValueId)
		{
			*objectId = game::gScrVarPub[inst].levelId;
			OP_EvalFieldVariableRef(inst, objectId, fieldValueIndex, fieldValueId);
		}
		
		void OP_EvalAnimFieldVariableRef(game::scriptInstance_t inst, unsigned int *objectId, unsigned int *fieldValueIndex, unsigned int *fieldValueId)
		{
			*objectId = game::gScrVarPub[inst].animId;
			OP_EvalFieldVariableRef(inst, objectId, fieldValueIndex, fieldValueId);
		}
		
		void OP_EvalSelfFieldVariableRef(game::scriptInstance_t inst, unsigned int *objectId, unsigned int *fieldValueIndex, unsigned int *fieldValueId)
		{
			assert(*objectId);

			*objectId = game::Scr_GetSelf(inst, game::gFs[inst].localId);
			OP_EvalFieldVariableRef(inst, objectId, fieldValueIndex, fieldValueId);
		}

		void OP_ClearFieldVariable(game::scriptInstance_t inst, unsigned int *objectId)
		{
			assert(*objectId);

			game::ClearVariableField(inst, *objectId, game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos), game::gFs[inst].top);
		}

		void OP_SafeSetVariableFieldCached(game::scriptInstance_t inst, int num)
		{
			assert(game::gFs[inst].top->type != game::VAR_CODEPOS);

			if (num < 0)
			{
				num = game::Scr_ReadUnsignedByte(inst, &game::gFs[inst].pos);
			}

			if (game::gFs[inst].top->type != game::VAR_PRECODEPOS)
			{
				game::SetVariableValue(inst, game::gFs[inst].top, game::gScrVmPub[inst].localVars[-num]);
				--game::gFs[inst].top;
			}
		}

		void OP_SafeCreateVariableFieldCached(game::scriptInstance_t inst)
		{
			++game::gScrVmPub[inst].localVars;
			++game::gFs[inst].localVarCount;

			*game::gScrVmPub[inst].localVars = game::GetNewVariable(inst, game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos), game::gFs[inst].localId);

			OP_SafeSetVariableFieldCached(inst, 0);
		}

		void OP_SafeSetWaittillVariableFieldCached(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top->type != game::VAR_PRECODEPOS);

			unsigned char num = game::Scr_ReadUnsignedByte(inst, &game::gFs[inst].pos);

			if (game::gFs[inst].top->type != game::VAR_CODEPOS)
			{
				game::SetVariableValue(inst, game::gFs[inst].top, game::gScrVmPub[inst].localVars[-num]);
				--game::gFs[inst].top;
			}
			else
			{
				game::ClearVariableValue(inst, game::gScrVmPub[inst].localVars[-num]);
			}
		}

		void OP_clearparams(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top->type != game::VAR_PRECODEPOS);

			while ( game::gFs[inst].top->type != game::VAR_CODEPOS )
			{
				game::RemoveRefToValueInternal(inst, game::gFs[inst].top->type, game::gFs[inst].top->u);
				--game::gFs[inst].top;

				assert(game::gFs[inst].top->type != game::VAR_PRECODEPOS);
			}
		}

		void OP_checkclearparams(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top->type != game::VAR_CODEPOS);
			if ( game::gFs[inst].top->type == game::VAR_PRECODEPOS )
			{
				/*if (gScrVarPub[inst].numScriptValues > 0x3F37E || gScrVarPub[inst].numScriptObjects > 0x737E)
				{
				gFs[inst] = localFs;
				if ( gScrVmPub[inst].showError )
				{
				Scr_DumpScriptThreads(inst);
				Scr_DumpScriptVariablesDefault(inst);
				Scr_Error(inst, "exceeded maximum number of script variables", 0);
				}
				Sys_Error("exceeded maximum number of script variables");
				}*/
				game::gFs[inst].top->type = game::VAR_CODEPOS;
			}
			else
			{
				game::Scr_Error("function called with too many parameters", inst, false);
			}
		}

		void OP_EvalLocalVariableRefCached(game::scriptInstance_t inst, int num, unsigned int* fieldValueIndex, unsigned int* fieldValueId)
		{
			if (num < 0)
			{
				num = game::Scr_ReadUnsignedByte(inst, &game::gFs[inst].pos);
			}

			*fieldValueIndex = 0;
			*fieldValueId = game::gScrVmPub[inst].localVars[-num];
		}

		void OP_SetLevelFieldVariableField(game::scriptInstance_t inst)
		{
			game::SetVariableValue(inst, game::gFs[inst].top, game::GetVariable(inst, game::gScrVarPub[inst].levelId, game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos)));
			--game::gFs[inst].top;
		}

		void OP_SetAnimFieldVariableField(game::scriptInstance_t inst)
		{
			game::SetVariableValue(inst, game::gFs[inst].top, game::GetVariable(inst, game::gScrVarPub[inst].animId, game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos)));

			game::gFs[inst].top--;
		}

		void OP_SetVariableField(game::scriptInstance_t inst, unsigned int* objectId, unsigned int* fieldValueIndex, unsigned int* fieldValueId)
		{
			if ( *fieldValueIndex )
			{
				assert(*fieldValueId);

				if ( game::gFs[inst].top->type)
				{
					game::SetVariableValue(inst, game::gFs[inst].top, *fieldValueId);
				}
				else
				{
					game::RemoveVariableValue(inst, *objectId, *fieldValueIndex);
				}
			}
			else
			{
				game::SetVariableFieldValue(inst, *fieldValueId, game::gFs[inst].top);
			}

			game::gFs[inst].top--;
		}

		void OP_SetSelfFieldVariableField(game::scriptInstance_t inst, unsigned int* objectId, unsigned int* fieldValueIndex, unsigned int* fieldValueId)
		{
			unsigned short fieldName = game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos);
			*objectId = game::Scr_GetSelf(inst, game::gFs[inst].localId);
			*fieldValueIndex = game::Scr_GetVariableFieldIndex(inst, fieldName, *objectId);
			*fieldValueId = game::gScrVarGlob[inst].childVariables[*fieldValueIndex].hash.id;

			OP_SetVariableField(inst, objectId, fieldValueIndex, fieldValueId);
		}

		void OP_SetLocalVariableFieldCached(game::scriptInstance_t inst, int num)
		{
			if (num < 0)
			{
				num = game::Scr_ReadUnsignedByte(inst, &game::gFs[inst].pos);
			}

			game::SetVariableValue(inst, game::gFs[inst].top, game::gScrVmPub[inst].localVars[-num]);
			game::gFs[inst].top--;
		}

		void post_builtin(game::scriptInstance_t inst)
		{
			unsigned int paramcount;

			game::gFs[inst].top = game::gScrVmPub[inst].top;
			game::gFs[inst].pos = game::gScrVmPub[inst].function_frame->fs.pos;

			if ( game::gScrVmPub[inst].outparamcount )
			{
				paramcount = game::gScrVmPub[inst].outparamcount;
				game::gScrVmPub[inst].outparamcount = 0;
				game::gScrVmPub[inst].top -= paramcount;

				do
				{
					game::RemoveRefToValueInternal(inst, game::gFs[inst].top->type, game::gFs[inst].top->u);
					--game::gFs[inst].top;
					--paramcount;
				}
				while ( paramcount );
			}

			if ( game::gScrVmPub[inst].inparamcount )
			{
				assert(game::gScrVmPub[inst].inparamcount == 1);

				game::gScrVmPub[inst].inparamcount = 0;
				assert(game::gFs[inst].top == game::gScrVmPub[inst].top);
			}
			else
			{
				assert(game::gFs[inst].top == game::gScrVmPub[inst].top);

				game::gFs[inst].top[1].type = game::VAR_UNDEFINED;
				++game::gFs[inst].top;
			}
		}

		void OP_CallBuiltin(game::scriptInstance_t inst, int num)
		{
			if (num < 0)
			{
				num = game::Scr_ReadUnsignedByte(inst, &game::gFs[inst].pos);
			}

			assert(!game::gScrVmPub[inst].outparamcount);

			assert(!game::gScrVmPub[inst].inparamcount);

			game::gScrVmPub[inst].outparamcount = num;

			//const char* debugpos = game::gFs[inst].pos;
			unsigned short builtinIndex = game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos);
			game::gScrVmPub[inst].function_frame->fs.pos = game::gFs[inst].pos;

			/*
			if ( gScrVmDebugPub[inst].func_table[builtinIndex].breakpointCount )
			{
			outparamcount = gScrVmPub[inst].outparamcount;
			Scr_HitBuiltinBreakpoint(inst, localFs.top, debugpos, localFs.localId, gOpcode[inst], builtinIndex, outparamcount);
			gScrVmPub[inst].outparamcount = outparamcount;
			}*/

			assert(builtinIndex >= 0);
			assert(builtinIndex < 1024);

			game::gScrVmPub[inst].top = game::gFs[inst].top;
			((void (*)(void))game::gScrCompilePub[inst].func_table[builtinIndex])();

			post_builtin(inst);
		}

		void OP_CallBuiltinMethod(game::scriptInstance_t inst, int num, unsigned int *objectId)
		{
			game::VariableType type;
			game::scr_entref_t entref;

			if (num < 0)
			{
				num = game::Scr_ReadUnsignedByte(inst, &game::gFs[inst].pos);
			}

			assert(!game::gScrVmPub[inst].outparamcount);

			assert(!game::gScrVmPub[inst].inparamcount);

			game::gScrVmPub[inst].outparamcount = num;

			//const char* debugpos = game::gFs[inst].pos;
			game::gScrVmPub[inst].top = game::gFs[inst].top - 1;
			unsigned short builtinIndex = game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos);

			if (game::gFs[inst].top->type != game::VAR_POINTER)
			{
				type = game::gFs[inst].top->type;
				game::RemoveRefToValueInternal(inst, game::gFs[inst].top->type, game::gFs[inst].top->u);
				game::gScrVarPub[inst].error_index = -1;
				game::Scr_Error(game::va("%s is not an entity", game::var_typename[type]), inst, false);
			}

			*objectId = game::gFs[inst].top->u.pointerValue;

			if (game::GetObjectType(inst, *objectId) != game::VAR_ENTITY)
			{
				type = game::GetObjectType(inst, *objectId);
				game::RemoveRefToObject(*objectId, inst);
				game::gScrVarPub[inst].error_index = -1;
				game::Scr_Error(game::va("%s is not an entity", game::var_typename[type]), inst, false);
			}

			entref = *game::Scr_GetEntityIdRef(&entref, inst, *objectId);

			game::RemoveRefToObject(*objectId, inst);
			game::gScrVmPub[inst].function_frame->fs.pos = game::gFs[inst].pos;
			/*
			if ( gScrVmGlob[inst].recordPlace )
		  Scr_GetFileAndLine(inst, localFs.pos, &gScrVmGlob[inst].lastFileName, &gScrVmGlob[inst].lastLine);
		if ( gScrVmDebugPub[inst].func_table[builtinIndex].breakpointCount )
		{
		  if ( gScrVmPub[inst].top != localFs.top - 1 && !Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\clientscript\\cscr_vm.cpp", 1611, 0, "%s", "gScrVmPub[inst].top == localFs.top - 1") )
			__debugbreak();
		  v104 = gScrVmPub[inst].outparamcount;
		  Scr_HitBuiltinBreakpoint(inst, localFs.top, debugpos, localFs.localId, gOpcode[inst], builtinIndex, v104 + 1);
		  gScrVmPub[inst].outparamcount = v104;
		  gScrVmPub[inst].top = localFs.top - 1;
		}*/

			assert(builtinIndex >= 0);
			assert(builtinIndex < 1024);

			((void (__cdecl *)(game::scr_entref_t))game::gScrCompilePub[inst].func_table[builtinIndex])(entref);

			post_builtin(inst);
		}

		bool OP_wait(game::scriptInstance_t inst)
		{
			game::function_stack_t localFs = game::gFs[inst];
			int waitTime;
			game::VariableValue stackValue;
			unsigned int id;
			unsigned int stackId;

			assert(game::Scr_IsInOpcodeMemory(inst, localFs.pos));

			if ( localFs.top->type == game::VAR_FLOAT )
			{
				if (localFs.top->u.floatValue < 0.0f)
				{
					game::gFs[inst] = localFs;
					game::Scr_Error("negative wait is not allowed", inst, false);
				}

				waitTime = (int)(((inst != game::SCRIPTINSTANCE_SERVER ? 60 : 20) * localFs.top->u.floatValue) + 9.313225746154785e-10);
				if ( !waitTime )
				{
					waitTime = localFs.top->u.floatValue != 0.0;
				}
			}
			else if ( localFs.top->type == game::VAR_INTEGER )
			{
				waitTime = localFs.top->u.intValue * (inst != game::SCRIPTINSTANCE_SERVER ? 60 : 20);
			}
			else
			{
				game::gScrVarPub[inst].error_index = 2;
				game::gFs[inst] = localFs;
				waitTime = 0;
				game::Scr_Error(game::va("type %s is not a float", game::var_typename[localFs.top->type]), inst, false);
			}

			if ((unsigned int)waitTime >= 0xFFFFFF)
			{
				game::gScrVarPub[inst].error_index = 2;
				if (waitTime >= 0)
				{
					game::gFs[inst] = localFs;
					game::Scr_Error("wait is too long", inst, false);
				}

				game::gFs[inst] = localFs;
				game::Scr_Error("negative wait is not allowed", inst, false);
			}

			if ( waitTime )
			{
				game::Scr_ResetTimeout(inst);
			}

			waitTime = (waitTime + game::gScrVarPub[inst].time) & 0xFFFFFF;
			--localFs.top;
			stackValue.type = game::VAR_STACK;

			game::gFs[inst] = localFs;
			stackValue.u.stackValue = game::VM_ArchiveStack(inst);
			localFs = game::gFs[inst];

			id = game::GetArray(inst, game::GetVariable(inst, game::gScrVarPub[inst].timeArrayId, waitTime));

			stackId = game::GetNewObjectVariable(inst, localFs.localId, id);
			game::SetNewVariableValue(inst, stackId, &stackValue);
			game::Scr_SetThreadWaitTime(inst, localFs.localId, waitTime);

			localFs.startTop[1].type = game::VAR_UNDEFINED;
			if ( game::gThreadCount[inst] )
			{
				--game::gThreadCount[inst];
				game::RemoveRefToObject(localFs.localId, inst);
				localFs = game::gScrVmPub[inst].function_frame->fs;
				localFs.top->type = (game::VariableType)game::gScrVmPub[inst].function_frame->topType;
				++localFs.top;

				game::gFs[inst] = localFs;
				return true;
			}

			assert(game::g_script_error_level[inst] >= 0);
			--game::g_script_error_level[inst];
			game::gFs[inst] = localFs;
			return false;
		}

		bool OP_waittillFrameEnd(game::scriptInstance_t inst)
		{
			game::function_stack_t localFs = game::gFs[inst];
			game::VariableValue stackValue;
			unsigned int id;
			unsigned int stackId;

			assert(game::Scr_IsInOpcodeMemory(inst, localFs.pos));
			assert((game::gScrVarPub[inst].time & VAR_NAME_LOW_MASK) == 0);

			stackValue.type = game::VAR_STACK;

			game::gFs[inst] = localFs;
			stackValue.u.stackValue = game::VM_ArchiveStack(inst);
			localFs = game::gFs[inst];

			id = game::GetArray(inst, game::GetVariable(inst, game::gScrVarPub[inst].timeArrayId, game::gScrVarPub[inst].time));

			stackId = game::GetNewObjectVariableReverse(inst, id, localFs.localId);

			game::SetNewVariableValue(inst, stackId, &stackValue);
			game::Scr_SetThreadWaitTime(inst, localFs.localId, game::gScrVarPub[inst].time);

			localFs.startTop[1].type = game::VAR_UNDEFINED;
			if ( game::gThreadCount[inst] )
			{
				--game::gThreadCount[inst];
				game::RemoveRefToObject(localFs.localId, inst);
				localFs = game::gScrVmPub[inst].function_frame->fs;
				localFs.top->type = (game::VariableType)game::gScrVmPub[inst].function_frame->topType;
				++localFs.top;

				game::gFs[inst] = localFs;
				return true;
			}

			assert(game::g_script_error_level[inst] >= 0);
			--game::g_script_error_level[inst];

			game::gFs[inst] = localFs;
			return false;
		}

		void OP_PreScriptCall(game::scriptInstance_t inst, bool)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			game::gFs[inst].top[1].type = game::VAR_PRECODEPOS;
			++game::gFs[inst].top;
		}

		void function_call(game::scriptInstance_t inst)
		{
			game::gScrVmPub[inst].function_frame->fs.localVarCount = game::gFs[inst].localVarCount;
			game::gFs[inst].localVarCount = 0;
			++game::gScrVmPub[inst].function_count;
			++game::gScrVmPub[inst].function_frame;
			game::gScrVmPub[inst].function_frame->fs.localId = game::gFs[inst].localId;

			// pluto
			if (game::plutonium::vm_execute_update_codepos != nullptr)
			{
				game::plutonium::vm_execute_update_codepos(inst);
			}
			//

			assert(game::gFs[inst].pos);

		}

		void OP_ScriptFunctionCall(game::scriptInstance_t inst)
		{
			unsigned int selfId;

			if ( game::gScrVmPub[inst].function_count >= 31 )
			{
				game::Scr_Error("script stack overflow (too many embedded function calls)", inst, false);
			}

			selfId = game::Scr_GetSelf(inst, game::gFs[inst].localId);
			game::AddRefToObject(inst, selfId);

			game::gFs[inst].localId = game::AllocChildThread(inst, game::gFs[inst].localId, selfId);
			game::gScrVmPub[inst].function_frame->fs.pos = game::gFs[inst].pos;
			game::gFs[inst].pos = game::Scr_ReadCodePos(inst, &game::gScrVmPub[inst].function_frame->fs.pos);

			function_call(inst);
		}

		void OP_ScriptFunctionCall2(game::scriptInstance_t inst)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			game::gFs[inst].top[1].type = game::VAR_PRECODEPOS;
			++game::gFs[inst].top;

			OP_ScriptFunctionCall(inst);
		}

		void OP_ScriptFunctionCallPointer(game::scriptInstance_t inst)
		{
			unsigned int selfId;

			if (game::gFs[inst].top->type != game::VAR_FUNCTION)
			{
				game::Scr_Error(game::va("%s is not a function pointer", game::var_typename[game::gFs[inst].top->type]), inst, false);
			}

			if (game::gScrVmPub[inst].function_count >= 31)
			{
				game::gScrVarPub[inst].error_index = 1;
				game::Scr_Error("script stack overflow (too many embedded function calls)", inst, false);
			}

			selfId = game::Scr_GetSelf(inst, game::gFs[inst].localId);

			game::AddRefToObject(inst, selfId);
			game::gFs[inst].localId = game::AllocChildThread(inst, game::gFs[inst].localId, selfId);
			game::gScrVmPub[inst].function_frame->fs.pos = game::gFs[inst].pos;
			game::gFs[inst].pos = game::gFs[inst].top->u.codePosValue;
			--game::gFs[inst].top;
			
			function_call(inst);
		}

		void OP_ScriptMethodCall(game::scriptInstance_t inst)
		{
			game::VariableType type;

			if (game::gFs[inst].top->type != game::VAR_POINTER)
			{
				type = game::gFs[inst].top->type;
				game::gScrVarPub[inst].error_index = 1;
				game::Scr_Error(game::va("%s is not an object", game::var_typename[type]), inst, false);
			}

			if (game::gScrVmPub[inst].function_count >= 31)
			{
				game::Scr_Error("script stack overflow (too many embedded function calls)", inst, false);
			}

			game::gFs[inst].localId = game::AllocChildThread(inst, game::gFs[inst].localId, game::gFs[inst].top->u.pointerValue);
			--game::gFs[inst].top;
			game::gScrVmPub[inst].function_frame->fs.pos = game::gFs[inst].pos;
			game::gFs[inst].pos = game::Scr_ReadCodePos(inst, &game::gScrVmPub[inst].function_frame->fs.pos);

			function_call(inst);
		}

		void OP_ScriptMethodCallPointer(game::scriptInstance_t inst)
		{
			const char* tempCodePos;
			game::VariableType type;

			if (game::gFs[inst].top->type != game::VAR_FUNCTION)
			{
				game::RemoveRefToValue(inst, game::gFs[inst].top--);
				game::Scr_Error(game::va("%s is not a function pointer", game::var_typename[game::gFs[inst].top[1].type]), inst, false);
			}

			tempCodePos = game::gFs[inst].top->u.codePosValue;
			--game::gFs[inst].top;

			if (game::gFs[inst].top->type != game::VAR_POINTER)
			{
				type = game::gFs[inst].top->type;
				game::gScrVarPub[inst].error_index = 2;
				game::Scr_Error(game::va("%s is not an object", game::var_typename[type]), inst, false);
			}

			if (game::gScrVmPub[inst].function_count >= 31)
			{
				game::gScrVarPub[inst].error_index = 1;
				game::Scr_Error("script stack overflow (too many embedded function calls)", inst, false);
			}

			game::gFs[inst].localId = game::AllocChildThread(inst, game::gFs[inst].localId, game::gFs[inst].top->u.pointerValue);
			--game::gFs[inst].top;
			game::gScrVmPub[inst].function_frame->fs.pos = game::gFs[inst].pos;
			game::gFs[inst].pos = tempCodePos;

			function_call(inst);
		}

		void thread_call(game::scriptInstance_t inst)
		{
			game::gScrVmPub[inst].function_frame->fs.top = game::gFs[inst].startTop;
			game::gScrVmPub[inst].function_frame->topType = game::gFs[inst].startTop->type;
			game::gFs[inst].startTop->type = game::VAR_PRECODEPOS;

			++game::gThreadCount[inst];

			function_call(inst);
		}

		void OP_ScriptThreadCall(game::scriptInstance_t inst)
		{
			unsigned int selfId;
			int num;

			if ( game::gScrVmPub[inst].function_count >= 31 )
			{
				game::gScrVarPub[inst].error_index = 1;
				game::Scr_Error("script stack overflow (too many embedded function calls)", inst, false);
			}

			selfId = game::Scr_GetSelf(inst, game::gFs[inst].localId);
			game::AddRefToObject(inst, selfId);
			game::gFs[inst].localId = game::AllocThread(inst, selfId);
			game::gScrVmPub[inst].function_frame->fs.pos = game::gFs[inst].pos;
			game::gScrVmPub[inst].function_frame->fs.startTop = game::gFs[inst].startTop;
			game::gFs[inst].pos = game::Scr_ReadCodePos(inst, &game::gScrVmPub[inst].function_frame->fs.pos);

			num = game::Scr_ReadUnsignedInt(inst, &game::gScrVmPub[inst].function_frame->fs.pos);
			game::gFs[inst].startTop = &game::gFs[inst].top[-num];

			thread_call(inst);
		}

		void OP_ScriptThreadCallPointer(game::scriptInstance_t inst)
		{
			unsigned int selfId;
			const char* tempCodePos;
			int num;

			if (game::gFs[inst].top->type != game::VAR_FUNCTION)
			{
				game::Scr_Error(game::va("%s is not a function pointer", game::var_typename[game::gFs[inst].top->type]), inst, false);
			}

			if (game::gScrVmPub[inst].function_count >= 31)
			{
				game::gScrVarPub[inst].error_index = 1;
				game::Scr_Error("script stack overflow (too many embedded function calls)", inst, false);
			}

			tempCodePos = game::gFs[inst].top->u.codePosValue;
			--game::gFs[inst].top;
			selfId = game::Scr_GetSelf(inst, game::gFs[inst].localId);

			game::AddRefToObject(inst, selfId);
			game::gFs[inst].localId = game::AllocThread(inst, selfId);
			game::gScrVmPub[inst].function_frame->fs.pos = game::gFs[inst].pos;
			game::gScrVmPub[inst].function_frame->fs.startTop = game::gFs[inst].startTop;
			game::gFs[inst].pos = tempCodePos;

			num = game::Scr_ReadUnsignedInt(inst, &game::gScrVmPub[inst].function_frame->fs.pos);
			game::gFs[inst].startTop = &game::gFs[inst].top[-num];

			thread_call(inst);
		}

		void OP_ScriptMethodThreadCall(game::scriptInstance_t inst)
		{
			game::VariableType type;
			int num;

			if (game::gFs[inst].top->type != game::VAR_POINTER)
			{
				type = game::gFs[inst].top->type;
				game::gScrVarPub[inst].error_index = 2;
				game::Scr_Error(game::va("%s is not an object", game::var_typename[type]), inst, false);
			}

			if (game::gScrVmPub[inst].function_count >= 31)
			{
				game::gScrVarPub[inst].error_index = 1;
				game::Scr_Error("script stack overflow (too many embedded function calls)", inst, false);
			}

			game::gFs[inst].localId = game::AllocThread(inst, game::gFs[inst].top->u.pointerValue);
			--game::gFs[inst].top;
			game::gScrVmPub[inst].function_frame->fs.pos = game::gFs[inst].pos;
			game::gScrVmPub[inst].function_frame->fs.startTop = game::gFs[inst].startTop;
			game::gFs[inst].pos = game::Scr_ReadCodePos(inst, &game::gScrVmPub[inst].function_frame->fs.pos);

			num = game::Scr_ReadUnsignedInt(inst, &game::gScrVmPub[inst].function_frame->fs.pos);
			game::gFs[inst].startTop = &game::gFs[inst].top[-num];
			
			thread_call(inst);
		}

		void OP_ScriptMethodThreadCallPointer(game::scriptInstance_t inst)
		{
			const char* tempCodePos;
			game::VariableType type;
			int num;

			if (game::gFs[inst].top->type != game::VAR_FUNCTION)
			{
				game::RemoveRefToValue(inst, game::gFs[inst].top--);
				game::Scr_Error(game::va("%s is not a function pointer", game::var_typename[game::gFs[inst].top[1].type]), inst, false);
			}

			tempCodePos = game::gFs[inst].top->u.codePosValue;
			--game::gFs[inst].top;

			if (game::gFs[inst].top->type != game::VAR_POINTER)
			{
				type = game::gFs[inst].top->type;
				game::gScrVarPub[inst].error_index = 2;
				game::Scr_Error(game::va("%s is not an object", game::var_typename[type]), inst, false);
			}

			if (game::gScrVmPub[inst].function_count >= 31)
			{
				game::gScrVarPub[inst].error_index = 1;
				game::Scr_Error("script stack overflow (too many embedded function calls)", inst, false);
			}

			game::gFs[inst].localId = game::AllocThread(inst, game::gFs[inst].top->u.pointerValue);
			--game::gFs[inst].top;
			game::gScrVmPub[inst].function_frame->fs.pos = game::gFs[inst].pos;
			game::gScrVmPub[inst].function_frame->fs.startTop = game::gFs[inst].startTop;
			game::gFs[inst].pos = tempCodePos;

			num = game::Scr_ReadUnsignedInt(inst, &game::gScrVmPub[inst].function_frame->fs.pos);
			game::gFs[inst].startTop = &game::gFs[inst].top[-num];

			thread_call(inst);
		}

		void OP_DecTop(game::scriptInstance_t inst)
		{
			game::RemoveRefToValue(inst, game::gFs[inst].top);
			game::gFs[inst].top--;
		}

		void OP_CastFieldObject(game::scriptInstance_t inst, unsigned int* objectId)
		{
			*objectId = game::Scr_EvalFieldObject(game::gFs[inst].top, inst, game::gScrVarPub[inst].tempVariable).pointerValue;
			game::gFs[inst].top--;
		}

		void OP_EvalLocalVariableObjectCached(game::scriptInstance_t inst, unsigned int* objectId)
		{
			*objectId = game::Scr_EvalVariableObject(inst, game::Scr_GetLocalVar(inst, *game::gFs[inst].pos));
			// error recovery handler will inc the pos
			game::Scr_ReadUnsignedByte(inst, &game::gFs[inst].pos);
		}

		void OP_CastBool(game::scriptInstance_t inst)
		{
			game::Scr_CastBool(inst, game::gFs[inst].top);
		}

		void OP_BoolNot(game::scriptInstance_t inst)
		{
			game::Scr_EvalBoolNot(inst, game::gFs[inst].top);
		}

		void OP_BoolComplement(game::scriptInstance_t inst)
		{
			game::Scr_EvalBoolComplement(inst, game::gFs[inst].top);
		}

		void OP_JumpOnFalse(game::scriptInstance_t inst)
		{
			unsigned short jumpOffset;

			game::Scr_CastBool(inst, game::gFs[inst].top);

			assert(game::gFs[inst].top->type == game::VAR_INTEGER);

			jumpOffset = game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos);

			if ( !game::gFs[inst].top->u.intValue )
			{
				game::gFs[inst].pos += jumpOffset;
			}

			game::gFs[inst].top--;
		}

		void OP_JumpOnTrue(game::scriptInstance_t inst)
		{
			unsigned short jumpOffset;

			game::Scr_CastBool(inst, game::gFs[inst].top);

			assert(game::gFs[inst].top->type == game::VAR_INTEGER);

			jumpOffset = game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos);

			if ( game::gFs[inst].top->u.intValue )
			{
				game::gFs[inst].pos += jumpOffset;
			}

			game::gFs[inst].top--;
		}

		void OP_JumpOnFalseExpr(game::scriptInstance_t inst)
		{
			unsigned short jumpOffset;

			game::Scr_CastBool(inst, game::gFs[inst].top);
			assert(game::gFs[inst].top->type == game::VAR_INTEGER);

			jumpOffset = game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos);

			if ( !game::gFs[inst].top->u.intValue )
			{
				game::gFs[inst].pos += jumpOffset;
				return;
			}

			--game::gFs[inst].top;
		}

		void OP_JumpOnTrueExpr(game::scriptInstance_t inst)
		{
			unsigned short jumpOffset;

			game::Scr_CastBool(inst, game::gFs[inst].top);
			assert(game::gFs[inst].top->type == game::VAR_INTEGER);

			jumpOffset = game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos);

			if ( game::gFs[inst].top->u.intValue )
			{
				game::gFs[inst].pos += jumpOffset;
				return;
			}

			--game::gFs[inst].top;
		}

		void OP_jump(game::scriptInstance_t inst)
		{
			int jumpOffset;
			jumpOffset = game::Scr_ReadUnsignedInt(inst, &game::gFs[inst].pos);
			game::gFs[inst].pos += jumpOffset;
		}

		bool OP_jumpback(game::scriptInstance_t inst)
		{
			unsigned int parentLocalId;
			unsigned short jumpOffset;

			/*if (gScrVarPub[inst].numScriptValues > 0x3F37E || gScrVarPub[inst].numScriptObjects > 0x737E)
			{
				if ( gScrVmPub[inst].showError )
				{
					Scr_DumpScriptThreads(inst);
					Scr_DumpScriptVariablesDefault(inst);
					gFs[inst] = localFs;
					Scr_Error(inst, "exceeded maximum number of script variables", 0);
				}
				Sys_Error("exceeded maximum number of script variables");
			}*/

			if ((game::Sys_Milliseconds() - game::gScrVmGlob[inst].starttime) >= 2500)
			{
				/*if (!logScriptTimes && !Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\clientscript\\cscr_vm.cpp", 2013, 0, "%s", "logScriptTimes"))
					__debugbreak();
				if (logScriptTimes->current.enabled)
				{
					v28 = Sys_Milliseconds();
					Com_Printf(game::CON_CHANNEL_PARSERSCRIPT, "EXCEED TIME: %d\n", v28);
				}*/

				if (!game::gScrVmGlob[inst].loading)
				{
					/*if (always_false())
					{
						Com_PrintWarning(game::CON_CHANNEL_PARSERSCRIPT, "script runtime warning: potential infinite loop in script.\n");
						Scr_PrintPrevCodePos(inst, 24, localFs.pos, 0);
						jumpOffset = Scr_ReadUnsignedShort(&localFs.pos);
						localFs.pos -= jumpOffset;
						Scr_ResetTimeout(inst);
					}
					VM_PrintJumpHistory(inst);
					if (gScrVmPub[inst].showError)
					{
						if (gScrVmPub[inst].debugCode && !Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\clientscript\\cscr_vm.cpp", 2046, 0, "%s", "!gScrVmPub[inst].debugCode"))
							__debugbreak();
						Scr_DumpScriptThreads(inst);
						Scr_DumpScriptVariablesDefault(inst);
						gFs[inst] = localFs;
						Scr_Error(inst, "potential infinite loop in script", 0);
					}*/

					if (!game::gScrVmPub[inst].abort_on_error)
					{
						// t5 added this extra string
						const char* side = inst == game::SCRIPTINSTANCE_CLIENT ? "client" : "server";

						game::Com_PrintError(game::CON_CHANNEL_PARSERSCRIPT, "%s script runtime error: potential infinite loop in script - killing thread.\n", side);

						game::Scr_PrintPrevCodePos(game::gFs[inst].pos, inst, game::CON_CHANNEL_PARSERSCRIPT, 0);
						game::Scr_ResetTimeout(inst);

						while (1)
						{
							parentLocalId = game::GetSafeParentLocalId(inst, game::gFs[inst].localId);
							game::Scr_KillThread(inst, game::gFs[inst].localId);

							game::gScrVmPub[inst].localVars -= game::gFs[inst].localVarCount;
							assert(game::gFs[inst].top->type != game::VAR_PRECODEPOS);

							while (game::gFs[inst].top->type != game::VAR_CODEPOS)
							{
								game::RemoveRefToValue(inst, game::gFs[inst].top--);
								assert(game::gFs[inst].top->type != game::VAR_PRECODEPOS);
							}

							--game::gScrVmPub[inst].function_count;
							--game::gScrVmPub[inst].function_frame;
							if (!parentLocalId)
							{
								break;
							}

							assert(game::gFs[inst].top != game::gFs[inst].startTop);

							game::RemoveRefToObject(game::gFs[inst].localId, inst);

							assert(game::gFs[inst].top->type == game::VAR_CODEPOS);

							game::gFs[inst].pos = game::gScrVmPub[inst].function_frame->fs.pos;
							assert(game::gFs[inst].pos);

							game::gFs[inst].localVarCount = game::gScrVmPub[inst].function_frame->fs.localVarCount;
							game::gFs[inst].localId = parentLocalId;
							--game::gFs[inst].top;
						}

						assert(game::gFs[inst].top == game::gFs[inst].startTop);
						
						game::gFs[inst].startTop[1].type = game::VAR_UNDEFINED;
						if ( game::gThreadCount[inst] )
						{
							--game::gThreadCount[inst];
							game::RemoveRefToObject(game::gFs[inst].localId, inst);
							game::gFs[inst] = game::gScrVmPub[inst].function_frame->fs;
							game::gFs[inst].top->type = (game::VariableType)game::gScrVmPub[inst].function_frame->topType;
							++game::gFs[inst].top;
							return true;
						}

						assert(game::g_script_error_level[inst] >= 0);
						--game::g_script_error_level[inst];
						return false;
					}

					// t5 is different here
					// game::Scr_DumpScriptThreads(inst);
					game::gScrVmPub[inst].terminal_error = 1;
					game::Scr_ResetTimeout(inst); // fix the bug
					game::Scr_Error("potential infinite loop in script", inst, false);
				}
				else
				{
					//if ( gScrVmPub[inst].abort_on_error )
					//	gScrVmPub[inst].showError = 1;
					game::Com_PrintWarning(game::CON_CHANNEL_PARSERSCRIPT, "script runtime warning: potential infinite loop in script.\n");
					game::Scr_PrintPrevCodePos(game::gFs[inst].pos, inst, game::CON_CHANNEL_PARSERSCRIPT, 0);
					jumpOffset = game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos);
					game::gFs[inst].pos -= jumpOffset;
					game::Scr_ResetTimeout(inst);
				}
			}
			else
			{
				// gScrVmDebugPub[inst].jumpbackHistory[gScrVmDebugPub[inst].jumpbackHistoryIndex] = localFs.pos;
				// gScrVmDebugPub[inst].jumpbackHistoryIndex = (gScrVmDebugPub[inst].jumpbackHistoryIndex + 1) % 0x80u;
				jumpOffset = game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos);
				game::gFs[inst].pos -= jumpOffset;
			}

			return true;
		}

		void OP_inc(game::scriptInstance_t inst, unsigned int *fieldValueId)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			++game::gFs[inst].top;
			*game::gFs[inst].top = game::Scr_EvalVariableField(inst, *fieldValueId);

			if ( game::gFs[inst].top->type != game::VAR_INTEGER )
			{
				game::Scr_Error(game::va("++ must be applied to an int (applied to %s)", game::var_typename[game::gFs[inst].top->type]), inst, false);
			}

			++game::gFs[inst].top->u.intValue;
			assert(*game::gFs[inst].pos == game::OpcodeVM::OP_SetVariableField);
		}

		void OP_dec(game::scriptInstance_t inst, unsigned int *fieldValueId)
		{
			assert(game::gFs[inst].top >= game::gScrVmPub[inst].stack);
			assert(&game::gFs[inst].top[1] <= game::gScrVmPub[inst].maxstack);

			++game::gFs[inst].top;
			*game::gFs[inst].top = game::Scr_EvalVariableField(inst, *fieldValueId);

			if ( game::gFs[inst].top->type != game::VAR_INTEGER )
			{
				game::Scr_Error(game::va("-- must be applied to an int (applied to %s)", game::var_typename[game::gFs[inst].top->type]), inst, false);
			}

			--game::gFs[inst].top->u.intValue;
			assert(*game::gFs[inst].pos == game::OpcodeVM::OP_SetVariableField);
		}

		void OP_bit_or(game::scriptInstance_t inst)
		{
			game::Scr_EvalOr(game::gFs[inst].top - 1, game::gFs[inst].top, inst);
			--game::gFs[inst].top;
		}

		void OP_bit_ex_or(game::scriptInstance_t inst)
		{
			game::Scr_EvalExOr(game::gFs[inst].top - 1, game::gFs[inst].top, inst);
			--game::gFs[inst].top;
		}

		void OP_bit_and(game::scriptInstance_t inst)
		{
			game::Scr_EvalAnd(game::gFs[inst].top - 1, game::gFs[inst].top, inst);
			--game::gFs[inst].top;
		}

		void OP_equality(game::scriptInstance_t inst)
		{
			game::Scr_EvalEquality(game::gFs[inst].top - 1, inst, game::gFs[inst].top);
			--game::gFs[inst].top;
		}

		void OP_inequality(game::scriptInstance_t inst)
		{
			game::Scr_EvalInequality(inst, game::gFs[inst].top - 1, game::gFs[inst].top);
			--game::gFs[inst].top;
		}

		void OP_less(game::scriptInstance_t inst)
		{
			game::Scr_EvalLess(game::gFs[inst].top, game::gFs[inst].top - 1, inst);
			--game::gFs[inst].top;
		}

		void OP_greater(game::scriptInstance_t inst)
		{
			game::Scr_EvalGreater(game::gFs[inst].top, game::gFs[inst].top - 1, inst);
			--game::gFs[inst].top;
		}

		void OP_less_equal(game::scriptInstance_t inst)
		{
			game::Scr_EvalLessEqual(inst, game::gFs[inst].top - 1, game::gFs[inst].top);
			--game::gFs[inst].top;
		}

		void OP_greater_equal(game::scriptInstance_t inst)
		{
			game::Scr_EvalGreaterEqual(inst, game::gFs[inst].top - 1, game::gFs[inst].top);
			--game::gFs[inst].top;
		}

		void OP_shift_left(game::scriptInstance_t inst)
		{
			game::Scr_EvalShiftLeft(game::gFs[inst].top - 1, game::gFs[inst].top, inst);
			--game::gFs[inst].top;
		}

		void OP_shift_right(game::scriptInstance_t inst)
		{
			game::Scr_EvalShiftRight(game::gFs[inst].top - 1, game::gFs[inst].top, inst);
			--game::gFs[inst].top;
		}

		void OP_plus(game::scriptInstance_t inst)
		{
			game::Scr_EvalPlus(inst, game::gFs[inst].top - 1, game::gFs[inst].top);
			--game::gFs[inst].top;
		}

		void OP_minus(game::scriptInstance_t inst)
		{
			game::Scr_EvalMinus(game::gFs[inst].top, inst, game::gFs[inst].top - 1);
			--game::gFs[inst].top;
		}

		void OP_multiply(game::scriptInstance_t inst)
		{
			game::Scr_EvalMultiply(game::gFs[inst].top, inst, game::gFs[inst].top - 1);
			--game::gFs[inst].top;
		}

		void OP_divide(game::scriptInstance_t inst)
		{
			game::Scr_EvalDivide(game::gFs[inst].top, inst, game::gFs[inst].top - 1);
			--game::gFs[inst].top;
		}

		void OP_mod(game::scriptInstance_t inst)
		{
			game::Scr_EvalMod(inst, game::gFs[inst].top - 1, game::gFs[inst].top);
			--game::gFs[inst].top;
		}

		void OP_size(game::scriptInstance_t inst)
		{
			game::Scr_EvalSizeValue(inst, game::gFs[inst].top);
		}

		bool OP_waittill(game::scriptInstance_t inst)
		{
			game::function_stack_t localFs = game::gFs[inst];
			game::VariableType type;
			game::VariableValue tempValue;
			unsigned int stringValue;
			game::VariableValue stackValue;
			unsigned int id;
			unsigned int stackId;

			assert(game::Scr_IsInOpcodeMemory(inst, localFs.pos));

			if (localFs.top->type != game::VAR_POINTER)
			{
				type = localFs.top->type;
				game::gScrVarPub[inst].error_index = 2;
				game::gFs[inst] = localFs;
				game::Scr_Error(game::va("%s is not an object", game::var_typename[type]), inst, false);
			}

			if (!game::IsFieldObject(inst, localFs.top->u.stringValue))
			{
				type = game::GetObjectType(inst, localFs.top->u.stringValue);
				game::gScrVarPub[inst].error_index = 2;
				game::gFs[inst] = localFs;
				game::Scr_Error(game::va("%s is not an object", game::var_typename[type]), inst, false);
			}

			tempValue.u.intValue = localFs.top->u.intValue;
			--localFs.top;
			if ( localFs.top->type != game::VAR_STRING )
			{
				++localFs.top;
				game::gScrVarPub[inst].error_index = 3;
				game::gFs[inst] = localFs;
				game::Scr_Error("first parameter of waittill must evaluate to a string", inst, false);
			}

			stringValue = localFs.top->u.stringValue;
			--localFs.top;

			assert(game::GetObjectType(inst, tempValue.u.stringValue) != game::VAR_THREAD);
			assert(game::GetObjectType(inst, tempValue.u.stringValue) != game::VAR_NOTIFY_THREAD);
			assert(game::GetObjectType(inst, tempValue.u.stringValue) != game::VAR_TIME_THREAD);
			assert(game::GetObjectType(inst, tempValue.u.stringValue) != game::VAR_CHILD_THREAD);
			assert(game::GetObjectType(inst, tempValue.u.stringValue) != game::VAR_DEAD_THREAD);

			stackValue.type = game::VAR_STACK;

			game::gFs[inst] = localFs;
			stackValue.u.stackValue = game::VM_ArchiveStack(inst);
			localFs = game::gFs[inst];

			id = game::GetArray(inst, game::GetVariable(inst, game::GetArray(inst, game::GetVariable(inst, tempValue.u.stringValue, OBJECT_STACK)), stringValue));

			stackId = game::GetNewObjectVariable(inst, localFs.localId, id);

			game::SetNewVariableValue(inst, stackId, &stackValue);
			tempValue.type = game::VAR_POINTER;

			game::SetNewVariableValue(inst, game::GetNewObjectVariable(inst, localFs.localId, game::GetArray(inst, game::GetObjectVariable(game::Scr_GetSelf(inst, localFs.localId), inst, game::gScrVarPub[inst].pauseArrayId))), &tempValue);

			game::Scr_SetThreadNotifyName(inst, localFs.localId, stringValue);

			localFs.startTop[1].type = game::VAR_UNDEFINED;
			if ( game::gThreadCount[inst] )
			{
				--game::gThreadCount[inst];
				game::RemoveRefToObject(localFs.localId, inst);
				localFs = game::gScrVmPub[inst].function_frame->fs;
				localFs.top->type = (game::VariableType)game::gScrVmPub[inst].function_frame->topType;
				++localFs.top;

				game::gFs[inst] = localFs;
				return true;
			}

			assert(game::g_script_error_level[inst] >= 0);

			--game::g_script_error_level[inst];
			game::gFs[inst] = localFs;
			return false;
		}

		void OP_notify(game::scriptInstance_t inst)
		{
			game::function_stack_t localFs = game::gFs[inst];
			game::VariableType type;
			unsigned int id;
			unsigned int stringValue;

			if ( localFs.top->type != game::VAR_POINTER )
			{
				type = localFs.top->type;
				game::gScrVarPub[inst].error_index = 2;
				game::gFs[inst] = localFs;
				game::Scr_Error(game::va("%s is not an object", game::var_typename[type]), inst, false);
			}

			id = localFs.top->u.stringValue;
			if ( !game::IsFieldObject(inst, id) )
			{
				type = game::GetObjectType(inst, localFs.top->u.stringValue);
				game::gScrVarPub[inst].error_index = 2;
				game::gFs[inst] = localFs;
				game::Scr_Error(game::va("%s is not an object", game::var_typename[type]), inst, false);
			}

			--localFs.top;
			if ( localFs.top->type != game::VAR_STRING )
			{
				++localFs.top;
				game::gScrVarPub[inst].error_index = 1;
				game::gFs[inst] = localFs;
				game::Scr_Error("first parameter of notify must evaluate to a string", inst, false);
			}

			stringValue = localFs.top->u.stringValue;
			--localFs.top;

			// if ( gScrVmDebugPub[inst].checkBreakon )
			// 	Scr_CheckBreakonNotify(inst, id, stringValue, localFs.top, localFs.pos, localFs.localId);

			game::gScrVmPub[inst].function_frame->fs.pos = localFs.pos;
			game::VM_Notify(inst, id, stringValue, localFs.top);
			localFs.pos = game::gScrVmPub[inst].function_frame->fs.pos;

			game::RemoveRefToObject(id, inst);
			game::SL_RemoveRefToString(stringValue, inst);

			assert(localFs.top->type != game::VAR_CODEPOS);

			while ( localFs.top->type != game::VAR_PRECODEPOS )
			{
				game::RemoveRefToValue(inst, localFs.top--);
				assert(localFs.top->type != game::VAR_CODEPOS);
			}

			--localFs.top;
			game::gFs[inst] = localFs;
		}

		void OP_endon(game::scriptInstance_t inst)
		{
			game::function_stack_t localFs = game::gFs[inst];
			game::VariableType type;
			game::VariableValue tempValue;
			unsigned int stringValue;
			unsigned int threadId;

			if ( localFs.top->type != game::VAR_POINTER )
			{
				type = localFs.top->type;
				game::gScrVarPub[inst].error_index = 1;
				game::gFs[inst] = localFs;
				game::Scr_Error(game::va("%s is not an object", game::var_typename[type]), inst, false);
			}

			if ( !game::IsFieldObject(inst, localFs.top->u.stringValue) )
			{
				type = game::GetObjectType(inst, localFs.top->u.stringValue);
				game::gScrVarPub[inst].error_index = 1;
				game::gFs[inst] = localFs;
				game::Scr_Error(game::va("%s is not an object", game::var_typename[type]), inst, false);
			}

			if ( localFs.top[-1].type != game::VAR_STRING )
			{
				game::gFs[inst] = localFs;
				game::Scr_Error("first parameter of endon must evaluate to a string", inst, false);
			}
			stringValue = localFs.top[-1].u.stringValue;
			game::AddRefToObject(inst, localFs.localId);
			threadId = game::AllocThread(inst, localFs.localId);

			assert(game::GetObjectType(inst, localFs.top->u.stringValue) != game::VAR_THREAD);
			assert(game::GetObjectType(inst, localFs.top->u.stringValue) != game::VAR_NOTIFY_THREAD);
			assert(game::GetObjectType(inst, localFs.top->u.stringValue) != game::VAR_TIME_THREAD);
			assert(game::GetObjectType(inst, localFs.top->u.stringValue) != game::VAR_CHILD_THREAD);
			assert(game::GetObjectType(inst, localFs.top->u.stringValue) != game::VAR_DEAD_THREAD);

			game::GetObjectVariable(threadId, inst, game::GetArray(inst, game::GetVariable(inst, game::GetArray(inst, game::GetVariable(inst, localFs.top->u.stringValue, OBJECT_STACK)), stringValue)));
			game::RemoveRefToObject(threadId, inst);

			tempValue.type = game::VAR_POINTER;
			tempValue.u.intValue = localFs.top->u.intValue;

			game::SetNewVariableValue(inst, game::GetNewObjectVariable(inst, threadId, game::GetArray(inst, game::GetObjectVariable(localFs.localId, inst, game::gScrVarPub[inst].pauseArrayId))), &tempValue);
			game::Scr_SetThreadNotifyName(inst, threadId, stringValue);

			localFs.top -= 2;
			game::gFs[inst] = localFs;
		}

		void OP_switch(game::scriptInstance_t inst)
		{
			game::function_stack_t localFs = game::gFs[inst];
			int jumpOffset;
			unsigned int caseValue;
			unsigned int currentCaseValue;
			const char* currentCodePos;

			jumpOffset = game::Scr_ReadUnsignedInt(inst, &localFs.pos);
			localFs.pos += jumpOffset;

			game::gCaseCount[inst] = game::Scr_ReadUnsignedShort(inst, &localFs.pos);

			if ( localFs.top->type == game::VAR_STRING )
			{
				caseValue = localFs.top->u.stringValue;
				game::SL_RemoveRefToString(localFs.top->u.stringValue, inst);
			}
			else
			{
				if ( localFs.top->type != game::VAR_INTEGER )
				{
					game::gFs[inst] = localFs;
					game::Scr_Error(game::va("cannot switch on %s", game::var_typename[localFs.top->type]), inst, false);
				}

				if ( !game::IsValidArrayIndex(inst, localFs.top->u.stringValue) )
				{
					game::gFs[inst] = localFs;
					game::Scr_Error(game::va("switch index %d out of range", localFs.top->u.intValue), inst, false);
				}

				caseValue = game::GetInternalVariableIndex(inst, localFs.top->u.stringValue);
			}
			if (!game::gCaseCount[inst])
			{
				localFs.top--;
				game::gFs[inst] = localFs;
				return;
			}

			assert(caseValue);

			do
			{
				currentCaseValue = game::Scr_ReadUnsignedInt(inst, &localFs.pos);
				currentCodePos = game::Scr_ReadCodePos(inst, &localFs.pos);
				if ( currentCaseValue == caseValue )
				{
					localFs.pos = currentCodePos;
					assert(currentCodePos);

					localFs.top--;
					game::gFs[inst] = localFs;
					return;
				}

				--game::gCaseCount[inst];
			}
			while ( game::gCaseCount[inst] );

			if ( !currentCaseValue )
			{
				localFs.pos = currentCodePos;
				assert(currentCodePos);
			}

			localFs.top--;
			game::gFs[inst] = localFs;
		}

		void OP_endswitch(game::scriptInstance_t inst)
		{
			game::gCaseCount[inst] = game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos);
			game::Scr_ReadData(inst, &game::gFs[inst].pos, 2 * game::gCaseCount[inst]);
		}

		void OP_vector(game::scriptInstance_t inst)
		{
			game::gFs[inst].top -= 2;
			game::Scr_CastVector(inst, game::gFs[inst].top);
		}

		void OP_NOP([[maybe_unused]] game::scriptInstance_t inst)
		{
		}

		void OP_abort(game::scriptInstance_t inst)
		{
			assert(game::g_script_error_level[inst] >= 0);
			--game::g_script_error_level[inst];
		}

		void OP_object([[maybe_unused]] game::scriptInstance_t inst)
		{
			/*if (localFs.top < gScrVmPub[inst].stack && !Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\clientscript\\cscr_vm.cpp", 2397, 0, "%s", "localFs.top >= gScrVmPub[inst].stack"))
				__debugbreak();
			if ( localFs.top > gScrVmPub[inst].maxstack && !Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\clientscript\\cscr_vm.cpp", 2398, 0, "%s", "localFs.top <= gScrVmPub[inst].maxstack") )
				__debugbreak();
			classnum = R_ReadPrimDrawSurfInt((GfxReadCmdBuf *)&localFs);
			entnum = R_ReadPrimDrawSurfInt((GfxReadCmdBuf *)&localFs);
			v38.intValue = FindEntityId(inst, entnum, classnum, 0);
			localFs.top[1].u = v38;
			if ( !localFs.top[1].u.intValue )
			{
				localFs.top[1].type = game::VAR_UNDEFINED;
				++localFs.top;
				gFs[inst] = localFs;
				Scr_Error(inst, "unknown object", 0);
			}
			++localFs.top;
			goto object;

			++game::gFs[inst].top;
			v278 = game::gFs[inst].pos;
			v279 = *(__int32 *)v278;
			v280 = v278 + 4;                        // Scr_ReadUnsignedInt
			game::gFs[inst].pos = v278 + 4;               // Scr_ReadUnsignedInt
			v281 = *((__int32 *)v278 + 1);
			game::gFs[inst].pos = v280 + 4;
			game::gFs[inst].top->u.intValue = game::FindEntityId(v279, v281, inst);
			v282 = game::gFs[inst].top;
			if ( !v282->u.intValue )
			{
				v282->type = game::VAR_UNDEFINED;
				game::Scr_Error("unknown object", inst, 0);
			}
			goto object;*/
		}

		void OP_thread_object([[maybe_unused]] game::scriptInstance_t inst)
		{
			/*if (localFs.top < gScrVmPub[inst].stack && !Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\clientscript\\cscr_vm.cpp", 2422, 0, "%s", "localFs.top >= gScrVmPub[inst].stack"))
				__debugbreak();
			if ( &localFs.top[1] > gScrVmPub[inst].maxstack && !Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\clientscript\\cscr_vm.cpp", 2423, 0, "%s", "localFs.top+1 <= gScrVmPub[inst].maxstack") )
				__debugbreak();
			v39 = Scr_ReadUnsignedShort(&localFs.pos);
			localFs.top[1].u.intValue = v39;
			++localFs.top;
		object:
			localFs.top->type = VAR_BEGIN_REF;
			AddRefToObject(inst, localFs.top->u.stringValue);

			++game::gFs[inst].top;
			v283 = game::gFs[inst].pos;
			v284 = *(__int16 *)v283;
			game::gFs[inst].pos = v283 + 2;               // Scr_ReadUnsignedShort
			game::gFs[inst].top->u.intValue = v284;
		object:
			game::gFs[inst].top->type = VAR_BEGIN_REF;
			v30.intValue = game::gFs[inst].top->u.intValue;
		inc_ref_count_continue:
			++game::gScrVarGlob[inst].parentVariables[v30.intValue + 1].u.next;*/
		}

		void OP_EvalLocalVariable([[maybe_unused]] game::scriptInstance_t inst)
		{
			/*if (localFs.top < gScrVmPub[inst].stack && !Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\clientscript\\cscr_vm.cpp", 2429, 0, "%s", "localFs.top >= gScrVmPub[inst].stack"))
				__debugbreak();
			if ( &localFs.top[1] > gScrVmPub[inst].maxstack && !Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\clientscript\\cscr_vm.cpp", 2430, 0, "%s", "localFs.top+1 <= gScrVmPub[inst].maxstack") )
				__debugbreak();
			v40 = Scr_ReadUnsignedShort(&localFs.pos);
			v63 = FindVariable(inst, localFs.localId, v40);
			v90 = Scr_EvalVariable(inst, v63);
			localFs.top[1] = v90;
			++localFs.top;

			++game::gFs[inst].top;
			v285 = game::gFs[inst].pos;
			v286 = *(__int16 *)v285;
			game::gFs[inst].pos = v285 + 2;               // Scr_ReadUnsignedShort
			v287 = &game::gScrVarGlob[inst].childVariables[game::gScrVarGlob[inst].childVariables[game::FindVariableIndexInternal2(
				inst,
				v286,
				(v286 + game::gFs[inst].localId) % 0xFFFD
				+ 1)].hash.id];// FindVariable FindVariableIndexInternal
			v310.intValue = (int)v287->u.u.intValue;
			v311 = v287->w.status & 0x1F;
			game::AddRefToValue(inst, (game::VariableType)v311, v310);// Scr_EvalVariable
			v288 = game::gFs[inst].top;
			v288->u = v310;
			v288->type = (game::VariableType)v311;*/
		}

		void OP_EvalLocalVariableRef([[maybe_unused]] game::scriptInstance_t inst)
		{
			/*fieldValueIndex = 0;
			v41 = Scr_ReadUnsignedShort(&localFs.pos);
			fieldValueId = FindVariable(inst, localFs.localId, v41);
			if ( !fieldValueId )
			{
				gFs[inst] = localFs;
				Scr_Error(inst, "cannot create a new local variable in the debugger", 0);
			}

			v289 = game::gFs[inst].pos;
			v290 = *(__int16 *)v289;
			game::gFs[inst].pos = v289 + 2;               // Scr_ReadUnsignedShort
			fieldValueIndex = 0;
			v291 = game::FindVariableIndexInternal2(inst, v290, (v290 + game::gFs[inst].localId) % 0xFFFD + 1);// FindVariableIndexInternal
			fieldValueId = game::gScrVarGlob[inst].childVariables[v291].hash.id;// FindVariable
			if ( game::gScrVarGlob[inst].childVariables[v291].hash.id )
			{
				continue;
			}
			game::Scr_Error("cannot create a new local variable in the debugger", inst, 0);
			goto OP_prof_begin;*/
		}

		void OP_prof_begin(game::scriptInstance_t inst)
		{
			game::Scr_ReadUnsignedByte(inst, &game::gFs[inst].pos);
		}

		void OP_prof_end(game::scriptInstance_t inst)
		{
			game::Scr_ReadUnsignedByte(inst, &game::gFs[inst].pos);
		}
	}

	// Completed
	unsigned int VM_ExecuteInternal(game::scriptInstance_t inst)
	{
		unsigned int objectId;
		unsigned int fieldValueId;
		unsigned int fieldValueIndex;

		++game::g_script_error_level[inst];
		while (true)
		{
			assert(game::g_script_error_level[inst] >= 0);
			assert(game::g_script_error_level[inst] < 33);
			assert(inst == 0 || inst == 1);
			//if (game::_setjmp3((int *)game::g_script_error.get() + 0x10 * (0x21 * inst + game::g_script_error_level[inst]), 0))
			if (!setjmp(g_script_error[inst][game::g_script_error_level[inst]]))
			{
				break;
			}

			switch ( game::gOpcode[inst] )
			{
			case game::OP_EvalLocalArrayRefCached0:
			case game::OP_EvalLocalArrayRefCached:
			case game::OP_EvalArrayRef:
			case game::OP_ClearArray:
			case game::OP_EvalLocalVariableRef:
				assert(game::gScrVarPub[inst].error_index >= -1);

				if ( game::gScrVarPub[inst].error_index < 0 )
				{
					game::gScrVarPub[inst].error_index = 1;
				}

				break;

			case game::OP_EvalSelfFieldVariable:
			case game::OP_EvalFieldVariable:
			case game::OP_ClearFieldVariable:
			case game::OP_SetVariableField:
			case game::OP_SetSelfFieldVariableField:
			case game::OP_inc:
			case game::OP_dec:
				game::gScrVarPub[inst].error_index = 0;
				break;

			case game::OP_CallBuiltin0:
			case game::OP_CallBuiltin1:
			case game::OP_CallBuiltin2:
			case game::OP_CallBuiltin3:
			case game::OP_CallBuiltin4:
			case game::OP_CallBuiltin5:
			case game::OP_CallBuiltin:
				assert(game::gScrVarPub[inst].error_index >= 0);

				if ( game::gScrVarPub[inst].error_index > 0 )
				{
					game::gScrVarPub[inst].error_index = game::gScrVmPub[inst].outparamcount + 1 - game::gScrVarPub[inst].error_index;
				}

				break;

			case game::OP_CallBuiltinMethod0:
			case game::OP_CallBuiltinMethod1:
			case game::OP_CallBuiltinMethod2:
			case game::OP_CallBuiltinMethod3:
			case game::OP_CallBuiltinMethod4:
			case game::OP_CallBuiltinMethod5:
			case game::OP_CallBuiltinMethod:
				assert(game::gScrVarPub[inst].error_index >= -1);

				if ( game::gScrVarPub[inst].error_index <= 0 )
				{
					if ( game::gScrVarPub[inst].error_index < 0 )
					{
						game::gScrVarPub[inst].error_index = 1;
					}
				}
				else
				{
					game::gScrVarPub[inst].error_index = game::gScrVmPub[inst].outparamcount + 2 - game::gScrVarPub[inst].error_index;
				}

				break;

			default:
				break;
			}

			game::RuntimeError(
				inst,
				game::gFs[inst].pos,
				game::gScrVarPub[inst].error_index,
				game::gScrVarPub[inst].error_message,
				game::gScrVmGlob[inst].dialog_error_message);

			game::Scr_ClearErrorMessage(inst);

			switch ( game::gOpcode[inst] )
			{
			case game::OP_EvalLocalArrayCached:
			case game::OP_EvalArray:
				game::RemoveRefToValue(inst, game::gFs[inst].top--);
				game::RemoveRefToValue(inst, game::gFs[inst].top);
				game::gFs[inst].top->type = game::VAR_UNDEFINED;
				break;

			case game::OP_EvalLocalArrayRefCached0:
			case game::OP_EvalLocalArrayRefCached:
			case game::OP_EvalArrayRef:
			case game::OP_EvalLocalVariableRef:
				fieldValueIndex = 0;
				fieldValueId = game::GetDummyFieldValue(inst);
				game::RemoveRefToValue(inst, game::gFs[inst].top);
				--game::gFs[inst].top;
				break;

			case game::OP_ClearArray:
			case game::OP_wait:
				game::RemoveRefToValue(inst, game::gFs[inst].top);
				--game::gFs[inst].top;
				break;

			case game::OP_GetSelfObject:
				objectId = game::GetDummyObject(inst);
				break;

			case game::OP_EvalSelfFieldVariable:
			case game::OP_EvalFieldVariable:
				game::gFs[inst].top->type = game::VAR_UNDEFINED;
				break;

			case game::OP_EvalSelfFieldVariableRef:
			case game::OP_EvalFieldVariableRef:
				fieldValueIndex = 0;
				fieldValueId = game::GetDummyFieldValue(inst);
				break;

			case game::OP_ClearFieldVariable:
				if ( game::gScrVmPub[inst].outparamcount )
				{
					assert(game::gScrVmPub[inst].outparamcount == 1);
					assert(game::gScrVmPub[inst].top->type == game::VAR_UNDEFINED);
					game::gScrVmPub[inst].outparamcount = 0;
				}

				if ( game::gScrVmPub[inst].outparamcount )
				{
					game::gScrVmPub[inst].outparamcount = 0;
				}

				break;

			case game::OP_checkclearparams:
				assert(game::gFs[inst].top->type != game::VAR_CODEPOS);

				while ( game::gFs[inst].top->type != game::VAR_PRECODEPOS )
				{
					game::RemoveRefToValue(inst, game::gFs[inst].top--);
					assert(game::gFs[inst].top->type != game::VAR_CODEPOS);
				}

				game::gFs[inst].top->type = game::VAR_CODEPOS;
				break;

			case game::OP_SetVariableField:
				if ( game::gScrVmPub[inst].outparamcount )
				{
					assert(game::gScrVmPub[inst].outparamcount == 1);
					assert(game::gScrVmPub[inst].top == game::gFs[inst].top);
					game::RemoveRefToValue(inst, game::gFs[inst].top);
					game::gScrVmPub[inst].outparamcount = 0;
				}

				--game::gFs[inst].top;
				break;

			case game::OP_SetSelfFieldVariableField:
				game::RemoveRefToValue(inst, game::gFs[inst].top);
				game::gScrVmPub[inst].outparamcount = 0;
				--game::gFs[inst].top;
				break;

			case game::OP_CallBuiltin0:
			case game::OP_CallBuiltin1:
			case game::OP_CallBuiltin2:
			case game::OP_CallBuiltin3:
			case game::OP_CallBuiltin4:
			case game::OP_CallBuiltin5:
			case game::OP_CallBuiltin:
			case game::OP_CallBuiltinMethod0:
			case game::OP_CallBuiltinMethod1:
			case game::OP_CallBuiltinMethod2:
			case game::OP_CallBuiltinMethod3:
			case game::OP_CallBuiltinMethod4:
			case game::OP_CallBuiltinMethod5:
			case game::OP_CallBuiltinMethod:
				game::Scr_ClearOutParams(inst);
				game::gFs[inst].top = game::gScrVmPub[inst].top + 1;
				game::gFs[inst].top->type = game::VAR_UNDEFINED;
				break;

			case game::OP_ScriptFunctionCall2:
			case game::OP_ScriptFunctionCall:
			case game::OP_ScriptMethodCall:
				game::Scr_ReadCodePos(inst, &game::gFs[inst].pos);
				[[fallthrough]];

			case game::OP_ScriptFunctionCallPointer:
			case game::OP_ScriptMethodCallPointer:
				assert(game::gFs[inst].top->type != game::VAR_CODEPOS);

				while ( game::gFs[inst].top->type != game::VAR_PRECODEPOS )
				{
					game::RemoveRefToValue(inst, game::gFs[inst].top);
					--game::gFs[inst].top;
					assert(game::gFs[inst].top->type != game::VAR_CODEPOS);
				}

				game::gFs[inst].top->type = game::VAR_UNDEFINED;
				break;

			case game::OP_ScriptThreadCall:
			case game::OP_ScriptMethodThreadCall:
				game::Scr_ReadCodePos(inst, &game::gFs[inst].pos);
				[[fallthrough]];

			case game::OP_ScriptThreadCallPointer:
			case game::OP_ScriptMethodThreadCallPointer:
			{
				for (unsigned int paramcount = game::Scr_ReadUnsignedInt(inst, &game::gFs[inst].pos);
					paramcount;
					--paramcount)
				{
					game::RemoveRefToValue(inst, game::gFs[inst].top--);
				}
				++game::gFs[inst].top;
				game::gFs[inst].top->type = game::VAR_UNDEFINED;
				break;
			}

			case game::OP_CastFieldObject:
				objectId = game::GetDummyObject(inst);
				--game::gFs[inst].top;
				break;

			case game::OP_EvalLocalVariableObjectCached:
				game::Scr_ReadUnsignedByte(inst, &game::gFs[inst].pos);
				objectId = game::GetDummyObject(inst);
				break;

			case game::OP_JumpOnFalse:
			case game::OP_JumpOnTrue:
			case game::OP_JumpOnFalseExpr:
			case game::OP_JumpOnTrueExpr:
				game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos);
				--game::gFs[inst].top;
				break;

			case game::OP_jumpback:
			{
				unsigned short jumpOffset = game::Scr_ReadUnsignedShort(inst, &game::gFs[inst].pos);
				game::gFs[inst].pos -= jumpOffset;
				break;
			}

			case game::OP_bit_or:
			case game::OP_bit_ex_or:
			case game::OP_bit_and:
			case game::OP_equality:
			case game::OP_inequality:
			case game::OP_less:
			case game::OP_greater:
			case game::OP_less_equal:
			case game::OP_greater_equal:
			case game::OP_shift_left:
			case game::OP_shift_right:
			case game::OP_plus:
			case game::OP_minus:
			case game::OP_multiply:
			case game::OP_divide:
			case game::OP_mod:
				--game::gFs[inst].top;
				break;

			case game::OP_waittillmatch:
				game::Scr_ReadUnsignedByte(inst, &game::gFs[inst].pos);
				[[fallthrough]];

			case game::OP_waittill:
			case game::OP_endon:
				game::RemoveRefToValue(inst, game::gFs[inst].top);
				--game::gFs[inst].top;
				game::RemoveRefToValue(inst, game::gFs[inst].top);
				--game::gFs[inst].top;
				break;

			case game::OP_notify:
				assert(game::gFs[inst].top->type != game::VAR_CODEPOS);

				while ( game::gFs[inst].top->type != game::VAR_PRECODEPOS )
				{
					game::RemoveRefToValue(inst, game::gFs[inst].top--);
					assert(game::gFs[inst].top->type != game::VAR_CODEPOS);
				}

				game::RemoveRefToValue(inst, game::gFs[inst].top);
				--game::gFs[inst].top;
				break;

			case game::OP_switch:
			{
				if (game::gCaseCount[inst])
				{
					int currentCaseValue;
					const char* currentCodePos;

					do
					{
						currentCaseValue = game::Scr_ReadUnsignedInt(inst, &game::gFs[inst].pos);
						currentCodePos = game::Scr_ReadCodePos(inst, &game::gFs[inst].pos);
						--game::gCaseCount[inst];
					} while (game::gCaseCount[inst]);

					if (!currentCaseValue)
					{
						game::gFs[inst].pos = currentCodePos;
						assert(currentCodePos);
					}
				}

				game::RemoveRefToValue(inst, game::gFs[inst].top);
				--game::gFs[inst].top;
				break;
			}

			default:
				break;
			}

			continue;
		}

		while ( true )
		{
			game::gOpcode[inst] = (game::OpcodeVM)game::Scr_ReadUnsignedByte(inst, &game::gFs[inst].pos);
		interrupt_return:
			switch ( game::gOpcode[inst] )
			{
			case game::OP_End:
				if (VM::OP_End(inst))
				{
					continue;
				}

				return game::gFs[inst].localId;

			case game::OP_Return:
				if (VM::OP_Return(inst))
				{
					continue;
				}

				return game::gFs[inst].localId;

			case game::OP_GetUndefined:
				VM::OP_GetUndefined(inst);
				continue;

			case game::OP_GetZero:
				VM::OP_GetZero(inst);
				continue;

			case game::OP_GetByte:
				VM::OP_GetByte(inst);
				continue;

			case game::OP_GetNegByte:
				VM::OP_GetNegByte(inst);
				continue;

			case game::OP_GetUnsignedShort:
				VM::OP_GetUnsignedShort(inst);
				continue;

			case game::OP_GetNegUnsignedShort:
				VM::OP_GetNegUnsignedShort(inst);
				continue;

			case game::OP_GetInteger:
				VM::OP_GetInteger(inst);
				continue;

			case game::OP_GetFloat:
				VM::OP_GetFloat(inst);
				continue;

			case game::OP_GetString:
				VM::OP_GetString(inst);
				continue;

			case game::OP_GetIString:
				VM::OP_GetIString(inst);
				continue;

			case game::OP_GetVector:
				VM::OP_GetVector(inst);
				continue;

			case game::OP_GetLevelObject:
				VM::OP_GetLevelObject(inst, &objectId);
				continue;

			case game::OP_GetAnimObject:
				VM::OP_GetAnimObject(inst, &objectId);
				continue;

			case game::OP_GetSelf:
				VM::OP_GetSelf(inst);
				continue;

			case game::OP_GetLevel:
				VM::OP_GetLevel(inst);
				continue;

			case game::OP_GetGame:
				VM::OP_GetGame(inst);
				continue;

			case game::OP_GetAnim:
				VM::OP_GetAnim(inst);
				continue;

			case game::OP_GetAnimation:
				VM::OP_GetAnimation(inst);
				continue;

			case game::OP_GetGameRef:
				VM::OP_GetGameRef(inst, &fieldValueIndex, &fieldValueId);
				continue;

			case game::OP_GetFunction:
				VM::OP_GetFunction(inst);
				continue;

			case game::OP_CreateLocalVariable:
				VM::OP_CreateLocalVariable(inst);
				continue;

			case game::OP_RemoveLocalVariables:
				VM::OP_RemoveLocalVariables(inst);
				continue;

			case game::OP_EvalLocalVariableCached0:
				VM::OP_EvalLocalVariableCached(inst, 0);
				continue;

			case game::OP_EvalLocalVariableCached1:
				VM::OP_EvalLocalVariableCached(inst, 1);
				continue;

			case game::OP_EvalLocalVariableCached2:
				VM::OP_EvalLocalVariableCached(inst, 2);
				continue;

			case game::OP_EvalLocalVariableCached3:
				VM::OP_EvalLocalVariableCached(inst, 3);
				continue;

			case game::OP_EvalLocalVariableCached4:
				VM::OP_EvalLocalVariableCached(inst, 4);
				continue;

			case game::OP_EvalLocalVariableCached5:
				VM::OP_EvalLocalVariableCached(inst, 5);
				continue;

			case game::OP_EvalLocalVariableCached:
				VM::OP_EvalLocalVariableCached(inst, -1);
				continue;

			case game::OP_EvalLocalArrayCached:
				VM::OP_EvalLocalArrayCached(inst);
				continue;

			case game::OP_EvalArray:
				VM::OP_EvalArray(inst);
				continue;

			case game::OP_EvalLocalArrayRefCached0:
				VM::OP_EvalLocalArrayRefCached(inst, 0, &fieldValueId, &fieldValueIndex, &objectId);
				continue;

			case game::OP_EvalLocalArrayRefCached:
				VM::OP_EvalLocalArrayRefCached(inst, -1, &fieldValueId, &fieldValueIndex, &objectId);
				continue;

			case game::OP_EvalArrayRef:
				VM::OP_EvalArrayRef(inst, &fieldValueId, &fieldValueIndex, &objectId);
				continue;

			case game::OP_ClearArray:
				VM::OP_ClearArray(inst, &fieldValueId);
				continue;

			case game::OP_EmptyArray:
				VM::OP_EmptyArray(inst);
				continue;

			case game::OP_GetSelfObject:
				VM::OP_GetSelfObject(inst, &objectId);
				continue;

			case game::OP_EvalLevelFieldVariable:
				VM::OP_EvalLevelAnimFieldVariable(inst, true, &objectId);
				continue;

			case game::OP_EvalAnimFieldVariable:
				VM::OP_EvalLevelAnimFieldVariable(inst, false, &objectId);
				continue;

			case game::OP_EvalSelfFieldVariable:
				VM::OP_EvalSelfFieldVariable(inst, &objectId);
				continue;

			case game::OP_EvalFieldVariable:
				VM::OP_EvalFieldVariable(inst, &objectId);
				continue;

			case game::OP_EvalLevelFieldVariableRef:
				VM::OP_EvalLevelFieldVariableRef(inst, &objectId, &fieldValueIndex, &fieldValueId);
				continue;

			case game::OP_EvalAnimFieldVariableRef:
				VM::OP_EvalAnimFieldVariableRef(inst, &objectId, &fieldValueIndex, &fieldValueId);
				continue;

			case game::OP_EvalSelfFieldVariableRef:
				VM::OP_EvalSelfFieldVariableRef(inst, &objectId, &fieldValueIndex, &fieldValueId);
				continue;

			case game::OP_EvalFieldVariableRef:
				VM::OP_EvalFieldVariableRef(inst, &objectId, &fieldValueIndex, &fieldValueId);
				continue;

			case game::OP_ClearFieldVariable:
				VM::OP_ClearFieldVariable(inst, &objectId);
				continue;

			case game::OP_SafeCreateVariableFieldCached:
				VM::OP_SafeCreateVariableFieldCached(inst);
				continue;

			case game::OP_SafeSetVariableFieldCached0:
				VM::OP_SafeSetVariableFieldCached(inst, 0);
				continue;

			case game::OP_SafeSetVariableFieldCached:
				VM::OP_SafeSetVariableFieldCached(inst, -1);
				continue;

			case game::OP_SafeSetWaittillVariableFieldCached:
				VM::OP_SafeSetWaittillVariableFieldCached(inst);
				continue;

			case game::OP_clearparams:
				VM::OP_clearparams(inst);
				continue;

			case game::OP_checkclearparams:
				VM::OP_checkclearparams(inst);
				continue;

			case game::OP_EvalLocalVariableRefCached0:
				VM::OP_EvalLocalVariableRefCached(inst, 0, &fieldValueIndex, &fieldValueId);
				continue;

			case game::OP_EvalLocalVariableRefCached:
				VM::OP_EvalLocalVariableRefCached(inst, -1, &fieldValueIndex, &fieldValueId);
				continue;

			case game::OP_SetLevelFieldVariableField:
				VM::OP_SetLevelFieldVariableField(inst);
				continue;

			case game::OP_SetVariableField:
				VM::OP_SetVariableField(inst, &objectId, &fieldValueIndex, &fieldValueId);
				continue;

			case game::OP_SetAnimFieldVariableField:
				VM::OP_SetAnimFieldVariableField(inst);
				continue;

			case game::OP_SetSelfFieldVariableField:
				VM::OP_SetSelfFieldVariableField(inst, &objectId, &fieldValueIndex, &fieldValueId);
				continue;

			case game::OP_SetLocalVariableFieldCached0:
				VM::OP_SetLocalVariableFieldCached(inst, 0);
				continue;

			case game::OP_SetLocalVariableFieldCached:
				VM::OP_SetLocalVariableFieldCached(inst, -1);
				continue;

			case game::OP_CallBuiltin0:
				VM::OP_CallBuiltin(inst, 0);
				continue;

			case game::OP_CallBuiltin1:
				VM::OP_CallBuiltin(inst, 1);
				continue;
			case game::OP_CallBuiltin2:

				VM::OP_CallBuiltin(inst, 2);
				continue;

			case game::OP_CallBuiltin3:
				VM::OP_CallBuiltin(inst, 3);
				continue;

			case game::OP_CallBuiltin4:
				VM::OP_CallBuiltin(inst, 4);
				continue;

			case game::OP_CallBuiltin5:
				VM::OP_CallBuiltin(inst, 5);
				continue;

			case game::OP_CallBuiltin:
				VM::OP_CallBuiltin(inst, -1);
				continue;

			case game::OP_CallBuiltinMethod0:
				VM::OP_CallBuiltinMethod(inst, 0, &objectId);
				continue;

			case game::OP_CallBuiltinMethod1:
				VM::OP_CallBuiltinMethod(inst, 1, &objectId);
				continue;

			case game::OP_CallBuiltinMethod2:
				VM::OP_CallBuiltinMethod(inst, 2, &objectId);
				continue;

			case game::OP_CallBuiltinMethod3:
				VM::OP_CallBuiltinMethod(inst, 3, &objectId);
				continue;

			case game::OP_CallBuiltinMethod4:
				VM::OP_CallBuiltinMethod(inst, 4, &objectId);
				continue;

			case game::OP_CallBuiltinMethod5:
				VM::OP_CallBuiltinMethod(inst, 5, &objectId);
				continue;

			case game::OP_CallBuiltinMethod:
				VM::OP_CallBuiltinMethod(inst, -1, &objectId);
				continue;

			case game::OP_wait:
				if (VM::OP_wait(inst))
				{
					continue;
				}

				return game::gFs[inst].localId;

			case game::OP_waittillFrameEnd:
				if (VM::OP_waittillFrameEnd(inst))
				{
					continue;
				}

				return game::gFs[inst].localId;

			case game::OP_PreScriptCall:
				VM::OP_PreScriptCall(inst, true);
				continue;

			case game::OP_voidCodepos:
				VM::OP_PreScriptCall(inst, false);
				continue;

			case game::OP_ScriptFunctionCall2:
				VM::OP_ScriptFunctionCall2(inst);
				continue;

			case game::OP_ScriptFunctionCall:
				VM::OP_ScriptFunctionCall(inst);
				continue;

			case game::OP_ScriptFunctionCallPointer:
				VM::OP_ScriptFunctionCallPointer(inst);
				continue;

			case game::OP_ScriptMethodCall:
				VM::OP_ScriptMethodCall(inst);
				continue;

			case game::OP_ScriptMethodCallPointer:
				VM::OP_ScriptMethodCallPointer(inst);
				continue;

			case game::OP_ScriptThreadCall:
				VM::OP_ScriptThreadCall(inst);
				continue;

			case game::OP_ScriptThreadCallPointer:
				VM::OP_ScriptThreadCallPointer(inst);
				continue;

			case game::OP_ScriptMethodThreadCall:
				VM::OP_ScriptMethodThreadCall(inst);
				continue;

			case game::OP_ScriptMethodThreadCallPointer:
				VM::OP_ScriptMethodThreadCallPointer(inst);
				continue;

			case game::OP_DecTop:
				VM::OP_DecTop(inst);
				continue;

			case game::OP_CastFieldObject:
				VM::OP_CastFieldObject(inst, &objectId);
				continue;

			case game::OP_EvalLocalVariableObjectCached:
				VM::OP_EvalLocalVariableObjectCached(inst, &objectId);
				continue;

			case game::OP_CastBool:
				VM::OP_CastBool(inst);
				continue;

			case game::OP_BoolNot:
				VM::OP_BoolNot(inst);
				continue;

			case game::OP_BoolComplement:
				VM::OP_BoolComplement(inst);
				continue;

			case game::OP_JumpOnFalse:
				VM::OP_JumpOnFalse(inst);
				continue;

			case game::OP_JumpOnTrue:
				VM::OP_JumpOnTrue(inst);
				continue;

			case game::OP_JumpOnFalseExpr:
				VM::OP_JumpOnFalseExpr(inst);
				continue;

			case game::OP_JumpOnTrueExpr:
				VM::OP_JumpOnTrueExpr(inst);
				continue;

			case game::OP_jump:
				VM::OP_jump(inst);
				continue;

			case game::OP_jumpback:
				if (VM::OP_jumpback(inst))
				{
					continue;
				}

				return game::gFs[inst].localId;

			case game::OP_inc:
				VM::OP_inc(inst, &fieldValueId);
				continue;

			case game::OP_dec:
				VM::OP_dec(inst, &fieldValueId);
				continue;

			case game::OP_bit_or:
				VM::OP_bit_or(inst);
				continue;

			case game::OP_bit_ex_or:
				VM::OP_bit_ex_or(inst);
				continue;

			case game::OP_bit_and:
				VM::OP_bit_and(inst);
				continue;

			case game::OP_equality:
				VM::OP_equality(inst);
				continue;

			case game::OP_inequality:
				VM::OP_inequality(inst);
				continue;

			case game::OP_less:
				VM::OP_less(inst);
				continue;

			case game::OP_greater:
				VM::OP_greater(inst);
				continue;

			case game::OP_less_equal:
				VM::OP_less_equal(inst);
				continue;

			case game::OP_greater_equal:
				VM::OP_greater_equal(inst);
				continue;

			case game::OP_shift_left:
				VM::OP_shift_left(inst);
				continue;

			case game::OP_shift_right:
				VM::OP_shift_right(inst);
				continue;

			case game::OP_plus:
				VM::OP_plus(inst);
				continue;

			case game::OP_minus:
				VM::OP_minus(inst);
				continue;

			case game::OP_multiply:
				VM::OP_multiply(inst);
				continue;

			case game::OP_divide:
				VM::OP_divide(inst);
				continue;

			case game::OP_mod:
				VM::OP_mod(inst);
				continue;

			case game::OP_size:
				VM::OP_size(inst);
				continue;

			case game::OP_waittillmatch:
			case game::OP_waittill:
				if (VM::OP_waittill(inst))
				{
					continue;
				}

				return game::gFs[inst].localId;

			case game::OP_notify:
				VM::OP_notify(inst);
				continue;

			case game::OP_endon:
				VM::OP_endon(inst);
				continue;

			case game::OP_switch:
				VM::OP_switch(inst);
				continue;

			case game::OP_endswitch:
				VM::OP_endswitch(inst);
				continue;

			case game::OP_vector:
				VM::OP_vector(inst);
				continue;

			case game::OP_NOP:
				VM::OP_NOP(inst);
				continue;

			case game::OP_abort:
				VM::OP_abort(inst);
				return 0;

			case game::OP_object:
				VM::OP_object(inst);
				continue;

			case game::OP_thread_object:
				VM::OP_thread_object(inst);
				continue;

			case game::OP_EvalLocalVariable:
				VM::OP_EvalLocalVariable(inst);
				continue;

			case game::OP_EvalLocalVariableRef:
				VM::OP_EvalLocalVariableRef(inst);
				continue;

			case game::OP_prof_begin:
				VM::OP_prof_begin(inst);
				continue;

			case game::OP_prof_end:
				VM::OP_prof_end(inst);
				continue;

			case game::OP_breakpoint:
				if ( !game::gScrVarPub[inst].developer )
				{
					continue;
				}
				//game::gOpcode[inst] = Scr_HitBreakpoint(inst, localFs.top, localFs.pos, localFs.localId, 0);
				goto interrupt_return;

			case game::OP_assignmentBreakpoint:
				//game::gOpcode[inst] = Scr_HitAssignmentBreakpoint(inst, localFs.top, localFs.pos, localFs.localId, 0);
				goto interrupt_return;

			case game::OP_manualAndAssignmentBreakpoint:
				//game::gOpcode[inst] = Scr_HitAssignmentBreakpoint(inst, localFs.top, localFs.pos, localFs.localId, 1);
				goto interrupt_return;

			default:
				game::gScrVmPub[inst].terminal_error = 1;
				game::RuntimeError(inst, game::gFs[inst].pos, 0, game::va("CODE ERROR: unknown opcode %d", game::gOpcode[inst]), nullptr);
				continue;
			}
		}
	}

	// Restored
	void Scr_RemoveThreadNotifyName(game::scriptInstance_t inst, unsigned int startLocalId)
	{
		unsigned __int16 stringValue;
		game::VariableValueInternal *entryValue;

		entryValue = &game::gScrVarGlob[inst].parentVariables[startLocalId + 1];

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert((entryValue->w.type & VAR_MASK) == game::VAR_NOTIFY_THREAD);

		stringValue = game::Scr_GetThreadNotifyName(inst, startLocalId);

		assert(stringValue);

		game::SL_RemoveRefToString(stringValue, inst);
		entryValue->w.status &= ~VAR_MASK;
		entryValue->w.status |= game::VAR_THREAD;
	}

	// Restored
	unsigned int Scr_GetThreadNotifyName(game::scriptInstance_t inst, unsigned int startLocalId)
	{
		assert((game::gScrVarGlob[inst].parentVariables[startLocalId + 1].w.type & VAR_STAT_MASK) == VAR_STAT_EXTERNAL);

		assert((game::gScrVarGlob[inst].parentVariables[startLocalId + 1].w.type & VAR_MASK) == game::VAR_NOTIFY_THREAD);

		assert((game::gScrVarGlob[inst].parentVariables[startLocalId + 1].w.notifyName >> VAR_NAME_BIT_SHIFT) < VARIABLELIST_CHILD_SIZE);

		return game::gScrVarGlob[inst].parentVariables[startLocalId + 1].w.status >> VAR_NAME_BIT_SHIFT;
	}

	// Restored
	unsigned int GetArraySize(game::scriptInstance_t inst, unsigned int id)
	{
		game::VariableValueInternal *entryValue;

		assert(id);

		entryValue = &game::gScrVarGlob[inst].parentVariables[id + 1];

		assert((entryValue->w.type & VAR_MASK) == game::VAR_ARRAY);

		return entryValue->u.o.u.entnum;
	}

	// Completed
	void VM_CancelNotifyInternal(game::scriptInstance_t inst, unsigned int notifyNameListId, unsigned int notifyListOwnerId, unsigned int startLocalId, unsigned int notifyListId, unsigned int stringValue)
	{
		assert(stringValue == game::Scr_GetThreadNotifyName(inst, startLocalId));

		assert(notifyListId == game::FindObject(inst, game::FindVariable(OBJECT_NOTIFY_LIST, notifyListOwnerId, inst)));

		assert(notifyNameListId == game::FindObject(inst, game::FindVariable(stringValue, notifyListId, inst)));

		game::Scr_RemoveThreadNotifyName(inst, startLocalId);
		game::RemoveObjectVariable(inst, notifyNameListId, startLocalId);

		if ( !game::GetArraySize(inst, notifyNameListId) )
		{
			game::RemoveVariable(stringValue, notifyListId, inst);
			if ( !game::GetArraySize(inst, notifyListId) )
			{
				game::RemoveVariable(OBJECT_STACK, notifyListOwnerId, inst);
			}
		}
	}

	// Completed
	void VM_CancelNotify(game::scriptInstance_t inst, unsigned int notifyListOwnerId, unsigned int startLocalId)
	{
		unsigned int stringValue;
		unsigned int notifyListId;
		unsigned int notifyNameListId;

		notifyListId = game::FindObject(inst, game::FindVariable(OBJECT_STACK, notifyListOwnerId, inst));
		stringValue = game::Scr_GetThreadNotifyName(inst, startLocalId);

		assert(stringValue);

		notifyNameListId = game::FindObject(inst, game::FindVariable(stringValue, notifyListId, inst));
		game::VM_CancelNotifyInternal(inst, notifyNameListId, notifyListOwnerId, startLocalId, notifyListId, stringValue);
	}

	// Restored
	unsigned int GetParentLocalId(game::scriptInstance_t inst, unsigned int threadId)
	{
		assert((game::gScrVarGlob[inst].parentVariables[threadId + 1].w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL);

		assert((game::gScrVarGlob[inst].parentVariables[threadId + 1].w.type & VAR_MASK) == game::VAR_CHILD_THREAD);

		return game::gScrVarGlob[inst].parentVariables[threadId + 1].w.status >> VAR_NAME_BIT_SHIFT;
	}

	// Completed
	game::VariableStackBuffer *VM_ArchiveStack(game::scriptInstance_t inst)
	{
		game::VariableStackBuffer *stackValue;
		game::VariableValue *top;
		char *buf;
		char *bufa;
		unsigned int localId;
		int size;
		int bufLen;
		game::function_stack_t* stack;

		stack = &game::gFs[inst];

		top = stack->top;
		size = top - stack->startTop;

		assert(size == (unsigned short)size);

		bufLen = 5 * size + 11; // t5 is 13?

		assert(bufLen == (unsigned short)bufLen);

		stackValue = (game::VariableStackBuffer *)game::MT_Alloc(bufLen, inst);
		localId = stack->localId;
		stackValue->localId = localId;
		stackValue->size = size;
		stackValue->bufLen = bufLen;
		stackValue->pos = (char*)stack->pos;
		stackValue->time = game::gScrVarPub[inst].time;
		game::gScrVmPub[inst].localVars -= stack->localVarCount;
		buf = &stackValue->buf[5 * size];
		while ( size )
		{
			bufa = buf - 4;
			if ( top->type == game::VAR_CODEPOS )
			{
				--game::gScrVmPub[inst].function_count;
				--game::gScrVmPub[inst].function_frame;
				*(int *)bufa = (int)game::gScrVmPub[inst].function_frame->fs.pos;
				game::gScrVmPub[inst].localVars -= game::gScrVmPub[inst].function_frame->fs.localVarCount;
				localId = game::GetParentLocalId(inst, localId);
			}
			else
			{
				*(int *)bufa = top->u.intValue;
			}
			buf = bufa - 1;

			assert(top->type >= 0 && top->type < (1 << 8));

			*buf = top->type;
			--top;
			--size;
		}
		--game::gScrVmPub[inst].function_count;
		--game::gScrVmPub[inst].function_frame;
		game::AddRefToObject(inst, localId);
		stack->localId = localId;
		return stackValue;
	}

	// Completed
	int Scr_AddLocalVars(game::scriptInstance_t inst, unsigned int localId)
	{
		int localVarCount;
		unsigned int fieldIndex;

		localVarCount = 0;
		for ( fieldIndex = game::FindLastSibling(localId, inst);
			fieldIndex;
			fieldIndex = game::gScrVarGlob[inst].childVariables[fieldIndex].hash.u.prev )
		{
			*++game::gScrVmPub[inst].localVars = game::gScrVarGlob[inst].childVariables[fieldIndex].hash.id;
			++localVarCount;
		}
		return localVarCount;
	}

	// Restored
	void Scr_ClearWaitTime(game::scriptInstance_t inst, unsigned int startLocalId)
	{
		game::VariableValueInternal *entryValue;

		entryValue = &game::gScrVarGlob[inst].parentVariables[startLocalId + 1];

		assert(((entryValue->w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL));

		assert((entryValue->w.type & VAR_MASK) == game::VAR_TIME_THREAD);

		entryValue->w.status &= ~VAR_MASK;
		entryValue->w.status |= game::VAR_THREAD;
	}

	// Completed
	void VM_UnarchiveStack(game::scriptInstance_t inst, unsigned int startLocalId, game::VariableStackBuffer *stackValue)
	{
		game::VariableValue *top;
		char *buf;
		const char **bufa;
		unsigned int localId;
		int function_count;
		int size;

		assert(!game::gScrVmPub[inst].function_count);

		assert(stackValue->pos);

		assert(game::gFs[inst].startTop == &game::gScrVmPub[inst].stack[0]);

		game::gScrVmPub[inst].function_frame->fs.pos = stackValue->pos;
		++game::gScrVmPub[inst].function_count;
		++game::gScrVmPub[inst].function_frame;
		size = stackValue->size;
		buf = stackValue->buf;
		top = game::gScrVmPub[inst].stack;

		while ( size )
		{
			--size;
			top[1].type = (game::VariableType)*buf;
			++top;
			bufa = (const char **)(buf + 1);

			if ( top->type == game::VAR_CODEPOS )
			{
				assert(game::gScrVmPub[inst].function_count < MAX_VM_STACK_DEPTH);

				game::gScrVmPub[inst].function_frame->fs.pos = *bufa;
				++game::gScrVmPub[inst].function_count;
				++game::gScrVmPub[inst].function_frame;
			}
			else
			{
				top->u.intValue = (int)*bufa;
			}

			buf = (char *)(bufa + 1);
		}

		game::gFs[inst].pos = stackValue->pos;
		game::gFs[inst].top = top;
		localId = stackValue->localId;
		game::gFs[inst].localId = localId;
		game::Scr_ClearWaitTime(inst, startLocalId);

		assert(game::gScrVmPub[inst].function_count < MAX_VM_STACK_DEPTH);

		function_count = game::gScrVmPub[inst].function_count;

		while ( 1 )
		{
			game::gScrVmPub[inst].function_frame_start[function_count--].fs.localId = localId;
			if ( !function_count )
			{
				break;
			}
			localId = game::GetParentLocalId(inst, localId);
		}

		while ( ++function_count != game::gScrVmPub[inst].function_count )
		{
			game::gScrVmPub[inst].function_frame_start[function_count].fs.localVarCount = game::Scr_AddLocalVars(inst, game::gScrVmPub[inst].function_frame_start[function_count].fs.localId);
		}

		game::gFs[inst].localVarCount = game::Scr_AddLocalVars(inst, game::gFs[inst].localId);
		if ( (unsigned __int8)stackValue->time != (unsigned __int8)(game::gScrVarPub[inst].time & 0xFF) )
		{
			game::Scr_ResetTimeout(inst);
		}

		game::MT_Free((void *)stackValue, stackValue->bufLen, inst);

		assert(game::gScrVmPub[inst].stack[0].type == game::VAR_CODEPOS);
	}

	// Restored
	void Scr_SetThreadWaitTime(game::scriptInstance_t inst, unsigned int startLocalId, unsigned int waitTime)
	{
		game::VariableValueInternal *entryValue;

		entryValue = &game::gScrVarGlob[inst].parentVariables[startLocalId + 1];

		assert(((entryValue->w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL));

		assert(((entryValue->w.type & VAR_MASK) == game::VAR_THREAD) || !game::Scr_GetThreadNotifyName(inst, startLocalId));

		entryValue->w.status &= ~VAR_MASK;
		entryValue->w.status = (unsigned __int8)entryValue->w.status;
		entryValue->w.status |= game::VAR_TIME_THREAD;
		game::gScrVarGlob[inst].parentVariables[startLocalId + 1].w.status |= waitTime << 8;
	}

	// Completed
	void VM_TerminateStack(game::scriptInstance_t inst, unsigned int endLocalId, unsigned int startLocalId, game::VariableStackBuffer *stackValue)
	{
		unsigned int stackId;
		unsigned int localId;
		const char* buf;
		const char *bufa;
		int size;
		int sizea;
		unsigned int parentLocalId;
		game::VariableUnion u;
		game::VariableValue tempValue;

		assert(startLocalId);

		size = stackValue->size;
		localId = stackValue->localId;
		buf = &stackValue->buf[5 * size];

		while ( size )
		{
			bufa = buf - 4;
			u.intValue = *(int*)bufa;
			buf = bufa - 1;
			--size;

			if ( *buf == game::VAR_CODEPOS )
			{
				parentLocalId = game::GetParentLocalId(inst, localId);
				game::Scr_KillThread(inst, localId);
				game::RemoveRefToObject(localId, inst);

				if ( localId == endLocalId )
				{
					assert(startLocalId != localId);

					sizea = size + 1;
					*(char*)buf = 0;

					assert(stackValue->size >= size);

					game::Scr_SetThreadWaitTime(inst, startLocalId, game::gScrVarPub[inst].time);

					assert(u.codePosValue);

					stackValue->pos = (char*)u.codePosValue;
					stackValue->localId = parentLocalId;
					stackValue->size = sizea;
					tempValue.type = game::VAR_STACK;
					tempValue.u.stackValue = stackValue;
					stackId = game::GetNewObjectVariable(inst, startLocalId, game::GetArray(inst, game::GetVariable(inst, game::gScrVarPub[inst].timeArrayId, game::gScrVarPub[inst].time)));
					game::SetNewVariableValue(inst, stackId, &tempValue);
					return;
				}

				localId = parentLocalId;
			}
			else
			{
				game::RemoveRefToValueInternal(inst, (game::VariableType)*(unsigned __int8 *)buf, u);
			}
		}

		assert(localId == endLocalId);

		assert(startLocalId == localId);

		game::Scr_KillThread(inst, localId);
		game::RemoveRefToObject(localId, inst);
		game::MT_Free(stackValue, stackValue->bufLen, inst);
	}

	// Restored
	void Scr_SetThreadNotifyName(game::scriptInstance_t inst, unsigned int startLocalId, unsigned int stringValue)
	{
		game::VariableValueInternal *entryValue;

		entryValue = &game::gScrVarGlob[inst].parentVariables[startLocalId + 1];

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(((entryValue->w.type & VAR_MASK) == game::VAR_THREAD));

		entryValue->w.status &= ~VAR_MASK;
		entryValue->w.status = (unsigned __int8)entryValue->w.status;
		entryValue->w.status |= game::VAR_NOTIFY_THREAD;
		entryValue->w.status |= stringValue << 8;
	}

	// Completed
	void VM_TrimStack(game::scriptInstance_t inst, unsigned int startLocalId, game::VariableStackBuffer *stackValue, int fromEndon)
	{
		unsigned int localId;
		const char *buf;
		const char *bufa;
		int size;
		unsigned int parentLocalId;
		game::VariableUnion u;
		game::VariableValue tempValue;

		assert(startLocalId);

		size = stackValue->size;
		localId = stackValue->localId;
		buf = &stackValue->buf[5 * size];

		while ( size )
		{
			bufa = buf - 4;
			u.intValue = *(int *)bufa;
			buf = bufa - 1;
			--size;
			if ( *buf == game::VAR_CODEPOS )
			{
				if ( game::FindObjectVariable(inst, game::gScrVarPub[inst].pauseArrayId, localId) )
				{
					assert(startLocalId != localId);

					stackValue->localId = localId;
					stackValue->size = size + 1;
					game::Scr_StopThread(inst, localId);
					if ( fromEndon )
					{
						return;
					}

					game::Scr_SetThreadNotifyName(inst, startLocalId, 0);
					stackValue->pos = 0;
					tempValue.type = game::VAR_STACK;
					tempValue.u.stackValue = stackValue;
					game::SetNewVariableValue(inst, game::GetNewVariable(inst, OBJECT_STACK, startLocalId), &tempValue);
					return;
				}

				parentLocalId = game::GetParentLocalId(inst, localId);
				game::Scr_KillThread(inst, localId);
				game::RemoveRefToObject(localId, inst);
				localId = parentLocalId;
			}
			else
			{
				game::RemoveRefToValueInternal(inst, (game::VariableType)*(unsigned __int8 *)buf, u);
			}
		}

		assert(startLocalId == localId);

		if ( fromEndon )
		{
			game::RemoveVariable(OBJECT_STACK, startLocalId, inst);
		}

		game::Scr_KillThread(inst, startLocalId);
		game::RemoveRefToObject(startLocalId, inst);
		game::MT_Free(stackValue, stackValue->bufLen, inst);
	}

	// Restored
	void Scr_DebugTerminateThread(game::scriptInstance_t inst, int topThread)
	{
		// if ( topThread != game::gScrVmPub[inst].function_count )
		{
			game::gScrVmPub[inst].function_frame_start[topThread].fs.pos = game::g_EndPos.get();
		}
	}

	// Completed
	void Scr_TerminateRunningThread(game::scriptInstance_t inst, unsigned int localId)
	{
		int function_count;
		int topThread;
		unsigned int threadId;

		assert(game::gScrVmPub[inst].function_count);

		function_count = game::gScrVmPub[inst].function_count;
		topThread = function_count;

		while ( 1 )
		{
			assert(function_count);

			threadId = game::gScrVmPub[inst].function_frame_start[function_count].fs.localId;
			if ( threadId == localId )
			{
				break;
			}

			--function_count;
			if ( !game::GetSafeParentLocalId(inst, threadId) )
			{
				topThread = function_count;
			}
		}

		while ( topThread >= function_count )
		{
			if ( game::gScrVarPub[inst].developer )
			{
				game::Scr_DebugTerminateThread(inst, topThread);
			}
			else
			{
				game::gScrVmPub[inst].function_frame_start[topThread].fs.pos = game::g_EndPos.get();
			}
			--topThread;
		}
	}

	// Restored
	unsigned int Scr_GetThreadWaitTime(game::scriptInstance_t inst, unsigned int startLocalId)
	{
		assert((game::gScrVarGlob[inst].parentVariables[startLocalId + 1].w.status & VAR_STAT_MASK) == VAR_STAT_EXTERNAL);

		assert((game::gScrVarGlob[inst].parentVariables[startLocalId + 1].w.type & VAR_MASK) == game::VAR_TIME_THREAD);

		return game::gScrVarGlob[inst].parentVariables[startLocalId + 1].w.status >> 8;
	}

	const char* Scr_GetStackThreadPos([[maybe_unused]] game::scriptInstance_t inst, [[maybe_unused]] unsigned int endLocalId, [[maybe_unused]] game::VariableStackBuffer* stackValue, [[maybe_unused]] bool killThread)
	{
		assert(game::gScrVarPub[inst].developer);

		return 0;
	}

	// Completed
	void Scr_TerminateWaitThread(game::scriptInstance_t inst, unsigned int localId, unsigned int startLocalId)
	{
		game::VariableStackBuffer *stackValue;
		unsigned int stackId;
		unsigned int time;
		unsigned int id;

		time = game::Scr_GetThreadWaitTime(inst, startLocalId);
		game::Scr_ClearWaitTime(inst, startLocalId);
		id = game::FindObject(inst, game::FindVariable(time, game::gScrVarPub[inst].timeArrayId, inst));
		stackId = game::FindObjectVariable(inst, id, startLocalId);

		assert(stackId);

		assert(game::GetValueType(inst, stackId) == game::VAR_STACK);

		stackValue = game::GetVariableValueAddress(inst, stackId)->u.stackValue;
		if ( game::gScrVarPub[inst].developer )
		{
			game::Scr_GetStackThreadPos(inst, localId, stackValue, 1);
		}

		game::RemoveObjectVariable(inst, id, startLocalId);
		if ( !game::GetArraySize(inst, id) && time != game::gScrVarPub[inst].time )
		{
			game::RemoveVariable(time, game::gScrVarPub[inst].timeArrayId, inst);
		}

		game::VM_TerminateStack(inst, localId, startLocalId, stackValue);
	}

	// Restored
	unsigned int Scr_GetSelf(game::scriptInstance_t inst, unsigned int threadId)
	{
		assert((game::gScrVarGlob[inst].parentVariables[threadId + 1].w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(((game::gScrVarGlob[inst].parentVariables[threadId + 1].w.type & VAR_MASK) >= game::VAR_THREAD) &&
			   ((game::gScrVarGlob[inst].parentVariables[threadId + 1].w.type & VAR_MASK) <= game::VAR_CHILD_THREAD));

		return game::gScrVarGlob[inst].parentVariables[threadId + 1].u.o.u.self;
	}

	// Completed
	void Scr_CancelWaittill(game::scriptInstance_t inst, unsigned int startLocalId)
	{
		unsigned int selfNameId;
		unsigned int selfId;

		selfId = game::Scr_GetSelf(inst, startLocalId);
		selfNameId = game::FindObject(inst, game::FindObjectVariable(inst, game::gScrVarPub[inst].pauseArrayId, selfId));
		game::VM_CancelNotify(inst, game::GetVariableValueAddress(inst, game::FindObjectVariable(inst, selfNameId, startLocalId))->u.pointerValue, startLocalId);
		game::RemoveObjectVariable(inst, selfNameId, startLocalId);
		if ( !game::GetArraySize(inst, selfNameId) )
		{
			game::RemoveObjectVariable(inst, game::gScrVarPub[inst].pauseArrayId, selfId);
		}
	}

	// Completed
	void Scr_TerminateWaittillThread(game::scriptInstance_t inst, unsigned int localId, unsigned int startLocalId)
	{
		game::VariableStackBuffer *stackValue;
		unsigned int stringValue;
		unsigned int stackId;
		unsigned int stackIda;
		unsigned int selfNameId;
		unsigned int notifyListId;
		unsigned int notifyNameListId;
		unsigned int notifyListOwnerId;
		unsigned int selfId;

		stringValue = game::Scr_GetThreadNotifyName(inst, startLocalId);
		if ( stringValue )
		{
			selfId = game::Scr_GetSelf(inst, startLocalId);
			selfNameId = game::FindObject(inst, game::FindObjectVariable(inst, game::gScrVarPub[inst].pauseArrayId, selfId));
			notifyListOwnerId = game::GetVariableValueAddress(inst, game::FindObjectVariable(inst, selfNameId, startLocalId))->u.intValue;
			notifyListId = game::FindObject(inst, game::FindVariable(OBJECT_STACK, notifyListOwnerId, inst));
			notifyNameListId = game::FindObject(inst, game::FindVariable(stringValue, notifyListId, inst));
			stackId = game::FindObjectVariable(inst, notifyNameListId, startLocalId);

			assert(stackId);

			assert(game::GetValueType(inst, stackId) == game::VAR_STACK);

			stackValue = game::GetVariableValueAddress(inst, stackId)->u.stackValue;

			if ( game::gScrVarPub[inst].developer )
			{
				game::Scr_GetStackThreadPos(inst, localId, stackValue, 1);
			}

			game::VM_CancelNotifyInternal(inst, notifyNameListId, notifyListOwnerId, startLocalId, notifyListId, stringValue);
			game::RemoveObjectVariable(inst, selfNameId, startLocalId);

			if ( !game::GetArraySize(inst, selfNameId) )
			{
				game::RemoveObjectVariable(inst, game::gScrVarPub[inst].pauseArrayId, selfId);
			}
		}
		else
		{
			stackIda = game::FindVariable(OBJECT_STACK, startLocalId, inst);

			assert(stackIda);

			assert(game::GetValueType(inst, stackIda) == game::VAR_STACK);

			stackValue = game::GetVariableValueAddress(inst, stackIda)->u.stackValue;
			if ( game::gScrVarPub[inst].developer )
			{
				game::Scr_GetStackThreadPos(inst, localId, stackValue, 1);
			}
			game::RemoveVariable(OBJECT_STACK, startLocalId, inst);
		}

		game::VM_TerminateStack(inst, localId, startLocalId, stackValue);
	}

	// Completed
	void Scr_TerminateThread(unsigned int localId, game::scriptInstance_t inst)
	{
		unsigned int startLocalId;

		startLocalId = game::GetStartLocalId(localId, inst);
		switch ( game::GetObjectType(inst, startLocalId) )
		{
		case game::VAR_THREAD:
			game::Scr_TerminateRunningThread(inst, localId);
			break;
		case game::VAR_NOTIFY_THREAD:
			game::Scr_TerminateWaittillThread(inst, localId, startLocalId);
			break;
		case game::VAR_TIME_THREAD:
			game::Scr_TerminateWaitThread(inst, localId, startLocalId);
			break;
		default:
			//assertMsg("unreachable");
			assert(false);
			break;
		}
	}

	// Restored
	unsigned int GetVariableKeyObject(game::scriptInstance_t inst, unsigned int id)
	{
		game::VariableValueInternal* entryValue;

		entryValue = &game::gScrVarGlob[inst].childVariables[id];

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(!IsObject(entryValue));

		return (game::gScrVarGlob[inst].childVariables[id].w.status >> 8) - 0x10000;
	}

	// Restored
	int MT_Realloc(game::scriptInstance_t inst, int oldNumBytes, int newNumbytes)
	{
		int size;

		size = game::MT_GetSize(oldNumBytes, inst);
		return size >= game::MT_GetSize(newNumbytes, inst);
	}

	// Completed
	void VM_Notify(game::scriptInstance_t inst, int notifyListOwnerId, unsigned int stringValue, game::VariableValue *top)
	{
		game::VariableStackBuffer *stackValue;
		unsigned int notifyListIndex;
		game::VariableValue tempValue2;
		game::VariableValue tempValue3;
		unsigned int stackId;
		unsigned int startLocalId;
		game::VariableStackBuffer *newStackValue;
		game::VariableValue tempValue5;
		game::VariableValue *currentValue;
		char *buf;
		unsigned int selfNameId;
		int size;
		int len;
		unsigned int notifyListId;
		unsigned int notifyNameListId;
		int newSize;
		int bufLen;
		bool bNoStack;
		game::VariableUnion *tempValue;
		unsigned int selfId;
		unsigned int notifyListEntry;

		notifyListId = game::FindVariable(OBJECT_STACK, notifyListOwnerId, inst);
		if ( notifyListId )
		{
			notifyListId = game::FindObject(inst, notifyListId);

			assert(notifyListId);

			notifyNameListId = game::FindVariable(stringValue, notifyListId, inst);
			if ( notifyNameListId )
			{
				notifyNameListId = game::FindObject(inst, notifyNameListId);

				assert(notifyNameListId);

				game::AddRefToObject(inst, notifyNameListId);

				assert(!game::gScrVarPub[inst].evaluate);

				game::gScrVarPub[inst].evaluate = 1;
				notifyListEntry = notifyNameListId;

				while ( 1 )
				{
					notifyListIndex = game::FindLastSibling(notifyListEntry, inst);
				next:
					if ( !notifyListIndex )
					{
						break;
					}

					notifyListEntry = game::gScrVarGlob[inst].childVariables[notifyListIndex].hash.id;

					assert(notifyListEntry);

					startLocalId = game::GetVariableKeyObject(inst, notifyListEntry);
					selfId = game::Scr_GetSelf(inst, startLocalId);
					selfNameId = game::FindObject(inst, game::FindObjectVariable(inst, game::gScrVarPub[inst].pauseArrayId, selfId));

					if ( game::GetValueType(inst, notifyListEntry) )
					{
						assert(game::GetValueType(inst, notifyListEntry) == game::VAR_STACK);

						tempValue = &game::GetVariableValueAddress(inst, notifyListEntry)->u;
						stackValue = tempValue->stackValue;
						if ( *((char *)stackValue->pos - 1) == game::OP_waittillmatch )
						{
							size = *stackValue->pos;

							assert(size >= 0);

							assert(size <= stackValue->size);

							buf = &stackValue->buf[5 * (stackValue->size - size)];
							for ( currentValue = top;
								size;
								--currentValue )
							{
								assert(currentValue->type != game::VAR_CODEPOS);

								if ( currentValue->type == game::VAR_PRECODEPOS )
								{
									notifyListIndex = game::gScrVarGlob[inst].childVariables[notifyListIndex].hash.u.prev;
									goto next;
								}

								--size;
								tempValue3.type = (game::VariableType)(unsigned char)*buf;

								assert(tempValue3.type != game::VAR_CODEPOS);

								if ( tempValue3.type == game::VAR_PRECODEPOS )
								{
									break;
								}

								tempValue3.u.intValue = *(int*)++buf;
								buf += 4;
								game::AddRefToValue(inst, tempValue3.type, tempValue3.u);
								tempValue2.u.intValue = currentValue->u.intValue;
								tempValue2.type = currentValue->type;
								game::AddRefToValue(inst, currentValue->type, tempValue2.u);
								game::Scr_EvalEquality(&tempValue3, inst, &tempValue2);

								if ( game::gScrVarPub[inst].error_message )
								{
									game::RuntimeError(inst, stackValue->pos, *stackValue->pos - size + 3, game::gScrVarPub[inst].error_message, game::gScrVmGlob[inst].dialog_error_message);
									game::Scr_ClearErrorMessage(inst);
									notifyListIndex = game::gScrVarGlob[inst].childVariables[notifyListIndex].hash.u.prev;
									goto next;
								}

								assert(tempValue3.type == game::VAR_INTEGER);

								if ( !tempValue3.u.intValue )
								{
									notifyListIndex = game::gScrVarGlob[inst].childVariables[notifyListIndex].hash.u.prev;
									goto next;
								}
							}
							++stackValue->pos;
							bNoStack = 1;
						}
						else
						{
							assert(top->type != game::VAR_CODEPOS);

							bNoStack = top->type == game::VAR_PRECODEPOS;
						}

						tempValue5.type = game::VAR_STACK;
						tempValue5.u.stackValue = stackValue;
						stackId = game::GetNewObjectVariable(inst, startLocalId, game::GetArray(inst, game::GetVariable(inst, game::gScrVarPub[inst].timeArrayId, game::gScrVarPub[inst].time)));
						game::SetNewVariableValue(inst, stackId, &tempValue5);
						tempValue = &game::GetVariableValueAddress(inst, stackId)->u;

						game::VM_CancelNotifyInternal(inst, notifyNameListId, notifyListOwnerId, startLocalId, notifyListId, stringValue);

						game::RemoveObjectVariable(inst, selfNameId, startLocalId);
						if ( !game::GetArraySize(inst, selfNameId) )
						{
							game::RemoveObjectVariable(inst, game::gScrVarPub[inst].pauseArrayId, selfId);
						}

						game::Scr_SetThreadWaitTime(inst, startLocalId, game::gScrVarPub[inst].time);
						if ( bNoStack )
						{
							notifyListEntry = notifyNameListId;
						}
						else
						{
							assert((top->type != game::VAR_PRECODEPOS));

							assert((top->type != game::VAR_CODEPOS));

							size = stackValue->size;
							newSize = size;
							currentValue = top;
							do
							{
								++newSize;
								--currentValue;

								assert((currentValue->type != game::VAR_CODEPOS));
							}
							while ( currentValue->type != game::VAR_PRECODEPOS );

							assert(newSize >= 0 && newSize < VARIABLELIST_CHILD_SIZE);

							len = 5 * size;
							bufLen = 5 * newSize + 11;

							if ( !game::MT_Realloc(inst, stackValue->bufLen, bufLen) )
							{
								newStackValue = (game::VariableStackBuffer *)game::MT_Alloc(bufLen, inst);
								newStackValue->bufLen = bufLen;
								newStackValue->pos = stackValue->pos;
								newStackValue->localId = stackValue->localId;
								memcpy(newStackValue->buf, stackValue->buf, len);
								game::MT_Free(stackValue, stackValue->bufLen, inst);
								stackValue = newStackValue;
								tempValue->stackValue = newStackValue;
							}

							stackValue->size = newSize;
							buf = &stackValue->buf[len];
							newSize -= size;

							assert(newSize);

							do
							{
								++currentValue;
								game::AddRefToValue(inst, currentValue->type, currentValue->u);

								assert((unsigned)currentValue->type < game::VAR_COUNT);

								*buf++ = currentValue->type;
								*(int *)buf = currentValue->u.intValue;
								buf += 4;
								--newSize;
							}
							while ( newSize );

							assert(buf - (const char*)stackValue == bufLen);

							notifyListEntry = notifyNameListId;
						}
					}
					else
					{
						game::VM_CancelNotifyInternal(inst, notifyNameListId, notifyListOwnerId, startLocalId, notifyListId, stringValue);
						game::Scr_KillEndonThread(inst, startLocalId);
						game::RemoveObjectVariable(inst, selfNameId, startLocalId);

						if ( !game::GetArraySize(inst, selfNameId) )
						{
							game::RemoveObjectVariable(inst, game::gScrVarPub[inst].pauseArrayId, selfId);
						}

						game::Scr_TerminateThread(selfId, inst);
						notifyListEntry = notifyNameListId;
					}
				}
				game::RemoveRefToObject(notifyNameListId, inst);

				assert(game::gScrVarPub[inst].evaluate);

				game::gScrVarPub[inst].evaluate = 0;
			}
		}
	}

	//Restored function
	void SL_CheckExists([[maybe_unused]] game::scriptInstance_t inst, [[maybe_unused]] unsigned int stringValue)
	{

	}

	// Completed
	void Scr_NotifyNum_Internal(game::scriptInstance_t inst, int entnum, unsigned int classnum, unsigned int stringValue, unsigned int paramcount)
	{
		game::VariableValue *startTop;
		int type;
		unsigned int id;
		unsigned int paramcounta;

		game::SL_CheckExists(inst, stringValue);

		assert(game::gScrVarPub[inst].timeArrayId);

		assert(paramcount <= game::gScrVmPub[inst].inparamcount);

		game::Scr_ClearOutParams(inst);
		startTop = &game::gScrVmPub[inst].top[-paramcount];
		paramcounta = game::gScrVmPub[inst].inparamcount - paramcount;

		// pluto
		if (classnum == -1)
		{
			id = entnum; // this is for level notify
		}
		//
		else
		{
			id = game::FindEntityId(classnum, entnum, inst);
		}

		if ( id )
		{
			type = startTop->type;
			startTop->type = game::VAR_PRECODEPOS;
			game::gScrVmPub[inst].inparamcount = 0;
			game::VM_Notify(inst, id, stringValue, game::gScrVmPub[inst].top);
			startTop->type = (game::VariableType)type;
		}

		while ( game::gScrVmPub[inst].top != startTop )
		{
			game::RemoveRefToValueInternal(inst, game::gScrVmPub[inst].top->type, game::gScrVmPub[inst].top->u);
			--game::gScrVmPub[inst].top;
		}

		game::gScrVmPub[inst].inparamcount = paramcounta;

		assert(!game::gScrVmPub[inst].outparamcount);

		game::SL_CheckExists(inst, stringValue);
	}

	// Completed
	void Scr_CancelNotifyList(unsigned int notifyListOwnerId, game::scriptInstance_t inst)
	{
		game::VariableStackBuffer* stackValuea;
		game::VariableStackBuffer *stackValue;
		game::VariableValueInternal_u* valueAddress;
		unsigned int stackId;
		unsigned int stackIda;
		unsigned int startLocalId;
		unsigned int selfStartLocalId;
		unsigned int notifyListId;
		unsigned int notifyListIda;
		unsigned int notifyNameListId;
		unsigned int notifyNameListIda;
		unsigned int selfLocalId;

		while ( 1 )
		{
			notifyListId = game::FindVariable(OBJECT_STACK, notifyListOwnerId, inst);
			if ( !notifyListId )
			{
				break;
			}

			notifyListIda = game::FindObject(inst, notifyListId);

			assert(notifyListIda);

			notifyNameListId = game::FindFirstSibling(inst, notifyListIda);
			if ( !notifyNameListId )
			{
				break;
			}

			notifyNameListIda = game::FindObject(inst, notifyNameListId);

			assert(notifyNameListIda);

			stackId = game::FindFirstSibling(inst, notifyNameListIda);
			if ( !stackId )
			{
				break;
			}

			startLocalId = game::GetVariableKeyObject(inst, stackId);

			assert(startLocalId);

			if ( game::GetValueType(inst, stackId) == game::VAR_STACK )
			{
				stackValuea = game::GetVariableValueAddress(inst, stackId)->u.stackValue;
				game::Scr_CancelWaittill(inst, startLocalId);
				game::VM_TrimStack(inst, startLocalId, stackValuea, 0);
			}
			else
			{
				game::AddRefToObject(inst, startLocalId);
				game::Scr_CancelWaittill(inst, startLocalId);
				selfLocalId = game::Scr_GetSelf(inst, startLocalId);
				selfStartLocalId = game::GetStartLocalId(selfLocalId, inst);
				stackIda = game::FindVariable(OBJECT_STACK, selfStartLocalId, inst);

				if ( stackIda )
				{
					assert(!game::Scr_GetThreadNotifyName(inst, selfStartLocalId));

					assert(game::GetValueType(inst, stackIda) == game::VAR_STACK);

					valueAddress = game::GetVariableValueAddress(inst, stackIda);

					stackValue = valueAddress->u.stackValue;

					assert(!stackValue->pos);

					game::VM_TrimStack(inst, selfStartLocalId, stackValue, 1);
				}

				game::Scr_KillEndonThread(inst, startLocalId);
				game::RemoveRefToEmptyObject(inst, startLocalId);
			}
		}
	}

	// Decomp Status: Tested, Completed
	void VM_TerminateTime(game::scriptInstance_t inst, unsigned int timeId)
	{
		game::VariableStackBuffer* stackValue;
		unsigned int stackId;
		unsigned int startLocalId;

		assert(timeId);

		assert(!game::gScrVmPub[inst].function_count);

		game::AddRefToObject(inst, timeId);

		while (1)
		{
			stackId = game::FindFirstSibling(inst, timeId);

			if (!stackId)
			{
				break;
			}

			startLocalId = game::GetVariableKeyObject(inst, stackId);

			assert(startLocalId);

			assert(game::GetValueType(inst, stackId) == game::VAR_STACK);

			stackValue = game::GetVariableValueAddress(inst, stackId)->u.stackValue;
			game::RemoveObjectVariable(inst, timeId, startLocalId);
			game::Scr_ClearWaitTime(inst, startLocalId);
			game::VM_TerminateStack(inst, startLocalId, startLocalId, stackValue);
		}

		game::RemoveRefToObject(timeId, inst);
	}

	// Decomp Status: Tested, Completed
	void VM_Resume(game::scriptInstance_t inst, unsigned int timeId)
	{
		int stackId;
		unsigned int startLocalId;
		int id;
		game::VariableStackBuffer *stackValue;

		assert(game::gScrVmPub[inst].top == game::gScrVmPub[inst].stack);

		game::Scr_ResetTimeout(inst);
		game::AddRefToObject(inst, timeId);
		game::gFs[inst].startTop = game::gScrVmPub[inst].stack;
		game::gThreadCount[inst] = 0;

		while ( true )
		{
			assert(!game::gScrVarPub[inst].error_index);

			assert(!game::gScrVmPub[inst].outparamcount);

			assert(!game::gScrVmPub[inst].inparamcount);

			assert(!game::gScrVmPub[inst].function_count);

			assert(game::gScrVmPub[inst].localVars == game::gScrVmGlob[inst].localVarsStack - 1);

			assert(game::gFs[inst].startTop == &game::gScrVmPub[inst].stack[0]);

			assert(!game::gThreadCount[inst]);

			stackId = game::FindFirstSibling(inst, timeId);

			if (!stackId)
			{
				break;
			}

			startLocalId = game::GetVariableKeyObject(inst, stackId);

			assert(startLocalId);

			assert(game::GetValueType(inst, stackId) == game::VAR_STACK);
			
			stackValue = game::GetVariableValueAddress(inst, stackId)->u.stackValue;
			game::RemoveObjectVariable(inst, timeId, startLocalId);
			game::VM_UnarchiveStack(inst, startLocalId, stackValue);
			id = game::VM_ExecuteInternal(inst);
			game::RemoveRefToObject(id, inst);
			game::RemoveRefToValue(inst, &game::gScrVmPub[inst].stack[1]);
		}

		game::RemoveRefToObject(timeId, inst);
		game::ClearVariableValue(inst, game::gScrVarPub[inst].tempVariable);
		game::gScrVmPub[inst].top = game::gScrVmPub[inst].stack;
	}

	// Decomp Status: Tested, Completed
	unsigned int VM_Execute(game::scriptInstance_t inst, unsigned int localId, const char *pos, unsigned int paramcount)
	{
		game::VariableValue *startTop;
		game::VariableType type;
		int thread_count_backup;
		game::function_stack_t fs_backup[game::SCRIPT_INSTANCE_MAX];
		unsigned int paramcounta;

		assert(paramcount <= game::gScrVmPub[inst].inparamcount);

		game::Scr_ClearOutParams(inst);
		startTop = &game::gScrVmPub[inst].top[-paramcount];
		paramcounta = game::gScrVmPub[inst].inparamcount - paramcount;
		startTop = &game::gScrVmPub[inst].top[-paramcount];
		if (game::gScrVmPub[inst].function_count >= MAX_VM_STACK_DEPTH)
		{
			game::Scr_KillThread(inst, localId);
			game::gScrVmPub[inst].inparamcount = paramcounta + 1;

			assert(!game::gScrVmPub[inst].outparamcount);

			while (paramcounta)
			{
				game::RemoveRefToValue(inst, game::gScrVmPub[inst].top);
				--game::gScrVmPub[inst].top;
				--paramcounta;
			}

			++game::gScrVmPub[inst].top;
			game::gScrVmPub[inst].top->type = game::VAR_UNDEFINED;
			game::RuntimeError(inst, pos, 0, "script stack overflow (too many embedded function calls)", 0);
		}
		else
		{
			fs_backup[inst] = game::gFs[inst];
			fs_backup[inst].startTop = game::gFs[inst].startTop;
			thread_count_backup = game::gThreadCount[inst];
			game::gFs[inst].localId = localId;
			game::gFs[inst].startTop = startTop;

			if (game::gScrVmPub[inst].function_count)
			{
				++game::gScrVmPub[inst].function_count;
				++game::gScrVmPub[inst].function_frame;
				game::gScrVmPub[inst].function_frame->fs.localId = 0;
			}

			game::gScrVmPub[inst].function_frame->fs.pos = pos;
			++game::gScrVmPub[inst].function_count;
			++game::gScrVmPub[inst].function_frame;
			game::gScrVmPub[inst].function_frame->fs.localId = localId;
			type = startTop->type;
			startTop->type = game::VAR_PRECODEPOS;
			game::gScrVmPub[inst].inparamcount = 0;
			game::gFs[inst].top = game::gScrVmPub[inst].top;
			game::gFs[inst].pos = pos;
			game::gFs[inst].localVarCount = 0;
			game::gThreadCount[inst] = 0;
			localId = game::VM_ExecuteInternal(inst);
			game::gFs[inst] = fs_backup[inst];
			game::gFs[inst].startTop = fs_backup[inst].startTop;
			game::gThreadCount[inst] = thread_count_backup;
			startTop->type = type;
			game::gScrVmPub[inst].top = startTop + 1;
			game::gScrVmPub[inst].inparamcount = paramcounta + 1;

			assert(!game::gScrVmPub[inst].outparamcount);

			game::ClearVariableValue(inst, game::gScrVarPub[inst].tempVariable);

			if ( game::gScrVmPub[inst].function_count )
			{
				--game::gScrVmPub[inst].function_count;
				--game::gScrVmPub[inst].function_frame;
				return localId;
			}
		}
		return localId;
	}

	// Decomp Status: Tested, Completed
	unsigned short Scr_ExecThread(game::scriptInstance_t inst, unsigned int handle, unsigned int paramCount)
	{
		unsigned int objId;
		unsigned short threadId;
		const char* pos;

		// pluto
		if (game::plutonium::scr_execthread_update_codepos_func != nullptr)
		{
			game::plutonium::scr_execthread_update_codepos_func(inst, inst, &handle, &handle);
		}
		//

		pos = &game::gScrVarPub[inst].programBuffer[handle];

		if ( !game::gScrVmPub[inst].function_count )
		{
			assert(game::gScrVmPub[inst].localVars == game::gScrVmGlob[inst].localVarsStack - 1);

			game::Scr_ResetTimeout(inst);
		}

		assert(game::gScrVarPub[inst].timeArrayId);

		assert(handle);

		game::Scr_IsInOpcodeMemory(inst, pos);
		game::AddRefToObject(inst, game::gScrVarPub[inst].levelId);
		objId = game::AllocThread(inst, game::gScrVarPub[inst].levelId);
		threadId = game::VM_Execute(inst, objId, pos, paramCount);

		game::RemoveRefToValue(inst, game::gScrVmPub[inst].top);
		game::gScrVmPub[inst].top->type = game::VAR_UNDEFINED;

		--game::gScrVmPub[inst].top;
		--game::gScrVmPub[inst].inparamcount;

		if (!game::gScrVmPub[inst].function_count)
		{
			assert(game::gScrVmPub[inst].localVars == game::gScrVmGlob[inst].localVarsStack - 1);
		}

		return threadId;
	}

	// Decomp Status: Tested, Completed
	unsigned short Scr_ExecEntThreadNum(game::scriptInstance_t inst, int entNum, unsigned int handle, int numParams, unsigned int clientNum)
	{
		unsigned int threadId;
		unsigned short thread;
		unsigned int objId;
		const char* pos;
		game::classNum_e classnum = game::CLASS_NUM_ENTITY;

		// pluto
		if (game::plutonium::scr_execentthread_update_codepos_func != nullptr)
		{
			game::plutonium::scr_execentthread_update_codepos_func(inst, &handle);
		}
		//

		pos = &game::gScrVarPub[inst].programBuffer[handle];

		if ( !game::gScrVmPub[inst].function_count )
		{
			assert(game::gScrVmPub[inst].localVars == game::gScrVmGlob[inst].localVarsStack - 1);

			game::Scr_ResetTimeout(inst);
		}

		assert(game::gScrVarPub[inst].timeArrayId);

		assert(handle);
		
		assert(game::Scr_IsInOpcodeMemory(inst, pos));

		objId = game::Scr_GetEntityId(entNum, inst, classnum, clientNum);
		game::AddRefToObject(inst, objId);
		threadId = game::AllocThread(inst, objId);
		thread = game::VM_Execute(inst, threadId, &game::gScrVarPub[inst].programBuffer[handle], numParams);
		game::RemoveRefToValue(inst, game::gScrVmPub[inst].top);
		game::gScrVmPub[inst].top->type = game::VAR_UNDEFINED;
		--game::gScrVmPub[inst].top;
		--game::gScrVmPub[inst].inparamcount;

		if (!game::gScrVmPub[inst].function_count)
		{
			assert(game::gScrVmPub[inst].localVars == game::gScrVmGlob[inst].localVarsStack - 1);
		}

		return thread;
	}

	// Decomp Status: Tested, Completed
	void Scr_AddExecThread(game::scriptInstance_t inst, unsigned int handle)
	{
		unsigned int threadId;
		unsigned int thread;
		unsigned int paramcount = 0;

		// pluto
		if (game::plutonium::scr_addexecthread_update_codepos_func != nullptr)
		{
			game::plutonium::scr_addexecthread_update_codepos_func(inst, &handle);
		}
		//

		if ( !game::gScrVmPub[inst].function_count )
		{
			assert(game::gScrVmPub[inst].localVars == game::gScrVmGlob[inst].localVarsStack - 1);

			game::Scr_ResetTimeout(inst);
		}

		assert(game::gScrVarPub[inst].timeArrayId);

		assert(game::Scr_IsInOpcodeMemory(inst, &game::gScrVarPub[inst].programBuffer[handle]));

		game::AddRefToObject(inst, game::gScrVarPub[inst].levelId);
		threadId = game::AllocThread(inst, game::gScrVarPub[inst].levelId);
		thread = game::VM_Execute(inst, threadId, &game::gScrVarPub[inst].programBuffer[handle], paramcount);
		game::RemoveRefToObject(thread, inst);
		++game::gScrVmPub[inst].outparamcount;
		--game::gScrVmPub[inst].inparamcount;

		if (!game::gScrVmPub[inst].function_count)
		{
			assert(game::gScrVmPub[inst].localVars == game::gScrVmGlob[inst].localVarsStack - 1);
		}
	}

	// Decomp Status: Tested, Completed
	void VM_SetTime(game::scriptInstance_t inst)
	{
		int id;

		assert((game::gScrVarPub[inst].time & VAR_NAME_LOW_MASK) == 0);

		if (game::gScrVarPub[inst].timeArrayId)
		{
			id = game::FindVariable(game::gScrVarPub[inst].time, game::gScrVarPub[inst].timeArrayId, inst);
			if ( id )
			{
				game::VM_Resume(inst, game::FindObject(inst, id));
				game::SafeRemoveVariable(game::gScrVarPub[inst].time, game::gScrVarPub[inst].timeArrayId, inst);
			}
		}
	}

	// Decomp Status: Tested, Completed
	void Scr_InitSystem(game::scriptInstance_t inst)
	{
		assert(!game::gScrVarPub[inst].timeArrayId);

		//assert(!game::gScrVarPub[inst].ext_threadcount);

		//assert(!game::gScrVarPub[inst].varUsagePos);

		game::gScrVarPub[inst].timeArrayId = game::AllocObject(inst);

		assert(!game::gScrVarPub[inst].pauseArrayId);

		game::gScrVarPub[inst].pauseArrayId = game::Scr_AllocArray(inst);

		assert(!game::gScrVarPub[inst].levelId);

		game::gScrVarPub[inst].levelId = game::AllocObject(inst);

		game::gScrVarPub[inst].time = 0;

		assert(!game::gScrVarPub[inst].animId);

		game::gScrVarPub[inst].animId = game::AllocObject(inst);

		assert(!game::gScrVarPub[inst].freeEntList);

		game::g_script_error_level[inst] = -1;
	}

	//Restored function
	bool Scr_IsStackClear(game::scriptInstance_t inst)
	{
		return game::gScrVmPub[inst].top == game::gScrVmPub[inst].stack;
	}

	// Decomp Status: Tested, Completed
	void Scr_ShutdownSystem(game::scriptInstance_t inst, int bComplete)
	{
		int functionCount;
		int id;
		unsigned int ida;
		unsigned int idb;
		unsigned int parentId;

		game::Scr_FreeEntityList(inst);
		if ( game::gScrVarPub[inst].timeArrayId )
		{
			game::Scr_FreeGameVariable(inst, bComplete);
			functionCount = game::gScrVmPub[inst].function_count;
			game::gScrVmPub[inst].function_count = 0;

			for (id = game::FindFirstSibling(inst, game::gScrVarPub[inst].timeArrayId); id; id = game::FindNextSibling(inst, id))
			{
				game::VM_TerminateTime(inst, game::FindObject(inst, id));
			}

			while (true)
			{
				ida = game::FindFirstSibling(inst, game::gScrVarPub[inst].pauseArrayId);
				if (!ida)
				{
					break;
				}

				idb = game::FindFirstSibling(inst, game::FindObject(inst, ida));

				assert(idb);

				parentId = game::GetVariableValueAddress(inst, idb)->u.stringValue;
				game::AddRefToObject(inst, parentId);
				game::Scr_CancelNotifyList(parentId, inst);
				game::RemoveRefToObject(parentId, inst);
			}

			assert(game::gScrVarPub[inst].levelId);

			game::ClearObject(game::gScrVarPub[inst].levelId, inst);
			game::RemoveRefToEmptyObject(inst, game::gScrVarPub[inst].levelId);
			game::gScrVarPub[inst].levelId = 0;

			assert(game::gScrVarPub[inst].animId);

			game::ClearObject(game::gScrVarPub[inst].animId, inst);
			game::RemoveRefToEmptyObject(inst, game::gScrVarPub[inst].animId);
			game::gScrVarPub[inst].animId = 0;

			assert(game::gScrVarPub[inst].timeArrayId);

			game::ClearObject(game::gScrVarPub[inst].timeArrayId, inst);
			game::RemoveRefToEmptyObject(inst, game::gScrVarPub[inst].timeArrayId);
			game::gScrVarPub[inst].timeArrayId = 0;

			assert(game::gScrVarPub[inst].pauseArrayId);

			assert(!game::GetArraySize(inst, game::gScrVarPub[inst].pauseArrayId));

			game::ClearObject(game::gScrVarPub[inst].pauseArrayId, inst);
			game::RemoveRefToEmptyObject(inst, game::gScrVarPub[inst].pauseArrayId);
			game::gScrVarPub[inst].pauseArrayId = 0;

			assert(!game::gScrVarPub[inst].freeEntList);

			game::Scr_FreeObjects(inst);

			if ( functionCount )
			{
				game::gScrVarPub[inst].bInited = 0;
				game::Scr_Init(inst);
			}
			else
			{
				//assert(!game::gScrVarPub[inst].ext_threadcount);

				assert(game::Scr_IsStackClear(inst));
			}
		}
	}

	// Decomp Status: Tested, Completed
	bool Scr_IsSystemActive()
	{
		game::scriptInstance_t inst = game::SCRIPTINSTANCE_SERVER;

		return game::gScrVarPub[inst].timeArrayId && !game::gScrVarPub[inst].error_message;
	}

	// Decomp Status: Tested, Completed
	int Scr_GetInt(game::scriptInstance_t inst, unsigned int index)
	{
		game::VariableValue *value;
		const char *errorMsg;

		if ( index < game::gScrVmPub[inst].outparamcount )
		{
			value = &game::gScrVmPub[inst].top[-index];
			if ( value->type == game::VAR_INTEGER )
			{
				return value->u.intValue;
			}

			game::gScrVarPub[inst].error_index = index + 1;
			errorMsg = game::va("type %s is not an int", game::var_typename[value->type]);
			game::Scr_Error(errorMsg, inst, false);
		}

		errorMsg = game::va("parameter %d does not exist", index + 1);
		game::Scr_Error(errorMsg, inst, false);
		return 0;
	}

	// Decomp Status: Tested, Completed
	game::scr_anim_s Scr_GetAnim(unsigned int index, game::XAnimTree_s *animTreeInputForValidation)
	{
		game::VariableValue *value;
		game::scr_anim_s result;
		game::XAnim_s *animTreeAnimPtr;
		game::XAnim_s *animPtr;
		const char *debugMsg;
		const char *errorMsg;
		game::scriptInstance_t inst = game::SCRIPTINSTANCE_SERVER;
		game::animUserInstance_t user = game::ANIM_USER_SERVER;

		result.u.linkPointer = nullptr;

		if ( index >= game::gScrVmPub[inst].outparamcount )
		{
			errorMsg = game::va("parameter %d does not exist", index + 1);
			game::Scr_Error(errorMsg, inst, false);
			return result;
		}

		value = &game::gScrVmPub[inst].top[-index];
		if (value->type != game::VAR_ANIMATION )
		{
			game::gScrVarPub[inst].error_message = (char*)game::va("type %s is not an anim", game::var_typename[value->type]);
			game::RemoveRefToValueInternal(inst, value->type, value->u);
			value->type = game::VAR_UNDEFINED;
			game::gScrVarPub[inst].error_index = index + 1;
			game::Scr_ErrorInternal(inst);
			return result;
		}

		result.u.linkPointer = (const char*)value->u.intValue;
		if ( !animTreeInputForValidation )
		{
			return result;
		}

		animTreeAnimPtr = animTreeInputForValidation->anims;
		animPtr = game::gScrAnimPub[inst].xanim_lookup[user][(unsigned int)result.u.linkPointer >> 16].anims;
		if ( animPtr == animTreeAnimPtr )
		{
			return result;
		}

		debugMsg = game::XAnimGetAnimDebugName(value->u.intValue, animPtr);
		game::gScrVarPub[inst].error_message = (char*)game::va("anim '%s' in animtree '%s' does not belong to the entity's animtree '%s'", debugMsg, animTreeAnimPtr->debugName, animTreeAnimPtr->debugName);
		game::RemoveRefToValueInternal(game::SCRIPTINSTANCE_SERVER, value->type, value->u);
		value->type = game::VAR_UNDEFINED;
		game::gScrVarPub[inst].error_index = index + 1;
		game::Scr_ErrorInternal(game::SCRIPTINSTANCE_SERVER);
		return result;
	}

	// Decomp Status: Untested, Completed
	game::scr_animtree_t Scr_GetAnimTree()
	{
		const char* errorMsg;
		unsigned int i;
		game::VariableValue* value;
		unsigned int index = 0;
		game::scr_animtree_t result;

		game::animUserInstance_t user = game::ANIM_USER_SERVER;
		game::scriptInstance_t inst = game::SCRIPTINSTANCE_SERVER;

		result.anims = nullptr;

		if (index < game::gScrVmPub[inst].outparamcount)
		{
			value = &game::gScrVmPub[inst].top[-index];
			if (value->type == game::VAR_INTEGER)
			{
				i = value->u.intValue;
				if (value->u.intValue <= (int)game::gScrAnimPub[inst].xanim_num[user] && game::gScrAnimPub[inst].xanim_lookup[user][i].anims)
				{
					result.anims = game::gScrAnimPub[inst].xanim_lookup[user][i].anims;
					return result;
				}

				game::gScrVarPub[inst].error_message = (char*)"bad anim tree";
			}
			else
			{
				game::gScrVarPub[inst].error_message = (char*)game::va("type %s is not an animtree", game::var_typename[value->type]);
			}

			game::RemoveRefToValue(inst, value);
			value->u.intValue = 0;
			game::gScrVarPub[inst].error_index = index + 1;
			game::Scr_ErrorInternal(inst);
		}

		errorMsg = game::va("parameter %d does not exist", index + 1);
		game::Scr_Error(errorMsg, inst, false);
		return result;
	}

	// Decomp Status: Tested, Completed
	float Scr_GetFloat(game::scriptInstance_t inst, unsigned int index)
	{
		game::VariableValue *value;
		game::VariableType type;
		const char *errorMsg;

		if ( index < game::gScrVmPub[inst].outparamcount )
		{
			value = &game::gScrVmPub[inst].top[-index];
			type = value->type;
			if ( type == game::VAR_FLOAT )
			{
				return value->u.floatValue;
			}

			if ( type == game::VAR_INTEGER )
			{
				return (float)value->u.intValue;
			}

			game::gScrVarPub[inst].error_index = index + 1;
			errorMsg = game::va("type %s is not a float", game::var_typename[value->type]);
			game::Scr_Error(errorMsg, inst, false);
		}

		errorMsg = game::va("parameter %d does not exist", index + 1);
		game::Scr_Error(errorMsg, inst, false);
		return 0.0f;
	}

	// Decomp Status: Tested, Completed
	unsigned int Scr_GetConstString(game::scriptInstance_t inst, unsigned int index)
	{
		game::VariableValue *value;
		const char *errorMsg;

		if ( index < game::gScrVmPub[inst].outparamcount )
		{
			value = &game::gScrVmPub[inst].top[-index];
			if ( game::Scr_CastString(inst, value) )
			{
				assert(value->type == game::VAR_STRING);

				return value->u.stringValue;
			}

			game::gScrVarPub[inst].error_index = index + 1;
			game::Scr_ErrorInternal(inst);
		}

		errorMsg = game::va("parameter %d does not exist", index + 1);
		game::Scr_Error(errorMsg, inst, false);
		return 0;
	}

	// Decomp Status: Tested, Completed
	unsigned int Scr_GetConstLowercaseString(game::scriptInstance_t inst, unsigned int index)
	{
		const char* errorMsg;
		char* originalStr;
		char retStr[SL_MAX_STRING_LEN];
		int i;
		game::VariableValue* value;
		unsigned int stringValue;

		if (index >= game::gScrVmPub[inst].outparamcount)
		{
			errorMsg = game::va("parameter %d does not exist", index + 1);
			game::Scr_Error(errorMsg, inst, false);
			return 0;
		}

		value = &game::gScrVmPub[inst].top[-index];
		if (!game::Scr_CastString(inst, value))
		{
			game::gScrVarPub[inst].error_index = index + 1;
			game::Scr_ErrorInternal(inst);
			return 0;
		}

		assert(value->type == game::VAR_STRING);

		stringValue = value->u.stringValue;
		originalStr = game::SL_ConvertToString(stringValue, inst);
		for (i = 0; ; ++i)
		{
			retStr[i] = tolower(originalStr[i]);
			if (!originalStr[i])
			{
				break;
			}
		}

		assert(value->type == game::VAR_STRING);

		value->u.stringValue = game::SL_GetString_(retStr, inst, 0);
		game::SL_RemoveRefToString(stringValue, inst);
		//SL_CheckExists(inst, value->u.intValue);
		return value->u.stringValue;
	}

	// Decomp Status: Untested, Completed
	const char *Scr_GetString(unsigned int index, game::scriptInstance_t inst)
	{
		unsigned int stringValue;

		stringValue = game::Scr_GetConstString(inst, index);
		return game::SL_ConvertToString(stringValue, inst);
	}

	// Decomp Status: Untested, Completed
	unsigned int Scr_GetConstStringIncludeNull(game::scriptInstance_t inst)
	{
		unsigned int result = 0;
		unsigned int index = 0;

		if ( index >= game::gScrVmPub[inst].outparamcount || game::gScrVmPub[inst].top[-index].type)
		{
			result = game::Scr_GetConstString(inst, index);
		}

		return result;
	}

	// Decomp Status: Tested, Completed
	char *Scr_GetDebugString(game::scriptInstance_t inst, unsigned int index)
	{
		game::VariableValue *value;
		char *result;
		const char *errorMsg;

		if ( index >= game::gScrVmPub[inst].outparamcount )
		{
			errorMsg = game::va("parameter %d does not exist", index + 1);
			game::Scr_Error(errorMsg, inst, false);
			result = 0;
		}
		else
		{
			value = &game::gScrVmPub[inst].top[-index];
			game::Scr_CastDebugString(inst, value);

			assert(value->type == game::VAR_STRING);

			result = game::SL_ConvertToString(value->u.stringValue, inst);
		}

		return result;
	}

	// Decomp Status: Tested, Completed
	unsigned int Scr_GetConstIString(unsigned int index)
	{
		const char* errorMsg;
		game::VariableValue* value;
		game::scriptInstance_t inst = game::SCRIPTINSTANCE_SERVER;

		if (index < game::gScrVmPub[inst].outparamcount)
		{
			value = &game::gScrVmPub[inst].top[-index];
			if (value->type == game::VAR_ISTRING)
			{
				return value->u.stringValue;
			}

			game::gScrVarPub[inst].error_index = index + 1;
			errorMsg = game::va("type %s is not a localized string", game::var_typename[value->type]);
			game::Scr_Error(errorMsg, inst, false);
		}

		errorMsg = game::va("parameter %d does not exist", index + 1);
		game::Scr_Error(errorMsg, inst, false);
		return 0;
	}

	// Decomp Status: Tested, Completed
	void Scr_GetVector(game::scriptInstance_t inst, float * vectorValue, unsigned int index)
	{
		const char* errorMsg;
		const float* varValue;
		game::VariableValue* value;

		if (index < game::gScrVmPub[inst].outparamcount)
		{
			value = &game::gScrVmPub[inst].top[-index];
			if (value->type == game::VAR_VECTOR)
			{
				varValue = value->u.vectorValue;
				vectorValue[0] = varValue[0];
				vectorValue[1] = varValue[1];
				vectorValue[2] = varValue[2];
				return;
			}

			game::gScrVarPub[inst].error_index = index + 1;
			errorMsg = game::va("type %s is not a vector", game::var_typename[value->type]);
			game::Scr_Error(errorMsg, inst, false);
		}

		errorMsg = game::va("parameter %d does not exist", index + 1);
		game::Scr_Error(errorMsg, inst, false);
	}

	// Decomp Status: Untested, Completed
	unsigned int Scr_GetFunc()
	{
		const char *errorMsg;
		game::scriptInstance_t inst = game::SCRIPTINSTANCE_SERVER;
		unsigned int index = 0;

		if ( game::gScrVmPub[inst].outparamcount )
		{
			if ( game::gScrVmPub[inst].top[-index].type == game::VAR_FUNCTION)
			{
				assert(game::Scr_IsInOpcodeMemory(inst, game::gScrVmPub[inst].top[-index].u.codePosValue));

				return game::gScrVmPub[inst].top[-index].u.intValue - (unsigned int)game::gScrVarPub[inst].programBuffer;
			}

			game::gScrVarPub[inst].error_index = index + 1;
			errorMsg = game::va("type %s is not a function", game::var_typename[game::gScrVmPub[inst].top[-index].type]);
			game::Scr_Error(errorMsg, inst, false);
		}

		errorMsg = game::va("parameter %d does not exist", index + 1);
		game::Scr_Error(errorMsg, inst, false);
		return 0;
	}

	// Decomp Status: Tested, Completed
	game::scr_entref_t *Scr_GetEntityRef(game::scriptInstance_t inst, game::scr_entref_t *retstr, unsigned int index)
	{
		const char* errorMsg;
		game::scr_entref_t entRef;
		game::VariableValue* value;
		unsigned int id;

		if (index < game::gScrVmPub[inst].outparamcount)
		{
			value = &game::gScrVmPub[inst].top[-index];
			if (value->type == game::VAR_POINTER)
			{
				id = value->u.intValue;
				if (game::GetObjectType(inst, id) == game::VAR_ENTITY)
				{
					*retstr = *game::Scr_GetEntityIdRef(&entRef, inst, id);;
					return retstr;
				}

				game::gScrVarPub[inst].error_index = index + 1;
				errorMsg = game::va("type %s is not an entity", game::var_typename[game::GetObjectType(inst, id)]);
				game::Scr_Error(errorMsg, inst, false);
			}

			game::gScrVarPub[inst].error_index = index + 1;
			errorMsg = game::va("type %s is not an entity", game::var_typename[value->type]);
			game::Scr_Error(errorMsg, inst, false);
		}

		errorMsg = game::va("parameter %d does not exist", index + 1);
		game::Scr_Error(errorMsg, inst, false);
		return retstr;
	}

	// Decomp Status: Tested, Completed
	game::VariableUnion Scr_GetObject(game::scriptInstance_t inst)
	{
		const char *errorMsg;
		unsigned int index = 0;

		if (index < game::gScrVmPub[inst].outparamcount )
		{
			if (game::gScrVmPub[inst].top[-index].type == game::VAR_POINTER)
			{
				return game::gScrVmPub[inst].top[-index].u;
			}

			game::gScrVarPub[inst].error_index = index + 1;
			errorMsg = game::va("type %s is not an object", game::var_typename[game::gScrVmPub[inst].top[-index].type]);
			game::Scr_Error(errorMsg, inst, false);
		}

		errorMsg = game::va("parameter %d does not exist", index + 1);
		game::Scr_Error(errorMsg, inst, false);
		return game::gScrVmPub[inst].top[-index].u; // won't reach it ok
	}

	// Decomp Status: Tested, Completed
	game::VariableType Scr_GetType(game::scriptInstance_t inst, unsigned int index)
	{
		const char *errorMsg;

		if ( index < game::gScrVmPub[inst].outparamcount )
		{
			return game::gScrVmPub[inst].top[-index].type;
		}

		errorMsg = game::va("parameter %d does not exist", index + 1);
		game::Scr_Error(errorMsg, inst, false);
		return (game::VariableType)0;
	}

	// Decomp Status: Tested, Completed
	const char *Scr_GetTypeName(game::scriptInstance_t inst)
	{
		const char *errorMsg;
		unsigned int index = 0;

		if (index < game::gScrVmPub[inst].outparamcount )
		{
			return game::var_typename[game::gScrVmPub[inst].top[-index].type];
		}

		errorMsg = game::va("parameter %d does not exist", index + 1);
		game::Scr_Error(errorMsg, inst, false);
		return 0;
	}

	// Decomp Status: Tested, Completed
	game::VariableType Scr_GetPointerType(game::scriptInstance_t inst, unsigned int index)
	{
		const char *errorMsg;

		if ( index < game::gScrVmPub[inst].outparamcount )
		{
			if (game::gScrVmPub[inst].top[-index].type == game::VAR_POINTER )
			{
				return (game::VariableType)(game::gScrVarGlob[inst].parentVariables[game::gScrVmPub[inst].top[-index].u.intValue + 1].w.status & VAR_MASK);
			}

			errorMsg = game::va("type %s is not an object", game::var_typename[game::gScrVmPub[inst].top[-index].type]);
			game::Scr_Error(errorMsg, inst, false);
		}

		errorMsg = game::va("parameter %d does not exist", index + 1);
		game::Scr_Error(errorMsg, inst, false);
		return (game::VariableType)0;
	}

	// Decomp Status: Tested, Completed
	void Scr_AddInt(game::scriptInstance_t inst, int value)
	{
		game::IncInParam(inst);
		game::gScrVmPub[inst].top->type = game::VAR_INTEGER;
		game::gScrVmPub[inst].top->u.intValue = value;
	}

	// Decomp Status: Tested, Completed
	void Scr_AddFloat(game::scriptInstance_t inst, float value)
	{
		game::IncInParam(inst);
		game::gScrVmPub[inst].top->type = game::VAR_FLOAT;
		game::gScrVmPub[inst].top->u.floatValue = value;
	}

	// Decomp Status: Tested, Completed
	void Scr_AddAnim(game::scr_anim_s value)
	{
		game::scriptInstance_t inst = game::SCRIPTINSTANCE_SERVER;

		game::IncInParam(inst);
		game::gScrVmPub[inst].top->type = game::VAR_ANIMATION;
		game::gScrVmPub[inst].top->u.intValue = (int)value.u.linkPointer;
	}

	// Decomp Status: Tested, Completed
	void Scr_AddUndefined(game::scriptInstance_t inst)
	{
		game::IncInParam(inst);
		game::gScrVmPub[inst].top->type = game::VAR_UNDEFINED;
	}

	// Decomp Status: Tested, Completed
	void Scr_AddObject(game::scriptInstance_t inst, unsigned int entid)
	{
		assert(entid);

		assert(game::GetObjectType(inst, entid) != game::VAR_THREAD);

		assert(game::GetObjectType(inst, entid) != game::VAR_NOTIFY_THREAD);

		assert(game::GetObjectType(inst, entid) != game::VAR_TIME_THREAD);

		assert(game::GetObjectType(inst, entid) != game::VAR_CHILD_THREAD);

		assert(game::GetObjectType(inst, entid) != game::VAR_DEAD_THREAD);

		game::IncInParam(inst);
		game::gScrVmPub[inst].top->type = game::VAR_POINTER;
		game::gScrVmPub[inst].top->u.intValue = entid;
		game::AddRefToObject(inst, entid);
	}

	// Decomp Status: Tested, Completed
	void Scr_AddString(game::scriptInstance_t inst, const char *string)
	{
		assert(string);

		game::IncInParam(inst);
		game::gScrVmPub[inst].top->type = game::VAR_STRING;
		game::gScrVmPub[inst].top->u.stringValue = game::SL_GetString_(string, inst, 0);
	}

	// Decomp Status: Tested, Completed
	void Scr_AddIString(const char *string)
	{
		game::scriptInstance_t inst = game::SCRIPTINSTANCE_SERVER;

		assert(string);

		game::IncInParam(inst);
		game::gScrVmPub[inst].top->type = game::VAR_ISTRING;
		game::gScrVmPub[inst].top->u.stringValue = game::SL_GetString_(string, inst, 0);
	}

	// Decomp Status: Tested, Completed
	void Scr_AddConstString(game::scriptInstance_t inst, unsigned int id)
	{
		assert(id);

		game::IncInParam(inst);
		game::gScrVmPub[inst].top->type = game::VAR_STRING;
		game::gScrVmPub[inst].top->u.intValue = id;
		game::SL_AddRefToString(inst, id);
	}

	// Decomp Status: Tested, Completed
	void Scr_AddVector(game::scriptInstance_t inst, float *value)
	{
		game::IncInParam(inst);
		game::gScrVmPub[inst].top->type = game::VAR_VECTOR;
		game::gScrVmPub[inst].top->u.vectorValue = game::Scr_AllocVector_(inst, value);
	}

	// Restored Function
	void IncInParam(game::scriptInstance_t inst)
	{
		assert(((game::gScrVmPub[inst].top >= game::gScrVmGlob[inst].eval_stack - 1) && (game::gScrVmPub[inst].top <= game::gScrVmGlob[inst].eval_stack)) || 
			   ((game::gScrVmPub[inst].top >= game::gScrVmPub[inst].stack) && (game::gScrVmPub[inst].top <= game::gScrVmPub[inst].maxstack)));

		game::Scr_ClearOutParams(inst);

		if (game::gScrVmPub[inst].top == game::gScrVmPub[inst].maxstack)
		{
			game::Sys_Error("Internal script stack overflow");
		}

		++game::gScrVmPub[inst].top;
		++game::gScrVmPub[inst].inparamcount;

		assert(((game::gScrVmPub[inst].top >= game::gScrVmGlob[inst].eval_stack) && (game::gScrVmPub[inst].top <= game::gScrVmGlob[inst].eval_stack + 1)) || 
			   ((game::gScrVmPub[inst].top >= game::gScrVmPub[inst].stack) && (game::gScrVmPub[inst].top <= game::gScrVmPub[inst].maxstack)));
	}

	// Decomp Status: Tested, Completed
	void Scr_MakeArray(game::scriptInstance_t inst)
	{
		game::IncInParam(inst);
		game::gScrVmPub[inst].top->type = game::VAR_POINTER;
		game::gScrVmPub[inst].top->u.intValue = game::Scr_AllocArray(inst);
	}

	// Decomp Status: Tested, Completed
	void Scr_AddArray(game::scriptInstance_t inst)
	{
		unsigned int arraySize;
		unsigned int id;

		assert(game::gScrVmPub[inst].inparamcount);

		--game::gScrVmPub[inst].top;
		--game::gScrVmPub[inst].inparamcount;

		assert(game::gScrVmPub[inst].top->type == game::VAR_POINTER);

		arraySize = game::GetArraySize(inst, game::gScrVmPub[inst].top->u.stringValue);
		id = game::GetNewArrayVariable(inst, game::gScrVmPub[inst].top->u.stringValue, arraySize);
		game::SetNewVariableValue(inst, id, game::gScrVmPub[inst].top + 1);
	}

	// Restored function
	void SetNewVariableValue(game::scriptInstance_t inst, unsigned int id, game::VariableValue* value)
	{
		game::VariableValueInternal* entryValue;

		assert(value->type < game::VAR_THREAD);

		entryValue = &game::gScrVarGlob[inst].childVariables[id];

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);

		assert(!IsObject(entryValue));

		assert(value->type >= game::VAR_UNDEFINED && value->type < game::VAR_COUNT);

		assert((entryValue->w.type & VAR_MASK) == game::VAR_UNDEFINED);
		
		assert((value->type != game::VAR_POINTER) || ((entryValue->w.type & VAR_MASK) < game::FIRST_DEAD_OBJECT));

		entryValue->w.status |= value->type;
		entryValue->u.u.intValue = value->u.intValue;
	}

	// Decomp Status: Tested, Completed
	void Scr_AddArrayStringIndexed(unsigned int stringValue, game::scriptInstance_t inst)
	{
		unsigned int id;

		assert(game::gScrVmPub[inst].inparamcount);

		--game::gScrVmPub[inst].top;
		--game::gScrVmPub[inst].inparamcount;

		assert(game::gScrVmPub[inst].top->type == game::VAR_POINTER);

		id = game::GetNewVariable(inst, stringValue, game::gScrVmPub[inst].top->u.stringValue);
		game::SetNewVariableValue(inst, id, game::gScrVmPub[inst].top + 1);
	}

	//Restored function
	void Scr_SetErrorMessage(game::scriptInstance_t inst, const char* error)
	{
		if (!game::gScrVarPub[inst].error_message)
		{
			game::I_strncpyz(game::error_message_buff.get(), error, 1023u);
			game::error_message_buff[1023] = '\0';
			game::gScrVarPub[inst].error_message = game::error_message_buff.get();
		}
	}

	// Decomp Status: Tested, Completed
	void Scr_Error(const char* error, game::scriptInstance_t inst, int is_terminal)
	{
		game::Scr_SetErrorMessage(inst, error);

		game::gScrVmPub[inst].terminal_error = is_terminal;
		game::Scr_ErrorInternal(inst);
	}

	// Decomp Status: Tested, Completed
	void Scr_TerminalError(game::scriptInstance_t inst, const char* error)
	{
		game::Scr_DumpScriptThreads(inst);
		game::gScrVmPub[inst].terminal_error = 1;
		game::Scr_Error(error, inst, false);
	}

	// Decomp Status: Tested, Completed
	void Scr_ParamError(unsigned int index, game::scriptInstance_t inst, const char* error)
	{
		assert(index < game::gScrVmPub[inst].outparamcount);

		game::gScrVarPub[inst].error_index = index + 1;
		game::Scr_Error(error, inst, false);
	}

	// Decomp Status: Tested, Completed
	void Scr_ObjectError(game::scriptInstance_t inst, const char* error)
	{
		game::gScrVarPub[inst].error_index = -1;
		game::Scr_Error(error, inst, false);
	}

	//Restored function
	int CScr_SetObjectField(game::classNum_e classnum, int entnum, int clientNum, int offset)
	{
		if (classnum > game::CLASS_NUM_ENTITY)
		{
			//assertMsg("bad classnum");
			assert(false);
			return 1;
		}
		else
		{
			return game::CScr_SetEntityField(offset, entnum, clientNum);
		}
	}

	// Decomp Status: Tested, Completed
	bool SetEntityFieldValue(game::scriptInstance_t inst, int offset, int entnum, game::classNum_e classnum, int clientNum, game::VariableValue *value)
	{
		int bSet = false;

		assert((value - game::gScrVmPub[inst].stack > 0));

		assert((value - game::gScrVmPub[inst].maxstack <= 0));

		assert(!game::gScrVmPub[inst].inparamcount);

		assert(!game::gScrVmPub[inst].outparamcount);

		game::gScrVmPub[inst].top = value;
		game::gScrVmPub[inst].outparamcount = 1;

		if ( inst == game::SCRIPTINSTANCE_CLIENT )
		{
			bSet = game::CScr_SetObjectField(classnum, entnum, clientNum, offset);
		}
		else
		{
			bSet = game::Scr_SetObjectField(offset, entnum, classnum, inst);
		}

		if ( !bSet )
		{
			assert(!game::gScrVmPub[inst].inparamcount);

			assert(game::gScrVmPub[inst].outparamcount == 1);

			game::gScrVmPub[inst].outparamcount = 0;
			return 0;
		}

		assert(!game::gScrVmPub[inst].inparamcount);

		if ( !game::gScrVmPub[inst].outparamcount )
		{
			return 1;
		}
		
		assert(game::gScrVmPub[inst].outparamcount == 1);

		game::RemoveRefToValue(inst, game::gScrVmPub[inst].top);
		--game::gScrVmPub[inst].top;
		game::gScrVmPub[inst].outparamcount = 0;
		return 1;
	}

	//Restored function
	void CScr_GetObjectField(game::classNum_e classnum, int entnum, int clientNum, int offset)
	{
		if (classnum > game::CLASS_NUM_ENTITY)
		{
			//assertMsg("bad classnum");
			assert(false);
		}
		else
		{
			game::CScr_GetEntityField(offset, entnum, clientNum);
		}
	}

	// Decomp Status: Tested, Completed
	game::VariableValue GetEntityFieldValue(int offset, int entnum, game::scriptInstance_t inst, game::classNum_e classnum, int clientNum)
	{
		game::VariableValue result;

		assert(!game::gScrVmPub[inst].inparamcount);

		assert(!game::gScrVmPub[inst].outparamcount);

		game::gScrVmPub[inst].top = game::gScrVmGlob[inst].eval_stack - 1;
		game::gScrVmGlob[inst].eval_stack[0].type = game::VAR_UNDEFINED;

		if (inst == game::SCRIPTINSTANCE_CLIENT)
		{
			game::CScr_GetObjectField(classnum, entnum, clientNum, offset);
		}
		else
		{
			game::Scr_GetObjectField(offset, inst, classnum, entnum);
		}

		assert(!game::gScrVmPub[inst].inparamcount || game::gScrVmPub[inst].inparamcount == 1);

		assert(!game::gScrVmPub[inst].outparamcount);

		assert(game::gScrVmPub[inst].top - game::gScrVmPub[inst].inparamcount == game::gScrVmGlob[inst].eval_stack - 1);

		result.u.intValue = game::gScrVmGlob[inst].eval_stack[0].u.intValue;
		result.type = game::gScrVmGlob[inst].eval_stack[0].type;
		game::gScrVmPub[inst].inparamcount = 0;
		return result;
	}

	//Restored function
	void SetVariableFieldValue(game::scriptInstance_t inst, unsigned int id, game::VariableValue* value)
	{
		if (id)
		{
			game::SetVariableValue(inst, value, id);
		}
		else
		{
			game::SetVariableEntityFieldValue(inst, game::gScrVarPub[inst].entId, game::gScrVarPub[inst].entFieldName, value);
		}
	}

	// Decomp Status: Tested, Completed
	void Scr_SetStructField(unsigned int structId, unsigned int index, game::scriptInstance_t inst)
	{
		unsigned int fieldValueId;
		
		assert(!game::gScrVmPub[inst].outparamcount);

		assert(game::gScrVmPub[inst].inparamcount == 1);

		fieldValueId = game::gScrVarGlob[inst].childVariables[game::Scr_GetVariableFieldIndex(inst, index, structId)].hash.id;

		assert(game::gScrVmPub[inst].inparamcount == 1);

		game::gScrVmPub[inst].inparamcount = 0;
		game::SetVariableFieldValue(inst, fieldValueId, game::gScrVmPub[inst].top);

		assert(!game::gScrVmPub[inst].inparamcount);

		assert(!game::gScrVmPub[inst].outparamcount);

		--game::gScrVmPub[inst].top;
	}

	// Decomp Status: Tested, Completed
	void Scr_IncTime(game::scriptInstance_t inst)
	{
		game::Scr_RunCurrentThreads(inst);
		game::Scr_FreeEntityList(inst);

		assert((game::gScrVarPub[inst].time & VAR_NAME_LOW_MASK) == 0);

		++game::gScrVarPub[inst].time;
		game::gScrVarPub[inst].time &= ~VAR_NAME_LOW_MASK;
	}

	// Decomp Status: Tested, Completed
	void Scr_RunCurrentThreads(game::scriptInstance_t inst)
	{
		int preTime;

		preTime = timeGetTime();

		assert(!game::gScrVmPub[inst].function_count);
		
		assert(!game::gScrVarPub[inst].error_message);

		assert(!game::gScrVarPub[inst].error_index);

		assert(!game::gScrVmPub[inst].outparamcount);

		assert(!game::gScrVmPub[inst].inparamcount);

		assert(game::gScrVmPub[inst].top == game::gScrVmPub[inst].stack);

		game::VM_SetTime(inst);
		game::gScrExecuteTime[inst] += timeGetTime() - preTime;
	}

	// Decomp Status: Tested, Completed
	void Scr_ResetTimeout(game::scriptInstance_t inst)
	{
		game::gScrVmGlob[inst].starttime = game::Sys_Milliseconds();
	}

	game::VariableStackBuffer* GetRefVariableStackBuffer(game::scriptInstance_t inst, int id)
	{
		assert(id);

		assert((id * MT_NODE_SIZE) < MT_SIZE);

		return (game::VariableStackBuffer*)&game::gScrMemTreePub[inst].mt_buffer->nodes[id];
	}

	void Scr_NotifyNum(int entnum, game::classNum_e classnum, unsigned int stringValue, unsigned int paramcount)
	{
		game::Scr_NotifyNum_Internal(game::SCRIPTINSTANCE_SERVER, entnum, classnum, stringValue, paramcount);
	}
}
#pragma warning(pop)
