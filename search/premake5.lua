location_dir = "../../build/search/"

include(location_dir .. "conanbuildinfo.premake.lua")

workspace("search")
	location(location_dir)
	conan_basic_setup()

	project("search")
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		targetdir = location_dir .. "bin/%{cfg.buildcfg}"

		files{
			"src/**",
		}

		includedirs{
			"src",
		}

		defines{"_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS"}

		filter "configurations:Debug"
			defines { "DEBUG" }
			symbols "On"

		filter "configurations:Release"
			defines { "NDEBUG" }
			optimize "On"