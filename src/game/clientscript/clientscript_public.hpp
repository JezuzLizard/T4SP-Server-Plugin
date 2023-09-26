#pragma once

#define VAR_STAT_FREE 0
#define VAR_STAT_MASK 0x60
#define VAR_STAT_MOVABLE 0x20
#define VAR_STAT_HEAD 0x40
#define VAR_STAT_EXTERNAL 0x60

#define VAR_MASK 0x1F
#define VAR_ENT_MASK 0x3FFF
#define VAR_CLIENT_MASK 0xE
#define VAR_NAME_LOW_MASK 0xFF000000
#define VAR_NAME_HIGH_MASK 0xFFFFFF00
#define VAR_NAME_BIT_SHIFT 8
#define VAR_PARENTID_BIT_SHIFT 8
#define OBJECT_STACK 0x15FFE
#define OBJECT_NOTIFY_LIST 0x15FFE

#define VARIABLELIST_CHILD_SIZE 0x10000
#define VARIABLELIST_CHILD_BEGIN 0x6000

#define IsObject(__parentValue__) \
	((__parentValue__->w.status & VAR_MASK) >= game::VAR_THREAD) \

#define MT_NODE_BITS 16
#define MT_NODE_SIZE sizeof(game::MemoryNode)
#define MT_SIZE sizeof(game::scrMemTreeGlob_t::nodes)
#define MT_NODE_COUNT (1 << MT_NODE_BITS)
#define MT_NUM_BUCKETS 256

#define HASH_STAT_MASK 0x30000
#define HASH_STAT_HEAD 0x20000
#define HASH_STAT_MOVABLE 0x10000
#define HASH_STAT_FREE 0
#define HASH_MAX_HASHES 25000
#define SL_MAX_STRING_LEN 0x2000
#define SL_MAX_STRING_INDEX 0x10000

#define MAX_VM_STACK_DEPTH 30

#ifdef __cplusplus
namespace game
{
#endif

	struct HunkUser;
	struct XAnim_s;
	struct actorBackup_s;
	struct XAnimTree_s;
	struct actor_s;
	struct centity_s;
	struct gentity_s;
	struct sentient_s;
	struct gclient_s;
	struct game_hudelem_s;
	struct dvar_s;

#pragma region "enums"

	enum classNum_e
	{
		CLASS_NUM_ENTITY = 0x0,
		CLASS_NUM_HUDELEM = 0x1,
		CLASS_NUM_PATHNODE = 0x2,
		CLASS_NUM_VEHICLENODE = 0x3,
		CLASS_NUM_COUNT = 0x4,
	};

	enum scriptInstance_t : __int32
	{
		SCRIPTINSTANCE_SERVER = 0x0,
		SCRIPTINSTANCE_CLIENT = 0x1,
		SCRIPT_INSTANCE_MAX = 0x2,
	};

	enum animUserInstance_t
	{
		ANIM_USER_CLIENT = 0x0,
		ANIM_USER_SERVER = 0x1,
		ANIM_USER_COUNT = 0x2
	};

	enum OpcodeVM : __int32
	{
		OP_End = 0x0,
		OP_Return = 0x1,
		OP_GetUndefined = 0x2,
		OP_GetZero = 0x3,
		OP_GetByte = 0x4,
		OP_GetNegByte = 0x5,
		OP_GetUnsignedShort = 0x6,
		OP_GetNegUnsignedShort = 0x7,
		OP_GetInteger = 0x8,
		OP_GetFloat = 0x9,
		OP_GetString = 0xA,
		OP_GetIString = 0xB,
		OP_GetVector = 0xC,
		OP_GetLevelObject = 0xD,
		OP_GetAnimObject = 0xE,
		OP_GetSelf = 0xF,
		OP_GetLevel = 0x10,
		OP_GetGame = 0x11,
		OP_GetAnim = 0x12,
		OP_GetAnimation = 0x13,
		OP_GetGameRef = 0x14,
		OP_GetFunction = 0x15,
		OP_CreateLocalVariable = 0x16,
		OP_RemoveLocalVariables = 0x17,
		OP_EvalLocalVariableCached0 = 0x18,
		OP_EvalLocalVariableCached1 = 0x19,
		OP_EvalLocalVariableCached2 = 0x1A,
		OP_EvalLocalVariableCached3 = 0x1B,
		OP_EvalLocalVariableCached4 = 0x1C,
		OP_EvalLocalVariableCached5 = 0x1D,
		OP_EvalLocalVariableCached = 0x1E,
		OP_EvalLocalArrayCached = 0x1F,
		OP_EvalArray = 0x20,
		OP_EvalLocalArrayRefCached0 = 0x21,
		OP_EvalLocalArrayRefCached = 0x22,
		OP_EvalArrayRef = 0x23,
		OP_ClearArray = 0x24,
		OP_EmptyArray = 0x25,
		OP_GetSelfObject = 0x26,
		OP_EvalLevelFieldVariable = 0x27,
		OP_EvalAnimFieldVariable = 0x28,
		OP_EvalSelfFieldVariable = 0x29,
		OP_EvalFieldVariable = 0x2A,
		OP_EvalLevelFieldVariableRef = 0x2B,
		OP_EvalAnimFieldVariableRef = 0x2C,
		OP_EvalSelfFieldVariableRef = 0x2D,
		OP_EvalFieldVariableRef = 0x2E,
		OP_ClearFieldVariable = 0x2F,
		OP_SafeCreateVariableFieldCached = 0x30,
		OP_SafeSetVariableFieldCached0 = 0x31,
		OP_SafeSetVariableFieldCached = 0x32,
		OP_SafeSetWaittillVariableFieldCached = 0x33,
		OP_clearparams = 0x34,
		OP_checkclearparams = 0x35,
		OP_EvalLocalVariableRefCached0 = 0x36,
		OP_EvalLocalVariableRefCached = 0x37,
		OP_SetLevelFieldVariableField = 0x38,
		OP_SetVariableField = 0x39,
		OP_SetAnimFieldVariableField = 0x3A,
		OP_SetSelfFieldVariableField = 0x3B,
		OP_SetLocalVariableFieldCached0 = 0x3C,
		OP_SetLocalVariableFieldCached = 0x3D,
		OP_CallBuiltin0 = 0x3E,
		OP_CallBuiltin1 = 0x3F,
		OP_CallBuiltin2 = 0x40,
		OP_CallBuiltin3 = 0x41,
		OP_CallBuiltin4 = 0x42,
		OP_CallBuiltin5 = 0x43,
		OP_CallBuiltin = 0x44,
		OP_CallBuiltinMethod0 = 0x45,
		OP_CallBuiltinMethod1 = 0x46,
		OP_CallBuiltinMethod2 = 0x47,
		OP_CallBuiltinMethod3 = 0x48,
		OP_CallBuiltinMethod4 = 0x49,
		OP_CallBuiltinMethod5 = 0x4A,
		OP_CallBuiltinMethod = 0x4B,
		OP_wait = 0x4C,
		OP_waittillFrameEnd = 0x4D,
		OP_PreScriptCall = 0x4E,
		OP_ScriptFunctionCall2 = 0x4F,
		OP_ScriptFunctionCall = 0x50,
		OP_ScriptFunctionCallPointer = 0x51,
		OP_ScriptMethodCall = 0x52,
		OP_ScriptMethodCallPointer = 0x53,
		OP_ScriptThreadCall = 0x54,
		OP_ScriptThreadCallPointer = 0x55,
		OP_ScriptMethodThreadCall = 0x56,
		OP_ScriptMethodThreadCallPointer = 0x57,
		OP_DecTop = 0x58,
		OP_CastFieldObject = 0x59,
		OP_EvalLocalVariableObjectCached = 0x5A,
		OP_CastBool = 0x5B,
		OP_BoolNot = 0x5C,
		OP_BoolComplement = 0x5D,
		OP_JumpOnFalse = 0x5E,
		OP_JumpOnTrue = 0x5F,
		OP_JumpOnFalseExpr = 0x60,
		OP_JumpOnTrueExpr = 0x61,
		OP_jump = 0x62,
		OP_jumpback = 0x63,
		OP_inc = 0x64,
		OP_dec = 0x65,
		OP_bit_or = 0x66,
		OP_bit_ex_or = 0x67,
		OP_bit_and = 0x68,
		OP_equality = 0x69,
		OP_inequality = 0x6A,
		OP_less = 0x6B,
		OP_greater = 0x6C,
		OP_less_equal = 0x6D,
		OP_greater_equal = 0x6E,
		OP_shift_left = 0x6F,
		OP_shift_right = 0x70,
		OP_plus = 0x71,
		OP_minus = 0x72,
		OP_multiply = 0x73,
		OP_divide = 0x74,
		OP_mod = 0x75,
		OP_size = 0x76,
		OP_waittillmatch = 0x77,
		OP_waittill = 0x78,
		OP_notify = 0x79,
		OP_endon = 0x7A,
		OP_voidCodepos = 0x7B,
		OP_switch = 0x7C,
		OP_endswitch = 0x7D,
		OP_vector = 0x7E,
		OP_NOP = 0x7F,
		OP_abort = 0x80,
		OP_object = 0x81,
		OP_thread_object = 0x82,
		OP_EvalLocalVariable = 0x83,
		OP_EvalLocalVariableRef = 0x84,
		OP_prof_begin = 0x85,
		OP_prof_end = 0x86,
		OP_breakpoint = 0x87,
		OP_assignmentBreakpoint = 0x88,
		OP_manualAndAssignmentBreakpoint = 0x89,
		OP_count = 0x8A,
	};

	enum scr_enum_t
	{
		ENUM_NOP = 0x0,
		ENUM_program = 0x1,
		ENUM_assignment = 0x2,
		ENUM_unknown_variable = 0x3,
		ENUM_duplicate_variable = 0x4,
		ENUM_local_variable = 0x5,
		ENUM_local_variable_frozen = 0x6,
		ENUM_duplicate_expression = 0x7,
		ENUM_primitive_expression = 0x8,
		ENUM_integer = 0x9,
		ENUM_float = 0xA,
		ENUM_minus_integer = 0xB,
		ENUM_minus_float = 0xC,
		ENUM_string = 0xD,
		ENUM_istring = 0xE,
		ENUM_array_variable = 0xF,
		ENUM_unknown_field = 0x10,
		ENUM_field_variable = 0x11,
		ENUM_field_variable_frozen = 0x12,
		ENUM_variable = 0x13,
		ENUM_function = 0x14,
		ENUM_call_expression = 0x15,
		ENUM_local_function = 0x16,
		ENUM_far_function = 0x17,
		ENUM_function_pointer = 0x18,
		ENUM_call = 0x19,
		ENUM_method = 0x1A,
		ENUM_call_expression_statement = 0x1B,
		ENUM_script_call = 0x1C,
		ENUM_return = 0x1D,
		ENUM_return2 = 0x1E,
		ENUM_wait = 0x1F,
		ENUM_script_thread_call = 0x20,
		ENUM_undefined = 0x21,
		ENUM_self = 0x22,
		ENUM_self_frozen = 0x23,
		ENUM_level = 0x24,
		ENUM_game = 0x25,
		ENUM_anim = 0x26,
		ENUM_if = 0x27,
		ENUM_if_else = 0x28,
		ENUM_while = 0x29,
		ENUM_for = 0x2A,
		ENUM_inc = 0x2B,
		ENUM_dec = 0x2C,
		ENUM_binary_equals = 0x2D,
		ENUM_statement_list = 0x2E,
		ENUM_developer_statement_list = 0x2F,
		ENUM_expression_list = 0x30,
		ENUM_bool_or = 0x31,
		ENUM_bool_and = 0x32,
		ENUM_binary = 0x33,
		ENUM_bool_not = 0x34,
		ENUM_bool_complement = 0x35,
		ENUM_size_field = 0x36,
		ENUM_self_field = 0x37,
		ENUM_precachetree = 0x38,
		ENUM_waittill = 0x39,
		ENUM_waittillmatch = 0x3A,
		ENUM_waittillFrameEnd = 0x3B,
		ENUM_notify = 0x3C,
		ENUM_endon = 0x3D,
		ENUM_switch = 0x3E,
		ENUM_case = 0x3F,
		ENUM_default = 0x40,
		ENUM_break = 0x41,
		ENUM_continue = 0x42,
		ENUM_expression = 0x43,
		ENUM_empty_array = 0x44,
		ENUM_animation = 0x45,
		ENUM_thread = 0x46,
		ENUM_begin_developer_thread = 0x47,
		ENUM_end_developer_thread = 0x48,
		ENUM_usingtree = 0x49,
		ENUM_false = 0x4A,
		ENUM_true = 0x4B,
		ENUM_animtree = 0x4C,
		ENUM_breakon = 0x4D,
		ENUM_breakpoint = 0x4E,
		ENUM_prof_begin = 0x4F,
		ENUM_prof_end = 0x50,
		ENUM_vector = 0x51,
		ENUM_object = 0x52,
		ENUM_thread_object = 0x53,
		ENUM_local = 0x54,
		ENUM_statement = 0x55,
		ENUM_bad_expression = 0x56,
		ENUM_bad_statement = 0x57,
		ENUM_include = 0x58,
		ENUM_argument = 0x59,
	};

	/*enum HASH_e
	{
		HASH_STAT_MASK = 0x30000,
		HASH_STAT_HEAD = 0x20000,
		HASH_STAT_MOVABLE = 0x10000,
		HASH_STAT_FREE = 0x0,
	};

	enum VAR_e
	{
		VAR_STAT_FREE = 0x0,
		VAR_BEGIN_REF = 0x1,
		VAR_END_REF = 0x5,
		VAR_STAT_MASK = 0x60,
		VAR_STAT_MOVABLE = 0x20,
		VAR_STAT_HEAD = 0x40,
		VAR_STAT_EXTERNAL = 0x60,
		VAR_MASK = 0x1F,
		VAR_NAME_LOW_MASK = 0xFF000000,
		VAR_NAME_HIGH_MASK = 0xFFFFFF00,
		VAR_NAME_BITS = 0x8,
		VARIABLELIST_CHILD_SIZE = 0x10000,
		VARIABLELIST_CHILD_BEGIN = 0x6000,
		SL_MAX_STRING_INDEX = 0x10000,
		OBJECT_STACK = 0x15FFE,
		FIRST_OBJECT = 0x14,
	};*/

	enum ObjectTypes
	{
		FIRST_OBJECT = 0xD,
		FIRST_CLEARABLE_OBJECT = 0x11,
		LAST_NONENTITY_OBJECT = 0x11,
		FIRST_ENTITY_OBJECT = 0x13,
		FIRST_NONFIELD_OBJECT = 0x14,
		FIRST_DEAD_OBJECT = 0x15,
	};

	enum VariableType
	{
		VAR_UNDEFINED = 0x0,
		VAR_POINTER = 0x1,
		VAR_STRING = 0x2,
		VAR_ISTRING = 0x3,
		VAR_VECTOR = 0x4,
		VAR_FLOAT = 0x5,
		VAR_INTEGER = 0x6,
		VAR_CODEPOS = 0x7,
		VAR_PRECODEPOS = 0x8,
		VAR_FUNCTION = 0x9,
		VAR_STACK = 0xA,
		VAR_ANIMATION = 0xB,
		VAR_DEVELOPER_CODEPOS = 0xC,
		VAR_THREAD = 0xD,
		VAR_NOTIFY_THREAD = 0xE,
		VAR_TIME_THREAD = 0xF,
		VAR_CHILD_THREAD = 0x10,
		VAR_OBJECT = 0x11,
		VAR_DEAD_ENTITY = 0x12,
		VAR_ENTITY = 0x13,
		VAR_ARRAY = 0x14,
		VAR_DEAD_THREAD = 0x15,
		VAR_COUNT = 0x16,
		VAR_THREAD_LIST = 0x17,
		VAR_ENDON_LIST = 0x18,
	};

	enum scr_builtin_type_t
	{
		BUILTIN_ANY = 0x0,
		BUILTIN_DEVELOPER_ONLY = 0x1,
	};

	enum Scr_SourceType_t
	{
		SOURCE_TYPE_NONE = 0x0,
		SOURCE_TYPE_BREAKPOINT = 0x1,
		SOURCE_TYPE_CALL = 0x2,
	};

	enum scr_abort_t
	{
		SCR_ABORT_NONE = 0x0,
		SCR_ABORT_CONTINUE = 0x1,
		SCR_ABORT_BREAK = 0x2,
		SCR_ABORT_RETURN = 0x3,
		SCR_ABORT_MAX = 0x3,
	};

	enum scr_call_type_t
	{
		CALL_NONE = 0x0,
		CALL_BUILTIN = 0x1,
		CALL_THREAD = 0x2,
		CALL_FUNCTION = 0x3,
	};

	enum sl_user_type_e
	{
		SL_USER_GAME = 0x1,
		SL_USER_TEMP = 0x2,
		SL_USER_XZONE = 0x4,
		SL_USER_XZONE_TEMP = 0x8,
	};

#pragma endregion

#pragma region "structs"

	struct VariableStackBuffer
	{
		const char * pos; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 size; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 bufLen; //OFS: 0x6 SIZE: 0x2
		unsigned __int16 localId; //OFS: 0x8 SIZE: 0x2
		unsigned __int8 time; //OFS: 0xA SIZE: 0x1
		char buf[1]; //OFS: 0xB SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(VariableStackBuffer, 0xC);
	ASSERT_STRUCT_OFFSET(VariableStackBuffer, pos, 0x0);
	ASSERT_STRUCT_OFFSET(VariableStackBuffer, size, 0x4);
	ASSERT_STRUCT_OFFSET(VariableStackBuffer, bufLen, 0x6);
	ASSERT_STRUCT_OFFSET(VariableStackBuffer, localId, 0x8);
	ASSERT_STRUCT_OFFSET(VariableStackBuffer, time, 0xA);
	ASSERT_STRUCT_OFFSET(VariableStackBuffer, buf, 0xB);

	struct __declspec(align(2)) scr_anim_u_u
	{
		unsigned __int16 index; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 tree; //OFS: 0x2 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(scr_anim_u_u, 0x4);
	ASSERT_STRUCT_OFFSET(scr_anim_u_u, index, 0x0);
	ASSERT_STRUCT_OFFSET(scr_anim_u_u, tree, 0x2);

	union scr_anim_u
	{
		scr_anim_u_u s; //OFS: 0x0 SIZE: 0x4
		const char * linkPointer; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(scr_anim_u, 0x4);

	struct scr_anim_s
	{
		scr_anim_u u; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(scr_anim_s, 0x4);
	ASSERT_STRUCT_OFFSET(scr_anim_s, u, 0x0);

