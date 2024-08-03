#pragma once

namespace gsc
{
	namespace function
	{
		void add(const std::string& name, const game::BuiltinFunction function);
	}

	namespace method
	{
		void add(const std::string& name, const game::BuiltinMethod method);
	}
}