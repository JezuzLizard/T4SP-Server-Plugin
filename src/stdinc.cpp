#include <stdinc.hpp>
#include "codsrc/clientscript/clientscript_public.hpp"
#include <dbghelp.h>

namespace game
{
#define QUICK_TO_JSON_FIELD(j, v, membername) j[#membername] = v.membername

#define QUICK_TO_JSON_FIELD_SAFE_CSTR(j, v, membername) \
	if (v.membername) \
		j[#membername] = v.membername; \
	else \
		j[#membername] = "(NULL)"

#define QUICK_TO_JSON_FIELD_PTR_ADDR(j, v, membername) j[#membername] = reinterpret_cast<size_t>(&v.membername)

#define QUICK_TO_JSON_FIELD_ARRAY(j, v, membername) \
	for (auto i = 0; i < ARRAY_COUNT(v.membername); i++) \
	{ \
		j[#membername][i] = v.membername[i]; \
	}

#define QUICK_TO_JSON_FIELD_SL_STRING(j, v, membername) j[#membername "Str"] = SL_ConvertToStringSafe(v.membername, *gInst)

	void to_json(nlohmann::json& j, const scrVarPub_t& v)
	{
		QUICK_TO_JSON_FIELD_SAFE_CSTR(j, v, fieldBuffer);
		QUICK_TO_JSON_FIELD(j, v, canonicalStrCount);
		QUICK_TO_JSON_FIELD(j, v, developer);
		QUICK_TO_JSON_FIELD(j, v, developer_script);
		QUICK_TO_JSON_FIELD(j, v, evaluate);
		QUICK_TO_JSON_FIELD_SAFE_CSTR(j, v, error_message);
		QUICK_TO_JSON_FIELD(j, v, error_index);
		QUICK_TO_JSON_FIELD(j, v, time);
		QUICK_TO_JSON_FIELD(j, v, timeArrayId);
		QUICK_TO_JSON_FIELD(j, v, pauseArrayId);
		QUICK_TO_JSON_FIELD(j, v, levelId);
		QUICK_TO_JSON_FIELD(j, v, gameId);
		QUICK_TO_JSON_FIELD(j, v, animId);
		QUICK_TO_JSON_FIELD(j, v, freeEntList);
		QUICK_TO_JSON_FIELD(j, v, tempVariable);
		QUICK_TO_JSON_FIELD(j, v, bInited);
		QUICK_TO_JSON_FIELD(j, v, savecount);
		QUICK_TO_JSON_FIELD(j, v, checksum);
		QUICK_TO_JSON_FIELD(j, v, entId);
		QUICK_TO_JSON_FIELD(j, v, entFieldName);
		QUICK_TO_JSON_FIELD_SL_STRING(j, v, entFieldName);
		QUICK_TO_JSON_FIELD_PTR_ADDR(j, v, programHunkUser);
		QUICK_TO_JSON_FIELD_PTR_ADDR(j, v, programBuffer);
		QUICK_TO_JSON_FIELD_PTR_ADDR(j, v, endScriptBuffer);
		QUICK_TO_JSON_FIELD_ARRAY(j, v, saveIdMap);
		QUICK_TO_JSON_FIELD_ARRAY(j, v, saveIdMapRev);
	}
}

// https://stackoverflow.com/questions/5693192/win32-backtrace-from-c-code
std::string build_code_stack()
{
	unsigned int   i;
	void         * stack[ 100 ];
	unsigned short frames;
	SYMBOL_INFO  * symbol;
	HANDLE         process;
	std::string answer{};

	process = GetCurrentProcess();

	SymInitialize( process, NULL, TRUE );

	frames               = CaptureStackBackTrace( 0, 100, stack, NULL );
	symbol               = ( SYMBOL_INFO * )calloc( sizeof( SYMBOL_INFO ) + 256 * sizeof( char ), 1 );
	symbol->MaxNameLen   = 255;
	symbol->SizeOfStruct = sizeof( SYMBOL_INFO );

	for( i = 0; i < frames; i++ )
	{
		SymFromAddr( process, ( DWORD64 )( stack[ i ] ), 0, symbol );

		answer += std::format("{}: {} - 0x{:06x}\n", frames - i - 1, symbol->Name, symbol->Address);
	}

	free( symbol );

	return answer;
}

int op_idx[game::SCRIPT_INSTANCE_MAX] = { 0, 0 };
bool op_idx_rolled_over[game::SCRIPT_INSTANCE_MAX] = { false, false };
game::OpcodeVM op_history[game::SCRIPT_INSTANCE_MAX][128] = {};

int builtin_idx[game::SCRIPT_INSTANCE_MAX] = { 0, 0 };
bool builtin_idx_rolled_over[game::SCRIPT_INSTANCE_MAX] = { false, false };
int builtin_history[game::SCRIPT_INSTANCE_MAX][128] = {};

int codepos_idx[game::SCRIPT_INSTANCE_MAX] = { 0, 0 };
bool codepos_idx_rolled_over[game::SCRIPT_INSTANCE_MAX] = { false, false };
const char* codepos_history[game::SCRIPT_INSTANCE_MAX][128] = {};

std::string build_builtin_history(game::scriptInstance_t inst)
{
	std::string answer{};

	int count = builtin_idx_rolled_over[inst] ? ARRAY_COUNT(builtin_history[inst]) : builtin_idx[inst];

	for (auto i = 0; i < count; i++)
	{
		auto idx = builtin_idx[inst] - 1 - i;
		if (idx < 0)
		{
			idx += ARRAY_COUNT(builtin_history[inst]);
		}

		// todo, convert to builtin name
		answer += std::format("{}\n", builtin_history[inst][idx]);
	}

	return answer;
}

std::string build_codepos_history(game::scriptInstance_t inst)
{
	std::string answer{};
	int bufferIndex;
	int prevSourcePos;
	int col;
	char line[1024];
	int lineNum;
	const char* fileName;

	int count = codepos_idx_rolled_over[inst] ? ARRAY_COUNT(codepos_history[inst]) : codepos_idx[inst];

	for (auto i = 0; i < count; i++)
	{
		auto idx = codepos_idx[inst] - 1 - i;
		if (idx < 0)
		{
			idx += ARRAY_COUNT(codepos_history[inst]);
		}

		bufferIndex = game::Scr_GetSourceBuffer(inst, codepos_history[inst][idx]);
		prevSourcePos = game::Scr_GetPrevSourcePos(inst, codepos_history[inst][idx], 0);
		lineNum = game::Scr_GetLineInfo(&col, game::gScrParserPub[inst].sourceBufferLookup[bufferIndex].sourceBuf, prevSourcePos, line);
		fileName = game::gScrParserPub[inst].sourceBufferLookup[bufferIndex].buf;

		answer += std::format("{}({}, {}): '{}'\n", fileName, lineNum, col, line);
	}

	return answer;
}

std::string build_op_history(game::scriptInstance_t inst)
{
	static const char* OpcodeVMToString[] = {
		"OP_End",
		"OP_Return",
		"OP_GetUndefined",
		"OP_GetZero",
		"OP_GetByte",
		"OP_GetNegByte",
		"OP_GetUnsignedShort",
		"OP_GetNegUnsignedShort",
		"OP_GetInteger",
		"OP_GetFloat",
		"OP_GetString",
		"OP_GetIString",
		"OP_GetVector",
		"OP_GetLevelObject",
		"OP_GetAnimObject",
		"OP_GetSelf",
		"OP_GetLevel",
		"OP_GetGame",
		"OP_GetAnim",
		"OP_GetAnimation",
		"OP_GetGameRef",
		"OP_GetFunction",
		"OP_CreateLocalVariable",
		"OP_RemoveLocalVariables",
		"OP_EvalLocalVariableCached0",
		"OP_EvalLocalVariableCached1",
		"OP_EvalLocalVariableCached2",
		"OP_EvalLocalVariableCached3",
		"OP_EvalLocalVariableCached4",
		"OP_EvalLocalVariableCached5",
		"OP_EvalLocalVariableCached",
		"OP_EvalLocalArrayCached",
		"OP_EvalArray",
		"OP_EvalLocalArrayRefCached0",
		"OP_EvalLocalArrayRefCached",
		"OP_EvalArrayRef",
		"OP_ClearArray",
		"OP_EmptyArray",
		"OP_GetSelfObject",
		"OP_EvalLevelFieldVariable",
		"OP_EvalAnimFieldVariable",
		"OP_EvalSelfFieldVariable",
		"OP_EvalFieldVariable",
		"OP_EvalLevelFieldVariableRef",
		"OP_EvalAnimFieldVariableRef",
		"OP_EvalSelfFieldVariableRef",
		"OP_EvalFieldVariableRef",
		"OP_ClearFieldVariable",
		"OP_SafeCreateVariableFieldCached",
		"OP_SafeSetVariableFieldCached0",
		"OP_SafeSetVariableFieldCached",
		"OP_SafeSetWaittillVariableFieldCached",
		"OP_clearparams",
		"OP_checkclearparams",
		"OP_EvalLocalVariableRefCached0",
		"OP_EvalLocalVariableRefCached",
		"OP_SetLevelFieldVariableField",
		"OP_SetVariableField",
		"OP_SetAnimFieldVariableField",
		"OP_SetSelfFieldVariableField",
		"OP_SetLocalVariableFieldCached0",
		"OP_SetLocalVariableFieldCached",
		"OP_CallBuiltin0",
		"OP_CallBuiltin1",
		"OP_CallBuiltin2",
		"OP_CallBuiltin3",
		"OP_CallBuiltin4",
		"OP_CallBuiltin5",
		"OP_CallBuiltin",
		"OP_CallBuiltinMethod0",
		"OP_CallBuiltinMethod1",
		"OP_CallBuiltinMethod2",
		"OP_CallBuiltinMethod3",
		"OP_CallBuiltinMethod4",
		"OP_CallBuiltinMethod5",
		"OP_CallBuiltinMethod",
		"OP_wait",
		"OP_waittillFrameEnd",
		"OP_PreScriptCall",
		"OP_ScriptFunctionCall2",
		"OP_ScriptFunctionCall",
		"OP_ScriptFunctionCallPointer",
		"OP_ScriptMethodCall",
		"OP_ScriptMethodCallPointer",
		"OP_ScriptThreadCall",
		"OP_ScriptThreadCallPointer",
		"OP_ScriptMethodThreadCall",
		"OP_ScriptMethodThreadCallPointer",
		"OP_DecTop",
		"OP_CastFieldObject",
		"OP_EvalLocalVariableObjectCached",
		"OP_CastBool",
		"OP_BoolNot",
		"OP_BoolComplement",
		"OP_JumpOnFalse",
		"OP_JumpOnTrue",
		"OP_JumpOnFalseExpr",
		"OP_JumpOnTrueExpr",
		"OP_jump",
		"OP_jumpback",
		"OP_inc",
		"OP_dec",
		"OP_bit_or",
		"OP_bit_ex_or",
		"OP_bit_and",
		"OP_equality",
		"OP_inequality",
		"OP_less",
		"OP_greater",
		"OP_less_equal",
		"OP_greater_equal",
		"OP_shift_left",
		"OP_shift_right",
		"OP_plus",
		"OP_minus",
		"OP_multiply",
		"OP_divide",
		"OP_mod",
		"OP_size",
		"OP_waittillmatch",
		"OP_waittill",
		"OP_notify",
		"OP_endon",
		"OP_voidCodepos",
		"OP_switch",
		"OP_endswitch",
		"OP_vector",
		"OP_NOP",
		"OP_abort",
		"OP_object",
		"OP_thread_object",
		"OP_EvalLocalVariable",
		"OP_EvalLocalVariableRef",
		"OP_prof_begin",
		"OP_prof_end",
		"OP_breakpoint",
		"OP_assignmentBreakpoint",
		"OP_manualAndAssignmentBreakpoint",
		"OP_count"
	};

	std::string answer{};

	int count = op_idx_rolled_over[inst] ? ARRAY_COUNT(op_history[inst]) : op_idx[inst];

	for (auto i = 0; i < count; i++)
	{
		auto idx = op_idx[inst] - 1 - i;
		if (idx < 0)
		{
			idx += ARRAY_COUNT(op_history[inst]);
		}

		if ((int)op_history[inst][idx] >= 0 && op_history[inst][idx] < game::OP_count)
		{
			answer += std::format("{}\n", OpcodeVMToString[op_history[inst][idx]]);
		}
		else
		{
			answer += std::format("0x{:02x}\n", (int)op_history[inst][idx]);
		}
	}

	return answer;
}

std::string build_gsc_stack(game::scriptInstance_t inst)
{
	std::string answer{};

	int bufferIndex;
	int prevSourcePos;
	int col;
	char line[1024];
	int lineNum;
	const char* fileName;

	if (!game::gFs[inst].pos || !game::Scr_IsInOpcodeMemory(inst, game::gFs[inst].pos))
	{
		return answer;
	}

	for (auto frame = game::gScrVmPub[inst].function_frame_start;; frame++)
	{
		if (!frame->fs.pos || !game::Scr_IsInOpcodeMemory(inst, frame->fs.pos))
		{
			break;
		}

		bufferIndex = game::Scr_GetSourceBuffer(inst, frame->fs.pos - 1);
		prevSourcePos = game::Scr_GetPrevSourcePos(inst, frame->fs.pos - 1, 0);
		lineNum = game::Scr_GetLineInfo(&col, game::gScrParserPub[inst].sourceBufferLookup[bufferIndex].sourceBuf, prevSourcePos, line);
		fileName = game::gScrParserPub[inst].sourceBufferLookup[bufferIndex].buf;

		answer += std::format("{}({}, {}): '{}'\n", fileName, lineNum, col, line);

		if (frame == game::gScrVmPub[inst].function_frame)
		{
			break;
		}
	}

	return answer;
}

std::string build_gsc_dump(game::scriptInstance_t inst)
{
	nlohmann::json answer{};
	auto t = *game::gInst;
	*game::gInst = inst;

	answer["inst"] = inst;
	answer["gScrVarPub"] = game::gScrVarPub[inst];
	answer["codeCallStack"] = build_code_stack();
	answer["gscCallStack"] = build_gsc_stack(inst);
	answer["opHistory"] = build_op_history(inst);
	answer["builtinHistory"] = build_builtin_history(inst);
	answer["codeposHistory"] = build_codepos_history(inst);

	*game::gInst = t;

	return answer.dump(2);
}

void push_opcode_history(game::scriptInstance_t inst, game::OpcodeVM op)
{
	assert(inst == 0 || inst == 1);
	//assert((int)op >= 0 && op < game::OP_count);

	op_history[inst][op_idx[inst]++] = op;

	if (op_idx[inst] >= ARRAY_COUNT(op_history[inst]))
	{
		op_idx_rolled_over[inst] = true;
		op_idx[inst] = 0;
	}
}

void push_builtin_history(game::scriptInstance_t inst, int idx)
{
	assert(inst == 0 || inst == 1);
	assert(idx >= 0 && idx < 1024);

	builtin_history[inst][builtin_idx[inst]++] = idx;

	if (builtin_idx[inst] >= ARRAY_COUNT(builtin_history[inst]))
	{
		builtin_idx_rolled_over[inst] = true;
		builtin_idx[inst] = 0;
	}
}

void push_codepos_history(game::scriptInstance_t inst, const char* pos)
{
	assert(inst == 0 || inst == 1);
	assert(game::Scr_IsInOpcodeMemory(inst, pos));

	codepos_history[inst][codepos_idx[inst]++] = pos;

	if (codepos_idx[inst] >= ARRAY_COUNT(codepos_history[inst]))
	{
		codepos_idx_rolled_over[inst] = true;
		codepos_idx[inst] = 0;
	}
}
