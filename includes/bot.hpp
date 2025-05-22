#pragma once

#ifndef SMARTTGBOTPP_HPP
#define SMARTTGBOTPP_HPP

#include "API.hpp"

namespace SmartTgBotPP
{
    class bot
    {
        TSTR BotToken;

      public:
        explicit bot();
        explicit bot(TCSTR &BotToken);

        TCVOID SetToken(TCSTR &BotToken);

        TCPAIR GetUpdates(void) const;
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_HPP
