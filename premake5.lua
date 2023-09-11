dependencies = {
	basePath = "./deps"
}

function dependencies.load()
	dir = path.join(dependencies.basePath, "premake/*.lua")
	deps = os.matchfiles(dir)

	for i, dep in pairs(deps) do
		dep = dep:gsub(".lua", "")
		require(dep)
	end
end

function dependencies.imports()
	for i, proj in pairs(dependencies) do
		if type(i) == 'number' then
			proj.import()
		end
	end
end

function dependencies.projects()
	for i, proj in pairs(dependencies) do
		if type(i) == 'number' then
			proj.project()
		end
	end
end

dependencies.load()

workspace "t4sp-server-plugin"
	location "./build"
	objdir "%{wks.location}/obj/%{cfg.buildcfg}"
	targetdir "%{wks.location}/bin/%{cfg.buildcfg}"
	targetname "%{prj.name}"

	configurations { "Debug", "Release", }

	language "C++"
	cppdialect "C++20"

	architecture "x86"

	systemversion "latest"
	symbols "On"
	staticruntime "On"
	editandcontinue "Off"
	warnings "Extra"
	characterset "ASCII"

	defines { "_CRT_SECURE_NO_WARNINGS" }

	flags
	{
		"NoIncrementalLink",
		"MultiProcessorCompile",
	}
	
	filter "configurations:Release"
		optimize "Full"
		defines { "NDEBUG" }
		flags {
			"FatalCompileWarnings",
		}
	filter {}

	filter "configurations:Debug"
		optimize "Debug"
		defines { "DEBUG", "_DEBUG" }
	filter {}

	startproject "t4sp-server-plugin"

	project "t4sp-server-plugin"
		kind "SharedLib"
		language "C++"

		files 
		{
			"./src/**.h",
			"./src/**.hpp",
			"./src/**.cpp",
			"./src/**.c",
			"./src/**.asm"
		}

		includedirs 
		{
			"%{prj.location}/src",
			"./src",
		}

		resincludedirs 
		{
			"$(ProjectDir)src"
		}
	
		pchheader "stdinc.hpp"
		pchsource "src/stdinc.cpp"
		buildoptions { "/Zm100 -Zm100" }

		dependencies.imports()

		if _OPTIONS["copy-to"] then
			postbuildcommands {"copy /y \"$(TargetPath)\" \"" .. _OPTIONS["copy-to"] .. "\""}
		else
			filter "configurations:Release"
				postbuildcommands {
					"if \"%COMPUTERNAME%\" == \"NEW-BUILT\" ( copy /y \"$(TargetPath)\" \"$(CODWAW_PATH)\\t4\\plugins\\\" )"
				}
			filter {}
			
			filter "configurations:Debug"
				postbuildcommands {
					"if \"%COMPUTERNAME%\" == \"NEW-BUILT\" ( copy /y \"$(TargetPath)\" \"$(CODWAW_PATH)\\t4staging\\plugins\\\" )"
				}
			filter {}
		end

	group "Dependencies"
	dependencies.projects()