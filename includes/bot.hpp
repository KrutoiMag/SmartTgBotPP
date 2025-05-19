#pragma once

#ifndef SMARTTGBOTPP_HPP
#define SMARTTGBOTPP_HPP

#include <string>

namespace SmartTgBotPP
{
    using TSTR = std::string;
    using TCSTR = const TSTR;
    using TCVOID = const void;

    class bot
    {
        TSTR BotToken;

      public:
        bot();
        bot(TCSTR &BotToken);

        TCVOID SetToken(TCSTR &BotToken);
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_HPP
