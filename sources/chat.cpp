#include "../includes/chat.hpp"

// SmartTgBotPP::chat::chat(const chat &_chat)
// {
//     init(_chat);
// }

// SmartTgBotPP::chat &SmartTgBotPP::chat::operator=(const chat &_chat)
// {
//     if (this == &_chat)
//         return *this;
//
//     init(_chat);
//
//     return *this;
// }

const void SmartTgBotPP::chat::SetID(const std::size_t &ID)
{
    this->ID = ID;
}

const void SmartTgBotPP::chat::SetType(const std::string &type)
{
    this->type = type;
}

const void SmartTgBotPP::chat::SetTitle(const std::string &title)
{
    this->title = title;
}

const void SmartTgBotPP::chat::SetUserName(const std::string &UserName)
{
    this->UserName = UserName;
}

const void SmartTgBotPP::chat::SetFirstName(const std::string &FirstName)
{
    this->FirstName = FirstName;
}

const void SmartTgBotPP::chat::SetLastName(const std::string &LastName)
{
    this->LastName = LastName;
}

const void SmartTgBotPP::chat::SetForumStatus(const bool &status)
{
    IsForum = status;
}

const void SmartTgBotPP::chat::init(const chat &_chat)
{
    ID = _chat.ID;
    type = _chat.type;
    title = _chat.title;
    UserName = _chat.UserName;
    FirstName = _chat.FirstName;
    LastName = _chat.LastName;
    IsForum = _chat.IsForum;
}

const std::size_t &SmartTgBotPP::chat::GetID(void) const
{
    return ID;
}

const std::string &SmartTgBotPP::chat::GetType(void) const
{
    return type;
}

const std::string &SmartTgBotPP::chat::GetTitle(void) const
{
    return title;
}

const std::string &SmartTgBotPP::chat::GetUserName(void) const
{
    return UserName;
}

const std::string &SmartTgBotPP::chat::GetFirstName(void) const
{
    return FirstName;
}

const std::string &SmartTgBotPP::chat::GetLastName(void) const
{
    return LastName;
}

const bool &SmartTgBotPP::chat::GetForumStatus(void) const
{
    return IsForum;
}
