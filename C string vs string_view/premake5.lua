newoption {
	trigger		= "name",
	value		= "string",
	description	= "Name to be used for the workspace and project",
	default		= "CeleroTemplate",
}

newoption {
	trigger		= "celero-include",
	value		= "path",
	description	= "Celero include path",
}

newoption {
	trigger		= "celero-lib",
	value		= "path",
	description	= "Celero release library path",
}

newoption {
	trigger		= "celero-lib-d",
	value		= "path",
	description	= "Celero debug library path",
}


workspace(_OPTIONS["name"])
	configurations { "Debug", "Release" }
	
project(_OPTIONS["name"])
	kind "ConsoleApp"
	language "C++"
	targetdir "bin/%{cfg.buildcfg}"

	files { "**.h", "**.cpp" }

	defines { "_VARIADIC_MAX=10", "CELERO_STATIC", "_MBCS" }
	if os.is("windows") then
		defines{"WIN32", "_WINDOWS"}
		links{"PowrProf.lib"}
	end
	includedirs{_OPTIONS["celero-include"]}

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"
		links{_OPTIONS["celero-lib-d"]}

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"
		links{_OPTIONS["celero-lib"]}