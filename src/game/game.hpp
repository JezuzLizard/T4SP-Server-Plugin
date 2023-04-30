#pragma once

#include "structs.hpp"

#define SELECT(mp, sp) (game::environment::t4mp() ? mp : sp)
#define CALL_ADDR(mp, sp) reinterpret_cast<void*>(SELECT(mp, sp))

namespace game
{
	enum gamemode
	{
		multiplayer,
		singleplayer,
		none
	};

	extern gamemode current;

	namespace environment
	{
		bool t4mp();
		bool t4sp();
	}

	extern std::map<std::string, team_t> team_map;

	__inline void* G_ClientDoPerFrameNotifies() { return CALL_ADDR(0x0, 0x503540); }
	void G_ClientDoPerFrameNotifies(gentity_s* ent, void* call_addr = G_ClientDoPerFrameNotifies());

	void Scr_PrintPrevCodePos(const char* codepos, int scriptInstance, con_channel_e channel, int index);
	void RemoveRefToObject(scriptInstance_t inst, unsigned int id);
	int Scr_LoadScript(const char* file, scriptInstance_t inst);
	unsigned int Scr_GetFunctionHandle(scriptInstance_t inst, const char* file, const char* handle);

	const char* Cmd_Argv(int index);
	unsigned int Cmd_Argc();
	void Cmd_AddCommand(const char* name, void(__cdecl* function)());

	dvar_s* Dvar_RegisterInt(const char* name, int value, int min, int max, DvarFlags flags, const char* desc);
	dvar_s* Dvar_RegisterString(const char* name, const char* value, DvarFlags flags, const char* desc);

	int Scr_GetInt(game::scriptInstance_t inst, unsigned int arg_index);
	void Scr_AddInt(game::scriptInstance_t inst, int value);
	float Scr_GetFloat(game::scriptInstance_t inst, unsigned int arg_index);
	void Scr_AddFloat(game::scriptInstance_t inst, float value);
	char* Scr_GetString(game::scriptInstance_t inst, unsigned int arg_index);
	void Scr_AddString(game::scriptInstance_t inst, const char* string);
	const char* Scr_GetIString(game::scriptInstance_t inst, unsigned int arg_index);
	void Scr_AddIString(game::scriptInstance_t inst, const char* string);
	unsigned short Scr_GetConstString(game::scriptInstance_t inst, unsigned int arg_index);
	void Scr_AddConstString(game::scriptInstance_t inst, unsigned short id);
	void Scr_GetVector(game::scriptInstance_t inst, unsigned int arg_index, float* value);
	void Scr_AddVector(game::scriptInstance_t inst, float* value);
	void Scr_AddUndefined(game::scriptInstance_t inst);
	gentity_s* Scr_GetEntity(unsigned int arg_index);
	void Scr_AddEntity(game::scriptInstance_t inst, gentity_s* ent);
	__inline void* Scr_GetEntityId() { return CALL_ADDR(0x0, 0x692520); }
	unsigned int Scr_GetEntityId(scriptInstance_t inst, unsigned int entnum, classNum_e classnum, unsigned int clientnum, void* call_addr = Scr_GetEntityId());
	void Scr_AddEntityNum(scriptInstance_t inst, unsigned int entid);
	pathnode_t* Scr_GetPathnode(scriptInstance_t inst);
	void Scr_AddPathnode(scriptInstance_t inst, pathnode_t* node);
	void Scr_AddHudElem(game_hudelem_s* hud);
	void Scr_AddObject(scriptInstance_t inst, int entid);
	void Scr_MakeArray(scriptInstance_t inst);
	void Scr_AddArrayStringIndexed(scriptInstance_t inst, unsigned short id);
	unsigned short Scr_ExecThread(scriptInstance_t inst, int handle, int paramCount);
	unsigned short Scr_ExecEntThread(scriptInstance_t inst, int entNum, int handle, int numParams, int entClass);
	__inline void* Scr_NotifyNum() { return CALL_ADDR(0x0, 0x698CC0); }
	void Scr_NotifyNum(scriptInstance_t inst, int entNum, int entClass, unsigned int notifStr, int numParams, void* call_addr = Scr_NotifyNum());

	unsigned int Scr_GetNumParam(scriptInstance_t inst);
	VariableType Scr_GetType(scriptInstance_t inst, unsigned int index);
	void Scr_Error(const char* err, scriptInstance_t inst, bool is_terminal);
	const char* SL_ConvertToString(scriptInstance_t inst, int id);

	int Path_FindPath(path_t* pPath, team_t eTeam, float* vStartPos, float* vGoalPos, int bAllowNegotiationLinks);
	pathnode_t* Path_NearestNodeNotCrossPlanes(int typeFlags, int maxNodes, float* vOrigin, pathsort_t* nodes, float fMaxDist, float a6, float a7, int iPlaneCount, int* returnCount, nearestNodeHeightCheck heightCheck);
	int Path_FindPathFromTo(float* startPos, pathnode_t* pNodeTo, path_t* pPath, team_t eTeam, pathnode_t* pNodeFrom, float* vGoalPos, int bAllowNegotiationLinks, int bIgnoreBadplaces);
	int Path_GeneratePath(path_t* pPath, team_t eTeam, const float* vStartPos, float* vGoalPos, pathnode_t* pNodeFrom, pathnode_t* pNodeTo, int bIncludeGoalPos, int bAllowNegotiationLinks);
	void Path_UpdateLookahead(path_t* pPath, const float* vStartPos, int bReduceLookaheadAmount, int a4, int bAllowBacktrack);
	void Path_AddTrimmedAmount(const float* a1, path_t* a2);
	void Path_TransferLookahead(path_t* a1, const float* a2);
	pathnode_t* Path_ConvertIndexToNode(int index);
	unsigned int __cdecl Path_ConvertNodeToIndex(const game::pathnode_t* node);
	pathnode_t* Path_GetNegotiationNode(const path_t* pPath);
	void Path_IncrementNodeUserCount(path_t* pPath);
	void Path_DecrementNodeUserCount(path_t* pPath);
	void Path_Clear(path_t* pPath);
	float Vec2Length(const float* v);
	float Path_GetPathDir(float* delta, const float* vFrom, const float* vTo);
	float Vec3DistanceSq(const float* p1, const float* p2);
	float EvaluateHeuristic(CustomSearchInfo_FindPath* searchInfo, pathnode_t* pSuccessor, const float* vGoalPos);

	void Sentient_GetVelocity(sentient_s* self, float* vVelOut);

	template <typename T>
	class symbol
	{
	public:
		symbol(const size_t t4mp, const size_t t4sp)
			: t4mp_(reinterpret_cast<T*>(t4mp))
			, t4sp_(reinterpret_cast<T*>(t4sp))
		{
		}

		T* get() const
		{
			if (environment::t4mp())
			{
				return t4mp_;
			}

			return t4sp_;
		}

		void set(const size_t ptr)
		{
			this->t4mp_ = reinterpret_cast<T*>(ptr);
			this->t4sp_ = reinterpret_cast<T*>(ptr);
		}

		operator T* () const
		{
			return this->get();
		}

		T* operator->() const
		{
			return this->get();
		}

	private:
		T* t4mp_;
		T* t4sp_;
	};
}

#include "symbols.hpp"