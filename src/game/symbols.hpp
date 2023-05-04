#pragma once

#define WEAK __declspec(selectany)

namespace game
{
	// Functions

	WEAK symbol<void(con_channel_e channel, const char* fmt, ...)> Com_PrintF{ 0x0, 0x59A2C0 };
	WEAK symbol<dvar_s*(const char* name, dvarType_t type, DvarFlags flags, DvarValue dval, DvarLimits dom, const char* desc)> Dvar_RegisterVariant{ 0x0, 0x5EED90 };
	WEAK symbol<dvar_s* (char* name)> Dvar_FindMalleableVar{ 0x0, 0x5EDE30 };
	WEAK symbol<void(client_s* client, svscmd_type type, const char* buffer)> SV_AddServerCommand{ 0x0, 0x633D30 };
	WEAK symbol<char* ()> SV_ExpandNewlines{ 0x0, 0x633AD0 };

	WEAK symbol<void(scriptInstance_t inst)> Scr_AddArray { 0x0, 0x69AA50 };
	WEAK symbol<unsigned int(scriptInstance_t inst, char* string, int user, unsigned int len)> SL_GetStringOfSize { 0x0, 0x68DE50 };

	WEAK symbol<int(path_t* pPath, team_t eTeam, const float* vStartPos, pathnode_t* pNodeFrom, const float* vGoalPos, int bAllowNegotiationLinks, CustomSearchInfo_FindPath* custom, int bIncludeGoalInPath, pathnode_t* bIgnoreBadPlaces)> Path_AStarAlgorithm_CustomSearchInfo_FindPath_{ 0x0, 0x4D3190 };

	// Variables

	WEAK symbol<char> tempServerCommandBuf{ 0x0, 0x2FCDC00 };

	WEAK symbol<cmd_function_s*> cmd_functions{ 0x0, 0x1F416F4 };
	WEAK symbol<CmdArgs> cmd_args{ 0x0, 0x1F41670 };
	WEAK symbol<serverStatic_s> svs{ 0x0, 0x23D5C80 };
	WEAK symbol<GameWorldSp*> gameWorldCurrent{ 0x0, 0x8E1D80 };
	WEAK symbol<pathlocal_t> g_path{ 0x0, 0x1F2F700 };
	WEAK symbol<gentity_s> g_entities{ 0x0, 0x176C6F0 };
	WEAK symbol<game_hudelem_s> g_hudelems{ 0x0, 0x173C6F0 };
	WEAK symbol<scrVarPub_t> gScrVarPub{ 0x0, 0x3882B70 };
	WEAK symbol<scrVmPub_t> gScrVmPub{ 0x0, 0x3BD4700 };
	WEAK symbol<level_locals_s> level{ 0x0, 0x18F5D88 };
	WEAK symbol<float*> g_pathAttemptGoalPos{ 0x0, 0x16CFD6C };
	//WEAK symbol<scrParserPub_t> scrParserPub{ 0x0, 0x3882B00 };
	WEAK symbol<scrVarGlob_t> gScrVarGlob{ 0x0, 0x3914700 };

	WEAK symbol<function_stack_t> function_stack{ 0x0, 0x3BDDDD0 };
	WEAK symbol<scr_const_t> scr_const{0x0, 0x1F33B90};
	WEAK symbol<char*> var_typename{ 0x0, 0x8CF4B0 };

	WEAK symbol<WeaponDef*> BG_WeaponNames{ 0x0, 0x8F6770 };

	// Dvars

	WEAK symbol<dvar_s*> com_developer{ 0x0, 0x1F55288 };
	WEAK symbol<dvar_s*> com_logfile{ 0x0, 0x1F552BC };
	WEAK symbol<dvar_s*> com_developer_script{ 0x0, 0x1F9646C };
	WEAK symbol<dvar_s*> com_dedicated{ 0x0, 0x212B2F4 };
	WEAK symbol<dvar_s*> ai_pathNegotiationOverlapCost{ 0x0, 0x18FB224 };
	WEAK symbol<dvar_s*> fs_homepath{ 0x0, 0x2123C1C };
	WEAK symbol<dvar_s*> fs_game{ 0x0, 0x2122B00 };
	WEAK symbol<dvar_s*> useFastFile{ 0x0, 0x1F552FC };
	WEAK symbol<dvar_s*> sv_running{ 0x0, 0x1F552DC };
	WEAK symbol<dvar_s*> sv_maxclients{ 0x0, 0x23D5C30 };
	WEAK symbol<dvar_s*> g_connectpaths{ 0x0, 0x18ECF8C };
	WEAK symbol<dvar_s*> r_reflectionProbeGenerate{ 0x0, 0x3BFD478 };

	namespace plutonium
	{
	}
}
