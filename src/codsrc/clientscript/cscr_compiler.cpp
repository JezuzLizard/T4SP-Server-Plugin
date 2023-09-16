#include <stdinc.hpp>
#include "clientscript_public.hpp"
#include <component/gsc.hpp>

#pragma warning(push)
#pragma warning(disable: 4244)
namespace codsrc
{
	// Completed
	void RemoveRefToValue(game::scriptInstance_t inst, game::VariableValue* value)
	{
		game::RemoveRefToValueInternal(inst, value->type, value->u);
	}

	// Completed
	void Scr_CompileRemoveRefToString(game::scriptInstance_t inst, unsigned int stringVal)
	{
		assert(stringVal);

		if (!game::gScrCompileGlob[inst].bConstRefCount) // gScrCompilePub[inst].developer_statement != 3 
		{
			game::SL_RemoveRefToString(stringVal, inst);
		}
	}

	// Completed
	void EmitCanonicalString(game::scriptInstance_t inst, unsigned int stringVal)
	{
		assert(stringVal);

		game::gScrCompileGlob[inst].codePos = game::TempMalloc(2);

		if ( game::gScrCompilePub[inst].developer_statement == 2 )
		{
			assert(!game::gScrVarPub[inst].developer_script);
			game::Scr_CompileRemoveRefToString(inst, stringVal);
		}
		/*
		else if ( gScrCompilePub[inst].developer_statement == 3 )
		  {
			*(_WORD *)gScrCompileGlob[inst].codePos = Scr_CompileCanonicalString(inst, stringValue);
			if ( !*(_WORD *)gScrCompileGlob[inst].codePos )
			  CompileError(inst, 0, "unknown field");
		  }
		*/
		else
		{
			if ( game::gScrCompileGlob[inst].bConstRefCount )
			{
				game::SL_AddRefToString(inst, stringVal);
			}

			*(short *)game::gScrCompileGlob[inst].codePos = game::SL_TransferToCanonicalString(inst, stringVal);
		}
	}

	// Completed
	void CompileTransferRefToString(unsigned int stringValue, game::scriptInstance_t inst, unsigned int user)
	{
		assert(stringValue);

		if ( game::gScrCompilePub[inst].developer_statement == 2 )
		{
			game::Scr_CompileRemoveRefToString(inst, stringValue);
		}
		else // if ( gScrCompilePub[inst].developer_statement != 3 )
		{
			if ( game::gScrCompileGlob[inst].bConstRefCount )
			{
				game::SL_AddRefToString(inst, stringValue);
			}

			game::SL_TransferRefToUser(stringValue, user, inst);
		}
	}

	// Completed
	void EmitOpcode(game::scriptInstance_t inst, game::OpcodeVM op, int offset, int callType)
	{
		int valueIndex;
		int value_count;
		unsigned int index;
		unsigned int indexa;

		/*
		if ( gScrCompilePub[inst].developer_statement == 3 )
		  {
			gScrCompileGlob[inst].codePos = TempMalloc(1);
			*gScrCompileGlob[inst].codePos = op;
			return;
		  }
		*/

		if ( game::gScrCompilePub[inst].value_count )
		{
			value_count = game::gScrCompilePub[inst].value_count;
			game::gScrCompilePub[inst].value_count = 0;
			for ( valueIndex = 0;
				valueIndex < value_count;
				++valueIndex )
			{
				game::EmitValue(inst, &game::gScrCompileGlob[inst].value_start[valueIndex]);
			}
		}

		game::gScrCompilePub[inst].allowedBreakpoint = (!game::gScrCompileGlob[inst].cumulOffset || callType == 2 || callType == 3);

		game::gScrCompileGlob[inst].cumulOffset += offset;

		if ( game::gScrCompileGlob[inst].maxOffset < game::gScrCompileGlob[inst].cumulOffset )
		{
			game::gScrCompileGlob[inst].maxOffset = game::gScrCompileGlob[inst].cumulOffset;
		}

		if ( callType && game::gScrCompileGlob[inst].maxCallOffset < game::gScrCompileGlob[inst].cumulOffset )
		{
			game::gScrCompileGlob[inst].maxCallOffset = game::gScrCompileGlob[inst].cumulOffset;
		}

		game::gScrVarPub[inst].checksum *= 31;
		game::gScrVarPub[inst].checksum += op;

		if ( game::gScrCompilePub[inst].opcodePos )
		{
			game::gScrCompileGlob[inst].codePos = game::gScrCompilePub[inst].opcodePos;
			switch ( op )
			{
			case game::OP_EvalArray:
				if ( *game::gScrCompilePub[inst].opcodePos == game::OP_EvalLocalVariableCached )
				{
					game::RemoveOpcodePos(inst);
					*game::gScrCompilePub[inst].opcodePos = game::OP_EvalLocalArrayCached;
					return;
				}

				index = *(unsigned __int8 *)game::gScrCompilePub[inst].opcodePos - game::OP_EvalLocalVariableCached0;
				if ( index > 5 )
				{
					goto LABEL_81;
				}

				game::RemoveOpcodePos(inst);
				*game::gScrCompilePub[inst].opcodePos = game::OP_EvalLocalArrayCached;
				game::EmitByte(inst, index);
				return;
			case game::OP_EvalArrayRef:
				if ( *game::gScrCompilePub[inst].opcodePos == game::OP_EvalLocalVariableRefCached )
				{
					game::RemoveOpcodePos(inst);
					*game::gScrCompilePub[inst].opcodePos = game::OP_EvalLocalArrayRefCached;
					// game::EmitPreAssignmentPos(inst);
					return;
				}
				if ( *game::gScrCompilePub[inst].opcodePos != game::OP_EvalLocalVariableRefCached0 )
				{
					goto LABEL_81;
				}

				game::RemoveOpcodePos(inst);
				*game::gScrCompilePub[inst].opcodePos = game::OP_EvalLocalArrayRefCached0;
				// game::EmitPreAssignmentPos(inst);
				return;
			case game::OP_EvalFieldVariable:
				if ( *game::gScrCompilePub[inst].opcodePos == game::OP_GetSelfObject )
				{
					*game::gScrCompilePub[inst].opcodePos = game::OP_EvalSelfFieldVariable;
					// game::EmitPreAssignmentPos(inst);
					return;
				}
				if ( *game::gScrCompilePub[inst].opcodePos == game::OP_GetLevelObject )
				{
					*game::gScrCompilePub[inst].opcodePos = game::OP_EvalLevelFieldVariable;
					// game::EmitPreAssignmentPos(inst);
					return;
				}
				if ( *game::gScrCompilePub[inst].opcodePos != game::OP_GetAnimObject )
				{
					goto LABEL_81;
				}

				*game::gScrCompilePub[inst].opcodePos = game::OP_EvalAnimFieldVariable;
				// game::EmitPreAssignmentPos(inst);
				return;
			case game::OP_EvalFieldVariableRef:
				if ( *game::gScrCompilePub[inst].opcodePos == game::OP_GetSelfObject )
				{
					*game::gScrCompilePub[inst].opcodePos = game::OP_EvalSelfFieldVariableRef;
					// game::EmitPreAssignmentPos(inst);
					return;
				}
				if ( *game::gScrCompilePub[inst].opcodePos == game::OP_GetLevelObject )
				{
					*game::gScrCompilePub[inst].opcodePos = game::OP_EvalLevelFieldVariableRef;
					// game::EmitPreAssignmentPos(inst);
					return;
				}
				if ( *game::gScrCompilePub[inst].opcodePos != game::OP_GetAnimObject )
				{
					goto LABEL_81;
				}

				*game::gScrCompilePub[inst].opcodePos = game::OP_EvalAnimFieldVariableRef;
				// game::EmitPreAssignmentPos(inst);
				return;
			case game::OP_SafeSetVariableFieldCached0:
				if ( *game::gScrCompilePub[inst].opcodePos != game::OP_CreateLocalVariable )
				{
					goto LABEL_81;
				}

				*game::gScrCompilePub[inst].opcodePos = game::OP_SafeCreateVariableFieldCached;
				return;
			case game::OP_SetVariableField:
				switch ( *game::gScrCompilePub[inst].opcodePos )
				{
				case game::OP_EvalLocalVariableRefCached:
					game::RemoveOpcodePos(inst);
					*game::gScrCompilePub[inst].opcodePos = game::OP_SetLocalVariableFieldCached;
					// game::EmitPreAssignmentPos(inst);
					return;
				case game::OP_EvalLocalVariableRefCached0:
					game::RemoveOpcodePos(inst);
					*game::gScrCompilePub[inst].opcodePos = game::OP_SetLocalVariableFieldCached0;
					// game::EmitPreAssignmentPos(inst);
					return;
				case game::OP_EvalSelfFieldVariableRef:
					game::RemoveOpcodePos(inst);
					*game::gScrCompilePub[inst].opcodePos = game::OP_SetSelfFieldVariableField;
					// game::EmitPreAssignmentPos(inst);
					return;
				case game::OP_EvalLevelFieldVariableRef:
					game::RemoveOpcodePos(inst);
					*game::gScrCompilePub[inst].opcodePos = game::OP_SetLevelFieldVariableField;
					// game::EmitPreAssignmentPos(inst);
					return;
				}
				if ( *game::gScrCompilePub[inst].opcodePos != game::OP_EvalAnimFieldVariableRef )
				{
					goto LABEL_81;
				}

				game::RemoveOpcodePos(inst);
				*game::gScrCompilePub[inst].opcodePos = game::OP_SetAnimFieldVariableField;
				// game::EmitPreAssignmentPos(inst);
				return;
			case game::OP_ScriptFunctionCall:
				if ( *game::gScrCompilePub[inst].opcodePos != game::OP_PreScriptCall )
				{
					goto LABEL_81;
				}

				*game::gScrCompilePub[inst].opcodePos = game::OP_ScriptFunctionCall2;
				return;
			case game::OP_ScriptMethodCall:
				if ( *game::gScrCompilePub[inst].opcodePos != game::OP_GetSelf )
				{
					goto LABEL_81;
				}

				game::RemoveOpcodePos(inst);
				*game::gScrCompilePub[inst].opcodePos = game::OP_ScriptFunctionCall;
				assert(game::gScrCompileGlob[inst].prevOpcodePos);

				if ( *game::gScrCompileGlob[inst].prevOpcodePos != game::OP_PreScriptCall )
				{
					return;
				}

				assert(game::gScrCompilePub[inst].opcodePos == game::TempMalloc(0) - 1);

				game::TempMemorySetPos(game::gScrCompilePub[inst].opcodePos);
				--game::gScrCompilePub[inst].opcodePos;
				game::gScrCompileGlob[inst].prevOpcodePos = 0;
				game::gScrCompileGlob[inst].codePos = game::gScrCompilePub[inst].opcodePos;
				*game::gScrCompilePub[inst].opcodePos = game::OP_ScriptFunctionCall2;
				return;
			case game::OP_ScriptMethodThreadCall:
				if ( *game::gScrCompilePub[inst].opcodePos != game::OP_GetSelf )
				{
					goto LABEL_81;
				}

				game::RemoveOpcodePos(inst);
				*game::gScrCompilePub[inst].opcodePos = game::OP_ScriptThreadCall;
				return;
			case game::OP_CastFieldObject:
				if ( *game::gScrCompilePub[inst].opcodePos == game::OP_EvalLocalVariableCached )
				{
					*game::gScrCompilePub[inst].opcodePos = game::OP_EvalLocalVariableObjectCached;
					return;
				}
				indexa = *(unsigned __int8 *)game::gScrCompilePub[inst].opcodePos - game::OP_EvalLocalVariableCached0;
				if ( indexa > 5 )
				{
					goto LABEL_81;
				}

				*game::gScrCompilePub[inst].opcodePos = game::OP_EvalLocalVariableObjectCached;
				game::EmitByte(inst, indexa);
				break;
			case game::OP_JumpOnFalse:
				if ( *game::gScrCompilePub[inst].opcodePos != game::OP_BoolNot )
				{
					goto LABEL_81;
				}

				game::RemoveOpcodePos(inst);
				*game::gScrCompilePub[inst].opcodePos = game::OP_JumpOnTrue;
				return;
			default:
				goto LABEL_81;
			}
		}
		else
		{
		LABEL_81:
			game::gScrCompileGlob[inst].prevOpcodePos = game::gScrCompilePub[inst].opcodePos;
			game::gScrCompilePub[inst].opcodePos = game::TempMalloc(1);
			game::gScrCompileGlob[inst].codePos = game::gScrCompilePub[inst].opcodePos;
			*game::gScrCompilePub[inst].opcodePos = op;
		}
	}

	// Completed
	void EmitEnd(game::scriptInstance_t inst)
	{
		game::EmitOpcode(inst, game::OP_End, 0, 0);
		// EmitPreAssignmentPos(inst);
	}

	// Completed
	void EmitReturn(game::scriptInstance_t inst)
	{
		game::EmitOpcode(inst, game::OP_Return, -1, 0);
		// game::EmitPreAssignmentPos(inst);
	}

	// Completed
	void EmitCodepos(game::scriptInstance_t inst, int codepos)
	{
		game::gScrCompileGlob[inst].codePos = game::TempMalloc(4);
		*(int *)game::gScrCompileGlob[inst].codePos = codepos;
	}

	// Completed
	void EmitShort(game::scriptInstance_t inst, int value)
	{
		game::gScrCompileGlob[inst].codePos = game::TempMalloc(2);
		*(short *)game::gScrCompileGlob[inst].codePos = value;
	}

	// Completed
	void EmitByte(game::scriptInstance_t inst, int value)
	{
		game::gScrCompileGlob[inst].codePos = game::TempMalloc(1);
		*(char *)game::gScrCompileGlob[inst].codePos = value;
	}

