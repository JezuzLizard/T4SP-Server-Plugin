#include <stdinc.hpp>
#include "game.hpp"

#include <utils/hook.hpp>
#include <utils/memory.hpp>
#include <utils/string.hpp>

namespace game
{
	gamemode current = reinterpret_cast<const char*>(0x88A5DC) != "CoDWaW.exe"s
		? gamemode::multiplayer
		: gamemode::singleplayer;

	namespace environment
	{
		bool t4mp()
		{
			return current == gamemode::multiplayer;
		}

		bool t4sp()
		{
			return current == gamemode::singleplayer;
		}
	}

	std::map<std::string, team_t> team_map =
	{
		{ "free", TEAM_FREE },
		{ "axis", TEAM_AXIS },
		{ "allies", TEAM_ALLIES },
		{ "neutral", TEAM_NEUTRAL },
		{ "dead", TEAM_DEAD }
	};

	void G_ClientDoPerFrameNotifies(gentity_s* ent, void* call_addr)
	{
		__asm
		{
			mov edi, ent;
			call call_addr;
		}
	}

	void Scr_PrintPrevCodePos(const char* codepos, int scriptInstance, con_channel_e channel, int index)
	{
		static const auto call_addr = SELECT(0x0, 0x68B340);

		__asm
		{
			push index;
			push channel;
			push scriptInstance;
			mov eax, codepos;
			call call_addr;
			add esp, 0xC;
		}
	}

	void RemoveRefToObject(scriptInstance_t inst/*<ecx>*/, unsigned int id/*<eax>*/)
	{
		static const auto call_addr = SELECT(0x0, 0x690040);

		__asm
		{
			mov ecx, inst;
			mov eax, id;
			call call_addr;
		}
	}

