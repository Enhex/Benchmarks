newoption {
	trigger     = "location",
	value       = "./",
	description = "Where to generate the project.",
}

if not _OPTIONS["location"] then
	_OPTIONS["location"] = "./"
end

location_dir = _OPTIONS["location"]

include(location_dir .. "conanbuildinfo.premake.lua")

project_name = "linear-algebra-libs"

workspace(project_name)
	location(location_dir)
	conan_basic_setup()

	project(project_name)
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++20"
		targetdir = location_dir .. "bin/%{cfg.buildcfg}"

		files{
			"src/**",
		}

		includedirs{
			"src",
		}

		defines{"_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS"}

		vectorextensions "AVX2"

		filter "configurations:Debug"
			defines { "DEBUG" }
			symbols "On"

		filter "configurations:Release"
			defines { "NDEBUG" }
			optimize "On"