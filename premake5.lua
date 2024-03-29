


workspace "ThunderSHIEngine"

	architecture "x64"


	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "ThunderSHIEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "ThunderSHIEngine/vendor/Glad/include"

include "ThunderSHIEngine/vendor/GLFW"
include "ThunderSHIEngine/vendor/Glad"

project "ThunderSHIEngine"
	location "ThunderSHIEngine"
	kind "SharedLib"
	language "c++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "tepch.h"
	pchsource "ThunderSHIEngine/src/tepch.cpp"

	files
	{
	"%{prj.name}/src/**.h",
	"%{prj.name}/src/**.cpp"

	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}
	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}
	filter "system:windows"
		cppdialect"c++17"
		staticruntime "on"
		systemversion "latest"
		defines
		{
			"TE_PLATFORM_WINDOWS",
			"TE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
	}

	filter "configurations:Debug"
		defines "TE_DEBUG"
		buildoptions "/MDd"
		symbols "ON"	
		
	filter "configurations:Rlease"
		defines "TE_RELEASE"
		buildoptions "/MDd"
		optimize "ON"	
		
	filter "configurations:Dist"
		defines "TE_DIST"
		buildoptions "/MDd"
		optimize "ON"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "c++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")
	files
	{
	"%{prj.name}/src/**.h",
	"%{prj.name}/src/**.cpp"

	}

	includedirs
	{
		"ThunderSHIEngine/vendor/spdlog/include",
		"ThunderSHIEngine/src"
	}

	links
	{
		"ThunderSHIEngine"
	}

	filter "system:windows"
		cppdialect"c++17"
		staticruntime "on"
		systemversion "latest"
		defines
		{
			"TE_PLATFORM_WINDOWS",
		}


	filter "configurations:Debug"
		defines "TE_DEBUG"
		buildoptions "/MDd"
		symbols "ON"	
		
	filter "configurations:Rlease"
		defines "TE_RELEASE"
		buildoptions "/MDd"
		optimize "ON"	
		
	filter "configurations:Dist"
		defines "TE_DIST"
		buildoptions "/MDd"
		optimize "ON"