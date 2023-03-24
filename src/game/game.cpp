#include <stdinc.hpp>
#include "game.hpp"

#include <utils/hook.hpp>
#include <utils/memory.hpp>

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

	namespace plutonium
	{
	}
}
