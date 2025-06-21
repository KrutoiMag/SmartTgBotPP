#include "../includes/InlineKeyboardMarkup.hpp"
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
        SmartTgBotPP::InlineKeyboardMarkup InlineKeyboardMarkup;
        std::vector<SmartTgBotPP::InlineKeyboardButton> InlineKeyboardButtons{
            SmartTgBotPP::InlineKeyboardButton("Text", "opt0"), SmartTgBotPP::InlineKeyboardButton("Text", "opt1")};

        InlineKeyboardMarkup.InsertRow();
        InlineKeyboardMarkup.InsertRow();

        for (const auto &i : InlineKeyboardButtons)
        {
            InlineKeyboardMarkup.InsertButtonInRow(0, i);
            InlineKeyboardMarkup.InsertButtonInRow(1, i);
        }

        InlineKeyboardMarkup.GetButtonFromRow(0, 0).value()->SetCallbackData("opt0");

        cout << InlineKeyboardMarkup.GetRowsCount() << endl;
        cout << InlineKeyboardMarkup.GetButtonFromRow(0, 0).value()->GetText() << endl;

        message.SetText("Hi!");

        watcher.SetTimeout(0);

        while (watcher.watch())
        {
            if (!bot.GetUpdate().GetMessage().GetText().empty())
            {
                cout << bot.GetUpdate().GetMessage().GetText() << endl;
                message.SetText("UpdateID: " + std::to_string(bot.GetUpdate().GetUpdateID()));
                bot.SendMessage(bot.GetUpdate().GetMessage().GetChat().GetID(), message,
                                std::make_optional<SmartTgBotPP::InlineKeyboardMarkup>(InlineKeyboardMarkup));
            }
        }
    }
    catch (exception &ex)
    {
        cout << ex.what();
    }

    return EXIT_SUCCESS;
}
