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
	int Scr_GetEntityId(int entNum, scriptInstance_t inst, classNum_e classnum, unsigned __int16 clientnum);
	pathnode_t* Scr_GetPathnode(scriptInstance_t inst);
	void Scr_AddPathnode(scriptInstance_t inst, pathnode_t* node);
	void Scr_MakeArray(scriptInstance_t inst);
	void Scr_AddArrayStringIndexed(scriptInstance_t inst, unsigned short id);
	const char* SL_ConvertToString(scriptInstance_t inst, unsigned short id);

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