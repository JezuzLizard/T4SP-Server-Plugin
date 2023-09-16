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

static const char* scr_enum_t_to_string[] =
{
	"ENUM_NOP",
	"ENUM_program",
	"ENUM_assignment",
	"ENUM_unknown_variable",
	"ENUM_duplicate_variable",
	"ENUM_local_variable",
	"ENUM_local_variable_frozen",
	"ENUM_duplicate_expression",
	"ENUM_primitive_expression",
	"ENUM_integer",
	"ENUM_float",
	"ENUM_minus_integer",
	"ENUM_minus_float",
	"ENUM_string",
	"ENUM_istring",
	"ENUM_array_variable",
	"ENUM_unknown_field",
	"ENUM_field_variable",
	"ENUM_field_variable_frozen",
	"ENUM_variable",
	"ENUM_function",
	"ENUM_call_expression",
	"ENUM_local_function",
	"ENUM_far_function",
	"ENUM_function_pointer",
	"ENUM_call",
	"ENUM_method",
	"ENUM_call_expression_statement",
	"ENUM_script_call",
	"ENUM_return",
	"ENUM_return2",
	"ENUM_wait",
	"ENUM_script_thread_call",
	"ENUM_undefined",
	"ENUM_self",
	"ENUM_self_frozen",
	"ENUM_level",
	"ENUM_game",
	"ENUM_anim",
	"ENUM_if",
	"ENUM_if_else",
	"ENUM_while",
	"ENUM_for",
	"ENUM_inc",
	"ENUM_dec",
	"ENUM_binary_equals",
	"ENUM_statement_list",
	"ENUM_developer_statement_list",
	"ENUM_expression_list",
	"ENUM_bool_or",
	"ENUM_bool_and",
	"ENUM_binary",
	"ENUM_bool_not",
	"ENUM_bool_complement",
	"ENUM_size_field",
	"ENUM_self_field",
	"ENUM_precachetree",
	"ENUM_waittill",
	"ENUM_waittillmatch",
	"ENUM_waittillFrameEnd",
	"ENUM_notify",
	"ENUM_endon",
	"ENUM_switch",
	"ENUM_case",
	"ENUM_default",
	"ENUM_break",
	"ENUM_continue",
	"ENUM_expression",
	"ENUM_empty_array",
	"ENUM_animation",
	"ENUM_thread",
	"ENUM_begin_developer_thread",
	"ENUM_end_developer_thread",
	"ENUM_usingtree",
	"ENUM_false",
	"ENUM_true",
	"ENUM_animtree",
	"ENUM_breakon",
	"ENUM_breakpoint",
	"ENUM_prof_begin",
	"ENUM_prof_end",
	"ENUM_vector",
	"ENUM_object",
	"ENUM_thread_object",
	"ENUM_local",
	"ENUM_statement",
	"ENUM_bad_expression",
	"ENUM_bad_statement",
	"ENUM_include",
	"ENUM_argument"
};

void print_statement_ast(game::scriptInstance_t inst, game::sval_u val, int depth);

void print_depth(int depth)
{
	for (auto i = 0; i < depth; i++)
	{
		printf("  ");
	}
}

void print_statement_list_ast(game::scriptInstance_t inst, game::sval_u *val, int depth)
{
	game::sval_u *node;
	game::sval_u *nextNode;

	printf("statements:\n");

	for (node = val->node[1].node;
		node;
		node = nextNode)
	{
		nextNode = node[1].node;

		print_statement_ast(inst, *node, depth + 1);
		printf("\n");
	}
}

void print_formal_params_ast(game::scriptInstance_t inst, game::sval_u *node)
{
	printf("formal params:");
	while ( 1 )
	{
		node = node[1].node;
		if ( !node )
		{
			break;
		}

		auto expr_name = node->node[0].stringValue;
		auto sourcePos = node->node[1].sourcePosValue;

		printf(" %s %d, ", game::SL_ConvertToString(expr_name, inst), sourcePos);
	}
}

