#include "../includes/user.hpp"

using STBPPU = SmartTgBotPP::user;

STBPPU::user(const int &ID, const bool &IsBot, const bool &IsPremium, const bool &AddedToAttachmentMenu,
             const bool &CanJoinGroups, const bool &CanReadAllGroupMessages, const bool &SupportsInlineQueries,
             const bool &CanConnectToBusiness, const bool &HasMainWebApp)
{
    _ID = ID;
    _IsBot = IsBot;
    _IsPremium = IsPremium;
    _AddedToAttachmentMenu = AddedToAttachmentMenu;
    _CanJoinGroups = CanJoinGroups;
    _SupportsInlineQueries = SupportsInlineQueries;
    _CanConnectToBusiness = CanConnectToBusiness;
    _HasMainWebApp = HasMainWebApp;
}

const int &STBPPU::GetID(void) const
{
    return _ID;
}

const void STBPPU::SetID(const int &ID)
{
    _ID = ID;
}

const void STBPPU::SetFirstName(const std::string &FirstName)
{
    this->FirstName = FirstName;
}

const void STBPPU::SetLastName(const std::string &LastName)
{
    this->LastName = LastName;
}

const void STBPPU::SetUsername(const std::string &username)
{
    this->username = username;
}

const void STBPPU::SetLanguageCode(const std::string &LanguageCode)
{
    this->LanguageCode = LanguageCode;
}

const bool &STBPPU::IsBot(void) const
{
    return _IsBot;
}

const bool &STBPPU::IsPremium(void) const
{
    return _IsPremium;
}

const bool &STBPPU::AddedToAttachmentMenu(void) const
{
    return _AddedToAttachmentMenu;
}

const bool &STBPPU::CanJoinGroups(void) const
{
    return _CanJoinGroups;
}

const bool &STBPPU::CanReadAllGroupMessages(void) const
{
    return _CanReadAllGroupMessages;
}

const bool &STBPPU::SupportsInlineQueries(void) const
{
    return _SupportsInlineQueries;
}

const bool &STBPPU::CanConnectToBusiness(void) const
{
    return _CanConnectToBusiness;
}

const bool &STBPPU::HasMainWebApp(void) const
{
    return _HasMainWebApp;
}

const std::string &STBPPU::user::GetFirstName(void) const
{
    return FirstName;
}

const std::string &STBPPU::user::GetLastName(void) const
{
    return LastName;
}

const std::string &STBPPU::user::GetLanguageCode(void) const
{
    return LanguageCode;
}
