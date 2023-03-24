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