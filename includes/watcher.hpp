#pragma once

#ifndef SMARTTGBOTPP_WATCHER_HPP
#define SMARTTGBOTPP_WATCHER_HPP

#include "bot.hpp"

#include <memory>

namespace SmartTgBotPP
{
    class watcher
    {
        std::unique_ptr<const bot *> _bot;

      public:
        explicit watcher(void) = default;
        explicit watcher(const SmartTgBotPP::bot &_bot);

        const void init(const SmartTgBotPP::bot &_bot);

        const bool watch(void) const;
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_WATCHER_HPP
