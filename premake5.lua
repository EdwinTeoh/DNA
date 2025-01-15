workspace "DNA"
	architecture "x64"
    startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "DNA"
	location "DNA"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.anme}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DNA_WINDOWS",
			"DNA_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HZ_DIST"
		symbols "On"

	filter { "system:windows", "configurations:Debug", "configurations:Release"}
		buildoptions "/utf-8"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.anme}/src/**.cpp"
	}

	includedirs
	{
		"DNA/vendor/spdlog/include",
		"DNA/src"
	}

	links
	{
		"DNA"
	}
    
    postbuildcommands
    {
        "{COPY} ../bin/" .. outputdir .. "/DNA/DNA.dll ../bin/" .. outputdir .. "/Sandbox"
    }

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DNA_WINDOWS",
		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HZ_DIST"
		symbols "On"

	filter { "system:windows", "configurations:Debug", "configurations:Release"}
		buildoptions "/utf-8"