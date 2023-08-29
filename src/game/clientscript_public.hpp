#pragma once

#ifdef __cplusplus
namespace game
{
#endif

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

	enum ai_animmode_t
	{
		AI_ANIM_UNKNOWN = 0x0,
		AI_ANIM_MOVE_CODE = 0x1,
		AI_ANIM_USE_POS_DELTAS = 0x2,
		AI_ANIM_USE_ANGLE_DELTAS = 0x3,
		AI_ANIM_USE_BOTH_DELTAS = 0x4,
		AI_ANIM_USE_BOTH_DELTAS_NOCLIP = 0x5,
		AI_ANIM_USE_BOTH_DELTAS_NOGRAVITY = 0x6,
		AI_ANIM_USE_BOTH_DELTAS_ZONLY_PHYSICS = 0x7,
		AI_ANIM_NOPHYSICS = 0x8,
		AI_ANIM_POINT_RELATIVE = 0x9,
	};

	enum ai_orient_mode_t
	{
		AI_ORIENT_INVALID = 0x0,
		AI_ORIENT_DONT_CHANGE = 0x1,
		AI_ORIENT_TO_MOTION = 0x2,
		AI_ORIENT_TO_ENEMY = 0x3,
		AI_ORIENT_TO_ENEMY_OR_MOTION = 0x4,
		AI_ORIENT_TO_ENEMY_OR_MOTION_SIDESTEP = 0x5,
		AI_ORIENT_TO_GOAL = 0x6,
		AI_ORIENT_COUNT = 0x7,
	};

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
		function_stack_t _fs; //OFS: 0x0 SIZE: 0x14
		VariableType topType; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(function_frame_t, 0x18);
	ASSERT_STRUCT_OFFSET(function_frame_t, _fs, 0x0);
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

	struct HunkUser
	{
		HunkUser * current; //OFS: 0x0 SIZE: 0x4
		HunkUser * next; //OFS: 0x4 SIZE: 0x4
		int maxSize; //OFS: 0x8 SIZE: 0x4
		int end; //OFS: 0xC SIZE: 0x4
		int pos; //OFS: 0x10 SIZE: 0x4
		int locked; //OFS: 0x14 SIZE: 0x4
		char * name; //OFS: 0x18 SIZE: 0x4
		bool fixed; //OFS: 0x1C SIZE: 0x1
		bool tempMem; //OFS: 0x1D SIZE: 0x1
		bool debugMem; //OFS: 0x1E SIZE: 0x1
		int type; //OFS: 0x20 SIZE: 0x4
		unsigned __int8 buf[1]; //OFS: 0x24 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(HunkUser, 0x28);
	ASSERT_STRUCT_OFFSET(HunkUser, current, 0x0);
	ASSERT_STRUCT_OFFSET(HunkUser, next, 0x4);
	ASSERT_STRUCT_OFFSET(HunkUser, maxSize, 0x8);
	ASSERT_STRUCT_OFFSET(HunkUser, end, 0xC);
	ASSERT_STRUCT_OFFSET(HunkUser, pos, 0x10);
	ASSERT_STRUCT_OFFSET(HunkUser, locked, 0x14);
	ASSERT_STRUCT_OFFSET(HunkUser, name, 0x18);
	ASSERT_STRUCT_OFFSET(HunkUser, fixed, 0x1C);
	ASSERT_STRUCT_OFFSET(HunkUser, tempMem, 0x1D);
	ASSERT_STRUCT_OFFSET(HunkUser, debugMem, 0x1E);
	ASSERT_STRUCT_OFFSET(HunkUser, type, 0x20);
	ASSERT_STRUCT_OFFSET(HunkUser, buf, 0x24);

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

