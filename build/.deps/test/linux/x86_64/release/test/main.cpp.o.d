{
    depfiles = "main.o: test/main.cpp test/../includes/SmartTgBotPP.hpp  test/../includes/watcher.hpp test/../includes/bot.hpp  test/../includes/API.hpp test/../includes/update.hpp  test/../includes/message.hpp test/../includes/chat.hpp  test/../includes/user.hpp test/../includes/timer.hpp\
",
    depfiles_format = "gcc",
    files = {
        "test/main.cpp"
    },
    values = {
        "/usr/bin/gcc",
        {
            "-m64",
            "-fvisibility=hidden",
            "-fvisibility-inlines-hidden",
            "-O3",
            "-std=c++17",
            "-Ibuild/.gens/test/linux/x86_64/release/platform/windows/idl",
            "-Ibuild/.gens/SmartTgBotPP/linux/x86_64/release/platform/windows/idl",
            "-DNDEBUG"
        }
    }
}