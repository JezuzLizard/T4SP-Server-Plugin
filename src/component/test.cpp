#include <stdinc.hpp>
#include "loader/component_loader.hpp"

#include <utils/hook.hpp>

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
		}

	private:
	};
}

REGISTER_COMPONENT(test::component)
