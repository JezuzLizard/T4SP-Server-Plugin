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

	int Scr_GetInt(game::scriptInstance_t inst, unsigned int arg_index); //testing
	void Scr_AddInt(game::scriptInstance_t inst, int value); //testing
	float Scr_GetFloat(game::scriptInstance_t inst, unsigned int arg_index); //testing
	void Scr_AddFloat(game::scriptInstance_t inst, float value); //testing
	char* Scr_GetString(game::scriptInstance_t inst, unsigned int arg_index); //testing
	void Scr_AddString(game::scriptInstance_t inst, const char* string); //testing
	const char* Scr_GetIString(game::scriptInstance_t inst, unsigned int arg_index); //testing
	void Scr_AddIString(game::scriptInstance_t inst, const char* string); //testing
	unsigned short Scr_GetConstString(game::scriptInstance_t inst, unsigned int arg_index); //testing
	void Scr_AddConstString(game::scriptInstance_t inst, unsigned short id); //testing
	void Scr_GetVector(game::scriptInstance_t inst, unsigned int arg_index, float* value); //testing
	void Scr_AddVector(game::scriptInstance_t inst, float* value); //testing
	void Scr_AddUndefined(game::scriptInstance_t inst); //testing
	gentity_s* Scr_GetEntity(unsigned int arg_index); //testing
	void Scr_AddEntity(game::scriptInstance_t inst, gentity_s* ent); //testing
	unsigned int Scr_GetEntityId(scriptInstance_t inst, int entNum, classNum_e classnum, unsigned int clientnum); //testing
	void Scr_AddEntityNum(scriptInstance_t inst, unsigned short entid); //testing
	pathnode_t* Scr_GetPathnode(scriptInstance_t inst); //testing
	void Scr_AddPathnode(scriptInstance_t inst, pathnode_t* node); //testing
	void Scr_MakeArray(scriptInstance_t inst); //testing
	void Scr_AddArrayStringIndexed(scriptInstance_t inst, unsigned short id); //testing
	const char* SL_ConvertToString(scriptInstance_t inst, int id); //testing

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