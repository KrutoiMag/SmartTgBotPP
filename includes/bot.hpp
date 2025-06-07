#pragma once

#ifndef SMARTTGBOTPP_HPP
#define SMARTTGBOTPP_HPP

#include "API.hpp"
#include "update.hpp"

namespace SmartTgBotPP
{
    class bot
    {
        TSTR BotToken;

      public:
        explicit bot();
        explicit bot(TCSTR &BotToken);

        TCVOID SetToken(TCSTR &BotToken), SendMessage(const std::string &ChatID, const message &_message) const;

        TCPAIR<update> GetUpdate(void) const;
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_HPP