	int Scr_LoadScript(const char* file, scriptInstance_t inst)
	{
		static const auto call_addr = SELECT(0x646DE0, 0x689C60);
		int answer;

		__asm
		{
			mov ecx, file;
			mov edx, inst;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	unsigned int Scr_GetFunctionHandle/*<eax>*/(scriptInstance_t inst/*<ecx>*/, const char* file/*<eax>*/, const char* handle)
	{
		static const auto call_addr = SELECT(0x0, 0x6894B0);

		unsigned int answer;

		__asm
		{
			push handle;
			mov eax, file;
			mov ecx, inst;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}

		return answer;
	}

	int Scr_GetInt(game::scriptInstance_t inst, unsigned int arg_index)
	{
		static const auto call_addr = SELECT(0x0, 0x699C50);
		int answer;

		__asm
		{
			mov ecx, arg_index;
			mov eax, inst;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	void Scr_AddInt(game::scriptInstance_t inst, int value)
	{
		static const auto call_addr = SELECT(0x0, 0x69A610);

		__asm
		{
			push value;
			mov eax, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	float Scr_GetFloat(game::scriptInstance_t inst, unsigned int arg_index)
	{
		static const auto call_addr = SELECT(0x0, 0x699E90);
		float answer;

		__asm
		{
			mov ecx, arg_index;
			mov eax, inst;
			call call_addr;
			movss answer, xmm0;
		}

		return answer;
	}

	void Scr_AddFloat(game::scriptInstance_t inst, float value)
	{
		static const auto call_addr = SELECT(0x0, 0x69A670);

		__asm
		{
			push value;
			mov eax, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	char* Scr_GetString(game::scriptInstance_t inst, unsigned int arg_index)
	{
		static const auto call_addr = SELECT(0x0, 0x69A0D0);
		char* answer;

		__asm
		{
			mov esi, inst;
			mov eax, arg_index;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	void Scr_AddString(game::scriptInstance_t inst, const char* string)
	{
		static const auto call_addr = SELECT(0x0, 0x69A7E0);

		__asm
		{
			push string;
			mov eax, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	const char* Scr_GetIString(game::scriptInstance_t inst, unsigned int arg_index)
	{
		static const auto call_addr = SELECT(0x0, 0x69A1A0); //Scr_GetConstIString

		int id;

		__asm
		{
			mov eax, arg_index;
			call call_addr;
			mov id, eax;
		}

		return SL_ConvertToString(inst, id);
	}

	void Scr_AddIString(game::scriptInstance_t inst, const char* string)
	{
		static const auto call_addr = SELECT(0x0, 0x69A860);

		__asm
		{
			mov esi, string;
			call call_addr;
		}
	}

	unsigned short Scr_GetConstString(game::scriptInstance_t inst, unsigned int arg_index)
	{
		static const auto call_addr = SELECT(0x0, 0x699F30);

		unsigned short answer;

		__asm
		{
			push arg_index;
			mov eax, inst;
			call call_addr;
			mov answer, cx;
			add esp, 0x4;
		}

		return answer;
	}

	void Scr_AddConstString(game::scriptInstance_t inst, unsigned short id)
	{
		static const auto call_addr = SELECT(0x0, 0x69A8D0);

		__asm
		{
			mov si, id;
			mov eax, inst;
			call call_addr;
		}
	}

	void Scr_GetVector(game::scriptInstance_t inst, unsigned int arg_index, float* value)
	{
		static const auto call_addr = SELECT(0x0, 0x69A220);

		__asm
		{
			push arg_index;
			mov ecx, value;
			mov eax, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	void Scr_AddVector(game::scriptInstance_t inst, float* value)
	{
		static const auto call_addr = SELECT(0x0, 0x69A940);

		__asm
		{
			push value;
			mov eax, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	void Scr_AddUndefined(game::scriptInstance_t inst)
	{
		static const auto call_addr = SELECT(0x0, 0x69A720);

		__asm
		{
			mov eax, inst;
			call call_addr;
		}
	}

	gentity_s* Scr_GetEntity(unsigned int arg_index)
	{
		static const auto call_addr = SELECT(0x0, 0x546E30);
		gentity_s* answer;

		__asm
		{
			mov eax, arg_index;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	void Scr_AddEntity(game::scriptInstance_t inst, gentity_s* ent)
	{
		static const auto call_addr = SELECT(0x0, 0x546D90);

		__asm
		{
			mov edi, inst;
			mov eax, ent;
			call call_addr;
		}
	}

	unsigned int Scr_GetEntityId(scriptInstance_t inst, unsigned int entnum, classNum_e classnum, unsigned int clientnum, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			push clientnum;
			push classnum;
			push inst;
			mov eax, entnum;
			call call_addr;
			add esp, 0xC;
			mov answer, eax;
		}

		return answer;
	}

	void Scr_AddEntityNum(scriptInstance_t inst, unsigned int entid)
	{
		static const auto call_addr = SELECT(0x0, 0x69A770);

		__asm
		{
			mov esi, entid;
			mov eax, inst;
			call call_addr;
		}
	}

	//Only supports getting the first argument as a path node
	pathnode_t* Scr_GetPathnode(scriptInstance_t inst)
	{
		static const auto call_addr = SELECT(0x0, 0x559E20);
		pathnode_t* answer;

		__asm
		{
			mov eax, inst;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	void Scr_AddPathnode(scriptInstance_t inst, pathnode_t* node)
	{
		unsigned int entnum = node - (*gameWorldCurrent)->path.nodes;
		auto entid = Scr_GetEntityId(inst, entnum, CLASS_NUM_PATHNODE, 0);
		Scr_AddEntityNum(inst, entid);
	}

	void Scr_AddHudElem(game_hudelem_s* hud)
	{
		int entId = Scr_GetEntityId(SCRIPTINSTANCE_SERVER, hud - g_hudelems, CLASS_NUM_HUDELEM, 0);
		Scr_AddObject(SCRIPTINSTANCE_SERVER, entId);
	}

	void Scr_AddObject(scriptInstance_t inst/*<eax>*/, int entid/*<esi>*/)
	{
		static const auto call_addr = SELECT(0x0, 0x69A770);

		__asm
		{
			mov esi, entid;
			mov eax, inst;
			call call_addr;
		}
	}

	void Scr_MakeArray(scriptInstance_t inst)
	{
		static const auto call_addr = SELECT(0x0, 0x69A9D0);

		__asm
		{
			mov eax, inst;
			call call_addr;
		}
	}

	void Scr_AddArrayStringIndexed(scriptInstance_t inst, unsigned short id)
	{
		static const auto call_addr = SELECT(0x0, 0x69AAF0);

		__asm
		{
			mov edi, inst;
			movzx ecx, id;
			call call_addr;
		}
	}

	unsigned short Scr_ExecThread/*<ax>*/(scriptInstance_t inst/*<edi>*/, int handle, int paramCount)
	{
		static const auto call_addr = SELECT(0x0, 0x699560);

		unsigned short answer;

		__asm
		{
			push paramCount;
			push handle;
			mov edi, inst;
			call call_addr;
			add esp, 0x8;
			mov answer, ax;
		}

		return answer;
	}

	unsigned short Scr_ExecEntThread/*<ax>*/(scriptInstance_t inst/*<edi>*/, int entNum, int handle, int numParams, int entClass)
	{
		static const auto call_addr = SELECT(0x0, 0x699640);

		unsigned short answer;

		__asm
		{
			push entClass;
			push numParams;
			push handle;
			push entNum;
			mov edi, inst;
			call call_addr;
			add esp, 0x10;
			mov answer, ax;
		}

		return answer;
	}

	void Scr_NotifyNum(scriptInstance_t inst, int entNum, int entClass, unsigned int notifStr, int numParams, void* call_addr)
	{
		__asm
		{
			push numParams;
			push notifStr;
			push entClass;
			push entNum;
			mov eax, inst;
			call call_addr;
			add esp, 0x10;
		}
	}

	unsigned int GetArrayVariableIndex(unsigned int unsignedValue, scriptInstance_t inst, unsigned int parentId, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			push parentId;
			push inst;
			mov eax, unsignedValue;
			call call_addr;
			mov answer, eax;
			add esp, 0x8;
		}

		return answer;
	}

	unsigned int Scr_GetNumParam(scriptInstance_t inst)
	{
		return gScrVmPub[inst].outparamcount;
	}

	VariableType Scr_GetType(scriptInstance_t inst, unsigned int index)
	{
		static const auto call_addr = SELECT(0x0, 0x69A4E0);
		VariableType answer;

		__asm
		{
			mov eax, inst;
			mov ecx, index;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	void Scr_Error(const char* err, scriptInstance_t inst, bool is_terminal)
	{
		static const auto call_addr = SELECT(0x0, 0x69AB70);

		__asm
		{
			push is_terminal;
			mov edi, inst;
			mov ecx, err;
			call call_addr;
			add esp, 0x4;
		}
	}

	const char* SL_ConvertToString(scriptInstance_t inst, int id)
	{
		static const auto call_addr = SELECT(0x0, 0x68D950);
		const char* answer;

		__asm
		{
			mov ecx, inst;
			mov eax, id;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	const char* Cmd_Argv(int index)
	{
		static const auto call_addr = SELECT(0x0, 0x435CE0);
		const char* answer;

		__asm
		{
			mov eax, index;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	unsigned int Cmd_Argc()
	{
		return cmd_args->argc[cmd_args->nesting];
	}

	void Cmd_AddCommand(const char* name, void(__cdecl* function)())
	{
		auto newCmd = utils::memory::allocate<game::cmd_function_s>();
		auto name_dup = utils::memory::duplicate_string(name);

		*newCmd = {};
		newCmd->next = *game::cmd_functions;
		newCmd->function = function;
		newCmd->name = name_dup;

		*game::cmd_functions = newCmd;
	}

	dvar_s* Dvar_RegisterInt(const char* name, int value, int min, int max, DvarFlags flags, const char* desc)
	{
		DvarLimits limits;
		DvarValue dvar_value;
		limits.integer.min = min;
		limits.integer.max = max;
		dvar_value.integer = value;
		return Dvar_RegisterVariant(name, game::DVAR_TYPE_INT, flags, dvar_value, limits, desc);
	}

	dvar_s* Dvar_RegisterString(const char* name, const char* value, DvarFlags flags, const char* desc)
	{
		DvarLimits limits = {};
		DvarValue dvar_value;
		dvar_value.string = value;
		return Dvar_RegisterVariant(name, game::DVAR_TYPE_STRING, flags, dvar_value, limits, desc);
	}

	const char* Dvar_ValueToString(dvar_s* dvar, DvarValue dvarValue)
	{
		static const auto call_addr = SELECT(0x0, 0x5ECAB0);

		const char* answer;

		__asm
		{
			push dvarValue;
			mov ecx, dvar;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}

		return answer;
	}

	void Dvar_SetVariant(dvar_s* dvar, DvarValue val, DvarSetSource dvarSetSource)
	{
		static const auto call_addr = SELECT(0x0, 0x5EDA40);

		__asm
		{
			push dvarSetSource;
			push val;
			push dvar;
			call call_addr;
			add esp, 0xC;
		}
	}

	int Path_FindPath(path_t* pPath, team_t eTeam, float* vStartPos, float* vGoalPos, int bAllowNegotiationLinks)
	{
		static const auto call_addr = SELECT(0x0, 0x4CF280);

		int answer;

		__asm
		{
			push bAllowNegotiationLinks;
			push vGoalPos;
			push vStartPos;
			mov edx, eTeam;
			mov ecx, pPath;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	pathnode_t* Path_NearestNodeNotCrossPlanes(int typeFlags, int maxNodes, float* vOrigin, pathsort_t* nodes, float fMaxDist, float a6, float a7, int iPlaneCount, int* returnCount, nearestNodeHeightCheck heightCheck)
	{
		static const auto call_addr = SELECT(0x0, 0x55C210);

		pathnode_t* answer;

		__asm
		{
			push heightCheck;
			push returnCount;
			push iPlaneCount;
			push a7;
			push a6;
			push fMaxDist;
			push nodes;
			push vOrigin;
			mov ecx, maxNodes;
			mov edx, typeFlags;
			call call_addr;
			add esp, 0x20;
			mov answer, eax;
		}

		return answer;
	}

	//This is a __userpurge, which automatically cleans up the stack by itself so do not do add esp
	int Path_FindPathFromTo(float* startPos, pathnode_t* pNodeTo, path_t* pPath, team_t eTeam, pathnode_t* pNodeFrom, float* vGoalPos, int bAllowNegotiationLinks, int bIgnoreBadplaces)
	{
		static const auto call_addr = SELECT(0x0, 0x4CF3F0);

		int answer;

		__asm
		{
			push bIgnoreBadplaces;
			push bAllowNegotiationLinks;
			push vGoalPos;
			push pNodeFrom;
			push eTeam;
			push pPath;
			mov edx, pNodeTo;
			mov eax, startPos;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	//This is a __userpurge, which automatically cleans up the stack by itself so do not do add esp
	int Path_GeneratePath(path_t* pPath, team_t eTeam, const float* vStartPos, float* vGoalPos, pathnode_t* pNodeFrom, pathnode_t* pNodeTo, int bIncludeGoalPos, int bAllowNegotiationLinks)
	{
		static const auto call_addr = SELECT(0x0, 0x4CED90);

		int answer;

		__asm
		{
			push bAllowNegotiationLinks;
			push bIncludeGoalPos;
			push pNodeTo;
			push pNodeFrom;
			push vGoalPos;
			push vStartPos;
			push eTeam;
			mov eax, pPath;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	void /*__userpurge*/ Path_UpdateLookahead(path_t* pPath/*@<eax>*/, const float* vStartPos, int bReduceLookaheadAmount, int a4, int bAllowBacktrack)
	{
		static const auto call_addr = SELECT(0x0, 0x4D2120);

		__asm
		{
			push bAllowBacktrack;
			push a4;
			push bReduceLookaheadAmount;
			push vStartPos;
			mov eax, pPath;
			call call_addr;
		}
	}

	void /*__usercall*/ Path_AddTrimmedAmount(const float* a1/*@<eax>*/, path_t* a2/*@<edi>*/)
	{
		static const auto call_addr = SELECT(0x0, 0x4CE560);

		__asm
		{
			mov edi, a2;
			mov eax, a1;
			call call_addr;
		}
	}

	void /*__stdcall*/ Path_TransferLookahead(path_t* a1, const float* a2)
	{
		static const auto call_addr = SELECT(0x0, 0x4CE980);

		__asm
		{
			push a2;
			push a1;
			call call_addr;
		}
	}

	bool PM_IsSprinting(const playerState_s* ps)
	{
		return ps->sprintState.lastSprintStart && ps->sprintState.lastSprintStart > ps->sprintState.lastSprintEnd;
	}

	game::pathnode_t* Path_ConvertIndexToNode(int index)
	{
		return &(*game::gameWorldCurrent)->path.nodes[index];
	}

	unsigned int __cdecl Path_ConvertNodeToIndex(const game::pathnode_t* node)
	{
		return node - (*gameWorldCurrent)->path.nodes;
	}

	game::pathnode_t* Path_GetNegotiationNode(const game::path_t* pPath)
	{
		return Path_ConvertIndexToNode(pPath->pts[pPath->wNegotiationStartNode].iNodeNum);
	}

	void Path_IncrementNodeUserCount(game::path_t* pPath)
	{
		game::pathnode_t* negotiationNode; // [esp+4h] [ebp-4h]

		negotiationNode = Path_GetNegotiationNode(pPath);
		++negotiationNode->dynamic.userCount;
	}

	void Path_DecrementNodeUserCount(game::path_t* pPath)
	{
		game::pathnode_t* negotiationNode; // [esp+4h] [ebp-4h]

		negotiationNode = Path_GetNegotiationNode(pPath);
		--negotiationNode->dynamic.userCount;
	}

	void Path_Clear(game::path_t* pPath)
	{
		if (pPath->wNegotiationStartNode > 0)
		{
			Path_DecrementNodeUserCount(pPath);
			pPath->wNegotiationStartNode = 0;
		}
		pPath->wPathLen = 0;
		pPath->wOrigPathLen = 0;
	}

	float Vec2Length(const float* v)
	{
		return sqrt((*v * *v) + (v[1] * v[1]));
	}

	float Path_GetPathDir(float* delta, const float* vFrom, const float* vTo)
	{
		float fDist; // [esp+18h] [ebp-4h]

		delta[0] = *vTo - vFrom[0];
		delta[1] = vTo[1] - vFrom[1];
		fDist = Vec2Length(delta);
		delta[0] = (1.0 / fDist) * delta[0];
		delta[1] = (1.0 / fDist) * delta[1];
		return fDist;
	}

	float Vec3DistanceSq(const float* p1, const float* p2)
	{
		float vDiffY; // [esp+4h] [ebp-8h]
		float vDiffZ; // [esp+8h] [ebp-4h]

		vDiffY = p2[1] - p1[1];
		vDiffZ = p2[2] - p1[2];
		return vDiffZ * vDiffZ + vDiffY * vDiffY + (float)(*p2 - *p1) * (float)(*p2 - *p1);
	}

	float EvaluateHeuristic(game::CustomSearchInfo_FindPath* searchInfo, game::pathnode_t* pSuccessor, const float* vGoalPos)
	{
		float v[2]; // [esp+18h] [ebp-Ch] BYREF
		float dist; // [esp+20h] [ebp-4h]

		v[0] = *vGoalPos - pSuccessor->constant.vOrigin[0];
		v[1] = vGoalPos[1] - pSuccessor->constant.vOrigin[1];
		dist = Vec2Length(v);
		dist = (pSuccessor->dynamic.userCount * searchInfo->negotiationOverlapCost) + dist;
		if (pSuccessor->constant.minUseDistSq > 1.0
			&& pSuccessor->constant.minUseDistSq > Vec3DistanceSq(pSuccessor->constant.vOrigin, searchInfo->startPos))
		{
			dist = dist + searchInfo->negotiationOverlapCost;
		}
		return dist;
	}

	VariableUnion Scr_GetObject(unsigned int index, scriptInstance_t inst)
	{
		const char* v3; // eax
		const char* v4; // eax
		VariableValue* value; // [esp+0h] [ebp-4h]

		if (index < gScrVmPub[inst].outparamcount)
		{
			value = &gScrVmPub[inst].top[-index];
			if (value->type == VAR_BEGIN_REF)
				return value->u;
			gScrVarPub[inst].error_index = index + 1;
			v3 = utils::string::va("type %s is not an object", var_typename[value->type]);
			Scr_Error(v3, inst, 0);
		}
		v4 = utils::string::va("parameter %d does not exist", index + 1);
		Scr_Error(v4, inst, 0);
		return value->u;
	}

	unsigned int GetArraySize(scriptInstance_t inst, unsigned int id)
	{
		VariableValueInternal* entryValue; // [esp+0h] [ebp-4h]

		entryValue = &gScrVarGlob[inst].parentVariables[id + 1];
		return entryValue->u.o.u.size;
	}

	unsigned int GetArrayVariable(scriptInstance_t inst, unsigned int parentId, unsigned int unsignedValue)
	{
		return gScrVarGlob[inst].childVariables[GetArrayVariableIndex(unsignedValue, inst, parentId)].hash.id;
	}

	unsigned int __cdecl Scr_GetFunc(scriptInstance_t inst, unsigned int index)
	{
		VariableValue* value; // [esp+0h] [ebp-4h]

		if (index >= gScrVmPub[inst].outparamcount)
		{
			Scr_Error(utils::string::va("parameter %d does not exist", index + 1), inst, false);
			return 0;
		}
		value = &gScrVmPub[inst].top[-index];
		if (value->type != VAR_FUNCTION)
		{
			gScrVarPub[inst].error_index = index + 1;
			Scr_Error(utils::string::va("type %s is not a function", var_typename[value->type]), inst, false);
			return 0;
		}
		return value->u.intValue - (unsigned int)gScrVarPub[inst].programBuffer;
	}

	void Dvar_Reset(DvarSetSource dvarSetSource, dvar_s* dvar)
	{
		return Dvar_SetVariant(dvar, dvar->reset, dvarSetSource);
	}

	void SV_SendServerCommand(client_s* clientArg, svscmd_type type, char* Format, ...)
	{
		client_s* i; // esi
		va_list ArgList; // [esp+18h] [ebp+Ch] BYREF

		va_start(ArgList, Format);
		_vsnprintf(tempServerCommandBuf, 0x20000u, Format, ArgList);
		if (clientArg)
		{
			SV_AddServerCommand(clientArg, type, tempServerCommandBuf);
		}
		else
		{
			if ((*com_dedicated)->current.integer && !strncmp(tempServerCommandBuf, "print", 5u))
			{
				Com_PrintF(CON_CHANNEL_SERVER, "broadcast: %s\n", SV_ExpandNewlines());
			}
			for (auto i = 0; i < (*sv_maxclients)->current.integer; ++i)
			{
				auto client = &svs->clients[i];
				if (client->header.state >= CS_PRIMED)
				{
					SV_AddServerCommand(client, type, tempServerCommandBuf);
				}
			}
		}
	}

	void Sentient_GetVelocity(sentient_s* self, float* vVelOut)
	{
		static const auto call_addr = SELECT(0x0, 0x5662A0);

		__asm
		{
			mov ecx, vVelOut;
			mov eax, self;
			call call_addr;
		}
	}

	namespace plutonium
	{
	}
}
