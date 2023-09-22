SQLiteCpp = {
	source = path.join(dependencies.basePath, "SQLiteCpp"),
}

function SQLiteCpp.import()
	links { "SQLiteCpp" }
	SQLiteCpp.includes()
end

function SQLiteCpp.includes()
	includedirs {
		path.join(SQLiteCpp.source, "include"),
		path.join(SQLiteCpp.source, "sqlite3")
	}
end

function SQLiteCpp.project()
	project "SQLiteCpp"
		language "C"

		SQLiteCpp.includes()

		files {
			path.join(path.join(SQLiteCpp.source, "src"), "**.cpp"),
			path.join(path.join(SQLiteCpp.source, "include"), "**.h"),
			path.join(path.join(SQLiteCpp.source, "sqlite3"), "**.c"),
			path.join(path.join(SQLiteCpp.source, "sqlite3"), "**.h")
		}

		warnings "Off"
		kind "StaticLib"
end

table.insert(dependencies, SQLiteCpp)
