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

	float Scr_GetFloat(game::scriptInstance_t inst, unsigned int arg_index)
	{
		static const auto call_addr = SELECT(0x0, 0x699E90);
		float answer;

		__asm
		{
			mov ecx, arg_index;
			mov eax, inst;
			call call_addr;
			mov answer, eax;
		}

		return answer;
	}

	char* Scr_GetString(game::scriptInstance_t inst, unsigned int arg_index)
	{
		static const auto call_addr = SELECT(0x0, 0x699F30);
		char* answer;

		__asm
		{
			mov ecx, arg_index;
			mov eax, inst;
			call call_addr;
			mov answer, eax;
		}

		return answer;
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
			mov cx, id;
			call call_addr;
		}
	}

	const char* SL_ConvertToString(scriptInstance_t inst, unsigned short id)
	{
		static const auto call_addr = SELECT(0x0, 0x699F30);
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

	namespace plutonium
	{
	}
}
