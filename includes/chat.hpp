#pragma once

#ifndef SMARTTGBOTPP_CHAT_HPP
#define SMARTTGBOTPP_CHAT_HPP

#include <string>

namespace SmartTgBotPP
{
    class chat
    {
        std::size_t ID = 0;
        std::string type, title, UserName, FirstName, LastName;
        bool IsForum = false;

      public:
        explicit chat(void) = default;

        const void SetID(const std::size_t &ID), SetType(const std::string &type), SetTitle(const std::string &title),
            SetUserName(const std::string &UserName), SetFirstName(const std::string &FirstName),
            SetLastName(const std::string &LastName), SetForumStatus(const bool &status), init(const chat &_chat);

        const std::size_t &GetID(void) const;

        const std::string &GetType(void) const, &GetTitle(void) const, &GetUserName(void) const,
            &GetFirstName(void) const, &GetLastName(void) const;

        const bool &GetForumStatus(void) const;
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_CHAT_HPP
