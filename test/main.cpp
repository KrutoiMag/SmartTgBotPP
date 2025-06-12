#include "../includes/SmartTgBotPP.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <memory>

using namespace std;

int main(void)
{
    std::ios::sync_with_stdio(false);

    try
    {
        SmartTgBotPP::bot bot("7637934556:AAFpOp4QsCPb4GLRP3COVZdL7NTmCb9vu-U");
        SmartTgBotPP::watcher watcher(bot);
        SmartTgBotPP::message message;

        message.SetText("Hi!");

        watcher.SetTimeout(1);

        // SmartTgBotPP::timer timer;
        //
        // timer.start();
        //
        // while (true)
        // {
        //     cout << timer.get() << endl;
        // }

        while (watcher.watch())
        {
            cout << bot.GetUpdates().size() << endl;
            for (auto &i : bot.GetUpdates())
            {
                cout << i.GetMessage().GetText() << endl;
                // bot.SendMessage(std::to_string(bot.GetUpdate()->GetMessage().GetChat().GetID()), message);
            }
        }
    }
    catch (exception &ex)
    {
        cout << ex.what();
    }

    return EXIT_SUCCESS;
}
