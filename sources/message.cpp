#include "../includes/message.hpp"

SmartTgBotPP::message::message(const message &_message)
{
    init(_message);
}

SmartTgBotPP::message &SmartTgBotPP::message::operator=(const message &_message)
{
    if (this == &_message)
        return *this;

    init(_message);

    return *this;
}

SmartTgBotPP::message::message(const std::string &text)
{
    this->text = text;
}

const void SmartTgBotPP::message::SetText(const std::string &text)
{
    this->text = text;
}

const void SmartTgBotPP::message::SetUser(const user &_user)
{
    this->_user = std::make_unique<user>(_user);
}

const void SmartTgBotPP::message::SetChat(const chat &_chat)
{
    this->_chat = std::make_shared<chat>(_chat);
}

const void SmartTgBotPP::message::SetPhoto(const std::vector<PhotoSize> &photo)
{
    this->photo = std::make_shared<std::vector<PhotoSize>>(photo);
}

const int &SmartTgBotPP::message::GetID(void) const
{
    return ID;
}

const std::string &SmartTgBotPP::message::GetText(void) const
{
    return text;
}

const SmartTgBotPP::chat &SmartTgBotPP::message::GetChat(void) const
{
    return *_chat;
}

const void SmartTgBotPP::message::init(const message &_message)
{
    ID = _message.ID;
    ThreadID = _message.ThreadID;
    if (_message._user)
        _user = std::make_unique<user>(*_message._user);
    text = _message.text;
    _chat = _message._chat;
}

SmartTgBotPP::user &SmartTgBotPP::message::GetUser()
{
    return *_user;
}

const std::vector<SmartTgBotPP::PhotoSize> &SmartTgBotPP::message::GetPhoto() const
{
    return *photo;
}