	struct scrMemTreeGlob_t
	{
		MemoryNode nodes[65536]; //OFS: 0x0 SIZE: 0xC0000
		unsigned __int8 leftBits[256]; //OFS: 0xC0000 SIZE: 0x100
		unsigned __int8 numBits[256]; //OFS: 0xC0100 SIZE: 0x100
		unsigned __int8 logBits[256]; //OFS: 0xC0200 SIZE: 0x100
		unsigned __int16 head[17]; //OFS: 0xC0300 SIZE: 0x22
		_BYTE gap_C0322[93]; //OFS: 0xC0322 SIZE: 0x5D
		char field_C037F; //OFS: 0xC037F SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(scrMemTreeGlob_t, 0xC0380);
	ASSERT_STRUCT_OFFSET(scrMemTreeGlob_t, nodes, 0x0);
	ASSERT_STRUCT_OFFSET(scrMemTreeGlob_t, leftBits, 0xC0000);
	ASSERT_STRUCT_OFFSET(scrMemTreeGlob_t, numBits, 0xC0100);
	ASSERT_STRUCT_OFFSET(scrMemTreeGlob_t, logBits, 0xC0200);
	ASSERT_STRUCT_OFFSET(scrMemTreeGlob_t, head, 0xC0300);
	ASSERT_STRUCT_OFFSET(scrMemTreeGlob_t, gap_C0322, 0xC0322);
	ASSERT_STRUCT_OFFSET(scrMemTreeGlob_t, field_C037F, 0xC037F);

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

	struct __declspec(align(2)) XAnimParent
	{
		unsigned __int16 flags; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 children; //OFS: 0x2 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(XAnimParent, 0x4);
	ASSERT_STRUCT_OFFSET(XAnimParent, flags, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimParent, children, 0x2);

	struct XAnimEntry
	{
		unsigned __int16 bCreated; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 numAnims; //OFS: 0x2 SIZE: 0x2
		unsigned __int16 parent; //OFS: 0x4 SIZE: 0x2
		__int16 field_6; //OFS: 0x6 SIZE: 0x2
		XAnimParent animParent; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XAnimEntry, 0xC);
	ASSERT_STRUCT_OFFSET(XAnimEntry, bCreated, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimEntry, numAnims, 0x2);
	ASSERT_STRUCT_OFFSET(XAnimEntry, parent, 0x4);
	ASSERT_STRUCT_OFFSET(XAnimEntry, field_6, 0x6);
	ASSERT_STRUCT_OFFSET(XAnimEntry, animParent, 0x8);

	struct XAnim_s
	{
		char * debugName; //OFS: 0x0 SIZE: 0x4
		unsigned int size; //OFS: 0x4 SIZE: 0x4
		char ** debugAnimNames; //OFS: 0x8 SIZE: 0x4
		XAnimEntry entries[1]; //OFS: 0xC SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(XAnim_s, 0x18);
	ASSERT_STRUCT_OFFSET(XAnim_s, debugName, 0x0);
	ASSERT_STRUCT_OFFSET(XAnim_s, size, 0x4);
	ASSERT_STRUCT_OFFSET(XAnim_s, debugAnimNames, 0x8);
	ASSERT_STRUCT_OFFSET(XAnim_s, entries, 0xC);

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

	struct XAnimTree_s
	{
		XAnim_s * anims; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 children; //OFS: 0x4 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(XAnimTree_s, 0x8);
	ASSERT_STRUCT_OFFSET(XAnimTree_s, anims, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimTree_s, children, 0x4);

	struct actor_prone_info_s
	{
		bool bCorpseOrientation; //OFS: 0x0 SIZE: 0x1
		bool orientPitch; //OFS: 0x1 SIZE: 0x1
		bool prone; //OFS: 0x2 SIZE: 0x1
		int iProneTime; //OFS: 0x4 SIZE: 0x4
		int iProneTrans; //OFS: 0x8 SIZE: 0x4
		float fBodyHeight; //OFS: 0xC SIZE: 0x4
		float fBodyPitch; //OFS: 0x10 SIZE: 0x4
		float fBodyRoll; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(actor_prone_info_s, 0x18);
	ASSERT_STRUCT_OFFSET(actor_prone_info_s, bCorpseOrientation, 0x0);
	ASSERT_STRUCT_OFFSET(actor_prone_info_s, orientPitch, 0x1);
	ASSERT_STRUCT_OFFSET(actor_prone_info_s, prone, 0x2);
	ASSERT_STRUCT_OFFSET(actor_prone_info_s, iProneTime, 0x4);
	ASSERT_STRUCT_OFFSET(actor_prone_info_s, iProneTrans, 0x8);
	ASSERT_STRUCT_OFFSET(actor_prone_info_s, fBodyHeight, 0xC);
	ASSERT_STRUCT_OFFSET(actor_prone_info_s, fBodyPitch, 0x10);
	ASSERT_STRUCT_OFFSET(actor_prone_info_s, fBodyRoll, 0x14);

