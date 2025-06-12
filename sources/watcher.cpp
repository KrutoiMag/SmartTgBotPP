#include "../includes/watcher.hpp"

#include <algorithm>
#include <chrono>

using STBPPW = SmartTgBotPP::watcher;

STBPPW::watcher(SmartTgBotPP::bot &_bot)
{
    init(_bot);
}

STBPPW::watcher::~watcher(void)
{
    _bot.reset();
    _timer.reset();
}

const void STBPPW::init(SmartTgBotPP::bot &_bot)
{
    _timer->start();

    this->_bot = std::make_shared<SmartTgBotPP::bot *>(&_bot);
}

const void STBPPW::SetTimeout(const double &milliseconds)
{
    this->milliseconds = milliseconds;
}

const bool STBPPW::watch(void) const
{
    if (_timer->get() >= milliseconds)
    {
        std::size_t offset = 0;

        for (const auto &i : (*_bot)->GetUpdates())
        {
            offset = std::max(i.GetUpdateID(), offset);
        }

        offset += 1;

        (*_bot)->SetOffset(offset);

        return !(*_bot)->RequestUpdates().empty();
    }
    else
        return true;
}
