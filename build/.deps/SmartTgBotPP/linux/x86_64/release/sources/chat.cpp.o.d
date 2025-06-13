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
    depfiles_format = "gcc",
    depfiles = "chat.o: sources/chat.cpp sources/../includes/chat.hpp\
",
    files = {
        "sources/chat.cpp"
    }
}