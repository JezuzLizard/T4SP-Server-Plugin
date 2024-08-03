#include <stdinc.hpp>

#include "scheduler.hpp"

namespace scheduler
{
	void on_scr_execute(const std::function<void()>& callback)
	{
		plugin::get()->get_interface()->callbacks()->on_scripts_execute((plutonium::sdk::v1::interfaces::callbacks::on_scripts_execute_callback)&callback);
	}
}
