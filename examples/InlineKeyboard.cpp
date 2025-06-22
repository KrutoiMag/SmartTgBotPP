#include "../includes/SmartTgBotPP.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);

    try
    {
        if (argc != 2)
        {
            throw std::runtime_error("No bot token provided!");
        }

        auto bot = std::make_unique<SmartTgBotPP::bot>(argv[1]);
        auto watcher = std::make_unique<SmartTgBotPP::watcher>(*bot);

        std::unique_ptr<SmartTgBotPP::InlineKeyboardButton> InlineKeyboardButtons[3][3];

        for (short i = 0; i < 3; i++)
        {
            for (short j = 0; j < 3; j++)
            {
                InlineKeyboardButtons[i][j] =
                    std::make_unique<SmartTgBotPP::InlineKeyboardButton>("btn", "opt" + std::to_string(i + j));
            }
        }

        auto InlineKeyboardMarkup = std::make_unique<SmartTgBotPP::InlineKeyboardMarkup>();

        for (short i = 0; i < 3; i++)
        {
            InlineKeyboardMarkup->InsertRow();
            for (short j = 0; j < 3; j++)
            {
                InlineKeyboardMarkup->InsertButtonInRow(i, *InlineKeyboardButtons[i][j]);
            }
        }

        while (watcher->watch())
        {
            string t = bot->GetUpdate().GetMessage().GetText();
	    cout << true << endl;
            if (!t.empty())
            {
                bot->SendMessage(bot->GetUpdate().GetMessage().GetChat().GetID(), SmartTgBotPP::message(t),
                                 *InlineKeyboardMarkup);
            }
        }
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

    return EXIT_SUCCESS;
}
