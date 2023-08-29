#include <stdinc.hpp>

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

	namespace plutonium
	{
	}
}
