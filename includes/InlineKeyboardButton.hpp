#pragma once

#ifndef SMARTTGBOTPP_INLINEKEYBOARDBUTTON_HPP
#define SMARTTGBOTPP_INLINEKEYBOARDBUTTON_HPP

#include <string>

namespace SmartTgBotPP
{
    class InlineKeyboardButton
    {
        std::string text, URL, CallbackData, SwitchInlineQuery, SwitchInlineQueryCurrentChat;

        bool pay;

      public:
        explicit InlineKeyboardButton() = default;
        explicit InlineKeyboardButton(const InlineKeyboardButton &_InlineKeyboardButton);
        explicit InlineKeyboardButton(const std::string &text, const std::string &CallbackData,
                                      const std::string &SwitchInlineQuery = "",
                                      const std::string &SwitchInlineQueryCurrentChat = "", const bool &pay = false);

        const void SetText(const std::string &text), SetURL(const std::string &URL),
            SetCallbackData(const std::string &CallbackData),
            SetSwitchInlineQuery(const std::string &SwitchInlineQuery),
            SetSwitchInlineQueryCurrentChat(const std::string &SwitchInlineQueryCurrentChat), SetPay(const bool &pay);

        const std::string &GetText() const, &GetURL() const, &GetCallbackData() const, &GetSwitchInlineQuery() const,
            &GetSwitchInlineQueryCurrentChat() const;

        const bool &GetPay() const;
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_INLINEKEYBOARDBUTTON_HPP
