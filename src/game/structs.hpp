#pragma once

#ifdef __cplusplus
#include <d3d9.h>

#define ASSERT_STRUCT_SIZE(structure, size) static_assert(sizeof(structure) == size, "sizeof(" #structure ") != " #size);
#define ASSERT_STRUCT_OFFSET(structure, member, offset) static_assert(offsetof(structure, member) == offset, "offsetof(" #structure ", " #member ") != " #offset);
#else
#define ASSERT_STRUCT_SIZE(structure, size)
#define ASSERT_STRUCT_OFFSET(structure, member, offset)
#endif

ASSERT_STRUCT_SIZE(int, 4);
ASSERT_STRUCT_SIZE(char, 1);
ASSERT_STRUCT_SIZE(short, 2);
ASSERT_STRUCT_SIZE(float, 4);
ASSERT_STRUCT_SIZE(double, 8);
ASSERT_STRUCT_SIZE(long, 4);
ASSERT_STRUCT_SIZE(long long, 8);
ASSERT_STRUCT_SIZE(void*, 4);
ASSERT_STRUCT_SIZE(jmp_buf, 4 * 16)
ASSERT_STRUCT_SIZE(CRITICAL_SECTION, 0x18)

#ifdef __cplusplus
namespace game
{
#endif

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
		CON_CHANNEL_PARSERSCRIPT = 0x17,
		CON_CHANNEL_SCRIPT = 0x18,
		CON_CHANNEL_COOPINFO = 0x19,
		CON_BUILTIN_CHANNEL_COUNT = 0x1A,
	};

	struct scr_entref_t
	{
		unsigned __int16 entnum;
		unsigned __int16 classnum;
		unsigned __int16 client;
	};

	typedef void(__cdecl* BuiltinMethod)(scr_entref_t);
	typedef void(__cdecl* BuiltinFunction)();

#ifdef __cplusplus
}
#endif