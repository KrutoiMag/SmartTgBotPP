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
    depfiles = "ChatFullInfo.o: sources/ChatFullInfo.cpp  sources/../includes/ChatFullInfo.hpp sources/../includes/chat.hpp\
",
    files = {
        "sources/ChatFullInfo.cpp"
    }
}