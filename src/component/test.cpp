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
#include <SQLiteCpp/Database.h>

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

			{
				SQLite::Database db("test.db3", SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
				db.exec("CREATE TABLE test (id INTEGER PRIMARY KEY, value TEXT, weight INTEGER)");

				db.exec("INSERT INTO test VALUES (NULL, \"first\",  3)");
				db.exec("INSERT INTO test VALUES (NULL, \"second\", 5)");
				db.exec("INSERT INTO test VALUES (NULL, \"third\",  7)");

				printf("%s %s %d\n", db.execAndGet("SELECT value FROM test WHERE id=2").getString().c_str(), db.execAndGet("SELECT value FROM test WHERE weight=7").getString().c_str(), db.execAndGet("SELECT weight FROM test WHERE value=\"first\"").getInt());
			}
		}

	private:
	};
}

REGISTER_COMPONENT(test::component)