	// Completed
	void EmitGetInteger(game::scriptInstance_t inst, int value, game::sval_u sourcePos)
	{
		if ( value < 0 )
		{
			if ( value > -256 )
			{
				game::EmitOpcode(inst, game::OP_GetNegByte, 1, 0);
				game::AddOpcodePos(inst, sourcePos.stringValue, 1);
				game::EmitByte(inst, -(char)value);
				return;
			}
			if ( value > -65536 )
			{
				game::EmitOpcode(inst, game::OP_GetNegUnsignedShort, 1, 0);
				game::AddOpcodePos(inst, sourcePos.stringValue, 1);
				game::EmitShort(inst, -(__int16)value);
				return;
			}
		}
		else
		{
			if ( !value )
			{
				game::EmitOpcode(inst, game::OP_GetZero, 1, 0);
				game::AddOpcodePos(inst, sourcePos.stringValue, 1);
				return;
			}
			if ( value < 256 )
			{
				game::EmitOpcode(inst, game::OP_GetByte, 1, 0);
				game::AddOpcodePos(inst, sourcePos.stringValue, 1);
				game::EmitByte(inst, value);
				return;
			}
			if ( value < 0x10000 )
			{
				game::EmitOpcode(inst, game::OP_GetUnsignedShort, 1, 0);
				game::AddOpcodePos(inst, sourcePos.stringValue, 1);
				game::EmitShort(inst, value);
				return;
			}
		}
		game::EmitOpcode(inst, game::OP_GetInteger, 1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
		game::EmitCodepos(inst, value);
	}

	// Restored
	void EmitFloat(game::scriptInstance_t inst, float value)
	{
		game::gScrCompileGlob[inst].codePos = game::TempMalloc(4);
		*(float *)game::gScrCompileGlob[inst].codePos = value;
	}

	// Completed
	void EmitGetFloat(game::scriptInstance_t inst, float value, game::sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_GetFloat, 1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
		game::EmitFloat(inst, value);
	}

	// Completed
	void EmitAnimTree(game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		if ( game::gScrAnimPub[inst].animTreeIndex )
		{
			game::EmitGetInteger(inst, game::gScrAnimPub[inst].animTreeIndex, sourcePos);
		}
		else
		{
			game::CompileError(inst, sourcePos.stringValue, "#using_animtree was not specified");
		}
	}

	// Restored
	void EmitCanonicalStringConst(game::scriptInstance_t inst, unsigned int stringValue)
	{
		bool bConstRefCount;

		bConstRefCount = game::gScrCompileGlob[inst].bConstRefCount;
		game::gScrCompileGlob[inst].bConstRefCount = 1;
		game::EmitCanonicalString(inst, stringValue);
		game::gScrCompileGlob[inst].bConstRefCount = bConstRefCount;
	}

	// Completed
	int Scr_FindLocalVarIndex(game::scriptInstance_t inst, unsigned int name, game::sval_u sourcePos, int create, game::scr_block_s* block)
	{
		int i;

		/*assert(gScrCompilePub[inst].developer_statement != SCR_DEV_EVALUATE (3));*/

		if ( block )
		{
			for ( i = 0;
				;
				++i )
			{
				if ( i >= block->localVarsCount )
				{
					if ( !create || game::gScrCompileGlob[inst].forceNotCreate )
					{
						game::CompileError(inst, sourcePos.stringValue, "uninitialised variable '%s'", game::SL_ConvertToString(name, inst));
						return 0;
					}

					game::CompileError(inst, sourcePos.stringValue, "unreachable code");
					return 0;
				}

				if ( i == block->localVarsCreateCount )
				{
					++block->localVarsCreateCount;
					game::EmitOpcode(inst, game::OP_CreateLocalVariable, 0, 0);
					game::EmitCanonicalStringConst(inst, block->localVars[i].name);
					// game::AddOpcodePos(inst, block->localVars[i].sourcePos, 0);
				}

				if ( block->localVars[i].name == name )
				{
					break;
				}
			}

			game::Scr_CompileRemoveRefToString(inst, name);

			if ( ((unsigned __int8)(1 << (i & 7)) & block->localVarsInitBits[i >> 3]) == 0 )
			{
				if ( !create || game::gScrCompileGlob[inst].forceNotCreate )
				{
					if ( !create || game::gScrCompileGlob[inst].forceNotCreate )
					{
						game::CompileError(inst, sourcePos.stringValue, "uninitialised variable '%s'", game::SL_ConvertToString(name, inst));
						return 0;
					}

					game::CompileError(inst, sourcePos.stringValue, "unreachable code");
					return 0;
				}

				block->localVarsInitBits[i >> 3] |= 1 << (i & 7);
			}

			assert((block->localVarsCreateCount - 1) >= i);
			return block->localVarsCreateCount - 1 - i;
		}

		game::CompileError(inst, sourcePos.stringValue, "unreachable code");
		return 0;
	}

	// Completed
	void EmitCreateLocalVars(game::scriptInstance_t inst, game::scr_block_s* block)
	{
		int i;

		assert(block->localVarsPublicCount >= block->localVarsCreateCount);

		if ( block->localVarsCreateCount != block->localVarsPublicCount )
		{
			for ( i = block->localVarsCreateCount;
				i < block->localVarsPublicCount;
				++i )
			{
				game::EmitOpcode(inst, game::OP_CreateLocalVariable, 0, 0);
				game::EmitCanonicalStringConst(inst, block->localVars[i].name);
				// game::AddOpcodePos(inst, block->localVars[i].sourcePos, 0);
			}

			block->localVarsCreateCount = block->localVarsPublicCount;
		}
	}

	// Completed
	void EmitRemoveLocalVars(game::scriptInstance_t inst, game::scr_block_s* outerBlock, game::scr_block_s* block)
	{
		int removeCount;

		if ( !block->abortLevel )
		{
			assert(block->localVarsCreateCount >= block->localVarsPublicCount);
			assert(block->localVarsPublicCount >= outerBlock->localVarsPublicCount);

			removeCount = block->localVarsCreateCount - outerBlock->localVarsPublicCount;
			assert(removeCount >= 0);

			if ( removeCount )
			{
				game::EmitOpcode(inst, game::OP_RemoveLocalVariables, 0, 0);
				game::EmitByte(inst, removeCount);
				block->localVarsCreateCount = block->localVarsPublicCount;
			}
		}
	}

	// Completed
	void EmitNOP2(game::scr_block_s* block, game::scriptInstance_t inst, int lastStatement, unsigned int endSourcePos)
	{
		int checksum;

		checksum = game::gScrVarPub[inst].checksum;

		if ( (char)lastStatement )
		{
			game::EmitEnd(inst);
			game::AddOpcodePos(inst, endSourcePos, 1);
		}
		else
		{
			game::EmitRemoveLocalVars(inst, block, block);
		}

		game::gScrVarPub[inst].checksum = checksum + 1;
	}

	// Completed
	void Scr_InitFromChildBlocks(game::scr_block_s** childBlocks, int childCount, game::scr_block_s* block)
	{
		game::scr_block_s *childBlock;
		game::scr_block_s *childBlocka; 
		int childIndex;
		int childIndexa;
		int localVarsCreateCount;
		unsigned int name;
		int i;

		if ( childCount )
		{
			localVarsCreateCount = (*childBlocks)->localVarsPublicCount;
			for ( childIndex = 1;
				childIndex < childCount;
				++childIndex )
			{
				childBlock = childBlocks[childIndex];
				if ( childBlock->localVarsPublicCount < localVarsCreateCount )
				{
					localVarsCreateCount = childBlock->localVarsPublicCount;
				}
			}

			assert(block->localVarsCreateCount <= localVarsCreateCount);
			assert(localVarsCreateCount <= block->localVarsCount);

			block->localVarsCreateCount = localVarsCreateCount;
			for ( i = 0;
				i < localVarsCreateCount;
				++i )
			{
				assert(i < block->localVarsCount);

				if ( ((1 << (i & 7)) & (unsigned __int8)block->localVarsInitBits[i >> 3]) == 0 )
				{
					name = block->localVars[i].name;
					for ( childIndexa = 0;
						childIndexa < childCount;
						++childIndexa )
					{
						childBlocka = childBlocks[childIndexa];
						assert(localVarsCreateCount <= childBlocka->localVarsPublicCount);
						assert(i < childBlocka->localVarsPublicCount);
						assert(childBlocka->localVars[i].name == name);

						if ( ((1 << (i & 7)) & (unsigned __int8)childBlocka->localVarsInitBits[i >> 3]) == 0 )
						{
							goto LABEL_14;
						}
					}
					block->localVarsInitBits[i >> 3] |= 1 << (i & 7);
				}

			LABEL_14:
				;
			}
		}
	}

	// Restored
	int Scr_FindLocalVar(game::scr_block_s *block, int startIndex, unsigned int name)
	{
		while ( startIndex < block->localVarsCount )
		{
			if ( block->localVars[startIndex].name == name )
			{
				return startIndex;
			}

			++startIndex;
		}

		return -1;
	}

	// Completed
	void Scr_AppendChildBlocks(game::scr_block_s* block, game::scr_block_s** childBlocks, int childCount)
	{
		unsigned int localVar;
		int childIndex;
		int childIndexa;
		int i;

		if ( childCount && !block->abortLevel )
		{
			for ( childIndex = 0;
				childIndex < childCount;
				++childIndex )
			{
				childBlocks[childIndex]->abortLevel = 0;
			}

			for ( i = 0;
				i < (*childBlocks)->localVarsCount;
				++i )
			{
				localVar = (*childBlocks)->localVars[i].name;
				// v5 = (*childBlocks)->localVars[i].sourcePos;

				if ( game::Scr_FindLocalVar(block, 0, localVar) < 0 )
				{
					for ( childIndexa = 1;
						childIndexa < childCount;
						++childIndexa )
					{
						if ( game::Scr_FindLocalVar(childBlocks[childIndexa], 0, localVar) < 0 )
						{
							goto LABEL_8;
						}
					}

					block->localVars[block->localVarsCount].name = localVar;
					// block->localVars[block->localVarsCount].sourcePos = v5;
					++block->localVarsCount;
				}
			LABEL_8:
				;
			}
		}
	}

	// Restored
	void Scr_CheckLocalVarsCount(int localVarsCount)
	{
		if ( localVarsCount >= 64 )
		{
			game::Com_Error(game::ERR_DROP, "LOCAL_game::VAR_STACK_SIZE exceeded");
		}
	}

	// Completed
	void Scr_MergeChildBlocks(game::scr_block_s** childBlocks, int childCount, game::scr_block_s* block)
	{
		int j;
		unsigned int localVar;
		game::scr_block_s *childBlock;
		int childIndex;
		int i;

		if ( childCount && !block->abortLevel )
		{
			for ( childIndex = 0;
				childIndex < childCount;
				++childIndex )
			{
				childBlock = childBlocks[childIndex];
				assert(!childBlock->localVarsPublicCount);

				childBlock->localVarsPublicCount = block->localVarsCount;
				for ( i = 0;
					i < block->localVarsCount;
					++i )
				{
					localVar = block->localVars[i].name;
					// v6 = block->localVars[i].sourcePos;
					j = game::Scr_FindLocalVar(childBlock, i, localVar);
					if ( j < 0 )
					{
						j = childBlock->localVarsCount;
						game::Scr_CheckLocalVarsCount(j);
						++childBlock->localVarsCount;
					}

					while ( j > i )
					{
						// v3 = *(_DWORD *)&childBlock->localVarsInitBits[8 * j + 4];
						childBlock->localVars[j].name = childBlock->localVars[j - 1].name;
						// childBlock->localVars[j].sourcePos = v3;
						j--;
					}

					childBlock->localVars[i].name = localVar;
					// childBlock->localVars[i].sourcePos = v6;
				}
			}
		}
	}

	// Completed
	void Scr_TransferBlock(game::scr_block_s* to, game::scr_block_s* from)
	{
		int j;
		unsigned int localVar;
		int i;

		assert(to->localVarsPublicCount <= from->localVarsCount);

		for ( i = 0;
			i < to->localVarsPublicCount || i < from->localVarsCreateCount;
			++i )
		{
			localVar = from->localVars[i].name;
			// v5 = from->localVars[i].sourcePos;
			j = game::Scr_FindLocalVar(to, i, localVar);
			if ( j < 0 )
			{
				j = to->localVarsCount;
				game::Scr_CheckLocalVarsCount(j);
				++to->localVarsCount;
			}

			if (j >= to->localVarsPublicCount)
			{
				++to->localVarsPublicCount;
				assert(to->localVarsPublicCount <= from->localVarsCount);
			}

			while ( j > i )
			{
				// v2 = *(_DWORD *)&to->localVarsInitBits[8 * j + 4];
				to->localVars[j].name = to->localVars[j - 1].name;
				// to->localVars[j].sourcePos = v2;
				j--;
			}

			to->localVars[i].name = localVar;
			// to->localVars[i].sourcePos = v5;
			if ( ((1 << (i & 7)) & (unsigned __int8)from->localVarsInitBits[i >> 3]) != 0 )
			{
				to->localVarsInitBits[i >> 3] |= 1 << (i & 7);
			}
		}

		assert(from->localVarsCreateCount <= to->localVarsPublicCount);

		to->localVarsCreateCount = from->localVarsCreateCount;
		to->abortLevel = 0;
	}

	// Completed
	void EmitSafeSetVariableField(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u expr, game::sval_u sourcePos)
	{
		int index;

		index = game::Scr_FindLocalVarIndex(inst, expr.stringValue, sourcePos, 1, block);

		if (index == 0)
		{
			game::EmitOpcode(inst, game::OP_SafeSetVariableFieldCached0, 0, 0);
		}
		else
		{
			game::EmitOpcode(inst, game::OP_SafeSetVariableFieldCached, 0, 0);
		}

		// game::EmitPreAssignmentPos(inst);

		if ( index )
		{
			game::EmitByte(inst, index);
		}

		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
		// game::EmitAssignmentPos(inst);
	}

	// Completed
	void EmitSafeSetWaittillVariableField(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u expr, game::sval_u sourcePos)
	{
		char index;

		index = Scr_FindLocalVarIndex(inst, expr.stringValue, sourcePos, 1, block);
		game::EmitOpcode(inst, game::OP_SafeSetWaittillVariableFieldCached, 0, 0);
		// game::EmitPreAssignmentPos(inst);
		game::EmitByte(inst, index);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
		// game::EmitAssignmentPos(inst);
	}

	// Completed
	void EmitGetString(unsigned int value, game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_GetString, 1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
		game::EmitShort(inst, value);
		game::CompileTransferRefToString(value, inst, 1u);
	}

	// Complete
	void EmitGetIString(unsigned int value, game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_GetIString, 1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
		game::EmitShort(inst, value);
		game::CompileTransferRefToString(value, inst, 1u);
	}

	// Decomp Status: Untested
	// void __usercall EmitGetVector(const float *value@<eax>, game::scriptInstance_t inst, game::sval_u sourcePos)
	void EmitGetVector(const float* value, game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		int i;

		game::EmitOpcode(inst, game::OP_GetVector, 1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);

		for ( i = 0;
			i < 3;
			++i )
		{
			game::EmitFloat(inst, value[i]);
		}

		game::RemoveRefToVector(value, inst);
	}

	// Restored
	void EmitGetUndefined(game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_GetUndefined, 1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
	}

	// Completed
	void EmitValue(game::scriptInstance_t inst, game::VariableCompileValue* constValue)
	{
		switch (constValue->value.type)
		{
		case game::VAR_UNDEFINED:
			game::EmitGetUndefined(inst, constValue->sourcePos);
			break;
		case game::VAR_STRING:
			game::EmitGetString(constValue->value.u.intValue, inst, constValue->sourcePos);
			break;
		case game::VAR_ISTRING:
			game::EmitGetIString(constValue->value.u.intValue, inst, constValue->sourcePos);
			break;
		case game::VAR_VECTOR:
			game::EmitGetVector(constValue->value.u.vectorValue, inst, constValue->sourcePos);
			break;
		case game::VAR_FLOAT:
			game::EmitGetFloat(inst, constValue->value.u.floatValue, constValue->sourcePos);
			break;
		case game::VAR_INTEGER:
			game::EmitGetInteger(inst, constValue->value.u.intValue, constValue->sourcePos);
			break;
		default:
			return;
		}
	}

	// Completed
	void Scr_PushValue(game::scriptInstance_t inst, game::VariableCompileValue* constValue)
	{
		if ( game::gScrCompilePub[inst].value_count < 32 )
		{
			game::gScrCompileGlob[inst].value_start[game::gScrCompilePub[inst].value_count++] = *constValue;
		}
		else
		{
			game::CompileError(inst, constValue->sourcePos.stringValue, "VALUE_STACK_SIZE exceeded");
		}
	}

	// Completed
	void EmitCastBool(game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_CastBool, 0, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
	}

	// Completed
	void EmitBoolNot(game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_BoolNot, 0, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
	}

	// Completed
	void EmitBoolComplement(game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_BoolComplement, 0, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
	}

	// Restored
	void EmitPrimitiveExpression(game::scriptInstance_t inst, game::sval_u expr, game::scr_block_s *block)
	{
		game::VariableCompileValue constValue;

		if ( game::EmitOrEvalPrimitiveExpression(inst, expr, &constValue, block) )
		{
			game::EmitValue(inst, &constValue);
		}
	}

	// Completed
	void EmitSize(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u expr, game::sval_u sourcePos)
	{
		game::EmitPrimitiveExpression(inst, expr, block);
		game::EmitOpcode(inst, game::OP_size, 0, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
	}

	// Completed
	void EmitSelf(game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_GetSelf, 1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
	}

	// Completed
	void EmitLevel(game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_GetLevel, 1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
	}

	// Completed
	void EmitGame(game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_GetGame, 1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
	}

	// Completed
	void EmitAnim(game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_GetAnim, 1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
	}

	// Completed
	void EmitSelfObject(game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_GetSelfObject, 0, 0);
		// game::EmitPreAssignmentPos(inst);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
	}

	// Completed
	void EmitLevelObject(game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_GetLevelObject, 0, 0);
		// game::EmitPreAssignmentPos(inst);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
	}