	union VariableUnion
	{
		int intValue; //OFS: 0x0 SIZE: 0x4
		float floatValue; //OFS: 0x1 SIZE: 0x4
		unsigned int stringValue; //OFS: 0x2 SIZE: 0x4
		const float * vectorValue; //OFS: 0x3 SIZE: 0x4
		const char * codePosValue; //OFS: 0x4 SIZE: 0x4
		unsigned int pointerValue; //OFS: 0x5 SIZE: 0x4
		VariableStackBuffer * stackValue; //OFS: 0x6 SIZE: 0x4
		unsigned int entityOffset; //OFS: 0x7 SIZE: 0x4
		scr_anim_s anim;
	};
	ASSERT_STRUCT_SIZE(VariableUnion, 0x4);

	struct VariableValue
	{
		VariableUnion u; //OFS: 0x0 SIZE: 0x4
		VariableType type; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(VariableValue, 0x8);
	ASSERT_STRUCT_OFFSET(VariableValue, u, 0x0);
	ASSERT_STRUCT_OFFSET(VariableValue, type, 0x4);

	struct scrVmGlob_t
	{
		VariableValue eval_stack[2]; //OFS: 0x0 SIZE: 0x10
		char * dialog_error_message; //OFS: 0x10 SIZE: 0x4
		int loading; //OFS: 0x14 SIZE: 0x4
		int starttime; //OFS: 0x18 SIZE: 0x4
		unsigned int localVarsStack[2048]; //OFS: 0x1C SIZE: 0x2000
	};
	ASSERT_STRUCT_SIZE(scrVmGlob_t, 0x201C);
	ASSERT_STRUCT_OFFSET(scrVmGlob_t, eval_stack, 0x0);
	ASSERT_STRUCT_OFFSET(scrVmGlob_t, dialog_error_message, 0x10);
	ASSERT_STRUCT_OFFSET(scrVmGlob_t, loading, 0x14);
	ASSERT_STRUCT_OFFSET(scrVmGlob_t, starttime, 0x18);
	ASSERT_STRUCT_OFFSET(scrVmGlob_t, localVarsStack, 0x1C);

	struct function_stack_t
	{
		const char * pos; //OFS: 0x0 SIZE: 0x4
		unsigned int localId; //OFS: 0x4 SIZE: 0x4
		unsigned int localVarCount; //OFS: 0x8 SIZE: 0x4
		VariableValue * top; //OFS: 0xC SIZE: 0x4
		VariableValue * startTop; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(function_stack_t, 0x14);
	ASSERT_STRUCT_OFFSET(function_stack_t, pos, 0x0);
	ASSERT_STRUCT_OFFSET(function_stack_t, localId, 0x4);
	ASSERT_STRUCT_OFFSET(function_stack_t, localVarCount, 0x8);
	ASSERT_STRUCT_OFFSET(function_stack_t, top, 0xC);
	ASSERT_STRUCT_OFFSET(function_stack_t, startTop, 0x10);

	struct function_frame_t
	{
		function_stack_t fs; //OFS: 0x0 SIZE: 0x14
		VariableType topType; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(function_frame_t, 0x18);
	ASSERT_STRUCT_OFFSET(function_frame_t, fs, 0x0);
	ASSERT_STRUCT_OFFSET(function_frame_t, topType, 0x14);

	struct scrVmPub_t
	{
		unsigned int * localVars; //OFS: 0x0 SIZE: 0x4
		VariableValue * maxstack; //OFS: 0x4 SIZE: 0x4
		int function_count; //OFS: 0x8 SIZE: 0x4
		function_frame_t * function_frame; //OFS: 0xC SIZE: 0x4
		VariableValue * top; //OFS: 0x10 SIZE: 0x4
		bool debugCode; //OFS: 0x14 SIZE: 0x1
		bool abort_on_error; //OFS: 0x15 SIZE: 0x1
		char terminal_error; //OFS: 0x16 SIZE: 0x1
		char field_17; //OFS: 0x17 SIZE: 0x1
		unsigned int inparamcount; //OFS: 0x18 SIZE: 0x4
		unsigned int outparamcount; //OFS: 0x1C SIZE: 0x4
		function_frame_t function_frame_start[32]; //OFS: 0x20 SIZE: 0x300
		VariableValue stack[2048]; //OFS: 0x320 SIZE: 0x4000
	};
	ASSERT_STRUCT_SIZE(scrVmPub_t, 0x4320);
	ASSERT_STRUCT_OFFSET(scrVmPub_t, localVars, 0x0);
	ASSERT_STRUCT_OFFSET(scrVmPub_t, maxstack, 0x4);
	ASSERT_STRUCT_OFFSET(scrVmPub_t, function_count, 0x8);
	ASSERT_STRUCT_OFFSET(scrVmPub_t, function_frame, 0xC);
	ASSERT_STRUCT_OFFSET(scrVmPub_t, top, 0x10);
	ASSERT_STRUCT_OFFSET(scrVmPub_t, debugCode, 0x14);
	ASSERT_STRUCT_OFFSET(scrVmPub_t, abort_on_error, 0x15);
	ASSERT_STRUCT_OFFSET(scrVmPub_t, terminal_error, 0x16);
	ASSERT_STRUCT_OFFSET(scrVmPub_t, field_17, 0x17);
	ASSERT_STRUCT_OFFSET(scrVmPub_t, inparamcount, 0x18);
	ASSERT_STRUCT_OFFSET(scrVmPub_t, outparamcount, 0x1C);
	ASSERT_STRUCT_OFFSET(scrVmPub_t, function_frame_start, 0x20);
	ASSERT_STRUCT_OFFSET(scrVmPub_t, stack, 0x320);

	union Variable_u
	{
		unsigned __int16 prev; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 prevSibling; //OFS: 0x1 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(Variable_u, 0x2);

	struct __declspec(align(2)) Variable
	{
		unsigned __int16 id; //OFS: 0x0 SIZE: 0x2
		Variable_u u; //OFS: 0x2 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(Variable, 0x4);
	ASSERT_STRUCT_OFFSET(Variable, id, 0x0);
	ASSERT_STRUCT_OFFSET(Variable, u, 0x2);

	union ObjectInfo_u
	{
		unsigned __int16 entnum; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 size; //OFS: 0x1 SIZE: 0x2
		unsigned __int16 nextEntId; //OFS: 0x2 SIZE: 0x2
		unsigned __int16 self; //OFS: 0x3 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(ObjectInfo_u, 0x2);

	struct __declspec(align(2)) ObjectInfo
	{
		unsigned __int16 refCount; //OFS: 0x0 SIZE: 0x2
		ObjectInfo_u u; //OFS: 0x2 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(ObjectInfo, 0x4);
	ASSERT_STRUCT_OFFSET(ObjectInfo, refCount, 0x0);
	ASSERT_STRUCT_OFFSET(ObjectInfo, u, 0x2);

	union VariableValueInternal_u
	{
		unsigned __int16 next; //OFS: 0x0 SIZE: 0x2
		VariableUnion u; //OFS: 0x1 SIZE: 0x4
		ObjectInfo o; //OFS: 0x2 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(VariableValueInternal_u, 0x4);

	struct VariableValueInternal_w_bits
	{
		unsigned int type : 5;
		unsigned int status : 2;
		unsigned int unk1 : 1;
		unsigned int name : 24;
	};
	ASSERT_STRUCT_SIZE(VariableValueInternal_w_bits, 0x4);

	union VariableValueInternal_w
	{
		unsigned int status; //OFS: 0x0 SIZE: 0x4
		unsigned int type; //OFS: 0x1 SIZE: 0x4
		unsigned int name; //OFS: 0x2 SIZE: 0x4
		unsigned int classnum; //OFS: 0x3 SIZE: 0x4
		unsigned int notifyName; //OFS: 0x4 SIZE: 0x4
		unsigned int waitTime; //OFS: 0x5 SIZE: 0x4
		unsigned int parentLocalId; //OFS: 0x6 SIZE: 0x4
		VariableValueInternal_w_bits bits;
	};
	ASSERT_STRUCT_SIZE(VariableValueInternal_w, 0x4);

	union VariableValueInternal_v
	{
		unsigned __int16 next; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 index; //OFS: 0x1 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(VariableValueInternal_v, 0x2);

	struct VariableValueInternal
	{
		Variable hash; //OFS: 0x0 SIZE: 0x4
		VariableValueInternal_u u; //OFS: 0x4 SIZE: 0x4
		VariableValueInternal_w w; //OFS: 0x8 SIZE: 0x4
		VariableValueInternal_v v; //OFS: 0xC SIZE: 0x2
		unsigned __int16 nextSibling; //OFS: 0xE SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(VariableValueInternal, 0x10);
	ASSERT_STRUCT_OFFSET(VariableValueInternal, hash, 0x0);
	ASSERT_STRUCT_OFFSET(VariableValueInternal, u, 0x4);
	ASSERT_STRUCT_OFFSET(VariableValueInternal, w, 0x8);
	ASSERT_STRUCT_OFFSET(VariableValueInternal, v, 0xC);
	ASSERT_STRUCT_OFFSET(VariableValueInternal, nextSibling, 0xE);

	struct scrVarGlob_t
	{
		VariableValueInternal parentVariables[24576]; //OFS: 0x0 SIZE: 0x60000
		VariableValueInternal childVariables[65536]; //OFS: 0x60000 SIZE: 0x100000
	};
	ASSERT_STRUCT_SIZE(scrVarGlob_t, 0x160000);
	ASSERT_STRUCT_OFFSET(scrVarGlob_t, parentVariables, 0x0);
	ASSERT_STRUCT_OFFSET(scrVarGlob_t, childVariables, 0x60000);

	union HashEntry_u
	{
		unsigned int prev; //OFS: 0x0 SIZE: 0x4
		unsigned int str; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(HashEntry_u, 0x4);

	struct HashEntry
	{
		unsigned int status_next; //OFS: 0x0 SIZE: 0x4
		HashEntry_u u; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(HashEntry, 0x8);
	ASSERT_STRUCT_OFFSET(HashEntry, status_next, 0x0);
	ASSERT_STRUCT_OFFSET(HashEntry, u, 0x4);

	struct __declspec(align(64)) scrStringGlob_t
	{
		HashEntry hashTable[25000]; //OFS: 0x0 SIZE: 0x30D40
		bool inited; //OFS: 0x30D40 SIZE: 0x1
		HashEntry * nextFreeEntry; //OFS: 0x30D44 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(scrStringGlob_t, 0x30D80);
	ASSERT_STRUCT_OFFSET(scrStringGlob_t, hashTable, 0x0);
	ASSERT_STRUCT_OFFSET(scrStringGlob_t, inited, 0x30D40);
	ASSERT_STRUCT_OFFSET(scrStringGlob_t, nextFreeEntry, 0x30D44);

