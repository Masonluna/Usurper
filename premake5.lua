workspace "Usurper"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    IncludeDir = {}
    IncludeDir["Glad"]   = "Usurper/vendor/Glad/include"
    IncludeDir["GLFW"]   = "Usurper/vendor/GLFW/include"
    IncludeDir["glm"]    = "Usurper/vendor/glm/glm-1.0.1"
    IncludeDir["spdlog"] = "Usurper/vendor/spdlog/include"

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
            "%{prj.name}/src/Core",
            "%{prj.name}/src/Graphics/Render",
            "%{prj.name}/src/Graphics",
            "%{IncludeDir.GLFW}",
            "%{IncludeDir.Glad}",
            "%{IncludeDir.glm}",
            "%{IncludeDir.spdlog}"
        }

        libdirs {
            "%{prj.name}/vendor/GLFW/lib",
            "%{prj.name}/vendor/spdlog/lib"
        }
        links {
            "glfw3.lib",
            "opengl32.lib",
            "spdlog.lib"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "Off"
            systemversion "latest"

        filter "configurations:Debug"
            symbols "On"

        filter "configurations:Release"
            optimize "On"

        filter "action:vs*"
            buildoptions { "/utf-8" }