	// Completed
	void EmitAnimObject(game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_GetAnimObject, 0, 0);
		// game::EmitPreAssignmentPos(inst);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
	}

	// Completed
	void EmitLocalVariable(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u expr, game::sval_u sourcePos)
	{
		int index;
		unsigned int opcode;

		/*if (gScrCompilePub[inst].developer_statement == 3)
		{
			EmitOpcode(inst, game::OP_EvalLocalVariable, 1, 0);
			EmitCanonicalString(inst, expr.stringValue);
			return;
		}*/

		index = game::Scr_FindLocalVarIndex(inst, expr.stringValue, sourcePos, 0, block);

		if ( index > 5 )
		{
			opcode = game::OP_EvalLocalVariableCached;
			game::EmitOpcode(inst, game::OP_EvalLocalVariableCached, 1, 0);
		}
		else
		{
			opcode = index + game::OP_EvalLocalVariableCached0;
			game::EmitOpcode(inst, (game::OpcodeVM)opcode, 1, 0);
		}

		if ( opcode == game::OP_EvalLocalVariableCached )
		{
			game::EmitByte(inst, index);
		}
		
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
	}

	// Completed
	void EmitLocalVariableRef(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u expr, game::sval_u sourcePos)
	{
		int index;

		/*if (gScrCompilePub[inst].developer_statement == 3)
		{
			EmitOpcode(inst, game::OP_EvalLocalVariableRef, 0, 0);
			EmitCanonicalString(inst, expr.stringValue);
		}*/

		index = game::Scr_FindLocalVarIndex(inst, expr.stringValue, sourcePos, 1, block);

		if (index == 0)
		{
			game::EmitOpcode(inst, game::OP_EvalLocalVariableRefCached0, 0, 0);
		}
		else
		{
			game::EmitOpcode(inst, game::OP_EvalLocalVariableRefCached, 0, 0);
		}

		// game::EmitPreAssignmentPos(inst);

		if ( index )
		{
			game::EmitByte(inst, index);
		}

		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
	}

	// Completed
	void Scr_RegisterLocalVar(unsigned int name, [[maybe_unused]] game::sval_u sourcePos, game::scr_block_s* block)
	{
		int i;

		if ( !block->abortLevel )
		{
			for ( i = 0;
				i < block->localVarsCount;
				++i )
			{
				if ( block->localVars[i].name == name )
				{
					return;
				}
			}

			game::Scr_CheckLocalVarsCount(block->localVarsCount);
			block->localVars[block->localVarsCount].name = name;
			//block->localVars[block->localVarsCount].sourcePos = sourcePos.stringValue;
			block->localVarsCount++;
		}
	}

	// Completed
	void EmitGameRef(game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_GetGameRef, 0, 0);
		// game::EmitPreAssignmentPos(inst);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
	}

	// Completed
	void EmitClearArray(game::scriptInstance_t inst, game::sval_u sourcePos, game::sval_u indexSourcePos)
	{
		game::EmitOpcode(inst, game::OP_ClearArray, -1, 0);
		game::AddOpcodePos(inst, indexSourcePos.stringValue, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
		// game::EmitAssignmentPos(inst);
	}

	// Completed
	void EmitEmptyArray(game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_EmptyArray, 1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
	}

	// Restored
	void Scr_EmitAnimation(game::scriptInstance_t inst, char *pos, unsigned int animName, unsigned int sourcePos)
	{
		if ( game::gScrAnimPub[inst].animTreeNames )
		{
			game::Scr_EmitAnimationInternal(inst, pos, animName, game::gScrAnimPub[inst].animTreeNames);
		}
		else
		{
			game::CompileError(inst, sourcePos, "#using_animtree was not specified");
		}
	}

	// Completed
	void EmitAnimation(game::scriptInstance_t inst, game::sval_u anim, game::sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_GetAnimation, 1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
		game::EmitCodepos(inst, 0xFFFFFFFF);

		if ( game::gScrCompilePub[inst].developer_statement != 2 )
		{
			game::Scr_EmitAnimation(inst, game::gScrCompileGlob[inst].codePos, anim.stringValue, sourcePos.stringValue);
		}

		game::Scr_CompileRemoveRefToString(inst, anim.stringValue);
	}

	// Completed
	void EmitFieldVariable(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u expr, game::sval_u field, game::sval_u sourcePos)
	{
		game::EmitPrimitiveExpressionFieldObject(inst, expr, sourcePos, block);
		game::EmitOpcode(inst, game::OP_EvalFieldVariable, 1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
		game::EmitCanonicalString(inst, field.stringValue);
	}

	// Completed
	void EmitClearFieldVariable(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u expr, game::sval_u field, game::sval_u sourcePos, game::sval_u rhsSourcePos)
	{
		game::EmitPrimitiveExpressionFieldObject(inst, expr, sourcePos, block);
		game::EmitOpcode(inst, game::OP_ClearFieldVariable, 0, 0);
		game::AddOpcodePos(inst, rhsSourcePos.stringValue, 0);
		game::EmitCanonicalString(inst, field.stringValue);
		// game::EmitAssignmentPos(inst);
	}

	// Decomp Status: Untested
	// void __usercall EmitObject(game::scriptInstance_t inst@<edi>, game::sval_u expr, game::sval_u sourcePos)
	void EmitObject([[maybe_unused]] game::scriptInstance_t inst, [[maybe_unused]] game::sval_u expr, [[maybe_unused]] game::sval_u sourcePos)
	{
		/*int v3;													// esi
		unsigned int* v4;										// ecx
		char v5;												// dl
		unsigned int v6;										// eax
		VariableValueInternal_w v7;								// eax
		int v8;													// eax
		int v9;													// eax
		game::VariableCompileValue* v10;								// esi
		bool v11;												// al
		int v12;												// eax
		unsigned int* v13;										// eax
		char* v14;												// eax
		char* v15;												// eax
		scr_classStruct_t* v16; // eax
		char* v17;												// esi
		int v18;												// eax
		game::VariableCompileValue* v19;								// esi
		bool v20;												// al
		int v21;												// eax
		unsigned int* v22;										// eax
		char* v23;												// eax
		char* v24;												// eax
		int codepos;											// [esp+Ch] [ebp-Ch]
		int codeposa;											// [esp+Ch] [ebp-Ch]
		int a2;													// [esp+10h] [ebp-8h]
		int a2a;												// [esp+10h] [ebp-8h]
		int v29;												// [esp+14h] [ebp-4h]

		if (game::gScrCompilePub[inst].script_loading)
		{
			game::CompileError(inst, sourcePos.stringValue, "$ can only be used in the script debugger");
		}
		v3 = 0;
		if (expr.stringValue)
		{
			v4 = game::gScrMemTreePub[inst].mt_buffer->nodes[expr.stringValue].padding;
		}
		else
		{
			v4 = 0;
		}
		v5 = *(char*)v4;
		if (*(char*)v4 == 0x74)
		{
			v6 = game::j__atol((const char*)v4 + 1);
			a2 = v6;
			if (v6)
			{
				if (v6 < 0x5FFE)
				{
					v7.status = (unsigned int)game::gScrVarGlob[inst].parentVariables[(unsigned __int16)v6 + 1].w.status;
					if ((v7.status & 0x60) != 0)
					{
						v8 = v7.status & 0x1F;
						if (v8 >= 13 && (v8 <= 16 || v8 == 21))
						{
							v9 = game::gScrCompilePub[inst].value_count;
							if (v9)
							{
								game::gScrCompilePub[inst].value_count = 0;
								if (v9 > 0)
								{
									v10 = game::gScrCompileGlob[inst].value_start;
									codepos = v9;
									do
									{
										game::EmitValue(inst, v10++);
										--codepos;
									} while (codepos);
								}
							}
							v11 = game::gScrCompileGlob[inst].cumulOffset++ == 0;
							game::gScrCompilePub[inst].allowedBreakpoint = v11;
							v12 = game::gScrCompileGlob[inst].cumulOffset;
							if (game::gScrCompileGlob[inst].maxOffset < v12)
							{
								game::gScrCompileGlob[inst].maxOffset = v12;
							}
							v13 = &game::gScrVarPub[inst].checksum;
							*v13 *= 31;
							*v13 += 130;
							v14 = game::gScrCompilePub[inst].opcodePos;
							if (v14)
							{
								game::gScrCompileGlob[inst].codePos = v14;
							}
							game::gScrCompileGlob[inst].prevOpcodePos = v14;
							v15 = (char*)game::Hunk_UserAlloc((*game::g_user), 1, 1);
							game::gScrCompilePub[inst].opcodePos = v15;
							game::gScrCompileGlob[inst].codePos = v15;
							*v15 = -126;
							game::EmitShort(inst, a2);
							return;
						}
					}
				}
			}
		LABEL_22:
			game::CompileError(inst, sourcePos.stringValue, "bad expression");
		}
		if (v5 == 97)
		{
			game::CompileError(inst, sourcePos.stringValue, "argument expressions not supported in statements");
		}
		v16 = game::gScrClassMap[inst]; // Scr_GetClassnumForCharId
		while (v16->charId != v5)
		{
			++v3;
			++v16;
			if (v3 >= 4)
			{
				goto LABEL_30;
			}
		}
		codeposa = v3;
		if (v3 < 0)
		{
		LABEL_30:
			game::CompileError(inst, sourcePos.stringValue, "bad expression");
		}
		v17 = (char*)v4 + 1;
		v29 = game::j__atol((const char*)v4 + 1);
		if (!v29 && *v17 != 48)
		{
			goto LABEL_22;
		}
		v18 = game::gScrCompilePub[inst].value_count;
		if (v18)
		{
			game::gScrCompilePub[inst].value_count = 0;
			if (v18 > 0)
			{
				v19 = game::gScrCompileGlob[inst].value_start;
				a2a = v18;
				do
				{
					game::EmitValue(inst, v19++);
					--a2a;
				} while (a2a);
			}
		}
		v20 = game::gScrCompileGlob[inst].cumulOffset++ == 0;
		game::gScrCompilePub[inst].allowedBreakpoint = v20;
		v21 = game::gScrCompileGlob[inst].cumulOffset;
		if (game::gScrCompileGlob[inst].maxOffset < v21)
		{
			game::gScrCompileGlob[inst].maxOffset = v21;
		}
		v22 = &game::gScrVarPub[inst].checksum;
		*v22 *= 31;
		*v22 += 129;
		v23 = game::gScrCompilePub[inst].opcodePos;
		if (v23)
		{
			game::gScrCompileGlob[inst].codePos = v23;
		}
		game::gScrCompileGlob[inst].prevOpcodePos = v23;
		v24 = (char*)game::Hunk_UserAlloc((*game::g_user), 1, 1);
		game::gScrCompilePub[inst].opcodePos = v24;
		game::gScrCompileGlob[inst].codePos = v24;
		*v24 = -127;
		game::EmitCodepos(inst, codeposa);
		game::EmitCodepos(inst, v29);*/

		/*
		game::VariableType v3; // [esp+0h] [ebp-18h]
  const char *classnum; // [esp+4h] [ebp-14h]
  char *s; // [esp+Ch] [ebp-Ch]
  const char *entnum; // [esp+10h] [ebp-8h]
  unsigned int idValue; // [esp+14h] [ebp-4h]

  if ( gScrCompilePub[inst].script_loading )
  {
	CompileError(inst, sourcePos.stringValue, "$ can only be used in the script debugger");
	return;
  }
  s = SL_ConvertToString(expr.stringValue, inst);
  if ( *s == 't' )
  {
	idValue = atoi(s + 1);
	if ( idValue )
	{
	  if ( idValue < 0x7FFE && !IsObjectFree(inst, (unsigned __int16)idValue) )
	  {
		v3 = GetObjectType(inst, (unsigned __int16)idValue);
		if ( v3 >= game::VAR_THREAD && (v3 <= game::VAR_CHILD_THREAD || v3 == game::VAR_DEAD_THREAD) )
		{
		  EmitOpcode(inst, 0x82u, 1, 0);
		  EmitShort(inst, idValue);
		  return;
		}
	  }
	}
LABEL_17:
	CompileError(inst, sourcePos.stringValue, "bad expression");
	return;
  }
  if ( *s == 97 )
  {
	CompileError(inst, sourcePos.stringValue, "argument expressions not supported in statements");
	return;
  }
  classnum = (const char *)Scr_GetClassnumForCharId(inst, *s);
  if ( (int)classnum < 0 )
	goto LABEL_17;
  entnum = (const char *)atoi(s + 1);
  if ( !entnum && s[1] != 48 )
	goto LABEL_17;
  EmitOpcode(inst, 0x81u, 1, 0);
  EmitCodepos(inst, classnum);
  EmitCodepos(inst, entnum);
		*/
	}

	// Completed
	void EmitDecTop(game::scriptInstance_t inst)
	{
		game::EmitOpcode(inst, game::OP_DecTop, -1, 0);
	}

	// Completed
	void EmitCastFieldObject(game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_CastFieldObject, -1, 0);
		// game::EmitPreAssignmentPos(inst);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
	}

	// Restored
	void EmitEvalArray(game::scriptInstance_t inst, game::sval_u sourcePos, game::sval_u indexSourcePos)
	{
		game::EmitOpcode(inst, game::OP_EvalArray, -1, 0);
		game::AddOpcodePos(inst, indexSourcePos.stringValue, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
	}

	// Completed
	void EmitArrayVariable(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u expr, game::sval_u index, game::sval_u sourcePos, game::sval_u indexSourcePos)
	{
		game::EmitExpression(inst, index, block);
		game::EmitPrimitiveExpression(inst, expr, block);
		game::EmitEvalArray(inst, sourcePos, indexSourcePos);
	}

	// Restored
	void EmitEvalArrayRef(game::scriptInstance_t inst, game::sval_u sourcePos, game::sval_u indexSourcePos)
	{
		game::EmitOpcode(inst, game::OP_EvalArrayRef, -1, 0);
		game::AddOpcodePos(inst, indexSourcePos.stringValue, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
	}

	// Completed
	void EmitArrayVariableRef(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u expr, game::sval_u index, game::sval_u sourcePos, game::sval_u indexSourcePos)
	{
		game::EmitExpression(inst, index, block);
		game::EmitArrayPrimitiveExpressionRef(inst, expr, sourcePos, block);
		game::EmitEvalArrayRef(inst, sourcePos, indexSourcePos);
	}

	// Completed
	void EmitClearArrayVariable(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u expr, game::sval_u index, game::sval_u sourcePos, game::sval_u indexSourcePos)
	{
		game::EmitExpression(inst, index, block);
		game::EmitArrayPrimitiveExpressionRef(inst, expr, sourcePos, block);
		game::EmitClearArray(inst, sourcePos, indexSourcePos);
	}

	// Completed
	void EmitVariableExpression(game::scriptInstance_t inst, game::sval_u expr, game::scr_block_s* block)
	{
		switch ( expr.node->type )
		{
		case game::ENUM_local_variable:
			game::EmitLocalVariable(block, inst, expr.node[1], expr.node[2]);
			break;
		case game::ENUM_array_variable:
			game::EmitArrayVariable(block, inst, expr.node[1], expr.node[2], expr.node[3], expr.node[4]);
			break;
		case game::ENUM_field_variable:
			game::EmitFieldVariable(block, inst, expr.node[1], expr.node[2], expr.node[3]);
			break;
		case game::ENUM_self_field:
			if ( game::gScrCompilePub[inst].script_loading )
			{
				game::CompileError(inst, expr.node[2].sourcePosValue, "self field can only be used in the script debugger");
			}
			else
			{
				game::CompileError(inst, expr.node[2].sourcePosValue, "self field in assignment expression not currently supported");
			}

			break;
		case game::ENUM_object:
			game::EmitObject(inst, expr.node[1], expr.node[2]);
			break;
		default:
			return;
		}
	}

	// Completed
	int EmitExpressionList(game::scriptInstance_t inst, game::sval_u exprlist, game::scr_block_s* block)
	{
		game::sval_u *node;
		int expr_count;

		expr_count = 0;
		for ( node = exprlist.node[0].node;
			node;
			node = node[1].node )
		{
			game::EmitExpression(inst, node->node[0], block);
			++expr_count;
		}

		return expr_count;
	}

	// Completed
	void AddExpressionListOpcodePos(game::scriptInstance_t inst, game::sval_u exprlist)
	{
		game::sval_u *node;

		if (game::gScrVarPub[inst].developer)
		{
			for (node = exprlist.node[0].node;
				node;
				node = node[1].node)
			{
				game::AddOpcodePos(inst, node->node[1].sourcePosValue, 0);
			}
		}
	}

	// Completed
	void AddFilePrecache(game::scriptInstance_t inst, unsigned int filename, unsigned int sourcePos, bool include, unsigned int* filePosId, unsigned int* fileCountId)
	{
		game::SL_AddRefToString(inst, filename);
		game::Scr_CompileRemoveRefToString(inst, filename);
		game::gScrCompileGlob[inst].precachescriptList->filename = filename;
		game::gScrCompileGlob[inst].precachescriptList->sourcePos = sourcePos;
		game::gScrCompileGlob[inst].precachescriptList->include = include;
		++game::gScrCompileGlob[inst].precachescriptList;

		if ( !include )
		{
			*filePosId = game::GetObject(inst, game::GetVariable(inst, game::gScrCompilePub[inst].scriptsPos, filename));
			*fileCountId = game::GetObject(inst, game::GetVariable(inst, game::gScrCompilePub[inst].scriptsCount, filename));
		}
	}

	// Completed
	void EmitFunction(game::scriptInstance_t inst, game::sval_u func, game::sval_u sourcePos)
	{
		unsigned int threadCountId;
		unsigned int valueId;
		unsigned int fileCountId;
		unsigned int filename;
		unsigned int posId;
		unsigned int threadName;
		bool bExists;
		int scope;
		unsigned int countId;
		unsigned int filePosId;
		game::VariableValue count;
		game::VariableValue value;
		game::VariableValue pos;

		/*if (gScrCompilePub[inst].developer_statement == 3)
		{
			CompileError(inst, sourcePos.stringValue, "cannot evaluate in the debugger");
			return;
		}*/

		if ( game::gScrCompilePub[inst].developer_statement == 2 )
		{
			game::Scr_CompileRemoveRefToString(inst, func.node[1].type);

			if ( func.node[0].type != game::ENUM_far_function )
			{
				return;
			}

			game::Scr_CompileRemoveRefToString(inst, func.node[2].stringValue);
			--game::gScrCompilePub[inst].far_function_count;
			return;
		}

		if ( func.node[0].type == game::ENUM_local_function )
		{
			scope = 0;
			fileCountId = game::gScrCompileGlob[inst].fileCountId;
			threadName = func.node[1].stringValue;
			game::CompileTransferRefToString(threadName, inst, 2u);
		}
		else
		{
			assert(func.node[0].type == game::ENUM_far_function);

			scope = 1;
			filename = game::Scr_CreateCanonicalFilename(inst, game::SL_ConvertToString(func.node[1].stringValue, inst));
			game::Scr_CompileRemoveRefToString(inst, func.node[1].stringValue);
			value = game::Scr_EvalVariable(inst, game::FindVariable(filename, game::gScrCompilePub[inst].loadedscripts, inst));
			bExists = value.type != game::VAR_UNDEFINED;
			game::AddFilePrecache(inst, filename, sourcePos.stringValue, 0, &filePosId, &fileCountId);

			threadName = func.node[2].stringValue;
			game::CompileTransferRefToString(threadName, inst, 2u);
			if ( bExists )
			{
				posId = game::FindVariable(threadName, filePosId, inst);
				if (!posId)
				{
					game::CompileError(inst, sourcePos.stringValue, "unknown function");
				}

				pos = game::Scr_EvalVariable(inst, posId);
				assert((pos.type == game::VAR_CODEPOS || pos.type == game::VAR_DEVELOPER_CODEPOS));
				assert(pos.u.codePosValue);

				if ( pos.type == game::VAR_CODEPOS )
				{
					game::EmitCodepos(inst, pos.u.intValue);
					return;
				}

				assert(pos.type == game::VAR_DEVELOPER_CODEPOS);
				assert(game::gScrVarPub[inst].developer_script);
				assert(game::gScrCompilePub[inst].developer_statement != 2); // SCR_DEV_IGNORE

				if ( !game::gScrCompilePub[inst].developer_statement )
				{
					game::CompileError(inst, sourcePos.stringValue, "normal script cannot reference a function in a /# ... #/ comment");
				}

				game::EmitCodepos(inst, pos.u.intValue);
				return;
			}
		}

		game::EmitCodepos(inst, scope);
		threadCountId = game::GetObject(inst, game::GetVariable(inst, fileCountId, threadName));
		assert(threadCountId);

		countId = game::GetVariable(inst, threadCountId, 0);
		count = game::Scr_EvalVariable(inst, countId);

		assert((count.type == game::VAR_UNDEFINED) || (count.type == game::VAR_INTEGER));

		if (count.type == game::VAR_UNDEFINED)
		{
			count.type = game::VAR_INTEGER;
			count.u.intValue = 0;
		}

		valueId = game::GetNewVariable(inst, count.u.intValue + 1, threadCountId);
		value.u.intValue = (int)game::gScrCompileGlob[inst].codePos;

		if ( game::gScrCompilePub[inst].developer_statement )
		{
			assert(game::gScrVarPub[inst].developer_script);
			value.type = game::VAR_DEVELOPER_CODEPOS;
		}
		else
		{
			value.type = game::VAR_CODEPOS;
		}

		game::SetNewVariableValue(inst, valueId, &value);
		++count.u.intValue;
		game::SetVariableValue(inst, &count, countId);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
	}

	// Completed
	void EmitGetFunction(game::scriptInstance_t inst, game::sval_u func, game::sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_GetFunction, 1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 3);
		game::EmitFunction(inst, func, sourcePos);
	}

	// Completed
	int AddFunction(game::scriptInstance_t inst, int func)
	{
		int i;

		for ( i = 0;
			i < game::gScrCompilePub[inst].func_table_size;
			++i )
		{
			if ( game::gScrCompilePub[inst].func_table[i] == func )
			{
				return i;
			}
		}

		assert(i == game::gScrCompilePub[inst].func_table_size);

		if ( game::gScrCompilePub[inst].func_table_size == 1024 )
		{
			game::Com_Error(game::ERR_DROP, "\x15SCR_FUNC_TABLE_SIZE exceeded");
		}

		game::gScrCompilePub[inst].func_table[game::gScrCompilePub[inst].func_table_size] = func;
		// game::gScrVmDebugPub[inst].func_table[game::gScrCompilePub[inst].func_table_size].breakpointCount = 0;
		game::gScrCompilePub[inst].func_table_size++;
		return i;
	}

	// Completed
	void EmitPostScriptFunction(game::scriptInstance_t inst, game::sval_u func, int param_count, int bMethod, game::sval_u nameSourcePos)
	{
		if ( bMethod )
		{
			game::EmitOpcode(inst, game::OP_ScriptMethodCall, -param_count - 1, 3);
		}
		else
		{
			game::EmitOpcode(inst, game::OP_ScriptFunctionCall, -param_count, 3);
		}

		game::AddOpcodePos(inst, nameSourcePos.stringValue, 3);
		game::EmitFunction(inst, func, nameSourcePos);
	}

	// Completed
	void EmitPostScriptFunctionPointer(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u expr, int param_count, int bMethod, game::sval_u nameSourcePos, game::sval_u sourcePos)
	{
		game::EmitExpression(inst, expr, block);

		if ( bMethod )
		{
			game::EmitOpcode(inst, game::OP_ScriptMethodCallPointer, -param_count - 2, 3);
		}
		else
		{
			game::EmitOpcode(inst, game::OP_ScriptFunctionCallPointer, -param_count - 1, 3);
		}

		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
		game::AddOpcodePos(inst, nameSourcePos.stringValue, 1);
	}

	// Completed
	void EmitPostScriptThread(game::scriptInstance_t inst, game::sval_u func, int param_count, int bMethod, game::sval_u sourcePos)
	{
		if ( bMethod )
		{
			game::EmitOpcode(inst, game::OP_ScriptMethodThreadCall, -param_count, 2);
		}
		else
		{
			game::EmitOpcode(inst, game::OP_ScriptThreadCall, 1 - param_count, 2);
		}

		game::AddOpcodePos(inst, sourcePos.stringValue, 3);
		game::EmitFunction(inst, func, sourcePos);
		game::EmitCodepos(inst, param_count);
	}

	// Completed
	void EmitPostScriptThreadPointer(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u expr, int param_count, int bMethod, game::sval_u sourcePos)
	{
		game::EmitExpression(inst, expr, block);

		if ( bMethod )
		{
			game::EmitOpcode(inst, game::OP_ScriptMethodThreadCallPointer, -param_count - 1, 2);
		}
		else
		{
			game::EmitOpcode(inst, game::OP_ScriptThreadCallPointer, -param_count, 2);
		}

		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
		game::EmitCodepos(inst, param_count);
	}

	// Completed
	void EmitPostScriptFunctionCall(game::scriptInstance_t inst, int bMethod, int param_count, game::sval_u func_name, game::sval_u nameSourcePos, game::scr_block_s* block)
	{
		if (func_name.node[0].type == game::ENUM_function)
		{
			game::EmitPostScriptFunction(inst, func_name.node[1], param_count, bMethod, nameSourcePos);
		}
		else if (func_name.node[0].type == game::ENUM_function_pointer)
		{
			game::EmitPostScriptFunctionPointer(
				block,
				inst,
				func_name.node[1],
				param_count,
				bMethod,
				nameSourcePos,
				func_name.node[2]);
		}
	}

	// Completed
	void EmitPostScriptThreadCall(game::scriptInstance_t inst, int isMethod, int param_count, game::sval_u func_name, game::sval_u sourcePos, game::sval_u nameSourcePos, game::scr_block_s* block)
	{
		if (func_name.node[0].type == game::ENUM_function)
		{
			game::EmitPostScriptThread(inst, func_name.node[1], param_count, isMethod, nameSourcePos);
		}
		else if (func_name.node[0].type == game::ENUM_function_pointer)
		{
			game::EmitPostScriptThreadPointer(
				block,
				inst,
				func_name.node[1],
				param_count,
				isMethod,
				func_name.node[2]);
		}

		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
	}

	// Completed
	void EmitPreFunctionCall(game::scriptInstance_t inst)
	{
		game::EmitOpcode(inst, game::OP_PreScriptCall, 1, 0);
	}

	// Completed
	void EmitPostFunctionCall(game::scriptInstance_t inst, int bMethod, game::sval_u func_name, int param_count, game::scr_block_s* block)
	{
		if (func_name.node[0].type == game::ENUM_script_call)
		{
			game::EmitPostScriptFunctionCall(
				inst,
				bMethod,
				param_count,
				func_name.node[1],
				func_name.node[2],
				block);
		}
		else if (func_name.node[0].type == game::ENUM_script_thread_call)
		{
			game::EmitPostScriptThreadCall(
				inst,
				bMethod,
				param_count,
				func_name.node[1],
				func_name.node[2],
				func_name.node[3],
				block);
		}
	}

	// Completed
	void Scr_BeginDevScript(game::scriptInstance_t inst, int* type, char** savedPos)
	{
		if ( game::gScrCompilePub[inst].developer_statement )
		{
			*type = 0;
		}
		else
		{
			if ( game::gScrVarPub[inst].developer_script )
			{
				game::gScrCompilePub[inst].developer_statement = 1;
			}
			else
			{
				*savedPos = game::TempMalloc(0);
				game::gScrCompilePub[inst].developer_statement = 2;
			}
			*type = 1;
		}
	}

	// Completed
	void Scr_EndDevScript(game::scriptInstance_t inst, char** savedPos)
	{
		// if ( type != 1 && !Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\clientscript\\cscr_compiler.cpp", 1833, 0, "%s", "type == BUILTIN_DEVELOPER_ONLY") )
		game::gScrCompilePub[inst].developer_statement = 0;

		if ( !game::gScrVarPub[inst].developer_script )
		{
			game::TempMemorySetPos(*savedPos);
		}
	}

	// Completed
	void EmitCallBuiltinOpcode(game::scriptInstance_t inst, int param_count, game::sval_u sourcePos)
	{
		unsigned int opcode;

		if ( param_count > 5 )
		{
			opcode = game::OP_CallBuiltin;
			game::EmitOpcode(inst, game::OP_CallBuiltin, 1 - param_count, 1);
		}
		else
		{
			opcode = param_count + game::OP_CallBuiltin0;
			game::EmitOpcode(inst, (game::OpcodeVM)(param_count + game::OP_CallBuiltin0), 1 - param_count, 1);
		}

		game::AddOpcodePos(inst, sourcePos.stringValue, 9);

		if ( opcode == game::OP_CallBuiltin )
		{
			game::EmitByte(inst, param_count);
		}
	}

	// Completed
	void EmitCallBuiltinMethodOpcode(game::scriptInstance_t inst, int param_count, game::sval_u sourcePos)
	{
		unsigned int opcode;

		if ( param_count > 5 )
		{
			opcode = game::OP_CallBuiltinMethod;
			game::EmitOpcode(inst, game::OP_CallBuiltinMethod, -param_count, 1);
		}
		else
		{
			opcode = param_count + game::OP_CallBuiltinMethod0;
			game::EmitOpcode(inst, (game::OpcodeVM)(param_count + game::OP_CallBuiltinMethod0), -param_count, 1);
		}

		// game::EmitPreAssignmentPos(inst);
		game::AddOpcodePos(inst, sourcePos.stringValue, 9);

		if ( opcode == game::OP_CallBuiltinMethod )
		{
			game::EmitByte(inst, param_count);
		}
	}

	// Restored
	unsigned int Scr_GetBuiltin(game::scriptInstance_t inst, game::sval_u func_name)
	{
		game::sval_u func_namea;
		game::sval_u func_nameb;

		if ( func_name.node[0].type != game::ENUM_script_call )
		{
			return 0;
		}

		func_namea = func_name.node[1];
		if ( func_namea.node[0].type != game::ENUM_function )
		{
			return 0;
		}

		func_nameb = func_namea.node[1];
		if ( func_nameb.node[0].type != game::ENUM_local_function )
		{
			return 0;
		}

		if ( /*game::gScrCompilePub[inst].developer_statement == 3 ||*/ !game::FindVariable(func_nameb.node[1].stringValue, game::gScrCompileGlob[inst].filePosId, inst))
		{
			return func_nameb.node[1].stringValue;
		}

		return 0;
	}

	// Restored
	int Scr_GetUncacheType(int type)
	{
		if ( type == game::VAR_CODEPOS )
		{
			return 0;
		}

		assert(type == game::VAR_DEVELOPER_CODEPOS);
		return 1;
	}

	// Restored
	int Scr_GetCacheType(int type)
	{
		if ( !type )
		{
			return game::VAR_CODEPOS;
		}

		assert(type == 1);  // BUILTIN_DEVELOPER_ONLY

		return game::VAR_DEVELOPER_CODEPOS;
	}

	// Restored
	game::BuiltinFunction Scr_GetFunction(const char** pName, int* type)
	{
		game::BuiltinFunction answer;

		answer = game::Sentient_GetFunction(pName);

		if (answer)
		{
			return answer;
		}

		return game::BuiltIn_GetFunction(pName, type);
	}

	// Restored
	game::BuiltinFunction GetFunction(game::scriptInstance_t inst, const char **pName, int *type)
	{
		if ( inst )
		{
			// pluto
			if (game::plutonium::cscr_get_function_hook != nullptr)
			{
				return game::plutonium::cscr_get_function_hook(pName, type);
			}
			//
			else
			{
				return game::CScr_GetFunction(pName, type);
			}

		}

		// our addition
		auto f = gsc::function::get(pName, type);
		if (f != nullptr)
		{
			return f;
		}
		//

		// pluto
		if (game::plutonium::scr_get_function_hook != nullptr)
		{
			return game::plutonium::scr_get_function_hook(pName, type);
		}
		//
		else
		{
			return game::Scr_GetFunction(pName, type);
		}
	}

	// Completed
	void EmitCall(game::scriptInstance_t inst, game::sval_u func_name, game::sval_u params, int bStatement, game::scr_block_s* block)
	{
		void (__cdecl *func)();
		char *savedPos;
		unsigned int funcId;
		int param_count;
		unsigned int name;
		const char *pName;
		int type;
		game::sval_u sourcePos;
		game::VariableValue value;

		savedPos = 0;
		name = game::Scr_GetBuiltin(inst, func_name);
		if ( !name )
		{
			goto script_function;
		}

		pName = game::SL_ConvertToString(name, inst);
		sourcePos = func_name.node[2];

		/*if (gScrCompilePub[inst].developer_statement == 3)
		{
			type = 0;
			func = game::GetFunction(inst, &pName, &type);
		}
		else*/
		{
			funcId = game::FindVariable(name, game::gScrCompilePub[inst].builtinFunc, inst);
			if ( funcId )
			{
				value = game::Scr_EvalVariable(inst, funcId);
				type = game::Scr_GetUncacheType(value.type);
				func = (void (__cdecl *)())value.u.intValue;
			}
			else
			{
				type = 0;
				func = game::GetFunction(inst, &pName, &type);
				funcId = game::GetNewVariable(inst, name, game::gScrCompilePub[inst].builtinFunc);
				value.type = (game::VariableType)game::Scr_GetCacheType(type);
				value.u.intValue = (int)func;
				game::SetVariableValue(inst, &value, funcId);
			}
		}

		if ( func )
		{
			if ( type == 1 && (game::Scr_BeginDevScript(inst, &type, &savedPos), type == 1) && !bStatement )
			{
				game::CompileError(inst, sourcePos.stringValue, "return value of developer command can not be accessed if not in a /# ... #/ comment");
			}
			else
			{
				param_count = game::EmitExpressionList(inst, params, block);
				if ( param_count < 256 )
				{
					game::Scr_CompileRemoveRefToString(inst, name);
					game::EmitCallBuiltinOpcode(inst, param_count, sourcePos);
					game::EmitShort(inst, game::AddFunction(inst, (int)func));
					game::AddExpressionListOpcodePos(inst, params);

					if ( bStatement )
					{
						game::EmitDecTop(inst);
					}

					if ( type == 1 )
					{
						game::Scr_EndDevScript(inst, &savedPos);
					}
				}
				else
				{
					game::CompileError(inst, sourcePos.stringValue, "parameter count exceeds 256");
				}
			}
		}
		else
		{
		script_function:
			/*if (gScrCompilePub[inst].developer_statement == 3)
			{
				CompileError(inst, *(_DWORD *)(func_name.stringValue + 8), "unknown builtin function");
			}
			else*/
			{
				if ( func_name.node[0].type == game::ENUM_script_call)
				{
					game::EmitPreFunctionCall(inst);
				}

				param_count = game::EmitExpressionList(inst, params, block);
				game::EmitPostFunctionCall(inst, 0, func_name, param_count, block);
				game::AddExpressionListOpcodePos(inst, params);

				if ( bStatement )
				{
					game::EmitDecTop(inst);
				}
			}
		}
	}

	// Restored
	game::BuiltinMethod GetMethod(game::scriptInstance_t inst, const char **pName, int *type)
	{
		if ( inst )
		{
			// pluto
			if (game::plutonium::cscr_get_method_hook != nullptr)
			{
				return game::plutonium::cscr_get_method_hook(pName, type);
			}
			//
			else
			{
				return game::CScr_GetMethod(pName, type);
			}
		}

		// our addition
		auto f = gsc::method::get(pName, type);
		if (f != nullptr)
		{
			return f;
		}
		//

		// pluto
		if (game::plutonium::scr_get_method_hook != nullptr)
		{
			return game::plutonium::scr_get_method_hook(pName, type);
		}
		//
		else
		{
			return game::Scr_GetMethod(type, pName);
		}
	}

	// Completed
	void EmitMethod(game::scriptInstance_t inst, game::sval_u expr, game::sval_u func_name, game::sval_u params, game::sval_u methodSourcePos, int bStatement, game::scr_block_s* block)
	{
		char *savedPos;
		unsigned int methId;
		void (__cdecl *meth)(game::scr_entref_t);
		int param_count;
		unsigned int name;
		const char *pName;
		int type;
		game::sval_u sourcePos;
		game::VariableValue value;

		savedPos = 0;
		name = game::Scr_GetBuiltin(inst, func_name);
		if ( !name )
		{
			goto script_method;
		}

		pName = game::SL_ConvertToString(name, inst);
		sourcePos = func_name.node[2];
		/*if (gScrCompilePub[inst].developer_statement == 3)
		{
			type = 0;
			meth = GetMethod(inst, &pName, &type);
		}
		else*/
		{
			methId = game::FindVariable(name, game::gScrCompilePub[inst].builtinMeth, inst);
			if ( methId )
			{
				value = game::Scr_EvalVariable(inst, methId);
				type = game::Scr_GetUncacheType(value.type);
				meth = (void (__cdecl *)(game::scr_entref_t))value.u.intValue;
			}
			else
			{
				type = 0;
				meth = game::GetMethod(inst, &pName, &type); // waltuh
				methId = game::GetNewVariable(inst, name, game::gScrCompilePub[inst].builtinMeth);
				value.type = (game::VariableType)game::Scr_GetCacheType(type);
				value.u.intValue = (int)meth;
				game::SetVariableValue(inst, &value, methId);
			}
		}

		if ( meth )
		{
			if ( type == 1 && (game::Scr_BeginDevScript(inst, &type, &savedPos), type == 1) && !bStatement )
			{
				game::CompileError(inst, sourcePos.stringValue, "return value of developer command can not be accessed if not in a /# ... #/ comment");
			}
			else
			{
				param_count = game::EmitExpressionList(inst, params, block);
				game::EmitPrimitiveExpression(inst, expr, block);
				if ( param_count < 256 )
				{
					game::Scr_CompileRemoveRefToString(inst, name);
					game::EmitCallBuiltinMethodOpcode(inst, param_count, sourcePos);
					game::EmitShort(inst, game::AddFunction(inst, (int)meth));
					game::AddOpcodePos(inst, methodSourcePos.stringValue, 0);
					game::AddExpressionListOpcodePos(inst, params);

					if ( bStatement )
					{
						game::EmitDecTop(inst);
					}

					// game::EmitAssignmentPos(inst);
					if ( type == 1 )
					{
						game::Scr_EndDevScript(inst, &savedPos);
					}
				}
				else
				{
					game::CompileError(inst, sourcePos.stringValue, "parameter count exceeds 256");
				}
			}
		}
		else
		{
		script_method:
			/*if (gScrCompilePub[inst].developer_statement == 3)
			{
				CompileError(inst, *(_DWORD *)(func_name.stringValue + 8), "unknown builtin method");
			}
			else*/
			{
				if ( func_name.node[0].type == game::ENUM_script_call)
				{
					game::EmitPreFunctionCall(inst);
				}

				param_count = game::EmitExpressionList(inst, params, block);
				game::EmitPrimitiveExpression(inst, expr, block);
				game::EmitPostFunctionCall(inst, 1, func_name, param_count, block);
				game::AddOpcodePos(inst, methodSourcePos.stringValue, 0);
				game::AddExpressionListOpcodePos(inst, params);

				if ( bStatement )
				{
					game::EmitDecTop(inst);
				}
			}
		}
	}

	// Completed
	void LinkThread(game::scriptInstance_t inst, unsigned int threadCountId, game::VariableValue* pos, int allowFarCall)
	{
		unsigned int valueId;
		unsigned int countId;
		int type;
		int i;
		game::VariableValueInternal_u *value;
		game::VariableValue count;

		countId = game::FindVariable(0, threadCountId, inst);
		if ( countId )
		{
			count = game::Scr_EvalVariable(inst, countId);
			assert(count.type == game::VAR_INTEGER);

			for ( i = 0;
				i < count.u.intValue;
				++i )
			{
				valueId = game::FindVariable(i + 1, threadCountId, inst);
				assert(valueId);

				value = game::GetVariableValueAddress(inst, valueId);

				type = game::GetValueType(inst, valueId);
				assert(type == game::VAR_CODEPOS || type == game::VAR_DEVELOPER_CODEPOS);

				if ( pos->type == game::VAR_DEVELOPER_CODEPOS )
				{
					assert(game::gScrVarPub[inst].developer_script);

					if ( type == game::VAR_CODEPOS )
					{
						game::CompileError2(value->u.codePosValue, inst, game::CompileError2_ADDR(), "normal script cannot reference a function in a /# ... #/ comment");
						return;
					}
				}

				if ( pos->type == game::VAR_UNDEFINED || !allowFarCall && *(int*)value->u.codePosValue == 1 )
				{
					game::CompileError2(value->u.codePosValue, inst, game::CompileError2_ADDR(), "unknown function");
					return;
				}

				*(int*)value->u.codePosValue = pos->u.intValue;
				game::RemoveVariable(i + 1, threadCountId, inst);
			}

			game::RemoveVariable(0, threadCountId, inst);
		}
	}

	// Restored
	unsigned int GetVariableName(game::scriptInstance_t inst, unsigned int id)
	{
		game::VariableValueInternal *entryValue;

		entryValue = &game::gScrVarGlob[inst].childVariables[id];

		assert((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);
		assert(!IsObject(entryValue));

		return entryValue->w.status >> 8;
	}

	// Completed
	void LinkFile(game::scriptInstance_t inst, unsigned int filePosId, unsigned int fileCountId)
	{
		unsigned int threadCountId;
		game::VariableValue pos;
		unsigned int threadCountPtr;
		unsigned int posId;
		game::VariableValue emptyValue;
		unsigned int nameId;

		emptyValue.type = game::VAR_UNDEFINED;
		emptyValue.u.intValue = 0;

		for ( threadCountPtr = game::FindFirstSibling(inst, fileCountId);
			threadCountPtr;
			threadCountPtr = game::FindNextSibling(inst, threadCountPtr) )
		{
			threadCountId = game::FindObject(inst, threadCountPtr);
			assert(threadCountId);

			nameId = game::GetVariableName(inst, threadCountPtr);
			posId = game::FindVariable(nameId, filePosId, inst);

			if ( posId )
			{
				pos = game::Scr_EvalVariable(inst, posId);
				assert(pos.type == game::VAR_CODEPOS || pos.type == game::VAR_DEVELOPER_CODEPOS);
				assert(pos.u.codePosValue);
				game::LinkThread(inst, threadCountId, &pos, 1);
			}
			else
			{
				game::LinkThread(inst, threadCountId, &emptyValue, 1);
			}
		}

		game::ClearObject(fileCountId, inst);
	}

	// Completed
	void CheckThreadPosition(game::scriptInstance_t inst, unsigned int posId, unsigned int name, unsigned int sourcePos)
	{
		game::VariableValue pos;

		assert(!game::gScrVarPub[inst].evaluate);

		pos = game::Scr_EvalVariable(inst, posId);
		if ( pos.type != game::VAR_UNDEFINED )
		{
			// pluto
			auto* developer = game::Dvar_FindVar("developer");
			if ( pos.u.intValue && developer && developer->current.enabled )
			//
			{
				game::CompileError(inst, sourcePos, "function '%s' already defined in '%s'", game::SL_ConvertToString(name, inst), game::gScrParserPub[inst].sourceBufferLookup[game::Scr_GetSourceBuffer(inst, pos.u.codePosValue)].buf);
			}
			else
			{
				game::CompileError(inst, sourcePos, "function '%s' already defined", game::SL_ConvertToString(name, inst));
			}
		}
	}

	// Completed
	void EmitCallExpression(game::scriptInstance_t inst, game::scr_block_s* block, game::sval_u expr, int bStatement)
	{
		if (expr.node[0].type == game::ENUM_call)
		{
			game::EmitCall(inst, expr.node[1], expr.node[2], bStatement, block);
		}
		else if (expr.node[0].type == game::ENUM_method)
		{
			game::EmitMethod(
				inst,
				expr.node[1],
				expr.node[2],
				expr.node[3],
				expr.node[4],
				bStatement,
				block);
		}
	}

	// Completed
	void EmitCallExpressionFieldObject(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u expr)
	{
		if (expr.node[0].type == game::ENUM_call)
		{
			game::EmitCall(inst, expr.node[1], expr.node[2], 0, block);
			game::EmitCastFieldObject(inst, expr.node[3]);
		}
		else if (expr.node[0].type == game::ENUM_method)
		{
			game::EmitMethod(
				inst,
				expr.node[1],
				expr.node[2],
				expr.node[3],
				expr.node[4],
				0,
				block);
			game::EmitCastFieldObject(inst, expr.node[5]);
		}
	}

	// Completed
	void Scr_CreateVector(game::scriptInstance_t inst, game::VariableCompileValue* constValue, game::VariableValue* value)
	{
		int type;
		int i;
		float vec[3];

		for ( i = 0;
			i < 3;
			++i )
		{
			type = constValue[i].value.type;
			if ( type == game::VAR_FLOAT )
			{
				vec[2 - i] = constValue[i].value.u.floatValue;
			}
			else
			{
				if ( type != game::VAR_INTEGER )
				{
					game::CompileError(inst, constValue[i].sourcePos.stringValue, "type %s is not a float", game::var_typename[type]);
					return;
				}
				vec[2 - i] = (float)constValue[i].value.u.intValue;
			}
		}

		value->type = game::VAR_VECTOR;
		value->u.vectorValue = game::Scr_AllocVector_(inst, vec);
	}

	// Restored
	int GetExpressionCount(game::sval_u exprlist)
	{
		game::sval_u *node;
		int expr_count;

		expr_count = 0;
		for ( node = exprlist.node->node;
			node;
			node = node[1].node )
		{
			++expr_count;
		}

		return expr_count;
	}

	// Completed
	bool EvalPrimitiveExpressionList(game::scriptInstance_t inst, game::sval_u exprlist, game::sval_u sourcePos, game::VariableCompileValue* constValue)
	{
		game::sval_u* node;
		game::VariableCompileValue constValue2[3];
		int expr_count;
		int i;

		assert(constValue);

		expr_count = game::GetExpressionCount(exprlist);
		if ( expr_count == 1 )
		{
			return game::EvalExpression(constValue, inst, exprlist.node->node->node[0]);
		}

		if ( expr_count != 3 )
		{
			return 0;
		}

		i = 0;
		for ( node = exprlist.node->node;
			node;
			node = node[1].node )
		{
			if ( !game::EvalExpression(&constValue2[i], inst, *node->node) )
			{
				return 0;
			}

			++i;
		}

		game::Scr_CreateVector(inst, constValue2, &constValue->value);
		constValue->sourcePos = sourcePos;
		return 1;
	}

	// Completed
	bool EmitOrEvalPrimitiveExpressionList(game::scriptInstance_t inst, game::sval_u exprlist, game::sval_u sourcePos, game::VariableCompileValue* constValue, game::scr_block_s* block)
	{
		bool result;
		game::sval_u *node;
		game::VariableCompileValue constValue2;
		int expr_count;
		bool success;

		assert(constValue);

		expr_count = game::GetExpressionCount(exprlist);
		if ( expr_count == 1 )
		{
			return game::EmitOrEvalExpression(inst, exprlist.node->node->node[0], constValue, block);
		}

		if ( expr_count == 3 )
		{
			success = 1;
			for ( node = exprlist.node->node;
				node;
				node = node[1].node )
			{
				if ( success )
				{
					success = game::EmitOrEvalExpression(inst, *node->node, &constValue2, block);
					if ( success )
					{
						game::Scr_PushValue(inst, &constValue2);
					}
				}
				else
				{
					game::EmitExpression(inst, *node->node, block);
				}
			}

			if ( success )
			{
				assert(game::gScrCompilePub[inst].value_count >= 3);

				game::gScrCompilePub[inst].value_count -= 3;
				game::Scr_CreateVector(inst, &game::gScrCompileGlob[inst].value_start[game::gScrCompilePub[inst].value_count], &constValue->value);
				constValue->sourcePos = sourcePos;
				result = 1;
			}
			else
			{
				game::EmitOpcode(inst, game::OP_vector, -2, 0);
				game::AddOpcodePos(inst, sourcePos.stringValue, 1);
				game::AddExpressionListOpcodePos(inst, exprlist);
				result = 0;
			}
		}
		else
		{
			game::CompileError(inst, sourcePos.stringValue, "expression list must have 1 or 3 parameters");
			result = 0;
		}

		return result;
	}

	// Restored
	game::sval_u * GetSingleParameter(game::sval_u exprlist)
	{
		if ( !exprlist.node->node )
		{
			return 0;
		}

		if ( exprlist.node->node[1].node )
		{
			return 0;
		}

		return exprlist.node->node;
	}
	
	// Restored
	void EmitExpressionFieldObject(game::scriptInstance_t inst, game::sval_u expr, game::sval_u sourcePos, game::scr_block_s *block)
	{
		if ( expr.node[0].type == game::ENUM_primitive_expression)
		{
			game::EmitPrimitiveExpressionFieldObject(inst, expr.node[1], expr.node[2], block);
		}
		else
		{
			game::CompileError(inst, sourcePos.stringValue, "not an object");
		}
	}

	// Completed
	void EmitExpressionListFieldObject(game::scriptInstance_t inst, game::sval_u exprlist, game::sval_u sourcePos, game::scr_block_s* block)
	{
		game::sval_u *node;

		node = game::GetSingleParameter(exprlist);

		if ( node )
		{
			game::EmitExpressionFieldObject(inst, *node->node, node->node[1], block);
		}
		else
		{
			game::CompileError(inst, sourcePos.stringValue, "not an object");
		}
	}

	// Restored
	void EvalInteger(int value, game::sval_u sourcePos, game::VariableCompileValue *constValue)
	{
		assert(constValue);

		constValue->value.type = game::VAR_INTEGER;
		constValue->value.u.intValue = value;
		constValue->sourcePos = sourcePos;
	}

	// Restored
	void EvalFloat(float value, game::sval_u sourcePos, game::VariableCompileValue *constValue)
	{
		assert(constValue);

		constValue->value.type = game::VAR_FLOAT;
		constValue->value.u.floatValue = value;
		constValue->sourcePos = sourcePos;
	}

	// Restored
	void EvalString(unsigned int value, game::sval_u sourcePos, game::VariableCompileValue *constValue)
	{
		assert(constValue);

		constValue->value.type = game::VAR_STRING;
		constValue->value.u.stringValue = value;
		constValue->sourcePos = sourcePos;
	}

	// Restored
	void EvalIString(unsigned int value, game::sval_u sourcePos, game::VariableCompileValue *constValue)
	{
		assert(constValue);

		constValue->value.type = game::VAR_ISTRING;
		constValue->value.u.stringValue = value;
		constValue->sourcePos = sourcePos;
	}

	// Restored
	void EvalUndefined(game::sval_u sourcePos, game::VariableCompileValue *constValue)
	{
		assert(constValue);

		constValue->value.type = game::VAR_UNDEFINED;
		constValue->sourcePos = sourcePos;
	}

	// Completed
	bool EvalPrimitiveExpression(game::scriptInstance_t inst, game::sval_u expr, game::VariableCompileValue* constValue)
	{
		bool result;

		switch ( expr.node[0].type )
		{
		case game::ENUM_integer:
			game::EvalInteger(expr.node[1].intValue, expr.node[2], constValue);
			result = 1;
			break;
		case game::ENUM_float:
			game::EvalFloat(expr.node[1].floatValue, expr.node[2], constValue);
			result = 1;
			break;
		case game::ENUM_minus_integer:
			game::EvalInteger(-expr.node[1].intValue, expr.node[2], constValue);
			result = 1;
			break;
		case game::ENUM_minus_float:
			game::EvalFloat(-expr.node[1].floatValue, expr.node[2], constValue);
			result = 1;
			break;
		case game::ENUM_string:
			game::EvalString(expr.node[1].stringValue, expr.node[2], constValue);
			result = 1;
			break;
		case game::ENUM_istring:
			game::EvalIString(expr.node[1].stringValue, expr.node[2], constValue);
			result = 1;
			break;
		case game::ENUM_undefined:
			game::EvalUndefined(expr.node[1], constValue);
			result = 1;
			break;
		case game::ENUM_expression_list:
			result = game::EvalPrimitiveExpressionList(inst, expr.node[1], expr.node[2], constValue);
			break;
		case game::ENUM_false:
			game::EvalInteger(0, expr.node[1], constValue);
			result = 1;
			break;
		case game::ENUM_true:
			game::EvalInteger(1, expr.node[1], constValue);
			result = 1;
			break;
		default:
			result = 0;
			break;
		}

		return result;
	}

	// Completed
	bool EmitOrEvalPrimitiveExpression(game::scriptInstance_t inst, game::sval_u expr, game::VariableCompileValue* constValue, game::scr_block_s* block)
	{
		bool result;

		switch (expr.node[0].type)
		{
		case game::ENUM_variable:
			game::EmitVariableExpression(inst, expr.node[1], block);
			result = 0;
			break;
		case game::ENUM_function:
			game::EmitGetFunction(inst, expr.node[1], expr.node[2]);
			result = 0;
			break;
		case game::ENUM_call_expression:
			game::EmitCallExpression(inst, block, expr.node[1], 0);
			result = 0;
			break;
		case game::ENUM_self:
			game::EmitSelf(inst, expr.node[1]);
			result = 0;
			break;
		case game::ENUM_level:
			game::EmitLevel(inst, expr.node[1]);
			result = 0;
			break;
		case game::ENUM_game:
			game::EmitGame(inst, expr.node[1]);
			result = 0;
			break;
		case game::ENUM_anim:
			game::EmitAnim(inst, expr.node[1]);
			result = 0;
			break;
		case game::ENUM_expression_list:
			result = game::EmitOrEvalPrimitiveExpressionList(
				inst,
				expr.node[1],
				expr.node[2],
				constValue,
				block);
			break;
		case game::ENUM_size_field:
			game::EmitSize(block, inst, expr.node[1], expr.node[2]);
			result = 0;
			break;
		case game::ENUM_empty_array:
			game::EmitEmptyArray(inst, expr.node[1]);
			result = 0;
			break;
		case game::ENUM_animation:
			game::EmitAnimation(inst, expr.node[1], expr.node[2]);
			result = 0;
			break;
		case game::ENUM_animtree:
			game::EmitAnimTree(inst, expr.node[1]);
			result = 0;
			break;
		case game::ENUM_breakon:
			game::CompileError(inst, expr.node[3].sourcePosValue, "illegal function name");
		default:
			result = game::EvalPrimitiveExpression(inst, expr, constValue);
			break;
		}

		return result;
	}

	// Completed
	void EmitBoolOrExpression(game::scriptInstance_t inst, game::sval_u expr1, game::sval_u expr2, game::sval_u expr1sourcePos, game::sval_u expr2sourcePos, game::scr_block_s* block)
	{
		char *pos;
		unsigned int offset;
		const char *nextPos;

		game::EmitExpression(inst, expr1, block);
		game::EmitOpcode(inst, game::OP_JumpOnTrueExpr, -1, 0);
		game::AddOpcodePos(inst, expr1sourcePos.stringValue, 0);
		game::EmitShort(inst, 0);
		pos = game::gScrCompileGlob[inst].codePos;
		nextPos = game::TempMalloc(0);
		game::EmitExpression(inst, expr2, block);
		game::EmitCastBool(inst, expr2sourcePos);

		offset = game::TempMalloc(0) - nextPos;
		assert(offset < 65536);

		*(short *)pos = (short)offset;
	}

	// Completed
	void EmitBoolAndExpression(game::scriptInstance_t inst, game::sval_u expr1, game::sval_u expr2, game::sval_u expr1sourcePos, game::sval_u expr2sourcePos, game::scr_block_s* block)
	{
		char *pos;
		unsigned int offset;
		const char *nextPos;

		game::EmitExpression(inst, expr1, block);
		game::EmitOpcode(inst, game::OP_JumpOnFalseExpr, -1, 0);
		game::AddOpcodePos(inst, expr1sourcePos.stringValue, 0);
		game::EmitShort(inst, 0);
		pos = game::gScrCompileGlob[inst].codePos;
		nextPos = game::TempMalloc(0);
		game::EmitExpression(inst, expr2, block);
		game::EmitCastBool(inst, expr2sourcePos);

		offset = game::TempMalloc(0) - nextPos;
		assert(offset < 65536);

		*(short *)pos = (short)offset;
	}

	// Copleted
	bool EvalBinaryOperatorExpression(game::scriptInstance_t inst, game::sval_u expr1, game::sval_u expr2, game::sval_u opcode, game::sval_u sourcePos, game::VariableCompileValue* constValue)
	{
		bool result;
		game::VariableCompileValue constValue2;
		game::VariableCompileValue constValue1;

		if ( !game::EvalExpression(&constValue1, inst, expr1) )
		{
			return 0;
		}

		if ( !game::EvalExpression(&constValue2, inst, expr2) )
		{
			return 0;
		}

		game::AddRefToValue(inst, constValue1.value.type, constValue1.value.u);
		game::AddRefToValue(inst, constValue2.value.type, constValue2.value.u);
		game::Scr_EvalBinaryOperator(inst, &constValue2.value, (game::OpcodeVM)opcode.intValue, &constValue1.value);

		if ( game::gScrVarPub[inst].error_message )
		{
			game::CompileError(inst, sourcePos.stringValue, "%s", game::gScrVarPub[inst].error_message);
			result = 0;
		}
		else
		{
			constValue->value.u.intValue = constValue1.value.u.intValue;
			constValue->value.type = constValue1.value.type;
			constValue->sourcePos = sourcePos;
			result = 1;
		}

		return result;
	}

	// Restored
	void Scr_PopValue(game::scriptInstance_t inst)
	{
		assert(game::gScrCompilePub[inst].value_count);
		--game::gScrCompilePub[inst].value_count;
	}

	// Completed
	bool EmitOrEvalBinaryOperatorExpression(game::scriptInstance_t inst, game::sval_u expr1, game::sval_u expr2, game::sval_u opcode, game::sval_u sourcePos, game::VariableCompileValue* constValue, game::scr_block_s* block)
	{
		bool result;
		game::VariableCompileValue constValue2;
		game::VariableCompileValue constValue1;

		if ( !game::EmitOrEvalExpression(inst, expr1, &constValue1, block) )
		{
			game::EmitExpression(inst, expr2, block);
		emitOpcode:
			game::EmitOpcode(inst, (game::OpcodeVM)opcode.type, -1, 0);
			game::AddOpcodePos(inst, sourcePos.stringValue, 0);
			return 0;
		}

		game::Scr_PushValue(inst, &constValue1);

		if ( !game::EmitOrEvalExpression(inst, expr2, &constValue2, block) )
		{
			goto emitOpcode;
		}

		game::Scr_PopValue(inst);
		game::Scr_EvalBinaryOperator(inst, &constValue2.value, (game::OpcodeVM)opcode.intValue, &constValue1.value);

		if ( game::gScrVarPub[inst].error_message )
		{
			game::CompileError(inst, sourcePos.stringValue, "%s", game::gScrVarPub[inst].error_message);
			result = 0;
		}
		else
		{
			constValue->value.u.intValue = constValue1.value.u.intValue;
			constValue->value.type = constValue1.value.type;
			constValue->sourcePos = sourcePos;
			result = 1;
		}

		return result;
	}

	// Restored
	void EmitSetVariableField(game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_SetVariableField, -1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
		// game::EmitAssignmentPos(inst);
	}

	// Completed
	void EmitBinaryEqualsOperatorExpression(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u lhs, game::sval_u rhs, game::sval_u opcode, game::sval_u sourcePos)
	{
		assert(!game::gScrCompileGlob[inst].bConstRefCount);

		game::gScrCompileGlob[inst].bConstRefCount = 1;
		game::EmitVariableExpression(inst, lhs, block);
		assert(game::gScrCompileGlob[inst].bConstRefCount);

		game::gScrCompileGlob[inst].bConstRefCount = 0;
		game::EmitExpression(inst, rhs, block);
		game::EmitOpcode(inst, (game::OpcodeVM)opcode.type, -1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
		game::EmitVariableExpressionRef(inst, lhs, block);
		game::EmitSetVariableField(inst, sourcePos);
	}

	// Completed
	void Scr_CalcLocalVarsVariableExpressionRef(game::scr_block_s* block, game::sval_u expr)
	{
		if (expr.node[0].type == game::ENUM_local_variable)
		{
			game::Scr_RegisterLocalVar(expr.node[1].stringValue, expr.node[2], block);
		}
		else if (expr.node[0].type == game::ENUM_array_variable)
		{
			game::Scr_CalcLocalVarsArrayVariableRef(expr.node[1], block);
		}
	}

	// Completed
	bool EvalExpression(game::VariableCompileValue* constValue, game::scriptInstance_t inst, game::sval_u expr)
	{
		if (expr.node[0].type == game::ENUM_primitive_expression)
		{
			return game::EvalPrimitiveExpression(inst, expr.node[1], constValue);
		}
		if (expr.node[0].type == game::ENUM_binary)
		{
			return game::EvalBinaryOperatorExpression(
				inst,
				expr.node[1],
				expr.node[2],
				expr.node[3],
				expr.node[4],
				constValue);
		}

		return 0;
	}

	// Completed
	bool EmitOrEvalExpression(game::scriptInstance_t inst, game::sval_u expr, game::VariableCompileValue* constValue, game::scr_block_s* block)
	{
		bool result;

		switch ( expr.node[0].type )
		{
		case game::ENUM_duplicate_expression:
			assert(!game::gScrCompileGlob[inst].bConstRefCount);
			game::gScrCompileGlob[inst].bConstRefCount = 1;
			result = game::EmitOrEvalExpression(inst, expr.node[1], constValue, block);
			assert(game::gScrCompileGlob[inst].bConstRefCount);
			game::gScrCompileGlob[inst].bConstRefCount = 0;
			break;
		case game::ENUM_primitive_expression:
			result = EmitOrEvalPrimitiveExpression(inst, expr.node[1], constValue, block);
			break;
		case game::ENUM_bool_or:
			game::EmitBoolOrExpression(inst, expr.node[1], expr.node[2], expr.node[3], expr.node[4], block);
			result = 0;
			break;
		case game::ENUM_bool_and:
			game::EmitBoolAndExpression(inst, expr.node[1], expr.node[2], expr.node[3], expr.node[4], block);
			result = 0;
			break;
		case game::ENUM_binary:
			result = game::EmitOrEvalBinaryOperatorExpression(inst, expr.node[1], expr.node[2], expr.node[3], expr.node[4], constValue, block);
			break;
		case game::ENUM_bool_not:
			game::EmitExpression(inst, expr.node[1], block);
			game::EmitBoolNot(inst, expr.node[2]);
			result = 0;
			break;
		case game::ENUM_bool_complement:
			game::EmitExpression(inst, expr.node[1], block);
			game::EmitBoolComplement(inst, expr.node[2]);
			result = 0;
			break;
		default:
			result = 0;
			break;
		}
		return result;
	}

	// Completed
	void EmitExpression(game::scriptInstance_t inst, game::sval_u expr, game::scr_block_s* block)
	{
		game::VariableCompileValue constValue;

		if (game::EmitOrEvalExpression(inst, expr, &constValue, block))
		{
			game::EmitValue(inst, &constValue);
		}
	}

	// Restored
	void EmitFieldVariableRef(game::scriptInstance_t inst, game::sval_u expr, game::sval_u field, game::sval_u sourcePos, game::scr_block_s *block)
	{
		game::EmitPrimitiveExpressionFieldObject(inst, expr, sourcePos, block);
		game::EmitOpcode(inst, game::OP_EvalFieldVariableRef, 0, 0);
		game::EmitCanonicalString(inst, field.stringValue);
	}

	// Completed
	void EmitVariableExpressionRef(game::scriptInstance_t inst, game::sval_u expr, game::scr_block_s* block)
	{
		switch ( expr.node[0].type )
		{
		case game::ENUM_duplicate_variable:
			assert(!game::gScrCompileGlob[inst].bConstRefCount);
			game::gScrCompileGlob[inst].bConstRefCount = 1;
			game::EmitVariableExpressionRef(inst, expr.node[1], block);
			assert(game::gScrCompileGlob[inst].bConstRefCount);
			game::gScrCompileGlob[inst].bConstRefCount = 0;
			break;
		case game::ENUM_local_variable:
			game::EmitLocalVariableRef(block, inst, expr.node[1], expr.node[2]);
			break;
		case game::ENUM_array_variable:
			game::EmitArrayVariableRef(block, inst, expr.node[1], expr.node[2], expr.node[3], expr.node[4]);
			break;
		case game::ENUM_field_variable:
			game::EmitFieldVariableRef(inst, expr.node[1], expr.node[2], expr.node[3], block);
			break;
		case game::ENUM_self_field:
		case game::ENUM_object:
			if ( game::gScrCompilePub[inst].script_loading )
			{
				game::CompileError(inst, expr.node[2].sourcePosValue, "$ and self field can only be used in the script debugger");
			}
			else
			{
				game::CompileError(inst, expr.node[2].sourcePosValue, "not an lvalue");
			}
			break;
		default:
			return;
		}
	}

	// Completed
	void EmitArrayPrimitiveExpressionRef(game::scriptInstance_t inst, game::sval_u expr, game::sval_u sourcePos, game::scr_block_s* block)
	{
		if (expr.node[0].type == game::ENUM_variable)
		{
			game::EmitVariableExpressionRef(inst, expr.node[1], block);
		}
		else
		{
			if (expr.node[0].type != game::ENUM_game)
			{
				game::CompileError(inst, sourcePos.stringValue, "not an lvalue");
			}

			game::EmitGameRef(inst, expr.node[1]);
		}
	}

	// Restored
	void Scr_CalcLocalVarsArrayPrimitiveExpressionRef(game::sval_u expr, game::scr_block_s *block)
	{
		if ( expr.node[0].type == game::ENUM_variable )
		{
			game::Scr_CalcLocalVarsVariableExpressionRef(block, expr.node[1]);
		}
	}

	// Completed
	void Scr_CalcLocalVarsArrayVariableRef(game::sval_u expr, game::scr_block_s* block)
	{
		game::Scr_CalcLocalVarsArrayPrimitiveExpressionRef(expr, block);
	}

	// Completed
	void EmitPrimitiveExpressionFieldObject(game::scriptInstance_t inst, game::sval_u expr, game::sval_u sourcePos, game::scr_block_s* block)
	{
		switch ( expr.node[0].type )
		{
		case game::ENUM_variable:
			game::EmitVariableExpression(inst, expr.node[1], block);
			game::EmitCastFieldObject(inst, expr.node[2]);
			break;
		case game::ENUM_call_expression:
			game::EmitCallExpressionFieldObject(block, inst, expr.node[1]);
			break;
		case game::ENUM_self:
			game::EmitSelfObject(inst, expr.node[1]);
			break;
		case game::ENUM_level:
			game::EmitLevelObject(inst, expr.node[1]);
			break;
		case game::ENUM_anim:
			game::EmitAnimObject(inst, expr.node[1]);
			break;
		case game::ENUM_expression_list:
			game::EmitExpressionListFieldObject(inst, expr.node[1], sourcePos, block);
			break;
		default:
			game::CompileError(inst, sourcePos.stringValue, "not an object");
			break;
		}
	}

	// Completed
	void ConnectBreakStatements(game::scriptInstance_t inst)
	{
		game::BreakStatementInfo *breakStatement;
		const char *codePos;

		assert(!game::gScrCompilePub[inst].value_count);
		codePos = game::TempMalloc(0);

		for ( breakStatement = game::gScrCompileGlob[inst].currentBreakStatement;
			breakStatement;
			breakStatement = breakStatement->next )
		{
			*(int *)breakStatement->codePos = codePos - breakStatement->nextCodePos;
		}
	}

	// Completed
	void ConnectContinueStatements(game::scriptInstance_t inst)
	{
		game::ContinueStatementInfo *continueStatement;
		const char *codePos;

		codePos = game::TempMalloc(0);
		for ( continueStatement = game::gScrCompileGlob[inst].currentContinueStatement;
			continueStatement;
			continueStatement = continueStatement->next )
		{
			*(int *)continueStatement->codePos = codePos - continueStatement->nextCodePos;
		}
	}

	// Completed
	bool EmitClearVariableExpression(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u expr, game::sval_u rhsSourcePos)
	{
		bool result;
		const char* s;

		switch (expr.node[0].type)
		{
		case game::ENUM_local_variable:
			result = 0;
			break;
		case game::ENUM_array_variable:
			game::EmitClearArrayVariable(
				block,
				inst,
				expr.node[1],
				expr.node[2],
				expr.node[3],
				expr.node[4]);
			result = 1;
			break;
		case game::ENUM_field_variable:
			game::EmitClearFieldVariable(
				block,
				inst,
				expr.node[1],
				expr.node[2],
				expr.node[3],
				rhsSourcePos);
			result = 1;
			break;
		case game::ENUM_self_field:
		case game::ENUM_object:
			s = "not an lvalue";
			if (game::gScrCompilePub[inst].script_loading)
			{
				s = "$ and self field can only be used in the script debugger";
			}
			game::CompileError(inst, expr.node[2].sourcePosValue, s);
		default:
			result = 1;
			break;
		}
		return result;
	}

	// Restored
	BOOL IsUndefinedPrimitiveExpression(game::sval_u expr)
	{
		return expr.node[0].type == game::ENUM_undefined;
	}

	// Restored
	bool IsUndefinedExpression(game::sval_u expr)
	{
		if ( expr.node[0].type == game::ENUM_primitive_expression)
		{
			return game::IsUndefinedPrimitiveExpression(expr.node[1]);
		}

		return 0;
	}

	// Completed
	void EmitAssignmentStatement(game::scriptInstance_t inst, game::sval_u lhs, game::sval_u rhs, game::sval_u sourcePos, game::sval_u rhsSourcePos, game::scr_block_s* block)
	{
		if ( !game::IsUndefinedExpression(rhs) || !game::EmitClearVariableExpression(block, inst, lhs, rhsSourcePos) )
		{
			game::EmitExpression(inst, rhs, block);
			game::EmitVariableExpressionRef(inst, lhs, block);
			game::EmitSetVariableField(inst, sourcePos);
		}
	}

	// Completed
	void EmitCallExpressionStatement(game::scriptInstance_t inst, game::scr_block_s* block, game::sval_u expr)
	{
		game::EmitCallExpression(inst, block, expr, 1);
	}

	// Completed
	void EmitReturnStatement(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u expr, game::sval_u sourcePos)
	{
		if ( !block->abortLevel )
		{
			block->abortLevel = 3;
		}

		game::EmitExpression(inst, expr, block);
		game::EmitReturn(inst);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
	}

	// Completed
	void EmitWaitStatement(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u expr, game::sval_u sourcePos, game::sval_u waitSourcePos)
	{
		game::EmitExpression(inst, expr, block);
		game::EmitOpcode(inst, game::OP_wait, -1, 0);
		game::AddOpcodePos(inst, waitSourcePos.stringValue, 0);
		game::AddOpcodePos(inst, waitSourcePos.stringValue, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
	}

	// Completed
	void EmitWaittillFrameEnd(game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		game::EmitOpcode(inst, game::OP_waittillFrameEnd, 0, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
	}

	// Completed
	void EmitIfStatement(game::scriptInstance_t inst, game::sval_u expr, game::sval_u stmt, game::sval_u sourcePos, int lastStatement, unsigned int endSourcePos, game::scr_block_s* block, game::sval_u* ifStatBlock)
	{
		char *pos;
		unsigned int offset;
		const char *nextPos;

		game::EmitExpression(inst, expr, block);
		game::EmitOpcode(inst, game::OP_JumpOnFalse, -1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
		game::EmitShort(inst, 0);
		pos = game::gScrCompileGlob[inst].codePos;
		nextPos = game::TempMalloc(0);
		game::Scr_TransferBlock(ifStatBlock->block, block);
		game::EmitStatement(inst, stmt, lastStatement, endSourcePos, ifStatBlock->block);

		assert(ifStatBlock->block->localVarsPublicCount == block->localVarsCreateCount);

		game::EmitNOP2(ifStatBlock->block, inst, lastStatement, endSourcePos);
		offset = game::TempMalloc(0) - nextPos;
		assert(offset < 65536);

		*(short *)pos = (short)offset;
	}

	// Restored
	void Scr_CopyBlock(game::scr_block_s *from, game::scr_block_s **to)
	{
		if ( !*to )
		{
			*to = (game::scr_block_s*)game::Hunk_AllocateTempMemoryHigh(sizeof(game::scr_block_s));
		}

		memcpy(*to, from, sizeof(game::scr_block_s));
		(*to)->localVarsPublicCount = 0;
	}

	// Completed
	void Scr_CalcLocalVarsIfStatement(game::scriptInstance_t inst, game::sval_u stmt, game::scr_block_s* block, game::sval_u* ifStatBlock)
	{
		game::Scr_CopyBlock(block, (game::scr_block_s **)ifStatBlock);
		game::Scr_CalcLocalVarsStatement(inst, stmt, ifStatBlock->block);
		game::Scr_MergeChildBlocks((game::scr_block_s **)ifStatBlock, 1, block);
	}

	// Completed
	void EmitIfElseStatement(game::scriptInstance_t inst, game::sval_u expr, game::sval_u stmt1, game::sval_u stmt2, game::sval_u sourcePos, game::sval_u elseSourcePos, int lastStatement, unsigned int endSourcePos, game::scr_block_s* block, game::sval_u* ifStatBlock, game::sval_u* elseStatBlock)
	{
		int checksum;
		unsigned int offset;
		const char *nextPos1;
		char *pos1;
		game::scr_block_s *childBlocks[2];
		const char *nextPos2;
		int childCount;
		const char *pos2;

		childCount = 0;
		game::EmitExpression(inst, expr, block);
		game::EmitOpcode(inst, game::OP_JumpOnFalse, -1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
		game::EmitShort(inst, 0);
		pos1 = game::gScrCompileGlob[inst].codePos;
		nextPos1 = game::TempMalloc(0);

		game::Scr_TransferBlock(ifStatBlock->block, block);
		game::EmitStatement(inst, stmt1, lastStatement, endSourcePos, ifStatBlock->block);
		game::EmitRemoveLocalVars(inst, ifStatBlock->block, ifStatBlock->block);

		if ( !ifStatBlock->block->abortLevel )
		{
			childBlocks[childCount++] = ifStatBlock->block;
		}

		checksum = game::gScrVarPub[inst].checksum;
		if ( (char)lastStatement )
		{
			game::EmitEnd(inst);
			game::EmitCodepos(inst, 0);
			game::AddOpcodePos(inst, endSourcePos, 1);
			pos2 = 0;
			nextPos2 = 0;
		}
		else
		{
			game::EmitOpcode(inst, game::OP_jump, 0, 0);
			game::AddOpcodePos(inst, elseSourcePos.stringValue, 1);
			game::EmitCodepos(inst, 0);
			pos2 = game::gScrCompileGlob[inst].codePos;
			nextPos2 = game::TempMalloc(0);
		}

		game::gScrVarPub[inst].checksum = checksum + 1;
		offset = game::TempMalloc(0) - nextPos1;
		assert(offset < 65536);
		*(short *)pos1 = (short)offset;

		game::Scr_TransferBlock(elseStatBlock->block, block);
		game::EmitStatement(inst, stmt2, lastStatement, endSourcePos, elseStatBlock->block);
		game::EmitNOP2(elseStatBlock->block, inst, lastStatement, endSourcePos);

		if ( !elseStatBlock->block->abortLevel )
		{
			childBlocks[childCount++] = elseStatBlock->block;
		}

		if ( !(char)lastStatement )
		{
			*(int*)pos2 = game::TempMalloc(0) - nextPos2;
		}

		game::Scr_InitFromChildBlocks(childBlocks, childCount, block);
	}

	// Completed
	void Scr_CalcLocalVarsIfElseStatement(game::scriptInstance_t inst, game::sval_u stmt1, game::sval_u stmt2, game::scr_block_s* block, game::sval_u* ifStatBlock, game::sval_u* elseStatBlock)
	{
		game::scr_block_s *childBlocks[2];
		int childCount;
		int abortLevel;

		childCount = 0;
		abortLevel = 3;
		game::Scr_CopyBlock(block, (game::scr_block_s **)ifStatBlock);
		game::Scr_CalcLocalVarsStatement(inst, stmt1, ifStatBlock->block);

		if ( ifStatBlock->node->intValue <= 3 )
		{
			abortLevel = ifStatBlock->node->intValue;

			if ( !abortLevel )
			{
				childBlocks[childCount++] = ifStatBlock->block;
			}
		}

		game::Scr_CopyBlock(block, (game::scr_block_s **)elseStatBlock);
		game::Scr_CalcLocalVarsStatement(inst, stmt2, elseStatBlock->block);
		if ( elseStatBlock->node->intValue <= abortLevel )
		{
			abortLevel = elseStatBlock->node->intValue;

			if ( !abortLevel )
			{
				childBlocks[childCount++] = elseStatBlock->block;
			}
		}

		if ( !block->abortLevel )
		{
			block->abortLevel = abortLevel;
		}

		game::Scr_AppendChildBlocks(block, childBlocks, childCount);
		game::Scr_MergeChildBlocks(childBlocks, childCount, block);
	}

	// Restored
	void Scr_CheckMaxSwitchCases(int count)
	{
		if ( count >= 512 )
		{
			game::Com_Error(game::ERR_DROP, "MAX_SWITCH_CASES exceeded");
		}
	}

	// Completed
	void Scr_AddBreakBlock(game::scriptInstance_t inst, game::scr_block_s* block)
	{
		if ( !block->abortLevel && game::gScrCompileGlob[inst].breakChildBlocks && game::gScrCompilePub[inst].developer_statement != 2 )
		{
			game::Scr_CheckMaxSwitchCases(*game::gScrCompileGlob[inst].breakChildCount);
			game::gScrCompileGlob[inst].breakChildBlocks[(*game::gScrCompileGlob[inst].breakChildCount)++] = block;
		}
	}

	// Completed
	void Scr_AddContinueBlock(game::scriptInstance_t inst, game::scr_block_s* block)
	{
		if ( !block->abortLevel && game::gScrCompileGlob[inst].continueChildBlocks && game::gScrCompilePub[inst].developer_statement != 2 )
		{
			game::Scr_CheckMaxSwitchCases(*game::gScrCompileGlob[inst].continueChildCount);
			game::gScrCompileGlob[inst].continueChildBlocks[(*game::gScrCompileGlob[inst].continueChildCount)++] = block;
		}
	}

	// Completed
	void EmitWhileStatement(game::scriptInstance_t inst, game::sval_u expr, game::sval_u stmt, game::sval_u sourcePos, game::sval_u whileSourcePos, game::scr_block_s* block, game::sval_u* whileStatBlock)
	{
		game::ContinueStatementInfo *oldContinueStatement;
		int breakChildCount;
		int *oldBreakChildCount;
		game::scr_block_s **breakChildBlocks;
		game::BreakStatementInfo *oldBreakStatement;
		bool constConditional;
		unsigned int offset;
		bool bOldCanBreak;
		bool bOldCanContinue;
		int *oldContinueChildCount;
		game::VariableCompileValue constValue;
		const char *pos1;
		const char *nextPos2;
		game::scr_block_s **oldBreakChildBlocks;
		const char *pos2;
		game::scr_block_s **oldContinueChildBlocks;
		game::scr_block_s *oldBreakBlock;

		bOldCanBreak = game::gScrCompileGlob[inst].bCanBreak;
		oldBreakStatement = game::gScrCompileGlob[inst].currentBreakStatement;
		game::gScrCompileGlob[inst].bCanBreak = 0;
		bOldCanContinue = game::gScrCompileGlob[inst].bCanContinue;
		oldContinueStatement = game::gScrCompileGlob[inst].currentContinueStatement;
		game::gScrCompileGlob[inst].bCanContinue = 0;
		game::Scr_TransferBlock(whileStatBlock->block, block);
		game::EmitCreateLocalVars(inst, whileStatBlock->block);

		assert(whileStatBlock->block->localVarsCreateCount <= block->localVarsCount);

		block->localVarsCreateCount = whileStatBlock->block->localVarsCreateCount;

		pos1 = game::TempMalloc(0);
		constConditional = 0;

		if ( game::EmitOrEvalExpression(inst, expr, &constValue, block) )
		{
			if ( constValue.value.type == game::VAR_INTEGER || constValue.value.type == game::VAR_FLOAT )
			{
				game::Scr_CastBool(inst, &constValue.value);
				if ( !constValue.value.u.intValue )
				{
					game::CompileError(inst, sourcePos.stringValue, "conditional expression cannot be always false");
				}

				constConditional = 1;
			}
			else
			{
				game::EmitValue(inst, &constValue);
			}
		}

		oldBreakChildBlocks = game::gScrCompileGlob[inst].breakChildBlocks;
		oldBreakChildCount = game::gScrCompileGlob[inst].breakChildCount;
		oldBreakBlock = game::gScrCompileGlob[inst].breakBlock;
		oldContinueChildBlocks = game::gScrCompileGlob[inst].continueChildBlocks;
		oldContinueChildCount = game::gScrCompileGlob[inst].continueChildCount;
		breakChildCount = 0;
		game::gScrCompileGlob[inst].continueChildBlocks = 0;
		game::gScrCompileGlob[inst].breakBlock = whileStatBlock->block;

		if ( constConditional )
		{
			pos2 = 0;
			nextPos2 = 0;
			breakChildBlocks = (game::scr_block_s **)game::Hunk_AllocateTempMemoryHigh(2048);
			game::gScrCompileGlob[inst].breakChildCount = &breakChildCount;
		}
		else
		{
			game::EmitOpcode(inst, game::OP_JumpOnFalse, -1, 0);
			game::AddOpcodePos(inst, sourcePos.stringValue, 0);
			game::EmitShort(inst, 0);
			pos2 = game::gScrCompileGlob[inst].codePos;
			nextPos2 = game::TempMalloc(0);
			breakChildBlocks = 0;
		}

		game::gScrCompileGlob[inst].breakChildBlocks = breakChildBlocks;
		game::gScrCompileGlob[inst].bCanBreak = 1;
		game::gScrCompileGlob[inst].currentBreakStatement = 0;
		game::gScrCompileGlob[inst].bCanContinue = 1;
		game::gScrCompileGlob[inst].currentContinueStatement = 0;
		game::EmitStatement(inst, stmt, 0, 0, whileStatBlock->block);

		if ( whileStatBlock->block->abortLevel != 3 ) // SCR_ABORT_RETURN
		{
			whileStatBlock->block->abortLevel = 0; // SCR_ABORT_NONE
		}

		game::gScrCompileGlob[inst].bCanBreak = 0;
		game::gScrCompileGlob[inst].bCanContinue = 0;
		game::ConnectContinueStatements(inst);
		game::EmitOpcode(inst, game::OP_jumpback, 0, 0);
		game::AddOpcodePos(inst, whileSourcePos.stringValue, 0);

		if ( stmt.node->type == game::ENUM_statement_list )
		{
			game::AddOpcodePos(inst, stmt.node[3].sourcePosValue, 1); // SOURCE_TYPE_BREAKPOINT
		}

		game::EmitShort(inst, 0);
		offset = game::TempMalloc(0) - pos1;

		assert(offset < 65536);

		*(short *)game::gScrCompileGlob[inst].codePos = offset;

		if ( pos2 )
		{
			offset = game::TempMalloc(0) - nextPos2;
			assert(offset < 65536);
			*(short *)pos2 = offset;
		}

		game::ConnectBreakStatements(inst);
		game::gScrCompileGlob[inst].bCanBreak = bOldCanBreak;
		game::gScrCompileGlob[inst].currentBreakStatement = oldBreakStatement;
		game::gScrCompileGlob[inst].bCanContinue = bOldCanContinue;
		game::gScrCompileGlob[inst].currentContinueStatement = oldContinueStatement;

		if ( constConditional )
		{
			game::Scr_InitFromChildBlocks(breakChildBlocks, breakChildCount, block);
		}

		game::gScrCompileGlob[inst].breakChildBlocks = oldBreakChildBlocks;
		game::gScrCompileGlob[inst].breakChildCount = oldBreakChildCount;
		game::gScrCompileGlob[inst].breakBlock = oldBreakBlock;
		game::gScrCompileGlob[inst].continueChildBlocks = oldContinueChildBlocks;
		game::gScrCompileGlob[inst].continueChildCount = oldContinueChildCount;
	}

	// Completed
	void Scr_CalcLocalVarsWhileStatement(game::scriptInstance_t inst, game::sval_u expr, game::sval_u stmt, game::scr_block_s* block, game::sval_u* whileStatBlock)
	{
		int breakChildCount;
		int *oldBreakChildCount;
		game::scr_block_s **breakChildBlocks;
		bool constConditional;
		int continueChildCount;
		int *oldContinueChildCount;
		game::VariableCompileValue constValue;
		int i;
		game::scr_block_s **continueChildBlocks;
		game::scr_block_s **oldBreakChildBlocks;
		int abortLevel;
		game::scr_block_s **oldContinueChildBlocks;

		constConditional = 0;
		if ( game::EvalExpression(&constValue, inst, expr) )
		{
			if ( constValue.value.type == game::VAR_INTEGER || constValue.value.type == game::VAR_FLOAT )
			{
				game::Scr_CastBool(inst, &constValue.value);
				if ( constValue.value.u.intValue )
				{
					constConditional = 1;
				}
			}

			game::RemoveRefToValueInternal(inst, constValue.value.type, constValue.value.u);
		}

		oldBreakChildBlocks = game::gScrCompileGlob[inst].breakChildBlocks;
		oldBreakChildCount = game::gScrCompileGlob[inst].breakChildCount;
		oldContinueChildBlocks = game::gScrCompileGlob[inst].continueChildBlocks;
		oldContinueChildCount = game::gScrCompileGlob[inst].continueChildCount;
		breakChildCount = 0;
		continueChildCount = 0;
		continueChildBlocks = (game::scr_block_s **)game::Hunk_AllocateTempMemoryHigh(2048);
		game::gScrCompileGlob[inst].continueChildBlocks = continueChildBlocks;
		game::gScrCompileGlob[inst].continueChildCount = &continueChildCount;
		abortLevel = block->abortLevel;

		if ( constConditional )
		{
			breakChildBlocks = (game::scr_block_s **)game::Hunk_AllocateTempMemoryHigh(2048);
			game::gScrCompileGlob[inst].breakChildCount = &breakChildCount;
		}
		else
		{
			breakChildBlocks = 0;
		}

		game::gScrCompileGlob[inst].breakChildBlocks = breakChildBlocks;
		game::Scr_CopyBlock(block, (game::scr_block_s **)whileStatBlock);
		game::Scr_CalcLocalVarsStatement(inst, stmt, whileStatBlock->block);
		game::Scr_AddContinueBlock(inst, whileStatBlock->block);

		for ( i = 0;
			i < continueChildCount;
			++i )
		{
			game::Scr_AppendChildBlocks(block, &continueChildBlocks[i], 1);
		}

		if ( constConditional )
		{
			game::Scr_AppendChildBlocks(block, breakChildBlocks, breakChildCount);
		}

		game::Scr_MergeChildBlocks((game::scr_block_s **)whileStatBlock, 1, block);
		game::gScrCompileGlob[inst].breakChildBlocks = oldBreakChildBlocks;
		game::gScrCompileGlob[inst].breakChildCount = oldBreakChildCount;
		game::gScrCompileGlob[inst].continueChildBlocks = oldContinueChildBlocks;
		game::gScrCompileGlob[inst].continueChildCount = oldContinueChildCount;
	}

	// Completed
	void EmitForStatement(game::scriptInstance_t inst, game::sval_u stmt1, game::sval_u expr, game::sval_u stmt2, game::sval_u stmt, game::sval_u sourcePos, game::sval_u forSourcePos, game::scr_block_s* block, game::sval_u* forStatBlock, game::sval_u* forStatPostBlock)
	{
		game::ContinueStatementInfo *oldContinueStatement;
		int breakChildCount;
		int *oldBreakChildCount;
		game::scr_block_s **breakChildBlocks;
		game::BreakStatementInfo *oldBreakStatement;
		bool constConditional;
		unsigned int offset;
		bool bOldCanBreak;
		bool bOldCanContinue;
		int continueChildCount;
		int *oldContinueChildCount;
		game::VariableCompileValue constValue;
		const char *pos1;
		const char *nextPos2;
		game::scr_block_s **continueChildBlocks;
		game::scr_block_s **oldBreakChildBlocks;
		const char *pos2;
		game::scr_block_s **oldContinueChildBlocks;
		game::scr_block_s *oldBreakBlock;

		bOldCanBreak = game::gScrCompileGlob[inst].bCanBreak;
		oldBreakStatement = game::gScrCompileGlob[inst].currentBreakStatement;
		game::gScrCompileGlob[inst].bCanBreak = 0;
		bOldCanContinue = game::gScrCompileGlob[inst].bCanContinue;
		oldContinueStatement = game::gScrCompileGlob[inst].currentContinueStatement;
		game::gScrCompileGlob[inst].bCanContinue = 0;
		game::EmitStatement(inst, stmt1, 0, 0, block);
		game::Scr_TransferBlock(forStatBlock->block, block);
		game::EmitCreateLocalVars(inst, forStatBlock->block);
		
		assert(forStatBlock->block->localVarsCreateCount <= block->localVarsCount);

		block->localVarsCreateCount = forStatBlock->block->localVarsCreateCount;
		game::Scr_TransferBlock(forStatPostBlock->block, block);

		pos1 = game::TempMalloc(0);
		if ( expr.node[0].type == game::ENUM_expression)
		{
			constConditional = 0;
			if ( game::EmitOrEvalExpression(inst, expr.node[1], &constValue, block) )
			{
				if ( constValue.value.type == game::VAR_INTEGER || constValue.value.type == game::VAR_FLOAT )
				{
					game::Scr_CastBool(inst, &constValue.value);
					if ( !constValue.value.u.intValue )
					{
						game::CompileError(inst, sourcePos.stringValue, "conditional expression cannot be always false");
					}

					constConditional = 1;
				}
				else
				{
					game::EmitValue(inst, &constValue);
				}
			}
		}
		else
		{
			constConditional = 1;
		}

		oldBreakChildBlocks = game::gScrCompileGlob[inst].breakChildBlocks;
		oldBreakChildCount = game::gScrCompileGlob[inst].breakChildCount;
		oldBreakBlock = game::gScrCompileGlob[inst].breakBlock;
		oldContinueChildBlocks = game::gScrCompileGlob[inst].continueChildBlocks;
		oldContinueChildCount = game::gScrCompileGlob[inst].continueChildCount;
		breakChildCount = 0;
		continueChildCount = 0;
		continueChildBlocks = (game::scr_block_s **)game::Hunk_AllocateTempMemoryHigh(2048);
		game::gScrCompileGlob[inst].continueChildBlocks = continueChildBlocks;
		game::gScrCompileGlob[inst].continueChildCount = &continueChildCount;
		game::gScrCompileGlob[inst].breakBlock = forStatBlock->block;

		if ( constConditional )
		{
			pos2 = 0;
			nextPos2 = 0;
			breakChildBlocks = (game::scr_block_s **)game::Hunk_AllocateTempMemoryHigh(2048);
			game::gScrCompileGlob[inst].breakChildCount = &breakChildCount;
		}
		else
		{
			game::EmitOpcode(inst, game::OP_JumpOnFalse, -1, 0);
			game::AddOpcodePos(inst, sourcePos.stringValue, 0);
			game::EmitShort(inst, 0);
			pos2 = game::gScrCompileGlob[inst].codePos;
			nextPos2 = game::TempMalloc(0);
			breakChildBlocks = 0;
		}

		game::gScrCompileGlob[inst].breakChildBlocks = breakChildBlocks;
		game::gScrCompileGlob[inst].bCanBreak = 1;
		game::gScrCompileGlob[inst].currentBreakStatement = 0;
		game::gScrCompileGlob[inst].bCanContinue = 1;
		game::gScrCompileGlob[inst].currentContinueStatement = 0;

		game::EmitStatement(inst, stmt, 0, 0, forStatBlock->block);
		game::Scr_AddContinueBlock(inst, forStatBlock->block);
		game::gScrCompileGlob[inst].bCanBreak = 0;
		game::gScrCompileGlob[inst].bCanContinue = 0;
		game::ConnectContinueStatements(inst);
		game::Scr_InitFromChildBlocks(continueChildBlocks, continueChildCount, forStatPostBlock->block);
		game::EmitStatement(inst, stmt2, 0, 0, forStatPostBlock->block);
		game::EmitOpcode(inst, game::OP_jumpback, 0, 0);
		game::AddOpcodePos(inst, forSourcePos.stringValue, 0);

		if ( stmt.node[0].type == game::ENUM_statement_list)
		{
			game::AddOpcodePos(inst, stmt.node[3].sourcePosValue, 1);
		}

		game::EmitShort(inst, 0);

		offset = game::TempMalloc(0) - pos1;
		assert(offset < 65536);
		*(short *)game::gScrCompileGlob[inst].codePos = offset;
		if ( pos2 )
		{
			offset = game::TempMalloc(0) - nextPos2;
			assert(offset < 65536);
			*(short *)pos2 = offset;
		}

		game::ConnectBreakStatements(inst);
		game::gScrCompileGlob[inst].bCanBreak = bOldCanBreak;
		game::gScrCompileGlob[inst].currentBreakStatement = oldBreakStatement;
		game::gScrCompileGlob[inst].bCanContinue = bOldCanContinue;
		game::gScrCompileGlob[inst].currentContinueStatement = oldContinueStatement;

		if ( constConditional )
		{
			game::Scr_InitFromChildBlocks(breakChildBlocks, breakChildCount, block);
		}

		game::gScrCompileGlob[inst].breakChildBlocks = oldBreakChildBlocks;
		game::gScrCompileGlob[inst].breakChildCount = oldBreakChildCount;
		game::gScrCompileGlob[inst].breakBlock = oldBreakBlock;
		game::gScrCompileGlob[inst].continueChildBlocks = oldContinueChildBlocks;
		game::gScrCompileGlob[inst].continueChildCount = oldContinueChildCount;
	}

	// Completed
	void Scr_CalcLocalVarsForStatement(game::scriptInstance_t inst, game::sval_u stmt1, game::sval_u expr, game::sval_u stmt2, game::sval_u stmt, game::scr_block_s* block, game::sval_u* forStatBlock, game::sval_u* forStatPostBlock)
	{
		int breakChildCount;
		int *oldBreakChildCount;
		game::scr_block_s **breakChildBlocks;
		bool constConditional;
		int continueChildCount;
		int *oldContinueChildCount;
		game::VariableCompileValue constValue;
		int i;
		game::scr_block_s **continueChildBlocks;
		game::scr_block_s **oldBreakChildBlocks;
		int abortLevel;
		game::scr_block_s **oldContinueChildBlocks;

		game::Scr_CalcLocalVarsStatement(inst, stmt1, block);
		if ( expr.node[0].type == game::ENUM_expression)
		{
			constConditional = 0;
			if ( game::EvalExpression(&constValue, inst, expr.node[1]) )
			{
				if ( constValue.value.type == game::VAR_INTEGER || constValue.value.type == game::VAR_FLOAT )
				{
					game::Scr_CastBool(inst, &constValue.value);
					if ( constValue.value.u.intValue )
					{
						constConditional = 1;
					}
				}

				game::RemoveRefToValueInternal(inst, constValue.value.type, constValue.value.u);
			}
		}
		else
		{
			constConditional = 1;
		}

		oldBreakChildBlocks = game::gScrCompileGlob[inst].breakChildBlocks;
		oldBreakChildCount = game::gScrCompileGlob[inst].breakChildCount;
		oldContinueChildBlocks = game::gScrCompileGlob[inst].continueChildBlocks;
		oldContinueChildCount = game::gScrCompileGlob[inst].continueChildCount;
		breakChildCount = 0;
		continueChildCount = 0;
		continueChildBlocks = (game::scr_block_s **)game::Hunk_AllocateTempMemoryHigh(2048);
		game::gScrCompileGlob[inst].continueChildBlocks = continueChildBlocks;
		game::gScrCompileGlob[inst].continueChildCount = &continueChildCount;
		abortLevel = block->abortLevel;

		if ( constConditional )
		{
			breakChildBlocks = (game::scr_block_s **)game::Hunk_AllocateTempMemoryHigh(2048);
			game::gScrCompileGlob[inst].breakChildCount = &breakChildCount;
		}
		else
		{
			breakChildBlocks = 0;
		}

		game::gScrCompileGlob[inst].breakChildBlocks = breakChildBlocks;
		game::Scr_CopyBlock(block, (game::scr_block_s **)forStatBlock);
		game::Scr_CopyBlock(block, (game::scr_block_s **)forStatPostBlock);
		game::Scr_CalcLocalVarsStatement(inst, stmt, forStatBlock->block);
		game::Scr_AddContinueBlock(inst, forStatBlock->block);

		for ( i = 0;
			i < continueChildCount;
			++i )
		{
			game::Scr_AppendChildBlocks(block, &continueChildBlocks[i], 1);
		}

		game::Scr_CalcLocalVarsStatement(inst, stmt2, forStatPostBlock->block);
		game::Scr_AppendChildBlocks(block, (game::scr_block_s **)forStatPostBlock, 1);
		game::Scr_MergeChildBlocks((game::scr_block_s **)forStatPostBlock, 1, block);

		if ( constConditional )
		{
			game::Scr_AppendChildBlocks(block, breakChildBlocks, breakChildCount);
		}

		game::Scr_MergeChildBlocks((game::scr_block_s **)forStatBlock, 1, block);
		game::gScrCompileGlob[inst].breakChildBlocks = oldBreakChildBlocks;
		game::gScrCompileGlob[inst].breakChildCount = oldBreakChildCount;
		game::gScrCompileGlob[inst].continueChildBlocks = oldContinueChildBlocks;
		game::gScrCompileGlob[inst].continueChildCount = oldContinueChildCount;
	}

	// Completed
	void EmitIncStatement(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u expr, game::sval_u sourcePos)
	{
		assert(!game::gScrCompileGlob[inst].forceNotCreate);
		game::gScrCompileGlob[inst].forceNotCreate = 1;
		game::EmitVariableExpressionRef(inst, expr, block);
		assert(game::gScrCompileGlob[inst].forceNotCreate);
		game::gScrCompileGlob[inst].forceNotCreate = 0;
		game::EmitOpcode(inst, game::OP_inc, 1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
		game::EmitSetVariableField(inst, sourcePos);
	}

	// Completed
	void EmitDecStatement(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u expr, game::sval_u sourcePos)
	{
		assert(!game::gScrCompileGlob[inst].forceNotCreate);
		game::gScrCompileGlob[inst].forceNotCreate = 1;
		game::EmitVariableExpressionRef(inst, expr, block);
		assert(game::gScrCompileGlob[inst].forceNotCreate);
		game::gScrCompileGlob[inst].forceNotCreate = 0;
		game::EmitOpcode(inst, game::OP_dec, 1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
		game::EmitSetVariableField(inst, sourcePos);
	}

	// REstored
	void Scr_CalcLocalVarsSafeSetVariableField(game::sval_u expr, game::sval_u sourcePos, game::scr_block_s *block)
	{
		game::Scr_RegisterLocalVar(expr.stringValue, sourcePos, block);
	}

	// Completed
	void Scr_CalcLocalVarsFormalParameterListInternal(game::sval_u* node, game::scr_block_s* block)
	{
		while ( 1 )
		{
			node = node[1].node;
			if ( !node )
			{
				break;
			}

			game::Scr_CalcLocalVarsSafeSetVariableField(*node->node, node[1], block);
		}
	}

	// Restored
	void EmitFormalWaittillParameterListRefInternal(game::scriptInstance_t inst, game::sval_u *node, game::scr_block_s *block)
	{
		while ( 1 )
		{
			node = node[1].node;
			if ( !node )
			{
				break;
			}

			game::EmitSafeSetWaittillVariableField(block, inst, *node->node, node->node[1]);
		}
	}

	// Completed
	void EmitWaittillStatement(game::scriptInstance_t inst, game::sval_u obj, game::sval_u exprlist, game::sval_u sourcePos, game::sval_u waitSourcePos, game::scr_block_s* block)
	{
		game::sval_u *node;

		node = exprlist.node->node[1].node;

		assert(node);

		game::EmitExpression(inst, *node->node, block);
		game::EmitPrimitiveExpression(inst, obj, block);
		game::EmitOpcode(inst, game::OP_waittill, -2, 0);
		game::AddOpcodePos(inst, waitSourcePos.stringValue, 0);
		game::AddOpcodePos(inst, waitSourcePos.stringValue, 0); // SOURCE_TYPE_NONE
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
		game::AddOpcodePos(inst, node->node[1].sourcePosValue, 0);
		game::EmitFormalWaittillParameterListRefInternal(inst, node, block);
		game::EmitOpcode(inst, game::OP_clearparams, 0, 0);
	}

	// Completed
	void EmitWaittillmatchStatement(game::scriptInstance_t inst, game::sval_u obj, game::sval_u exprlist, game::sval_u sourcePos, game::sval_u waitSourcePos, game::scr_block_s* block)
	{
		game::sval_u *node;
		game::sval_u *nodea;
		int exprCount;

		node = exprlist.node->node[1].node;
		assert(node);

		for ( exprCount = 0;
			;
			++exprCount )
		{
			node = node[1].node;
			if ( !node )
			{
				break;
			}

			game::EmitExpression(inst, *node->node, block);
		}

		nodea = exprlist.node->node[1].node;
		assert(nodea);

		game::EmitExpression(inst, *nodea->node, block);
		game::EmitPrimitiveExpression(inst, obj, block);
		game::EmitOpcode(inst, game::OP_waittillmatch, -2 - exprCount, 0);
		game::AddOpcodePos(inst, waitSourcePos.stringValue, 0);
		game::AddOpcodePos(inst, waitSourcePos.stringValue, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
		game::AddOpcodePos(inst, nodea->node[1].sourcePosValue, 0);

		while ( 1 )
		{
			nodea = nodea[1].node;
			if ( !nodea )
			{
				break;
			}

			game::AddOpcodePos(inst, nodea->node[1].stringValue, 0);
		}

		assert(exprCount < 256);

		game::EmitByte(inst, exprCount);
		game::EmitOpcode(inst, game::OP_clearparams, 0, 0);
	}

	// Completed
	void EmitNotifyStatement(game::scriptInstance_t inst, game::sval_u obj, game::sval_u exprlist, game::sval_u sourcePos, game::sval_u notifySourcePos, game::scr_block_s* block)
	{
		game::sval_u *node;
		game::sval_u *start_node;
		int expr_count;

		game::EmitOpcode(inst, game::OP_voidCodepos, 1, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
		expr_count = 0;
		start_node = 0;

		for ( node = exprlist.node->node;
			node;
			node = node[1].node )
		{
			start_node = node;
			game::EmitExpression(inst, *node->node, block);
			++expr_count;
		}

		assert(start_node);

		game::EmitPrimitiveExpression(inst, obj, block);
		game::EmitOpcode(inst, game::OP_notify, -expr_count - 2, 0);
		game::AddOpcodePos(inst, notifySourcePos.stringValue, 16);
		game::AddOpcodePos(inst, start_node->node[1].stringValue, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
	}

	// Completed
	void EmitEndOnStatement(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u obj, game::sval_u expr, game::sval_u sourcePos, game::sval_u exprSourcePos)
	{
		game::EmitExpression(inst, expr, block);
		game::EmitPrimitiveExpression(inst, obj, block);
		game::EmitOpcode(inst, game::OP_endon, -2, 0);
		game::AddOpcodePos(inst, exprSourcePos.stringValue, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
	}

	// Completed
	int CompareCaseInfo(const void* elem1, const void* elem2)
	{
		int result;

		if (*(int*)elem1 <= *(int*)elem2)
		{
			result = *(int*)elem1 < *(int*)elem2;
		}
		else
		{
			result = -1;
		}

		return result;
	}

	// Completed
	void EmitCaseStatement(game::scriptInstance_t inst, game::sval_u expr, game::sval_u sourcePos)
	{
		unsigned int name;
		game::sval_u namea;

		if ( expr.node[0].type == game::ENUM_integer)
		{
			if ( game::IsValidArrayIndex(inst, expr.node[1].idValue) )
			{
				name = game::GetInternalVariableIndex(inst, expr.node[1].idValue);
				game::EmitCaseStatementInfo(inst, name, sourcePos);
			}
			else
			{
				game::CompileError(inst, sourcePos.stringValue, game::va("case index %d out of range", expr.node[1].intValue));
			}
		}
		else if ( expr.node[0].type == game::ENUM_string )
		{
			namea = expr.node[1];
			game::CompileTransferRefToString(namea.stringValue, inst, 1u);
			game::EmitCaseStatementInfo(inst, namea.stringValue, sourcePos);
		}
		else
		{
			game::CompileError(inst, sourcePos.stringValue, "case expression must be an int or string");
		}
	}

	// Restored
	void EmitDefaultStatement(game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		game::EmitCaseStatementInfo(inst, 0, sourcePos);
	}

	// Restored
	char Scr_IsLastStatement(game::scriptInstance_t inst, game::sval_u *node)
	{
		if ( !node )
		{
			return 1;
		}

		if ( game::gScrVarPub[inst].developer_script )
		{
			return 0;
		}

		while ( node )
		{
			if ( node->node[0].type != game::ENUM_developer_statement_list )
			{
				return 0;
			}

			node = node[1].node;
		}

		return 1;
	}

	// Completed
	void EmitSwitchStatementList(game::scriptInstance_t inst, game::sval_u val, int lastStatement, unsigned int endSourcePos, game::scr_block_s* block)
	{
		game::sval_u *node;
		game::sval_u *nextNode;
		int breakChildCount;
		game::scr_block_s **breakChildBlocks;
		int *oldBreakChildCount;
		bool hasDefault;
		game::scr_block_s **oldBreakChildBlocks;
		game::scr_block_s *oldBreakBlock;

		oldBreakChildBlocks = game::gScrCompileGlob[inst].breakChildBlocks;
		oldBreakChildCount = game::gScrCompileGlob[inst].breakChildCount;
		oldBreakBlock = game::gScrCompileGlob[inst].breakBlock;
		breakChildCount = 0;
		breakChildBlocks = (game::scr_block_s **)game::Hunk_AllocateTempMemoryHigh(2048);
		game::gScrCompileGlob[inst].breakChildBlocks = breakChildBlocks;
		game::gScrCompileGlob[inst].breakChildCount = &breakChildCount;
		game::gScrCompileGlob[inst].breakBlock = 0;
		hasDefault = 0;

		for ( node = val.node->node[1].node;
			node;
			node = nextNode )
		{
			nextNode = node[1].node;
			if ( node->node->type == game::ENUM_case || node->node->type == game::ENUM_default )
			{
				if ( game::gScrCompileGlob[inst].breakBlock )
				{
					assert(game::gScrCompileGlob[inst].bCanBreak);
					game::gScrCompileGlob[inst].bCanBreak = 0;
					game::EmitRemoveLocalVars(inst, game::gScrCompileGlob[inst].breakBlock, game::gScrCompileGlob[inst].breakBlock);
				}

				if ( node->node->type == game::ENUM_case )
				{
					game::gScrCompileGlob[inst].breakBlock = node->node[3].block;
					game::EmitCaseStatement(inst, node->node[1], node->node[2]);
				}
				else
				{
					game::gScrCompileGlob[inst].breakBlock = node->node[2].block;
					hasDefault = 1;
					game::EmitDefaultStatement(inst, node->node[1]);
				}

				game::Scr_TransferBlock(game::gScrCompileGlob[inst].breakBlock, block);
				assert(!game::gScrCompileGlob[inst].bCanBreak);
				game::gScrCompileGlob[inst].bCanBreak = 1;
			}
			else
			{
				if ( !game::gScrCompileGlob[inst].breakBlock )
				{
					game::CompileError(inst, endSourcePos, "missing case statement");
					return;
				}

				if ( lastStatement && game::Scr_IsLastStatement(inst, nextNode) )
				{
					game::EmitStatement(inst, *node, 1, endSourcePos, game::gScrCompileGlob[inst].breakBlock);
				}
				else
				{
					game::EmitStatement(inst, *node, 0, endSourcePos, game::gScrCompileGlob[inst].breakBlock);
				}

				if ( game::gScrCompileGlob[inst].breakBlock && game::gScrCompileGlob[inst].breakBlock->abortLevel )
				{
					game::gScrCompileGlob[inst].breakBlock = 0;
					assert(game::gScrCompileGlob[inst].bCanBreak);
					game::gScrCompileGlob[inst].bCanBreak = 0;
				}
			}
		}

		if ( game::gScrCompileGlob[inst].breakBlock )
		{
			assert(game::gScrCompileGlob[inst].bCanBreak);
			game::gScrCompileGlob[inst].bCanBreak = 0;
			game::EmitRemoveLocalVars(inst, game::gScrCompileGlob[inst].breakBlock, game::gScrCompileGlob[inst].breakBlock);
		}

		if ( hasDefault )
		{
			if ( game::gScrCompileGlob[inst].breakBlock )
			{
				game::Scr_AddBreakBlock(inst, game::gScrCompileGlob[inst].breakBlock);
			}
			game::Scr_InitFromChildBlocks(breakChildBlocks, breakChildCount, block);
		}

		game::gScrCompileGlob[inst].breakChildBlocks = oldBreakChildBlocks;
		game::gScrCompileGlob[inst].breakChildCount = oldBreakChildCount;
		game::gScrCompileGlob[inst].breakBlock = oldBreakBlock;
	}

	// Completed
	void Scr_CalcLocalVarsSwitchStatement(game::scriptInstance_t inst, game::sval_u stmtlist, game::scr_block_s* block)
	{
		game::sval_u *node;
		int breakChildCount;
		game::scr_block_s **breakChildBlocks;
		int *oldBreakChildCount;
		bool hasDefault;
		game::scr_block_s *currentBlock;
		game::scr_block_s **childBlocks;
		game::scr_block_s **oldBreakChildBlocks;
		int childCount;
		int abortLevel;

		abortLevel = 3;
		oldBreakChildBlocks = game::gScrCompileGlob[inst].breakChildBlocks;
		oldBreakChildCount = game::gScrCompileGlob[inst].breakChildCount;
		breakChildCount = 0;
		breakChildBlocks = (game::scr_block_s **)game::Hunk_AllocateTempMemoryHigh(2048);
		game::gScrCompileGlob[inst].breakChildBlocks = breakChildBlocks;
		game::gScrCompileGlob[inst].breakChildCount = &breakChildCount;
		childCount = 0;
		currentBlock = 0;
		hasDefault = 0;
		childBlocks = (game::scr_block_s**)game::Hunk_AllocateTempMemoryHigh(2048);

		for ( node = stmtlist.node->node[1].node;
			node;
			node = node[1].node )
		{
			if ( node->node[0].type == game::ENUM_case || node->node[0].type == game::ENUM_default)
			{
				currentBlock = 0;
				game::Scr_CopyBlock(block, &currentBlock);

				if ( node->node[0].type == game::ENUM_case )
				{
					node->node[3].block = currentBlock;
				}
				else
				{
					node->node[2].block = currentBlock;
					hasDefault = 1;
				}
			}
			else if ( currentBlock )
			{
				game::Scr_CalcLocalVarsStatement(inst, *node, currentBlock);
				if ( currentBlock->abortLevel )
				{
					if ( currentBlock->abortLevel == 2 )
					{
						currentBlock->abortLevel = 0;
						abortLevel = 0;
						game::Scr_CheckMaxSwitchCases(childCount);
						childBlocks[childCount++] = currentBlock;
					}
					else if ( currentBlock->abortLevel <= abortLevel )
					{
						abortLevel = currentBlock->abortLevel;
					}

					currentBlock = 0;
				}
			}
		}

		if ( hasDefault )
		{
			if ( currentBlock )
			{
				game::Scr_AddBreakBlock(inst, currentBlock);
				game::Scr_CheckMaxSwitchCases(childCount);
				childBlocks[childCount++] = currentBlock;
			}

			if ( !block->abortLevel )
			{
				block->abortLevel = abortLevel;
			}

			game::Scr_AppendChildBlocks(block, breakChildBlocks, breakChildCount);
			game::Scr_MergeChildBlocks(childBlocks, childCount, block);
		}

		game::gScrCompileGlob[inst].breakChildBlocks = oldBreakChildBlocks;
		game::gScrCompileGlob[inst].breakChildCount = oldBreakChildCount;
	}

	// Completed
	void EmitSwitchStatement(game::scriptInstance_t inst, game::sval_u expr, game::sval_u stmtlist, game::sval_u sourcePos, int lastStatement, unsigned int endSourcePos, game::scr_block_s* block)
	{
		game::CaseStatementInfo *oldCaseStatement;
		char *pos3;
		game::BreakStatementInfo *oldBreakStatement;
		bool bOldCanBreak;
		char *nextPos1;
		game::CaseStatementInfo *caseStatement;
		game::CaseStatementInfo *caseStatementa;
		char *pos1;
		int num;
		char *pos2;

		oldCaseStatement = game::gScrCompileGlob[inst].currentCaseStatement;
		bOldCanBreak = game::gScrCompileGlob[inst].bCanBreak;
		oldBreakStatement = game::gScrCompileGlob[inst].currentBreakStatement;

		game::gScrCompileGlob[inst].bCanBreak = 0;
		game::EmitExpression(inst, expr, block);
		game::EmitOpcode(inst, game::OP_switch, -1, 0);
		game::EmitCodepos(inst, 0);

		pos1 = game::gScrCompileGlob[inst].codePos;
		nextPos1 = game::TempMalloc(0);
		game::gScrCompileGlob[inst].currentCaseStatement = 0;
		game::gScrCompileGlob[inst].currentBreakStatement = 0;
		game::EmitSwitchStatementList(inst, stmtlist, lastStatement, endSourcePos, block);
		game::EmitOpcode(inst, game::OP_endswitch, 0, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
		game::EmitShort(inst, 0);

		pos2 = game::gScrCompileGlob[inst].codePos;
		*(int *)pos1 = pos2 - nextPos1;
		pos3 = game::TempMalloc(0);
		num = 0;
		caseStatement = game::gScrCompileGlob[inst].currentCaseStatement;
		while ( caseStatement )
		{
			game::EmitCodepos(inst, caseStatement->name);
			game::EmitCodepos(inst, (int)caseStatement->codePos);
			caseStatement = caseStatement->next;
			++num;
		}

		*(short *)pos2 = num;
		qsort(pos3, num, 8u, game::CompareCaseInfo);

		while ( num > 1 )
		{
			if ( *(int *)pos3 == *((int *)pos3 + 2) )
			{
				for ( caseStatementa = game::gScrCompileGlob[inst].currentCaseStatement;
					caseStatementa;
					caseStatementa = caseStatementa->next )
				{
					if ( caseStatementa->name == *(unsigned int *)pos3 )
					{
						game::CompileError(inst, caseStatementa->sourcePos, "duplicate case expression");
						return;
					}
				}
			}
			--num;
			pos3 += 8;
		}

		game::ConnectBreakStatements(inst);
		game::gScrCompileGlob[inst].currentCaseStatement = oldCaseStatement;
		game::gScrCompileGlob[inst].bCanBreak = bOldCanBreak;
		game::gScrCompileGlob[inst].currentBreakStatement = oldBreakStatement;
	}

	// Completed
	void EmitCaseStatementInfo(game::scriptInstance_t inst, unsigned int name, game::sval_u sourcePos)
	{
		game::CaseStatementInfo *newCaseStatement;

		if ( game::gScrCompilePub[inst].developer_statement == 2 )
		{
			assert(!game::gScrVarPub[inst].developer_script);
		}
		else
		{
			newCaseStatement = (game::CaseStatementInfo *)game::Hunk_AllocateTempMemoryHigh(sizeof(game::CaseStatementInfo));
			newCaseStatement->name = name;
			newCaseStatement->codePos = game::TempMalloc(0);
			newCaseStatement->sourcePos = sourcePos.stringValue;
			newCaseStatement->next = game::gScrCompileGlob[inst].currentCaseStatement;
			game::gScrCompileGlob[inst].currentCaseStatement = newCaseStatement;
		}
	}

	// Completed
	void EmitBreakStatement(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		game::BreakStatementInfo *newBreakStatement;

		if ( game::gScrCompileGlob[inst].bCanBreak && !block->abortLevel )
		{
			game::Scr_AddBreakBlock(inst, block);
			assert(game::gScrCompileGlob[inst].breakBlock);
			game::EmitRemoveLocalVars(inst, game::gScrCompileGlob[inst].breakBlock, block);
			block->abortLevel = 2;
			game::EmitOpcode(inst, game::OP_jump, 0, 0);
			game::AddOpcodePos(inst, sourcePos.stringValue, 1);
			game::EmitCodepos(inst, 0);

			if ( game::gScrCompilePub[inst].developer_statement != 2 )
			{
				newBreakStatement = (game::BreakStatementInfo *)game::Hunk_AllocateTempMemoryHigh(sizeof(game::BreakStatementInfo));
				newBreakStatement->codePos = game::gScrCompileGlob[inst].codePos;
				newBreakStatement->nextCodePos = game::TempMalloc(0);
				newBreakStatement->next = game::gScrCompileGlob[inst].currentBreakStatement;
				game::gScrCompileGlob[inst].currentBreakStatement = newBreakStatement;
			}
		}
		else
		{
			game::CompileError(inst, sourcePos.stringValue, "illegal break statement");
		}
	}

	// Completed
	void EmitContinueStatement(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u sourcePos)
	{
		game::ContinueStatementInfo *newContinueStatement;

		if ( game::gScrCompileGlob[inst].bCanContinue && !block->abortLevel )
		{
			game::Scr_AddContinueBlock(inst, block);
			game::EmitRemoveLocalVars(inst, block, block);
			block->abortLevel = 1;
			game::EmitOpcode(inst, game::OP_jump, 0, 0);
			game::AddOpcodePos(inst, sourcePos.stringValue, 1);
			game::EmitCodepos(inst, 0);

			if ( game::gScrCompilePub[inst].developer_statement != 2 )
			{
				newContinueStatement = (game::ContinueStatementInfo *)game::Hunk_AllocateTempMemoryHigh(sizeof(game::ContinueStatementInfo));
				newContinueStatement->codePos = game::gScrCompileGlob[inst].codePos;
				newContinueStatement->nextCodePos = game::TempMalloc(0);
				newContinueStatement->next = game::gScrCompileGlob[inst].currentContinueStatement;
				game::gScrCompileGlob[inst].currentContinueStatement = newContinueStatement;
			}
		}
		else
		{
			game::CompileError(inst, sourcePos.stringValue, "illegal continue statement");
		}
	}

	// Completed
	void EmitProfStatement(game::scriptInstance_t inst, game::sval_u profileName, [[maybe_unused]] game::sval_u sourcePos, game::OpcodeVM op)
	{
		if ( game::gScrVarPub[inst].developer_script )
		{
			game::Scr_CompileRemoveRefToString(inst, profileName.stringValue);
			game::EmitOpcode(inst, op, 0, 0);
			game::EmitByte(inst, 0);
		}
		else
		{
			game::Scr_CompileRemoveRefToString(inst, profileName.stringValue);
		}
	}

	// Restored
	void EmitProfBeginStatement(game::scriptInstance_t inst, game::sval_u profileName, game::sval_u sourcePos)
	{
		game::EmitProfStatement(inst, profileName, sourcePos, game::OP_prof_begin);
	}

	// Restored
	void EmitProfEndStatement(game::scriptInstance_t inst, game::sval_u profileName, game::sval_u sourcePos)
	{
		game::EmitProfStatement(inst, profileName, sourcePos, game::OP_prof_end);
	}

	// Restored
	void EmitEndStatement(game::scriptInstance_t inst, game::sval_u sourcePos, game::scr_block_s *block)
	{
		if ( !block->abortLevel )
		{
			block->abortLevel = 3;
		}

		game::EmitEnd(inst);
		game::AddOpcodePos(inst, sourcePos.stringValue, 1);
	}

	// Completed
	void EmitStatement(game::scriptInstance_t inst, game::sval_u val, int lastStatement, unsigned int endSourcePos, game::scr_block_s* block)
	{
		/*if (gScrCompilePub[inst].developer_statement == 3)
		{
			switch ( *(_BYTE *)val.stringValue )
			{
			case game::ENUM_assignment:
			case game::ENUM_call_expression_statement:
			case game::ENUM_inc:
			case game::ENUM_dec:
			case game::ENUM_binary_equals:
			case game::ENUM_statement_list:
			case game::ENUM_notify:
				break;
			default:
				CompileError(inst, 0, "illegal statement in debugger");
				break;
			}
		}*/

		switch (val.node[0].type)
		{
		case game::ENUM_assignment:
			game::EmitAssignmentStatement(
				inst,
				val.node[1],
				val.node[2],
				val.node[3],
				val.node[4],
				block);
			break;
		case game::ENUM_call_expression_statement:
			game::EmitCallExpressionStatement(inst, block, val.node[1]);
			break;
		case game::ENUM_return:
			game::EmitReturnStatement(block, inst, val.node[1], val.node[2]);
			break;
		case game::ENUM_return2:
			game::EmitEndStatement(inst, val.node[1], block);
			break;
		case game::ENUM_wait:
			game::EmitWaitStatement(
				block,
				inst,
				val.node[1],
				val.node[2],
				val.node[3]);
			break;
		case game::ENUM_if:
			game::EmitIfStatement(
				inst,
				val.node[1],
				val.node[2],
				val.node[3],
				lastStatement,
				endSourcePos,
				block,
				&val.node[4]);
			break;
		case game::ENUM_if_else:
			game::EmitIfElseStatement(
				inst,
				val.node[1],
				val.node[2],
				val.node[3],
				val.node[4],
				val.node[5],
				lastStatement,
				endSourcePos,
				block,
				&val.node[6],
				&val.node[7]);
			break;
		case game::ENUM_while:
			game::EmitWhileStatement(
				inst,
				val.node[1],
				val.node[2],
				val.node[3],
				val.node[4],
				block,
				&val.node[5]);
			break;
		case game::ENUM_for:
			game::EmitForStatement(
				inst,
				val.node[1],
				val.node[2],
				val.node[3],
				val.node[4],
				val.node[5],
				val.node[6],
				block,
				&val.node[7],
				&val.node[8]);
			break;
		case game::ENUM_inc:
			game::EmitIncStatement(block, inst, val.node[1], val.node[2]);
			break;
		case game::ENUM_dec:
			game::EmitDecStatement(block, inst, val.node[1], val.node[2]);
			break;
		case game::ENUM_binary_equals:
			game::EmitBinaryEqualsOperatorExpression(
				block,
				inst,
				val.node[1],
				val.node[2],
				val.node[3],
				val.node[4]);
			break;
		case game::ENUM_statement_list:
			game::EmitStatementList(inst, val.node[1], lastStatement, endSourcePos, block);
			break;
		case game::ENUM_developer_statement_list:
			game::EmitDeveloperStatementList(
				inst,
				val.node[1],
				val.node[2],
				block,
				&val.node[3]);
			break;
		case game::ENUM_waittill:
			game::EmitWaittillStatement(
				inst,
				val.node[1],
				val.node[2],
				val.node[3],
				val.node[4],
				block);
			break;
		case game::ENUM_waittillmatch:
			game::EmitWaittillmatchStatement(
				inst,
				val.node[1],
				val.node[2],
				val.node[3],
				val.node[4],
				block);
			break;
		case game::ENUM_waittillFrameEnd:
			game::EmitWaittillFrameEnd(inst, val.node[1]);
			break;
		case game::ENUM_notify:
			game::EmitNotifyStatement(
				inst,
				val.node[1],
				val.node[2],
				val.node[3],
				val.node[4],
				block);
			break;
		case game::ENUM_endon:
			game::EmitEndOnStatement(
				block,
				inst,
				val.node[1],
				val.node[2],
				val.node[3],
				val.node[4]);
			break;
		case game::ENUM_switch:
			game::EmitSwitchStatement(
				inst,
				val.node[1],
				val.node[2],
				val.node[3],
				lastStatement,
				endSourcePos,
				block);
			break;
		case game::ENUM_case:
			game::CompileError(inst, val.node[2].sourcePosValue, "illegal case statement");
		case game::ENUM_default:
			game::CompileError(inst, val.node[1].sourcePosValue, "illegal default statement");
		case game::ENUM_break:
			game::EmitBreakStatement(block, inst, val.node[1]);
			break;
		case game::ENUM_continue:
			game::EmitContinueStatement(block, inst, val.node[1]);
			break;
		/*case game::ENUM_breakpoint:
			EmitBreakpointStatement(inst, *(game::sval_u *)(val.stringValue + 4));
			break;*/
		case game::ENUM_prof_begin:
			game::EmitProfBeginStatement(inst, val.node[1], val.node[2]);
			break;
		case game::ENUM_prof_end:
			game::EmitProfEndStatement(inst, val.node[1], val.node[2]);
			break;
		default:
			return;
		}
	}

	// Restored
	void Scr_CalcLocalVarsIncStatement(game::sval_u expr, game::scr_block_s *block)
	{
		game::Scr_CalcLocalVarsVariableExpressionRef(block, expr);
	}

	// Restored
	void Scr_CalcLocalVarsWaittillStatement(game::sval_u exprlist, game::scr_block_s *block)
	{
		game::sval_u *node;

		node = exprlist.node->node[1].node;
		assert(node);
		game::Scr_CalcLocalVarsFormalParameterListInternal(node, block);
	}

	// Completed
	void Scr_CalcLocalVarsStatement(game::scriptInstance_t inst, game::sval_u val, game::scr_block_s* block)
	{
		switch (val.node[0].type)
		{
		case game::ENUM_assignment:
			game::Scr_CalcLocalVarsIncStatement(val.node[1], block);
			break;
		case game::ENUM_return:
		case game::ENUM_return2:
			if (!block->abortLevel)
			{
				block->abortLevel = 3;
			}
			break;
		case game::ENUM_if:
			game::Scr_CalcLocalVarsIfStatement(inst, val.node[2], block, &val.node[4]);
			break;
		case game::ENUM_if_else:
			game::Scr_CalcLocalVarsIfElseStatement(
				inst,
				val.node[2],
				val.node[3],
				block,
				&val.node[6],
				&val.node[7]);
			break;
		case game::ENUM_while:
			game::Scr_CalcLocalVarsWhileStatement(
				inst,
				val.node[1],
				val.node[2],
				block,
				&val.node[5]);
			break;
		case game::ENUM_for:
			game::Scr_CalcLocalVarsForStatement(
				inst,
				val.node[1],
				val.node[2],
				val.node[3],
				val.node[4],
				block,
				&val.node[7],
				&val.node[8]);
			break;
		case game::ENUM_inc:
		case game::ENUM_dec:
		case game::ENUM_binary_equals:
			game::Scr_CalcLocalVarsIncStatement(val.node[1], block);
			break;
		case game::ENUM_statement_list:
			game::Scr_CalcLocalVarsStatementList(block, inst, val.node[1]);
			break;
		case game::ENUM_developer_statement_list:
			game::Scr_CalcLocalVarsDeveloperStatementList(
				inst,
				val.node[1],
				block,
				&val.node[3]);
			break;
		case game::ENUM_waittill:
			game::Scr_CalcLocalVarsWaittillStatement(val.node[2], block);
			break;
		case game::ENUM_switch:
			game::Scr_CalcLocalVarsSwitchStatement(inst, *(game::sval_u*)(val.stringValue + 8), block);
			break;
		case game::ENUM_break:
			game::Scr_AddBreakBlock(inst, block);
			if (!block->abortLevel)
			{
				block->abortLevel = 2;
			}
			break;
		case game::ENUM_continue:
			game::Scr_AddContinueBlock(inst, block);
			if (!block->abortLevel)
			{
				block->abortLevel = 1;
			}
			break;
		default:
			return;
		}
	}

	// Completed
	void EmitStatementList(game::scriptInstance_t inst, game::sval_u val, int lastStatement, unsigned int endSourcePos, game::scr_block_s* block)
	{
		game::sval_u *node;
		game::sval_u *nextNode;

		for ( node = val.node->node[1].node;
			node;
			node = nextNode )
		{
			nextNode = node[1].node;

			if ( (char)lastStatement && game::Scr_IsLastStatement(inst, nextNode) )
			{
				game::EmitStatement(inst, *node, 1, endSourcePos, block);
			}
			else
			{
				game::EmitStatement(inst, *node, 0, endSourcePos, block);
			}
		}
	}

	// Completed
	void Scr_CalcLocalVarsStatementList(game::scr_block_s* block, game::scriptInstance_t inst, game::sval_u val)
	{
		game::sval_u *node;

		for ( node = val.node->node[1].node;
			node;
			node = node[1].node )
		{
			game::Scr_CalcLocalVarsStatement(inst, *node, block);
		}
	}

	// Completed
	void Scr_CalcLocalVarsDeveloperStatementList(game::scriptInstance_t inst, game::sval_u val, game::scr_block_s* block, game::sval_u* devStatBlock)
	{
		game::Scr_CopyBlock(block, (game::scr_block_s **)devStatBlock);
		game::Scr_CalcLocalVarsStatementList(devStatBlock->block, inst, val);
		game::Scr_MergeChildBlocks((game::scr_block_s **)devStatBlock, 1, block);
	}

	// Completed
	void EmitDeveloperStatementList(game::scriptInstance_t inst, game::sval_u val, game::sval_u sourcePos, game::scr_block_s* block, game::sval_u* devStatBlock)
	{
		char *savedPos;
		unsigned int savedChecksum;

		if ( game::gScrCompilePub[inst].developer_statement )
		{
			game::CompileError(inst, sourcePos.stringValue, "cannot recurse /#");
		}
		else
		{
			savedChecksum = game::gScrVarPub[inst].checksum;
			game::Scr_TransferBlock(devStatBlock->block, block);

			if ( game::gScrVarPub[inst].developer_script )
			{
				game::gScrCompilePub[inst].developer_statement = 1;
				game::EmitStatementList(inst, val, 0, 0, devStatBlock->block);
				game::EmitRemoveLocalVars(inst, devStatBlock->block, devStatBlock->block);
			}
			else
			{
				savedPos = game::TempMalloc(0);
				game::gScrCompilePub[inst].developer_statement = 2;
				game::EmitStatementList(inst, val, 0, 0, devStatBlock->block);
				game::TempMemorySetPos(savedPos);
			}

			game::gScrCompilePub[inst].developer_statement = 0;
			game::gScrVarPub[inst].checksum = savedChecksum;
		}
	}

	// Restored
	void EmitFormalParameterListInternal(game::scriptInstance_t inst, game::sval_u *node, game::scr_block_s *block)
	{
		while ( 1 )
		{
			node = node[1].node;
			if ( !node )
			{
				break;
			}

			game::EmitSafeSetVariableField(block, inst, *node->node, node->node[1]);
		}
	}

	// Completed
	void EmitFormalParameterList(game::scriptInstance_t inst, game::sval_u exprlist, game::sval_u sourcePos, game::scr_block_s* block)
	{
		game::EmitFormalParameterListInternal(inst, exprlist.node->node, block);
		game::EmitOpcode(inst, game::OP_checkclearparams, 0, 0);
		game::AddOpcodePos(inst, sourcePos.stringValue, 0);
	}

	// Restored
	unsigned int SpecifyThreadPosition(game::scriptInstance_t inst, unsigned int posId, unsigned int name, unsigned int sourcePos, int type)
	{
		game::VariableValue pos;

		game::CheckThreadPosition(inst, posId, name, sourcePos);
		pos.type = (game::VariableType)type;
		pos.u.intValue = 0;
		game::SetNewVariableValue(inst, posId, &pos);
		return posId;
	}

	// Completed
	void SpecifyThread(game::scriptInstance_t inst, game::sval_u val)
	{
		if ( val.node[0].type == game::ENUM_thread )
		{
			if ( !game::gScrCompileGlob[inst].in_developer_thread || game::gScrVarPub[inst].developer_script )
			{
				game::SpecifyThreadPosition(inst, game::GetVariable(inst, game::gScrCompileGlob[inst].filePosId, val.node[1].stringValue), val.node[1].stringValue, val.node[4].stringValue, game::gScrCompileGlob[inst].in_developer_thread ? game::VAR_DEVELOPER_CODEPOS : game::VAR_CODEPOS);
			}
		}
		else if ( val.node[0].type == game::ENUM_begin_developer_thread )
		{
			if ( game::gScrCompileGlob[inst].in_developer_thread )
			{
				game::CompileError(inst, val.node[1].sourcePosValue, "cannot recurse /#");
			}
			else
			{
				game::gScrCompileGlob[inst].in_developer_thread = 1;
				game::gScrCompileGlob[inst].developer_thread_sourcePos = val.node[1].sourcePosValue;
			}
		}
		else if ( val.node[0].type == game::ENUM_end_developer_thread )
		{
			if ( game::gScrCompileGlob[inst].in_developer_thread )
			{
				game::gScrCompileGlob[inst].in_developer_thread = 0;
			}
			else
			{
				game::CompileError(inst, val.node[1].sourcePosValue, "#/ has no matching /#");
			}
		}
	}

	// Completed
	void EmitThreadInternal(game::scriptInstance_t inst, game::sval_u val, game::sval_u sourcePos, game::sval_u endSourcePos, game::scr_block_s* block)
	{
		game::AddThreadStartOpcodePos(inst, sourcePos.stringValue);
		game::gScrCompileGlob[inst].cumulOffset = 0;
		game::gScrCompileGlob[inst].maxOffset = 0;
		game::gScrCompileGlob[inst].maxCallOffset = 0;

		// pluto
		if (game::plutonium::store_func_codepos != nullptr)
		{
			game::plutonium::store_func_codepos(inst, val.node[1].stringValue);
		}
		//

		game::CompileTransferRefToString(val.node[1].stringValue, inst, 2u);
		game::EmitFormalParameterList(inst, val.node[2], sourcePos, block);
		game::EmitStatementList(inst, val.node[3], 1, endSourcePos.stringValue, block);
		game::EmitEnd(inst);
		game::AddOpcodePos(inst, endSourcePos.stringValue, 1);
		game::AddOpcodePos(inst, 0xFFFFFFFE, 0);

		assert(!game::gScrCompileGlob[inst].cumulOffset);

		if ( game::gScrCompileGlob[inst].maxOffset + 32 * game::gScrCompileGlob[inst].maxCallOffset >= 2048 )
		{
			game::CompileError(inst, sourcePos.stringValue, "function exceeds operand stack size");
		}
	}

	// Restored
	void Scr_CalcLocalVarsFormalParameterList(game::sval_u exprlist, game::scr_block_s *block)
	{
		game::Scr_CalcLocalVarsFormalParameterListInternal(exprlist.node->node, block);
	}

	// Completed
	void Scr_CalcLocalVarsThread(game::sval_u* stmttblock, game::scriptInstance_t inst, game::sval_u exprlist, game::sval_u stmtlist)
	{
		game::gScrCompileGlob[inst].forceNotCreate = 0;
		
		stmttblock->block = (game::scr_block_s*)game::Hunk_AllocateTempMemoryHigh(sizeof(game::scr_block_s));
		stmttblock->block->abortLevel = 0;
		stmttblock->block->localVarsCreateCount = 0;
		stmttblock->block->localVarsCount = 0;
		stmttblock->block->localVarsPublicCount = 0;

		memset(stmttblock->block->localVarsInitBits, 0, sizeof(stmttblock->block->localVarsInitBits));

		game::Scr_CalcLocalVarsFormalParameterList(exprlist, stmttblock->block);
		game::Scr_CalcLocalVarsStatementList(stmttblock->block, inst, stmtlist);
	}

	// Completed
	void InitThread(int type, game::scriptInstance_t inst)
	{
		game::gScrCompileGlob[inst].currentCaseStatement = 0;
		game::gScrCompileGlob[inst].bCanBreak = 0;
		game::gScrCompileGlob[inst].currentBreakStatement = 0;
		game::gScrCompileGlob[inst].bCanContinue = 0;
		game::gScrCompileGlob[inst].currentContinueStatement = 0;
		game::gScrCompileGlob[inst].breakChildBlocks = 0;
		game::gScrCompileGlob[inst].continueChildBlocks = 0;

		if ( game::gScrCompileGlob[inst].firstThread[type] )
		{
			game::gScrCompileGlob[inst].firstThread[type] = 0;
			game::EmitEnd(inst);
			game::AddOpcodePos(inst, 0, 0);
			game::AddOpcodePos(inst, 0xFFFFFFFE, 0);
		}
	}

	// Restored
	void SetThreadPosition(game::scriptInstance_t inst, unsigned int posId)
	{
		game::GetVariableValueAddress(inst, posId)->u.intValue = (unsigned int)game::TempMalloc(0);
	}

	// Completed
	void EmitNormalThread(game::scriptInstance_t inst, game::sval_u val, game::sval_u* stmttblock)
	{
		unsigned int posId;

		game::InitThread(0, inst);
		posId = game::FindVariable(val.node[1].stringValue, game::gScrCompileGlob[inst].filePosId, inst);
		game::SetThreadPosition(inst, posId);
		game::EmitThreadInternal(inst, val, val.node[4], val.node[5], stmttblock->block);
	}

	// Completed
	void EmitDeveloperThread(game::scriptInstance_t inst, game::sval_u val, game::sval_u* stmttblock)
	{
		unsigned int posId;
		unsigned int savedChecksum;
		char *begin_pos;

		assert(game::gScrCompilePub[inst].developer_statement == 0); // SCR_DEV_NO

		if ( game::gScrVarPub[inst].developer_script )
		{
			game::gScrCompilePub[inst].developer_statement = 1;
			game::InitThread(1, inst);
			posId = game::FindVariable(val.node[1].stringValue, game::gScrCompileGlob[inst].filePosId, inst);
			game::SetThreadPosition(inst, posId);
			game::EmitThreadInternal(inst, val, val.node[4], val.node[5], stmttblock->block);
		}
		else
		{
			begin_pos = game::TempMalloc(0);
			savedChecksum = game::gScrVarPub[inst].checksum;
			game::gScrCompilePub[inst].developer_statement = 2;
			game::InitThread(1, inst);
			game::EmitThreadInternal(inst, val, val.node[4], val.node[5], stmttblock->block);
			game::TempMemorySetPos(begin_pos);
			game::gScrVarPub[inst].checksum = savedChecksum;
		}

		game::gScrCompilePub[inst].developer_statement = 0;
	}

	// Completed
	void EmitThread(game::scriptInstance_t inst, game::sval_u val)
	{
		switch (val.node[0].type)
		{
		case game::ENUM_thread:
			game::Scr_CalcLocalVarsThread(&val.node[6], inst, val.node[2], val.node[3]);

			if (game::gScrCompileGlob[inst].in_developer_thread)
			{
				game::EmitDeveloperThread(inst, val, &val.node[6]);
			}
			else
			{
				game::EmitNormalThread(inst, val, &val.node[6]);
			}
			break;
		case game::ENUM_begin_developer_thread:
			assert(!game::gScrCompileGlob[inst].in_developer_thread);
			game::gScrCompileGlob[inst].in_developer_thread = 1;
			break;
		case game::ENUM_end_developer_thread:
			assert(game::gScrCompileGlob[inst].in_developer_thread);
			game::gScrCompileGlob[inst].in_developer_thread = 0;
			break;
		case game::ENUM_usingtree:
			if (game::gScrCompileGlob[inst].in_developer_thread)
			{
				game::CompileError(inst, val.node[2].sourcePosValue, "cannot put #using_animtree inside /# ... #/ comment");
			}

			game::Scr_UsingTree(inst, game::SL_ConvertToString(val.node[1].stringValue, inst), val.node[3].sourcePosValue);
			game::Scr_CompileRemoveRefToString(inst, val.node[1].stringValue);
			break;
		default:
			return;
		}
	}

	// Completed
	void EmitThreadList(game::scriptInstance_t inst, game::sval_u val)
	{
		game::sval_u *node;
		game::sval_u *nodea;

		game::gScrCompileGlob[inst].in_developer_thread = 0;

		for ( node = val.node->node[1].node;
			node;
			node = node[1].node )
		{
			game::SpecifyThread(inst, *node);
		}

		if ( game::gScrCompileGlob[inst].in_developer_thread )
		{
			game::CompileError(inst, game::gScrCompileGlob[inst].developer_thread_sourcePos, "/# has no matching #/");
		}

		game::gScrCompileGlob[inst].firstThread[0] = 1;
		game::gScrCompileGlob[inst].firstThread[1] = 1;

		assert(!game::gScrCompileGlob[inst].in_developer_thread);

		for ( nodea = val.node->node[1].node;
			nodea;
			nodea = nodea[1].node )
		{
			game::EmitThread(inst, *nodea);
		}

		assert(!game::gScrCompileGlob[inst].in_developer_thread);
	}

	// Completed
	void EmitInclude(game::scriptInstance_t inst, game::sval_u val)
	{
		unsigned int filename;

		assert(val.node[0].type == game::ENUM_include);

		filename = game::Scr_CreateCanonicalFilename(inst, game::SL_ConvertToString(val.node[1].stringValue, inst));
		game::Scr_CompileRemoveRefToString(inst, val.node[1].stringValue);
		game::AddFilePrecache(inst, filename, val.node[2].sourcePosValue, 1, 0, 0);
	}

	// Restored
	void EmitIncludeList(game::scriptInstance_t inst, game::sval_u val)
	{
		game::sval_u *node;

		for ( node = val.node->node[1].node;
			node;
			node = node[1].node )
		{
			game::EmitInclude(inst, *node);
		}
	}

	// Completed
	void ScriptCompile(game::scriptInstance_t inst, game::sval_u val, unsigned int filePosId, unsigned int fileCountId, unsigned int scriptId, game::PrecacheEntry* entries, int entriesCount)
	{
		int j;
		game::VariableValue pos;
		unsigned __int16 filename;
		game::PrecacheEntry* precachescript;
		int far_function_count;
		game::PrecacheEntry* precachescript2;
		unsigned int includeFilePosId;
		unsigned int toPosId;
		unsigned int posId;
		game::VariableValue includePos;
		unsigned __int16 name;
		unsigned int includePosId;
		game::PrecacheEntry* precachescriptList;
		int i;
		unsigned int toThreadCountId;
		unsigned int duplicateFilePosId;
		game::VariableValue value;
		int entriesCounta;

		game::gScrCompileGlob[inst].filePosId = filePosId;
		game::gScrCompileGlob[inst].fileCountId = fileCountId;
		game::gScrCompileGlob[inst].bConstRefCount = 0;
		game::gScrAnimPub[inst].animTreeIndex = 0;
		game::gScrCompilePub[inst].developer_statement = 0;

		precachescriptList = game::gScrCompilePub[inst].far_function_count ? &entries[entriesCount] : 0;
		entriesCounta = game::gScrCompilePub[inst].far_function_count + entriesCount;
		if (entriesCounta > 0x400) // 0x700 on t5
		{
			game::Com_Error(game::ERR_DROP, "MAX_PRECACHE_ENTRIES exceeded.\nThis means that the script recursion is too deep.\nPlease see a coder."); // t5 meme message
		}

		game::gScrCompileGlob[inst].precachescriptList = precachescriptList;

		game::EmitIncludeList(inst, *val.node);
		game::EmitThreadList(inst, val.node[1]);

		game::gScrCompilePub[inst].programLen = game::TempMalloc(0) - game::gScrVarPub[inst].programBuffer;
		game::Scr_ShutdownAllocNode(inst);
		game::Hunk_ClearTempMemoryHigh();

		far_function_count = game::gScrCompileGlob[inst].precachescriptList - precachescriptList;
		duplicateFilePosId = game::AllocObject(inst);

		for (i = 0;
			i < far_function_count;
			++i)
		{
			precachescript = &precachescriptList[i];
			filename = precachescript->filename;
			includeFilePosId = game::Scr_LoadScriptInternal(inst, game::SL_ConvertToString(filename, inst), entries, entriesCounta);

			if (!includeFilePosId)
			{
				game::CompileError(inst, precachescript->sourcePos, "Could not find script '%s'", game::SL_ConvertToString(filename, inst));
				return;
			}

			game::SL_RemoveRefToString(filename, inst);

			if (precachescript->include)
			{
				for (j = i + 1;
					j < far_function_count;
					++j)
				{
					precachescript2 = &precachescriptList[j];

					if (!precachescript2->include)
					{
						break;
					}

					if (precachescript2->filename == filename)
					{
						game::CompileError(inst, precachescript2->sourcePos, "Duplicate #include");
						return;
					}
				}

				precachescript->include = 0;
				pos.type = game::VAR_CODEPOS;

				for (includePosId = game::FindFirstSibling(inst, includeFilePosId);
					includePosId;
					includePosId = game::FindNextSibling(inst, includePosId))
				{
					includePos = game::Scr_EvalVariable(inst, includePosId);

					assert((includePos.type == game::VAR_CODEPOS) || (includePos.type == game::VAR_DEVELOPER_CODEPOS));

					name = game::GetVariableName(inst, includePosId);
					posId = game::FindVariable(name, filePosId, inst);

					if (posId)
					{
						game::CheckThreadPosition(inst, posId, name, precachescript->sourcePos);
					}

					toPosId = game::GetVariable(inst, duplicateFilePosId, name);
					game::CheckThreadPosition(inst, toPosId, name, precachescript->sourcePos);
					pos.u.intValue = game::GetVariableValueAddress(inst, includePosId)->u.intValue;
					game::SetNewVariableValue(inst, toPosId, &pos);
					toThreadCountId = game::GetObject(inst, game::GetVariable(inst, fileCountId, name));
					game::LinkThread(inst, toThreadCountId, &includePos, 0);
					game::RemoveVariable(name, fileCountId, inst);
				}
			}
		}

		game::ClearObject(duplicateFilePosId, inst);
		game::RemoveRefToEmptyObject(inst, duplicateFilePosId);
		game::LinkFile(inst, filePosId, fileCountId);
		value.type = game::VAR_INTEGER;
		game::SetVariableValue(inst, &value, scriptId);
	}
}
#pragma warning(pop)
