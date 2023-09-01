#include <stdinc.hpp>
#include "clientscript_public.hpp"

namespace codsrc
{
	// Restored
	char* TempMalloc(int len)
	{
		return (char *)game::Hunk_UserAlloc(*game::g_user, len, 1);
	}

	// Restored
	void TempMemoryReset(game::HunkUser* user)
	{
		*game::g_user = user;
	}

	// Restored
	void TempMemorySetPos(char* pos)
	{
		(*game::g_user)->pos = (int)pos;
	}
}