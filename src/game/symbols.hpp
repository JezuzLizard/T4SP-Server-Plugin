#pragma once

#define WEAK __declspec(selectany)

namespace game
{
	// Functions

	WEAK symbol<void(con_channel_e channel, const char* fmt, ...)> Com_PrintF{ 0x0, 0x59A2C0 };
	WEAK symbol<dvar_s*(const char* name, dvarType_t type, DvarFlags flags, DvarValue dval, DvarLimits dom, const char* desc)> Dvar_RegisterVariant{ 0x0, 0x5EED90 };

	WEAK symbol<void(scriptInstance_t inst)> Scr_AddArray { 0x0, 0x69AA50 };
	WEAK symbol<unsigned int(scriptInstance_t inst, char* string, int user, unsigned int len)> SL_GetStringOfSize { 0x0, 0x68DE50 };

	WEAK symbol<int(path_t* pPath, team_t eTeam, const float* vStartPos, pathnode_t* pNodeFrom, const float* vGoalPos, int bAllowNegotiationLinks, CustomSearchInfo_FindPath* custom, int bIncludeGoalInPath, pathnode_t* bIgnoreBadPlaces)> Path_AStarAlgorithm_CustomSearchInfo_FindPath_{ 0x0, 0x4D3190 };

	// Variables

	WEAK symbol<cmd_function_s*> cmd_functions{ 0x0, 0x1F416F4 };
	WEAK symbol<CmdArgs> cmd_args{ 0x0, 0x1F41670 };

	WEAK symbol<GameWorldSp*> gameWorldCurrent{ 0x0, 0x8E1D80 };

	WEAK symbol<pathlocal_t> g_path{ 0x0, 0x1F2F700 };

	WEAK symbol<gentity_s> g_entities{ 0x0, 0x176C6F0 };

	WEAK symbol<scrVmPub_t> scrVmPub{ 0x0, 0x3BD4700 };

	WEAK symbol<dvar_s*> ai_pathNegotiationOverlapCost{ 0x0, 0x18FB224 };

	namespace plutonium
	{
	}
}
