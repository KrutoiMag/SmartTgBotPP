#pragma once

#ifndef SMARTTGBOTPP_WATCHER_HPP
#define SMARTTGBOTPP_WATCHER_HPP

#include "bot.hpp"
#include "timer.hpp"

#include <memory>

namespace SmartTgBotPP
{
    class watcher
    {
        std::shared_ptr<bot *> _bot;
        std::shared_ptr<timer> _timer = std::make_shared<timer>();

        double milliseconds = 5;

	int offset = 0;

      public:
        explicit watcher(void) = default;
        explicit watcher(SmartTgBotPP::bot &_bot);
        ~watcher(void);

        const void init(SmartTgBotPP::bot &_bot), SetTimeout(const double &milliseconds);

        const bool watch(void) const;
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_WATCHER_HPP
