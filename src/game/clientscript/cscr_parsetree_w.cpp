#include <stdinc.hpp>
#include "codsrc/clientscript/cscr_parsetree.hpp"

namespace game
{
	sval_u* Scr_AllocNode(scriptInstance_t inst, int size)
	{
		return codsrc::Scr_AllocNode(inst, size);
	}
}