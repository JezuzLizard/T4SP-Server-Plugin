#pragma once

namespace gsc
{
	namespace function
	{
		void add(const std::string& name, const game::BuiltinFunction function);
		const std::unordered_map<std::string, game::BuiltinFunction>& get();
	}

	namespace method
	{
		void add(const std::string& name, const game::BuiltinMethod method);
		const std::unordered_map<std::string, game::BuiltinMethod>& get();
	}
}