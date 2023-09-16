#pragma once

namespace gsc
{
	namespace function
	{
		void add(const std::string& name, const game::BuiltinFunction function);
		game::BuiltinFunction get(const char** name, int* type);
	}

	namespace method
	{
		void add(const std::string& name, const game::BuiltinMethod method);
		game::BuiltinMethod get(const char** name, int* type);
	}
}