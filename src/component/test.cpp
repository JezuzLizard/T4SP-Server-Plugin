#include <stdinc.hpp>
#include "loader/component_loader.hpp"

#include <utils/hook.hpp>
#include "gsc.hpp"

namespace test
{
	namespace
	{
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			gsc::function::add("testfunc", []()
			{
				game::Com_Printf(game::CON_CHANNEL_DONT_FILTER, "this is a test builtin\n");
			});

			gsc::method::add("testmeth", [](game::scr_entref_t ref)
			{
				game::Com_Printf(game::CON_CHANNEL_DONT_FILTER, "this is a test builtin on ent %d\n", ref.entnum);
			});
		}

	private:
	};
}

REGISTER_COMPONENT(test::component)
