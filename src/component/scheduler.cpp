#include <stdinc.hpp>

#include "scheduler.hpp"

namespace scheduler
{
	void on_scr_execute(void(*callback)())
	{
		plugin::get()->get_interface()->callbacks()->on_scripts_execute(callback);
	}
}
