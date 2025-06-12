#include "../includes/timer.hpp"
#include <chrono>

SmartTgBotPP::timer::timer(const timer &_timer)
{
}

const void SmartTgBotPP::timer::start(void)
{
    IsStarted = true;

    _start = std::make_shared<std::chrono::steady_clock::time_point>(std::chrono::steady_clock::now());
}

const void SmartTgBotPP::timer::stop(void)
{
    IsStarted = false;
}

const void SmartTgBotPP::timer::clean(void)
{
    _start.reset();
}

const double SmartTgBotPP::timer::get(void) const
{
    std::chrono::duration<double> output;

    if (IsStarted)
        output = std::chrono::steady_clock::now() - (*_start);

    return output.count();
}
