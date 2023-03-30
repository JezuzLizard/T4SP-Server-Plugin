#pragma once

#include <stdinc.hpp>

namespace gsc
{
	namespace
	{

	}

	namespace function
	{
		void add(const std::string& name, const game::BuiltinFunction function);
	}

	namespace method
	{
		void add(const std::string& name, const game::BuiltinMethod method);
	}
}