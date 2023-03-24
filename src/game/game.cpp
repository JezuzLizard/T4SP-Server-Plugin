#include <stdinc.hpp>
#include "game.hpp"

#include <utils/hook.hpp>

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

	namespace plutonium
	{
		bool is_up_to_date()
		{
			return true;
		}
	}
}
