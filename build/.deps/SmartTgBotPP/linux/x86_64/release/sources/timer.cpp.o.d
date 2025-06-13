{
    values = {
        "/usr/bin/gcc",
        {
            "-m64",
            "-fvisibility=hidden",
            "-fvisibility-inlines-hidden",
            "-O3",
            "-std=c++17",
            "-Ibuild/.gens/SmartTgBotPP/linux/x86_64/release/platform/windows/idl",
            "-DNDEBUG"
        }
    },
    files = {
        "sources/timer.cpp"
    },
    depfiles = "timer.o: sources/timer.cpp sources/../includes/timer.hpp\
",
    depfiles_format = "gcc"
}