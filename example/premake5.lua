flags("MultiProcessorCompile")

workspace("examples")
        configurations({
                "Debug",
                "Release"
        })
        platforms({
                "Native",
                "Win32",
                "Win64"
        })
        defaultplatform("Native")

filter("platforms:Win32")
        system("windows")
        architecture("x86")
        gccprefix("i686-w64-mingw32-")

filter("platforms:Win64")
        system("windows")
        architecture("x86_64")
        gccprefix("x86_64-w64-mingw32-")

filter({})

include("..")

project("example1")
	flags("RelativeLinks")
	kind("ConsoleApp")
	language("C")
	targetdir("bin/%{cfg.buildcfg}/%{cfg.platform}")
	objdir("obj")
	files("src/example1.c")
	includedirs("../include")
	links("htmle")
