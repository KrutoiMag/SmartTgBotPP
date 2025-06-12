#pragma once

#include <memory>
#ifndef SMARTTGBOTPP_HPP
#define SMARTTGBOTPP_HPP

#include "API.hpp"
#include "update.hpp"

#include <optional>
#include <vector>

namespace SmartTgBotPP
{
    class bot
    {
        TSTR BotToken;

        std::shared_ptr<std::vector<update>> CurrentUpdates = std::make_shared<std::vector<update>>();

        std::size_t offset = 0;

      public:
        explicit bot();
        explicit bot(TCSTR &BotToken);
        ~bot(void);

        TCVOID SetToken(TCSTR &BotToken), SetOffset(const std::size_t &offset);

        const bool SendMessage(const std::string &ChatID, const message &_message) const;

        std::vector<update> RequestUpdates(void);

        std::vector<update> GetUpdates(void);
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_HPP