void print_statement_ast(game::scriptInstance_t inst, game::sval_u val, int depth)
{
	print_depth(depth);

	printf("%s", scr_enum_t_to_string[val.node[0].type]);

	switch (val.node[0].type)
	{
	case game::ENUM_assignment:
	{
		auto lhs = val.node[1];
		auto rhs = val.node[2];
		auto sourcePos = val.node[3].sourcePosValue;
		auto rhsSourcePos = val.node[4].sourcePosValue;

		printf(" lhs %d\n", sourcePos);
		print_statement_ast(inst, lhs, depth + 1);
		printf("\n");

		print_depth(depth);
		printf("rhs %d\n", rhsSourcePos);
		print_statement_ast(inst, rhs, depth + 1);
		break;
	}
	case game::ENUM_local_variable:
	{
		auto var_name = val.node[1].stringValue;
		auto sourcePos = val.node[2].sourcePosValue;

		printf(" %s %d", game::SL_ConvertToString(var_name, inst), sourcePos);
		break;
	}
	case game::ENUM_array_variable:
	{
		auto prim_expr = val.node[1];
		auto index_expr = val.node[2];
		auto sourcePos = val.node[3].sourcePosValue;
		auto indexSourcePos = val.node[4].sourcePosValue;

		printf(" prim_expr %d\n", sourcePos);
		print_statement_ast(inst, prim_expr, depth + 1);
		printf("\n");

		print_depth(depth);
		printf("index_expr %d\n", indexSourcePos);
		print_statement_ast(inst, index_expr, depth + 1);
		break;
	}
	case game::ENUM_field_variable:
	{
		auto expr = val.node[1];
		auto field = val.node[2].stringValue;
		auto sourcePos = val.node[3].sourcePosValue;

		printf(" %s %d\n", game::SL_ConvertToString(field, inst), sourcePos);
		print_statement_ast(inst, expr, depth + 1);
		break;
	}
	case game::ENUM_thread:
	{
		auto thread_name = val.node[1].stringValue;
		auto exprlist = val.node[2].node;  
		auto stmtlist = val.node[3].node;
		auto sourcePos = val.node[4].sourcePosValue;
		auto endSourcePos = val.node[5].sourcePosValue;
		auto stmtblock = &val.node[6].block;
		stmtblock = stmtblock;

		printf(" %s %d %d\n", game::SL_ConvertToString(thread_name, inst), sourcePos, endSourcePos);
		print_depth(depth);

		print_formal_params_ast(inst, exprlist->node);
		printf("\n");
		print_depth(depth);

		print_statement_list_ast(inst, stmtlist, depth);
		break;
	}
	case game::ENUM_begin_developer_thread:
	{
		auto sourcePos = val.node[1].sourcePosValue;

		printf(" %d", sourcePos);
		break;
	}
	case game::ENUM_end_developer_thread:
	{
		auto sourcePos = val.node[1].sourcePosValue;

		printf(" %d", sourcePos);
		break;
	}
	case game::ENUM_usingtree:
	{
		auto string_val = val.node[1].stringValue;
		auto sourcePos = val.node[2].sourcePosValue;
		auto sourcePos2 = val.node[3].sourcePosValue;

		printf(" %s %d %d", game::SL_ConvertToString(string_val, inst), sourcePos, sourcePos2);
		break;
	}
	default:
		break;
	}
}

void print_ast(game::scriptInstance_t inst, game::sval_u val)
{
	// this is the include list
	game::sval_u this_node = val.node[0];
	game::sval_u* node;

	printf("%s\n", game::gScrParserPub[inst].scriptfilename);
	printf("includes\n");

	for ( node = this_node.node->node[1].node;
		node;
		node = node[1].node )
	{
		print_depth(1);
		printf("%s %s %d\n", scr_enum_t_to_string[node->node[0].type], game::SL_ConvertToString(node->node[1].stringValue, inst), node->node[1].sourcePosValue);
	}

	printf("threads\n");

	// this is the thread list
	this_node = val.node[1];

	for ( node = this_node.node->node[1].node;
		node;
		node = node[1].node )
	{
		print_statement_ast(inst, *node, 1);
		printf("\n");
	}

	printf("done\n");
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
