#include <stdinc.hpp>
#include "codsrc/clientscript/cscr_tempmemory.hpp"

namespace game
{
	void TempMemorySetPos(char* pos)
	{
		codsrc::TempMemorySetPos(pos);
	}

	void TempMemoryReset(HunkUser* user)
	{
		codsrc::TempMemoryReset(user);
	}

	char* TempMalloc(int len)
	{
		return codsrc::TempMalloc(len);
	}
}