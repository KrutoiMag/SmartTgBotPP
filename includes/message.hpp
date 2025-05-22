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
        int id = 0, ThreadID = 0;

	std::unique_ptr<user> _user;

      public:
        explicit message(void) = default;
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_MESSAGE_HPP
