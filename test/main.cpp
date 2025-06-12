#include "../includes/ChatFullInfo.hpp"
#include "../includes/SmartTgBotPP.hpp"
#include "../includes/nlohmann/json.hpp"
#include "../includes/user.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <memory.h>

using namespace std;

int main(void)
{
    std::ios::sync_with_stdio(false);

    try
    {
        SmartTgBotPP::bot bot("ENTER YOUR BOT TOKEN HERE!");
        SmartTgBotPP::watcher watcher(bot);
        SmartTgBotPP::message message;

        message.SetText("Hi!");

        while (watcher.watch())
        {
            cout << bot.GetUpdate()->GetMessage().GetChat().GetID() << endl;
            bot.SendMessage(std::to_string(bot.GetUpdate()->GetMessage().GetChat().GetID()), message);
        }
    }
    catch (exception &ex)
    {
        cout << ex.what();
    }

    return EXIT_SUCCESS;
}
