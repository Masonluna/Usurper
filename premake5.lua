workspace "Usurper"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    IncludeDir = {}
    IncludeDir["Glad"] = "Usurper/vendor/Glad/include"
    IncludeDir["GLFW"] = "Usurper/vendor/GLFW/include"


    project "Usurper"
        location "Usurper"
        kind "ConsoleApp"
        language "C++"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir("bin-int/" .. outputdir .. "/%{prj.name}")

        files {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp",
            "%{prj.name}/vendor/Glad/src/glad.c"
        }

        includedirs {
            "%{prj.name}/src",
            "%{IncludeDir.GLFW}",
            "%{IncludeDir.Glad}"
        }

        libdirs {
            "%{prj.name}/vendor/GLFW/lib"
        }
        links {
            "glfw3.lib",
            "opengl32.lib"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "Off"
            systemversion "latest"

        filter "configurations:Debug"
            symbols "On"

        filter "configurations:Release"
            optimize "On"
