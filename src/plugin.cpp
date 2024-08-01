#include <stdinc.hpp>
#include "component/signatures.hpp"

#include <utils/hook.hpp>
#include "loader/component_loader.hpp"

namespace plugin
{
	std::uint32_t plugin::plugin_version()
	{
		return 1;
	}

	const char* plugin::plugin_name()
	{
		return "t4sp-server-plugin";
	}

	bool plugin::is_game_supported(plutonium::sdk::game game)
	{
		return game == plutonium::sdk::game::t4;
	}

	void plugin::on_startup(plutonium::sdk::iinterface* interface_ptr, plutonium::sdk::game game)
	{
		this->interface_ = interface_ptr;
		this->game_ = game;

		if (!game::environment::t4sp())
		{
			MessageBoxA(nullptr, "Unsupported game executable. (t4sp is only supported)", "ERROR, BRO!", 0);
			return;
		}

		if (!signatures::process())
		{
			MessageBoxA(NULL,
				std::format("This version of t4sp-server-plugin is outdated.\n" \
					"Download the latest dll from here: https://github.com/JezuzLizard/T4SP-Server-Plugin/releases\n" \
					"'{}' failed", signatures::get_err_reason()).c_str(),
				"ERROR", MB_ICONERROR);

			return;
		}

		if (game::plutonium::printf.get() != nullptr)
		{
			utils::hook::jump(reinterpret_cast<uintptr_t>(&printf), game::plutonium::printf);
		}

		component_loader::post_unpack();
	}

	void plugin::on_shutdown()
	{
	}

	plutonium::sdk::iinterface* plugin::get_interface()
	{
		return this->interface_;
	}

	plutonium::sdk::game plugin::get_game()
	{
		return this->game_;
	}

	plugin* get()
	{
		static plugin instance;
		return &instance;
	}
}
