// https://core.telegram.org/bots/api#message

#pragma once

#ifndef SMARTTGBOTPP_MESSAGE_HPP
#define SMARTTGBOTPP_MESSAGE_HPP

#include "user.hpp"

#include <memory>

namespace SmartTgBotPP
{
    class message
    {
        int ID = 0, ThreadID = 0;

        std::shared_ptr<user> _user;

        std::string text;

      public:
        explicit message(void) = default;

        message &operator=(const message &_message);

        const void SetText(const std::string &text);

        const int &GetID(void) const;

        const std::string &GetText(void) const;
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_MESSAGE_HPP
