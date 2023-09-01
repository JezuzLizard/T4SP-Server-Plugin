#pragma once

namespace codsrc
{
	char* TempMalloc(int len);
	void TempMemoryReset(game::HunkUser* user);
	void TempMemorySetPos(char* pos);
}
