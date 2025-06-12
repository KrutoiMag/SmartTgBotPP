#pragma once

#include <memory>
#ifndef SMARTTGBOTPP_HPP
#define SMARTTGBOTPP_HPP

#include "API.hpp"
#include "update.hpp"

#include <optional>

namespace SmartTgBotPP
{
    class bot
    {
        TSTR BotToken;

        std::shared_ptr<update> CurrentUpdate = std::make_shared<update>();

      public:
        explicit bot();
        explicit bot(TCSTR &BotToken);
        ~bot(void);

        TCVOID SetToken(TCSTR &BotToken);

        const bool SendMessage(const std::string &ChatID, const message &_message) const;

        std::optional<update> RequestUpdate(void), GetUpdate(void);
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_HPP
