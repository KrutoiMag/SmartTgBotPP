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
    depfiles = "watcher.o: sources/watcher.cpp sources/../includes/nlohmann/json.hpp  sources/../includes/watcher.hpp sources/../includes/bot.hpp  sources/../includes/API.hpp sources/../includes/update.hpp  sources/../includes/message.hpp sources/../includes/chat.hpp  sources/../includes/user.hpp sources/../includes/timer.hpp\
",
    depfiles_format = "gcc",
    files = {
        "sources/watcher.cpp"
    }
}