	struct scrVarPub_t
	{
		char * fieldBuffer; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 canonicalStrCount; //OFS: 0x4 SIZE: 0x2
		bool developer; //OFS: 0x6 SIZE: 0x1
		bool developer_script; //OFS: 0x7 SIZE: 0x1
		bool evaluate; //OFS: 0x8 SIZE: 0x1
		char * error_message; //OFS: 0xC SIZE: 0x4
		int error_index; //OFS: 0x10 SIZE: 0x4
		unsigned int time; //OFS: 0x14 SIZE: 0x4
		unsigned int timeArrayId; //OFS: 0x18 SIZE: 0x4
		unsigned int pauseArrayId; //OFS: 0x1C SIZE: 0x4
		unsigned int levelId; //OFS: 0x20 SIZE: 0x4
		unsigned int gameId; //OFS: 0x24 SIZE: 0x4
		unsigned int animId; //OFS: 0x28 SIZE: 0x4
		unsigned int freeEntList; //OFS: 0x2C SIZE: 0x4
		unsigned int tempVariable; //OFS: 0x30 SIZE: 0x4
		bool bInited; //OFS: 0x34 SIZE: 0x1
		unsigned __int16 savecount; //OFS: 0x36 SIZE: 0x2
		unsigned int checksum; //OFS: 0x38 SIZE: 0x4
		unsigned int entId; //OFS: 0x3C SIZE: 0x4
		unsigned int entFieldName; //OFS: 0x40 SIZE: 0x4
		HunkUser * programHunkUser; //OFS: 0x44 SIZE: 0x4
		char * programBuffer; //OFS: 0x48 SIZE: 0x4
		char * endScriptBuffer; //OFS: 0x4C SIZE: 0x4
		unsigned __int16 saveIdMap[24574]; //OFS: 0x50 SIZE: 0xBFFC
		unsigned __int16 saveIdMapRev[24574]; //OFS: 0xC04C SIZE: 0xBFFC
	};
	ASSERT_STRUCT_SIZE(scrVarPub_t, 0x18048);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, fieldBuffer, 0x0);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, canonicalStrCount, 0x4);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, developer, 0x6);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, developer_script, 0x7);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, evaluate, 0x8);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, error_message, 0xC);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, error_index, 0x10);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, time, 0x14);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, timeArrayId, 0x18);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, pauseArrayId, 0x1C);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, levelId, 0x20);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, gameId, 0x24);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, animId, 0x28);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, freeEntList, 0x2C);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, tempVariable, 0x30);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, bInited, 0x34);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, savecount, 0x36);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, checksum, 0x38);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, entId, 0x3C);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, entFieldName, 0x40);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, programHunkUser, 0x44);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, programBuffer, 0x48);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, endScriptBuffer, 0x4C);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, saveIdMap, 0x50);
	ASSERT_STRUCT_OFFSET(scrVarPub_t, saveIdMapRev, 0xC04C);

	struct SourceBufferInfo
	{
		const char * codePos; //OFS: 0x0 SIZE: 0x4
		char * buf; //OFS: 0x4 SIZE: 0x4
		const char * sourceBuf; //OFS: 0x8 SIZE: 0x4
		int len; //OFS: 0xC SIZE: 0x4
		int sortedIndex; //OFS: 0x10 SIZE: 0x4
		bool archive; //OFS: 0x14 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(SourceBufferInfo, 0x18);
	ASSERT_STRUCT_OFFSET(SourceBufferInfo, codePos, 0x0);
	ASSERT_STRUCT_OFFSET(SourceBufferInfo, buf, 0x4);
	ASSERT_STRUCT_OFFSET(SourceBufferInfo, sourceBuf, 0x8);
	ASSERT_STRUCT_OFFSET(SourceBufferInfo, len, 0xC);
	ASSERT_STRUCT_OFFSET(SourceBufferInfo, sortedIndex, 0x10);
	ASSERT_STRUCT_OFFSET(SourceBufferInfo, archive, 0x14);

	struct scrParserPub_t
	{
		SourceBufferInfo * sourceBufferLookup; //OFS: 0x0 SIZE: 0x4
		unsigned int sourceBufferLookupLen; //OFS: 0x4 SIZE: 0x4
		const char * scriptfilename; //OFS: 0x8 SIZE: 0x4
		const char * sourceBuf; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(scrParserPub_t, 0x10);
	ASSERT_STRUCT_OFFSET(scrParserPub_t, sourceBufferLookup, 0x0);
	ASSERT_STRUCT_OFFSET(scrParserPub_t, sourceBufferLookupLen, 0x4);
	ASSERT_STRUCT_OFFSET(scrParserPub_t, scriptfilename, 0x8);
	ASSERT_STRUCT_OFFSET(scrParserPub_t, sourceBuf, 0xC);

	struct MemoryNode
	{
		unsigned __int16 prev; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 next; //OFS: 0x2 SIZE: 0x2
		unsigned int padding[2]; //OFS: 0x4 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(MemoryNode, 0xC);
	ASSERT_STRUCT_OFFSET(MemoryNode, prev, 0x0);
	ASSERT_STRUCT_OFFSET(MemoryNode, next, 0x2);
	ASSERT_STRUCT_OFFSET(MemoryNode, padding, 0x4);

	struct __declspec(align(128)) scrMemTreeGlob_t
	{
		MemoryNode nodes[MT_NODE_COUNT];
		unsigned __int8 leftBits[MT_NUM_BUCKETS];
		unsigned __int8 numBits[MT_NUM_BUCKETS];
		unsigned __int8 logBits[MT_NUM_BUCKETS];
		unsigned __int16 head[MT_NODE_BITS + 1];
	};
	ASSERT_STRUCT_SIZE(scrMemTreeGlob_t, 0xC0380);
	ASSERT_STRUCT_OFFSET(scrMemTreeGlob_t, nodes, 0x0);
	ASSERT_STRUCT_OFFSET(scrMemTreeGlob_t, leftBits, 0xC0000);
	ASSERT_STRUCT_OFFSET(scrMemTreeGlob_t, numBits, 0xC0100);
	ASSERT_STRUCT_OFFSET(scrMemTreeGlob_t, logBits, 0xC0200);
	ASSERT_STRUCT_OFFSET(scrMemTreeGlob_t, head, 0xC0300);

	struct OpcodeLookup
	{
		const char * codePos; //OFS: 0x0 SIZE: 0x4
		unsigned int sourcePosIndex; //OFS: 0x4 SIZE: 0x4
		unsigned int sourcePosCount; //OFS: 0x8 SIZE: 0x4
		int profileTime; //OFS: 0xC SIZE: 0x4
		int profileBuiltInTime; //OFS: 0x10 SIZE: 0x4
		int profileUsage; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(OpcodeLookup, 0x18);
	ASSERT_STRUCT_OFFSET(OpcodeLookup, codePos, 0x0);
	ASSERT_STRUCT_OFFSET(OpcodeLookup, sourcePosIndex, 0x4);
	ASSERT_STRUCT_OFFSET(OpcodeLookup, sourcePosCount, 0x8);
	ASSERT_STRUCT_OFFSET(OpcodeLookup, profileTime, 0xC);
	ASSERT_STRUCT_OFFSET(OpcodeLookup, profileBuiltInTime, 0x10);
	ASSERT_STRUCT_OFFSET(OpcodeLookup, profileUsage, 0x14);

	struct SourceLookup
	{
		unsigned int sourcePos; //OFS: 0x0 SIZE: 0x4
		int type; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SourceLookup, 0x8);
	ASSERT_STRUCT_OFFSET(SourceLookup, sourcePos, 0x0);
	ASSERT_STRUCT_OFFSET(SourceLookup, type, 0x4);

	struct SaveSourceBufferInfo
	{
		char * sourceBuf; //OFS: 0x0 SIZE: 0x4
		int len; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SaveSourceBufferInfo, 0x8);
	ASSERT_STRUCT_OFFSET(SaveSourceBufferInfo, sourceBuf, 0x0);
	ASSERT_STRUCT_OFFSET(SaveSourceBufferInfo, len, 0x4);

	struct scrParserGlob_t
	{
		OpcodeLookup * opcodeLookup; //OFS: 0x0 SIZE: 0x4
		unsigned int opcodeLookupMaxLen; //OFS: 0x4 SIZE: 0x4
		unsigned int opcodeLookupLen; //OFS: 0x8 SIZE: 0x4
		SourceLookup * sourcePosLookup; //OFS: 0xC SIZE: 0x4
		unsigned int sourcePosLookupMaxLen; //OFS: 0x10 SIZE: 0x4
		unsigned int sourcePosLookupLen; //OFS: 0x14 SIZE: 0x4
		unsigned int sourceBufferLookupMaxLen; //OFS: 0x18 SIZE: 0x4
		const unsigned __int8 * currentCodePos; //OFS: 0x1C SIZE: 0x4
		unsigned int currentSourcePosCount; //OFS: 0x20 SIZE: 0x4
		SaveSourceBufferInfo * saveSourceBufferLookup; //OFS: 0x24 SIZE: 0x4
		unsigned int saveSourceBufferLookupLen; //OFS: 0x28 SIZE: 0x4
		int delayedSourceIndex; //OFS: 0x2C SIZE: 0x4
		int threadStartSourceIndex; //OFS: 0x30 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(scrParserGlob_t, 0x34);
	ASSERT_STRUCT_OFFSET(scrParserGlob_t, opcodeLookup, 0x0);
	ASSERT_STRUCT_OFFSET(scrParserGlob_t, opcodeLookupMaxLen, 0x4);
	ASSERT_STRUCT_OFFSET(scrParserGlob_t, opcodeLookupLen, 0x8);
	ASSERT_STRUCT_OFFSET(scrParserGlob_t, sourcePosLookup, 0xC);
	ASSERT_STRUCT_OFFSET(scrParserGlob_t, sourcePosLookupMaxLen, 0x10);
	ASSERT_STRUCT_OFFSET(scrParserGlob_t, sourcePosLookupLen, 0x14);
	ASSERT_STRUCT_OFFSET(scrParserGlob_t, sourceBufferLookupMaxLen, 0x18);
	ASSERT_STRUCT_OFFSET(scrParserGlob_t, currentCodePos, 0x1C);
	ASSERT_STRUCT_OFFSET(scrParserGlob_t, currentSourcePosCount, 0x20);
	ASSERT_STRUCT_OFFSET(scrParserGlob_t, saveSourceBufferLookup, 0x24);
	ASSERT_STRUCT_OFFSET(scrParserGlob_t, saveSourceBufferLookupLen, 0x28);
	ASSERT_STRUCT_OFFSET(scrParserGlob_t, delayedSourceIndex, 0x2C);
	ASSERT_STRUCT_OFFSET(scrParserGlob_t, threadStartSourceIndex, 0x30);

	struct scrMemTreePub_t
	{
		scrMemTreeGlob_t * mt_buffer; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(scrMemTreePub_t, 0x4);
	ASSERT_STRUCT_OFFSET(scrMemTreePub_t, mt_buffer, 0x0);

	struct CaseStatementInfo
	{
		unsigned int name; //OFS: 0x0 SIZE: 0x4
		const char * codePos; //OFS: 0x4 SIZE: 0x4
		unsigned int sourcePos; //OFS: 0x8 SIZE: 0x4
		CaseStatementInfo * next; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(CaseStatementInfo, 0x10);
	ASSERT_STRUCT_OFFSET(CaseStatementInfo, name, 0x0);
	ASSERT_STRUCT_OFFSET(CaseStatementInfo, codePos, 0x4);
	ASSERT_STRUCT_OFFSET(CaseStatementInfo, sourcePos, 0x8);
	ASSERT_STRUCT_OFFSET(CaseStatementInfo, next, 0xC);

	struct BreakStatementInfo
	{
		const char * codePos; //OFS: 0x0 SIZE: 0x4
		const char * nextCodePos; //OFS: 0x4 SIZE: 0x4
		BreakStatementInfo * next; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(BreakStatementInfo, 0xC);
	ASSERT_STRUCT_OFFSET(BreakStatementInfo, codePos, 0x0);
	ASSERT_STRUCT_OFFSET(BreakStatementInfo, nextCodePos, 0x4);
	ASSERT_STRUCT_OFFSET(BreakStatementInfo, next, 0x8);

	struct ContinueStatementInfo
	{
		const char * codePos; //OFS: 0x0 SIZE: 0x4
		const char * nextCodePos; //OFS: 0x4 SIZE: 0x4
		ContinueStatementInfo * next; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ContinueStatementInfo, 0xC);
	ASSERT_STRUCT_OFFSET(ContinueStatementInfo, codePos, 0x0);
	ASSERT_STRUCT_OFFSET(ContinueStatementInfo, nextCodePos, 0x4);
	ASSERT_STRUCT_OFFSET(ContinueStatementInfo, next, 0x8);

	struct scr_localVar_t
	{
		unsigned int name; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(scr_localVar_t, 0x4);
	ASSERT_STRUCT_OFFSET(scr_localVar_t, name, 0x0);

	struct scr_block_s
	{
		int abortLevel; //OFS: 0x0 SIZE: 0x4
		int localVarsCreateCount; //OFS: 0x4 SIZE: 0x4
		int localVarsPublicCount; //OFS: 0x8 SIZE: 0x4
		int localVarsCount; //OFS: 0xC SIZE: 0x4
		unsigned __int8 localVarsInitBits[8]; //OFS: 0x10 SIZE: 0x8
		scr_localVar_t localVars[64]; //OFS: 0x18 SIZE: 0x100
	};
	ASSERT_STRUCT_SIZE(scr_block_s, 0x118);
	ASSERT_STRUCT_OFFSET(scr_block_s, abortLevel, 0x0);
	ASSERT_STRUCT_OFFSET(scr_block_s, localVarsCreateCount, 0x4);
	ASSERT_STRUCT_OFFSET(scr_block_s, localVarsPublicCount, 0x8);
	ASSERT_STRUCT_OFFSET(scr_block_s, localVarsCount, 0xC);
	ASSERT_STRUCT_OFFSET(scr_block_s, localVarsInitBits, 0x10);
	ASSERT_STRUCT_OFFSET(scr_block_s, localVars, 0x18);

	struct PrecacheEntry
	{
		unsigned __int16 filename; //OFS: 0x0 SIZE: 0x2
		bool include; //OFS: 0x2 SIZE: 0x1
		unsigned int sourcePos; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(PrecacheEntry, 0x8);
	ASSERT_STRUCT_OFFSET(PrecacheEntry, filename, 0x0);
	ASSERT_STRUCT_OFFSET(PrecacheEntry, include, 0x2);
	ASSERT_STRUCT_OFFSET(PrecacheEntry, sourcePos, 0x4);

	union sval_u
	{
		char type; //OFS: 0x0 SIZE: 0x1
		unsigned int stringValue; //OFS: 0x1 SIZE: 0x4
		unsigned int idValue; //OFS: 0x2 SIZE: 0x4
		float floatValue; //OFS: 0x3 SIZE: 0x4
		int intValue; //OFS: 0x4 SIZE: 0x4
		sval_u * node; //OFS: 0x5 SIZE: 0x4
		unsigned int sourcePosValue; //OFS: 0x6 SIZE: 0x4
		const char * codePosValue; //OFS: 0x7 SIZE: 0x4
		const char * debugString; //OFS: 0x8 SIZE: 0x4
		scr_block_s * block; //OFS: 0x9 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(sval_u, 0x4);

	struct VariableCompileValue
	{
		VariableValue value; //OFS: 0x0 SIZE: 0x8
		sval_u sourcePos; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(VariableCompileValue, 0xC);
	ASSERT_STRUCT_OFFSET(VariableCompileValue, value, 0x0);
	ASSERT_STRUCT_OFFSET(VariableCompileValue, sourcePos, 0x8);

	struct scrCompileGlob_t
	{
		char * codePos; //OFS: 0x0 SIZE: 0x4
		char * prevOpcodePos; //OFS: 0x4 SIZE: 0x4
		unsigned int filePosId; //OFS: 0x8 SIZE: 0x4
		unsigned int fileCountId; //OFS: 0xC SIZE: 0x4
		int cumulOffset; //OFS: 0x10 SIZE: 0x4
		int maxOffset; //OFS: 0x14 SIZE: 0x4
		int maxCallOffset; //OFS: 0x18 SIZE: 0x4
		bool bConstRefCount; //OFS: 0x1C SIZE: 0x1
		bool in_developer_thread; //OFS: 0x1D SIZE: 0x1
		unsigned int developer_thread_sourcePos; //OFS: 0x20 SIZE: 0x4
		bool firstThread[2]; //OFS: 0x24 SIZE: 0x2
		CaseStatementInfo * currentCaseStatement; //OFS: 0x28 SIZE: 0x4
		bool bCanBreak; //OFS: 0x2C SIZE: 0x1
		BreakStatementInfo * currentBreakStatement; //OFS: 0x30 SIZE: 0x4
		bool bCanContinue; //OFS: 0x34 SIZE: 0x1
		ContinueStatementInfo * currentContinueStatement; //OFS: 0x38 SIZE: 0x4
		scr_block_s ** breakChildBlocks; //OFS: 0x3C SIZE: 0x4
		int * breakChildCount; //OFS: 0x40 SIZE: 0x4
		scr_block_s * breakBlock; //OFS: 0x44 SIZE: 0x4
		scr_block_s ** continueChildBlocks; //OFS: 0x48 SIZE: 0x4
		int * continueChildCount; //OFS: 0x4C SIZE: 0x4
		bool forceNotCreate; //OFS: 0x50 SIZE: 0x1
		PrecacheEntry * precachescriptList; //OFS: 0x54 SIZE: 0x4
		VariableCompileValue value_start[32]; //OFS: 0x58 SIZE: 0x180
	};
	ASSERT_STRUCT_SIZE(scrCompileGlob_t, 0x1D8);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, codePos, 0x0);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, prevOpcodePos, 0x4);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, filePosId, 0x8);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, fileCountId, 0xC);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, cumulOffset, 0x10);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, maxOffset, 0x14);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, maxCallOffset, 0x18);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, bConstRefCount, 0x1C);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, in_developer_thread, 0x1D);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, developer_thread_sourcePos, 0x20);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, firstThread, 0x24);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, currentCaseStatement, 0x28);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, bCanBreak, 0x2C);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, currentBreakStatement, 0x30);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, bCanContinue, 0x34);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, currentContinueStatement, 0x38);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, breakChildBlocks, 0x3C);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, breakChildCount, 0x40);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, breakBlock, 0x44);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, continueChildBlocks, 0x48);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, continueChildCount, 0x4C);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, forceNotCreate, 0x50);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, precachescriptList, 0x54);
	ASSERT_STRUCT_OFFSET(scrCompileGlob_t, value_start, 0x58);

	struct scrCompilePub_t
	{
		int value_count; //OFS: 0x0 SIZE: 0x4
		int far_function_count; //OFS: 0x4 SIZE: 0x4
		unsigned int loadedscripts; //OFS: 0x8 SIZE: 0x4
		unsigned int scriptsPos; //OFS: 0xC SIZE: 0x4
		unsigned int scriptsCount; //OFS: 0x10 SIZE: 0x4
		unsigned int builtinFunc; //OFS: 0x14 SIZE: 0x4
		unsigned int builtinMeth; //OFS: 0x18 SIZE: 0x4
		unsigned __int16 canonicalStrings[65536]; //OFS: 0x1C SIZE: 0x20000
		const char * in_ptr; //OFS: 0x2001C SIZE: 0x4
		const char * parseBuf; //OFS: 0x20020 SIZE: 0x4
		bool script_loading; //OFS: 0x20024 SIZE: 0x1
		bool allowedBreakpoint; //OFS: 0x20025 SIZE: 0x1
		int developer_statement; //OFS: 0x20028 SIZE: 0x4
		char * opcodePos; //OFS: 0x2002C SIZE: 0x4
		unsigned int programLen; //OFS: 0x20030 SIZE: 0x4
		int func_table_size; //OFS: 0x20034 SIZE: 0x4
		int func_table[1024]; //OFS: 0x20038 SIZE: 0x1000
	};
	ASSERT_STRUCT_SIZE(scrCompilePub_t, 0x21038);
	ASSERT_STRUCT_OFFSET(scrCompilePub_t, value_count, 0x0);
	ASSERT_STRUCT_OFFSET(scrCompilePub_t, far_function_count, 0x4);
	ASSERT_STRUCT_OFFSET(scrCompilePub_t, loadedscripts, 0x8);
	ASSERT_STRUCT_OFFSET(scrCompilePub_t, scriptsPos, 0xC);
	ASSERT_STRUCT_OFFSET(scrCompilePub_t, scriptsCount, 0x10);
	ASSERT_STRUCT_OFFSET(scrCompilePub_t, builtinFunc, 0x14);
	ASSERT_STRUCT_OFFSET(scrCompilePub_t, builtinMeth, 0x18);
	ASSERT_STRUCT_OFFSET(scrCompilePub_t, canonicalStrings, 0x1C);
	ASSERT_STRUCT_OFFSET(scrCompilePub_t, in_ptr, 0x2001C);
	ASSERT_STRUCT_OFFSET(scrCompilePub_t, parseBuf, 0x20020);
	ASSERT_STRUCT_OFFSET(scrCompilePub_t, script_loading, 0x20024);
	ASSERT_STRUCT_OFFSET(scrCompilePub_t, allowedBreakpoint, 0x20025);
	ASSERT_STRUCT_OFFSET(scrCompilePub_t, developer_statement, 0x20028);
	ASSERT_STRUCT_OFFSET(scrCompilePub_t, opcodePos, 0x2002C);
	ASSERT_STRUCT_OFFSET(scrCompilePub_t, programLen, 0x20030);
	ASSERT_STRUCT_OFFSET(scrCompilePub_t, func_table_size, 0x20034);
	ASSERT_STRUCT_OFFSET(scrCompilePub_t, func_table, 0x20038);

	struct animScriptCondition_t
	{
		int index; //OFS: 0x0 SIZE: 0x4
		unsigned int value[2]; //OFS: 0x4 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(animScriptCondition_t, 0xC);
	ASSERT_STRUCT_OFFSET(animScriptCondition_t, index, 0x0);
	ASSERT_STRUCT_OFFSET(animScriptCondition_t, value, 0x4);

	struct animScriptCommand_t
	{
		__int16 bodyPart[2]; //OFS: 0x0 SIZE: 0x4
		__int16 animIndex[2]; //OFS: 0x4 SIZE: 0x4
		unsigned __int16 animDuration[2]; //OFS: 0x8 SIZE: 0x4
		snd_alias_list_t * soundAlias; //OFS: 0xC SIZE: 0x4
		unsigned __int16 tagName; //OFS: 0x10 SIZE: 0x2
		unsigned __int16 flags; //OFS: 0x12 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(animScriptCommand_t, 0x14);
	ASSERT_STRUCT_OFFSET(animScriptCommand_t, bodyPart, 0x0);
	ASSERT_STRUCT_OFFSET(animScriptCommand_t, animIndex, 0x4);
	ASSERT_STRUCT_OFFSET(animScriptCommand_t, animDuration, 0x8);
	ASSERT_STRUCT_OFFSET(animScriptCommand_t, soundAlias, 0xC);
	ASSERT_STRUCT_OFFSET(animScriptCommand_t, tagName, 0x10);
	ASSERT_STRUCT_OFFSET(animScriptCommand_t, flags, 0x12);

	struct animScriptItem_t
	{
		int numConditions; //OFS: 0x0 SIZE: 0x4
		animScriptCondition_t conditions[4]; //OFS: 0x4 SIZE: 0x30
		int numCommands; //OFS: 0x34 SIZE: 0x4
		animScriptCommand_t commands[8]; //OFS: 0x38 SIZE: 0xA0
	};
	ASSERT_STRUCT_SIZE(animScriptItem_t, 0xD8);
	ASSERT_STRUCT_OFFSET(animScriptItem_t, numConditions, 0x0);
	ASSERT_STRUCT_OFFSET(animScriptItem_t, conditions, 0x4);
	ASSERT_STRUCT_OFFSET(animScriptItem_t, numCommands, 0x34);
	ASSERT_STRUCT_OFFSET(animScriptItem_t, commands, 0x38);

	struct animScript_t
	{
		int numItems; //OFS: 0x0 SIZE: 0x4
		animScriptItem_t * items[128]; //OFS: 0x4 SIZE: 0x200
	};
	ASSERT_STRUCT_SIZE(animScript_t, 0x204);
	ASSERT_STRUCT_OFFSET(animScript_t, numItems, 0x0);
	ASSERT_STRUCT_OFFSET(animScript_t, items, 0x4);

	struct scr_animtree_t
	{
		XAnim_s * anims; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(scr_animtree_t, 0x4);
	ASSERT_STRUCT_OFFSET(scr_animtree_t, anims, 0x0);

	struct scrAnimPub_t
	{
		unsigned int animtrees; //OFS: 0x0 SIZE: 0x4
		unsigned int animtree_node; //OFS: 0x4 SIZE: 0x4
		unsigned int animTreeNames; //OFS: 0x8 SIZE: 0x4
		scr_animtree_t xanim_lookup[2][128]; //OFS: 0xC SIZE: 0x400
		unsigned int xanim_num[2]; //OFS: 0x40C SIZE: 0x8
		unsigned int animTreeIndex; //OFS: 0x414 SIZE: 0x4
		bool animtree_loading; //OFS: 0x418 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(scrAnimPub_t, 0x41C);
	ASSERT_STRUCT_OFFSET(scrAnimPub_t, animtrees, 0x0);
	ASSERT_STRUCT_OFFSET(scrAnimPub_t, animtree_node, 0x4);
	ASSERT_STRUCT_OFFSET(scrAnimPub_t, animTreeNames, 0x8);
	ASSERT_STRUCT_OFFSET(scrAnimPub_t, xanim_lookup, 0xC);
	ASSERT_STRUCT_OFFSET(scrAnimPub_t, xanim_num, 0x40C);
	ASSERT_STRUCT_OFFSET(scrAnimPub_t, animTreeIndex, 0x414);
	ASSERT_STRUCT_OFFSET(scrAnimPub_t, animtree_loading, 0x418);

	struct scrAnimGlob_t
	{
		char * start; //OFS: 0x0 SIZE: 0x4
		char * pos; //OFS: 0x4 SIZE: 0x4
		unsigned __int16 using_xanim_lookup[2][128]; //OFS: 0x8 SIZE: 0x200
		int bAnimCheck; //OFS: 0x208 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(scrAnimGlob_t, 0x20C);
	ASSERT_STRUCT_OFFSET(scrAnimGlob_t, start, 0x0);
	ASSERT_STRUCT_OFFSET(scrAnimGlob_t, pos, 0x4);
	ASSERT_STRUCT_OFFSET(scrAnimGlob_t, using_xanim_lookup, 0x8);
	ASSERT_STRUCT_OFFSET(scrAnimGlob_t, bAnimCheck, 0x208);

	struct cscr_data_t
	{
		int delete_; //OFS: 0x0 SIZE: 0x4
		int initstructs; //OFS: 0x4 SIZE: 0x4
		int createstruct; //OFS: 0x8 SIZE: 0x4
		int field_C; //OFS: 0xC SIZE: 0x4
		int statechange; //OFS: 0x10 SIZE: 0x4
		int maprestart; //OFS: 0x14 SIZE: 0x4
		int localclientconnect; //OFS: 0x18 SIZE: 0x4
		int localclientdisconnect; //OFS: 0x1C SIZE: 0x4
		int entityspawned; //OFS: 0x20 SIZE: 0x4
		int scriptmodelspawned; //OFS: 0x24 SIZE: 0x4
		int playfootstep; //OFS: 0x28 SIZE: 0x4
		int activateexploder; //OFS: 0x2C SIZE: 0x4
		int deactivateexploder; //OFS: 0x30 SIZE: 0x4
		int levelnotify; //OFS: 0x34 SIZE: 0x4
		int field_38; //OFS: 0x38 SIZE: 0x4
		int field_3C; //OFS: 0x3C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(cscr_data_t, 0x40);
	ASSERT_STRUCT_OFFSET(cscr_data_t, delete_, 0x0);
	ASSERT_STRUCT_OFFSET(cscr_data_t, initstructs, 0x4);
	ASSERT_STRUCT_OFFSET(cscr_data_t, createstruct, 0x8);
	ASSERT_STRUCT_OFFSET(cscr_data_t, field_C, 0xC);
	ASSERT_STRUCT_OFFSET(cscr_data_t, statechange, 0x10);
	ASSERT_STRUCT_OFFSET(cscr_data_t, maprestart, 0x14);
	ASSERT_STRUCT_OFFSET(cscr_data_t, localclientconnect, 0x18);
	ASSERT_STRUCT_OFFSET(cscr_data_t, localclientdisconnect, 0x1C);
	ASSERT_STRUCT_OFFSET(cscr_data_t, entityspawned, 0x20);
	ASSERT_STRUCT_OFFSET(cscr_data_t, scriptmodelspawned, 0x24);
	ASSERT_STRUCT_OFFSET(cscr_data_t, playfootstep, 0x28);
	ASSERT_STRUCT_OFFSET(cscr_data_t, activateexploder, 0x2C);
	ASSERT_STRUCT_OFFSET(cscr_data_t, deactivateexploder, 0x30);
	ASSERT_STRUCT_OFFSET(cscr_data_t, levelnotify, 0x34);
	ASSERT_STRUCT_OFFSET(cscr_data_t, field_38, 0x38);
	ASSERT_STRUCT_OFFSET(cscr_data_t, field_3C, 0x3C);

	struct __declspec(align(2)) cscr_const_t
	{
		unsigned __int16 movedone; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 rotatedone; //OFS: 0x2 SIZE: 0x2
		unsigned __int16 entityshutdown; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 front_left; //OFS: 0x6 SIZE: 0x2
		unsigned __int16 front_right; //OFS: 0x8 SIZE: 0x2
		unsigned __int16 back_left; //OFS: 0xA SIZE: 0x2
		unsigned __int16 back_right; //OFS: 0xC SIZE: 0x2
		unsigned __int16 middle_left; //OFS: 0xE SIZE: 0x2
		unsigned __int16 middle_right; //OFS: 0x10 SIZE: 0x2
		unsigned __int16 fraction; //OFS: 0x12 SIZE: 0x2
		unsigned __int16 position; //OFS: 0x14 SIZE: 0x2
		unsigned __int16 entity; //OFS: 0x16 SIZE: 0x2
		unsigned __int16 normal; //OFS: 0x18 SIZE: 0x2
		unsigned __int16 surfacetype; //OFS: 0x1A SIZE: 0x2
		unsigned __int16 weapon_fired; //OFS: 0x1C SIZE: 0x2
		unsigned __int16 none; //OFS: 0x1E SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(cscr_const_t, 0x20);
	ASSERT_STRUCT_OFFSET(cscr_const_t, movedone, 0x0);
	ASSERT_STRUCT_OFFSET(cscr_const_t, rotatedone, 0x2);
	ASSERT_STRUCT_OFFSET(cscr_const_t, entityshutdown, 0x4);
	ASSERT_STRUCT_OFFSET(cscr_const_t, front_left, 0x6);
	ASSERT_STRUCT_OFFSET(cscr_const_t, front_right, 0x8);
	ASSERT_STRUCT_OFFSET(cscr_const_t, back_left, 0xA);
	ASSERT_STRUCT_OFFSET(cscr_const_t, back_right, 0xC);
	ASSERT_STRUCT_OFFSET(cscr_const_t, middle_left, 0xE);
	ASSERT_STRUCT_OFFSET(cscr_const_t, middle_right, 0x10);
	ASSERT_STRUCT_OFFSET(cscr_const_t, fraction, 0x12);
	ASSERT_STRUCT_OFFSET(cscr_const_t, position, 0x14);
	ASSERT_STRUCT_OFFSET(cscr_const_t, entity, 0x16);
	ASSERT_STRUCT_OFFSET(cscr_const_t, normal, 0x18);
	ASSERT_STRUCT_OFFSET(cscr_const_t, surfacetype, 0x1A);
	ASSERT_STRUCT_OFFSET(cscr_const_t, weapon_fired, 0x1C);
	ASSERT_STRUCT_OFFSET(cscr_const_t, none, 0x1E);

	struct __declspec(align(2)) scr_entref_t
	{
		unsigned __int16 entnum; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 classnum; //OFS: 0x2 SIZE: 0x2
		unsigned __int16 client; //OFS: 0x4 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(scr_entref_t, 0x6);
	ASSERT_STRUCT_OFFSET(scr_entref_t, entnum, 0x0);
	ASSERT_STRUCT_OFFSET(scr_entref_t, classnum, 0x2);
	ASSERT_STRUCT_OFFSET(scr_entref_t, client, 0x4);

	struct __declspec(align(2)) scr_const_t
	{
		unsigned __int16 _; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 active2; //OFS: 0x2 SIZE: 0x2
		unsigned __int16 j_spine4; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 j_helmet; //OFS: 0x6 SIZE: 0x2
		unsigned __int16 j_head; //OFS: 0x8 SIZE: 0x2
		unsigned __int16 all; //OFS: 0xA SIZE: 0x2
		unsigned __int16 allies; //OFS: 0xC SIZE: 0x2
		unsigned __int16 axis; //OFS: 0xE SIZE: 0x2
		unsigned __int16 bad_path; //OFS: 0x10 SIZE: 0x2
		unsigned __int16 begin_firing; //OFS: 0x12 SIZE: 0x2
		unsigned __int16 unknown_location; //OFS: 0x14 SIZE: 0x2
		unsigned __int16 cancel_location; //OFS: 0x16 SIZE: 0x2
		unsigned __int16 confirm_location; //OFS: 0x18 SIZE: 0x2
		unsigned __int16 regroup_location; //OFS: 0x1A SIZE: 0x2
		unsigned __int16 defend_location; //OFS: 0x1C SIZE: 0x2
		unsigned __int16 clear_squadcommand; //OFS: 0x1E SIZE: 0x2
		unsigned __int16 squadleader_changed; //OFS: 0x20 SIZE: 0x2
		unsigned __int16 squad_disbanded; //OFS: 0x22 SIZE: 0x2
		unsigned __int16 deployed_turret; //OFS: 0x24 SIZE: 0x2
		unsigned __int16 crouch; //OFS: 0x26 SIZE: 0x2
		unsigned __int16 current; //OFS: 0x28 SIZE: 0x2
		unsigned __int16 damage; //OFS: 0x2A SIZE: 0x2
		unsigned __int16 dead; //OFS: 0x2C SIZE: 0x2
		unsigned __int16 death; //OFS: 0x2E SIZE: 0x2
		unsigned __int16 disconnect; //OFS: 0x30 SIZE: 0x2
		unsigned __int16 death_or_disconnect; //OFS: 0x32 SIZE: 0x2
		unsigned __int16 detonate; //OFS: 0x34 SIZE: 0x2
		unsigned __int16 direct; //OFS: 0x36 SIZE: 0x2
		unsigned __int16 dlight; //OFS: 0x38 SIZE: 0x2
		unsigned __int16 done; //OFS: 0x3A SIZE: 0x2
		unsigned __int16 empty; //OFS: 0x3C SIZE: 0x2
		unsigned __int16 end_firing; //OFS: 0x3E SIZE: 0x2
		unsigned __int16 enter_vehicle; //OFS: 0x40 SIZE: 0x2
		unsigned __int16 entity; //OFS: 0x42 SIZE: 0x2
		unsigned __int16 exit_vehicle; //OFS: 0x44 SIZE: 0x2
		unsigned __int16 change_seat; //OFS: 0x46 SIZE: 0x2
		unsigned __int16 vehicle_death; //OFS: 0x48 SIZE: 0x2
		unsigned __int16 explode; //OFS: 0x4A SIZE: 0x2
		unsigned __int16 failed; //OFS: 0x4C SIZE: 0x2
		unsigned __int16 free; //OFS: 0x4E SIZE: 0x2
		unsigned __int16 fraction; //OFS: 0x50 SIZE: 0x2
		unsigned __int16 goal; //OFS: 0x52 SIZE: 0x2
		unsigned __int16 goal_changed; //OFS: 0x54 SIZE: 0x2
		unsigned __int16 goal_yaw; //OFS: 0x56 SIZE: 0x2
		unsigned __int16 grenade; //OFS: 0x58 SIZE: 0x2
		unsigned __int16 grenade_danger; //OFS: 0x5A SIZE: 0x2
		unsigned __int16 grenade_fire; //OFS: 0x5C SIZE: 0x2
		unsigned __int16 grenade_launcher_fire; //OFS: 0x5E SIZE: 0x2
		unsigned __int16 grenade_pullback; //OFS: 0x60 SIZE: 0x2
		unsigned __int16 info_notnull; //OFS: 0x62 SIZE: 0x2
		unsigned __int16 invisible; //OFS: 0x64 SIZE: 0x2
		unsigned __int16 key1; //OFS: 0x66 SIZE: 0x2
		unsigned __int16 key2; //OFS: 0x68 SIZE: 0x2
		unsigned __int16 killanimscript; //OFS: 0x6A SIZE: 0x2
		unsigned __int16 left; //OFS: 0x6C SIZE: 0x2
		unsigned __int16 left_tread; //OFS: 0x6E SIZE: 0x2
		unsigned __int16 light; //OFS: 0x70 SIZE: 0x2
		unsigned __int16 movedone; //OFS: 0x72 SIZE: 0x2
		unsigned __int16 noclass; //OFS: 0x74 SIZE: 0x2
		unsigned __int16 none; //OFS: 0x76 SIZE: 0x2
		unsigned __int16 normal; //OFS: 0x78 SIZE: 0x2
		unsigned __int16 player; //OFS: 0x7A SIZE: 0x2
		unsigned __int16 position; //OFS: 0x7C SIZE: 0x2
		unsigned __int16 projectile_impact; //OFS: 0x7E SIZE: 0x2
		unsigned __int16 prone; //OFS: 0x80 SIZE: 0x2
		unsigned __int16 right; //OFS: 0x82 SIZE: 0x2
		unsigned __int16 right_tread; //OFS: 0x84 SIZE: 0x2
		unsigned __int16 tank_armor; //OFS: 0x86 SIZE: 0x2
		unsigned __int16 reload; //OFS: 0x88 SIZE: 0x2
		unsigned __int16 reload_start; //OFS: 0x8A SIZE: 0x2
		unsigned __int16 rocket; //OFS: 0x8C SIZE: 0x2
		unsigned __int16 rotatedone; //OFS: 0x8E SIZE: 0x2
		unsigned __int16 script_brushmodel; //OFS: 0x90 SIZE: 0x2
		unsigned __int16 script_model; //OFS: 0x92 SIZE: 0x2
		unsigned __int16 script_origin; //OFS: 0x94 SIZE: 0x2
		unsigned __int16 snd_enveffectsprio_level; //OFS: 0x96 SIZE: 0x2
		unsigned __int16 snd_enveffectsprio_shellshock; //OFS: 0x98 SIZE: 0x2
		unsigned __int16 snd_busvolprio_holdbreath; //OFS: 0x9A SIZE: 0x2
		unsigned __int16 snd_busvolprio_pain; //OFS: 0x9C SIZE: 0x2
		unsigned __int16 snd_busvolprio_shellshock; //OFS: 0x9E SIZE: 0x2
		unsigned __int16 stand; //OFS: 0xA0 SIZE: 0x2
		unsigned __int16 suppression; //OFS: 0xA2 SIZE: 0x2
		unsigned __int16 suppression_end; //OFS: 0xA4 SIZE: 0x2
		unsigned __int16 surfacetype; //OFS: 0xA6 SIZE: 0x2
		unsigned __int16 tag_aim; //OFS: 0xA8 SIZE: 0x2
		unsigned __int16 tag_aim_animated; //OFS: 0xAA SIZE: 0x2
		unsigned __int16 tag_brass; //OFS: 0xAC SIZE: 0x2
		unsigned __int16 tag_butt; //OFS: 0xAE SIZE: 0x2
		unsigned __int16 tag_clip; //OFS: 0xB0 SIZE: 0x2
		unsigned __int16 tag_flash; //OFS: 0xB2 SIZE: 0x2
		unsigned __int16 tag_flash_11; //OFS: 0xB4 SIZE: 0x2
		unsigned __int16 tag_flash_2; //OFS: 0xB6 SIZE: 0x2
		unsigned __int16 tag_flash_22; //OFS: 0xB8 SIZE: 0x2
		unsigned __int16 tag_flash_3; //OFS: 0xBA SIZE: 0x2
		unsigned __int16 tag_fx; //OFS: 0xBC SIZE: 0x2
		unsigned __int16 tag_inhand2; //OFS: 0xBE SIZE: 0x2
		unsigned __int16 tag_knife_attach; //OFS: 0xC0 SIZE: 0x2
		unsigned __int16 tag_knife_fx; //OFS: 0xC2 SIZE: 0x2
		unsigned __int16 tag_bayonet; //OFS: 0xC4 SIZE: 0x2
		unsigned __int16 tag_laser; //OFS: 0xC6 SIZE: 0x2
		unsigned __int16 tag_origin; //OFS: 0xC8 SIZE: 0x2
		unsigned __int16 tag_weapon; //OFS: 0xCA SIZE: 0x2
		unsigned __int16 tag_player2; //OFS: 0xCC SIZE: 0x2
		unsigned __int16 tag_camera; //OFS: 0xCE SIZE: 0x2
		unsigned __int16 tag_weapon_right; //OFS: 0xD0 SIZE: 0x2
		unsigned __int16 tag_gasmask; //OFS: 0xD2 SIZE: 0x2
		unsigned __int16 tag_gasmask2; //OFS: 0xD4 SIZE: 0x2
		unsigned __int16 tag_sync; //OFS: 0xD6 SIZE: 0x2
		unsigned __int16 tag_wake; //OFS: 0xD8 SIZE: 0x2
		unsigned __int16 target_script_trigger; //OFS: 0xDA SIZE: 0x2
		unsigned __int16 tempEntity; //OFS: 0xDC SIZE: 0x2
		unsigned __int16 top; //OFS: 0xDE SIZE: 0x2
		unsigned __int16 touch; //OFS: 0xE0 SIZE: 0x2
		unsigned __int16 trigger; //OFS: 0xE2 SIZE: 0x2
		unsigned __int16 trigger_use; //OFS: 0xE4 SIZE: 0x2
		unsigned __int16 trigger_use_touch; //OFS: 0xE6 SIZE: 0x2
		unsigned __int16 trigger_damage; //OFS: 0xE8 SIZE: 0x2
		unsigned __int16 trigger_lookat; //OFS: 0xEA SIZE: 0x2
		unsigned __int16 trigger_radius; //OFS: 0xEC SIZE: 0x2
		unsigned __int16 truck_cam; //OFS: 0xEE SIZE: 0x2
		unsigned __int16 weapon_change_on_turret; //OFS: 0xF0 SIZE: 0x2
		unsigned __int16 weapon_change; //OFS: 0xF2 SIZE: 0x2
		unsigned __int16 weapon_change_complete; //OFS: 0xF4 SIZE: 0x2
		unsigned __int16 weapon_fired; //OFS: 0xF6 SIZE: 0x2
		unsigned __int16 weapon_pvp_attack; //OFS: 0xF8 SIZE: 0x2
		unsigned __int16 worldspawn; //OFS: 0xFA SIZE: 0x2
		unsigned __int16 flashbang; //OFS: 0xFC SIZE: 0x2
		unsigned __int16 flash; //OFS: 0xFE SIZE: 0x2
		unsigned __int16 smoke; //OFS: 0x100 SIZE: 0x2
		unsigned __int16 night_vision_on; //OFS: 0x102 SIZE: 0x2
		unsigned __int16 night_vision_off; //OFS: 0x104 SIZE: 0x2
		unsigned __int16 back_low; //OFS: 0x106 SIZE: 0x2
		unsigned __int16 back_mid; //OFS: 0x108 SIZE: 0x2
		unsigned __int16 back_up; //OFS: 0x10A SIZE: 0x2
		unsigned __int16 head; //OFS: 0x10C SIZE: 0x2
		unsigned __int16 j_mainroot; //OFS: 0x10E SIZE: 0x2
		unsigned __int16 neck; //OFS: 0x110 SIZE: 0x2
		unsigned __int16 pelvis; //OFS: 0x112 SIZE: 0x2
		unsigned __int16 j_head2; //OFS: 0x114 SIZE: 0x2
		unsigned __int16 MOD_UNKNOWN; //OFS: 0x116 SIZE: 0x2
		unsigned __int16 MOD_PISTOL_BULLET; //OFS: 0x118 SIZE: 0x2
		unsigned __int16 MOD_RIFLE_BULLET; //OFS: 0x11A SIZE: 0x2
		unsigned __int16 MOD_GRENADE; //OFS: 0x11C SIZE: 0x2
		unsigned __int16 MOD_GRENADE_SPLASH; //OFS: 0x11E SIZE: 0x2
		unsigned __int16 MOD_PROJECTILE; //OFS: 0x120 SIZE: 0x2
		unsigned __int16 MOD_PROJECTILE_SPLASH; //OFS: 0x122 SIZE: 0x2
		unsigned __int16 MOD_MELEE; //OFS: 0x124 SIZE: 0x2
		unsigned __int16 MOD_BAYONET; //OFS: 0x126 SIZE: 0x2
		unsigned __int16 MOD_HEAD_SHOT; //OFS: 0x128 SIZE: 0x2
		unsigned __int16 MOD_CRUSH; //OFS: 0x12A SIZE: 0x2
		unsigned __int16 MOD_TELEFRAG; //OFS: 0x12C SIZE: 0x2
		unsigned __int16 MOD_FALLING; //OFS: 0x12E SIZE: 0x2
		unsigned __int16 MOD_SUICIDE; //OFS: 0x130 SIZE: 0x2
		unsigned __int16 MOD_TRIGGER_HURT; //OFS: 0x132 SIZE: 0x2
		unsigned __int16 MOD_EXPLOSIVE; //OFS: 0x134 SIZE: 0x2
		unsigned __int16 MOD_IMPACT; //OFS: 0x136 SIZE: 0x2
		unsigned __int16 MOD_BURNED; //OFS: 0x138 SIZE: 0x2
		unsigned __int16 MOD_HIT_BY_OBJECT; //OFS: 0x13A SIZE: 0x2
		unsigned __int16 MOD_DROWN; //OFS: 0x13C SIZE: 0x2
		unsigned __int16 script_vehicle; //OFS: 0x13E SIZE: 0x2
		unsigned __int16 script_vehicle_collision; //OFS: 0x140 SIZE: 0x2
		unsigned __int16 script_vehicle_collmap; //OFS: 0x142 SIZE: 0x2
		unsigned __int16 script_vehicle_corpse; //OFS: 0x144 SIZE: 0x2
		unsigned __int16 turret_fire; //OFS: 0x146 SIZE: 0x2
		unsigned __int16 turret_on_target; //OFS: 0x148 SIZE: 0x2
		unsigned __int16 turret_not_on_target; //OFS: 0x14A SIZE: 0x2
		unsigned __int16 turret_on_vistarget; //OFS: 0x14C SIZE: 0x2
		unsigned __int16 turret_no_vis; //OFS: 0x14E SIZE: 0x2
		unsigned __int16 turret_rotate_stopped; //OFS: 0x150 SIZE: 0x2
		unsigned __int16 turret_deactivate; //OFS: 0x152 SIZE: 0x2
		unsigned __int16 turretstatechange; //OFS: 0x154 SIZE: 0x2
		unsigned __int16 turretownerchange; //OFS: 0x156 SIZE: 0x2
		unsigned __int16 reached_end_node; //OFS: 0x158 SIZE: 0x2
		unsigned __int16 reached_wait_node; //OFS: 0x15A SIZE: 0x2
		unsigned __int16 reached_wait_speed; //OFS: 0x15C SIZE: 0x2
		unsigned __int16 near_goal; //OFS: 0x15E SIZE: 0x2
		unsigned __int16 veh_collision; //OFS: 0x160 SIZE: 0x2
		unsigned __int16 veh_predictedcollision; //OFS: 0x162 SIZE: 0x2
		unsigned __int16 script_camera; //OFS: 0x164 SIZE: 0x2
		unsigned __int16 begin; //OFS: 0x166 SIZE: 0x2
		unsigned __int16 curve_nodehit; //OFS: 0x168 SIZE: 0x2
		unsigned __int16 curve_start; //OFS: 0x16A SIZE: 0x2
		unsigned __int16 curve_end; //OFS: 0x16C SIZE: 0x2
		unsigned __int16 tag_enter_driver; //OFS: 0x16E SIZE: 0x2
		unsigned __int16 tag_enter_gunner1; //OFS: 0x170 SIZE: 0x2
		unsigned __int16 tag_enter_gunner2; //OFS: 0x172 SIZE: 0x2
		unsigned __int16 tag_enter_gunner3; //OFS: 0x174 SIZE: 0x2
		unsigned __int16 tag_enter_gunner4; //OFS: 0x176 SIZE: 0x2
		unsigned __int16 tag_enter_passenger; //OFS: 0x178 SIZE: 0x2
		unsigned __int16 tag_enter_passenger2; //OFS: 0x17A SIZE: 0x2
		unsigned __int16 tag_enter_passenger3; //OFS: 0x17C SIZE: 0x2
		unsigned __int16 tag_enter_passenger4; //OFS: 0x17E SIZE: 0x2
		unsigned __int16 tag_player; //OFS: 0x180 SIZE: 0x2
		unsigned __int16 tag_passenger1; //OFS: 0x182 SIZE: 0x2
		unsigned __int16 tag_passenger2; //OFS: 0x184 SIZE: 0x2
		unsigned __int16 tag_passenger3; //OFS: 0x186 SIZE: 0x2
		unsigned __int16 tag_passenger4; //OFS: 0x188 SIZE: 0x2
		unsigned __int16 tag_gunner1; //OFS: 0x18A SIZE: 0x2
		unsigned __int16 tag_gunner2; //OFS: 0x18C SIZE: 0x2
		unsigned __int16 tag_gunner3; //OFS: 0x18E SIZE: 0x2
		unsigned __int16 tag_gunner4; //OFS: 0x190 SIZE: 0x2
		unsigned __int16 tag_gunner_barrel1; //OFS: 0x192 SIZE: 0x2
		unsigned __int16 tag_gunner_barrel2; //OFS: 0x194 SIZE: 0x2
		unsigned __int16 tag_gunner_barrel3; //OFS: 0x196 SIZE: 0x2
		unsigned __int16 tag_gunner_barrel4; //OFS: 0x198 SIZE: 0x2
		unsigned __int16 tag_gunner_turret1; //OFS: 0x19A SIZE: 0x2
		unsigned __int16 tag_gunner_turret2; //OFS: 0x19C SIZE: 0x2
		unsigned __int16 tag_gunner_turret3; //OFS: 0x19E SIZE: 0x2
		unsigned __int16 tag_gunner_turret4; //OFS: 0x1A0 SIZE: 0x2
		unsigned __int16 tag_flash_gunner1; //OFS: 0x1A2 SIZE: 0x2
		unsigned __int16 tag_flash_gunner2; //OFS: 0x1A4 SIZE: 0x2
		unsigned __int16 tag_flash_gunner3; //OFS: 0x1A6 SIZE: 0x2
		unsigned __int16 tag_flash_gunner4; //OFS: 0x1A8 SIZE: 0x2
		unsigned __int16 tag_flash_gunner1a; //OFS: 0x1AA SIZE: 0x2
		unsigned __int16 tag_flash_gunner2a; //OFS: 0x1AC SIZE: 0x2
		unsigned __int16 tag_flash_gunner3a; //OFS: 0x1AE SIZE: 0x2
		unsigned __int16 tag_flash_gunner4a; //OFS: 0x1B0 SIZE: 0x2
		unsigned __int16 tag_gunner_brass1; //OFS: 0x1B2 SIZE: 0x2
		unsigned __int16 tag_gunner_hands1; //OFS: 0x1B4 SIZE: 0x2
		unsigned __int16 tag_wheel_front_left; //OFS: 0x1B6 SIZE: 0x2
		unsigned __int16 tag_wheel_front_right; //OFS: 0x1B8 SIZE: 0x2
		unsigned __int16 tag_wheel_back_left; //OFS: 0x1BA SIZE: 0x2
		unsigned __int16 tag_wheel_back_right; //OFS: 0x1BC SIZE: 0x2
		unsigned __int16 tag_wheel_middle_left; //OFS: 0x1BE SIZE: 0x2
		unsigned __int16 tag_wheel_middle_right; //OFS: 0x1C0 SIZE: 0x2
		unsigned __int16 vampire_health_regen; //OFS: 0x1C2 SIZE: 0x2
		unsigned __int16 vampire_kill; //OFS: 0x1C4 SIZE: 0x2
		unsigned __int16 morphine_shot; //OFS: 0x1C6 SIZE: 0x2
		unsigned __int16 morphine_revive; //OFS: 0x1C8 SIZE: 0x2
		unsigned __int16 freelook; //OFS: 0x1CA SIZE: 0x2
		unsigned __int16 intermission; //OFS: 0x1CC SIZE: 0x2
		unsigned __int16 playing; //OFS: 0x1CE SIZE: 0x2
		unsigned __int16 spectator; //OFS: 0x1D0 SIZE: 0x2
		unsigned __int16 action_notify_attack; //OFS: 0x1D2 SIZE: 0x2
		unsigned __int16 action_notify_melee; //OFS: 0x1D4 SIZE: 0x2
		unsigned __int16 action_notify_use_reload; //OFS: 0x1D6 SIZE: 0x2
		unsigned __int16 always; //OFS: 0x1D8 SIZE: 0x2
		unsigned __int16 auto_ai; //OFS: 0x1DA SIZE: 0x2
		unsigned __int16 auto_nonai; //OFS: 0x1DC SIZE: 0x2
		unsigned __int16 back_left; //OFS: 0x1DE SIZE: 0x2
		unsigned __int16 back_right; //OFS: 0x1E0 SIZE: 0x2
		unsigned __int16 begin_custom_anim; //OFS: 0x1E2 SIZE: 0x2
		unsigned __int16 bullethit; //OFS: 0x1E4 SIZE: 0x2
		unsigned __int16 count; //OFS: 0x1E6 SIZE: 0x2
		unsigned __int16 corner_approach; //OFS: 0x1E8 SIZE: 0x2
		unsigned __int16 damage_notdone; //OFS: 0x1EA SIZE: 0x2
		unsigned __int16 deathplant; //OFS: 0x1EC SIZE: 0x2
		unsigned __int16 front_left; //OFS: 0x1EE SIZE: 0x2
		unsigned __int16 front_right; //OFS: 0x1F0 SIZE: 0x2
		unsigned __int16 tag_inhand; //OFS: 0x1F2 SIZE: 0x2
		unsigned __int16 high_priority; //OFS: 0x1F4 SIZE: 0x2
		unsigned __int16 info_player_deathmatch; //OFS: 0x1F6 SIZE: 0x2
		unsigned __int16 infinite_energy; //OFS: 0x1F8 SIZE: 0x2
		unsigned __int16 low_priority; //OFS: 0x1FA SIZE: 0x2
		unsigned __int16 manual; //OFS: 0x1FC SIZE: 0x2
		unsigned __int16 manual_ai; //OFS: 0x1FE SIZE: 0x2
		unsigned __int16 max_time; //OFS: 0x200 SIZE: 0x2
		unsigned __int16 menuresponse; //OFS: 0x202 SIZE: 0x2
		unsigned __int16 middle_left; //OFS: 0x204 SIZE: 0x2
		unsigned __int16 middle_right; //OFS: 0x206 SIZE: 0x2
		unsigned __int16 min_energy; //OFS: 0x208 SIZE: 0x2
		unsigned __int16 min_time; //OFS: 0x20A SIZE: 0x2
		unsigned __int16 neutral; //OFS: 0x20C SIZE: 0x2
		unsigned __int16 never; //OFS: 0x20E SIZE: 0x2
		unsigned __int16 pickup; //OFS: 0x210 SIZE: 0x2
		unsigned __int16 receiver; //OFS: 0x212 SIZE: 0x2
		unsigned __int16 sound_blend; //OFS: 0x214 SIZE: 0x2
		unsigned __int16 tag_wingtipl; //OFS: 0x216 SIZE: 0x2
		unsigned __int16 tag_wingtipr; //OFS: 0x218 SIZE: 0x2
		unsigned __int16 tag_wingmidl; //OFS: 0x21A SIZE: 0x2
		unsigned __int16 tag_wingmidr; //OFS: 0x21C SIZE: 0x2
		unsigned __int16 tag_prop; //OFS: 0x21E SIZE: 0x2
		unsigned __int16 tag_end; //OFS: 0x220 SIZE: 0x2
		unsigned __int16 tag_tailtop; //OFS: 0x222 SIZE: 0x2
		unsigned __int16 tag_tailbottom; //OFS: 0x224 SIZE: 0x2
		unsigned __int16 tag_detach; //OFS: 0x226 SIZE: 0x2
		unsigned __int16 tag_passenger; //OFS: 0x228 SIZE: 0x2
		unsigned __int16 tag_enter_back; //OFS: 0x22A SIZE: 0x2
		unsigned __int16 tag_detach2; //OFS: 0x22C SIZE: 0x2
		unsigned __int16 tag_popout; //OFS: 0x22E SIZE: 0x2
		unsigned __int16 tag_body; //OFS: 0x230 SIZE: 0x2
		unsigned __int16 tag_turret; //OFS: 0x232 SIZE: 0x2
		unsigned __int16 tag_turret_base; //OFS: 0x234 SIZE: 0x2
		unsigned __int16 tag_barrel; //OFS: 0x236 SIZE: 0x2
		unsigned __int16 tag_weapon_left; //OFS: 0x238 SIZE: 0x2
		unsigned __int16 human; //OFS: 0x23A SIZE: 0x2
		unsigned __int16 custom; //OFS: 0x23C SIZE: 0x2
		unsigned __int16 angle_deltas; //OFS: 0x23E SIZE: 0x2
		unsigned __int16 bulletwhizby; //OFS: 0x240 SIZE: 0x2
		unsigned __int16 dog; //OFS: 0x242 SIZE: 0x2
		unsigned __int16 enemy; //OFS: 0x244 SIZE: 0x2
		unsigned __int16 enemy_visible; //OFS: 0x246 SIZE: 0x2
		unsigned __int16 face_angle; //OFS: 0x248 SIZE: 0x2
		unsigned __int16 face_current; //OFS: 0x24A SIZE: 0x2
		unsigned __int16 face_default; //OFS: 0x24C SIZE: 0x2
		unsigned __int16 face_direction; //OFS: 0x24E SIZE: 0x2
		unsigned __int16 face_enemy; //OFS: 0x250 SIZE: 0x2
		unsigned __int16 face_enemy_or_motion; //OFS: 0x252 SIZE: 0x2
		unsigned __int16 face_goal; //OFS: 0x254 SIZE: 0x2
		unsigned __int16 face_motion; //OFS: 0x256 SIZE: 0x2
		unsigned __int16 face_point; //OFS: 0x258 SIZE: 0x2
		unsigned __int16 gravity; //OFS: 0x25A SIZE: 0x2
		unsigned __int16 groundEntChanged; //OFS: 0x25C SIZE: 0x2
		unsigned __int16 gunshot; //OFS: 0x25E SIZE: 0x2
		unsigned __int16 obstacle; //OFS: 0x260 SIZE: 0x2
		unsigned __int16 movemode; //OFS: 0x262 SIZE: 0x2
		unsigned __int16 node_out_of_range; //OFS: 0x264 SIZE: 0x2
		unsigned __int16 node_relinquished; //OFS: 0x266 SIZE: 0x2
		unsigned __int16 node_taken; //OFS: 0x268 SIZE: 0x2
		unsigned __int16 node_not_safe; //OFS: 0x26A SIZE: 0x2
		unsigned __int16 noclip; //OFS: 0x26C SIZE: 0x2
		unsigned __int16 nogravity; //OFS: 0x26E SIZE: 0x2
		unsigned __int16 nophysics; //OFS: 0x270 SIZE: 0x2
		unsigned __int16 pain; //OFS: 0x272 SIZE: 0x2
		unsigned __int16 run; //OFS: 0x274 SIZE: 0x2
		unsigned __int16 runto_arrived; //OFS: 0x276 SIZE: 0x2
		unsigned __int16 silenced_shot; //OFS: 0x278 SIZE: 0x2
		unsigned __int16 spawned; //OFS: 0x27A SIZE: 0x2
		unsigned __int16 start_move; //OFS: 0x27C SIZE: 0x2
		unsigned __int16 stop; //OFS: 0x27E SIZE: 0x2
		unsigned __int16 stop_soon; //OFS: 0x280 SIZE: 0x2
		unsigned __int16 tag_eye; //OFS: 0x282 SIZE: 0x2
		unsigned __int16 walk; //OFS: 0x284 SIZE: 0x2
		unsigned __int16 world; //OFS: 0x286 SIZE: 0x2
		unsigned __int16 zonly_physics; //OFS: 0x288 SIZE: 0x2
		unsigned __int16 j_ankle_le; //OFS: 0x28A SIZE: 0x2
		unsigned __int16 j_ankle_ri; //OFS: 0x28C SIZE: 0x2
		unsigned __int16 j_ball_le; //OFS: 0x28E SIZE: 0x2
		unsigned __int16 j_ball_ri; //OFS: 0x290 SIZE: 0x2
		unsigned __int16 j_palm_le; //OFS: 0x292 SIZE: 0x2
		unsigned __int16 j_palm_ri; //OFS: 0x294 SIZE: 0x2
		unsigned __int16 broken; //OFS: 0x296 SIZE: 0x2
		unsigned __int16 destructible; //OFS: 0x298 SIZE: 0x2
		unsigned __int16 snapacknowledged; //OFS: 0x29A SIZE: 0x2
		unsigned __int16 disconnected; //OFS: 0x29C SIZE: 0x2
		unsigned __int16 cinematic; //OFS: 0x29E SIZE: 0x2
		unsigned __int16 uicinematic; //OFS: 0x2A0 SIZE: 0x2
		unsigned __int16 logo; //OFS: 0x2A2 SIZE: 0x2
		unsigned __int16 connecting; //OFS: 0x2A4 SIZE: 0x2
		unsigned __int16 challenging; //OFS: 0x2A6 SIZE: 0x2
		unsigned __int16 connected; //OFS: 0x2A8 SIZE: 0x2
		unsigned __int16 sendingstats; //OFS: 0x2AA SIZE: 0x2
		unsigned __int16 loading; //OFS: 0x2AC SIZE: 0x2
		unsigned __int16 primed; //OFS: 0x2AE SIZE: 0x2
		unsigned __int16 active; //OFS: 0x2B0 SIZE: 0x2
		unsigned __int16 map_restart; //OFS: 0x2B2 SIZE: 0x2
		unsigned __int16 orientdone; //OFS: 0x2B4 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(scr_const_t, 0x2B6);
	ASSERT_STRUCT_OFFSET(scr_const_t, _, 0x0);
	ASSERT_STRUCT_OFFSET(scr_const_t, active2, 0x2);
	ASSERT_STRUCT_OFFSET(scr_const_t, j_spine4, 0x4);
	ASSERT_STRUCT_OFFSET(scr_const_t, j_helmet, 0x6);
	ASSERT_STRUCT_OFFSET(scr_const_t, j_head, 0x8);
	ASSERT_STRUCT_OFFSET(scr_const_t, all, 0xA);
	ASSERT_STRUCT_OFFSET(scr_const_t, allies, 0xC);
	ASSERT_STRUCT_OFFSET(scr_const_t, axis, 0xE);
	ASSERT_STRUCT_OFFSET(scr_const_t, bad_path, 0x10);
	ASSERT_STRUCT_OFFSET(scr_const_t, begin_firing, 0x12);
	ASSERT_STRUCT_OFFSET(scr_const_t, unknown_location, 0x14);
	ASSERT_STRUCT_OFFSET(scr_const_t, cancel_location, 0x16);
	ASSERT_STRUCT_OFFSET(scr_const_t, confirm_location, 0x18);
	ASSERT_STRUCT_OFFSET(scr_const_t, regroup_location, 0x1A);
	ASSERT_STRUCT_OFFSET(scr_const_t, defend_location, 0x1C);
	ASSERT_STRUCT_OFFSET(scr_const_t, clear_squadcommand, 0x1E);
	ASSERT_STRUCT_OFFSET(scr_const_t, squadleader_changed, 0x20);
	ASSERT_STRUCT_OFFSET(scr_const_t, squad_disbanded, 0x22);
	ASSERT_STRUCT_OFFSET(scr_const_t, deployed_turret, 0x24);
	ASSERT_STRUCT_OFFSET(scr_const_t, crouch, 0x26);
	ASSERT_STRUCT_OFFSET(scr_const_t, current, 0x28);
	ASSERT_STRUCT_OFFSET(scr_const_t, damage, 0x2A);
	ASSERT_STRUCT_OFFSET(scr_const_t, dead, 0x2C);
	ASSERT_STRUCT_OFFSET(scr_const_t, death, 0x2E);
	ASSERT_STRUCT_OFFSET(scr_const_t, disconnect, 0x30);
	ASSERT_STRUCT_OFFSET(scr_const_t, death_or_disconnect, 0x32);
	ASSERT_STRUCT_OFFSET(scr_const_t, detonate, 0x34);
	ASSERT_STRUCT_OFFSET(scr_const_t, direct, 0x36);
	ASSERT_STRUCT_OFFSET(scr_const_t, dlight, 0x38);
	ASSERT_STRUCT_OFFSET(scr_const_t, done, 0x3A);
	ASSERT_STRUCT_OFFSET(scr_const_t, empty, 0x3C);
	ASSERT_STRUCT_OFFSET(scr_const_t, end_firing, 0x3E);
	ASSERT_STRUCT_OFFSET(scr_const_t, enter_vehicle, 0x40);
	ASSERT_STRUCT_OFFSET(scr_const_t, entity, 0x42);
	ASSERT_STRUCT_OFFSET(scr_const_t, exit_vehicle, 0x44);
	ASSERT_STRUCT_OFFSET(scr_const_t, change_seat, 0x46);
	ASSERT_STRUCT_OFFSET(scr_const_t, vehicle_death, 0x48);
	ASSERT_STRUCT_OFFSET(scr_const_t, explode, 0x4A);
	ASSERT_STRUCT_OFFSET(scr_const_t, failed, 0x4C);
	ASSERT_STRUCT_OFFSET(scr_const_t, free, 0x4E);
	ASSERT_STRUCT_OFFSET(scr_const_t, fraction, 0x50);
	ASSERT_STRUCT_OFFSET(scr_const_t, goal, 0x52);
	ASSERT_STRUCT_OFFSET(scr_const_t, goal_changed, 0x54);
	ASSERT_STRUCT_OFFSET(scr_const_t, goal_yaw, 0x56);
	ASSERT_STRUCT_OFFSET(scr_const_t, grenade, 0x58);
	ASSERT_STRUCT_OFFSET(scr_const_t, grenade_danger, 0x5A);
	ASSERT_STRUCT_OFFSET(scr_const_t, grenade_fire, 0x5C);
	ASSERT_STRUCT_OFFSET(scr_const_t, grenade_launcher_fire, 0x5E);
	ASSERT_STRUCT_OFFSET(scr_const_t, grenade_pullback, 0x60);
	ASSERT_STRUCT_OFFSET(scr_const_t, info_notnull, 0x62);
	ASSERT_STRUCT_OFFSET(scr_const_t, invisible, 0x64);
	ASSERT_STRUCT_OFFSET(scr_const_t, key1, 0x66);
	ASSERT_STRUCT_OFFSET(scr_const_t, key2, 0x68);
	ASSERT_STRUCT_OFFSET(scr_const_t, killanimscript, 0x6A);
	ASSERT_STRUCT_OFFSET(scr_const_t, left, 0x6C);
	ASSERT_STRUCT_OFFSET(scr_const_t, left_tread, 0x6E);
	ASSERT_STRUCT_OFFSET(scr_const_t, light, 0x70);
	ASSERT_STRUCT_OFFSET(scr_const_t, movedone, 0x72);
	ASSERT_STRUCT_OFFSET(scr_const_t, noclass, 0x74);
	ASSERT_STRUCT_OFFSET(scr_const_t, none, 0x76);
	ASSERT_STRUCT_OFFSET(scr_const_t, normal, 0x78);
	ASSERT_STRUCT_OFFSET(scr_const_t, player, 0x7A);
	ASSERT_STRUCT_OFFSET(scr_const_t, position, 0x7C);
	ASSERT_STRUCT_OFFSET(scr_const_t, projectile_impact, 0x7E);
	ASSERT_STRUCT_OFFSET(scr_const_t, prone, 0x80);
	ASSERT_STRUCT_OFFSET(scr_const_t, right, 0x82);
	ASSERT_STRUCT_OFFSET(scr_const_t, right_tread, 0x84);
	ASSERT_STRUCT_OFFSET(scr_const_t, tank_armor, 0x86);
	ASSERT_STRUCT_OFFSET(scr_const_t, reload, 0x88);
	ASSERT_STRUCT_OFFSET(scr_const_t, reload_start, 0x8A);
	ASSERT_STRUCT_OFFSET(scr_const_t, rocket, 0x8C);
	ASSERT_STRUCT_OFFSET(scr_const_t, rotatedone, 0x8E);
	ASSERT_STRUCT_OFFSET(scr_const_t, script_brushmodel, 0x90);
	ASSERT_STRUCT_OFFSET(scr_const_t, script_model, 0x92);
	ASSERT_STRUCT_OFFSET(scr_const_t, script_origin, 0x94);
	ASSERT_STRUCT_OFFSET(scr_const_t, snd_enveffectsprio_level, 0x96);
	ASSERT_STRUCT_OFFSET(scr_const_t, snd_enveffectsprio_shellshock, 0x98);
	ASSERT_STRUCT_OFFSET(scr_const_t, snd_busvolprio_holdbreath, 0x9A);
	ASSERT_STRUCT_OFFSET(scr_const_t, snd_busvolprio_pain, 0x9C);
	ASSERT_STRUCT_OFFSET(scr_const_t, snd_busvolprio_shellshock, 0x9E);
	ASSERT_STRUCT_OFFSET(scr_const_t, stand, 0xA0);
	ASSERT_STRUCT_OFFSET(scr_const_t, suppression, 0xA2);
	ASSERT_STRUCT_OFFSET(scr_const_t, suppression_end, 0xA4);
	ASSERT_STRUCT_OFFSET(scr_const_t, surfacetype, 0xA6);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_aim, 0xA8);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_aim_animated, 0xAA);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_brass, 0xAC);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_butt, 0xAE);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_clip, 0xB0);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_flash, 0xB2);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_flash_11, 0xB4);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_flash_2, 0xB6);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_flash_22, 0xB8);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_flash_3, 0xBA);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_fx, 0xBC);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_inhand2, 0xBE);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_knife_attach, 0xC0);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_knife_fx, 0xC2);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_bayonet, 0xC4);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_laser, 0xC6);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_origin, 0xC8);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_weapon, 0xCA);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_player2, 0xCC);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_camera, 0xCE);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_weapon_right, 0xD0);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_gasmask, 0xD2);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_gasmask2, 0xD4);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_sync, 0xD6);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_wake, 0xD8);
	ASSERT_STRUCT_OFFSET(scr_const_t, target_script_trigger, 0xDA);
	ASSERT_STRUCT_OFFSET(scr_const_t, tempEntity, 0xDC);
	ASSERT_STRUCT_OFFSET(scr_const_t, top, 0xDE);
	ASSERT_STRUCT_OFFSET(scr_const_t, touch, 0xE0);
	ASSERT_STRUCT_OFFSET(scr_const_t, trigger, 0xE2);
	ASSERT_STRUCT_OFFSET(scr_const_t, trigger_use, 0xE4);
	ASSERT_STRUCT_OFFSET(scr_const_t, trigger_use_touch, 0xE6);
	ASSERT_STRUCT_OFFSET(scr_const_t, trigger_damage, 0xE8);
	ASSERT_STRUCT_OFFSET(scr_const_t, trigger_lookat, 0xEA);
	ASSERT_STRUCT_OFFSET(scr_const_t, trigger_radius, 0xEC);
	ASSERT_STRUCT_OFFSET(scr_const_t, truck_cam, 0xEE);
	ASSERT_STRUCT_OFFSET(scr_const_t, weapon_change_on_turret, 0xF0);
	ASSERT_STRUCT_OFFSET(scr_const_t, weapon_change, 0xF2);
	ASSERT_STRUCT_OFFSET(scr_const_t, weapon_change_complete, 0xF4);
	ASSERT_STRUCT_OFFSET(scr_const_t, weapon_fired, 0xF6);
	ASSERT_STRUCT_OFFSET(scr_const_t, weapon_pvp_attack, 0xF8);
	ASSERT_STRUCT_OFFSET(scr_const_t, worldspawn, 0xFA);
	ASSERT_STRUCT_OFFSET(scr_const_t, flashbang, 0xFC);
	ASSERT_STRUCT_OFFSET(scr_const_t, flash, 0xFE);
	ASSERT_STRUCT_OFFSET(scr_const_t, smoke, 0x100);
	ASSERT_STRUCT_OFFSET(scr_const_t, night_vision_on, 0x102);
	ASSERT_STRUCT_OFFSET(scr_const_t, night_vision_off, 0x104);
	ASSERT_STRUCT_OFFSET(scr_const_t, back_low, 0x106);
	ASSERT_STRUCT_OFFSET(scr_const_t, back_mid, 0x108);
	ASSERT_STRUCT_OFFSET(scr_const_t, back_up, 0x10A);
	ASSERT_STRUCT_OFFSET(scr_const_t, head, 0x10C);
	ASSERT_STRUCT_OFFSET(scr_const_t, j_mainroot, 0x10E);
	ASSERT_STRUCT_OFFSET(scr_const_t, neck, 0x110);
	ASSERT_STRUCT_OFFSET(scr_const_t, pelvis, 0x112);
	ASSERT_STRUCT_OFFSET(scr_const_t, j_head2, 0x114);
	ASSERT_STRUCT_OFFSET(scr_const_t, MOD_UNKNOWN, 0x116);
	ASSERT_STRUCT_OFFSET(scr_const_t, MOD_PISTOL_BULLET, 0x118);
	ASSERT_STRUCT_OFFSET(scr_const_t, MOD_RIFLE_BULLET, 0x11A);
	ASSERT_STRUCT_OFFSET(scr_const_t, MOD_GRENADE, 0x11C);
	ASSERT_STRUCT_OFFSET(scr_const_t, MOD_GRENADE_SPLASH, 0x11E);
	ASSERT_STRUCT_OFFSET(scr_const_t, MOD_PROJECTILE, 0x120);
	ASSERT_STRUCT_OFFSET(scr_const_t, MOD_PROJECTILE_SPLASH, 0x122);
	ASSERT_STRUCT_OFFSET(scr_const_t, MOD_MELEE, 0x124);
	ASSERT_STRUCT_OFFSET(scr_const_t, MOD_BAYONET, 0x126);
	ASSERT_STRUCT_OFFSET(scr_const_t, MOD_HEAD_SHOT, 0x128);
	ASSERT_STRUCT_OFFSET(scr_const_t, MOD_CRUSH, 0x12A);
	ASSERT_STRUCT_OFFSET(scr_const_t, MOD_TELEFRAG, 0x12C);
	ASSERT_STRUCT_OFFSET(scr_const_t, MOD_FALLING, 0x12E);
	ASSERT_STRUCT_OFFSET(scr_const_t, MOD_SUICIDE, 0x130);
	ASSERT_STRUCT_OFFSET(scr_const_t, MOD_TRIGGER_HURT, 0x132);
	ASSERT_STRUCT_OFFSET(scr_const_t, MOD_EXPLOSIVE, 0x134);
	ASSERT_STRUCT_OFFSET(scr_const_t, MOD_IMPACT, 0x136);
	ASSERT_STRUCT_OFFSET(scr_const_t, MOD_BURNED, 0x138);
	ASSERT_STRUCT_OFFSET(scr_const_t, MOD_HIT_BY_OBJECT, 0x13A);
	ASSERT_STRUCT_OFFSET(scr_const_t, MOD_DROWN, 0x13C);
	ASSERT_STRUCT_OFFSET(scr_const_t, script_vehicle, 0x13E);
	ASSERT_STRUCT_OFFSET(scr_const_t, script_vehicle_collision, 0x140);
	ASSERT_STRUCT_OFFSET(scr_const_t, script_vehicle_collmap, 0x142);
	ASSERT_STRUCT_OFFSET(scr_const_t, script_vehicle_corpse, 0x144);
	ASSERT_STRUCT_OFFSET(scr_const_t, turret_fire, 0x146);
	ASSERT_STRUCT_OFFSET(scr_const_t, turret_on_target, 0x148);
	ASSERT_STRUCT_OFFSET(scr_const_t, turret_not_on_target, 0x14A);
	ASSERT_STRUCT_OFFSET(scr_const_t, turret_on_vistarget, 0x14C);
	ASSERT_STRUCT_OFFSET(scr_const_t, turret_no_vis, 0x14E);
	ASSERT_STRUCT_OFFSET(scr_const_t, turret_rotate_stopped, 0x150);
	ASSERT_STRUCT_OFFSET(scr_const_t, turret_deactivate, 0x152);
	ASSERT_STRUCT_OFFSET(scr_const_t, turretstatechange, 0x154);
	ASSERT_STRUCT_OFFSET(scr_const_t, turretownerchange, 0x156);
	ASSERT_STRUCT_OFFSET(scr_const_t, reached_end_node, 0x158);
	ASSERT_STRUCT_OFFSET(scr_const_t, reached_wait_node, 0x15A);
	ASSERT_STRUCT_OFFSET(scr_const_t, reached_wait_speed, 0x15C);
	ASSERT_STRUCT_OFFSET(scr_const_t, near_goal, 0x15E);
	ASSERT_STRUCT_OFFSET(scr_const_t, veh_collision, 0x160);
	ASSERT_STRUCT_OFFSET(scr_const_t, veh_predictedcollision, 0x162);
	ASSERT_STRUCT_OFFSET(scr_const_t, script_camera, 0x164);
	ASSERT_STRUCT_OFFSET(scr_const_t, begin, 0x166);
	ASSERT_STRUCT_OFFSET(scr_const_t, curve_nodehit, 0x168);
	ASSERT_STRUCT_OFFSET(scr_const_t, curve_start, 0x16A);
	ASSERT_STRUCT_OFFSET(scr_const_t, curve_end, 0x16C);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_enter_driver, 0x16E);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_enter_gunner1, 0x170);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_enter_gunner2, 0x172);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_enter_gunner3, 0x174);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_enter_gunner4, 0x176);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_enter_passenger, 0x178);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_enter_passenger2, 0x17A);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_enter_passenger3, 0x17C);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_enter_passenger4, 0x17E);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_player, 0x180);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_passenger1, 0x182);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_passenger2, 0x184);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_passenger3, 0x186);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_passenger4, 0x188);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_gunner1, 0x18A);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_gunner2, 0x18C);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_gunner3, 0x18E);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_gunner4, 0x190);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_gunner_barrel1, 0x192);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_gunner_barrel2, 0x194);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_gunner_barrel3, 0x196);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_gunner_barrel4, 0x198);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_gunner_turret1, 0x19A);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_gunner_turret2, 0x19C);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_gunner_turret3, 0x19E);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_gunner_turret4, 0x1A0);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_flash_gunner1, 0x1A2);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_flash_gunner2, 0x1A4);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_flash_gunner3, 0x1A6);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_flash_gunner4, 0x1A8);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_flash_gunner1a, 0x1AA);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_flash_gunner2a, 0x1AC);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_flash_gunner3a, 0x1AE);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_flash_gunner4a, 0x1B0);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_gunner_brass1, 0x1B2);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_gunner_hands1, 0x1B4);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_wheel_front_left, 0x1B6);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_wheel_front_right, 0x1B8);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_wheel_back_left, 0x1BA);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_wheel_back_right, 0x1BC);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_wheel_middle_left, 0x1BE);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_wheel_middle_right, 0x1C0);
	ASSERT_STRUCT_OFFSET(scr_const_t, vampire_health_regen, 0x1C2);
	ASSERT_STRUCT_OFFSET(scr_const_t, vampire_kill, 0x1C4);
	ASSERT_STRUCT_OFFSET(scr_const_t, morphine_shot, 0x1C6);
	ASSERT_STRUCT_OFFSET(scr_const_t, morphine_revive, 0x1C8);
	ASSERT_STRUCT_OFFSET(scr_const_t, freelook, 0x1CA);
	ASSERT_STRUCT_OFFSET(scr_const_t, intermission, 0x1CC);
	ASSERT_STRUCT_OFFSET(scr_const_t, playing, 0x1CE);
	ASSERT_STRUCT_OFFSET(scr_const_t, spectator, 0x1D0);
	ASSERT_STRUCT_OFFSET(scr_const_t, action_notify_attack, 0x1D2);
	ASSERT_STRUCT_OFFSET(scr_const_t, action_notify_melee, 0x1D4);
	ASSERT_STRUCT_OFFSET(scr_const_t, action_notify_use_reload, 0x1D6);
	ASSERT_STRUCT_OFFSET(scr_const_t, always, 0x1D8);
	ASSERT_STRUCT_OFFSET(scr_const_t, auto_ai, 0x1DA);
	ASSERT_STRUCT_OFFSET(scr_const_t, auto_nonai, 0x1DC);
	ASSERT_STRUCT_OFFSET(scr_const_t, back_left, 0x1DE);
	ASSERT_STRUCT_OFFSET(scr_const_t, back_right, 0x1E0);
	ASSERT_STRUCT_OFFSET(scr_const_t, begin_custom_anim, 0x1E2);
	ASSERT_STRUCT_OFFSET(scr_const_t, bullethit, 0x1E4);
	ASSERT_STRUCT_OFFSET(scr_const_t, count, 0x1E6);
	ASSERT_STRUCT_OFFSET(scr_const_t, corner_approach, 0x1E8);
	ASSERT_STRUCT_OFFSET(scr_const_t, damage_notdone, 0x1EA);
	ASSERT_STRUCT_OFFSET(scr_const_t, deathplant, 0x1EC);
	ASSERT_STRUCT_OFFSET(scr_const_t, front_left, 0x1EE);
	ASSERT_STRUCT_OFFSET(scr_const_t, front_right, 0x1F0);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_inhand, 0x1F2);
	ASSERT_STRUCT_OFFSET(scr_const_t, high_priority, 0x1F4);
	ASSERT_STRUCT_OFFSET(scr_const_t, info_player_deathmatch, 0x1F6);
	ASSERT_STRUCT_OFFSET(scr_const_t, infinite_energy, 0x1F8);
	ASSERT_STRUCT_OFFSET(scr_const_t, low_priority, 0x1FA);
	ASSERT_STRUCT_OFFSET(scr_const_t, manual, 0x1FC);
	ASSERT_STRUCT_OFFSET(scr_const_t, manual_ai, 0x1FE);
	ASSERT_STRUCT_OFFSET(scr_const_t, max_time, 0x200);
	ASSERT_STRUCT_OFFSET(scr_const_t, menuresponse, 0x202);
	ASSERT_STRUCT_OFFSET(scr_const_t, middle_left, 0x204);
	ASSERT_STRUCT_OFFSET(scr_const_t, middle_right, 0x206);
	ASSERT_STRUCT_OFFSET(scr_const_t, min_energy, 0x208);
	ASSERT_STRUCT_OFFSET(scr_const_t, min_time, 0x20A);
	ASSERT_STRUCT_OFFSET(scr_const_t, neutral, 0x20C);
	ASSERT_STRUCT_OFFSET(scr_const_t, never, 0x20E);
	ASSERT_STRUCT_OFFSET(scr_const_t, pickup, 0x210);
	ASSERT_STRUCT_OFFSET(scr_const_t, receiver, 0x212);
	ASSERT_STRUCT_OFFSET(scr_const_t, sound_blend, 0x214);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_wingtipl, 0x216);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_wingtipr, 0x218);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_wingmidl, 0x21A);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_wingmidr, 0x21C);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_prop, 0x21E);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_end, 0x220);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_tailtop, 0x222);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_tailbottom, 0x224);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_detach, 0x226);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_passenger, 0x228);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_enter_back, 0x22A);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_detach2, 0x22C);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_popout, 0x22E);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_body, 0x230);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_turret, 0x232);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_turret_base, 0x234);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_barrel, 0x236);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_weapon_left, 0x238);
	ASSERT_STRUCT_OFFSET(scr_const_t, human, 0x23A);
	ASSERT_STRUCT_OFFSET(scr_const_t, custom, 0x23C);
	ASSERT_STRUCT_OFFSET(scr_const_t, angle_deltas, 0x23E);
	ASSERT_STRUCT_OFFSET(scr_const_t, bulletwhizby, 0x240);
	ASSERT_STRUCT_OFFSET(scr_const_t, dog, 0x242);
	ASSERT_STRUCT_OFFSET(scr_const_t, enemy, 0x244);
	ASSERT_STRUCT_OFFSET(scr_const_t, enemy_visible, 0x246);
	ASSERT_STRUCT_OFFSET(scr_const_t, face_angle, 0x248);
	ASSERT_STRUCT_OFFSET(scr_const_t, face_current, 0x24A);
	ASSERT_STRUCT_OFFSET(scr_const_t, face_default, 0x24C);
	ASSERT_STRUCT_OFFSET(scr_const_t, face_direction, 0x24E);
	ASSERT_STRUCT_OFFSET(scr_const_t, face_enemy, 0x250);
	ASSERT_STRUCT_OFFSET(scr_const_t, face_enemy_or_motion, 0x252);
	ASSERT_STRUCT_OFFSET(scr_const_t, face_goal, 0x254);
	ASSERT_STRUCT_OFFSET(scr_const_t, face_motion, 0x256);
	ASSERT_STRUCT_OFFSET(scr_const_t, face_point, 0x258);
	ASSERT_STRUCT_OFFSET(scr_const_t, gravity, 0x25A);
	ASSERT_STRUCT_OFFSET(scr_const_t, groundEntChanged, 0x25C);
	ASSERT_STRUCT_OFFSET(scr_const_t, gunshot, 0x25E);
	ASSERT_STRUCT_OFFSET(scr_const_t, obstacle, 0x260);
	ASSERT_STRUCT_OFFSET(scr_const_t, movemode, 0x262);
	ASSERT_STRUCT_OFFSET(scr_const_t, node_out_of_range, 0x264);
	ASSERT_STRUCT_OFFSET(scr_const_t, node_relinquished, 0x266);
	ASSERT_STRUCT_OFFSET(scr_const_t, node_taken, 0x268);
	ASSERT_STRUCT_OFFSET(scr_const_t, node_not_safe, 0x26A);
	ASSERT_STRUCT_OFFSET(scr_const_t, noclip, 0x26C);
	ASSERT_STRUCT_OFFSET(scr_const_t, nogravity, 0x26E);
	ASSERT_STRUCT_OFFSET(scr_const_t, nophysics, 0x270);
	ASSERT_STRUCT_OFFSET(scr_const_t, pain, 0x272);
	ASSERT_STRUCT_OFFSET(scr_const_t, run, 0x274);
	ASSERT_STRUCT_OFFSET(scr_const_t, runto_arrived, 0x276);
	ASSERT_STRUCT_OFFSET(scr_const_t, silenced_shot, 0x278);
	ASSERT_STRUCT_OFFSET(scr_const_t, spawned, 0x27A);
	ASSERT_STRUCT_OFFSET(scr_const_t, start_move, 0x27C);
	ASSERT_STRUCT_OFFSET(scr_const_t, stop, 0x27E);
	ASSERT_STRUCT_OFFSET(scr_const_t, stop_soon, 0x280);
	ASSERT_STRUCT_OFFSET(scr_const_t, tag_eye, 0x282);
	ASSERT_STRUCT_OFFSET(scr_const_t, walk, 0x284);
	ASSERT_STRUCT_OFFSET(scr_const_t, world, 0x286);
	ASSERT_STRUCT_OFFSET(scr_const_t, zonly_physics, 0x288);
	ASSERT_STRUCT_OFFSET(scr_const_t, j_ankle_le, 0x28A);
	ASSERT_STRUCT_OFFSET(scr_const_t, j_ankle_ri, 0x28C);
	ASSERT_STRUCT_OFFSET(scr_const_t, j_ball_le, 0x28E);
	ASSERT_STRUCT_OFFSET(scr_const_t, j_ball_ri, 0x290);
	ASSERT_STRUCT_OFFSET(scr_const_t, j_palm_le, 0x292);
	ASSERT_STRUCT_OFFSET(scr_const_t, j_palm_ri, 0x294);
	ASSERT_STRUCT_OFFSET(scr_const_t, broken, 0x296);
	ASSERT_STRUCT_OFFSET(scr_const_t, destructible, 0x298);
	ASSERT_STRUCT_OFFSET(scr_const_t, snapacknowledged, 0x29A);
	ASSERT_STRUCT_OFFSET(scr_const_t, disconnected, 0x29C);
	ASSERT_STRUCT_OFFSET(scr_const_t, cinematic, 0x29E);
	ASSERT_STRUCT_OFFSET(scr_const_t, uicinematic, 0x2A0);
	ASSERT_STRUCT_OFFSET(scr_const_t, logo, 0x2A2);
	ASSERT_STRUCT_OFFSET(scr_const_t, connecting, 0x2A4);
	ASSERT_STRUCT_OFFSET(scr_const_t, challenging, 0x2A6);
	ASSERT_STRUCT_OFFSET(scr_const_t, connected, 0x2A8);
	ASSERT_STRUCT_OFFSET(scr_const_t, sendingstats, 0x2AA);
	ASSERT_STRUCT_OFFSET(scr_const_t, loading, 0x2AC);
	ASSERT_STRUCT_OFFSET(scr_const_t, primed, 0x2AE);
	ASSERT_STRUCT_OFFSET(scr_const_t, active, 0x2B0);
	ASSERT_STRUCT_OFFSET(scr_const_t, map_restart, 0x2B2);
	ASSERT_STRUCT_OFFSET(scr_const_t, orientdone, 0x2B4);

	struct scr_animscript_t
	{
		int func; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 name; //OFS: 0x4 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(scr_animscript_t, 0x8);
	ASSERT_STRUCT_OFFSET(scr_animscript_t, func, 0x0);
	ASSERT_STRUCT_OFFSET(scr_animscript_t, name, 0x4);

	struct AnimScriptList
	{
		scr_animscript_t combat; //OFS: 0x0 SIZE: 0x8
		scr_animscript_t concealment_crouch; //OFS: 0x8 SIZE: 0x8
		scr_animscript_t concealment_prone; //OFS: 0x10 SIZE: 0x8
		scr_animscript_t concealment_stand; //OFS: 0x18 SIZE: 0x8
		scr_animscript_t cover_arrival; //OFS: 0x20 SIZE: 0x8
		scr_animscript_t cover_crouch; //OFS: 0x28 SIZE: 0x8
		scr_animscript_t cover_left; //OFS: 0x30 SIZE: 0x8
		scr_animscript_t cover_prone; //OFS: 0x38 SIZE: 0x8
		scr_animscript_t cover_right; //OFS: 0x40 SIZE: 0x8
		scr_animscript_t cover_stand; //OFS: 0x48 SIZE: 0x8
		scr_animscript_t cover_wide_left; //OFS: 0x50 SIZE: 0x8
		scr_animscript_t cover_wide_right; //OFS: 0x58 SIZE: 0x8
		scr_animscript_t death; //OFS: 0x60 SIZE: 0x8
		scr_animscript_t grenade_return_throw; //OFS: 0x68 SIZE: 0x8
		scr_animscript_t init; //OFS: 0x70 SIZE: 0x8
		scr_animscript_t pain; //OFS: 0x78 SIZE: 0x8
		scr_animscript_t move; //OFS: 0x80 SIZE: 0x8
		scr_animscript_t scripted; //OFS: 0x88 SIZE: 0x8
		scr_animscript_t stop; //OFS: 0x90 SIZE: 0x8
		scr_animscript_t grenade_cower; //OFS: 0x98 SIZE: 0x8
		scr_animscript_t flashed; //OFS: 0xA0 SIZE: 0x8
		scr_animscript_t weapons[128]; //OFS: 0xA8 SIZE: 0x400
	};
	ASSERT_STRUCT_SIZE(AnimScriptList, 0x4A8);
	ASSERT_STRUCT_OFFSET(AnimScriptList, combat, 0x0);
	ASSERT_STRUCT_OFFSET(AnimScriptList, concealment_crouch, 0x8);
	ASSERT_STRUCT_OFFSET(AnimScriptList, concealment_prone, 0x10);
	ASSERT_STRUCT_OFFSET(AnimScriptList, concealment_stand, 0x18);
	ASSERT_STRUCT_OFFSET(AnimScriptList, cover_arrival, 0x20);
	ASSERT_STRUCT_OFFSET(AnimScriptList, cover_crouch, 0x28);
	ASSERT_STRUCT_OFFSET(AnimScriptList, cover_left, 0x30);
	ASSERT_STRUCT_OFFSET(AnimScriptList, cover_prone, 0x38);
	ASSERT_STRUCT_OFFSET(AnimScriptList, cover_right, 0x40);
	ASSERT_STRUCT_OFFSET(AnimScriptList, cover_stand, 0x48);
	ASSERT_STRUCT_OFFSET(AnimScriptList, cover_wide_left, 0x50);
	ASSERT_STRUCT_OFFSET(AnimScriptList, cover_wide_right, 0x58);
	ASSERT_STRUCT_OFFSET(AnimScriptList, death, 0x60);
	ASSERT_STRUCT_OFFSET(AnimScriptList, grenade_return_throw, 0x68);
	ASSERT_STRUCT_OFFSET(AnimScriptList, init, 0x70);
	ASSERT_STRUCT_OFFSET(AnimScriptList, pain, 0x78);
	ASSERT_STRUCT_OFFSET(AnimScriptList, move, 0x80);
	ASSERT_STRUCT_OFFSET(AnimScriptList, scripted, 0x88);
	ASSERT_STRUCT_OFFSET(AnimScriptList, stop, 0x90);
	ASSERT_STRUCT_OFFSET(AnimScriptList, grenade_cower, 0x98);
	ASSERT_STRUCT_OFFSET(AnimScriptList, flashed, 0xA0);
	ASSERT_STRUCT_OFFSET(AnimScriptList, weapons, 0xA8);

	struct scr_data_t
	{
		int levelscript; //OFS: 0x0 SIZE: 0x4
		int animscripts_scripted_init; //OFS: 0x4 SIZE: 0x4
		int CodeCallback_SaveRestored; //OFS: 0x8 SIZE: 0x4
		int CodeCallback_StartGameType; //OFS: 0xC SIZE: 0x4
		int CodeCallback_PlayerConnect; //OFS: 0x10 SIZE: 0x4
		int CodeCallback_PlayerDisconnect; //OFS: 0x14 SIZE: 0x4
		int CodeCallback_PlayerDamage; //OFS: 0x18 SIZE: 0x4
		int CodeCallback_PlayerKilled; //OFS: 0x1C SIZE: 0x4
		int CodeCallback_PlayerRevive; //OFS: 0x20 SIZE: 0x4
		int CodeCallback_PlayerLastStand; //OFS: 0x24 SIZE: 0x4
		XAnim_s * generic_human_animtree; //OFS: 0x28 SIZE: 0x4
		AnimScriptList anim; //OFS: 0x2C SIZE: 0x4A8
		AnimScriptList dogAnim; //OFS: 0x4D4 SIZE: 0x4A8
		int codescripts_delete_main; //OFS: 0x97C SIZE: 0x4
		int codescripts_struct_init; //OFS: 0x980 SIZE: 0x4
		int codescripts_struct_create; //OFS: 0x984 SIZE: 0x4
		int CodeCallback_LevelNotify; //OFS: 0x988 SIZE: 0x4
		XAnimTree_s * actorXAnimTrees[32]; //OFS: 0x98C SIZE: 0x80
		corpseInfo_t actorCorpseInfo[32]; //OFS: 0xA0C SIZE: 0x400
		XAnimTree_s * actorBackupXAnimTree; //OFS: 0xE0C SIZE: 0x4
		actorBackup_s * actorBackup; //OFS: 0xE10 SIZE: 0x4
		int CodeCallback_DisconnectedDuringLoad; //OFS: 0xE14 SIZE: 0x4
		corpseInfo_t playerCorpseInfo[8]; //OFS: 0xE18 SIZE: 0x100
	};
	ASSERT_STRUCT_SIZE(scr_data_t, 0xF18);
	ASSERT_STRUCT_OFFSET(scr_data_t, levelscript, 0x0);
	ASSERT_STRUCT_OFFSET(scr_data_t, animscripts_scripted_init, 0x4);
	ASSERT_STRUCT_OFFSET(scr_data_t, CodeCallback_SaveRestored, 0x8);
	ASSERT_STRUCT_OFFSET(scr_data_t, CodeCallback_StartGameType, 0xC);
	ASSERT_STRUCT_OFFSET(scr_data_t, CodeCallback_PlayerConnect, 0x10);
	ASSERT_STRUCT_OFFSET(scr_data_t, CodeCallback_PlayerDisconnect, 0x14);
	ASSERT_STRUCT_OFFSET(scr_data_t, CodeCallback_PlayerDamage, 0x18);
	ASSERT_STRUCT_OFFSET(scr_data_t, CodeCallback_PlayerKilled, 0x1C);
	ASSERT_STRUCT_OFFSET(scr_data_t, CodeCallback_PlayerRevive, 0x20);
	ASSERT_STRUCT_OFFSET(scr_data_t, CodeCallback_PlayerLastStand, 0x24);
	ASSERT_STRUCT_OFFSET(scr_data_t, generic_human_animtree, 0x28);
	ASSERT_STRUCT_OFFSET(scr_data_t, anim, 0x2C);
	ASSERT_STRUCT_OFFSET(scr_data_t, dogAnim, 0x4D4);
	ASSERT_STRUCT_OFFSET(scr_data_t, codescripts_delete_main, 0x97C);
	ASSERT_STRUCT_OFFSET(scr_data_t, codescripts_struct_init, 0x980);
	ASSERT_STRUCT_OFFSET(scr_data_t, codescripts_struct_create, 0x984);
	ASSERT_STRUCT_OFFSET(scr_data_t, CodeCallback_LevelNotify, 0x988);
	ASSERT_STRUCT_OFFSET(scr_data_t, actorXAnimTrees, 0x98C);
	ASSERT_STRUCT_OFFSET(scr_data_t, actorCorpseInfo, 0xA0C);
	ASSERT_STRUCT_OFFSET(scr_data_t, actorBackupXAnimTree, 0xE0C);
	ASSERT_STRUCT_OFFSET(scr_data_t, actorBackup, 0xE10);
	ASSERT_STRUCT_OFFSET(scr_data_t, CodeCallback_DisconnectedDuringLoad, 0xE14);
	ASSERT_STRUCT_OFFSET(scr_data_t, playerCorpseInfo, 0xE18);

	struct scr_classStruct_t
	{
		unsigned __int16 id; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 entArrayId; //OFS: 0x2 SIZE: 0x2
		char charId; //OFS: 0x4 SIZE: 0x1
		char * name; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(scr_classStruct_t, 0xC);
	ASSERT_STRUCT_OFFSET(scr_classStruct_t, id, 0x0);
	ASSERT_STRUCT_OFFSET(scr_classStruct_t, entArrayId, 0x2);
	ASSERT_STRUCT_OFFSET(scr_classStruct_t, charId, 0x4);
	ASSERT_STRUCT_OFFSET(scr_classStruct_t, name, 0x8);

	typedef void(__cdecl* BuiltinMethod)(scr_entref_t);
	typedef void(__cdecl* BuiltinFunction)();

	struct BuiltinFunctionDef
	{
		const char * actionString; //OFS: 0x0 SIZE: 0x4
		BuiltinFunction actionFunc; //OFS: 0x4 SIZE: 0x4
		int type; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(BuiltinFunctionDef, 0xC);
	ASSERT_STRUCT_OFFSET(BuiltinFunctionDef, actionString, 0x0);
	ASSERT_STRUCT_OFFSET(BuiltinFunctionDef, actionFunc, 0x4);
	ASSERT_STRUCT_OFFSET(BuiltinFunctionDef, type, 0x8);

	struct BuiltinMethodDef
	{
		const char * actionString; //OFS: 0x0 SIZE: 0x4
		BuiltinMethod actionFunc; //OFS: 0x4 SIZE: 0x4
		int type; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(BuiltinMethodDef, 0xC);
	ASSERT_STRUCT_OFFSET(BuiltinMethodDef, actionString, 0x0);
	ASSERT_STRUCT_OFFSET(BuiltinMethodDef, actionFunc, 0x4);
	ASSERT_STRUCT_OFFSET(BuiltinMethodDef, type, 0x8);

	struct RefString_u_s
	{
		unsigned __int32 refCount : 16;
		unsigned __int32 user : 8;
		unsigned __int32 byteLen : 8;
	};
	ASSERT_STRUCT_SIZE(RefString_u_s, 0x4);

	union RefString_u
	{
		RefString_u_s s; //OFS: 0x0 SIZE: 0x4
		volatile int data; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(RefString_u, 0x4);

	struct RefString
	{
		RefString_u u; //OFS: 0x0 SIZE: 0x4
		char str[1]; //OFS: 0x4 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(RefString, 0x8);
	ASSERT_STRUCT_OFFSET(RefString, u, 0x0);
	ASSERT_STRUCT_OFFSET(RefString, str, 0x4);

	struct RefVector_u_s
	{
		unsigned __int32 refCount : 16;
		unsigned __int32 user : 8;
		unsigned __int32 length : 8;
	};
	ASSERT_STRUCT_SIZE(RefVector_u_s, 0x4);

	union RefVector_u
	{
		RefVector_u_s s; //OFS: 0x0 SIZE: 0x4
		volatile int head; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(RefVector_u, 0x4);

	struct RefVector
	{
		RefVector_u u; //OFS: 0x0 SIZE: 0x4
		float vec[3]; //OFS: 0x4 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(RefVector, 0x10);
	ASSERT_STRUCT_OFFSET(RefVector, u, 0x0);
	ASSERT_STRUCT_OFFSET(RefVector, vec, 0x4);

	struct cent_field_s
	{
		const char * name; //OFS: 0x0 SIZE: 0x4
		int ofs; //OFS: 0x4 SIZE: 0x4
		fieldtype_t type; //OFS: 0x8 SIZE: 0x4
		void (__cdecl *setter)(centity_s *, const cent_field_s *); //OFS: 0xC SIZE: 0x4
		void (__cdecl *getter)(centity_s *, const cent_field_s *); //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(cent_field_s, 0x14);
	ASSERT_STRUCT_OFFSET(cent_field_s, name, 0x0);
	ASSERT_STRUCT_OFFSET(cent_field_s, ofs, 0x4);
	ASSERT_STRUCT_OFFSET(cent_field_s, type, 0x8);
	ASSERT_STRUCT_OFFSET(cent_field_s, setter, 0xC);
	ASSERT_STRUCT_OFFSET(cent_field_s, getter, 0x10);

	struct aifields
	{
		const char * name; //OFS: 0x0 SIZE: 0x4
		int ofs; //OFS: 0x4 SIZE: 0x4
		int type; //OFS: 0x8 SIZE: 0x4
		void (__cdecl *setter)(actor_s *, const aifields *); //OFS: 0xC SIZE: 0x4
		void (__cdecl *getter)(actor_s *, const aifields *); //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(aifields, 0x14);
	ASSERT_STRUCT_OFFSET(aifields, name, 0x0);
	ASSERT_STRUCT_OFFSET(aifields, ofs, 0x4);
	ASSERT_STRUCT_OFFSET(aifields, type, 0x8);
	ASSERT_STRUCT_OFFSET(aifields, setter, 0xC);
	ASSERT_STRUCT_OFFSET(aifields, getter, 0x10);

	struct ent_field_t
	{
		const char * name; //OFS: 0x0 SIZE: 0x4
		int ofs; //OFS: 0x4 SIZE: 0x4
		int type; //OFS: 0x8 SIZE: 0x4
		void (__cdecl *callback)(gentity_s *, int); //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ent_field_t, 0x10);
	ASSERT_STRUCT_OFFSET(ent_field_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(ent_field_t, ofs, 0x4);
	ASSERT_STRUCT_OFFSET(ent_field_t, type, 0x8);
	ASSERT_STRUCT_OFFSET(ent_field_t, callback, 0xC);

	struct sentient_fields_s
	{
		const char * name; //OFS: 0x0 SIZE: 0x4
		int ofs; //OFS: 0x4 SIZE: 0x4
		fieldtype_t type; //OFS: 0x8 SIZE: 0x4
		void (__cdecl *setter)(sentient_s *, const sentient_fields_s *); //OFS: 0xC SIZE: 0x4
		void (__cdecl *getter)(sentient_s *, const sentient_fields_s *); //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(sentient_fields_s, 0x14);
	ASSERT_STRUCT_OFFSET(sentient_fields_s, name, 0x0);
	ASSERT_STRUCT_OFFSET(sentient_fields_s, ofs, 0x4);
	ASSERT_STRUCT_OFFSET(sentient_fields_s, type, 0x8);
	ASSERT_STRUCT_OFFSET(sentient_fields_s, setter, 0xC);
	ASSERT_STRUCT_OFFSET(sentient_fields_s, getter, 0x10);

	struct client_fields_s
	{
		const char * name; //OFS: 0x0 SIZE: 0x4
		int ofs; //OFS: 0x4 SIZE: 0x4
		int type; //OFS: 0x8 SIZE: 0x4
		int type2; //OFS: 0xC SIZE: 0x4
		void (__cdecl *setter)(gclient_s *, client_fields_s *); //OFS: 0x10 SIZE: 0x4
		void (__cdecl *getter)(gclient_s *, client_fields_s *); //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(client_fields_s, 0x18);
	ASSERT_STRUCT_OFFSET(client_fields_s, name, 0x0);
	ASSERT_STRUCT_OFFSET(client_fields_s, ofs, 0x4);
	ASSERT_STRUCT_OFFSET(client_fields_s, type, 0x8);
	ASSERT_STRUCT_OFFSET(client_fields_s, type2, 0xC);
	ASSERT_STRUCT_OFFSET(client_fields_s, setter, 0x10);
	ASSERT_STRUCT_OFFSET(client_fields_s, getter, 0x14);

	struct game_hudelem_field_t
	{
		const char * name; //OFS: 0x0 SIZE: 0x4
		int ofs; //OFS: 0x4 SIZE: 0x4
		fieldtype_t type; //OFS: 0x8 SIZE: 0x4
		int mask; //OFS: 0xC SIZE: 0x4
		int shift; //OFS: 0x10 SIZE: 0x4
		void (__cdecl *setter)(game_hudelem_s *, int); //OFS: 0x14 SIZE: 0x4
		void (__cdecl *getter)(game_hudelem_s *, int); //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(game_hudelem_field_t, 0x1C);
	ASSERT_STRUCT_OFFSET(game_hudelem_field_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(game_hudelem_field_t, ofs, 0x4);
	ASSERT_STRUCT_OFFSET(game_hudelem_field_t, type, 0x8);
	ASSERT_STRUCT_OFFSET(game_hudelem_field_t, mask, 0xC);
	ASSERT_STRUCT_OFFSET(game_hudelem_field_t, shift, 0x10);
	ASSERT_STRUCT_OFFSET(game_hudelem_field_t, setter, 0x14);
	ASSERT_STRUCT_OFFSET(game_hudelem_field_t, getter, 0x18);

	struct node_field_t
	{
		const char * name; //OFS: 0x0 SIZE: 0x4
		int ofs; //OFS: 0x4 SIZE: 0x4
		fieldtype_t type; //OFS: 0x8 SIZE: 0x4
		void (__cdecl *getter)(void *, int) ; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(node_field_t, 0x10);
	ASSERT_STRUCT_OFFSET(node_field_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(node_field_t, ofs, 0x4);
	ASSERT_STRUCT_OFFSET(node_field_t, type, 0x8);
	ASSERT_STRUCT_OFFSET(node_field_t, getter, 0xC);

	struct yy_buffer_state
	{
		FILE * yy_input_file; //OFS: 0x0 SIZE: 0x4
		char * yy_ch_buf; //OFS: 0x4 SIZE: 0x4
		char * yy_buf_pos; //OFS: 0x8 SIZE: 0x4
		unsigned int yy_buf_size; //OFS: 0xC SIZE: 0x4
		int yy_n_chars; //OFS: 0x10 SIZE: 0x4
		int yy_is_our_buffer; //OFS: 0x14 SIZE: 0x4
		int yy_is_interactive; //OFS: 0x18 SIZE: 0x4
		int yy_at_bol; //OFS: 0x1C SIZE: 0x4
		int yy_fill_buffer; //OFS: 0x20 SIZE: 0x4
		int yy_buffer_status; //OFS: 0x24 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(yy_buffer_state, 0x28);
	ASSERT_STRUCT_OFFSET(yy_buffer_state, yy_input_file, 0x0);
	ASSERT_STRUCT_OFFSET(yy_buffer_state, yy_ch_buf, 0x4);
	ASSERT_STRUCT_OFFSET(yy_buffer_state, yy_buf_pos, 0x8);
	ASSERT_STRUCT_OFFSET(yy_buffer_state, yy_buf_size, 0xC);
	ASSERT_STRUCT_OFFSET(yy_buffer_state, yy_n_chars, 0x10);
	ASSERT_STRUCT_OFFSET(yy_buffer_state, yy_is_our_buffer, 0x14);
	ASSERT_STRUCT_OFFSET(yy_buffer_state, yy_is_interactive, 0x18);
	ASSERT_STRUCT_OFFSET(yy_buffer_state, yy_at_bol, 0x1C);
	ASSERT_STRUCT_OFFSET(yy_buffer_state, yy_fill_buffer, 0x20);
	ASSERT_STRUCT_OFFSET(yy_buffer_state, yy_buffer_status, 0x24);

	struct stype_t
	{
		sval_u val; //OFS: 0x0 SIZE: 0x4
		unsigned int pos; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(stype_t, 0x8);
	ASSERT_STRUCT_OFFSET(stype_t, val, 0x0);
	ASSERT_STRUCT_OFFSET(stype_t, pos, 0x4);

#pragma endregion

#ifdef __cplusplus
#pragma region "data"
	WEAK symbol<scrVmPub_t> gScrVmPub{ 0x0, 0x3BD4700 };
	WEAK symbol<scrVmGlob_t> gScrVmGlob{ 0x0, 0x3BDDDF8 };
	WEAK symbol<scrVarPub_t> gScrVarPub{ 0x0, 0x3882B70 };
	WEAK symbol<scrCompilePub_t> gScrCompilePub{ 0x0, 0x36BFF70 };
	WEAK symbol<scrAnimPub_t> gScrAnimPub{ 0x0, 0x36BF738 };
	WEAK symbol<jmp_buf> g_script_error{ 0x0, 0x3BDCD40 };
	WEAK symbol<int> g_script_error_level{ 0x0, 0x3BDDDC0 };
	WEAK symbol<function_stack_t> gFs{ 0x0, 0x3BDDDD0 };
	WEAK symbol<OpcodeVM> gOpcode{ 0x0, 0x3BDDDC8 };
	WEAK symbol<scrVarGlob_t> gScrVarGlob{ 0x0, 0x3914700 };
	WEAK symbol<scrMemTreePub_t> gScrMemTreePub{ 0x0, 0x3702390 };
	WEAK symbol<const char*> var_typename{ 0x0, 0x8CF4B0 };
	WEAK symbol<int> gThreadCount{ 0x0, 0x3882B5C };
	WEAK symbol<int> gCaseCount{ 0x0, 0x3882B54 };
	WEAK symbol<scrMemTreeGlob_t> gScrMemTreeGlob{ 0x0, 0x3702400 };
	WEAK symbol<int> gScrExecuteTime{ 0x0, 0x3882B4C };
	WEAK symbol<char> g_EndPos{ 0x0, 0x46E54C3 };
	WEAK symbol<scrStringGlob_t> gScrStringGlob{ 0x0, 0x38B2C00 };
	WEAK symbol<scrParserGlob_t> gScrParserGlob{ 0x0, 0x3702398 };
	WEAK symbol<scrParserPub_t> gScrParserPub{ 0x0, 0x3882B00 };
	WEAK symbol<scr_classStruct_t*> gScrClassMap{ 0x0, 0x8CF568 };
	WEAK symbol<scr_const_t> scr_const{ 0x0, 0x1F33B90 };
	WEAK symbol<bool> loadedImpureScript{ 0x0, 0x22C1352 };
	WEAK symbol<dvar_s*> sv_clientside{ 0x0, 0x3882B6C };
	WEAK symbol<char> error_message_buff{ 0x0, 0x3BE1E30 };
	WEAK symbol<scrCompileGlob_t> gScrCompileGlob{ 0x0, 0x3701FE0 };
	WEAK symbol<scrAnimGlob_t> gScrAnimGlob{ 0x0, 0x36BF320 };

	WEAK symbol<unsigned char> g_parse_user{ 0x0, 0x234F72E };
	WEAK symbol<scriptInstance_t> gInst{ 0x0, 0x3BE624C };
	WEAK symbol<int> yynerrs{ 0x0, 0x3BE6264 };
	WEAK symbol<int> yychar{ 0x0, 0x3BE6260 };
	WEAK symbol<stype_t> yylval{ 0x0, 0x3BE6240 };
	WEAK symbol<unsigned int> g_sourcePos{ 0x0, 0x3BE623C };
	WEAK symbol<sval_u> yaccResult{ 0x0, 0x3BE6258 };
	WEAK symbol<sval_u> g_dummyVal{ 0x0, 0x3BE6254 };
	WEAK symbol<int> yy_init{ 0x0, 0x8CF4A0 };
	WEAK symbol<int> yy_start{ 0x0, 0x46E54D4 };
	WEAK symbol<FILE*> yyin{ 0x0, 0x46E54D8 };
	WEAK symbol<FILE*> yyout{ 0x0, 0x46E54DC };
	WEAK symbol<yy_buffer_state*> yy_current_buffer{ 0x0, 0x46E54CC };
	WEAK symbol<int> yy_n_chars{ 0x0, 0x3BE6250 };
	WEAK symbol<char> yy_hold_char{ 0x0, 0x22C1353 };
	WEAK symbol<char*> yy_c_buf_p{ 0x0, 0x46E54D0 };
	WEAK symbol<int> yy_last_accepting_state{ 0x0, 0x3BE626C };
	WEAK symbol<char*> yy_last_accepting_cpos{ 0x0, 0x3BE2230 };
	WEAK symbol<size_t> yyleng{ 0x0, 0x3BE6248 };
	WEAK symbol<char*> yytext{ 0x0, 0x3BE2234 };
	WEAK symbol<int> yy_did_buffer_switch_on_eof{ 0x0, 0x3BE6268 };
	WEAK symbol<unsigned int> g_out_pos{ 0x0, 0x3BE625C };
	WEAK symbol<char> ch_buf{ 0x0, 0x3BE2238 };
	WEAK symbol<short> yypact{ 0x0, 0x82F2D0 };
	WEAK symbol<char> yytranslate{ 0x0, 0x82ED08 };
	WEAK symbol<short> yycheck{ 0x0, 0x82FFA0 };
	WEAK symbol<short> yytable{ 0x0, 0x82F518 };
	WEAK symbol<short> yyr1{ 0x0, 0x82EE68 };
	WEAK symbol<short> yyr2{ 0x0, 0x82EF78 };
	WEAK symbol<short> yydefact{ 0x0, 0x82F088 };
	WEAK symbol<int> yy_ec{ 0x0, 0x830C30 };
	WEAK symbol<short> yy_accept{ 0x0, 0x830A28 };
	WEAK symbol<short> yy_chk{ 0x0, 0x831930 };
	WEAK symbol<short> yy_base{ 0x0, 0x831120 };
	WEAK symbol<short> yy_def{ 0x0, 0x831338 };
	WEAK symbol<short> yy_nxt{ 0x0, 0x831550 };
	WEAK symbol<int> yy_meta{ 0x0, 0x831030 };
	WEAK symbol<short> yypgoto{ 0x0, 0x82F426 };
	WEAK symbol<short> yydefgoto{ 0x0, 0x82F1DE };
#pragma endregion

#pragma region "functions"
	WEAK symbol<int(jmp_buf buf, int count)>_setjmp3{ 0x0, 0x7E1894 };
	WEAK symbol<void(jmp_buf Buf, int Value)>longjmp{ 0x0, 0x7AD57C };

	inline void* CScr_SetEntityField_ADDR() { return CALL_ADDR(0x0, 0x671470); }
	int CScr_SetEntityField(int ofs, int entnum, unsigned int clientnum, void* call_addr = CScr_SetEntityField_ADDR());
	inline void* Scr_SetObjectField_ADDR() { return CALL_ADDR(0x0, 0x5469C0); }
	int Scr_SetObjectField(int ofs, int entnum, classNum_e classnum, scriptInstance_t inst, void* call_addr = Scr_SetObjectField_ADDR());
	inline void* CScr_GetEntityField_ADDR() { return CALL_ADDR(0x0, 0x671410); }
	void CScr_GetEntityField(int ofs, int entnum, unsigned int clientnum, void* call_addr = CScr_GetEntityField_ADDR());
	inline void* Scr_GetObjectField_ADDR() { return CALL_ADDR(0x0, 0x546D30); }
	void Scr_GetObjectField(int ofs, int inst, classNum_e classnum, int entnum, void* call_addr = Scr_GetObjectField_ADDR());
#pragma endregion
}

#include "cscr_main.hpp"
#include "cscr_memorytree.hpp"
#include "cscr_parser.hpp"
#include "cscr_parsetree.hpp"
#include "cscr_readwrite.hpp"
#include "cscr_stringlist.hpp"
#include "cscr_tempmemory.hpp"
#include "cscr_variable.hpp"
#include "cscr_vm.hpp"
#include "cscr_compiler.hpp"
#include "cscr_yacc.hpp"
#include "cscr_animtree.hpp"
#endif
