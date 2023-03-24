#pragma once

namespace game
{
	typedef float vec_t;
	typedef vec_t vec2_t[2];
	typedef vec_t vec3_t[3];
	typedef vec_t vec4_t[4];

	struct scr_entref_s
	{
		__int16 entnum;
		__int16 classnum;
	};

	typedef void(__cdecl* BuiltinFunction)();

	typedef void(__cdecl* BuiltinMethod)(scr_entref_s);

	enum con_channel_e
	{
		CON_CHANNEL_DONT_FILTER = 0x0,
		CON_CHANNEL_ERROR = 0x1,
		CON_CHANNEL_GAMENOTIFY = 0x2,
		CON_CHANNEL_BOLDGAME = 0x3,
		CON_CHANNEL_SUBTITLE = 0x4,
		CON_CHANNEL_OBITUARY = 0x5,
		CON_CHANNEL_LOGFILEONLY = 0x6,
		CON_CHANNEL_CONSOLEONLY = 0x7,
		CON_CHANNEL_GFX = 0x8,
		CON_CHANNEL_SOUND = 0x9,
		CON_CHANNEL_FILES = 0xA,
		CON_CHANNEL_DEVGUI = 0xB,
		CON_CHANNEL_PROFILE = 0xC,
		CON_CHANNEL_UI = 0xD,
		CON_CHANNEL_CLIENT = 0xE,
		CON_CHANNEL_SERVER = 0xF,
		CON_CHANNEL_SYSTEM = 0x10,
		CON_CHANNEL_PLAYERWEAP = 0x11,
		CON_CHANNEL_AI = 0x12,
		CON_CHANNEL_ANIM = 0x13,
		CON_CHANNEL_PHYS = 0x14,
		CON_CHANNEL_FX = 0x15,
		CON_CHANNEL_LEADERBOARDS = 0x16,
		CON_CHANNEL_LIVE = 0x17,
		CON_CHANNEL_PARSERSCRIPT = 0x18,
		CON_CHANNEL_SCRIPT = 0x19,
		CON_CHANNEL_SPAWNSYSTEM = 0x1A,
		CON_CHANNEL_COOPINFO = 0x1B,
		CON_CHANNEL_SERVERDEMO = 0x1C,
		CON_CHANNEL_DDL = 0x1D,
		CON_CHANNEL_NETWORK = 0x1E,
		CON_CHANNEL_SCHEDULER = 0x1F,
		CON_FIRST_DEBUG_CHANNEL = 0x1F,
		CON_CHANNEL_TASK = 0x20,
		CON_CHANNEL_SPU = 0x21,
		CON_BUILTIN_CHANNEL_COUNT = 0x22,
	};

	struct CmdArgs
	{
		int nesting;
		int localClientNum[8];
		int controllerIndex[8];
		int argc[8];
		char** argv[8];
	};

	struct cmd_function_s
	{
		cmd_function_s* next;
		const char* name;
		char unk[8];
		void(__cdecl* function)();
	};

	enum DvarFlags : unsigned __int16
	{
		DVAR_FLAG_NONE = 0x0,
		DVAR_FLAG_ARCHIVE = 0x1,
		DVAR_FLAG_USERINFO = 0x2,
		DVAR_FLAG_SERVERINFO = 0x4,
		DVAR_FLAG_SYSTEMINFO = 0x8,
		DVAR_FLAG_INIT = 0x10,
		DVAR_FLAG_LATCH = 0x20,
		DVAR_FLAG_ROM = 0x40,
		DVAR_FLAG_CHEAT = 0x80,
		DVAR_FLAG_CONFIG = 0x100,
		DVAR_FLAG_SAVED = 0x200,
		DVAR_FLAG_NORESTART = 0x400,
		DVAR_FLAG_UNK3 = 0x800,
		DVAR_FLAG_CHANGEABLE_RESET = 0x1000,
		DVAR_FLAG_UNK4 = 0x2000,
		DVAR_FLAG_EXTERNAL = 0x4000,
		DVAR_FLAG_AUTOEXEC = 0x8000,
	};

	enum dvarType_t : unsigned __int8
	{
		DVAR_TYPE_BOOL = 0x0,
		DVAR_TYPE_FLOAT = 0x1,
		DVAR_TYPE_FLOAT_2 = 0x2,
		DVAR_TYPE_FLOAT_3 = 0x3,
		DVAR_TYPE_FLOAT_4 = 0x4,
		DVAR_TYPE_INT = 0x5,
		DVAR_TYPE_ENUM = 0x6,
		DVAR_TYPE_STRING = 0x7,
		DVAR_TYPE_COLOR = 0x8,
		DVAR_TYPE_COUNT = 0x9,
	};

	union DvarValue
	{
		bool enabled;
		int integer;
		unsigned int unsignedInt;
		float value;
		float vector[4];
		const char* string;
		char color[4];
	};

	union __declspec(align(4)) DvarLimits
	{
		struct
		{
			int stringCount;
			const char** strings;
		} enumeration;
		struct
		{
			int min;
			int max;
		} integer;
		struct
		{
			float min;
			float max;
		} value;
		struct
		{
			float min;
			float max;
		} vector;
	};

	struct __declspec(align(4)) dvar_s
	{
		const char* name;
		const char* description;
		DvarFlags flags;
		dvarType_t type;
		char modified;
		int pad;
		DvarValue current;
		DvarValue latched;
		DvarValue reset;
		DvarValue saved;
		DvarLimits domain;
		dvar_s* hashNext;
	};

	static_assert(sizeof(dvar_s) == 0x5C);
}