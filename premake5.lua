


workspace "ThunderSHIEngine"

	architecture "x64"


	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ThunderSHIEngine"
	location "ThunderSHIEngine"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include";
	}

	filter "system:windows"
		cppdialect"c++17"
		staticruntime "on"
		systemversion "10.0"
		defines
		{
			"TE_PLATFORM_WINDOWS",
			"TE_BUILD_DLL"
		}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
	}

	filter "configurations:Debug"
		defines "TE_DEBUG"
		symbols "ON"	
		
	filter "configurations:Rlease"
		defines "TE_RELEASE"
		optimize "ON"	
		
	filter "configurations:Dist"
		defines "TE_DIST"
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
		"ThunderSHIEngine/vendor/spdlog/include";
		"ThunderSHIEngine/src";
	}

	links
	{
		"ThunderSHIEngine"
	}

	filter "system:windows"
		cppdialect"c++17"
		staticruntime "on"
		systemversion "10.0"
		defines
		{
			"TE_PLATFORM_WINDOWS",
		}


	filter "configurations:Debug"
		defines "TE_DEBUG"
		symbols "ON"	
		
	filter "configurations:Rlease"
		defines "TE_RELEASE"
		optimize "ON"	
		
	filter "configurations:Dist"
		defines "TE_DIST"
		optimize "ON"