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
    depfiles = "update.o: sources/update.cpp sources/../includes/update.hpp  sources/../includes/message.hpp sources/../includes/chat.hpp  sources/../includes/user.hpp sources/../includes/API.hpp\
",
    files = {
        "sources/update.cpp"
    }
}