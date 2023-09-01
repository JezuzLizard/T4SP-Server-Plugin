#pragma once

#ifdef __cplusplus
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
ASSERT_STRUCT_SIZE(jmp_buf, 4 * 16);
ASSERT_STRUCT_SIZE(CRITICAL_SECTION, 0x18);

#ifdef __cplusplus
#include "xasset.hpp"

namespace game
{
#endif
	struct XAnimTree_s;

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

#ifdef __cplusplus
}

#include "clientscript/clientscript_public.hpp"

namespace game
{
#endif

	struct client_s;
	struct NitrousVehicle;
	struct DObjModel_s;
	struct z_stream_s;
	struct flameGeneric_s;
	struct flameStream_s;
	struct phys_free_list_NitrousVehicle_T_internal;

	struct __declspec(align(1)) struc_74
	{
		_BYTE gap0[1567]; //OFS: 0x0 SIZE: 0x61F
		char field_61F; //OFS: 0x61F SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(struc_74, 0x620);
	ASSERT_STRUCT_OFFSET(struc_74, gap0, 0x0);
	ASSERT_STRUCT_OFFSET(struc_74, field_61F, 0x61F);

	struct ucmd_t
	{
		char * name; //OFS: 0x0 SIZE: 0x4
		void (__cdecl *func)(client_s *); //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ucmd_t, 0x8);
	ASSERT_STRUCT_OFFSET(ucmd_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(ucmd_t, func, 0x4);

	struct path_node_field_t
	{
		char * name; //OFS: 0x0 SIZE: 0x4
		int ofs; //OFS: 0x4 SIZE: 0x4
		int type; //OFS: 0x8 SIZE: 0x4
		void (__cdecl *getter)(void *, int); //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(path_node_field_t, 0x10);
	ASSERT_STRUCT_OFFSET(path_node_field_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(path_node_field_t, ofs, 0x4);
	ASSERT_STRUCT_OFFSET(path_node_field_t, type, 0x8);
	ASSERT_STRUCT_OFFSET(path_node_field_t, getter, 0xC);

	struct GamerSettingState
	{
		char isProfileLoggedIn; //OFS: 0x0 SIZE: 0x1
		char errorOnRead; //OFS: 0x1 SIZE: 0x1
		_BYTE gap2[7]; //OFS: 0x2 SIZE: 0x7
		char subtitlesEnabled; //OFS: 0x9 SIZE: 0x1
		_BYTE gapA[258]; //OFS: 0xA SIZE: 0x102
		int gameSkill; //OFS: 0x10C SIZE: 0x4
		_BYTE gap110[260]; //OFS: 0x110 SIZE: 0x104
		int takeCoverWarnings; //OFS: 0x214 SIZE: 0x4
		int cheatPoints; //OFS: 0x218 SIZE: 0x4
		int cheatItemsSet1; //OFS: 0x21C SIZE: 0x4
		int cheatItemsSet2; //OFS: 0x220 SIZE: 0x4
		int arcadeScores[19]; //OFS: 0x224 SIZE: 0x4C
		int missionGlobals[30]; //OFS: 0x270 SIZE: 0x78
		_BYTE gap2E8[520]; //OFS: 0x2E8 SIZE: 0x208
		float gamma; //OFS: 0x4F0 SIZE: 0x4
		_BYTE gap_4F4[4]; //OFS: 0x4F4 SIZE: 0x4
		char exeSettingsBuffer[1000]; //OFS: 0x4F8 SIZE: 0x3E8
		char commonSettingsBuffer[1000]; //OFS: 0x8E0 SIZE: 0x3E8
		char motd[256]; //OFS: 0xCC8 SIZE: 0x100
		_BYTE gap_DC8[4]; //OFS: 0xDC8 SIZE: 0x4
		int field_DCC; //OFS: 0xDCC SIZE: 0x4
		char clanAbbrev[172]; //OFS: 0xDD0 SIZE: 0xAC
	};
	ASSERT_STRUCT_SIZE(GamerSettingState, 0xE7C);
	ASSERT_STRUCT_OFFSET(GamerSettingState, isProfileLoggedIn, 0x0);
	ASSERT_STRUCT_OFFSET(GamerSettingState, errorOnRead, 0x1);
	ASSERT_STRUCT_OFFSET(GamerSettingState, gap2, 0x2);
	ASSERT_STRUCT_OFFSET(GamerSettingState, subtitlesEnabled, 0x9);
	ASSERT_STRUCT_OFFSET(GamerSettingState, gapA, 0xA);
	ASSERT_STRUCT_OFFSET(GamerSettingState, gameSkill, 0x10C);
	ASSERT_STRUCT_OFFSET(GamerSettingState, gap110, 0x110);
	ASSERT_STRUCT_OFFSET(GamerSettingState, takeCoverWarnings, 0x214);
	ASSERT_STRUCT_OFFSET(GamerSettingState, cheatPoints, 0x218);
	ASSERT_STRUCT_OFFSET(GamerSettingState, cheatItemsSet1, 0x21C);
	ASSERT_STRUCT_OFFSET(GamerSettingState, cheatItemsSet2, 0x220);
	ASSERT_STRUCT_OFFSET(GamerSettingState, arcadeScores, 0x224);
	ASSERT_STRUCT_OFFSET(GamerSettingState, missionGlobals, 0x270);
	ASSERT_STRUCT_OFFSET(GamerSettingState, gap2E8, 0x2E8);
	ASSERT_STRUCT_OFFSET(GamerSettingState, gamma, 0x4F0);
	ASSERT_STRUCT_OFFSET(GamerSettingState, gap_4F4, 0x4F4);
	ASSERT_STRUCT_OFFSET(GamerSettingState, exeSettingsBuffer, 0x4F8);
	ASSERT_STRUCT_OFFSET(GamerSettingState, commonSettingsBuffer, 0x8E0);
	ASSERT_STRUCT_OFFSET(GamerSettingState, motd, 0xCC8);
	ASSERT_STRUCT_OFFSET(GamerSettingState, gap_DC8, 0xDC8);
	ASSERT_STRUCT_OFFSET(GamerSettingState, field_DCC, 0xDCC);
	ASSERT_STRUCT_OFFSET(GamerSettingState, clanAbbrev, 0xDD0);

	struct __declspec(align(1)) colorunpacked
	{
		char r; //OFS: 0x0 SIZE: 0x1
		char g; //OFS: 0x1 SIZE: 0x1
		char b; //OFS: 0x2 SIZE: 0x1
		char a; //OFS: 0x3 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(colorunpacked, 0x4);
	ASSERT_STRUCT_OFFSET(colorunpacked, r, 0x0);
	ASSERT_STRUCT_OFFSET(colorunpacked, g, 0x1);
	ASSERT_STRUCT_OFFSET(colorunpacked, b, 0x2);
	ASSERT_STRUCT_OFFSET(colorunpacked, a, 0x3);

	union hudelem_color_t
	{
		colorunpacked color; //OFS: 0x0 SIZE: 0x4
		int rgba; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(hudelem_color_t, 0x4);

	struct hudelem_s
	{
		he_type_t type; //OFS: 0x0 SIZE: 0x4
		float x; //OFS: 0x4 SIZE: 0x4
		float y; //OFS: 0x8 SIZE: 0x4
		float z; //OFS: 0xC SIZE: 0x4
		int targetEntNum; //OFS: 0x10 SIZE: 0x4
		float fontScale; //OFS: 0x14 SIZE: 0x4
		float fromFontScale; //OFS: 0x18 SIZE: 0x4
		int fontScaleStartTime; //OFS: 0x1C SIZE: 0x4
		int fontScaleTime; //OFS: 0x20 SIZE: 0x4
		HudelemFontTypes font; //OFS: 0x24 SIZE: 0x4
		int alignOrg; //OFS: 0x28 SIZE: 0x4
		int alignScreen; //OFS: 0x2C SIZE: 0x4
		hudelem_color_t color; //OFS: 0x30 SIZE: 0x4
		hudelem_color_t fromColor; //OFS: 0x34 SIZE: 0x4
		int fadeStartTime; //OFS: 0x38 SIZE: 0x4
		int fadeTime; //OFS: 0x3C SIZE: 0x4
		int label; //OFS: 0x40 SIZE: 0x4
		int width; //OFS: 0x44 SIZE: 0x4
		int height; //OFS: 0x48 SIZE: 0x4
		int materialIndex; //OFS: 0x4C SIZE: 0x4
		int offscreenMaterialIdx; //OFS: 0x50 SIZE: 0x4
		int fromWidth; //OFS: 0x54 SIZE: 0x4
		int fromHeight; //OFS: 0x58 SIZE: 0x4
		int scaleStartTime; //OFS: 0x5C SIZE: 0x4
		int scaleTime; //OFS: 0x60 SIZE: 0x4
		float fromX; //OFS: 0x64 SIZE: 0x4
		float fromY; //OFS: 0x68 SIZE: 0x4
		int fromAlignOrg; //OFS: 0x6C SIZE: 0x4
		int fromAlignScreen; //OFS: 0x70 SIZE: 0x4
		int moveStartTime; //OFS: 0x74 SIZE: 0x4
		int moveTime; //OFS: 0x78 SIZE: 0x4
		int time; //OFS: 0x7C SIZE: 0x4
		int duration; //OFS: 0x80 SIZE: 0x4
		float value; //OFS: 0x84 SIZE: 0x4
		int text; //OFS: 0x88 SIZE: 0x4
		float sort; //OFS: 0x8C SIZE: 0x4
		hudelem_color_t glowColor; //OFS: 0x90 SIZE: 0x4
		int fxBirthTime; //OFS: 0x94 SIZE: 0x4
		int fxLetterTime; //OFS: 0x98 SIZE: 0x4
		int fxDecayStartTime; //OFS: 0x9C SIZE: 0x4
		int fxDecayDuration; //OFS: 0xA0 SIZE: 0x4
		int soundID; //OFS: 0xA4 SIZE: 0x4
		hudelem_flags_t flags; //OFS: 0xA8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(hudelem_s, 0xAC);
	ASSERT_STRUCT_OFFSET(hudelem_s, type, 0x0);
	ASSERT_STRUCT_OFFSET(hudelem_s, x, 0x4);
	ASSERT_STRUCT_OFFSET(hudelem_s, y, 0x8);
	ASSERT_STRUCT_OFFSET(hudelem_s, z, 0xC);
	ASSERT_STRUCT_OFFSET(hudelem_s, targetEntNum, 0x10);
	ASSERT_STRUCT_OFFSET(hudelem_s, fontScale, 0x14);
	ASSERT_STRUCT_OFFSET(hudelem_s, fromFontScale, 0x18);
	ASSERT_STRUCT_OFFSET(hudelem_s, fontScaleStartTime, 0x1C);
	ASSERT_STRUCT_OFFSET(hudelem_s, fontScaleTime, 0x20);
	ASSERT_STRUCT_OFFSET(hudelem_s, font, 0x24);
	ASSERT_STRUCT_OFFSET(hudelem_s, alignOrg, 0x28);
	ASSERT_STRUCT_OFFSET(hudelem_s, alignScreen, 0x2C);
	ASSERT_STRUCT_OFFSET(hudelem_s, color, 0x30);
	ASSERT_STRUCT_OFFSET(hudelem_s, fromColor, 0x34);
	ASSERT_STRUCT_OFFSET(hudelem_s, fadeStartTime, 0x38);
	ASSERT_STRUCT_OFFSET(hudelem_s, fadeTime, 0x3C);
	ASSERT_STRUCT_OFFSET(hudelem_s, label, 0x40);
	ASSERT_STRUCT_OFFSET(hudelem_s, width, 0x44);
	ASSERT_STRUCT_OFFSET(hudelem_s, height, 0x48);
	ASSERT_STRUCT_OFFSET(hudelem_s, materialIndex, 0x4C);
	ASSERT_STRUCT_OFFSET(hudelem_s, offscreenMaterialIdx, 0x50);
	ASSERT_STRUCT_OFFSET(hudelem_s, fromWidth, 0x54);
	ASSERT_STRUCT_OFFSET(hudelem_s, fromHeight, 0x58);
	ASSERT_STRUCT_OFFSET(hudelem_s, scaleStartTime, 0x5C);
	ASSERT_STRUCT_OFFSET(hudelem_s, scaleTime, 0x60);
	ASSERT_STRUCT_OFFSET(hudelem_s, fromX, 0x64);
	ASSERT_STRUCT_OFFSET(hudelem_s, fromY, 0x68);
	ASSERT_STRUCT_OFFSET(hudelem_s, fromAlignOrg, 0x6C);
	ASSERT_STRUCT_OFFSET(hudelem_s, fromAlignScreen, 0x70);
	ASSERT_STRUCT_OFFSET(hudelem_s, moveStartTime, 0x74);
	ASSERT_STRUCT_OFFSET(hudelem_s, moveTime, 0x78);
	ASSERT_STRUCT_OFFSET(hudelem_s, time, 0x7C);
	ASSERT_STRUCT_OFFSET(hudelem_s, duration, 0x80);
	ASSERT_STRUCT_OFFSET(hudelem_s, value, 0x84);
	ASSERT_STRUCT_OFFSET(hudelem_s, text, 0x88);
	ASSERT_STRUCT_OFFSET(hudelem_s, sort, 0x8C);
	ASSERT_STRUCT_OFFSET(hudelem_s, glowColor, 0x90);
	ASSERT_STRUCT_OFFSET(hudelem_s, fxBirthTime, 0x94);
	ASSERT_STRUCT_OFFSET(hudelem_s, fxLetterTime, 0x98);
	ASSERT_STRUCT_OFFSET(hudelem_s, fxDecayStartTime, 0x9C);
	ASSERT_STRUCT_OFFSET(hudelem_s, fxDecayDuration, 0xA0);
	ASSERT_STRUCT_OFFSET(hudelem_s, soundID, 0xA4);
	ASSERT_STRUCT_OFFSET(hudelem_s, flags, 0xA8);

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

	struct XAnimTree_s
	{
		XAnim_s * anims; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 children; //OFS: 0x4 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(XAnimTree_s, 0x8);
	ASSERT_STRUCT_OFFSET(XAnimTree_s, anims, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimTree_s, children, 0x4);

	union XAnimParent_u
	{
		XAnimParts * parts; //OFS: 0x0 SIZE: 0x4
		XAnimParent animParent; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XAnimParent_u, 0x4);

	struct XAnimState
	{
		float currentAnimTime; //OFS: 0x0 SIZE: 0x4
		float oldTime; //OFS: 0x4 SIZE: 0x4
		__int16 cycleCount; //OFS: 0x8 SIZE: 0x2
		__int16 oldCycleCount; //OFS: 0xA SIZE: 0x2
		float goalTime; //OFS: 0xC SIZE: 0x4
		float goalWeight; //OFS: 0x10 SIZE: 0x4
		float weight; //OFS: 0x14 SIZE: 0x4
		float rate; //OFS: 0x18 SIZE: 0x4
		bool instantWeightChange; //OFS: 0x1C SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(XAnimState, 0x20);
	ASSERT_STRUCT_OFFSET(XAnimState, currentAnimTime, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimState, oldTime, 0x4);
	ASSERT_STRUCT_OFFSET(XAnimState, cycleCount, 0x8);
	ASSERT_STRUCT_OFFSET(XAnimState, oldCycleCount, 0xA);
	ASSERT_STRUCT_OFFSET(XAnimState, goalTime, 0xC);
	ASSERT_STRUCT_OFFSET(XAnimState, goalWeight, 0x10);
	ASSERT_STRUCT_OFFSET(XAnimState, weight, 0x14);
	ASSERT_STRUCT_OFFSET(XAnimState, rate, 0x18);
	ASSERT_STRUCT_OFFSET(XAnimState, instantWeightChange, 0x1C);

	struct XAnimInfo
	{
		unsigned __int16 notifyChild; //OFS: 0x0 SIZE: 0x2
		__int16 notifyIndex; //OFS: 0x2 SIZE: 0x2
		unsigned __int16 notifyName; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 notifyType; //OFS: 0x6 SIZE: 0x2
		unsigned __int16 prev; //OFS: 0x8 SIZE: 0x2
		unsigned __int16 next; //OFS: 0xA SIZE: 0x2
		unsigned __int16 children; //OFS: 0xC SIZE: 0x2
		unsigned __int16 parent; //OFS: 0xE SIZE: 0x2
		unsigned __int16 animIndex; //OFS: 0x10 SIZE: 0x2
		unsigned __int16 animToModel; //OFS: 0x12 SIZE: 0x2
		XAnimParent_u u; //OFS: 0x14 SIZE: 0x4
		XAnimState state; //OFS: 0x18 SIZE: 0x20
	};
	ASSERT_STRUCT_SIZE(XAnimInfo, 0x38);
	ASSERT_STRUCT_OFFSET(XAnimInfo, notifyChild, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimInfo, notifyIndex, 0x2);
	ASSERT_STRUCT_OFFSET(XAnimInfo, notifyName, 0x4);
	ASSERT_STRUCT_OFFSET(XAnimInfo, notifyType, 0x6);
	ASSERT_STRUCT_OFFSET(XAnimInfo, prev, 0x8);
	ASSERT_STRUCT_OFFSET(XAnimInfo, next, 0xA);
	ASSERT_STRUCT_OFFSET(XAnimInfo, children, 0xC);
	ASSERT_STRUCT_OFFSET(XAnimInfo, parent, 0xE);
	ASSERT_STRUCT_OFFSET(XAnimInfo, animIndex, 0x10);
	ASSERT_STRUCT_OFFSET(XAnimInfo, animToModel, 0x12);
	ASSERT_STRUCT_OFFSET(XAnimInfo, u, 0x14);
	ASSERT_STRUCT_OFFSET(XAnimInfo, state, 0x18);

	struct trace_t
	{
		float normal[4]; //OFS: 0x0 SIZE: 0x10
		float fraction; //OFS: 0x10 SIZE: 0x4
		int surfaceFlags; //OFS: 0x14 SIZE: 0x4
		int contents; //OFS: 0x18 SIZE: 0x4
		char * material; //OFS: 0x1C SIZE: 0x4
		TraceHitType hitType; //OFS: 0x20 SIZE: 0x4
		unsigned __int16 hitId; //OFS: 0x24 SIZE: 0x2
		unsigned __int16 modelIndex; //OFS: 0x26 SIZE: 0x2
		unsigned __int16 partName; //OFS: 0x28 SIZE: 0x2
		unsigned __int16 boneIndex; //OFS: 0x2A SIZE: 0x2
		unsigned __int16 partGroup; //OFS: 0x2C SIZE: 0x2
		bool allsolid; //OFS: 0x2E SIZE: 0x1
		bool startsolid; //OFS: 0x2F SIZE: 0x1
		bool walkable; //OFS: 0x30 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(trace_t, 0x34);
	ASSERT_STRUCT_OFFSET(trace_t, normal, 0x0);
	ASSERT_STRUCT_OFFSET(trace_t, fraction, 0x10);
	ASSERT_STRUCT_OFFSET(trace_t, surfaceFlags, 0x14);
	ASSERT_STRUCT_OFFSET(trace_t, contents, 0x18);
	ASSERT_STRUCT_OFFSET(trace_t, material, 0x1C);
	ASSERT_STRUCT_OFFSET(trace_t, hitType, 0x20);
	ASSERT_STRUCT_OFFSET(trace_t, hitId, 0x24);
	ASSERT_STRUCT_OFFSET(trace_t, modelIndex, 0x26);
	ASSERT_STRUCT_OFFSET(trace_t, partName, 0x28);
	ASSERT_STRUCT_OFFSET(trace_t, boneIndex, 0x2A);
	ASSERT_STRUCT_OFFSET(trace_t, partGroup, 0x2C);
	ASSERT_STRUCT_OFFSET(trace_t, allsolid, 0x2E);
	ASSERT_STRUCT_OFFSET(trace_t, startsolid, 0x2F);
	ASSERT_STRUCT_OFFSET(trace_t, walkable, 0x30);

	struct trajectory_t
	{
		trType_t trType; //OFS: 0x0 SIZE: 0x4
		int trTime; //OFS: 0x4 SIZE: 0x4
		int trDuration; //OFS: 0x8 SIZE: 0x4
		float trBase[3]; //OFS: 0xC SIZE: 0xC
		float trDelta[3]; //OFS: 0x18 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(trajectory_t, 0x24);
	ASSERT_STRUCT_OFFSET(trajectory_t, trType, 0x0);
	ASSERT_STRUCT_OFFSET(trajectory_t, trTime, 0x4);
	ASSERT_STRUCT_OFFSET(trajectory_t, trDuration, 0x8);
	ASSERT_STRUCT_OFFSET(trajectory_t, trBase, 0xC);
	ASSERT_STRUCT_OFFSET(trajectory_t, trDelta, 0x18);

	struct LerpEntityStateTurret
	{
		float gunAngles[3]; //OFS: 0x0 SIZE: 0xC
		unsigned __int8 overheating; //OFS: 0xC SIZE: 0x1
		float heatVal; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(LerpEntityStateTurret, 0x14);
	ASSERT_STRUCT_OFFSET(LerpEntityStateTurret, gunAngles, 0x0);
	ASSERT_STRUCT_OFFSET(LerpEntityStateTurret, overheating, 0xC);
	ASSERT_STRUCT_OFFSET(LerpEntityStateTurret, heatVal, 0x10);

	struct LerpEntityStateLoopFx
	{
		float cullDist; //OFS: 0x0 SIZE: 0x4
		int period; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(LerpEntityStateLoopFx, 0x8);
	ASSERT_STRUCT_OFFSET(LerpEntityStateLoopFx, cullDist, 0x0);
	ASSERT_STRUCT_OFFSET(LerpEntityStateLoopFx, period, 0x4);

	union LerpEntityStateActor_unnamed_type_index
	{
		int actorNum; //OFS: 0x0 SIZE: 0x4
		int corpseNum; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(LerpEntityStateActor_unnamed_type_index, 0x4);

	struct __declspec(align(2)) LerpEntityStateActor_unnamed_type_proneInfo
	{
		__int16 fBodyPitch; //OFS: 0x0 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(LerpEntityStateActor_unnamed_type_proneInfo, 0x2);
	ASSERT_STRUCT_OFFSET(LerpEntityStateActor_unnamed_type_proneInfo, fBodyPitch, 0x0);

	struct LerpEntityStateActor
	{
		LerpEntityStateActor_unnamed_type_index index; //OFS: 0x0 SIZE: 0x4
		int species; //OFS: 0x4 SIZE: 0x4
		LerpEntityStateActor_unnamed_type_proneInfo proneInfo; //OFS: 0x8 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(LerpEntityStateActor, 0xC);
	ASSERT_STRUCT_OFFSET(LerpEntityStateActor, index, 0x0);
	ASSERT_STRUCT_OFFSET(LerpEntityStateActor, species, 0x4);
	ASSERT_STRUCT_OFFSET(LerpEntityStateActor, proneInfo, 0x8);

	struct LerpEntityStatePrimaryLight
	{
		char colorAndExp[4]; //OFS: 0x0 SIZE: 0x4
		float intensity; //OFS: 0x4 SIZE: 0x4
		float radius; //OFS: 0x8 SIZE: 0x4
		float cosHalfFovOuter; //OFS: 0xC SIZE: 0x4
		float cosHalfFovInner; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(LerpEntityStatePrimaryLight, 0x14);
	ASSERT_STRUCT_OFFSET(LerpEntityStatePrimaryLight, colorAndExp, 0x0);
	ASSERT_STRUCT_OFFSET(LerpEntityStatePrimaryLight, intensity, 0x4);
	ASSERT_STRUCT_OFFSET(LerpEntityStatePrimaryLight, radius, 0x8);
	ASSERT_STRUCT_OFFSET(LerpEntityStatePrimaryLight, cosHalfFovOuter, 0xC);
	ASSERT_STRUCT_OFFSET(LerpEntityStatePrimaryLight, cosHalfFovInner, 0x10);

	struct LerpEntityStatePlayer
	{
		float leanf; //OFS: 0x0 SIZE: 0x4
		int movementDir; //OFS: 0x4 SIZE: 0x4
		char vehicleType; //OFS: 0x8 SIZE: 0x1
		char vehicleAnimBoneIndex; //OFS: 0x9 SIZE: 0x1
		char vehicleSeat; //OFS: 0xA SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(LerpEntityStatePlayer, 0xC);
	ASSERT_STRUCT_OFFSET(LerpEntityStatePlayer, leanf, 0x0);
	ASSERT_STRUCT_OFFSET(LerpEntityStatePlayer, movementDir, 0x4);
	ASSERT_STRUCT_OFFSET(LerpEntityStatePlayer, vehicleType, 0x8);
	ASSERT_STRUCT_OFFSET(LerpEntityStatePlayer, vehicleAnimBoneIndex, 0x9);
	ASSERT_STRUCT_OFFSET(LerpEntityStatePlayer, vehicleSeat, 0xA);

	struct __declspec(align(2)) LerpEntityStateVehicleGunnerAngles
	{
		__int16 pitch; //OFS: 0x0 SIZE: 0x2
		__int16 yaw; //OFS: 0x2 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(LerpEntityStateVehicleGunnerAngles, 0x4);
	ASSERT_STRUCT_OFFSET(LerpEntityStateVehicleGunnerAngles, pitch, 0x0);
	ASSERT_STRUCT_OFFSET(LerpEntityStateVehicleGunnerAngles, yaw, 0x2);

	union LerpEntityStateVehicleThrottle_u
	{
		__int16 throttle; //OFS: 0x0 SIZE: 0x2
		__int16 bodyPitch; //OFS: 0x1 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(LerpEntityStateVehicleThrottle_u, 0x2);

	struct LerpEntityStateVehicle
	{
		float steerYaw; //OFS: 0x0 SIZE: 0x4
		float bodyRoll; //OFS: 0x4 SIZE: 0x4
		float bodyPitch; //OFS: 0x8 SIZE: 0x4
		LerpEntityStateVehicleGunnerAngles gunnerAngles[4]; //OFS: 0xC SIZE: 0x10
		LerpEntityStateVehicleThrottle_u ___u3; //OFS: 0x1C SIZE: 0x2
		__int16 gunPitch; //OFS: 0x1E SIZE: 0x2
		__int16 gunYaw; //OFS: 0x20 SIZE: 0x2
		char drawOnCompass; //OFS: 0x22 SIZE: 0x1
		int teamAndOwnerIndex; //OFS: 0x24 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(LerpEntityStateVehicle, 0x28);
	ASSERT_STRUCT_OFFSET(LerpEntityStateVehicle, steerYaw, 0x0);
	ASSERT_STRUCT_OFFSET(LerpEntityStateVehicle, bodyRoll, 0x4);
	ASSERT_STRUCT_OFFSET(LerpEntityStateVehicle, bodyPitch, 0x8);
	ASSERT_STRUCT_OFFSET(LerpEntityStateVehicle, gunnerAngles, 0xC);
	ASSERT_STRUCT_OFFSET(LerpEntityStateVehicle, ___u3, 0x1C);
	ASSERT_STRUCT_OFFSET(LerpEntityStateVehicle, gunPitch, 0x1E);
	ASSERT_STRUCT_OFFSET(LerpEntityStateVehicle, gunYaw, 0x20);
	ASSERT_STRUCT_OFFSET(LerpEntityStateVehicle, drawOnCompass, 0x22);
	ASSERT_STRUCT_OFFSET(LerpEntityStateVehicle, teamAndOwnerIndex, 0x24);

	struct LerpEntityStateMissile
	{
		int launchTime; //OFS: 0x0 SIZE: 0x4
		int parentClientNum; //OFS: 0x4 SIZE: 0x4
		int fuseTime; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(LerpEntityStateMissile, 0xC);
	ASSERT_STRUCT_OFFSET(LerpEntityStateMissile, launchTime, 0x0);
	ASSERT_STRUCT_OFFSET(LerpEntityStateMissile, parentClientNum, 0x4);
	ASSERT_STRUCT_OFFSET(LerpEntityStateMissile, fuseTime, 0x8);

	struct LerpEntityStateScriptMover
	{
		char attachTagIndex[4]; //OFS: 0x0 SIZE: 0x4
		int attachedTagIndex; //OFS: 0x4 SIZE: 0x4
		__int16 attachModelIndex[4]; //OFS: 0x8 SIZE: 0x8
		__int16 animScriptedAnim; //OFS: 0x10 SIZE: 0x2
		int animScriptedAnimTime; //OFS: 0x14 SIZE: 0x4
		__int16 attachedEntNum; //OFS: 0x18 SIZE: 0x2
		__int16 exploderIndex; //OFS: 0x1A SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(LerpEntityStateScriptMover, 0x1C);
	ASSERT_STRUCT_OFFSET(LerpEntityStateScriptMover, attachTagIndex, 0x0);
	ASSERT_STRUCT_OFFSET(LerpEntityStateScriptMover, attachedTagIndex, 0x4);
	ASSERT_STRUCT_OFFSET(LerpEntityStateScriptMover, attachModelIndex, 0x8);
	ASSERT_STRUCT_OFFSET(LerpEntityStateScriptMover, animScriptedAnim, 0x10);
	ASSERT_STRUCT_OFFSET(LerpEntityStateScriptMover, animScriptedAnimTime, 0x14);
	ASSERT_STRUCT_OFFSET(LerpEntityStateScriptMover, attachedEntNum, 0x18);
	ASSERT_STRUCT_OFFSET(LerpEntityStateScriptMover, exploderIndex, 0x1A);

	struct LerpEntityStateSoundBlend
	{
		float lerp; //OFS: 0x0 SIZE: 0x4
		float volumeScale; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(LerpEntityStateSoundBlend, 0x8);
	ASSERT_STRUCT_OFFSET(LerpEntityStateSoundBlend, lerp, 0x0);
	ASSERT_STRUCT_OFFSET(LerpEntityStateSoundBlend, volumeScale, 0x4);

	struct LerpEntityStateAnonymous
	{
		int data[15]; //OFS: 0x0 SIZE: 0x3C
	};
	ASSERT_STRUCT_SIZE(LerpEntityStateAnonymous, 0x3C);
	ASSERT_STRUCT_OFFSET(LerpEntityStateAnonymous, data, 0x0);

	union LerpEntityStateTypeUnion
	{
		LerpEntityStateTurret turret; //OFS: 0x0 SIZE: 0x14
		LerpEntityStateLoopFx loopFx; //OFS: 0x1 SIZE: 0x8
		LerpEntityStateActor actor; //OFS: 0x2 SIZE: 0xC
		LerpEntityStatePrimaryLight primaryLight; //OFS: 0x3 SIZE: 0x14
		LerpEntityStatePlayer player; //OFS: 0x4 SIZE: 0xC
		LerpEntityStateVehicle vehicle; //OFS: 0x5 SIZE: 0x28
		LerpEntityStateMissile missile; //OFS: 0x6 SIZE: 0xC
		LerpEntityStateScriptMover scriptMover; //OFS: 0x7 SIZE: 0x1C
		LerpEntityStateSoundBlend soundBlend; //OFS: 0x8 SIZE: 0x8
		LerpEntityStateAnonymous anonymous; //OFS: 0x9 SIZE: 0x3C
	};
	ASSERT_STRUCT_SIZE(LerpEntityStateTypeUnion, 0x3C);

	struct LerpEntityState
	{
		int eFlags; //OFS: 0x0 SIZE: 0x4
		trajectory_t pos; //OFS: 0x4 SIZE: 0x24
		trajectory_t apos; //OFS: 0x28 SIZE: 0x24
		LerpEntityStateTypeUnion u; //OFS: 0x4C SIZE: 0x3C
		int usecount; //OFS: 0x88 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(LerpEntityState, 0x8C);
	ASSERT_STRUCT_OFFSET(LerpEntityState, eFlags, 0x0);
	ASSERT_STRUCT_OFFSET(LerpEntityState, pos, 0x4);
	ASSERT_STRUCT_OFFSET(LerpEntityState, apos, 0x28);
	ASSERT_STRUCT_OFFSET(LerpEntityState, u, 0x4C);
	ASSERT_STRUCT_OFFSET(LerpEntityState, usecount, 0x88);

	struct __declspec(align(2)) LoopSound
	{
		unsigned __int16 soundAlias; //OFS: 0x0 SIZE: 0x2
		__int16 fadeTime; //OFS: 0x2 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(LoopSound, 0x4);
	ASSERT_STRUCT_OFFSET(LoopSound, soundAlias, 0x0);
	ASSERT_STRUCT_OFFSET(LoopSound, fadeTime, 0x2);

	union entityState_index
	{
		__int16 brushmodel; //OFS: 0x0 SIZE: 0x2
		__int16 xmodel; //OFS: 0x1 SIZE: 0x2
		__int16 primaryLight; //OFS: 0x2 SIZE: 0x2
		unsigned __int16 bone; //OFS: 0x3 SIZE: 0x2
		int pad; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(entityState_index, 0x4);

	union entityState_un1
	{
		char destructibleid; //OFS: 0x0 SIZE: 0x1
		char pad[4]; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(entityState_un1, 0x4);

	struct playerAnimState_t
	{
		int legsAnim; //OFS: 0x0 SIZE: 0x4
		int torsoAnim; //OFS: 0x4 SIZE: 0x4
		float fTorsoPitch; //OFS: 0x8 SIZE: 0x4
		float fWaistPitch; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(playerAnimState_t, 0x10);
	ASSERT_STRUCT_OFFSET(playerAnimState_t, legsAnim, 0x0);
	ASSERT_STRUCT_OFFSET(playerAnimState_t, torsoAnim, 0x4);
	ASSERT_STRUCT_OFFSET(playerAnimState_t, fTorsoPitch, 0x8);
	ASSERT_STRUCT_OFFSET(playerAnimState_t, fWaistPitch, 0xC);

	union entityState_un2
	{
		playerAnimState_t anim; //OFS: 0x0 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(entityState_un2, 0x10);

	union entityState_un3
	{
		int item; //OFS: 0x0 SIZE: 0x4
		int hintString; //OFS: 0x1 SIZE: 0x4
		int vehicleXModel; //OFS: 0x2 SIZE: 0x4
		unsigned int secondBcAlias; //OFS: 0x3 SIZE: 0x4
		unsigned int soundTag; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(entityState_un3, 0x4);

	struct entityState_s
	{
		int number; //OFS: 0x0 SIZE: 0x4
		entityType_t eType; //OFS: 0x4 SIZE: 0x4
		LerpEntityState lerp; //OFS: 0x8 SIZE: 0x8C
		int time2; //OFS: 0x94 SIZE: 0x4
		int otherEntityNum; //OFS: 0x98 SIZE: 0x4
		int groundEntityNum; //OFS: 0x9C SIZE: 0x4
		LoopSound loopSound; //OFS: 0xA0 SIZE: 0x4
		int surfType; //OFS: 0xA4 SIZE: 0x4
		entityState_index index; //OFS: 0xA8 SIZE: 0x4
		int clientnum; //OFS: 0xAC SIZE: 0x4
		int iHeadIcon; //OFS: 0xB0 SIZE: 0x4
		int solid; //OFS: 0xB4 SIZE: 0x4
		int eventParm; //OFS: 0xB8 SIZE: 0x4
		int eventSequence; //OFS: 0xBC SIZE: 0x4
		int events[4]; //OFS: 0xC0 SIZE: 0x10
		int eventParms[4]; //OFS: 0xD0 SIZE: 0x10
		int weapon; //OFS: 0xE0 SIZE: 0x4
		int weaponModel; //OFS: 0xE4 SIZE: 0x4
		int targetname; //OFS: 0xE8 SIZE: 0x4
		entityState_un1 un1; //OFS: 0xEC SIZE: 0x4
		entityState_un2 un2; //OFS: 0xF0 SIZE: 0x10
		entityState_un3 un3; //OFS: 0x100 SIZE: 0x4
		int animtreeIndex; //OFS: 0x104 SIZE: 0x4
		int partBits[4]; //OFS: 0x108 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(entityState_s, 0x118);
	ASSERT_STRUCT_OFFSET(entityState_s, number, 0x0);
	ASSERT_STRUCT_OFFSET(entityState_s, eType, 0x4);
	ASSERT_STRUCT_OFFSET(entityState_s, lerp, 0x8);
	ASSERT_STRUCT_OFFSET(entityState_s, time2, 0x94);
	ASSERT_STRUCT_OFFSET(entityState_s, otherEntityNum, 0x98);
	ASSERT_STRUCT_OFFSET(entityState_s, groundEntityNum, 0x9C);
	ASSERT_STRUCT_OFFSET(entityState_s, loopSound, 0xA0);
	ASSERT_STRUCT_OFFSET(entityState_s, surfType, 0xA4);
	ASSERT_STRUCT_OFFSET(entityState_s, index, 0xA8);
	ASSERT_STRUCT_OFFSET(entityState_s, clientnum, 0xAC);
	ASSERT_STRUCT_OFFSET(entityState_s, iHeadIcon, 0xB0);
	ASSERT_STRUCT_OFFSET(entityState_s, solid, 0xB4);
	ASSERT_STRUCT_OFFSET(entityState_s, eventParm, 0xB8);
	ASSERT_STRUCT_OFFSET(entityState_s, eventSequence, 0xBC);
	ASSERT_STRUCT_OFFSET(entityState_s, events, 0xC0);
	ASSERT_STRUCT_OFFSET(entityState_s, eventParms, 0xD0);
	ASSERT_STRUCT_OFFSET(entityState_s, weapon, 0xE0);
	ASSERT_STRUCT_OFFSET(entityState_s, weaponModel, 0xE4);
	ASSERT_STRUCT_OFFSET(entityState_s, targetname, 0xE8);
	ASSERT_STRUCT_OFFSET(entityState_s, un1, 0xEC);
	ASSERT_STRUCT_OFFSET(entityState_s, un2, 0xF0);
	ASSERT_STRUCT_OFFSET(entityState_s, un3, 0x100);
	ASSERT_STRUCT_OFFSET(entityState_s, animtreeIndex, 0x104);
	ASSERT_STRUCT_OFFSET(entityState_s, partBits, 0x108);

	struct __declspec(align(2)) EntHandle
	{
		unsigned __int16 number; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 infoIndex; //OFS: 0x2 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(EntHandle, 0x4);
	ASSERT_STRUCT_OFFSET(EntHandle, number, 0x0);
	ASSERT_STRUCT_OFFSET(EntHandle, infoIndex, 0x2);

	struct entityShared_s
	{
		unsigned __int8 linked; //OFS: 0x0 SIZE: 0x1
		unsigned __int8 bmodel; //OFS: 0x1 SIZE: 0x1
		unsigned __int16 svFlags; //OFS: 0x2 SIZE: 0x2
		unsigned __int8 eventType; //OFS: 0x4 SIZE: 0x1
		unsigned __int8 inuse; //OFS: 0x5 SIZE: 0x1
		int clientMask[2]; //OFS: 0x8 SIZE: 0x8
		int broadcastTime; //OFS: 0x10 SIZE: 0x4
		float mins[3]; //OFS: 0x14 SIZE: 0xC
		float maxs[3]; //OFS: 0x20 SIZE: 0xC
		contents_e contents; //OFS: 0x2C SIZE: 0x4
		float absmin[3]; //OFS: 0x30 SIZE: 0xC
		float absmax[3]; //OFS: 0x3C SIZE: 0xC
		float currentOrigin[3]; //OFS: 0x48 SIZE: 0xC
		float currentAngles[3]; //OFS: 0x54 SIZE: 0xC
		EntHandle ownerNum; //OFS: 0x60 SIZE: 0x4
		int eventTime; //OFS: 0x64 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(entityShared_s, 0x68);
	ASSERT_STRUCT_OFFSET(entityShared_s, linked, 0x0);
	ASSERT_STRUCT_OFFSET(entityShared_s, bmodel, 0x1);
	ASSERT_STRUCT_OFFSET(entityShared_s, svFlags, 0x2);
	ASSERT_STRUCT_OFFSET(entityShared_s, eventType, 0x4);
	ASSERT_STRUCT_OFFSET(entityShared_s, inuse, 0x5);
	ASSERT_STRUCT_OFFSET(entityShared_s, clientMask, 0x8);
	ASSERT_STRUCT_OFFSET(entityShared_s, broadcastTime, 0x10);
	ASSERT_STRUCT_OFFSET(entityShared_s, mins, 0x14);
	ASSERT_STRUCT_OFFSET(entityShared_s, maxs, 0x20);
	ASSERT_STRUCT_OFFSET(entityShared_s, contents, 0x2C);
	ASSERT_STRUCT_OFFSET(entityShared_s, absmin, 0x30);
	ASSERT_STRUCT_OFFSET(entityShared_s, absmax, 0x3C);
	ASSERT_STRUCT_OFFSET(entityShared_s, currentOrigin, 0x48);
	ASSERT_STRUCT_OFFSET(entityShared_s, currentAngles, 0x54);
	ASSERT_STRUCT_OFFSET(entityShared_s, ownerNum, 0x60);
	ASSERT_STRUCT_OFFSET(entityShared_s, eventTime, 0x64);

	struct SprintState
	{
		int sprintButtonUpRequired; //OFS: 0x0 SIZE: 0x4
		int sprintDelay; //OFS: 0x4 SIZE: 0x4
		int lastSprintStart; //OFS: 0x8 SIZE: 0x4
		int lastSprintEnd; //OFS: 0xC SIZE: 0x4
		int sprintStartMaxLength; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SprintState, 0x14);
	ASSERT_STRUCT_OFFSET(SprintState, sprintButtonUpRequired, 0x0);
	ASSERT_STRUCT_OFFSET(SprintState, sprintDelay, 0x4);
	ASSERT_STRUCT_OFFSET(SprintState, lastSprintStart, 0x8);
	ASSERT_STRUCT_OFFSET(SprintState, lastSprintEnd, 0xC);
	ASSERT_STRUCT_OFFSET(SprintState, sprintStartMaxLength, 0x10);

	struct MantleState
	{
		float yaw; //OFS: 0x0 SIZE: 0x4
		int timer; //OFS: 0x4 SIZE: 0x4
		int transIndex; //OFS: 0x8 SIZE: 0x4
		int flags; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(MantleState, 0x10);
	ASSERT_STRUCT_OFFSET(MantleState, yaw, 0x0);
	ASSERT_STRUCT_OFFSET(MantleState, timer, 0x4);
	ASSERT_STRUCT_OFFSET(MantleState, transIndex, 0x8);
	ASSERT_STRUCT_OFFSET(MantleState, flags, 0xC);

	struct objective_t
	{
		objectiveState_t state; //OFS: 0x0 SIZE: 0x4
		float origin[3]; //OFS: 0x4 SIZE: 0xC
		int entNum; //OFS: 0x10 SIZE: 0x4
		int teamNum; //OFS: 0x14 SIZE: 0x4
		int squadNum; //OFS: 0x18 SIZE: 0x4
		int icon; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(objective_t, 0x20);
	ASSERT_STRUCT_OFFSET(objective_t, state, 0x0);
	ASSERT_STRUCT_OFFSET(objective_t, origin, 0x4);
	ASSERT_STRUCT_OFFSET(objective_t, entNum, 0x10);
	ASSERT_STRUCT_OFFSET(objective_t, teamNum, 0x14);
	ASSERT_STRUCT_OFFSET(objective_t, squadNum, 0x18);
	ASSERT_STRUCT_OFFSET(objective_t, icon, 0x1C);

	struct playerState_s
	{
		int commandTime; //OFS: 0x0 SIZE: 0x4
		pmtype_t pm_type; //OFS: 0x4 SIZE: 0x4
		int bobCycle; //OFS: 0x8 SIZE: 0x4
		pmflags_t pm_flags; //OFS: 0xC SIZE: 0x4
		int weapFlags; //OFS: 0x10 SIZE: 0x4
		int otherFlags; //OFS: 0x14 SIZE: 0x4
		int pm_time; //OFS: 0x18 SIZE: 0x4
		LoopSound loopSound; //OFS: 0x1C SIZE: 0x4
		float origin[3]; //OFS: 0x20 SIZE: 0xC
		float velocity[3]; //OFS: 0x2C SIZE: 0xC
		float oldVelocity[2]; //OFS: 0x38 SIZE: 0x8
		int weaponTime; //OFS: 0x40 SIZE: 0x4
		int weaponDelay; //OFS: 0x44 SIZE: 0x4
		int grenadeTimeLeft; //OFS: 0x48 SIZE: 0x4
		int throwBackGrenadeOwner; //OFS: 0x4C SIZE: 0x4
		int throwBackGrenadeTimeLeft; //OFS: 0x50 SIZE: 0x4
		int weaponRestrictKickTime; //OFS: 0x54 SIZE: 0x4
		bool mountAvailable; //OFS: 0x58 SIZE: 0x1
		float mountPos[3]; //OFS: 0x5C SIZE: 0xC
		float mountDir; //OFS: 0x68 SIZE: 0x4
		int foliageSoundTime; //OFS: 0x6C SIZE: 0x4
		int gravity; //OFS: 0x70 SIZE: 0x4
		float leanf; //OFS: 0x74 SIZE: 0x4
		int speed; //OFS: 0x78 SIZE: 0x4
		float delta_angles[3]; //OFS: 0x7C SIZE: 0xC
		int groundEntityNum; //OFS: 0x88 SIZE: 0x4
		float vLadderVec[3]; //OFS: 0x8C SIZE: 0xC
		int jumpTime; //OFS: 0x98 SIZE: 0x4
		float jumpOriginZ; //OFS: 0x9C SIZE: 0x4
		int legsTimer; //OFS: 0xA0 SIZE: 0x4
		int legsAnim; //OFS: 0xA4 SIZE: 0x4
		int torsoTimer; //OFS: 0xA8 SIZE: 0x4
		int torsoAnim; //OFS: 0xAC SIZE: 0x4
		int legsAnimDuration; //OFS: 0xB0 SIZE: 0x4
		int torsoAnimDuration; //OFS: 0xB4 SIZE: 0x4
		int damageTimer; //OFS: 0xB8 SIZE: 0x4
		int damageDuration; //OFS: 0xBC SIZE: 0x4
		int flinchYawAnim; //OFS: 0xC0 SIZE: 0x4
		int corpseIndex; //OFS: 0xC4 SIZE: 0x4
		int movementDir; //OFS: 0xC8 SIZE: 0x4
		int eFlags; //OFS: 0xCC SIZE: 0x4
		int eventSequence; //OFS: 0xD0 SIZE: 0x4
		int events[4]; //OFS: 0xD4 SIZE: 0x10
		unsigned int eventParms[4]; //OFS: 0xE4 SIZE: 0x10
		int oldEventSequence; //OFS: 0xF4 SIZE: 0x4
		int clientNum; //OFS: 0xF8 SIZE: 0x4
		int offHandIndex; //OFS: 0xFC SIZE: 0x4
		OffhandSecondaryClass offhandSecondary; //OFS: 0x100 SIZE: 0x4
		unsigned int weapon; //OFS: 0x104 SIZE: 0x4
		weaponstate_t weaponstate; //OFS: 0x108 SIZE: 0x4
		unsigned int weaponShotCount; //OFS: 0x10C SIZE: 0x4
		float fWeaponPosFrac; //OFS: 0x110 SIZE: 0x4
		int adsDelayTime; //OFS: 0x114 SIZE: 0x4
		int spreadOverride; //OFS: 0x118 SIZE: 0x4
		int spreadOverrideState; //OFS: 0x11C SIZE: 0x4
		int viewmodelIndex; //OFS: 0x120 SIZE: 0x4
		float viewangles[3]; //OFS: 0x124 SIZE: 0xC
		int viewHeightTarget; //OFS: 0x130 SIZE: 0x4
		float viewHeightCurrent; //OFS: 0x134 SIZE: 0x4
		int viewHeightLerpTime; //OFS: 0x138 SIZE: 0x4
		int viewHeightLerpTarget; //OFS: 0x13C SIZE: 0x4
		int viewHeightLerpDown; //OFS: 0x140 SIZE: 0x4
		float viewAngleClampBase[2]; //OFS: 0x144 SIZE: 0x8
		float viewAngleClampRange[2]; //OFS: 0x14C SIZE: 0x8
		int damageEvent; //OFS: 0x154 SIZE: 0x4
		int damageYaw; //OFS: 0x158 SIZE: 0x4
		int damagePitch; //OFS: 0x15C SIZE: 0x4
		int damageCount; //OFS: 0x160 SIZE: 0x4
		int stats[6]; //OFS: 0x164 SIZE: 0x18
		int ammo[128]; //OFS: 0x17C SIZE: 0x200
		float heatpercent[128]; //OFS: 0x37C SIZE: 0x200
		bool overheating[128]; //OFS: 0x57C SIZE: 0x80
		int ammoclip[128]; //OFS: 0x5FC SIZE: 0x200
		unsigned int weapons[4]; //OFS: 0x7FC SIZE: 0x10
		unsigned int weaponold[4]; //OFS: 0x80C SIZE: 0x10
		unsigned int weaponrechamber[4]; //OFS: 0x81C SIZE: 0x10
		float proneDirection; //OFS: 0x82C SIZE: 0x4
		float proneDirectionPitch; //OFS: 0x830 SIZE: 0x4
		float proneTorsoPitch; //OFS: 0x834 SIZE: 0x4
		ViewLockTypes viewlocked; //OFS: 0x838 SIZE: 0x4
		int viewlocked_entNum; //OFS: 0x83C SIZE: 0x4
		int vehiclePos; //OFS: 0x840 SIZE: 0x4
		int vehicleType; //OFS: 0x844 SIZE: 0x4
		int vehicleAnimBoneIndex; //OFS: 0x848 SIZE: 0x4
		int linkFlags; //OFS: 0x84C SIZE: 0x4
		float linkAngles[3]; //OFS: 0x850 SIZE: 0xC
		float groundTiltAngles[3]; //OFS: 0x85C SIZE: 0xC
		int cursorHint; //OFS: 0x868 SIZE: 0x4
		int cursorHintString; //OFS: 0x86C SIZE: 0x4
		int cursorHintEntIndex; //OFS: 0x870 SIZE: 0x4
		int iCompassPlayerInfo; //OFS: 0x874 SIZE: 0x4
		int radarEnabled; //OFS: 0x878 SIZE: 0x4
		int locationSelectionInfo; //OFS: 0x87C SIZE: 0x4
		SprintState sprintState; //OFS: 0x880 SIZE: 0x14
		float fTorsoPitch; //OFS: 0x894 SIZE: 0x4
		float fWaistPitch; //OFS: 0x898 SIZE: 0x4
		float holdBreathScale; //OFS: 0x89C SIZE: 0x4
		int holdBreathTimer; //OFS: 0x8A0 SIZE: 0x4
		float moveSpeedScaleMultiplier; //OFS: 0x8A4 SIZE: 0x4
		MantleState mantleState; //OFS: 0x8A8 SIZE: 0x10
		int vehicleAnimStage; //OFS: 0x8B8 SIZE: 0x4
		int vehicleEntryPoint; //OFS: 0x8BC SIZE: 0x4
		unsigned int scriptedAnim; //OFS: 0x8C0 SIZE: 0x4
		int scriptedAnimTime; //OFS: 0x8C4 SIZE: 0x4
		float meleeChargeYaw; //OFS: 0x8C8 SIZE: 0x4
		int meleeChargeDist; //OFS: 0x8CC SIZE: 0x4
		int meleeChargeTime; //OFS: 0x8D0 SIZE: 0x4
		int weapLockFlags; //OFS: 0x8D4 SIZE: 0x4
		int weapLockedEntnum; //OFS: 0x8D8 SIZE: 0x4
		unsigned int forcedViewAnimWeaponIdx; //OFS: 0x8DC SIZE: 0x4
		int forcedViewAnimWeaponState; //OFS: 0x8E0 SIZE: 0x4
		unsigned int forcedViewAnimOriginalWeaponIdx; //OFS: 0x8E4 SIZE: 0x4
		int collectibles; //OFS: 0x8E8 SIZE: 0x4
		int actionSlotType[4]; //OFS: 0x8EC SIZE: 0x10
		int actionSlotParams[4]; //OFS: 0x8FC SIZE: 0x10
		int entityEventSequence; //OFS: 0x90C SIZE: 0x4
		int weapAnim; //OFS: 0x910 SIZE: 0x4
		float aimSpreadScale; //OFS: 0x914 SIZE: 0x4
		int shellshockIndex; //OFS: 0x918 SIZE: 0x4
		int shellshockTime; //OFS: 0x91C SIZE: 0x4
		int shellshockDuration; //OFS: 0x920 SIZE: 0x4
		float dofNearStart; //OFS: 0x924 SIZE: 0x4
		float dofNearEnd; //OFS: 0x928 SIZE: 0x4
		float dofFarStart; //OFS: 0x92C SIZE: 0x4
		float dofFarEnd; //OFS: 0x930 SIZE: 0x4
		float dofNearBlur; //OFS: 0x934 SIZE: 0x4
		float dofFarBlur; //OFS: 0x938 SIZE: 0x4
		float dofViewmodelStart; //OFS: 0x93C SIZE: 0x4
		float dofViewmodelEnd; //OFS: 0x940 SIZE: 0x4
		int waterlevel; //OFS: 0x944 SIZE: 0x4
		int hudElemLastAssignedSoundID; //OFS: 0x948 SIZE: 0x4
		int artilleryInboundIconLocation; //OFS: 0x94C SIZE: 0x4
		objective_t objectives[16]; //OFS: 0x950 SIZE: 0x200
		char weaponmodels[128]; //OFS: 0xB50 SIZE: 0x80
		int deltatime; //OFS: 0xBD0 SIZE: 0x4
		hudelem_s hudelems[31]; //OFS: 0xBD4 SIZE: 0x14D4
		int perks; //OFS: 0x20A8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(playerState_s, 0x20AC);
	ASSERT_STRUCT_OFFSET(playerState_s, commandTime, 0x0);
	ASSERT_STRUCT_OFFSET(playerState_s, pm_type, 0x4);
	ASSERT_STRUCT_OFFSET(playerState_s, bobCycle, 0x8);
	ASSERT_STRUCT_OFFSET(playerState_s, pm_flags, 0xC);
	ASSERT_STRUCT_OFFSET(playerState_s, weapFlags, 0x10);
	ASSERT_STRUCT_OFFSET(playerState_s, otherFlags, 0x14);
	ASSERT_STRUCT_OFFSET(playerState_s, pm_time, 0x18);
	ASSERT_STRUCT_OFFSET(playerState_s, loopSound, 0x1C);
	ASSERT_STRUCT_OFFSET(playerState_s, origin, 0x20);
	ASSERT_STRUCT_OFFSET(playerState_s, velocity, 0x2C);
	ASSERT_STRUCT_OFFSET(playerState_s, oldVelocity, 0x38);
	ASSERT_STRUCT_OFFSET(playerState_s, weaponTime, 0x40);
	ASSERT_STRUCT_OFFSET(playerState_s, weaponDelay, 0x44);
	ASSERT_STRUCT_OFFSET(playerState_s, grenadeTimeLeft, 0x48);
	ASSERT_STRUCT_OFFSET(playerState_s, throwBackGrenadeOwner, 0x4C);
	ASSERT_STRUCT_OFFSET(playerState_s, throwBackGrenadeTimeLeft, 0x50);
	ASSERT_STRUCT_OFFSET(playerState_s, weaponRestrictKickTime, 0x54);
	ASSERT_STRUCT_OFFSET(playerState_s, mountAvailable, 0x58);
	ASSERT_STRUCT_OFFSET(playerState_s, mountPos, 0x5C);
	ASSERT_STRUCT_OFFSET(playerState_s, mountDir, 0x68);
	ASSERT_STRUCT_OFFSET(playerState_s, foliageSoundTime, 0x6C);
	ASSERT_STRUCT_OFFSET(playerState_s, gravity, 0x70);
	ASSERT_STRUCT_OFFSET(playerState_s, leanf, 0x74);
	ASSERT_STRUCT_OFFSET(playerState_s, speed, 0x78);
	ASSERT_STRUCT_OFFSET(playerState_s, delta_angles, 0x7C);
	ASSERT_STRUCT_OFFSET(playerState_s, groundEntityNum, 0x88);
	ASSERT_STRUCT_OFFSET(playerState_s, vLadderVec, 0x8C);
	ASSERT_STRUCT_OFFSET(playerState_s, jumpTime, 0x98);
	ASSERT_STRUCT_OFFSET(playerState_s, jumpOriginZ, 0x9C);
	ASSERT_STRUCT_OFFSET(playerState_s, legsTimer, 0xA0);
	ASSERT_STRUCT_OFFSET(playerState_s, legsAnim, 0xA4);
	ASSERT_STRUCT_OFFSET(playerState_s, torsoTimer, 0xA8);
	ASSERT_STRUCT_OFFSET(playerState_s, torsoAnim, 0xAC);
	ASSERT_STRUCT_OFFSET(playerState_s, legsAnimDuration, 0xB0);
	ASSERT_STRUCT_OFFSET(playerState_s, torsoAnimDuration, 0xB4);
	ASSERT_STRUCT_OFFSET(playerState_s, damageTimer, 0xB8);
	ASSERT_STRUCT_OFFSET(playerState_s, damageDuration, 0xBC);
	ASSERT_STRUCT_OFFSET(playerState_s, flinchYawAnim, 0xC0);
	ASSERT_STRUCT_OFFSET(playerState_s, corpseIndex, 0xC4);
	ASSERT_STRUCT_OFFSET(playerState_s, movementDir, 0xC8);
	ASSERT_STRUCT_OFFSET(playerState_s, eFlags, 0xCC);
	ASSERT_STRUCT_OFFSET(playerState_s, eventSequence, 0xD0);
	ASSERT_STRUCT_OFFSET(playerState_s, events, 0xD4);
	ASSERT_STRUCT_OFFSET(playerState_s, eventParms, 0xE4);
	ASSERT_STRUCT_OFFSET(playerState_s, oldEventSequence, 0xF4);
	ASSERT_STRUCT_OFFSET(playerState_s, clientNum, 0xF8);
	ASSERT_STRUCT_OFFSET(playerState_s, offHandIndex, 0xFC);
	ASSERT_STRUCT_OFFSET(playerState_s, offhandSecondary, 0x100);
	ASSERT_STRUCT_OFFSET(playerState_s, weapon, 0x104);
	ASSERT_STRUCT_OFFSET(playerState_s, weaponstate, 0x108);
	ASSERT_STRUCT_OFFSET(playerState_s, weaponShotCount, 0x10C);
	ASSERT_STRUCT_OFFSET(playerState_s, fWeaponPosFrac, 0x110);
	ASSERT_STRUCT_OFFSET(playerState_s, adsDelayTime, 0x114);
	ASSERT_STRUCT_OFFSET(playerState_s, spreadOverride, 0x118);
	ASSERT_STRUCT_OFFSET(playerState_s, spreadOverrideState, 0x11C);
	ASSERT_STRUCT_OFFSET(playerState_s, viewmodelIndex, 0x120);
	ASSERT_STRUCT_OFFSET(playerState_s, viewangles, 0x124);
	ASSERT_STRUCT_OFFSET(playerState_s, viewHeightTarget, 0x130);
	ASSERT_STRUCT_OFFSET(playerState_s, viewHeightCurrent, 0x134);
	ASSERT_STRUCT_OFFSET(playerState_s, viewHeightLerpTime, 0x138);
	ASSERT_STRUCT_OFFSET(playerState_s, viewHeightLerpTarget, 0x13C);
	ASSERT_STRUCT_OFFSET(playerState_s, viewHeightLerpDown, 0x140);
	ASSERT_STRUCT_OFFSET(playerState_s, viewAngleClampBase, 0x144);
	ASSERT_STRUCT_OFFSET(playerState_s, viewAngleClampRange, 0x14C);
	ASSERT_STRUCT_OFFSET(playerState_s, damageEvent, 0x154);
	ASSERT_STRUCT_OFFSET(playerState_s, damageYaw, 0x158);
	ASSERT_STRUCT_OFFSET(playerState_s, damagePitch, 0x15C);
	ASSERT_STRUCT_OFFSET(playerState_s, damageCount, 0x160);
	ASSERT_STRUCT_OFFSET(playerState_s, stats, 0x164);
	ASSERT_STRUCT_OFFSET(playerState_s, ammo, 0x17C);
	ASSERT_STRUCT_OFFSET(playerState_s, heatpercent, 0x37C);
	ASSERT_STRUCT_OFFSET(playerState_s, overheating, 0x57C);
	ASSERT_STRUCT_OFFSET(playerState_s, ammoclip, 0x5FC);
	ASSERT_STRUCT_OFFSET(playerState_s, weapons, 0x7FC);
	ASSERT_STRUCT_OFFSET(playerState_s, weaponold, 0x80C);
	ASSERT_STRUCT_OFFSET(playerState_s, weaponrechamber, 0x81C);
	ASSERT_STRUCT_OFFSET(playerState_s, proneDirection, 0x82C);
	ASSERT_STRUCT_OFFSET(playerState_s, proneDirectionPitch, 0x830);
	ASSERT_STRUCT_OFFSET(playerState_s, proneTorsoPitch, 0x834);
	ASSERT_STRUCT_OFFSET(playerState_s, viewlocked, 0x838);
	ASSERT_STRUCT_OFFSET(playerState_s, viewlocked_entNum, 0x83C);
	ASSERT_STRUCT_OFFSET(playerState_s, vehiclePos, 0x840);
	ASSERT_STRUCT_OFFSET(playerState_s, vehicleType, 0x844);
	ASSERT_STRUCT_OFFSET(playerState_s, vehicleAnimBoneIndex, 0x848);
	ASSERT_STRUCT_OFFSET(playerState_s, linkFlags, 0x84C);
	ASSERT_STRUCT_OFFSET(playerState_s, linkAngles, 0x850);
	ASSERT_STRUCT_OFFSET(playerState_s, groundTiltAngles, 0x85C);
	ASSERT_STRUCT_OFFSET(playerState_s, cursorHint, 0x868);
	ASSERT_STRUCT_OFFSET(playerState_s, cursorHintString, 0x86C);
	ASSERT_STRUCT_OFFSET(playerState_s, cursorHintEntIndex, 0x870);
	ASSERT_STRUCT_OFFSET(playerState_s, iCompassPlayerInfo, 0x874);
	ASSERT_STRUCT_OFFSET(playerState_s, radarEnabled, 0x878);
	ASSERT_STRUCT_OFFSET(playerState_s, locationSelectionInfo, 0x87C);
	ASSERT_STRUCT_OFFSET(playerState_s, sprintState, 0x880);
	ASSERT_STRUCT_OFFSET(playerState_s, fTorsoPitch, 0x894);
	ASSERT_STRUCT_OFFSET(playerState_s, fWaistPitch, 0x898);
	ASSERT_STRUCT_OFFSET(playerState_s, holdBreathScale, 0x89C);
	ASSERT_STRUCT_OFFSET(playerState_s, holdBreathTimer, 0x8A0);
	ASSERT_STRUCT_OFFSET(playerState_s, moveSpeedScaleMultiplier, 0x8A4);
	ASSERT_STRUCT_OFFSET(playerState_s, mantleState, 0x8A8);
	ASSERT_STRUCT_OFFSET(playerState_s, vehicleAnimStage, 0x8B8);
	ASSERT_STRUCT_OFFSET(playerState_s, vehicleEntryPoint, 0x8BC);
	ASSERT_STRUCT_OFFSET(playerState_s, scriptedAnim, 0x8C0);
	ASSERT_STRUCT_OFFSET(playerState_s, scriptedAnimTime, 0x8C4);
	ASSERT_STRUCT_OFFSET(playerState_s, meleeChargeYaw, 0x8C8);
	ASSERT_STRUCT_OFFSET(playerState_s, meleeChargeDist, 0x8CC);
	ASSERT_STRUCT_OFFSET(playerState_s, meleeChargeTime, 0x8D0);
	ASSERT_STRUCT_OFFSET(playerState_s, weapLockFlags, 0x8D4);
	ASSERT_STRUCT_OFFSET(playerState_s, weapLockedEntnum, 0x8D8);
	ASSERT_STRUCT_OFFSET(playerState_s, forcedViewAnimWeaponIdx, 0x8DC);
	ASSERT_STRUCT_OFFSET(playerState_s, forcedViewAnimWeaponState, 0x8E0);
	ASSERT_STRUCT_OFFSET(playerState_s, forcedViewAnimOriginalWeaponIdx, 0x8E4);
	ASSERT_STRUCT_OFFSET(playerState_s, collectibles, 0x8E8);
	ASSERT_STRUCT_OFFSET(playerState_s, actionSlotType, 0x8EC);
	ASSERT_STRUCT_OFFSET(playerState_s, actionSlotParams, 0x8FC);
	ASSERT_STRUCT_OFFSET(playerState_s, entityEventSequence, 0x90C);
	ASSERT_STRUCT_OFFSET(playerState_s, weapAnim, 0x910);
	ASSERT_STRUCT_OFFSET(playerState_s, aimSpreadScale, 0x914);
	ASSERT_STRUCT_OFFSET(playerState_s, shellshockIndex, 0x918);
	ASSERT_STRUCT_OFFSET(playerState_s, shellshockTime, 0x91C);
	ASSERT_STRUCT_OFFSET(playerState_s, shellshockDuration, 0x920);
	ASSERT_STRUCT_OFFSET(playerState_s, dofNearStart, 0x924);
	ASSERT_STRUCT_OFFSET(playerState_s, dofNearEnd, 0x928);
	ASSERT_STRUCT_OFFSET(playerState_s, dofFarStart, 0x92C);
	ASSERT_STRUCT_OFFSET(playerState_s, dofFarEnd, 0x930);
	ASSERT_STRUCT_OFFSET(playerState_s, dofNearBlur, 0x934);
	ASSERT_STRUCT_OFFSET(playerState_s, dofFarBlur, 0x938);
	ASSERT_STRUCT_OFFSET(playerState_s, dofViewmodelStart, 0x93C);
	ASSERT_STRUCT_OFFSET(playerState_s, dofViewmodelEnd, 0x940);
	ASSERT_STRUCT_OFFSET(playerState_s, waterlevel, 0x944);
	ASSERT_STRUCT_OFFSET(playerState_s, hudElemLastAssignedSoundID, 0x948);
	ASSERT_STRUCT_OFFSET(playerState_s, artilleryInboundIconLocation, 0x94C);
	ASSERT_STRUCT_OFFSET(playerState_s, objectives, 0x950);
	ASSERT_STRUCT_OFFSET(playerState_s, weaponmodels, 0xB50);
	ASSERT_STRUCT_OFFSET(playerState_s, deltatime, 0xBD0);
	ASSERT_STRUCT_OFFSET(playerState_s, hudelems, 0xBD4);
	ASSERT_STRUCT_OFFSET(playerState_s, perks, 0x20A8);

	struct usercmd_s
	{
		int serverTime; //OFS: 0x0 SIZE: 0x4
		button_mask buttons; //OFS: 0x4 SIZE: 0x4
		int angles[3]; //OFS: 0x8 SIZE: 0xC
		char weapon; //OFS: 0x14 SIZE: 0x1
		char offHandIndex; //OFS: 0x15 SIZE: 0x1
		char forward; //OFS: 0x16 SIZE: 0x1
		char right; //OFS: 0x17 SIZE: 0x1
		char upmove; //OFS: 0x18 SIZE: 0x1
		char pitchmove; //OFS: 0x19 SIZE: 0x1
		char yawmove; //OFS: 0x1A SIZE: 0x1
		__int16 wiimoteGunPitch; //OFS: 0x1C SIZE: 0x2
		__int16 wiimoteGunYaw; //OFS: 0x1E SIZE: 0x2
		__int16 gunXOfs; //OFS: 0x20 SIZE: 0x2
		__int16 gunYOfs; //OFS: 0x22 SIZE: 0x2
		__int16 gunZOfs; //OFS: 0x24 SIZE: 0x2
		int meleeChargeYaw; //OFS: 0x28 SIZE: 0x4
		char meleeChargeDist; //OFS: 0x2C SIZE: 0x1
		int rollmove; //OFS: 0x30 SIZE: 0x4
		char selectedLocation[2]; //OFS: 0x34 SIZE: 0x2
		__int16 weapon_buddy; //OFS: 0x36 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(usercmd_s, 0x38);
	ASSERT_STRUCT_OFFSET(usercmd_s, serverTime, 0x0);
	ASSERT_STRUCT_OFFSET(usercmd_s, buttons, 0x4);
	ASSERT_STRUCT_OFFSET(usercmd_s, angles, 0x8);
	ASSERT_STRUCT_OFFSET(usercmd_s, weapon, 0x14);
	ASSERT_STRUCT_OFFSET(usercmd_s, offHandIndex, 0x15);
	ASSERT_STRUCT_OFFSET(usercmd_s, forward, 0x16);
	ASSERT_STRUCT_OFFSET(usercmd_s, right, 0x17);
	ASSERT_STRUCT_OFFSET(usercmd_s, upmove, 0x18);
	ASSERT_STRUCT_OFFSET(usercmd_s, pitchmove, 0x19);
	ASSERT_STRUCT_OFFSET(usercmd_s, yawmove, 0x1A);
	ASSERT_STRUCT_OFFSET(usercmd_s, wiimoteGunPitch, 0x1C);
	ASSERT_STRUCT_OFFSET(usercmd_s, wiimoteGunYaw, 0x1E);
	ASSERT_STRUCT_OFFSET(usercmd_s, gunXOfs, 0x20);
	ASSERT_STRUCT_OFFSET(usercmd_s, gunYOfs, 0x22);
	ASSERT_STRUCT_OFFSET(usercmd_s, gunZOfs, 0x24);
	ASSERT_STRUCT_OFFSET(usercmd_s, meleeChargeYaw, 0x28);
	ASSERT_STRUCT_OFFSET(usercmd_s, meleeChargeDist, 0x2C);
	ASSERT_STRUCT_OFFSET(usercmd_s, rollmove, 0x30);
	ASSERT_STRUCT_OFFSET(usercmd_s, selectedLocation, 0x34);
	ASSERT_STRUCT_OFFSET(usercmd_s, weapon_buddy, 0x36);

	struct clientState_s
	{
		int clientNum; //OFS: 0x0 SIZE: 0x4
		team_t team; //OFS: 0x4 SIZE: 0x4
		int modelindex; //OFS: 0x8 SIZE: 0x4
		int attachModelIndex[6]; //OFS: 0xC SIZE: 0x18
		int attachTagIndex[6]; //OFS: 0x24 SIZE: 0x18
		int lastDamageTime; //OFS: 0x3C SIZE: 0x4
		int lastStandStartTime; //OFS: 0x40 SIZE: 0x4
		int beingRevived; //OFS: 0x44 SIZE: 0x4
		int score; //OFS: 0x48 SIZE: 0x4
		int scoreMultiplier; //OFS: 0x4C SIZE: 0x4
		char name[32]; //OFS: 0x50 SIZE: 0x20
		float maxSprintTimeMultiplier; //OFS: 0x70 SIZE: 0x4
		int rank; //OFS: 0x74 SIZE: 0x4
		int prestige; //OFS: 0x78 SIZE: 0x4
		char clanAbbrev[8]; //OFS: 0x7C SIZE: 0x8
		int attachedEntNum; //OFS: 0x84 SIZE: 0x4
		int attachedTagIndex; //OFS: 0x88 SIZE: 0x4
		VehicleAnimState vehAnimState; //OFS: 0x8C SIZE: 0x4
		int perks; //OFS: 0x90 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(clientState_s, 0x94);
	ASSERT_STRUCT_OFFSET(clientState_s, clientNum, 0x0);
	ASSERT_STRUCT_OFFSET(clientState_s, team, 0x4);
	ASSERT_STRUCT_OFFSET(clientState_s, modelindex, 0x8);
	ASSERT_STRUCT_OFFSET(clientState_s, attachModelIndex, 0xC);
	ASSERT_STRUCT_OFFSET(clientState_s, attachTagIndex, 0x24);
	ASSERT_STRUCT_OFFSET(clientState_s, lastDamageTime, 0x3C);
	ASSERT_STRUCT_OFFSET(clientState_s, lastStandStartTime, 0x40);
	ASSERT_STRUCT_OFFSET(clientState_s, beingRevived, 0x44);
	ASSERT_STRUCT_OFFSET(clientState_s, score, 0x48);
	ASSERT_STRUCT_OFFSET(clientState_s, scoreMultiplier, 0x4C);
	ASSERT_STRUCT_OFFSET(clientState_s, name, 0x50);
	ASSERT_STRUCT_OFFSET(clientState_s, maxSprintTimeMultiplier, 0x70);
	ASSERT_STRUCT_OFFSET(clientState_s, rank, 0x74);
	ASSERT_STRUCT_OFFSET(clientState_s, prestige, 0x78);
	ASSERT_STRUCT_OFFSET(clientState_s, clanAbbrev, 0x7C);
	ASSERT_STRUCT_OFFSET(clientState_s, attachedEntNum, 0x84);
	ASSERT_STRUCT_OFFSET(clientState_s, attachedTagIndex, 0x88);
	ASSERT_STRUCT_OFFSET(clientState_s, vehAnimState, 0x8C);
	ASSERT_STRUCT_OFFSET(clientState_s, perks, 0x90);

	struct clientSession_s
	{
		sessionState_t sessionState; //OFS: 0x0 SIZE: 0x4
		int forceSpectatorClient; //OFS: 0x4 SIZE: 0x4
		int status_icon; //OFS: 0x8 SIZE: 0x4
		int archiveTime; //OFS: 0xC SIZE: 0x4
		int score; //OFS: 0x10 SIZE: 0x4
		int kills; //OFS: 0x14 SIZE: 0x4
		int assists; //OFS: 0x18 SIZE: 0x4
		int downs; //OFS: 0x1C SIZE: 0x4
		int revives; //OFS: 0x20 SIZE: 0x4
		int headshots; //OFS: 0x24 SIZE: 0x4
		int rankxp; //OFS: 0x28 SIZE: 0x4
		int something; //OFS: 0x2C SIZE: 0x4
		__int16 scriptId; //OFS: 0x30 SIZE: 0x2
		_BYTE gap_32[2]; //OFS: 0x32 SIZE: 0x2
		clientConnected_t connected; //OFS: 0x34 SIZE: 0x4
		usercmd_s cmd; //OFS: 0x38 SIZE: 0x38
		usercmd_s oldcmd; //OFS: 0x70 SIZE: 0x38
		int localClient; //OFS: 0xA8 SIZE: 0x4
		int predictItemPickup; //OFS: 0xAC SIZE: 0x4
		char newnetname[32]; //OFS: 0xB0 SIZE: 0x20
		int maxHealth; //OFS: 0xD0 SIZE: 0x4
		int enterTime; //OFS: 0xD4 SIZE: 0x4
		int teamState; //OFS: 0xD8 SIZE: 0x4
		int voteCount; //OFS: 0xDC SIZE: 0x4
		int teamVoteCount; //OFS: 0xE0 SIZE: 0x4
		float moveSpeedScaleMultiplier; //OFS: 0xE4 SIZE: 0x4
		int viewmodelIndex; //OFS: 0xE8 SIZE: 0x4
		int noSpectate; //OFS: 0xEC SIZE: 0x4
		int teamInfo; //OFS: 0xF0 SIZE: 0x4
		clientState_s _cs; //OFS: 0xF4 SIZE: 0x94
		int psOffsetTime; //OFS: 0x188 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(clientSession_s, 0x18C);
	ASSERT_STRUCT_OFFSET(clientSession_s, sessionState, 0x0);
	ASSERT_STRUCT_OFFSET(clientSession_s, forceSpectatorClient, 0x4);
	ASSERT_STRUCT_OFFSET(clientSession_s, status_icon, 0x8);
	ASSERT_STRUCT_OFFSET(clientSession_s, archiveTime, 0xC);
	ASSERT_STRUCT_OFFSET(clientSession_s, score, 0x10);
	ASSERT_STRUCT_OFFSET(clientSession_s, kills, 0x14);
	ASSERT_STRUCT_OFFSET(clientSession_s, assists, 0x18);
	ASSERT_STRUCT_OFFSET(clientSession_s, downs, 0x1C);
	ASSERT_STRUCT_OFFSET(clientSession_s, revives, 0x20);
	ASSERT_STRUCT_OFFSET(clientSession_s, headshots, 0x24);
	ASSERT_STRUCT_OFFSET(clientSession_s, rankxp, 0x28);
	ASSERT_STRUCT_OFFSET(clientSession_s, something, 0x2C);
	ASSERT_STRUCT_OFFSET(clientSession_s, scriptId, 0x30);
	ASSERT_STRUCT_OFFSET(clientSession_s, gap_32, 0x32);
	ASSERT_STRUCT_OFFSET(clientSession_s, connected, 0x34);
	ASSERT_STRUCT_OFFSET(clientSession_s, cmd, 0x38);
	ASSERT_STRUCT_OFFSET(clientSession_s, oldcmd, 0x70);
	ASSERT_STRUCT_OFFSET(clientSession_s, localClient, 0xA8);
	ASSERT_STRUCT_OFFSET(clientSession_s, predictItemPickup, 0xAC);
	ASSERT_STRUCT_OFFSET(clientSession_s, newnetname, 0xB0);
	ASSERT_STRUCT_OFFSET(clientSession_s, maxHealth, 0xD0);
	ASSERT_STRUCT_OFFSET(clientSession_s, enterTime, 0xD4);
	ASSERT_STRUCT_OFFSET(clientSession_s, teamState, 0xD8);
	ASSERT_STRUCT_OFFSET(clientSession_s, voteCount, 0xDC);
	ASSERT_STRUCT_OFFSET(clientSession_s, teamVoteCount, 0xE0);
	ASSERT_STRUCT_OFFSET(clientSession_s, moveSpeedScaleMultiplier, 0xE4);
	ASSERT_STRUCT_OFFSET(clientSession_s, viewmodelIndex, 0xE8);
	ASSERT_STRUCT_OFFSET(clientSession_s, noSpectate, 0xEC);
	ASSERT_STRUCT_OFFSET(clientSession_s, teamInfo, 0xF0);
	ASSERT_STRUCT_OFFSET(clientSession_s, _cs, 0xF4);
	ASSERT_STRUCT_OFFSET(clientSession_s, psOffsetTime, 0x188);

	struct gclient_s
	{
		playerState_s ps; //OFS: 0x0 SIZE: 0x20AC
		clientSession_s sess; //OFS: 0x20AC SIZE: 0x18C
		int spectatorClient; //OFS: 0x2238 SIZE: 0x4
		int noclip; //OFS: 0x223C SIZE: 0x4
		int ufo; //OFS: 0x2240 SIZE: 0x4
		int bFrozen; //OFS: 0x2244 SIZE: 0x4
		int buttons; //OFS: 0x2248 SIZE: 0x4
		int oldbuttons; //OFS: 0x224C SIZE: 0x4
		int latched_buttons; //OFS: 0x2250 SIZE: 0x4
		int buttonsSinceLastFrame; //OFS: 0x2254 SIZE: 0x4
		float fGunPitch; //OFS: 0x2258 SIZE: 0x4
		float fGunYaw; //OFS: 0x225C SIZE: 0x4
		float fGunXOfs; //OFS: 0x2260 SIZE: 0x4
		float fGunYOfs; //OFS: 0x2264 SIZE: 0x4
		float fGunZOfs; //OFS: 0x2268 SIZE: 0x4
		int damage_blood; //OFS: 0x226C SIZE: 0x4
		float damage_from[3]; //OFS: 0x2270 SIZE: 0xC
		int damage_fromWorld; //OFS: 0x227C SIZE: 0x4
		int respawnTime; //OFS: 0x2280 SIZE: 0x4
		int lastBadArcCreateTime; //OFS: 0x2284 SIZE: 0x4
		int outWaterTime; //OFS: 0x2288 SIZE: 0x4
		float currentAimSpreadScale; //OFS: 0x228C SIZE: 0x4
		gentity_s * pHitHitEnt; //OFS: 0x2290 SIZE: 0x4
		EntHandle pLookatEnt; //OFS: 0x2294 SIZE: 0x4
		float prevLinkedInvQuat[4]; //OFS: 0x2298 SIZE: 0x10
		bool prevLinkAnglesSet; //OFS: 0x22A8 SIZE: 0x1
		bool link_doCollision; //OFS: 0x22A9 SIZE: 0x1
		bool linkAnglesLocked; //OFS: 0x22AA SIZE: 0x1
		float linkAnglesFrac; //OFS: 0x22AC SIZE: 0x4
		float linkAnglesMinClamp[2]; //OFS: 0x22B0 SIZE: 0x8
		float linkAnglesMaxClamp[2]; //OFS: 0x22B8 SIZE: 0x8
		int inControlTime; //OFS: 0x22C0 SIZE: 0x4
		int lastTouchTime; //OFS: 0x22C4 SIZE: 0x4
		EntHandle useHoldEntity; //OFS: 0x22C8 SIZE: 0x4
		int useHoldTime; //OFS: 0x22CC SIZE: 0x4
		int useButtonDone; //OFS: 0x22D0 SIZE: 0x4
		int bDisableAutoPickup; //OFS: 0x22D4 SIZE: 0x4
		int invulnerableExpireTime; //OFS: 0x22D8 SIZE: 0x4
		bool invulnerableActivated; //OFS: 0x22DC SIZE: 0x1
		bool invulnerableEnabled; //OFS: 0x22DD SIZE: 0x1
		bool playerMoved; //OFS: 0x22DE SIZE: 0x1
		float playerLOSCheckPos[2]; //OFS: 0x22E0 SIZE: 0x8
		float playerLOSCheckDir[2]; //OFS: 0x22E8 SIZE: 0x8
		int playerLOSPosTime; //OFS: 0x22F0 SIZE: 0x4
		int playerADSTargetTime; //OFS: 0x22F4 SIZE: 0x4
		unsigned int lastWeapon; //OFS: 0x22F8 SIZE: 0x4
		bool previouslyFiring; //OFS: 0x22FC SIZE: 0x1
		bool previouslyUsingNightVision; //OFS: 0x22FD SIZE: 0x1
		int groundTiltEntNum; //OFS: 0x2300 SIZE: 0x4
		int revive; //OFS: 0x2304 SIZE: 0x4
		int reviveTime; //OFS: 0x2308 SIZE: 0x4
		int lastStand; //OFS: 0x230C SIZE: 0x4
		int lastStandTime; //OFS: 0x2310 SIZE: 0x4
		int switchSeatTime; //OFS: 0x2314 SIZE: 0x4
		int lastCmdTime; //OFS: 0x2318 SIZE: 0x4
		int inactivityTime; //OFS: 0x231C SIZE: 0x4
		int inactivityWarning; //OFS: 0x2320 SIZE: 0x4
		int lastVoiceTime; //OFS: 0x2324 SIZE: 0x4
		int lastServerTime; //OFS: 0x2328 SIZE: 0x4
		int lastSpawnTime; //OFS: 0x232C SIZE: 0x4
		int damageTime; //OFS: 0x2330 SIZE: 0x4
		float vGunSpeed[3]; //OFS: 0x2334 SIZE: 0xC
		int dropWeaponTime; //OFS: 0x2340 SIZE: 0x4
		bool previouslyChangingWeapon; //OFS: 0x2344 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(gclient_s, 0x2348);
	ASSERT_STRUCT_OFFSET(gclient_s, ps, 0x0);
	ASSERT_STRUCT_OFFSET(gclient_s, sess, 0x20AC);
	ASSERT_STRUCT_OFFSET(gclient_s, spectatorClient, 0x2238);
	ASSERT_STRUCT_OFFSET(gclient_s, noclip, 0x223C);
	ASSERT_STRUCT_OFFSET(gclient_s, ufo, 0x2240);
	ASSERT_STRUCT_OFFSET(gclient_s, bFrozen, 0x2244);
	ASSERT_STRUCT_OFFSET(gclient_s, buttons, 0x2248);
	ASSERT_STRUCT_OFFSET(gclient_s, oldbuttons, 0x224C);
	ASSERT_STRUCT_OFFSET(gclient_s, latched_buttons, 0x2250);
	ASSERT_STRUCT_OFFSET(gclient_s, buttonsSinceLastFrame, 0x2254);
	ASSERT_STRUCT_OFFSET(gclient_s, fGunPitch, 0x2258);
	ASSERT_STRUCT_OFFSET(gclient_s, fGunYaw, 0x225C);
	ASSERT_STRUCT_OFFSET(gclient_s, fGunXOfs, 0x2260);
	ASSERT_STRUCT_OFFSET(gclient_s, fGunYOfs, 0x2264);
	ASSERT_STRUCT_OFFSET(gclient_s, fGunZOfs, 0x2268);
	ASSERT_STRUCT_OFFSET(gclient_s, damage_blood, 0x226C);
	ASSERT_STRUCT_OFFSET(gclient_s, damage_from, 0x2270);
	ASSERT_STRUCT_OFFSET(gclient_s, damage_fromWorld, 0x227C);
	ASSERT_STRUCT_OFFSET(gclient_s, respawnTime, 0x2280);
	ASSERT_STRUCT_OFFSET(gclient_s, lastBadArcCreateTime, 0x2284);
	ASSERT_STRUCT_OFFSET(gclient_s, outWaterTime, 0x2288);
	ASSERT_STRUCT_OFFSET(gclient_s, currentAimSpreadScale, 0x228C);
	ASSERT_STRUCT_OFFSET(gclient_s, pHitHitEnt, 0x2290);
	ASSERT_STRUCT_OFFSET(gclient_s, pLookatEnt, 0x2294);
	ASSERT_STRUCT_OFFSET(gclient_s, prevLinkedInvQuat, 0x2298);
	ASSERT_STRUCT_OFFSET(gclient_s, prevLinkAnglesSet, 0x22A8);
	ASSERT_STRUCT_OFFSET(gclient_s, link_doCollision, 0x22A9);
	ASSERT_STRUCT_OFFSET(gclient_s, linkAnglesLocked, 0x22AA);
	ASSERT_STRUCT_OFFSET(gclient_s, linkAnglesFrac, 0x22AC);
	ASSERT_STRUCT_OFFSET(gclient_s, linkAnglesMinClamp, 0x22B0);
	ASSERT_STRUCT_OFFSET(gclient_s, linkAnglesMaxClamp, 0x22B8);
	ASSERT_STRUCT_OFFSET(gclient_s, inControlTime, 0x22C0);
	ASSERT_STRUCT_OFFSET(gclient_s, lastTouchTime, 0x22C4);
	ASSERT_STRUCT_OFFSET(gclient_s, useHoldEntity, 0x22C8);
	ASSERT_STRUCT_OFFSET(gclient_s, useHoldTime, 0x22CC);
	ASSERT_STRUCT_OFFSET(gclient_s, useButtonDone, 0x22D0);
	ASSERT_STRUCT_OFFSET(gclient_s, bDisableAutoPickup, 0x22D4);
	ASSERT_STRUCT_OFFSET(gclient_s, invulnerableExpireTime, 0x22D8);
	ASSERT_STRUCT_OFFSET(gclient_s, invulnerableActivated, 0x22DC);
	ASSERT_STRUCT_OFFSET(gclient_s, invulnerableEnabled, 0x22DD);
	ASSERT_STRUCT_OFFSET(gclient_s, playerMoved, 0x22DE);
	ASSERT_STRUCT_OFFSET(gclient_s, playerLOSCheckPos, 0x22E0);
	ASSERT_STRUCT_OFFSET(gclient_s, playerLOSCheckDir, 0x22E8);
	ASSERT_STRUCT_OFFSET(gclient_s, playerLOSPosTime, 0x22F0);
	ASSERT_STRUCT_OFFSET(gclient_s, playerADSTargetTime, 0x22F4);
	ASSERT_STRUCT_OFFSET(gclient_s, lastWeapon, 0x22F8);
	ASSERT_STRUCT_OFFSET(gclient_s, previouslyFiring, 0x22FC);
	ASSERT_STRUCT_OFFSET(gclient_s, previouslyUsingNightVision, 0x22FD);
	ASSERT_STRUCT_OFFSET(gclient_s, groundTiltEntNum, 0x2300);
	ASSERT_STRUCT_OFFSET(gclient_s, revive, 0x2304);
	ASSERT_STRUCT_OFFSET(gclient_s, reviveTime, 0x2308);
	ASSERT_STRUCT_OFFSET(gclient_s, lastStand, 0x230C);
	ASSERT_STRUCT_OFFSET(gclient_s, lastStandTime, 0x2310);
	ASSERT_STRUCT_OFFSET(gclient_s, switchSeatTime, 0x2314);
	ASSERT_STRUCT_OFFSET(gclient_s, lastCmdTime, 0x2318);
	ASSERT_STRUCT_OFFSET(gclient_s, inactivityTime, 0x231C);
	ASSERT_STRUCT_OFFSET(gclient_s, inactivityWarning, 0x2320);
	ASSERT_STRUCT_OFFSET(gclient_s, lastVoiceTime, 0x2324);
	ASSERT_STRUCT_OFFSET(gclient_s, lastServerTime, 0x2328);
	ASSERT_STRUCT_OFFSET(gclient_s, lastSpawnTime, 0x232C);
	ASSERT_STRUCT_OFFSET(gclient_s, damageTime, 0x2330);
	ASSERT_STRUCT_OFFSET(gclient_s, vGunSpeed, 0x2334);
	ASSERT_STRUCT_OFFSET(gclient_s, dropWeaponTime, 0x2340);
	ASSERT_STRUCT_OFFSET(gclient_s, previouslyChangingWeapon, 0x2344);

	struct sentient_s
	{
		gentity_s * ent; //OFS: 0x0 SIZE: 0x4
		team_t eTeam; //OFS: 0x4 SIZE: 0x4
		int iThreatBias; //OFS: 0x8 SIZE: 0x4
		int iThreatBiasGroupIndex; //OFS: 0xC SIZE: 0x4
		bool bIgnoreMe; //OFS: 0x10 SIZE: 0x1
		bool bIgnoreAll; //OFS: 0x11 SIZE: 0x1
		bool originChanged; //OFS: 0x12 SIZE: 0x1
		float oldOrigin[3]; //OFS: 0x14 SIZE: 0xC
		float maxVisibleDist; //OFS: 0x20 SIZE: 0x4
		int iEnemyNotifyTime; //OFS: 0x24 SIZE: 0x4
		int attackerCount; //OFS: 0x28 SIZE: 0x4
		gentity_s * lastAttacker; //OFS: 0x2C SIZE: 0x4
		EntHandle syncedMeleeEnt; //OFS: 0x30 SIZE: 0x4
		EntHandle targetEnt; //OFS: 0x34 SIZE: 0x4
		EntHandle scriptTargetEnt; //OFS: 0x38 SIZE: 0x4
		float entityTargetThreat; //OFS: 0x3C SIZE: 0x4
		int meleeAttackerSpot[4]; //OFS: 0x40 SIZE: 0x10
		float attackerAccuracy; //OFS: 0x50 SIZE: 0x4
		bool ignoreRandomBulletDamage; //OFS: 0x54 SIZE: 0x1
		bool turretInvulnerability; //OFS: 0x55 SIZE: 0x1
		pathnode_t * pClaimedNode; //OFS: 0x58 SIZE: 0x4
		pathnode_t * pPrevClaimedNode; //OFS: 0x5C SIZE: 0x4
		pathnode_t * pActualChainPos; //OFS: 0x60 SIZE: 0x4
		int iActualChainPosTime; //OFS: 0x64 SIZE: 0x4
		pathnode_t * pNearestNode; //OFS: 0x68 SIZE: 0x4
		unsigned __int8 bNearestNodeValid; //OFS: 0x6C SIZE: 0x1
		unsigned __int8 bNearestNodeBad; //OFS: 0x6D SIZE: 0x1
		float vNearestNodeCheckPos[3]; //OFS: 0x70 SIZE: 0xC
		bool inuse; //OFS: 0x7C SIZE: 0x1
		int banNodeTime; //OFS: 0x80 SIZE: 0x4
		bool bInMeleeCharge; //OFS: 0x84 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(sentient_s, 0x88);
	ASSERT_STRUCT_OFFSET(sentient_s, ent, 0x0);
	ASSERT_STRUCT_OFFSET(sentient_s, eTeam, 0x4);
	ASSERT_STRUCT_OFFSET(sentient_s, iThreatBias, 0x8);
	ASSERT_STRUCT_OFFSET(sentient_s, iThreatBiasGroupIndex, 0xC);
	ASSERT_STRUCT_OFFSET(sentient_s, bIgnoreMe, 0x10);
	ASSERT_STRUCT_OFFSET(sentient_s, bIgnoreAll, 0x11);
	ASSERT_STRUCT_OFFSET(sentient_s, originChanged, 0x12);
	ASSERT_STRUCT_OFFSET(sentient_s, oldOrigin, 0x14);
	ASSERT_STRUCT_OFFSET(sentient_s, maxVisibleDist, 0x20);
	ASSERT_STRUCT_OFFSET(sentient_s, iEnemyNotifyTime, 0x24);
	ASSERT_STRUCT_OFFSET(sentient_s, attackerCount, 0x28);
	ASSERT_STRUCT_OFFSET(sentient_s, lastAttacker, 0x2C);
	ASSERT_STRUCT_OFFSET(sentient_s, syncedMeleeEnt, 0x30);
	ASSERT_STRUCT_OFFSET(sentient_s, targetEnt, 0x34);
	ASSERT_STRUCT_OFFSET(sentient_s, scriptTargetEnt, 0x38);
	ASSERT_STRUCT_OFFSET(sentient_s, entityTargetThreat, 0x3C);
	ASSERT_STRUCT_OFFSET(sentient_s, meleeAttackerSpot, 0x40);
	ASSERT_STRUCT_OFFSET(sentient_s, attackerAccuracy, 0x50);
	ASSERT_STRUCT_OFFSET(sentient_s, ignoreRandomBulletDamage, 0x54);
	ASSERT_STRUCT_OFFSET(sentient_s, turretInvulnerability, 0x55);
	ASSERT_STRUCT_OFFSET(sentient_s, pClaimedNode, 0x58);
	ASSERT_STRUCT_OFFSET(sentient_s, pPrevClaimedNode, 0x5C);
	ASSERT_STRUCT_OFFSET(sentient_s, pActualChainPos, 0x60);
	ASSERT_STRUCT_OFFSET(sentient_s, iActualChainPosTime, 0x64);
	ASSERT_STRUCT_OFFSET(sentient_s, pNearestNode, 0x68);
	ASSERT_STRUCT_OFFSET(sentient_s, bNearestNodeValid, 0x6C);
	ASSERT_STRUCT_OFFSET(sentient_s, bNearestNodeBad, 0x6D);
	ASSERT_STRUCT_OFFSET(sentient_s, vNearestNodeCheckPos, 0x70);
	ASSERT_STRUCT_OFFSET(sentient_s, inuse, 0x7C);
	ASSERT_STRUCT_OFFSET(sentient_s, banNodeTime, 0x80);
	ASSERT_STRUCT_OFFSET(sentient_s, bInMeleeCharge, 0x84);

	struct actorState_s
	{
		int actorIndex; //OFS: 0x0 SIZE: 0x4
		int entityNum; //OFS: 0x4 SIZE: 0x4
		team_t team; //OFS: 0x8 SIZE: 0x4
		int modelindex; //OFS: 0xC SIZE: 0x4
		int attachModelIndex[6]; //OFS: 0x10 SIZE: 0x18
		int attachTagIndex[6]; //OFS: 0x28 SIZE: 0x18
		char name[32]; //OFS: 0x40 SIZE: 0x20
		int attachedEntNum; //OFS: 0x60 SIZE: 0x4
		int attachedTagIndex; //OFS: 0x64 SIZE: 0x4
		int animScriptedAnim; //OFS: 0x68 SIZE: 0x4
		int hudwarningType; //OFS: 0x6C SIZE: 0x4
		int lookAtEntNum; //OFS: 0x70 SIZE: 0x4
		int lastLookAtEntNum; //OFS: 0x74 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(actorState_s, 0x78);
	ASSERT_STRUCT_OFFSET(actorState_s, actorIndex, 0x0);
	ASSERT_STRUCT_OFFSET(actorState_s, entityNum, 0x4);
	ASSERT_STRUCT_OFFSET(actorState_s, team, 0x8);
	ASSERT_STRUCT_OFFSET(actorState_s, modelindex, 0xC);
	ASSERT_STRUCT_OFFSET(actorState_s, attachModelIndex, 0x10);
	ASSERT_STRUCT_OFFSET(actorState_s, attachTagIndex, 0x28);
	ASSERT_STRUCT_OFFSET(actorState_s, name, 0x40);
	ASSERT_STRUCT_OFFSET(actorState_s, attachedEntNum, 0x60);
	ASSERT_STRUCT_OFFSET(actorState_s, attachedTagIndex, 0x64);
	ASSERT_STRUCT_OFFSET(actorState_s, animScriptedAnim, 0x68);
	ASSERT_STRUCT_OFFSET(actorState_s, hudwarningType, 0x6C);
	ASSERT_STRUCT_OFFSET(actorState_s, lookAtEntNum, 0x70);
	ASSERT_STRUCT_OFFSET(actorState_s, lastLookAtEntNum, 0x74);

	struct ai_transition_cmd_t
	{
		ai_state_transition_t eTransition; //OFS: 0x0 SIZE: 0x4
		ai_state_t eState; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ai_transition_cmd_t, 0x8);
	ASSERT_STRUCT_OFFSET(ai_transition_cmd_t, eTransition, 0x0);
	ASSERT_STRUCT_OFFSET(ai_transition_cmd_t, eState, 0x4);

	struct __declspec(align(2)) ActorAnimSets
	{
		unsigned __int16 aimLow; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 aimLevel; //OFS: 0x2 SIZE: 0x2
		unsigned __int16 aimHigh; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 shootLow; //OFS: 0x6 SIZE: 0x2
		unsigned __int16 shootLevel; //OFS: 0x8 SIZE: 0x2
		unsigned __int16 shootHigh; //OFS: 0xA SIZE: 0x2
		unsigned __int16 animProneLow; //OFS: 0xC SIZE: 0x2
		unsigned __int16 animProneLevel; //OFS: 0xE SIZE: 0x2
		unsigned __int16 animProneHigh; //OFS: 0x10 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(ActorAnimSets, 0x12);
	ASSERT_STRUCT_OFFSET(ActorAnimSets, aimLow, 0x0);
	ASSERT_STRUCT_OFFSET(ActorAnimSets, aimLevel, 0x2);
	ASSERT_STRUCT_OFFSET(ActorAnimSets, aimHigh, 0x4);
	ASSERT_STRUCT_OFFSET(ActorAnimSets, shootLow, 0x6);
	ASSERT_STRUCT_OFFSET(ActorAnimSets, shootLevel, 0x8);
	ASSERT_STRUCT_OFFSET(ActorAnimSets, shootHigh, 0xA);
	ASSERT_STRUCT_OFFSET(ActorAnimSets, animProneLow, 0xC);
	ASSERT_STRUCT_OFFSET(ActorAnimSets, animProneLevel, 0xE);
	ASSERT_STRUCT_OFFSET(ActorAnimSets, animProneHigh, 0x10);

	struct ActorCachedInfo
	{
		int time; //OFS: 0x0 SIZE: 0x4
		float pos[3]; //OFS: 0x4 SIZE: 0xC
		float dir[3]; //OFS: 0x10 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(ActorCachedInfo, 0x1C);
	ASSERT_STRUCT_OFFSET(ActorCachedInfo, time, 0x0);
	ASSERT_STRUCT_OFFSET(ActorCachedInfo, pos, 0x4);
	ASSERT_STRUCT_OFFSET(ActorCachedInfo, dir, 0x10);

	struct ActorLookAtInfo
	{
		float vLookAtPos[3]; //OFS: 0x0 SIZE: 0xC
		float fLookAtTurnAngle; //OFS: 0xC SIZE: 0x4
		float fLookAtTurnSpeed; //OFS: 0x10 SIZE: 0x4
		float fLookAtTurnAccel; //OFS: 0x14 SIZE: 0x4
		float fLookAtAnimYawLimit; //OFS: 0x18 SIZE: 0x4
		float fLookAtYawLimit; //OFS: 0x1C SIZE: 0x4
		unsigned __int16 animLookAtStraight; //OFS: 0x20 SIZE: 0x2
		unsigned __int16 animLookAtLeft; //OFS: 0x22 SIZE: 0x2
		unsigned __int16 animLookAtRight; //OFS: 0x24 SIZE: 0x2
		bool bDoLookAt; //OFS: 0x26 SIZE: 0x1
		bool bLookAtSetup; //OFS: 0x27 SIZE: 0x1
		int iLookAtBlendEndTime; //OFS: 0x28 SIZE: 0x4
		float fLookAtAnimBlendRate; //OFS: 0x2C SIZE: 0x4
		float fLookAtLimitBlendRate; //OFS: 0x30 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ActorLookAtInfo, 0x34);
	ASSERT_STRUCT_OFFSET(ActorLookAtInfo, vLookAtPos, 0x0);
	ASSERT_STRUCT_OFFSET(ActorLookAtInfo, fLookAtTurnAngle, 0xC);
	ASSERT_STRUCT_OFFSET(ActorLookAtInfo, fLookAtTurnSpeed, 0x10);
	ASSERT_STRUCT_OFFSET(ActorLookAtInfo, fLookAtTurnAccel, 0x14);
	ASSERT_STRUCT_OFFSET(ActorLookAtInfo, fLookAtAnimYawLimit, 0x18);
	ASSERT_STRUCT_OFFSET(ActorLookAtInfo, fLookAtYawLimit, 0x1C);
	ASSERT_STRUCT_OFFSET(ActorLookAtInfo, animLookAtStraight, 0x20);
	ASSERT_STRUCT_OFFSET(ActorLookAtInfo, animLookAtLeft, 0x22);
	ASSERT_STRUCT_OFFSET(ActorLookAtInfo, animLookAtRight, 0x24);
	ASSERT_STRUCT_OFFSET(ActorLookAtInfo, bDoLookAt, 0x26);
	ASSERT_STRUCT_OFFSET(ActorLookAtInfo, bLookAtSetup, 0x27);
	ASSERT_STRUCT_OFFSET(ActorLookAtInfo, iLookAtBlendEndTime, 0x28);
	ASSERT_STRUCT_OFFSET(ActorLookAtInfo, fLookAtAnimBlendRate, 0x2C);
	ASSERT_STRUCT_OFFSET(ActorLookAtInfo, fLookAtLimitBlendRate, 0x30);

	struct visitor_base_t
	{
		void * __vftable; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(visitor_base_t, 0x4);
	ASSERT_STRUCT_OFFSET(visitor_base_t, __vftable, 0x0);

	struct hybrid_vector
	{
		float vec[4]; //OFS: 0x0 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(hybrid_vector, 0x10);
	ASSERT_STRUCT_OFFSET(hybrid_vector, vec, 0x0);

	struct colgeom_visitor_t
	{
		visitor_base_t baseclass_0; //OFS: 0x0 SIZE: 0x4
		hybrid_vector m_mn; //OFS: 0x4 SIZE: 0x10
		hybrid_vector m_mx; //OFS: 0x14 SIZE: 0x10
		hybrid_vector m_p0; //OFS: 0x24 SIZE: 0x10
		hybrid_vector m_p1; //OFS: 0x34 SIZE: 0x10
		hybrid_vector m_delta; //OFS: 0x44 SIZE: 0x10
		hybrid_vector m_rvec; //OFS: 0x54 SIZE: 0x10
		float m_radius; //OFS: 0x64 SIZE: 0x4
		int m_mask; //OFS: 0x68 SIZE: 0x4
		void * m_threadInfo; //OFS: 0x6C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(colgeom_visitor_t, 0x70);
	ASSERT_STRUCT_OFFSET(colgeom_visitor_t, baseclass_0, 0x0);
	ASSERT_STRUCT_OFFSET(colgeom_visitor_t, m_mn, 0x4);
	ASSERT_STRUCT_OFFSET(colgeom_visitor_t, m_mx, 0x14);
	ASSERT_STRUCT_OFFSET(colgeom_visitor_t, m_p0, 0x24);
	ASSERT_STRUCT_OFFSET(colgeom_visitor_t, m_p1, 0x34);
	ASSERT_STRUCT_OFFSET(colgeom_visitor_t, m_delta, 0x44);
	ASSERT_STRUCT_OFFSET(colgeom_visitor_t, m_rvec, 0x54);
	ASSERT_STRUCT_OFFSET(colgeom_visitor_t, m_radius, 0x64);
	ASSERT_STRUCT_OFFSET(colgeom_visitor_t, m_mask, 0x68);
	ASSERT_STRUCT_OFFSET(colgeom_visitor_t, m_threadInfo, 0x6C);

	union col_prim_t_u
	{
		const CollisionAabbTree * tree; //OFS: 0x0 SIZE: 0x4
		const cbrush_t * brush; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(col_prim_t_u, 0x4);

	struct col_prim_t
	{
		int type; //OFS: 0x0 SIZE: 0x4
		col_prim_t_u u; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(col_prim_t, 0x8);
	ASSERT_STRUCT_OFFSET(col_prim_t, type, 0x0);
	ASSERT_STRUCT_OFFSET(col_prim_t, u, 0x4);

	struct colgeom_visitor_inlined_t
	{
		colgeom_visitor_t baseclass_0; //OFS: 0x0 SIZE: 0x70
		int nprims; //OFS: 0x70 SIZE: 0x4
		col_prim_t prims[200]; //OFS: 0x74 SIZE: 0x640
	};
	ASSERT_STRUCT_SIZE(colgeom_visitor_inlined_t, 0x6B4);
	ASSERT_STRUCT_OFFSET(colgeom_visitor_inlined_t, baseclass_0, 0x0);
	ASSERT_STRUCT_OFFSET(colgeom_visitor_inlined_t, nprims, 0x70);
	ASSERT_STRUCT_OFFSET(colgeom_visitor_inlined_t, prims, 0x74);

	struct actor_physics_t
	{
		float vOrigin[3]; //OFS: 0x0 SIZE: 0xC
		float vVelocity[3]; //OFS: 0xC SIZE: 0xC
		__int16 groundEntNum; //OFS: 0x18 SIZE: 0x2
		int iFootstepTimer; //OFS: 0x1C SIZE: 0x4
		int bHasGroundPlane; //OFS: 0x20 SIZE: 0x4
		int groundplaneSlope; //OFS: 0x24 SIZE: 0x4
		int iSurfaceType; //OFS: 0x28 SIZE: 0x4
		float vWishDelta[3]; //OFS: 0x2C SIZE: 0xC
		int bIsAlive; //OFS: 0x38 SIZE: 0x4
		int iEntNum; //OFS: 0x3C SIZE: 0x4
		int ePhysicsType; //OFS: 0x40 SIZE: 0x4
		float fGravity; //OFS: 0x44 SIZE: 0x4
		int iMsec; //OFS: 0x48 SIZE: 0x4
		float vMins[3]; //OFS: 0x4C SIZE: 0xC
		float vMaxs[3]; //OFS: 0x58 SIZE: 0xC
		bool prone; //OFS: 0x64 SIZE: 0x1
		int iTraceMask; //OFS: 0x68 SIZE: 0x4
		int foliageSoundTime; //OFS: 0x6C SIZE: 0x4
		int iNumTouch; //OFS: 0x70 SIZE: 0x4
		int iTouchEnts[32]; //OFS: 0x74 SIZE: 0x80
		int iHitEntnum; //OFS: 0xF4 SIZE: 0x4
		float vHitOrigin[2]; //OFS: 0xF8 SIZE: 0x8
		float vHitNormal[2]; //OFS: 0x100 SIZE: 0x8
		unsigned __int8 bStuck; //OFS: 0x108 SIZE: 0x1
		unsigned __int8 bDeflected; //OFS: 0x109 SIZE: 0x1
		colgeom_visitor_inlined_t proximity_data; //OFS: 0x10C SIZE: 0x6B4
	};
	ASSERT_STRUCT_SIZE(actor_physics_t, 0x7C0);
	ASSERT_STRUCT_OFFSET(actor_physics_t, vOrigin, 0x0);
	ASSERT_STRUCT_OFFSET(actor_physics_t, vVelocity, 0xC);
	ASSERT_STRUCT_OFFSET(actor_physics_t, groundEntNum, 0x18);
	ASSERT_STRUCT_OFFSET(actor_physics_t, iFootstepTimer, 0x1C);
	ASSERT_STRUCT_OFFSET(actor_physics_t, bHasGroundPlane, 0x20);
	ASSERT_STRUCT_OFFSET(actor_physics_t, groundplaneSlope, 0x24);
	ASSERT_STRUCT_OFFSET(actor_physics_t, iSurfaceType, 0x28);
	ASSERT_STRUCT_OFFSET(actor_physics_t, vWishDelta, 0x2C);
	ASSERT_STRUCT_OFFSET(actor_physics_t, bIsAlive, 0x38);
	ASSERT_STRUCT_OFFSET(actor_physics_t, iEntNum, 0x3C);
	ASSERT_STRUCT_OFFSET(actor_physics_t, ePhysicsType, 0x40);
	ASSERT_STRUCT_OFFSET(actor_physics_t, fGravity, 0x44);
	ASSERT_STRUCT_OFFSET(actor_physics_t, iMsec, 0x48);
	ASSERT_STRUCT_OFFSET(actor_physics_t, vMins, 0x4C);
	ASSERT_STRUCT_OFFSET(actor_physics_t, vMaxs, 0x58);
	ASSERT_STRUCT_OFFSET(actor_physics_t, prone, 0x64);
	ASSERT_STRUCT_OFFSET(actor_physics_t, iTraceMask, 0x68);
	ASSERT_STRUCT_OFFSET(actor_physics_t, foliageSoundTime, 0x6C);
	ASSERT_STRUCT_OFFSET(actor_physics_t, iNumTouch, 0x70);
	ASSERT_STRUCT_OFFSET(actor_physics_t, iTouchEnts, 0x74);
	ASSERT_STRUCT_OFFSET(actor_physics_t, iHitEntnum, 0xF4);
	ASSERT_STRUCT_OFFSET(actor_physics_t, vHitOrigin, 0xF8);
	ASSERT_STRUCT_OFFSET(actor_physics_t, vHitNormal, 0x100);
	ASSERT_STRUCT_OFFSET(actor_physics_t, bStuck, 0x108);
	ASSERT_STRUCT_OFFSET(actor_physics_t, bDeflected, 0x109);
	ASSERT_STRUCT_OFFSET(actor_physics_t, proximity_data, 0x10C);

	struct pathpoint_t
	{
		float vOrigPoint[3]; //OFS: 0x0 SIZE: 0xC
		float fDir2D[2]; //OFS: 0xC SIZE: 0x8
		float fOrigLength; //OFS: 0x14 SIZE: 0x4
		int iNodeNum; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(pathpoint_t, 0x1C);
	ASSERT_STRUCT_OFFSET(pathpoint_t, vOrigPoint, 0x0);
	ASSERT_STRUCT_OFFSET(pathpoint_t, fDir2D, 0xC);
	ASSERT_STRUCT_OFFSET(pathpoint_t, fOrigLength, 0x14);
	ASSERT_STRUCT_OFFSET(pathpoint_t, iNodeNum, 0x18);

	struct path_t
	{
		pathpoint_t pts[32]; //OFS: 0x0 SIZE: 0x380
		__int16 wPathLen; //OFS: 0x380 SIZE: 0x2
		__int16 wOrigPathLen; //OFS: 0x382 SIZE: 0x2
		__int16 wDodgeCount; //OFS: 0x384 SIZE: 0x2
		__int16 wNegotiationStartNode; //OFS: 0x386 SIZE: 0x2
		__int16 lookaheadNextNode; //OFS: 0x388 SIZE: 0x2
		__int16 wDodgeEntity; //OFS: 0x38A SIZE: 0x2
		float vFinalGoal[3]; //OFS: 0x38C SIZE: 0xC
		float lookaheadDir[3]; //OFS: 0x398 SIZE: 0xC
		float forwardLookaheadDir2D[2]; //OFS: 0x3A4 SIZE: 0x8
		float fLookaheadDist; //OFS: 0x3AC SIZE: 0x4
		float fLookaheadAmount; //OFS: 0x3B0 SIZE: 0x4
		float fLookaheadDistToNextNode; //OFS: 0x3B4 SIZE: 0x4
		int minLookAheadNodes; //OFS: 0x3B8 SIZE: 0x4
		int flags; //OFS: 0x3BC SIZE: 0x4
		int iPathTime; //OFS: 0x3C0 SIZE: 0x4
		team_t eTeam; //OFS: 0x3C4 SIZE: 0x4
		float fCurrLength; //OFS: 0x3C8 SIZE: 0x4
		float vCurrPoint[3]; //OFS: 0x3CC SIZE: 0xC
		int iPathEndTime; //OFS: 0x3D8 SIZE: 0x4
		float pathEndAnimDistSq; //OFS: 0x3DC SIZE: 0x4
		int pathEndAnimNotified; //OFS: 0x3E0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(path_t, 0x3E4);
	ASSERT_STRUCT_OFFSET(path_t, pts, 0x0);
	ASSERT_STRUCT_OFFSET(path_t, wPathLen, 0x380);
	ASSERT_STRUCT_OFFSET(path_t, wOrigPathLen, 0x382);
	ASSERT_STRUCT_OFFSET(path_t, wDodgeCount, 0x384);
	ASSERT_STRUCT_OFFSET(path_t, wNegotiationStartNode, 0x386);
	ASSERT_STRUCT_OFFSET(path_t, lookaheadNextNode, 0x388);
	ASSERT_STRUCT_OFFSET(path_t, wDodgeEntity, 0x38A);
	ASSERT_STRUCT_OFFSET(path_t, vFinalGoal, 0x38C);
	ASSERT_STRUCT_OFFSET(path_t, lookaheadDir, 0x398);
	ASSERT_STRUCT_OFFSET(path_t, forwardLookaheadDir2D, 0x3A4);
	ASSERT_STRUCT_OFFSET(path_t, fLookaheadDist, 0x3AC);
	ASSERT_STRUCT_OFFSET(path_t, fLookaheadAmount, 0x3B0);
	ASSERT_STRUCT_OFFSET(path_t, fLookaheadDistToNextNode, 0x3B4);
	ASSERT_STRUCT_OFFSET(path_t, minLookAheadNodes, 0x3B8);
	ASSERT_STRUCT_OFFSET(path_t, flags, 0x3BC);
	ASSERT_STRUCT_OFFSET(path_t, iPathTime, 0x3C0);
	ASSERT_STRUCT_OFFSET(path_t, eTeam, 0x3C4);
	ASSERT_STRUCT_OFFSET(path_t, fCurrLength, 0x3C8);
	ASSERT_STRUCT_OFFSET(path_t, vCurrPoint, 0x3CC);
	ASSERT_STRUCT_OFFSET(path_t, iPathEndTime, 0x3D8);
	ASSERT_STRUCT_OFFSET(path_t, pathEndAnimDistSq, 0x3DC);
	ASSERT_STRUCT_OFFSET(path_t, pathEndAnimNotified, 0x3E0);

	struct path_trim_t
	{
		int iIndex; //OFS: 0x0 SIZE: 0x4
		int iDelta; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(path_trim_t, 0x8);
	ASSERT_STRUCT_OFFSET(path_trim_t, iIndex, 0x0);
	ASSERT_STRUCT_OFFSET(path_trim_t, iDelta, 0x4);

	struct actor_goal_s
	{
		float pos[3]; //OFS: 0x0 SIZE: 0xC
		float ang[3]; //OFS: 0xC SIZE: 0xC
		float radius; //OFS: 0x18 SIZE: 0x4
		float height; //OFS: 0x1C SIZE: 0x4
		pathnode_t * node; //OFS: 0x20 SIZE: 0x4
		gentity_s * volume; //OFS: 0x24 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(actor_goal_s, 0x28);
	ASSERT_STRUCT_OFFSET(actor_goal_s, pos, 0x0);
	ASSERT_STRUCT_OFFSET(actor_goal_s, ang, 0xC);
	ASSERT_STRUCT_OFFSET(actor_goal_s, radius, 0x18);
	ASSERT_STRUCT_OFFSET(actor_goal_s, height, 0x1C);
	ASSERT_STRUCT_OFFSET(actor_goal_s, node, 0x20);
	ASSERT_STRUCT_OFFSET(actor_goal_s, volume, 0x24);

	struct ActorCoverArrivalInfo
	{
		int arrivalNotifyRequested; //OFS: 0x0 SIZE: 0x4
		int animscriptOverrideRunTo; //OFS: 0x4 SIZE: 0x4
		float animscriptOverrideRunToPos[3]; //OFS: 0x8 SIZE: 0xC
		float animscriptOverrideOriginError[3]; //OFS: 0x14 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(ActorCoverArrivalInfo, 0x20);
	ASSERT_STRUCT_OFFSET(ActorCoverArrivalInfo, arrivalNotifyRequested, 0x0);
	ASSERT_STRUCT_OFFSET(ActorCoverArrivalInfo, animscriptOverrideRunTo, 0x4);
	ASSERT_STRUCT_OFFSET(ActorCoverArrivalInfo, animscriptOverrideRunToPos, 0x8);
	ASSERT_STRUCT_OFFSET(ActorCoverArrivalInfo, animscriptOverrideOriginError, 0x14);

	struct vis_cache_t
	{
		bool bVisible; //OFS: 0x0 SIZE: 0x1
		int iLastUpdateTime; //OFS: 0x4 SIZE: 0x4
		int iLastVisTime; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(vis_cache_t, 0xC);
	ASSERT_STRUCT_OFFSET(vis_cache_t, bVisible, 0x0);
	ASSERT_STRUCT_OFFSET(vis_cache_t, iLastUpdateTime, 0x4);
	ASSERT_STRUCT_OFFSET(vis_cache_t, iLastVisTime, 0x8);

	struct sentient_info_t
	{
		vis_cache_t VisCache; //OFS: 0x0 SIZE: 0xC
		int iLastAttackMeTime; //OFS: 0xC SIZE: 0x4
		int lastKnownPosTime; //OFS: 0x10 SIZE: 0x4
		int attackTime; //OFS: 0x14 SIZE: 0x4
		float vLastKnownPos[3]; //OFS: 0x18 SIZE: 0xC
		pathnode_t * pLastKnownNode; //OFS: 0x24 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(sentient_info_t, 0x28);
	ASSERT_STRUCT_OFFSET(sentient_info_t, VisCache, 0x0);
	ASSERT_STRUCT_OFFSET(sentient_info_t, iLastAttackMeTime, 0xC);
	ASSERT_STRUCT_OFFSET(sentient_info_t, lastKnownPosTime, 0x10);
	ASSERT_STRUCT_OFFSET(sentient_info_t, attackTime, 0x14);
	ASSERT_STRUCT_OFFSET(sentient_info_t, vLastKnownPos, 0x18);
	ASSERT_STRUCT_OFFSET(sentient_info_t, pLastKnownNode, 0x24);

	struct ai_suppression_t
	{
		int iTime; //OFS: 0x0 SIZE: 0x4
		sentient_s * pSuppressor; //OFS: 0x4 SIZE: 0x4
		float clipPlane[3]; //OFS: 0x8 SIZE: 0xC
		int movementOnly; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ai_suppression_t, 0x18);
	ASSERT_STRUCT_OFFSET(ai_suppression_t, iTime, 0x0);
	ASSERT_STRUCT_OFFSET(ai_suppression_t, pSuppressor, 0x4);
	ASSERT_STRUCT_OFFSET(ai_suppression_t, clipPlane, 0x8);
	ASSERT_STRUCT_OFFSET(ai_suppression_t, movementOnly, 0x14);

	struct potential_threat_t
	{
		bool isEnabled; //OFS: 0x0 SIZE: 0x1
		float direction[2]; //OFS: 0x4 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(potential_threat_t, 0xC);
	ASSERT_STRUCT_OFFSET(potential_threat_t, isEnabled, 0x0);
	ASSERT_STRUCT_OFFSET(potential_threat_t, direction, 0x4);

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

	struct actor_s
	{
		gentity_s * ent; //OFS: 0x0 SIZE: 0x4
		sentient_s * sentient; //OFS: 0x4 SIZE: 0x4
		AISpecies species; //OFS: 0x8 SIZE: 0x4
		actorState_s as; //OFS: 0xC SIZE: 0x78
		_BYTE gap84[40]; //OFS: 0x84 SIZE: 0x28
		_BYTE gapAC[716]; //OFS: 0xAC SIZE: 0x2CC
		_BYTE gap_378[2068]; //OFS: 0x378 SIZE: 0x814
		ai_state_t eState[5]; //OFS: 0xB8C SIZE: 0x14
		ai_substate_t eSubState[5]; //OFS: 0xBA0 SIZE: 0x14
		int stateLevel; //OFS: 0xBB4 SIZE: 0x4
		int iStateTime; //OFS: 0xBB8 SIZE: 0x4
		int preThinkTime; //OFS: 0xBBC SIZE: 0x4
		ai_transition_cmd_t StateTransitions[11]; //OFS: 0xBC0 SIZE: 0x58
		int transitionCount; //OFS: 0xC18 SIZE: 0x4
		ai_state_t eSimulatedState[5]; //OFS: 0xC1C SIZE: 0x14
		int simulatedStateLevel; //OFS: 0xC30 SIZE: 0x4
		int iPainTime; //OFS: 0xC34 SIZE: 0x4
		char allowPain; //OFS: 0xC38 SIZE: 0x1
		char allowDeath; //OFS: 0xC39 SIZE: 0x1
		char delayedDeath; //OFS: 0xC3A SIZE: 0x1
		char provideCoveringFire; //OFS: 0xC3B SIZE: 0x1
		int accuracy; //OFS: 0xC3C SIZE: 0x4
		int playerSightAccuracy; //OFS: 0xC40 SIZE: 0x4
		int missCount; //OFS: 0xC44 SIZE: 0x4
		int hitCount; //OFS: 0xC48 SIZE: 0x4
		int debugLastAccuracy; //OFS: 0xC4C SIZE: 0x4
		int lastShotTime; //OFS: 0xC50 SIZE: 0x4
		__int16 properName; //OFS: 0xC54 SIZE: 0x2
		__int16 weaponName; //OFS: 0xC56 SIZE: 0x2
		int iTraceCount; //OFS: 0xC58 SIZE: 0x4
		int fLookPitch; //OFS: 0xC5C SIZE: 0x4
		int fLookYaw; //OFS: 0xC60 SIZE: 0x4
		float vLookForward[3]; //OFS: 0xC64 SIZE: 0xC
		float vLookRight[3]; //OFS: 0xC70 SIZE: 0xC
		float vLookUp[3]; //OFS: 0xC7C SIZE: 0xC
		ai_orient_t CodeOrient; //OFS: 0xC88 SIZE: 0x10
		ai_orient_t ScriptOrient; //OFS: 0xC98 SIZE: 0x10
		float fDesiredBodyYaw; //OFS: 0xCA8 SIZE: 0x4
		ActorAnimSets animSets; //OFS: 0xCAC SIZE: 0x12
		__int16 anim_pose; //OFS: 0xCBE SIZE: 0x2
		int fInvProneAnimLowPitch; //OFS: 0xCC0 SIZE: 0x4
		int fInvProneAnimHighPitch; //OFS: 0xCC4 SIZE: 0x4
		float fProneLastDiff; //OFS: 0xCC8 SIZE: 0x4
		int bProneOK; //OFS: 0xCCC SIZE: 0x4
		actor_prone_info_s ProneInfo; //OFS: 0xCD0 SIZE: 0x18
		ActorCachedInfo eyeInfo; //OFS: 0xCE8 SIZE: 0x1C
		ActorCachedInfo muzzleInfo; //OFS: 0xD04 SIZE: 0x1C
		ActorLookAtInfo lookAtInfo; //OFS: 0xD20 SIZE: 0x34
		int iDamageTaken; //OFS: 0xD54 SIZE: 0x4
		int iDamageYaw; //OFS: 0xD58 SIZE: 0x4
		float damageDir[3]; //OFS: 0xD5C SIZE: 0xC
		__int16 damageHitLoc; //OFS: 0xD68 SIZE: 0x2
		__int16 damageWeapon; //OFS: 0xD6A SIZE: 0x2
		__int16 damageMod; //OFS: 0xD6C SIZE: 0x2
		ai_stance_e eAllowedStances; //OFS: 0xD70 SIZE: 0x4
		__int16 AnimScriptHandle; //OFS: 0xD74 SIZE: 0x2
		scr_animscript_t * pAnimScriptFunc; //OFS: 0xD78 SIZE: 0x4
		scr_animscript_t AnimScriptSpecific; //OFS: 0xD7C SIZE: 0x8
		ai_traverse_mode_t eTraverseMode; //OFS: 0xD84 SIZE: 0x4
		unsigned __int8 moveMode; //OFS: 0xD88 SIZE: 0x1
		bool safeToChangeScript; //OFS: 0xD89 SIZE: 0x1
		char bUseGoalWeight; //OFS: 0xD8A SIZE: 0x1
		ai_animmode_t eAnimMode; //OFS: 0xD8C SIZE: 0x4
		ai_animmode_t eScriptSetAnimMode; //OFS: 0xD90 SIZE: 0x4
		actor_physics_t Physics; //OFS: 0xD94 SIZE: 0x7C0
		path_t Path; //OFS: 0x1554 SIZE: 0x3E4
		float fWalkDist; //OFS: 0x1938 SIZE: 0x4
		path_trim_t TrimInfo; //OFS: 0x193C SIZE: 0x8
		int iFollowMin; //OFS: 0x1944 SIZE: 0x4
		int iFollowMax; //OFS: 0x1948 SIZE: 0x4
		float fInterval; //OFS: 0x194C SIZE: 0x4
		int pathWaitTime; //OFS: 0x1950 SIZE: 0x4
		int iTeamMoveWaitTime; //OFS: 0x1954 SIZE: 0x4
		int iTeamMoveDodgeTime; //OFS: 0x1958 SIZE: 0x4
		int pPileUpActor; //OFS: 0x195C SIZE: 0x4
		int pPileUpEnt; //OFS: 0x1960 SIZE: 0x4
		int bDontAvoidPlayer; //OFS: 0x1964 SIZE: 0x4
		__int16 chainFallback; //OFS: 0x1968 SIZE: 0x2
		int sideMove; //OFS: 0x196C SIZE: 0x4
		__int8 keepClaimedNode; //OFS: 0x1970 SIZE: 0x1
		__int8 keepClaimedNodeInGoal; //OFS: 0x1971 SIZE: 0x1
		unsigned __int8 keepNodeDuringScriptedAnim; //OFS: 0x1972 SIZE: 0x1
		bool noDodgeMove; //OFS: 0x1973 SIZE: 0x1
		int mayMoveTime; //OFS: 0x1974 SIZE: 0x4
		float prevMoveDir[2]; //OFS: 0x1978 SIZE: 0x8
		float leanAmount; //OFS: 0x1980 SIZE: 0x4
		int exposedStartTime; //OFS: 0x1984 SIZE: 0x4
		int exposedDuration; //OFS: 0x1988 SIZE: 0x4
		actor_goal_s codeGoal; //OFS: 0x198C SIZE: 0x28
		aiGoalSources codeGoalSrc; //OFS: 0x19B4 SIZE: 0x4
		actor_goal_s scriptGoal; //OFS: 0x19B8 SIZE: 0x28
		EntHandle scriptGoalEnt; //OFS: 0x19E0 SIZE: 0x4
		float pathEnemyLookahead; //OFS: 0x19E4 SIZE: 0x4
		float pathEnemyFightDist; //OFS: 0x19E8 SIZE: 0x4
		float meleeAttackDist; //OFS: 0x19EC SIZE: 0x4
		bool useEnemyGoal; //OFS: 0x19F0 SIZE: 0x1
		bool useMeleeAttackSpot; //OFS: 0x19F1 SIZE: 0x1
		bool goalPosChanged; //OFS: 0x19F2 SIZE: 0x1
		bool commitToFixedNode; //OFS: 0x19F3 SIZE: 0x1
		bool ignoreForFixedNodeSafeCheck; //OFS: 0x19F4 SIZE: 0x1
		bool fixedNode; //OFS: 0x19F5 SIZE: 0x1
		float fixedNodeSafeRadius; //OFS: 0x19F8 SIZE: 0x4
		float fixedNodeSafeVolumeRadiusSq; //OFS: 0x19FC SIZE: 0x4
		EntHandle fixedNodeSafeVolume; //OFS: 0x1A00 SIZE: 0x4
		int bNotifyTurnDone; //OFS: 0x1A04 SIZE: 0x4
		pathnode_t * pDesiredChainPos; //OFS: 0x1A08 SIZE: 0x4
		ActorCoverArrivalInfo arrivalInfo; //OFS: 0x1A0C SIZE: 0x20
		int bPacifist; //OFS: 0x1A2C SIZE: 0x4
		int iPacifistWait; //OFS: 0x1A30 SIZE: 0x4
		int numCoverNodesInGoal; //OFS: 0x1A34 SIZE: 0x4
		int iPotentialCoverNodeCount; //OFS: 0x1A38 SIZE: 0x4
		pathnode_t * pPotentialReacquireNode[10]; //OFS: 0x1A3C SIZE: 0x28
		int iPotentialReacquireNodeCount; //OFS: 0x1A64 SIZE: 0x4
		float engageMinDist; //OFS: 0x1A68 SIZE: 0x4
		float engageMinFalloffDist; //OFS: 0x1A6C SIZE: 0x4
		float engageMaxDist; //OFS: 0x1A70 SIZE: 0x4
		float engageMaxFalloffDist; //OFS: 0x1A74 SIZE: 0x4
		scr_animscript_t * pAttackScriptFunc; //OFS: 0x1A78 SIZE: 0x4
		float fovDot; //OFS: 0x1A7C SIZE: 0x4
		float fMaxSightDistSqrd; //OFS: 0x1A80 SIZE: 0x4
		int ignoreCloseFoliage; //OFS: 0x1A84 SIZE: 0x4
		sentient_info_t sentientInfo[36]; //OFS: 0x1A88 SIZE: 0x5A0
		SentientHandle pFavoriteEnemy; //OFS: 0x2028 SIZE: 0x4
		int talkToSpecies; //OFS: 0x202C SIZE: 0x4
		float lastEnemySightPos[3]; //OFS: 0x2030 SIZE: 0xC
		bool lastEnemySightPosValid; //OFS: 0x203C SIZE: 0x1
		float anglesToLikelyEnemyPath[3]; //OFS: 0x2040 SIZE: 0xC
		int faceLikelyEnemyPathNeedCheckTime; //OFS: 0x204C SIZE: 0x4
		int faceLikelyEnemyPathNeedRecalculateTime; //OFS: 0x2050 SIZE: 0x4
		pathnode_t * faceLikelyEnemyPathNode; //OFS: 0x2054 SIZE: 0x4
		ai_suppression_t Suppressant[4]; //OFS: 0x2058 SIZE: 0x60
		int ignoreSuppression; //OFS: 0x20B8 SIZE: 0x4
		int suppressionWait; //OFS: 0x20BC SIZE: 0x4
		int suppressionDuration; //OFS: 0x20C0 SIZE: 0x4
		int suppressionStartTime; //OFS: 0x20C4 SIZE: 0x4
		float suppressionMeter; //OFS: 0x20C8 SIZE: 0x4
		potential_threat_t potentialThreat; //OFS: 0x20CC SIZE: 0xC
		int threatUpdateTime; //OFS: 0x20D8 SIZE: 0x4
		int hasThreateningEnemy; //OFS: 0x20DC SIZE: 0x4
		float grenadeAwareness; //OFS: 0x20E0 SIZE: 0x4
		int bThrowbackGrenades; //OFS: 0x20E4 SIZE: 0x4
		EntHandle pGrenade; //OFS: 0x20E8 SIZE: 0x4
		int iGrenadeWeaponIndex; //OFS: 0x20EC SIZE: 0x4
		unsigned __int16 GrenadeTossMethod; //OFS: 0x20F0 SIZE: 0x2
		int bGrenadeTossValid; //OFS: 0x20F4 SIZE: 0x4
		int bGrenadeTargetValid; //OFS: 0x20F8 SIZE: 0x4
		int iGrenadeAmmo; //OFS: 0x20FC SIZE: 0x4
		float vGrenadeTossPos[3]; //OFS: 0x2100 SIZE: 0xC
		float vGrenadeTargetPos[3]; //OFS: 0x210C SIZE: 0xC
		float vGrenadeTossVel[3]; //OFS: 0x2118 SIZE: 0xC
		int bDropWeapon; //OFS: 0x2124 SIZE: 0x4
		int bDrawOnCompass; //OFS: 0x2128 SIZE: 0x4
		int bActivateCrosshair; //OFS: 0x212C SIZE: 0x4
		int iUseHintString; //OFS: 0x2130 SIZE: 0x4
		gentity_s * pTurret; //OFS: 0x2134 SIZE: 0x4
		unsigned __int16 turretAnim; //OFS: 0x2138 SIZE: 0x2
		unsigned __int8 turretAnimSet; //OFS: 0x213A SIZE: 0x1
		unsigned __int8 useable; //OFS: 0x213B SIZE: 0x1
		char ignoreTriggers; //OFS: 0x213C SIZE: 0x1
		bool pushable; //OFS: 0x213D SIZE: 0x1
		int inuse; //OFS: 0x2140 SIZE: 0x4
		ai_badplace_t aiBadPlace; //OFS: 0x2144 SIZE: 0x4
		float badPlaceAwareness; //OFS: 0x2148 SIZE: 0x4
		float goodShootPos[3]; //OFS: 0x214C SIZE: 0xC
		int goodShootPosValid; //OFS: 0x2158 SIZE: 0x4
		__int16 scriptState; //OFS: 0x215C SIZE: 0x2
		unsigned __int16 lastScriptState; //OFS: 0x215E SIZE: 0x2
		__int16 stateChangeReason; //OFS: 0x2160 SIZE: 0x2
		EntHandle pCloseEnt; //OFS: 0x2162 SIZE: 0x4
		int moveHistoryIndex; //OFS: 0x2168 SIZE: 0x4
		float moveHistory[10][2]; //OFS: 0x216C SIZE: 0x50
		EntHandle throwBackGrenadeKilledOriginalOwner; //OFS: 0x21BC SIZE: 0x4
		int flashBanged; //OFS: 0x21C0 SIZE: 0x4
		float flashBangedStrength; //OFS: 0x21C4 SIZE: 0x4
		int flashBangImmunity; //OFS: 0x21C8 SIZE: 0x4
		char * pszDebugInfo; //OFS: 0x21CC SIZE: 0x4
		pathnode_t * pPotentialCoverNode[1000]; //OFS: 0x21D0 SIZE: 0xFA0
		unsigned __int16 vis_blockers[36]; //OFS: 0x3170 SIZE: 0x48
	};
	ASSERT_STRUCT_SIZE(actor_s, 0x31B8);
	ASSERT_STRUCT_OFFSET(actor_s, ent, 0x0);
	ASSERT_STRUCT_OFFSET(actor_s, sentient, 0x4);
	ASSERT_STRUCT_OFFSET(actor_s, species, 0x8);
	ASSERT_STRUCT_OFFSET(actor_s, as, 0xC);
	ASSERT_STRUCT_OFFSET(actor_s, gap84, 0x84);
	ASSERT_STRUCT_OFFSET(actor_s, gapAC, 0xAC);
	ASSERT_STRUCT_OFFSET(actor_s, gap_378, 0x378);
	ASSERT_STRUCT_OFFSET(actor_s, eState, 0xB8C);
	ASSERT_STRUCT_OFFSET(actor_s, eSubState, 0xBA0);
	ASSERT_STRUCT_OFFSET(actor_s, stateLevel, 0xBB4);
	ASSERT_STRUCT_OFFSET(actor_s, iStateTime, 0xBB8);
	ASSERT_STRUCT_OFFSET(actor_s, preThinkTime, 0xBBC);
	ASSERT_STRUCT_OFFSET(actor_s, StateTransitions, 0xBC0);
	ASSERT_STRUCT_OFFSET(actor_s, transitionCount, 0xC18);
	ASSERT_STRUCT_OFFSET(actor_s, eSimulatedState, 0xC1C);
	ASSERT_STRUCT_OFFSET(actor_s, simulatedStateLevel, 0xC30);
	ASSERT_STRUCT_OFFSET(actor_s, iPainTime, 0xC34);
	ASSERT_STRUCT_OFFSET(actor_s, allowPain, 0xC38);
	ASSERT_STRUCT_OFFSET(actor_s, allowDeath, 0xC39);
	ASSERT_STRUCT_OFFSET(actor_s, delayedDeath, 0xC3A);
	ASSERT_STRUCT_OFFSET(actor_s, provideCoveringFire, 0xC3B);
	ASSERT_STRUCT_OFFSET(actor_s, accuracy, 0xC3C);
	ASSERT_STRUCT_OFFSET(actor_s, playerSightAccuracy, 0xC40);
	ASSERT_STRUCT_OFFSET(actor_s, missCount, 0xC44);
	ASSERT_STRUCT_OFFSET(actor_s, hitCount, 0xC48);
	ASSERT_STRUCT_OFFSET(actor_s, debugLastAccuracy, 0xC4C);
	ASSERT_STRUCT_OFFSET(actor_s, lastShotTime, 0xC50);
	ASSERT_STRUCT_OFFSET(actor_s, properName, 0xC54);
	ASSERT_STRUCT_OFFSET(actor_s, weaponName, 0xC56);
	ASSERT_STRUCT_OFFSET(actor_s, iTraceCount, 0xC58);
	ASSERT_STRUCT_OFFSET(actor_s, fLookPitch, 0xC5C);
	ASSERT_STRUCT_OFFSET(actor_s, fLookYaw, 0xC60);
	ASSERT_STRUCT_OFFSET(actor_s, vLookForward, 0xC64);
	ASSERT_STRUCT_OFFSET(actor_s, vLookRight, 0xC70);
	ASSERT_STRUCT_OFFSET(actor_s, vLookUp, 0xC7C);
	ASSERT_STRUCT_OFFSET(actor_s, CodeOrient, 0xC88);
	ASSERT_STRUCT_OFFSET(actor_s, ScriptOrient, 0xC98);
	ASSERT_STRUCT_OFFSET(actor_s, fDesiredBodyYaw, 0xCA8);
	ASSERT_STRUCT_OFFSET(actor_s, animSets, 0xCAC);
	ASSERT_STRUCT_OFFSET(actor_s, anim_pose, 0xCBE);
	ASSERT_STRUCT_OFFSET(actor_s, fInvProneAnimLowPitch, 0xCC0);
	ASSERT_STRUCT_OFFSET(actor_s, fInvProneAnimHighPitch, 0xCC4);
	ASSERT_STRUCT_OFFSET(actor_s, fProneLastDiff, 0xCC8);
	ASSERT_STRUCT_OFFSET(actor_s, bProneOK, 0xCCC);
	ASSERT_STRUCT_OFFSET(actor_s, ProneInfo, 0xCD0);
	ASSERT_STRUCT_OFFSET(actor_s, eyeInfo, 0xCE8);
	ASSERT_STRUCT_OFFSET(actor_s, muzzleInfo, 0xD04);
	ASSERT_STRUCT_OFFSET(actor_s, lookAtInfo, 0xD20);
	ASSERT_STRUCT_OFFSET(actor_s, iDamageTaken, 0xD54);
	ASSERT_STRUCT_OFFSET(actor_s, iDamageYaw, 0xD58);
	ASSERT_STRUCT_OFFSET(actor_s, damageDir, 0xD5C);
	ASSERT_STRUCT_OFFSET(actor_s, damageHitLoc, 0xD68);
	ASSERT_STRUCT_OFFSET(actor_s, damageWeapon, 0xD6A);
	ASSERT_STRUCT_OFFSET(actor_s, damageMod, 0xD6C);
	ASSERT_STRUCT_OFFSET(actor_s, eAllowedStances, 0xD70);
	ASSERT_STRUCT_OFFSET(actor_s, AnimScriptHandle, 0xD74);
	ASSERT_STRUCT_OFFSET(actor_s, pAnimScriptFunc, 0xD78);
	ASSERT_STRUCT_OFFSET(actor_s, AnimScriptSpecific, 0xD7C);
	ASSERT_STRUCT_OFFSET(actor_s, eTraverseMode, 0xD84);
	ASSERT_STRUCT_OFFSET(actor_s, moveMode, 0xD88);
	ASSERT_STRUCT_OFFSET(actor_s, safeToChangeScript, 0xD89);
	ASSERT_STRUCT_OFFSET(actor_s, bUseGoalWeight, 0xD8A);
	ASSERT_STRUCT_OFFSET(actor_s, eAnimMode, 0xD8C);
	ASSERT_STRUCT_OFFSET(actor_s, eScriptSetAnimMode, 0xD90);
	ASSERT_STRUCT_OFFSET(actor_s, Physics, 0xD94);
	ASSERT_STRUCT_OFFSET(actor_s, Path, 0x1554);
	ASSERT_STRUCT_OFFSET(actor_s, fWalkDist, 0x1938);
	ASSERT_STRUCT_OFFSET(actor_s, TrimInfo, 0x193C);
	ASSERT_STRUCT_OFFSET(actor_s, iFollowMin, 0x1944);
	ASSERT_STRUCT_OFFSET(actor_s, iFollowMax, 0x1948);
	ASSERT_STRUCT_OFFSET(actor_s, fInterval, 0x194C);
	ASSERT_STRUCT_OFFSET(actor_s, pathWaitTime, 0x1950);
	ASSERT_STRUCT_OFFSET(actor_s, iTeamMoveWaitTime, 0x1954);
	ASSERT_STRUCT_OFFSET(actor_s, iTeamMoveDodgeTime, 0x1958);
	ASSERT_STRUCT_OFFSET(actor_s, pPileUpActor, 0x195C);
	ASSERT_STRUCT_OFFSET(actor_s, pPileUpEnt, 0x1960);
	ASSERT_STRUCT_OFFSET(actor_s, bDontAvoidPlayer, 0x1964);
	ASSERT_STRUCT_OFFSET(actor_s, chainFallback, 0x1968);
	ASSERT_STRUCT_OFFSET(actor_s, sideMove, 0x196C);
	ASSERT_STRUCT_OFFSET(actor_s, keepClaimedNode, 0x1970);
	ASSERT_STRUCT_OFFSET(actor_s, keepClaimedNodeInGoal, 0x1971);
	ASSERT_STRUCT_OFFSET(actor_s, keepNodeDuringScriptedAnim, 0x1972);
	ASSERT_STRUCT_OFFSET(actor_s, noDodgeMove, 0x1973);
	ASSERT_STRUCT_OFFSET(actor_s, mayMoveTime, 0x1974);
	ASSERT_STRUCT_OFFSET(actor_s, prevMoveDir, 0x1978);
	ASSERT_STRUCT_OFFSET(actor_s, leanAmount, 0x1980);
	ASSERT_STRUCT_OFFSET(actor_s, exposedStartTime, 0x1984);
	ASSERT_STRUCT_OFFSET(actor_s, exposedDuration, 0x1988);
	ASSERT_STRUCT_OFFSET(actor_s, codeGoal, 0x198C);
	ASSERT_STRUCT_OFFSET(actor_s, codeGoalSrc, 0x19B4);
	ASSERT_STRUCT_OFFSET(actor_s, scriptGoal, 0x19B8);
	ASSERT_STRUCT_OFFSET(actor_s, scriptGoalEnt, 0x19E0);
	ASSERT_STRUCT_OFFSET(actor_s, pathEnemyLookahead, 0x19E4);
	ASSERT_STRUCT_OFFSET(actor_s, pathEnemyFightDist, 0x19E8);
	ASSERT_STRUCT_OFFSET(actor_s, meleeAttackDist, 0x19EC);
	ASSERT_STRUCT_OFFSET(actor_s, useEnemyGoal, 0x19F0);
	ASSERT_STRUCT_OFFSET(actor_s, useMeleeAttackSpot, 0x19F1);
	ASSERT_STRUCT_OFFSET(actor_s, goalPosChanged, 0x19F2);
	ASSERT_STRUCT_OFFSET(actor_s, commitToFixedNode, 0x19F3);
	ASSERT_STRUCT_OFFSET(actor_s, ignoreForFixedNodeSafeCheck, 0x19F4);
	ASSERT_STRUCT_OFFSET(actor_s, fixedNode, 0x19F5);
	ASSERT_STRUCT_OFFSET(actor_s, fixedNodeSafeRadius, 0x19F8);
	ASSERT_STRUCT_OFFSET(actor_s, fixedNodeSafeVolumeRadiusSq, 0x19FC);
	ASSERT_STRUCT_OFFSET(actor_s, fixedNodeSafeVolume, 0x1A00);
	ASSERT_STRUCT_OFFSET(actor_s, bNotifyTurnDone, 0x1A04);
	ASSERT_STRUCT_OFFSET(actor_s, pDesiredChainPos, 0x1A08);
	ASSERT_STRUCT_OFFSET(actor_s, arrivalInfo, 0x1A0C);
	ASSERT_STRUCT_OFFSET(actor_s, bPacifist, 0x1A2C);
	ASSERT_STRUCT_OFFSET(actor_s, iPacifistWait, 0x1A30);
	ASSERT_STRUCT_OFFSET(actor_s, numCoverNodesInGoal, 0x1A34);
	ASSERT_STRUCT_OFFSET(actor_s, iPotentialCoverNodeCount, 0x1A38);
	ASSERT_STRUCT_OFFSET(actor_s, pPotentialReacquireNode, 0x1A3C);
	ASSERT_STRUCT_OFFSET(actor_s, iPotentialReacquireNodeCount, 0x1A64);
	ASSERT_STRUCT_OFFSET(actor_s, engageMinDist, 0x1A68);
	ASSERT_STRUCT_OFFSET(actor_s, engageMinFalloffDist, 0x1A6C);
	ASSERT_STRUCT_OFFSET(actor_s, engageMaxDist, 0x1A70);
	ASSERT_STRUCT_OFFSET(actor_s, engageMaxFalloffDist, 0x1A74);
	ASSERT_STRUCT_OFFSET(actor_s, pAttackScriptFunc, 0x1A78);
	ASSERT_STRUCT_OFFSET(actor_s, fovDot, 0x1A7C);
	ASSERT_STRUCT_OFFSET(actor_s, fMaxSightDistSqrd, 0x1A80);
	ASSERT_STRUCT_OFFSET(actor_s, ignoreCloseFoliage, 0x1A84);
	ASSERT_STRUCT_OFFSET(actor_s, sentientInfo, 0x1A88);
	ASSERT_STRUCT_OFFSET(actor_s, pFavoriteEnemy, 0x2028);
	ASSERT_STRUCT_OFFSET(actor_s, talkToSpecies, 0x202C);
	ASSERT_STRUCT_OFFSET(actor_s, lastEnemySightPos, 0x2030);
	ASSERT_STRUCT_OFFSET(actor_s, lastEnemySightPosValid, 0x203C);
	ASSERT_STRUCT_OFFSET(actor_s, anglesToLikelyEnemyPath, 0x2040);
	ASSERT_STRUCT_OFFSET(actor_s, faceLikelyEnemyPathNeedCheckTime, 0x204C);
	ASSERT_STRUCT_OFFSET(actor_s, faceLikelyEnemyPathNeedRecalculateTime, 0x2050);
	ASSERT_STRUCT_OFFSET(actor_s, faceLikelyEnemyPathNode, 0x2054);
	ASSERT_STRUCT_OFFSET(actor_s, Suppressant, 0x2058);
	ASSERT_STRUCT_OFFSET(actor_s, ignoreSuppression, 0x20B8);
	ASSERT_STRUCT_OFFSET(actor_s, suppressionWait, 0x20BC);
	ASSERT_STRUCT_OFFSET(actor_s, suppressionDuration, 0x20C0);
	ASSERT_STRUCT_OFFSET(actor_s, suppressionStartTime, 0x20C4);
	ASSERT_STRUCT_OFFSET(actor_s, suppressionMeter, 0x20C8);
	ASSERT_STRUCT_OFFSET(actor_s, potentialThreat, 0x20CC);
	ASSERT_STRUCT_OFFSET(actor_s, threatUpdateTime, 0x20D8);
	ASSERT_STRUCT_OFFSET(actor_s, hasThreateningEnemy, 0x20DC);
	ASSERT_STRUCT_OFFSET(actor_s, grenadeAwareness, 0x20E0);
	ASSERT_STRUCT_OFFSET(actor_s, bThrowbackGrenades, 0x20E4);
	ASSERT_STRUCT_OFFSET(actor_s, pGrenade, 0x20E8);
	ASSERT_STRUCT_OFFSET(actor_s, iGrenadeWeaponIndex, 0x20EC);
	ASSERT_STRUCT_OFFSET(actor_s, GrenadeTossMethod, 0x20F0);
	ASSERT_STRUCT_OFFSET(actor_s, bGrenadeTossValid, 0x20F4);
	ASSERT_STRUCT_OFFSET(actor_s, bGrenadeTargetValid, 0x20F8);
	ASSERT_STRUCT_OFFSET(actor_s, iGrenadeAmmo, 0x20FC);
	ASSERT_STRUCT_OFFSET(actor_s, vGrenadeTossPos, 0x2100);
	ASSERT_STRUCT_OFFSET(actor_s, vGrenadeTargetPos, 0x210C);
	ASSERT_STRUCT_OFFSET(actor_s, vGrenadeTossVel, 0x2118);
	ASSERT_STRUCT_OFFSET(actor_s, bDropWeapon, 0x2124);
	ASSERT_STRUCT_OFFSET(actor_s, bDrawOnCompass, 0x2128);
	ASSERT_STRUCT_OFFSET(actor_s, bActivateCrosshair, 0x212C);
	ASSERT_STRUCT_OFFSET(actor_s, iUseHintString, 0x2130);
	ASSERT_STRUCT_OFFSET(actor_s, pTurret, 0x2134);
	ASSERT_STRUCT_OFFSET(actor_s, turretAnim, 0x2138);
	ASSERT_STRUCT_OFFSET(actor_s, turretAnimSet, 0x213A);
	ASSERT_STRUCT_OFFSET(actor_s, useable, 0x213B);
	ASSERT_STRUCT_OFFSET(actor_s, ignoreTriggers, 0x213C);
	ASSERT_STRUCT_OFFSET(actor_s, pushable, 0x213D);
	ASSERT_STRUCT_OFFSET(actor_s, inuse, 0x2140);
	ASSERT_STRUCT_OFFSET(actor_s, aiBadPlace, 0x2144);
	ASSERT_STRUCT_OFFSET(actor_s, badPlaceAwareness, 0x2148);
	ASSERT_STRUCT_OFFSET(actor_s, goodShootPos, 0x214C);
	ASSERT_STRUCT_OFFSET(actor_s, goodShootPosValid, 0x2158);
	ASSERT_STRUCT_OFFSET(actor_s, scriptState, 0x215C);
	ASSERT_STRUCT_OFFSET(actor_s, lastScriptState, 0x215E);
	ASSERT_STRUCT_OFFSET(actor_s, stateChangeReason, 0x2160);
	ASSERT_STRUCT_OFFSET(actor_s, pCloseEnt, 0x2162);
	ASSERT_STRUCT_OFFSET(actor_s, moveHistoryIndex, 0x2168);
	ASSERT_STRUCT_OFFSET(actor_s, moveHistory, 0x216C);
	ASSERT_STRUCT_OFFSET(actor_s, throwBackGrenadeKilledOriginalOwner, 0x21BC);
	ASSERT_STRUCT_OFFSET(actor_s, flashBanged, 0x21C0);
	ASSERT_STRUCT_OFFSET(actor_s, flashBangedStrength, 0x21C4);
	ASSERT_STRUCT_OFFSET(actor_s, flashBangImmunity, 0x21C8);
	ASSERT_STRUCT_OFFSET(actor_s, pszDebugInfo, 0x21CC);
	ASSERT_STRUCT_OFFSET(actor_s, pPotentialCoverNode, 0x21D0);
	ASSERT_STRUCT_OFFSET(actor_s, vis_blockers, 0x3170);

	struct vehicle_node_t
	{
		unsigned __int16 name; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 target; //OFS: 0x2 SIZE: 0x2
		unsigned __int16 script_linkname; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 script_noteworthy; //OFS: 0x6 SIZE: 0x2
		__int16 index; //OFS: 0x8 SIZE: 0x2
		int rotated; //OFS: 0xC SIZE: 0x4
		float speed; //OFS: 0x10 SIZE: 0x4
		float lookAhead; //OFS: 0x14 SIZE: 0x4
		float origin[3]; //OFS: 0x18 SIZE: 0xC
		float dir[3]; //OFS: 0x24 SIZE: 0xC
		float angles[3]; //OFS: 0x30 SIZE: 0xC
		float length; //OFS: 0x3C SIZE: 0x4
		__int16 nextIdx; //OFS: 0x40 SIZE: 0x2
		__int16 prevIdx; //OFS: 0x42 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(vehicle_node_t, 0x44);
	ASSERT_STRUCT_OFFSET(vehicle_node_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(vehicle_node_t, target, 0x2);
	ASSERT_STRUCT_OFFSET(vehicle_node_t, script_linkname, 0x4);
	ASSERT_STRUCT_OFFSET(vehicle_node_t, script_noteworthy, 0x6);
	ASSERT_STRUCT_OFFSET(vehicle_node_t, index, 0x8);
	ASSERT_STRUCT_OFFSET(vehicle_node_t, rotated, 0xC);
	ASSERT_STRUCT_OFFSET(vehicle_node_t, speed, 0x10);
	ASSERT_STRUCT_OFFSET(vehicle_node_t, lookAhead, 0x14);
	ASSERT_STRUCT_OFFSET(vehicle_node_t, origin, 0x18);
	ASSERT_STRUCT_OFFSET(vehicle_node_t, dir, 0x24);
	ASSERT_STRUCT_OFFSET(vehicle_node_t, angles, 0x30);
	ASSERT_STRUCT_OFFSET(vehicle_node_t, length, 0x3C);
	ASSERT_STRUCT_OFFSET(vehicle_node_t, nextIdx, 0x40);
	ASSERT_STRUCT_OFFSET(vehicle_node_t, prevIdx, 0x42);

	struct vehicle_pathpos_t
	{
		__int16 nodeIdx; //OFS: 0x0 SIZE: 0x2
		__int16 endOfPath; //OFS: 0x2 SIZE: 0x2
		float frac; //OFS: 0x4 SIZE: 0x4
		float speed; //OFS: 0x8 SIZE: 0x4
		float lookAhead; //OFS: 0xC SIZE: 0x4
		float slide; //OFS: 0x10 SIZE: 0x4
		float origin[3]; //OFS: 0x14 SIZE: 0xC
		float angles[3]; //OFS: 0x20 SIZE: 0xC
		float lookPos[3]; //OFS: 0x2C SIZE: 0xC
		vehicle_node_t switchNode[2]; //OFS: 0x38 SIZE: 0x88
	};
	ASSERT_STRUCT_SIZE(vehicle_pathpos_t, 0xC0);
	ASSERT_STRUCT_OFFSET(vehicle_pathpos_t, nodeIdx, 0x0);
	ASSERT_STRUCT_OFFSET(vehicle_pathpos_t, endOfPath, 0x2);
	ASSERT_STRUCT_OFFSET(vehicle_pathpos_t, frac, 0x4);
	ASSERT_STRUCT_OFFSET(vehicle_pathpos_t, speed, 0x8);
	ASSERT_STRUCT_OFFSET(vehicle_pathpos_t, lookAhead, 0xC);
	ASSERT_STRUCT_OFFSET(vehicle_pathpos_t, slide, 0x10);
	ASSERT_STRUCT_OFFSET(vehicle_pathpos_t, origin, 0x14);
	ASSERT_STRUCT_OFFSET(vehicle_pathpos_t, angles, 0x20);
	ASSERT_STRUCT_OFFSET(vehicle_pathpos_t, lookPos, 0x2C);
	ASSERT_STRUCT_OFFSET(vehicle_pathpos_t, switchNode, 0x38);

	struct vehicle_physic_t
	{
		float origin[3]; //OFS: 0x0 SIZE: 0xC
		float prevOrigin[3]; //OFS: 0xC SIZE: 0xC
		float angles[3]; //OFS: 0x18 SIZE: 0xC
		float prevAngles[3]; //OFS: 0x24 SIZE: 0xC
		float maxAngleVel[3]; //OFS: 0x30 SIZE: 0xC
		float yawAccel; //OFS: 0x3C SIZE: 0x4
		float yawDecel; //OFS: 0x40 SIZE: 0x4
		float mins[3]; //OFS: 0x44 SIZE: 0xC
		float maxs[3]; //OFS: 0x50 SIZE: 0xC
		float vel[3]; //OFS: 0x5C SIZE: 0xC
		float bodyVel[3]; //OFS: 0x68 SIZE: 0xC
		float rotVel[3]; //OFS: 0x74 SIZE: 0xC
		float accel[3]; //OFS: 0x80 SIZE: 0xC
		float maxPitchAngle; //OFS: 0x8C SIZE: 0x4
		float maxRollAngle; //OFS: 0x90 SIZE: 0x4
		float wheelZVel[6]; //OFS: 0x94 SIZE: 0x18
		float wheelZPos[6]; //OFS: 0xAC SIZE: 0x18
		int wheelSurfType[6]; //OFS: 0xC4 SIZE: 0x18
		float worldTilt[3]; //OFS: 0xDC SIZE: 0xC
		float worldTiltVel[3]; //OFS: 0xE8 SIZE: 0xC
		float curveLength; //OFS: 0xF4 SIZE: 0x4
		int curveID; //OFS: 0xF8 SIZE: 0x4
		float curveStep; //OFS: 0xFC SIZE: 0x4
		float curveTime; //OFS: 0x100 SIZE: 0x4
		float timeStep; //OFS: 0x104 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(vehicle_physic_t, 0x108);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, origin, 0x0);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, prevOrigin, 0xC);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, angles, 0x18);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, prevAngles, 0x24);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, maxAngleVel, 0x30);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, yawAccel, 0x3C);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, yawDecel, 0x40);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, mins, 0x44);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, maxs, 0x50);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, vel, 0x5C);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, bodyVel, 0x68);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, rotVel, 0x74);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, accel, 0x80);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, maxPitchAngle, 0x8C);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, maxRollAngle, 0x90);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, wheelZVel, 0x94);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, wheelZPos, 0xAC);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, wheelSurfType, 0xC4);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, worldTilt, 0xDC);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, worldTiltVel, 0xE8);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, curveLength, 0xF4);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, curveID, 0xF8);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, curveStep, 0xFC);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, curveTime, 0x100);
	ASSERT_STRUCT_OFFSET(vehicle_physic_t, timeStep, 0x104);

	struct VehicleTurret
	{
		int fireTime; //OFS: 0x0 SIZE: 0x4
		int fireBarrel; //OFS: 0x4 SIZE: 0x4
		float barrelOffset; //OFS: 0x8 SIZE: 0x4
		int flags; //OFS: 0xC SIZE: 0x4
		float heatVal; //OFS: 0x10 SIZE: 0x4
		int overheating; //OFS: 0x14 SIZE: 0x4
		VehicleTurretState turretState; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(VehicleTurret, 0x1C);
	ASSERT_STRUCT_OFFSET(VehicleTurret, fireTime, 0x0);
	ASSERT_STRUCT_OFFSET(VehicleTurret, fireBarrel, 0x4);
	ASSERT_STRUCT_OFFSET(VehicleTurret, barrelOffset, 0x8);
	ASSERT_STRUCT_OFFSET(VehicleTurret, flags, 0xC);
	ASSERT_STRUCT_OFFSET(VehicleTurret, heatVal, 0x10);
	ASSERT_STRUCT_OFFSET(VehicleTurret, overheating, 0x14);
	ASSERT_STRUCT_OFFSET(VehicleTurret, turretState, 0x18);

	struct VehicleJitter
	{
		int jitterPeriodMin; //OFS: 0x0 SIZE: 0x4
		int jitterPeriodMax; //OFS: 0x4 SIZE: 0x4
		int jitterEndTime; //OFS: 0x8 SIZE: 0x4
		float jitterOffsetRange[3]; //OFS: 0xC SIZE: 0xC
		float jitterDeltaAccel[3]; //OFS: 0x18 SIZE: 0xC
		float jitterAccel[3]; //OFS: 0x24 SIZE: 0xC
		float jitterPos[3]; //OFS: 0x30 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(VehicleJitter, 0x3C);
	ASSERT_STRUCT_OFFSET(VehicleJitter, jitterPeriodMin, 0x0);
	ASSERT_STRUCT_OFFSET(VehicleJitter, jitterPeriodMax, 0x4);
	ASSERT_STRUCT_OFFSET(VehicleJitter, jitterEndTime, 0x8);
	ASSERT_STRUCT_OFFSET(VehicleJitter, jitterOffsetRange, 0xC);
	ASSERT_STRUCT_OFFSET(VehicleJitter, jitterDeltaAccel, 0x18);
	ASSERT_STRUCT_OFFSET(VehicleJitter, jitterAccel, 0x24);
	ASSERT_STRUCT_OFFSET(VehicleJitter, jitterPos, 0x30);

	struct VehicleHover
	{
		float hoverRadius; //OFS: 0x0 SIZE: 0x4
		float hoverSpeed; //OFS: 0x4 SIZE: 0x4
		float hoverAccel; //OFS: 0x8 SIZE: 0x4
		float hoverGoalPos[3]; //OFS: 0xC SIZE: 0xC
		int useHoverAccelForAngles; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(VehicleHover, 0x1C);
	ASSERT_STRUCT_OFFSET(VehicleHover, hoverRadius, 0x0);
	ASSERT_STRUCT_OFFSET(VehicleHover, hoverSpeed, 0x4);
	ASSERT_STRUCT_OFFSET(VehicleHover, hoverAccel, 0x8);
	ASSERT_STRUCT_OFFSET(VehicleHover, hoverGoalPos, 0xC);
	ASSERT_STRUCT_OFFSET(VehicleHover, useHoverAccelForAngles, 0x18);

	struct VehicleTarget
	{
		int valid; //OFS: 0x0 SIZE: 0x4
		int hasTargetYaw; //OFS: 0x4 SIZE: 0x4
		int targetEnt; //OFS: 0x8 SIZE: 0x4
		int lookAtEnt; //OFS: 0xC SIZE: 0x4
		float targetOrigin[3]; //OFS: 0x10 SIZE: 0xC
		float targetOffset[3]; //OFS: 0x1C SIZE: 0xC
		float targetYaw; //OFS: 0x28 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(VehicleTarget, 0x2C);
	ASSERT_STRUCT_OFFSET(VehicleTarget, valid, 0x0);
	ASSERT_STRUCT_OFFSET(VehicleTarget, hasTargetYaw, 0x4);
	ASSERT_STRUCT_OFFSET(VehicleTarget, targetEnt, 0x8);
	ASSERT_STRUCT_OFFSET(VehicleTarget, lookAtEnt, 0xC);
	ASSERT_STRUCT_OFFSET(VehicleTarget, targetOrigin, 0x10);
	ASSERT_STRUCT_OFFSET(VehicleTarget, targetOffset, 0x1C);
	ASSERT_STRUCT_OFFSET(VehicleTarget, targetYaw, 0x28);

	struct VehicleGunnerTags
	{
		int turret; //OFS: 0x0 SIZE: 0x4
		int barrel; //OFS: 0x4 SIZE: 0x4
		int flash; //OFS: 0x8 SIZE: 0x4
		int flash2; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(VehicleGunnerTags, 0x10);
	ASSERT_STRUCT_OFFSET(VehicleGunnerTags, turret, 0x0);
	ASSERT_STRUCT_OFFSET(VehicleGunnerTags, barrel, 0x4);
	ASSERT_STRUCT_OFFSET(VehicleGunnerTags, flash, 0x8);
	ASSERT_STRUCT_OFFSET(VehicleGunnerTags, flash2, 0xC);

	struct VehicleTags
	{
		int player; //OFS: 0x0 SIZE: 0x4
		int detach; //OFS: 0x4 SIZE: 0x4
		int popout; //OFS: 0x8 SIZE: 0x4
		int body; //OFS: 0xC SIZE: 0x4
		int turret; //OFS: 0x10 SIZE: 0x4
		int turret_base; //OFS: 0x14 SIZE: 0x4
		int barrel; //OFS: 0x18 SIZE: 0x4
		int flash[5]; //OFS: 0x1C SIZE: 0x14
		VehicleGunnerTags gunnerTags[4]; //OFS: 0x30 SIZE: 0x40
		int wheel[6]; //OFS: 0x70 SIZE: 0x18
		int seats[10]; //OFS: 0x88 SIZE: 0x28
		int entryPoints[3]; //OFS: 0xB0 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(VehicleTags, 0xBC);
	ASSERT_STRUCT_OFFSET(VehicleTags, player, 0x0);
	ASSERT_STRUCT_OFFSET(VehicleTags, detach, 0x4);
	ASSERT_STRUCT_OFFSET(VehicleTags, popout, 0x8);
	ASSERT_STRUCT_OFFSET(VehicleTags, body, 0xC);
	ASSERT_STRUCT_OFFSET(VehicleTags, turret, 0x10);
	ASSERT_STRUCT_OFFSET(VehicleTags, turret_base, 0x14);
	ASSERT_STRUCT_OFFSET(VehicleTags, barrel, 0x18);
	ASSERT_STRUCT_OFFSET(VehicleTags, flash, 0x1C);
	ASSERT_STRUCT_OFFSET(VehicleTags, gunnerTags, 0x30);
	ASSERT_STRUCT_OFFSET(VehicleTags, wheel, 0x70);
	ASSERT_STRUCT_OFFSET(VehicleTags, seats, 0x88);
	ASSERT_STRUCT_OFFSET(VehicleTags, entryPoints, 0xB0);

	struct VehicleSeat
	{
		int _occupantEntNum; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(VehicleSeat, 0x4);
	ASSERT_STRUCT_OFFSET(VehicleSeat, _occupantEntNum, 0x0);

	struct Float4
	{
		float x; //OFS: 0x0 SIZE: 0x4
		float y; //OFS: 0x4 SIZE: 0x4
		float z; //OFS: 0x8 SIZE: 0x4
		float w; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(Float4, 0x10);
	ASSERT_STRUCT_OFFSET(Float4, x, 0x0);
	ASSERT_STRUCT_OFFSET(Float4, y, 0x4);
	ASSERT_STRUCT_OFFSET(Float4, z, 0x8);
	ASSERT_STRUCT_OFFSET(Float4, w, 0xC);

	struct Dir3
	{
		Float4 v; //OFS: 0x0 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(Dir3, 0x10);
	ASSERT_STRUCT_OFFSET(Dir3, v, 0x0);

	struct Position3
	{
		Float4 v; //OFS: 0x0 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(Position3, 0x10);
	ASSERT_STRUCT_OFFSET(Position3, v, 0x0);

	struct Mat43
	{
		Dir3 x; //OFS: 0x0 SIZE: 0x10
		Dir3 y; //OFS: 0x10 SIZE: 0x10
		Dir3 z; //OFS: 0x20 SIZE: 0x10
		Position3 w; //OFS: 0x30 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(Mat43, 0x40);
	ASSERT_STRUCT_OFFSET(Mat43, x, 0x0);
	ASSERT_STRUCT_OFFSET(Mat43, y, 0x10);
	ASSERT_STRUCT_OFFSET(Mat43, z, 0x20);
	ASSERT_STRUCT_OFFSET(Mat43, w, 0x30);

	struct VehicleParameter
	{
		float m_speed_max; //OFS: 0x0 SIZE: 0x4
		float m_accel_max; //OFS: 0x4 SIZE: 0x4
		float m_reverse_scale; //OFS: 0x8 SIZE: 0x4
		float m_steer_angle_max; //OFS: 0xC SIZE: 0x4
		float m_steer_speed; //OFS: 0x10 SIZE: 0x4
		float m_wheel_radius; //OFS: 0x14 SIZE: 0x4
		float m_susp_spring_k; //OFS: 0x18 SIZE: 0x4
		float m_susp_damp_k; //OFS: 0x1C SIZE: 0x4
		float m_susp_adj; //OFS: 0x20 SIZE: 0x4
		float m_susp_hard_limit; //OFS: 0x24 SIZE: 0x4
		float m_tire_fric_fwd; //OFS: 0x28 SIZE: 0x4
		float m_tire_fric_side; //OFS: 0x2C SIZE: 0x4
		float m_tire_fric_brake; //OFS: 0x30 SIZE: 0x4
		float m_tire_fric_hand_brake; //OFS: 0x34 SIZE: 0x4
		float m_body_mass; //OFS: 0x38 SIZE: 0x4
		float m_roll_stability; //OFS: 0x3C SIZE: 0x4
		float m_roll_resistance; //OFS: 0x40 SIZE: 0x4
		float m_upright_strength; //OFS: 0x44 SIZE: 0x4
		float m_tilt_fakey; //OFS: 0x48 SIZE: 0x4
		float m_peel_out_max_speed; //OFS: 0x4C SIZE: 0x4
		float m_inertia_scale_x; //OFS: 0x50 SIZE: 0x4
		float m_tire_damp_coast; //OFS: 0x54 SIZE: 0x4
		float m_tire_damp_brake; //OFS: 0x58 SIZE: 0x4
		float m_tire_damp_hand; //OFS: 0x5C SIZE: 0x4
		TractionType m_traction_type; //OFS: 0x60 SIZE: 0x4
		char m_name[64]; //OFS: 0x64 SIZE: 0x40
		float m_bbox_min[3]; //OFS: 0xA4 SIZE: 0xC
		float m_bbox_max[3]; //OFS: 0xB0 SIZE: 0xC
		float m_mass_center_offset[3]; //OFS: 0xBC SIZE: 0xC
		float m_buoyancybox_min[3]; //OFS: 0xC8 SIZE: 0xC
		float m_buoyancybox_max[3]; //OFS: 0xD4 SIZE: 0xC
		float m_water_speed_max; //OFS: 0xE0 SIZE: 0x4
		float m_water_accel_max; //OFS: 0xE4 SIZE: 0x4
		float m_water_turn_accel; //OFS: 0xE8 SIZE: 0x4
		float m_water_turn_speed_max; //OFS: 0xEC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(VehicleParameter, 0xF0);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_speed_max, 0x0);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_accel_max, 0x4);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_reverse_scale, 0x8);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_steer_angle_max, 0xC);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_steer_speed, 0x10);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_wheel_radius, 0x14);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_susp_spring_k, 0x18);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_susp_damp_k, 0x1C);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_susp_adj, 0x20);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_susp_hard_limit, 0x24);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_tire_fric_fwd, 0x28);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_tire_fric_side, 0x2C);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_tire_fric_brake, 0x30);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_tire_fric_hand_brake, 0x34);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_body_mass, 0x38);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_roll_stability, 0x3C);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_roll_resistance, 0x40);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_upright_strength, 0x44);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_tilt_fakey, 0x48);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_peel_out_max_speed, 0x4C);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_inertia_scale_x, 0x50);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_tire_damp_coast, 0x54);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_tire_damp_brake, 0x58);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_tire_damp_hand, 0x5C);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_traction_type, 0x60);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_name, 0x64);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_bbox_min, 0xA4);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_bbox_max, 0xB0);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_mass_center_offset, 0xBC);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_buoyancybox_min, 0xC8);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_buoyancybox_max, 0xD4);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_water_speed_max, 0xE0);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_water_accel_max, 0xE4);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_water_turn_accel, 0xE8);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_water_turn_speed_max, 0xEC);

	struct vehicle_info_t
	{
		char name[64]; //OFS: 0x0 SIZE: 0x40
		__int16 type; //OFS: 0x40 SIZE: 0x2
		int steerWheels; //OFS: 0x44 SIZE: 0x4
		int texScroll; //OFS: 0x48 SIZE: 0x4
		int quadBarrel; //OFS: 0x4C SIZE: 0x4
		int bulletDamage; //OFS: 0x50 SIZE: 0x4
		int armorPiercingDamage; //OFS: 0x54 SIZE: 0x4
		int grenadeDamage; //OFS: 0x58 SIZE: 0x4
		int projectileDamage; //OFS: 0x5C SIZE: 0x4
		int projectileSplashDamage; //OFS: 0x60 SIZE: 0x4
		int heavyExplosiveDamage; //OFS: 0x64 SIZE: 0x4
		int isDrivable; //OFS: 0x68 SIZE: 0x4
		int numberOfSeats; //OFS: 0x6C SIZE: 0x4
		int numberOfGunners; //OFS: 0x70 SIZE: 0x4
		int noSwitchToDriver; //OFS: 0x74 SIZE: 0x4
		int driverControlledGunPos; //OFS: 0x78 SIZE: 0x4
		float texScrollScale; //OFS: 0x7C SIZE: 0x4
		float wheelRotRate; //OFS: 0x80 SIZE: 0x4
		float maxSpeed; //OFS: 0x84 SIZE: 0x4
		float accel; //OFS: 0x88 SIZE: 0x4
		float rotRate; //OFS: 0x8C SIZE: 0x4
		float rotAccel; //OFS: 0x90 SIZE: 0x4
		float maxBodyPitch; //OFS: 0x94 SIZE: 0x4
		float maxBodyRoll; //OFS: 0x98 SIZE: 0x4
		float collisionDamage; //OFS: 0x9C SIZE: 0x4
		float collisionSpeed; //OFS: 0xA0 SIZE: 0x4
		float suspensionTravel; //OFS: 0xA4 SIZE: 0x4
		int a; //OFS: 0xA8 SIZE: 0x4
		char turretWeapon[64]; //OFS: 0xAC SIZE: 0x40
		float turretHorizSpanLeft; //OFS: 0xEC SIZE: 0x4
		float turretHorizSpanRight; //OFS: 0xF0 SIZE: 0x4
		float turretVertSpanUp; //OFS: 0xF4 SIZE: 0x4
		float turretVertSpanDown; //OFS: 0xF8 SIZE: 0x4
		float turretRotRate; //OFS: 0xFC SIZE: 0x4
		int turretClampPlayerView; //OFS: 0x100 SIZE: 0x4
		char gunnerWeapon[4][64]; //OFS: 0x104 SIZE: 0x100
		unsigned __int8 gunnerWeaponIndex[4]; //OFS: 0x204 SIZE: 0x4
		float gunnerRotRate; //OFS: 0x208 SIZE: 0x4
		float gunnerRestAngles[4][2]; //OFS: 0x20C SIZE: 0x20
		char sndNames[20][64]; //OFS: 0x22C SIZE: 0x500
		unsigned __int16 sndIndices[20]; //OFS: 0x72C SIZE: 0x28
		float engineSndSpeed; //OFS: 0x754 SIZE: 0x4
		int wheelMtrlSndCounts[2]; //OFS: 0x758 SIZE: 0x8
		float engineModLoopNaturalRPMs; //OFS: 0x760 SIZE: 0x4
		float idleRPMs; //OFS: 0x764 SIZE: 0x4
		float gear1MinRPMs; //OFS: 0x768 SIZE: 0x4
		float gear1MaxRPMs; //OFS: 0x76C SIZE: 0x4
		float gearChangeMPH; //OFS: 0x770 SIZE: 0x4
		float gear2MinRPMs; //OFS: 0x774 SIZE: 0x4
		float gear2MaxRPMs; //OFS: 0x778 SIZE: 0x4
		float engineModLoopModRate; //OFS: 0x77C SIZE: 0x4
		float engineModLoopAttenuation; //OFS: 0x780 SIZE: 0x4
		float engineModLoopCrossfadeLoadScale; //OFS: 0x784 SIZE: 0x4
		float engineModLoopCrossfadeDamageScale; //OFS: 0x788 SIZE: 0x4
		int trackLengthInches; //OFS: 0x78C SIZE: 0x4
		float clacksCurveDamageStart; //OFS: 0x790 SIZE: 0x4
		float clacksCurveDamageEnd; //OFS: 0x794 SIZE: 0x4
		float clacksCurveMaxOmitted; //OFS: 0x798 SIZE: 0x4
		float treadGrindAttenuation; //OFS: 0x79C SIZE: 0x4
		float treadDamageLoopHealthRatio; //OFS: 0x7A0 SIZE: 0x4
		int animType; //OFS: 0x7A4 SIZE: 0x4
		char animSet[64]; //OFS: 0x7A8 SIZE: 0x40
		float mantleAngles[4]; //OFS: 0x7E8 SIZE: 0x10
		char pad[16]; //OFS: 0x7F8 SIZE: 0x10
		int isNitrous; //OFS: 0x808 SIZE: 0x4
		VehicleParameter nitrousVehParams; //OFS: 0x80C SIZE: 0xF0
	};
	ASSERT_STRUCT_SIZE(vehicle_info_t, 0x8FC);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, type, 0x40);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, steerWheels, 0x44);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, texScroll, 0x48);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, quadBarrel, 0x4C);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, bulletDamage, 0x50);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, armorPiercingDamage, 0x54);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, grenadeDamage, 0x58);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, projectileDamage, 0x5C);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, projectileSplashDamage, 0x60);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, heavyExplosiveDamage, 0x64);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, isDrivable, 0x68);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, numberOfSeats, 0x6C);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, numberOfGunners, 0x70);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, noSwitchToDriver, 0x74);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, driverControlledGunPos, 0x78);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, texScrollScale, 0x7C);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, wheelRotRate, 0x80);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, maxSpeed, 0x84);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, accel, 0x88);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, rotRate, 0x8C);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, rotAccel, 0x90);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, maxBodyPitch, 0x94);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, maxBodyRoll, 0x98);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, collisionDamage, 0x9C);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, collisionSpeed, 0xA0);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, suspensionTravel, 0xA4);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, a, 0xA8);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, turretWeapon, 0xAC);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, turretHorizSpanLeft, 0xEC);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, turretHorizSpanRight, 0xF0);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, turretVertSpanUp, 0xF4);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, turretVertSpanDown, 0xF8);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, turretRotRate, 0xFC);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, turretClampPlayerView, 0x100);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, gunnerWeapon, 0x104);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, gunnerWeaponIndex, 0x204);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, gunnerRotRate, 0x208);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, gunnerRestAngles, 0x20C);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, sndNames, 0x22C);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, sndIndices, 0x72C);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, engineSndSpeed, 0x754);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, wheelMtrlSndCounts, 0x758);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, engineModLoopNaturalRPMs, 0x760);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, idleRPMs, 0x764);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, gear1MinRPMs, 0x768);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, gear1MaxRPMs, 0x76C);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, gearChangeMPH, 0x770);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, gear2MinRPMs, 0x774);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, gear2MaxRPMs, 0x778);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, engineModLoopModRate, 0x77C);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, engineModLoopAttenuation, 0x780);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, engineModLoopCrossfadeLoadScale, 0x784);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, engineModLoopCrossfadeDamageScale, 0x788);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, trackLengthInches, 0x78C);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, clacksCurveDamageStart, 0x790);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, clacksCurveDamageEnd, 0x794);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, clacksCurveMaxOmitted, 0x798);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, treadGrindAttenuation, 0x79C);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, treadDamageLoopHealthRatio, 0x7A0);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, animType, 0x7A4);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, animSet, 0x7A8);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, mantleAngles, 0x7E8);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, pad, 0x7F8);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, isNitrous, 0x808);
	ASSERT_STRUCT_OFFSET(vehicle_info_t, nitrousVehParams, 0x80C);

	struct PhysObjUserData
	{
		void * body; //OFS: 0x0 SIZE: 0x4
		NitrousVehicle * vehicle; //OFS: 0x4 SIZE: 0x4
		void * m_gjk_geom; //OFS: 0x8 SIZE: 0x4
		void * m_next_link; //OFS: 0xC SIZE: 0x4
		Mat43 cg2rb; //OFS: 0x10 SIZE: 0x40
		Mat43 cg2w; //OFS: 0x50 SIZE: 0x40
		void * m_bpb; //OFS: 0x90 SIZE: 0x4
		float savedPos[3]; //OFS: 0x94 SIZE: 0xC
		float savedRot[3][3]; //OFS: 0xA0 SIZE: 0x24
		int sndClass; //OFS: 0xC4 SIZE: 0x4
		float friction; //OFS: 0xC8 SIZE: 0x4
		float bounce; //OFS: 0xCC SIZE: 0x4
		int id; //OFS: 0xD0 SIZE: 0x4
		int refcount; //OFS: 0xD4 SIZE: 0x4
		int underwater; //OFS: 0xD8 SIZE: 0x4
		int buoyancy; //OFS: 0xDC SIZE: 0x4
		int timeBuoyant; //OFS: 0xE0 SIZE: 0x4
		int timeRipple; //OFS: 0xE4 SIZE: 0x4
		unsigned __int16 trDuration; //OFS: 0xE8 SIZE: 0x2
		float m_time_since_last_event; //OFS: 0xEC SIZE: 0x4
		float m_time_since_last_reeval; //OFS: 0xF0 SIZE: 0x4
		int m_flags; //OFS: 0xF4 SIZE: 0x4
		float mass; //OFS: 0xF8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(PhysObjUserData, 0xFC);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, body, 0x0);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, vehicle, 0x4);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, m_gjk_geom, 0x8);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, m_next_link, 0xC);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, cg2rb, 0x10);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, cg2w, 0x50);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, m_bpb, 0x90);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, savedPos, 0x94);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, savedRot, 0xA0);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, sndClass, 0xC4);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, friction, 0xC8);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, bounce, 0xCC);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, id, 0xD0);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, refcount, 0xD4);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, underwater, 0xD8);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, buoyancy, 0xDC);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, timeBuoyant, 0xE0);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, timeRipple, 0xE4);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, trDuration, 0xE8);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, m_time_since_last_event, 0xEC);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, m_time_since_last_reeval, 0xF0);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, m_flags, 0xF4);
	ASSERT_STRUCT_OFFSET(PhysObjUserData, mass, 0xF8);

	struct NitrousVehicleController
	{
		Dir3 m_script_goal_position; //OFS: 0x0 SIZE: 0x10
		float m_script_goal_radius; //OFS: 0x10 SIZE: 0x4
		float m_script_goal_speed; //OFS: 0x14 SIZE: 0x4
		float m_stuck_time; //OFS: 0x18 SIZE: 0x4
		Dir3 m_stuck_position; //OFS: 0x1C SIZE: 0x10
		usercmd_s m_cmd; //OFS: 0x2C SIZE: 0x38
		int m_cmd_local_client_num; //OFS: 0x64 SIZE: 0x4
		bool m_cmd_valid; //OFS: 0x68 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(NitrousVehicleController, 0x6C);
	ASSERT_STRUCT_OFFSET(NitrousVehicleController, m_script_goal_position, 0x0);
	ASSERT_STRUCT_OFFSET(NitrousVehicleController, m_script_goal_radius, 0x10);
	ASSERT_STRUCT_OFFSET(NitrousVehicleController, m_script_goal_speed, 0x14);
	ASSERT_STRUCT_OFFSET(NitrousVehicleController, m_stuck_time, 0x18);
	ASSERT_STRUCT_OFFSET(NitrousVehicleController, m_stuck_position, 0x1C);
	ASSERT_STRUCT_OFFSET(NitrousVehicleController, m_cmd, 0x2C);
	ASSERT_STRUCT_OFFSET(NitrousVehicleController, m_cmd_local_client_num, 0x64);
	ASSERT_STRUCT_OFFSET(NitrousVehicleController, m_cmd_valid, 0x68);

	struct NitrousVehicle
	{
		WheelEffectState m_wheel_effect_state[4]; //OFS: 0x0 SIZE: 0x10
		Mat43 m_wheel_orig_relpo[6]; //OFS: 0x10 SIZE: 0x180
		int m_wheel_damage[6]; //OFS: 0x190 SIZE: 0x18
		int m_wheel_surf_types[6]; //OFS: 0x1A8 SIZE: 0x18
		VehicleParameter * m_parameter; //OFS: 0x1C0 SIZE: 0x4
		float m_throttle; //OFS: 0x1C4 SIZE: 0x4
		float m_brake; //OFS: 0x1C8 SIZE: 0x4
		float m_hand_brake; //OFS: 0x1CC SIZE: 0x4
		float m_script_brake; //OFS: 0x1D0 SIZE: 0x4
		float m_steer_factor; //OFS: 0x1D4 SIZE: 0x4
		float m_forward_vel; //OFS: 0x1D8 SIZE: 0x4
		float m_hand_brake_friction_time; //OFS: 0x1DC SIZE: 0x4
		gentity_s * m_owner; //OFS: 0x1E0 SIZE: 0x4
		int m_entnum; //OFS: 0x1E4 SIZE: 0x4
		vehicle_info_t * m_vehicle_info; //OFS: 0x1E8 SIZE: 0x4
		PhysObjUserData * m_phys_user_data; //OFS: 0x1EC SIZE: 0x4
		XModel * m_xmodel; //OFS: 0x1F0 SIZE: 0x4
		float m_origin[3]; //OFS: 0x1F4 SIZE: 0xC
		float m_angles[3]; //OFS: 0x200 SIZE: 0xC
		void * m_orientation_constraint; //OFS: 0x20C SIZE: 0x4
		void * m_vpc; //OFS: 0x210 SIZE: 0x4
		int m_flags; //OFS: 0x214 SIZE: 0x4
		Mat43 m_prev_rb_mat; //OFS: 0x218 SIZE: 0x40
		NitrousVehicleController mVehicleController; //OFS: 0x258 SIZE: 0x6C
		float m_fake_rpm; //OFS: 0x2C4 SIZE: 0x4
		int m_num_colliding_wheels; //OFS: 0x2C8 SIZE: 0x4
		float m_current_side_fric_scale; //OFS: 0x2CC SIZE: 0x4
		float m_current_fwd_fric_scale; //OFS: 0x2D0 SIZE: 0x4
		float m_stuck_time; //OFS: 0x2D4 SIZE: 0x4
		int m_lastNetworkTime; //OFS: 0x2D8 SIZE: 0x4
		int m_lastErrorReductionTime; //OFS: 0x2DC SIZE: 0x4
		float m_networkErrorOrigin[3]; //OFS: 0x2E0 SIZE: 0xC
		float m_networkErrorAngles[3]; //OFS: 0x2EC SIZE: 0xC
		int m_trackDistAccumLeftInches; //OFS: 0x2F8 SIZE: 0x4
		int m_trackDistAccumRightInches; //OFS: 0x2FC SIZE: 0x4
		int m_sfx_state_flags; //OFS: 0x300 SIZE: 0x4
		float m_speed_scale; //OFS: 0x304 SIZE: 0x4
		int m_boost_start_time; //OFS: 0x308 SIZE: 0x4
		int b[3]; //OFS: 0x30C SIZE: 0xC
		int id; //OFS: 0x318 SIZE: 0x4
		int refcount; //OFS: 0x31C SIZE: 0x4
		void * m_wheels[6]; //OFS: 0x320 SIZE: 0x18
		float m_desired_speed_factor; //OFS: 0x338 SIZE: 0x4
		float m_acceleration_factor; //OFS: 0x33C SIZE: 0x4
		float m_power_braking_factor; //OFS: 0x340 SIZE: 0x4
		float m_braking_factor; //OFS: 0x344 SIZE: 0x4
		float m_coasting_factor; //OFS: 0x348 SIZE: 0x4
		float m_reference_wheel_radius; //OFS: 0x34C SIZE: 0x4
		float m_steer_current_angle; //OFS: 0x350 SIZE: 0x4
		float m_steer_max_angle; //OFS: 0x354 SIZE: 0x4
		float m_steer_speed; //OFS: 0x358 SIZE: 0x4
		Dir3 m_steer_front_pt_loc; //OFS: 0x35C SIZE: 0x10
		float m_steer_front_back_length; //OFS: 0x36C SIZE: 0x4
		unsigned int m_state_flags; //OFS: 0x370 SIZE: 0x4
		void * m_vci; //OFS: 0x374 SIZE: 0x4
		int a[2]; //OFS: 0x378 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(NitrousVehicle, 0x380);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_wheel_effect_state, 0x0);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_wheel_orig_relpo, 0x10);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_wheel_damage, 0x190);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_wheel_surf_types, 0x1A8);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_parameter, 0x1C0);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_throttle, 0x1C4);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_brake, 0x1C8);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_hand_brake, 0x1CC);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_script_brake, 0x1D0);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_steer_factor, 0x1D4);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_forward_vel, 0x1D8);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_hand_brake_friction_time, 0x1DC);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_owner, 0x1E0);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_entnum, 0x1E4);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_vehicle_info, 0x1E8);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_phys_user_data, 0x1EC);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_xmodel, 0x1F0);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_origin, 0x1F4);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_angles, 0x200);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_orientation_constraint, 0x20C);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_vpc, 0x210);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_flags, 0x214);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_prev_rb_mat, 0x218);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, mVehicleController, 0x258);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_fake_rpm, 0x2C4);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_num_colliding_wheels, 0x2C8);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_current_side_fric_scale, 0x2CC);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_current_fwd_fric_scale, 0x2D0);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_stuck_time, 0x2D4);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_lastNetworkTime, 0x2D8);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_lastErrorReductionTime, 0x2DC);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_networkErrorOrigin, 0x2E0);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_networkErrorAngles, 0x2EC);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_trackDistAccumLeftInches, 0x2F8);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_trackDistAccumRightInches, 0x2FC);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_sfx_state_flags, 0x300);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_speed_scale, 0x304);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_boost_start_time, 0x308);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, b, 0x30C);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, id, 0x318);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, refcount, 0x31C);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_wheels, 0x320);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_desired_speed_factor, 0x338);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_acceleration_factor, 0x33C);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_power_braking_factor, 0x340);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_braking_factor, 0x344);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_coasting_factor, 0x348);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_reference_wheel_radius, 0x34C);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_steer_current_angle, 0x350);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_steer_max_angle, 0x354);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_steer_speed, 0x358);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_steer_front_pt_loc, 0x35C);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_steer_front_back_length, 0x36C);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_state_flags, 0x370);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, m_vci, 0x374);
	ASSERT_STRUCT_OFFSET(NitrousVehicle, a, 0x378);

	struct __declspec(align(8)) vehicle_cache_t
	{
		float lastOrigin[3]; //OFS: 0x0 SIZE: 0xC
		float lastAngles[3]; //OFS: 0xC SIZE: 0xC
		int hit_indices[6]; //OFS: 0x18 SIZE: 0x18
		int hit_sflags[6]; //OFS: 0x30 SIZE: 0x18
		float hit_normals[6][3]; //OFS: 0x48 SIZE: 0x48
		float hit_fractions[6]; //OFS: 0x90 SIZE: 0x18
		colgeom_visitor_inlined_t proximity_data; //OFS: 0xA8 SIZE: 0x6B4
		int wheel_mask; //OFS: 0x75C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(vehicle_cache_t, 0x760);
	ASSERT_STRUCT_OFFSET(vehicle_cache_t, lastOrigin, 0x0);
	ASSERT_STRUCT_OFFSET(vehicle_cache_t, lastAngles, 0xC);
	ASSERT_STRUCT_OFFSET(vehicle_cache_t, hit_indices, 0x18);
	ASSERT_STRUCT_OFFSET(vehicle_cache_t, hit_sflags, 0x30);
	ASSERT_STRUCT_OFFSET(vehicle_cache_t, hit_normals, 0x48);
	ASSERT_STRUCT_OFFSET(vehicle_cache_t, hit_fractions, 0x90);
	ASSERT_STRUCT_OFFSET(vehicle_cache_t, proximity_data, 0xA8);
	ASSERT_STRUCT_OFFSET(vehicle_cache_t, wheel_mask, 0x75C);

	struct __declspec(align(8)) scr_vehicle_s
	{
		vehicle_pathpos_t pathPos; //OFS: 0x0 SIZE: 0xC0
		vehicle_physic_t phys; //OFS: 0xC0 SIZE: 0x108
		int entNum; //OFS: 0x1C8 SIZE: 0x4
		__int16 infoIdx; //OFS: 0x1CC SIZE: 0x2
		int flags; //OFS: 0x1D0 SIZE: 0x4
		int team; //OFS: 0x1D4 SIZE: 0x4
		VehicleMoveState moveState; //OFS: 0x1D8 SIZE: 0x4
		__int16 waitNode; //OFS: 0x1DC SIZE: 0x2
		float waitSpeed; //OFS: 0x1E0 SIZE: 0x4
		VehicleTurret turret; //OFS: 0x1E4 SIZE: 0x1C
		float turretRotScale; //OFS: 0x200 SIZE: 0x4
		VehicleJitter jitter; //OFS: 0x204 SIZE: 0x3C
		VehicleHover hover; //OFS: 0x240 SIZE: 0x1C
		VehicleTurret gunnerTurrets[4]; //OFS: 0x25C SIZE: 0x70
		VehicleJitter gunnerJitter[4]; //OFS: 0x2CC SIZE: 0xF0
		unsigned __int16 lookAtText0; //OFS: 0x3BC SIZE: 0x2
		unsigned __int16 lookAtText1; //OFS: 0x3BE SIZE: 0x2
		int manualMode; //OFS: 0x3C0 SIZE: 0x4
		float manualSpeed; //OFS: 0x3C4 SIZE: 0x4
		float manualAccel; //OFS: 0x3C8 SIZE: 0x4
		float manualDecel; //OFS: 0x3CC SIZE: 0x4
		float manualTime; //OFS: 0x3D0 SIZE: 0x4
		float speed; //OFS: 0x3D4 SIZE: 0x4
		float maxSpeedOverride; //OFS: 0x3D8 SIZE: 0x4
		float maxDragSpeed; //OFS: 0x3DC SIZE: 0x4
		float turningAbility; //OFS: 0x3E0 SIZE: 0x4
		int hasTarget; //OFS: 0x3E4 SIZE: 0x4
		int hasTargetYaw; //OFS: 0x3E8 SIZE: 0x4
		int hasGoalYaw; //OFS: 0x3EC SIZE: 0x4
		int stopAtGoal; //OFS: 0x3F0 SIZE: 0x4
		int stopping; //OFS: 0x3F4 SIZE: 0x4
		int targetEnt; //OFS: 0x3F8 SIZE: 0x4
		EntHandle lookAtEnt; //OFS: 0x3FC SIZE: 0x4
		float targetOrigin[3]; //OFS: 0x400 SIZE: 0xC
		float targetOffset[3]; //OFS: 0x40C SIZE: 0xC
		float targetYaw; //OFS: 0x418 SIZE: 0x4
		float goalPosition[3]; //OFS: 0x41C SIZE: 0xC
		float goalYaw; //OFS: 0x428 SIZE: 0x4
		float prevGoalYaw; //OFS: 0x42C SIZE: 0x4
		float yawOverShoot; //OFS: 0x430 SIZE: 0x4
		int yawSlowDown; //OFS: 0x434 SIZE: 0x4
		float hasGoalRoll; //OFS: 0x438 SIZE: 0x4
		float goalRoll; //OFS: 0x43C SIZE: 0x4
		float goalRollTime; //OFS: 0x440 SIZE: 0x4
		float currentRollTime; //OFS: 0x444 SIZE: 0x4
		int numRolls; //OFS: 0x448 SIZE: 0x4
		VehicleTarget gunnerTargets[4]; //OFS: 0x44C SIZE: 0xB0
		float nearGoalNotifyDist; //OFS: 0x4FC SIZE: 0x4
		float joltDir[2]; //OFS: 0x500 SIZE: 0x8
		float joltTime; //OFS: 0x508 SIZE: 0x4
		float joltWave; //OFS: 0x50C SIZE: 0x4
		float joltSpeed; //OFS: 0x510 SIZE: 0x4
		float joltDecel; //OFS: 0x514 SIZE: 0x4
		VehicleTags boneIndex; //OFS: 0x518 SIZE: 0xBC
		int turretHitNum; //OFS: 0x5D4 SIZE: 0x4
		VehicleSeat seats[8]; //OFS: 0x5D8 SIZE: 0x20
		float forcedMaterialSpeed; //OFS: 0x5F8 SIZE: 0x4
		NitrousVehicle * nitrousVehicle; //OFS: 0x5FC SIZE: 0x4
		vehicle_cache_t vehicle_cache; //OFS: 0x600 SIZE: 0x760
	};
	ASSERT_STRUCT_SIZE(scr_vehicle_s, 0xD60);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, pathPos, 0x0);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, phys, 0xC0);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, entNum, 0x1C8);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, infoIdx, 0x1CC);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, flags, 0x1D0);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, team, 0x1D4);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, moveState, 0x1D8);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, waitNode, 0x1DC);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, waitSpeed, 0x1E0);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, turret, 0x1E4);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, turretRotScale, 0x200);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, jitter, 0x204);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, hover, 0x240);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, gunnerTurrets, 0x25C);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, gunnerJitter, 0x2CC);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, lookAtText0, 0x3BC);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, lookAtText1, 0x3BE);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, manualMode, 0x3C0);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, manualSpeed, 0x3C4);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, manualAccel, 0x3C8);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, manualDecel, 0x3CC);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, manualTime, 0x3D0);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, speed, 0x3D4);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, maxSpeedOverride, 0x3D8);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, maxDragSpeed, 0x3DC);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, turningAbility, 0x3E0);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, hasTarget, 0x3E4);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, hasTargetYaw, 0x3E8);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, hasGoalYaw, 0x3EC);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, stopAtGoal, 0x3F0);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, stopping, 0x3F4);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, targetEnt, 0x3F8);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, lookAtEnt, 0x3FC);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, targetOrigin, 0x400);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, targetOffset, 0x40C);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, targetYaw, 0x418);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, goalPosition, 0x41C);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, goalYaw, 0x428);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, prevGoalYaw, 0x42C);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, yawOverShoot, 0x430);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, yawSlowDown, 0x434);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, hasGoalRoll, 0x438);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, goalRoll, 0x43C);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, goalRollTime, 0x440);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, currentRollTime, 0x444);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, numRolls, 0x448);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, gunnerTargets, 0x44C);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, nearGoalNotifyDist, 0x4FC);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, joltDir, 0x500);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, joltTime, 0x508);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, joltWave, 0x50C);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, joltSpeed, 0x510);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, joltDecel, 0x514);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, boneIndex, 0x518);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, turretHitNum, 0x5D4);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, seats, 0x5D8);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, forcedMaterialSpeed, 0x5F8);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, nitrousVehicle, 0x5FC);
	ASSERT_STRUCT_OFFSET(scr_vehicle_s, vehicle_cache, 0x600);

	struct TurretInfo
	{
		bool inuse; //OFS: 0x0 SIZE: 0x1
		int state; //OFS: 0x4 SIZE: 0x4
		int flags; //OFS: 0x8 SIZE: 0x4
		int fireTime; //OFS: 0xC SIZE: 0x4
		EntHandle manualTarget; //OFS: 0x10 SIZE: 0x4
		EntHandle target; //OFS: 0x14 SIZE: 0x4
		float targetPos[3]; //OFS: 0x18 SIZE: 0xC
		int targetTime; //OFS: 0x24 SIZE: 0x4
		float missOffsetNormalized[3]; //OFS: 0x28 SIZE: 0xC
		float arcmin[2]; //OFS: 0x34 SIZE: 0x8
		float arcmax[2]; //OFS: 0x3C SIZE: 0x8
		float initialYawmin; //OFS: 0x44 SIZE: 0x4
		float initialYawmax; //OFS: 0x48 SIZE: 0x4
		float forwardAngleDot; //OFS: 0x4C SIZE: 0x4
		float dropPitch; //OFS: 0x50 SIZE: 0x4
		int convergenceTime[2]; //OFS: 0x54 SIZE: 0x8
		int suppressTime; //OFS: 0x5C SIZE: 0x4
		float maxRangeSquared; //OFS: 0x60 SIZE: 0x4
		SentientHandle detachSentient; //OFS: 0x64 SIZE: 0x4
		int stance; //OFS: 0x68 SIZE: 0x4
		int prevStance; //OFS: 0x6C SIZE: 0x4
		int fireSndDelay; //OFS: 0x70 SIZE: 0x4
		float accuracy; //OFS: 0x74 SIZE: 0x4
		float userOrigin[3]; //OFS: 0x78 SIZE: 0xC
		int prevSentTarget; //OFS: 0x84 SIZE: 0x4
		float aiSpread; //OFS: 0x88 SIZE: 0x4
		float playerSpread; //OFS: 0x8C SIZE: 0x4
		team_t eTeam; //OFS: 0x90 SIZE: 0x4
		float heatVal; //OFS: 0x94 SIZE: 0x4
		bool overheating; //OFS: 0x98 SIZE: 0x1
		float originError[3]; //OFS: 0x9C SIZE: 0xC
		float anglesError[3]; //OFS: 0xA8 SIZE: 0xC
		float pitchCap; //OFS: 0xB4 SIZE: 0x4
		int triggerDown; //OFS: 0xB8 SIZE: 0x4
		unsigned __int16 fireSnd; //OFS: 0xBC SIZE: 0x2
		unsigned __int16 fireSndPlayer; //OFS: 0xBE SIZE: 0x2
		unsigned __int16 stopSnd; //OFS: 0xC0 SIZE: 0x2
		unsigned __int16 stopSndPlayer; //OFS: 0xC2 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(TurretInfo, 0xC4);
	ASSERT_STRUCT_OFFSET(TurretInfo, inuse, 0x0);
	ASSERT_STRUCT_OFFSET(TurretInfo, state, 0x4);
	ASSERT_STRUCT_OFFSET(TurretInfo, flags, 0x8);
	ASSERT_STRUCT_OFFSET(TurretInfo, fireTime, 0xC);
	ASSERT_STRUCT_OFFSET(TurretInfo, manualTarget, 0x10);
	ASSERT_STRUCT_OFFSET(TurretInfo, target, 0x14);
	ASSERT_STRUCT_OFFSET(TurretInfo, targetPos, 0x18);
	ASSERT_STRUCT_OFFSET(TurretInfo, targetTime, 0x24);
	ASSERT_STRUCT_OFFSET(TurretInfo, missOffsetNormalized, 0x28);
	ASSERT_STRUCT_OFFSET(TurretInfo, arcmin, 0x34);
	ASSERT_STRUCT_OFFSET(TurretInfo, arcmax, 0x3C);
	ASSERT_STRUCT_OFFSET(TurretInfo, initialYawmin, 0x44);
	ASSERT_STRUCT_OFFSET(TurretInfo, initialYawmax, 0x48);
	ASSERT_STRUCT_OFFSET(TurretInfo, forwardAngleDot, 0x4C);
	ASSERT_STRUCT_OFFSET(TurretInfo, dropPitch, 0x50);
	ASSERT_STRUCT_OFFSET(TurretInfo, convergenceTime, 0x54);
	ASSERT_STRUCT_OFFSET(TurretInfo, suppressTime, 0x5C);
	ASSERT_STRUCT_OFFSET(TurretInfo, maxRangeSquared, 0x60);
	ASSERT_STRUCT_OFFSET(TurretInfo, detachSentient, 0x64);
	ASSERT_STRUCT_OFFSET(TurretInfo, stance, 0x68);
	ASSERT_STRUCT_OFFSET(TurretInfo, prevStance, 0x6C);
	ASSERT_STRUCT_OFFSET(TurretInfo, fireSndDelay, 0x70);
	ASSERT_STRUCT_OFFSET(TurretInfo, accuracy, 0x74);
	ASSERT_STRUCT_OFFSET(TurretInfo, userOrigin, 0x78);
	ASSERT_STRUCT_OFFSET(TurretInfo, prevSentTarget, 0x84);
	ASSERT_STRUCT_OFFSET(TurretInfo, aiSpread, 0x88);
	ASSERT_STRUCT_OFFSET(TurretInfo, playerSpread, 0x8C);
	ASSERT_STRUCT_OFFSET(TurretInfo, eTeam, 0x90);
	ASSERT_STRUCT_OFFSET(TurretInfo, heatVal, 0x94);
	ASSERT_STRUCT_OFFSET(TurretInfo, overheating, 0x98);
	ASSERT_STRUCT_OFFSET(TurretInfo, originError, 0x9C);
	ASSERT_STRUCT_OFFSET(TurretInfo, anglesError, 0xA8);
	ASSERT_STRUCT_OFFSET(TurretInfo, pitchCap, 0xB4);
	ASSERT_STRUCT_OFFSET(TurretInfo, triggerDown, 0xB8);
	ASSERT_STRUCT_OFFSET(TurretInfo, fireSnd, 0xBC);
	ASSERT_STRUCT_OFFSET(TurretInfo, fireSndPlayer, 0xBE);
	ASSERT_STRUCT_OFFSET(TurretInfo, stopSnd, 0xC0);
	ASSERT_STRUCT_OFFSET(TurretInfo, stopSndPlayer, 0xC2);

	struct DestructibleBurnData
	{
		int burnTime; //OFS: 0x0 SIZE: 0x4
		unsigned int fx; //OFS: 0x4 SIZE: 0x4
		int sndId; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DestructibleBurnData, 0xC);
	ASSERT_STRUCT_OFFSET(DestructibleBurnData, burnTime, 0x0);
	ASSERT_STRUCT_OFFSET(DestructibleBurnData, fx, 0x4);
	ASSERT_STRUCT_OFFSET(DestructibleBurnData, sndId, 0x8);

	struct Destructible
	{
		int entNum; //OFS: 0x0 SIZE: 0x4
		__int16 pieceHealth[32]; //OFS: 0x4 SIZE: 0x40
		int xdollHandles[32]; //OFS: 0x44 SIZE: 0x80
		DestructibleBurnData burnData[32]; //OFS: 0xC4 SIZE: 0x180
		int oldestBurnTime; //OFS: 0x244 SIZE: 0x4
		unsigned __int8 clientNum; //OFS: 0x248 SIZE: 0x1
		unsigned __int8 destructiblePoseID; //OFS: 0x249 SIZE: 0x1
		DestructibleDef * ddef; //OFS: 0x24C SIZE: 0x4
		unsigned int flags; //OFS: 0x250 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(Destructible, 0x254);
	ASSERT_STRUCT_OFFSET(Destructible, entNum, 0x0);
	ASSERT_STRUCT_OFFSET(Destructible, pieceHealth, 0x4);
	ASSERT_STRUCT_OFFSET(Destructible, xdollHandles, 0x44);
	ASSERT_STRUCT_OFFSET(Destructible, burnData, 0xC4);
	ASSERT_STRUCT_OFFSET(Destructible, oldestBurnTime, 0x244);
	ASSERT_STRUCT_OFFSET(Destructible, clientNum, 0x248);
	ASSERT_STRUCT_OFFSET(Destructible, destructiblePoseID, 0x249);
	ASSERT_STRUCT_OFFSET(Destructible, ddef, 0x24C);
	ASSERT_STRUCT_OFFSET(Destructible, flags, 0x250);

	struct flame_timed_damage_t
	{
		gentity_s * attacker; //OFS: 0x0 SIZE: 0x4
		int damage; //OFS: 0x4 SIZE: 0x4
		float damageDuration; //OFS: 0x8 SIZE: 0x4
		float damageInterval; //OFS: 0xC SIZE: 0x4
		int start_timestamp; //OFS: 0x10 SIZE: 0x4
		int end_timestamp; //OFS: 0x14 SIZE: 0x4
		int lastupdate_timestamp; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(flame_timed_damage_t, 0x1C);
	ASSERT_STRUCT_OFFSET(flame_timed_damage_t, attacker, 0x0);
	ASSERT_STRUCT_OFFSET(flame_timed_damage_t, damage, 0x4);
	ASSERT_STRUCT_OFFSET(flame_timed_damage_t, damageDuration, 0x8);
	ASSERT_STRUCT_OFFSET(flame_timed_damage_t, damageInterval, 0xC);
	ASSERT_STRUCT_OFFSET(flame_timed_damage_t, start_timestamp, 0x10);
	ASSERT_STRUCT_OFFSET(flame_timed_damage_t, end_timestamp, 0x14);
	ASSERT_STRUCT_OFFSET(flame_timed_damage_t, lastupdate_timestamp, 0x18);

	struct missile_ent_t
	{
		float predictLandPos[3]; //OFS: 0x0 SIZE: 0xC
		int predictLandTime; //OFS: 0xC SIZE: 0x4
		int timestamp; //OFS: 0x10 SIZE: 0x4
		float time; //OFS: 0x14 SIZE: 0x4
		int timeOfBirth; //OFS: 0x18 SIZE: 0x4
		float travelDist; //OFS: 0x1C SIZE: 0x4
		float surfaceNormal[3]; //OFS: 0x20 SIZE: 0xC
		team_t team; //OFS: 0x2C SIZE: 0x4
		int thrownBack; //OFS: 0x30 SIZE: 0x4
		float curvature[3]; //OFS: 0x34 SIZE: 0xC
		float targetOffset[3]; //OFS: 0x40 SIZE: 0xC
		MissileStage stage; //OFS: 0x4C SIZE: 0x4
		MissileFlightMode flightMode; //OFS: 0x50 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(missile_ent_t, 0x54);
	ASSERT_STRUCT_OFFSET(missile_ent_t, predictLandPos, 0x0);
	ASSERT_STRUCT_OFFSET(missile_ent_t, predictLandTime, 0xC);
	ASSERT_STRUCT_OFFSET(missile_ent_t, timestamp, 0x10);
	ASSERT_STRUCT_OFFSET(missile_ent_t, time, 0x14);
	ASSERT_STRUCT_OFFSET(missile_ent_t, timeOfBirth, 0x18);
	ASSERT_STRUCT_OFFSET(missile_ent_t, travelDist, 0x1C);
	ASSERT_STRUCT_OFFSET(missile_ent_t, surfaceNormal, 0x20);
	ASSERT_STRUCT_OFFSET(missile_ent_t, team, 0x2C);
	ASSERT_STRUCT_OFFSET(missile_ent_t, thrownBack, 0x30);
	ASSERT_STRUCT_OFFSET(missile_ent_t, curvature, 0x34);
	ASSERT_STRUCT_OFFSET(missile_ent_t, targetOffset, 0x40);
	ASSERT_STRUCT_OFFSET(missile_ent_t, stage, 0x4C);
	ASSERT_STRUCT_OFFSET(missile_ent_t, flightMode, 0x50);

	struct mover_ent_t
	{
		float decelTime; //OFS: 0x0 SIZE: 0x4
		float aDecelTime; //OFS: 0x4 SIZE: 0x4
		float speed; //OFS: 0x8 SIZE: 0x4
		float aSpeed; //OFS: 0xC SIZE: 0x4
		float midTime; //OFS: 0x10 SIZE: 0x4
		float aMidTime; //OFS: 0x14 SIZE: 0x4
		float pos1[3]; //OFS: 0x18 SIZE: 0xC
		float pos2[3]; //OFS: 0x24 SIZE: 0xC
		float pos3[3]; //OFS: 0x30 SIZE: 0xC
		float apos1[3]; //OFS: 0x3C SIZE: 0xC
		float apos2[3]; //OFS: 0x48 SIZE: 0xC
		float apos3[3]; //OFS: 0x54 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(mover_ent_t, 0x60);
	ASSERT_STRUCT_OFFSET(mover_ent_t, decelTime, 0x0);
	ASSERT_STRUCT_OFFSET(mover_ent_t, aDecelTime, 0x4);
	ASSERT_STRUCT_OFFSET(mover_ent_t, speed, 0x8);
	ASSERT_STRUCT_OFFSET(mover_ent_t, aSpeed, 0xC);
	ASSERT_STRUCT_OFFSET(mover_ent_t, midTime, 0x10);
	ASSERT_STRUCT_OFFSET(mover_ent_t, aMidTime, 0x14);
	ASSERT_STRUCT_OFFSET(mover_ent_t, pos1, 0x18);
	ASSERT_STRUCT_OFFSET(mover_ent_t, pos2, 0x24);
	ASSERT_STRUCT_OFFSET(mover_ent_t, pos3, 0x30);
	ASSERT_STRUCT_OFFSET(mover_ent_t, apos1, 0x3C);
	ASSERT_STRUCT_OFFSET(mover_ent_t, apos2, 0x48);
	ASSERT_STRUCT_OFFSET(mover_ent_t, apos3, 0x54);

	struct trigger_ent_t
	{
		int threshold; //OFS: 0x0 SIZE: 0x4
		int accumulate; //OFS: 0x4 SIZE: 0x4
		int timestamp; //OFS: 0x8 SIZE: 0x4
		int singleUserEntIndex; //OFS: 0xC SIZE: 0x4
		bool requireLookAt; //OFS: 0x10 SIZE: 0x1
		int exposureIndex; //OFS: 0x14 SIZE: 0x4
		float exposureLerpToLighter; //OFS: 0x18 SIZE: 0x4
		float exposureLerpToDarker; //OFS: 0x1C SIZE: 0x4
		float exposureFeather[3]; //OFS: 0x20 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(trigger_ent_t, 0x2C);
	ASSERT_STRUCT_OFFSET(trigger_ent_t, threshold, 0x0);
	ASSERT_STRUCT_OFFSET(trigger_ent_t, accumulate, 0x4);
	ASSERT_STRUCT_OFFSET(trigger_ent_t, timestamp, 0x8);
	ASSERT_STRUCT_OFFSET(trigger_ent_t, singleUserEntIndex, 0xC);
	ASSERT_STRUCT_OFFSET(trigger_ent_t, requireLookAt, 0x10);
	ASSERT_STRUCT_OFFSET(trigger_ent_t, exposureIndex, 0x14);
	ASSERT_STRUCT_OFFSET(trigger_ent_t, exposureLerpToLighter, 0x18);
	ASSERT_STRUCT_OFFSET(trigger_ent_t, exposureLerpToDarker, 0x1C);
	ASSERT_STRUCT_OFFSET(trigger_ent_t, exposureFeather, 0x20);

	union gentity_u
	{
		missile_ent_t missile; //OFS: 0x0 SIZE: 0x54
		mover_ent_t mover; //OFS: 0x1 SIZE: 0x60
		trigger_ent_t trigger; //OFS: 0x2 SIZE: 0x2C
	};
	ASSERT_STRUCT_SIZE(gentity_u, 0x60);

	struct snd_wait_t
	{
		unsigned __int16 notifyString; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 index; //OFS: 0x2 SIZE: 0x2
		unsigned __int8 stoppable; //OFS: 0x4 SIZE: 0x1
		int basetime; //OFS: 0x8 SIZE: 0x4
		int duration; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(snd_wait_t, 0x10);
	ASSERT_STRUCT_OFFSET(snd_wait_t, notifyString, 0x0);
	ASSERT_STRUCT_OFFSET(snd_wait_t, index, 0x2);
	ASSERT_STRUCT_OFFSET(snd_wait_t, stoppable, 0x4);
	ASSERT_STRUCT_OFFSET(snd_wait_t, basetime, 0x8);
	ASSERT_STRUCT_OFFSET(snd_wait_t, duration, 0xC);

	struct tagInfo_s
	{
		gentity_s * parent; //OFS: 0x0 SIZE: 0x4
		gentity_s * next; //OFS: 0x4 SIZE: 0x4
		unsigned __int16 name; //OFS: 0x8 SIZE: 0x2
		int index; //OFS: 0xC SIZE: 0x4
		float axis[4][3]; //OFS: 0x10 SIZE: 0x30
		float parentInvAxis[4][3]; //OFS: 0x40 SIZE: 0x30
	};
	ASSERT_STRUCT_SIZE(tagInfo_s, 0x70);
	ASSERT_STRUCT_OFFSET(tagInfo_s, parent, 0x0);
	ASSERT_STRUCT_OFFSET(tagInfo_s, next, 0x4);
	ASSERT_STRUCT_OFFSET(tagInfo_s, name, 0x8);
	ASSERT_STRUCT_OFFSET(tagInfo_s, index, 0xC);
	ASSERT_STRUCT_OFFSET(tagInfo_s, axis, 0x10);
	ASSERT_STRUCT_OFFSET(tagInfo_s, parentInvAxis, 0x40);

	struct animscripted_s
	{
		float axis[4][3]; //OFS: 0x0 SIZE: 0x30
		float originError[3]; //OFS: 0x30 SIZE: 0xC
		float anglesError[3]; //OFS: 0x3C SIZE: 0xC
		unsigned __int16 anim; //OFS: 0x48 SIZE: 0x2
		unsigned __int16 root; //OFS: 0x4A SIZE: 0x2
		unsigned __int8 bStarted; //OFS: 0x4C SIZE: 0x1
		unsigned __int8 mode; //OFS: 0x4D SIZE: 0x1
		int startTime; //OFS: 0x50 SIZE: 0x4
		float fHeightOfs; //OFS: 0x54 SIZE: 0x4
		float fEndPitch; //OFS: 0x58 SIZE: 0x4
		float fEndRoll; //OFS: 0x5C SIZE: 0x4
		float fOrientLerp; //OFS: 0x60 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(animscripted_s, 0x64);
	ASSERT_STRUCT_OFFSET(animscripted_s, axis, 0x0);
	ASSERT_STRUCT_OFFSET(animscripted_s, originError, 0x30);
	ASSERT_STRUCT_OFFSET(animscripted_s, anglesError, 0x3C);
	ASSERT_STRUCT_OFFSET(animscripted_s, anim, 0x48);
	ASSERT_STRUCT_OFFSET(animscripted_s, root, 0x4A);
	ASSERT_STRUCT_OFFSET(animscripted_s, bStarted, 0x4C);
	ASSERT_STRUCT_OFFSET(animscripted_s, mode, 0x4D);
	ASSERT_STRUCT_OFFSET(animscripted_s, startTime, 0x50);
	ASSERT_STRUCT_OFFSET(animscripted_s, fHeightOfs, 0x54);
	ASSERT_STRUCT_OFFSET(animscripted_s, fEndPitch, 0x58);
	ASSERT_STRUCT_OFFSET(animscripted_s, fEndRoll, 0x5C);
	ASSERT_STRUCT_OFFSET(animscripted_s, fOrientLerp, 0x60);

	struct __declspec(align(8)) gentity_s
	{
		entityState_s s; //OFS: 0x0 SIZE: 0x118
		entityShared_s r; //OFS: 0x118 SIZE: 0x68
		gclient_s * client; //OFS: 0x180 SIZE: 0x4
		actor_s * actor; //OFS: 0x184 SIZE: 0x4
		sentient_s * sentient; //OFS: 0x188 SIZE: 0x4
		scr_vehicle_s * scr_vehicle; //OFS: 0x18C SIZE: 0x4
		TurretInfo * pTurretInfo; //OFS: 0x190 SIZE: 0x4
		Destructible * destructible; //OFS: 0x194 SIZE: 0x4
		unsigned __int16 model; //OFS: 0x198 SIZE: 0x2
		unsigned __int8 physicsObject; //OFS: 0x19A SIZE: 0x1
		unsigned __int8 takedamage; //OFS: 0x19B SIZE: 0x1
		unsigned __int8 active; //OFS: 0x19C SIZE: 0x1
		unsigned __int8 nopickup; //OFS: 0x19D SIZE: 0x1
		unsigned __int8 handler; //OFS: 0x19E SIZE: 0x1
		unsigned __int16 classname; //OFS: 0x1A0 SIZE: 0x2
		unsigned __int16 script_linkName; //OFS: 0x1A2 SIZE: 0x2
		unsigned __int16 script_noteworthy; //OFS: 0x1A4 SIZE: 0x2
		unsigned __int16 target; //OFS: 0x1A6 SIZE: 0x2
		int targetname; //OFS: 0x1A8 SIZE: 0x4
		int spawnflags2; //OFS: 0x1AC SIZE: 0x4
		int spawnflags; //OFS: 0x1B0 SIZE: 0x4
		int flags; //OFS: 0x1B4 SIZE: 0x4
		int clipmask; //OFS: 0x1B8 SIZE: 0x4
		int processedFrame; //OFS: 0x1BC SIZE: 0x4
		EntHandle parent; //OFS: 0x1C0 SIZE: 0x4
		int nextthink; //OFS: 0x1C4 SIZE: 0x4
		int health; //OFS: 0x1C8 SIZE: 0x4
		int maxhealth; //OFS: 0x1CC SIZE: 0x4
		int nexteq; //OFS: 0x1D0 SIZE: 0x4
		int damage; //OFS: 0x1D4 SIZE: 0x4
		flame_timed_damage_t flame_timed_damage[4]; //OFS: 0x1D8 SIZE: 0x70
		int last_timed_radius_damage; //OFS: 0x248 SIZE: 0x4
		int count; //OFS: 0x24C SIZE: 0x4
		gentity_s * chain; //OFS: 0x250 SIZE: 0x4
		gentity_s * activator; //OFS: 0x254 SIZE: 0x4
		gentity_u u; //OFS: 0x258 SIZE: 0x60
		EntHandle missileTargetEnt; //OFS: 0x2B8 SIZE: 0x4
		__int16 lookAtText0; //OFS: 0x2BC SIZE: 0x2
		__int16 lookAtText1; //OFS: 0x2BE SIZE: 0x2
		snd_wait_t snd_wait; //OFS: 0x2C0 SIZE: 0x10
		tagInfo_s * tagInfo; //OFS: 0x2D0 SIZE: 0x4
		gentity_s * tagChildren; //OFS: 0x2D4 SIZE: 0x4
		animscripted_s * scripted; //OFS: 0x2D8 SIZE: 0x4
		__int16 attachTagNames[31]; //OFS: 0x2DC SIZE: 0x3E
		__int16 attachModelNames[31]; //OFS: 0x31A SIZE: 0x3E
		int disconnectedLinks; //OFS: 0x358 SIZE: 0x4
		int iDisconnectTime; //OFS: 0x35C SIZE: 0x4
		float angleLerpRate; //OFS: 0x360 SIZE: 0x4
		int physObjId; //OFS: 0x364 SIZE: 0x4
		XAnimTree_s * pAnimTree; //OFS: 0x368 SIZE: 0x4
		gentity_s * nextFree; //OFS: 0x36C SIZE: 0x4
		int scriptUse; //OFS: 0x370 SIZE: 0x4
		int birthTime; //OFS: 0x374 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(gentity_s, 0x378);
	ASSERT_STRUCT_OFFSET(gentity_s, s, 0x0);
	ASSERT_STRUCT_OFFSET(gentity_s, r, 0x118);
	ASSERT_STRUCT_OFFSET(gentity_s, client, 0x180);
	ASSERT_STRUCT_OFFSET(gentity_s, actor, 0x184);
	ASSERT_STRUCT_OFFSET(gentity_s, sentient, 0x188);
	ASSERT_STRUCT_OFFSET(gentity_s, scr_vehicle, 0x18C);
	ASSERT_STRUCT_OFFSET(gentity_s, pTurretInfo, 0x190);
	ASSERT_STRUCT_OFFSET(gentity_s, destructible, 0x194);
	ASSERT_STRUCT_OFFSET(gentity_s, model, 0x198);
	ASSERT_STRUCT_OFFSET(gentity_s, physicsObject, 0x19A);
	ASSERT_STRUCT_OFFSET(gentity_s, takedamage, 0x19B);
	ASSERT_STRUCT_OFFSET(gentity_s, active, 0x19C);
	ASSERT_STRUCT_OFFSET(gentity_s, nopickup, 0x19D);
	ASSERT_STRUCT_OFFSET(gentity_s, handler, 0x19E);
	ASSERT_STRUCT_OFFSET(gentity_s, classname, 0x1A0);
	ASSERT_STRUCT_OFFSET(gentity_s, script_linkName, 0x1A2);
	ASSERT_STRUCT_OFFSET(gentity_s, script_noteworthy, 0x1A4);
	ASSERT_STRUCT_OFFSET(gentity_s, target, 0x1A6);
	ASSERT_STRUCT_OFFSET(gentity_s, targetname, 0x1A8);
	ASSERT_STRUCT_OFFSET(gentity_s, spawnflags2, 0x1AC);
	ASSERT_STRUCT_OFFSET(gentity_s, spawnflags, 0x1B0);
	ASSERT_STRUCT_OFFSET(gentity_s, flags, 0x1B4);
	ASSERT_STRUCT_OFFSET(gentity_s, clipmask, 0x1B8);
	ASSERT_STRUCT_OFFSET(gentity_s, processedFrame, 0x1BC);
	ASSERT_STRUCT_OFFSET(gentity_s, parent, 0x1C0);
	ASSERT_STRUCT_OFFSET(gentity_s, nextthink, 0x1C4);
	ASSERT_STRUCT_OFFSET(gentity_s, health, 0x1C8);
	ASSERT_STRUCT_OFFSET(gentity_s, maxhealth, 0x1CC);
	ASSERT_STRUCT_OFFSET(gentity_s, nexteq, 0x1D0);
	ASSERT_STRUCT_OFFSET(gentity_s, damage, 0x1D4);
	ASSERT_STRUCT_OFFSET(gentity_s, flame_timed_damage, 0x1D8);
	ASSERT_STRUCT_OFFSET(gentity_s, last_timed_radius_damage, 0x248);
	ASSERT_STRUCT_OFFSET(gentity_s, count, 0x24C);
	ASSERT_STRUCT_OFFSET(gentity_s, chain, 0x250);
	ASSERT_STRUCT_OFFSET(gentity_s, activator, 0x254);
	ASSERT_STRUCT_OFFSET(gentity_s, u, 0x258);
	ASSERT_STRUCT_OFFSET(gentity_s, missileTargetEnt, 0x2B8);
	ASSERT_STRUCT_OFFSET(gentity_s, lookAtText0, 0x2BC);
	ASSERT_STRUCT_OFFSET(gentity_s, lookAtText1, 0x2BE);
	ASSERT_STRUCT_OFFSET(gentity_s, snd_wait, 0x2C0);
	ASSERT_STRUCT_OFFSET(gentity_s, tagInfo, 0x2D0);
	ASSERT_STRUCT_OFFSET(gentity_s, tagChildren, 0x2D4);
	ASSERT_STRUCT_OFFSET(gentity_s, scripted, 0x2D8);
	ASSERT_STRUCT_OFFSET(gentity_s, attachTagNames, 0x2DC);
	ASSERT_STRUCT_OFFSET(gentity_s, attachModelNames, 0x31A);
	ASSERT_STRUCT_OFFSET(gentity_s, disconnectedLinks, 0x358);
	ASSERT_STRUCT_OFFSET(gentity_s, iDisconnectTime, 0x35C);
	ASSERT_STRUCT_OFFSET(gentity_s, angleLerpRate, 0x360);
	ASSERT_STRUCT_OFFSET(gentity_s, physObjId, 0x364);
	ASSERT_STRUCT_OFFSET(gentity_s, pAnimTree, 0x368);
	ASSERT_STRUCT_OFFSET(gentity_s, nextFree, 0x36C);
	ASSERT_STRUCT_OFFSET(gentity_s, scriptUse, 0x370);
	ASSERT_STRUCT_OFFSET(gentity_s, birthTime, 0x374);

	struct BulletTraceResults
	{
		trace_t trace; //OFS: 0x0 SIZE: 0x34
		gentity_s * hitEnt; //OFS: 0x34 SIZE: 0x4
		float hitPos[3]; //OFS: 0x38 SIZE: 0xC
		bool ignoreHitEnt; //OFS: 0x44 SIZE: 0x1
		int depthSurfaceType; //OFS: 0x48 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(BulletTraceResults, 0x4C);
	ASSERT_STRUCT_OFFSET(BulletTraceResults, trace, 0x0);
	ASSERT_STRUCT_OFFSET(BulletTraceResults, hitEnt, 0x34);
	ASSERT_STRUCT_OFFSET(BulletTraceResults, hitPos, 0x38);
	ASSERT_STRUCT_OFFSET(BulletTraceResults, ignoreHitEnt, 0x44);
	ASSERT_STRUCT_OFFSET(BulletTraceResults, depthSurfaceType, 0x48);

	struct svEntity_t
	{
		int worldSector; //OFS: 0x0 SIZE: 0x4
		int nextEntityInWorldSector; //OFS: 0x4 SIZE: 0x4
		entityState_s baseline; //OFS: 0x8 SIZE: 0x118
		int pad[10]; //OFS: 0x120 SIZE: 0x28
		int numClusters; //OFS: 0x148 SIZE: 0x4
		int clusternums[16]; //OFS: 0x14C SIZE: 0x40
		int lastCluster; //OFS: 0x18C SIZE: 0x4
		int linkcontents; //OFS: 0x190 SIZE: 0x4
		float linkmin[3]; //OFS: 0x194 SIZE: 0xC
		float linkmax[3]; //OFS: 0x1A0 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(svEntity_t, 0x1AC);
	ASSERT_STRUCT_OFFSET(svEntity_t, worldSector, 0x0);
	ASSERT_STRUCT_OFFSET(svEntity_t, nextEntityInWorldSector, 0x4);
	ASSERT_STRUCT_OFFSET(svEntity_t, baseline, 0x8);
	ASSERT_STRUCT_OFFSET(svEntity_t, pad, 0x120);
	ASSERT_STRUCT_OFFSET(svEntity_t, numClusters, 0x148);
	ASSERT_STRUCT_OFFSET(svEntity_t, clusternums, 0x14C);
	ASSERT_STRUCT_OFFSET(svEntity_t, lastCluster, 0x18C);
	ASSERT_STRUCT_OFFSET(svEntity_t, linkcontents, 0x190);
	ASSERT_STRUCT_OFFSET(svEntity_t, linkmin, 0x194);
	ASSERT_STRUCT_OFFSET(svEntity_t, linkmax, 0x1A0);

	struct __declspec(align(1)) struc_72
	{
		char field_0[795]; //OFS: 0x0 SIZE: 0x31B
		char field_31B; //OFS: 0x31B SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(struc_72, 0x31C);
	ASSERT_STRUCT_OFFSET(struc_72, field_0, 0x0);
	ASSERT_STRUCT_OFFSET(struc_72, field_31B, 0x31B);

	struct va_info_t
	{
		char va_string[16][1024]; //OFS: 0x0 SIZE: 0x4000
		int index; //OFS: 0x4000 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(va_info_t, 0x4004);
	ASSERT_STRUCT_OFFSET(va_info_t, va_string, 0x0);
	ASSERT_STRUCT_OFFSET(va_info_t, index, 0x4000);

	struct TraceCheckCount
	{
		int global; //OFS: 0x0 SIZE: 0x4
		int * partitions; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(TraceCheckCount, 0x8);
	ASSERT_STRUCT_OFFSET(TraceCheckCount, global, 0x0);
	ASSERT_STRUCT_OFFSET(TraceCheckCount, partitions, 0x4);

	struct TraceThreadInfo
	{
		TraceCheckCount checkcount; //OFS: 0x0 SIZE: 0x8
		cbrush_t * box_brush; //OFS: 0x8 SIZE: 0x4
		cmodel_t * box_model; //OFS: 0xC SIZE: 0x4
		PhysGeomList ** geoms; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(TraceThreadInfo, 0x14);
	ASSERT_STRUCT_OFFSET(TraceThreadInfo, checkcount, 0x0);
	ASSERT_STRUCT_OFFSET(TraceThreadInfo, box_brush, 0x8);
	ASSERT_STRUCT_OFFSET(TraceThreadInfo, box_model, 0xC);
	ASSERT_STRUCT_OFFSET(TraceThreadInfo, geoms, 0x10);

	struct TLSDataThreadInfo_t
	{
		int g_threadValue; //OFS: 0x0 SIZE: 0x4
		va_info_t * va_info; //OFS: 0x4 SIZE: 0x4
		jmp_buf * g_com_error; //OFS: 0x8 SIZE: 0x4
		TraceThreadInfo * g_traceThreadInfo; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(TLSDataThreadInfo_t, 0x10);
	ASSERT_STRUCT_OFFSET(TLSDataThreadInfo_t, g_threadValue, 0x0);
	ASSERT_STRUCT_OFFSET(TLSDataThreadInfo_t, va_info, 0x4);
	ASSERT_STRUCT_OFFSET(TLSDataThreadInfo_t, g_com_error, 0x8);
	ASSERT_STRUCT_OFFSET(TLSDataThreadInfo_t, g_traceThreadInfo, 0xC);

	struct TLSData_t
	{
		int field_0; //OFS: 0x0 SIZE: 0x4
		int field_4; //OFS: 0x4 SIZE: 0x4
		int field_8; //OFS: 0x8 SIZE: 0x4
		int field_C; //OFS: 0xC SIZE: 0x4
		int field_10; //OFS: 0x10 SIZE: 0x4
		TLSDataThreadInfo_t * TLSDataThreadInfo; //OFS: 0x14 SIZE: 0x4
		int field_18; //OFS: 0x18 SIZE: 0x4
		int field_1C; //OFS: 0x1C SIZE: 0x4
		int CurrentThreadId; //OFS: 0x20 SIZE: 0x4
		int field_24; //OFS: 0x24 SIZE: 0x4
		int field_28; //OFS: 0x28 SIZE: 0x4
		int field_2C; //OFS: 0x2C SIZE: 0x4
		int field_30; //OFS: 0x30 SIZE: 0x4
		int field_34; //OFS: 0x34 SIZE: 0x4
		int field_38; //OFS: 0x38 SIZE: 0x4
		int field_3C; //OFS: 0x3C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(TLSData_t, 0x40);
	ASSERT_STRUCT_OFFSET(TLSData_t, field_0, 0x0);
	ASSERT_STRUCT_OFFSET(TLSData_t, field_4, 0x4);
	ASSERT_STRUCT_OFFSET(TLSData_t, field_8, 0x8);
	ASSERT_STRUCT_OFFSET(TLSData_t, field_C, 0xC);
	ASSERT_STRUCT_OFFSET(TLSData_t, field_10, 0x10);
	ASSERT_STRUCT_OFFSET(TLSData_t, TLSDataThreadInfo, 0x14);
	ASSERT_STRUCT_OFFSET(TLSData_t, field_18, 0x18);
	ASSERT_STRUCT_OFFSET(TLSData_t, field_1C, 0x1C);
	ASSERT_STRUCT_OFFSET(TLSData_t, CurrentThreadId, 0x20);
	ASSERT_STRUCT_OFFSET(TLSData_t, field_24, 0x24);
	ASSERT_STRUCT_OFFSET(TLSData_t, field_28, 0x28);
	ASSERT_STRUCT_OFFSET(TLSData_t, field_2C, 0x2C);
	ASSERT_STRUCT_OFFSET(TLSData_t, field_30, 0x30);
	ASSERT_STRUCT_OFFSET(TLSData_t, field_34, 0x34);
	ASSERT_STRUCT_OFFSET(TLSData_t, field_38, 0x38);
	ASSERT_STRUCT_OFFSET(TLSData_t, field_3C, 0x3C);

	struct XZoneInfo
	{
		char * name; //OFS: 0x0 SIZE: 0x4
		int allocFlags; //OFS: 0x4 SIZE: 0x4
		int freeFlags; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XZoneInfo, 0xC);
	ASSERT_STRUCT_OFFSET(XZoneInfo, name, 0x0);
	ASSERT_STRUCT_OFFSET(XZoneInfo, allocFlags, 0x4);
	ASSERT_STRUCT_OFFSET(XZoneInfo, freeFlags, 0x8);

	union DvarValue
	{
		bool enabled; //OFS: 0x0 SIZE: 0x1
		int integer; //OFS: 0x1 SIZE: 0x4
		unsigned int unsignedInt; //OFS: 0x2 SIZE: 0x4
		float value; //OFS: 0x3 SIZE: 0x4
		float vector[4]; //OFS: 0x4 SIZE: 0x10
		const char * string; //OFS: 0x5 SIZE: 0x4
		char color[4]; //OFS: 0x6 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DvarValue, 0x10);

	struct DvarLimits_enum
	{
		int stringCount; //OFS: 0x0 SIZE: 0x4
		const char ** strings; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DvarLimits_enum, 0x8);
	ASSERT_STRUCT_OFFSET(DvarLimits_enum, stringCount, 0x0);
	ASSERT_STRUCT_OFFSET(DvarLimits_enum, strings, 0x4);

	struct DvarLimits_minmax
	{
		int min; //OFS: 0x0 SIZE: 0x4
		int max; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DvarLimits_minmax, 0x8);
	ASSERT_STRUCT_OFFSET(DvarLimits_minmax, min, 0x0);
	ASSERT_STRUCT_OFFSET(DvarLimits_minmax, max, 0x4);

	struct DvarLimits_float_minmax
	{
		float min; //OFS: 0x0 SIZE: 0x4
		float max; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DvarLimits_float_minmax, 0x8);
	ASSERT_STRUCT_OFFSET(DvarLimits_float_minmax, min, 0x0);
	ASSERT_STRUCT_OFFSET(DvarLimits_float_minmax, max, 0x4);

	union DvarLimits
	{
		DvarLimits_enum enumeration; //OFS: 0x0 SIZE: 0x8
		DvarLimits_minmax integer; //OFS: 0x1 SIZE: 0x8
		DvarLimits_float_minmax value; //OFS: 0x2 SIZE: 0x8
		DvarLimits_float_minmax vector; //OFS: 0x3 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(DvarLimits, 0x8);

	struct dvar_s
	{
		const char * name; //OFS: 0x0 SIZE: 0x4
		const char * description; //OFS: 0x4 SIZE: 0x4
		DvarFlags flags; //OFS: 0x8 SIZE: 0x2
		dvarType_t type; //OFS: 0xA SIZE: 0x1
		char modified; //OFS: 0xB SIZE: 0x1
		char saveRestorable; //OFS: 0xC SIZE: 0x1
		DvarValue current; //OFS: 0x10 SIZE: 0x10
		DvarValue latched; //OFS: 0x20 SIZE: 0x10
		DvarValue reset; //OFS: 0x30 SIZE: 0x10
		DvarValue saved; //OFS: 0x40 SIZE: 0x10
		DvarLimits domain; //OFS: 0x50 SIZE: 0x8
		dvar_s * hashNext; //OFS: 0x58 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(dvar_s, 0x5C);
	ASSERT_STRUCT_OFFSET(dvar_s, name, 0x0);
	ASSERT_STRUCT_OFFSET(dvar_s, description, 0x4);
	ASSERT_STRUCT_OFFSET(dvar_s, flags, 0x8);
	ASSERT_STRUCT_OFFSET(dvar_s, type, 0xA);
	ASSERT_STRUCT_OFFSET(dvar_s, modified, 0xB);
	ASSERT_STRUCT_OFFSET(dvar_s, saveRestorable, 0xC);
	ASSERT_STRUCT_OFFSET(dvar_s, current, 0x10);
	ASSERT_STRUCT_OFFSET(dvar_s, latched, 0x20);
	ASSERT_STRUCT_OFFSET(dvar_s, reset, 0x30);
	ASSERT_STRUCT_OFFSET(dvar_s, saved, 0x40);
	ASSERT_STRUCT_OFFSET(dvar_s, domain, 0x50);
	ASSERT_STRUCT_OFFSET(dvar_s, hashNext, 0x58);

	struct cmd_function_s
	{
		cmd_function_s * next; //OFS: 0x0 SIZE: 0x4
		const char * name; //OFS: 0x4 SIZE: 0x4
		const char * autoCompleteDir; //OFS: 0x8 SIZE: 0x4
		const char * autoCompleteExt; //OFS: 0xC SIZE: 0x4
		void (__cdecl *function)(); //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(cmd_function_s, 0x14);
	ASSERT_STRUCT_OFFSET(cmd_function_s, next, 0x0);
	ASSERT_STRUCT_OFFSET(cmd_function_s, name, 0x4);
	ASSERT_STRUCT_OFFSET(cmd_function_s, autoCompleteDir, 0x8);
	ASSERT_STRUCT_OFFSET(cmd_function_s, autoCompleteExt, 0xC);
	ASSERT_STRUCT_OFFSET(cmd_function_s, function, 0x10);

	struct msg_s
	{
		int overflowed; //OFS: 0x0 SIZE: 0x4
		int readonly; //OFS: 0x4 SIZE: 0x4
		char * data; //OFS: 0x8 SIZE: 0x4
		char * splitData; //OFS: 0xC SIZE: 0x4
		int maxsize; //OFS: 0x10 SIZE: 0x4
		int cursize; //OFS: 0x14 SIZE: 0x4
		int splitSize; //OFS: 0x18 SIZE: 0x4
		int readcount; //OFS: 0x1C SIZE: 0x4
		int bit; //OFS: 0x20 SIZE: 0x4
		int lastEntityRef; //OFS: 0x24 SIZE: 0x4
		int flush; //OFS: 0x28 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(msg_s, 0x2C);
	ASSERT_STRUCT_OFFSET(msg_s, overflowed, 0x0);
	ASSERT_STRUCT_OFFSET(msg_s, readonly, 0x4);
	ASSERT_STRUCT_OFFSET(msg_s, data, 0x8);
	ASSERT_STRUCT_OFFSET(msg_s, splitData, 0xC);
	ASSERT_STRUCT_OFFSET(msg_s, maxsize, 0x10);
	ASSERT_STRUCT_OFFSET(msg_s, cursize, 0x14);
	ASSERT_STRUCT_OFFSET(msg_s, splitSize, 0x18);
	ASSERT_STRUCT_OFFSET(msg_s, readcount, 0x1C);
	ASSERT_STRUCT_OFFSET(msg_s, bit, 0x20);
	ASSERT_STRUCT_OFFSET(msg_s, lastEntityRef, 0x24);
	ASSERT_STRUCT_OFFSET(msg_s, flush, 0x28);

	union netadr_s_ip
	{
		unsigned __int8 _ip[4]; //OFS: 0x0 SIZE: 0x4
		unsigned int ip_packed; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(netadr_s_ip, 0x4);

	struct netadr_s
	{
		netadrtype_t type; //OFS: 0x0 SIZE: 0x4
		union netadr_s_ip anonymous_0; //OFS: 0x4 SIZE: 0x4
		unsigned __int16 port; //OFS: 0x8 SIZE: 0x2
		unsigned __int8 netnum[4]; //OFS: 0xA SIZE: 0x4
		unsigned __int8 nodenum[6]; //OFS: 0xE SIZE: 0x6
		unsigned int routerHandle; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(netadr_s, 0x18);
	ASSERT_STRUCT_OFFSET(netadr_s, type, 0x0);
	ASSERT_STRUCT_OFFSET(netadr_s, anonymous_0, 0x4);
	ASSERT_STRUCT_OFFSET(netadr_s, port, 0x8);
	ASSERT_STRUCT_OFFSET(netadr_s, netnum, 0xA);
	ASSERT_STRUCT_OFFSET(netadr_s, nodenum, 0xE);
	ASSERT_STRUCT_OFFSET(netadr_s, routerHandle, 0x14);

	struct netProfilePacket_t
	{
		int iTime; //OFS: 0x0 SIZE: 0x4
		int iSize; //OFS: 0x4 SIZE: 0x4
		int bFragment; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(netProfilePacket_t, 0xC);
	ASSERT_STRUCT_OFFSET(netProfilePacket_t, iTime, 0x0);
	ASSERT_STRUCT_OFFSET(netProfilePacket_t, iSize, 0x4);
	ASSERT_STRUCT_OFFSET(netProfilePacket_t, bFragment, 0x8);

	struct netProfileStream_t
	{
		netProfilePacket_t packets[60]; //OFS: 0x0 SIZE: 0x2D0
		int iCurrPacket; //OFS: 0x2D0 SIZE: 0x4
		int iBytesPerSecond; //OFS: 0x2D4 SIZE: 0x4
		int iLastBPSCalcTime; //OFS: 0x2D8 SIZE: 0x4
		int iCountedPackets; //OFS: 0x2DC SIZE: 0x4
		int iCountedFragments; //OFS: 0x2E0 SIZE: 0x4
		int iFragmentPercentage; //OFS: 0x2E4 SIZE: 0x4
		int iLargestPacket; //OFS: 0x2E8 SIZE: 0x4
		int iSmallestPacket; //OFS: 0x2EC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(netProfileStream_t, 0x2F0);
	ASSERT_STRUCT_OFFSET(netProfileStream_t, packets, 0x0);
	ASSERT_STRUCT_OFFSET(netProfileStream_t, iCurrPacket, 0x2D0);
	ASSERT_STRUCT_OFFSET(netProfileStream_t, iBytesPerSecond, 0x2D4);
	ASSERT_STRUCT_OFFSET(netProfileStream_t, iLastBPSCalcTime, 0x2D8);
	ASSERT_STRUCT_OFFSET(netProfileStream_t, iCountedPackets, 0x2DC);
	ASSERT_STRUCT_OFFSET(netProfileStream_t, iCountedFragments, 0x2E0);
	ASSERT_STRUCT_OFFSET(netProfileStream_t, iFragmentPercentage, 0x2E4);
	ASSERT_STRUCT_OFFSET(netProfileStream_t, iLargestPacket, 0x2E8);
	ASSERT_STRUCT_OFFSET(netProfileStream_t, iSmallestPacket, 0x2EC);

	struct netProfileInfo_t
	{
		netProfileStream_t send; //OFS: 0x0 SIZE: 0x2F0
		netProfileStream_t recieve; //OFS: 0x2F0 SIZE: 0x2F0
	};
	ASSERT_STRUCT_SIZE(netProfileInfo_t, 0x5E0);
	ASSERT_STRUCT_OFFSET(netProfileInfo_t, send, 0x0);
	ASSERT_STRUCT_OFFSET(netProfileInfo_t, recieve, 0x2F0);

	struct netchan_s
	{
		int outgoingSequence; //OFS: 0x0 SIZE: 0x4
		netsrc_t sock; //OFS: 0x4 SIZE: 0x4
		int dropped; //OFS: 0x8 SIZE: 0x4
		int incomingSequence; //OFS: 0xC SIZE: 0x4
		netadr_s remoteAddress; //OFS: 0x10 SIZE: 0x18
		int qport; //OFS: 0x28 SIZE: 0x4
		int fragmentSequence; //OFS: 0x2C SIZE: 0x4
		int fragmentLength; //OFS: 0x30 SIZE: 0x4
		char * fragmentBuffer; //OFS: 0x34 SIZE: 0x4
		int fragmentBufferSize; //OFS: 0x38 SIZE: 0x4
		int unsentFragments; //OFS: 0x3C SIZE: 0x4
		int unsentFragmentStart; //OFS: 0x40 SIZE: 0x4
		int unsentLength; //OFS: 0x44 SIZE: 0x4
		int unsentBuffer; //OFS: 0x48 SIZE: 0x4
		int unsentBufferSize; //OFS: 0x4C SIZE: 0x4
		int reliable_fragments; //OFS: 0x50 SIZE: 0x4
		char fragment_send_count[128]; //OFS: 0x54 SIZE: 0x80
		int fragment_ack[4]; //OFS: 0xD4 SIZE: 0x10
		int lowest_send_count; //OFS: 0xE4 SIZE: 0x4
		netProfileInfo_t prof; //OFS: 0xE8 SIZE: 0x5E0
	};
	ASSERT_STRUCT_SIZE(netchan_s, 0x6C8);
	ASSERT_STRUCT_OFFSET(netchan_s, outgoingSequence, 0x0);
	ASSERT_STRUCT_OFFSET(netchan_s, sock, 0x4);
	ASSERT_STRUCT_OFFSET(netchan_s, dropped, 0x8);
	ASSERT_STRUCT_OFFSET(netchan_s, incomingSequence, 0xC);
	ASSERT_STRUCT_OFFSET(netchan_s, remoteAddress, 0x10);
	ASSERT_STRUCT_OFFSET(netchan_s, qport, 0x28);
	ASSERT_STRUCT_OFFSET(netchan_s, fragmentSequence, 0x2C);
	ASSERT_STRUCT_OFFSET(netchan_s, fragmentLength, 0x30);
	ASSERT_STRUCT_OFFSET(netchan_s, fragmentBuffer, 0x34);
	ASSERT_STRUCT_OFFSET(netchan_s, fragmentBufferSize, 0x38);
	ASSERT_STRUCT_OFFSET(netchan_s, unsentFragments, 0x3C);
	ASSERT_STRUCT_OFFSET(netchan_s, unsentFragmentStart, 0x40);
	ASSERT_STRUCT_OFFSET(netchan_s, unsentLength, 0x44);
	ASSERT_STRUCT_OFFSET(netchan_s, unsentBuffer, 0x48);
	ASSERT_STRUCT_OFFSET(netchan_s, unsentBufferSize, 0x4C);
	ASSERT_STRUCT_OFFSET(netchan_s, reliable_fragments, 0x50);
	ASSERT_STRUCT_OFFSET(netchan_s, fragment_send_count, 0x54);
	ASSERT_STRUCT_OFFSET(netchan_s, fragment_ack, 0xD4);
	ASSERT_STRUCT_OFFSET(netchan_s, lowest_send_count, 0xE4);
	ASSERT_STRUCT_OFFSET(netchan_s, prof, 0xE8);

	struct clientHeader_s
	{
		clientconn_e state; //OFS: 0x0 SIZE: 0x4
		connstate_t clientReportedState; //OFS: 0x4 SIZE: 0x4
		int huh; //OFS: 0x8 SIZE: 0x4
		int deltaMessage; //OFS: 0xC SIZE: 0x4
		int rateDelayed; //OFS: 0x10 SIZE: 0x4
		netchan_s netchan; //OFS: 0x14 SIZE: 0x6C8
		float predictedOrigin[3]; //OFS: 0x6DC SIZE: 0xC
		int predictedOriginServerTime; //OFS: 0x6E8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(clientHeader_s, 0x6EC);
	ASSERT_STRUCT_OFFSET(clientHeader_s, state, 0x0);
	ASSERT_STRUCT_OFFSET(clientHeader_s, clientReportedState, 0x4);
	ASSERT_STRUCT_OFFSET(clientHeader_s, huh, 0x8);
	ASSERT_STRUCT_OFFSET(clientHeader_s, deltaMessage, 0xC);
	ASSERT_STRUCT_OFFSET(clientHeader_s, rateDelayed, 0x10);
	ASSERT_STRUCT_OFFSET(clientHeader_s, netchan, 0x14);
	ASSERT_STRUCT_OFFSET(clientHeader_s, predictedOrigin, 0x6DC);
	ASSERT_STRUCT_OFFSET(clientHeader_s, predictedOriginServerTime, 0x6E8);

	struct reliableCommands_s
	{
		char cmd[512]; //OFS: 0x0 SIZE: 0x200
		int time; //OFS: 0x200 SIZE: 0x4
		int type; //OFS: 0x204 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(reliableCommands_s, 0x208);
	ASSERT_STRUCT_OFFSET(reliableCommands_s, cmd, 0x0);
	ASSERT_STRUCT_OFFSET(reliableCommands_s, time, 0x200);
	ASSERT_STRUCT_OFFSET(reliableCommands_s, type, 0x204);

	struct clientSnapshot_t
	{
		playerState_s ps; //OFS: 0x0 SIZE: 0x20AC
		int num_entities; //OFS: 0x20AC SIZE: 0x4
		int num_clients; //OFS: 0x20B0 SIZE: 0x4
		int num_actors; //OFS: 0x20B4 SIZE: 0x4
		int first_entity; //OFS: 0x20B8 SIZE: 0x4
		int first_client; //OFS: 0x20BC SIZE: 0x4
		int first_actor; //OFS: 0x20C0 SIZE: 0x4
		int num_animCmds; //OFS: 0x20C4 SIZE: 0x4
		int first_animCmd; //OFS: 0x20C8 SIZE: 0x4
		int messageSent; //OFS: 0x20CC SIZE: 0x4
		int messageAcked; //OFS: 0x20D0 SIZE: 0x4
		int messageSize; //OFS: 0x20D4 SIZE: 0x4
		int field_20D8; //OFS: 0x20D8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(clientSnapshot_t, 0x20DC);
	ASSERT_STRUCT_OFFSET(clientSnapshot_t, ps, 0x0);
	ASSERT_STRUCT_OFFSET(clientSnapshot_t, num_entities, 0x20AC);
	ASSERT_STRUCT_OFFSET(clientSnapshot_t, num_clients, 0x20B0);
	ASSERT_STRUCT_OFFSET(clientSnapshot_t, num_actors, 0x20B4);
	ASSERT_STRUCT_OFFSET(clientSnapshot_t, first_entity, 0x20B8);
	ASSERT_STRUCT_OFFSET(clientSnapshot_t, first_client, 0x20BC);
	ASSERT_STRUCT_OFFSET(clientSnapshot_t, first_actor, 0x20C0);
	ASSERT_STRUCT_OFFSET(clientSnapshot_t, num_animCmds, 0x20C4);
	ASSERT_STRUCT_OFFSET(clientSnapshot_t, first_animCmd, 0x20C8);
	ASSERT_STRUCT_OFFSET(clientSnapshot_t, messageSent, 0x20CC);
	ASSERT_STRUCT_OFFSET(clientSnapshot_t, messageAcked, 0x20D0);
	ASSERT_STRUCT_OFFSET(clientSnapshot_t, messageSize, 0x20D4);
	ASSERT_STRUCT_OFFSET(clientSnapshot_t, field_20D8, 0x20D8);

#pragma pack(push, 1)
	struct __declspec(align(1)) VoicePacket_t
	{
		char talker; //OFS: 0x0 SIZE: 0x1
		char data[256]; //OFS: 0x1 SIZE: 0x100
		int dataSize; //OFS: 0x101 SIZE: 0x4
	};
#pragma pack(pop)
	ASSERT_STRUCT_SIZE(VoicePacket_t, 0x105);
	ASSERT_STRUCT_OFFSET(VoicePacket_t, talker, 0x0);
	ASSERT_STRUCT_OFFSET(VoicePacket_t, data, 0x1);
	ASSERT_STRUCT_OFFSET(VoicePacket_t, dataSize, 0x101);

	struct client_s
	{
		clientHeader_s header; //OFS: 0x0 SIZE: 0x6EC
		char * dropReason; //OFS: 0x6EC SIZE: 0x4
		char userinfo[1536]; //OFS: 0x6F0 SIZE: 0x600
		reliableCommands_s reliableCommands[128]; //OFS: 0xCF0 SIZE: 0x10400
		int reliableSequence; //OFS: 0x110F0 SIZE: 0x4
		int reliableAcknowledge; //OFS: 0x110F4 SIZE: 0x4
		int reliableSent; //OFS: 0x110F8 SIZE: 0x4
		int messageAcknowledge; //OFS: 0x110FC SIZE: 0x4
		int gamestateMessageNum; //OFS: 0x11100 SIZE: 0x4
		int challenge; //OFS: 0x11104 SIZE: 0x4
		usercmd_s lastUsercmd; //OFS: 0x11108 SIZE: 0x38
		int lastClientCommand; //OFS: 0x11140 SIZE: 0x4
		char lastClientCommandString[1024]; //OFS: 0x11144 SIZE: 0x400
		gentity_s * gentity; //OFS: 0x11544 SIZE: 0x4
		char name[32]; //OFS: 0x11548 SIZE: 0x20
		char clanAbbrev[8]; //OFS: 0x11568 SIZE: 0x8
		char downloadName[64]; //OFS: 0x11570 SIZE: 0x40
		int download; //OFS: 0x115B0 SIZE: 0x4
		int downloadSize; //OFS: 0x115B4 SIZE: 0x4
		int downloadCount; //OFS: 0x115B8 SIZE: 0x4
		int downloadClientBlock; //OFS: 0x115BC SIZE: 0x4
		int downloadCurrentBlock; //OFS: 0x115C0 SIZE: 0x4
		int downloadXmitBlock; //OFS: 0x115C4 SIZE: 0x4
		unsigned __int8 * downloadBlocks[8]; //OFS: 0x115C8 SIZE: 0x20
		int downloadBlockSize[8]; //OFS: 0x115E8 SIZE: 0x20
		int downloadEOF; //OFS: 0x11608 SIZE: 0x4
		int downloadSendTime; //OFS: 0x1160C SIZE: 0x4
		int nextReliableTime; //OFS: 0x11610 SIZE: 0x4
		int lastPacketTime; //OFS: 0x11614 SIZE: 0x4
		int lastConnectTime; //OFS: 0x11618 SIZE: 0x4
		int nextSnapshotTime; //OFS: 0x1161C SIZE: 0x4
		int timeoutCount; //OFS: 0x11620 SIZE: 0x4
		clientSnapshot_t frames[16]; //OFS: 0x11624 SIZE: 0x20DC0
		int ping; //OFS: 0x323E4 SIZE: 0x4
		int rate; //OFS: 0x323E8 SIZE: 0x4
		int snapshotMsec; //OFS: 0x323EC SIZE: 0x4
		int pureAuthentic; //OFS: 0x323F0 SIZE: 0x4
		char netchanOutgoingBuffer[131072]; //OFS: 0x323F4 SIZE: 0x20000
		char netchanIncomingBuffer[2048]; //OFS: 0x523F4 SIZE: 0x800
		int guid; //OFS: 0x52BF4 SIZE: 0x4
		int scriptId; //OFS: 0x52BF8 SIZE: 0x4
		int bIsTestClient; //OFS: 0x52BFC SIZE: 0x4
		int serverId; //OFS: 0x52C00 SIZE: 0x4
		VoicePacket_t voicePackets[40]; //OFS: 0x52C04 SIZE: 0x28C8
		int voicePacketCount; //OFS: 0x554CC SIZE: 0x4
		char muteList[4]; //OFS: 0x554D0 SIZE: 0x4
		char sendVoice; //OFS: 0x554D4 SIZE: 0x1
		char stats[8192]; //OFS: 0x554D5 SIZE: 0x2000
		char statPacketsReceived; //OFS: 0x574D5 SIZE: 0x1
		char PBguid[33]; //OFS: 0x574D6 SIZE: 0x21
		char clientPBguid[33]; //OFS: 0x574F7 SIZE: 0x21
		_BYTE gap_57518[6167]; //OFS: 0x57518 SIZE: 0x1817
		char field_0; //OFS: 0x58D2F SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(client_s, 0x58D30);
	ASSERT_STRUCT_OFFSET(client_s, header, 0x0);
	ASSERT_STRUCT_OFFSET(client_s, dropReason, 0x6EC);
	ASSERT_STRUCT_OFFSET(client_s, userinfo, 0x6F0);
	ASSERT_STRUCT_OFFSET(client_s, reliableCommands, 0xCF0);
	ASSERT_STRUCT_OFFSET(client_s, reliableSequence, 0x110F0);
	ASSERT_STRUCT_OFFSET(client_s, reliableAcknowledge, 0x110F4);
	ASSERT_STRUCT_OFFSET(client_s, reliableSent, 0x110F8);
	ASSERT_STRUCT_OFFSET(client_s, messageAcknowledge, 0x110FC);
	ASSERT_STRUCT_OFFSET(client_s, gamestateMessageNum, 0x11100);
	ASSERT_STRUCT_OFFSET(client_s, challenge, 0x11104);
	ASSERT_STRUCT_OFFSET(client_s, lastUsercmd, 0x11108);
	ASSERT_STRUCT_OFFSET(client_s, lastClientCommand, 0x11140);
	ASSERT_STRUCT_OFFSET(client_s, lastClientCommandString, 0x11144);
	ASSERT_STRUCT_OFFSET(client_s, gentity, 0x11544);
	ASSERT_STRUCT_OFFSET(client_s, name, 0x11548);
	ASSERT_STRUCT_OFFSET(client_s, clanAbbrev, 0x11568);
	ASSERT_STRUCT_OFFSET(client_s, downloadName, 0x11570);
	ASSERT_STRUCT_OFFSET(client_s, download, 0x115B0);
	ASSERT_STRUCT_OFFSET(client_s, downloadSize, 0x115B4);
	ASSERT_STRUCT_OFFSET(client_s, downloadCount, 0x115B8);
	ASSERT_STRUCT_OFFSET(client_s, downloadClientBlock, 0x115BC);
	ASSERT_STRUCT_OFFSET(client_s, downloadCurrentBlock, 0x115C0);
	ASSERT_STRUCT_OFFSET(client_s, downloadXmitBlock, 0x115C4);
	ASSERT_STRUCT_OFFSET(client_s, downloadBlocks, 0x115C8);
	ASSERT_STRUCT_OFFSET(client_s, downloadBlockSize, 0x115E8);
	ASSERT_STRUCT_OFFSET(client_s, downloadEOF, 0x11608);
	ASSERT_STRUCT_OFFSET(client_s, downloadSendTime, 0x1160C);
	ASSERT_STRUCT_OFFSET(client_s, nextReliableTime, 0x11610);
	ASSERT_STRUCT_OFFSET(client_s, lastPacketTime, 0x11614);
	ASSERT_STRUCT_OFFSET(client_s, lastConnectTime, 0x11618);
	ASSERT_STRUCT_OFFSET(client_s, nextSnapshotTime, 0x1161C);
	ASSERT_STRUCT_OFFSET(client_s, timeoutCount, 0x11620);
	ASSERT_STRUCT_OFFSET(client_s, frames, 0x11624);
	ASSERT_STRUCT_OFFSET(client_s, ping, 0x323E4);
	ASSERT_STRUCT_OFFSET(client_s, rate, 0x323E8);
	ASSERT_STRUCT_OFFSET(client_s, snapshotMsec, 0x323EC);
	ASSERT_STRUCT_OFFSET(client_s, pureAuthentic, 0x323F0);
	ASSERT_STRUCT_OFFSET(client_s, netchanOutgoingBuffer, 0x323F4);
	ASSERT_STRUCT_OFFSET(client_s, netchanIncomingBuffer, 0x523F4);
	ASSERT_STRUCT_OFFSET(client_s, guid, 0x52BF4);
	ASSERT_STRUCT_OFFSET(client_s, scriptId, 0x52BF8);
	ASSERT_STRUCT_OFFSET(client_s, bIsTestClient, 0x52BFC);
	ASSERT_STRUCT_OFFSET(client_s, serverId, 0x52C00);
	ASSERT_STRUCT_OFFSET(client_s, voicePackets, 0x52C04);
	ASSERT_STRUCT_OFFSET(client_s, voicePacketCount, 0x554CC);
	ASSERT_STRUCT_OFFSET(client_s, muteList, 0x554D0);
	ASSERT_STRUCT_OFFSET(client_s, sendVoice, 0x554D4);
	ASSERT_STRUCT_OFFSET(client_s, stats, 0x554D5);
	ASSERT_STRUCT_OFFSET(client_s, statPacketsReceived, 0x574D5);
	ASSERT_STRUCT_OFFSET(client_s, PBguid, 0x574D6);
	ASSERT_STRUCT_OFFSET(client_s, clientPBguid, 0x574F7);
	ASSERT_STRUCT_OFFSET(client_s, gap_57518, 0x57518);
	ASSERT_STRUCT_OFFSET(client_s, field_0, 0x58D2F);

	union UILocalVar_u
	{
		int integer; //OFS: 0x0 SIZE: 0x4
		float value; //OFS: 0x1 SIZE: 0x4
		const char * string; //OFS: 0x2 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(UILocalVar_u, 0x4);

	struct UILocalVar
	{
		UILocalVarType type; //OFS: 0x0 SIZE: 0x4
		const char * name; //OFS: 0x4 SIZE: 0x4
		UILocalVar_u u; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(UILocalVar, 0xC);
	ASSERT_STRUCT_OFFSET(UILocalVar, type, 0x0);
	ASSERT_STRUCT_OFFSET(UILocalVar, name, 0x4);
	ASSERT_STRUCT_OFFSET(UILocalVar, u, 0x8);

	struct UILocalVarContext
	{
		UILocalVar table[256]; //OFS: 0x0 SIZE: 0xC00
	};
	ASSERT_STRUCT_SIZE(UILocalVarContext, 0xC00);
	ASSERT_STRUCT_OFFSET(UILocalVarContext, table, 0x0);

	struct UiContext
	{
		int contextIndex; //OFS: 0x0 SIZE: 0x4
		float bias; //OFS: 0x4 SIZE: 0x4
		int realTime; //OFS: 0x8 SIZE: 0x4
		int frameTime; //OFS: 0xC SIZE: 0x4
		float cur_x; //OFS: 0x10 SIZE: 0x4
		float cur_y; //OFS: 0x14 SIZE: 0x4
		int isCursorVisible; //OFS: 0x18 SIZE: 0x4
		int screenWidth; //OFS: 0x1C SIZE: 0x4
		int screenHeight; //OFS: 0x20 SIZE: 0x4
		float screenAspect; //OFS: 0x24 SIZE: 0x4
		float FPS; //OFS: 0x28 SIZE: 0x4
		float blurRadiusOut; //OFS: 0x2C SIZE: 0x4
		menuDef_t * Menus[512]; //OFS: 0x30 SIZE: 0x800
		int menuCount; //OFS: 0x830 SIZE: 0x4
		menuDef_t * menuStack[16]; //OFS: 0x834 SIZE: 0x40
		int openMenuCount; //OFS: 0x874 SIZE: 0x4
		UILocalVarContext localVars; //OFS: 0x878 SIZE: 0xC00
		StringTable * cinematicSubtitles; //OFS: 0x1478 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(UiContext, 0x147C);
	ASSERT_STRUCT_OFFSET(UiContext, contextIndex, 0x0);
	ASSERT_STRUCT_OFFSET(UiContext, bias, 0x4);
	ASSERT_STRUCT_OFFSET(UiContext, realTime, 0x8);
	ASSERT_STRUCT_OFFSET(UiContext, frameTime, 0xC);
	ASSERT_STRUCT_OFFSET(UiContext, cur_x, 0x10);
	ASSERT_STRUCT_OFFSET(UiContext, cur_y, 0x14);
	ASSERT_STRUCT_OFFSET(UiContext, isCursorVisible, 0x18);
	ASSERT_STRUCT_OFFSET(UiContext, screenWidth, 0x1C);
	ASSERT_STRUCT_OFFSET(UiContext, screenHeight, 0x20);
	ASSERT_STRUCT_OFFSET(UiContext, screenAspect, 0x24);
	ASSERT_STRUCT_OFFSET(UiContext, FPS, 0x28);
	ASSERT_STRUCT_OFFSET(UiContext, blurRadiusOut, 0x2C);
	ASSERT_STRUCT_OFFSET(UiContext, Menus, 0x30);
	ASSERT_STRUCT_OFFSET(UiContext, menuCount, 0x830);
	ASSERT_STRUCT_OFFSET(UiContext, menuStack, 0x834);
	ASSERT_STRUCT_OFFSET(UiContext, openMenuCount, 0x874);
	ASSERT_STRUCT_OFFSET(UiContext, localVars, 0x878);
	ASSERT_STRUCT_OFFSET(UiContext, cinematicSubtitles, 0x1478);

	union cpose_u
	{
		char pad[136]; //OFS: 0x0 SIZE: 0x88
	};
	ASSERT_STRUCT_SIZE(cpose_u, 0x88);

	struct cpose_t
	{
		unsigned __int16 lightingHandle; //OFS: 0x0 SIZE: 0x2
		unsigned __int8 eType; //OFS: 0x2 SIZE: 0x1
		unsigned __int8 eTypeUnion; //OFS: 0x3 SIZE: 0x1
		unsigned __int8 localClientNum; //OFS: 0x4 SIZE: 0x1
		bool isRagdoll; //OFS: 0x5 SIZE: 0x1
		int ragdollHandle; //OFS: 0x8 SIZE: 0x4
		int physObjId; //OFS: 0xC SIZE: 0x4
		int physUserBody; //OFS: 0x10 SIZE: 0x4
		unsigned __int8 destructiblePose; //OFS: 0x14 SIZE: 0x1
		int startBurnTime; //OFS: 0x18 SIZE: 0x4
		float wetness; //OFS: 0x1C SIZE: 0x4
		int cullIn; //OFS: 0x20 SIZE: 0x4
		float origin[3]; //OFS: 0x24 SIZE: 0xC
		float angles[3]; //OFS: 0x30 SIZE: 0xC
		float mins[3]; //OFS: 0x3C SIZE: 0xC
		cpose_u u; //OFS: 0x48 SIZE: 0x88
	};
	ASSERT_STRUCT_SIZE(cpose_t, 0xD0);
	ASSERT_STRUCT_OFFSET(cpose_t, lightingHandle, 0x0);
	ASSERT_STRUCT_OFFSET(cpose_t, eType, 0x2);
	ASSERT_STRUCT_OFFSET(cpose_t, eTypeUnion, 0x3);
	ASSERT_STRUCT_OFFSET(cpose_t, localClientNum, 0x4);
	ASSERT_STRUCT_OFFSET(cpose_t, isRagdoll, 0x5);
	ASSERT_STRUCT_OFFSET(cpose_t, ragdollHandle, 0x8);
	ASSERT_STRUCT_OFFSET(cpose_t, physObjId, 0xC);
	ASSERT_STRUCT_OFFSET(cpose_t, physUserBody, 0x10);
	ASSERT_STRUCT_OFFSET(cpose_t, destructiblePose, 0x14);
	ASSERT_STRUCT_OFFSET(cpose_t, startBurnTime, 0x18);
	ASSERT_STRUCT_OFFSET(cpose_t, wetness, 0x1C);
	ASSERT_STRUCT_OFFSET(cpose_t, cullIn, 0x20);
	ASSERT_STRUCT_OFFSET(cpose_t, origin, 0x24);
	ASSERT_STRUCT_OFFSET(cpose_t, angles, 0x30);
	ASSERT_STRUCT_OFFSET(cpose_t, mins, 0x3C);
	ASSERT_STRUCT_OFFSET(cpose_t, u, 0x48);

	struct canimscripted_s
	{
		float axis[4][3]; //OFS: 0x0 SIZE: 0x30
		unsigned __int16 anim; //OFS: 0x30 SIZE: 0x2
		unsigned __int8 bStarted; //OFS: 0x32 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(canimscripted_s, 0x34);
	ASSERT_STRUCT_OFFSET(canimscripted_s, axis, 0x0);
	ASSERT_STRUCT_OFFSET(canimscripted_s, anim, 0x30);
	ASSERT_STRUCT_OFFSET(canimscripted_s, bStarted, 0x32);

	struct cLinkInfo_s
	{
		float axis[4][3]; //OFS: 0x0 SIZE: 0x30
		int linkEnt; //OFS: 0x30 SIZE: 0x4
		int linkTag; //OFS: 0x34 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(cLinkInfo_s, 0x38);
	ASSERT_STRUCT_OFFSET(cLinkInfo_s, axis, 0x0);
	ASSERT_STRUCT_OFFSET(cLinkInfo_s, linkEnt, 0x30);
	ASSERT_STRUCT_OFFSET(cLinkInfo_s, linkTag, 0x34);

	struct cgVehicle_s
	{
		int lastGunnerFire[4]; //OFS: 0x0 SIZE: 0x10
		int wheelSurfType[6]; //OFS: 0x10 SIZE: 0x18
		float materialTime; //OFS: 0x28 SIZE: 0x4
		vehicle_cache_t * vehicle_cache; //OFS: 0x2C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(cgVehicle_s, 0x30);
	ASSERT_STRUCT_OFFSET(cgVehicle_s, lastGunnerFire, 0x0);
	ASSERT_STRUCT_OFFSET(cgVehicle_s, wheelSurfType, 0x10);
	ASSERT_STRUCT_OFFSET(cgVehicle_s, materialTime, 0x28);
	ASSERT_STRUCT_OFFSET(cgVehicle_s, vehicle_cache, 0x2C);

	struct centity_s
	{
		cpose_t pose; //OFS: 0x0 SIZE: 0xD0
		entityState_s nextState; //OFS: 0xD0 SIZE: 0x118
		LerpEntityState currentState; //OFS: 0x1E8 SIZE: 0x8C
		int previousEventSequence; //OFS: 0x274 SIZE: 0x4
		int miscTime; //OFS: 0x278 SIZE: 0x4
		int lastMuzzleFlash; //OFS: 0x27C SIZE: 0x4
		float lightingOrigin[3]; //OFS: 0x280 SIZE: 0xC
		XAnimTree_s * tree; //OFS: 0x28C SIZE: 0x4
		Destructible * destructible; //OFS: 0x290 SIZE: 0x4
		NitrousVehicle * nitrousVeh; //OFS: 0x294 SIZE: 0x4
		canimscripted_s * scripted; //OFS: 0x298 SIZE: 0x4
		cLinkInfo_s * linkInfo; //OFS: 0x29C SIZE: 0x4
		cgVehicle_s * vehicleInfo; //OFS: 0x2A0 SIZE: 0x4
		int nextRippleTime; //OFS: 0x2A4 SIZE: 0x4
		int numBulletImpacts; //OFS: 0x2A8 SIZE: 0x4
		unsigned __int16 attachModelNames[2]; //OFS: 0x2AC SIZE: 0x4
		unsigned __int16 attachTagNames[2]; //OFS: 0x2B0 SIZE: 0x4
		float originError[3]; //OFS: 0x2B4 SIZE: 0xC
		float anglesError[3]; //OFS: 0x2C0 SIZE: 0xC
		int firstAnimationTime; //OFS: 0x2CC SIZE: 0x4
		__int16 _bf_2d0; //OFS: 0x2D0 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(centity_s, 0x2D4);
	ASSERT_STRUCT_OFFSET(centity_s, pose, 0x0);
	ASSERT_STRUCT_OFFSET(centity_s, nextState, 0xD0);
	ASSERT_STRUCT_OFFSET(centity_s, currentState, 0x1E8);
	ASSERT_STRUCT_OFFSET(centity_s, previousEventSequence, 0x274);
	ASSERT_STRUCT_OFFSET(centity_s, miscTime, 0x278);
	ASSERT_STRUCT_OFFSET(centity_s, lastMuzzleFlash, 0x27C);
	ASSERT_STRUCT_OFFSET(centity_s, lightingOrigin, 0x280);
	ASSERT_STRUCT_OFFSET(centity_s, tree, 0x28C);
	ASSERT_STRUCT_OFFSET(centity_s, destructible, 0x290);
	ASSERT_STRUCT_OFFSET(centity_s, nitrousVeh, 0x294);
	ASSERT_STRUCT_OFFSET(centity_s, scripted, 0x298);
	ASSERT_STRUCT_OFFSET(centity_s, linkInfo, 0x29C);
	ASSERT_STRUCT_OFFSET(centity_s, vehicleInfo, 0x2A0);
	ASSERT_STRUCT_OFFSET(centity_s, nextRippleTime, 0x2A4);
	ASSERT_STRUCT_OFFSET(centity_s, numBulletImpacts, 0x2A8);
	ASSERT_STRUCT_OFFSET(centity_s, attachModelNames, 0x2AC);
	ASSERT_STRUCT_OFFSET(centity_s, attachTagNames, 0x2B0);
	ASSERT_STRUCT_OFFSET(centity_s, originError, 0x2B4);
	ASSERT_STRUCT_OFFSET(centity_s, anglesError, 0x2C0);
	ASSERT_STRUCT_OFFSET(centity_s, firstAnimationTime, 0x2CC);
	ASSERT_STRUCT_OFFSET(centity_s, _bf_2d0, 0x2D0);

	struct clSnapshot_s
	{
		int valid; //OFS: 0x0 SIZE: 0x4
		int snapFlags; //OFS: 0x4 SIZE: 0x4
		int serverTime; //OFS: 0x8 SIZE: 0x4
		int messageNum; //OFS: 0xC SIZE: 0x4
		int deltaNum; //OFS: 0x10 SIZE: 0x4
		int ping; //OFS: 0x14 SIZE: 0x4
		int whatistthis; //OFS: 0x18 SIZE: 0x4
		playerState_s ps; //OFS: 0x1C SIZE: 0x20AC
		int numEntities; //OFS: 0x20C8 SIZE: 0x4
		int numClients; //OFS: 0x20CC SIZE: 0x4
		int numActors; //OFS: 0x20D0 SIZE: 0x4
		int parseEntitiesNum; //OFS: 0x20D4 SIZE: 0x4
		int parseClientsNum; //OFS: 0x20D8 SIZE: 0x4
		int parseActorsNum; //OFS: 0x20DC SIZE: 0x4
		int parseAnimCmdsNum; //OFS: 0x20E0 SIZE: 0x4
		int numAnimCmds; //OFS: 0x20E4 SIZE: 0x4
		int serverCommandSequence; //OFS: 0x20E8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(clSnapshot_s, 0x20EC);
	ASSERT_STRUCT_OFFSET(clSnapshot_s, valid, 0x0);
	ASSERT_STRUCT_OFFSET(clSnapshot_s, snapFlags, 0x4);
	ASSERT_STRUCT_OFFSET(clSnapshot_s, serverTime, 0x8);
	ASSERT_STRUCT_OFFSET(clSnapshot_s, messageNum, 0xC);
	ASSERT_STRUCT_OFFSET(clSnapshot_s, deltaNum, 0x10);
	ASSERT_STRUCT_OFFSET(clSnapshot_s, ping, 0x14);
	ASSERT_STRUCT_OFFSET(clSnapshot_s, whatistthis, 0x18);
	ASSERT_STRUCT_OFFSET(clSnapshot_s, ps, 0x1C);
	ASSERT_STRUCT_OFFSET(clSnapshot_s, numEntities, 0x20C8);
	ASSERT_STRUCT_OFFSET(clSnapshot_s, numClients, 0x20CC);
	ASSERT_STRUCT_OFFSET(clSnapshot_s, numActors, 0x20D0);
	ASSERT_STRUCT_OFFSET(clSnapshot_s, parseEntitiesNum, 0x20D4);
	ASSERT_STRUCT_OFFSET(clSnapshot_s, parseClientsNum, 0x20D8);
	ASSERT_STRUCT_OFFSET(clSnapshot_s, parseActorsNum, 0x20DC);
	ASSERT_STRUCT_OFFSET(clSnapshot_s, parseAnimCmdsNum, 0x20E0);
	ASSERT_STRUCT_OFFSET(clSnapshot_s, numAnimCmds, 0x20E4);
	ASSERT_STRUCT_OFFSET(clSnapshot_s, serverCommandSequence, 0x20E8);

	struct gameState_s
	{
		int stringOffsets[3056]; //OFS: 0x0 SIZE: 0x2FC0
		char stringData[131072]; //OFS: 0x2FC0 SIZE: 0x20000
		int dataCount; //OFS: 0x22FC0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(gameState_s, 0x22FC4);
	ASSERT_STRUCT_OFFSET(gameState_s, stringOffsets, 0x0);
	ASSERT_STRUCT_OFFSET(gameState_s, stringData, 0x2FC0);
	ASSERT_STRUCT_OFFSET(gameState_s, dataCount, 0x22FC0);

	struct ClientArchiveData
	{
		int serverTime; //OFS: 0x0 SIZE: 0x4
		float origin[3]; //OFS: 0x4 SIZE: 0xC
		float velocity[3]; //OFS: 0x10 SIZE: 0xC
		int bobCycle; //OFS: 0x1C SIZE: 0x4
		int movementDir; //OFS: 0x20 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ClientArchiveData, 0x24);
	ASSERT_STRUCT_OFFSET(ClientArchiveData, serverTime, 0x0);
	ASSERT_STRUCT_OFFSET(ClientArchiveData, origin, 0x4);
	ASSERT_STRUCT_OFFSET(ClientArchiveData, velocity, 0x10);
	ASSERT_STRUCT_OFFSET(ClientArchiveData, bobCycle, 0x1C);
	ASSERT_STRUCT_OFFSET(ClientArchiveData, movementDir, 0x20);

	struct outPacket_t
	{
		int p_cmdNumber; //OFS: 0x0 SIZE: 0x4
		int p_serverTime; //OFS: 0x4 SIZE: 0x4
		int p_realtime; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(outPacket_t, 0xC);
	ASSERT_STRUCT_OFFSET(outPacket_t, p_cmdNumber, 0x0);
	ASSERT_STRUCT_OFFSET(outPacket_t, p_serverTime, 0x4);
	ASSERT_STRUCT_OFFSET(outPacket_t, p_realtime, 0x8);

	struct animCmdState_s
	{
		int field_0; //OFS: 0x0 SIZE: 0x4
		int field_4; //OFS: 0x4 SIZE: 0x4
		int field_8; //OFS: 0x8 SIZE: 0x4
		int field_C; //OFS: 0xC SIZE: 0x4
		int field_10; //OFS: 0x10 SIZE: 0x4
		int field_14; //OFS: 0x14 SIZE: 0x4
		int field_18; //OFS: 0x18 SIZE: 0x4
		int field_1C; //OFS: 0x1C SIZE: 0x4
		int field_20; //OFS: 0x20 SIZE: 0x4
		int field_24; //OFS: 0x24 SIZE: 0x4
		int field_28; //OFS: 0x28 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(animCmdState_s, 0x2C);
	ASSERT_STRUCT_OFFSET(animCmdState_s, field_0, 0x0);
	ASSERT_STRUCT_OFFSET(animCmdState_s, field_4, 0x4);
	ASSERT_STRUCT_OFFSET(animCmdState_s, field_8, 0x8);
	ASSERT_STRUCT_OFFSET(animCmdState_s, field_C, 0xC);
	ASSERT_STRUCT_OFFSET(animCmdState_s, field_10, 0x10);
	ASSERT_STRUCT_OFFSET(animCmdState_s, field_14, 0x14);
	ASSERT_STRUCT_OFFSET(animCmdState_s, field_18, 0x18);
	ASSERT_STRUCT_OFFSET(animCmdState_s, field_1C, 0x1C);
	ASSERT_STRUCT_OFFSET(animCmdState_s, field_20, 0x20);
	ASSERT_STRUCT_OFFSET(animCmdState_s, field_24, 0x24);
	ASSERT_STRUCT_OFFSET(animCmdState_s, field_28, 0x28);

	struct clientActive_s
	{
		char usingAds; //OFS: 0x0 SIZE: 0x1
		int timeoutcount; //OFS: 0x4 SIZE: 0x4
		clSnapshot_s snap; //OFS: 0x8 SIZE: 0x20EC
		char alwaysFalse; //OFS: 0x20F4 SIZE: 0x1
		int serverTime; //OFS: 0x20F8 SIZE: 0x4
		int oldServerTime; //OFS: 0x20FC SIZE: 0x4
		int oldFrameServerTime; //OFS: 0x2100 SIZE: 0x4
		int serverTimeDelta; //OFS: 0x2104 SIZE: 0x4
		int oldSnapServerTime; //OFS: 0x2108 SIZE: 0x4
		int extrapolatedSnapshot; //OFS: 0x210C SIZE: 0x4
		int newSnapshots; //OFS: 0x2110 SIZE: 0x4
		gameState_s gameState; //OFS: 0x2114 SIZE: 0x22FC4
		char mapname[64]; //OFS: 0x250D8 SIZE: 0x40
		int parseEntitiesNum; //OFS: 0x25118 SIZE: 0x4
		int parseClientsNum; //OFS: 0x2511C SIZE: 0x4
		int parseActorsNum; //OFS: 0x25120 SIZE: 0x4
		int parseAnimCmdsNum; //OFS: 0x25124 SIZE: 0x4
		int mouseDx[2]; //OFS: 0x25128 SIZE: 0x8
		int mouseDy[2]; //OFS: 0x25130 SIZE: 0x8
		int mouseIndex; //OFS: 0x25138 SIZE: 0x4
		char stanceHeld; //OFS: 0x2513C SIZE: 0x1
		StanceState stance; //OFS: 0x25140 SIZE: 0x4
		StanceState stancePosition; //OFS: 0x25144 SIZE: 0x4
		int stanceTime; //OFS: 0x25148 SIZE: 0x4
		int cgameUserCmdWeapon; //OFS: 0x2514C SIZE: 0x4
		int cgameUserCmdOffHandIndex; //OFS: 0x25150 SIZE: 0x4
		int cgameUserCmdGunPitch; //OFS: 0x25154 SIZE: 0x4
		int cgameUserCmdGunYaw; //OFS: 0x25158 SIZE: 0x4
		int field_2515C; //OFS: 0x2515C SIZE: 0x4
		int field_25160; //OFS: 0x25160 SIZE: 0x4
		int field_25164; //OFS: 0x25164 SIZE: 0x4
		int cgameFOVSensitivityScale; //OFS: 0x25168 SIZE: 0x4
		float cgameMaxPitchSpeed; //OFS: 0x2516C SIZE: 0x4
		float cgameMaxYawSpeed; //OFS: 0x25170 SIZE: 0x4
		float cgameKickAngles[3]; //OFS: 0x25174 SIZE: 0xC
		float cgameOrigin[3]; //OFS: 0x25180 SIZE: 0xC
		float cgameVelocity[3]; //OFS: 0x2518C SIZE: 0xC
		int cgameBobCycle; //OFS: 0x25198 SIZE: 0x4
		int cgameMovementDir; //OFS: 0x2519C SIZE: 0x4
		int cgameExtraButtons; //OFS: 0x251A0 SIZE: 0x4
		int cgamePredictedDataServerTime; //OFS: 0x251A4 SIZE: 0x4
		float viewangles[3]; //OFS: 0x251A8 SIZE: 0xC
		int serverId; //OFS: 0x251B4 SIZE: 0x4
		int bCmdForceValues; //OFS: 0x251B8 SIZE: 0x4
		int iForceButtons; //OFS: 0x251BC SIZE: 0x4
		int iForceWeapon; //OFS: 0x251C0 SIZE: 0x4
		int forceOffhand; //OFS: 0x251C4 SIZE: 0x4
		int skelTimeStamp; //OFS: 0x251C8 SIZE: 0x4
		int skelMemPos; //OFS: 0x251CC SIZE: 0x4
		char skelMemory[524288]; //OFS: 0x251D0 SIZE: 0x80000
		int skelMemoryStart; //OFS: 0xA51D0 SIZE: 0x4
		char allowedAllocSkel; //OFS: 0xA51D4 SIZE: 0x1
		usercmd_s cmds[128]; //OFS: 0xA51D8 SIZE: 0x1C00
		int cmdNumber; //OFS: 0xA6DD8 SIZE: 0x4
		ClientArchiveData clientArchive[256]; //OFS: 0xA6DDC SIZE: 0x2400
		int clientArchiveIndex; //OFS: 0xA91DC SIZE: 0x4
		outPacket_t outPackets[16]; //OFS: 0xA91E0 SIZE: 0xC0
		clSnapshot_s snapshots[16]; //OFS: 0xA92A0 SIZE: 0x20EC0
		entityState_s entityBaselines[1023]; //OFS: 0xCA160 SIZE: 0x45EE8
		entityState_s cachedEntityBaselines[351]; //OFS: 0x110048 SIZE: 0x17FE8
		entityState_s parseEntities[4096]; //OFS: 0x128030 SIZE: 0x118000
		entityState_s * parseEntitiesPtr; //OFS: 0x240030 SIZE: 0x4
		int maxEntities; //OFS: 0x240034 SIZE: 0x4
		clientState_s parseClients[64]; //OFS: 0x240038 SIZE: 0x2500
		clientState_s * parseClientsPtr; //OFS: 0x242538 SIZE: 0x4
		int maxClientStates; //OFS: 0x24253C SIZE: 0x4
		actorState_s parseActors[512]; //OFS: 0x242540 SIZE: 0xF000
		actorState_s * parseActorsPtr; //OFS: 0x251540 SIZE: 0x4
		int maxActorStates; //OFS: 0x251544 SIZE: 0x4
		animCmdState_s parseAnimCmds[16384]; //OFS: 0x251548 SIZE: 0xB0000
		animCmdState_s * parseAnimCmdsPtr; //OFS: 0x301548 SIZE: 0x4
		int maxAnimCmds; //OFS: 0x30154C SIZE: 0x4
		int corruptedTranslationFile; //OFS: 0x301550 SIZE: 0x4
		char translationVersion[256]; //OFS: 0x301554 SIZE: 0x100
	};
	ASSERT_STRUCT_SIZE(clientActive_s, 0x301654);
	ASSERT_STRUCT_OFFSET(clientActive_s, usingAds, 0x0);
	ASSERT_STRUCT_OFFSET(clientActive_s, timeoutcount, 0x4);
	ASSERT_STRUCT_OFFSET(clientActive_s, snap, 0x8);
	ASSERT_STRUCT_OFFSET(clientActive_s, alwaysFalse, 0x20F4);
	ASSERT_STRUCT_OFFSET(clientActive_s, serverTime, 0x20F8);
	ASSERT_STRUCT_OFFSET(clientActive_s, oldServerTime, 0x20FC);
	ASSERT_STRUCT_OFFSET(clientActive_s, oldFrameServerTime, 0x2100);
	ASSERT_STRUCT_OFFSET(clientActive_s, serverTimeDelta, 0x2104);
	ASSERT_STRUCT_OFFSET(clientActive_s, oldSnapServerTime, 0x2108);
	ASSERT_STRUCT_OFFSET(clientActive_s, extrapolatedSnapshot, 0x210C);
	ASSERT_STRUCT_OFFSET(clientActive_s, newSnapshots, 0x2110);
	ASSERT_STRUCT_OFFSET(clientActive_s, gameState, 0x2114);
	ASSERT_STRUCT_OFFSET(clientActive_s, mapname, 0x250D8);
	ASSERT_STRUCT_OFFSET(clientActive_s, parseEntitiesNum, 0x25118);
	ASSERT_STRUCT_OFFSET(clientActive_s, parseClientsNum, 0x2511C);
	ASSERT_STRUCT_OFFSET(clientActive_s, parseActorsNum, 0x25120);
	ASSERT_STRUCT_OFFSET(clientActive_s, parseAnimCmdsNum, 0x25124);
	ASSERT_STRUCT_OFFSET(clientActive_s, mouseDx, 0x25128);
	ASSERT_STRUCT_OFFSET(clientActive_s, mouseDy, 0x25130);
	ASSERT_STRUCT_OFFSET(clientActive_s, mouseIndex, 0x25138);
	ASSERT_STRUCT_OFFSET(clientActive_s, stanceHeld, 0x2513C);
	ASSERT_STRUCT_OFFSET(clientActive_s, stance, 0x25140);
	ASSERT_STRUCT_OFFSET(clientActive_s, stancePosition, 0x25144);
	ASSERT_STRUCT_OFFSET(clientActive_s, stanceTime, 0x25148);
	ASSERT_STRUCT_OFFSET(clientActive_s, cgameUserCmdWeapon, 0x2514C);
	ASSERT_STRUCT_OFFSET(clientActive_s, cgameUserCmdOffHandIndex, 0x25150);
	ASSERT_STRUCT_OFFSET(clientActive_s, cgameUserCmdGunPitch, 0x25154);
	ASSERT_STRUCT_OFFSET(clientActive_s, cgameUserCmdGunYaw, 0x25158);
	ASSERT_STRUCT_OFFSET(clientActive_s, field_2515C, 0x2515C);
	ASSERT_STRUCT_OFFSET(clientActive_s, field_25160, 0x25160);
	ASSERT_STRUCT_OFFSET(clientActive_s, field_25164, 0x25164);
	ASSERT_STRUCT_OFFSET(clientActive_s, cgameFOVSensitivityScale, 0x25168);
	ASSERT_STRUCT_OFFSET(clientActive_s, cgameMaxPitchSpeed, 0x2516C);
	ASSERT_STRUCT_OFFSET(clientActive_s, cgameMaxYawSpeed, 0x25170);
	ASSERT_STRUCT_OFFSET(clientActive_s, cgameKickAngles, 0x25174);
	ASSERT_STRUCT_OFFSET(clientActive_s, cgameOrigin, 0x25180);
	ASSERT_STRUCT_OFFSET(clientActive_s, cgameVelocity, 0x2518C);
	ASSERT_STRUCT_OFFSET(clientActive_s, cgameBobCycle, 0x25198);
	ASSERT_STRUCT_OFFSET(clientActive_s, cgameMovementDir, 0x2519C);
	ASSERT_STRUCT_OFFSET(clientActive_s, cgameExtraButtons, 0x251A0);
	ASSERT_STRUCT_OFFSET(clientActive_s, cgamePredictedDataServerTime, 0x251A4);
	ASSERT_STRUCT_OFFSET(clientActive_s, viewangles, 0x251A8);
	ASSERT_STRUCT_OFFSET(clientActive_s, serverId, 0x251B4);
	ASSERT_STRUCT_OFFSET(clientActive_s, bCmdForceValues, 0x251B8);
	ASSERT_STRUCT_OFFSET(clientActive_s, iForceButtons, 0x251BC);
	ASSERT_STRUCT_OFFSET(clientActive_s, iForceWeapon, 0x251C0);
	ASSERT_STRUCT_OFFSET(clientActive_s, forceOffhand, 0x251C4);
	ASSERT_STRUCT_OFFSET(clientActive_s, skelTimeStamp, 0x251C8);
	ASSERT_STRUCT_OFFSET(clientActive_s, skelMemPos, 0x251CC);
	ASSERT_STRUCT_OFFSET(clientActive_s, skelMemory, 0x251D0);
	ASSERT_STRUCT_OFFSET(clientActive_s, skelMemoryStart, 0xA51D0);
	ASSERT_STRUCT_OFFSET(clientActive_s, allowedAllocSkel, 0xA51D4);
	ASSERT_STRUCT_OFFSET(clientActive_s, cmds, 0xA51D8);
	ASSERT_STRUCT_OFFSET(clientActive_s, cmdNumber, 0xA6DD8);
	ASSERT_STRUCT_OFFSET(clientActive_s, clientArchive, 0xA6DDC);
	ASSERT_STRUCT_OFFSET(clientActive_s, clientArchiveIndex, 0xA91DC);
	ASSERT_STRUCT_OFFSET(clientActive_s, outPackets, 0xA91E0);
	ASSERT_STRUCT_OFFSET(clientActive_s, snapshots, 0xA92A0);
	ASSERT_STRUCT_OFFSET(clientActive_s, entityBaselines, 0xCA160);
	ASSERT_STRUCT_OFFSET(clientActive_s, cachedEntityBaselines, 0x110048);
	ASSERT_STRUCT_OFFSET(clientActive_s, parseEntities, 0x128030);
	ASSERT_STRUCT_OFFSET(clientActive_s, parseEntitiesPtr, 0x240030);
	ASSERT_STRUCT_OFFSET(clientActive_s, maxEntities, 0x240034);
	ASSERT_STRUCT_OFFSET(clientActive_s, parseClients, 0x240038);
	ASSERT_STRUCT_OFFSET(clientActive_s, parseClientsPtr, 0x242538);
	ASSERT_STRUCT_OFFSET(clientActive_s, maxClientStates, 0x24253C);
	ASSERT_STRUCT_OFFSET(clientActive_s, parseActors, 0x242540);
	ASSERT_STRUCT_OFFSET(clientActive_s, parseActorsPtr, 0x251540);
	ASSERT_STRUCT_OFFSET(clientActive_s, maxActorStates, 0x251544);
	ASSERT_STRUCT_OFFSET(clientActive_s, parseAnimCmds, 0x251548);
	ASSERT_STRUCT_OFFSET(clientActive_s, parseAnimCmdsPtr, 0x301548);
	ASSERT_STRUCT_OFFSET(clientActive_s, maxAnimCmds, 0x30154C);
	ASSERT_STRUCT_OFFSET(clientActive_s, corruptedTranslationFile, 0x301550);
	ASSERT_STRUCT_OFFSET(clientActive_s, translationVersion, 0x301554);

	struct shellshock_parms_t_screenBlend
	{
		int blurredFadeTime; //OFS: 0x0 SIZE: 0x4
		int blurredEffectTime; //OFS: 0x4 SIZE: 0x4
		int flashWhiteFadeTime; //OFS: 0x8 SIZE: 0x4
		int flashShotFadeTime; //OFS: 0xC SIZE: 0x4
		ShockViewTypes type; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(shellshock_parms_t_screenBlend, 0x14);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_screenBlend, blurredFadeTime, 0x0);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_screenBlend, blurredEffectTime, 0x4);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_screenBlend, flashWhiteFadeTime, 0x8);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_screenBlend, flashShotFadeTime, 0xC);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_screenBlend, type, 0x10);

	struct shellshock_parms_t_view
	{
		int fadeTime; //OFS: 0x0 SIZE: 0x4
		float kickRate; //OFS: 0x4 SIZE: 0x4
		float kickRadius; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(shellshock_parms_t_view, 0xC);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_view, fadeTime, 0x0);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_view, kickRate, 0x4);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_view, kickRadius, 0x8);

	struct shellshock_parms_t_sound
	{
		bool affect; //OFS: 0x0 SIZE: 0x1
		char loop[64]; //OFS: 0x1 SIZE: 0x40
		char loopSilent[64]; //OFS: 0x41 SIZE: 0x40
		char end[64]; //OFS: 0x81 SIZE: 0x40
		char endAbort[64]; //OFS: 0xC1 SIZE: 0x40
		int fadeInTime; //OFS: 0x104 SIZE: 0x4
		int fadeOutTime; //OFS: 0x108 SIZE: 0x4
		float drylevel; //OFS: 0x10C SIZE: 0x4
		float wetlevel; //OFS: 0x110 SIZE: 0x4
		char roomtype[64]; //OFS: 0x114 SIZE: 0x40
		float busVolume[64]; //OFS: 0x154 SIZE: 0x100
		int modEndDelay; //OFS: 0x254 SIZE: 0x4
		int loopFadeTime; //OFS: 0x258 SIZE: 0x4
		int loopEndDelay; //OFS: 0x25C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(shellshock_parms_t_sound, 0x260);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_sound, affect, 0x0);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_sound, loop, 0x1);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_sound, loopSilent, 0x41);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_sound, end, 0x81);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_sound, endAbort, 0xC1);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_sound, fadeInTime, 0x104);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_sound, fadeOutTime, 0x108);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_sound, drylevel, 0x10C);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_sound, wetlevel, 0x110);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_sound, roomtype, 0x114);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_sound, busVolume, 0x154);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_sound, modEndDelay, 0x254);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_sound, loopFadeTime, 0x258);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_sound, loopEndDelay, 0x25C);

	struct shellshock_parms_t_lookControl
	{
		bool affect; //OFS: 0x0 SIZE: 0x1
		int fadeTime; //OFS: 0x4 SIZE: 0x4
		float mouseSensitivity; //OFS: 0x8 SIZE: 0x4
		float maxPitchSpeed; //OFS: 0xC SIZE: 0x4
		float maxYawSpeed; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(shellshock_parms_t_lookControl, 0x14);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_lookControl, affect, 0x0);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_lookControl, fadeTime, 0x4);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_lookControl, mouseSensitivity, 0x8);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_lookControl, maxPitchSpeed, 0xC);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_lookControl, maxYawSpeed, 0x10);

	struct __declspec(align(1)) shellshock_parms_t_movement
	{
		bool affect; //OFS: 0x0 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(shellshock_parms_t_movement, 0x1);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t_movement, affect, 0x0);

	struct shellshock_parms_t
	{
		shellshock_parms_t_screenBlend screenBlend; //OFS: 0x0 SIZE: 0x14
		shellshock_parms_t_view view; //OFS: 0x14 SIZE: 0xC
		shellshock_parms_t_sound sound; //OFS: 0x20 SIZE: 0x260
		shellshock_parms_t_lookControl lookControl; //OFS: 0x280 SIZE: 0x14
		shellshock_parms_t_movement movement; //OFS: 0x294 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(shellshock_parms_t, 0x298);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t, screenBlend, 0x0);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t, view, 0x14);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t, sound, 0x20);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t, lookControl, 0x280);
	ASSERT_STRUCT_OFFSET(shellshock_parms_t, movement, 0x294);

	struct __declspec(align(8)) animation_s
	{
		char name[64]; //OFS: 0x0 SIZE: 0x40
		int initialLerp; //OFS: 0x40 SIZE: 0x4
		float moveSpeed; //OFS: 0x44 SIZE: 0x4
		int duration; //OFS: 0x48 SIZE: 0x4
		int nameHash; //OFS: 0x4C SIZE: 0x4
		int flags; //OFS: 0x50 SIZE: 0x4
		__int64 movetype; //OFS: 0x58 SIZE: 0x8
		int noteType; //OFS: 0x60 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(animation_s, 0x68);
	ASSERT_STRUCT_OFFSET(animation_s, name, 0x0);
	ASSERT_STRUCT_OFFSET(animation_s, initialLerp, 0x40);
	ASSERT_STRUCT_OFFSET(animation_s, moveSpeed, 0x44);
	ASSERT_STRUCT_OFFSET(animation_s, duration, 0x48);
	ASSERT_STRUCT_OFFSET(animation_s, nameHash, 0x4C);
	ASSERT_STRUCT_OFFSET(animation_s, flags, 0x50);
	ASSERT_STRUCT_OFFSET(animation_s, movetype, 0x58);
	ASSERT_STRUCT_OFFSET(animation_s, noteType, 0x60);

	struct lerpFrame_t
	{
		float yawAngle; //OFS: 0x0 SIZE: 0x4
		int yawing; //OFS: 0x4 SIZE: 0x4
		float pitchAngle; //OFS: 0x8 SIZE: 0x4
		int pitching; //OFS: 0xC SIZE: 0x4
		int animationNumber; //OFS: 0x10 SIZE: 0x4
		animation_s * animation; //OFS: 0x14 SIZE: 0x4
		int animationTime; //OFS: 0x18 SIZE: 0x4
		float oldFramePos[3]; //OFS: 0x1C SIZE: 0xC
		float animSpeedScale; //OFS: 0x28 SIZE: 0x4
		int oldFrameSnapshotTime; //OFS: 0x2C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(lerpFrame_t, 0x30);
	ASSERT_STRUCT_OFFSET(lerpFrame_t, yawAngle, 0x0);
	ASSERT_STRUCT_OFFSET(lerpFrame_t, yawing, 0x4);
	ASSERT_STRUCT_OFFSET(lerpFrame_t, pitchAngle, 0x8);
	ASSERT_STRUCT_OFFSET(lerpFrame_t, pitching, 0xC);
	ASSERT_STRUCT_OFFSET(lerpFrame_t, animationNumber, 0x10);
	ASSERT_STRUCT_OFFSET(lerpFrame_t, animation, 0x14);
	ASSERT_STRUCT_OFFSET(lerpFrame_t, animationTime, 0x18);
	ASSERT_STRUCT_OFFSET(lerpFrame_t, oldFramePos, 0x1C);
	ASSERT_STRUCT_OFFSET(lerpFrame_t, animSpeedScale, 0x28);
	ASSERT_STRUCT_OFFSET(lerpFrame_t, oldFrameSnapshotTime, 0x2C);

	struct clientControllers_t
	{
		float angles[6][3]; //OFS: 0x0 SIZE: 0x48
		float tag_origin_angles[3]; //OFS: 0x48 SIZE: 0xC
		float tag_origin_offset[3]; //OFS: 0x54 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(clientControllers_t, 0x60);
	ASSERT_STRUCT_OFFSET(clientControllers_t, angles, 0x0);
	ASSERT_STRUCT_OFFSET(clientControllers_t, tag_origin_angles, 0x48);
	ASSERT_STRUCT_OFFSET(clientControllers_t, tag_origin_offset, 0x54);

	struct clientInfo_t
	{
		int infoValid; //OFS: 0x0 SIZE: 0x4
		int nextValid; //OFS: 0x4 SIZE: 0x4
		int clientNum; //OFS: 0x8 SIZE: 0x4
		char name[32]; //OFS: 0xC SIZE: 0x20
		team_t team; //OFS: 0x2C SIZE: 0x4
		team_t oldteam; //OFS: 0x30 SIZE: 0x4
		int rank; //OFS: 0x34 SIZE: 0x4
		int prestige; //OFS: 0x38 SIZE: 0x4
		int perks; //OFS: 0x3C SIZE: 0x4
		int needsRevive; //OFS: 0x40 SIZE: 0x4
		char clanAbbrev[8]; //OFS: 0x44 SIZE: 0x8
		int score; //OFS: 0x4C SIZE: 0x4
		int location; //OFS: 0x50 SIZE: 0x4
		int health; //OFS: 0x54 SIZE: 0x4
		char model[64]; //OFS: 0x58 SIZE: 0x40
		char attachModelNames[6][64]; //OFS: 0x98 SIZE: 0x180
		char attachTagNames[6][64]; //OFS: 0x218 SIZE: 0x180
		lerpFrame_t legs; //OFS: 0x398 SIZE: 0x30
		lerpFrame_t torso; //OFS: 0x3C8 SIZE: 0x30
		float lerpMoveDir; //OFS: 0x3F8 SIZE: 0x4
		float lerpLean; //OFS: 0x3FC SIZE: 0x4
		float playerAngles[3]; //OFS: 0x400 SIZE: 0xC
		int leftHandGun; //OFS: 0x40C SIZE: 0x4
		int dobjDirty; //OFS: 0x410 SIZE: 0x4
		clientControllers_t control; //OFS: 0x414 SIZE: 0x60
		int lastDamageTime; //OFS: 0x474 SIZE: 0x4
		int lastStandStartTime; //OFS: 0x478 SIZE: 0x4
		int beingRevived; //OFS: 0x47C SIZE: 0x4
		unsigned int clientConditions[17][2]; //OFS: 0x480 SIZE: 0x88
		XAnimTree_s * pXAnimTree; //OFS: 0x508 SIZE: 0x4
		int iDObjWeapon; //OFS: 0x50C SIZE: 0x4
		unsigned __int8 weaponModel; //OFS: 0x510 SIZE: 0x1
		int stanceTransitionTime; //OFS: 0x514 SIZE: 0x4
		int turnAnimEndTime; //OFS: 0x518 SIZE: 0x4
		char turnAnimType; //OFS: 0x51C SIZE: 0x1
		int attachedEntNum; //OFS: 0x520 SIZE: 0x4
		char attachedTagName[64]; //OFS: 0x524 SIZE: 0x40
		bool hideWeapon; //OFS: 0x564 SIZE: 0x1
		bool usingKnife; //OFS: 0x565 SIZE: 0x1
		int nextHideWeaponTime; //OFS: 0x568 SIZE: 0x4
		float vehAnimLastOrg[3]; //OFS: 0x56C SIZE: 0xC
		float vehAnimLastAngle[3]; //OFS: 0x578 SIZE: 0xC
		int vehAnimLastBone; //OFS: 0x584 SIZE: 0x4
		int vehAnimLastTime; //OFS: 0x588 SIZE: 0x4
		int vehAnimLerpStartTime; //OFS: 0x58C SIZE: 0x4
		int vehAnimLerpEndTime; //OFS: 0x590 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(clientInfo_t, 0x594);
	ASSERT_STRUCT_OFFSET(clientInfo_t, infoValid, 0x0);
	ASSERT_STRUCT_OFFSET(clientInfo_t, nextValid, 0x4);
	ASSERT_STRUCT_OFFSET(clientInfo_t, clientNum, 0x8);
	ASSERT_STRUCT_OFFSET(clientInfo_t, name, 0xC);
	ASSERT_STRUCT_OFFSET(clientInfo_t, team, 0x2C);
	ASSERT_STRUCT_OFFSET(clientInfo_t, oldteam, 0x30);
	ASSERT_STRUCT_OFFSET(clientInfo_t, rank, 0x34);
	ASSERT_STRUCT_OFFSET(clientInfo_t, prestige, 0x38);
	ASSERT_STRUCT_OFFSET(clientInfo_t, perks, 0x3C);
	ASSERT_STRUCT_OFFSET(clientInfo_t, needsRevive, 0x40);
	ASSERT_STRUCT_OFFSET(clientInfo_t, clanAbbrev, 0x44);
	ASSERT_STRUCT_OFFSET(clientInfo_t, score, 0x4C);
	ASSERT_STRUCT_OFFSET(clientInfo_t, location, 0x50);
	ASSERT_STRUCT_OFFSET(clientInfo_t, health, 0x54);
	ASSERT_STRUCT_OFFSET(clientInfo_t, model, 0x58);
	ASSERT_STRUCT_OFFSET(clientInfo_t, attachModelNames, 0x98);
	ASSERT_STRUCT_OFFSET(clientInfo_t, attachTagNames, 0x218);
	ASSERT_STRUCT_OFFSET(clientInfo_t, legs, 0x398);
	ASSERT_STRUCT_OFFSET(clientInfo_t, torso, 0x3C8);
	ASSERT_STRUCT_OFFSET(clientInfo_t, lerpMoveDir, 0x3F8);
	ASSERT_STRUCT_OFFSET(clientInfo_t, lerpLean, 0x3FC);
	ASSERT_STRUCT_OFFSET(clientInfo_t, playerAngles, 0x400);
	ASSERT_STRUCT_OFFSET(clientInfo_t, leftHandGun, 0x40C);
	ASSERT_STRUCT_OFFSET(clientInfo_t, dobjDirty, 0x410);
	ASSERT_STRUCT_OFFSET(clientInfo_t, control, 0x414);
	ASSERT_STRUCT_OFFSET(clientInfo_t, lastDamageTime, 0x474);
	ASSERT_STRUCT_OFFSET(clientInfo_t, lastStandStartTime, 0x478);
	ASSERT_STRUCT_OFFSET(clientInfo_t, beingRevived, 0x47C);
	ASSERT_STRUCT_OFFSET(clientInfo_t, clientConditions, 0x480);
	ASSERT_STRUCT_OFFSET(clientInfo_t, pXAnimTree, 0x508);
	ASSERT_STRUCT_OFFSET(clientInfo_t, iDObjWeapon, 0x50C);
	ASSERT_STRUCT_OFFSET(clientInfo_t, weaponModel, 0x510);
	ASSERT_STRUCT_OFFSET(clientInfo_t, stanceTransitionTime, 0x514);
	ASSERT_STRUCT_OFFSET(clientInfo_t, turnAnimEndTime, 0x518);
	ASSERT_STRUCT_OFFSET(clientInfo_t, turnAnimType, 0x51C);
	ASSERT_STRUCT_OFFSET(clientInfo_t, attachedEntNum, 0x520);
	ASSERT_STRUCT_OFFSET(clientInfo_t, attachedTagName, 0x524);
	ASSERT_STRUCT_OFFSET(clientInfo_t, hideWeapon, 0x564);
	ASSERT_STRUCT_OFFSET(clientInfo_t, usingKnife, 0x565);
	ASSERT_STRUCT_OFFSET(clientInfo_t, nextHideWeaponTime, 0x568);
	ASSERT_STRUCT_OFFSET(clientInfo_t, vehAnimLastOrg, 0x56C);
	ASSERT_STRUCT_OFFSET(clientInfo_t, vehAnimLastAngle, 0x578);
	ASSERT_STRUCT_OFFSET(clientInfo_t, vehAnimLastBone, 0x584);
	ASSERT_STRUCT_OFFSET(clientInfo_t, vehAnimLastTime, 0x588);
	ASSERT_STRUCT_OFFSET(clientInfo_t, vehAnimLerpStartTime, 0x58C);
	ASSERT_STRUCT_OFFSET(clientInfo_t, vehAnimLerpEndTime, 0x590);

	struct actorInfo_t
	{
		int infoValid; //OFS: 0x0 SIZE: 0x4
		int nextValid; //OFS: 0x4 SIZE: 0x4
		int actorNum; //OFS: 0x8 SIZE: 0x4
		int entityNum; //OFS: 0xC SIZE: 0x4
		char name[32]; //OFS: 0x10 SIZE: 0x20
		team_t team; //OFS: 0x30 SIZE: 0x4
		char model[64]; //OFS: 0x34 SIZE: 0x40
		char attachModelNames[6][64]; //OFS: 0x74 SIZE: 0x180
		char attachTagNames[6][64]; //OFS: 0x1F4 SIZE: 0x180
		lerpFrame_t legs; //OFS: 0x374 SIZE: 0x30
		lerpFrame_t torso; //OFS: 0x3A4 SIZE: 0x30
		int dobjDirty; //OFS: 0x3D4 SIZE: 0x4
		int animsDirty; //OFS: 0x3D8 SIZE: 0x4
		XAnimTree_s * pXAnimTree; //OFS: 0x3DC SIZE: 0x4
		int iDObjWeapon; //OFS: 0x3E0 SIZE: 0x4
		int stanceTransitionTime; //OFS: 0x3E4 SIZE: 0x4
		int turnAnimEndTime; //OFS: 0x3E8 SIZE: 0x4
		char turnAnimType; //OFS: 0x3EC SIZE: 0x1
		int attachedEntNum; //OFS: 0x3F0 SIZE: 0x4
		char attachedTagName[64]; //OFS: 0x3F4 SIZE: 0x40
		int animScriptedAnim; //OFS: 0x434 SIZE: 0x4
		bool hideWeapon; //OFS: 0x438 SIZE: 0x1
		int hudwarningType; //OFS: 0x43C SIZE: 0x4
		int lookAtEntNum; //OFS: 0x440 SIZE: 0x4
		int lastLookAtEntNum; //OFS: 0x444 SIZE: 0x4
		float lookAtBlend; //OFS: 0x448 SIZE: 0x4
		int lookAtBlendedIn; //OFS: 0x44C SIZE: 0x4
		int lookAtTime; //OFS: 0x450 SIZE: 0x4
		int pad; //OFS: 0x454 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(actorInfo_t, 0x458);
	ASSERT_STRUCT_OFFSET(actorInfo_t, infoValid, 0x0);
	ASSERT_STRUCT_OFFSET(actorInfo_t, nextValid, 0x4);
	ASSERT_STRUCT_OFFSET(actorInfo_t, actorNum, 0x8);
	ASSERT_STRUCT_OFFSET(actorInfo_t, entityNum, 0xC);
	ASSERT_STRUCT_OFFSET(actorInfo_t, name, 0x10);
	ASSERT_STRUCT_OFFSET(actorInfo_t, team, 0x30);
	ASSERT_STRUCT_OFFSET(actorInfo_t, model, 0x34);
	ASSERT_STRUCT_OFFSET(actorInfo_t, attachModelNames, 0x74);
	ASSERT_STRUCT_OFFSET(actorInfo_t, attachTagNames, 0x1F4);
	ASSERT_STRUCT_OFFSET(actorInfo_t, legs, 0x374);
	ASSERT_STRUCT_OFFSET(actorInfo_t, torso, 0x3A4);
	ASSERT_STRUCT_OFFSET(actorInfo_t, dobjDirty, 0x3D4);
	ASSERT_STRUCT_OFFSET(actorInfo_t, animsDirty, 0x3D8);
	ASSERT_STRUCT_OFFSET(actorInfo_t, pXAnimTree, 0x3DC);
	ASSERT_STRUCT_OFFSET(actorInfo_t, iDObjWeapon, 0x3E0);
	ASSERT_STRUCT_OFFSET(actorInfo_t, stanceTransitionTime, 0x3E4);
	ASSERT_STRUCT_OFFSET(actorInfo_t, turnAnimEndTime, 0x3E8);
	ASSERT_STRUCT_OFFSET(actorInfo_t, turnAnimType, 0x3EC);
	ASSERT_STRUCT_OFFSET(actorInfo_t, attachedEntNum, 0x3F0);
	ASSERT_STRUCT_OFFSET(actorInfo_t, attachedTagName, 0x3F4);
	ASSERT_STRUCT_OFFSET(actorInfo_t, animScriptedAnim, 0x434);
	ASSERT_STRUCT_OFFSET(actorInfo_t, hideWeapon, 0x438);
	ASSERT_STRUCT_OFFSET(actorInfo_t, hudwarningType, 0x43C);
	ASSERT_STRUCT_OFFSET(actorInfo_t, lookAtEntNum, 0x440);
	ASSERT_STRUCT_OFFSET(actorInfo_t, lastLookAtEntNum, 0x444);
	ASSERT_STRUCT_OFFSET(actorInfo_t, lookAtBlend, 0x448);
	ASSERT_STRUCT_OFFSET(actorInfo_t, lookAtBlendedIn, 0x44C);
	ASSERT_STRUCT_OFFSET(actorInfo_t, lookAtTime, 0x450);
	ASSERT_STRUCT_OFFSET(actorInfo_t, pad, 0x454);

	struct cgs_s
	{
		int viewX; //OFS: 0x0 SIZE: 0x4
		int viewY; //OFS: 0x4 SIZE: 0x4
		int viewWidth; //OFS: 0x8 SIZE: 0x4
		int viewHeight; //OFS: 0xC SIZE: 0x4
		float viewAspect; //OFS: 0x10 SIZE: 0x4
		int serverCommandSequence; //OFS: 0x14 SIZE: 0x4
		int processedSnapshotNum; //OFS: 0x18 SIZE: 0x4
		int localServer; //OFS: 0x1C SIZE: 0x4
		char gametype[32]; //OFS: 0x20 SIZE: 0x20
		char szHostName[256]; //OFS: 0x40 SIZE: 0x100
		int maxclients; //OFS: 0x140 SIZE: 0x4
		int privateClients; //OFS: 0x144 SIZE: 0x4
		char mapname[64]; //OFS: 0x148 SIZE: 0x40
		int voteTime; //OFS: 0x188 SIZE: 0x4
		int voteYes; //OFS: 0x18C SIZE: 0x4
		int voteNo; //OFS: 0x190 SIZE: 0x4
		char voteString[256]; //OFS: 0x194 SIZE: 0x100
		int redCrosshair; //OFS: 0x294 SIZE: 0x4
		XModel * gameModels[512]; //OFS: 0x298 SIZE: 0x800
		FxEffectDef * fxs[196]; //OFS: 0xA98 SIZE: 0x310
		FxEffectDef * grenadeFx[24]; //OFS: 0xDA8 SIZE: 0x60
		shellshock_parms_t holdBreathParams; //OFS: 0xE08 SIZE: 0x298
		char teamChatMsgs[8][151]; //OFS: 0x10A0 SIZE: 0x4B8
		int teamChatMsgTimes[8]; //OFS: 0x1558 SIZE: 0x20
		int teamChatPos; //OFS: 0x1578 SIZE: 0x4
		int teamLastChatPos; //OFS: 0x157C SIZE: 0x4
		int compassWidth; //OFS: 0x1580 SIZE: 0x4
		int compassHeight; //OFS: 0x1584 SIZE: 0x4
		int compassY; //OFS: 0x1588 SIZE: 0x4
		clientInfo_t corpseinfo[8]; //OFS: 0x158C SIZE: 0x2CA0
		actorInfo_t actorCorpseInfo[32]; //OFS: 0x422C SIZE: 0x8B00
		XAnim_s * generic_human; //OFS: 0xCD2C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(cgs_s, 0xCD30);
	ASSERT_STRUCT_OFFSET(cgs_s, viewX, 0x0);
	ASSERT_STRUCT_OFFSET(cgs_s, viewY, 0x4);
	ASSERT_STRUCT_OFFSET(cgs_s, viewWidth, 0x8);
	ASSERT_STRUCT_OFFSET(cgs_s, viewHeight, 0xC);
	ASSERT_STRUCT_OFFSET(cgs_s, viewAspect, 0x10);
	ASSERT_STRUCT_OFFSET(cgs_s, serverCommandSequence, 0x14);
	ASSERT_STRUCT_OFFSET(cgs_s, processedSnapshotNum, 0x18);
	ASSERT_STRUCT_OFFSET(cgs_s, localServer, 0x1C);
	ASSERT_STRUCT_OFFSET(cgs_s, gametype, 0x20);
	ASSERT_STRUCT_OFFSET(cgs_s, szHostName, 0x40);
	ASSERT_STRUCT_OFFSET(cgs_s, maxclients, 0x140);
	ASSERT_STRUCT_OFFSET(cgs_s, privateClients, 0x144);
	ASSERT_STRUCT_OFFSET(cgs_s, mapname, 0x148);
	ASSERT_STRUCT_OFFSET(cgs_s, voteTime, 0x188);
	ASSERT_STRUCT_OFFSET(cgs_s, voteYes, 0x18C);
	ASSERT_STRUCT_OFFSET(cgs_s, voteNo, 0x190);
	ASSERT_STRUCT_OFFSET(cgs_s, voteString, 0x194);
	ASSERT_STRUCT_OFFSET(cgs_s, redCrosshair, 0x294);
	ASSERT_STRUCT_OFFSET(cgs_s, gameModels, 0x298);
	ASSERT_STRUCT_OFFSET(cgs_s, fxs, 0xA98);
	ASSERT_STRUCT_OFFSET(cgs_s, grenadeFx, 0xDA8);
	ASSERT_STRUCT_OFFSET(cgs_s, holdBreathParams, 0xE08);
	ASSERT_STRUCT_OFFSET(cgs_s, teamChatMsgs, 0x10A0);
	ASSERT_STRUCT_OFFSET(cgs_s, teamChatMsgTimes, 0x1558);
	ASSERT_STRUCT_OFFSET(cgs_s, teamChatPos, 0x1578);
	ASSERT_STRUCT_OFFSET(cgs_s, teamLastChatPos, 0x157C);
	ASSERT_STRUCT_OFFSET(cgs_s, compassWidth, 0x1580);
	ASSERT_STRUCT_OFFSET(cgs_s, compassHeight, 0x1584);
	ASSERT_STRUCT_OFFSET(cgs_s, compassY, 0x1588);
	ASSERT_STRUCT_OFFSET(cgs_s, corpseinfo, 0x158C);
	ASSERT_STRUCT_OFFSET(cgs_s, actorCorpseInfo, 0x422C);
	ASSERT_STRUCT_OFFSET(cgs_s, generic_human, 0xCD2C);

	struct snapshot_s
	{
		int snapFlags; //OFS: 0x0 SIZE: 0x4
		int ping; //OFS: 0x4 SIZE: 0x4
		int serverTime; //OFS: 0x8 SIZE: 0x4
		playerState_s ps; //OFS: 0xC SIZE: 0x20AC
		int numEntities; //OFS: 0x20B8 SIZE: 0x4
		int numClients; //OFS: 0x20BC SIZE: 0x4
		int numActors; //OFS: 0x20C0 SIZE: 0x4
		int field_20C4; //OFS: 0x20C4 SIZE: 0x4
		animCmdState_s parseAnimCmds[1117]; //OFS: 0x20C8 SIZE: 0xBFFC
		int field_E0C4; //OFS: 0xE0C4 SIZE: 0x4
		char what; //OFS: 0xE0C8 SIZE: 0x1
		char whatthe[1024]; //OFS: 0xE0C9 SIZE: 0x400
		_BYTE gap_E4C9[3]; //OFS: 0xE4C9 SIZE: 0x3
		entityState_s parseEntities[1024]; //OFS: 0xE4CC SIZE: 0x46000
		clientState_s parseClients[4]; //OFS: 0x544CC SIZE: 0x250
		actorState_s parseActors[32]; //OFS: 0x5471C SIZE: 0xF00
		int serverCommandSequence; //OFS: 0x5561C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(snapshot_s, 0x55620);
	ASSERT_STRUCT_OFFSET(snapshot_s, snapFlags, 0x0);
	ASSERT_STRUCT_OFFSET(snapshot_s, ping, 0x4);
	ASSERT_STRUCT_OFFSET(snapshot_s, serverTime, 0x8);
	ASSERT_STRUCT_OFFSET(snapshot_s, ps, 0xC);
	ASSERT_STRUCT_OFFSET(snapshot_s, numEntities, 0x20B8);
	ASSERT_STRUCT_OFFSET(snapshot_s, numClients, 0x20BC);
	ASSERT_STRUCT_OFFSET(snapshot_s, numActors, 0x20C0);
	ASSERT_STRUCT_OFFSET(snapshot_s, field_20C4, 0x20C4);
	ASSERT_STRUCT_OFFSET(snapshot_s, parseAnimCmds, 0x20C8);
	ASSERT_STRUCT_OFFSET(snapshot_s, field_E0C4, 0xE0C4);
	ASSERT_STRUCT_OFFSET(snapshot_s, what, 0xE0C8);
	ASSERT_STRUCT_OFFSET(snapshot_s, whatthe, 0xE0C9);
	ASSERT_STRUCT_OFFSET(snapshot_s, gap_E4C9, 0xE4C9);
	ASSERT_STRUCT_OFFSET(snapshot_s, parseEntities, 0xE4CC);
	ASSERT_STRUCT_OFFSET(snapshot_s, parseClients, 0x544CC);
	ASSERT_STRUCT_OFFSET(snapshot_s, parseActors, 0x5471C);
	ASSERT_STRUCT_OFFSET(snapshot_s, serverCommandSequence, 0x5561C);

	struct playerEntity_t
	{
		float fLastWeaponPosFrac; //OFS: 0x0 SIZE: 0x4
		int bPositionToADS; //OFS: 0x4 SIZE: 0x4
		float vPositionLastOrg[3]; //OFS: 0x8 SIZE: 0xC
		float vPositionLastAng[3]; //OFS: 0x14 SIZE: 0xC
		float fLastIdleFactor; //OFS: 0x20 SIZE: 0x4
		float vLastMoveOrg[3]; //OFS: 0x24 SIZE: 0xC
		float vLastMoveAng[3]; //OFS: 0x30 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(playerEntity_t, 0x3C);
	ASSERT_STRUCT_OFFSET(playerEntity_t, fLastWeaponPosFrac, 0x0);
	ASSERT_STRUCT_OFFSET(playerEntity_t, bPositionToADS, 0x4);
	ASSERT_STRUCT_OFFSET(playerEntity_t, vPositionLastOrg, 0x8);
	ASSERT_STRUCT_OFFSET(playerEntity_t, vPositionLastAng, 0x14);
	ASSERT_STRUCT_OFFSET(playerEntity_t, fLastIdleFactor, 0x20);
	ASSERT_STRUCT_OFFSET(playerEntity_t, vLastMoveOrg, 0x24);
	ASSERT_STRUCT_OFFSET(playerEntity_t, vLastMoveAng, 0x30);

	struct refdef_s
	{
		_BYTE gap_0[28]; //OFS: 0x0 SIZE: 0x1C
		float vieworg[3]; //OFS: 0x1C SIZE: 0xC
		_BYTE gap_28[17083]; //OFS: 0x28 SIZE: 0x42BB
		char field_42E3; //OFS: 0x42E3 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(refdef_s, 0x42E4);
	ASSERT_STRUCT_OFFSET(refdef_s, gap_0, 0x0);
	ASSERT_STRUCT_OFFSET(refdef_s, vieworg, 0x1C);
	ASSERT_STRUCT_OFFSET(refdef_s, gap_28, 0x28);
	ASSERT_STRUCT_OFFSET(refdef_s, field_42E3, 0x42E3);

	struct Camera
	{
		float lastViewOrg[3]; //OFS: 0x0 SIZE: 0xC
		float lastViewAngles[3]; //OFS: 0xC SIZE: 0xC
		float tweenStartOrg[3]; //OFS: 0x18 SIZE: 0xC
		float tweenStartAngles[3]; //OFS: 0x24 SIZE: 0xC
		float tweenStartFOV; //OFS: 0x30 SIZE: 0x4
		int tweenStartTime; //OFS: 0x34 SIZE: 0x4
		float tweenDuration; //OFS: 0x38 SIZE: 0x4
		float lastViewLockedEntOrg[3]; //OFS: 0x3C SIZE: 0xC
		CameraMode lastCamMode; //OFS: 0x48 SIZE: 0x4
		int lastVehicleSeatPos; //OFS: 0x4C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(Camera, 0x50);
	ASSERT_STRUCT_OFFSET(Camera, lastViewOrg, 0x0);
	ASSERT_STRUCT_OFFSET(Camera, lastViewAngles, 0xC);
	ASSERT_STRUCT_OFFSET(Camera, tweenStartOrg, 0x18);
	ASSERT_STRUCT_OFFSET(Camera, tweenStartAngles, 0x24);
	ASSERT_STRUCT_OFFSET(Camera, tweenStartFOV, 0x30);
	ASSERT_STRUCT_OFFSET(Camera, tweenStartTime, 0x34);
	ASSERT_STRUCT_OFFSET(Camera, tweenDuration, 0x38);
	ASSERT_STRUCT_OFFSET(Camera, lastViewLockedEntOrg, 0x3C);
	ASSERT_STRUCT_OFFSET(Camera, lastCamMode, 0x48);
	ASSERT_STRUCT_OFFSET(Camera, lastVehicleSeatPos, 0x4C);

	struct score_t
	{
		int client; //OFS: 0x0 SIZE: 0x4
		int score; //OFS: 0x4 SIZE: 0x4
		int ping; //OFS: 0x8 SIZE: 0x4
		int team; //OFS: 0xC SIZE: 0x4
		int kills; //OFS: 0x10 SIZE: 0x4
		int rank; //OFS: 0x14 SIZE: 0x4
		int assists; //OFS: 0x18 SIZE: 0x4
		int downs; //OFS: 0x1C SIZE: 0x4
		int revives; //OFS: 0x20 SIZE: 0x4
		int headshots; //OFS: 0x24 SIZE: 0x4
		int scoreMultiplier; //OFS: 0x28 SIZE: 0x4
		Material * hStatusIcon; //OFS: 0x2C SIZE: 0x4
		Material * hRankIcon; //OFS: 0x30 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(score_t, 0x34);
	ASSERT_STRUCT_OFFSET(score_t, client, 0x0);
	ASSERT_STRUCT_OFFSET(score_t, score, 0x4);
	ASSERT_STRUCT_OFFSET(score_t, ping, 0x8);
	ASSERT_STRUCT_OFFSET(score_t, team, 0xC);
	ASSERT_STRUCT_OFFSET(score_t, kills, 0x10);
	ASSERT_STRUCT_OFFSET(score_t, rank, 0x14);
	ASSERT_STRUCT_OFFSET(score_t, assists, 0x18);
	ASSERT_STRUCT_OFFSET(score_t, downs, 0x1C);
	ASSERT_STRUCT_OFFSET(score_t, revives, 0x20);
	ASSERT_STRUCT_OFFSET(score_t, headshots, 0x24);
	ASSERT_STRUCT_OFFSET(score_t, scoreMultiplier, 0x28);
	ASSERT_STRUCT_OFFSET(score_t, hStatusIcon, 0x2C);
	ASSERT_STRUCT_OFFSET(score_t, hRankIcon, 0x30);

	struct viewDamage_t
	{
		int time; //OFS: 0x0 SIZE: 0x4
		int duration; //OFS: 0x4 SIZE: 0x4
		float yaw; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(viewDamage_t, 0xC);
	ASSERT_STRUCT_OFFSET(viewDamage_t, time, 0x0);
	ASSERT_STRUCT_OFFSET(viewDamage_t, duration, 0x4);
	ASSERT_STRUCT_OFFSET(viewDamage_t, yaw, 0x8);

	struct objectiveInfo_t
	{
		objectiveState_t state; //OFS: 0x0 SIZE: 0x4
		float origin[8][3]; //OFS: 0x4 SIZE: 0x60
		int centNum[8]; //OFS: 0x64 SIZE: 0x20
		char string[1024]; //OFS: 0x84 SIZE: 0x400
		int ringTime; //OFS: 0x484 SIZE: 0x4
		int ringToggle; //OFS: 0x488 SIZE: 0x4
		int icon; //OFS: 0x48C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(objectiveInfo_t, 0x490);
	ASSERT_STRUCT_OFFSET(objectiveInfo_t, state, 0x0);
	ASSERT_STRUCT_OFFSET(objectiveInfo_t, origin, 0x4);
	ASSERT_STRUCT_OFFSET(objectiveInfo_t, centNum, 0x64);
	ASSERT_STRUCT_OFFSET(objectiveInfo_t, string, 0x84);
	ASSERT_STRUCT_OFFSET(objectiveInfo_t, ringTime, 0x484);
	ASSERT_STRUCT_OFFSET(objectiveInfo_t, ringToggle, 0x488);
	ASSERT_STRUCT_OFFSET(objectiveInfo_t, icon, 0x48C);

	struct targetInfo_t
	{
		int entNum; //OFS: 0x0 SIZE: 0x4
		float offset[3]; //OFS: 0x4 SIZE: 0xC
		int materialIndex; //OFS: 0x10 SIZE: 0x4
		int offscreenMaterialIndex; //OFS: 0x14 SIZE: 0x4
		int flags; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(targetInfo_t, 0x1C);
	ASSERT_STRUCT_OFFSET(targetInfo_t, entNum, 0x0);
	ASSERT_STRUCT_OFFSET(targetInfo_t, offset, 0x4);
	ASSERT_STRUCT_OFFSET(targetInfo_t, materialIndex, 0x10);
	ASSERT_STRUCT_OFFSET(targetInfo_t, offscreenMaterialIndex, 0x14);
	ASSERT_STRUCT_OFFSET(targetInfo_t, flags, 0x18);

	struct shellshock_t
	{
		shellshock_parms_t * parms; //OFS: 0x0 SIZE: 0x4
		int startTime; //OFS: 0x4 SIZE: 0x4
		int duration; //OFS: 0x8 SIZE: 0x4
		int loopEndTime; //OFS: 0xC SIZE: 0x4
		float sensitivity; //OFS: 0x10 SIZE: 0x4
		float viewDelta[2]; //OFS: 0x14 SIZE: 0x8
		int hasSavedScreen; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(shellshock_t, 0x20);
	ASSERT_STRUCT_OFFSET(shellshock_t, parms, 0x0);
	ASSERT_STRUCT_OFFSET(shellshock_t, startTime, 0x4);
	ASSERT_STRUCT_OFFSET(shellshock_t, duration, 0x8);
	ASSERT_STRUCT_OFFSET(shellshock_t, loopEndTime, 0xC);
	ASSERT_STRUCT_OFFSET(shellshock_t, sensitivity, 0x10);
	ASSERT_STRUCT_OFFSET(shellshock_t, viewDelta, 0x14);
	ASSERT_STRUCT_OFFSET(shellshock_t, hasSavedScreen, 0x1C);

	struct __declspec(align(8)) animScriptData_t
	{
		animation_s animations[512]; //OFS: 0x0 SIZE: 0xD000
		unsigned int numAnimations; //OFS: 0xD000 SIZE: 0x4
		animScript_t scriptAnims[1][45]; //OFS: 0xD004 SIZE: 0x5AB4
		animScript_t scriptCannedAnims[1][45]; //OFS: 0x12AB8 SIZE: 0x5AB4
		animScript_t scriptStateChange[1][1]; //OFS: 0x1856C SIZE: 0x204
		animScript_t scriptEvents[25]; //OFS: 0x18770 SIZE: 0x3264
		animScriptItem_t scriptItems[2048]; //OFS: 0x1B9D4 SIZE: 0x6C000
		int numScriptItems; //OFS: 0x879D4 SIZE: 0x4
		scr_animtree_t animTree; //OFS: 0x879D8 SIZE: 0x4
		unsigned __int16 bodyAnim; //OFS: 0x879DC SIZE: 0x2
		unsigned __int16 mainAnim; //OFS: 0x879DE SIZE: 0x2
		unsigned __int16 torsoAnim; //OFS: 0x879E0 SIZE: 0x2
		unsigned __int16 legsAnim; //OFS: 0x879E2 SIZE: 0x2
		snd_alias_list_t *(__cdecl *soundAlias)(const char *); //OFS: 0x879E4 SIZE: 0x4
		void (__cdecl *playSoundAlias)(int, snd_alias_list_t *); //OFS: 0x879E8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(animScriptData_t, 0x879F0);
	ASSERT_STRUCT_OFFSET(animScriptData_t, animations, 0x0);
	ASSERT_STRUCT_OFFSET(animScriptData_t, numAnimations, 0xD000);
	ASSERT_STRUCT_OFFSET(animScriptData_t, scriptAnims, 0xD004);
	ASSERT_STRUCT_OFFSET(animScriptData_t, scriptCannedAnims, 0x12AB8);
	ASSERT_STRUCT_OFFSET(animScriptData_t, scriptStateChange, 0x1856C);
	ASSERT_STRUCT_OFFSET(animScriptData_t, scriptEvents, 0x18770);
	ASSERT_STRUCT_OFFSET(animScriptData_t, scriptItems, 0x1B9D4);
	ASSERT_STRUCT_OFFSET(animScriptData_t, numScriptItems, 0x879D4);
	ASSERT_STRUCT_OFFSET(animScriptData_t, animTree, 0x879D8);
	ASSERT_STRUCT_OFFSET(animScriptData_t, bodyAnim, 0x879DC);
	ASSERT_STRUCT_OFFSET(animScriptData_t, mainAnim, 0x879DE);
	ASSERT_STRUCT_OFFSET(animScriptData_t, torsoAnim, 0x879E0);
	ASSERT_STRUCT_OFFSET(animScriptData_t, legsAnim, 0x879E2);
	ASSERT_STRUCT_OFFSET(animScriptData_t, soundAlias, 0x879E4);
	ASSERT_STRUCT_OFFSET(animScriptData_t, playSoundAlias, 0x879E8);

	struct bgs_t_generic_human
	{
		scr_animtree_t tree; //OFS: 0x0 SIZE: 0x4
		scr_anim_s torso; //OFS: 0x4 SIZE: 0x4
		scr_anim_s legs; //OFS: 0x8 SIZE: 0x4
		scr_anim_s turning; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(bgs_t_generic_human, 0x10);
	ASSERT_STRUCT_OFFSET(bgs_t_generic_human, tree, 0x0);
	ASSERT_STRUCT_OFFSET(bgs_t_generic_human, torso, 0x4);
	ASSERT_STRUCT_OFFSET(bgs_t_generic_human, legs, 0x8);
	ASSERT_STRUCT_OFFSET(bgs_t_generic_human, turning, 0xC);

	struct DSkelPartBits
	{
		int anim[4]; //OFS: 0x0 SIZE: 0x10
		int control[4]; //OFS: 0x10 SIZE: 0x10
		int skel[4]; //OFS: 0x20 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(DSkelPartBits, 0x30);
	ASSERT_STRUCT_OFFSET(DSkelPartBits, anim, 0x0);
	ASSERT_STRUCT_OFFSET(DSkelPartBits, control, 0x10);
	ASSERT_STRUCT_OFFSET(DSkelPartBits, skel, 0x20);

	struct DSkel
	{
		DSkelPartBits partBits; //OFS: 0x0 SIZE: 0x30
		int timeStamp; //OFS: 0x30 SIZE: 0x4
		DObjAnimMat * mat; //OFS: 0x34 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DSkel, 0x38);
	ASSERT_STRUCT_OFFSET(DSkel, partBits, 0x0);
	ASSERT_STRUCT_OFFSET(DSkel, timeStamp, 0x30);
	ASSERT_STRUCT_OFFSET(DSkel, mat, 0x34);

	struct DObj_s
	{
		XAnimTree_s * tree; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 duplicateParts; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 entnum; //OFS: 0x6 SIZE: 0x2
		unsigned __int8 duplicatePartsSize; //OFS: 0x8 SIZE: 0x1
		unsigned __int8 numModels; //OFS: 0x9 SIZE: 0x1
		unsigned __int8 numBones; //OFS: 0xA SIZE: 0x1
		unsigned int ignoreCollision; //OFS: 0xC SIZE: 0x4
		int locked; //OFS: 0x10 SIZE: 0x4
		DSkel skel; //OFS: 0x14 SIZE: 0x38
		float radius; //OFS: 0x4C SIZE: 0x4
		unsigned int hidePartBits[4]; //OFS: 0x50 SIZE: 0x10
		char localClientIndex; //OFS: 0x60 SIZE: 0x1
		unsigned __int8 flags; //OFS: 0x61 SIZE: 0x1
		unsigned __int16 ikStateIndex; //OFS: 0x62 SIZE: 0x2
		XModel ** models; //OFS: 0x64 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DObj_s, 0x68);
	ASSERT_STRUCT_OFFSET(DObj_s, tree, 0x0);
	ASSERT_STRUCT_OFFSET(DObj_s, duplicateParts, 0x4);
	ASSERT_STRUCT_OFFSET(DObj_s, entnum, 0x6);
	ASSERT_STRUCT_OFFSET(DObj_s, duplicatePartsSize, 0x8);
	ASSERT_STRUCT_OFFSET(DObj_s, numModels, 0x9);
	ASSERT_STRUCT_OFFSET(DObj_s, numBones, 0xA);
	ASSERT_STRUCT_OFFSET(DObj_s, ignoreCollision, 0xC);
	ASSERT_STRUCT_OFFSET(DObj_s, locked, 0x10);
	ASSERT_STRUCT_OFFSET(DObj_s, skel, 0x14);
	ASSERT_STRUCT_OFFSET(DObj_s, radius, 0x4C);
	ASSERT_STRUCT_OFFSET(DObj_s, hidePartBits, 0x50);
	ASSERT_STRUCT_OFFSET(DObj_s, localClientIndex, 0x60);
	ASSERT_STRUCT_OFFSET(DObj_s, flags, 0x61);
	ASSERT_STRUCT_OFFSET(DObj_s, ikStateIndex, 0x62);
	ASSERT_STRUCT_OFFSET(DObj_s, models, 0x64);

	struct __declspec(align(8)) bgs_s
	{
		animScriptData_t animScriptData; //OFS: 0x0 SIZE: 0x879F0
		bgs_t_generic_human generic_human; //OFS: 0x879F0 SIZE: 0x10
		int time; //OFS: 0x87A00 SIZE: 0x4
		int latestSnapshotTime; //OFS: 0x87A04 SIZE: 0x4
		int frametime; //OFS: 0x87A08 SIZE: 0x4
		int anim_user; //OFS: 0x87A0C SIZE: 0x4
		XModel *(__cdecl *GetXModel)(const char *); //OFS: 0x87A10 SIZE: 0x4
		void (__cdecl *CreateDObj)(DObjModel_s *, unsigned __int16, XAnimTree_s *, int, int, clientInfo_t *); //OFS: 0x87A14 SIZE: 0x4
		unsigned __int16 (__cdecl *AttachWeapon)(DObjModel_s *, unsigned __int16, clientInfo_t *); //OFS: 0x87A18 SIZE: 0x4
		DObj_s *(__cdecl *GetDObj)(int handle, int localClientNum); //OFS: 0x87A1C SIZE: 0x4
		void (__cdecl *SafeDObjFree)(int, int); //OFS: 0x87A20 SIZE: 0x4
		void *(__cdecl *AllocXAnim)(int); //OFS: 0x87A24 SIZE: 0x4
		clientInfo_t clientInfo[4]; //OFS: 0x87A28 SIZE: 0x1650
		actorInfo_t actorinfo[32]; //OFS: 0x89078 SIZE: 0x8B00
	};
	ASSERT_STRUCT_SIZE(bgs_s, 0x91B78);
	ASSERT_STRUCT_OFFSET(bgs_s, animScriptData, 0x0);
	ASSERT_STRUCT_OFFSET(bgs_s, generic_human, 0x879F0);
	ASSERT_STRUCT_OFFSET(bgs_s, time, 0x87A00);
	ASSERT_STRUCT_OFFSET(bgs_s, latestSnapshotTime, 0x87A04);
	ASSERT_STRUCT_OFFSET(bgs_s, frametime, 0x87A08);
	ASSERT_STRUCT_OFFSET(bgs_s, anim_user, 0x87A0C);
	ASSERT_STRUCT_OFFSET(bgs_s, GetXModel, 0x87A10);
	ASSERT_STRUCT_OFFSET(bgs_s, CreateDObj, 0x87A14);
	ASSERT_STRUCT_OFFSET(bgs_s, AttachWeapon, 0x87A18);
	ASSERT_STRUCT_OFFSET(bgs_s, GetDObj, 0x87A1C);
	ASSERT_STRUCT_OFFSET(bgs_s, SafeDObjFree, 0x87A20);
	ASSERT_STRUCT_OFFSET(bgs_s, AllocXAnim, 0x87A24);
	ASSERT_STRUCT_OFFSET(bgs_s, clientInfo, 0x87A28);
	ASSERT_STRUCT_OFFSET(bgs_s, actorinfo, 0x89078);

	struct visionSetVars_t
	{
		bool glowEnable; //OFS: 0x0 SIZE: 0x1
		float glowBloomCutoff; //OFS: 0x4 SIZE: 0x4
		float glowBloomDesaturation; //OFS: 0x8 SIZE: 0x4
		float glowBloomIntensity0; //OFS: 0xC SIZE: 0x4
		float glowBloomIntensity1; //OFS: 0x10 SIZE: 0x4
		float glowRadius0; //OFS: 0x14 SIZE: 0x4
		float glowRadius1; //OFS: 0x18 SIZE: 0x4
		float glowSkyBleedIntensity0; //OFS: 0x1C SIZE: 0x4
		float glowSkyBleedIntensity1; //OFS: 0x20 SIZE: 0x4
		float glowRayExpansion; //OFS: 0x24 SIZE: 0x4
		float glowRayIntensity; //OFS: 0x28 SIZE: 0x4
		bool filmEnable; //OFS: 0x2C SIZE: 0x1
		float filmBrightness; //OFS: 0x30 SIZE: 0x4
		float filmContrast; //OFS: 0x34 SIZE: 0x4
		float filmDesaturation; //OFS: 0x38 SIZE: 0x4
		bool filmInvert; //OFS: 0x3C SIZE: 0x1
		float filmLightTint[3]; //OFS: 0x40 SIZE: 0xC
		float filmDarkTint[3]; //OFS: 0x4C SIZE: 0xC
		bool reviveEnable; //OFS: 0x58 SIZE: 0x1
		float reviveContrastEdge; //OFS: 0x5C SIZE: 0x4
		float reviveBrightnessEdge; //OFS: 0x60 SIZE: 0x4
		float reviveDesaturationEdge; //OFS: 0x64 SIZE: 0x4
		float reviveDarkTintEdge[3]; //OFS: 0x68 SIZE: 0xC
		float reviveLightTintEdge[3]; //OFS: 0x74 SIZE: 0xC
		float reviveBlurRadiusEdge; //OFS: 0x80 SIZE: 0x4
		float reviveMotionblurWeight; //OFS: 0x84 SIZE: 0x4
		float reviveContrastCenter; //OFS: 0x88 SIZE: 0x4
		float reviveBrightnessCenter; //OFS: 0x8C SIZE: 0x4
		float reviveDesaturationCenter; //OFS: 0x90 SIZE: 0x4
		float reviveDarkTintCenter[3]; //OFS: 0x94 SIZE: 0xC
		float reviveLightTintCenter[3]; //OFS: 0xA0 SIZE: 0xC
		float masterRingmod; //OFS: 0xAC SIZE: 0x4
		float reverbRingmod; //OFS: 0xB0 SIZE: 0x4
		float hiFilter; //OFS: 0xB4 SIZE: 0x4
		float lowFilter; //OFS: 0xB8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(visionSetVars_t, 0xBC);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, glowEnable, 0x0);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, glowBloomCutoff, 0x4);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, glowBloomDesaturation, 0x8);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, glowBloomIntensity0, 0xC);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, glowBloomIntensity1, 0x10);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, glowRadius0, 0x14);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, glowRadius1, 0x18);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, glowSkyBleedIntensity0, 0x1C);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, glowSkyBleedIntensity1, 0x20);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, glowRayExpansion, 0x24);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, glowRayIntensity, 0x28);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, filmEnable, 0x2C);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, filmBrightness, 0x30);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, filmContrast, 0x34);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, filmDesaturation, 0x38);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, filmInvert, 0x3C);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, filmLightTint, 0x40);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, filmDarkTint, 0x4C);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, reviveEnable, 0x58);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, reviveContrastEdge, 0x5C);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, reviveBrightnessEdge, 0x60);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, reviveDesaturationEdge, 0x64);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, reviveDarkTintEdge, 0x68);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, reviveLightTintEdge, 0x74);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, reviveBlurRadiusEdge, 0x80);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, reviveMotionblurWeight, 0x84);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, reviveContrastCenter, 0x88);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, reviveBrightnessCenter, 0x8C);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, reviveDesaturationCenter, 0x90);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, reviveDarkTintCenter, 0x94);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, reviveLightTintCenter, 0xA0);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, masterRingmod, 0xAC);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, reverbRingmod, 0xB0);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, hiFilter, 0xB4);
	ASSERT_STRUCT_OFFSET(visionSetVars_t, lowFilter, 0xB8);

	struct visionSetLerpData_t
	{
		int timeStart; //OFS: 0x0 SIZE: 0x4
		int timeDuration; //OFS: 0x4 SIZE: 0x4
		visionSetLerpStyle_t style; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(visionSetLerpData_t, 0xC);
	ASSERT_STRUCT_OFFSET(visionSetLerpData_t, timeStart, 0x0);
	ASSERT_STRUCT_OFFSET(visionSetLerpData_t, timeDuration, 0x4);
	ASSERT_STRUCT_OFFSET(visionSetLerpData_t, style, 0x8);

	struct cg_s_lastFrame
	{
		float aimSpreadScale; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(cg_s_lastFrame, 0x4);
	ASSERT_STRUCT_OFFSET(cg_s_lastFrame, aimSpreadScale, 0x0);

	struct hudElemSoundInfo_t
	{
		int lastPlayedTime; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(hudElemSoundInfo_t, 0x4);
	ASSERT_STRUCT_OFFSET(hudElemSoundInfo_t, lastPlayedTime, 0x0);

	struct markerInfo_t
	{
		markerState_t state; //OFS: 0x0 SIZE: 0x4
		char shader[1024]; //OFS: 0x4 SIZE: 0x400
		float scale; //OFS: 0x404 SIZE: 0x4
		int entityNum; //OFS: 0x408 SIZE: 0x4
		float vector[3]; //OFS: 0x40C SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(markerInfo_t, 0x418);
	ASSERT_STRUCT_OFFSET(markerInfo_t, state, 0x0);
	ASSERT_STRUCT_OFFSET(markerInfo_t, shader, 0x4);
	ASSERT_STRUCT_OFFSET(markerInfo_t, scale, 0x404);
	ASSERT_STRUCT_OFFSET(markerInfo_t, entityNum, 0x408);
	ASSERT_STRUCT_OFFSET(markerInfo_t, vector, 0x40C);

	struct cg_s
	{
		int clientNum; //OFS: 0x0 SIZE: 0x4
		int localClientNum; //OFS: 0x4 SIZE: 0x4
		DemoType demoType; //OFS: 0x8 SIZE: 0x4
		CubemapShot cubemapShot; //OFS: 0xC SIZE: 0x4
		int cubemapSize; //OFS: 0x10 SIZE: 0x4
		int renderScreen; //OFS: 0x14 SIZE: 0x4
		int latestSnapshotNum; //OFS: 0x18 SIZE: 0x4
		int snapServerTime; //OFS: 0x1C SIZE: 0x4
		int loaded; //OFS: 0x20 SIZE: 0x4
		snapshot_s * snap; //OFS: 0x24 SIZE: 0x4
		snapshot_s * nextSnap; //OFS: 0x28 SIZE: 0x4
		snapshot_s activeSnapshots[2]; //OFS: 0x2C SIZE: 0xAAC40
		centity_s * currTarget; //OFS: 0xAAC6C SIZE: 0x4
		XModel * knifeModel; //OFS: 0xAAC70 SIZE: 0x4
		float frameInterpolation; //OFS: 0xAAC74 SIZE: 0x4
		int frametime; //OFS: 0xAAC78 SIZE: 0x4
		int time; //OFS: 0xAAC7C SIZE: 0x4
		int time_real; //OFS: 0xAAC80 SIZE: 0x4
		int oldTime; //OFS: 0xAAC84 SIZE: 0x4
		int physicsTime; //OFS: 0xAAC88 SIZE: 0x4
		char mapRestart; //OFS: 0xAAC8C SIZE: 0x1
		int renderingThirdPerson; //OFS: 0xAAC90 SIZE: 0x4
		void * script_camera; //OFS: 0xAAC94 SIZE: 0x4
		playerState_s predictedPlayerState; //OFS: 0xAAC98 SIZE: 0x20AC
		centity_s predictedPlayerEntity; //OFS: 0xACD44 SIZE: 0x2D4
		playerEntity_t playerEntity; //OFS: 0xAD018 SIZE: 0x3C
		int predictedErrorTime; //OFS: 0xAD054 SIZE: 0x4
		float predictedError[3]; //OFS: 0xAD058 SIZE: 0xC
		_BYTE gapAD064[12]; //OFS: 0xAD064 SIZE: 0xC
		float landChange; //OFS: 0xAD070 SIZE: 0x4
		int landTime; //OFS: 0xAD074 SIZE: 0x4
		float heightToCeiling; //OFS: 0xAD078 SIZE: 0x4
		int heightToCeilingTS; //OFS: 0xAD07C SIZE: 0x4
		refdef_s refdef; //OFS: 0xAD080 SIZE: 0x42E4
		float refdefViewAngles[3]; //OFS: 0xB1364 SIZE: 0xC
		Camera cameraData; //OFS: 0xB1370 SIZE: 0x50
		float swayViewAngles[3]; //OFS: 0xB13C0 SIZE: 0xC
		float swayAngles[3]; //OFS: 0xB13CC SIZE: 0xC
		float swayOffset[3]; //OFS: 0xB13D8 SIZE: 0xC
		float lastStandSwayAngles[3]; //OFS: 0xB13E4 SIZE: 0xC
		float lastStandSwayAVel[3]; //OFS: 0xB13F0 SIZE: 0xC
		float lastStandSwayTarget[3]; //OFS: 0xB13FC SIZE: 0xC
		int iEntityLastType[2048]; //OFS: 0xB1408 SIZE: 0x2000
		XModel * pEntityLastXMode[2048]; //OFS: 0xB3408 SIZE: 0x2000
		bool bEntityDObjDirty[2048]; //OFS: 0xB5408 SIZE: 0x800
		int iEntityLastAnimtree[2048]; //OFS: 0xB5C08 SIZE: 0x2000
		float zoomSensitivity; //OFS: 0xB7C08 SIZE: 0x4
		char isLoading; //OFS: 0xB7C0C SIZE: 0x1
		char objectiveText[1024]; //OFS: 0xB7C0D SIZE: 0x400
		int vehicleInitView; //OFS: 0xB8010 SIZE: 0x4
		float prevVehicleInvAxis[3][3]; //OFS: 0xB8014 SIZE: 0x24
		char vehicleViewLocked; //OFS: 0xB8038 SIZE: 0x1
		float vehicleViewLockedAngles[3]; //OFS: 0xB803C SIZE: 0xC
		char scriptMainMenu[256]; //OFS: 0xB8048 SIZE: 0x100
		int scoresRequestTime; //OFS: 0xB8148 SIZE: 0x4
		int numScores; //OFS: 0xB814C SIZE: 0x4
		score_t scores[4]; //OFS: 0xB8150 SIZE: 0xD0
		int showScores_real; //OFS: 0xB8220 SIZE: 0x4
		int scoreFadeTime_real; //OFS: 0xB8224 SIZE: 0x4
		int scoresOffBottom; //OFS: 0xB8228 SIZE: 0x4
		int scoresBottom; //OFS: 0xB822C SIZE: 0x4
		int firstLineVisible; //OFS: 0xB8230 SIZE: 0x4
		int lastLineVisible; //OFS: 0xB8234 SIZE: 0x4
		int drawHud; //OFS: 0xB8238 SIZE: 0x4
		int timeScaleTimeStart; //OFS: 0xB823C SIZE: 0x4
		float timeScaleStart; //OFS: 0xB8240 SIZE: 0x4
		int timeScaleTimeEnd; //OFS: 0xB8244 SIZE: 0x4
		float timeScaleEnd; //OFS: 0xB8248 SIZE: 0x4
		int crosshairClientNum; //OFS: 0xB824C SIZE: 0x4
		int crosshairClientLastTime; //OFS: 0xB8250 SIZE: 0x4
		int crosshairClientStartTime; //OFS: 0xB8254 SIZE: 0x4
		int identifyClientNum; //OFS: 0xB8258 SIZE: 0x4
		int deadquoteStartTime; //OFS: 0xB825C SIZE: 0x4
		int cursorHintIcon; //OFS: 0xB8260 SIZE: 0x4
		int cursorHintTime; //OFS: 0xB8264 SIZE: 0x4
		int cursorHintFade; //OFS: 0xB8268 SIZE: 0x4
		int cursorHintString; //OFS: 0xB826C SIZE: 0x4
		int lastClipFlashTime; //OFS: 0xB8270 SIZE: 0x4
		int invalidCmdHintType; //OFS: 0xB8274 SIZE: 0x4
		int invalidCmdHintTime; //OFS: 0xB8278 SIZE: 0x4
		int successfulCmdHintType; //OFS: 0xB827C SIZE: 0x4
		int successfulCmdHintTime; //OFS: 0xB8280 SIZE: 0x4
		int lastHealthPulseTime; //OFS: 0xB8284 SIZE: 0x4
		int lastHealthLerpDelay; //OFS: 0xB8288 SIZE: 0x4
		int lastHealthClient; //OFS: 0xB828C SIZE: 0x4
		float lastHealth; //OFS: 0xB8290 SIZE: 0x4
		float healthOverlayFromAlpha; //OFS: 0xB8294 SIZE: 0x4
		float healthOverlayToAlpha; //OFS: 0xB8298 SIZE: 0x4
		int healthOverlayPulseTime; //OFS: 0xB829C SIZE: 0x4
		int healthOverlayPulseDuration; //OFS: 0xB82A0 SIZE: 0x4
		int healthOverlayPulsePhase; //OFS: 0xB82A4 SIZE: 0x4
		bool healthOverlayHurt; //OFS: 0xB82A8 SIZE: 0x1
		int healthOverlayLastHitTime; //OFS: 0xB82AC SIZE: 0x4
		float healthOverlayOldHealth; //OFS: 0xB82B0 SIZE: 0x4
		int healthOverlayPulseIndex; //OFS: 0xB82B4 SIZE: 0x4
		int proneBlockedEndTime; //OFS: 0xB82B8 SIZE: 0x4
		int lastStance; //OFS: 0xB82BC SIZE: 0x4
		int lastStanceChangeTime; //OFS: 0xB82C0 SIZE: 0x4
		int lastStanceFlashTime; //OFS: 0xB82C4 SIZE: 0x4
		int voiceTime; //OFS: 0xB82C8 SIZE: 0x4
		int weaponSelect; //OFS: 0xB82CC SIZE: 0x4
		int weaponSelectTime; //OFS: 0xB82D0 SIZE: 0x4
		int weaponLatestPrimaryIdx; //OFS: 0xB82D4 SIZE: 0x4
		int prevViewmodelWeapon; //OFS: 0xB82D8 SIZE: 0x4
		int equippedOffHand; //OFS: 0xB82DC SIZE: 0x4
		viewDamage_t viewDamage[8]; //OFS: 0xB82E0 SIZE: 0x60
		int damageTime; //OFS: 0xB8340 SIZE: 0x4
		float damageX; //OFS: 0xB8344 SIZE: 0x4
		float damageY; //OFS: 0xB8348 SIZE: 0x4
		float damageValue; //OFS: 0xB834C SIZE: 0x4
		float viewFade; //OFS: 0xB8350 SIZE: 0x4
		int waterDropCount; //OFS: 0xB8354 SIZE: 0x4
		int waterDropStartTime; //OFS: 0xB8358 SIZE: 0x4
		int waterDropStopTime; //OFS: 0xB835C SIZE: 0x4
		int weapIdleTime; //OFS: 0xB8360 SIZE: 0x4
		int nomarks; //OFS: 0xB8364 SIZE: 0x4
		int v_dmg_time; //OFS: 0xB8368 SIZE: 0x4
		float v_dmg_pitch; //OFS: 0xB836C SIZE: 0x4
		float v_dmg_roll; //OFS: 0xB8370 SIZE: 0x4
		float fBobCycle; //OFS: 0xB8374 SIZE: 0x4
		float xyspeed; //OFS: 0xB8378 SIZE: 0x4
		float kickAVel[3]; //OFS: 0xB837C SIZE: 0xC
		float kickAngles[3]; //OFS: 0xB8388 SIZE: 0xC
		float offsetAngles[3]; //OFS: 0xB8394 SIZE: 0xC
		char field_B83A0; //OFS: 0xB83A0 SIZE: 0x1
		int gunPitch; //OFS: 0xB83A4 SIZE: 0x4
		int gunYaw; //OFS: 0xB83A8 SIZE: 0x4
		int gunXOfs; //OFS: 0xB83AC SIZE: 0x4
		int gunYOfs; //OFS: 0xB83B0 SIZE: 0x4
		int gunZOfs; //OFS: 0xB83B4 SIZE: 0x4
		float vGunOffset[3]; //OFS: 0xB83B8 SIZE: 0xC
		float recoilSpeed[3]; //OFS: 0xB83C4 SIZE: 0xC
		float vAngOfs[3]; //OFS: 0xB83D0 SIZE: 0xC
		float flamethrowerYawCap; //OFS: 0xB83DC SIZE: 0x4
		float flamethrowerPitchCap; //OFS: 0xB83E0 SIZE: 0x4
		float flamethrowerKickOffset[3]; //OFS: 0xB83E4 SIZE: 0xC
		float viewModelAxis[4][3]; //OFS: 0xB83F0 SIZE: 0x30
		char hideViewModel; //OFS: 0xB8420 SIZE: 0x1
		float rumbleScale; //OFS: 0xB8424 SIZE: 0x4
		int compassNorthYaw; //OFS: 0xB8428 SIZE: 0x4
		float compassNorth[2]; //OFS: 0xB842C SIZE: 0x8
		Material * compassMapMaterial; //OFS: 0xB8434 SIZE: 0x4
		float compassMapUpperLeft[2]; //OFS: 0xB8438 SIZE: 0x8
		float compassMapWorldSize[2]; //OFS: 0xB8440 SIZE: 0x8
		int compassLastTime; //OFS: 0xB8448 SIZE: 0x4
		float compassYaw; //OFS: 0xB844C SIZE: 0x4
		float compassSpeed; //OFS: 0xB8450 SIZE: 0x4
		int compassFadeTime; //OFS: 0xB8454 SIZE: 0x4
		int healthFadeTime; //OFS: 0xB8458 SIZE: 0x4
		int ammoFadeTime; //OFS: 0xB845C SIZE: 0x4
		int stanceFadeTime; //OFS: 0xB8460 SIZE: 0x4
		int sprintFadeTime; //OFS: 0xB8464 SIZE: 0x4
		int offhandFadeTime; //OFS: 0xB8468 SIZE: 0x4
		int offhandFlashTime; //OFS: 0xB846C SIZE: 0x4
		objectiveInfo_t objectiveInfo_t[16]; //OFS: 0xB8470 SIZE: 0x4900
		int showScores; //OFS: 0xBCD70 SIZE: 0x4
		int scoreFadeTime; //OFS: 0xBCD74 SIZE: 0x4
		targetInfo_t targets[32]; //OFS: 0xBCD78 SIZE: 0x380
		shellshock_t shellshock; //OFS: 0xBD0F8 SIZE: 0x20
		int field_BD118; //OFS: 0xBD118 SIZE: 0x4
		int field_BD11C; //OFS: 0xBD11C SIZE: 0x4
		int field_BD120; //OFS: 0xBD120 SIZE: 0x4
		int holdBreathTime; //OFS: 0xBD124 SIZE: 0x4
		int holdBreathInTime; //OFS: 0xBD128 SIZE: 0x4
		int holdBreathDelay; //OFS: 0xBD12C SIZE: 0x4
		float holdBreathFrac; //OFS: 0xBD130 SIZE: 0x4
		int waterBob; //OFS: 0xBD134 SIZE: 0x4
		int bloodLastTime; //OFS: 0xBD138 SIZE: 0x4
		int radarProgress; //OFS: 0xBD13C SIZE: 0x4
		float selectedLocation[2]; //OFS: 0xBD140 SIZE: 0x8
		SprintState sprintStates; //OFS: 0xBD148 SIZE: 0x14
		int adsViewErrorDone; //OFS: 0xBD15C SIZE: 0x4
		int inKillCam; //OFS: 0xBD160 SIZE: 0x4
		int field_BD164; //OFS: 0xBD164 SIZE: 0x4
		bgs_s bgs; //OFS: 0xBD168 SIZE: 0x91B78
		char field_14ECE0[45056]; //OFS: 0x14ECE0 SIZE: 0xB000
		float vehReticleOffset[2]; //OFS: 0x159CE0 SIZE: 0x8
		float vehReticleVel[2]; //OFS: 0x159CE8 SIZE: 0x8
		int vehReticleLockOnStartTime; //OFS: 0x159CF0 SIZE: 0x4
		int vehReticleLockOnDuration; //OFS: 0x159CF4 SIZE: 0x4
		int vehReticleLockOnEntNum; //OFS: 0x159CF8 SIZE: 0x4
		cpose_t viewModelPose; //OFS: 0x159CFC SIZE: 0xD0
		visionSetVars_t visionSetPreLoaded[8]; //OFS: 0x159DCC SIZE: 0x5E0
		char visionSetPreLoadedName[512]; //OFS: 0x15A3AC SIZE: 0x200
		visionSetVars_t visionSetFrom[6]; //OFS: 0x15A5AC SIZE: 0x468
		visionSetVars_t visionSetTo[6]; //OFS: 0x15AA14 SIZE: 0x468
		visionSetVars_t visionSetCurrent[6]; //OFS: 0x15AE7C SIZE: 0x468
		visionSetLerpData_t visionSetLerpData[6]; //OFS: 0x15B2E4 SIZE: 0x48
		char visionNameNaked[64]; //OFS: 0x15B32C SIZE: 0x40
		char visionNameNight[64]; //OFS: 0x15B36C SIZE: 0x40
		char visionNameVampire0[64]; //OFS: 0x15B3AC SIZE: 0x40
		char visionNameVampire1[64]; //OFS: 0x15B3EC SIZE: 0x40
		char visionNameBerserker0[64]; //OFS: 0x15B42C SIZE: 0x40
		char visionNameBerserker1[64]; //OFS: 0x15B46C SIZE: 0x40
		char visionNameLastStand[64]; //OFS: 0x15B4AC SIZE: 0x40
		char visionNameDeath[64]; //OFS: 0x15B4EC SIZE: 0x40
		int extraButtons; //OFS: 0x15B52C SIZE: 0x4
		int lastActionSlotTime; //OFS: 0x15B530 SIZE: 0x4
		int playerTeleported; //OFS: 0x15B534 SIZE: 0x4
		int stepViewStart; //OFS: 0x15B538 SIZE: 0x4
		float stepViewChange; //OFS: 0x15B53C SIZE: 0x4
		cg_s_lastFrame lastFrame; //OFS: 0x15B540 SIZE: 0x4
		int nextRippleTime; //OFS: 0x15B544 SIZE: 0x4
		float zNear; //OFS: 0x15B548 SIZE: 0x4
		float prevLinkedInvQuat[4]; //OFS: 0x15B54C SIZE: 0x10
		float linkAnglesFrac; //OFS: 0x15B55C SIZE: 0x4
		char prevLinkAnglesSet; //OFS: 0x15B560 SIZE: 0x1
		hudElemSoundInfo_t hudElemSound[32]; //OFS: 0x15B564 SIZE: 0x80
		markerInfo_t markers[8]; //OFS: 0x15B5E4 SIZE: 0x20C0
		int impactEffectsNext; //OFS: 0x15D6A4 SIZE: 0x4
		int impactEffects[256]; //OFS: 0x15D6A8 SIZE: 0x400
		char visionsetVampireEnable; //OFS: 0x15DAA8 SIZE: 0x1
		char visionsetBerserkerEnable; //OFS: 0x15DAA9 SIZE: 0x1
		char visionsetDeathEnable; //OFS: 0x15DAAA SIZE: 0x1
		int generateClientSave; //OFS: 0x15DAAC SIZE: 0x4
		int commitClientSave; //OFS: 0x15DAB0 SIZE: 0x4
		char zapperMenuActive; //OFS: 0x15DAB4 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(cg_s, 0x15DAB8);
	ASSERT_STRUCT_OFFSET(cg_s, clientNum, 0x0);
	ASSERT_STRUCT_OFFSET(cg_s, localClientNum, 0x4);
	ASSERT_STRUCT_OFFSET(cg_s, demoType, 0x8);
	ASSERT_STRUCT_OFFSET(cg_s, cubemapShot, 0xC);
	ASSERT_STRUCT_OFFSET(cg_s, cubemapSize, 0x10);
	ASSERT_STRUCT_OFFSET(cg_s, renderScreen, 0x14);
	ASSERT_STRUCT_OFFSET(cg_s, latestSnapshotNum, 0x18);
	ASSERT_STRUCT_OFFSET(cg_s, snapServerTime, 0x1C);
	ASSERT_STRUCT_OFFSET(cg_s, loaded, 0x20);
	ASSERT_STRUCT_OFFSET(cg_s, snap, 0x24);
	ASSERT_STRUCT_OFFSET(cg_s, nextSnap, 0x28);
	ASSERT_STRUCT_OFFSET(cg_s, activeSnapshots, 0x2C);
	ASSERT_STRUCT_OFFSET(cg_s, currTarget, 0xAAC6C);
	ASSERT_STRUCT_OFFSET(cg_s, knifeModel, 0xAAC70);
	ASSERT_STRUCT_OFFSET(cg_s, frameInterpolation, 0xAAC74);
	ASSERT_STRUCT_OFFSET(cg_s, frametime, 0xAAC78);
	ASSERT_STRUCT_OFFSET(cg_s, time, 0xAAC7C);
	ASSERT_STRUCT_OFFSET(cg_s, time_real, 0xAAC80);
	ASSERT_STRUCT_OFFSET(cg_s, oldTime, 0xAAC84);
	ASSERT_STRUCT_OFFSET(cg_s, physicsTime, 0xAAC88);
	ASSERT_STRUCT_OFFSET(cg_s, mapRestart, 0xAAC8C);
	ASSERT_STRUCT_OFFSET(cg_s, renderingThirdPerson, 0xAAC90);
	ASSERT_STRUCT_OFFSET(cg_s, script_camera, 0xAAC94);
	ASSERT_STRUCT_OFFSET(cg_s, predictedPlayerState, 0xAAC98);
	ASSERT_STRUCT_OFFSET(cg_s, predictedPlayerEntity, 0xACD44);
	ASSERT_STRUCT_OFFSET(cg_s, playerEntity, 0xAD018);
	ASSERT_STRUCT_OFFSET(cg_s, predictedErrorTime, 0xAD054);
	ASSERT_STRUCT_OFFSET(cg_s, predictedError, 0xAD058);
	ASSERT_STRUCT_OFFSET(cg_s, gapAD064, 0xAD064);
	ASSERT_STRUCT_OFFSET(cg_s, landChange, 0xAD070);
	ASSERT_STRUCT_OFFSET(cg_s, landTime, 0xAD074);
	ASSERT_STRUCT_OFFSET(cg_s, heightToCeiling, 0xAD078);
	ASSERT_STRUCT_OFFSET(cg_s, heightToCeilingTS, 0xAD07C);
	ASSERT_STRUCT_OFFSET(cg_s, refdef, 0xAD080);
	ASSERT_STRUCT_OFFSET(cg_s, refdefViewAngles, 0xB1364);
	ASSERT_STRUCT_OFFSET(cg_s, cameraData, 0xB1370);
	ASSERT_STRUCT_OFFSET(cg_s, swayViewAngles, 0xB13C0);
	ASSERT_STRUCT_OFFSET(cg_s, swayAngles, 0xB13CC);
	ASSERT_STRUCT_OFFSET(cg_s, swayOffset, 0xB13D8);
	ASSERT_STRUCT_OFFSET(cg_s, lastStandSwayAngles, 0xB13E4);
	ASSERT_STRUCT_OFFSET(cg_s, lastStandSwayAVel, 0xB13F0);
	ASSERT_STRUCT_OFFSET(cg_s, lastStandSwayTarget, 0xB13FC);
	ASSERT_STRUCT_OFFSET(cg_s, iEntityLastType, 0xB1408);
	ASSERT_STRUCT_OFFSET(cg_s, pEntityLastXMode, 0xB3408);
	ASSERT_STRUCT_OFFSET(cg_s, bEntityDObjDirty, 0xB5408);
	ASSERT_STRUCT_OFFSET(cg_s, iEntityLastAnimtree, 0xB5C08);
	ASSERT_STRUCT_OFFSET(cg_s, zoomSensitivity, 0xB7C08);
	ASSERT_STRUCT_OFFSET(cg_s, isLoading, 0xB7C0C);
	ASSERT_STRUCT_OFFSET(cg_s, objectiveText, 0xB7C0D);
	ASSERT_STRUCT_OFFSET(cg_s, vehicleInitView, 0xB8010);
	ASSERT_STRUCT_OFFSET(cg_s, prevVehicleInvAxis, 0xB8014);
	ASSERT_STRUCT_OFFSET(cg_s, vehicleViewLocked, 0xB8038);
	ASSERT_STRUCT_OFFSET(cg_s, vehicleViewLockedAngles, 0xB803C);
	ASSERT_STRUCT_OFFSET(cg_s, scriptMainMenu, 0xB8048);
	ASSERT_STRUCT_OFFSET(cg_s, scoresRequestTime, 0xB8148);
	ASSERT_STRUCT_OFFSET(cg_s, numScores, 0xB814C);
	ASSERT_STRUCT_OFFSET(cg_s, scores, 0xB8150);
	ASSERT_STRUCT_OFFSET(cg_s, showScores_real, 0xB8220);
	ASSERT_STRUCT_OFFSET(cg_s, scoreFadeTime_real, 0xB8224);
	ASSERT_STRUCT_OFFSET(cg_s, scoresOffBottom, 0xB8228);
	ASSERT_STRUCT_OFFSET(cg_s, scoresBottom, 0xB822C);
	ASSERT_STRUCT_OFFSET(cg_s, firstLineVisible, 0xB8230);
	ASSERT_STRUCT_OFFSET(cg_s, lastLineVisible, 0xB8234);
	ASSERT_STRUCT_OFFSET(cg_s, drawHud, 0xB8238);
	ASSERT_STRUCT_OFFSET(cg_s, timeScaleTimeStart, 0xB823C);
	ASSERT_STRUCT_OFFSET(cg_s, timeScaleStart, 0xB8240);
	ASSERT_STRUCT_OFFSET(cg_s, timeScaleTimeEnd, 0xB8244);
	ASSERT_STRUCT_OFFSET(cg_s, timeScaleEnd, 0xB8248);
	ASSERT_STRUCT_OFFSET(cg_s, crosshairClientNum, 0xB824C);
	ASSERT_STRUCT_OFFSET(cg_s, crosshairClientLastTime, 0xB8250);
	ASSERT_STRUCT_OFFSET(cg_s, crosshairClientStartTime, 0xB8254);
	ASSERT_STRUCT_OFFSET(cg_s, identifyClientNum, 0xB8258);
	ASSERT_STRUCT_OFFSET(cg_s, deadquoteStartTime, 0xB825C);
	ASSERT_STRUCT_OFFSET(cg_s, cursorHintIcon, 0xB8260);
	ASSERT_STRUCT_OFFSET(cg_s, cursorHintTime, 0xB8264);
	ASSERT_STRUCT_OFFSET(cg_s, cursorHintFade, 0xB8268);
	ASSERT_STRUCT_OFFSET(cg_s, cursorHintString, 0xB826C);
	ASSERT_STRUCT_OFFSET(cg_s, lastClipFlashTime, 0xB8270);
	ASSERT_STRUCT_OFFSET(cg_s, invalidCmdHintType, 0xB8274);
	ASSERT_STRUCT_OFFSET(cg_s, invalidCmdHintTime, 0xB8278);
	ASSERT_STRUCT_OFFSET(cg_s, successfulCmdHintType, 0xB827C);
	ASSERT_STRUCT_OFFSET(cg_s, successfulCmdHintTime, 0xB8280);
	ASSERT_STRUCT_OFFSET(cg_s, lastHealthPulseTime, 0xB8284);
	ASSERT_STRUCT_OFFSET(cg_s, lastHealthLerpDelay, 0xB8288);
	ASSERT_STRUCT_OFFSET(cg_s, lastHealthClient, 0xB828C);
	ASSERT_STRUCT_OFFSET(cg_s, lastHealth, 0xB8290);
	ASSERT_STRUCT_OFFSET(cg_s, healthOverlayFromAlpha, 0xB8294);
	ASSERT_STRUCT_OFFSET(cg_s, healthOverlayToAlpha, 0xB8298);
	ASSERT_STRUCT_OFFSET(cg_s, healthOverlayPulseTime, 0xB829C);
	ASSERT_STRUCT_OFFSET(cg_s, healthOverlayPulseDuration, 0xB82A0);
	ASSERT_STRUCT_OFFSET(cg_s, healthOverlayPulsePhase, 0xB82A4);
	ASSERT_STRUCT_OFFSET(cg_s, healthOverlayHurt, 0xB82A8);
	ASSERT_STRUCT_OFFSET(cg_s, healthOverlayLastHitTime, 0xB82AC);
	ASSERT_STRUCT_OFFSET(cg_s, healthOverlayOldHealth, 0xB82B0);
	ASSERT_STRUCT_OFFSET(cg_s, healthOverlayPulseIndex, 0xB82B4);
	ASSERT_STRUCT_OFFSET(cg_s, proneBlockedEndTime, 0xB82B8);
	ASSERT_STRUCT_OFFSET(cg_s, lastStance, 0xB82BC);
	ASSERT_STRUCT_OFFSET(cg_s, lastStanceChangeTime, 0xB82C0);
	ASSERT_STRUCT_OFFSET(cg_s, lastStanceFlashTime, 0xB82C4);
	ASSERT_STRUCT_OFFSET(cg_s, voiceTime, 0xB82C8);
	ASSERT_STRUCT_OFFSET(cg_s, weaponSelect, 0xB82CC);
	ASSERT_STRUCT_OFFSET(cg_s, weaponSelectTime, 0xB82D0);
	ASSERT_STRUCT_OFFSET(cg_s, weaponLatestPrimaryIdx, 0xB82D4);
	ASSERT_STRUCT_OFFSET(cg_s, prevViewmodelWeapon, 0xB82D8);
	ASSERT_STRUCT_OFFSET(cg_s, equippedOffHand, 0xB82DC);
	ASSERT_STRUCT_OFFSET(cg_s, viewDamage, 0xB82E0);
	ASSERT_STRUCT_OFFSET(cg_s, damageTime, 0xB8340);
	ASSERT_STRUCT_OFFSET(cg_s, damageX, 0xB8344);
	ASSERT_STRUCT_OFFSET(cg_s, damageY, 0xB8348);
	ASSERT_STRUCT_OFFSET(cg_s, damageValue, 0xB834C);
	ASSERT_STRUCT_OFFSET(cg_s, viewFade, 0xB8350);
	ASSERT_STRUCT_OFFSET(cg_s, waterDropCount, 0xB8354);
	ASSERT_STRUCT_OFFSET(cg_s, waterDropStartTime, 0xB8358);
	ASSERT_STRUCT_OFFSET(cg_s, waterDropStopTime, 0xB835C);
	ASSERT_STRUCT_OFFSET(cg_s, weapIdleTime, 0xB8360);
	ASSERT_STRUCT_OFFSET(cg_s, nomarks, 0xB8364);
	ASSERT_STRUCT_OFFSET(cg_s, v_dmg_time, 0xB8368);
	ASSERT_STRUCT_OFFSET(cg_s, v_dmg_pitch, 0xB836C);
	ASSERT_STRUCT_OFFSET(cg_s, v_dmg_roll, 0xB8370);
	ASSERT_STRUCT_OFFSET(cg_s, fBobCycle, 0xB8374);
	ASSERT_STRUCT_OFFSET(cg_s, xyspeed, 0xB8378);
	ASSERT_STRUCT_OFFSET(cg_s, kickAVel, 0xB837C);
	ASSERT_STRUCT_OFFSET(cg_s, kickAngles, 0xB8388);
	ASSERT_STRUCT_OFFSET(cg_s, offsetAngles, 0xB8394);
	ASSERT_STRUCT_OFFSET(cg_s, field_B83A0, 0xB83A0);
	ASSERT_STRUCT_OFFSET(cg_s, gunPitch, 0xB83A4);
	ASSERT_STRUCT_OFFSET(cg_s, gunYaw, 0xB83A8);
	ASSERT_STRUCT_OFFSET(cg_s, gunXOfs, 0xB83AC);
	ASSERT_STRUCT_OFFSET(cg_s, gunYOfs, 0xB83B0);
	ASSERT_STRUCT_OFFSET(cg_s, gunZOfs, 0xB83B4);
	ASSERT_STRUCT_OFFSET(cg_s, vGunOffset, 0xB83B8);
	ASSERT_STRUCT_OFFSET(cg_s, recoilSpeed, 0xB83C4);
	ASSERT_STRUCT_OFFSET(cg_s, vAngOfs, 0xB83D0);
	ASSERT_STRUCT_OFFSET(cg_s, flamethrowerYawCap, 0xB83DC);
	ASSERT_STRUCT_OFFSET(cg_s, flamethrowerPitchCap, 0xB83E0);
	ASSERT_STRUCT_OFFSET(cg_s, flamethrowerKickOffset, 0xB83E4);
	ASSERT_STRUCT_OFFSET(cg_s, viewModelAxis, 0xB83F0);
	ASSERT_STRUCT_OFFSET(cg_s, hideViewModel, 0xB8420);
	ASSERT_STRUCT_OFFSET(cg_s, rumbleScale, 0xB8424);
	ASSERT_STRUCT_OFFSET(cg_s, compassNorthYaw, 0xB8428);
	ASSERT_STRUCT_OFFSET(cg_s, compassNorth, 0xB842C);
	ASSERT_STRUCT_OFFSET(cg_s, compassMapMaterial, 0xB8434);
	ASSERT_STRUCT_OFFSET(cg_s, compassMapUpperLeft, 0xB8438);
	ASSERT_STRUCT_OFFSET(cg_s, compassMapWorldSize, 0xB8440);
	ASSERT_STRUCT_OFFSET(cg_s, compassLastTime, 0xB8448);
	ASSERT_STRUCT_OFFSET(cg_s, compassYaw, 0xB844C);
	ASSERT_STRUCT_OFFSET(cg_s, compassSpeed, 0xB8450);
	ASSERT_STRUCT_OFFSET(cg_s, compassFadeTime, 0xB8454);
	ASSERT_STRUCT_OFFSET(cg_s, healthFadeTime, 0xB8458);
	ASSERT_STRUCT_OFFSET(cg_s, ammoFadeTime, 0xB845C);
	ASSERT_STRUCT_OFFSET(cg_s, stanceFadeTime, 0xB8460);
	ASSERT_STRUCT_OFFSET(cg_s, sprintFadeTime, 0xB8464);
	ASSERT_STRUCT_OFFSET(cg_s, offhandFadeTime, 0xB8468);
	ASSERT_STRUCT_OFFSET(cg_s, offhandFlashTime, 0xB846C);
	ASSERT_STRUCT_OFFSET(cg_s, objectiveInfo_t, 0xB8470);
	ASSERT_STRUCT_OFFSET(cg_s, showScores, 0xBCD70);
	ASSERT_STRUCT_OFFSET(cg_s, scoreFadeTime, 0xBCD74);
	ASSERT_STRUCT_OFFSET(cg_s, targets, 0xBCD78);
	ASSERT_STRUCT_OFFSET(cg_s, shellshock, 0xBD0F8);
	ASSERT_STRUCT_OFFSET(cg_s, field_BD118, 0xBD118);
	ASSERT_STRUCT_OFFSET(cg_s, field_BD11C, 0xBD11C);
	ASSERT_STRUCT_OFFSET(cg_s, field_BD120, 0xBD120);
	ASSERT_STRUCT_OFFSET(cg_s, holdBreathTime, 0xBD124);
	ASSERT_STRUCT_OFFSET(cg_s, holdBreathInTime, 0xBD128);
	ASSERT_STRUCT_OFFSET(cg_s, holdBreathDelay, 0xBD12C);
	ASSERT_STRUCT_OFFSET(cg_s, holdBreathFrac, 0xBD130);
	ASSERT_STRUCT_OFFSET(cg_s, waterBob, 0xBD134);
	ASSERT_STRUCT_OFFSET(cg_s, bloodLastTime, 0xBD138);
	ASSERT_STRUCT_OFFSET(cg_s, radarProgress, 0xBD13C);
	ASSERT_STRUCT_OFFSET(cg_s, selectedLocation, 0xBD140);
	ASSERT_STRUCT_OFFSET(cg_s, sprintStates, 0xBD148);
	ASSERT_STRUCT_OFFSET(cg_s, adsViewErrorDone, 0xBD15C);
	ASSERT_STRUCT_OFFSET(cg_s, inKillCam, 0xBD160);
	ASSERT_STRUCT_OFFSET(cg_s, field_BD164, 0xBD164);
	ASSERT_STRUCT_OFFSET(cg_s, bgs, 0xBD168);
	ASSERT_STRUCT_OFFSET(cg_s, field_14ECE0, 0x14ECE0);
	ASSERT_STRUCT_OFFSET(cg_s, vehReticleOffset, 0x159CE0);
	ASSERT_STRUCT_OFFSET(cg_s, vehReticleVel, 0x159CE8);
	ASSERT_STRUCT_OFFSET(cg_s, vehReticleLockOnStartTime, 0x159CF0);
	ASSERT_STRUCT_OFFSET(cg_s, vehReticleLockOnDuration, 0x159CF4);
	ASSERT_STRUCT_OFFSET(cg_s, vehReticleLockOnEntNum, 0x159CF8);
	ASSERT_STRUCT_OFFSET(cg_s, viewModelPose, 0x159CFC);
	ASSERT_STRUCT_OFFSET(cg_s, visionSetPreLoaded, 0x159DCC);
	ASSERT_STRUCT_OFFSET(cg_s, visionSetPreLoadedName, 0x15A3AC);
	ASSERT_STRUCT_OFFSET(cg_s, visionSetFrom, 0x15A5AC);
	ASSERT_STRUCT_OFFSET(cg_s, visionSetTo, 0x15AA14);
	ASSERT_STRUCT_OFFSET(cg_s, visionSetCurrent, 0x15AE7C);
	ASSERT_STRUCT_OFFSET(cg_s, visionSetLerpData, 0x15B2E4);
	ASSERT_STRUCT_OFFSET(cg_s, visionNameNaked, 0x15B32C);
	ASSERT_STRUCT_OFFSET(cg_s, visionNameNight, 0x15B36C);
	ASSERT_STRUCT_OFFSET(cg_s, visionNameVampire0, 0x15B3AC);
	ASSERT_STRUCT_OFFSET(cg_s, visionNameVampire1, 0x15B3EC);
	ASSERT_STRUCT_OFFSET(cg_s, visionNameBerserker0, 0x15B42C);
	ASSERT_STRUCT_OFFSET(cg_s, visionNameBerserker1, 0x15B46C);
	ASSERT_STRUCT_OFFSET(cg_s, visionNameLastStand, 0x15B4AC);
	ASSERT_STRUCT_OFFSET(cg_s, visionNameDeath, 0x15B4EC);
	ASSERT_STRUCT_OFFSET(cg_s, extraButtons, 0x15B52C);
	ASSERT_STRUCT_OFFSET(cg_s, lastActionSlotTime, 0x15B530);
	ASSERT_STRUCT_OFFSET(cg_s, playerTeleported, 0x15B534);
	ASSERT_STRUCT_OFFSET(cg_s, stepViewStart, 0x15B538);
	ASSERT_STRUCT_OFFSET(cg_s, stepViewChange, 0x15B53C);
	ASSERT_STRUCT_OFFSET(cg_s, lastFrame, 0x15B540);
	ASSERT_STRUCT_OFFSET(cg_s, nextRippleTime, 0x15B544);
	ASSERT_STRUCT_OFFSET(cg_s, zNear, 0x15B548);
	ASSERT_STRUCT_OFFSET(cg_s, prevLinkedInvQuat, 0x15B54C);
	ASSERT_STRUCT_OFFSET(cg_s, linkAnglesFrac, 0x15B55C);
	ASSERT_STRUCT_OFFSET(cg_s, prevLinkAnglesSet, 0x15B560);
	ASSERT_STRUCT_OFFSET(cg_s, hudElemSound, 0x15B564);
	ASSERT_STRUCT_OFFSET(cg_s, markers, 0x15B5E4);
	ASSERT_STRUCT_OFFSET(cg_s, impactEffectsNext, 0x15D6A4);
	ASSERT_STRUCT_OFFSET(cg_s, impactEffects, 0x15D6A8);
	ASSERT_STRUCT_OFFSET(cg_s, visionsetVampireEnable, 0x15DAA8);
	ASSERT_STRUCT_OFFSET(cg_s, visionsetBerserkerEnable, 0x15DAA9);
	ASSERT_STRUCT_OFFSET(cg_s, visionsetDeathEnable, 0x15DAAA);
	ASSERT_STRUCT_OFFSET(cg_s, generateClientSave, 0x15DAAC);
	ASSERT_STRUCT_OFFSET(cg_s, commitClientSave, 0x15DAB0);
	ASSERT_STRUCT_OFFSET(cg_s, zapperMenuActive, 0x15DAB4);

	struct SpawnVar
	{
		bool spawnVarsValid; //OFS: 0x0 SIZE: 0x1
		int numSpawnVars; //OFS: 0x4 SIZE: 0x4
		char * spawnVars[64][2]; //OFS: 0x8 SIZE: 0x200
		int numSpawnVarChars; //OFS: 0x208 SIZE: 0x4
		char spawnVarChars[2048]; //OFS: 0x20C SIZE: 0x800
	};
	ASSERT_STRUCT_SIZE(SpawnVar, 0xA0C);
	ASSERT_STRUCT_OFFSET(SpawnVar, spawnVarsValid, 0x0);
	ASSERT_STRUCT_OFFSET(SpawnVar, numSpawnVars, 0x4);
	ASSERT_STRUCT_OFFSET(SpawnVar, spawnVars, 0x8);
	ASSERT_STRUCT_OFFSET(SpawnVar, numSpawnVarChars, 0x208);
	ASSERT_STRUCT_OFFSET(SpawnVar, spawnVarChars, 0x20C);

	struct cached_tag_mat_t
	{
		int time; //OFS: 0x0 SIZE: 0x4
		int entnum; //OFS: 0x4 SIZE: 0x4
		unsigned __int16 name; //OFS: 0x8 SIZE: 0x2
		float tagMat[4][3]; //OFS: 0xC SIZE: 0x30
	};
	ASSERT_STRUCT_SIZE(cached_tag_mat_t, 0x3C);
	ASSERT_STRUCT_OFFSET(cached_tag_mat_t, time, 0x0);
	ASSERT_STRUCT_OFFSET(cached_tag_mat_t, entnum, 0x4);
	ASSERT_STRUCT_OFFSET(cached_tag_mat_t, name, 0x8);
	ASSERT_STRUCT_OFFSET(cached_tag_mat_t, tagMat, 0xC);

	struct trigger_info_t
	{
		unsigned __int16 entnum; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 otherEntnum; //OFS: 0x2 SIZE: 0x2
		int useCount; //OFS: 0x4 SIZE: 0x4
		int otherUseCount; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(trigger_info_t, 0xC);
	ASSERT_STRUCT_OFFSET(trigger_info_t, entnum, 0x0);
	ASSERT_STRUCT_OFFSET(trigger_info_t, otherEntnum, 0x2);
	ASSERT_STRUCT_OFFSET(trigger_info_t, useCount, 0x4);
	ASSERT_STRUCT_OFFSET(trigger_info_t, otherUseCount, 0x8);

	struct level_locals_s
	{
		gclient_s * clients; //OFS: 0x0 SIZE: 0x4
		gentity_s * gentities; //OFS: 0x4 SIZE: 0x4
		int unk1; //OFS: 0x8 SIZE: 0x4
		int num_entities; //OFS: 0xC SIZE: 0x4
		gentity_s * firstFreeEnt; //OFS: 0x10 SIZE: 0x4
		gentity_s * lastFreeEnt; //OFS: 0x14 SIZE: 0x4
		sentient_s * sentients; //OFS: 0x18 SIZE: 0x4
		actor_s * actors; //OFS: 0x1C SIZE: 0x4
		scr_vehicle_s * vehicles; //OFS: 0x20 SIZE: 0x4
		TurretInfo * turrets; //OFS: 0x24 SIZE: 0x4
		animCmdState_s * animCmds; //OFS: 0x28 SIZE: 0x4
		int gap_2C[1024]; //OFS: 0x2C SIZE: 0x1000
		int logFile; //OFS: 0x102C SIZE: 0x4
		int initializing; //OFS: 0x1030 SIZE: 0x4
		int clientIsSpawning; //OFS: 0x1034 SIZE: 0x4
		int maxclients; //OFS: 0x1038 SIZE: 0x4
		int framenum; //OFS: 0x103C SIZE: 0x4
		int time; //OFS: 0x1040 SIZE: 0x4
		int previousTime; //OFS: 0x1044 SIZE: 0x4
		int startTime; //OFS: 0x1048 SIZE: 0x4
		int newSession; //OFS: 0x104C SIZE: 0x4
		int actorCorpseCount; //OFS: 0x1050 SIZE: 0x4
		SpawnVar spawnVar; //OFS: 0x1054 SIZE: 0xA0C
		int reloadDelayTime; //OFS: 0x1A60 SIZE: 0x4
		int absoluteReloadDelayTime; //OFS: 0x1A64 SIZE: 0x4
		EntHandle droppedWeaponCue[32]; //OFS: 0x1A68 SIZE: 0x80
		int changelevel; //OFS: 0x1AE8 SIZE: 0x4
		int bMissionSuccess; //OFS: 0x1AEC SIZE: 0x4
		int bMissionFailed; //OFS: 0x1AF0 SIZE: 0x4
		int exitTime; //OFS: 0x1AF4 SIZE: 0x4
		int savepersist; //OFS: 0x1AF8 SIZE: 0x4
		char cinematic[64]; //OFS: 0x1AFC SIZE: 0x40
		float fFogOpaqueDist; //OFS: 0x1B3C SIZE: 0x4
		float fFogOpaqueDistSqrd; //OFS: 0x1B40 SIZE: 0x4
		unsigned int grenadeHintCount; //OFS: 0x1B44 SIZE: 0x4
		int remapCount; //OFS: 0x1B48 SIZE: 0x4
		int iSearchFrame; //OFS: 0x1B4C SIZE: 0x4
		loading_t loading; //OFS: 0x1B50 SIZE: 0x4
		int actorPredictDepth; //OFS: 0x1B54 SIZE: 0x4
		int bDrawCompassFriendlies; //OFS: 0x1B58 SIZE: 0x4
		int bPlayerIgnoreRadiusDamage; //OFS: 0x1B5C SIZE: 0x4
		int bPlayerIgnoreRadiusDamageLatched; //OFS: 0x1B60 SIZE: 0x4
		int triggerIndex; //OFS: 0x1B64 SIZE: 0x4
		int padd; //OFS: 0x1B68 SIZE: 0x4
		int currentEntityThink; //OFS: 0x1B6C SIZE: 0x4
		int currentIndex; //OFS: 0x1B70 SIZE: 0x4
		bool checkAnimChange; //OFS: 0x1B74 SIZE: 0x1
		int registerWeapons; //OFS: 0x1B78 SIZE: 0x4
		int bRegisterItems; //OFS: 0x1B7C SIZE: 0x4
		int framePos; //OFS: 0x1B80 SIZE: 0x4
		cached_tag_mat_t cachedTagMat; //OFS: 0x1B84 SIZE: 0x3C
		cached_tag_mat_t cachedEntTargetTagMat; //OFS: 0x1BC0 SIZE: 0x3C
		__int16 soundAliasFirst; //OFS: 0x1BFC SIZE: 0x2
		__int16 soundAliasLast; //OFS: 0x1BFE SIZE: 0x2
		trigger_info_t pendingTriggerList[256]; //OFS: 0x1C00 SIZE: 0xC00
		trigger_info_t currentTriggerList[256]; //OFS: 0x2800 SIZE: 0xC00
		int pendingTriggerListSize; //OFS: 0x3400 SIZE: 0x4
		int currentTriggerListSize; //OFS: 0x3404 SIZE: 0x4
		int entTriggerIndex[1024]; //OFS: 0x3408 SIZE: 0x1000
		unsigned __int8 specialIndex[1024]; //OFS: 0x4408 SIZE: 0x400
		_BYTE gap4808[2628]; //OFS: 0x4808 SIZE: 0xA44
		int scriptPrintChannel; //OFS: 0x524C SIZE: 0x4
		float compassMapUpperLeft[2]; //OFS: 0x5250 SIZE: 0x8
		float compassMapWorldSize[2]; //OFS: 0x5258 SIZE: 0x8
		float compassNorth[2]; //OFS: 0x5260 SIZE: 0x8
		float mapSunColor[3]; //OFS: 0x5268 SIZE: 0xC
		float mapSunDirection[3]; //OFS: 0x5274 SIZE: 0xC
		int script_ai_limit; //OFS: 0x5280 SIZE: 0x4
		int disable_grenade_suicide; //OFS: 0x5284 SIZE: 0x4
		_BYTE gap5288[4]; //OFS: 0x5288 SIZE: 0x4
		int manualNameChange; //OFS: 0x528C SIZE: 0x4
		objective_t objectives[16]; //OFS: 0x5290 SIZE: 0x200
		int frameTime; //OFS: 0x5490 SIZE: 0x4
		int finished; //OFS: 0x5494 SIZE: 0x4
		int levelWasForceEnded; //OFS: 0x5498 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(level_locals_s, 0x549C);
	ASSERT_STRUCT_OFFSET(level_locals_s, clients, 0x0);
	ASSERT_STRUCT_OFFSET(level_locals_s, gentities, 0x4);
	ASSERT_STRUCT_OFFSET(level_locals_s, unk1, 0x8);
	ASSERT_STRUCT_OFFSET(level_locals_s, num_entities, 0xC);
	ASSERT_STRUCT_OFFSET(level_locals_s, firstFreeEnt, 0x10);
	ASSERT_STRUCT_OFFSET(level_locals_s, lastFreeEnt, 0x14);
	ASSERT_STRUCT_OFFSET(level_locals_s, sentients, 0x18);
	ASSERT_STRUCT_OFFSET(level_locals_s, actors, 0x1C);
	ASSERT_STRUCT_OFFSET(level_locals_s, vehicles, 0x20);
	ASSERT_STRUCT_OFFSET(level_locals_s, turrets, 0x24);
	ASSERT_STRUCT_OFFSET(level_locals_s, animCmds, 0x28);
	ASSERT_STRUCT_OFFSET(level_locals_s, gap_2C, 0x2C);
	ASSERT_STRUCT_OFFSET(level_locals_s, logFile, 0x102C);
	ASSERT_STRUCT_OFFSET(level_locals_s, initializing, 0x1030);
	ASSERT_STRUCT_OFFSET(level_locals_s, clientIsSpawning, 0x1034);
	ASSERT_STRUCT_OFFSET(level_locals_s, maxclients, 0x1038);
	ASSERT_STRUCT_OFFSET(level_locals_s, framenum, 0x103C);
	ASSERT_STRUCT_OFFSET(level_locals_s, time, 0x1040);
	ASSERT_STRUCT_OFFSET(level_locals_s, previousTime, 0x1044);
	ASSERT_STRUCT_OFFSET(level_locals_s, startTime, 0x1048);
	ASSERT_STRUCT_OFFSET(level_locals_s, newSession, 0x104C);
	ASSERT_STRUCT_OFFSET(level_locals_s, actorCorpseCount, 0x1050);
	ASSERT_STRUCT_OFFSET(level_locals_s, spawnVar, 0x1054);
	ASSERT_STRUCT_OFFSET(level_locals_s, reloadDelayTime, 0x1A60);
	ASSERT_STRUCT_OFFSET(level_locals_s, absoluteReloadDelayTime, 0x1A64);
	ASSERT_STRUCT_OFFSET(level_locals_s, droppedWeaponCue, 0x1A68);
	ASSERT_STRUCT_OFFSET(level_locals_s, changelevel, 0x1AE8);
	ASSERT_STRUCT_OFFSET(level_locals_s, bMissionSuccess, 0x1AEC);
	ASSERT_STRUCT_OFFSET(level_locals_s, bMissionFailed, 0x1AF0);
	ASSERT_STRUCT_OFFSET(level_locals_s, exitTime, 0x1AF4);
	ASSERT_STRUCT_OFFSET(level_locals_s, savepersist, 0x1AF8);
	ASSERT_STRUCT_OFFSET(level_locals_s, cinematic, 0x1AFC);
	ASSERT_STRUCT_OFFSET(level_locals_s, fFogOpaqueDist, 0x1B3C);
	ASSERT_STRUCT_OFFSET(level_locals_s, fFogOpaqueDistSqrd, 0x1B40);
	ASSERT_STRUCT_OFFSET(level_locals_s, grenadeHintCount, 0x1B44);
	ASSERT_STRUCT_OFFSET(level_locals_s, remapCount, 0x1B48);
	ASSERT_STRUCT_OFFSET(level_locals_s, iSearchFrame, 0x1B4C);
	ASSERT_STRUCT_OFFSET(level_locals_s, loading, 0x1B50);
	ASSERT_STRUCT_OFFSET(level_locals_s, actorPredictDepth, 0x1B54);
	ASSERT_STRUCT_OFFSET(level_locals_s, bDrawCompassFriendlies, 0x1B58);
	ASSERT_STRUCT_OFFSET(level_locals_s, bPlayerIgnoreRadiusDamage, 0x1B5C);
	ASSERT_STRUCT_OFFSET(level_locals_s, bPlayerIgnoreRadiusDamageLatched, 0x1B60);
	ASSERT_STRUCT_OFFSET(level_locals_s, triggerIndex, 0x1B64);
	ASSERT_STRUCT_OFFSET(level_locals_s, padd, 0x1B68);
	ASSERT_STRUCT_OFFSET(level_locals_s, currentEntityThink, 0x1B6C);
	ASSERT_STRUCT_OFFSET(level_locals_s, currentIndex, 0x1B70);
	ASSERT_STRUCT_OFFSET(level_locals_s, checkAnimChange, 0x1B74);
	ASSERT_STRUCT_OFFSET(level_locals_s, registerWeapons, 0x1B78);
	ASSERT_STRUCT_OFFSET(level_locals_s, bRegisterItems, 0x1B7C);
	ASSERT_STRUCT_OFFSET(level_locals_s, framePos, 0x1B80);
	ASSERT_STRUCT_OFFSET(level_locals_s, cachedTagMat, 0x1B84);
	ASSERT_STRUCT_OFFSET(level_locals_s, cachedEntTargetTagMat, 0x1BC0);
	ASSERT_STRUCT_OFFSET(level_locals_s, soundAliasFirst, 0x1BFC);
	ASSERT_STRUCT_OFFSET(level_locals_s, soundAliasLast, 0x1BFE);
	ASSERT_STRUCT_OFFSET(level_locals_s, pendingTriggerList, 0x1C00);
	ASSERT_STRUCT_OFFSET(level_locals_s, currentTriggerList, 0x2800);
	ASSERT_STRUCT_OFFSET(level_locals_s, pendingTriggerListSize, 0x3400);
	ASSERT_STRUCT_OFFSET(level_locals_s, currentTriggerListSize, 0x3404);
	ASSERT_STRUCT_OFFSET(level_locals_s, entTriggerIndex, 0x3408);
	ASSERT_STRUCT_OFFSET(level_locals_s, specialIndex, 0x4408);
	ASSERT_STRUCT_OFFSET(level_locals_s, gap4808, 0x4808);
	ASSERT_STRUCT_OFFSET(level_locals_s, scriptPrintChannel, 0x524C);
	ASSERT_STRUCT_OFFSET(level_locals_s, compassMapUpperLeft, 0x5250);
	ASSERT_STRUCT_OFFSET(level_locals_s, compassMapWorldSize, 0x5258);
	ASSERT_STRUCT_OFFSET(level_locals_s, compassNorth, 0x5260);
	ASSERT_STRUCT_OFFSET(level_locals_s, mapSunColor, 0x5268);
	ASSERT_STRUCT_OFFSET(level_locals_s, mapSunDirection, 0x5274);
	ASSERT_STRUCT_OFFSET(level_locals_s, script_ai_limit, 0x5280);
	ASSERT_STRUCT_OFFSET(level_locals_s, disable_grenade_suicide, 0x5284);
	ASSERT_STRUCT_OFFSET(level_locals_s, gap5288, 0x5288);
	ASSERT_STRUCT_OFFSET(level_locals_s, manualNameChange, 0x528C);
	ASSERT_STRUCT_OFFSET(level_locals_s, objectives, 0x5290);
	ASSERT_STRUCT_OFFSET(level_locals_s, frameTime, 0x5490);
	ASSERT_STRUCT_OFFSET(level_locals_s, finished, 0x5494);
	ASSERT_STRUCT_OFFSET(level_locals_s, levelWasForceEnded, 0x5498);

	// aaaaaaaaaaaaaaaaaaaaaaaaaaaa
	struct FxBoltAndSortOrder_s1
	{
		__int32 _bf_0; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxBoltAndSortOrder_s1, 0x4);
	ASSERT_STRUCT_OFFSET(FxBoltAndSortOrder_s1, _bf_0, 0x0);

	// aaaaaaaaaaaaaaaaaaaaaaaaaaaa
	struct FxBoltAndSortOrder_s2
	{
		__int32 _bf_0; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxBoltAndSortOrder_s2, 0x4);
	ASSERT_STRUCT_OFFSET(FxBoltAndSortOrder_s2, _bf_0, 0x0);

	union FxBoltAndSortOrder
	{
		FxBoltAndSortOrder_s1 s0; //OFS: 0x0 SIZE: 0x4
		FxBoltAndSortOrder_s2 s1; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxBoltAndSortOrder, 0x4);

	struct FxSpatialFrame
	{
		float quat[4]; //OFS: 0x0 SIZE: 0x10
		float origin[3]; //OFS: 0x10 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(FxSpatialFrame, 0x1C);
	ASSERT_STRUCT_OFFSET(FxSpatialFrame, quat, 0x0);
	ASSERT_STRUCT_OFFSET(FxSpatialFrame, origin, 0x10);

	struct orientation_t
	{
		float origin[3]; //OFS: 0x0 SIZE: 0xC
		float axis[3][3]; //OFS: 0xC SIZE: 0x24
	};
	ASSERT_STRUCT_SIZE(orientation_t, 0x30);
	ASSERT_STRUCT_OFFSET(orientation_t, origin, 0x0);
	ASSERT_STRUCT_OFFSET(orientation_t, axis, 0xC);

	struct FxEffect
	{
		FxEffectDef * def; //OFS: 0x0 SIZE: 0x4
		int status; //OFS: 0x4 SIZE: 0x4
		unsigned __int16 firstElemHandle[3]; //OFS: 0x8 SIZE: 0x6
		unsigned __int16 firstSortedElemHandle; //OFS: 0xE SIZE: 0x2
		unsigned __int16 firstTrailHandle; //OFS: 0x10 SIZE: 0x2
		unsigned __int16 randomSeed; //OFS: 0x12 SIZE: 0x2
		unsigned __int16 owner; //OFS: 0x14 SIZE: 0x2
		unsigned __int16 packedLighting; //OFS: 0x16 SIZE: 0x2
		FxBoltAndSortOrder boltAndSortOrder; //OFS: 0x18 SIZE: 0x4
		int frameCount; //OFS: 0x1C SIZE: 0x4
		int msecBegin; //OFS: 0x20 SIZE: 0x4
		int msecLastUpdate; //OFS: 0x24 SIZE: 0x4
		FxSpatialFrame frameAtSpawn; //OFS: 0x28 SIZE: 0x1C
		FxSpatialFrame frameNow; //OFS: 0x44 SIZE: 0x1C
		FxSpatialFrame framePrev; //OFS: 0x60 SIZE: 0x1C
		float distanceTraveled; //OFS: 0x7C SIZE: 0x4
		orientation_t boneOffset; //OFS: 0x80 SIZE: 0x30
		unsigned int uniqueHandle; //OFS: 0xB0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxEffect, 0xB4);
	ASSERT_STRUCT_OFFSET(FxEffect, def, 0x0);
	ASSERT_STRUCT_OFFSET(FxEffect, status, 0x4);
	ASSERT_STRUCT_OFFSET(FxEffect, firstElemHandle, 0x8);
	ASSERT_STRUCT_OFFSET(FxEffect, firstSortedElemHandle, 0xE);
	ASSERT_STRUCT_OFFSET(FxEffect, firstTrailHandle, 0x10);
	ASSERT_STRUCT_OFFSET(FxEffect, randomSeed, 0x12);
	ASSERT_STRUCT_OFFSET(FxEffect, owner, 0x14);
	ASSERT_STRUCT_OFFSET(FxEffect, packedLighting, 0x16);
	ASSERT_STRUCT_OFFSET(FxEffect, boltAndSortOrder, 0x18);
	ASSERT_STRUCT_OFFSET(FxEffect, frameCount, 0x1C);
	ASSERT_STRUCT_OFFSET(FxEffect, msecBegin, 0x20);
	ASSERT_STRUCT_OFFSET(FxEffect, msecLastUpdate, 0x24);
	ASSERT_STRUCT_OFFSET(FxEffect, frameAtSpawn, 0x28);
	ASSERT_STRUCT_OFFSET(FxEffect, frameNow, 0x44);
	ASSERT_STRUCT_OFFSET(FxEffect, framePrev, 0x60);
	ASSERT_STRUCT_OFFSET(FxEffect, distanceTraveled, 0x7C);
	ASSERT_STRUCT_OFFSET(FxEffect, boneOffset, 0x80);
	ASSERT_STRUCT_OFFSET(FxEffect, uniqueHandle, 0xB0);

	struct __declspec(align(1)) FxElem_u_s_fade
	{
		char fadeAlpha; //OFS: 0x0 SIZE: 0x1
		char fadeAlphaPerSec; //OFS: 0x1 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(FxElem_u_s_fade, 0x2);
	ASSERT_STRUCT_OFFSET(FxElem_u_s_fade, fadeAlpha, 0x0);
	ASSERT_STRUCT_OFFSET(FxElem_u_s_fade, fadeAlphaPerSec, 0x1);

	struct __declspec(align(2)) FxElem_u_s
	{
		unsigned __int16 lightingHandle; //OFS: 0x0 SIZE: 0x2
		FxElem_u_s_fade fade; //OFS: 0x2 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(FxElem_u_s, 0x4);
	ASSERT_STRUCT_OFFSET(FxElem_u_s, lightingHandle, 0x0);
	ASSERT_STRUCT_OFFSET(FxElem_u_s, fade, 0x2);

	union FxElem_u
	{
		float trailTexCoord; //OFS: 0x0 SIZE: 0x4
		FxElem_u_s s; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxElem_u, 0x4);

	struct FxElem
	{
		unsigned __int8 defIndex; //OFS: 0x0 SIZE: 0x1
		unsigned __int8 sequence; //OFS: 0x1 SIZE: 0x1
		unsigned __int8 atRestFraction; //OFS: 0x2 SIZE: 0x1
		unsigned __int8 emitResidual; //OFS: 0x3 SIZE: 0x1
		unsigned __int16 nextElemHandleInEffect; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 prevElemHandleInEffect; //OFS: 0x6 SIZE: 0x2
		int msecBegin; //OFS: 0x8 SIZE: 0x4
		float baseVel[3]; //OFS: 0xC SIZE: 0xC
		float origin[3]; //OFS: 0x18 SIZE: 0xC
		FxElem_u u; //OFS: 0x24 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxElem, 0x28);
	ASSERT_STRUCT_OFFSET(FxElem, defIndex, 0x0);
	ASSERT_STRUCT_OFFSET(FxElem, sequence, 0x1);
	ASSERT_STRUCT_OFFSET(FxElem, atRestFraction, 0x2);
	ASSERT_STRUCT_OFFSET(FxElem, emitResidual, 0x3);
	ASSERT_STRUCT_OFFSET(FxElem, nextElemHandleInEffect, 0x4);
	ASSERT_STRUCT_OFFSET(FxElem, prevElemHandleInEffect, 0x6);
	ASSERT_STRUCT_OFFSET(FxElem, msecBegin, 0x8);
	ASSERT_STRUCT_OFFSET(FxElem, baseVel, 0xC);
	ASSERT_STRUCT_OFFSET(FxElem, origin, 0x18);
	ASSERT_STRUCT_OFFSET(FxElem, u, 0x24);

	union FxPool_FxElem
	{
		int nextFree; //OFS: 0x0 SIZE: 0x4
		FxElem item; //OFS: 0x1 SIZE: 0x28
	};
	ASSERT_STRUCT_SIZE(FxPool_FxElem, 0x28);

	struct __declspec(align(2)) FxTrail
	{
		unsigned __int16 nextTrailHandle; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 firstElemHandle; //OFS: 0x2 SIZE: 0x2
		unsigned __int16 lastElemHandle; //OFS: 0x4 SIZE: 0x2
		char defIndex; //OFS: 0x6 SIZE: 0x1
		char sequence; //OFS: 0x7 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(FxTrail, 0x8);
	ASSERT_STRUCT_OFFSET(FxTrail, nextTrailHandle, 0x0);
	ASSERT_STRUCT_OFFSET(FxTrail, firstElemHandle, 0x2);
	ASSERT_STRUCT_OFFSET(FxTrail, lastElemHandle, 0x4);
	ASSERT_STRUCT_OFFSET(FxTrail, defIndex, 0x6);
	ASSERT_STRUCT_OFFSET(FxTrail, sequence, 0x7);

	union FxPool_FxTrail
	{
		int nextFree; //OFS: 0x0 SIZE: 0x4
		FxTrail item; //OFS: 0x1 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(FxPool_FxTrail, 0x8);

	struct FxTrailElem
	{
		float origin[3]; //OFS: 0x0 SIZE: 0xC
		float spawnDist; //OFS: 0xC SIZE: 0x4
		int msecBegin; //OFS: 0x10 SIZE: 0x4
		unsigned __int16 nextTrailElemHandle; //OFS: 0x14 SIZE: 0x2
		__int16 baseVelZ; //OFS: 0x16 SIZE: 0x2
		char basis[2][3]; //OFS: 0x18 SIZE: 0x6
		unsigned __int8 sequence; //OFS: 0x1E SIZE: 0x1
		unsigned __int8 unused; //OFS: 0x1F SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(FxTrailElem, 0x20);
	ASSERT_STRUCT_OFFSET(FxTrailElem, origin, 0x0);
	ASSERT_STRUCT_OFFSET(FxTrailElem, spawnDist, 0xC);
	ASSERT_STRUCT_OFFSET(FxTrailElem, msecBegin, 0x10);
	ASSERT_STRUCT_OFFSET(FxTrailElem, nextTrailElemHandle, 0x14);
	ASSERT_STRUCT_OFFSET(FxTrailElem, baseVelZ, 0x16);
	ASSERT_STRUCT_OFFSET(FxTrailElem, basis, 0x18);
	ASSERT_STRUCT_OFFSET(FxTrailElem, sequence, 0x1E);
	ASSERT_STRUCT_OFFSET(FxTrailElem, unused, 0x1F);

	union FxPool_FxTrailElem
	{
		int nextFree; //OFS: 0x0 SIZE: 0x4
		FxTrailElem item; //OFS: 0x1 SIZE: 0x20
	};
	ASSERT_STRUCT_SIZE(FxPool_FxTrailElem, 0x20);

	struct FxVisBlocker
	{
		float origin[3]; //OFS: 0x0 SIZE: 0xC
		unsigned __int16 radius; //OFS: 0xC SIZE: 0x2
		unsigned __int16 visibility; //OFS: 0xE SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(FxVisBlocker, 0x10);
	ASSERT_STRUCT_OFFSET(FxVisBlocker, origin, 0x0);
	ASSERT_STRUCT_OFFSET(FxVisBlocker, radius, 0xC);
	ASSERT_STRUCT_OFFSET(FxVisBlocker, visibility, 0xE);

	struct FxVisState
	{
		FxVisBlocker blocker[256]; //OFS: 0x0 SIZE: 0x1000
		int blockerCount; //OFS: 0x1000 SIZE: 0x4
		unsigned int pad[3]; //OFS: 0x1004 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(FxVisState, 0x1010);
	ASSERT_STRUCT_OFFSET(FxVisState, blocker, 0x0);
	ASSERT_STRUCT_OFFSET(FxVisState, blockerCount, 0x1000);
	ASSERT_STRUCT_OFFSET(FxVisState, pad, 0x1004);

	struct FxSystemBuffers
	{
		FxEffect effects[1024]; //OFS: 0x0 SIZE: 0x2D000
		FxPool_FxElem elems[2048]; //OFS: 0x2D000 SIZE: 0x14000
		FxPool_FxTrail trails[128]; //OFS: 0x41000 SIZE: 0x400
		FxPool_FxTrailElem trailElems[2048]; //OFS: 0x41400 SIZE: 0x10000
		FxVisState visState[2]; //OFS: 0x51400 SIZE: 0x2020
		unsigned __int16 deferredElems[2048]; //OFS: 0x53420 SIZE: 0x1000
		unsigned __int8 padBuffer[96]; //OFS: 0x54420 SIZE: 0x60
	};
	ASSERT_STRUCT_SIZE(FxSystemBuffers, 0x54480);
	ASSERT_STRUCT_OFFSET(FxSystemBuffers, effects, 0x0);
	ASSERT_STRUCT_OFFSET(FxSystemBuffers, elems, 0x2D000);
	ASSERT_STRUCT_OFFSET(FxSystemBuffers, trails, 0x41000);
	ASSERT_STRUCT_OFFSET(FxSystemBuffers, trailElems, 0x41400);
	ASSERT_STRUCT_OFFSET(FxSystemBuffers, visState, 0x51400);
	ASSERT_STRUCT_OFFSET(FxSystemBuffers, deferredElems, 0x53420);
	ASSERT_STRUCT_OFFSET(FxSystemBuffers, padBuffer, 0x54420);

	struct FxCamera
	{
		float origin[3]; //OFS: 0x0 SIZE: 0xC
		int isValid; //OFS: 0xC SIZE: 0x4
		float frustum[6][4]; //OFS: 0x10 SIZE: 0x60
		float axis[3][3]; //OFS: 0x70 SIZE: 0x24
		unsigned int frustumPlaneCount; //OFS: 0x94 SIZE: 0x4
		float viewOffset[3]; //OFS: 0x98 SIZE: 0xC
		unsigned int pad[3]; //OFS: 0xA4 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(FxCamera, 0xB0);
	ASSERT_STRUCT_OFFSET(FxCamera, origin, 0x0);
	ASSERT_STRUCT_OFFSET(FxCamera, isValid, 0xC);
	ASSERT_STRUCT_OFFSET(FxCamera, frustum, 0x10);
	ASSERT_STRUCT_OFFSET(FxCamera, axis, 0x70);
	ASSERT_STRUCT_OFFSET(FxCamera, frustumPlaneCount, 0x94);
	ASSERT_STRUCT_OFFSET(FxCamera, viewOffset, 0x98);
	ASSERT_STRUCT_OFFSET(FxCamera, pad, 0xA4);

	struct __declspec(align(2)) r_double_index_t
	{
		unsigned __int16 value[2]; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(r_double_index_t, 0x4);
	ASSERT_STRUCT_OFFSET(r_double_index_t, value, 0x0);

	struct FxSpriteInfo
	{
		r_double_index_t * indices; //OFS: 0x0 SIZE: 0x4
		unsigned int indexCount; //OFS: 0x4 SIZE: 0x4
		Material * material; //OFS: 0x8 SIZE: 0x4
		const char * name; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxSpriteInfo, 0x10);
	ASSERT_STRUCT_OFFSET(FxSpriteInfo, indices, 0x0);
	ASSERT_STRUCT_OFFSET(FxSpriteInfo, indexCount, 0x4);
	ASSERT_STRUCT_OFFSET(FxSpriteInfo, material, 0x8);
	ASSERT_STRUCT_OFFSET(FxSpriteInfo, name, 0xC);

	struct FxEffectPriorityList
	{
		unsigned __int16 list[1024]; //OFS: 0x0 SIZE: 0x800
		int endOfSorted; //OFS: 0x800 SIZE: 0x4
		int firstUnsorted; //OFS: 0x804 SIZE: 0x4
		unsigned __int8 haveUnsorted; //OFS: 0x808 SIZE: 0x1
		unsigned __int8 pad[7]; //OFS: 0x809 SIZE: 0x7
	};
	ASSERT_STRUCT_SIZE(FxEffectPriorityList, 0x810);
	ASSERT_STRUCT_OFFSET(FxEffectPriorityList, list, 0x0);
	ASSERT_STRUCT_OFFSET(FxEffectPriorityList, endOfSorted, 0x800);
	ASSERT_STRUCT_OFFSET(FxEffectPriorityList, firstUnsorted, 0x804);
	ASSERT_STRUCT_OFFSET(FxEffectPriorityList, haveUnsorted, 0x808);
	ASSERT_STRUCT_OFFSET(FxEffectPriorityList, pad, 0x809);

	struct FxSystem
	{
		FxCamera camera; //OFS: 0x0 SIZE: 0xB0
		FxCamera cameraPrev; //OFS: 0xB0 SIZE: 0xB0
		FxSpriteInfo sprite; //OFS: 0x160 SIZE: 0x10
		FxEffect * effects; //OFS: 0x170 SIZE: 0x4
		FxPool_FxElem * elems; //OFS: 0x174 SIZE: 0x4
		FxPool_FxTrail * trails; //OFS: 0x178 SIZE: 0x4
		FxPool_FxTrailElem * trailElems; //OFS: 0x17C SIZE: 0x4
		unsigned __int16 * deferredElems; //OFS: 0x180 SIZE: 0x4
		int firstFreeElem; //OFS: 0x184 SIZE: 0x4
		int firstFreeTrailElem; //OFS: 0x188 SIZE: 0x4
		int firstFreeTrail; //OFS: 0x18C SIZE: 0x4
		int deferredElemCount; //OFS: 0x190 SIZE: 0x4
		int activeElemCount; //OFS: 0x194 SIZE: 0x4
		int activeTrailElemCount; //OFS: 0x198 SIZE: 0x4
		int activeTrailCount; //OFS: 0x19C SIZE: 0x4
		int gfxCloudCount; //OFS: 0x1A0 SIZE: 0x4
		FxVisState * visState; //OFS: 0x1A4 SIZE: 0x4
		FxVisState * visStateBufferRead; //OFS: 0x1A8 SIZE: 0x4
		FxVisState * visStateBufferWrite; //OFS: 0x1AC SIZE: 0x4
		int firstActiveEffect; //OFS: 0x1B0 SIZE: 0x4
		int firstNewEffect; //OFS: 0x1B4 SIZE: 0x4
		int firstFreeEffect; //OFS: 0x1B8 SIZE: 0x4
		unsigned __int16 allEffectHandles[1024]; //OFS: 0x1BC SIZE: 0x800
		int activeSpotLightEffectCount; //OFS: 0x9BC SIZE: 0x4
		int activeSpotLightElemCount; //OFS: 0x9C0 SIZE: 0x4
		unsigned __int16 activeSpotLightEffectHandle; //OFS: 0x9C4 SIZE: 0x2
		unsigned __int16 activeSpotLightElemHandle; //OFS: 0x9C6 SIZE: 0x2
		__int16 activeSpotLightBoltDobj; //OFS: 0x9C8 SIZE: 0x2
		int iteratorCount; //OFS: 0x9CC SIZE: 0x4
		int msecNow; //OFS: 0x9D0 SIZE: 0x4
		int msecDraw; //OFS: 0x9D4 SIZE: 0x4
		int frameCount; //OFS: 0x9D8 SIZE: 0x4
		char isInitialized; //OFS: 0x9DC SIZE: 0x1
		bool needsGarbageCollection; //OFS: 0x9DD SIZE: 0x1
		bool isArchiving; //OFS: 0x9DE SIZE: 0x1
		char localClientNum; //OFS: 0x9DF SIZE: 0x1
		unsigned int restartList[32]; //OFS: 0x9E0 SIZE: 0x80
		FxEffectPriorityList priorityList; //OFS: 0xA60 SIZE: 0x810
	};
	ASSERT_STRUCT_SIZE(FxSystem, 0x1270);
	ASSERT_STRUCT_OFFSET(FxSystem, camera, 0x0);
	ASSERT_STRUCT_OFFSET(FxSystem, cameraPrev, 0xB0);
	ASSERT_STRUCT_OFFSET(FxSystem, sprite, 0x160);
	ASSERT_STRUCT_OFFSET(FxSystem, effects, 0x170);
	ASSERT_STRUCT_OFFSET(FxSystem, elems, 0x174);
	ASSERT_STRUCT_OFFSET(FxSystem, trails, 0x178);
	ASSERT_STRUCT_OFFSET(FxSystem, trailElems, 0x17C);
	ASSERT_STRUCT_OFFSET(FxSystem, deferredElems, 0x180);
	ASSERT_STRUCT_OFFSET(FxSystem, firstFreeElem, 0x184);
	ASSERT_STRUCT_OFFSET(FxSystem, firstFreeTrailElem, 0x188);
	ASSERT_STRUCT_OFFSET(FxSystem, firstFreeTrail, 0x18C);
	ASSERT_STRUCT_OFFSET(FxSystem, deferredElemCount, 0x190);
	ASSERT_STRUCT_OFFSET(FxSystem, activeElemCount, 0x194);
	ASSERT_STRUCT_OFFSET(FxSystem, activeTrailElemCount, 0x198);
	ASSERT_STRUCT_OFFSET(FxSystem, activeTrailCount, 0x19C);
	ASSERT_STRUCT_OFFSET(FxSystem, gfxCloudCount, 0x1A0);
	ASSERT_STRUCT_OFFSET(FxSystem, visState, 0x1A4);
	ASSERT_STRUCT_OFFSET(FxSystem, visStateBufferRead, 0x1A8);
	ASSERT_STRUCT_OFFSET(FxSystem, visStateBufferWrite, 0x1AC);
	ASSERT_STRUCT_OFFSET(FxSystem, firstActiveEffect, 0x1B0);
	ASSERT_STRUCT_OFFSET(FxSystem, firstNewEffect, 0x1B4);
	ASSERT_STRUCT_OFFSET(FxSystem, firstFreeEffect, 0x1B8);
	ASSERT_STRUCT_OFFSET(FxSystem, allEffectHandles, 0x1BC);
	ASSERT_STRUCT_OFFSET(FxSystem, activeSpotLightEffectCount, 0x9BC);
	ASSERT_STRUCT_OFFSET(FxSystem, activeSpotLightElemCount, 0x9C0);
	ASSERT_STRUCT_OFFSET(FxSystem, activeSpotLightEffectHandle, 0x9C4);
	ASSERT_STRUCT_OFFSET(FxSystem, activeSpotLightElemHandle, 0x9C6);
	ASSERT_STRUCT_OFFSET(FxSystem, activeSpotLightBoltDobj, 0x9C8);
	ASSERT_STRUCT_OFFSET(FxSystem, iteratorCount, 0x9CC);
	ASSERT_STRUCT_OFFSET(FxSystem, msecNow, 0x9D0);
	ASSERT_STRUCT_OFFSET(FxSystem, msecDraw, 0x9D4);
	ASSERT_STRUCT_OFFSET(FxSystem, frameCount, 0x9D8);
	ASSERT_STRUCT_OFFSET(FxSystem, isInitialized, 0x9DC);
	ASSERT_STRUCT_OFFSET(FxSystem, needsGarbageCollection, 0x9DD);
	ASSERT_STRUCT_OFFSET(FxSystem, isArchiving, 0x9DE);
	ASSERT_STRUCT_OFFSET(FxSystem, localClientNum, 0x9DF);
	ASSERT_STRUCT_OFFSET(FxSystem, restartList, 0x9E0);
	ASSERT_STRUCT_OFFSET(FxSystem, priorityList, 0xA60);

	struct server_s
	{
		serverState_t state; //OFS: 0x0 SIZE: 0x4
		int timeResidual; //OFS: 0x4 SIZE: 0x4
		bool inFrame; //OFS: 0x8 SIZE: 0x1
		int restarting; //OFS: 0xC SIZE: 0x4
		int num_restarts; //OFS: 0x10 SIZE: 0x4
		int start_frameTime; //OFS: 0x14 SIZE: 0x4
		int checksumFeed; //OFS: 0x18 SIZE: 0x4
		cmodel_t * models[512]; //OFS: 0x1C SIZE: 0x800
		__int16 emptyConfigString; //OFS: 0x81C SIZE: 0x2
		__int16 configstrings[3056]; //OFS: 0x81E SIZE: 0x17E0
		svEntity_t svEntities[1024]; //OFS: 0x2000 SIZE: 0x6B000
		entityState_s savedEntities[350]; //OFS: 0x6D000 SIZE: 0x17ED0
		gentity_s * gentities; //OFS: 0x84ED0 SIZE: 0x4
		int entitiySize; //OFS: 0x84ED4 SIZE: 0x4
		int max_clients; //OFS: 0x84ED8 SIZE: 0x4
		int num_saved_ents; //OFS: 0x84EDC SIZE: 0x4
		gclient_s * gameClients; //OFS: 0x84EE0 SIZE: 0x4
		int gameClientSize; //OFS: 0x84EE4 SIZE: 0x4
		actor_s * actors; //OFS: 0x84EE8 SIZE: 0x4
		int actorSize; //OFS: 0x84EEC SIZE: 0x4
		animCmdState_s * animCmds; //OFS: 0x84EF0 SIZE: 0x4
		int animCmdSize; //OFS: 0x84EF4 SIZE: 0x4
		int checksum; //OFS: 0x84EF8 SIZE: 0x4
		int skelTimeStamp; //OFS: 0x84EFC SIZE: 0x4
		int skelMemPos; //OFS: 0x84F00 SIZE: 0x4
		_BYTE gap_84F04[84]; //OFS: 0x84F04 SIZE: 0x54
		int bpsTotalBytes; //OFS: 0x84F58 SIZE: 0x4
		_BYTE gap_84F5C[84]; //OFS: 0x84F5C SIZE: 0x54
		int ubpsTotalBytes; //OFS: 0x84FB0 SIZE: 0x4
		_BYTE gap_84FB4[24]; //OFS: 0x84FB4 SIZE: 0x18
		char gametype[64]; //OFS: 0x84FCC SIZE: 0x40
		bool killServer; //OFS: 0x8500C SIZE: 0x1
		_BYTE gap_8500D[3]; //OFS: 0x8500D SIZE: 0x3
		char * killReason; //OFS: 0x85010 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(server_s, 0x85014);
	ASSERT_STRUCT_OFFSET(server_s, state, 0x0);
	ASSERT_STRUCT_OFFSET(server_s, timeResidual, 0x4);
	ASSERT_STRUCT_OFFSET(server_s, inFrame, 0x8);
	ASSERT_STRUCT_OFFSET(server_s, restarting, 0xC);
	ASSERT_STRUCT_OFFSET(server_s, num_restarts, 0x10);
	ASSERT_STRUCT_OFFSET(server_s, start_frameTime, 0x14);
	ASSERT_STRUCT_OFFSET(server_s, checksumFeed, 0x18);
	ASSERT_STRUCT_OFFSET(server_s, models, 0x1C);
	ASSERT_STRUCT_OFFSET(server_s, emptyConfigString, 0x81C);
	ASSERT_STRUCT_OFFSET(server_s, configstrings, 0x81E);
	ASSERT_STRUCT_OFFSET(server_s, svEntities, 0x2000);
	ASSERT_STRUCT_OFFSET(server_s, savedEntities, 0x6D000);
	ASSERT_STRUCT_OFFSET(server_s, gentities, 0x84ED0);
	ASSERT_STRUCT_OFFSET(server_s, entitiySize, 0x84ED4);
	ASSERT_STRUCT_OFFSET(server_s, max_clients, 0x84ED8);
	ASSERT_STRUCT_OFFSET(server_s, num_saved_ents, 0x84EDC);
	ASSERT_STRUCT_OFFSET(server_s, gameClients, 0x84EE0);
	ASSERT_STRUCT_OFFSET(server_s, gameClientSize, 0x84EE4);
	ASSERT_STRUCT_OFFSET(server_s, actors, 0x84EE8);
	ASSERT_STRUCT_OFFSET(server_s, actorSize, 0x84EEC);
	ASSERT_STRUCT_OFFSET(server_s, animCmds, 0x84EF0);
	ASSERT_STRUCT_OFFSET(server_s, animCmdSize, 0x84EF4);
	ASSERT_STRUCT_OFFSET(server_s, checksum, 0x84EF8);
	ASSERT_STRUCT_OFFSET(server_s, skelTimeStamp, 0x84EFC);
	ASSERT_STRUCT_OFFSET(server_s, skelMemPos, 0x84F00);
	ASSERT_STRUCT_OFFSET(server_s, gap_84F04, 0x84F04);
	ASSERT_STRUCT_OFFSET(server_s, bpsTotalBytes, 0x84F58);
	ASSERT_STRUCT_OFFSET(server_s, gap_84F5C, 0x84F5C);
	ASSERT_STRUCT_OFFSET(server_s, ubpsTotalBytes, 0x84FB0);
	ASSERT_STRUCT_OFFSET(server_s, gap_84FB4, 0x84FB4);
	ASSERT_STRUCT_OFFSET(server_s, gametype, 0x84FCC);
	ASSERT_STRUCT_OFFSET(server_s, killServer, 0x8500C);
	ASSERT_STRUCT_OFFSET(server_s, gap_8500D, 0x8500D);
	ASSERT_STRUCT_OFFSET(server_s, killReason, 0x85010);

	struct challenge_s
	{
		netadr_s adr; //OFS: 0x0 SIZE: 0x18
		int challenge; //OFS: 0x18 SIZE: 0x4
		int time; //OFS: 0x1C SIZE: 0x4
		int pingTime; //OFS: 0x20 SIZE: 0x4
		int firstTime; //OFS: 0x24 SIZE: 0x4
		int firstPing; //OFS: 0x28 SIZE: 0x4
		int connected; //OFS: 0x2C SIZE: 0x4
		int guid; //OFS: 0x30 SIZE: 0x4
		char PBguid[33]; //OFS: 0x34 SIZE: 0x21
		char clientPBguid[33]; //OFS: 0x55 SIZE: 0x21
	};
	ASSERT_STRUCT_SIZE(challenge_s, 0x78);
	ASSERT_STRUCT_OFFSET(challenge_s, adr, 0x0);
	ASSERT_STRUCT_OFFSET(challenge_s, challenge, 0x18);
	ASSERT_STRUCT_OFFSET(challenge_s, time, 0x1C);
	ASSERT_STRUCT_OFFSET(challenge_s, pingTime, 0x20);
	ASSERT_STRUCT_OFFSET(challenge_s, firstTime, 0x24);
	ASSERT_STRUCT_OFFSET(challenge_s, firstPing, 0x28);
	ASSERT_STRUCT_OFFSET(challenge_s, connected, 0x2C);
	ASSERT_STRUCT_OFFSET(challenge_s, guid, 0x30);
	ASSERT_STRUCT_OFFSET(challenge_s, PBguid, 0x34);
	ASSERT_STRUCT_OFFSET(challenge_s, clientPBguid, 0x55);

	struct tempBanSlot_t
	{
		int guid; //OFS: 0x0 SIZE: 0x4
		int banTime; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(tempBanSlot_t, 0x8);
	ASSERT_STRUCT_OFFSET(tempBanSlot_t, guid, 0x0);
	ASSERT_STRUCT_OFFSET(tempBanSlot_t, banTime, 0x4);

	struct __declspec(align(16)) serverStatic_s
	{
		char cachedSnapshot[22528]; //OFS: 0x0 SIZE: 0x5800
		char cachedSnapshot_[1294336]; //OFS: 0x5800 SIZE: 0x13C000
		char cachedSnapshot__[15360]; //OFS: 0x141800 SIZE: 0x3C00
		char cachedSnapshot___[180224]; //OFS: 0x145400 SIZE: 0x2C000
		int initialized; //OFS: 0x171400 SIZE: 0x4
		int time; //OFS: 0x171404 SIZE: 0x4
		int snapFlagServerBit; //OFS: 0x171408 SIZE: 0x4
		int field_17140C; //OFS: 0x17140C SIZE: 0x4
		client_s clients[4]; //OFS: 0x171410 SIZE: 0x1634C0
		int numSnapshotEntities; //OFS: 0x2D48D0 SIZE: 0x4
		int numSnapshotClients; //OFS: 0x2D48D4 SIZE: 0x4
		int numSnapshotActors; //OFS: 0x2D48D8 SIZE: 0x4
		int nextSnapshotEntities[4]; //OFS: 0x2D48DC SIZE: 0x10
		int nextSnapshotClients[4]; //OFS: 0x2D48EC SIZE: 0x10
		int nextSnapshotActors[4]; //OFS: 0x2D48FC SIZE: 0x10
		entityState_s snapshotEntities[4][5376]; //OFS: 0x2D490C SIZE: 0x5BE000
		clientState_s snapshotClients[4][64]; //OFS: 0x89290C SIZE: 0x9400
		actorState_s snapshotActors[4][512]; //OFS: 0x89BD0C SIZE: 0x3C000
		int nextCachedSnapshotEntities; //OFS: 0x8D7D0C SIZE: 0x4
		int nextCachedSnapshotClients; //OFS: 0x8D7D10 SIZE: 0x4
		int awdd; //OFS: 0x8D7D14 SIZE: 0x4
		int nextCachedSnapshotFrames; //OFS: 0x8D7D18 SIZE: 0x4
		char cachedSnapshot____[136256]; //OFS: 0x8D7D1C SIZE: 0x21440
		int nextHeartbeatTime; //OFS: 0x8F915C SIZE: 0x4
		int nextStatusResponseTime; //OFS: 0x8F9160 SIZE: 0x4
		challenge_s challenges[1024]; //OFS: 0x8F9164 SIZE: 0x1E000
		int numSnapshotAnimCmds; //OFS: 0x917164 SIZE: 0x4
		int nextSnapshotAnimCmds[4]; //OFS: 0x917168 SIZE: 0x10
		animCmdState_s snapshotAnimCmds[4][16384]; //OFS: 0x917178 SIZE: 0x2C0000
		int acaw; //OFS: 0xBD7178 SIZE: 0x4
		netProfileInfo_t OOBProf; //OFS: 0xBD717C SIZE: 0x5E0
		tempBanSlot_t tempBans[16]; //OFS: 0xBD775C SIZE: 0x80
		int field_BD77DC; //OFS: 0xBD77DC SIZE: 0x4
		int field_BD77E0[2][4]; //OFS: 0xBD77E0 SIZE: 0x20
		float mapCenter[3]; //OFS: 0xBD7800 SIZE: 0xC
		int playerDeaths[4]; //OFS: 0xBD780C SIZE: 0x10
		int playerScore[4]; //OFS: 0xBD781C SIZE: 0x10
		_BYTE gapBD782C[83]; //OFS: 0xBD782C SIZE: 0x53
		char field_BD787F; //OFS: 0xBD787F SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(serverStatic_s, 0xBD7880);
	ASSERT_STRUCT_OFFSET(serverStatic_s, cachedSnapshot, 0x0);
	ASSERT_STRUCT_OFFSET(serverStatic_s, cachedSnapshot_, 0x5800);
	ASSERT_STRUCT_OFFSET(serverStatic_s, cachedSnapshot__, 0x141800);
	ASSERT_STRUCT_OFFSET(serverStatic_s, cachedSnapshot___, 0x145400);
	ASSERT_STRUCT_OFFSET(serverStatic_s, initialized, 0x171400);
	ASSERT_STRUCT_OFFSET(serverStatic_s, time, 0x171404);
	ASSERT_STRUCT_OFFSET(serverStatic_s, snapFlagServerBit, 0x171408);
	ASSERT_STRUCT_OFFSET(serverStatic_s, field_17140C, 0x17140C);
	ASSERT_STRUCT_OFFSET(serverStatic_s, clients, 0x171410);
	ASSERT_STRUCT_OFFSET(serverStatic_s, numSnapshotEntities, 0x2D48D0);
	ASSERT_STRUCT_OFFSET(serverStatic_s, numSnapshotClients, 0x2D48D4);
	ASSERT_STRUCT_OFFSET(serverStatic_s, numSnapshotActors, 0x2D48D8);
	ASSERT_STRUCT_OFFSET(serverStatic_s, nextSnapshotEntities, 0x2D48DC);
	ASSERT_STRUCT_OFFSET(serverStatic_s, nextSnapshotClients, 0x2D48EC);
	ASSERT_STRUCT_OFFSET(serverStatic_s, nextSnapshotActors, 0x2D48FC);
	ASSERT_STRUCT_OFFSET(serverStatic_s, snapshotEntities, 0x2D490C);
	ASSERT_STRUCT_OFFSET(serverStatic_s, snapshotClients, 0x89290C);
	ASSERT_STRUCT_OFFSET(serverStatic_s, snapshotActors, 0x89BD0C);
	ASSERT_STRUCT_OFFSET(serverStatic_s, nextCachedSnapshotEntities, 0x8D7D0C);
	ASSERT_STRUCT_OFFSET(serverStatic_s, nextCachedSnapshotClients, 0x8D7D10);
	ASSERT_STRUCT_OFFSET(serverStatic_s, awdd, 0x8D7D14);
	ASSERT_STRUCT_OFFSET(serverStatic_s, nextCachedSnapshotFrames, 0x8D7D18);
	ASSERT_STRUCT_OFFSET(serverStatic_s, cachedSnapshot____, 0x8D7D1C);
	ASSERT_STRUCT_OFFSET(serverStatic_s, nextHeartbeatTime, 0x8F915C);
	ASSERT_STRUCT_OFFSET(serverStatic_s, nextStatusResponseTime, 0x8F9160);
	ASSERT_STRUCT_OFFSET(serverStatic_s, challenges, 0x8F9164);
	ASSERT_STRUCT_OFFSET(serverStatic_s, numSnapshotAnimCmds, 0x917164);
	ASSERT_STRUCT_OFFSET(serverStatic_s, nextSnapshotAnimCmds, 0x917168);
	ASSERT_STRUCT_OFFSET(serverStatic_s, snapshotAnimCmds, 0x917178);
	ASSERT_STRUCT_OFFSET(serverStatic_s, acaw, 0xBD7178);
	ASSERT_STRUCT_OFFSET(serverStatic_s, OOBProf, 0xBD717C);
	ASSERT_STRUCT_OFFSET(serverStatic_s, tempBans, 0xBD775C);
	ASSERT_STRUCT_OFFSET(serverStatic_s, field_BD77DC, 0xBD77DC);
	ASSERT_STRUCT_OFFSET(serverStatic_s, field_BD77E0, 0xBD77E0);
	ASSERT_STRUCT_OFFSET(serverStatic_s, mapCenter, 0xBD7800);
	ASSERT_STRUCT_OFFSET(serverStatic_s, playerDeaths, 0xBD780C);
	ASSERT_STRUCT_OFFSET(serverStatic_s, playerScore, 0xBD781C);
	ASSERT_STRUCT_OFFSET(serverStatic_s, gapBD782C, 0xBD782C);
	ASSERT_STRUCT_OFFSET(serverStatic_s, field_BD787F, 0xBD787F);

	struct serverStaticHeader_s
	{
		client_s * clients; //OFS: 0x0 SIZE: 0x4
		actor_s * actors; //OFS: 0x4 SIZE: 0x4
		animCmdState_s * animCmds; //OFS: 0x8 SIZE: 0x4
		int time; //OFS: 0xC SIZE: 0x4
		int snapFlagServerBit; //OFS: 0x10 SIZE: 0x4
		int numSnapshotEntities; //OFS: 0x14 SIZE: 0x4
		int numSnapshotClients; //OFS: 0x18 SIZE: 0x4
		int numSnapshotActors; //OFS: 0x1C SIZE: 0x4
		int nextSnapshotEntities[4]; //OFS: 0x20 SIZE: 0x10
		entityState_s * snapshotEntities[4]; //OFS: 0x30 SIZE: 0x10
		clientState_s * snapshotClients[4]; //OFS: 0x40 SIZE: 0x10
		actorState_s * snapshotActors[4]; //OFS: 0x50 SIZE: 0x10
		svEntity_t * svEntities; //OFS: 0x60 SIZE: 0x4
		_BYTE gap_64[32]; //OFS: 0x64 SIZE: 0x20
		int numSnapshotAnimCmds; //OFS: 0x84 SIZE: 0x4
		animCmdState_s * snapshotAnimCmds[4]; //OFS: 0x88 SIZE: 0x10
		_BYTE gap_98[4]; //OFS: 0x98 SIZE: 0x4
		int awdawdd; //OFS: 0x9C SIZE: 0x4
		int nextCachedSnapshotFrames; //OFS: 0xA0 SIZE: 0x4
		_BYTE gap_A4[4]; //OFS: 0xA4 SIZE: 0x4
		int nextCachedSnapshotEntities; //OFS: 0xA8 SIZE: 0x4
		int nextCachedSnapshotClients; //OFS: 0xAC SIZE: 0x4
		int awdawd; //OFS: 0xB0 SIZE: 0x4
		int max_clients; //OFS: 0xB4 SIZE: 0x4
		char gap_B8[44]; //OFS: 0xB8 SIZE: 0x2C
		int snapshotPeek; //OFS: 0xE4 SIZE: 0x4
		vehicle_info_t * bg_vehicleInfos; //OFS: 0xE8 SIZE: 0x4
		entityState_s * savedEntities; //OFS: 0xEC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(serverStaticHeader_s, 0xF0);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, clients, 0x0);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, actors, 0x4);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, animCmds, 0x8);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, time, 0xC);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, snapFlagServerBit, 0x10);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, numSnapshotEntities, 0x14);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, numSnapshotClients, 0x18);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, numSnapshotActors, 0x1C);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, nextSnapshotEntities, 0x20);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, snapshotEntities, 0x30);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, snapshotClients, 0x40);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, snapshotActors, 0x50);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, svEntities, 0x60);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, gap_64, 0x64);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, numSnapshotAnimCmds, 0x84);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, snapshotAnimCmds, 0x88);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, gap_98, 0x98);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, awdawdd, 0x9C);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, nextCachedSnapshotFrames, 0xA0);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, gap_A4, 0xA4);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, nextCachedSnapshotEntities, 0xA8);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, nextCachedSnapshotClients, 0xAC);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, awdawd, 0xB0);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, max_clients, 0xB4);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, gap_B8, 0xB8);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, snapshotPeek, 0xE4);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, bg_vehicleInfos, 0xE8);
	ASSERT_STRUCT_OFFSET(serverStaticHeader_s, savedEntities, 0xEC);

	struct CmdArgs
	{
		int nesting; //OFS: 0x0 SIZE: 0x4
		int localClientNum[8]; //OFS: 0x4 SIZE: 0x20
		int controllerIndex[8]; //OFS: 0x24 SIZE: 0x20
		int argc[8]; //OFS: 0x44 SIZE: 0x20
		char ** argv[8]; //OFS: 0x64 SIZE: 0x20
	};
	ASSERT_STRUCT_SIZE(CmdArgs, 0x84);
	ASSERT_STRUCT_OFFSET(CmdArgs, nesting, 0x0);
	ASSERT_STRUCT_OFFSET(CmdArgs, localClientNum, 0x4);
	ASSERT_STRUCT_OFFSET(CmdArgs, controllerIndex, 0x24);
	ASSERT_STRUCT_OFFSET(CmdArgs, argc, 0x44);
	ASSERT_STRUCT_OFFSET(CmdArgs, argv, 0x64);

	struct pmove_s
	{
		playerState_s * ps; //OFS: 0x0 SIZE: 0x4
		usercmd_s cmd; //OFS: 0x4 SIZE: 0x38
		usercmd_s oldcmd; //OFS: 0x3C SIZE: 0x38
		int tracemask; //OFS: 0x74 SIZE: 0x4
		int numtouch; //OFS: 0x78 SIZE: 0x4
		int touchents[32]; //OFS: 0x7C SIZE: 0x80
		float mins[3]; //OFS: 0xFC SIZE: 0xC
		float maxs[3]; //OFS: 0x108 SIZE: 0xC
		float xyspeed; //OFS: 0x114 SIZE: 0x4
		int proneChange; //OFS: 0x118 SIZE: 0x4
		float maxSprintTimeMultiplier; //OFS: 0x11C SIZE: 0x4
		bool mantleStarted; //OFS: 0x120 SIZE: 0x1
		float mantleEndPos[3]; //OFS: 0x124 SIZE: 0xC
		int mantleDuration; //OFS: 0x130 SIZE: 0x4
		int viewChangeTime; //OFS: 0x134 SIZE: 0x4
		float viewChange; //OFS: 0x138 SIZE: 0x4
		float vehicleAngles[3]; //OFS: 0x13C SIZE: 0xC
		pmoveVehAnimState_t vehAnimState; //OFS: 0x148 SIZE: 0x4
		unsigned __int8 handler; //OFS: 0x14C SIZE: 0x1
		int localClientNum; //OFS: 0x150 SIZE: 0x4
		colgeom_visitor_inlined_t proximity_data; //OFS: 0x154 SIZE: 0x6B4
	};
	ASSERT_STRUCT_SIZE(pmove_s, 0x808);
	ASSERT_STRUCT_OFFSET(pmove_s, ps, 0x0);
	ASSERT_STRUCT_OFFSET(pmove_s, cmd, 0x4);
	ASSERT_STRUCT_OFFSET(pmove_s, oldcmd, 0x3C);
	ASSERT_STRUCT_OFFSET(pmove_s, tracemask, 0x74);
	ASSERT_STRUCT_OFFSET(pmove_s, numtouch, 0x78);
	ASSERT_STRUCT_OFFSET(pmove_s, touchents, 0x7C);
	ASSERT_STRUCT_OFFSET(pmove_s, mins, 0xFC);
	ASSERT_STRUCT_OFFSET(pmove_s, maxs, 0x108);
	ASSERT_STRUCT_OFFSET(pmove_s, xyspeed, 0x114);
	ASSERT_STRUCT_OFFSET(pmove_s, proneChange, 0x118);
	ASSERT_STRUCT_OFFSET(pmove_s, maxSprintTimeMultiplier, 0x11C);
	ASSERT_STRUCT_OFFSET(pmove_s, mantleStarted, 0x120);
	ASSERT_STRUCT_OFFSET(pmove_s, mantleEndPos, 0x124);
	ASSERT_STRUCT_OFFSET(pmove_s, mantleDuration, 0x130);
	ASSERT_STRUCT_OFFSET(pmove_s, viewChangeTime, 0x134);
	ASSERT_STRUCT_OFFSET(pmove_s, viewChange, 0x138);
	ASSERT_STRUCT_OFFSET(pmove_s, vehicleAngles, 0x13C);
	ASSERT_STRUCT_OFFSET(pmove_s, vehAnimState, 0x148);
	ASSERT_STRUCT_OFFSET(pmove_s, handler, 0x14C);
	ASSERT_STRUCT_OFFSET(pmove_s, localClientNum, 0x150);
	ASSERT_STRUCT_OFFSET(pmove_s, proximity_data, 0x154);

	struct clientLogo_t
	{
		int startTime; //OFS: 0x0 SIZE: 0x4
		int duration; //OFS: 0x4 SIZE: 0x4
		int fadein; //OFS: 0x8 SIZE: 0x4
		int fadeout; //OFS: 0xC SIZE: 0x4
		Material * material[2]; //OFS: 0x10 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(clientLogo_t, 0x18);
	ASSERT_STRUCT_OFFSET(clientLogo_t, startTime, 0x0);
	ASSERT_STRUCT_OFFSET(clientLogo_t, duration, 0x4);
	ASSERT_STRUCT_OFFSET(clientLogo_t, fadein, 0x8);
	ASSERT_STRUCT_OFFSET(clientLogo_t, fadeout, 0xC);
	ASSERT_STRUCT_OFFSET(clientLogo_t, material, 0x10);

	struct serverInfo_t
	{
		netadr_s hostAddr; //OFS: 0x0 SIZE: 0x18
		int secShit[7];
		int playerSlots; //OFS: 0x34 SIZE: 0x4
		int playerSlotsUsed; //OFS: 0x38 SIZE: 0x4
		int playerReservedSlots; //OFS: 0x3C SIZE: 0x4
		int playerReservedSlotsUsed; //OFS: 0x40 SIZE: 0x4
		int field_44; //OFS: 0x44 SIZE: 0x4
		int field_48; //OFS: 0x48 SIZE: 0x4
		int field_4C; //OFS: 0x4C SIZE: 0x4
		netadr_s adr; //OFS: 0x50 SIZE: 0x18
		char allowAnonymouse; //OFS: 0x68 SIZE: 0x1
		char bPassword; //OFS: 0x69 SIZE: 0x1
		char pure; //OFS: 0x6A SIZE: 0x1
		char consoleDisabled; //OFS: 0x6B SIZE: 0x1
		char arcademode; //OFS: 0x6C SIZE: 0x1
		char nettype; //OFS: 0x6D SIZE: 0x1
		char clients; //OFS: 0x6E SIZE: 0x1
		char maxClients; //OFS: 0x6F SIZE: 0x1
		char dirty; //OFS: 0x70 SIZE: 0x1
		char friendlyfire; //OFS: 0x71 SIZE: 0x1
		char killcam; //OFS: 0x72 SIZE: 0x1
		char hardware; //OFS: 0x73 SIZE: 0x1
		char mod; //OFS: 0x74 SIZE: 0x1
		char requestCount; //OFS: 0x75 SIZE: 0x1
		char punkBuster; //OFS: 0x76 SIZE: 0x1
		__int16 minping; //OFS: 0x78 SIZE: 0x2
		__int16 maxping; //OFS: 0x7A SIZE: 0x2
		__int16 ping; //OFS: 0x7C SIZE: 0x2
		char hostname[32]; //OFS: 0x7E SIZE: 0x20
		char mapname[32]; //OFS: 0x9E SIZE: 0x20
		char game[36]; //OFS: 0xBE SIZE: 0x24
		char gametype[16]; //OFS: 0xE2 SIZE: 0x10
		int field_F4; //OFS: 0xF4 SIZE: 0x4
		int field_F8; //OFS: 0xF8 SIZE: 0x4
		int field_FC; //OFS: 0xFC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(serverInfo_t, 0x100);
	ASSERT_STRUCT_OFFSET(serverInfo_t, hostAddr, 0x0);
	ASSERT_STRUCT_OFFSET(serverInfo_t, playerSlots, 0x34);
	ASSERT_STRUCT_OFFSET(serverInfo_t, playerSlotsUsed, 0x38);
	ASSERT_STRUCT_OFFSET(serverInfo_t, playerReservedSlots, 0x3C);
	ASSERT_STRUCT_OFFSET(serverInfo_t, playerReservedSlotsUsed, 0x40);
	ASSERT_STRUCT_OFFSET(serverInfo_t, field_44, 0x44);
	ASSERT_STRUCT_OFFSET(serverInfo_t, field_48, 0x48);
	ASSERT_STRUCT_OFFSET(serverInfo_t, field_4C, 0x4C);
	ASSERT_STRUCT_OFFSET(serverInfo_t, adr, 0x50);
	ASSERT_STRUCT_OFFSET(serverInfo_t, allowAnonymouse, 0x68);
	ASSERT_STRUCT_OFFSET(serverInfo_t, bPassword, 0x69);
	ASSERT_STRUCT_OFFSET(serverInfo_t, pure, 0x6A);
	ASSERT_STRUCT_OFFSET(serverInfo_t, consoleDisabled, 0x6B);
	ASSERT_STRUCT_OFFSET(serverInfo_t, arcademode, 0x6C);
	ASSERT_STRUCT_OFFSET(serverInfo_t, nettype, 0x6D);
	ASSERT_STRUCT_OFFSET(serverInfo_t, clients, 0x6E);
	ASSERT_STRUCT_OFFSET(serverInfo_t, maxClients, 0x6F);
	ASSERT_STRUCT_OFFSET(serverInfo_t, dirty, 0x70);
	ASSERT_STRUCT_OFFSET(serverInfo_t, friendlyfire, 0x71);
	ASSERT_STRUCT_OFFSET(serverInfo_t, killcam, 0x72);
	ASSERT_STRUCT_OFFSET(serverInfo_t, hardware, 0x73);
	ASSERT_STRUCT_OFFSET(serverInfo_t, mod, 0x74);
	ASSERT_STRUCT_OFFSET(serverInfo_t, requestCount, 0x75);
	ASSERT_STRUCT_OFFSET(serverInfo_t, punkBuster, 0x76);
	ASSERT_STRUCT_OFFSET(serverInfo_t, minping, 0x78);
	ASSERT_STRUCT_OFFSET(serverInfo_t, maxping, 0x7A);
	ASSERT_STRUCT_OFFSET(serverInfo_t, ping, 0x7C);
	ASSERT_STRUCT_OFFSET(serverInfo_t, hostname, 0x7E);
	ASSERT_STRUCT_OFFSET(serverInfo_t, mapname, 0x9E);
	ASSERT_STRUCT_OFFSET(serverInfo_t, game, 0xBE);
	ASSERT_STRUCT_OFFSET(serverInfo_t, gametype, 0xE2);
	ASSERT_STRUCT_OFFSET(serverInfo_t, field_F4, 0xF4);
	ASSERT_STRUCT_OFFSET(serverInfo_t, field_F8, 0xF8);
	ASSERT_STRUCT_OFFSET(serverInfo_t, field_FC, 0xFC);

	struct trDebugString_t
	{
		float xyz[3]; //OFS: 0x0 SIZE: 0xC
		float color[4]; //OFS: 0xC SIZE: 0x10
		float scale; //OFS: 0x1C SIZE: 0x4
		char text[96]; //OFS: 0x20 SIZE: 0x60
	};
	ASSERT_STRUCT_SIZE(trDebugString_t, 0x80);
	ASSERT_STRUCT_OFFSET(trDebugString_t, xyz, 0x0);
	ASSERT_STRUCT_OFFSET(trDebugString_t, color, 0xC);
	ASSERT_STRUCT_OFFSET(trDebugString_t, scale, 0x1C);
	ASSERT_STRUCT_OFFSET(trDebugString_t, text, 0x20);

	struct clientDebugStringInfo_t
	{
		int max; //OFS: 0x0 SIZE: 0x4
		int num; //OFS: 0x4 SIZE: 0x4
		trDebugString_t * strings; //OFS: 0x8 SIZE: 0x4
		int * durations; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(clientDebugStringInfo_t, 0x10);
	ASSERT_STRUCT_OFFSET(clientDebugStringInfo_t, max, 0x0);
	ASSERT_STRUCT_OFFSET(clientDebugStringInfo_t, num, 0x4);
	ASSERT_STRUCT_OFFSET(clientDebugStringInfo_t, strings, 0x8);
	ASSERT_STRUCT_OFFSET(clientDebugStringInfo_t, durations, 0xC);

	struct trDebugLine_t
	{
		float start[3]; //OFS: 0x0 SIZE: 0xC
		float end[3]; //OFS: 0xC SIZE: 0xC
		float color[4]; //OFS: 0x18 SIZE: 0x10
		int depthTest; //OFS: 0x28 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(trDebugLine_t, 0x2C);
	ASSERT_STRUCT_OFFSET(trDebugLine_t, start, 0x0);
	ASSERT_STRUCT_OFFSET(trDebugLine_t, end, 0xC);
	ASSERT_STRUCT_OFFSET(trDebugLine_t, color, 0x18);
	ASSERT_STRUCT_OFFSET(trDebugLine_t, depthTest, 0x28);

	struct clientDebugLineInfo_t
	{
		int max; //OFS: 0x0 SIZE: 0x4
		int num; //OFS: 0x4 SIZE: 0x4
		trDebugLine_t * lines; //OFS: 0x8 SIZE: 0x4
		int * durations; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(clientDebugLineInfo_t, 0x10);
	ASSERT_STRUCT_OFFSET(clientDebugLineInfo_t, max, 0x0);
	ASSERT_STRUCT_OFFSET(clientDebugLineInfo_t, num, 0x4);
	ASSERT_STRUCT_OFFSET(clientDebugLineInfo_t, lines, 0x8);
	ASSERT_STRUCT_OFFSET(clientDebugLineInfo_t, durations, 0xC);

	struct clientDebug_t
	{
		int prevFromServer; //OFS: 0x0 SIZE: 0x4
		int fromServer; //OFS: 0x4 SIZE: 0x4
		clientDebugStringInfo_t clStrings; //OFS: 0x8 SIZE: 0x10
		clientDebugStringInfo_t svStringsBuffer; //OFS: 0x18 SIZE: 0x10
		clientDebugStringInfo_t svStrings; //OFS: 0x28 SIZE: 0x10
		clientDebugLineInfo_t clLines; //OFS: 0x38 SIZE: 0x10
		clientDebugLineInfo_t svLinesBuffer; //OFS: 0x48 SIZE: 0x10
		clientDebugLineInfo_t svLines; //OFS: 0x58 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(clientDebug_t, 0x68);
	ASSERT_STRUCT_OFFSET(clientDebug_t, prevFromServer, 0x0);
	ASSERT_STRUCT_OFFSET(clientDebug_t, fromServer, 0x4);
	ASSERT_STRUCT_OFFSET(clientDebug_t, clStrings, 0x8);
	ASSERT_STRUCT_OFFSET(clientDebug_t, svStringsBuffer, 0x18);
	ASSERT_STRUCT_OFFSET(clientDebug_t, svStrings, 0x28);
	ASSERT_STRUCT_OFFSET(clientDebug_t, clLines, 0x38);
	ASSERT_STRUCT_OFFSET(clientDebug_t, svLinesBuffer, 0x48);
	ASSERT_STRUCT_OFFSET(clientDebug_t, svLines, 0x58);

	struct clientStatic_s
	{
		int quit; //OFS: 0x0 SIZE: 0x4
		int hunkUsersStarted; //OFS: 0x4 SIZE: 0x4
		char serverName[256]; //OFS: 0x8 SIZE: 0x100
		char field_108[32]; //OFS: 0x108 SIZE: 0x20
		int field_128; //OFS: 0x128 SIZE: 0x4
		_BYTE gap12C[16]; //OFS: 0x12C SIZE: 0x10
		int rendererStarted; //OFS: 0x13C SIZE: 0x4
		int soundStarted; //OFS: 0x140 SIZE: 0x4
		int uiStarted; //OFS: 0x144 SIZE: 0x4
		int frametime; //OFS: 0x148 SIZE: 0x4
		int realtimepause; //OFS: 0x14C SIZE: 0x4
		int realtime; //OFS: 0x150 SIZE: 0x4
		int realFrameTime; //OFS: 0x154 SIZE: 0x4
		clientLogo_t logo; //OFS: 0x158 SIZE: 0x18
		float mapCenter[3]; //OFS: 0x170 SIZE: 0xC
		int numlocalservers; //OFS: 0x17C SIZE: 0x4
		serverInfo_t localServers[128]; //OFS: 0x180 SIZE: 0x8000
		_BYTE gap_8180[4]; //OFS: 0x8180 SIZE: 0x4
		int numglobalservers; //OFS: 0x8184 SIZE: 0x4
		serverInfo_t globalServers[20000]; //OFS: 0x8188 SIZE: 0x4E2000
		int numfriendsservers; //OFS: 0x4EA188 SIZE: 0x4
		int pad; //OFS: 0x4EA18C SIZE: 0x4
		serverInfo_t friendServers[128]; //OFS: 0x4EA190 SIZE: 0x8000
		int numfavoriteservers; //OFS: 0x4F2190 SIZE: 0x4
		int pad2; //OFS: 0x4F2194 SIZE: 0x4
		serverInfo_t favoriteServers[128]; //OFS: 0x4F2198 SIZE: 0x8000
		int pingUpdateSource; //OFS: 0x4FA198 SIZE: 0x4
		_BYTE gap_4FA19C[2916]; //OFS: 0x4FA19C SIZE: 0xB64
		netadr_s dNet; //OFS: 0x4FAD00 SIZE: 0x18
		_BYTE gap4FAD18[52]; //OFS: 0x4FAD18 SIZE: 0x34
		clientDebug_t debug; //OFS: 0x4FAD4C SIZE: 0x68
		float renderForward[3]; //OFS: 0x4FADB4 SIZE: 0xC
		float renderPos[3]; //OFS: 0x4FADC0 SIZE: 0xC
		int download; //OFS: 0x4FADCC SIZE: 0x4
		char downloadTempName[256]; //OFS: 0x4FADD0 SIZE: 0x100
		char downloadName[256]; //OFS: 0x4FAED0 SIZE: 0x100
		int downloadNumber; //OFS: 0x4FAFD0 SIZE: 0x4
		int downloadBlock; //OFS: 0x4FAFD4 SIZE: 0x4
		int downloadCount; //OFS: 0x4FAFD8 SIZE: 0x4
		int downloadSize; //OFS: 0x4FAFDC SIZE: 0x4
		char downloadList[1536]; //OFS: 0x4FAFE0 SIZE: 0x600
		int downloadRestart; //OFS: 0x4FB5E0 SIZE: 0x4
		int gameDirChanged; //OFS: 0x4FB5E4 SIZE: 0x4
		_BYTE gap_4FB5E8[119]; //OFS: 0x4FB5E8 SIZE: 0x77
		char field_4FB65F; //OFS: 0x4FB65F SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(clientStatic_s, 0x4FB660);
	ASSERT_STRUCT_OFFSET(clientStatic_s, quit, 0x0);
	ASSERT_STRUCT_OFFSET(clientStatic_s, hunkUsersStarted, 0x4);
	ASSERT_STRUCT_OFFSET(clientStatic_s, serverName, 0x8);
	ASSERT_STRUCT_OFFSET(clientStatic_s, field_108, 0x108);
	ASSERT_STRUCT_OFFSET(clientStatic_s, field_128, 0x128);
	ASSERT_STRUCT_OFFSET(clientStatic_s, gap12C, 0x12C);
	ASSERT_STRUCT_OFFSET(clientStatic_s, rendererStarted, 0x13C);
	ASSERT_STRUCT_OFFSET(clientStatic_s, soundStarted, 0x140);
	ASSERT_STRUCT_OFFSET(clientStatic_s, uiStarted, 0x144);
	ASSERT_STRUCT_OFFSET(clientStatic_s, frametime, 0x148);
	ASSERT_STRUCT_OFFSET(clientStatic_s, realtimepause, 0x14C);
	ASSERT_STRUCT_OFFSET(clientStatic_s, realtime, 0x150);
	ASSERT_STRUCT_OFFSET(clientStatic_s, realFrameTime, 0x154);
	ASSERT_STRUCT_OFFSET(clientStatic_s, logo, 0x158);
	ASSERT_STRUCT_OFFSET(clientStatic_s, mapCenter, 0x170);
	ASSERT_STRUCT_OFFSET(clientStatic_s, numlocalservers, 0x17C);
	ASSERT_STRUCT_OFFSET(clientStatic_s, localServers, 0x180);
	ASSERT_STRUCT_OFFSET(clientStatic_s, gap_8180, 0x8180);
	ASSERT_STRUCT_OFFSET(clientStatic_s, numglobalservers, 0x8184);
	ASSERT_STRUCT_OFFSET(clientStatic_s, globalServers, 0x8188);
	ASSERT_STRUCT_OFFSET(clientStatic_s, numfriendsservers, 0x4EA188);
	ASSERT_STRUCT_OFFSET(clientStatic_s, pad, 0x4EA18C);
	ASSERT_STRUCT_OFFSET(clientStatic_s, friendServers, 0x4EA190);
	ASSERT_STRUCT_OFFSET(clientStatic_s, numfavoriteservers, 0x4F2190);
	ASSERT_STRUCT_OFFSET(clientStatic_s, pad2, 0x4F2194);
	ASSERT_STRUCT_OFFSET(clientStatic_s, favoriteServers, 0x4F2198);
	ASSERT_STRUCT_OFFSET(clientStatic_s, pingUpdateSource, 0x4FA198);
	ASSERT_STRUCT_OFFSET(clientStatic_s, gap_4FA19C, 0x4FA19C);
	ASSERT_STRUCT_OFFSET(clientStatic_s, dNet, 0x4FAD00);
	ASSERT_STRUCT_OFFSET(clientStatic_s, gap4FAD18, 0x4FAD18);
	ASSERT_STRUCT_OFFSET(clientStatic_s, debug, 0x4FAD4C);
	ASSERT_STRUCT_OFFSET(clientStatic_s, renderForward, 0x4FADB4);
	ASSERT_STRUCT_OFFSET(clientStatic_s, renderPos, 0x4FADC0);
	ASSERT_STRUCT_OFFSET(clientStatic_s, download, 0x4FADCC);
	ASSERT_STRUCT_OFFSET(clientStatic_s, downloadTempName, 0x4FADD0);
	ASSERT_STRUCT_OFFSET(clientStatic_s, downloadName, 0x4FAED0);
	ASSERT_STRUCT_OFFSET(clientStatic_s, downloadNumber, 0x4FAFD0);
	ASSERT_STRUCT_OFFSET(clientStatic_s, downloadBlock, 0x4FAFD4);
	ASSERT_STRUCT_OFFSET(clientStatic_s, downloadCount, 0x4FAFD8);
	ASSERT_STRUCT_OFFSET(clientStatic_s, downloadSize, 0x4FAFDC);
	ASSERT_STRUCT_OFFSET(clientStatic_s, downloadList, 0x4FAFE0);
	ASSERT_STRUCT_OFFSET(clientStatic_s, downloadRestart, 0x4FB5E0);
	ASSERT_STRUCT_OFFSET(clientStatic_s, gameDirChanged, 0x4FB5E4);
	ASSERT_STRUCT_OFFSET(clientStatic_s, gap_4FB5E8, 0x4FB5E8);
	ASSERT_STRUCT_OFFSET(clientStatic_s, field_4FB65F, 0x4FB65F);

	struct clientUIActive_s
	{
		char active; //OFS: 0x0 SIZE: 0x1
		char isRunning; //OFS: 0x1 SIZE: 0x1
		char cgameInitialized; //OFS: 0x2 SIZE: 0x1
		char cgameInitCalled; //OFS: 0x3 SIZE: 0x1
		int mapPreloaded; //OFS: 0x4 SIZE: 0x4
		int keyCatchers; //OFS: 0x8 SIZE: 0x4
		int displayHUDWithKeycatchUI; //OFS: 0xC SIZE: 0x4
		connstate_t connectionState[1]; //OFS: 0x10 SIZE: 0x4
		int nextScrollTime; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(clientUIActive_s, 0x18);
	ASSERT_STRUCT_OFFSET(clientUIActive_s, active, 0x0);
	ASSERT_STRUCT_OFFSET(clientUIActive_s, isRunning, 0x1);
	ASSERT_STRUCT_OFFSET(clientUIActive_s, cgameInitialized, 0x2);
	ASSERT_STRUCT_OFFSET(clientUIActive_s, cgameInitCalled, 0x3);
	ASSERT_STRUCT_OFFSET(clientUIActive_s, mapPreloaded, 0x4);
	ASSERT_STRUCT_OFFSET(clientUIActive_s, keyCatchers, 0x8);
	ASSERT_STRUCT_OFFSET(clientUIActive_s, displayHUDWithKeycatchUI, 0xC);
	ASSERT_STRUCT_OFFSET(clientUIActive_s, connectionState, 0x10);
	ASSERT_STRUCT_OFFSET(clientUIActive_s, nextScrollTime, 0x14);

	struct TraceExtents
	{
		float start[4]; //OFS: 0x0 SIZE: 0x10
		float end[4]; //OFS: 0x10 SIZE: 0x10
		float invDelta[4]; //OFS: 0x20 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(TraceExtents, 0x30);
	ASSERT_STRUCT_OFFSET(TraceExtents, start, 0x0);
	ASSERT_STRUCT_OFFSET(TraceExtents, end, 0x10);
	ASSERT_STRUCT_OFFSET(TraceExtents, invDelta, 0x20);

	struct moveclip_t
	{
		float mins[3]; //OFS: 0x0 SIZE: 0xC
		float maxs[3]; //OFS: 0xC SIZE: 0xC
		float outerSize[3]; //OFS: 0x18 SIZE: 0xC
		TraceExtents extents; //OFS: 0x24 SIZE: 0x30
		int passEntityNum; //OFS: 0x54 SIZE: 0x4
		int passOwnerNum; //OFS: 0x58 SIZE: 0x4
		int contentmask; //OFS: 0x5C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(moveclip_t, 0x60);
	ASSERT_STRUCT_OFFSET(moveclip_t, mins, 0x0);
	ASSERT_STRUCT_OFFSET(moveclip_t, maxs, 0xC);
	ASSERT_STRUCT_OFFSET(moveclip_t, outerSize, 0x18);
	ASSERT_STRUCT_OFFSET(moveclip_t, extents, 0x24);
	ASSERT_STRUCT_OFFSET(moveclip_t, passEntityNum, 0x54);
	ASSERT_STRUCT_OFFSET(moveclip_t, passOwnerNum, 0x58);
	ASSERT_STRUCT_OFFSET(moveclip_t, contentmask, 0x5C);

	struct IgnoreEntParams
	{
		int baseEntity; //OFS: 0x0 SIZE: 0x4
		int parentEntity; //OFS: 0x4 SIZE: 0x4
		char ignoreSelf; //OFS: 0x8 SIZE: 0x1
		char ignoreParent; //OFS: 0x9 SIZE: 0x1
		char ignoreSiblings; //OFS: 0xA SIZE: 0x1
		char ignoreChildren; //OFS: 0xB SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(IgnoreEntParams, 0xC);
	ASSERT_STRUCT_OFFSET(IgnoreEntParams, baseEntity, 0x0);
	ASSERT_STRUCT_OFFSET(IgnoreEntParams, parentEntity, 0x4);
	ASSERT_STRUCT_OFFSET(IgnoreEntParams, ignoreSelf, 0x8);
	ASSERT_STRUCT_OFFSET(IgnoreEntParams, ignoreParent, 0x9);
	ASSERT_STRUCT_OFFSET(IgnoreEntParams, ignoreSiblings, 0xA);
	ASSERT_STRUCT_OFFSET(IgnoreEntParams, ignoreChildren, 0xB);

	struct pointtrace_t
	{
		TraceExtents extents; //OFS: 0x0 SIZE: 0x30
		IgnoreEntParams * ignoreEntParams; //OFS: 0x30 SIZE: 0x4
		int contentmask; //OFS: 0x34 SIZE: 0x4
		int bLocational; //OFS: 0x38 SIZE: 0x4
		int priorityMap; //OFS: 0x3C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(pointtrace_t, 0x40);
	ASSERT_STRUCT_OFFSET(pointtrace_t, extents, 0x0);
	ASSERT_STRUCT_OFFSET(pointtrace_t, ignoreEntParams, 0x30);
	ASSERT_STRUCT_OFFSET(pointtrace_t, contentmask, 0x34);
	ASSERT_STRUCT_OFFSET(pointtrace_t, bLocational, 0x38);
	ASSERT_STRUCT_OFFSET(pointtrace_t, priorityMap, 0x3C);

	struct field_t
	{
		int cursor; //OFS: 0x0 SIZE: 0x4
		int scroll; //OFS: 0x4 SIZE: 0x4
		int drawWidth; //OFS: 0x8 SIZE: 0x4
		int widthInPixels; //OFS: 0xC SIZE: 0x4
		float charHeight; //OFS: 0x10 SIZE: 0x4
		int fixedSize; //OFS: 0x14 SIZE: 0x4
		char buffer[256]; //OFS: 0x18 SIZE: 0x100
	};
	ASSERT_STRUCT_SIZE(field_t, 0x118);
	ASSERT_STRUCT_OFFSET(field_t, cursor, 0x0);
	ASSERT_STRUCT_OFFSET(field_t, scroll, 0x4);
	ASSERT_STRUCT_OFFSET(field_t, drawWidth, 0x8);
	ASSERT_STRUCT_OFFSET(field_t, widthInPixels, 0xC);
	ASSERT_STRUCT_OFFSET(field_t, charHeight, 0x10);
	ASSERT_STRUCT_OFFSET(field_t, fixedSize, 0x14);
	ASSERT_STRUCT_OFFSET(field_t, buffer, 0x18);

	struct entityHandler_t
	{
		void (__cdecl *think)(gentity_s *); //OFS: 0x0 SIZE: 0x4
		void (__cdecl *reached)(gentity_s *); //OFS: 0x4 SIZE: 0x4
		void (__cdecl *blocked)(gentity_s *, gentity_s *); //OFS: 0x8 SIZE: 0x4
		void (__cdecl *touch)(gentity_s *, gentity_s *, int); //OFS: 0xC SIZE: 0x4
		void (__cdecl *use)(gentity_s *, gentity_s *, gentity_s *); //OFS: 0x10 SIZE: 0x4
		void (__cdecl *pain)(gentity_s *, gentity_s *, int, const float *, const int, const float *, const int, const int); //OFS: 0x14 SIZE: 0x4
		void (__cdecl *die)(gentity_s *, gentity_s *, gentity_s *, const int, const int, const int, const float *, const int); //OFS: 0x18 SIZE: 0x4
		void (__cdecl *entinfo)(gentity_s *, float *); //OFS: 0x1C SIZE: 0x4
		void (__cdecl *controller)(const gentity_s *, int *); //OFS: 0x20 SIZE: 0x4
		meansOfDeath_t methodOfDeath; //OFS: 0x24 SIZE: 0x4
		int splashMethodOfDeath; //OFS: 0x28 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(entityHandler_t, 0x2C);
	ASSERT_STRUCT_OFFSET(entityHandler_t, think, 0x0);
	ASSERT_STRUCT_OFFSET(entityHandler_t, reached, 0x4);
	ASSERT_STRUCT_OFFSET(entityHandler_t, blocked, 0x8);
	ASSERT_STRUCT_OFFSET(entityHandler_t, touch, 0xC);
	ASSERT_STRUCT_OFFSET(entityHandler_t, use, 0x10);
	ASSERT_STRUCT_OFFSET(entityHandler_t, pain, 0x14);
	ASSERT_STRUCT_OFFSET(entityHandler_t, die, 0x18);
	ASSERT_STRUCT_OFFSET(entityHandler_t, entinfo, 0x1C);
	ASSERT_STRUCT_OFFSET(entityHandler_t, controller, 0x20);
	ASSERT_STRUCT_OFFSET(entityHandler_t, methodOfDeath, 0x24);
	ASSERT_STRUCT_OFFSET(entityHandler_t, splashMethodOfDeath, 0x28);

	struct CmdArgsPrivate
	{
		char textPool[8192]; //OFS: 0x0 SIZE: 0x2000
		char * argvPool[512]; //OFS: 0x2000 SIZE: 0x800
		int usedTextPool[8]; //OFS: 0x2800 SIZE: 0x20
		int totalUsedArgvPool; //OFS: 0x2820 SIZE: 0x4
		int totalUsedTextPool; //OFS: 0x2824 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(CmdArgsPrivate, 0x2828);
	ASSERT_STRUCT_OFFSET(CmdArgsPrivate, textPool, 0x0);
	ASSERT_STRUCT_OFFSET(CmdArgsPrivate, argvPool, 0x2000);
	ASSERT_STRUCT_OFFSET(CmdArgsPrivate, usedTextPool, 0x2800);
	ASSERT_STRUCT_OFFSET(CmdArgsPrivate, totalUsedArgvPool, 0x2820);
	ASSERT_STRUCT_OFFSET(CmdArgsPrivate, totalUsedTextPool, 0x2824);

	struct ConDrawInputGlob
	{
		char autoCompleteChoice[64]; //OFS: 0x0 SIZE: 0x40
		int matchIndex; //OFS: 0x40 SIZE: 0x4
		int matchCount; //OFS: 0x44 SIZE: 0x4
		const char * inputText; //OFS: 0x48 SIZE: 0x4
		int inputTextLen; //OFS: 0x4C SIZE: 0x4
		bool hasExactMatch; //OFS: 0x50 SIZE: 0x1
		bool mayAutoComplete; //OFS: 0x51 SIZE: 0x1
		float x; //OFS: 0x54 SIZE: 0x4
		float y; //OFS: 0x58 SIZE: 0x4
		float leftX; //OFS: 0x5C SIZE: 0x4
		float fontHeight; //OFS: 0x60 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ConDrawInputGlob, 0x64);
	ASSERT_STRUCT_OFFSET(ConDrawInputGlob, autoCompleteChoice, 0x0);
	ASSERT_STRUCT_OFFSET(ConDrawInputGlob, matchIndex, 0x40);
	ASSERT_STRUCT_OFFSET(ConDrawInputGlob, matchCount, 0x44);
	ASSERT_STRUCT_OFFSET(ConDrawInputGlob, inputText, 0x48);
	ASSERT_STRUCT_OFFSET(ConDrawInputGlob, inputTextLen, 0x4C);
	ASSERT_STRUCT_OFFSET(ConDrawInputGlob, hasExactMatch, 0x50);
	ASSERT_STRUCT_OFFSET(ConDrawInputGlob, mayAutoComplete, 0x51);
	ASSERT_STRUCT_OFFSET(ConDrawInputGlob, x, 0x54);
	ASSERT_STRUCT_OFFSET(ConDrawInputGlob, y, 0x58);
	ASSERT_STRUCT_OFFSET(ConDrawInputGlob, leftX, 0x5C);
	ASSERT_STRUCT_OFFSET(ConDrawInputGlob, fontHeight, 0x60);

	struct clientConnection_t
	{
		int qport; //OFS: 0x0 SIZE: 0x4
		int clientNum; //OFS: 0x4 SIZE: 0x4
		int lastPacketSentTime; //OFS: 0x8 SIZE: 0x4
		int lastPacketTime; //OFS: 0xC SIZE: 0x4
		netadr_s serverAddress; //OFS: 0x10 SIZE: 0x18
		int connectTime; //OFS: 0x28 SIZE: 0x4
		int connectPacketCount; //OFS: 0x2C SIZE: 0x4
		char serverMessage[256]; //OFS: 0x30 SIZE: 0x100
		int challenge; //OFS: 0x130 SIZE: 0x4
		int checksumFeed; //OFS: 0x134 SIZE: 0x4
		int reliableSequence; //OFS: 0x138 SIZE: 0x4
		int reliableAcknowledge; //OFS: 0x13C SIZE: 0x4
		char reliableCommands[128][512]; //OFS: 0x140 SIZE: 0x10000
		int serverMessageSequence; //OFS: 0x10140 SIZE: 0x4
		int serverCommandSequence; //OFS: 0x10144 SIZE: 0x4
		int lastExecutedServerCommand; //OFS: 0x10148 SIZE: 0x4
		char serverCommands[128][512]; //OFS: 0x1014C SIZE: 0x10000
		char isServerRestarting; //OFS: 0x2014C SIZE: 0x1
		int timeDemoBaseTime; //OFS: 0x20150 SIZE: 0x4
		netchan_s netchan; //OFS: 0x20154 SIZE: 0x6C8
		char netchanOutgoingBuffer[2048]; //OFS: 0x2081C SIZE: 0x800
		char netchanIncomingBuffer[131072]; //OFS: 0x2101C SIZE: 0x20000
		netProfileInfo_t OOBProf; //OFS: 0x4101C SIZE: 0x5E0
		char statPacketsToSend; //OFS: 0x415FC SIZE: 0x1
		int statPacketSendTime[7]; //OFS: 0x41600 SIZE: 0x1C
		int serverChallenge; //OFS: 0x4161C SIZE: 0x4
		int clientChallenge; //OFS: 0x41620 SIZE: 0x4
		int nonce; //OFS: 0x41624 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(clientConnection_t, 0x41628);
	ASSERT_STRUCT_OFFSET(clientConnection_t, qport, 0x0);
	ASSERT_STRUCT_OFFSET(clientConnection_t, clientNum, 0x4);
	ASSERT_STRUCT_OFFSET(clientConnection_t, lastPacketSentTime, 0x8);
	ASSERT_STRUCT_OFFSET(clientConnection_t, lastPacketTime, 0xC);
	ASSERT_STRUCT_OFFSET(clientConnection_t, serverAddress, 0x10);
	ASSERT_STRUCT_OFFSET(clientConnection_t, connectTime, 0x28);
	ASSERT_STRUCT_OFFSET(clientConnection_t, connectPacketCount, 0x2C);
	ASSERT_STRUCT_OFFSET(clientConnection_t, serverMessage, 0x30);
	ASSERT_STRUCT_OFFSET(clientConnection_t, challenge, 0x130);
	ASSERT_STRUCT_OFFSET(clientConnection_t, checksumFeed, 0x134);
	ASSERT_STRUCT_OFFSET(clientConnection_t, reliableSequence, 0x138);
	ASSERT_STRUCT_OFFSET(clientConnection_t, reliableAcknowledge, 0x13C);
	ASSERT_STRUCT_OFFSET(clientConnection_t, reliableCommands, 0x140);
	ASSERT_STRUCT_OFFSET(clientConnection_t, serverMessageSequence, 0x10140);
	ASSERT_STRUCT_OFFSET(clientConnection_t, serverCommandSequence, 0x10144);
	ASSERT_STRUCT_OFFSET(clientConnection_t, lastExecutedServerCommand, 0x10148);
	ASSERT_STRUCT_OFFSET(clientConnection_t, serverCommands, 0x1014C);
	ASSERT_STRUCT_OFFSET(clientConnection_t, isServerRestarting, 0x2014C);
	ASSERT_STRUCT_OFFSET(clientConnection_t, timeDemoBaseTime, 0x20150);
	ASSERT_STRUCT_OFFSET(clientConnection_t, netchan, 0x20154);
	ASSERT_STRUCT_OFFSET(clientConnection_t, netchanOutgoingBuffer, 0x2081C);
	ASSERT_STRUCT_OFFSET(clientConnection_t, netchanIncomingBuffer, 0x2101C);
	ASSERT_STRUCT_OFFSET(clientConnection_t, OOBProf, 0x4101C);
	ASSERT_STRUCT_OFFSET(clientConnection_t, statPacketsToSend, 0x415FC);
	ASSERT_STRUCT_OFFSET(clientConnection_t, statPacketSendTime, 0x41600);
	ASSERT_STRUCT_OFFSET(clientConnection_t, serverChallenge, 0x4161C);
	ASSERT_STRUCT_OFFSET(clientConnection_t, clientChallenge, 0x41620);
	ASSERT_STRUCT_OFFSET(clientConnection_t, nonce, 0x41624);

	struct CmdText
	{
		char * data; //OFS: 0x0 SIZE: 0x4
		int maxsize; //OFS: 0x4 SIZE: 0x4
		int cmdsize; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(CmdText, 0xC);
	ASSERT_STRUCT_OFFSET(CmdText, data, 0x0);
	ASSERT_STRUCT_OFFSET(CmdText, maxsize, 0x4);
	ASSERT_STRUCT_OFFSET(CmdText, cmdsize, 0x8);

	struct Console
	{
		_BYTE gap_0[66120]; //OFS: 0x0 SIZE: 0x10248
		char outputVisible; //OFS: 0x10248 SIZE: 0x1
		_BYTE gap_10249[18563]; //OFS: 0x10249 SIZE: 0x4883
		int field_14ACC; //OFS: 0x14ACC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(Console, 0x14AD0);
	ASSERT_STRUCT_OFFSET(Console, gap_0, 0x0);
	ASSERT_STRUCT_OFFSET(Console, outputVisible, 0x10248);
	ASSERT_STRUCT_OFFSET(Console, gap_10249, 0x10249);
	ASSERT_STRUCT_OFFSET(Console, field_14ACC, 0x14ACC);

	struct vehicle_field_s
	{
		const char * name; //OFS: 0x0 SIZE: 0x4
		int ofs; //OFS: 0x4 SIZE: 0x4
		int type; //OFS: 0x8 SIZE: 0x4
		int mask; //OFS: 0xC SIZE: 0x4
		void (__cdecl *setter)(void *, int); //OFS: 0x10 SIZE: 0x4
		void (__cdecl *getter)(void *, int); //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(vehicle_field_s, 0x18);
	ASSERT_STRUCT_OFFSET(vehicle_field_s, name, 0x0);
	ASSERT_STRUCT_OFFSET(vehicle_field_s, ofs, 0x4);
	ASSERT_STRUCT_OFFSET(vehicle_field_s, type, 0x8);
	ASSERT_STRUCT_OFFSET(vehicle_field_s, mask, 0xC);
	ASSERT_STRUCT_OFFSET(vehicle_field_s, setter, 0x10);
	ASSERT_STRUCT_OFFSET(vehicle_field_s, getter, 0x14);

	struct menuParse_t
	{
		const char * name; //OFS: 0x0 SIZE: 0x4
		void (__cdecl *func)(void *, int); //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(menuParse_t, 0x8);
	ASSERT_STRUCT_OFFSET(menuParse_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(menuParse_t, func, 0x4);

	struct itemParse_t
	{
		const char * name; //OFS: 0x0 SIZE: 0x4
		void (__cdecl *func)(void *, int); //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(itemParse_t, 0x8);
	ASSERT_STRUCT_OFFSET(itemParse_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(itemParse_t, func, 0x4);

	struct commandDef_t
	{
		const char * name; //OFS: 0x0 SIZE: 0x4
		void (__cdecl *func)(UiContext *, itemDef_s *, char **); //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(commandDef_t, 0x8);
	ASSERT_STRUCT_OFFSET(commandDef_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(commandDef_t, func, 0x4);

	struct KeyState
	{
		int down; //OFS: 0x0 SIZE: 0x4
		int repeats; //OFS: 0x4 SIZE: 0x4
		char * binding; //OFS: 0x8 SIZE: 0x4
		char * binding_2; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(KeyState, 0x10);
	ASSERT_STRUCT_OFFSET(KeyState, down, 0x0);
	ASSERT_STRUCT_OFFSET(KeyState, repeats, 0x4);
	ASSERT_STRUCT_OFFSET(KeyState, binding, 0x8);
	ASSERT_STRUCT_OFFSET(KeyState, binding_2, 0xC);

	struct PlayerKeyState
	{
		int chat_team; //OFS: 0x0 SIZE: 0x4
		_BYTE gap_4[4]; //OFS: 0x4 SIZE: 0x4
		int anyKeyDown; //OFS: 0x8 SIZE: 0x4
		KeyState keys[256]; //OFS: 0xC SIZE: 0x1000
		LocSelInputState locSelInputState; //OFS: 0x100C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(PlayerKeyState, 0x1010);
	ASSERT_STRUCT_OFFSET(PlayerKeyState, chat_team, 0x0);
	ASSERT_STRUCT_OFFSET(PlayerKeyState, gap_4, 0x4);
	ASSERT_STRUCT_OFFSET(PlayerKeyState, anyKeyDown, 0x8);
	ASSERT_STRUCT_OFFSET(PlayerKeyState, keys, 0xC);
	ASSERT_STRUCT_OFFSET(PlayerKeyState, locSelInputState, 0x100C);

	union qfile_gus
	{
		_iobuf * o; //OFS: 0x0 SIZE: 0x4
		char * z; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(qfile_gus, 0x4);

	struct qfile_us
	{
		qfile_gus file; //OFS: 0x0 SIZE: 0x4
		int iwdIsClone; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(qfile_us, 0x8);
	ASSERT_STRUCT_OFFSET(qfile_us, file, 0x0);
	ASSERT_STRUCT_OFFSET(qfile_us, iwdIsClone, 0x4);

	struct fileHandleData_t
	{
		qfile_us handleFiles; //OFS: 0x0 SIZE: 0x8
		int handleSync; //OFS: 0x8 SIZE: 0x4
		int fileSize; //OFS: 0xC SIZE: 0x4
		int zipFilePos; //OFS: 0x10 SIZE: 0x4
		void * zipFile; //OFS: 0x14 SIZE: 0x4
		int streamed; //OFS: 0x18 SIZE: 0x4
		char name[256]; //OFS: 0x1C SIZE: 0x100
	};
	ASSERT_STRUCT_SIZE(fileHandleData_t, 0x11C);
	ASSERT_STRUCT_OFFSET(fileHandleData_t, handleFiles, 0x0);
	ASSERT_STRUCT_OFFSET(fileHandleData_t, handleSync, 0x8);
	ASSERT_STRUCT_OFFSET(fileHandleData_t, fileSize, 0xC);
	ASSERT_STRUCT_OFFSET(fileHandleData_t, zipFilePos, 0x10);
	ASSERT_STRUCT_OFFSET(fileHandleData_t, zipFile, 0x14);
	ASSERT_STRUCT_OFFSET(fileHandleData_t, streamed, 0x18);
	ASSERT_STRUCT_OFFSET(fileHandleData_t, name, 0x1C);

	struct game_hudelem_s
	{
		hudelem_s elem; //OFS: 0x0 SIZE: 0xAC
		int clientNum; //OFS: 0xAC SIZE: 0x4
		int team; //OFS: 0xB0 SIZE: 0x4
		int archived; //OFS: 0xB4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(game_hudelem_s, 0xB8);
	ASSERT_STRUCT_OFFSET(game_hudelem_s, elem, 0x0);
	ASSERT_STRUCT_OFFSET(game_hudelem_s, clientNum, 0xAC);
	ASSERT_STRUCT_OFFSET(game_hudelem_s, team, 0xB0);
	ASSERT_STRUCT_OFFSET(game_hudelem_s, archived, 0xB4);

	struct PartyData_s
	{
		_BYTE gap_0[5996]; //OFS: 0x0 SIZE: 0x176C
		_DWORD areWeHost; //OFS: 0x176C SIZE: 0x4
		_DWORD joiningAnotherParty; //OFS: 0x1770 SIZE: 0x4
		_DWORD inParty; //OFS: 0x1774 SIZE: 0x4
		_DWORD party_systemActive; //OFS: 0x1778 SIZE: 0x4
		_BYTE gap_177C[2739]; //OFS: 0x177C SIZE: 0xAB3
		char field_222F; //OFS: 0x222F SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(PartyData_s, 0x2230);
	ASSERT_STRUCT_OFFSET(PartyData_s, gap_0, 0x0);
	ASSERT_STRUCT_OFFSET(PartyData_s, areWeHost, 0x176C);
	ASSERT_STRUCT_OFFSET(PartyData_s, joiningAnotherParty, 0x1770);
	ASSERT_STRUCT_OFFSET(PartyData_s, inParty, 0x1774);
	ASSERT_STRUCT_OFFSET(PartyData_s, party_systemActive, 0x1778);
	ASSERT_STRUCT_OFFSET(PartyData_s, gap_177C, 0x177C);
	ASSERT_STRUCT_OFFSET(PartyData_s, field_222F, 0x222F);

	struct __declspec(align(1)) SessionData
	{
		_BYTE gap0[375]; //OFS: 0x0 SIZE: 0x177
		char field_177; //OFS: 0x177 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(SessionData, 0x178);
	ASSERT_STRUCT_OFFSET(SessionData, gap0, 0x0);
	ASSERT_STRUCT_OFFSET(SessionData, field_177, 0x177);

	struct __declspec(align(1)) playerDetails_s
	{
		_BYTE gap0[103]; //OFS: 0x0 SIZE: 0x67
		char field_67; //OFS: 0x67 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(playerDetails_s, 0x68);
	ASSERT_STRUCT_OFFSET(playerDetails_s, gap0, 0x0);
	ASSERT_STRUCT_OFFSET(playerDetails_s, field_67, 0x67);

	struct cspField_t
	{
		const char * szName; //OFS: 0x0 SIZE: 0x4
		int iOffset; //OFS: 0x4 SIZE: 0x4
		int iFieldType; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(cspField_t, 0xC);
	ASSERT_STRUCT_OFFSET(cspField_t, szName, 0x0);
	ASSERT_STRUCT_OFFSET(cspField_t, iOffset, 0x4);
	ASSERT_STRUCT_OFFSET(cspField_t, iFieldType, 0x8);

	struct NetField
	{
		const char * name; //OFS: 0x0 SIZE: 0x4
		int offset; //OFS: 0x4 SIZE: 0x4
		int bits; //OFS: 0x8 SIZE: 0x4
		int type; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(NetField, 0x10);
	ASSERT_STRUCT_OFFSET(NetField, name, 0x0);
	ASSERT_STRUCT_OFFSET(NetField, offset, 0x4);
	ASSERT_STRUCT_OFFSET(NetField, bits, 0x8);
	ASSERT_STRUCT_OFFSET(NetField, type, 0xC);

	struct constantConfigString
	{
		int configStringNum; //OFS: 0x0 SIZE: 0x4
		char * configString; //OFS: 0x4 SIZE: 0x4
		int configStringHash; //OFS: 0x8 SIZE: 0x4
		int lowercaseConfigStringHash; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(constantConfigString, 0x10);
	ASSERT_STRUCT_OFFSET(constantConfigString, configStringNum, 0x0);
	ASSERT_STRUCT_OFFSET(constantConfigString, configString, 0x4);
	ASSERT_STRUCT_OFFSET(constantConfigString, configStringHash, 0x8);
	ASSERT_STRUCT_OFFSET(constantConfigString, lowercaseConfigStringHash, 0xC);

	struct __declspec(align(2)) _XINPUT_VIBRATION
	{
		unsigned __int16 wLeftMotorSpeed; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 wRightMotorSpeed; //OFS: 0x2 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(_XINPUT_VIBRATION, 0x4);
	ASSERT_STRUCT_OFFSET(_XINPUT_VIBRATION, wLeftMotorSpeed, 0x0);
	ASSERT_STRUCT_OFFSET(_XINPUT_VIBRATION, wRightMotorSpeed, 0x2);

	struct __declspec(align(2)) _XINPUT_GAMEPAD
	{
		WORD wButtons; //OFS: 0x0 SIZE: 0x2
		BYTE bLeftTrigger; //OFS: 0x2 SIZE: 0x1
		BYTE bRightTrigger; //OFS: 0x3 SIZE: 0x1
		SHORT sThumbLX; //OFS: 0x4 SIZE: 0x2
		SHORT sThumbLY; //OFS: 0x6 SIZE: 0x2
		SHORT sThumbRX; //OFS: 0x8 SIZE: 0x2
		SHORT sThumbRY; //OFS: 0xA SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(_XINPUT_GAMEPAD, 0xC);
	ASSERT_STRUCT_OFFSET(_XINPUT_GAMEPAD, wButtons, 0x0);
	ASSERT_STRUCT_OFFSET(_XINPUT_GAMEPAD, bLeftTrigger, 0x2);
	ASSERT_STRUCT_OFFSET(_XINPUT_GAMEPAD, bRightTrigger, 0x3);
	ASSERT_STRUCT_OFFSET(_XINPUT_GAMEPAD, sThumbLX, 0x4);
	ASSERT_STRUCT_OFFSET(_XINPUT_GAMEPAD, sThumbLY, 0x6);
	ASSERT_STRUCT_OFFSET(_XINPUT_GAMEPAD, sThumbRX, 0x8);
	ASSERT_STRUCT_OFFSET(_XINPUT_GAMEPAD, sThumbRY, 0xA);

	struct _XINPUT_STATE
	{
		DWORD dwPacketNumber; //OFS: 0x0 SIZE: 0x4
		_XINPUT_GAMEPAD Gamepad; //OFS: 0x4 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(_XINPUT_STATE, 0x10);
	ASSERT_STRUCT_OFFSET(_XINPUT_STATE, dwPacketNumber, 0x0);
	ASSERT_STRUCT_OFFSET(_XINPUT_STATE, Gamepad, 0x4);

	struct PhysicalMemoryAllocation
	{
		char * name; //OFS: 0x0 SIZE: 0x4
		unsigned int pos; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(PhysicalMemoryAllocation, 0x8);
	ASSERT_STRUCT_OFFSET(PhysicalMemoryAllocation, name, 0x0);
	ASSERT_STRUCT_OFFSET(PhysicalMemoryAllocation, pos, 0x4);

	struct PhysicalMemoryPrim
	{
		char * allocName; //OFS: 0x0 SIZE: 0x4
		unsigned int allocListCount; //OFS: 0x4 SIZE: 0x4
		unsigned int pos; //OFS: 0x8 SIZE: 0x4
		PhysicalMemoryAllocation allocList[32]; //OFS: 0xC SIZE: 0x100
	};
	ASSERT_STRUCT_SIZE(PhysicalMemoryPrim, 0x10C);
	ASSERT_STRUCT_OFFSET(PhysicalMemoryPrim, allocName, 0x0);
	ASSERT_STRUCT_OFFSET(PhysicalMemoryPrim, allocListCount, 0x4);
	ASSERT_STRUCT_OFFSET(PhysicalMemoryPrim, pos, 0x8);
	ASSERT_STRUCT_OFFSET(PhysicalMemoryPrim, allocList, 0xC);

	struct PhysicalMemory
	{
		char * name; //OFS: 0x0 SIZE: 0x4
		unsigned __int8 * buf; //OFS: 0x4 SIZE: 0x4
		PhysicalMemoryPrim prim[2]; //OFS: 0x8 SIZE: 0x218
		unsigned int size; //OFS: 0x220 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(PhysicalMemory, 0x224);
	ASSERT_STRUCT_OFFSET(PhysicalMemory, name, 0x0);
	ASSERT_STRUCT_OFFSET(PhysicalMemory, buf, 0x4);
	ASSERT_STRUCT_OFFSET(PhysicalMemory, prim, 0x8);
	ASSERT_STRUCT_OFFSET(PhysicalMemory, size, 0x220);

	struct fileInIwd_s
	{
		unsigned int pos; //OFS: 0x0 SIZE: 0x4
		char * name; //OFS: 0x4 SIZE: 0x4
		fileInIwd_s * next; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(fileInIwd_s, 0xC);
	ASSERT_STRUCT_OFFSET(fileInIwd_s, pos, 0x0);
	ASSERT_STRUCT_OFFSET(fileInIwd_s, name, 0x4);
	ASSERT_STRUCT_OFFSET(fileInIwd_s, next, 0x8);

	struct iwd_t
	{
		char iwdFilename[256]; //OFS: 0x0 SIZE: 0x100
		char iwdBasename[256]; //OFS: 0x100 SIZE: 0x100
		char iwdGamename[256]; //OFS: 0x200 SIZE: 0x100
		char * handle; //OFS: 0x300 SIZE: 0x4
		int checksum; //OFS: 0x304 SIZE: 0x4
		int pure_checksum; //OFS: 0x308 SIZE: 0x4
		volatile int hasOpenFile; //OFS: 0x30C SIZE: 0x4
		int numfiles; //OFS: 0x310 SIZE: 0x4
		char referenced; //OFS: 0x314 SIZE: 0x1
		unsigned int hashSize; //OFS: 0x318 SIZE: 0x4
		fileInIwd_s ** hashTable; //OFS: 0x31C SIZE: 0x4
		fileInIwd_s * buildBuffer; //OFS: 0x320 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(iwd_t, 0x324);
	ASSERT_STRUCT_OFFSET(iwd_t, iwdFilename, 0x0);
	ASSERT_STRUCT_OFFSET(iwd_t, iwdBasename, 0x100);
	ASSERT_STRUCT_OFFSET(iwd_t, iwdGamename, 0x200);
	ASSERT_STRUCT_OFFSET(iwd_t, handle, 0x300);
	ASSERT_STRUCT_OFFSET(iwd_t, checksum, 0x304);
	ASSERT_STRUCT_OFFSET(iwd_t, pure_checksum, 0x308);
	ASSERT_STRUCT_OFFSET(iwd_t, hasOpenFile, 0x30C);
	ASSERT_STRUCT_OFFSET(iwd_t, numfiles, 0x310);
	ASSERT_STRUCT_OFFSET(iwd_t, referenced, 0x314);
	ASSERT_STRUCT_OFFSET(iwd_t, hashSize, 0x318);
	ASSERT_STRUCT_OFFSET(iwd_t, hashTable, 0x31C);
	ASSERT_STRUCT_OFFSET(iwd_t, buildBuffer, 0x320);

	struct __declspec(align(1)) directory_t
	{
		char path[256]; //OFS: 0x0 SIZE: 0x100
		char gamedir[256]; //OFS: 0x100 SIZE: 0x100
	};
	ASSERT_STRUCT_SIZE(directory_t, 0x200);
	ASSERT_STRUCT_OFFSET(directory_t, path, 0x0);
	ASSERT_STRUCT_OFFSET(directory_t, gamedir, 0x100);

	struct searchpath_s
	{
		searchpath_s * next; //OFS: 0x0 SIZE: 0x4
		iwd_t * iwd; //OFS: 0x4 SIZE: 0x4
		directory_t * dir; //OFS: 0x8 SIZE: 0x4
		int bLocalized; //OFS: 0xC SIZE: 0x4
		int ignore; //OFS: 0x10 SIZE: 0x4
		int ignorePureCheck; //OFS: 0x14 SIZE: 0x4
		int language; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(searchpath_s, 0x1C);
	ASSERT_STRUCT_OFFSET(searchpath_s, next, 0x0);
	ASSERT_STRUCT_OFFSET(searchpath_s, iwd, 0x4);
	ASSERT_STRUCT_OFFSET(searchpath_s, dir, 0x8);
	ASSERT_STRUCT_OFFSET(searchpath_s, bLocalized, 0xC);
	ASSERT_STRUCT_OFFSET(searchpath_s, ignore, 0x10);
	ASSERT_STRUCT_OFFSET(searchpath_s, ignorePureCheck, 0x14);
	ASSERT_STRUCT_OFFSET(searchpath_s, language, 0x18);

	struct __declspec(align(1)) PrintChannel
	{
		char name[32]; //OFS: 0x0 SIZE: 0x20
		bool allowScript; //OFS: 0x20 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(PrintChannel, 0x21);
	ASSERT_STRUCT_OFFSET(PrintChannel, name, 0x0);
	ASSERT_STRUCT_OFFSET(PrintChannel, allowScript, 0x20);

	struct PrintChannelGlob
	{
		PrintChannel openChannels[256]; //OFS: 0x0 SIZE: 0x2100
		unsigned int filters[7][8]; //OFS: 0x2100 SIZE: 0xE0
	};
	ASSERT_STRUCT_SIZE(PrintChannelGlob, 0x21E0);
	ASSERT_STRUCT_OFFSET(PrintChannelGlob, openChannels, 0x0);
	ASSERT_STRUCT_OFFSET(PrintChannelGlob, filters, 0x2100);

	struct weaponParms
	{
		float forward[3]; //OFS: 0x0 SIZE: 0xC
		float right[3]; //OFS: 0xC SIZE: 0xC
		float up[3]; //OFS: 0x18 SIZE: 0xC
		float muzzleTrace[3]; //OFS: 0x24 SIZE: 0xC
		float gunForward[3]; //OFS: 0x30 SIZE: 0xC
		const WeaponDef * weapDef; //OFS: 0x3C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(weaponParms, 0x40);
	ASSERT_STRUCT_OFFSET(weaponParms, forward, 0x0);
	ASSERT_STRUCT_OFFSET(weaponParms, right, 0xC);
	ASSERT_STRUCT_OFFSET(weaponParms, up, 0x18);
	ASSERT_STRUCT_OFFSET(weaponParms, muzzleTrace, 0x24);
	ASSERT_STRUCT_OFFSET(weaponParms, gunForward, 0x30);
	ASSERT_STRUCT_OFFSET(weaponParms, weapDef, 0x3C);

	struct AntilagClientStore
	{
		float realClientPositions[4][3]; //OFS: 0x0 SIZE: 0x30
		bool clientMoved[4]; //OFS: 0x30 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(AntilagClientStore, 0x34);
	ASSERT_STRUCT_OFFSET(AntilagClientStore, realClientPositions, 0x0);
	ASSERT_STRUCT_OFFSET(AntilagClientStore, clientMoved, 0x30);

	struct loadAssets_t
	{
		float fadeClamp; //OFS: 0x0 SIZE: 0x4
		int fadeCycle; //OFS: 0x4 SIZE: 0x4
		float fadeAmount; //OFS: 0x8 SIZE: 0x4
		float fadeInAmount; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(loadAssets_t, 0x10);
	ASSERT_STRUCT_OFFSET(loadAssets_t, fadeClamp, 0x0);
	ASSERT_STRUCT_OFFSET(loadAssets_t, fadeCycle, 0x4);
	ASSERT_STRUCT_OFFSET(loadAssets_t, fadeAmount, 0x8);
	ASSERT_STRUCT_OFFSET(loadAssets_t, fadeInAmount, 0xC);

	struct menu_stuffs
	{
		loadAssets_t loadAssets; //OFS: 0x0 SIZE: 0x10
		MenuList menuList; //OFS: 0x10 SIZE: 0xC
		itemDef_s * items[256]; //OFS: 0x1C SIZE: 0x400
		menuDef_t * menus[512]; //OFS: 0x41C SIZE: 0x800
	};
	ASSERT_STRUCT_SIZE(menu_stuffs, 0xC1C);
	ASSERT_STRUCT_OFFSET(menu_stuffs, loadAssets, 0x0);
	ASSERT_STRUCT_OFFSET(menu_stuffs, menuList, 0x10);
	ASSERT_STRUCT_OFFSET(menu_stuffs, items, 0x1C);
	ASSERT_STRUCT_OFFSET(menu_stuffs, menus, 0x41C);

	struct punctuation_s
	{
		char * p; //OFS: 0x0 SIZE: 0x4
		int n; //OFS: 0x4 SIZE: 0x4
		punctuation_s * next; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(punctuation_s, 0xC);
	ASSERT_STRUCT_OFFSET(punctuation_s, p, 0x0);
	ASSERT_STRUCT_OFFSET(punctuation_s, n, 0x4);
	ASSERT_STRUCT_OFFSET(punctuation_s, next, 0x8);

	struct __declspec(align(8)) token_s
	{
		char string[1024]; //OFS: 0x0 SIZE: 0x400
		int type; //OFS: 0x400 SIZE: 0x4
		int subtype; //OFS: 0x404 SIZE: 0x4
		unsigned int intvalue; //OFS: 0x408 SIZE: 0x4
		long double floatvalue; //OFS: 0x410 SIZE: 0x8
		char * whitespace_p; //OFS: 0x418 SIZE: 0x4
		char * endwhitespace_p; //OFS: 0x41C SIZE: 0x4
		int line; //OFS: 0x420 SIZE: 0x4
		int linescrossed; //OFS: 0x424 SIZE: 0x4
		token_s * next; //OFS: 0x428 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(token_s, 0x430);
	ASSERT_STRUCT_OFFSET(token_s, string, 0x0);
	ASSERT_STRUCT_OFFSET(token_s, type, 0x400);
	ASSERT_STRUCT_OFFSET(token_s, subtype, 0x404);
	ASSERT_STRUCT_OFFSET(token_s, intvalue, 0x408);
	ASSERT_STRUCT_OFFSET(token_s, floatvalue, 0x410);
	ASSERT_STRUCT_OFFSET(token_s, whitespace_p, 0x418);
	ASSERT_STRUCT_OFFSET(token_s, endwhitespace_p, 0x41C);
	ASSERT_STRUCT_OFFSET(token_s, line, 0x420);
	ASSERT_STRUCT_OFFSET(token_s, linescrossed, 0x424);
	ASSERT_STRUCT_OFFSET(token_s, next, 0x428);

	struct __declspec(align(8)) script_s
	{
		char filename[64]; //OFS: 0x0 SIZE: 0x40
		char * buffer; //OFS: 0x40 SIZE: 0x4
		char * script_p; //OFS: 0x44 SIZE: 0x4
		char * end_p; //OFS: 0x48 SIZE: 0x4
		char * lastscript_p; //OFS: 0x4C SIZE: 0x4
		char * whitespace_p; //OFS: 0x50 SIZE: 0x4
		char * endwhitespace_p; //OFS: 0x54 SIZE: 0x4
		int length; //OFS: 0x58 SIZE: 0x4
		int line; //OFS: 0x5C SIZE: 0x4
		int lastline; //OFS: 0x60 SIZE: 0x4
		int tokenavailable; //OFS: 0x64 SIZE: 0x4
		int flags; //OFS: 0x68 SIZE: 0x4
		punctuation_s * punctuations; //OFS: 0x6C SIZE: 0x4
		punctuation_s ** punctuationtable; //OFS: 0x70 SIZE: 0x4
		token_s token; //OFS: 0x78 SIZE: 0x430
		script_s * next; //OFS: 0x4A8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(script_s, 0x4B0);
	ASSERT_STRUCT_OFFSET(script_s, filename, 0x0);
	ASSERT_STRUCT_OFFSET(script_s, buffer, 0x40);
	ASSERT_STRUCT_OFFSET(script_s, script_p, 0x44);
	ASSERT_STRUCT_OFFSET(script_s, end_p, 0x48);
	ASSERT_STRUCT_OFFSET(script_s, lastscript_p, 0x4C);
	ASSERT_STRUCT_OFFSET(script_s, whitespace_p, 0x50);
	ASSERT_STRUCT_OFFSET(script_s, endwhitespace_p, 0x54);
	ASSERT_STRUCT_OFFSET(script_s, length, 0x58);
	ASSERT_STRUCT_OFFSET(script_s, line, 0x5C);
	ASSERT_STRUCT_OFFSET(script_s, lastline, 0x60);
	ASSERT_STRUCT_OFFSET(script_s, tokenavailable, 0x64);
	ASSERT_STRUCT_OFFSET(script_s, flags, 0x68);
	ASSERT_STRUCT_OFFSET(script_s, punctuations, 0x6C);
	ASSERT_STRUCT_OFFSET(script_s, punctuationtable, 0x70);
	ASSERT_STRUCT_OFFSET(script_s, token, 0x78);
	ASSERT_STRUCT_OFFSET(script_s, next, 0x4A8);

	struct define_s
	{
		char * name; //OFS: 0x0 SIZE: 0x4
		int flags; //OFS: 0x4 SIZE: 0x4
		int builtin; //OFS: 0x8 SIZE: 0x4
		int numparms; //OFS: 0xC SIZE: 0x4
		token_s * parms; //OFS: 0x10 SIZE: 0x4
		token_s * tokens; //OFS: 0x14 SIZE: 0x4
		define_s * next; //OFS: 0x18 SIZE: 0x4
		define_s * hashnext; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(define_s, 0x20);
	ASSERT_STRUCT_OFFSET(define_s, name, 0x0);
	ASSERT_STRUCT_OFFSET(define_s, flags, 0x4);
	ASSERT_STRUCT_OFFSET(define_s, builtin, 0x8);
	ASSERT_STRUCT_OFFSET(define_s, numparms, 0xC);
	ASSERT_STRUCT_OFFSET(define_s, parms, 0x10);
	ASSERT_STRUCT_OFFSET(define_s, tokens, 0x14);
	ASSERT_STRUCT_OFFSET(define_s, next, 0x18);
	ASSERT_STRUCT_OFFSET(define_s, hashnext, 0x1C);

	struct indent_s
	{
		int type; //OFS: 0x0 SIZE: 0x4
		parseSkip_t skip; //OFS: 0x4 SIZE: 0x4
		script_s * script; //OFS: 0x8 SIZE: 0x4
		indent_s * next; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(indent_s, 0x10);
	ASSERT_STRUCT_OFFSET(indent_s, type, 0x0);
	ASSERT_STRUCT_OFFSET(indent_s, skip, 0x4);
	ASSERT_STRUCT_OFFSET(indent_s, script, 0x8);
	ASSERT_STRUCT_OFFSET(indent_s, next, 0xC);

	struct __declspec(align(8)) source_s
	{
		char filename[64]; //OFS: 0x0 SIZE: 0x40
		char includepath[64]; //OFS: 0x40 SIZE: 0x40
		punctuation_s * punctuations; //OFS: 0x80 SIZE: 0x4
		script_s * scriptstack; //OFS: 0x84 SIZE: 0x4
		token_s * tokens; //OFS: 0x88 SIZE: 0x4
		define_s * defines; //OFS: 0x8C SIZE: 0x4
		define_s ** definehash; //OFS: 0x90 SIZE: 0x4
		indent_s * indentstack; //OFS: 0x94 SIZE: 0x4
		int skip; //OFS: 0x98 SIZE: 0x4
		token_s token; //OFS: 0xA0 SIZE: 0x430
	};
	ASSERT_STRUCT_SIZE(source_s, 0x4D0);
	ASSERT_STRUCT_OFFSET(source_s, filename, 0x0);
	ASSERT_STRUCT_OFFSET(source_s, includepath, 0x40);
	ASSERT_STRUCT_OFFSET(source_s, punctuations, 0x80);
	ASSERT_STRUCT_OFFSET(source_s, scriptstack, 0x84);
	ASSERT_STRUCT_OFFSET(source_s, tokens, 0x88);
	ASSERT_STRUCT_OFFSET(source_s, defines, 0x8C);
	ASSERT_STRUCT_OFFSET(source_s, definehash, 0x90);
	ASSERT_STRUCT_OFFSET(source_s, indentstack, 0x94);
	ASSERT_STRUCT_OFFSET(source_s, skip, 0x98);
	ASSERT_STRUCT_OFFSET(source_s, token, 0xA0);

	struct pc_token_s
	{
		int type; //OFS: 0x0 SIZE: 0x4
		int subtype; //OFS: 0x4 SIZE: 0x4
		int intvalue; //OFS: 0x8 SIZE: 0x4
		float floatvalue; //OFS: 0xC SIZE: 0x4
		char string[1024]; //OFS: 0x10 SIZE: 0x400
	};
	ASSERT_STRUCT_SIZE(pc_token_s, 0x410);
	ASSERT_STRUCT_OFFSET(pc_token_s, type, 0x0);
	ASSERT_STRUCT_OFFSET(pc_token_s, subtype, 0x4);
	ASSERT_STRUCT_OFFSET(pc_token_s, intvalue, 0x8);
	ASSERT_STRUCT_OFFSET(pc_token_s, floatvalue, 0xC);
	ASSERT_STRUCT_OFFSET(pc_token_s, string, 0x10);

	// uiInfo_s

	struct AimTweakables
	{
		float slowdownRegionWidth; //OFS: 0x0 SIZE: 0x4
		float slowdownRegionHeight; //OFS: 0x4 SIZE: 0x4
		float autoAimRegionWidth; //OFS: 0x8 SIZE: 0x4
		float autoAimRegionHeight; //OFS: 0xC SIZE: 0x4
		float autoMeleeRegionWidth; //OFS: 0x10 SIZE: 0x4
		float autoMeleeRegionHeight; //OFS: 0x14 SIZE: 0x4
		float lockOnRegionWidth; //OFS: 0x18 SIZE: 0x4
		float lockOnRegionHeight; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(AimTweakables, 0x20);
	ASSERT_STRUCT_OFFSET(AimTweakables, slowdownRegionWidth, 0x0);
	ASSERT_STRUCT_OFFSET(AimTweakables, slowdownRegionHeight, 0x4);
	ASSERT_STRUCT_OFFSET(AimTweakables, autoAimRegionWidth, 0x8);
	ASSERT_STRUCT_OFFSET(AimTweakables, autoAimRegionHeight, 0xC);
	ASSERT_STRUCT_OFFSET(AimTweakables, autoMeleeRegionWidth, 0x10);
	ASSERT_STRUCT_OFFSET(AimTweakables, autoMeleeRegionHeight, 0x14);
	ASSERT_STRUCT_OFFSET(AimTweakables, lockOnRegionWidth, 0x18);
	ASSERT_STRUCT_OFFSET(AimTweakables, lockOnRegionHeight, 0x1C);

	struct AimScreenTarget
	{
		int entIndex; //OFS: 0x0 SIZE: 0x4
		float clipMins[2]; //OFS: 0x4 SIZE: 0x8
		float clipMaxs[2]; //OFS: 0xC SIZE: 0x8
		float aimPos[3]; //OFS: 0x14 SIZE: 0xC
		float velocity[3]; //OFS: 0x20 SIZE: 0xC
		float distSqr; //OFS: 0x2C SIZE: 0x4
		float crosshairDistSqr; //OFS: 0x30 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(AimScreenTarget, 0x34);
	ASSERT_STRUCT_OFFSET(AimScreenTarget, entIndex, 0x0);
	ASSERT_STRUCT_OFFSET(AimScreenTarget, clipMins, 0x4);
	ASSERT_STRUCT_OFFSET(AimScreenTarget, clipMaxs, 0xC);
	ASSERT_STRUCT_OFFSET(AimScreenTarget, aimPos, 0x14);
	ASSERT_STRUCT_OFFSET(AimScreenTarget, velocity, 0x20);
	ASSERT_STRUCT_OFFSET(AimScreenTarget, distSqr, 0x2C);
	ASSERT_STRUCT_OFFSET(AimScreenTarget, crosshairDistSqr, 0x30);

	struct AimAssistGlobals
	{
		bool initialized; //OFS: 0x0 SIZE: 0x1
		AimTweakables tweakables; //OFS: 0x4 SIZE: 0x20
		float viewOrigin[3]; //OFS: 0x24 SIZE: 0xC
		float viewAngles[3]; //OFS: 0x30 SIZE: 0xC
		float viewAxis[3][3]; //OFS: 0x3C SIZE: 0x24
		float fovTurnRateScale; //OFS: 0x60 SIZE: 0x4
		float fovScaleInv; //OFS: 0x64 SIZE: 0x4
		float adsLerp; //OFS: 0x68 SIZE: 0x4
		float pitchDelta; //OFS: 0x6C SIZE: 0x4
		float yawDelta; //OFS: 0x70 SIZE: 0x4
		float screenWidth; //OFS: 0x74 SIZE: 0x4
		float screenHeight; //OFS: 0x78 SIZE: 0x4
		float screenMtx[4][4]; //OFS: 0x7C SIZE: 0x40
		float invScreenMtx[4][4]; //OFS: 0xBC SIZE: 0x40
		AimScreenTarget screenTargets[64]; //OFS: 0xFC SIZE: 0xD00
		int screenTargetCount; //OFS: 0xDFC SIZE: 0x4
		int autoAimTargetEnt; //OFS: 0xE00 SIZE: 0x4
		bool autoAimPressed; //OFS: 0xE04 SIZE: 0x1
		bool autoAimActive; //OFS: 0xE05 SIZE: 0x1
		float autoAimPitch; //OFS: 0xE08 SIZE: 0x4
		float autoAimPitchTarget; //OFS: 0xE0C SIZE: 0x4
		float autoAimYaw; //OFS: 0xE10 SIZE: 0x4
		float autoAimYawTarget; //OFS: 0xE14 SIZE: 0x4
		bool autoAimJustGotTarget; //OFS: 0xE18 SIZE: 0x1
		bool autoAimHasRealTarget; //OFS: 0xE19 SIZE: 0x1
		bool aimSlowdownActive; //OFS: 0xE1A SIZE: 0x1
		int aimSlowdownTargetEnt; //OFS: 0xE1C SIZE: 0x4
		int autoMeleeTargetEnt; //OFS: 0xE20 SIZE: 0x4
		eAutoMeleeState autoMeleeState; //OFS: 0xE24 SIZE: 0x4
		float autoMeleePitch; //OFS: 0xE28 SIZE: 0x4
		float autoMeleePitchTarget; //OFS: 0xE2C SIZE: 0x4
		float autoMeleeYaw; //OFS: 0xE30 SIZE: 0x4
		float autoMeleeYawTarget; //OFS: 0xE34 SIZE: 0x4
		int lockOnTargetEnt; //OFS: 0xE38 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(AimAssistGlobals, 0xE3C);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, initialized, 0x0);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, tweakables, 0x4);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, viewOrigin, 0x24);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, viewAngles, 0x30);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, viewAxis, 0x3C);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, fovTurnRateScale, 0x60);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, fovScaleInv, 0x64);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, adsLerp, 0x68);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, pitchDelta, 0x6C);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, yawDelta, 0x70);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, screenWidth, 0x74);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, screenHeight, 0x78);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, screenMtx, 0x7C);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, invScreenMtx, 0xBC);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, screenTargets, 0xFC);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, screenTargetCount, 0xDFC);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, autoAimTargetEnt, 0xE00);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, autoAimPressed, 0xE04);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, autoAimActive, 0xE05);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, autoAimPitch, 0xE08);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, autoAimPitchTarget, 0xE0C);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, autoAimYaw, 0xE10);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, autoAimYawTarget, 0xE14);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, autoAimJustGotTarget, 0xE18);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, autoAimHasRealTarget, 0xE19);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, aimSlowdownActive, 0xE1A);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, aimSlowdownTargetEnt, 0xE1C);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, autoMeleeTargetEnt, 0xE20);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, autoMeleeState, 0xE24);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, autoMeleePitch, 0xE28);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, autoMeleePitchTarget, 0xE2C);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, autoMeleeYaw, 0xE30);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, autoMeleeYawTarget, 0xE34);
	ASSERT_STRUCT_OFFSET(AimAssistGlobals, lockOnTargetEnt, 0xE38);

	struct AimInput
	{
		int deltaTime; //OFS: 0x0 SIZE: 0x4
		float pitch; //OFS: 0x4 SIZE: 0x4
		float pitchAxis; //OFS: 0x8 SIZE: 0x4
		float pitchMax; //OFS: 0xC SIZE: 0x4
		float yaw; //OFS: 0x10 SIZE: 0x4
		float yawAxis; //OFS: 0x14 SIZE: 0x4
		float yawMax; //OFS: 0x18 SIZE: 0x4
		int forwardAxis; //OFS: 0x1C SIZE: 0x4
		int rightAxis; //OFS: 0x20 SIZE: 0x4
		int buttons; //OFS: 0x24 SIZE: 0x4
		int localClientNum; //OFS: 0x28 SIZE: 0x4
		playerState_s * ps; //OFS: 0x2C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(AimInput, 0x30);
	ASSERT_STRUCT_OFFSET(AimInput, deltaTime, 0x0);
	ASSERT_STRUCT_OFFSET(AimInput, pitch, 0x4);
	ASSERT_STRUCT_OFFSET(AimInput, pitchAxis, 0x8);
	ASSERT_STRUCT_OFFSET(AimInput, pitchMax, 0xC);
	ASSERT_STRUCT_OFFSET(AimInput, yaw, 0x10);
	ASSERT_STRUCT_OFFSET(AimInput, yawAxis, 0x14);
	ASSERT_STRUCT_OFFSET(AimInput, yawMax, 0x18);
	ASSERT_STRUCT_OFFSET(AimInput, forwardAxis, 0x1C);
	ASSERT_STRUCT_OFFSET(AimInput, rightAxis, 0x20);
	ASSERT_STRUCT_OFFSET(AimInput, buttons, 0x24);
	ASSERT_STRUCT_OFFSET(AimInput, localClientNum, 0x28);
	ASSERT_STRUCT_OFFSET(AimInput, ps, 0x2C);

	struct AimOutput
	{
		float pitch; //OFS: 0x0 SIZE: 0x4
		float yaw; //OFS: 0x4 SIZE: 0x4
		int meleeChargeYaw; //OFS: 0x8 SIZE: 0x4
		int meleeChargeDist; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(AimOutput, 0x10);
	ASSERT_STRUCT_OFFSET(AimOutput, pitch, 0x0);
	ASSERT_STRUCT_OFFSET(AimOutput, yaw, 0x4);
	ASSERT_STRUCT_OFFSET(AimOutput, meleeChargeYaw, 0x8);
	ASSERT_STRUCT_OFFSET(AimOutput, meleeChargeDist, 0xC);

	struct struc_16A3BA0
	{
		int field_0; //OFS: 0x0 SIZE: 0x4
		int field_4[512]; //OFS: 0x4 SIZE: 0x800
		char field_804[512]; //OFS: 0x804 SIZE: 0x200
		void * field_A04; //OFS: 0xA04 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(struc_16A3BA0, 0xA08);
	ASSERT_STRUCT_OFFSET(struc_16A3BA0, field_0, 0x0);
	ASSERT_STRUCT_OFFSET(struc_16A3BA0, field_4, 0x4);
	ASSERT_STRUCT_OFFSET(struc_16A3BA0, field_804, 0x804);
	ASSERT_STRUCT_OFFSET(struc_16A3BA0, field_A04, 0xA04);

	struct SpawnFuncEntry
	{
		const char * classname; //OFS: 0x0 SIZE: 0x4
		void (__cdecl *callback)(gentity_s *); //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SpawnFuncEntry, 0x8);
	ASSERT_STRUCT_OFFSET(SpawnFuncEntry, classname, 0x0);
	ASSERT_STRUCT_OFFSET(SpawnFuncEntry, callback, 0x4);

	struct ScriptFunctions
	{
		int maxSize; //OFS: 0x0 SIZE: 0x4
		int count; //OFS: 0x4 SIZE: 0x4
		int * address; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ScriptFunctions, 0xC);
	ASSERT_STRUCT_OFFSET(ScriptFunctions, maxSize, 0x0);
	ASSERT_STRUCT_OFFSET(ScriptFunctions, count, 0x4);
	ASSERT_STRUCT_OFFSET(ScriptFunctions, address, 0x8);

	struct StreamDelayInfo
	{
		const void * ptr; //OFS: 0x0 SIZE: 0x4
		int size; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(StreamDelayInfo, 0x8);
	ASSERT_STRUCT_OFFSET(StreamDelayInfo, ptr, 0x0);
	ASSERT_STRUCT_OFFSET(StreamDelayInfo, size, 0x4);

	union ct_data_s_fc
	{
		unsigned __int16 freq; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 code; //OFS: 0x1 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(ct_data_s_fc, 0x2);

	union ct_data_s_dl
	{
		unsigned __int16 dad; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 len; //OFS: 0x1 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(ct_data_s_dl, 0x2);

	struct __declspec(align(2)) ct_data_s
	{
		ct_data_s_fc fc; //OFS: 0x0 SIZE: 0x2
		ct_data_s_dl _dl; //OFS: 0x2 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(ct_data_s, 0x4);
	ASSERT_STRUCT_OFFSET(ct_data_s, fc, 0x0);
	ASSERT_STRUCT_OFFSET(ct_data_s, _dl, 0x2);

	struct static_tree_desc_s
	{
		const ct_data_s * static_tree; //OFS: 0x0 SIZE: 0x4
		const int * extra_bits; //OFS: 0x4 SIZE: 0x4
		int extra_base; //OFS: 0x8 SIZE: 0x4
		int elems; //OFS: 0xC SIZE: 0x4
		int max_length; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(static_tree_desc_s, 0x14);
	ASSERT_STRUCT_OFFSET(static_tree_desc_s, static_tree, 0x0);
	ASSERT_STRUCT_OFFSET(static_tree_desc_s, extra_bits, 0x4);
	ASSERT_STRUCT_OFFSET(static_tree_desc_s, extra_base, 0x8);
	ASSERT_STRUCT_OFFSET(static_tree_desc_s, elems, 0xC);
	ASSERT_STRUCT_OFFSET(static_tree_desc_s, max_length, 0x10);

	struct tree_desc_s
	{
		ct_data_s * dyn_tree; //OFS: 0x0 SIZE: 0x4
		int max_code; //OFS: 0x4 SIZE: 0x4
		static_tree_desc_s * stat_desc; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(tree_desc_s, 0xC);
	ASSERT_STRUCT_OFFSET(tree_desc_s, dyn_tree, 0x0);
	ASSERT_STRUCT_OFFSET(tree_desc_s, max_code, 0x4);
	ASSERT_STRUCT_OFFSET(tree_desc_s, stat_desc, 0x8);

	struct deflate_state
	{
		z_stream_s * strm; //OFS: 0x0 SIZE: 0x4
		int status; //OFS: 0x4 SIZE: 0x4
		unsigned __int8 * pending_buf; //OFS: 0x8 SIZE: 0x4
		unsigned int pending_buf_size; //OFS: 0xC SIZE: 0x4
		unsigned __int8 * pending_out; //OFS: 0x10 SIZE: 0x4
		int pending; //OFS: 0x14 SIZE: 0x4
		int noheader; //OFS: 0x18 SIZE: 0x4
		unsigned __int8 data_type; //OFS: 0x1C SIZE: 0x1
		unsigned __int8 method; //OFS: 0x1D SIZE: 0x1
		int last_flush; //OFS: 0x20 SIZE: 0x4
		unsigned int w_size; //OFS: 0x24 SIZE: 0x4
		unsigned int w_bits; //OFS: 0x28 SIZE: 0x4
		unsigned int w_mask; //OFS: 0x2C SIZE: 0x4
		unsigned __int8 * window; //OFS: 0x30 SIZE: 0x4
		unsigned int window_size; //OFS: 0x34 SIZE: 0x4
		unsigned __int16 * prev; //OFS: 0x38 SIZE: 0x4
		unsigned __int16 * head; //OFS: 0x3C SIZE: 0x4
		unsigned int ins_h; //OFS: 0x40 SIZE: 0x4
		unsigned int hash_size; //OFS: 0x44 SIZE: 0x4
		unsigned int hash_bits; //OFS: 0x48 SIZE: 0x4
		unsigned int hash_mask; //OFS: 0x4C SIZE: 0x4
		unsigned int hash_shift; //OFS: 0x50 SIZE: 0x4
		int block_start; //OFS: 0x54 SIZE: 0x4
		unsigned int match_length; //OFS: 0x58 SIZE: 0x4
		unsigned int prev_match; //OFS: 0x5C SIZE: 0x4
		int match_available; //OFS: 0x60 SIZE: 0x4
		unsigned int strstart; //OFS: 0x64 SIZE: 0x4
		unsigned int match_start; //OFS: 0x68 SIZE: 0x4
		unsigned int lookahead; //OFS: 0x6C SIZE: 0x4
		unsigned int prev_length; //OFS: 0x70 SIZE: 0x4
		unsigned int max_chain_length; //OFS: 0x74 SIZE: 0x4
		unsigned int max_lazy_match; //OFS: 0x78 SIZE: 0x4
		int level; //OFS: 0x7C SIZE: 0x4
		int strategy; //OFS: 0x80 SIZE: 0x4
		unsigned int good_match; //OFS: 0x84 SIZE: 0x4
		int nice_match; //OFS: 0x88 SIZE: 0x4
		ct_data_s dyn_ltree[573]; //OFS: 0x8C SIZE: 0x8F4
		ct_data_s dyn_dtree[61]; //OFS: 0x980 SIZE: 0xF4
		ct_data_s bl_tree[39]; //OFS: 0xA74 SIZE: 0x9C
		tree_desc_s l_desc; //OFS: 0xB10 SIZE: 0xC
		tree_desc_s d_desc; //OFS: 0xB1C SIZE: 0xC
		tree_desc_s bl_desc; //OFS: 0xB28 SIZE: 0xC
		unsigned __int16 bl_count[16]; //OFS: 0xB34 SIZE: 0x20
		int heap[573]; //OFS: 0xB54 SIZE: 0x8F4
		int heap_len; //OFS: 0x1448 SIZE: 0x4
		int heap_max; //OFS: 0x144C SIZE: 0x4
		unsigned __int8 depth[573]; //OFS: 0x1450 SIZE: 0x23D
		unsigned __int8 * l_buf; //OFS: 0x1690 SIZE: 0x4
		unsigned int lit_bufsize; //OFS: 0x1694 SIZE: 0x4
		unsigned int last_lit; //OFS: 0x1698 SIZE: 0x4
		unsigned __int16 * d_buf; //OFS: 0x169C SIZE: 0x4
		unsigned int opt_len; //OFS: 0x16A0 SIZE: 0x4
		unsigned int static_len; //OFS: 0x16A4 SIZE: 0x4
		unsigned int matches; //OFS: 0x16A8 SIZE: 0x4
		int last_eob_len; //OFS: 0x16AC SIZE: 0x4
		unsigned __int16 bi_buf; //OFS: 0x16B0 SIZE: 0x2
		int bi_valid; //OFS: 0x16B4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(deflate_state, 0x16B8);
	ASSERT_STRUCT_OFFSET(deflate_state, strm, 0x0);
	ASSERT_STRUCT_OFFSET(deflate_state, status, 0x4);
	ASSERT_STRUCT_OFFSET(deflate_state, pending_buf, 0x8);
	ASSERT_STRUCT_OFFSET(deflate_state, pending_buf_size, 0xC);
	ASSERT_STRUCT_OFFSET(deflate_state, pending_out, 0x10);
	ASSERT_STRUCT_OFFSET(deflate_state, pending, 0x14);
	ASSERT_STRUCT_OFFSET(deflate_state, noheader, 0x18);
	ASSERT_STRUCT_OFFSET(deflate_state, data_type, 0x1C);
	ASSERT_STRUCT_OFFSET(deflate_state, method, 0x1D);
	ASSERT_STRUCT_OFFSET(deflate_state, last_flush, 0x20);
	ASSERT_STRUCT_OFFSET(deflate_state, w_size, 0x24);
	ASSERT_STRUCT_OFFSET(deflate_state, w_bits, 0x28);
	ASSERT_STRUCT_OFFSET(deflate_state, w_mask, 0x2C);
	ASSERT_STRUCT_OFFSET(deflate_state, window, 0x30);
	ASSERT_STRUCT_OFFSET(deflate_state, window_size, 0x34);
	ASSERT_STRUCT_OFFSET(deflate_state, prev, 0x38);
	ASSERT_STRUCT_OFFSET(deflate_state, head, 0x3C);
	ASSERT_STRUCT_OFFSET(deflate_state, ins_h, 0x40);
	ASSERT_STRUCT_OFFSET(deflate_state, hash_size, 0x44);
	ASSERT_STRUCT_OFFSET(deflate_state, hash_bits, 0x48);
	ASSERT_STRUCT_OFFSET(deflate_state, hash_mask, 0x4C);
	ASSERT_STRUCT_OFFSET(deflate_state, hash_shift, 0x50);
	ASSERT_STRUCT_OFFSET(deflate_state, block_start, 0x54);
	ASSERT_STRUCT_OFFSET(deflate_state, match_length, 0x58);
	ASSERT_STRUCT_OFFSET(deflate_state, prev_match, 0x5C);
	ASSERT_STRUCT_OFFSET(deflate_state, match_available, 0x60);
	ASSERT_STRUCT_OFFSET(deflate_state, strstart, 0x64);
	ASSERT_STRUCT_OFFSET(deflate_state, match_start, 0x68);
	ASSERT_STRUCT_OFFSET(deflate_state, lookahead, 0x6C);
	ASSERT_STRUCT_OFFSET(deflate_state, prev_length, 0x70);
	ASSERT_STRUCT_OFFSET(deflate_state, max_chain_length, 0x74);
	ASSERT_STRUCT_OFFSET(deflate_state, max_lazy_match, 0x78);
	ASSERT_STRUCT_OFFSET(deflate_state, level, 0x7C);
	ASSERT_STRUCT_OFFSET(deflate_state, strategy, 0x80);
	ASSERT_STRUCT_OFFSET(deflate_state, good_match, 0x84);
	ASSERT_STRUCT_OFFSET(deflate_state, nice_match, 0x88);
	ASSERT_STRUCT_OFFSET(deflate_state, dyn_ltree, 0x8C);
	ASSERT_STRUCT_OFFSET(deflate_state, dyn_dtree, 0x980);
	ASSERT_STRUCT_OFFSET(deflate_state, bl_tree, 0xA74);
	ASSERT_STRUCT_OFFSET(deflate_state, l_desc, 0xB10);
	ASSERT_STRUCT_OFFSET(deflate_state, d_desc, 0xB1C);
	ASSERT_STRUCT_OFFSET(deflate_state, bl_desc, 0xB28);
	ASSERT_STRUCT_OFFSET(deflate_state, bl_count, 0xB34);
	ASSERT_STRUCT_OFFSET(deflate_state, heap, 0xB54);
	ASSERT_STRUCT_OFFSET(deflate_state, heap_len, 0x1448);
	ASSERT_STRUCT_OFFSET(deflate_state, heap_max, 0x144C);
	ASSERT_STRUCT_OFFSET(deflate_state, depth, 0x1450);
	ASSERT_STRUCT_OFFSET(deflate_state, l_buf, 0x1690);
	ASSERT_STRUCT_OFFSET(deflate_state, lit_bufsize, 0x1694);
	ASSERT_STRUCT_OFFSET(deflate_state, last_lit, 0x1698);
	ASSERT_STRUCT_OFFSET(deflate_state, d_buf, 0x169C);
	ASSERT_STRUCT_OFFSET(deflate_state, opt_len, 0x16A0);
	ASSERT_STRUCT_OFFSET(deflate_state, static_len, 0x16A4);
	ASSERT_STRUCT_OFFSET(deflate_state, matches, 0x16A8);
	ASSERT_STRUCT_OFFSET(deflate_state, last_eob_len, 0x16AC);
	ASSERT_STRUCT_OFFSET(deflate_state, bi_buf, 0x16B0);
	ASSERT_STRUCT_OFFSET(deflate_state, bi_valid, 0x16B4);

	struct internal_state_sub_check
	{
		unsigned int was; //OFS: 0x0 SIZE: 0x4
		unsigned int need; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(internal_state_sub_check, 0x8);
	ASSERT_STRUCT_OFFSET(internal_state_sub_check, was, 0x0);
	ASSERT_STRUCT_OFFSET(internal_state_sub_check, need, 0x4);

	union internal_state_sub
	{
		unsigned int method; //OFS: 0x0 SIZE: 0x4
		internal_state_sub_check check; //OFS: 0x1 SIZE: 0x8
		unsigned int marker; //OFS: 0x2 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(internal_state_sub, 0x8);

	struct __declspec(align(1)) inflate_huft_s_word_what
	{
		unsigned __int8 Exop; //OFS: 0x0 SIZE: 0x1
		unsigned __int8 Bits; //OFS: 0x1 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(inflate_huft_s_word_what, 0x2);
	ASSERT_STRUCT_OFFSET(inflate_huft_s_word_what, Exop, 0x0);
	ASSERT_STRUCT_OFFSET(inflate_huft_s_word_what, Bits, 0x1);

	union inflate_huft_s_word
	{
		inflate_huft_s_word_what what; //OFS: 0x0 SIZE: 0x2
		unsigned int pad; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(inflate_huft_s_word, 0x4);

	struct inflate_huft_s
	{
		inflate_huft_s_word word; //OFS: 0x0 SIZE: 0x4
		unsigned int base; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(inflate_huft_s, 0x8);
	ASSERT_STRUCT_OFFSET(inflate_huft_s, word, 0x0);
	ASSERT_STRUCT_OFFSET(inflate_huft_s, base, 0x4);

	struct inflate_blocks_state_sub_trees
	{
		unsigned int table; //OFS: 0x0 SIZE: 0x4
		unsigned int index; //OFS: 0x4 SIZE: 0x4
		unsigned int * blens; //OFS: 0x8 SIZE: 0x4
		unsigned int bb; //OFS: 0xC SIZE: 0x4
		inflate_huft_s * tb; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(inflate_blocks_state_sub_trees, 0x14);
	ASSERT_STRUCT_OFFSET(inflate_blocks_state_sub_trees, table, 0x0);
	ASSERT_STRUCT_OFFSET(inflate_blocks_state_sub_trees, index, 0x4);
	ASSERT_STRUCT_OFFSET(inflate_blocks_state_sub_trees, blens, 0x8);
	ASSERT_STRUCT_OFFSET(inflate_blocks_state_sub_trees, bb, 0xC);
	ASSERT_STRUCT_OFFSET(inflate_blocks_state_sub_trees, tb, 0x10);

	struct inflate_codes_state_sub_code
	{
		inflate_huft_s * tree; //OFS: 0x0 SIZE: 0x4
		unsigned int need; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(inflate_codes_state_sub_code, 0x8);
	ASSERT_STRUCT_OFFSET(inflate_codes_state_sub_code, tree, 0x0);
	ASSERT_STRUCT_OFFSET(inflate_codes_state_sub_code, need, 0x4);

	struct inflate_codes_state_sub_copy
	{
		unsigned int get; //OFS: 0x0 SIZE: 0x4
		unsigned int dist; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(inflate_codes_state_sub_copy, 0x8);
	ASSERT_STRUCT_OFFSET(inflate_codes_state_sub_copy, get, 0x0);
	ASSERT_STRUCT_OFFSET(inflate_codes_state_sub_copy, dist, 0x4);

	union inflate_codes_state_sub
	{
		struct inflate_codes_state_sub_code code; //OFS: 0x0 SIZE: 0x8
		struct inflate_codes_state_sub_copy copy; //OFS: 0x1 SIZE: 0x8
		unsigned int lit; //OFS: 0x2 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(inflate_codes_state_sub, 0x8);

	struct inflate_codes_state
	{
		int mode; //OFS: 0x0 SIZE: 0x4
		int len; //OFS: 0x4 SIZE: 0x4
		inflate_codes_state_sub sub; //OFS: 0x8 SIZE: 0x8
		char lbits; //OFS: 0x10 SIZE: 0x1
		char dbits; //OFS: 0x11 SIZE: 0x1
		inflate_huft_s * ltree; //OFS: 0x14 SIZE: 0x4
		inflate_huft_s * dtree; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(inflate_codes_state, 0x1C);
	ASSERT_STRUCT_OFFSET(inflate_codes_state, mode, 0x0);
	ASSERT_STRUCT_OFFSET(inflate_codes_state, len, 0x4);
	ASSERT_STRUCT_OFFSET(inflate_codes_state, sub, 0x8);
	ASSERT_STRUCT_OFFSET(inflate_codes_state, lbits, 0x10);
	ASSERT_STRUCT_OFFSET(inflate_codes_state, dbits, 0x11);
	ASSERT_STRUCT_OFFSET(inflate_codes_state, ltree, 0x14);
	ASSERT_STRUCT_OFFSET(inflate_codes_state, dtree, 0x18);

	struct inflate_blocks_state_sub_decode
	{
		inflate_codes_state * codes; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(inflate_blocks_state_sub_decode, 0x4);
	ASSERT_STRUCT_OFFSET(inflate_blocks_state_sub_decode, codes, 0x0);

	union inflate_blocks_state_sub
	{
		unsigned int left; //OFS: 0x0 SIZE: 0x4
		inflate_blocks_state_sub_trees trees; //OFS: 0x1 SIZE: 0x14
		inflate_blocks_state_sub_decode decode; //OFS: 0x2 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(inflate_blocks_state_sub, 0x14);

	struct inflate_blocks_state
	{
		inflate_block_mode mode; //OFS: 0x0 SIZE: 0x4
		inflate_blocks_state_sub sub; //OFS: 0x4 SIZE: 0x14
		unsigned int last; //OFS: 0x18 SIZE: 0x4
		unsigned int bitk; //OFS: 0x1C SIZE: 0x4
		unsigned int bitb; //OFS: 0x20 SIZE: 0x4
		inflate_huft_s * hufts; //OFS: 0x24 SIZE: 0x4
		unsigned __int8 * window; //OFS: 0x28 SIZE: 0x4
		unsigned __int8 * end; //OFS: 0x2C SIZE: 0x4
		unsigned __int8 * read; //OFS: 0x30 SIZE: 0x4
		unsigned __int8 * write; //OFS: 0x34 SIZE: 0x4
		unsigned int (__cdecl *checkfn)(unsigned int, const unsigned __int8 *, unsigned int); //OFS: 0x38 SIZE: 0x4
		int check; //OFS: 0x3C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(inflate_blocks_state, 0x40);
	ASSERT_STRUCT_OFFSET(inflate_blocks_state, mode, 0x0);
	ASSERT_STRUCT_OFFSET(inflate_blocks_state, sub, 0x4);
	ASSERT_STRUCT_OFFSET(inflate_blocks_state, last, 0x18);
	ASSERT_STRUCT_OFFSET(inflate_blocks_state, bitk, 0x1C);
	ASSERT_STRUCT_OFFSET(inflate_blocks_state, bitb, 0x20);
	ASSERT_STRUCT_OFFSET(inflate_blocks_state, hufts, 0x24);
	ASSERT_STRUCT_OFFSET(inflate_blocks_state, window, 0x28);
	ASSERT_STRUCT_OFFSET(inflate_blocks_state, end, 0x2C);
	ASSERT_STRUCT_OFFSET(inflate_blocks_state, read, 0x30);
	ASSERT_STRUCT_OFFSET(inflate_blocks_state, write, 0x34);
	ASSERT_STRUCT_OFFSET(inflate_blocks_state, checkfn, 0x38);
	ASSERT_STRUCT_OFFSET(inflate_blocks_state, check, 0x3C);

	typedef inflate_block_mode inflate_mode;

	struct internal_state
	{
		inflate_mode mode; //OFS: 0x0 SIZE: 0x4
		internal_state_sub sub; //OFS: 0x4 SIZE: 0x8
		int nowrap; //OFS: 0xC SIZE: 0x4
		unsigned int wbits; //OFS: 0x10 SIZE: 0x4
		inflate_blocks_state * blocks; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(internal_state, 0x18);
	ASSERT_STRUCT_OFFSET(internal_state, mode, 0x0);
	ASSERT_STRUCT_OFFSET(internal_state, sub, 0x4);
	ASSERT_STRUCT_OFFSET(internal_state, nowrap, 0xC);
	ASSERT_STRUCT_OFFSET(internal_state, wbits, 0x10);
	ASSERT_STRUCT_OFFSET(internal_state, blocks, 0x14);

	union deflate_or_inflate_state
	{
		deflate_state * deflate_state; //OFS: 0x0 SIZE: 0x4
		internal_state * inflate_state; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(deflate_or_inflate_state, 0x4);

	struct z_stream_s
	{
		unsigned __int8 * next_in; //OFS: 0x0 SIZE: 0x4
		unsigned int avail_in; //OFS: 0x4 SIZE: 0x4
		unsigned int total_in; //OFS: 0x8 SIZE: 0x4
		unsigned __int8 * next_out; //OFS: 0xC SIZE: 0x4
		unsigned int avail_out; //OFS: 0x10 SIZE: 0x4
		unsigned int total_out; //OFS: 0x14 SIZE: 0x4
		char * msg; //OFS: 0x18 SIZE: 0x4
		deflate_or_inflate_state state; //OFS: 0x1C SIZE: 0x4
		unsigned __int8 *(__cdecl *zalloc)(unsigned __int8 *opaque, unsigned int items, unsigned int size); //OFS: 0x20 SIZE: 0x4
		void (__cdecl *zfree)(unsigned __int8 *opaque, unsigned __int8 *address); //OFS: 0x24 SIZE: 0x4
		unsigned __int8 * opaque; //OFS: 0x28 SIZE: 0x4
		int data_type; //OFS: 0x2C SIZE: 0x4
		int adler; //OFS: 0x30 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(z_stream_s, 0x34);
	ASSERT_STRUCT_OFFSET(z_stream_s, next_in, 0x0);
	ASSERT_STRUCT_OFFSET(z_stream_s, avail_in, 0x4);
	ASSERT_STRUCT_OFFSET(z_stream_s, total_in, 0x8);
	ASSERT_STRUCT_OFFSET(z_stream_s, next_out, 0xC);
	ASSERT_STRUCT_OFFSET(z_stream_s, avail_out, 0x10);
	ASSERT_STRUCT_OFFSET(z_stream_s, total_out, 0x14);
	ASSERT_STRUCT_OFFSET(z_stream_s, msg, 0x18);
	ASSERT_STRUCT_OFFSET(z_stream_s, state, 0x1C);
	ASSERT_STRUCT_OFFSET(z_stream_s, zalloc, 0x20);
	ASSERT_STRUCT_OFFSET(z_stream_s, zfree, 0x24);
	ASSERT_STRUCT_OFFSET(z_stream_s, opaque, 0x28);
	ASSERT_STRUCT_OFFSET(z_stream_s, data_type, 0x2C);
	ASSERT_STRUCT_OFFSET(z_stream_s, adler, 0x30);

	struct DB_LoadData
	{
		void * f; //OFS: 0x0 SIZE: 0x4
		char * filename; //OFS: 0x4 SIZE: 0x4
		XBlock * blocks; //OFS: 0x8 SIZE: 0x4
		int outstandingReads; //OFS: 0xC SIZE: 0x4
		_OVERLAPPED overlapped; //OFS: 0x10 SIZE: 0x14
		z_stream_s stream; //OFS: 0x24 SIZE: 0x34
		char * compressBufferStart; //OFS: 0x58 SIZE: 0x4
		void * compressBufferEnd; //OFS: 0x5C SIZE: 0x4
		void (__cdecl *interrupt)(); //OFS: 0x60 SIZE: 0x4
		int allocType; //OFS: 0x64 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DB_LoadData, 0x68);
	ASSERT_STRUCT_OFFSET(DB_LoadData, f, 0x0);
	ASSERT_STRUCT_OFFSET(DB_LoadData, filename, 0x4);
	ASSERT_STRUCT_OFFSET(DB_LoadData, blocks, 0x8);
	ASSERT_STRUCT_OFFSET(DB_LoadData, outstandingReads, 0xC);
	ASSERT_STRUCT_OFFSET(DB_LoadData, overlapped, 0x10);
	ASSERT_STRUCT_OFFSET(DB_LoadData, stream, 0x24);
	ASSERT_STRUCT_OFFSET(DB_LoadData, compressBufferStart, 0x58);
	ASSERT_STRUCT_OFFSET(DB_LoadData, compressBufferEnd, 0x5C);
	ASSERT_STRUCT_OFFSET(DB_LoadData, interrupt, 0x60);
	ASSERT_STRUCT_OFFSET(DB_LoadData, allocType, 0x64);

	struct areaParms_t
	{
		const float * mins; //OFS: 0x0 SIZE: 0x4
		const float * maxs; //OFS: 0x4 SIZE: 0x4
		int * list; //OFS: 0x8 SIZE: 0x4
		int count; //OFS: 0xC SIZE: 0x4
		int maxcount; //OFS: 0x10 SIZE: 0x4
		int contentmask; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(areaParms_t, 0x18);
	ASSERT_STRUCT_OFFSET(areaParms_t, mins, 0x0);
	ASSERT_STRUCT_OFFSET(areaParms_t, maxs, 0x4);
	ASSERT_STRUCT_OFFSET(areaParms_t, list, 0x8);
	ASSERT_STRUCT_OFFSET(areaParms_t, count, 0xC);
	ASSERT_STRUCT_OFFSET(areaParms_t, maxcount, 0x10);
	ASSERT_STRUCT_OFFSET(areaParms_t, contentmask, 0x14);

	struct useList_t
	{
		gentity_s * ent; //OFS: 0x0 SIZE: 0x4
		float score; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(useList_t, 0x8);
	ASSERT_STRUCT_OFFSET(useList_t, ent, 0x0);
	ASSERT_STRUCT_OFFSET(useList_t, score, 0x4);

	struct NodeTypeToName
	{
		nodeType type; //OFS: 0x0 SIZE: 0x4
		const char * name; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(NodeTypeToName, 0x8);
	ASSERT_STRUCT_OFFSET(NodeTypeToName, type, 0x0);
	ASSERT_STRUCT_OFFSET(NodeTypeToName, name, 0x4);

	struct pathnode_field_t
	{
		const char * name; //OFS: 0x0 SIZE: 0x4
		int ofs; //OFS: 0x4 SIZE: 0x4
		fieldtype_t type; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(pathnode_field_t, 0xC);
	ASSERT_STRUCT_OFFSET(pathnode_field_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(pathnode_field_t, ofs, 0x4);
	ASSERT_STRUCT_OFFSET(pathnode_field_t, type, 0x8);

	struct badplace_arc_t
	{
		float origin[3]; //OFS: 0x0 SIZE: 0xC
		float radius; //OFS: 0xC SIZE: 0x4
		float halfheight; //OFS: 0x10 SIZE: 0x4
		float angle0; //OFS: 0x14 SIZE: 0x4
		float angle1; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(badplace_arc_t, 0x1C);
	ASSERT_STRUCT_OFFSET(badplace_arc_t, origin, 0x0);
	ASSERT_STRUCT_OFFSET(badplace_arc_t, radius, 0xC);
	ASSERT_STRUCT_OFFSET(badplace_arc_t, halfheight, 0x10);
	ASSERT_STRUCT_OFFSET(badplace_arc_t, angle0, 0x14);
	ASSERT_STRUCT_OFFSET(badplace_arc_t, angle1, 0x18);

	struct badplace_brush_t
	{
		gentity_s * volume; //OFS: 0x0 SIZE: 0x4
		float radius; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(badplace_brush_t, 0x8);
	ASSERT_STRUCT_OFFSET(badplace_brush_t, volume, 0x0);
	ASSERT_STRUCT_OFFSET(badplace_brush_t, radius, 0x4);

	union badplace_parms_t
	{
		badplace_arc_t arc; //OFS: 0x0 SIZE: 0x1C
		badplace_brush_t brush; //OFS: 0x1 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(badplace_parms_t, 0x1C);

	struct badplace_t
	{
		int endtime; //OFS: 0x0 SIZE: 0x4
		int pingTime; //OFS: 0x4 SIZE: 0x4
		unsigned __int16 name; //OFS: 0x8 SIZE: 0x2
		unsigned __int8 type; //OFS: 0xA SIZE: 0x1
		unsigned __int8 teamflags; //OFS: 0xB SIZE: 0x1
		int depth; //OFS: 0xC SIZE: 0x4
		badplace_parms_t parms; //OFS: 0x10 SIZE: 0x1C
	};
	ASSERT_STRUCT_SIZE(badplace_t, 0x2C);
	ASSERT_STRUCT_OFFSET(badplace_t, endtime, 0x0);
	ASSERT_STRUCT_OFFSET(badplace_t, pingTime, 0x4);
	ASSERT_STRUCT_OFFSET(badplace_t, name, 0x8);
	ASSERT_STRUCT_OFFSET(badplace_t, type, 0xA);
	ASSERT_STRUCT_OFFSET(badplace_t, teamflags, 0xB);
	ASSERT_STRUCT_OFFSET(badplace_t, depth, 0xC);
	ASSERT_STRUCT_OFFSET(badplace_t, parms, 0x10);

	struct __declspec(align(2)) PathLinkInfo
	{
		unsigned __int16 from; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 to; //OFS: 0x2 SIZE: 0x2
		unsigned __int16 prev; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 next; //OFS: 0x6 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(PathLinkInfo, 0x8);
	ASSERT_STRUCT_OFFSET(PathLinkInfo, from, 0x0);
	ASSERT_STRUCT_OFFSET(PathLinkInfo, to, 0x2);
	ASSERT_STRUCT_OFFSET(PathLinkInfo, prev, 0x4);
	ASSERT_STRUCT_OFFSET(PathLinkInfo, next, 0x6);

	struct pathsort_t
	{
		pathnode_t * node; //OFS: 0x0 SIZE: 0x4
		float metric; //OFS: 0x4 SIZE: 0x4
		float distMetric; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(pathsort_t, 0xC);
	ASSERT_STRUCT_OFFSET(pathsort_t, node, 0x0);
	ASSERT_STRUCT_OFFSET(pathsort_t, metric, 0x4);
	ASSERT_STRUCT_OFFSET(pathsort_t, distMetric, 0x8);

	struct pathlocal_t_circle
	{
		float origin[3]; //OFS: 0x0 SIZE: 0xC
		float maxDist; //OFS: 0xC SIZE: 0x4
		float maxDistSq; //OFS: 0x10 SIZE: 0x4
		float maxHeightSq; //OFS: 0x14 SIZE: 0x4
		int typeFlags; //OFS: 0x18 SIZE: 0x4
		pathsort_t * nodes; //OFS: 0x1C SIZE: 0x4
		int maxNodes; //OFS: 0x20 SIZE: 0x4
		int nodeCount; //OFS: 0x24 SIZE: 0x4
		float maxHeight; //OFS: 0x28 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(pathlocal_t_circle, 0x2C);
	ASSERT_STRUCT_OFFSET(pathlocal_t_circle, origin, 0x0);
	ASSERT_STRUCT_OFFSET(pathlocal_t_circle, maxDist, 0xC);
	ASSERT_STRUCT_OFFSET(pathlocal_t_circle, maxDistSq, 0x10);
	ASSERT_STRUCT_OFFSET(pathlocal_t_circle, maxHeightSq, 0x14);
	ASSERT_STRUCT_OFFSET(pathlocal_t_circle, typeFlags, 0x18);
	ASSERT_STRUCT_OFFSET(pathlocal_t_circle, nodes, 0x1C);
	ASSERT_STRUCT_OFFSET(pathlocal_t_circle, maxNodes, 0x20);
	ASSERT_STRUCT_OFFSET(pathlocal_t_circle, nodeCount, 0x24);
	ASSERT_STRUCT_OFFSET(pathlocal_t_circle, maxHeight, 0x28);

	struct __declspec(align(128)) pathlocal_t
	{
		PathLinkInfo pathLinkInfoArray[2048]; //OFS: 0x0 SIZE: 0x4000
		int pathLinkInfoArrayInited; //OFS: 0x4000 SIZE: 0x4
		unsigned int actualNodeCount; //OFS: 0x4004 SIZE: 0x4
		pathlocal_t_circle circle; //OFS: 0x4008 SIZE: 0x2C
		unsigned int extraNodes; //OFS: 0x4034 SIZE: 0x4
		unsigned int originErrors; //OFS: 0x4038 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(pathlocal_t, 0x4080);
	ASSERT_STRUCT_OFFSET(pathlocal_t, pathLinkInfoArray, 0x0);
	ASSERT_STRUCT_OFFSET(pathlocal_t, pathLinkInfoArrayInited, 0x4000);
	ASSERT_STRUCT_OFFSET(pathlocal_t, actualNodeCount, 0x4004);
	ASSERT_STRUCT_OFFSET(pathlocal_t, circle, 0x4008);
	ASSERT_STRUCT_OFFSET(pathlocal_t, extraNodes, 0x4034);
	ASSERT_STRUCT_OFFSET(pathlocal_t, originErrors, 0x4038);

	struct AIEventListener
	{
		int entIndex; //OFS: 0x0 SIZE: 0x4
		unsigned int events; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(AIEventListener, 0x8);
	ASSERT_STRUCT_OFFSET(AIEventListener, entIndex, 0x0);
	ASSERT_STRUCT_OFFSET(AIEventListener, events, 0x4);

	struct vnode_field_t
	{
		const char * name; //OFS: 0x0 SIZE: 0x4
		int ofs; //OFS: 0x4 SIZE: 0x4
		fieldtype_t type; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(vnode_field_t, 0xC);
	ASSERT_STRUCT_OFFSET(vnode_field_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(vnode_field_t, ofs, 0x4);
	ASSERT_STRUCT_OFFSET(vnode_field_t, type, 0x8);

	struct StreamFileNameRaw
	{
		const char * dir; //OFS: 0x0 SIZE: 0x4
		const char * name; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(StreamFileNameRaw, 0x8);
	ASSERT_STRUCT_OFFSET(StreamFileNameRaw, dir, 0x0);
	ASSERT_STRUCT_OFFSET(StreamFileNameRaw, name, 0x4);

	union StreamFileInfo
	{
		StreamFileNameRaw raw[32]; //OFS: 0x0 SIZE: 0x100
	};
	ASSERT_STRUCT_SIZE(StreamFileInfo, 0x100);

	struct GfxStreamingAabbTree
	{
		unsigned __int16 firstItem; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 itemCount; //OFS: 0x2 SIZE: 0x2
		unsigned __int16 firstChild; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 childCount; //OFS: 0x6 SIZE: 0x2
		float mins[3]; //OFS: 0x8 SIZE: 0xC
		float maxs[3]; //OFS: 0x14 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(GfxStreamingAabbTree, 0x20);
	ASSERT_STRUCT_OFFSET(GfxStreamingAabbTree, firstItem, 0x0);
	ASSERT_STRUCT_OFFSET(GfxStreamingAabbTree, itemCount, 0x2);
	ASSERT_STRUCT_OFFSET(GfxStreamingAabbTree, firstChild, 0x4);
	ASSERT_STRUCT_OFFSET(GfxStreamingAabbTree, childCount, 0x6);
	ASSERT_STRUCT_OFFSET(GfxStreamingAabbTree, mins, 0x8);
	ASSERT_STRUCT_OFFSET(GfxStreamingAabbTree, maxs, 0x14);

	struct GfxWorldStreamInfo
	{
		int aabbTreeCount; //OFS: 0x0 SIZE: 0x4
		GfxStreamingAabbTree * aabbTrees; //OFS: 0x4 SIZE: 0x4
		int leafRefCount; //OFS: 0x8 SIZE: 0x4
		int * leafRefs; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWorldStreamInfo, 0x10);
	ASSERT_STRUCT_OFFSET(GfxWorldStreamInfo, aabbTreeCount, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldStreamInfo, aabbTrees, 0x4);
	ASSERT_STRUCT_OFFSET(GfxWorldStreamInfo, leafRefCount, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWorldStreamInfo, leafRefs, 0xC);

	struct GfxWorldGeomStreamGroup
	{
		float roughCenter[3]; //OFS: 0x0 SIZE: 0xC
		float streamDist; //OFS: 0xC SIZE: 0x4
		unsigned __int16 firstVolume; //OFS: 0x10 SIZE: 0x2
		unsigned __int16 numVolumes; //OFS: 0x12 SIZE: 0x2
		unsigned __int16 * surfs; //OFS: 0x14 SIZE: 0x4
		char * name; //OFS: 0x18 SIZE: 0x4
		unsigned int fileSize; //OFS: 0x1C SIZE: 0x4
		unsigned __int16 surfCount; //OFS: 0x20 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(GfxWorldGeomStreamGroup, 0x24);
	ASSERT_STRUCT_OFFSET(GfxWorldGeomStreamGroup, roughCenter, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldGeomStreamGroup, streamDist, 0xC);
	ASSERT_STRUCT_OFFSET(GfxWorldGeomStreamGroup, firstVolume, 0x10);
	ASSERT_STRUCT_OFFSET(GfxWorldGeomStreamGroup, numVolumes, 0x12);
	ASSERT_STRUCT_OFFSET(GfxWorldGeomStreamGroup, surfs, 0x14);
	ASSERT_STRUCT_OFFSET(GfxWorldGeomStreamGroup, name, 0x18);
	ASSERT_STRUCT_OFFSET(GfxWorldGeomStreamGroup, fileSize, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxWorldGeomStreamGroup, surfCount, 0x20);

	struct GfxWorldGeomStreamVolume
	{
		float matrix[3][3]; //OFS: 0x0 SIZE: 0x24
		float translate[3]; //OFS: 0x24 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(GfxWorldGeomStreamVolume, 0x30);
	ASSERT_STRUCT_OFFSET(GfxWorldGeomStreamVolume, matrix, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldGeomStreamVolume, translate, 0x24);

	struct GfxWorldGeomStreamInfo
	{
		int aabbTreeCount; //OFS: 0x0 SIZE: 0x4
		GfxStreamingAabbTree * aabbTrees; //OFS: 0x4 SIZE: 0x4
		int groupIndexCount; //OFS: 0x8 SIZE: 0x4
		unsigned __int16 * groupIndices; //OFS: 0xC SIZE: 0x4
		int groupCount; //OFS: 0x10 SIZE: 0x4
		GfxWorldGeomStreamGroup * groups; //OFS: 0x14 SIZE: 0x4
		int volumeCount; //OFS: 0x18 SIZE: 0x4
		GfxWorldGeomStreamVolume * volumes; //OFS: 0x1C SIZE: 0x4
		int streamBufSize; //OFS: 0x20 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWorldGeomStreamInfo, 0x24);
	ASSERT_STRUCT_OFFSET(GfxWorldGeomStreamInfo, aabbTreeCount, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldGeomStreamInfo, aabbTrees, 0x4);
	ASSERT_STRUCT_OFFSET(GfxWorldGeomStreamInfo, groupIndexCount, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWorldGeomStreamInfo, groupIndices, 0xC);
	ASSERT_STRUCT_OFFSET(GfxWorldGeomStreamInfo, groupCount, 0x10);
	ASSERT_STRUCT_OFFSET(GfxWorldGeomStreamInfo, groups, 0x14);
	ASSERT_STRUCT_OFFSET(GfxWorldGeomStreamInfo, volumeCount, 0x18);
	ASSERT_STRUCT_OFFSET(GfxWorldGeomStreamInfo, volumes, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxWorldGeomStreamInfo, streamBufSize, 0x20);

	struct GfxWorldXModelStreamInfo
	{
		int aabbTreeCount; //OFS: 0x0 SIZE: 0x4
		GfxStreamingAabbTree * aabbTrees; //OFS: 0x4 SIZE: 0x4
		int smodelIndexCount; //OFS: 0x8 SIZE: 0x4
		unsigned __int16 * smodelIndices; //OFS: 0xC SIZE: 0x4
		int streamBufSize; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWorldXModelStreamInfo, 0x14);
	ASSERT_STRUCT_OFFSET(GfxWorldXModelStreamInfo, aabbTreeCount, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldXModelStreamInfo, aabbTrees, 0x4);
	ASSERT_STRUCT_OFFSET(GfxWorldXModelStreamInfo, smodelIndexCount, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWorldXModelStreamInfo, smodelIndices, 0xC);
	ASSERT_STRUCT_OFFSET(GfxWorldXModelStreamInfo, streamBufSize, 0x10);

	struct GfxSimpleWaterCell
	{
		float mins[3]; //OFS: 0x0 SIZE: 0xC
		float maxs[3]; //OFS: 0xC SIZE: 0xC
		float underSurfaceHeight[169]; //OFS: 0x18 SIZE: 0x2A4
	};
	ASSERT_STRUCT_SIZE(GfxSimpleWaterCell, 0x2BC);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterCell, mins, 0x0);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterCell, maxs, 0xC);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterCell, underSurfaceHeight, 0x18);

	struct GfxSimpleWaterWaveGen
	{
		float pos[3]; //OFS: 0x0 SIZE: 0xC
		float amplitude; //OFS: 0xC SIZE: 0x4
		float waveLength; //OFS: 0x10 SIZE: 0x4
		float frequency; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxSimpleWaterWaveGen, 0x18);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterWaveGen, pos, 0x0);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterWaveGen, amplitude, 0xC);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterWaveGen, waveLength, 0x10);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterWaveGen, frequency, 0x14);

	struct GfxSimpleWaterData
	{
		int minx; //OFS: 0x0 SIZE: 0x4
		int miny; //OFS: 0x4 SIZE: 0x4
		int maxx; //OFS: 0x8 SIZE: 0x4
		int maxy; //OFS: 0xC SIZE: 0x4
		float seaLevel; //OFS: 0x10 SIZE: 0x4
		float minAlpha; //OFS: 0x14 SIZE: 0x4
		float maxAlpha; //OFS: 0x18 SIZE: 0x4
		float minAlphaDepth; //OFS: 0x1C SIZE: 0x4
		float maxAlphaDepth; //OFS: 0x20 SIZE: 0x4
		float animFadeBegin; //OFS: 0x24 SIZE: 0x4
		float animFadeEnd; //OFS: 0x28 SIZE: 0x4
		float cullDist; //OFS: 0x2C SIZE: 0x4
		float minColor[3]; //OFS: 0x30 SIZE: 0xC
		float maxColor[3]; //OFS: 0x3C SIZE: 0xC
		float depthAmpReduceSlope; //OFS: 0x48 SIZE: 0x4
		float depthAmpReduceIntercept; //OFS: 0x4C SIZE: 0x4
		Material * waterMaterial; //OFS: 0x50 SIZE: 0x4
		unsigned int numCells; //OFS: 0x54 SIZE: 0x4
		GfxSimpleWaterCell * cells; //OFS: 0x58 SIZE: 0x4
		unsigned __int8 * cellVisData; //OFS: 0x5C SIZE: 0x4
		unsigned int numWaveGens; //OFS: 0x60 SIZE: 0x4
		GfxSimpleWaterWaveGen * waveGens; //OFS: 0x64 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxSimpleWaterData, 0x68);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, minx, 0x0);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, miny, 0x4);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, maxx, 0x8);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, maxy, 0xC);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, seaLevel, 0x10);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, minAlpha, 0x14);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, maxAlpha, 0x18);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, minAlphaDepth, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, maxAlphaDepth, 0x20);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, animFadeBegin, 0x24);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, animFadeEnd, 0x28);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, cullDist, 0x2C);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, minColor, 0x30);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, maxColor, 0x3C);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, depthAmpReduceSlope, 0x48);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, depthAmpReduceIntercept, 0x4C);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, waterMaterial, 0x50);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, numCells, 0x54);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, cells, 0x58);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, cellVisData, 0x5C);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, numWaveGens, 0x60);
	ASSERT_STRUCT_OFFSET(GfxSimpleWaterData, waveGens, 0x64);

	struct worldContents_s
	{
		int contentsStaticModels; //OFS: 0x0 SIZE: 0x4
		int contentsEntities; //OFS: 0x4 SIZE: 0x4
		unsigned __int16 entities; //OFS: 0x8 SIZE: 0x2
		unsigned __int16 staticModels; //OFS: 0xA SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(worldContents_s, 0xC);
	ASSERT_STRUCT_OFFSET(worldContents_s, contentsStaticModels, 0x0);
	ASSERT_STRUCT_OFFSET(worldContents_s, contentsEntities, 0x4);
	ASSERT_STRUCT_OFFSET(worldContents_s, entities, 0x8);
	ASSERT_STRUCT_OFFSET(worldContents_s, staticModels, 0xA);

	union worldTree_s_u
	{
		unsigned __int16 parent; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 nextFree; //OFS: 0x1 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(worldTree_s_u, 0x2);

	struct worldTree_s
	{
		float dist; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 axis; //OFS: 0x4 SIZE: 0x2
		worldTree_s_u u; //OFS: 0x6 SIZE: 0x2
		unsigned __int16 child[2]; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(worldTree_s, 0xC);
	ASSERT_STRUCT_OFFSET(worldTree_s, dist, 0x0);
	ASSERT_STRUCT_OFFSET(worldTree_s, axis, 0x4);
	ASSERT_STRUCT_OFFSET(worldTree_s, u, 0x6);
	ASSERT_STRUCT_OFFSET(worldTree_s, child, 0x8);

	struct worldSector_s
	{
		worldContents_s contents; //OFS: 0x0 SIZE: 0xC
		worldTree_s tree; //OFS: 0xC SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(worldSector_s, 0x18);
	ASSERT_STRUCT_OFFSET(worldSector_s, contents, 0x0);
	ASSERT_STRUCT_OFFSET(worldSector_s, tree, 0xC);

	struct cm_world_t
	{
		float mins[3]; //OFS: 0x0 SIZE: 0xC
		float maxs[3]; //OFS: 0xC SIZE: 0xC
		unsigned __int16 freeHead; //OFS: 0x18 SIZE: 0x2
		worldSector_s sectors[1024]; //OFS: 0x1C SIZE: 0x6000
	};
	ASSERT_STRUCT_SIZE(cm_world_t, 0x601C);
	ASSERT_STRUCT_OFFSET(cm_world_t, mins, 0x0);
	ASSERT_STRUCT_OFFSET(cm_world_t, maxs, 0xC);
	ASSERT_STRUCT_OFFSET(cm_world_t, freeHead, 0x18);
	ASSERT_STRUCT_OFFSET(cm_world_t, sectors, 0x1C);

	struct SnapshotInfo_s
	{
		int clientNum; //OFS: 0x0 SIZE: 0x4
		clientHeader_s * client; //OFS: 0x4 SIZE: 0x4
		int snapshotDeltaTime; //OFS: 0x8 SIZE: 0x4
		BaseLineState fromBaseline; //OFS: 0xC SIZE: 0x4
		bool archived; //OFS: 0x10 SIZE: 0x1
		float field_14[3]; //OFS: 0x14 SIZE: 0xC
		float field_20[2]; //OFS: 0x20 SIZE: 0x8
		char field_28; //OFS: 0x28 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(SnapshotInfo_s, 0x2C);
	ASSERT_STRUCT_OFFSET(SnapshotInfo_s, clientNum, 0x0);
	ASSERT_STRUCT_OFFSET(SnapshotInfo_s, client, 0x4);
	ASSERT_STRUCT_OFFSET(SnapshotInfo_s, snapshotDeltaTime, 0x8);
	ASSERT_STRUCT_OFFSET(SnapshotInfo_s, fromBaseline, 0xC);
	ASSERT_STRUCT_OFFSET(SnapshotInfo_s, archived, 0x10);
	ASSERT_STRUCT_OFFSET(SnapshotInfo_s, field_14, 0x14);
	ASSERT_STRUCT_OFFSET(SnapshotInfo_s, field_20, 0x20);
	ASSERT_STRUCT_OFFSET(SnapshotInfo_s, field_28, 0x28);

	struct NetFieldList
	{
		const NetField * array; //OFS: 0x0 SIZE: 0x4
		unsigned int count; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(NetFieldList, 0x8);
	ASSERT_STRUCT_OFFSET(NetFieldList, array, 0x0);
	ASSERT_STRUCT_OFFSET(NetFieldList, count, 0x4);

	struct kbutton_t
	{
		int down[2]; //OFS: 0x0 SIZE: 0x8
		unsigned int downtime; //OFS: 0x8 SIZE: 0x4
		unsigned int msec; //OFS: 0xC SIZE: 0x4
		bool active; //OFS: 0x10 SIZE: 0x1
		bool wasPressed; //OFS: 0x11 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(kbutton_t, 0x14);
	ASSERT_STRUCT_OFFSET(kbutton_t, down, 0x0);
	ASSERT_STRUCT_OFFSET(kbutton_t, downtime, 0x8);
	ASSERT_STRUCT_OFFSET(kbutton_t, msec, 0xC);
	ASSERT_STRUCT_OFFSET(kbutton_t, active, 0x10);
	ASSERT_STRUCT_OFFSET(kbutton_t, wasPressed, 0x11);

	struct GamepadVirtualAxisMapping
	{
		GamepadPhysicalAxis physicalAxis; //OFS: 0x0 SIZE: 0x4
		GamepadMapping mapType; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GamepadVirtualAxisMapping, 0x8);
	ASSERT_STRUCT_OFFSET(GamepadVirtualAxisMapping, physicalAxis, 0x0);
	ASSERT_STRUCT_OFFSET(GamepadVirtualAxisMapping, mapType, 0x4);

	struct ScreenPlacement
	{
		float scaleVirtualToReal[2]; //OFS: 0x0 SIZE: 0x8
		float scaleVirtualToFull[2]; //OFS: 0x8 SIZE: 0x8
		float scaleRealToVirtual[2]; //OFS: 0x10 SIZE: 0x8
		float virtualViewableMin[2]; //OFS: 0x18 SIZE: 0x8
		float virtualViewableMax[2]; //OFS: 0x20 SIZE: 0x8
		float realViewportSize[2]; //OFS: 0x28 SIZE: 0x8
		float realViewableMin[2]; //OFS: 0x30 SIZE: 0x8
		float realViewableMax[2]; //OFS: 0x38 SIZE: 0x8
		float subScreen[2]; //OFS: 0x40 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(ScreenPlacement, 0x48);
	ASSERT_STRUCT_OFFSET(ScreenPlacement, scaleVirtualToReal, 0x0);
	ASSERT_STRUCT_OFFSET(ScreenPlacement, scaleVirtualToFull, 0x8);
	ASSERT_STRUCT_OFFSET(ScreenPlacement, scaleRealToVirtual, 0x10);
	ASSERT_STRUCT_OFFSET(ScreenPlacement, virtualViewableMin, 0x18);
	ASSERT_STRUCT_OFFSET(ScreenPlacement, virtualViewableMax, 0x20);
	ASSERT_STRUCT_OFFSET(ScreenPlacement, realViewportSize, 0x28);
	ASSERT_STRUCT_OFFSET(ScreenPlacement, realViewableMin, 0x30);
	ASSERT_STRUCT_OFFSET(ScreenPlacement, realViewableMax, 0x38);
	ASSERT_STRUCT_OFFSET(ScreenPlacement, subScreen, 0x40);

	struct GraphFloat
	{
		char name[64]; //OFS: 0x0 SIZE: 0x40
		float knots[32][2]; //OFS: 0x40 SIZE: 0x100
		int knotCount; //OFS: 0x140 SIZE: 0x4
		float scale; //OFS: 0x144 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GraphFloat, 0x148);
	ASSERT_STRUCT_OFFSET(GraphFloat, name, 0x0);
	ASSERT_STRUCT_OFFSET(GraphFloat, knots, 0x40);
	ASSERT_STRUCT_OFFSET(GraphFloat, knotCount, 0x140);
	ASSERT_STRUCT_OFFSET(GraphFloat, scale, 0x144);

	struct dsound_sample_t
	{
		void * DSCB; //OFS: 0x0 SIZE: 0x4
		void * DSB; //OFS: 0x4 SIZE: 0x4
		unsigned int dwBufferSize; //OFS: 0x8 SIZE: 0x4
		unsigned int dwCaptureOffset; //OFS: 0xC SIZE: 0x4
		unsigned int currentOffset; //OFS: 0x10 SIZE: 0x4
		unsigned int lastOffset; //OFS: 0x14 SIZE: 0x4
		unsigned int currentBufferLength; //OFS: 0x18 SIZE: 0x4
		int stopPosition; //OFS: 0x1C SIZE: 0x4
		unsigned int lastPlayPos; //OFS: 0x20 SIZE: 0x4
		int bytesBuffered; //OFS: 0x24 SIZE: 0x4
		int mode; //OFS: 0x28 SIZE: 0x4
		int frequency; //OFS: 0x2C SIZE: 0x4
		int volume; //OFS: 0x30 SIZE: 0x4
		int pan; //OFS: 0x34 SIZE: 0x4
		int channels; //OFS: 0x38 SIZE: 0x4
		bool playing; //OFS: 0x3C SIZE: 0x1
		int channel; //OFS: 0x40 SIZE: 0x4
		char playMode; //OFS: 0x44 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(dsound_sample_t, 0x48);
	ASSERT_STRUCT_OFFSET(dsound_sample_t, DSCB, 0x0);
	ASSERT_STRUCT_OFFSET(dsound_sample_t, DSB, 0x4);
	ASSERT_STRUCT_OFFSET(dsound_sample_t, dwBufferSize, 0x8);
	ASSERT_STRUCT_OFFSET(dsound_sample_t, dwCaptureOffset, 0xC);
	ASSERT_STRUCT_OFFSET(dsound_sample_t, currentOffset, 0x10);
	ASSERT_STRUCT_OFFSET(dsound_sample_t, lastOffset, 0x14);
	ASSERT_STRUCT_OFFSET(dsound_sample_t, currentBufferLength, 0x18);
	ASSERT_STRUCT_OFFSET(dsound_sample_t, stopPosition, 0x1C);
	ASSERT_STRUCT_OFFSET(dsound_sample_t, lastPlayPos, 0x20);
	ASSERT_STRUCT_OFFSET(dsound_sample_t, bytesBuffered, 0x24);
	ASSERT_STRUCT_OFFSET(dsound_sample_t, mode, 0x28);
	ASSERT_STRUCT_OFFSET(dsound_sample_t, frequency, 0x2C);
	ASSERT_STRUCT_OFFSET(dsound_sample_t, volume, 0x30);
	ASSERT_STRUCT_OFFSET(dsound_sample_t, pan, 0x34);
	ASSERT_STRUCT_OFFSET(dsound_sample_t, channels, 0x38);
	ASSERT_STRUCT_OFFSET(dsound_sample_t, playing, 0x3C);
	ASSERT_STRUCT_OFFSET(dsound_sample_t, channel, 0x40);
	ASSERT_STRUCT_OFFSET(dsound_sample_t, playMode, 0x44);

	struct audioSample_t
	{
		char * buffer; //OFS: 0x0 SIZE: 0x4
		int lengthInBytes; //OFS: 0x4 SIZE: 0x4
		int lengthInSamples; //OFS: 0x8 SIZE: 0x4
		int bytesPerSample; //OFS: 0xC SIZE: 0x4
		int frequency; //OFS: 0x10 SIZE: 0x4
		bool stereo; //OFS: 0x14 SIZE: 0x1
		int channels; //OFS: 0x18 SIZE: 0x4
		int sampleOffset; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(audioSample_t, 0x20);
	ASSERT_STRUCT_OFFSET(audioSample_t, buffer, 0x0);
	ASSERT_STRUCT_OFFSET(audioSample_t, lengthInBytes, 0x4);
	ASSERT_STRUCT_OFFSET(audioSample_t, lengthInSamples, 0x8);
	ASSERT_STRUCT_OFFSET(audioSample_t, bytesPerSample, 0xC);
	ASSERT_STRUCT_OFFSET(audioSample_t, frequency, 0x10);
	ASSERT_STRUCT_OFFSET(audioSample_t, stereo, 0x14);
	ASSERT_STRUCT_OFFSET(audioSample_t, channels, 0x18);
	ASSERT_STRUCT_OFFSET(audioSample_t, sampleOffset, 0x1C);

	struct sysEvent_t
	{
		int evTime; //OFS: 0x0 SIZE: 0x4
		sysEventType_t evType; //OFS: 0x4 SIZE: 0x4
		int evValue; //OFS: 0x8 SIZE: 0x4
		int evValue2; //OFS: 0xC SIZE: 0x4
		int evPtrLength; //OFS: 0x10 SIZE: 0x4
		void * evPtr; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(sysEvent_t, 0x18);
	ASSERT_STRUCT_OFFSET(sysEvent_t, evTime, 0x0);
	ASSERT_STRUCT_OFFSET(sysEvent_t, evType, 0x4);
	ASSERT_STRUCT_OFFSET(sysEvent_t, evValue, 0x8);
	ASSERT_STRUCT_OFFSET(sysEvent_t, evValue2, 0xC);
	ASSERT_STRUCT_OFFSET(sysEvent_t, evPtrLength, 0x10);
	ASSERT_STRUCT_OFFSET(sysEvent_t, evPtr, 0x14);

	struct traceWork_t
	{
		float delta[4]; //OFS: 0x0 SIZE: 0x10
		float midpoint[4]; //OFS: 0x10 SIZE: 0x10
		float halfDelta[4]; //OFS: 0x20 SIZE: 0x10
		float halfDeltaAbs[4]; //OFS: 0x30 SIZE: 0x10
		float size[4]; //OFS: 0x40 SIZE: 0x10
		float bounds[2][4]; //OFS: 0x50 SIZE: 0x20
		float radiusOffset[4]; //OFS: 0x70 SIZE: 0x10
		TraceExtents extents; //OFS: 0x80 SIZE: 0x30
		float deltaLen; //OFS: 0xB0 SIZE: 0x4
		float deltaLenSq; //OFS: 0xB4 SIZE: 0x4
		int contents; //OFS: 0xB8 SIZE: 0x4
		bool isPoint; //OFS: 0xBC SIZE: 0x1
		bool axialCullOnly; //OFS: 0xBD SIZE: 0x1
		bool doublesided; //OFS: 0xBE SIZE: 0x1
		float radius; //OFS: 0xC0 SIZE: 0x4
		float offsetZ; //OFS: 0xC4 SIZE: 0x4
		float boundingRadius; //OFS: 0xC8 SIZE: 0x4
		TraceThreadInfo threadInfo; //OFS: 0xCC SIZE: 0x14
	};
	ASSERT_STRUCT_SIZE(traceWork_t, 0xE0);
	ASSERT_STRUCT_OFFSET(traceWork_t, delta, 0x0);
	ASSERT_STRUCT_OFFSET(traceWork_t, midpoint, 0x10);
	ASSERT_STRUCT_OFFSET(traceWork_t, halfDelta, 0x20);
	ASSERT_STRUCT_OFFSET(traceWork_t, halfDeltaAbs, 0x30);
	ASSERT_STRUCT_OFFSET(traceWork_t, size, 0x40);
	ASSERT_STRUCT_OFFSET(traceWork_t, bounds, 0x50);
	ASSERT_STRUCT_OFFSET(traceWork_t, radiusOffset, 0x70);
	ASSERT_STRUCT_OFFSET(traceWork_t, extents, 0x80);
	ASSERT_STRUCT_OFFSET(traceWork_t, deltaLen, 0xB0);
	ASSERT_STRUCT_OFFSET(traceWork_t, deltaLenSq, 0xB4);
	ASSERT_STRUCT_OFFSET(traceWork_t, contents, 0xB8);
	ASSERT_STRUCT_OFFSET(traceWork_t, isPoint, 0xBC);
	ASSERT_STRUCT_OFFSET(traceWork_t, axialCullOnly, 0xBD);
	ASSERT_STRUCT_OFFSET(traceWork_t, doublesided, 0xBE);
	ASSERT_STRUCT_OFFSET(traceWork_t, radius, 0xC0);
	ASSERT_STRUCT_OFFSET(traceWork_t, offsetZ, 0xC4);
	ASSERT_STRUCT_OFFSET(traceWork_t, boundingRadius, 0xC8);
	ASSERT_STRUCT_OFFSET(traceWork_t, threadInfo, 0xCC);

	struct __declspec(align(1)) defVtxDef
	{
		char gap0[1]; //OFS: 0x0 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(defVtxDef, 0x1);
	ASSERT_STRUCT_OFFSET(defVtxDef, gap0, 0x0);

	struct __declspec(align(2)) GfxCachedLightEffect
	{
		unsigned __int16 lightIndex; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 atten; //OFS: 0x2 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(GfxCachedLightEffect, 0x4);
	ASSERT_STRUCT_OFFSET(GfxCachedLightEffect, lightIndex, 0x0);
	ASSERT_STRUCT_OFFSET(GfxCachedLightEffect, atten, 0x2);

	struct GfxCachedLightSetting
	{
		__int16 firstIndex; //OFS: 0x0 SIZE: 0x2
		__int16 count; //OFS: 0x2 SIZE: 0x2
		GfxColor ambient; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxCachedLightSetting, 0x8);
	ASSERT_STRUCT_OFFSET(GfxCachedLightSetting, firstIndex, 0x0);
	ASSERT_STRUCT_OFFSET(GfxCachedLightSetting, count, 0x2);
	ASSERT_STRUCT_OFFSET(GfxCachedLightSetting, ambient, 0x4);

	struct GfxLightGrid2dLight
	{
		float pos[4]; //OFS: 0x0 SIZE: 0x10
		float color[3]; //OFS: 0x10 SIZE: 0xC
		float pad; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxLightGrid2dLight, 0x20);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2dLight, pos, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2dLight, color, 0x10);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2dLight, pad, 0x1C);

	struct GfxLightGrid2dIndex
	{
		unsigned int index; //OFS: 0x0 SIZE: 0x4
		float atten; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxLightGrid2dIndex, 0x8);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2dIndex, index, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2dIndex, atten, 0x4);

	struct GfxLightGrid2dRow
	{
		float minColumnCoord; //OFS: 0x0 SIZE: 0x4
		unsigned int firstGridPoint; //OFS: 0x4 SIZE: 0x4
		unsigned int numGridPoints; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxLightGrid2dRow, 0xC);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2dRow, minColumnCoord, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2dRow, firstGridPoint, 0x4);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2dRow, numGridPoints, 0x8);

	struct __declspec(align(2)) GfxLightGrid2dPoint
	{
		unsigned __int16 first; //OFS: 0x0 SIZE: 0x2
		unsigned __int8 count; //OFS: 0x2 SIZE: 0x1
		unsigned __int8 ambientIndex; //OFS: 0x3 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(GfxLightGrid2dPoint, 0x4);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2dPoint, first, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2dPoint, count, 0x2);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2dPoint, ambientIndex, 0x3);

	struct GfxLightGrid2dCell
	{
		float mins[3]; //OFS: 0x0 SIZE: 0xC
		float maxs[3]; //OFS: 0xC SIZE: 0xC
		float rowDelta; //OFS: 0x18 SIZE: 0x4
		float columnDelta; //OFS: 0x1C SIZE: 0x4
		float minRowCoord; //OFS: 0x20 SIZE: 0x4
		unsigned __int16 firstRow; //OFS: 0x24 SIZE: 0x2
		unsigned __int16 numRows; //OFS: 0x26 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(GfxLightGrid2dCell, 0x28);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2dCell, mins, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2dCell, maxs, 0xC);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2dCell, rowDelta, 0x18);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2dCell, columnDelta, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2dCell, minRowCoord, 0x20);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2dCell, firstRow, 0x24);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2dCell, numRows, 0x26);

	struct GfxLightGrid2d
	{
		unsigned int numLights; //OFS: 0x0 SIZE: 0x4
		GfxLightGrid2dLight * lights; //OFS: 0x4 SIZE: 0x4
		unsigned int numIndices; //OFS: 0x8 SIZE: 0x4
		GfxLightGrid2dIndex * indices; //OFS: 0xC SIZE: 0x4
		unsigned int numRows; //OFS: 0x10 SIZE: 0x4
		GfxLightGrid2dRow * rows; //OFS: 0x14 SIZE: 0x4
		unsigned int numPoints; //OFS: 0x18 SIZE: 0x4
		GfxLightGrid2dPoint * points; //OFS: 0x1C SIZE: 0x4
		unsigned int numCells; //OFS: 0x20 SIZE: 0x4
		GfxLightGrid2dCell * cells; //OFS: 0x24 SIZE: 0x4
		unsigned int numAmbients; //OFS: 0x28 SIZE: 0x4
		GfxColor * ambients; //OFS: 0x2C SIZE: 0x4
		unsigned int numPointHeights; //OFS: 0x30 SIZE: 0x4
		__int16 * pointHeights; //OFS: 0x34 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxLightGrid2d, 0x38);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2d, numLights, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2d, lights, 0x4);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2d, numIndices, 0x8);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2d, indices, 0xC);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2d, numRows, 0x10);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2d, rows, 0x14);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2d, numPoints, 0x18);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2d, points, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2d, numCells, 0x20);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2d, cells, 0x24);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2d, numAmbients, 0x28);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2d, ambients, 0x2C);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2d, numPointHeights, 0x30);
	ASSERT_STRUCT_OFFSET(GfxLightGrid2d, pointHeights, 0x34);

	struct GfxLightmapArray
	{
		GfxImage * primary; //OFS: 0x0 SIZE: 0x4
		GfxImage * secondary; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxLightmapArray, 0x8);
	ASSERT_STRUCT_OFFSET(GfxLightmapArray, primary, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightmapArray, secondary, 0x4);

	struct GpadAxesGlob
	{
		int axesValues[6]; //OFS: 0x0 SIZE: 0x18
		GamepadVirtualAxisMapping virtualAxes[6]; //OFS: 0x18 SIZE: 0x30
	};
	ASSERT_STRUCT_SIZE(GpadAxesGlob, 0x48);
	ASSERT_STRUCT_OFFSET(GpadAxesGlob, axesValues, 0x0);
	ASSERT_STRUCT_OFFSET(GpadAxesGlob, virtualAxes, 0x18);

	struct __declspec(align(2)) _XINPUT_CAPABILITIES
	{
		char Type; //OFS: 0x0 SIZE: 0x1
		char SubType; //OFS: 0x1 SIZE: 0x1
		unsigned __int16 Flags; //OFS: 0x2 SIZE: 0x2
		_XINPUT_GAMEPAD Gamepad; //OFS: 0x4 SIZE: 0xC
		_XINPUT_VIBRATION Vibration; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(_XINPUT_CAPABILITIES, 0x14);
	ASSERT_STRUCT_OFFSET(_XINPUT_CAPABILITIES, Type, 0x0);
	ASSERT_STRUCT_OFFSET(_XINPUT_CAPABILITIES, SubType, 0x1);
	ASSERT_STRUCT_OFFSET(_XINPUT_CAPABILITIES, Flags, 0x2);
	ASSERT_STRUCT_OFFSET(_XINPUT_CAPABILITIES, Gamepad, 0x4);
	ASSERT_STRUCT_OFFSET(_XINPUT_CAPABILITIES, Vibration, 0x10);

	struct GamePad
	{
		bool enabled; //OFS: 0x0 SIZE: 0x1
		bool keyboardEnabled; //OFS: 0x1 SIZE: 0x1
		__int16 digitals; //OFS: 0x2 SIZE: 0x2
		__int16 lastDigitals; //OFS: 0x4 SIZE: 0x2
		float analogs[2]; //OFS: 0x8 SIZE: 0x8
		float lastAnalogs[2]; //OFS: 0x10 SIZE: 0x8
		float sticks[4]; //OFS: 0x18 SIZE: 0x10
		float lastSticks[4]; //OFS: 0x28 SIZE: 0x10
		bool stickDown[4][2]; //OFS: 0x38 SIZE: 0x8
		bool stickDownLast[4][2]; //OFS: 0x40 SIZE: 0x8
		float lowRumble; //OFS: 0x48 SIZE: 0x4
		float highRumble; //OFS: 0x4C SIZE: 0x4
		_XINPUT_VIBRATION feedback[6]; //OFS: 0x50 SIZE: 0x18
		_XINPUT_CAPABILITIES keyboardCaps; //OFS: 0x68 SIZE: 0x14
	};
	ASSERT_STRUCT_SIZE(GamePad, 0x7C);
	ASSERT_STRUCT_OFFSET(GamePad, enabled, 0x0);
	ASSERT_STRUCT_OFFSET(GamePad, keyboardEnabled, 0x1);
	ASSERT_STRUCT_OFFSET(GamePad, digitals, 0x2);
	ASSERT_STRUCT_OFFSET(GamePad, lastDigitals, 0x4);
	ASSERT_STRUCT_OFFSET(GamePad, analogs, 0x8);
	ASSERT_STRUCT_OFFSET(GamePad, lastAnalogs, 0x10);
	ASSERT_STRUCT_OFFSET(GamePad, sticks, 0x18);
	ASSERT_STRUCT_OFFSET(GamePad, lastSticks, 0x28);
	ASSERT_STRUCT_OFFSET(GamePad, stickDown, 0x38);
	ASSERT_STRUCT_OFFSET(GamePad, stickDownLast, 0x40);
	ASSERT_STRUCT_OFFSET(GamePad, lowRumble, 0x48);
	ASSERT_STRUCT_OFFSET(GamePad, highRumble, 0x4C);
	ASSERT_STRUCT_OFFSET(GamePad, feedback, 0x50);
	ASSERT_STRUCT_OFFSET(GamePad, keyboardCaps, 0x68);

	struct BulletFireParams
	{
		int weaponEntIndex; //OFS: 0x0 SIZE: 0x4
		int ignoreEntIndex; //OFS: 0x4 SIZE: 0x4
		float damageMultiplier; //OFS: 0x8 SIZE: 0x4
		int methodOfDeath; //OFS: 0xC SIZE: 0x4
		float origStart[3]; //OFS: 0x10 SIZE: 0xC
		float start[3]; //OFS: 0x1C SIZE: 0xC
		float end[3]; //OFS: 0x28 SIZE: 0xC
		float dir[3]; //OFS: 0x34 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(BulletFireParams, 0x40);
	ASSERT_STRUCT_OFFSET(BulletFireParams, weaponEntIndex, 0x0);
	ASSERT_STRUCT_OFFSET(BulletFireParams, ignoreEntIndex, 0x4);
	ASSERT_STRUCT_OFFSET(BulletFireParams, damageMultiplier, 0x8);
	ASSERT_STRUCT_OFFSET(BulletFireParams, methodOfDeath, 0xC);
	ASSERT_STRUCT_OFFSET(BulletFireParams, origStart, 0x10);
	ASSERT_STRUCT_OFFSET(BulletFireParams, start, 0x1C);
	ASSERT_STRUCT_OFFSET(BulletFireParams, end, 0x28);
	ASSERT_STRUCT_OFFSET(BulletFireParams, dir, 0x34);

	struct locTraceWork_t
	{
		int contents; //OFS: 0x0 SIZE: 0x4
		TraceExtents extents; //OFS: 0x4 SIZE: 0x30
	};
	ASSERT_STRUCT_SIZE(locTraceWork_t, 0x34);
	ASSERT_STRUCT_OFFSET(locTraceWork_t, contents, 0x0);
	ASSERT_STRUCT_OFFSET(locTraceWork_t, extents, 0x4);

	struct cg_level_locals_t
	{
		con_channel_e scriptPrintChannel; //OFS: 0x0 SIZE: 0x4
		SpawnVar spawnVar; //OFS: 0x4 SIZE: 0xA0C
	};
	ASSERT_STRUCT_SIZE(cg_level_locals_t, 0xA10);
	ASSERT_STRUCT_OFFSET(cg_level_locals_t, scriptPrintChannel, 0x0);
	ASSERT_STRUCT_OFFSET(cg_level_locals_t, spawnVar, 0x4);

	struct cent_field_t
	{
		char * name; //OFS: 0x0 SIZE: 0x4
		int ofs; //OFS: 0x4 SIZE: 0x4
		fieldtype_t type; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(cent_field_t, 0xC);
	ASSERT_STRUCT_OFFSET(cent_field_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(cent_field_t, ofs, 0x4);
	ASSERT_STRUCT_OFFSET(cent_field_t, type, 0x8);

	struct Bone
	{
		int parentBone; //OFS: 0x0 SIZE: 0x4
		unsigned __int8 animBones[2]; //OFS: 0x4 SIZE: 0x2
		int rigidBody; //OFS: 0x8 SIZE: 0x4
		float length; //OFS: 0xC SIZE: 0x4
		float center[3]; //OFS: 0x10 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(Bone, 0x1C);
	ASSERT_STRUCT_OFFSET(Bone, parentBone, 0x0);
	ASSERT_STRUCT_OFFSET(Bone, animBones, 0x4);
	ASSERT_STRUCT_OFFSET(Bone, rigidBody, 0x8);
	ASSERT_STRUCT_OFFSET(Bone, length, 0xC);
	ASSERT_STRUCT_OFFSET(Bone, center, 0x10);

	struct LerpBone
	{
		int parentBone; //OFS: 0x0 SIZE: 0x4
		unsigned __int8 animBone; //OFS: 0x4 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(LerpBone, 0x8);
	ASSERT_STRUCT_OFFSET(LerpBone, parentBone, 0x0);
	ASSERT_STRUCT_OFFSET(LerpBone, animBone, 0x4);

	struct Joint
	{
		int joint; //OFS: 0x0 SIZE: 0x4
		int joint2; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(Joint, 0x8);
	ASSERT_STRUCT_OFFSET(Joint, joint, 0x0);
	ASSERT_STRUCT_OFFSET(Joint, joint2, 0x4);

	struct BoneOrientation
	{
		float origin[3]; //OFS: 0x0 SIZE: 0xC
		int boneFlags; //OFS: 0xC SIZE: 0x4
		float orientation[4]; //OFS: 0x10 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(BoneOrientation, 0x20);
	ASSERT_STRUCT_OFFSET(BoneOrientation, origin, 0x0);
	ASSERT_STRUCT_OFFSET(BoneOrientation, boneFlags, 0xC);
	ASSERT_STRUCT_OFFSET(BoneOrientation, orientation, 0x10);

	struct RagdollBody
	{
		int references; //OFS: 0x0 SIZE: 0x4
		int ragdollDef; //OFS: 0x4 SIZE: 0x4
		int dobj; //OFS: 0x8 SIZE: 0x4
		DObj_s * obj; //OFS: 0xC SIZE: 0x4
		cpose_t * pose; //OFS: 0x10 SIZE: 0x4
		float poseOffset[3]; //OFS: 0x14 SIZE: 0xC
		int localClientNum; //OFS: 0x20 SIZE: 0x4
		RagdollBodyState state; //OFS: 0x24 SIZE: 0x4
		int stateMsec; //OFS: 0x28 SIZE: 0x4
		int stateFrames; //OFS: 0x2C SIZE: 0x4
		int velCaptureMsec; //OFS: 0x30 SIZE: 0x4
		int stableTime; //OFS: 0x34 SIZE: 0x4
		int numBones; //OFS: 0x38 SIZE: 0x4
		Bone bones[14]; //OFS: 0x3C SIZE: 0x188
		int numLerpBones; //OFS: 0x1C4 SIZE: 0x4
		LerpBone lerpBones[9]; //OFS: 0x1C8 SIZE: 0x48
		int numJoints; //OFS: 0x210 SIZE: 0x4
		Joint joints[28]; //OFS: 0x214 SIZE: 0xE0
		int curOrientationBuffer; //OFS: 0x2F4 SIZE: 0x4
		BoneOrientation boneOrientations[2][23]; //OFS: 0x2F8 SIZE: 0x5C0
		BoneOrientation lerpBoneOffsets[9]; //OFS: 0x8B8 SIZE: 0x120
		int flags; //OFS: 0x9D8 SIZE: 0x4
		int storedLaunchCount; //OFS: 0x9DC SIZE: 0x4
		hitLocation_t storedLaunchHitLoc[2]; //OFS: 0x9E0 SIZE: 0x8
		float storedLaunchForce[2][3]; //OFS: 0x9E8 SIZE: 0x18
		void * m_bpg; //OFS: 0xA00 SIZE: 0x4
		void * m_list_bpcp; //OFS: 0xA04 SIZE: 0x4
		int rope_id; //OFS: 0xA08 SIZE: 0x4
		void * rbc_dist; //OFS: 0xA0C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(RagdollBody, 0xA10);
	ASSERT_STRUCT_OFFSET(RagdollBody, references, 0x0);
	ASSERT_STRUCT_OFFSET(RagdollBody, ragdollDef, 0x4);
	ASSERT_STRUCT_OFFSET(RagdollBody, dobj, 0x8);
	ASSERT_STRUCT_OFFSET(RagdollBody, obj, 0xC);
	ASSERT_STRUCT_OFFSET(RagdollBody, pose, 0x10);
	ASSERT_STRUCT_OFFSET(RagdollBody, poseOffset, 0x14);
	ASSERT_STRUCT_OFFSET(RagdollBody, localClientNum, 0x20);
	ASSERT_STRUCT_OFFSET(RagdollBody, state, 0x24);
	ASSERT_STRUCT_OFFSET(RagdollBody, stateMsec, 0x28);
	ASSERT_STRUCT_OFFSET(RagdollBody, stateFrames, 0x2C);
	ASSERT_STRUCT_OFFSET(RagdollBody, velCaptureMsec, 0x30);
	ASSERT_STRUCT_OFFSET(RagdollBody, stableTime, 0x34);
	ASSERT_STRUCT_OFFSET(RagdollBody, numBones, 0x38);
	ASSERT_STRUCT_OFFSET(RagdollBody, bones, 0x3C);
	ASSERT_STRUCT_OFFSET(RagdollBody, numLerpBones, 0x1C4);
	ASSERT_STRUCT_OFFSET(RagdollBody, lerpBones, 0x1C8);
	ASSERT_STRUCT_OFFSET(RagdollBody, numJoints, 0x210);
	ASSERT_STRUCT_OFFSET(RagdollBody, joints, 0x214);
	ASSERT_STRUCT_OFFSET(RagdollBody, curOrientationBuffer, 0x2F4);
	ASSERT_STRUCT_OFFSET(RagdollBody, boneOrientations, 0x2F8);
	ASSERT_STRUCT_OFFSET(RagdollBody, lerpBoneOffsets, 0x8B8);
	ASSERT_STRUCT_OFFSET(RagdollBody, flags, 0x9D8);
	ASSERT_STRUCT_OFFSET(RagdollBody, storedLaunchCount, 0x9DC);
	ASSERT_STRUCT_OFFSET(RagdollBody, storedLaunchHitLoc, 0x9E0);
	ASSERT_STRUCT_OFFSET(RagdollBody, storedLaunchForce, 0x9E8);
	ASSERT_STRUCT_OFFSET(RagdollBody, m_bpg, 0xA00);
	ASSERT_STRUCT_OFFSET(RagdollBody, m_list_bpcp, 0xA04);
	ASSERT_STRUCT_OFFSET(RagdollBody, rope_id, 0xA08);
	ASSERT_STRUCT_OFFSET(RagdollBody, rbc_dist, 0xA0C);

	struct BoneDef
	{
		char animBoneTextNames[2][20]; //OFS: 0x0 SIZE: 0x28
		unsigned int animBoneNames[2]; //OFS: 0x28 SIZE: 0x8
		float radius; //OFS: 0x30 SIZE: 0x4
		bool mirror; //OFS: 0x34 SIZE: 0x1
		float percent; //OFS: 0x38 SIZE: 0x4
		float mass; //OFS: 0x3C SIZE: 0x4
		float friction; //OFS: 0x40 SIZE: 0x4
		float buoyancy; //OFS: 0x44 SIZE: 0x4
		int parentBone; //OFS: 0x48 SIZE: 0x4
		PhysicsGeomType geomType; //OFS: 0x4C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(BoneDef, 0x50);
	ASSERT_STRUCT_OFFSET(BoneDef, animBoneTextNames, 0x0);
	ASSERT_STRUCT_OFFSET(BoneDef, animBoneNames, 0x28);
	ASSERT_STRUCT_OFFSET(BoneDef, radius, 0x30);
	ASSERT_STRUCT_OFFSET(BoneDef, mirror, 0x34);
	ASSERT_STRUCT_OFFSET(BoneDef, percent, 0x38);
	ASSERT_STRUCT_OFFSET(BoneDef, mass, 0x3C);
	ASSERT_STRUCT_OFFSET(BoneDef, friction, 0x40);
	ASSERT_STRUCT_OFFSET(BoneDef, buoyancy, 0x44);
	ASSERT_STRUCT_OFFSET(BoneDef, parentBone, 0x48);
	ASSERT_STRUCT_OFFSET(BoneDef, geomType, 0x4C);

	struct BaseLerpBoneDef
	{
		char animBoneTextName[20]; //OFS: 0x0 SIZE: 0x14
		unsigned int animBoneName; //OFS: 0x14 SIZE: 0x4
		unsigned int parentBoneIndex; //OFS: 0x18 SIZE: 0x4
		int lerpTime; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(BaseLerpBoneDef, 0x20);
	ASSERT_STRUCT_OFFSET(BaseLerpBoneDef, animBoneTextName, 0x0);
	ASSERT_STRUCT_OFFSET(BaseLerpBoneDef, animBoneName, 0x14);
	ASSERT_STRUCT_OFFSET(BaseLerpBoneDef, parentBoneIndex, 0x18);
	ASSERT_STRUCT_OFFSET(BaseLerpBoneDef, lerpTime, 0x1C);

	struct JointDef
	{
		unsigned __int8 bone; //OFS: 0x0 SIZE: 0x1
		JointType type; //OFS: 0x4 SIZE: 0x4
		int numLimitAxes; //OFS: 0x8 SIZE: 0x4
		float limitAxes[3][3]; //OFS: 0xC SIZE: 0x24
		float minAngles[3]; //OFS: 0x30 SIZE: 0xC
		float maxAngles[3]; //OFS: 0x3C SIZE: 0xC
		float axisFriction[3]; //OFS: 0x48 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(JointDef, 0x54);
	ASSERT_STRUCT_OFFSET(JointDef, bone, 0x0);
	ASSERT_STRUCT_OFFSET(JointDef, type, 0x4);
	ASSERT_STRUCT_OFFSET(JointDef, numLimitAxes, 0x8);
	ASSERT_STRUCT_OFFSET(JointDef, limitAxes, 0xC);
	ASSERT_STRUCT_OFFSET(JointDef, minAngles, 0x30);
	ASSERT_STRUCT_OFFSET(JointDef, maxAngles, 0x3C);
	ASSERT_STRUCT_OFFSET(JointDef, axisFriction, 0x48);

	struct __declspec(align(1)) SelfPairDef
	{
		unsigned __int8 bones[2]; //OFS: 0x0 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(SelfPairDef, 0x2);
	ASSERT_STRUCT_OFFSET(SelfPairDef, bones, 0x0);

	struct RagdollDef
	{
		bool inUse; //OFS: 0x0 SIZE: 0x1
		bool bound; //OFS: 0x1 SIZE: 0x1
		int numBones; //OFS: 0x4 SIZE: 0x4
		BoneDef boneDefs[14]; //OFS: 0x8 SIZE: 0x460
		int numBaseLerpBones; //OFS: 0x468 SIZE: 0x4
		BaseLerpBoneDef baseLerpBoneDefs[9]; //OFS: 0x46C SIZE: 0x120
		int numJoints; //OFS: 0x58C SIZE: 0x4
		JointDef jointDefs[28]; //OFS: 0x590 SIZE: 0x930
		int numSelfPairs; //OFS: 0xEC0 SIZE: 0x4
		SelfPairDef selfPairDefs[33]; //OFS: 0xEC4 SIZE: 0x42
	};
	ASSERT_STRUCT_SIZE(RagdollDef, 0xF08);
	ASSERT_STRUCT_OFFSET(RagdollDef, inUse, 0x0);
	ASSERT_STRUCT_OFFSET(RagdollDef, bound, 0x1);
	ASSERT_STRUCT_OFFSET(RagdollDef, numBones, 0x4);
	ASSERT_STRUCT_OFFSET(RagdollDef, boneDefs, 0x8);
	ASSERT_STRUCT_OFFSET(RagdollDef, numBaseLerpBones, 0x468);
	ASSERT_STRUCT_OFFSET(RagdollDef, baseLerpBoneDefs, 0x46C);
	ASSERT_STRUCT_OFFSET(RagdollDef, numJoints, 0x58C);
	ASSERT_STRUCT_OFFSET(RagdollDef, jointDefs, 0x590);
	ASSERT_STRUCT_OFFSET(RagdollDef, numSelfPairs, 0xEC0);
	ASSERT_STRUCT_OFFSET(RagdollDef, selfPairDefs, 0xEC4);

	struct CameraShake
	{
		int time; //OFS: 0x0 SIZE: 0x4
		float scale; //OFS: 0x4 SIZE: 0x4
		float length; //OFS: 0x8 SIZE: 0x4
		float radius; //OFS: 0xC SIZE: 0x4
		float src[3]; //OFS: 0x10 SIZE: 0xC
		float size; //OFS: 0x1C SIZE: 0x4
		float rumbleScale; //OFS: 0x20 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(CameraShake, 0x24);
	ASSERT_STRUCT_OFFSET(CameraShake, time, 0x0);
	ASSERT_STRUCT_OFFSET(CameraShake, scale, 0x4);
	ASSERT_STRUCT_OFFSET(CameraShake, length, 0x8);
	ASSERT_STRUCT_OFFSET(CameraShake, radius, 0xC);
	ASSERT_STRUCT_OFFSET(CameraShake, src, 0x10);
	ASSERT_STRUCT_OFFSET(CameraShake, size, 0x1C);
	ASSERT_STRUCT_OFFSET(CameraShake, rumbleScale, 0x20);

	struct CameraShakeSet
	{
		CameraShake shakes[4]; //OFS: 0x0 SIZE: 0x90
		float phase; //OFS: 0x90 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(CameraShakeSet, 0x94);
	ASSERT_STRUCT_OFFSET(CameraShakeSet, shakes, 0x0);
	ASSERT_STRUCT_OFFSET(CameraShakeSet, phase, 0x90);

	struct DynEntityCollTree
	{
		float dist; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 axis; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 nextFree; //OFS: 0x6 SIZE: 0x2
		unsigned __int16 child[2]; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DynEntityCollTree, 0xC);
	ASSERT_STRUCT_OFFSET(DynEntityCollTree, dist, 0x0);
	ASSERT_STRUCT_OFFSET(DynEntityCollTree, axis, 0x4);
	ASSERT_STRUCT_OFFSET(DynEntityCollTree, nextFree, 0x6);
	ASSERT_STRUCT_OFFSET(DynEntityCollTree, child, 0x8);

	struct DynEntityCollSector
	{
		DynEntityCollTree tree; //OFS: 0x0 SIZE: 0xC
		int contents; //OFS: 0xC SIZE: 0x4
		unsigned __int16 entListHead; //OFS: 0x10 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(DynEntityCollSector, 0x14);
	ASSERT_STRUCT_OFFSET(DynEntityCollSector, tree, 0x0);
	ASSERT_STRUCT_OFFSET(DynEntityCollSector, contents, 0xC);
	ASSERT_STRUCT_OFFSET(DynEntityCollSector, entListHead, 0x10);

	struct DynEntityCollWorld
	{
		float mins[3]; //OFS: 0x0 SIZE: 0xC
		float maxs[3]; //OFS: 0xC SIZE: 0xC
		unsigned __int16 freeHead; //OFS: 0x18 SIZE: 0x2
		DynEntityCollSector sectors[1024]; //OFS: 0x1C SIZE: 0x5000
	};
	ASSERT_STRUCT_SIZE(DynEntityCollWorld, 0x501C);
	ASSERT_STRUCT_OFFSET(DynEntityCollWorld, mins, 0x0);
	ASSERT_STRUCT_OFFSET(DynEntityCollWorld, maxs, 0xC);
	ASSERT_STRUCT_OFFSET(DynEntityCollWorld, freeHead, 0x18);
	ASSERT_STRUCT_OFFSET(DynEntityCollWorld, sectors, 0x1C);

	struct CgEntCollTree
	{
		float dist; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 axis; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 nextFree; //OFS: 0x6 SIZE: 0x2
		unsigned __int16 child[2]; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(CgEntCollTree, 0xC);
	ASSERT_STRUCT_OFFSET(CgEntCollTree, dist, 0x0);
	ASSERT_STRUCT_OFFSET(CgEntCollTree, axis, 0x4);
	ASSERT_STRUCT_OFFSET(CgEntCollTree, nextFree, 0x6);
	ASSERT_STRUCT_OFFSET(CgEntCollTree, child, 0x8);

	struct CgEntCollSector
	{
		CgEntCollTree tree; //OFS: 0x0 SIZE: 0xC
		unsigned __int16 entListHead; //OFS: 0xC SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(CgEntCollSector, 0x10);
	ASSERT_STRUCT_OFFSET(CgEntCollSector, tree, 0x0);
	ASSERT_STRUCT_OFFSET(CgEntCollSector, entListHead, 0xC);

	struct CgEntCollWorld
	{
		float mins[3]; //OFS: 0x0 SIZE: 0xC
		float maxs[3]; //OFS: 0xC SIZE: 0xC
		unsigned __int16 freeHead; //OFS: 0x18 SIZE: 0x2
		CgEntCollSector sectors[1024]; //OFS: 0x1C SIZE: 0x4000
	};
	ASSERT_STRUCT_SIZE(CgEntCollWorld, 0x401C);
	ASSERT_STRUCT_OFFSET(CgEntCollWorld, mins, 0x0);
	ASSERT_STRUCT_OFFSET(CgEntCollWorld, maxs, 0xC);
	ASSERT_STRUCT_OFFSET(CgEntCollWorld, freeHead, 0x18);
	ASSERT_STRUCT_OFFSET(CgEntCollWorld, sectors, 0x1C);

	struct CgEntCollNode
	{
		unsigned __int16 sector; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 nextEntInSector; //OFS: 0x2 SIZE: 0x2
		float linkMins[2]; //OFS: 0x4 SIZE: 0x8
		float linkMaxs[2]; //OFS: 0xC SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(CgEntCollNode, 0x14);
	ASSERT_STRUCT_OFFSET(CgEntCollNode, sector, 0x0);
	ASSERT_STRUCT_OFFSET(CgEntCollNode, nextEntInSector, 0x2);
	ASSERT_STRUCT_OFFSET(CgEntCollNode, linkMins, 0x4);
	ASSERT_STRUCT_OFFSET(CgEntCollNode, linkMaxs, 0xC);

	struct pathstatic_t
	{
		pathlink_s * pathLinks; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 * indirectNodes; //OFS: 0x4 SIZE: 0x4
		char * pathbuf; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(pathstatic_t, 0xC);
	ASSERT_STRUCT_OFFSET(pathstatic_t, pathLinks, 0x0);
	ASSERT_STRUCT_OFFSET(pathstatic_t, indirectNodes, 0x4);
	ASSERT_STRUCT_OFFSET(pathstatic_t, pathbuf, 0x8);

	struct MemoryFile
	{
		unsigned __int8 * buffer; //OFS: 0x0 SIZE: 0x4
		int bufferSize; //OFS: 0x4 SIZE: 0x4
		int bytesUsed; //OFS: 0x8 SIZE: 0x4
		int cacheBufferUsed; //OFS: 0xC SIZE: 0x4
		int segmentIndex; //OFS: 0x10 SIZE: 0x4
		int segmentStart; //OFS: 0x14 SIZE: 0x4
		int nonZeroCount; //OFS: 0x18 SIZE: 0x4
		int zeroCount; //OFS: 0x1C SIZE: 0x4
		bool errorOnOverflow; //OFS: 0x20 SIZE: 0x1
		bool memoryOverflow; //OFS: 0x21 SIZE: 0x1
		bool compress_enabled; //OFS: 0x22 SIZE: 0x1
		bool rle_enabled; //OFS: 0x23 SIZE: 0x1
		bool is_writing; //OFS: 0x24 SIZE: 0x1
		z_stream_s stream; //OFS: 0x28 SIZE: 0x34
		unsigned __int8 cacheBuffer[32760]; //OFS: 0x5C SIZE: 0x7FF8
	};
	ASSERT_STRUCT_SIZE(MemoryFile, 0x8054);
	ASSERT_STRUCT_OFFSET(MemoryFile, buffer, 0x0);
	ASSERT_STRUCT_OFFSET(MemoryFile, bufferSize, 0x4);
	ASSERT_STRUCT_OFFSET(MemoryFile, bytesUsed, 0x8);
	ASSERT_STRUCT_OFFSET(MemoryFile, cacheBufferUsed, 0xC);
	ASSERT_STRUCT_OFFSET(MemoryFile, segmentIndex, 0x10);
	ASSERT_STRUCT_OFFSET(MemoryFile, segmentStart, 0x14);
	ASSERT_STRUCT_OFFSET(MemoryFile, nonZeroCount, 0x18);
	ASSERT_STRUCT_OFFSET(MemoryFile, zeroCount, 0x1C);
	ASSERT_STRUCT_OFFSET(MemoryFile, errorOnOverflow, 0x20);
	ASSERT_STRUCT_OFFSET(MemoryFile, memoryOverflow, 0x21);
	ASSERT_STRUCT_OFFSET(MemoryFile, compress_enabled, 0x22);
	ASSERT_STRUCT_OFFSET(MemoryFile, rle_enabled, 0x23);
	ASSERT_STRUCT_OFFSET(MemoryFile, is_writing, 0x24);
	ASSERT_STRUCT_OFFSET(MemoryFile, stream, 0x28);
	ASSERT_STRUCT_OFFSET(MemoryFile, cacheBuffer, 0x5C);

	struct qtime_s
	{
		int tm_sec; //OFS: 0x0 SIZE: 0x4
		int tm_min; //OFS: 0x4 SIZE: 0x4
		int tm_hour; //OFS: 0x8 SIZE: 0x4
		int tm_mday; //OFS: 0xC SIZE: 0x4
		int tm_mon; //OFS: 0x10 SIZE: 0x4
		int tm_year; //OFS: 0x14 SIZE: 0x4
		int tm_wday; //OFS: 0x18 SIZE: 0x4
		int tm_yday; //OFS: 0x1C SIZE: 0x4
		int tm_isdst; //OFS: 0x20 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(qtime_s, 0x24);
	ASSERT_STRUCT_OFFSET(qtime_s, tm_sec, 0x0);
	ASSERT_STRUCT_OFFSET(qtime_s, tm_min, 0x4);
	ASSERT_STRUCT_OFFSET(qtime_s, tm_hour, 0x8);
	ASSERT_STRUCT_OFFSET(qtime_s, tm_mday, 0xC);
	ASSERT_STRUCT_OFFSET(qtime_s, tm_mon, 0x10);
	ASSERT_STRUCT_OFFSET(qtime_s, tm_year, 0x14);
	ASSERT_STRUCT_OFFSET(qtime_s, tm_wday, 0x18);
	ASSERT_STRUCT_OFFSET(qtime_s, tm_yday, 0x1C);
	ASSERT_STRUCT_OFFSET(qtime_s, tm_isdst, 0x20);

	struct SaveHeader
	{
		int saveVersion; //OFS: 0x0 SIZE: 0x4
		int gameCheckSum; //OFS: 0x4 SIZE: 0x4
		int saveCheckSum; //OFS: 0x8 SIZE: 0x4
		int saveId; //OFS: 0xC SIZE: 0x4
		bool isUsingScriptChecksum; //OFS: 0x10 SIZE: 0x1
		int scrCheckSum[3]; //OFS: 0x14 SIZE: 0xC
		char mapName[256]; //OFS: 0x20 SIZE: 0x100
		char buildNumber[128]; //OFS: 0x120 SIZE: 0x80
		char campaign[256]; //OFS: 0x1A0 SIZE: 0x100
		char screenShotName[64]; //OFS: 0x2A0 SIZE: 0x40
		char description[256]; //OFS: 0x2E0 SIZE: 0x100
		char filename[64]; //OFS: 0x3E0 SIZE: 0x40
		int health; //OFS: 0x420 SIZE: 0x4
		int skill; //OFS: 0x424 SIZE: 0x4
		bool internalSave; //OFS: 0x428 SIZE: 0x1
		qtime_s time; //OFS: 0x42C SIZE: 0x24
		int server_bodySize; //OFS: 0x450 SIZE: 0x4
		int client_bodySize; //OFS: 0x454 SIZE: 0x4
		int pad[16]; //OFS: 0x458 SIZE: 0x40
	};
	ASSERT_STRUCT_SIZE(SaveHeader, 0x498);
	ASSERT_STRUCT_OFFSET(SaveHeader, saveVersion, 0x0);
	ASSERT_STRUCT_OFFSET(SaveHeader, gameCheckSum, 0x4);
	ASSERT_STRUCT_OFFSET(SaveHeader, saveCheckSum, 0x8);
	ASSERT_STRUCT_OFFSET(SaveHeader, saveId, 0xC);
	ASSERT_STRUCT_OFFSET(SaveHeader, isUsingScriptChecksum, 0x10);
	ASSERT_STRUCT_OFFSET(SaveHeader, scrCheckSum, 0x14);
	ASSERT_STRUCT_OFFSET(SaveHeader, mapName, 0x20);
	ASSERT_STRUCT_OFFSET(SaveHeader, buildNumber, 0x120);
	ASSERT_STRUCT_OFFSET(SaveHeader, campaign, 0x1A0);
	ASSERT_STRUCT_OFFSET(SaveHeader, screenShotName, 0x2A0);
	ASSERT_STRUCT_OFFSET(SaveHeader, description, 0x2E0);
	ASSERT_STRUCT_OFFSET(SaveHeader, filename, 0x3E0);
	ASSERT_STRUCT_OFFSET(SaveHeader, health, 0x420);
	ASSERT_STRUCT_OFFSET(SaveHeader, skill, 0x424);
	ASSERT_STRUCT_OFFSET(SaveHeader, internalSave, 0x428);
	ASSERT_STRUCT_OFFSET(SaveHeader, time, 0x42C);
	ASSERT_STRUCT_OFFSET(SaveHeader, server_bodySize, 0x450);
	ASSERT_STRUCT_OFFSET(SaveHeader, client_bodySize, 0x454);
	ASSERT_STRUCT_OFFSET(SaveHeader, pad, 0x458);

	struct SaveGame
	{
		MemoryFile server_memFile; //OFS: 0x0 SIZE: 0x8054
		MemoryFile client_memFile; //OFS: 0x8054 SIZE: 0x8054
		SaveBufferState saveState; //OFS: 0x100A8 SIZE: 0x4
		SaveHeader header; //OFS: 0x100AC SIZE: 0x498
		bool isUsingGlobalBuffer; //OFS: 0x10544 SIZE: 0x1
		bool isDirectWriteActive; //OFS: 0x10545 SIZE: 0x1
		bool isWrittenToDevice; //OFS: 0x10546 SIZE: 0x1
		bool suppressPlayerNotify; //OFS: 0x10547 SIZE: 0x1
		bool isClientDoneSaving; //OFS: 0x10548 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(SaveGame, 0x1054C);
	ASSERT_STRUCT_OFFSET(SaveGame, server_memFile, 0x0);
	ASSERT_STRUCT_OFFSET(SaveGame, client_memFile, 0x8054);
	ASSERT_STRUCT_OFFSET(SaveGame, saveState, 0x100A8);
	ASSERT_STRUCT_OFFSET(SaveGame, header, 0x100AC);
	ASSERT_STRUCT_OFFSET(SaveGame, isUsingGlobalBuffer, 0x10544);
	ASSERT_STRUCT_OFFSET(SaveGame, isDirectWriteActive, 0x10545);
	ASSERT_STRUCT_OFFSET(SaveGame, isWrittenToDevice, 0x10546);
	ASSERT_STRUCT_OFFSET(SaveGame, suppressPlayerNotify, 0x10547);
	ASSERT_STRUCT_OFFSET(SaveGame, isClientDoneSaving, 0x10548);

	struct parseInfo_t
	{
		char token[1024]; //OFS: 0x0 SIZE: 0x400
		int lines; //OFS: 0x400 SIZE: 0x4
		bool ungetToken; //OFS: 0x404 SIZE: 0x1
		bool spaceDelimited; //OFS: 0x405 SIZE: 0x1
		bool keepStringQuotes; //OFS: 0x406 SIZE: 0x1
		bool csv; //OFS: 0x407 SIZE: 0x1
		bool negativeNumbers; //OFS: 0x408 SIZE: 0x1
		char * errorPrefix; //OFS: 0x40C SIZE: 0x4
		char * warningPrefix; //OFS: 0x410 SIZE: 0x4
		int backup_lines; //OFS: 0x414 SIZE: 0x4
		char * backup_text; //OFS: 0x418 SIZE: 0x4
		char * parseFile; //OFS: 0x41C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(parseInfo_t, 0x420);
	ASSERT_STRUCT_OFFSET(parseInfo_t, token, 0x0);
	ASSERT_STRUCT_OFFSET(parseInfo_t, lines, 0x400);
	ASSERT_STRUCT_OFFSET(parseInfo_t, ungetToken, 0x404);
	ASSERT_STRUCT_OFFSET(parseInfo_t, spaceDelimited, 0x405);
	ASSERT_STRUCT_OFFSET(parseInfo_t, keepStringQuotes, 0x406);
	ASSERT_STRUCT_OFFSET(parseInfo_t, csv, 0x407);
	ASSERT_STRUCT_OFFSET(parseInfo_t, negativeNumbers, 0x408);
	ASSERT_STRUCT_OFFSET(parseInfo_t, errorPrefix, 0x40C);
	ASSERT_STRUCT_OFFSET(parseInfo_t, warningPrefix, 0x410);
	ASSERT_STRUCT_OFFSET(parseInfo_t, backup_lines, 0x414);
	ASSERT_STRUCT_OFFSET(parseInfo_t, backup_text, 0x418);
	ASSERT_STRUCT_OFFSET(parseInfo_t, parseFile, 0x41C);

	struct pml_t
	{
		float forward[3]; //OFS: 0x0 SIZE: 0xC
		float right[3]; //OFS: 0xC SIZE: 0xC
		float up[3]; //OFS: 0x18 SIZE: 0xC
		float frametime; //OFS: 0x24 SIZE: 0x4
		int msec; //OFS: 0x28 SIZE: 0x4
		int walking; //OFS: 0x2C SIZE: 0x4
		int groundPlane; //OFS: 0x30 SIZE: 0x4
		int almostGroundPlane; //OFS: 0x34 SIZE: 0x4
		trace_t groundTrace; //OFS: 0x38 SIZE: 0x34
		float impactSpeed; //OFS: 0x6C SIZE: 0x4
		float previous_origin[3]; //OFS: 0x70 SIZE: 0xC
		float previous_velocity[3]; //OFS: 0x7C SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(pml_t, 0x88);
	ASSERT_STRUCT_OFFSET(pml_t, forward, 0x0);
	ASSERT_STRUCT_OFFSET(pml_t, right, 0xC);
	ASSERT_STRUCT_OFFSET(pml_t, up, 0x18);
	ASSERT_STRUCT_OFFSET(pml_t, frametime, 0x24);
	ASSERT_STRUCT_OFFSET(pml_t, msec, 0x28);
	ASSERT_STRUCT_OFFSET(pml_t, walking, 0x2C);
	ASSERT_STRUCT_OFFSET(pml_t, groundPlane, 0x30);
	ASSERT_STRUCT_OFFSET(pml_t, almostGroundPlane, 0x34);
	ASSERT_STRUCT_OFFSET(pml_t, groundTrace, 0x38);
	ASSERT_STRUCT_OFFSET(pml_t, impactSpeed, 0x6C);
	ASSERT_STRUCT_OFFSET(pml_t, previous_origin, 0x70);
	ASSERT_STRUCT_OFFSET(pml_t, previous_velocity, 0x7C);

	struct saveField_t
	{
		int ofs; //OFS: 0x0 SIZE: 0x4
		saveFieldtype_t type; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(saveField_t, 0x8);
	ASSERT_STRUCT_OFFSET(saveField_t, ofs, 0x0);
	ASSERT_STRUCT_OFFSET(saveField_t, type, 0x4);

	struct SavedScreenParams
	{
		float s0; //OFS: 0x0 SIZE: 0x4
		float t0; //OFS: 0x4 SIZE: 0x4
		float _ds; //OFS: 0x8 SIZE: 0x4
		float dt; //OFS: 0xC SIZE: 0x4
		int isSet; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SavedScreenParams, 0x14);
	ASSERT_STRUCT_OFFSET(SavedScreenParams, s0, 0x0);
	ASSERT_STRUCT_OFFSET(SavedScreenParams, t0, 0x4);
	ASSERT_STRUCT_OFFSET(SavedScreenParams, _ds, 0x8);
	ASSERT_STRUCT_OFFSET(SavedScreenParams, dt, 0xC);
	ASSERT_STRUCT_OFFSET(SavedScreenParams, isSet, 0x10);

	struct r_global_permanent_t
	{
		Material * sortedMaterials[2048]; //OFS: 0x0 SIZE: 0x2000
		int needSortMaterials; //OFS: 0x2000 SIZE: 0x4
		int materialCount; //OFS: 0x2004 SIZE: 0x4
		int needMaterialPreload; //OFS: 0x2008 SIZE: 0x4
		GfxImage * whiteImage; //OFS: 0x200C SIZE: 0x4
		GfxImage * blackImage; //OFS: 0x2010 SIZE: 0x4
		GfxImage * blankImage; //OFS: 0x2014 SIZE: 0x4
		GfxImage * grayImage; //OFS: 0x2018 SIZE: 0x4
		GfxImage * identityNormalMapImage; //OFS: 0x201C SIZE: 0x4
		GfxImage * specularityImage; //OFS: 0x2020 SIZE: 0x4
		GfxImage * outdoorImage; //OFS: 0x2024 SIZE: 0x4
		GfxImage * pixelCostColorCode; //OFS: 0x2028 SIZE: 0x4
		GfxLightDef * dlightDef; //OFS: 0x202C SIZE: 0x4
		Material * defaultMaterial; //OFS: 0x2030 SIZE: 0x4
		Material * whiteMaterial; //OFS: 0x2034 SIZE: 0x4
		Material * additiveMaterial; //OFS: 0x2038 SIZE: 0x4
		Material * additiveMaterialNoDepth; //OFS: 0x203C SIZE: 0x4
		Material * pointMaterial; //OFS: 0x2040 SIZE: 0x4
		Material * lineMaterial; //OFS: 0x2044 SIZE: 0x4
		Material * lineMaterialNoDepth; //OFS: 0x2048 SIZE: 0x4
		Material * clearAlphaMaterial; //OFS: 0x204C SIZE: 0x4
		Material * clearAlphaStencilMaterial; //OFS: 0x2050 SIZE: 0x4
		Material * shadowClearMaterial; //OFS: 0x2054 SIZE: 0x4
		Material * shadowCookieOverlayMaterial; //OFS: 0x2058 SIZE: 0x4
		Material * shadowCookieBlurMaterial; //OFS: 0x205C SIZE: 0x4
		Material * shadowCasterMaterial; //OFS: 0x2060 SIZE: 0x4
		Material * shadowOverlayMaterial; //OFS: 0x2064 SIZE: 0x4
		Material * depthPrepassMaterial; //OFS: 0x2068 SIZE: 0x4
		Material * glareBlindMaterial; //OFS: 0x206C SIZE: 0x4
		Material * lightCoronaMaterial; //OFS: 0x2070 SIZE: 0x4
		Material * pixelCostAddDepthAlwaysMaterial; //OFS: 0x2074 SIZE: 0x4
		Material * pixelCostAddDepthDisableMaterial; //OFS: 0x2078 SIZE: 0x4
		Material * pixelCostAddDepthEqualMaterial; //OFS: 0x207C SIZE: 0x4
		Material * pixelCostAddDepthLessMaterial; //OFS: 0x2080 SIZE: 0x4
		Material * pixelCostAddDepthWriteMaterial; //OFS: 0x2084 SIZE: 0x4
		Material * pixelCostAddNoDepthWriteMaterial; //OFS: 0x2088 SIZE: 0x4
		Material * pixelCostColorCodeMaterial; //OFS: 0x208C SIZE: 0x4
		Material * stencilShadowMaterial; //OFS: 0x2090 SIZE: 0x4
		Material * stencilDisplayMaterial; //OFS: 0x2094 SIZE: 0x4
		Material * floatZDisplayMaterial; //OFS: 0x2098 SIZE: 0x4
		Material * colorChannelMixerMaterial; //OFS: 0x209C SIZE: 0x4
		Material * frameColorDebugMaterial; //OFS: 0x20A0 SIZE: 0x4
		Material * frameAlphaDebugMaterial; //OFS: 0x20A4 SIZE: 0x4
		GfxImage * rawImage; //OFS: 0x20A8 SIZE: 0x4
		GfxWorld * world; //OFS: 0x20AC SIZE: 0x4
		Material * feedbackReplaceMaterial; //OFS: 0x20B0 SIZE: 0x4
		Material * feedbackBlendMaterial; //OFS: 0x20B4 SIZE: 0x4
		Material * feedbackFilmBlendMaterial; //OFS: 0x20B8 SIZE: 0x4
		Material * cinematicMaterial; //OFS: 0x20BC SIZE: 0x4
		Material * flameThrowerFXMaterial; //OFS: 0x20C0 SIZE: 0x4
		Material * waterSheetingFXMaterial; //OFS: 0x20C4 SIZE: 0x4
		Material * waterDropletMaterial; //OFS: 0x20C8 SIZE: 0x4
		Material * reviveFXMaterial; //OFS: 0x20CC SIZE: 0x4
		Material * postFxColorMaterial; //OFS: 0x20D0 SIZE: 0x4
		Material * postFxMaterial; //OFS: 0x20D4 SIZE: 0x4
		Material * poisonFXMaterial; //OFS: 0x20D8 SIZE: 0x4
		Material * symmetricFilterMaterial[8]; //OFS: 0x20DC SIZE: 0x20
		Material * godRaysFilterMaterial; //OFS: 0x20FC SIZE: 0x4
		Material * shellShockBlurredMaterial; //OFS: 0x2100 SIZE: 0x4
		Material * shellShockFlashedMaterial; //OFS: 0x2104 SIZE: 0x4
		Material * glowConsistentSetupMaterial; //OFS: 0x2108 SIZE: 0x4
		Material * glowApplyBloomMaterial; //OFS: 0x210C SIZE: 0x4
		Material * ropeMaterial; //OFS: 0x2110 SIZE: 0x4
		int savedScreenTimes[4]; //OFS: 0x2114 SIZE: 0x10
		SavedScreenParams savedScreenParams[4]; //OFS: 0x2124 SIZE: 0x50
		GfxImage * terrain_scorch_images[31]; //OFS: 0x2174 SIZE: 0x7C
		GfxImage * splitscreen_sidebars; //OFS: 0x21F0 SIZE: 0x4
		char pad[140]; //OFS: 0x21F4 SIZE: 0x8C
	};
	ASSERT_STRUCT_SIZE(r_global_permanent_t, 0x2280);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, sortedMaterials, 0x0);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, needSortMaterials, 0x2000);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, materialCount, 0x2004);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, needMaterialPreload, 0x2008);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, whiteImage, 0x200C);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, blackImage, 0x2010);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, blankImage, 0x2014);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, grayImage, 0x2018);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, identityNormalMapImage, 0x201C);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, specularityImage, 0x2020);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, outdoorImage, 0x2024);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, pixelCostColorCode, 0x2028);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, dlightDef, 0x202C);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, defaultMaterial, 0x2030);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, whiteMaterial, 0x2034);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, additiveMaterial, 0x2038);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, additiveMaterialNoDepth, 0x203C);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, pointMaterial, 0x2040);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, lineMaterial, 0x2044);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, lineMaterialNoDepth, 0x2048);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, clearAlphaMaterial, 0x204C);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, clearAlphaStencilMaterial, 0x2050);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, shadowClearMaterial, 0x2054);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, shadowCookieOverlayMaterial, 0x2058);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, shadowCookieBlurMaterial, 0x205C);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, shadowCasterMaterial, 0x2060);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, shadowOverlayMaterial, 0x2064);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, depthPrepassMaterial, 0x2068);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, glareBlindMaterial, 0x206C);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, lightCoronaMaterial, 0x2070);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, pixelCostAddDepthAlwaysMaterial, 0x2074);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, pixelCostAddDepthDisableMaterial, 0x2078);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, pixelCostAddDepthEqualMaterial, 0x207C);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, pixelCostAddDepthLessMaterial, 0x2080);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, pixelCostAddDepthWriteMaterial, 0x2084);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, pixelCostAddNoDepthWriteMaterial, 0x2088);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, pixelCostColorCodeMaterial, 0x208C);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, stencilShadowMaterial, 0x2090);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, stencilDisplayMaterial, 0x2094);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, floatZDisplayMaterial, 0x2098);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, colorChannelMixerMaterial, 0x209C);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, frameColorDebugMaterial, 0x20A0);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, frameAlphaDebugMaterial, 0x20A4);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, rawImage, 0x20A8);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, world, 0x20AC);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, feedbackReplaceMaterial, 0x20B0);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, feedbackBlendMaterial, 0x20B4);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, feedbackFilmBlendMaterial, 0x20B8);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, cinematicMaterial, 0x20BC);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, flameThrowerFXMaterial, 0x20C0);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, waterSheetingFXMaterial, 0x20C4);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, waterDropletMaterial, 0x20C8);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, reviveFXMaterial, 0x20CC);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, postFxColorMaterial, 0x20D0);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, postFxMaterial, 0x20D4);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, poisonFXMaterial, 0x20D8);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, symmetricFilterMaterial, 0x20DC);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, godRaysFilterMaterial, 0x20FC);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, shellShockBlurredMaterial, 0x2100);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, shellShockFlashedMaterial, 0x2104);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, glowConsistentSetupMaterial, 0x2108);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, glowApplyBloomMaterial, 0x210C);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, ropeMaterial, 0x2110);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, savedScreenTimes, 0x2114);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, savedScreenParams, 0x2124);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, terrain_scorch_images, 0x2174);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, splitscreen_sidebars, 0x21F0);
	ASSERT_STRUCT_OFFSET(r_global_permanent_t, pad, 0x21F4);

	// r_globals_t

	struct BspLumpData_t
	{
		char name[64]; //OFS: 0x0 SIZE: 0x40
		void * header; //OFS: 0x40 SIZE: 0x4
		unsigned int fileSize; //OFS: 0x44 SIZE: 0x4
		unsigned int checksum; //OFS: 0x48 SIZE: 0x4
		LumpType loadedLumpType; //OFS: 0x4C SIZE: 0x4
		const void * loadedLumpData; //OFS: 0x50 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(BspLumpData_t, 0x54);
	ASSERT_STRUCT_OFFSET(BspLumpData_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(BspLumpData_t, header, 0x40);
	ASSERT_STRUCT_OFFSET(BspLumpData_t, fileSize, 0x44);
	ASSERT_STRUCT_OFFSET(BspLumpData_t, checksum, 0x48);
	ASSERT_STRUCT_OFFSET(BspLumpData_t, loadedLumpType, 0x4C);
	ASSERT_STRUCT_OFFSET(BspLumpData_t, loadedLumpData, 0x50);

	struct nodespawn_t
	{
		char * name; //OFS: 0x0 SIZE: 0x4
		nodeType type; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(nodespawn_t, 0x8);
	ASSERT_STRUCT_OFFSET(nodespawn_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(nodespawn_t, type, 0x4);

	struct keyname_t
	{
		char * name; //OFS: 0x0 SIZE: 0x4
		int keynum; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(keyname_t, 0x8);
	ASSERT_STRUCT_OFFSET(keyname_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(keyname_t, keynum, 0x4);

	struct visField_t
	{
		const char * name; //OFS: 0x0 SIZE: 0x4
		int offset; //OFS: 0x4 SIZE: 0x4
		int fieldType; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(visField_t, 0xC);
	ASSERT_STRUCT_OFFSET(visField_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(visField_t, offset, 0x4);
	ASSERT_STRUCT_OFFSET(visField_t, fieldType, 0x8);

	struct directive_s
	{
		char * name; //OFS: 0x0 SIZE: 0x4
		int (__cdecl *func)(source_s *); //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(directive_s, 0x8);
	ASSERT_STRUCT_OFFSET(directive_s, name, 0x0);
	ASSERT_STRUCT_OFFSET(directive_s, func, 0x4);

	struct viewLerpWaypoint_s
	{
		int iFrac; //OFS: 0x0 SIZE: 0x4
		float fViewHeight; //OFS: 0x4 SIZE: 0x4
		int iOffset; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(viewLerpWaypoint_s, 0xC);
	ASSERT_STRUCT_OFFSET(viewLerpWaypoint_s, iFrac, 0x0);
	ASSERT_STRUCT_OFFSET(viewLerpWaypoint_s, fViewHeight, 0x4);
	ASSERT_STRUCT_OFFSET(viewLerpWaypoint_s, iOffset, 0x8);

	struct pmoveHandler_t
	{
		void (__cdecl *trace)(trace_t *, const float *, const float *, const float *, const float *, int, int, void *); //OFS: 0x0 SIZE: 0x4
		void * water; //OFS: 0x4 SIZE: 0x4
		void (__cdecl *playerEvent)(int, int); //OFS: 0x8 SIZE: 0x4
		bool (__cdecl *getEntityOriginAngles)(int, int, float *, float *); //OFS: 0xC SIZE: 0x4
		unsigned __int16 (__cdecl *getVehicleTypeString)(int, int); //OFS: 0x10 SIZE: 0x4
		void (__cdecl *entityLinkFromPMove)(int, int, const int); //OFS: 0x14 SIZE: 0x4
		int (__cdecl *getPlayerWeapon)(const playerState_s *, const int); //OFS: 0x18 SIZE: 0x4
		void (__cdecl *setVehDriverInputs)(const int, const int, usercmd_s *); //OFS: 0x1C SIZE: 0x4
		int (__cdecl *isEntWalkable)(const int, const int); //OFS: 0x20 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(pmoveHandler_t, 0x24);
	ASSERT_STRUCT_OFFSET(pmoveHandler_t, trace, 0x0);
	ASSERT_STRUCT_OFFSET(pmoveHandler_t, water, 0x4);
	ASSERT_STRUCT_OFFSET(pmoveHandler_t, playerEvent, 0x8);
	ASSERT_STRUCT_OFFSET(pmoveHandler_t, getEntityOriginAngles, 0xC);
	ASSERT_STRUCT_OFFSET(pmoveHandler_t, getVehicleTypeString, 0x10);
	ASSERT_STRUCT_OFFSET(pmoveHandler_t, entityLinkFromPMove, 0x14);
	ASSERT_STRUCT_OFFSET(pmoveHandler_t, getPlayerWeapon, 0x18);
	ASSERT_STRUCT_OFFSET(pmoveHandler_t, setVehDriverInputs, 0x1C);
	ASSERT_STRUCT_OFFSET(pmoveHandler_t, isEntWalkable, 0x20);

	struct CustomSearchInfo_FindPath
	{
		pathnode_t * m_pNodeTo; //OFS: 0x0 SIZE: 0x4
		float startPos[3]; //OFS: 0x4 SIZE: 0xC
		float negotiationOverlapCost; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(CustomSearchInfo_FindPath, 0x14);
	ASSERT_STRUCT_OFFSET(CustomSearchInfo_FindPath, m_pNodeTo, 0x0);
	ASSERT_STRUCT_OFFSET(CustomSearchInfo_FindPath, startPos, 0x4);
	ASSERT_STRUCT_OFFSET(CustomSearchInfo_FindPath, negotiationOverlapCost, 0x10);

	struct threat_bias_t
	{
		unsigned __int16 groupName[16]; //OFS: 0x0 SIZE: 0x20
		int threatTable[16][16]; //OFS: 0x20 SIZE: 0x400
		int threatGroupCount; //OFS: 0x420 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(threat_bias_t, 0x424);
	ASSERT_STRUCT_OFFSET(threat_bias_t, groupName, 0x0);
	ASSERT_STRUCT_OFFSET(threat_bias_t, threatTable, 0x20);
	ASSERT_STRUCT_OFFSET(threat_bias_t, threatGroupCount, 0x420);

	struct nodetype
	{
		nodetype * left; //OFS: 0x0 SIZE: 0x4
		nodetype * right; //OFS: 0x4 SIZE: 0x4
		nodetype * parent; //OFS: 0x8 SIZE: 0x4
		int weight; //OFS: 0xC SIZE: 0x4
		int symbol; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(nodetype, 0x14);
	ASSERT_STRUCT_OFFSET(nodetype, left, 0x0);
	ASSERT_STRUCT_OFFSET(nodetype, right, 0x4);
	ASSERT_STRUCT_OFFSET(nodetype, parent, 0x8);
	ASSERT_STRUCT_OFFSET(nodetype, weight, 0xC);
	ASSERT_STRUCT_OFFSET(nodetype, symbol, 0x10);

	struct huff_t
	{
		int blocNode; //OFS: 0x0 SIZE: 0x4
		int blocPtrs; //OFS: 0x4 SIZE: 0x4
		nodetype * tree; //OFS: 0x8 SIZE: 0x4
		nodetype * loc[257]; //OFS: 0xC SIZE: 0x404
		nodetype ** freelist; //OFS: 0x410 SIZE: 0x4
		nodetype nodeList[768]; //OFS: 0x414 SIZE: 0x3C00
		nodetype * nodePtrs[768]; //OFS: 0x4014 SIZE: 0xC00
	};
	ASSERT_STRUCT_SIZE(huff_t, 0x4C14);
	ASSERT_STRUCT_OFFSET(huff_t, blocNode, 0x0);
	ASSERT_STRUCT_OFFSET(huff_t, blocPtrs, 0x4);
	ASSERT_STRUCT_OFFSET(huff_t, tree, 0x8);
	ASSERT_STRUCT_OFFSET(huff_t, loc, 0xC);
	ASSERT_STRUCT_OFFSET(huff_t, freelist, 0x410);
	ASSERT_STRUCT_OFFSET(huff_t, nodeList, 0x414);
	ASSERT_STRUCT_OFFSET(huff_t, nodePtrs, 0x4014);

	struct huffman_t
	{
		huff_t compressDecompress; //OFS: 0x0 SIZE: 0x4C14
	};
	ASSERT_STRUCT_SIZE(huffman_t, 0x4C14);
	ASSERT_STRUCT_OFFSET(huffman_t, compressDecompress, 0x0);

	struct snapshotEntityNumbers_t
	{
		int numSnapshotEntities; //OFS: 0x0 SIZE: 0x4
		int snapshotEntities[1024]; //OFS: 0x4 SIZE: 0x1000
	};
	ASSERT_STRUCT_SIZE(snapshotEntityNumbers_t, 0x1004);
	ASSERT_STRUCT_OFFSET(snapshotEntityNumbers_t, numSnapshotEntities, 0x0);
	ASSERT_STRUCT_OFFSET(snapshotEntityNumbers_t, snapshotEntities, 0x4);

	struct AttractorRepulsor_t
	{
		bool inUse; //OFS: 0x0 SIZE: 0x1
		bool isAttractor; //OFS: 0x1 SIZE: 0x1
		int entnum; //OFS: 0x4 SIZE: 0x4
		float origin[3]; //OFS: 0x8 SIZE: 0xC
		float strength; //OFS: 0x14 SIZE: 0x4
		float maxDist; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(AttractorRepulsor_t, 0x1C);
	ASSERT_STRUCT_OFFSET(AttractorRepulsor_t, inUse, 0x0);
	ASSERT_STRUCT_OFFSET(AttractorRepulsor_t, isAttractor, 0x1);
	ASSERT_STRUCT_OFFSET(AttractorRepulsor_t, entnum, 0x4);
	ASSERT_STRUCT_OFFSET(AttractorRepulsor_t, origin, 0x8);
	ASSERT_STRUCT_OFFSET(AttractorRepulsor_t, strength, 0x14);
	ASSERT_STRUCT_OFFSET(AttractorRepulsor_t, maxDist, 0x18);

	struct attrGlob_t
	{
		AttractorRepulsor_t attractors[32]; //OFS: 0x0 SIZE: 0x380
	};
	ASSERT_STRUCT_SIZE(attrGlob_t, 0x380);
	ASSERT_STRUCT_OFFSET(attrGlob_t, attractors, 0x0);

	struct actor_physics_local_t
	{
		float fFrameTime; //OFS: 0x0 SIZE: 0x4
		int bIsWalking; //OFS: 0x4 SIZE: 0x4
		int bGroundPlane; //OFS: 0x8 SIZE: 0x4
		trace_t groundTrace; //OFS: 0xC SIZE: 0x34
		float fImpactSpeed; //OFS: 0x40 SIZE: 0x4
		float vPrevOrigin[3]; //OFS: 0x44 SIZE: 0xC
		float vPrevVelocity[3]; //OFS: 0x50 SIZE: 0xC
		int iTraceMask; //OFS: 0x5C SIZE: 0x4
		float stepheight; //OFS: 0x60 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(actor_physics_local_t, 0x64);
	ASSERT_STRUCT_OFFSET(actor_physics_local_t, fFrameTime, 0x0);
	ASSERT_STRUCT_OFFSET(actor_physics_local_t, bIsWalking, 0x4);
	ASSERT_STRUCT_OFFSET(actor_physics_local_t, bGroundPlane, 0x8);
	ASSERT_STRUCT_OFFSET(actor_physics_local_t, groundTrace, 0xC);
	ASSERT_STRUCT_OFFSET(actor_physics_local_t, fImpactSpeed, 0x40);
	ASSERT_STRUCT_OFFSET(actor_physics_local_t, vPrevOrigin, 0x44);
	ASSERT_STRUCT_OFFSET(actor_physics_local_t, vPrevVelocity, 0x50);
	ASSERT_STRUCT_OFFSET(actor_physics_local_t, iTraceMask, 0x5C);
	ASSERT_STRUCT_OFFSET(actor_physics_local_t, stepheight, 0x60);

	struct ai_funcs_t
	{
		bool (__cdecl *pfnStart)(actor_s *pSelf, ai_state_t ePrevState); //OFS: 0x0 SIZE: 0x4
		void (__cdecl *pfnFinish)(actor_s *pSelf, ai_state_t eNextState); //OFS: 0x4 SIZE: 0x4
		void (__cdecl *pfnSuspend)(actor_s *pSelf, ai_state_t eNextState); //OFS: 0x8 SIZE: 0x4
		bool (__cdecl *pfnResume)(actor_s *pSelf, ai_state_t ePrevState); //OFS: 0xC SIZE: 0x4
		actor_think_result_t (__cdecl *pfnThink)(actor_s *pSelf); //OFS: 0x10 SIZE: 0x4
		void (__cdecl *pfnTouch)(actor_s *pSelf, gentity_s *pOther); //OFS: 0x14 SIZE: 0x4
		void (__cdecl *pfnPain)(actor_s *pSelf, gentity_s *pAttacker, int iDamage, float *vPoint, int iMod, float *vDir, hitLocation_t hitLoc); //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ai_funcs_t, 0x1C);
	ASSERT_STRUCT_OFFSET(ai_funcs_t, pfnStart, 0x0);
	ASSERT_STRUCT_OFFSET(ai_funcs_t, pfnFinish, 0x4);
	ASSERT_STRUCT_OFFSET(ai_funcs_t, pfnSuspend, 0x8);
	ASSERT_STRUCT_OFFSET(ai_funcs_t, pfnResume, 0xC);
	ASSERT_STRUCT_OFFSET(ai_funcs_t, pfnThink, 0x10);
	ASSERT_STRUCT_OFFSET(ai_funcs_t, pfnTouch, 0x14);
	ASSERT_STRUCT_OFFSET(ai_funcs_t, pfnPain, 0x18);

	struct AimTarget
	{
		int entIndex; //OFS: 0x0 SIZE: 0x4
		float worldDistSqr; //OFS: 0x4 SIZE: 0x4
		float mins[3]; //OFS: 0x8 SIZE: 0xC
		float maxs[3]; //OFS: 0x14 SIZE: 0xC
		float velocity[3]; //OFS: 0x20 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(AimTarget, 0x2C);
	ASSERT_STRUCT_OFFSET(AimTarget, entIndex, 0x0);
	ASSERT_STRUCT_OFFSET(AimTarget, worldDistSqr, 0x4);
	ASSERT_STRUCT_OFFSET(AimTarget, mins, 0x8);
	ASSERT_STRUCT_OFFSET(AimTarget, maxs, 0x14);
	ASSERT_STRUCT_OFFSET(AimTarget, velocity, 0x20);

	struct AimTargetGlob
	{
		AimTarget targets[64]; //OFS: 0x0 SIZE: 0xB00
		int targetCount; //OFS: 0xB00 SIZE: 0x4
		AimTarget clientTargets[64]; //OFS: 0xB04 SIZE: 0xB00
		int clientTargetCount; //OFS: 0x1604 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(AimTargetGlob, 0x1608);
	ASSERT_STRUCT_OFFSET(AimTargetGlob, targets, 0x0);
	ASSERT_STRUCT_OFFSET(AimTargetGlob, targetCount, 0xB00);
	ASSERT_STRUCT_OFFSET(AimTargetGlob, clientTargets, 0xB04);
	ASSERT_STRUCT_OFFSET(AimTargetGlob, clientTargetCount, 0x1604);

	struct ThreadDebugInfo
	{
		const char * pos[32]; //OFS: 0x0 SIZE: 0x80
		int posSize; //OFS: 0x80 SIZE: 0x4
		float varUsage; //OFS: 0x84 SIZE: 0x4
		float endonUsage; //OFS: 0x88 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ThreadDebugInfo, 0x8C);
	ASSERT_STRUCT_OFFSET(ThreadDebugInfo, pos, 0x0);
	ASSERT_STRUCT_OFFSET(ThreadDebugInfo, posSize, 0x80);
	ASSERT_STRUCT_OFFSET(ThreadDebugInfo, varUsage, 0x84);
	ASSERT_STRUCT_OFFSET(ThreadDebugInfo, endonUsage, 0x88);

	struct configstringBundle
	{
		int index; //OFS: 0x0 SIZE: 0x4
		char * val; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(configstringBundle, 0x8);
	ASSERT_STRUCT_OFFSET(configstringBundle, index, 0x0);
	ASSERT_STRUCT_OFFSET(configstringBundle, val, 0x4);

	struct fake_centity_s
	{
		unsigned int flags; //OFS: 0x0 SIZE: 0x4
		snd_alias_t * soundAliasPtr; //OFS: 0x4 SIZE: 0x4
		centity_s cent; //OFS: 0x8 SIZE: 0x2D4
		char soundAlias[64]; //OFS: 0x2DC SIZE: 0x40
	};
	ASSERT_STRUCT_SIZE(fake_centity_s, 0x31C);
	ASSERT_STRUCT_OFFSET(fake_centity_s, flags, 0x0);
	ASSERT_STRUCT_OFFSET(fake_centity_s, soundAliasPtr, 0x4);
	ASSERT_STRUCT_OFFSET(fake_centity_s, cent, 0x8);
	ASSERT_STRUCT_OFFSET(fake_centity_s, soundAlias, 0x2DC);

	struct LayeredTechniqueSetName
	{
		const char * inputName; //OFS: 0x0 SIZE: 0x4
		const char * namePrefixRegister; //OFS: 0x4 SIZE: 0x4
		const char * namePrefixGenerate; //OFS: 0x8 SIZE: 0x4
		const char * nameChunk; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(LayeredTechniqueSetName, 0x10);
	ASSERT_STRUCT_OFFSET(LayeredTechniqueSetName, inputName, 0x0);
	ASSERT_STRUCT_OFFSET(LayeredTechniqueSetName, namePrefixRegister, 0x4);
	ASSERT_STRUCT_OFFSET(LayeredTechniqueSetName, namePrefixGenerate, 0x8);
	ASSERT_STRUCT_OFFSET(LayeredTechniqueSetName, nameChunk, 0xC);

	struct cgMedia_t
	{
		Material * whiteMaterial; //OFS: 0x0 SIZE: 0x4
		int field_4; //OFS: 0x4 SIZE: 0x4
		int field_8; //OFS: 0x8 SIZE: 0x4
		int field_C; //OFS: 0xC SIZE: 0x4
		int field_10; //OFS: 0x10 SIZE: 0x4
		int field_14; //OFS: 0x14 SIZE: 0x4
		int field_18; //OFS: 0x18 SIZE: 0x4
		int field_1C; //OFS: 0x1C SIZE: 0x4
		int field_20; //OFS: 0x20 SIZE: 0x4
		int field_24; //OFS: 0x24 SIZE: 0x4
		int field_28; //OFS: 0x28 SIZE: 0x4
		int field_2C; //OFS: 0x2C SIZE: 0x4
		int field_30[3]; //OFS: 0x30 SIZE: 0xC
		int field_3C; //OFS: 0x3C SIZE: 0x4
		int field_40; //OFS: 0x40 SIZE: 0x4
		int field_44; //OFS: 0x44 SIZE: 0x4
		int field_48[129]; //OFS: 0x48 SIZE: 0x204
		int field_24C; //OFS: 0x24C SIZE: 0x4
		int field_250; //OFS: 0x250 SIZE: 0x4
		int field_254; //OFS: 0x254 SIZE: 0x4
		int field_258; //OFS: 0x258 SIZE: 0x4
		int field_25C; //OFS: 0x25C SIZE: 0x4
		int field_260[1]; //OFS: 0x260 SIZE: 0x4
		int field_264; //OFS: 0x264 SIZE: 0x4
		int field_268; //OFS: 0x268 SIZE: 0x4
		int field_26C; //OFS: 0x26C SIZE: 0x4
		int field_270; //OFS: 0x270 SIZE: 0x4
		int field_274; //OFS: 0x274 SIZE: 0x4
		int field_278; //OFS: 0x278 SIZE: 0x4
		int field_27C; //OFS: 0x27C SIZE: 0x4
		int field_280; //OFS: 0x280 SIZE: 0x4
		int cgMedia_smallDevFont; //OFS: 0x284 SIZE: 0x4
		int field_288; //OFS: 0x288 SIZE: 0x4
		int field_28C; //OFS: 0x28C SIZE: 0x4
		int field_290; //OFS: 0x290 SIZE: 0x4
		int field_294[31]; //OFS: 0x294 SIZE: 0x7C
		int field_310[31]; //OFS: 0x310 SIZE: 0x7C
		int field_38C[31]; //OFS: 0x38C SIZE: 0x7C
		int field_408[31]; //OFS: 0x408 SIZE: 0x7C
		int field_484[1]; //OFS: 0x484 SIZE: 0x4
		char field_488[120]; //OFS: 0x488 SIZE: 0x78
		int field_500[31]; //OFS: 0x500 SIZE: 0x7C
		int field_57C[31]; //OFS: 0x57C SIZE: 0x7C
		int field_5F8[31]; //OFS: 0x5F8 SIZE: 0x7C
		int field_674[31]; //OFS: 0x674 SIZE: 0x7C
		int field_6F0[31]; //OFS: 0x6F0 SIZE: 0x7C
		int field_76C[31]; //OFS: 0x76C SIZE: 0x7C
		int field_7E8[31]; //OFS: 0x7E8 SIZE: 0x7C
		int field_864[31]; //OFS: 0x864 SIZE: 0x7C
		int field_8E0[31]; //OFS: 0x8E0 SIZE: 0x7C
		_DWORD field_95C[31]; //OFS: 0x95C SIZE: 0x7C
		int field_9D8[31]; //OFS: 0x9D8 SIZE: 0x7C
		_DWORD field_A54[31]; //OFS: 0xA54 SIZE: 0x7C
		int field_AD0[31]; //OFS: 0xAD0 SIZE: 0x7C
		_DWORD field_B4C[31]; //OFS: 0xB4C SIZE: 0x7C
		int field_BC8[31]; //OFS: 0xBC8 SIZE: 0x7C
		_DWORD field_C44[31]; //OFS: 0xC44 SIZE: 0x7C
		int field_CC0[31]; //OFS: 0xCC0 SIZE: 0x7C
		_DWORD field_D3C[31]; //OFS: 0xD3C SIZE: 0x7C
		int field_DB8[31]; //OFS: 0xDB8 SIZE: 0x7C
		_DWORD field_E34[24]; //OFS: 0xE34 SIZE: 0x60
		int field_E94[7]; //OFS: 0xE94 SIZE: 0x1C
		int field_EB0[24]; //OFS: 0xEB0 SIZE: 0x60
		int field_F10[7]; //OFS: 0xF10 SIZE: 0x1C
		_DWORD field_F2C[24]; //OFS: 0xF2C SIZE: 0x60
		int field_F8C[7]; //OFS: 0xF8C SIZE: 0x1C
		int field_FA8[24]; //OFS: 0xFA8 SIZE: 0x60
		int field_1008[7]; //OFS: 0x1008 SIZE: 0x1C
		_DWORD field_1024[31]; //OFS: 0x1024 SIZE: 0x7C
		_DWORD field_10A0[31]; //OFS: 0x10A0 SIZE: 0x7C
		_DWORD field_111C[31]; //OFS: 0x111C SIZE: 0x7C
		_DWORD field_1198[31]; //OFS: 0x1198 SIZE: 0x7C
		_DWORD field_1214[31]; //OFS: 0x1214 SIZE: 0x7C
		int field_1290; //OFS: 0x1290 SIZE: 0x4
		int field_1294; //OFS: 0x1294 SIZE: 0x4
		int field_1298; //OFS: 0x1298 SIZE: 0x4
		int field_129C; //OFS: 0x129C SIZE: 0x4
		int field_12A0; //OFS: 0x12A0 SIZE: 0x4
		int field_12A4; //OFS: 0x12A4 SIZE: 0x4
		int field_12A8; //OFS: 0x12A8 SIZE: 0x4
		int field_12AC; //OFS: 0x12AC SIZE: 0x4
		int field_12B0; //OFS: 0x12B0 SIZE: 0x4
		int field_12B4; //OFS: 0x12B4 SIZE: 0x4
		int field_12B8; //OFS: 0x12B8 SIZE: 0x4
		int field_12BC; //OFS: 0x12BC SIZE: 0x4
		int field_12C0; //OFS: 0x12C0 SIZE: 0x4
		int field_12C4; //OFS: 0x12C4 SIZE: 0x4
		int field_12C8; //OFS: 0x12C8 SIZE: 0x4
		int field_12CC; //OFS: 0x12CC SIZE: 0x4
		int field_12D0; //OFS: 0x12D0 SIZE: 0x4
		int field_12D4; //OFS: 0x12D4 SIZE: 0x4
		int field_12D8; //OFS: 0x12D8 SIZE: 0x4
		int field_12DC; //OFS: 0x12DC SIZE: 0x4
		int field_12E0; //OFS: 0x12E0 SIZE: 0x4
		int field_12E4; //OFS: 0x12E4 SIZE: 0x4
		int field_12E8; //OFS: 0x12E8 SIZE: 0x4
		int field_12EC; //OFS: 0x12EC SIZE: 0x4
		int field_12F0; //OFS: 0x12F0 SIZE: 0x4
		int field_12F4; //OFS: 0x12F4 SIZE: 0x4
		int field_12F8; //OFS: 0x12F8 SIZE: 0x4
		int field_12FC; //OFS: 0x12FC SIZE: 0x4
		int field_1300; //OFS: 0x1300 SIZE: 0x4
		int field_1304; //OFS: 0x1304 SIZE: 0x4
		_DWORD field_1308[1550]; //OFS: 0x1308 SIZE: 0x1838
		int field_2B40; //OFS: 0x2B40 SIZE: 0x4
		int field_2B44; //OFS: 0x2B44 SIZE: 0x4
		int field_2B48; //OFS: 0x2B48 SIZE: 0x4
		int field_2B4C; //OFS: 0x2B4C SIZE: 0x4
		int field_2B50; //OFS: 0x2B50 SIZE: 0x4
		int field_2B54; //OFS: 0x2B54 SIZE: 0x4
		int field_2B58; //OFS: 0x2B58 SIZE: 0x4
		int field_2B5C; //OFS: 0x2B5C SIZE: 0x4
		int field_2B60; //OFS: 0x2B60 SIZE: 0x4
		int field_2B64; //OFS: 0x2B64 SIZE: 0x4
		int field_2B68; //OFS: 0x2B68 SIZE: 0x4
		int field_2B6C; //OFS: 0x2B6C SIZE: 0x4
		int field_2B70; //OFS: 0x2B70 SIZE: 0x4
		int field_2B74; //OFS: 0x2B74 SIZE: 0x4
		int field_2B78; //OFS: 0x2B78 SIZE: 0x4
		int field_2B7C; //OFS: 0x2B7C SIZE: 0x4
		_BYTE gap2B80[8]; //OFS: 0x2B80 SIZE: 0x8
		int field_2B88; //OFS: 0x2B88 SIZE: 0x4
		int field_2B8C; //OFS: 0x2B8C SIZE: 0x4
		int field_2B90; //OFS: 0x2B90 SIZE: 0x4
		Material * hud_grenadeicon; //OFS: 0x2B94 SIZE: 0x4
		Material * hud_flashbangicon; //OFS: 0x2B98 SIZE: 0x4
		Material * hud_grenadethrowback; //OFS: 0x2B9C SIZE: 0x4
		int hud_grenadepointer; //OFS: 0x2BA0 SIZE: 0x4
		int field_2BA4; //OFS: 0x2BA4 SIZE: 0x4
		int field_2BA8; //OFS: 0x2BA8 SIZE: 0x4
		Material * offscreenObjectivePointer; //OFS: 0x2BAC SIZE: 0x4
		int field_2BB0; //OFS: 0x2BB0 SIZE: 0x4
		char field_2BB4[4]; //OFS: 0x2BB4 SIZE: 0x4
		int field_2BB8; //OFS: 0x2BB8 SIZE: 0x4
		int field_2BBC; //OFS: 0x2BBC SIZE: 0x4
		int field_2BC0; //OFS: 0x2BC0 SIZE: 0x4
		int field_2BC4; //OFS: 0x2BC4 SIZE: 0x4
		int field_2BC8; //OFS: 0x2BC8 SIZE: 0x4
		int field_2BCC; //OFS: 0x2BCC SIZE: 0x4
		int field_2BD0; //OFS: 0x2BD0 SIZE: 0x4
		int field_2BD4; //OFS: 0x2BD4 SIZE: 0x4
		int field_2BD8; //OFS: 0x2BD8 SIZE: 0x4
		int field_2BDC; //OFS: 0x2BDC SIZE: 0x4
		int field_2BE0; //OFS: 0x2BE0 SIZE: 0x4
		int field_2BE4; //OFS: 0x2BE4 SIZE: 0x4
		int field_2BE8; //OFS: 0x2BE8 SIZE: 0x4
		int field_2BEC; //OFS: 0x2BEC SIZE: 0x4
		int field_2BF0; //OFS: 0x2BF0 SIZE: 0x4
		int field_2BF4; //OFS: 0x2BF4 SIZE: 0x4
		int field_2BF8; //OFS: 0x2BF8 SIZE: 0x4
		int nightVisionOverlay; //OFS: 0x2BFC SIZE: 0x4
		_BYTE gap2C00[4]; //OFS: 0x2C00 SIZE: 0x4
		int field_2C04; //OFS: 0x2C04 SIZE: 0x4
		int field_2C08; //OFS: 0x2C08 SIZE: 0x4
		int field_2C0C; //OFS: 0x2C0C SIZE: 0x4
		int field_2C10; //OFS: 0x2C10 SIZE: 0x4
		int field_2C14; //OFS: 0x2C14 SIZE: 0x4
		int field_2C18; //OFS: 0x2C18 SIZE: 0x4
		int field_2C1C; //OFS: 0x2C1C SIZE: 0x4
		Material * textDecodeCharacters; //OFS: 0x2C20 SIZE: 0x4
		Material * textDecodeCharactersGlow; //OFS: 0x2C24 SIZE: 0x4
		_BYTE gap2C28[32]; //OFS: 0x2C28 SIZE: 0x20
		int field_2C48[1]; //OFS: 0x2C48 SIZE: 0x4
		int field_2C4C; //OFS: 0x2C4C SIZE: 0x4
		int field_2C50; //OFS: 0x2C50 SIZE: 0x4
		int field_2C54; //OFS: 0x2C54 SIZE: 0x4
		int field_2C58; //OFS: 0x2C58 SIZE: 0x4
		int field_2C5C; //OFS: 0x2C5C SIZE: 0x4
		int field_2C60; //OFS: 0x2C60 SIZE: 0x4
		int field_2C64; //OFS: 0x2C64 SIZE: 0x4
		int field_2C68; //OFS: 0x2C68 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(cgMedia_t, 0x2C6C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, whiteMaterial, 0x0);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_4, 0x4);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_8, 0x8);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_C, 0xC);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_10, 0x10);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_14, 0x14);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_18, 0x18);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_1C, 0x1C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_20, 0x20);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_24, 0x24);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_28, 0x28);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2C, 0x2C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_30, 0x30);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_3C, 0x3C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_40, 0x40);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_44, 0x44);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_48, 0x48);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_24C, 0x24C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_250, 0x250);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_254, 0x254);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_258, 0x258);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_25C, 0x25C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_260, 0x260);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_264, 0x264);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_268, 0x268);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_26C, 0x26C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_270, 0x270);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_274, 0x274);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_278, 0x278);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_27C, 0x27C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_280, 0x280);
	ASSERT_STRUCT_OFFSET(cgMedia_t, cgMedia_smallDevFont, 0x284);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_288, 0x288);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_28C, 0x28C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_290, 0x290);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_294, 0x294);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_310, 0x310);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_38C, 0x38C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_408, 0x408);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_484, 0x484);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_488, 0x488);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_500, 0x500);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_57C, 0x57C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_5F8, 0x5F8);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_674, 0x674);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_6F0, 0x6F0);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_76C, 0x76C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_7E8, 0x7E8);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_864, 0x864);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_8E0, 0x8E0);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_95C, 0x95C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_9D8, 0x9D8);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_A54, 0xA54);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_AD0, 0xAD0);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_B4C, 0xB4C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_BC8, 0xBC8);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_C44, 0xC44);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_CC0, 0xCC0);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_D3C, 0xD3C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_DB8, 0xDB8);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_E34, 0xE34);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_E94, 0xE94);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_EB0, 0xEB0);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_F10, 0xF10);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_F2C, 0xF2C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_F8C, 0xF8C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_FA8, 0xFA8);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_1008, 0x1008);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_1024, 0x1024);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_10A0, 0x10A0);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_111C, 0x111C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_1198, 0x1198);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_1214, 0x1214);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_1290, 0x1290);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_1294, 0x1294);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_1298, 0x1298);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_129C, 0x129C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12A0, 0x12A0);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12A4, 0x12A4);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12A8, 0x12A8);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12AC, 0x12AC);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12B0, 0x12B0);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12B4, 0x12B4);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12B8, 0x12B8);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12BC, 0x12BC);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12C0, 0x12C0);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12C4, 0x12C4);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12C8, 0x12C8);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12CC, 0x12CC);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12D0, 0x12D0);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12D4, 0x12D4);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12D8, 0x12D8);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12DC, 0x12DC);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12E0, 0x12E0);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12E4, 0x12E4);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12E8, 0x12E8);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12EC, 0x12EC);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12F0, 0x12F0);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12F4, 0x12F4);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12F8, 0x12F8);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_12FC, 0x12FC);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_1300, 0x1300);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_1304, 0x1304);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_1308, 0x1308);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2B40, 0x2B40);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2B44, 0x2B44);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2B48, 0x2B48);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2B4C, 0x2B4C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2B50, 0x2B50);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2B54, 0x2B54);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2B58, 0x2B58);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2B5C, 0x2B5C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2B60, 0x2B60);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2B64, 0x2B64);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2B68, 0x2B68);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2B6C, 0x2B6C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2B70, 0x2B70);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2B74, 0x2B74);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2B78, 0x2B78);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2B7C, 0x2B7C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, gap2B80, 0x2B80);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2B88, 0x2B88);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2B8C, 0x2B8C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2B90, 0x2B90);
	ASSERT_STRUCT_OFFSET(cgMedia_t, hud_grenadeicon, 0x2B94);
	ASSERT_STRUCT_OFFSET(cgMedia_t, hud_flashbangicon, 0x2B98);
	ASSERT_STRUCT_OFFSET(cgMedia_t, hud_grenadethrowback, 0x2B9C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, hud_grenadepointer, 0x2BA0);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2BA4, 0x2BA4);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2BA8, 0x2BA8);
	ASSERT_STRUCT_OFFSET(cgMedia_t, offscreenObjectivePointer, 0x2BAC);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2BB0, 0x2BB0);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2BB4, 0x2BB4);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2BB8, 0x2BB8);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2BBC, 0x2BBC);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2BC0, 0x2BC0);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2BC4, 0x2BC4);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2BC8, 0x2BC8);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2BCC, 0x2BCC);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2BD0, 0x2BD0);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2BD4, 0x2BD4);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2BD8, 0x2BD8);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2BDC, 0x2BDC);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2BE0, 0x2BE0);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2BE4, 0x2BE4);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2BE8, 0x2BE8);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2BEC, 0x2BEC);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2BF0, 0x2BF0);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2BF4, 0x2BF4);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2BF8, 0x2BF8);
	ASSERT_STRUCT_OFFSET(cgMedia_t, nightVisionOverlay, 0x2BFC);
	ASSERT_STRUCT_OFFSET(cgMedia_t, gap2C00, 0x2C00);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2C04, 0x2C04);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2C08, 0x2C08);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2C0C, 0x2C0C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2C10, 0x2C10);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2C14, 0x2C14);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2C18, 0x2C18);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2C1C, 0x2C1C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, textDecodeCharacters, 0x2C20);
	ASSERT_STRUCT_OFFSET(cgMedia_t, textDecodeCharactersGlow, 0x2C24);
	ASSERT_STRUCT_OFFSET(cgMedia_t, gap2C28, 0x2C28);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2C48, 0x2C48);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2C4C, 0x2C4C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2C50, 0x2C50);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2C54, 0x2C54);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2C58, 0x2C58);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2C5C, 0x2C5C);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2C60, 0x2C60);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2C64, 0x2C64);
	ASSERT_STRUCT_OFFSET(cgMedia_t, field_2C68, 0x2C68);

	struct gitem_s
	{
		itemType_t giType; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(gitem_s, 0x4);
	ASSERT_STRUCT_OFFSET(gitem_s, giType, 0x0);

	struct weaponInfo_s
	{
		DObj_s * viewModelDObj; //OFS: 0x0 SIZE: 0x4
		XModel * handModel; //OFS: 0x4 SIZE: 0x4
		XModel * gogglesModel; //OFS: 0x8 SIZE: 0x4
		XModel * rocketModel; //OFS: 0xC SIZE: 0x4
		XModel * knifeModel; //OFS: 0x10 SIZE: 0x4
		unsigned __int8 weapModelIdx; //OFS: 0x14 SIZE: 0x1
		unsigned int partBits[4]; //OFS: 0x18 SIZE: 0x10
		int iPrevAnim; //OFS: 0x28 SIZE: 0x4
		int hasAnimTree; //OFS: 0x2C SIZE: 0x4
		XAnimTree_s * tree; //OFS: 0x30 SIZE: 0x4
		int registered; //OFS: 0x34 SIZE: 0x4
		gitem_s * item; //OFS: 0x38 SIZE: 0x4
		char * translatedDisplayName; //OFS: 0x3C SIZE: 0x4
		char * translatedModename; //OFS: 0x40 SIZE: 0x4
		char * translatedAIOverlayDescription; //OFS: 0x44 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(weaponInfo_s, 0x48);
	ASSERT_STRUCT_OFFSET(weaponInfo_s, viewModelDObj, 0x0);
	ASSERT_STRUCT_OFFSET(weaponInfo_s, handModel, 0x4);
	ASSERT_STRUCT_OFFSET(weaponInfo_s, gogglesModel, 0x8);
	ASSERT_STRUCT_OFFSET(weaponInfo_s, rocketModel, 0xC);
	ASSERT_STRUCT_OFFSET(weaponInfo_s, knifeModel, 0x10);
	ASSERT_STRUCT_OFFSET(weaponInfo_s, weapModelIdx, 0x14);
	ASSERT_STRUCT_OFFSET(weaponInfo_s, partBits, 0x18);
	ASSERT_STRUCT_OFFSET(weaponInfo_s, iPrevAnim, 0x28);
	ASSERT_STRUCT_OFFSET(weaponInfo_s, hasAnimTree, 0x2C);
	ASSERT_STRUCT_OFFSET(weaponInfo_s, tree, 0x30);
	ASSERT_STRUCT_OFFSET(weaponInfo_s, registered, 0x34);
	ASSERT_STRUCT_OFFSET(weaponInfo_s, item, 0x38);
	ASSERT_STRUCT_OFFSET(weaponInfo_s, translatedDisplayName, 0x3C);
	ASSERT_STRUCT_OFFSET(weaponInfo_s, translatedModename, 0x40);
	ASSERT_STRUCT_OFFSET(weaponInfo_s, translatedAIOverlayDescription, 0x44);

	struct CompassVehicle
	{
		int entityNum; //OFS: 0x0 SIZE: 0x4
		int lastUpdate; //OFS: 0x4 SIZE: 0x4
		float lastPos[2]; //OFS: 0x8 SIZE: 0x8
		float lastYaw; //OFS: 0x10 SIZE: 0x4
		int drawOnCompass; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(CompassVehicle, 0x18);
	ASSERT_STRUCT_OFFSET(CompassVehicle, entityNum, 0x0);
	ASSERT_STRUCT_OFFSET(CompassVehicle, lastUpdate, 0x4);
	ASSERT_STRUCT_OFFSET(CompassVehicle, lastPos, 0x8);
	ASSERT_STRUCT_OFFSET(CompassVehicle, lastYaw, 0x10);
	ASSERT_STRUCT_OFFSET(CompassVehicle, drawOnCompass, 0x14);

	struct CompassActor
	{
		int lastUpdate; //OFS: 0x0 SIZE: 0x4
		float lastPos[2]; //OFS: 0x4 SIZE: 0x8
		float lastYaw; //OFS: 0xC SIZE: 0x4
		int beginFadeTime; //OFS: 0x10 SIZE: 0x4
		bool enemy; //OFS: 0x14 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(CompassActor, 0x18);
	ASSERT_STRUCT_OFFSET(CompassActor, lastUpdate, 0x0);
	ASSERT_STRUCT_OFFSET(CompassActor, lastPos, 0x4);
	ASSERT_STRUCT_OFFSET(CompassActor, lastYaw, 0xC);
	ASSERT_STRUCT_OFFSET(CompassActor, beginFadeTime, 0x10);
	ASSERT_STRUCT_OFFSET(CompassActor, enemy, 0x14);

	struct DeferredMsg
	{
		unsigned __int8 data[1264]; //OFS: 0x0 SIZE: 0x4F0
		int datalen; //OFS: 0x4F0 SIZE: 0x4
		int j; //OFS: 0x4F4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DeferredMsg, 0x4F8);
	ASSERT_STRUCT_OFFSET(DeferredMsg, data, 0x0);
	ASSERT_STRUCT_OFFSET(DeferredMsg, datalen, 0x4F0);
	ASSERT_STRUCT_OFFSET(DeferredMsg, j, 0x4F4);

	struct DeferredQueue
	{
		DeferredMsg msgs[16]; //OFS: 0x0 SIZE: 0x4F80
		int get; //OFS: 0x4F80 SIZE: 0x4
		int send; //OFS: 0x4F84 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DeferredQueue, 0x4F88);
	ASSERT_STRUCT_OFFSET(DeferredQueue, msgs, 0x0);
	ASSERT_STRUCT_OFFSET(DeferredQueue, get, 0x4F80);
	ASSERT_STRUCT_OFFSET(DeferredQueue, send, 0x4F84);

	struct struc_838200
	{
		int field_0; //OFS: 0x0 SIZE: 0x4
		int field_4; //OFS: 0x4 SIZE: 0x4
		void * field_8; //OFS: 0x8 SIZE: 0x4
		int field_C; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(struc_838200, 0x10);
	ASSERT_STRUCT_OFFSET(struc_838200, field_0, 0x0);
	ASSERT_STRUCT_OFFSET(struc_838200, field_4, 0x4);
	ASSERT_STRUCT_OFFSET(struc_838200, field_8, 0x8);
	ASSERT_STRUCT_OFFSET(struc_838200, field_C, 0xC);

	struct ClientVoicePacket_t
	{
		char data[256]; //OFS: 0x0 SIZE: 0x100
		int dataSize; //OFS: 0x100 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ClientVoicePacket_t, 0x104);
	ASSERT_STRUCT_OFFSET(ClientVoicePacket_t, data, 0x0);
	ASSERT_STRUCT_OFFSET(ClientVoicePacket_t, dataSize, 0x100);

	struct voiceCommunication_t
	{
		ClientVoicePacket_t voicePackets[10]; //OFS: 0x0 SIZE: 0xA28
		int voicePacketCount; //OFS: 0xA28 SIZE: 0x4
		int voicePacketLastTransmit; //OFS: 0xA2C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(voiceCommunication_t, 0xA30);
	ASSERT_STRUCT_OFFSET(voiceCommunication_t, voicePackets, 0x0);
	ASSERT_STRUCT_OFFSET(voiceCommunication_t, voicePacketCount, 0xA28);
	ASSERT_STRUCT_OFFSET(voiceCommunication_t, voicePacketLastTransmit, 0xA2C);

	struct __declspec(align(2)) EntHandleList
	{
		unsigned __int16 infoIndex; //OFS: 0x0 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(EntHandleList, 0x2);
	ASSERT_STRUCT_OFFSET(EntHandleList, infoIndex, 0x0);

	struct GfxEntity
	{
		unsigned int renderFxFlags; //OFS: 0x0 SIZE: 0x4
		float materialTime; //OFS: 0x4 SIZE: 0x4
		float destructibleBurnAmount; //OFS: 0x8 SIZE: 0x4
		float destructibleFadeAmount; //OFS: 0xC SIZE: 0x4
		float modelRadius; //OFS: 0x10 SIZE: 0x4
		float wetness; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxEntity, 0x18);
	ASSERT_STRUCT_OFFSET(GfxEntity, renderFxFlags, 0x0);
	ASSERT_STRUCT_OFFSET(GfxEntity, materialTime, 0x4);
	ASSERT_STRUCT_OFFSET(GfxEntity, destructibleBurnAmount, 0x8);
	ASSERT_STRUCT_OFFSET(GfxEntity, destructibleFadeAmount, 0xC);
	ASSERT_STRUCT_OFFSET(GfxEntity, modelRadius, 0x10);
	ASSERT_STRUCT_OFFSET(GfxEntity, wetness, 0x14);

	struct localEntity_s
	{
		localEntity_s * prev; //OFS: 0x0 SIZE: 0x4
		localEntity_s * next; //OFS: 0x4 SIZE: 0x4
		leType_t leType; //OFS: 0x8 SIZE: 0x4
		int endTime; //OFS: 0xC SIZE: 0x4
		trajectory_t pos; //OFS: 0x10 SIZE: 0x24
		float color[4]; //OFS: 0x34 SIZE: 0x10
		float tracerClipDist; //OFS: 0x44 SIZE: 0x4
		GfxEntity refEntity; //OFS: 0x48 SIZE: 0x18
	};
	ASSERT_STRUCT_SIZE(localEntity_s, 0x60);
	ASSERT_STRUCT_OFFSET(localEntity_s, prev, 0x0);
	ASSERT_STRUCT_OFFSET(localEntity_s, next, 0x4);
	ASSERT_STRUCT_OFFSET(localEntity_s, leType, 0x8);
	ASSERT_STRUCT_OFFSET(localEntity_s, endTime, 0xC);
	ASSERT_STRUCT_OFFSET(localEntity_s, pos, 0x10);
	ASSERT_STRUCT_OFFSET(localEntity_s, color, 0x34);
	ASSERT_STRUCT_OFFSET(localEntity_s, tracerClipDist, 0x44);
	ASSERT_STRUCT_OFFSET(localEntity_s, refEntity, 0x48);

	struct lagometer_t
	{
		int frameSamples[128]; //OFS: 0x0 SIZE: 0x200
		int frameCount; //OFS: 0x200 SIZE: 0x4
		int snapshotFlags[128]; //OFS: 0x204 SIZE: 0x200
		int snapshotSamples[128]; //OFS: 0x404 SIZE: 0x200
		int snapshotCount; //OFS: 0x604 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(lagometer_t, 0x608);
	ASSERT_STRUCT_OFFSET(lagometer_t, frameSamples, 0x0);
	ASSERT_STRUCT_OFFSET(lagometer_t, frameCount, 0x200);
	ASSERT_STRUCT_OFFSET(lagometer_t, snapshotFlags, 0x204);
	ASSERT_STRUCT_OFFSET(lagometer_t, snapshotSamples, 0x404);
	ASSERT_STRUCT_OFFSET(lagometer_t, snapshotCount, 0x604);

	struct serverStatus_s
	{
		char string[8192]; //OFS: 0x0 SIZE: 0x2000
		netadr_s address; //OFS: 0x2000 SIZE: 0x18
		int time; //OFS: 0x2018 SIZE: 0x4
		int startTime; //OFS: 0x201C SIZE: 0x4
		int pending; //OFS: 0x2020 SIZE: 0x4
		int print; //OFS: 0x2024 SIZE: 0x4
		int retrieved; //OFS: 0x2028 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(serverStatus_s, 0x202C);
	ASSERT_STRUCT_OFFSET(serverStatus_s, string, 0x0);
	ASSERT_STRUCT_OFFSET(serverStatus_s, address, 0x2000);
	ASSERT_STRUCT_OFFSET(serverStatus_s, time, 0x2018);
	ASSERT_STRUCT_OFFSET(serverStatus_s, startTime, 0x201C);
	ASSERT_STRUCT_OFFSET(serverStatus_s, pending, 0x2020);
	ASSERT_STRUCT_OFFSET(serverStatus_s, print, 0x2024);
	ASSERT_STRUCT_OFFSET(serverStatus_s, retrieved, 0x2028);

	struct ClientSnapshotData
	{
		int snapshotSize[8]; //OFS: 0x0 SIZE: 0x20
		int compressedSize[8]; //OFS: 0x20 SIZE: 0x20
		int index; //OFS: 0x40 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ClientSnapshotData, 0x44);
	ASSERT_STRUCT_OFFSET(ClientSnapshotData, snapshotSize, 0x0);
	ASSERT_STRUCT_OFFSET(ClientSnapshotData, compressedSize, 0x20);
	ASSERT_STRUCT_OFFSET(ClientSnapshotData, index, 0x40);

	struct hunkUsed_t
	{
		int permanent; //OFS: 0x0 SIZE: 0x4
		int temp; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(hunkUsed_t, 0x8);
	ASSERT_STRUCT_OFFSET(hunkUsed_t, permanent, 0x0);
	ASSERT_STRUCT_OFFSET(hunkUsed_t, temp, 0x4);

	struct struc_21AC318
	{
		int com_list_cache; //OFS: 0x0 SIZE: 0x4
		int field_4; //OFS: 0x4 SIZE: 0x4
		int field_8; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(struc_21AC318, 0xC);
	ASSERT_STRUCT_OFFSET(struc_21AC318, com_list_cache, 0x0);
	ASSERT_STRUCT_OFFSET(struc_21AC318, field_4, 0x4);
	ASSERT_STRUCT_OFFSET(struc_21AC318, field_8, 0x8);

	struct fileData_s
	{
		void * data; //OFS: 0x0 SIZE: 0x4
		fileData_s * next; //OFS: 0x4 SIZE: 0x4
		unsigned __int8 type; //OFS: 0x8 SIZE: 0x1
		char name[1]; //OFS: 0x9 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(fileData_s, 0xC);
	ASSERT_STRUCT_OFFSET(fileData_s, data, 0x0);
	ASSERT_STRUCT_OFFSET(fileData_s, next, 0x4);
	ASSERT_STRUCT_OFFSET(fileData_s, type, 0x8);
	ASSERT_STRUCT_OFFSET(fileData_s, name, 0x9);

	struct WinVars_t
	{
		HINSTANCE__ * reflib_library; //OFS: 0x0 SIZE: 0x4
		int reflib_active; //OFS: 0x4 SIZE: 0x4
		HWND__ * hWnd; //OFS: 0x8 SIZE: 0x4
		HINSTANCE__ * hInstance; //OFS: 0xC SIZE: 0x4
		int activeApp; //OFS: 0x10 SIZE: 0x4
		int isMinimized; //OFS: 0x14 SIZE: 0x4
		int recenterMouse; //OFS: 0x18 SIZE: 0x4
		unsigned int sysMsgTime; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(WinVars_t, 0x20);
	ASSERT_STRUCT_OFFSET(WinVars_t, reflib_library, 0x0);
	ASSERT_STRUCT_OFFSET(WinVars_t, reflib_active, 0x4);
	ASSERT_STRUCT_OFFSET(WinVars_t, hWnd, 0x8);
	ASSERT_STRUCT_OFFSET(WinVars_t, hInstance, 0xC);
	ASSERT_STRUCT_OFFSET(WinVars_t, activeApp, 0x10);
	ASSERT_STRUCT_OFFSET(WinVars_t, isMinimized, 0x14);
	ASSERT_STRUCT_OFFSET(WinVars_t, recenterMouse, 0x18);
	ASSERT_STRUCT_OFFSET(WinVars_t, sysMsgTime, 0x1C);

	struct _pendedBadPlace
	{
		badplace_parms_t params; //OFS: 0x0 SIZE: 0x1C
		unsigned int name; //OFS: 0x1C SIZE: 0x4
		int duration; //OFS: 0x20 SIZE: 0x4
		int teamflags; //OFS: 0x24 SIZE: 0x4
		int type; //OFS: 0x28 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(_pendedBadPlace, 0x2C);
	ASSERT_STRUCT_OFFSET(_pendedBadPlace, params, 0x0);
	ASSERT_STRUCT_OFFSET(_pendedBadPlace, name, 0x1C);
	ASSERT_STRUCT_OFFSET(_pendedBadPlace, duration, 0x20);
	ASSERT_STRUCT_OFFSET(_pendedBadPlace, teamflags, 0x24);
	ASSERT_STRUCT_OFFSET(_pendedBadPlace, type, 0x28);

	struct EntHandleInfo
	{
		void * handle; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 next; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 prev; //OFS: 0x6 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(EntHandleInfo, 0x8);
	ASSERT_STRUCT_OFFSET(EntHandleInfo, handle, 0x0);
	ASSERT_STRUCT_OFFSET(EntHandleInfo, next, 0x4);
	ASSERT_STRUCT_OFFSET(EntHandleInfo, prev, 0x6);

	struct StreamPosInfo
	{
		char * pos; //OFS: 0x0 SIZE: 0x4
		unsigned int index; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(StreamPosInfo, 0x8);
	ASSERT_STRUCT_OFFSET(StreamPosInfo, pos, 0x0);
	ASSERT_STRUCT_OFFSET(StreamPosInfo, index, 0x4);

	struct pushed_t
	{
		gentity_s * ent; //OFS: 0x0 SIZE: 0x4
		float origin[3]; //OFS: 0x4 SIZE: 0xC
		float angles[3]; //OFS: 0x10 SIZE: 0xC
		float surfaceNormal[3]; //OFS: 0x1C SIZE: 0xC
		float deltayaw; //OFS: 0x28 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(pushed_t, 0x2C);
	ASSERT_STRUCT_OFFSET(pushed_t, ent, 0x0);
	ASSERT_STRUCT_OFFSET(pushed_t, origin, 0x4);
	ASSERT_STRUCT_OFFSET(pushed_t, angles, 0x10);
	ASSERT_STRUCT_OFFSET(pushed_t, surfaceNormal, 0x1C);
	ASSERT_STRUCT_OFFSET(pushed_t, deltayaw, 0x28);

	struct target_t
	{
		gentity_s * ent; //OFS: 0x0 SIZE: 0x4
		float offset[3]; //OFS: 0x4 SIZE: 0xC
		int materialIndex; //OFS: 0x10 SIZE: 0x4
		int offscreenMaterialIndex; //OFS: 0x14 SIZE: 0x4
		int flags; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(target_t, 0x1C);
	ASSERT_STRUCT_OFFSET(target_t, ent, 0x0);
	ASSERT_STRUCT_OFFSET(target_t, offset, 0x4);
	ASSERT_STRUCT_OFFSET(target_t, materialIndex, 0x10);
	ASSERT_STRUCT_OFFSET(target_t, offscreenMaterialIndex, 0x14);
	ASSERT_STRUCT_OFFSET(target_t, flags, 0x18);

	struct node_params_t
	{
		char classname[64]; //OFS: 0x0 SIZE: 0x40
		char targetname[64]; //OFS: 0x40 SIZE: 0x40
		unsigned __int16 targetname_hash; //OFS: 0x80 SIZE: 0x2
		char target[64]; //OFS: 0x82 SIZE: 0x40
		char target2[64]; //OFS: 0xC2 SIZE: 0x40
		float origin[3]; //OFS: 0x104 SIZE: 0xC
		float angles[3]; //OFS: 0x110 SIZE: 0xC
		int used; //OFS: 0x11C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(node_params_t, 0x120);
	ASSERT_STRUCT_OFFSET(node_params_t, classname, 0x0);
	ASSERT_STRUCT_OFFSET(node_params_t, targetname, 0x40);
	ASSERT_STRUCT_OFFSET(node_params_t, targetname_hash, 0x80);
	ASSERT_STRUCT_OFFSET(node_params_t, target, 0x82);
	ASSERT_STRUCT_OFFSET(node_params_t, target2, 0xC2);
	ASSERT_STRUCT_OFFSET(node_params_t, origin, 0x104);
	ASSERT_STRUCT_OFFSET(node_params_t, angles, 0x110);
	ASSERT_STRUCT_OFFSET(node_params_t, used, 0x11C);

	struct BreakablePiece
	{
		XModel * model; //OFS: 0x0 SIZE: 0x4
		int physObjId; //OFS: 0x4 SIZE: 0x4
		unsigned __int16 lightingHandle; //OFS: 0x8 SIZE: 0x2
		bool active; //OFS: 0xA SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(BreakablePiece, 0xC);
	ASSERT_STRUCT_OFFSET(BreakablePiece, model, 0x0);
	ASSERT_STRUCT_OFFSET(BreakablePiece, physObjId, 0x4);
	ASSERT_STRUCT_OFFSET(BreakablePiece, lightingHandle, 0x8);
	ASSERT_STRUCT_OFFSET(BreakablePiece, active, 0xA);

	struct DynEnt_BurnData
	{
		unsigned __int16 id; //OFS: 0x0 SIZE: 0x2
		unsigned int fx; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DynEnt_BurnData, 0x8);
	ASSERT_STRUCT_OFFSET(DynEnt_BurnData, id, 0x0);
	ASSERT_STRUCT_OFFSET(DynEnt_BurnData, fx, 0x4);

	struct __declspec(align(1)) unkLaserStruct
	{
		char pad1[72]; //OFS: 0x0 SIZE: 0x48
	};
	ASSERT_STRUCT_SIZE(unkLaserStruct, 0x48);
	ASSERT_STRUCT_OFFSET(unkLaserStruct, pad1, 0x0);

	struct FxMarkPoint
	{
		float xyz[3]; //OFS: 0x0 SIZE: 0xC
		float lmapCoord[2]; //OFS: 0xC SIZE: 0x8
		float normal[3]; //OFS: 0x14 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(FxMarkPoint, 0x20);
	ASSERT_STRUCT_OFFSET(FxMarkPoint, xyz, 0x0);
	ASSERT_STRUCT_OFFSET(FxMarkPoint, lmapCoord, 0xC);
	ASSERT_STRUCT_OFFSET(FxMarkPoint, normal, 0x14);

	struct __declspec(align(2)) GfxMarkContext
	{
		unsigned __int8 lmapIndex; //OFS: 0x0 SIZE: 0x1
		unsigned __int8 primaryLightIndex; //OFS: 0x1 SIZE: 0x1
		unsigned __int8 reflectionProbeIndex; //OFS: 0x2 SIZE: 0x1
		unsigned __int8 modelTypeAndSurf; //OFS: 0x3 SIZE: 0x1
		unsigned __int16 modelIndex; //OFS: 0x4 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(GfxMarkContext, 0x6);
	ASSERT_STRUCT_OFFSET(GfxMarkContext, lmapIndex, 0x0);
	ASSERT_STRUCT_OFFSET(GfxMarkContext, primaryLightIndex, 0x1);
	ASSERT_STRUCT_OFFSET(GfxMarkContext, reflectionProbeIndex, 0x2);
	ASSERT_STRUCT_OFFSET(GfxMarkContext, modelTypeAndSurf, 0x3);
	ASSERT_STRUCT_OFFSET(GfxMarkContext, modelIndex, 0x4);

	struct FxMark
	{
		unsigned __int16 prevMark; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 nextMark; //OFS: 0x2 SIZE: 0x2
		int frameCountDrawn; //OFS: 0x4 SIZE: 0x4
		int frameCountAlloced; //OFS: 0x8 SIZE: 0x4
		float origin[3]; //OFS: 0xC SIZE: 0xC
		float radius; //OFS: 0x18 SIZE: 0x4
		float texCoordAxis[3]; //OFS: 0x1C SIZE: 0xC
		float hitNormal[3]; //OFS: 0x28 SIZE: 0xC
		unsigned __int8 nativeColor[4]; //OFS: 0x34 SIZE: 0x4
		Material * material; //OFS: 0x38 SIZE: 0x4
		int tris; //OFS: 0x3C SIZE: 0x4
		int points; //OFS: 0x40 SIZE: 0x4
		GfxMarkContext context; //OFS: 0x44 SIZE: 0x6
		unsigned __int16 pointCount; //OFS: 0x4A SIZE: 0x2
		unsigned __int8 triCount; //OFS: 0x4C SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(FxMark, 0x50);
	ASSERT_STRUCT_OFFSET(FxMark, prevMark, 0x0);
	ASSERT_STRUCT_OFFSET(FxMark, nextMark, 0x2);
	ASSERT_STRUCT_OFFSET(FxMark, frameCountDrawn, 0x4);
	ASSERT_STRUCT_OFFSET(FxMark, frameCountAlloced, 0x8);
	ASSERT_STRUCT_OFFSET(FxMark, origin, 0xC);
	ASSERT_STRUCT_OFFSET(FxMark, radius, 0x18);
	ASSERT_STRUCT_OFFSET(FxMark, texCoordAxis, 0x1C);
	ASSERT_STRUCT_OFFSET(FxMark, hitNormal, 0x28);
	ASSERT_STRUCT_OFFSET(FxMark, nativeColor, 0x34);
	ASSERT_STRUCT_OFFSET(FxMark, material, 0x38);
	ASSERT_STRUCT_OFFSET(FxMark, tris, 0x3C);
	ASSERT_STRUCT_OFFSET(FxMark, points, 0x40);
	ASSERT_STRUCT_OFFSET(FxMark, context, 0x44);
	ASSERT_STRUCT_OFFSET(FxMark, pointCount, 0x4A);
	ASSERT_STRUCT_OFFSET(FxMark, triCount, 0x4C);

	struct FxTriGroup
	{
		unsigned __int16 indices[2][3]; //OFS: 0x0 SIZE: 0xC
		GfxMarkContext context; //OFS: 0xC SIZE: 0x6
		unsigned __int8 triCount; //OFS: 0x12 SIZE: 0x1
		unsigned __int8 unused[1]; //OFS: 0x13 SIZE: 0x1
		int next; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxTriGroup, 0x18);
	ASSERT_STRUCT_OFFSET(FxTriGroup, indices, 0x0);
	ASSERT_STRUCT_OFFSET(FxTriGroup, context, 0xC);
	ASSERT_STRUCT_OFFSET(FxTriGroup, triCount, 0x12);
	ASSERT_STRUCT_OFFSET(FxTriGroup, unused, 0x13);
	ASSERT_STRUCT_OFFSET(FxTriGroup, next, 0x14);

	struct FxTriGroupPool
	{
		FxTriGroup triGroup; //OFS: 0x0 SIZE: 0x18
	};
	ASSERT_STRUCT_SIZE(FxTriGroupPool, 0x18);
	ASSERT_STRUCT_OFFSET(FxTriGroupPool, triGroup, 0x0);

	struct FxPointGroup
	{
		FxMarkPoint points[2]; //OFS: 0x0 SIZE: 0x40
		int next; //OFS: 0x40 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxPointGroup, 0x44);
	ASSERT_STRUCT_OFFSET(FxPointGroup, points, 0x0);
	ASSERT_STRUCT_OFFSET(FxPointGroup, next, 0x40);

	struct FxPointGroupPool
	{
		FxPointGroup pointGroup; //OFS: 0x0 SIZE: 0x44
	};
	ASSERT_STRUCT_SIZE(FxPointGroupPool, 0x44);
	ASSERT_STRUCT_OFFSET(FxPointGroupPool, pointGroup, 0x0);

	struct FxMarksSystem
	{
		int frameCount; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 firstFreeMarkHandle; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 firstActiveWorldMarkHandle; //OFS: 0x6 SIZE: 0x2
		unsigned __int16 entFirstMarkHandles[2048]; //OFS: 0x8 SIZE: 0x1000
		void * firstFreeTriGroup; //OFS: 0x1008 SIZE: 0x4
		void * firstFreePointGroup; //OFS: 0x100C SIZE: 0x4
		FxMark marks[256]; //OFS: 0x1010 SIZE: 0x5000
		FxTriGroupPool triGroups[1024]; //OFS: 0x6010 SIZE: 0x6000
		FxPointGroupPool pointGroups[1536]; //OFS: 0xC010 SIZE: 0x19800
		bool noMarks; //OFS: 0x25810 SIZE: 0x1
		bool hasCarryIndex; //OFS: 0x25811 SIZE: 0x1
		unsigned __int16 carryIndex; //OFS: 0x25812 SIZE: 0x2
		unsigned int allocedMarkCount; //OFS: 0x25814 SIZE: 0x4
		unsigned int freedMarkCount; //OFS: 0x25818 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxMarksSystem, 0x2581C);
	ASSERT_STRUCT_OFFSET(FxMarksSystem, frameCount, 0x0);
	ASSERT_STRUCT_OFFSET(FxMarksSystem, firstFreeMarkHandle, 0x4);
	ASSERT_STRUCT_OFFSET(FxMarksSystem, firstActiveWorldMarkHandle, 0x6);
	ASSERT_STRUCT_OFFSET(FxMarksSystem, entFirstMarkHandles, 0x8);
	ASSERT_STRUCT_OFFSET(FxMarksSystem, firstFreeTriGroup, 0x1008);
	ASSERT_STRUCT_OFFSET(FxMarksSystem, firstFreePointGroup, 0x100C);
	ASSERT_STRUCT_OFFSET(FxMarksSystem, marks, 0x1010);
	ASSERT_STRUCT_OFFSET(FxMarksSystem, triGroups, 0x6010);
	ASSERT_STRUCT_OFFSET(FxMarksSystem, pointGroups, 0xC010);
	ASSERT_STRUCT_OFFSET(FxMarksSystem, noMarks, 0x25810);
	ASSERT_STRUCT_OFFSET(FxMarksSystem, hasCarryIndex, 0x25811);
	ASSERT_STRUCT_OFFSET(FxMarksSystem, carryIndex, 0x25812);
	ASSERT_STRUCT_OFFSET(FxMarksSystem, allocedMarkCount, 0x25814);
	ASSERT_STRUCT_OFFSET(FxMarksSystem, freedMarkCount, 0x25818);

	struct rope_t
	{
		char field_0; //OFS: 0x0 SIZE: 0x1
		_BYTE gap1[3039]; //OFS: 0x1 SIZE: 0xBDF
		int field_BE0; //OFS: 0xBE0 SIZE: 0x4
		_BYTE gapBE4[48]; //OFS: 0xBE4 SIZE: 0x30
		int field_C14; //OFS: 0xC14 SIZE: 0x4
		_BYTE gapC18[12]; //OFS: 0xC18 SIZE: 0xC
		int field_C24; //OFS: 0xC24 SIZE: 0x4
		_BYTE gapC28[32]; //OFS: 0xC28 SIZE: 0x20
		int field_C48; //OFS: 0xC48 SIZE: 0x4
		_BYTE gapC4C[11]; //OFS: 0xC4C SIZE: 0xB
		char field_C57; //OFS: 0xC57 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(rope_t, 0xC58);
	ASSERT_STRUCT_OFFSET(rope_t, field_0, 0x0);
	ASSERT_STRUCT_OFFSET(rope_t, gap1, 0x1);
	ASSERT_STRUCT_OFFSET(rope_t, field_BE0, 0xBE0);
	ASSERT_STRUCT_OFFSET(rope_t, gapBE4, 0xBE4);
	ASSERT_STRUCT_OFFSET(rope_t, field_C14, 0xC14);
	ASSERT_STRUCT_OFFSET(rope_t, gapC18, 0xC18);
	ASSERT_STRUCT_OFFSET(rope_t, field_C24, 0xC24);
	ASSERT_STRUCT_OFFSET(rope_t, gapC28, 0xC28);
	ASSERT_STRUCT_OFFSET(rope_t, field_C48, 0xC48);
	ASSERT_STRUCT_OFFSET(rope_t, gapC4C, 0xC4C);
	ASSERT_STRUCT_OFFSET(rope_t, field_C57, 0xC57);

	struct unkServerListStruct
	{
		char field_0[1]; //OFS: 0x0 SIZE: 0x1
		_BYTE gap1[175]; //OFS: 0x1 SIZE: 0xAF
		int field_B0[1]; //OFS: 0xB0 SIZE: 0x4
		int field_B4[1]; //OFS: 0xB4 SIZE: 0x4
		char field_B8[1]; //OFS: 0xB8 SIZE: 0x1
		char field_B9[1]; //OFS: 0xB9 SIZE: 0x1
		char field_BA[1]; //OFS: 0xBA SIZE: 0x1
		char field_BB[5]; //OFS: 0xBB SIZE: 0x5
		_BYTE field_C0[49]; //OFS: 0xC0 SIZE: 0x31
		char field_F1[1]; //OFS: 0xF1 SIZE: 0x1
		_BYTE gapF2; //OFS: 0xF2 SIZE: 0x1
		char field_F3[32]; //OFS: 0xF3 SIZE: 0x20
		char field_113[64]; //OFS: 0x113 SIZE: 0x40
		char field_153[128]; //OFS: 0x153 SIZE: 0x80
		char field_1D3[1]; //OFS: 0x1D3 SIZE: 0x1
		char field_1D4[4]; //OFS: 0x1D4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(unkServerListStruct, 0x1D8);

	struct dwUnifiedFriends
	{
		unkServerListStruct unkFriendsStruct; //OFS: 0x0 SIZE: 0x1D8
		_BYTE gap1D8[46727]; //OFS: 0x1D8 SIZE: 0xB687
		char field_B85F; //OFS: 0xB85F SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(dwUnifiedFriends, 0xB860);
	ASSERT_STRUCT_OFFSET(dwUnifiedFriends, unkFriendsStruct, 0x0);
	ASSERT_STRUCT_OFFSET(dwUnifiedFriends, gap1D8, 0x1D8);
	ASSERT_STRUCT_OFFSET(dwUnifiedFriends, field_B85F, 0xB85F);

	struct struc_1F3A280
	{
		int field_0[1]; //OFS: 0x0 SIZE: 0x4
		int field_4[1]; //OFS: 0x4 SIZE: 0x4
		char field_8[64]; //OFS: 0x8 SIZE: 0x40
		int field_48[1]; //OFS: 0x48 SIZE: 0x4
		int field_4C[1]; //OFS: 0x4C SIZE: 0x4
		_BYTE gap50[7919]; //OFS: 0x50 SIZE: 0x1EEF
		char field_1F3F; //OFS: 0x1F3F SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(struc_1F3A280, 0x1F40);
	ASSERT_STRUCT_OFFSET(struc_1F3A280, field_0, 0x0);
	ASSERT_STRUCT_OFFSET(struc_1F3A280, field_4, 0x4);
	ASSERT_STRUCT_OFFSET(struc_1F3A280, field_8, 0x8);
	ASSERT_STRUCT_OFFSET(struc_1F3A280, field_48, 0x48);
	ASSERT_STRUCT_OFFSET(struc_1F3A280, field_4C, 0x4C);
	ASSERT_STRUCT_OFFSET(struc_1F3A280, gap50, 0x50);
	ASSERT_STRUCT_OFFSET(struc_1F3A280, field_1F3F, 0x1F3F);

	struct struc_1F3DAC0
	{
		int field_0[1]; //OFS: 0x0 SIZE: 0x4
		int field_4[1]; //OFS: 0x4 SIZE: 0x4
		char field_8[72]; //OFS: 0x8 SIZE: 0x48
		_BYTE gap50[7919]; //OFS: 0x50 SIZE: 0x1EEF
		char field_1F3F; //OFS: 0x1F3F SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(struc_1F3DAC0, 0x1F40);
	ASSERT_STRUCT_OFFSET(struc_1F3DAC0, field_0, 0x0);
	ASSERT_STRUCT_OFFSET(struc_1F3DAC0, field_4, 0x4);
	ASSERT_STRUCT_OFFSET(struc_1F3DAC0, field_8, 0x8);
	ASSERT_STRUCT_OFFSET(struc_1F3DAC0, gap50, 0x50);
	ASSERT_STRUCT_OFFSET(struc_1F3DAC0, field_1F3F, 0x1F3F);

	struct CachedAssets_t
	{
		Material * scrollBarArrowUp; //OFS: 0x0 SIZE: 0x4
		Material * scrollBarArrowDown; //OFS: 0x4 SIZE: 0x4
		Material * scrollBarArrowLeft; //OFS: 0x8 SIZE: 0x4
		Material * scrollBarArrowRight; //OFS: 0xC SIZE: 0x4
		Material * scrollBar; //OFS: 0x10 SIZE: 0x4
		Material * scrollBarThumb; //OFS: 0x14 SIZE: 0x4
		Material * sliderBar; //OFS: 0x18 SIZE: 0x4
		Material * sliderThumb; //OFS: 0x1C SIZE: 0x4
		Material * whiteMaterial; //OFS: 0x20 SIZE: 0x4
		Material * cursor; //OFS: 0x24 SIZE: 0x4
		Material * playlist_sp_recrMaterial; //OFS: 0x28 SIZE: 0x4
		Material * playlist_sp_regMaterial; //OFS: 0x2C SIZE: 0x4
		Material * playlist_sp_hardMaterial; //OFS: 0x30 SIZE: 0x4
		Material * playlist_sp_vetMaterial; //OFS: 0x34 SIZE: 0x4
		Font_s * bigFont; //OFS: 0x38 SIZE: 0x4
		Font_s * smallFont; //OFS: 0x3C SIZE: 0x4
		Font_s * consoleFont; //OFS: 0x40 SIZE: 0x4
		Font_s * boldFont; //OFS: 0x44 SIZE: 0x4
		Font_s * normalFont; //OFS: 0x48 SIZE: 0x4
		Font_s * extraBigFont; //OFS: 0x4C SIZE: 0x4
		Font_s * objectiveFont; //OFS: 0x50 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(CachedAssets_t, 0x54);
	ASSERT_STRUCT_OFFSET(CachedAssets_t, scrollBarArrowUp, 0x0);
	ASSERT_STRUCT_OFFSET(CachedAssets_t, scrollBarArrowDown, 0x4);
	ASSERT_STRUCT_OFFSET(CachedAssets_t, scrollBarArrowLeft, 0x8);
	ASSERT_STRUCT_OFFSET(CachedAssets_t, scrollBarArrowRight, 0xC);
	ASSERT_STRUCT_OFFSET(CachedAssets_t, scrollBar, 0x10);
	ASSERT_STRUCT_OFFSET(CachedAssets_t, scrollBarThumb, 0x14);
	ASSERT_STRUCT_OFFSET(CachedAssets_t, sliderBar, 0x18);
	ASSERT_STRUCT_OFFSET(CachedAssets_t, sliderThumb, 0x1C);
	ASSERT_STRUCT_OFFSET(CachedAssets_t, whiteMaterial, 0x20);
	ASSERT_STRUCT_OFFSET(CachedAssets_t, cursor, 0x24);
	ASSERT_STRUCT_OFFSET(CachedAssets_t, playlist_sp_recrMaterial, 0x28);
	ASSERT_STRUCT_OFFSET(CachedAssets_t, playlist_sp_regMaterial, 0x2C);
	ASSERT_STRUCT_OFFSET(CachedAssets_t, playlist_sp_hardMaterial, 0x30);
	ASSERT_STRUCT_OFFSET(CachedAssets_t, playlist_sp_vetMaterial, 0x34);
	ASSERT_STRUCT_OFFSET(CachedAssets_t, bigFont, 0x38);
	ASSERT_STRUCT_OFFSET(CachedAssets_t, smallFont, 0x3C);
	ASSERT_STRUCT_OFFSET(CachedAssets_t, consoleFont, 0x40);
	ASSERT_STRUCT_OFFSET(CachedAssets_t, boldFont, 0x44);
	ASSERT_STRUCT_OFFSET(CachedAssets_t, normalFont, 0x48);
	ASSERT_STRUCT_OFFSET(CachedAssets_t, extraBigFont, 0x4C);
	ASSERT_STRUCT_OFFSET(CachedAssets_t, objectiveFont, 0x50);

	struct pendingServer_t
	{
		char adrstr[64]; //OFS: 0x0 SIZE: 0x40
		char name[64]; //OFS: 0x40 SIZE: 0x40
		int startTime; //OFS: 0x80 SIZE: 0x4
		int serverNum; //OFS: 0x84 SIZE: 0x4
		int valid; //OFS: 0x88 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(pendingServer_t, 0x8C);
	ASSERT_STRUCT_OFFSET(pendingServer_t, adrstr, 0x0);
	ASSERT_STRUCT_OFFSET(pendingServer_t, name, 0x40);
	ASSERT_STRUCT_OFFSET(pendingServer_t, startTime, 0x80);
	ASSERT_STRUCT_OFFSET(pendingServer_t, serverNum, 0x84);
	ASSERT_STRUCT_OFFSET(pendingServer_t, valid, 0x88);

	struct pendingServerStatus_t
	{
		int num; //OFS: 0x0 SIZE: 0x4
		pendingServer_t server[8]; //OFS: 0x4 SIZE: 0x460
	};
	ASSERT_STRUCT_SIZE(pendingServerStatus_t, 0x464);
	ASSERT_STRUCT_OFFSET(pendingServerStatus_t, num, 0x0);
	ASSERT_STRUCT_OFFSET(pendingServerStatus_t, server, 0x4);

	struct serverStatusInfo_s
	{
		char gap1[787]; //OFS: 0x0 SIZE: 0x313
		int numLinesnot; //OFS: 0x314 SIZE: 0x4
		char gap2[2357]; //OFS: 0x318 SIZE: 0x935
	};
	ASSERT_STRUCT_SIZE(serverStatusInfo_s, 0xC50);
	ASSERT_STRUCT_OFFSET(serverStatusInfo_s, gap1, 0x0);
	ASSERT_STRUCT_OFFSET(serverStatusInfo_s, numLinesnot, 0x314);
	ASSERT_STRUCT_OFFSET(serverStatusInfo_s, gap2, 0x318);

	struct XAnimNotify_s
	{
		char * name; //OFS: 0x0 SIZE: 0x4
		unsigned int type; //OFS: 0x4 SIZE: 0x4
		float timeFrac; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XAnimNotify_s, 0xC);
	ASSERT_STRUCT_OFFSET(XAnimNotify_s, name, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimNotify_s, type, 0x4);
	ASSERT_STRUCT_OFFSET(XAnimNotify_s, timeFrac, 0x8);

	struct infoParm_t
	{
		const char * name; //OFS: 0x0 SIZE: 0x4
		int clearSolid; //OFS: 0x4 SIZE: 0x4
		int surfaceFlags; //OFS: 0x8 SIZE: 0x4
		int contents; //OFS: 0xC SIZE: 0x4
		int toolFlags; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(infoParm_t, 0x14);
	ASSERT_STRUCT_OFFSET(infoParm_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(infoParm_t, clearSolid, 0x4);
	ASSERT_STRUCT_OFFSET(infoParm_t, surfaceFlags, 0x8);
	ASSERT_STRUCT_OFFSET(infoParm_t, contents, 0xC);
	ASSERT_STRUCT_OFFSET(infoParm_t, toolFlags, 0x10);

	struct Destructible_BonePose
	{
		int boneid; //OFS: 0x0 SIZE: 0x4
		int pieceIndex; //OFS: 0x4 SIZE: 0x4
		float angles_original[3]; //OFS: 0x8 SIZE: 0xC
		float angles_offset[3]; //OFS: 0x14 SIZE: 0xC
		float angles_vel[3]; //OFS: 0x20 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(Destructible_BonePose, 0x2C);
	ASSERT_STRUCT_OFFSET(Destructible_BonePose, boneid, 0x0);
	ASSERT_STRUCT_OFFSET(Destructible_BonePose, pieceIndex, 0x4);
	ASSERT_STRUCT_OFFSET(Destructible_BonePose, angles_original, 0x8);
	ASSERT_STRUCT_OFFSET(Destructible_BonePose, angles_offset, 0x14);
	ASSERT_STRUCT_OFFSET(Destructible_BonePose, angles_vel, 0x20);

	struct DestructiblePose
	{
		Destructible_BonePose bones[32]; //OFS: 0x0 SIZE: 0x580
		__int16 numBones; //OFS: 0x580 SIZE: 0x2
		__int16 destructibleID; //OFS: 0x582 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(DestructiblePose, 0x584);
	ASSERT_STRUCT_OFFSET(DestructiblePose, bones, 0x0);
	ASSERT_STRUCT_OFFSET(DestructiblePose, numBones, 0x580);
	ASSERT_STRUCT_OFFSET(DestructiblePose, destructibleID, 0x582);

	struct struct_0
	{
		int clientNum; //OFS: 0x0 SIZE: 0x4
		int var_44; //OFS: 0x4 SIZE: 0x4
		int var_40; //OFS: 0x8 SIZE: 0x4
		int var_3C; //OFS: 0xC SIZE: 0x4
		int var_38; //OFS: 0x10 SIZE: 0x4
		int var_34; //OFS: 0x14 SIZE: 0x4
		int var_30; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(struct_0, 0x1C);
	ASSERT_STRUCT_OFFSET(struct_0, clientNum, 0x0);
	ASSERT_STRUCT_OFFSET(struct_0, var_44, 0x4);
	ASSERT_STRUCT_OFFSET(struct_0, var_40, 0x8);
	ASSERT_STRUCT_OFFSET(struct_0, var_3C, 0xC);
	ASSERT_STRUCT_OFFSET(struct_0, var_38, 0x10);
	ASSERT_STRUCT_OFFSET(struct_0, var_34, 0x14);
	ASSERT_STRUCT_OFFSET(struct_0, var_30, 0x18);

	struct DObjModel_s
	{
		XModel * model; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 boneName; //OFS: 0x4 SIZE: 0x2
		bool ignoreCollision; //OFS: 0x6 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(DObjModel_s, 0x8);
	ASSERT_STRUCT_OFFSET(DObjModel_s, model, 0x0);
	ASSERT_STRUCT_OFFSET(DObjModel_s, boneName, 0x4);
	ASSERT_STRUCT_OFFSET(DObjModel_s, ignoreCollision, 0x6);

	struct leafList_s
	{
		int count; //OFS: 0x0 SIZE: 0x4
		int maxcount; //OFS: 0x4 SIZE: 0x4
		int overflowed; //OFS: 0x8 SIZE: 0x4
		unsigned __int16 * list; //OFS: 0xC SIZE: 0x4
		float bounds[2][3]; //OFS: 0x10 SIZE: 0x18
		int lastLeaf; //OFS: 0x28 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(leafList_s, 0x2C);
	ASSERT_STRUCT_OFFSET(leafList_s, count, 0x0);
	ASSERT_STRUCT_OFFSET(leafList_s, maxcount, 0x4);
	ASSERT_STRUCT_OFFSET(leafList_s, overflowed, 0x8);
	ASSERT_STRUCT_OFFSET(leafList_s, list, 0xC);
	ASSERT_STRUCT_OFFSET(leafList_s, bounds, 0x10);
	ASSERT_STRUCT_OFFSET(leafList_s, lastLeaf, 0x28);

	struct FastCriticalSection
	{
		volatile int readCount; //OFS: 0x0 SIZE: 0x4
		volatile int writeCount; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FastCriticalSection, 0x8);
	ASSERT_STRUCT_OFFSET(FastCriticalSection, readCount, 0x0);
	ASSERT_STRUCT_OFFSET(FastCriticalSection, writeCount, 0x4);

	struct ParseThreadInfo
	{
		parseInfo_t parseInfo[16]; //OFS: 0x0 SIZE: 0x4200
		int parseInfoNum; //OFS: 0x4200 SIZE: 0x4
		char * tokenPos; //OFS: 0x4204 SIZE: 0x4
		char * prevTokenPos; //OFS: 0x4208 SIZE: 0x4
		char line[1024]; //OFS: 0x420C SIZE: 0x400
	};
	ASSERT_STRUCT_SIZE(ParseThreadInfo, 0x460C);
	ASSERT_STRUCT_OFFSET(ParseThreadInfo, parseInfo, 0x0);
	ASSERT_STRUCT_OFFSET(ParseThreadInfo, parseInfoNum, 0x4200);
	ASSERT_STRUCT_OFFSET(ParseThreadInfo, tokenPos, 0x4204);
	ASSERT_STRUCT_OFFSET(ParseThreadInfo, prevTokenPos, 0x4208);
	ASSERT_STRUCT_OFFSET(ParseThreadInfo, line, 0x420C);

	struct LargeLocal
	{
		int startPos; //OFS: 0x0 SIZE: 0x4
		int size; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(LargeLocal, 0x8);
	ASSERT_STRUCT_OFFSET(LargeLocal, startPos, 0x0);
	ASSERT_STRUCT_OFFSET(LargeLocal, size, 0x4);

	struct XFile
	{
		unsigned int size; //OFS: 0x0 SIZE: 0x4
		unsigned int externalSize; //OFS: 0x4 SIZE: 0x4
		unsigned int blockSize[8]; //OFS: 0x8 SIZE: 0x20
	};
	ASSERT_STRUCT_SIZE(XFile, 0x28);
	ASSERT_STRUCT_OFFSET(XFile, size, 0x0);
	ASSERT_STRUCT_OFFSET(XFile, externalSize, 0x4);
	ASSERT_STRUCT_OFFSET(XFile, blockSize, 0x8);

	union pointtrace_or_moveclip_u
	{
		pointtrace_t point; //OFS: 0x0 SIZE: 0x40
		moveclip_t move; //OFS: 0x1 SIZE: 0x60
	};
	ASSERT_STRUCT_SIZE(pointtrace_or_moveclip_u, 0x60);

	struct PhysGlob
	{
		int physGlob; //OFS: 0x0 SIZE: 0x4
		int field_4; //OFS: 0x4 SIZE: 0x4
		int field_8; //OFS: 0x8 SIZE: 0x4
		int field_C; //OFS: 0xC SIZE: 0x4
		int field_10[1]; //OFS: 0x10 SIZE: 0x4
		int field_14[1]; //OFS: 0x14 SIZE: 0x4
		int field_18[3]; //OFS: 0x18 SIZE: 0xC
		int field_24; //OFS: 0x24 SIZE: 0x4
		_BYTE gap28[12]; //OFS: 0x28 SIZE: 0xC
		float field_34[16]; //OFS: 0x34 SIZE: 0x40
		int physGlob__timeLastSnapshot; //OFS: 0x74 SIZE: 0x4
		int physGlob__timeLastUpdate; //OFS: 0x78 SIZE: 0x4
		float physGlob__timeNowLerpFrac; //OFS: 0x7C SIZE: 0x4
		int collisionCallback; //OFS: 0x80 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(PhysGlob, 0x84);
	ASSERT_STRUCT_OFFSET(PhysGlob, physGlob, 0x0);
	ASSERT_STRUCT_OFFSET(PhysGlob, field_4, 0x4);
	ASSERT_STRUCT_OFFSET(PhysGlob, field_8, 0x8);
	ASSERT_STRUCT_OFFSET(PhysGlob, field_C, 0xC);
	ASSERT_STRUCT_OFFSET(PhysGlob, field_10, 0x10);
	ASSERT_STRUCT_OFFSET(PhysGlob, field_14, 0x14);
	ASSERT_STRUCT_OFFSET(PhysGlob, field_18, 0x18);
	ASSERT_STRUCT_OFFSET(PhysGlob, field_24, 0x24);
	ASSERT_STRUCT_OFFSET(PhysGlob, gap28, 0x28);
	ASSERT_STRUCT_OFFSET(PhysGlob, field_34, 0x34);
	ASSERT_STRUCT_OFFSET(PhysGlob, physGlob__timeLastSnapshot, 0x74);
	ASSERT_STRUCT_OFFSET(PhysGlob, physGlob__timeLastUpdate, 0x78);
	ASSERT_STRUCT_OFFSET(PhysGlob, physGlob__timeNowLerpFrac, 0x7C);
	ASSERT_STRUCT_OFFSET(PhysGlob, collisionCallback, 0x80);

	struct CinematicGlob
	{
		char currentCinematicName[256]; //OFS: 0x0 SIZE: 0x100
		char targetCinematicName[256]; //OFS: 0x100 SIZE: 0x100
		char nextCinematicName[256]; //OFS: 0x200 SIZE: 0x100
		unsigned int nextCinematicPlaybackFlags; //OFS: 0x300 SIZE: 0x4
		unsigned int playbackFlags; //OFS: 0x304 SIZE: 0x4
		bool targetCinematicChanged; //OFS: 0x308 SIZE: 0x1
		bool cinematicFinished; //OFS: 0x309 SIZE: 0x1
		char field_30A[2]; //OFS: 0x30A SIZE: 0x2
		int field_30C; //OFS: 0x30C SIZE: 0x4
		int field_310; //OFS: 0x310 SIZE: 0x4
		char field_314; //OFS: 0x314 SIZE: 0x1
		char field_315; //OFS: 0x315 SIZE: 0x1
		char field_316; //OFS: 0x316 SIZE: 0x1
		char field_317; //OFS: 0x317 SIZE: 0x1
		char field_318; //OFS: 0x318 SIZE: 0x1
		char field_319[3]; //OFS: 0x319 SIZE: 0x3
		int field_31C; //OFS: 0x31C SIZE: 0x4
		int field_320; //OFS: 0x320 SIZE: 0x4
		int field_324; //OFS: 0x324 SIZE: 0x4
		int field_328; //OFS: 0x328 SIZE: 0x4
		int field_32C; //OFS: 0x32C SIZE: 0x4
		int field_330; //OFS: 0x330 SIZE: 0x4
		int field_334; //OFS: 0x334 SIZE: 0x4
		_BYTE gap338[176]; //OFS: 0x338 SIZE: 0xB0
		int field_3E8; //OFS: 0x3E8 SIZE: 0x4
		int field_3EC; //OFS: 0x3EC SIZE: 0x4
		int field_3F0; //OFS: 0x3F0 SIZE: 0x4
		int field_3F4; //OFS: 0x3F4 SIZE: 0x4
		int field_3F8; //OFS: 0x3F8 SIZE: 0x4
		int field_3FC; //OFS: 0x3FC SIZE: 0x4
		int field_400; //OFS: 0x400 SIZE: 0x4
		int field_404; //OFS: 0x404 SIZE: 0x4
		int field_408; //OFS: 0x408 SIZE: 0x4
		int field_40C; //OFS: 0x40C SIZE: 0x4
		int field_410; //OFS: 0x410 SIZE: 0x4
		int field_414; //OFS: 0x414 SIZE: 0x4
		int field_418; //OFS: 0x418 SIZE: 0x4
		void * field_41C; //OFS: 0x41C SIZE: 0x4
		int field_420; //OFS: 0x420 SIZE: 0x4
		int field_424; //OFS: 0x424 SIZE: 0x4
		int field_428; //OFS: 0x428 SIZE: 0x4
		int field_42C; //OFS: 0x42C SIZE: 0x4
		int field_430; //OFS: 0x430 SIZE: 0x4
		int field_434; //OFS: 0x434 SIZE: 0x4
		_BYTE gap438[864]; //OFS: 0x438 SIZE: 0x360
		int activeTextureSet; //OFS: 0x798 SIZE: 0x4
		int activeImageFrameTextureSet; //OFS: 0x79C SIZE: 0x4
		void * memPool; //OFS: 0x7A0 SIZE: 0x4
		float playbackVolume; //OFS: 0x7A4 SIZE: 0x4
		bool underrun; //OFS: 0x7A8 SIZE: 0x1
		char field_7A9[3]; //OFS: 0x7A9 SIZE: 0x3
		int field_7AC; //OFS: 0x7AC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(CinematicGlob, 0x7B0);
	ASSERT_STRUCT_OFFSET(CinematicGlob, currentCinematicName, 0x0);
	ASSERT_STRUCT_OFFSET(CinematicGlob, targetCinematicName, 0x100);
	ASSERT_STRUCT_OFFSET(CinematicGlob, nextCinematicName, 0x200);
	ASSERT_STRUCT_OFFSET(CinematicGlob, nextCinematicPlaybackFlags, 0x300);
	ASSERT_STRUCT_OFFSET(CinematicGlob, playbackFlags, 0x304);
	ASSERT_STRUCT_OFFSET(CinematicGlob, targetCinematicChanged, 0x308);
	ASSERT_STRUCT_OFFSET(CinematicGlob, cinematicFinished, 0x309);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_30A, 0x30A);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_30C, 0x30C);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_310, 0x310);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_314, 0x314);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_315, 0x315);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_316, 0x316);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_317, 0x317);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_318, 0x318);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_319, 0x319);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_31C, 0x31C);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_320, 0x320);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_324, 0x324);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_328, 0x328);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_32C, 0x32C);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_330, 0x330);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_334, 0x334);
	ASSERT_STRUCT_OFFSET(CinematicGlob, gap338, 0x338);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_3E8, 0x3E8);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_3EC, 0x3EC);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_3F0, 0x3F0);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_3F4, 0x3F4);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_3F8, 0x3F8);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_3FC, 0x3FC);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_400, 0x400);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_404, 0x404);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_408, 0x408);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_40C, 0x40C);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_410, 0x410);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_414, 0x414);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_418, 0x418);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_41C, 0x41C);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_420, 0x420);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_424, 0x424);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_428, 0x428);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_42C, 0x42C);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_430, 0x430);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_434, 0x434);
	ASSERT_STRUCT_OFFSET(CinematicGlob, gap438, 0x438);
	ASSERT_STRUCT_OFFSET(CinematicGlob, activeTextureSet, 0x798);
	ASSERT_STRUCT_OFFSET(CinematicGlob, activeImageFrameTextureSet, 0x79C);
	ASSERT_STRUCT_OFFSET(CinematicGlob, memPool, 0x7A0);
	ASSERT_STRUCT_OFFSET(CinematicGlob, playbackVolume, 0x7A4);
	ASSERT_STRUCT_OFFSET(CinematicGlob, underrun, 0x7A8);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_7A9, 0x7A9);
	ASSERT_STRUCT_OFFSET(CinematicGlob, field_7AC, 0x7AC);

	struct sightclip_t
	{
		float mins[3]; //OFS: 0x0 SIZE: 0xC
		float maxs[3]; //OFS: 0xC SIZE: 0xC
		float outerSize[3]; //OFS: 0x18 SIZE: 0xC
		float start[3]; //OFS: 0x24 SIZE: 0xC
		float end[3]; //OFS: 0x30 SIZE: 0xC
		int passEntityNum[2]; //OFS: 0x3C SIZE: 0x8
		int contentmask; //OFS: 0x44 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(sightclip_t, 0x48);
	ASSERT_STRUCT_OFFSET(sightclip_t, mins, 0x0);
	ASSERT_STRUCT_OFFSET(sightclip_t, maxs, 0xC);
	ASSERT_STRUCT_OFFSET(sightclip_t, outerSize, 0x18);
	ASSERT_STRUCT_OFFSET(sightclip_t, start, 0x24);
	ASSERT_STRUCT_OFFSET(sightclip_t, end, 0x30);
	ASSERT_STRUCT_OFFSET(sightclip_t, passEntityNum, 0x3C);
	ASSERT_STRUCT_OFFSET(sightclip_t, contentmask, 0x44);

	struct sightpointtrace_t
	{
		float start[3]; //OFS: 0x0 SIZE: 0xC
		float end[3]; //OFS: 0xC SIZE: 0xC
		int passEntityNum[2]; //OFS: 0x18 SIZE: 0x8
		int contentmask; //OFS: 0x20 SIZE: 0x4
		int locational; //OFS: 0x24 SIZE: 0x4
		unsigned __int8 * priorityMap; //OFS: 0x28 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(sightpointtrace_t, 0x2C);
	ASSERT_STRUCT_OFFSET(sightpointtrace_t, start, 0x0);
	ASSERT_STRUCT_OFFSET(sightpointtrace_t, end, 0xC);
	ASSERT_STRUCT_OFFSET(sightpointtrace_t, passEntityNum, 0x18);
	ASSERT_STRUCT_OFFSET(sightpointtrace_t, contentmask, 0x20);
	ASSERT_STRUCT_OFFSET(sightpointtrace_t, locational, 0x24);
	ASSERT_STRUCT_OFFSET(sightpointtrace_t, priorityMap, 0x28);

	union sightclip_or_sightpointtrace_u
	{
		sightclip_t sightclip; //OFS: 0x0 SIZE: 0x48
		sightpointtrace_t sightpointtrace; //OFS: 0x1 SIZE: 0x2C
	};
	ASSERT_STRUCT_SIZE(sightclip_or_sightpointtrace_u, 0x48);

	struct targGlob_t
	{
		target_t targets[32]; //OFS: 0x0 SIZE: 0x380
		int targetCount; //OFS: 0x380 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(targGlob_t, 0x384);
	ASSERT_STRUCT_OFFSET(targGlob_t, targets, 0x0);
	ASSERT_STRUCT_OFFSET(targGlob_t, targetCount, 0x380);

	struct snd_fader
	{
		float value; //OFS: 0x0 SIZE: 0x4
		float goal; //OFS: 0x4 SIZE: 0x4
		float rate; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(snd_fader, 0xC);
	ASSERT_STRUCT_OFFSET(snd_fader, value, 0x0);
	ASSERT_STRUCT_OFFSET(snd_fader, goal, 0x4);
	ASSERT_STRUCT_OFFSET(snd_fader, rate, 0x8);

	struct SndEntHandle
	{
		int handle; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SndEntHandle, 0x4);
	ASSERT_STRUCT_OFFSET(SndEntHandle, handle, 0x0);

	struct snd_player_water
	{
		float waterHeight; //OFS: 0x0 SIZE: 0x4
		float position[3]; //OFS: 0x4 SIZE: 0xC
		float viewHeight; //OFS: 0x10 SIZE: 0x4
		unsigned int lastTransition; //OFS: 0x14 SIZE: 0x4
		unsigned int timeTillGulp; //OFS: 0x18 SIZE: 0x4
		SndEntHandle ent; //OFS: 0x1C SIZE: 0x4
		int startId; //OFS: 0x20 SIZE: 0x4
		int enterId; //OFS: 0x24 SIZE: 0x4
		int exitId; //OFS: 0x28 SIZE: 0x4
		int idleId; //OFS: 0x2C SIZE: 0x4
		int swimId; //OFS: 0x30 SIZE: 0x4
		int vxId; //OFS: 0x34 SIZE: 0x4
		bool in_use; //OFS: 0x38 SIZE: 0x1
		bool is_new; //OFS: 0x39 SIZE: 0x1
		snd_fader idleBlend; //OFS: 0x3C SIZE: 0xC
		snd_fader swimBlend; //OFS: 0x48 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(snd_player_water, 0x54);
	ASSERT_STRUCT_OFFSET(snd_player_water, waterHeight, 0x0);
	ASSERT_STRUCT_OFFSET(snd_player_water, position, 0x4);
	ASSERT_STRUCT_OFFSET(snd_player_water, viewHeight, 0x10);
	ASSERT_STRUCT_OFFSET(snd_player_water, lastTransition, 0x14);
	ASSERT_STRUCT_OFFSET(snd_player_water, timeTillGulp, 0x18);
	ASSERT_STRUCT_OFFSET(snd_player_water, ent, 0x1C);
	ASSERT_STRUCT_OFFSET(snd_player_water, startId, 0x20);
	ASSERT_STRUCT_OFFSET(snd_player_water, enterId, 0x24);
	ASSERT_STRUCT_OFFSET(snd_player_water, exitId, 0x28);
	ASSERT_STRUCT_OFFSET(snd_player_water, idleId, 0x2C);
	ASSERT_STRUCT_OFFSET(snd_player_water, swimId, 0x30);
	ASSERT_STRUCT_OFFSET(snd_player_water, vxId, 0x34);
	ASSERT_STRUCT_OFFSET(snd_player_water, in_use, 0x38);
	ASSERT_STRUCT_OFFSET(snd_player_water, is_new, 0x39);
	ASSERT_STRUCT_OFFSET(snd_player_water, idleBlend, 0x3C);
	ASSERT_STRUCT_OFFSET(snd_player_water, swimBlend, 0x48);

	struct snd_volume_info_t
	{
		float volume; //OFS: 0x0 SIZE: 0x4
		float goalvolume; //OFS: 0x4 SIZE: 0x4
		float goalrate; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(snd_volume_info_t, 0xC);
	ASSERT_STRUCT_OFFSET(snd_volume_info_t, volume, 0x0);
	ASSERT_STRUCT_OFFSET(snd_volume_info_t, goalvolume, 0x4);
	ASSERT_STRUCT_OFFSET(snd_volume_info_t, goalrate, 0x8);

	struct SndBusVolGroup
	{
		snd_volume_info_t busVol[64]; //OFS: 0x0 SIZE: 0x300
		bool active; //OFS: 0x300 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(SndBusVolGroup, 0x304);
	ASSERT_STRUCT_OFFSET(SndBusVolGroup, busVol, 0x0);
	ASSERT_STRUCT_OFFSET(SndBusVolGroup, active, 0x300);

	struct snd_enveffect
	{
		snd_reverb_patch_t * reverb; //OFS: 0x0 SIZE: 0x4
		float drylevel; //OFS: 0x4 SIZE: 0x4
		float drygoal; //OFS: 0x8 SIZE: 0x4
		float dryrate; //OFS: 0xC SIZE: 0x4
		float wetlevel; //OFS: 0x10 SIZE: 0x4
		float wetgoal; //OFS: 0x14 SIZE: 0x4
		float wetrate; //OFS: 0x18 SIZE: 0x4
		bool active; //OFS: 0x1C SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(snd_enveffect, 0x20);
	ASSERT_STRUCT_OFFSET(snd_enveffect, reverb, 0x0);
	ASSERT_STRUCT_OFFSET(snd_enveffect, drylevel, 0x4);
	ASSERT_STRUCT_OFFSET(snd_enveffect, drygoal, 0x8);
	ASSERT_STRUCT_OFFSET(snd_enveffect, dryrate, 0xC);
	ASSERT_STRUCT_OFFSET(snd_enveffect, wetlevel, 0x10);
	ASSERT_STRUCT_OFFSET(snd_enveffect, wetgoal, 0x14);
	ASSERT_STRUCT_OFFSET(snd_enveffect, wetrate, 0x18);
	ASSERT_STRUCT_OFFSET(snd_enveffect, active, 0x1C);

	struct snd_listener
	{
		orientation_t orient; //OFS: 0x0 SIZE: 0x30
		int clientNum; //OFS: 0x30 SIZE: 0x4
		bool active; //OFS: 0x34 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(snd_listener, 0x38);
	ASSERT_STRUCT_OFFSET(snd_listener, orient, 0x0);
	ASSERT_STRUCT_OFFSET(snd_listener, clientNum, 0x30);
	ASSERT_STRUCT_OFFSET(snd_listener, active, 0x34);

	struct snd_amplifier
	{
		snd_listener * listener; //OFS: 0x0 SIZE: 0x4
		int minRadius; //OFS: 0x4 SIZE: 0x4
		int maxRadius; //OFS: 0x8 SIZE: 0x4
		float falloffExp; //OFS: 0xC SIZE: 0x4
		float minVol; //OFS: 0x10 SIZE: 0x4
		float maxVol; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(snd_amplifier, 0x18);
	ASSERT_STRUCT_OFFSET(snd_amplifier, listener, 0x0);
	ASSERT_STRUCT_OFFSET(snd_amplifier, minRadius, 0x4);
	ASSERT_STRUCT_OFFSET(snd_amplifier, maxRadius, 0x8);
	ASSERT_STRUCT_OFFSET(snd_amplifier, falloffExp, 0xC);
	ASSERT_STRUCT_OFFSET(snd_amplifier, minVol, 0x10);
	ASSERT_STRUCT_OFFSET(snd_amplifier, maxVol, 0x14);

	struct snd_bus_t
	{
		snd_bus_info_t * info; //OFS: 0x0 SIZE: 0x4
		snd_fader scriptAttenuation; //OFS: 0x4 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(snd_bus_t, 0x10);
	ASSERT_STRUCT_OFFSET(snd_bus_t, info, 0x0);
	ASSERT_STRUCT_OFFSET(snd_bus_t, scriptAttenuation, 0x4);

	struct SndFileSpecificChannelInfo
	{
		SndFileLoadingState loadingState; //OFS: 0x0 SIZE: 0x4
		int srcChannelCount; //OFS: 0x4 SIZE: 0x4
		int baserate; //OFS: 0x8 SIZE: 0x4
		int endtime; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SndFileSpecificChannelInfo, 0x10);
	ASSERT_STRUCT_OFFSET(SndFileSpecificChannelInfo, loadingState, 0x0);
	ASSERT_STRUCT_OFFSET(SndFileSpecificChannelInfo, srcChannelCount, 0x4);
	ASSERT_STRUCT_OFFSET(SndFileSpecificChannelInfo, baserate, 0x8);
	ASSERT_STRUCT_OFFSET(SndFileSpecificChannelInfo, endtime, 0xC);

	struct sndLengthNotifyInfo
	{
		SndLengthId id[4]; //OFS: 0x0 SIZE: 0x10
		void * data[4]; //OFS: 0x10 SIZE: 0x10
		int count; //OFS: 0x20 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(sndLengthNotifyInfo, 0x24);
	ASSERT_STRUCT_OFFSET(sndLengthNotifyInfo, id, 0x0);
	ASSERT_STRUCT_OFFSET(sndLengthNotifyInfo, data, 0x10);
	ASSERT_STRUCT_OFFSET(sndLengthNotifyInfo, count, 0x20);

	struct snd_channel_info_t
	{
		SndFileSpecificChannelInfo soundFileInfo; //OFS: 0x0 SIZE: 0x10
		SndEntHandle sndEnt; //OFS: 0x10 SIZE: 0x4
		snd_entity_update entity_update; //OFS: 0x14 SIZE: 0x4
		int bus; //OFS: 0x18 SIZE: 0x4
		int startDelay; //OFS: 0x1C SIZE: 0x4
		int timeshift; //OFS: 0x20 SIZE: 0x4
		float fraction; //OFS: 0x24 SIZE: 0x4
		int startTime; //OFS: 0x28 SIZE: 0x4
		int looptime; //OFS: 0x2C SIZE: 0x4
		int totalMsec; //OFS: 0x30 SIZE: 0x4
		int playbackId; //OFS: 0x34 SIZE: 0x4
		sndLengthNotifyInfo lengthNotifyInfo; //OFS: 0x38 SIZE: 0x24
		snd_alias_t * alias0; //OFS: 0x5C SIZE: 0x4
		snd_alias_t * alias1; //OFS: 0x60 SIZE: 0x4
		int saveIndex0; //OFS: 0x64 SIZE: 0x4
		int saveIndex1; //OFS: 0x68 SIZE: 0x4
		float lerp; //OFS: 0x6C SIZE: 0x4
		float offset[3]; //OFS: 0x70 SIZE: 0xC
		float position[3]; //OFS: 0x7C SIZE: 0xC
		float velocity[3]; //OFS: 0x88 SIZE: 0xC
		float orientation[3][3]; //OFS: 0x94 SIZE: 0x24
		float direction[3]; //OFS: 0xB8 SIZE: 0xC
		float fluxVelocity[3]; //OFS: 0xC4 SIZE: 0xC
		float baseDistance; //OFS: 0xD0 SIZE: 0x4
		float distanceAttenuation; //OFS: 0xD4 SIZE: 0x4
		float reverbAttenuation; //OFS: 0xD8 SIZE: 0x4
		float cylinderAttenuation; //OFS: 0xDC SIZE: 0x4
		float volModSeed; //OFS: 0xE0 SIZE: 0x4
		float volModStart; //OFS: 0xE4 SIZE: 0x4
		float pitchModSeed; //OFS: 0xE8 SIZE: 0x4
		float globalPriority; //OFS: 0xEC SIZE: 0x4
		snd_fader doppler; //OFS: 0xF0 SIZE: 0xC
		snd_fader fade; //OFS: 0xFC SIZE: 0xC
		snd_fader script_fade; //OFS: 0x108 SIZE: 0xC
		snd_fader script_pitch; //OFS: 0x114 SIZE: 0xC
		snd_fader losOcclusion; //OFS: 0x120 SIZE: 0xC
		int losHitCache; //OFS: 0x12C SIZE: 0x4
		int closestListenerIndex; //OFS: 0x130 SIZE: 0x4
		snd_alias_system_t system; //OFS: 0x134 SIZE: 0x4
		float dryLevel; //OFS: 0x138 SIZE: 0x4
		float wetLevel; //OFS: 0x13C SIZE: 0x4
		snd_speaker_map pan; //OFS: 0x140 SIZE: 0x48
		bool paused; //OFS: 0x188 SIZE: 0x1
		bool timescale; //OFS: 0x189 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(snd_channel_info_t, 0x18C);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, soundFileInfo, 0x0);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, sndEnt, 0x10);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, entity_update, 0x14);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, bus, 0x18);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, startDelay, 0x1C);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, timeshift, 0x20);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, fraction, 0x24);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, startTime, 0x28);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, looptime, 0x2C);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, totalMsec, 0x30);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, playbackId, 0x34);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, lengthNotifyInfo, 0x38);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, alias0, 0x5C);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, alias1, 0x60);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, saveIndex0, 0x64);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, saveIndex1, 0x68);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, lerp, 0x6C);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, offset, 0x70);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, position, 0x7C);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, velocity, 0x88);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, orientation, 0x94);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, direction, 0xB8);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, fluxVelocity, 0xC4);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, baseDistance, 0xD0);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, distanceAttenuation, 0xD4);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, reverbAttenuation, 0xD8);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, cylinderAttenuation, 0xDC);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, volModSeed, 0xE0);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, volModStart, 0xE4);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, pitchModSeed, 0xE8);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, globalPriority, 0xEC);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, doppler, 0xF0);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, fade, 0xFC);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, script_fade, 0x108);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, script_pitch, 0x114);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, losOcclusion, 0x120);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, losHitCache, 0x12C);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, closestListenerIndex, 0x130);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, system, 0x134);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, dryLevel, 0x138);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, wetLevel, 0x13C);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, pan, 0x140);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, paused, 0x188);
	ASSERT_STRUCT_OFFSET(snd_channel_info_t, timescale, 0x189);

	struct snd_reverb_fader_t
	{
		snd_fader room; //OFS: 0x0 SIZE: 0xC
		snd_fader roomHF; //OFS: 0xC SIZE: 0xC
		snd_fader roomRolloffFactor; //OFS: 0x18 SIZE: 0xC
		snd_fader decayTime; //OFS: 0x24 SIZE: 0xC
		snd_fader decayHFRatio; //OFS: 0x30 SIZE: 0xC
		snd_fader reflections; //OFS: 0x3C SIZE: 0xC
		snd_fader reflectionsDelay; //OFS: 0x48 SIZE: 0xC
		snd_fader reverb; //OFS: 0x54 SIZE: 0xC
		snd_fader reverbDelay; //OFS: 0x60 SIZE: 0xC
		snd_fader diffusion; //OFS: 0x6C SIZE: 0xC
		snd_fader density; //OFS: 0x78 SIZE: 0xC
		snd_fader HFReference; //OFS: 0x84 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(snd_reverb_fader_t, 0x90);
	ASSERT_STRUCT_OFFSET(snd_reverb_fader_t, room, 0x0);
	ASSERT_STRUCT_OFFSET(snd_reverb_fader_t, roomHF, 0xC);
	ASSERT_STRUCT_OFFSET(snd_reverb_fader_t, roomRolloffFactor, 0x18);
	ASSERT_STRUCT_OFFSET(snd_reverb_fader_t, decayTime, 0x24);
	ASSERT_STRUCT_OFFSET(snd_reverb_fader_t, decayHFRatio, 0x30);
	ASSERT_STRUCT_OFFSET(snd_reverb_fader_t, reflections, 0x3C);
	ASSERT_STRUCT_OFFSET(snd_reverb_fader_t, reflectionsDelay, 0x48);
	ASSERT_STRUCT_OFFSET(snd_reverb_fader_t, reverb, 0x54);
	ASSERT_STRUCT_OFFSET(snd_reverb_fader_t, reverbDelay, 0x60);
	ASSERT_STRUCT_OFFSET(snd_reverb_fader_t, diffusion, 0x6C);
	ASSERT_STRUCT_OFFSET(snd_reverb_fader_t, density, 0x78);
	ASSERT_STRUCT_OFFSET(snd_reverb_fader_t, HFReference, 0x84);

	struct snd_occlusion_trace_t
	{
		float listener[3]; //OFS: 0x0 SIZE: 0xC
		float playback[3]; //OFS: 0xC SIZE: 0xC
		int cache; //OFS: 0x18 SIZE: 0x4
		int id; //OFS: 0x1C SIZE: 0x4
		float occlusion; //OFS: 0x20 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(snd_occlusion_trace_t, 0x24);
	ASSERT_STRUCT_OFFSET(snd_occlusion_trace_t, listener, 0x0);
	ASSERT_STRUCT_OFFSET(snd_occlusion_trace_t, playback, 0xC);
	ASSERT_STRUCT_OFFSET(snd_occlusion_trace_t, cache, 0x18);
	ASSERT_STRUCT_OFFSET(snd_occlusion_trace_t, id, 0x1C);
	ASSERT_STRUCT_OFFSET(snd_occlusion_trace_t, occlusion, 0x20);

	struct snd_local_t
	{
		bool Initialized2d; //OFS: 0x0 SIZE: 0x1
		bool Initialized3d; //OFS: 0x1 SIZE: 0x1
		bool paused; //OFS: 0x2 SIZE: 0x1
		int playbackIdCounter; //OFS: 0x4 SIZE: 0x4
		int playback_channels; //OFS: 0x8 SIZE: 0x4
		int pausetime; //OFS: 0xC SIZE: 0x4
		int cpu; //OFS: 0x10 SIZE: 0x4
		snd_fader volume; //OFS: 0x14 SIZE: 0xC
		SndBusVolGroup busVolGroups[5]; //OFS: 0x20 SIZE: 0xF14
		SndBusVolGroup * busVol; //OFS: 0xF34 SIZE: 0x4
		snd_fader slave; //OFS: 0xF38 SIZE: 0xC
		snd_enveffect envEffects[3]; //OFS: 0xF44 SIZE: 0x60
		snd_enveffect * effect; //OFS: 0xFA4 SIZE: 0x4
		bool pauseSettings[64]; //OFS: 0xFA8 SIZE: 0x40
		snd_listener listeners[2]; //OFS: 0xFE8 SIZE: 0x70
		int time; //OFS: 0x1058 SIZE: 0x4
		int looptime; //OFS: 0x105C SIZE: 0x4
		snd_amplifier amplifier; //OFS: 0x1060 SIZE: 0x18
		snd_bus_t buses[64]; //OFS: 0x1078 SIZE: 0x400
		int voice_bus; //OFS: 0x1478 SIZE: 0x4
		snd_channel_info_t chaninfo[70]; //OFS: 0x147C SIZE: 0x6C48
		int channelAliasHash[70]; //OFS: 0x80C4 SIZE: 0x118
		_BYTE gap81DC[840]; //OFS: 0x81DC SIZE: 0x348
		int max_2D_channels; //OFS: 0x8524 SIZE: 0x4
		int max_3D_channels; //OFS: 0x8528 SIZE: 0x4
		int max_stream_channels; //OFS: 0x852C SIZE: 0x4
		snd_reverb_fader_t reverb_fader; //OFS: 0x8530 SIZE: 0x90
		snd_reverb_patch_t current_reverb_patch; //OFS: 0x85C0 SIZE: 0x50
		snd_master_effect_t * masterEffect; //OFS: 0x8610 SIZE: 0x4
		snd_master_effect_t visionsetMasterEffect; //OFS: 0x8614 SIZE: 0x38
		SndDriverGlobals * global_constants; //OFS: 0x864C SIZE: 0x4
		snd_occlusion_trace_t occlusionTraces[70]; //OFS: 0x8650 SIZE: 0x9D8
		int occlusionRunning; //OFS: 0x9028 SIZE: 0x4
		char framesSinceLastOcclusionUpdate[4]; //OFS: 0x902C SIZE: 0x4
		int traceSequence; //OFS: 0x9030 SIZE: 0x4
		int lastTraceSequence; //OFS: 0x9034 SIZE: 0x4
		int inCinematic; //OFS: 0x9038 SIZE: 0x4
		int cinematicTimestamp; //OFS: 0x903C SIZE: 0x4
		int cinematicUpdate; //OFS: 0x9040 SIZE: 0x4
		int forcePause; //OFS: 0x9044 SIZE: 0x4
		int globalAttenuation; //OFS: 0x9048 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(snd_local_t, 0x904C);
	ASSERT_STRUCT_OFFSET(snd_local_t, Initialized2d, 0x0);
	ASSERT_STRUCT_OFFSET(snd_local_t, Initialized3d, 0x1);
	ASSERT_STRUCT_OFFSET(snd_local_t, paused, 0x2);
	ASSERT_STRUCT_OFFSET(snd_local_t, playbackIdCounter, 0x4);
	ASSERT_STRUCT_OFFSET(snd_local_t, playback_channels, 0x8);
	ASSERT_STRUCT_OFFSET(snd_local_t, pausetime, 0xC);
	ASSERT_STRUCT_OFFSET(snd_local_t, cpu, 0x10);
	ASSERT_STRUCT_OFFSET(snd_local_t, volume, 0x14);
	ASSERT_STRUCT_OFFSET(snd_local_t, busVolGroups, 0x20);
	ASSERT_STRUCT_OFFSET(snd_local_t, busVol, 0xF34);
	ASSERT_STRUCT_OFFSET(snd_local_t, slave, 0xF38);
	ASSERT_STRUCT_OFFSET(snd_local_t, envEffects, 0xF44);
	ASSERT_STRUCT_OFFSET(snd_local_t, effect, 0xFA4);
	ASSERT_STRUCT_OFFSET(snd_local_t, pauseSettings, 0xFA8);
	ASSERT_STRUCT_OFFSET(snd_local_t, listeners, 0xFE8);
	ASSERT_STRUCT_OFFSET(snd_local_t, time, 0x1058);
	ASSERT_STRUCT_OFFSET(snd_local_t, looptime, 0x105C);
	ASSERT_STRUCT_OFFSET(snd_local_t, amplifier, 0x1060);
	ASSERT_STRUCT_OFFSET(snd_local_t, buses, 0x1078);
	ASSERT_STRUCT_OFFSET(snd_local_t, voice_bus, 0x1478);
	ASSERT_STRUCT_OFFSET(snd_local_t, chaninfo, 0x147C);
	ASSERT_STRUCT_OFFSET(snd_local_t, channelAliasHash, 0x80C4);
	ASSERT_STRUCT_OFFSET(snd_local_t, gap81DC, 0x81DC);
	ASSERT_STRUCT_OFFSET(snd_local_t, max_2D_channels, 0x8524);
	ASSERT_STRUCT_OFFSET(snd_local_t, max_3D_channels, 0x8528);
	ASSERT_STRUCT_OFFSET(snd_local_t, max_stream_channels, 0x852C);
	ASSERT_STRUCT_OFFSET(snd_local_t, reverb_fader, 0x8530);
	ASSERT_STRUCT_OFFSET(snd_local_t, current_reverb_patch, 0x85C0);
	ASSERT_STRUCT_OFFSET(snd_local_t, masterEffect, 0x8610);
	ASSERT_STRUCT_OFFSET(snd_local_t, visionsetMasterEffect, 0x8614);
	ASSERT_STRUCT_OFFSET(snd_local_t, global_constants, 0x864C);
	ASSERT_STRUCT_OFFSET(snd_local_t, occlusionTraces, 0x8650);
	ASSERT_STRUCT_OFFSET(snd_local_t, occlusionRunning, 0x9028);
	ASSERT_STRUCT_OFFSET(snd_local_t, framesSinceLastOcclusionUpdate, 0x902C);
	ASSERT_STRUCT_OFFSET(snd_local_t, traceSequence, 0x9030);
	ASSERT_STRUCT_OFFSET(snd_local_t, lastTraceSequence, 0x9034);
	ASSERT_STRUCT_OFFSET(snd_local_t, inCinematic, 0x9038);
	ASSERT_STRUCT_OFFSET(snd_local_t, cinematicTimestamp, 0x903C);
	ASSERT_STRUCT_OFFSET(snd_local_t, cinematicUpdate, 0x9040);
	ASSERT_STRUCT_OFFSET(snd_local_t, forcePause, 0x9044);
	ASSERT_STRUCT_OFFSET(snd_local_t, globalAttenuation, 0x9048);

	struct animStringItem_t
	{
		const char * string; //OFS: 0x0 SIZE: 0x4
		int hash; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(animStringItem_t, 0x8);
	ASSERT_STRUCT_OFFSET(animStringItem_t, string, 0x0);
	ASSERT_STRUCT_OFFSET(animStringItem_t, hash, 0x4);

	struct animConditionTable_t
	{
		animScriptConditionTypes_t type; //OFS: 0x0 SIZE: 0x4
		animStringItem_t * values; //OFS: 0x4 SIZE: 0x4
		int minValue; //OFS: 0x8 SIZE: 0x4
		int maxValue; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(animConditionTable_t, 0x10);
	ASSERT_STRUCT_OFFSET(animConditionTable_t, type, 0x0);
	ASSERT_STRUCT_OFFSET(animConditionTable_t, values, 0x4);
	ASSERT_STRUCT_OFFSET(animConditionTable_t, minValue, 0x8);
	ASSERT_STRUCT_OFFSET(animConditionTable_t, maxValue, 0xC);

	struct SurfaceTypeSoundList
	{
		char * surfaceSoundBase; //OFS: 0x0 SIZE: 0x4
		char ** soundAliasList; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SurfaceTypeSoundList, 0x8);
	ASSERT_STRUCT_OFFSET(SurfaceTypeSoundList, surfaceSoundBase, 0x0);
	ASSERT_STRUCT_OFFSET(SurfaceTypeSoundList, soundAliasList, 0x4);

	struct VariantWind
	{
		float wind_vector[3]; //OFS: 0x0 SIZE: 0xC
		float rustle_angular_frequency[3]; //OFS: 0xC SIZE: 0xC
		float rustle_amplitude[3]; //OFS: 0x18 SIZE: 0xC
		float blade_acceleration; //OFS: 0x24 SIZE: 0x4
		float blade_velocity; //OFS: 0x28 SIZE: 0x4
		int reset_timer; //OFS: 0x2C SIZE: 0x4
		int gust_start; //OFS: 0x30 SIZE: 0x4
		int gust_dur; //OFS: 0x34 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(VariantWind, 0x38);
	ASSERT_STRUCT_OFFSET(VariantWind, wind_vector, 0x0);
	ASSERT_STRUCT_OFFSET(VariantWind, rustle_angular_frequency, 0xC);
	ASSERT_STRUCT_OFFSET(VariantWind, rustle_amplitude, 0x18);
	ASSERT_STRUCT_OFFSET(VariantWind, blade_acceleration, 0x24);
	ASSERT_STRUCT_OFFSET(VariantWind, blade_velocity, 0x28);
	ASSERT_STRUCT_OFFSET(VariantWind, reset_timer, 0x2C);
	ASSERT_STRUCT_OFFSET(VariantWind, gust_start, 0x30);
	ASSERT_STRUCT_OFFSET(VariantWind, gust_dur, 0x34);

	struct GrassWind
	{
		float pos[2]; //OFS: 0x0 SIZE: 0x8
		float dir[2]; //OFS: 0x8 SIZE: 0x8
		float strength_skew; //OFS: 0x10 SIZE: 0x4
		int life_span; //OFS: 0x14 SIZE: 0x4
		int start_time; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GrassWind, 0x1C);
	ASSERT_STRUCT_OFFSET(GrassWind, pos, 0x0);
	ASSERT_STRUCT_OFFSET(GrassWind, dir, 0x8);
	ASSERT_STRUCT_OFFSET(GrassWind, strength_skew, 0x10);
	ASSERT_STRUCT_OFFSET(GrassWind, life_span, 0x14);
	ASSERT_STRUCT_OFFSET(GrassWind, start_time, 0x18);

	struct vehAnimClient_t
	{
		bool initialized; //OFS: 0x0 SIZE: 0x1
		VehicleSeatPositions curSeat; //OFS: 0x4 SIZE: 0x4
		VehicleSeatPositions prevSeat; //OFS: 0x8 SIZE: 0x4
		bool moving; //OFS: 0xC SIZE: 0x1
		int animStage; //OFS: 0x10 SIZE: 0x4
		int animIndex; //OFS: 0x14 SIZE: 0x4
		int tagName; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(vehAnimClient_t, 0x1C);
	ASSERT_STRUCT_OFFSET(vehAnimClient_t, initialized, 0x0);
	ASSERT_STRUCT_OFFSET(vehAnimClient_t, curSeat, 0x4);
	ASSERT_STRUCT_OFFSET(vehAnimClient_t, prevSeat, 0x8);
	ASSERT_STRUCT_OFFSET(vehAnimClient_t, moving, 0xC);
	ASSERT_STRUCT_OFFSET(vehAnimClient_t, animStage, 0x10);
	ASSERT_STRUCT_OFFSET(vehAnimClient_t, animIndex, 0x14);
	ASSERT_STRUCT_OFFSET(vehAnimClient_t, tagName, 0x18);

	struct FxUniqueHandleDb_Node
	{
		FxEffect * effect; //OFS: 0x0 SIZE: 0x4
		FxUniqueHandleDb_Node * next; //OFS: 0x4 SIZE: 0x4
		unsigned int handle; //OFS: 0x8 SIZE: 0x4
		int pad[1]; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxUniqueHandleDb_Node, 0x10);
	ASSERT_STRUCT_OFFSET(FxUniqueHandleDb_Node, effect, 0x0);
	ASSERT_STRUCT_OFFSET(FxUniqueHandleDb_Node, next, 0x4);
	ASSERT_STRUCT_OFFSET(FxUniqueHandleDb_Node, handle, 0x8);
	ASSERT_STRUCT_OFFSET(FxUniqueHandleDb_Node, pad, 0xC);

	struct FxUniqueHandleDb
	{
		FxUniqueHandleDb_Node nodes[1024]; //OFS: 0x0 SIZE: 0x4000
	};
	ASSERT_STRUCT_SIZE(FxUniqueHandleDb, 0x4000);
	ASSERT_STRUCT_OFFSET(FxUniqueHandleDb, nodes, 0x0);

	struct snd_whizby
	{
		snd_alias_t * alias; //OFS: 0x0 SIZE: 0x4
		float start[3]; //OFS: 0x4 SIZE: 0xC
		float end[3]; //OFS: 0x10 SIZE: 0xC
		float t; //OFS: 0x1C SIZE: 0x4
		int playbackId; //OFS: 0x20 SIZE: 0x4
		int shooter; //OFS: 0x24 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(snd_whizby, 0x28);
	ASSERT_STRUCT_OFFSET(snd_whizby, alias, 0x0);
	ASSERT_STRUCT_OFFSET(snd_whizby, start, 0x4);
	ASSERT_STRUCT_OFFSET(snd_whizby, end, 0x10);
	ASSERT_STRUCT_OFFSET(snd_whizby, t, 0x1C);
	ASSERT_STRUCT_OFFSET(snd_whizby, playbackId, 0x20);
	ASSERT_STRUCT_OFFSET(snd_whizby, shooter, 0x24);

	struct snd_speaker_angle
	{
		snd_speaker_flag speaker; //OFS: 0x0 SIZE: 0x4
		float angle; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(snd_speaker_angle, 0x8);
	ASSERT_STRUCT_OFFSET(snd_speaker_angle, speaker, 0x0);
	ASSERT_STRUCT_OFFSET(snd_speaker_angle, angle, 0x4);

	struct snd_speaker_config
	{
		char * name; //OFS: 0x0 SIZE: 0x4
		snd_speaker_flag outputFormat; //OFS: 0x4 SIZE: 0x4
		unsigned int speakerCount; //OFS: 0x8 SIZE: 0x4
		unsigned int speakerMapCount; //OFS: 0xC SIZE: 0x4
		unsigned int angleCount; //OFS: 0x10 SIZE: 0x4
		snd_speaker_angle angles[8]; //OFS: 0x14 SIZE: 0x40
	};
	ASSERT_STRUCT_SIZE(snd_speaker_config, 0x54);
	ASSERT_STRUCT_OFFSET(snd_speaker_config, name, 0x0);
	ASSERT_STRUCT_OFFSET(snd_speaker_config, outputFormat, 0x4);
	ASSERT_STRUCT_OFFSET(snd_speaker_config, speakerCount, 0x8);
	ASSERT_STRUCT_OFFSET(snd_speaker_config, speakerMapCount, 0xC);
	ASSERT_STRUCT_OFFSET(snd_speaker_config, angleCount, 0x10);
	ASSERT_STRUCT_OFFSET(snd_speaker_config, angles, 0x14);

	// SoundState

	struct GrassForce
	{
		float worldPosition[3]; //OFS: 0x0 SIZE: 0xC
		float radius; //OFS: 0xC SIZE: 0x4
		float strength; //OFS: 0x10 SIZE: 0x4
		float frequency; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GrassForce, 0x18);
	ASSERT_STRUCT_OFFSET(GrassForce, worldPosition, 0x0);
	ASSERT_STRUCT_OFFSET(GrassForce, radius, 0xC);
	ASSERT_STRUCT_OFFSET(GrassForce, strength, 0x10);
	ASSERT_STRUCT_OFFSET(GrassForce, frequency, 0x14);

	struct GrassWindForce
	{
		float worldPosition[2]; //OFS: 0x0 SIZE: 0x8
		float inverseRadiusSquared; //OFS: 0x8 SIZE: 0x4
		float strength; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GrassWindForce, 0x10);
	ASSERT_STRUCT_OFFSET(GrassWindForce, worldPosition, 0x0);
	ASSERT_STRUCT_OFFSET(GrassWindForce, inverseRadiusSquared, 0x8);
	ASSERT_STRUCT_OFFSET(GrassWindForce, strength, 0xC);

	struct PerFrameFoliageInfo
	{
		GrassForce grassInstantForces[16]; //OFS: 0x0 SIZE: 0x180
		GrassForce grassPersistantForces[8]; //OFS: 0x180 SIZE: 0xC0
		GrassWindForce grassWindForces[16]; //OFS: 0x240 SIZE: 0x100
		unsigned int numGrassInstantForces; //OFS: 0x340 SIZE: 0x4
		unsigned int numGrassPersistantForces; //OFS: 0x344 SIZE: 0x4
		unsigned int numGrassWindForces; //OFS: 0x348 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(PerFrameFoliageInfo, 0x34C);
	ASSERT_STRUCT_OFFSET(PerFrameFoliageInfo, grassInstantForces, 0x0);
	ASSERT_STRUCT_OFFSET(PerFrameFoliageInfo, grassPersistantForces, 0x180);
	ASSERT_STRUCT_OFFSET(PerFrameFoliageInfo, grassWindForces, 0x240);
	ASSERT_STRUCT_OFFSET(PerFrameFoliageInfo, numGrassInstantForces, 0x340);
	ASSERT_STRUCT_OFFSET(PerFrameFoliageInfo, numGrassPersistantForces, 0x344);
	ASSERT_STRUCT_OFFSET(PerFrameFoliageInfo, numGrassWindForces, 0x348);

	struct GrassPersistForce
	{
		float worldPosition[3]; //OFS: 0x0 SIZE: 0xC
		float radius; //OFS: 0xC SIZE: 0x4
		float strength; //OFS: 0x10 SIZE: 0x4
		float frequency; //OFS: 0x14 SIZE: 0x4
		float age; //OFS: 0x18 SIZE: 0x4
		float maxAge; //OFS: 0x1C SIZE: 0x4
		float maxStrength; //OFS: 0x20 SIZE: 0x4
		bool isActive; //OFS: 0x24 SIZE: 0x1
		ForceType forceType; //OFS: 0x28 SIZE: 0x4
		unsigned int id; //OFS: 0x2C SIZE: 0x4
		float curForcePercent; //OFS: 0x30 SIZE: 0x4
		float trgForcePercent; //OFS: 0x34 SIZE: 0x4
		ShakeForceState shakeForceState; //OFS: 0x38 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GrassPersistForce, 0x3C);
	ASSERT_STRUCT_OFFSET(GrassPersistForce, worldPosition, 0x0);
	ASSERT_STRUCT_OFFSET(GrassPersistForce, radius, 0xC);
	ASSERT_STRUCT_OFFSET(GrassPersistForce, strength, 0x10);
	ASSERT_STRUCT_OFFSET(GrassPersistForce, frequency, 0x14);
	ASSERT_STRUCT_OFFSET(GrassPersistForce, age, 0x18);
	ASSERT_STRUCT_OFFSET(GrassPersistForce, maxAge, 0x1C);
	ASSERT_STRUCT_OFFSET(GrassPersistForce, maxStrength, 0x20);
	ASSERT_STRUCT_OFFSET(GrassPersistForce, isActive, 0x24);
	ASSERT_STRUCT_OFFSET(GrassPersistForce, forceType, 0x28);
	ASSERT_STRUCT_OFFSET(GrassPersistForce, id, 0x2C);
	ASSERT_STRUCT_OFFSET(GrassPersistForce, curForcePercent, 0x30);
	ASSERT_STRUCT_OFFSET(GrassPersistForce, trgForcePercent, 0x34);
	ASSERT_STRUCT_OFFSET(GrassPersistForce, shakeForceState, 0x38);

	struct ClientFoliageInfo
	{
		PerFrameFoliageInfo perFrame[2]; //OFS: 0x0 SIZE: 0x698
		GrassPersistForce persistantForces[8]; //OFS: 0x698 SIZE: 0x1E0
		float clientPlayerPos[3]; //OFS: 0x878 SIZE: 0xC
		bool clientIsActive; //OFS: 0x884 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(ClientFoliageInfo, 0x888);
	ASSERT_STRUCT_OFFSET(ClientFoliageInfo, perFrame, 0x0);
	ASSERT_STRUCT_OFFSET(ClientFoliageInfo, persistantForces, 0x698);
	ASSERT_STRUCT_OFFSET(ClientFoliageInfo, clientPlayerPos, 0x878);
	ASSERT_STRUCT_OFFSET(ClientFoliageInfo, clientIsActive, 0x884);

	struct WindState
	{
		float windDirection[3]; //OFS: 0x0 SIZE: 0xC
		float windSpringAngle[16]; //OFS: 0xC SIZE: 0x40
		float windRustleAngle[16][3]; //OFS: 0x4C SIZE: 0xC0
	};
	ASSERT_STRUCT_SIZE(WindState, 0x10C);
	ASSERT_STRUCT_OFFSET(WindState, windDirection, 0x0);
	ASSERT_STRUCT_OFFSET(WindState, windSpringAngle, 0xC);
	ASSERT_STRUCT_OFFSET(WindState, windRustleAngle, 0x4C);

	struct __declspec(align(8)) cdl_proftimer
	{
		unsigned __int64 stamp; //OFS: 0x0 SIZE: 0x8
		unsigned __int64 value; //OFS: 0x8 SIZE: 0x8
		unsigned __int64 avr; //OFS: 0x10 SIZE: 0x8
		unsigned __int64 tot; //OFS: 0x18 SIZE: 0x8
		unsigned __int64 capture_count; //OFS: 0x20 SIZE: 0x8
		unsigned __int64 calls; //OFS: 0x28 SIZE: 0x8
		bool capture; //OFS: 0x30 SIZE: 0x1
		unsigned __int64 mx[5]; //OFS: 0x38 SIZE: 0x28
	};
	ASSERT_STRUCT_SIZE(cdl_proftimer, 0x60);
	ASSERT_STRUCT_OFFSET(cdl_proftimer, stamp, 0x0);
	ASSERT_STRUCT_OFFSET(cdl_proftimer, value, 0x8);
	ASSERT_STRUCT_OFFSET(cdl_proftimer, avr, 0x10);
	ASSERT_STRUCT_OFFSET(cdl_proftimer, tot, 0x18);
	ASSERT_STRUCT_OFFSET(cdl_proftimer, capture_count, 0x20);
	ASSERT_STRUCT_OFFSET(cdl_proftimer, calls, 0x28);
	ASSERT_STRUCT_OFFSET(cdl_proftimer, capture, 0x30);
	ASSERT_STRUCT_OFFSET(cdl_proftimer, mx, 0x38);

	struct WaterSimulationCmdUpdate
	{
		unsigned int startTile; //OFS: 0x0 SIZE: 0x4
		unsigned int srcBuf; //OFS: 0x4 SIZE: 0x4
		unsigned int destBuf; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(WaterSimulationCmdUpdate, 0xC);
	ASSERT_STRUCT_OFFSET(WaterSimulationCmdUpdate, startTile, 0x0);
	ASSERT_STRUCT_OFFSET(WaterSimulationCmdUpdate, srcBuf, 0x4);
	ASSERT_STRUCT_OFFSET(WaterSimulationCmdUpdate, destBuf, 0x8);

	struct GfxWaterVertex
	{
		char pos[4]; //OFS: 0x0 SIZE: 0x4
		char normal[4]; //OFS: 0x4 SIZE: 0x4
		GfxColor color; //OFS: 0x8 SIZE: 0x4
		char texCoord[4]; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWaterVertex, 0x10);
	ASSERT_STRUCT_OFFSET(GfxWaterVertex, pos, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWaterVertex, normal, 0x4);
	ASSERT_STRUCT_OFFSET(GfxWaterVertex, color, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWaterVertex, texCoord, 0xC);

	struct tilemesh_t
	{
		int srcU; //OFS: 0x0 SIZE: 0x4
		int srcV; //OFS: 0x4 SIZE: 0x4
		int worldX; //OFS: 0x8 SIZE: 0x4
		int worldY; //OFS: 0xC SIZE: 0x4
		int worldZ; //OFS: 0x10 SIZE: 0x4
		int lastSkinTime; //OFS: 0x14 SIZE: 0x4
		unsigned int baseVertex; //OFS: 0x18 SIZE: 0x4
		GfxWaterVertex * lockedData; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(tilemesh_t, 0x20);
	ASSERT_STRUCT_OFFSET(tilemesh_t, srcU, 0x0);
	ASSERT_STRUCT_OFFSET(tilemesh_t, srcV, 0x4);
	ASSERT_STRUCT_OFFSET(tilemesh_t, worldX, 0x8);
	ASSERT_STRUCT_OFFSET(tilemesh_t, worldY, 0xC);
	ASSERT_STRUCT_OFFSET(tilemesh_t, worldZ, 0x10);
	ASSERT_STRUCT_OFFSET(tilemesh_t, lastSkinTime, 0x14);
	ASSERT_STRUCT_OFFSET(tilemesh_t, baseVertex, 0x18);
	ASSERT_STRUCT_OFFSET(tilemesh_t, lockedData, 0x1C);

	union WaterSimulationCmdSkin_u
	{
		tilemesh_t * meshesEA[16]; //OFS: 0x0 SIZE: 0x40
		tilemesh_t * meshes[16]; //OFS: 0x1 SIZE: 0x40
	};
	ASSERT_STRUCT_SIZE(WaterSimulationCmdSkin_u, 0x40);

	struct WaterSimulationCmdSkin
	{
		unsigned int startTile; //OFS: 0x0 SIZE: 0x4
		unsigned int srcBuf; //OFS: 0x4 SIZE: 0x4
		WaterSimulationCmdSkin_u u; //OFS: 0x8 SIZE: 0x40
	};
	ASSERT_STRUCT_SIZE(WaterSimulationCmdSkin, 0x48);
	ASSERT_STRUCT_OFFSET(WaterSimulationCmdSkin, startTile, 0x0);
	ASSERT_STRUCT_OFFSET(WaterSimulationCmdSkin, srcBuf, 0x4);
	ASSERT_STRUCT_OFFSET(WaterSimulationCmdSkin, u, 0x8);

	struct WaterSimulationCmd
	{
		WaterSimulationCmdUpdate update; //OFS: 0x0 SIZE: 0xC
		WaterSimulationCmdSkin skin; //OFS: 0xC SIZE: 0x48
	};
	ASSERT_STRUCT_SIZE(WaterSimulationCmd, 0x54);
	ASSERT_STRUCT_OFFSET(WaterSimulationCmd, update, 0x0);
	ASSERT_STRUCT_OFFSET(WaterSimulationCmd, skin, 0xC);

	struct staticmodeltrace_t
	{
		TraceExtents extents; //OFS: 0x0 SIZE: 0x30
		int contents; //OFS: 0x30 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(staticmodeltrace_t, 0x34);
	ASSERT_STRUCT_OFFSET(staticmodeltrace_t, extents, 0x0);
	ASSERT_STRUCT_OFFSET(staticmodeltrace_t, contents, 0x30);

	struct cg_hudelem_t
	{
		float x; //OFS: 0x0 SIZE: 0x4
		float y; //OFS: 0x4 SIZE: 0x4
		float rotation; //OFS: 0x8 SIZE: 0x4
		float width; //OFS: 0xC SIZE: 0x4
		float height; //OFS: 0x10 SIZE: 0x4
		char hudElemLabel[256]; //OFS: 0x14 SIZE: 0x100
		float labelWidth; //OFS: 0x114 SIZE: 0x4
		char hudElemText[256]; //OFS: 0x118 SIZE: 0x100
		float textWidth; //OFS: 0x218 SIZE: 0x4
		Font_s * font; //OFS: 0x21C SIZE: 0x4
		float fontScale; //OFS: 0x220 SIZE: 0x4
		float fontHeight; //OFS: 0x224 SIZE: 0x4
		float color[4]; //OFS: 0x228 SIZE: 0x10
		int timeNow; //OFS: 0x238 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(cg_hudelem_t, 0x23C);
	ASSERT_STRUCT_OFFSET(cg_hudelem_t, x, 0x0);
	ASSERT_STRUCT_OFFSET(cg_hudelem_t, y, 0x4);
	ASSERT_STRUCT_OFFSET(cg_hudelem_t, rotation, 0x8);
	ASSERT_STRUCT_OFFSET(cg_hudelem_t, width, 0xC);
	ASSERT_STRUCT_OFFSET(cg_hudelem_t, height, 0x10);
	ASSERT_STRUCT_OFFSET(cg_hudelem_t, hudElemLabel, 0x14);
	ASSERT_STRUCT_OFFSET(cg_hudelem_t, labelWidth, 0x114);
	ASSERT_STRUCT_OFFSET(cg_hudelem_t, hudElemText, 0x118);
	ASSERT_STRUCT_OFFSET(cg_hudelem_t, textWidth, 0x218);
	ASSERT_STRUCT_OFFSET(cg_hudelem_t, font, 0x21C);
	ASSERT_STRUCT_OFFSET(cg_hudelem_t, fontScale, 0x220);
	ASSERT_STRUCT_OFFSET(cg_hudelem_t, fontHeight, 0x224);
	ASSERT_STRUCT_OFFSET(cg_hudelem_t, color, 0x228);
	ASSERT_STRUCT_OFFSET(cg_hudelem_t, timeNow, 0x238);

	struct __declspec(align(2)) GfxCmdHeader
	{
		GfxRenderCommand id; //OFS: 0x0 SIZE: 0x1
		unsigned __int16 byteCount; //OFS: 0x2 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(GfxCmdHeader, 0x4);
	ASSERT_STRUCT_OFFSET(GfxCmdHeader, id, 0x0);
	ASSERT_STRUCT_OFFSET(GfxCmdHeader, byteCount, 0x2);

	struct GfxCmdDrawText2D
	{
		GfxCmdHeader header; //OFS: 0x0 SIZE: 0x4
		float x; //OFS: 0x4 SIZE: 0x4
		float y; //OFS: 0x8 SIZE: 0x4
		float rotation; //OFS: 0xC SIZE: 0x4
		Font_s * font; //OFS: 0x10 SIZE: 0x4
		float xScale; //OFS: 0x14 SIZE: 0x4
		float yScale; //OFS: 0x18 SIZE: 0x4
		GfxColor color; //OFS: 0x1C SIZE: 0x4
		int maxChars; //OFS: 0x20 SIZE: 0x4
		int renderFlags; //OFS: 0x24 SIZE: 0x4
		int cursorPos; //OFS: 0x28 SIZE: 0x4
		char cursorLetter; //OFS: 0x2C SIZE: 0x1
		GfxColor glowForceColor; //OFS: 0x30 SIZE: 0x4
		int fxBirthTime; //OFS: 0x34 SIZE: 0x4
		int fxLetterTime; //OFS: 0x38 SIZE: 0x4
		int fxDecayStartTime; //OFS: 0x3C SIZE: 0x4
		int fxDecayDuration; //OFS: 0x40 SIZE: 0x4
		Material * fxMaterial; //OFS: 0x44 SIZE: 0x4
		Material * fxMaterialGlow; //OFS: 0x48 SIZE: 0x4
		float padding; //OFS: 0x4C SIZE: 0x4
		char text[3]; //OFS: 0x50 SIZE: 0x3
	};
	ASSERT_STRUCT_SIZE(GfxCmdDrawText2D, 0x54);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawText2D, header, 0x0);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawText2D, x, 0x4);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawText2D, y, 0x8);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawText2D, rotation, 0xC);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawText2D, font, 0x10);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawText2D, xScale, 0x14);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawText2D, yScale, 0x18);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawText2D, color, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawText2D, maxChars, 0x20);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawText2D, renderFlags, 0x24);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawText2D, cursorPos, 0x28);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawText2D, cursorLetter, 0x2C);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawText2D, glowForceColor, 0x30);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawText2D, fxBirthTime, 0x34);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawText2D, fxLetterTime, 0x38);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawText2D, fxDecayStartTime, 0x3C);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawText2D, fxDecayDuration, 0x40);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawText2D, fxMaterial, 0x44);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawText2D, fxMaterialGlow, 0x48);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawText2D, padding, 0x4C);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawText2D, text, 0x50);

	struct GfxCmdArray
	{
		unsigned __int8 * cmds; //OFS: 0x0 SIZE: 0x4
		int usedTotal; //OFS: 0x4 SIZE: 0x4
		int usedCritical; //OFS: 0x8 SIZE: 0x4
		GfxCmdHeader * lastCmd; //OFS: 0xC SIZE: 0x4
		int byteSize; //OFS: 0x10 SIZE: 0x4
		int warnSize; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxCmdArray, 0x18);
	ASSERT_STRUCT_OFFSET(GfxCmdArray, cmds, 0x0);
	ASSERT_STRUCT_OFFSET(GfxCmdArray, usedTotal, 0x4);
	ASSERT_STRUCT_OFFSET(GfxCmdArray, usedCritical, 0x8);
	ASSERT_STRUCT_OFFSET(GfxCmdArray, lastCmd, 0xC);
	ASSERT_STRUCT_OFFSET(GfxCmdArray, byteSize, 0x10);
	ASSERT_STRUCT_OFFSET(GfxCmdArray, warnSize, 0x14);

	struct GfxCmdStretchPic
	{
		GfxCmdHeader header; //OFS: 0x0 SIZE: 0x4
		Material * material; //OFS: 0x4 SIZE: 0x4
		float x; //OFS: 0x8 SIZE: 0x4
		float y; //OFS: 0xC SIZE: 0x4
		float w; //OFS: 0x10 SIZE: 0x4
		float h; //OFS: 0x14 SIZE: 0x4
		float s0; //OFS: 0x18 SIZE: 0x4
		float t0; //OFS: 0x1C SIZE: 0x4
		float s1; //OFS: 0x20 SIZE: 0x4
		float t1; //OFS: 0x24 SIZE: 0x4
		GfxColor color; //OFS: 0x28 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxCmdStretchPic, 0x2C);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPic, header, 0x0);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPic, material, 0x4);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPic, x, 0x8);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPic, y, 0xC);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPic, w, 0x10);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPic, h, 0x14);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPic, s0, 0x18);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPic, t0, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPic, s1, 0x20);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPic, t1, 0x24);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPic, color, 0x28);

	struct GfxCmdDrawQuadPic
	{
		GfxCmdHeader header; //OFS: 0x0 SIZE: 0x4
		Material * material; //OFS: 0x4 SIZE: 0x4
		float verts[4][2]; //OFS: 0x8 SIZE: 0x20
		GfxColor color; //OFS: 0x28 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxCmdDrawQuadPic, 0x2C);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawQuadPic, header, 0x0);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawQuadPic, material, 0x4);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawQuadPic, verts, 0x8);
	ASSERT_STRUCT_OFFSET(GfxCmdDrawQuadPic, color, 0x28);

	struct config_s
	{
		unsigned __int16 good_length; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 max_lazy; //OFS: 0x2 SIZE: 0x2
		unsigned __int16 nice_length; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 max_chain; //OFS: 0x6 SIZE: 0x2
		block_state (__cdecl *func)(deflate_or_inflate_state *, int); //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(config_s, 0xC);
	ASSERT_STRUCT_OFFSET(config_s, good_length, 0x0);
	ASSERT_STRUCT_OFFSET(config_s, max_lazy, 0x2);
	ASSERT_STRUCT_OFFSET(config_s, nice_length, 0x4);
	ASSERT_STRUCT_OFFSET(config_s, max_chain, 0x6);
	ASSERT_STRUCT_OFFSET(config_s, func, 0x8);

	struct __declspec(align(8)) sharedUiInfo_t
	{
		CachedAssets_t assets; //OFS: 0x0 SIZE: 0x54
		char field_54[4]; //OFS: 0x54 SIZE: 0x4
		int sharedUiInfo_playerCount; //OFS: 0x58 SIZE: 0x4
		_BYTE field_5C[256]; //OFS: 0x5C SIZE: 0x100
		int field_15C[1]; //OFS: 0x15C SIZE: 0x4
		int field_160; //OFS: 0x160 SIZE: 0x4
		int field_164; //OFS: 0x164 SIZE: 0x4
		int field_168; //OFS: 0x168 SIZE: 0x4
		int field_16C; //OFS: 0x16C SIZE: 0x4
		char field_170[12]; //OFS: 0x170 SIZE: 0xC
		char field_17C[1396]; //OFS: 0x17C SIZE: 0x574
		int field_6F0; //OFS: 0x6F0 SIZE: 0x4
		_BYTE gap6F4[3456]; //OFS: 0x6F4 SIZE: 0xD80
		int field_1474; //OFS: 0x1474 SIZE: 0x4
		char field_1478[11]; //OFS: 0x1478 SIZE: 0xB
		char field_1483; //OFS: 0x1483 SIZE: 0x1
		char field_1484[1396]; //OFS: 0x1484 SIZE: 0x574
		int field_19F8; //OFS: 0x19F8 SIZE: 0x4
		char field_19FC[32]; //OFS: 0x19FC SIZE: 0x20
		char field_1A1C[56]; //OFS: 0x1A1C SIZE: 0x38
		int field_1A54[1]; //OFS: 0x1A54 SIZE: 0x4
		char field_1A58[8]; //OFS: 0x1A58 SIZE: 0x8
		int field_1A60[1]; //OFS: 0x1A60 SIZE: 0x4
		_BYTE gap1A64[128]; //OFS: 0x1A64 SIZE: 0x80
		int field_1AE4[1]; //OFS: 0x1AE4 SIZE: 0x4
		int field_1AE8[7653]; //OFS: 0x1AE8 SIZE: 0x7794
		int field_927C[1]; //OFS: 0x927C SIZE: 0x4
		int field_9280; //OFS: 0x9280 SIZE: 0x4
		int field_9284; //OFS: 0x9284 SIZE: 0x4
		int field_9288; //OFS: 0x9288 SIZE: 0x4
		_BYTE gap928C[8]; //OFS: 0x928C SIZE: 0x8
		int field_9294; //OFS: 0x9294 SIZE: 0x4
		int field_9298; //OFS: 0x9298 SIZE: 0x4
		_BYTE gap929C[8]; //OFS: 0x929C SIZE: 0x8
		int sharedUiInfo_serverHardwareIconList[1]; //OFS: 0x92A4 SIZE: 0x4
		int sharedUiInfo_modList[383]; //OFS: 0x92A8 SIZE: 0x5FC
		int sharedUiInfo_modCount; //OFS: 0x98A4 SIZE: 0x4
		int field_98A8; //OFS: 0x98A8 SIZE: 0x4
		char field_98AC[4]; //OFS: 0x98AC SIZE: 0x4
		__int64 field_98B0; //OFS: 0x98B0 SIZE: 0x8
		int field_98B8; //OFS: 0x98B8 SIZE: 0x4
		int field_98BC; //OFS: 0x98BC SIZE: 0x4
		_BYTE gap98C0[1104]; //OFS: 0x98C0 SIZE: 0x450
		int field_9D10; //OFS: 0x9D10 SIZE: 0x4
		char field_9D14[4]; //OFS: 0x9D14 SIZE: 0x4
		int field_9D18; //OFS: 0x9D18 SIZE: 0x4
		int field_9D1C; //OFS: 0x9D1C SIZE: 0x4
		_BYTE gap9D20[4]; //OFS: 0x9D20 SIZE: 0x4
		int field_9D24; //OFS: 0x9D24 SIZE: 0x4
		int field_9D28[1]; //OFS: 0x9D28 SIZE: 0x4
		int serverNumber[20000]; //OFS: 0x9D2C SIZE: 0x13880
		size_t field_1D5AC; //OFS: 0x1D5AC SIZE: 0x4
		int field_1D5B0; //OFS: 0x1D5B0 SIZE: 0x4
		int field_1D5B4; //OFS: 0x1D5B4 SIZE: 0x4
		int field_1D5B8; //OFS: 0x1D5B8 SIZE: 0x4
		char field_1D5BC[4]; //OFS: 0x1D5BC SIZE: 0x4
		int field_1D5C0; //OFS: 0x1D5C0 SIZE: 0x4
		int field_1D5C4; //OFS: 0x1D5C4 SIZE: 0x4
		int field_1D5C8; //OFS: 0x1D5C8 SIZE: 0x4
		_BYTE gap1D5CC[16]; //OFS: 0x1D5CC SIZE: 0x10
		char field_1D5DC[1023]; //OFS: 0x1D5DC SIZE: 0x3FF
		char field_1D9DB[1]; //OFS: 0x1D9DB SIZE: 0x1
		char field_1D9DC[100]; //OFS: 0x1D9DC SIZE: 0x64
		char field_1DA40[64]; //OFS: 0x1DA40 SIZE: 0x40
		char field_1DA80[64]; //OFS: 0x1DA80 SIZE: 0x40
		int field_1DAC0[771]; //OFS: 0x1DAC0 SIZE: 0xC0C
		int haredUiInfo_serverStatusInfo_numLines; //OFS: 0x1E6CC SIZE: 0x4
		int field_1E6D0; //OFS: 0x1E6D0 SIZE: 0x4
		int field_1E6D4; //OFS: 0x1E6D4 SIZE: 0x4
		_BYTE gap1E6D8[2239]; //OFS: 0x1E6D8 SIZE: 0x8BF
		char field_1EF97; //OFS: 0x1EF97 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(sharedUiInfo_t, 0x1EF98);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, assets, 0x0);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_54, 0x54);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, sharedUiInfo_playerCount, 0x58);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_5C, 0x5C);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_15C, 0x15C);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_160, 0x160);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_164, 0x164);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_168, 0x168);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_16C, 0x16C);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_170, 0x170);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_17C, 0x17C);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_6F0, 0x6F0);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, gap6F4, 0x6F4);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1474, 0x1474);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1478, 0x1478);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1483, 0x1483);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1484, 0x1484);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_19F8, 0x19F8);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_19FC, 0x19FC);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1A1C, 0x1A1C);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1A54, 0x1A54);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1A58, 0x1A58);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1A60, 0x1A60);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, gap1A64, 0x1A64);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1AE4, 0x1AE4);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1AE8, 0x1AE8);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_927C, 0x927C);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_9280, 0x9280);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_9284, 0x9284);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_9288, 0x9288);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, gap928C, 0x928C);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_9294, 0x9294);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_9298, 0x9298);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, gap929C, 0x929C);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, sharedUiInfo_serverHardwareIconList, 0x92A4);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, sharedUiInfo_modList, 0x92A8);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, sharedUiInfo_modCount, 0x98A4);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_98A8, 0x98A8);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_98AC, 0x98AC);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_98B0, 0x98B0);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_98B8, 0x98B8);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_98BC, 0x98BC);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, gap98C0, 0x98C0);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_9D10, 0x9D10);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_9D14, 0x9D14);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_9D18, 0x9D18);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_9D1C, 0x9D1C);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, gap9D20, 0x9D20);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_9D24, 0x9D24);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_9D28, 0x9D28);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, serverNumber, 0x9D2C);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1D5AC, 0x1D5AC);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1D5B0, 0x1D5B0);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1D5B4, 0x1D5B4);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1D5B8, 0x1D5B8);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1D5BC, 0x1D5BC);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1D5C0, 0x1D5C0);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1D5C4, 0x1D5C4);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1D5C8, 0x1D5C8);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, gap1D5CC, 0x1D5CC);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1D5DC, 0x1D5DC);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1D9DB, 0x1D9DB);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1D9DC, 0x1D9DC);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1DA40, 0x1DA40);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1DA80, 0x1DA80);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1DAC0, 0x1DAC0);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, haredUiInfo_serverStatusInfo_numLines, 0x1E6CC);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1E6D0, 0x1E6D0);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1E6D4, 0x1E6D4);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, gap1E6D8, 0x1E6D8);
	ASSERT_STRUCT_OFFSET(sharedUiInfo_t, field_1EF97, 0x1EF97);

	struct playlistEntry
	{
		char mapname[32]; //OFS: 0x0 SIZE: 0x20
		char gametype[16]; //OFS: 0x20 SIZE: 0x10
		int fullWeight; //OFS: 0x30 SIZE: 0x4
		int remainingWeight; //OFS: 0x34 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(playlistEntry, 0x38);
	ASSERT_STRUCT_OFFSET(playlistEntry, mapname, 0x0);
	ASSERT_STRUCT_OFFSET(playlistEntry, gametype, 0x20);
	ASSERT_STRUCT_OFFSET(playlistEntry, fullWeight, 0x30);
	ASSERT_STRUCT_OFFSET(playlistEntry, remainingWeight, 0x34);

	struct playlistInfo
	{
		char name[64]; //OFS: 0x0 SIZE: 0x40
		char description[256]; //OFS: 0x40 SIZE: 0x100
		char lockdescription[256]; //OFS: 0x140 SIZE: 0x100
		char icon[32]; //OFS: 0x240 SIZE: 0x20
		char rules[1024]; //OFS: 0x260 SIZE: 0x400
		playlistEntry entries[128]; //OFS: 0x660 SIZE: 0x1C00
		int numEntries; //OFS: 0x2260 SIZE: 0x4
		int unlockXp; //OFS: 0x2264 SIZE: 0x4
		int gametypeban; //OFS: 0x2268 SIZE: 0x4
		int maxPartySize; //OFS: 0x226C SIZE: 0x4
		int dlc; //OFS: 0x2270 SIZE: 0x4
		char ranked; //OFS: 0x2274 SIZE: 0x1
		char collectors; //OFS: 0x2275 SIZE: 0x1
		char finishedsolo; //OFS: 0x2276 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(playlistInfo, 0x2278);
	ASSERT_STRUCT_OFFSET(playlistInfo, name, 0x0);
	ASSERT_STRUCT_OFFSET(playlistInfo, description, 0x40);
	ASSERT_STRUCT_OFFSET(playlistInfo, lockdescription, 0x140);
	ASSERT_STRUCT_OFFSET(playlistInfo, icon, 0x240);
	ASSERT_STRUCT_OFFSET(playlistInfo, rules, 0x260);
	ASSERT_STRUCT_OFFSET(playlistInfo, entries, 0x660);
	ASSERT_STRUCT_OFFSET(playlistInfo, numEntries, 0x2260);
	ASSERT_STRUCT_OFFSET(playlistInfo, unlockXp, 0x2264);
	ASSERT_STRUCT_OFFSET(playlistInfo, gametypeban, 0x2268);
	ASSERT_STRUCT_OFFSET(playlistInfo, maxPartySize, 0x226C);
	ASSERT_STRUCT_OFFSET(playlistInfo, dlc, 0x2270);
	ASSERT_STRUCT_OFFSET(playlistInfo, ranked, 0x2274);
	ASSERT_STRUCT_OFFSET(playlistInfo, collectors, 0x2275);
	ASSERT_STRUCT_OFFSET(playlistInfo, finishedsolo, 0x2276);

	struct __declspec(align(1)) playlistGametype
	{
		char scriptName[16]; //OFS: 0x0 SIZE: 0x10
		char internalName[16]; //OFS: 0x10 SIZE: 0x10
		char localizedName[64]; //OFS: 0x20 SIZE: 0x40
		char rules[1024]; //OFS: 0x60 SIZE: 0x400
		bool teamBased; //OFS: 0x460 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(playlistGametype, 0x461);
	ASSERT_STRUCT_OFFSET(playlistGametype, scriptName, 0x0);
	ASSERT_STRUCT_OFFSET(playlistGametype, internalName, 0x10);
	ASSERT_STRUCT_OFFSET(playlistGametype, localizedName, 0x20);
	ASSERT_STRUCT_OFFSET(playlistGametype, rules, 0x60);
	ASSERT_STRUCT_OFFSET(playlistGametype, teamBased, 0x460);

	struct PendingSave
	{
		char filename[64]; //OFS: 0x0 SIZE: 0x40
		char description[256]; //OFS: 0x40 SIZE: 0x100
		char screenShotName[64]; //OFS: 0x140 SIZE: 0x40
		int saveId; //OFS: 0x180 SIZE: 0x4
		SaveType saveType; //OFS: 0x184 SIZE: 0x4
		unsigned int commitLevel; //OFS: 0x188 SIZE: 0x4
		bool suppressPlayerNotify; //OFS: 0x18C SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(PendingSave, 0x190);
	ASSERT_STRUCT_OFFSET(PendingSave, filename, 0x0);
	ASSERT_STRUCT_OFFSET(PendingSave, description, 0x40);
	ASSERT_STRUCT_OFFSET(PendingSave, screenShotName, 0x140);
	ASSERT_STRUCT_OFFSET(PendingSave, saveId, 0x180);
	ASSERT_STRUCT_OFFSET(PendingSave, saveType, 0x184);
	ASSERT_STRUCT_OFFSET(PendingSave, commitLevel, 0x188);
	ASSERT_STRUCT_OFFSET(PendingSave, suppressPlayerNotify, 0x18C);

	struct PendingSaveList
	{
		PendingSave pendingSaves[3]; //OFS: 0x0 SIZE: 0x4B0
		int count; //OFS: 0x4B0 SIZE: 0x4
		bool isAutoSaving; //OFS: 0x4B4 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(PendingSaveList, 0x4B8);
	ASSERT_STRUCT_OFFSET(PendingSaveList, pendingSaves, 0x0);
	ASSERT_STRUCT_OFFSET(PendingSaveList, count, 0x4B0);
	ASSERT_STRUCT_OFFSET(PendingSaveList, isAutoSaving, 0x4B4);

	struct GfxCmdStretchPicRotateXY
	{
		GfxCmdHeader header; //OFS: 0x0 SIZE: 0x4
		Material * material; //OFS: 0x4 SIZE: 0x4
		float x; //OFS: 0x8 SIZE: 0x4
		float y; //OFS: 0xC SIZE: 0x4
		float w; //OFS: 0x10 SIZE: 0x4
		float h; //OFS: 0x14 SIZE: 0x4
		float s0; //OFS: 0x18 SIZE: 0x4
		float t0; //OFS: 0x1C SIZE: 0x4
		float s1; //OFS: 0x20 SIZE: 0x4
		float t1; //OFS: 0x24 SIZE: 0x4
		GfxColor color; //OFS: 0x28 SIZE: 0x4
		float rotation; //OFS: 0x2C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxCmdStretchPicRotateXY, 0x30);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPicRotateXY, header, 0x0);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPicRotateXY, material, 0x4);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPicRotateXY, x, 0x8);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPicRotateXY, y, 0xC);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPicRotateXY, w, 0x10);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPicRotateXY, h, 0x14);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPicRotateXY, s0, 0x18);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPicRotateXY, t0, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPicRotateXY, s1, 0x20);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPicRotateXY, t1, 0x24);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPicRotateXY, color, 0x28);
	ASSERT_STRUCT_OFFSET(GfxCmdStretchPicRotateXY, rotation, 0x2C);

	struct XZoneMemory
	{
		XBlock blocks[9]; //OFS: 0x0 SIZE: 0x48
		char * lockedVertexData; //OFS: 0x48 SIZE: 0x4
		char * lockedIndexData; //OFS: 0x4C SIZE: 0x4
		void * vertexBuffer; //OFS: 0x50 SIZE: 0x4
		void * indexBuffer; //OFS: 0x54 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XZoneMemory, 0x58);
	ASSERT_STRUCT_OFFSET(XZoneMemory, blocks, 0x0);
	ASSERT_STRUCT_OFFSET(XZoneMemory, lockedVertexData, 0x48);
	ASSERT_STRUCT_OFFSET(XZoneMemory, lockedIndexData, 0x4C);
	ASSERT_STRUCT_OFFSET(XZoneMemory, vertexBuffer, 0x50);
	ASSERT_STRUCT_OFFSET(XZoneMemory, indexBuffer, 0x54);

	struct SaveMemoryGlob
	{
		SaveGame * committedGameSave; //OFS: 0x0 SIZE: 0x4
		SaveGame * currentGameSave; //OFS: 0x4 SIZE: 0x4
		SaveGame game0; //OFS: 0x8 SIZE: 0x1054C
		SaveGame game1; //OFS: 0x10554 SIZE: 0x1054C
		char field_20AA0[2097152]; //OFS: 0x20AA0 SIZE: 0x200000
		char field_220AA0[1048576]; //OFS: 0x220AA0 SIZE: 0x100000
		char field_320AA0[2097152]; //OFS: 0x320AA0 SIZE: 0x200000
		char field_520AA0[1048576]; //OFS: 0x520AA0 SIZE: 0x100000
		int recentLoadTime; //OFS: 0x620AA0 SIZE: 0x4
		char isCommitForced; //OFS: 0x620AA4 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(SaveMemoryGlob, 0x620AA8);
	ASSERT_STRUCT_OFFSET(SaveMemoryGlob, committedGameSave, 0x0);
	ASSERT_STRUCT_OFFSET(SaveMemoryGlob, currentGameSave, 0x4);
	ASSERT_STRUCT_OFFSET(SaveMemoryGlob, game0, 0x8);
	ASSERT_STRUCT_OFFSET(SaveMemoryGlob, game1, 0x10554);
	ASSERT_STRUCT_OFFSET(SaveMemoryGlob, field_20AA0, 0x20AA0);
	ASSERT_STRUCT_OFFSET(SaveMemoryGlob, field_220AA0, 0x220AA0);
	ASSERT_STRUCT_OFFSET(SaveMemoryGlob, field_320AA0, 0x320AA0);
	ASSERT_STRUCT_OFFSET(SaveMemoryGlob, field_520AA0, 0x520AA0);
	ASSERT_STRUCT_OFFSET(SaveMemoryGlob, recentLoadTime, 0x620AA0);
	ASSERT_STRUCT_OFFSET(SaveMemoryGlob, isCommitForced, 0x620AA4);

	struct file_in_zip_read_info_s
	{
		char * read_buffer; //OFS: 0x0 SIZE: 0x4
		z_stream_s stream; //OFS: 0x4 SIZE: 0x34
		unsigned int pos_in_zipfile; //OFS: 0x38 SIZE: 0x4
		unsigned int stream_initialised; //OFS: 0x3C SIZE: 0x4
		unsigned int offset_local_extrafield; //OFS: 0x40 SIZE: 0x4
		unsigned int size_local_extrafield; //OFS: 0x44 SIZE: 0x4
		unsigned int pos_local_extrafield; //OFS: 0x48 SIZE: 0x4
		unsigned int rest_read_compressed; //OFS: 0x4C SIZE: 0x4
		unsigned int rest_read_uncompressed; //OFS: 0x50 SIZE: 0x4
		_iobuf * file; //OFS: 0x54 SIZE: 0x4
		unsigned int compression_method; //OFS: 0x58 SIZE: 0x4
		unsigned int byte_before_the_zipfile; //OFS: 0x5C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(file_in_zip_read_info_s, 0x60);
	ASSERT_STRUCT_OFFSET(file_in_zip_read_info_s, read_buffer, 0x0);
	ASSERT_STRUCT_OFFSET(file_in_zip_read_info_s, stream, 0x4);
	ASSERT_STRUCT_OFFSET(file_in_zip_read_info_s, pos_in_zipfile, 0x38);
	ASSERT_STRUCT_OFFSET(file_in_zip_read_info_s, stream_initialised, 0x3C);
	ASSERT_STRUCT_OFFSET(file_in_zip_read_info_s, offset_local_extrafield, 0x40);
	ASSERT_STRUCT_OFFSET(file_in_zip_read_info_s, size_local_extrafield, 0x44);
	ASSERT_STRUCT_OFFSET(file_in_zip_read_info_s, pos_local_extrafield, 0x48);
	ASSERT_STRUCT_OFFSET(file_in_zip_read_info_s, rest_read_compressed, 0x4C);
	ASSERT_STRUCT_OFFSET(file_in_zip_read_info_s, rest_read_uncompressed, 0x50);
	ASSERT_STRUCT_OFFSET(file_in_zip_read_info_s, file, 0x54);
	ASSERT_STRUCT_OFFSET(file_in_zip_read_info_s, compression_method, 0x58);
	ASSERT_STRUCT_OFFSET(file_in_zip_read_info_s, byte_before_the_zipfile, 0x5C);

	struct flamePhysics_t
	{
		float origin[3]; //OFS: 0x0 SIZE: 0xC
		float newPos[3]; //OFS: 0xC SIZE: 0xC
		float velocity[3]; //OFS: 0x18 SIZE: 0xC
		float invStartSpeed; //OFS: 0x24 SIZE: 0x4
		float gravity; //OFS: 0x28 SIZE: 0x4
		float rotation; //OFS: 0x2C SIZE: 0x4
		float rotVel; //OFS: 0x30 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(flamePhysics_t, 0x34);
	ASSERT_STRUCT_OFFSET(flamePhysics_t, origin, 0x0);
	ASSERT_STRUCT_OFFSET(flamePhysics_t, newPos, 0xC);
	ASSERT_STRUCT_OFFSET(flamePhysics_t, velocity, 0x18);
	ASSERT_STRUCT_OFFSET(flamePhysics_t, invStartSpeed, 0x24);
	ASSERT_STRUCT_OFFSET(flamePhysics_t, gravity, 0x28);
	ASSERT_STRUCT_OFFSET(flamePhysics_t, rotation, 0x2C);
	ASSERT_STRUCT_OFFSET(flamePhysics_t, rotVel, 0x30);

	struct flameSize_t
	{
		float current; //OFS: 0x0 SIZE: 0x4
		float rate; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(flameSize_t, 0x8);
	ASSERT_STRUCT_OFFSET(flameSize_t, current, 0x0);
	ASSERT_STRUCT_OFFSET(flameSize_t, rate, 0x4);

	struct flameAge_t
	{
		int lastUpdateTime; //OFS: 0x0 SIZE: 0x4
		int startTime; //OFS: 0x4 SIZE: 0x4
		int endTime; //OFS: 0x8 SIZE: 0x4
		float invTimeScale; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(flameAge_t, 0x10);
	ASSERT_STRUCT_OFFSET(flameAge_t, lastUpdateTime, 0x0);
	ASSERT_STRUCT_OFFSET(flameAge_t, startTime, 0x4);
	ASSERT_STRUCT_OFFSET(flameAge_t, endTime, 0x8);
	ASSERT_STRUCT_OFFSET(flameAge_t, invTimeScale, 0xC);

	struct flameList_t
	{
		flameGeneric_s * prev; //OFS: 0x0 SIZE: 0x4
		flameGeneric_s * next; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(flameList_t, 0x8);
	ASSERT_STRUCT_OFFSET(flameList_t, prev, 0x0);
	ASSERT_STRUCT_OFFSET(flameList_t, next, 0x4);

	struct flameRender_s
	{
		char name[128]; //OFS: 0x0 SIZE: 0x80
		flameGeneric_s * fireList; //OFS: 0x80 SIZE: 0x4
		flameGeneric_s * dripsList; //OFS: 0x84 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(flameRender_s, 0x88);
	ASSERT_STRUCT_OFFSET(flameRender_s, name, 0x0);
	ASSERT_STRUCT_OFFSET(flameRender_s, fireList, 0x80);
	ASSERT_STRUCT_OFFSET(flameRender_s, dripsList, 0x84);

	struct flameGeneric_s
	{
		flamePhysics_t phys; //OFS: 0x0 SIZE: 0x34
		flameSize_t size; //OFS: 0x34 SIZE: 0x8
		flameAge_t age; //OFS: 0x3C SIZE: 0x10
		flameList_t listGlobal; //OFS: 0x4C SIZE: 0x8
		flameList_t listLocal; //OFS: 0x54 SIZE: 0x8
		flameStream_s * stream; //OFS: 0x5C SIZE: 0x4
		__int32 _bf_60; //OFS: 0x60 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(flameGeneric_s, 0x64);
	ASSERT_STRUCT_OFFSET(flameGeneric_s, phys, 0x0);
	ASSERT_STRUCT_OFFSET(flameGeneric_s, size, 0x34);
	ASSERT_STRUCT_OFFSET(flameGeneric_s, age, 0x3C);
	ASSERT_STRUCT_OFFSET(flameGeneric_s, listGlobal, 0x4C);
	ASSERT_STRUCT_OFFSET(flameGeneric_s, listLocal, 0x54);
	ASSERT_STRUCT_OFFSET(flameGeneric_s, stream, 0x5C);
	ASSERT_STRUCT_OFFSET(flameGeneric_s, _bf_60, 0x60);

	struct flameChunk_s
	{
		flameGeneric_s gen; //OFS: 0x0 SIZE: 0x64
		int spawnFireInterval; //OFS: 0x64 SIZE: 0x4
		int lastSpawnFire; //OFS: 0x68 SIZE: 0x4
		int spawnDripsInterval; //OFS: 0x6C SIZE: 0x4
		int spawnSmokeInterval; //OFS: 0x70 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(flameChunk_s, 0x74);
	ASSERT_STRUCT_OFFSET(flameChunk_s, gen, 0x0);
	ASSERT_STRUCT_OFFSET(flameChunk_s, spawnFireInterval, 0x64);
	ASSERT_STRUCT_OFFSET(flameChunk_s, lastSpawnFire, 0x68);
	ASSERT_STRUCT_OFFSET(flameChunk_s, spawnDripsInterval, 0x6C);
	ASSERT_STRUCT_OFFSET(flameChunk_s, spawnSmokeInterval, 0x70);

	struct flameStream_s
	{
		flameGeneric_s gen; //OFS: 0x0 SIZE: 0x64
		float fuelVerts[128][3]; //OFS: 0x64 SIZE: 0x600
		float flameVerts[128][3]; //OFS: 0x664 SIZE: 0x600
		flameTable * flameVars; //OFS: 0xC64 SIZE: 0x4
		flameRender_s * flameRend; //OFS: 0xC68 SIZE: 0x4
		flameChunk_s * chunkList; //OFS: 0xC6C SIZE: 0x4
		int lastSmokeChunkTime; //OFS: 0xC70 SIZE: 0x4
		int lastDripChunkTime; //OFS: 0xC74 SIZE: 0x4
		int entityNum; //OFS: 0xC78 SIZE: 0x4
		int damage; //OFS: 0xC7C SIZE: 0x4
		float damageDuration; //OFS: 0xC80 SIZE: 0x4
		float damageInterval; //OFS: 0xC84 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(flameStream_s, 0xC88);
	ASSERT_STRUCT_OFFSET(flameStream_s, gen, 0x0);
	ASSERT_STRUCT_OFFSET(flameStream_s, fuelVerts, 0x64);
	ASSERT_STRUCT_OFFSET(flameStream_s, flameVerts, 0x664);
	ASSERT_STRUCT_OFFSET(flameStream_s, flameVars, 0xC64);
	ASSERT_STRUCT_OFFSET(flameStream_s, flameRend, 0xC68);
	ASSERT_STRUCT_OFFSET(flameStream_s, chunkList, 0xC6C);
	ASSERT_STRUCT_OFFSET(flameStream_s, lastSmokeChunkTime, 0xC70);
	ASSERT_STRUCT_OFFSET(flameStream_s, lastDripChunkTime, 0xC74);
	ASSERT_STRUCT_OFFSET(flameStream_s, entityNum, 0xC78);
	ASSERT_STRUCT_OFFSET(flameStream_s, damage, 0xC7C);
	ASSERT_STRUCT_OFFSET(flameStream_s, damageDuration, 0xC80);
	ASSERT_STRUCT_OFFSET(flameStream_s, damageInterval, 0xC84);

	struct flameSmoke_t
	{
		flameGeneric_s gen; //OFS: 0x0 SIZE: 0x64
		Material * material; //OFS: 0x64 SIZE: 0x4
		float smokeFadein; //OFS: 0x68 SIZE: 0x4
		float smokeFadeout; //OFS: 0x6C SIZE: 0x4
		float smokeMaxAlpha; //OFS: 0x70 SIZE: 0x4
		float smokeBrightness; //OFS: 0x74 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(flameSmoke_t, 0x78);
	ASSERT_STRUCT_OFFSET(flameSmoke_t, gen, 0x0);
	ASSERT_STRUCT_OFFSET(flameSmoke_t, material, 0x64);
	ASSERT_STRUCT_OFFSET(flameSmoke_t, smokeFadein, 0x68);
	ASSERT_STRUCT_OFFSET(flameSmoke_t, smokeFadeout, 0x6C);
	ASSERT_STRUCT_OFFSET(flameSmoke_t, smokeMaxAlpha, 0x70);
	ASSERT_STRUCT_OFFSET(flameSmoke_t, smokeBrightness, 0x74);

	struct flameDrips_t
	{
		flameGeneric_s gen; //OFS: 0x0 SIZE: 0x64
		flameRender_s * flameRend; //OFS: 0x64 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(flameDrips_t, 0x68);
	ASSERT_STRUCT_OFFSET(flameDrips_t, gen, 0x0);
	ASSERT_STRUCT_OFFSET(flameDrips_t, flameRend, 0x64);

	struct flameFire_t
	{
		flameGeneric_s gen; //OFS: 0x0 SIZE: 0x64
		flameRender_s * flameRend; //OFS: 0x64 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(flameFire_t, 0x68);
	ASSERT_STRUCT_OFFSET(flameFire_t, gen, 0x0);
	ASSERT_STRUCT_OFFSET(flameFire_t, flameRend, 0x64);

	struct flameWeaponConfig_t
	{
		bool bIsFiring; //OFS: 0x0 SIZE: 0x1
		bool bFireWhileIdle; //OFS: 0x1 SIZE: 0x1
		float origin[3]; //OFS: 0x4 SIZE: 0xC
		float angle[3]; //OFS: 0x10 SIZE: 0xC
		float strength; //OFS: 0x1C SIZE: 0x4
		float thickness; //OFS: 0x20 SIZE: 0x4
		float burnRate; //OFS: 0x24 SIZE: 0x4
		float entityOrigin[3]; //OFS: 0x28 SIZE: 0xC
		flameTable * fTable; //OFS: 0x34 SIZE: 0x4
		int damage; //OFS: 0x38 SIZE: 0x4
		float damageDuration; //OFS: 0x3C SIZE: 0x4
		float damageInterval; //OFS: 0x40 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(flameWeaponConfig_t, 0x44);
	ASSERT_STRUCT_OFFSET(flameWeaponConfig_t, bIsFiring, 0x0);
	ASSERT_STRUCT_OFFSET(flameWeaponConfig_t, bFireWhileIdle, 0x1);
	ASSERT_STRUCT_OFFSET(flameWeaponConfig_t, origin, 0x4);
	ASSERT_STRUCT_OFFSET(flameWeaponConfig_t, angle, 0x10);
	ASSERT_STRUCT_OFFSET(flameWeaponConfig_t, strength, 0x1C);
	ASSERT_STRUCT_OFFSET(flameWeaponConfig_t, thickness, 0x20);
	ASSERT_STRUCT_OFFSET(flameWeaponConfig_t, burnRate, 0x24);
	ASSERT_STRUCT_OFFSET(flameWeaponConfig_t, entityOrigin, 0x28);
	ASSERT_STRUCT_OFFSET(flameWeaponConfig_t, fTable, 0x34);
	ASSERT_STRUCT_OFFSET(flameWeaponConfig_t, damage, 0x38);
	ASSERT_STRUCT_OFFSET(flameWeaponConfig_t, damageDuration, 0x3C);
	ASSERT_STRUCT_OFFSET(flameWeaponConfig_t, damageInterval, 0x40);

	struct flameChunkSpawnVars_t
	{
		int time; //OFS: 0x0 SIZE: 0x4
		int duration; //OFS: 0x4 SIZE: 0x4
		float origin[3]; //OFS: 0x8 SIZE: 0xC
		float angle[3]; //OFS: 0x14 SIZE: 0xC
		float speed; //OFS: 0x20 SIZE: 0x4
		float decel; //OFS: 0x24 SIZE: 0x4
		float gravityStart; //OFS: 0x28 SIZE: 0x4
		float gravityEnd; //OFS: 0x2C SIZE: 0x4
		float sizeMax; //OFS: 0x30 SIZE: 0x4
		float sizeStart; //OFS: 0x34 SIZE: 0x4
		float sizeEnd; //OFS: 0x38 SIZE: 0x4
		float sizeRate; //OFS: 0x3C SIZE: 0x4
		float spawnFireIntervalStart; //OFS: 0x40 SIZE: 0x4
		float spawnFireIntervalEnd; //OFS: 0x44 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(flameChunkSpawnVars_t, 0x48);
	ASSERT_STRUCT_OFFSET(flameChunkSpawnVars_t, time, 0x0);
	ASSERT_STRUCT_OFFSET(flameChunkSpawnVars_t, duration, 0x4);
	ASSERT_STRUCT_OFFSET(flameChunkSpawnVars_t, origin, 0x8);
	ASSERT_STRUCT_OFFSET(flameChunkSpawnVars_t, angle, 0x14);
	ASSERT_STRUCT_OFFSET(flameChunkSpawnVars_t, speed, 0x20);
	ASSERT_STRUCT_OFFSET(flameChunkSpawnVars_t, decel, 0x24);
	ASSERT_STRUCT_OFFSET(flameChunkSpawnVars_t, gravityStart, 0x28);
	ASSERT_STRUCT_OFFSET(flameChunkSpawnVars_t, gravityEnd, 0x2C);
	ASSERT_STRUCT_OFFSET(flameChunkSpawnVars_t, sizeMax, 0x30);
	ASSERT_STRUCT_OFFSET(flameChunkSpawnVars_t, sizeStart, 0x34);
	ASSERT_STRUCT_OFFSET(flameChunkSpawnVars_t, sizeEnd, 0x38);
	ASSERT_STRUCT_OFFSET(flameChunkSpawnVars_t, sizeRate, 0x3C);
	ASSERT_STRUCT_OFFSET(flameChunkSpawnVars_t, spawnFireIntervalStart, 0x40);
	ASSERT_STRUCT_OFFSET(flameChunkSpawnVars_t, spawnFireIntervalEnd, 0x44);

	struct FxEffectDefTableEntry
	{
		unsigned int key; //OFS: 0x0 SIZE: 0x4
		FxEffectDef * effectDef; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxEffectDefTableEntry, 0x8);
	ASSERT_STRUCT_OFFSET(FxEffectDefTableEntry, key, 0x0);
	ASSERT_STRUCT_OFFSET(FxEffectDefTableEntry, effectDef, 0x4);

	struct FxEffectDefTable
	{
		int count; //OFS: 0x0 SIZE: 0x4
		FxEffectDefTableEntry entries[512]; //OFS: 0x4 SIZE: 0x1000
	};
	ASSERT_STRUCT_SIZE(FxEffectDefTable, 0x1004);
	ASSERT_STRUCT_OFFSET(FxEffectDefTable, count, 0x0);
	ASSERT_STRUCT_OFFSET(FxEffectDefTable, entries, 0x4);

	struct flameSource_t
	{
		float origin[3]; //OFS: 0x0 SIZE: 0xC
		float angle[3]; //OFS: 0xC SIZE: 0xC
		float entityOrigin[3]; //OFS: 0x18 SIZE: 0xC
		flameStream_s * currentStream; //OFS: 0x24 SIZE: 0x4
		int lastUsedTime; //OFS: 0x28 SIZE: 0x4
		int entityNum; //OFS: 0x2C SIZE: 0x4
		int firstDobjHandle; //OFS: 0x30 SIZE: 0x4
		int thirdDobjHandle; //OFS: 0x34 SIZE: 0x4
		snd_fader soundLerp; //OFS: 0x38 SIZE: 0xC
		int lastSoundTime; //OFS: 0x44 SIZE: 0x4
		float flameSoundPoint[3]; //OFS: 0x48 SIZE: 0xC
		int soundOffLoopId; //OFS: 0x54 SIZE: 0x4
		int soundOnLoopId; //OFS: 0x58 SIZE: 0x4
		int soundCooldownId; //OFS: 0x5C SIZE: 0x4
		int soundIgniteId; //OFS: 0x60 SIZE: 0x4
		bool bIsFiring; //OFS: 0x64 SIZE: 0x1
		bool inUse; //OFS: 0x65 SIZE: 0x1
		bool is_server_alloc; //OFS: 0x66 SIZE: 0x1
		bool wasFiring; //OFS: 0x67 SIZE: 0x1
		unsigned __int8 firstBoneIndex; //OFS: 0x68 SIZE: 0x1
		unsigned __int8 thirdBoneIndex; //OFS: 0x69 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(flameSource_t, 0x6C);
	ASSERT_STRUCT_OFFSET(flameSource_t, origin, 0x0);
	ASSERT_STRUCT_OFFSET(flameSource_t, angle, 0xC);
	ASSERT_STRUCT_OFFSET(flameSource_t, entityOrigin, 0x18);
	ASSERT_STRUCT_OFFSET(flameSource_t, currentStream, 0x24);
	ASSERT_STRUCT_OFFSET(flameSource_t, lastUsedTime, 0x28);
	ASSERT_STRUCT_OFFSET(flameSource_t, entityNum, 0x2C);
	ASSERT_STRUCT_OFFSET(flameSource_t, firstDobjHandle, 0x30);
	ASSERT_STRUCT_OFFSET(flameSource_t, thirdDobjHandle, 0x34);
	ASSERT_STRUCT_OFFSET(flameSource_t, soundLerp, 0x38);
	ASSERT_STRUCT_OFFSET(flameSource_t, lastSoundTime, 0x44);
	ASSERT_STRUCT_OFFSET(flameSource_t, flameSoundPoint, 0x48);
	ASSERT_STRUCT_OFFSET(flameSource_t, soundOffLoopId, 0x54);
	ASSERT_STRUCT_OFFSET(flameSource_t, soundOnLoopId, 0x58);
	ASSERT_STRUCT_OFFSET(flameSource_t, soundCooldownId, 0x5C);
	ASSERT_STRUCT_OFFSET(flameSource_t, soundIgniteId, 0x60);
	ASSERT_STRUCT_OFFSET(flameSource_t, bIsFiring, 0x64);
	ASSERT_STRUCT_OFFSET(flameSource_t, inUse, 0x65);
	ASSERT_STRUCT_OFFSET(flameSource_t, is_server_alloc, 0x66);
	ASSERT_STRUCT_OFFSET(flameSource_t, wasFiring, 0x67);
	ASSERT_STRUCT_OFFSET(flameSource_t, firstBoneIndex, 0x68);
	ASSERT_STRUCT_OFFSET(flameSource_t, thirdBoneIndex, 0x69);

	struct __declspec(align(1)) _FM_BURNSAMPLE
	{
		ComBurnableSample active[32]; //OFS: 0x0 SIZE: 0x20
	};
	ASSERT_STRUCT_SIZE(_FM_BURNSAMPLE, 0x20);
	ASSERT_STRUCT_OFFSET(_FM_BURNSAMPLE, active, 0x0);

	struct _fm_activecell
	{
		float pos[3]; //OFS: 0x0 SIZE: 0xC
		int time; //OFS: 0xC SIZE: 0x4
		unsigned int index; //OFS: 0x10 SIZE: 0x4
		float spreadProbability; //OFS: 0x14 SIZE: 0x4
		unsigned __int8 x; //OFS: 0x18 SIZE: 0x1
		unsigned __int8 y; //OFS: 0x19 SIZE: 0x1
		unsigned __int8 stage; //OFS: 0x1A SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(_fm_activecell, 0x1C);
	ASSERT_STRUCT_OFFSET(_fm_activecell, pos, 0x0);
	ASSERT_STRUCT_OFFSET(_fm_activecell, time, 0xC);
	ASSERT_STRUCT_OFFSET(_fm_activecell, index, 0x10);
	ASSERT_STRUCT_OFFSET(_fm_activecell, spreadProbability, 0x14);
	ASSERT_STRUCT_OFFSET(_fm_activecell, x, 0x18);
	ASSERT_STRUCT_OFFSET(_fm_activecell, y, 0x19);
	ASSERT_STRUCT_OFFSET(_fm_activecell, stage, 0x1A);

	struct loadAnim_t
	{
		scr_anim_s anim; //OFS: 0x0 SIZE: 0x4
		int iNameHash; //OFS: 0x4 SIZE: 0x4
		char szAnimName[64]; //OFS: 0x8 SIZE: 0x40
	};
	ASSERT_STRUCT_SIZE(loadAnim_t, 0x48);
	ASSERT_STRUCT_OFFSET(loadAnim_t, anim, 0x0);
	ASSERT_STRUCT_OFFSET(loadAnim_t, iNameHash, 0x4);
	ASSERT_STRUCT_OFFSET(loadAnim_t, szAnimName, 0x8);

	struct animVehicleSeats_t
	{
		int seats; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(animVehicleSeats_t, 0x4);
	ASSERT_STRUCT_OFFSET(animVehicleSeats_t, seats, 0x0);

	struct TIMED_RADIUS_DAMAGE
	{
		float pos[3]; //OFS: 0x0 SIZE: 0xC
		int life; //OFS: 0xC SIZE: 0x4
		float radiusSqr; //OFS: 0x10 SIZE: 0x4
		int damage; //OFS: 0x14 SIZE: 0x4
		int rate; //OFS: 0x18 SIZE: 0x4
		int mod; //OFS: 0x1C SIZE: 0x4
		int weapon; //OFS: 0x20 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(TIMED_RADIUS_DAMAGE, 0x24);
	ASSERT_STRUCT_OFFSET(TIMED_RADIUS_DAMAGE, pos, 0x0);
	ASSERT_STRUCT_OFFSET(TIMED_RADIUS_DAMAGE, life, 0xC);
	ASSERT_STRUCT_OFFSET(TIMED_RADIUS_DAMAGE, radiusSqr, 0x10);
	ASSERT_STRUCT_OFFSET(TIMED_RADIUS_DAMAGE, damage, 0x14);
	ASSERT_STRUCT_OFFSET(TIMED_RADIUS_DAMAGE, rate, 0x18);
	ASSERT_STRUCT_OFFSET(TIMED_RADIUS_DAMAGE, mod, 0x1C);
	ASSERT_STRUCT_OFFSET(TIMED_RADIUS_DAMAGE, weapon, 0x20);

	struct VehicleLocalPhysics
	{
		trace_t groundTrace; //OFS: 0x0 SIZE: 0x34
		int hasGround; //OFS: 0x34 SIZE: 0x4
		int onGround; //OFS: 0x38 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(VehicleLocalPhysics, 0x3C);
	ASSERT_STRUCT_OFFSET(VehicleLocalPhysics, groundTrace, 0x0);
	ASSERT_STRUCT_OFFSET(VehicleLocalPhysics, hasGround, 0x34);
	ASSERT_STRUCT_OFFSET(VehicleLocalPhysics, onGround, 0x38);

	struct VehiclePhysicsBackup
	{
		vehicle_pathpos_t pathPos; //OFS: 0x0 SIZE: 0xC0
		vehicle_physic_t phys; //OFS: 0xC0 SIZE: 0x108
	};
	ASSERT_STRUCT_SIZE(VehiclePhysicsBackup, 0x1C8);
	ASSERT_STRUCT_OFFSET(VehiclePhysicsBackup, pathPos, 0x0);
	ASSERT_STRUCT_OFFSET(VehiclePhysicsBackup, phys, 0xC0);

	struct phys_free_list_NitrousVehicle_T_internal_base
	{
		phys_free_list_NitrousVehicle_T_internal * m_prev_T_internal; //OFS: 0x0 SIZE: 0x4
		phys_free_list_NitrousVehicle_T_internal * m_next_T_internal; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(phys_free_list_NitrousVehicle_T_internal_base, 0x8);
	ASSERT_STRUCT_OFFSET(phys_free_list_NitrousVehicle_T_internal_base, m_prev_T_internal, 0x0);
	ASSERT_STRUCT_OFFSET(phys_free_list_NitrousVehicle_T_internal_base, m_next_T_internal, 0x4);

	struct phys_free_list_NitrousVehicle_T_internal
	{
		NitrousVehicle m_data; //OFS: 0x0 SIZE: 0x380
		phys_free_list_NitrousVehicle_T_internal_base m_ptr; //OFS: 0x380 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(phys_free_list_NitrousVehicle_T_internal, 0x388);
	ASSERT_STRUCT_OFFSET(phys_free_list_NitrousVehicle_T_internal, m_data, 0x0);
	ASSERT_STRUCT_OFFSET(phys_free_list_NitrousVehicle_T_internal, m_ptr, 0x380);

	struct phys_memory_heap
	{
		char * m_buffer_start; //OFS: 0x0 SIZE: 0x4
		char * m_buffer_end; //OFS: 0x4 SIZE: 0x4
		char * m_buffer_cur; //OFS: 0x8 SIZE: 0x4
		char * m_user_start; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(phys_memory_heap, 0x10);
	ASSERT_STRUCT_OFFSET(phys_memory_heap, m_buffer_start, 0x0);
	ASSERT_STRUCT_OFFSET(phys_memory_heap, m_buffer_end, 0x4);
	ASSERT_STRUCT_OFFSET(phys_memory_heap, m_buffer_cur, 0x8);
	ASSERT_STRUCT_OFFSET(phys_memory_heap, m_user_start, 0xC);

	struct phys_memory_manager_new
	{
		int m_memory_buffer_size; //OFS: 0x0 SIZE: 0x4
		int m_memory_buffer_alignment; //OFS: 0x4 SIZE: 0x4
		void * m_memory_buffer; //OFS: 0x8 SIZE: 0x4
		phys_memory_heap m_allocater; //OFS: 0xC SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(phys_memory_manager_new, 0x1C);
	ASSERT_STRUCT_OFFSET(phys_memory_manager_new, m_memory_buffer_size, 0x0);
	ASSERT_STRUCT_OFFSET(phys_memory_manager_new, m_memory_buffer_alignment, 0x4);
	ASSERT_STRUCT_OFFSET(phys_memory_manager_new, m_memory_buffer, 0x8);
	ASSERT_STRUCT_OFFSET(phys_memory_manager_new, m_allocater, 0xC);

	struct phys_free_list_NitrousVehicle
	{
		phys_free_list_NitrousVehicle_T_internal_base m_dummy_head; //OFS: 0x0 SIZE: 0x8
		int m_allocated_slot_count; //OFS: 0x8 SIZE: 0x4
		phys_memory_manager_new * m_pmm; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(phys_free_list_NitrousVehicle, 0x10);
	ASSERT_STRUCT_OFFSET(phys_free_list_NitrousVehicle, m_dummy_head, 0x0);
	ASSERT_STRUCT_OFFSET(phys_free_list_NitrousVehicle, m_allocated_slot_count, 0x8);
	ASSERT_STRUCT_OFFSET(phys_free_list_NitrousVehicle, m_pmm, 0xC);

	struct HudGrenade
	{
		float origin[3]; //OFS: 0x0 SIZE: 0xC
		float predicted_dmg_ratio; //OFS: 0xC SIZE: 0x4
		float predicted_time_ratio; //OFS: 0x10 SIZE: 0x4
		Material * material; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(HudGrenade, 0x18);
	ASSERT_STRUCT_OFFSET(HudGrenade, origin, 0x0);
	ASSERT_STRUCT_OFFSET(HudGrenade, predicted_dmg_ratio, 0xC);
	ASSERT_STRUCT_OFFSET(HudGrenade, predicted_time_ratio, 0x10);
	ASSERT_STRUCT_OFFSET(HudGrenade, material, 0x14);

	struct SaveTimeGlob
	{
		bool isSaving; //OFS: 0x0 SIZE: 0x1
		bool callWrite; //OFS: 0x1 SIZE: 0x1
		int saveTime; //OFS: 0x4 SIZE: 0x4
		bool hasfirstFrameShown; //OFS: 0x8 SIZE: 0x1
		const char * saveMenuName; //OFS: 0xC SIZE: 0x4
		char execOnSuccess[256]; //OFS: 0x10 SIZE: 0x100
		bool hasExecOnSuccess; //OFS: 0x110 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(SaveTimeGlob, 0x114);
	ASSERT_STRUCT_OFFSET(SaveTimeGlob, isSaving, 0x0);
	ASSERT_STRUCT_OFFSET(SaveTimeGlob, callWrite, 0x1);
	ASSERT_STRUCT_OFFSET(SaveTimeGlob, saveTime, 0x4);
	ASSERT_STRUCT_OFFSET(SaveTimeGlob, hasfirstFrameShown, 0x8);
	ASSERT_STRUCT_OFFSET(SaveTimeGlob, saveMenuName, 0xC);
	ASSERT_STRUCT_OFFSET(SaveTimeGlob, execOnSuccess, 0x10);
	ASSERT_STRUCT_OFFSET(SaveTimeGlob, hasExecOnSuccess, 0x110);

	struct SentientGlobals
	{
		int lastTime; //OFS: 0x0 SIZE: 0x4
		int lastSample; //OFS: 0x4 SIZE: 0x4
		float playerTrail[2][3]; //OFS: 0x8 SIZE: 0x18
		int sampleTime[2]; //OFS: 0x20 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(SentientGlobals, 0x28);
	ASSERT_STRUCT_OFFSET(SentientGlobals, lastTime, 0x0);
	ASSERT_STRUCT_OFFSET(SentientGlobals, lastSample, 0x4);
	ASSERT_STRUCT_OFFSET(SentientGlobals, playerTrail, 0x8);
	ASSERT_STRUCT_OFFSET(SentientGlobals, sampleTime, 0x20);

	struct DynEnt_FadeData
	{
		unsigned __int16 id; //OFS: 0x0 SIZE: 0x2
		int startTime; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DynEnt_FadeData, 0x8);
	ASSERT_STRUCT_OFFSET(DynEnt_FadeData, id, 0x0);
	ASSERT_STRUCT_OFFSET(DynEnt_FadeData, startTime, 0x4);



#ifdef __cplusplus
}
#endif