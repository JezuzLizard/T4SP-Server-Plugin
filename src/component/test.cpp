#include <stdinc.hpp>
#include "loader/component_loader.hpp"

#include "scheduler.hpp"
#include "gsc.hpp"

#include <utils/io.hpp>
#include <utils/hook.hpp>
#include <utils/string.hpp>
#include <utils/http.hpp>
#include <json.hpp>
#include <parser.hpp>

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
			//Disable AI print spam
			utils::hook::nop(0x4BAB7D, 5);
			utils::hook::nop(0x4BAAFA, 5);

			//Disable asset loading print spam
			utils::hook::nop(0x48D9D9, 5);

			//Disable unknown dvar spam
			utils::hook::nop(0x5F04AF, 5);

			if (utils::io::file_exists("some_file.csv"))
			{
				std::ifstream f("some_file.csv");
				aria::csv::CsvParser parser(f);
				for (auto& row : parser)
				{
					for (auto& field : row)
					{
						printf("%s", std::format("{} | ", field).c_str());
					}

					printf("\n");
				}
			}
		}

	private:
	};
}

REGISTER_COMPONENT(test::component)
