#include <stdinc.hpp>

#include "gsc.hpp"

namespace gsc
{
	namespace function
	{
		void add(const std::string& name, const game::BuiltinFunction function)
		{
			plugin::get()->get_interface()->gsc()->register_function(name, function);
		}
	}

	namespace method
	{
		void add(const std::string& name, const game::BuiltinMethod method)
		{
			plugin::get()->get_interface()->gsc()->register_method(name, (plutonium::sdk::v1::interfaces::gsc::method_callback)method);
		}
	}
}

