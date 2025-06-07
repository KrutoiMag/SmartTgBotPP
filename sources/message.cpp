#include "../includes/message.hpp"

SmartTgBotPP::message &SmartTgBotPP::message::operator=(const message &_message)
{
    if (this == &_message)
        return *this;

    ID = _message.ID;
    ThreadID = _message.ThreadID;
    _user = _message._user;

    return *this;
}

const void SmartTgBotPP::message::SetText(const std::string &text)
{
    this->text = text;
}

const int &SmartTgBotPP::message::GetID(void) const
{
    return ID;
}

const std::string &SmartTgBotPP::message::GetText(void) const
{
    return text;
}
