#pragma once

namespace game
{
	void TempMemorySetPos(char* pos);
	void TempMemoryReset(HunkUser* user);
	char* TempMalloc(int len);
}