	struct corpseInfo_t
	{
		XAnimTree_s * tree; //OFS: 0x0 SIZE: 0x4
		int entnum; //OFS: 0x4 SIZE: 0x4
		actor_prone_info_s proneInfo; //OFS: 0x8 SIZE: 0x18
	};
	ASSERT_STRUCT_SIZE(corpseInfo_t, 0x20);
	ASSERT_STRUCT_OFFSET(corpseInfo_t, tree, 0x0);
	ASSERT_STRUCT_OFFSET(corpseInfo_t, entnum, 0x4);
	ASSERT_STRUCT_OFFSET(corpseInfo_t, proneInfo, 0x8);

	struct ai_orient_t
	{
		ai_orient_mode_t eMode; //OFS: 0x0 SIZE: 0x4
		float fDesiredLookPitch; //OFS: 0x4 SIZE: 0x4
		float fDesiredLookYaw; //OFS: 0x8 SIZE: 0x4
		float fDesiredBodyYaw; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ai_orient_t, 0x10);
	ASSERT_STRUCT_OFFSET(ai_orient_t, eMode, 0x0);
	ASSERT_STRUCT_OFFSET(ai_orient_t, fDesiredLookPitch, 0x4);
	ASSERT_STRUCT_OFFSET(ai_orient_t, fDesiredLookYaw, 0x8);
	ASSERT_STRUCT_OFFSET(ai_orient_t, fDesiredBodyYaw, 0xC);

	struct actorBackup_s
	{
		ai_animmode_t eAnimMode; //OFS: 0x0 SIZE: 0x4
		ai_animmode_t eDesiredAnimMode; //OFS: 0x4 SIZE: 0x4
		ai_animmode_t eScriptSetAnimMode; //OFS: 0x8 SIZE: 0x4
		bool bUseGoalWeight; //OFS: 0xC SIZE: 0x1
		char gapD[1987]; //OFS: 0xD SIZE: 0x7C3
		ai_orient_t ScriptOrient; //OFS: 0x7D0 SIZE: 0x10
		ai_orient_t CodeOrient; //OFS: 0x7E0 SIZE: 0x10
		float fDesiredBodyYaw; //OFS: 0x7F0 SIZE: 0x4
		float currentOrigin[3]; //OFS: 0x7F4 SIZE: 0xC
		float currentAngles[3]; //OFS: 0x800 SIZE: 0xC
		float vLookForward[3]; //OFS: 0x80C SIZE: 0xC
		float vLookRight[3]; //OFS: 0x818 SIZE: 0xC
		float vLookUp[3]; //OFS: 0x824 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(actorBackup_s, 0x830);
	ASSERT_STRUCT_OFFSET(actorBackup_s, eAnimMode, 0x0);
	ASSERT_STRUCT_OFFSET(actorBackup_s, eDesiredAnimMode, 0x4);
	ASSERT_STRUCT_OFFSET(actorBackup_s, eScriptSetAnimMode, 0x8);
	ASSERT_STRUCT_OFFSET(actorBackup_s, bUseGoalWeight, 0xC);
	ASSERT_STRUCT_OFFSET(actorBackup_s, gapD, 0xD);
	ASSERT_STRUCT_OFFSET(actorBackup_s, ScriptOrient, 0x7D0);
	ASSERT_STRUCT_OFFSET(actorBackup_s, CodeOrient, 0x7E0);
	ASSERT_STRUCT_OFFSET(actorBackup_s, fDesiredBodyYaw, 0x7F0);
	ASSERT_STRUCT_OFFSET(actorBackup_s, currentOrigin, 0x7F4);
	ASSERT_STRUCT_OFFSET(actorBackup_s, currentAngles, 0x800);
	ASSERT_STRUCT_OFFSET(actorBackup_s, vLookForward, 0x80C);
	ASSERT_STRUCT_OFFSET(actorBackup_s, vLookRight, 0x818);
	ASSERT_STRUCT_OFFSET(actorBackup_s, vLookUp, 0x824);

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

#ifdef __cplusplus
}
#endif
