// https://core.telegram.org/bots/api#user

#pragma once

#ifndef SMARTTGBOTPP_USER_HPP
#define SMARTTGBOTPP_USER_HPP

#include "API.hpp"

namespace SmartTgBotPP
{
    class user
    {
        std::size_t _ID = 0;
        bool _IsBot = false, _IsPremium = false, _AddedToAttachmentMenu = false, _CanJoinGroups = false,
             _CanReadAllGroupMessages = false, _SupportsInlineQueries = false, _CanConnectToBusiness = false,
             _HasMainWebApp = false;
        std::string FirstName, LastName, username, LanguageCode;

      public:
        explicit user() = default;
        explicit user(const int &ID, const bool &IsBot = false, const bool &IsPremium = false,
                      const bool &AddedToAttachmentMenu = false, const bool &CanJoinGroups = false,
                      const bool &CanReadAllGroupMessages = false, const bool &SupportsInlineQueries = false,
                      const bool &CanConnectToBusiness = false, const bool &HasMainWebApp = false);

        const std::size_t &GetID(void) const;

        const void SetID(const std::size_t &ID), SetFirstName(const std::string &FirstName),
            SetLastName(const std::string &LastName), SetUsername(const std::string &username),
            SetLanguageCode(const std::string &LanguageCode);

        const bool &IsBot(void) const, &IsPremium(void) const, &AddedToAttachmentMenu(void) const,
            &CanJoinGroups(void) const, &CanReadAllGroupMessages(void) const, &SupportsInlineQueries(void) const,
            &CanConnectToBusiness(void) const, &HasMainWebApp(void) const;

        const std::string &GetFirstName(void) const, &GetLastName(void) const, &GetLanguageCode(void) const;
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_USER_HPP
