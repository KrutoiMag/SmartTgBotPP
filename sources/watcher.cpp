#include "../includes/watcher.hpp"

using STBPPW = SmartTgBotPP::watcher;

STBPPW::watcher(SmartTgBotPP::bot &_bot)
{
    init(_bot);
}

const void STBPPW::init(SmartTgBotPP::bot &_bot)
{
    this->_bot = std::make_shared<SmartTgBotPP::bot *>(&_bot);
}

const bool STBPPW::watch(void) const
{
    return (*_bot)->RequestUpdate().has_value();
}
