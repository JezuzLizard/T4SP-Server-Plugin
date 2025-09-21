#include <stdinc.hpp>

namespace game
{
	void TempMemorySetPos(char* pos)
	{
		(*game::g_user)->pos = (int)pos;
	}

	void TempMemoryReset(HunkUser* user)
	{
		*game::g_user = user;
	}

	char* TempMalloc(int len)
	{
		return (char*)game::Hunk_UserAlloc(*game::g_user, len, 1);
	}
}