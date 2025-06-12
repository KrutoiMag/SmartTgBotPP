#pragma once

#ifndef SMARTTGBOTPP_TIMER_HPP
#define SMARTTGBOTPP_TIMER_HPP

#include <chrono>
#include <memory>

namespace SmartTgBotPP
{
    class timer
    {
        std::shared_ptr<std::chrono::steady_clock::time_point> _start =
            std::make_shared<std::chrono::steady_clock::time_point>();

        bool IsStarted = false;

      public:
        explicit timer(void) = default;
        explicit timer(const timer &_timer);

        const void start(void), stop(void), clean(void);

        const double get(void) const;
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_TIMER_HPP
