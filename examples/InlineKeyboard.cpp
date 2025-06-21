#include "../includes/SmartTgBotPP.hpp"

#include <cinttypes>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <optional>
#include <vector>

using namespace std;

using KEYBOARD_BUTTONS = std::vector<std::vector<std::optional<std::unique_ptr<SmartTgBotPP::InlineKeyboardButton>>>>;

const inline void InitInlineKeyboardButtons(KEYBOARD_BUTTONS &InlineKeyboardButtons)
{
    for (short i = 0; i < 3; i++)
    {
        InlineKeyboardButtons.emplace_back();
        for (short j = 0; j < 3; j++)
        {
            InlineKeyboardButtons.back().emplace_back(
                std::make_optional<std::unique_ptr<SmartTgBotPP::InlineKeyboardButton>>(
                    std::make_unique<SmartTgBotPP::InlineKeyboardButton>("Text", "opt" + std::to_string(i + j))));
        }
    }
}

const inline void InitInlineKeyboardMarkup(SmartTgBotPP::InlineKeyboardMarkup &InlineKeyboardMarkup,
                                           const KEYBOARD_BUTTONS &InlineKeyboardButtons)
{
    for (std::size_t i = 0; i < InlineKeyboardButtons.size(); i++)
    {
        InlineKeyboardMarkup.InsertRow();
        for (const auto &j : InlineKeyboardButtons[i])
        {
            if (j.has_value())
                InlineKeyboardMarkup.InsertButtonInRow(i, *(j.value()));
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);

    auto bot = std::make_unique<SmartTgBotPP::bot>(argv[1]);
    auto watcher = std::make_unique<SmartTgBotPP::watcher>(*bot);
    auto InlineKeyboardMarkup = std::make_unique<SmartTgBotPP::InlineKeyboardMarkup>();

    KEYBOARD_BUTTONS InlineKeyboardButtons;

    InitInlineKeyboardButtons(InlineKeyboardButtons);
    InitInlineKeyboardMarkup(*InlineKeyboardMarkup, InlineKeyboardButtons);

    while (watcher->watch())
    {
        const std::string &t = bot->GetUpdate().GetMessage().GetText();

        if (!t.empty())
        {
            bot->SendMessage(bot->GetUpdate().GetMessage().GetChat().GetID(), SmartTgBotPP::message(t),
                             std::make_optional<SmartTgBotPP::InlineKeyboardMarkup>(*InlineKeyboardMarkup));
        }
    }

    return EXIT_SUCCESS;
}
