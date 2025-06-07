#include "../includes/SmartTgBotPP.hpp"
#include "../includes/nlohmann/json.hpp"
#include "../includes/user.hpp"

#include <cstdlib>
#include <iostream>
#include <memory.h>

using namespace std;

int main(void)
{
    std::ios::sync_with_stdio(false);

    SmartTgBotPP::bot bot("7637934556:AAFpOp4QsCPb4GLRP3COVZdL7NTmCb9vu-U");
    SmartTgBotPP::watcher watcher(bot);
    SmartTgBotPP::message message;

    message.SetText("siski");

    while (watcher.watch())
    {
	    bot.SendMessage("7118418038", message);
	    cout << bot.GetUpdate().second.GetUpdateID() << endl;
    }

    return EXIT_SUCCESS;
}
