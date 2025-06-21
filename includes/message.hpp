// https://core.telegram.org/bots/api#message

#pragma once

#ifndef SMARTTGBOTPP_MESSAGE_HPP
#define SMARTTGBOTPP_MESSAGE_HPP

#include "chat.hpp"
#include "user.hpp"

#include <memory>

namespace SmartTgBotPP
{
    class message
    {
        int ID = 0, ThreadID = 0;

        std::shared_ptr<user> _user = std::make_shared<user>();

        std::string text;

        std::shared_ptr<chat> _chat = std::make_shared<chat>();

      public:
        explicit message(void) = default;
        explicit message(const message &_message);
        explicit message(const std::string &text);

        message &operator=(const message &_message);

        const void SetText(const std::string &text), SetUser(const user &_user), SetChat(const chat &chat);

        const int &GetID(void) const;

        const std::string &GetText(void) const;

        const chat &GetChat(void) const;

        const void init(const message &_message);

        user &GetUser(void);
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_MESSAGE_HPP
