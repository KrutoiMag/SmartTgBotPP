#include "../includes/watcher.hpp"

using STBPPW = SmartTgBotPP::watcher;

STBPPW::watcher(const SmartTgBotPP::bot &_bot)
{
	init(_bot);
}

const void STBPPW::init(const SmartTgBotPP::bot &_bot)
{
    this->_bot = std::make_unique<const SmartTgBotPP::bot *>(&_bot);
}

const bool STBPPW::watch(void) const
{
    return (*_bot)->GetUpdates().first;
}
