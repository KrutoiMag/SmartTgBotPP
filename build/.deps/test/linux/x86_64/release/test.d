{
    files = {
        "build/.objs/test/linux/x86_64/release/test/main.cpp.o",
        "build/linux/x86_64/release/libSmartTgBotPP.a"
    },
    values = {
        "/usr/bin/g++",
        {
            "-m64",
            "-Lbuild/linux/x86_64/release",
            "-s",
            "-lSmartTgBotPP",
            "-lcurl"
        }
    }
}