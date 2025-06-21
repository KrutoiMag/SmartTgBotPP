#include "../includes/InlineKeyboardButton.hpp"

SmartTgBotPP::InlineKeyboardButton::InlineKeyboardButton(const InlineKeyboardButton &_InlineKeyboardButton)
{
    text = _InlineKeyboardButton.text;
    URL = _InlineKeyboardButton.URL;
    CallbackData = _InlineKeyboardButton.CallbackData;
    SwitchInlineQuery = _InlineKeyboardButton.SwitchInlineQuery;
    SwitchInlineQueryCurrentChat = _InlineKeyboardButton.SwitchInlineQueryCurrentChat;
}

SmartTgBotPP::InlineKeyboardButton::InlineKeyboardButton(const std::string &text, const std::string &CallbackData,
                                                         const std::string &SwitchInlineQuery,
                                                         const std::string &SwitchInlineQueryCurrentChat,
                                                         const bool &pay)
{
    this->text = text;
    this->CallbackData = CallbackData;
    this->SwitchInlineQuery = SwitchInlineQuery;
    this->SwitchInlineQueryCurrentChat = SwitchInlineQueryCurrentChat;
    this->pay = pay;
}

const void SmartTgBotPP::InlineKeyboardButton::SetText(const std::string &text)
{
    this->text = text;
}

const void SmartTgBotPP::InlineKeyboardButton::SetURL(const std::string &URL)
{
    this->URL = URL;
}

const void SmartTgBotPP::InlineKeyboardButton::SetCallbackData(const std::string &CallbackData)
{
    this->CallbackData = CallbackData;
}

const void SmartTgBotPP::InlineKeyboardButton::SetSwitchInlineQuery(const std::string &SwitchInlineQuery)
{
    this->SwitchInlineQuery = SwitchInlineQuery;
}

const void SmartTgBotPP::InlineKeyboardButton::SetSwitchInlineQueryCurrentChat(
    const std::string &SwitchInlineQueryCurrentChat)
{
    this->SwitchInlineQueryCurrentChat = SwitchInlineQueryCurrentChat;
}

const void SmartTgBotPP::InlineKeyboardButton::SetPay(const bool &pay)
{
    this->pay = pay;
}

const std::string &SmartTgBotPP::InlineKeyboardButton::GetText() const
{
    return text;
}

const std::string &SmartTgBotPP::InlineKeyboardButton::GetURL() const
{
    return URL;
}

const std::string &SmartTgBotPP::InlineKeyboardButton::GetCallbackData() const
{
    return CallbackData;
}

const std::string &SmartTgBotPP::InlineKeyboardButton::GetSwitchInlineQuery() const
{
    return SwitchInlineQuery;
}

const std::string &SmartTgBotPP::InlineKeyboardButton::GetSwitchInlineQueryCurrentChat() const
{
    return SwitchInlineQueryCurrentChat;
}

const bool &SmartTgBotPP::InlineKeyboardButton::GetPay() const
{
    return pay;
}
