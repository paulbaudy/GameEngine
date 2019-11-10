workspace "GameEngine"
    architecture "x64"

    configurations
    {
        "DebugGame",
        "Game",
        "DebugEditor"
    }

binFolderName = "Binaries/"
IntFolderName = "Intermediates/"
buildcgf = "%{cfg.buildcfg}"
system = "%{cfg.system}"
outputdir = buildcgf .. "_" .. system


project "GameEngine"
    location "GameEngine"
    kind "SharedLib"
    language "C++"

    targetdir (binFolderName .. outputdir .. "/%{prj.name}/")
    objdir (IntFolderName .. outputdir .. "/%{prj.name}/")

    files
    {
        "%{prj.name}" .. "/Source/**.h",
        "%{prj.name}" .. "/Source/**.cpp"
    }

    includedirs
    {
        "%{prj.name}" .. "/ThirdParties/spdlog/include",
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "GE_PLATFORM_WINDOWS",
            "GE_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../" ..  "GameProject")
        }

    filter "configurations:DebugGame"
        defines "GE_BUILD_DEBUG"
        symbols "On"

    filter "configurations:Game"
        defines "GE_BUILD_RELEASE"
        optimize "On"

project "GameProject"
    location "GameProject"
    kind "ConsoleApp"
    language "C++"

    targetdir (binFolderName .. outputdir ..  "/%{prj.name}/")
    objdir (IntFolderName .. outputdir ..  "/%{prj.name}/")

    files
    {
        "%{prj.name}" .. "/Source/**.h",
        "%{prj.name}" .. "/Source/**.cpp",
    }

    includedirs
    {
        "GameEngine/ThirdParties/spdlog/include",
        "GameEngine/Source"
    }

    links
    {
        "GameEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "GE_PLATFORM_WINDOWS"
        }

    filter "configurations:DebugGame"
        defines "GE_BUILD_DEBUG"
        symbols "On"

    filter "configurations:Game"
        defines "GE_BUILD_RELEASE"
        optimize "On"
