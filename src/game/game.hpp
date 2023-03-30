#pragma once

#include "structs.hpp"

#define SELECT(mp, sp) (game::environment::t4mp() ? mp : sp)

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
	unsigned int Scr_GetEntityId(scriptInstance_t inst, int entNum, classNum_e classnum, unsigned int clientnum);
	void Scr_AddEntityNum(scriptInstance_t inst, unsigned int entid);
	pathnode_t* Scr_GetPathnode(scriptInstance_t inst);
	void Scr_AddPathnode(scriptInstance_t inst, pathnode_t* node);
	void Scr_MakeArray(scriptInstance_t inst);
	void Scr_AddArrayStringIndexed(scriptInstance_t inst, unsigned short id);
	unsigned int Scr_GetNumParam(scriptInstance_t inst);
	VariableType Scr_GetType(scriptInstance_t inst, unsigned int index);
	void Scr_Error(const char* err, scriptInstance_t inst, bool is_terminal);
	const char* SL_ConvertToString(scriptInstance_t inst, int id);

	int Path_FindPath(path_t* pPath, team_t eTeam, float* vStartPos, float* vGoalPos, int bAllowNegotiationLinks);
	pathnode_t* Path_NearestNodeNotCrossPlanes(float maxDistSq, float maxHeightSq, float* vOrigin, pathsort_t* nodes, float a5, int a6, int a7, int a8, int* returnCount, int a10);
	int Path_FindPathFromTo(float* startPos, pathnode_t* pNodeTo, path_t* pPath, team_t eTeam, pathnode_t* pNodeFrom, float* vGoalPos, int bAllowNegotiationLinks, int bIgnoreBadplaces);

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