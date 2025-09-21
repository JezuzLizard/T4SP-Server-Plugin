#include <stdinc.hpp>

namespace game
{
	sval_u* Scr_AllocNode(scriptInstance_t inst, int size)
	{
		assert(game::g_allocNodeUser[inst]);

		return (game::sval_u*)game::Hunk_UserAlloc(game::g_allocNodeUser[inst], 4 * size, 4);
	}
}