#pragma once

#ifndef SMARTTGBOTPP_WATCHER_HPP
#define SMARTTGBOTPP_WATCHER_HPP

#include "bot.hpp"

#include <memory>

namespace SmartTgBotPP
{
    class watcher
    {
        std::shared_ptr<bot*> _bot;

      public:
        explicit watcher(void) = default;
        explicit watcher(SmartTgBotPP::bot &_bot);

        const void init(SmartTgBotPP::bot &_bot);

        const bool watch(void) const;
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_WATCHER_HPP
