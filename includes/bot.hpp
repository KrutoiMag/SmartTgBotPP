#pragma once

#ifndef SMARTTGBOTPP_HPP
#define SMARTTGBOTPP_HPP

#include "API.hpp"
#include "InlineKeyboardMarkup.hpp"
#include "update.hpp"

#include <memory>
#include <optional>
#include <vector>

namespace SmartTgBotPP
{
    class bot
    {
        TSTR BotToken;

        std::shared_ptr<update> CurrentUpdate = std::make_shared<update>();

        std::size_t offset = 0;

        std::string JSON;

      public:
        explicit bot();
        explicit bot(TCSTR &BotToken);
        ~bot(void);

        TCVOID SetToken(TCSTR &BotToken), SetOffset(const std::size_t &offset);

        const bool SendMessage(const std::size_t &ChatID, const message &_message,
                               const InlineKeyboardMarkup &_InlineKeyboardMarkup = {}) const,
            ok() const;

        update RequestUpdate(void);

        update GetUpdate(void);

        const std::string &GetJSON(void) const;
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_HPP
