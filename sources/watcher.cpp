#include "../includes/nlohmann/json.hpp"
#include "../includes/watcher.hpp"

#include <algorithm>
#include <chrono>
#include <memory>

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
    std::unique_ptr<nlohmann::json> js;

    if (_timer->get() >= milliseconds)
    {
        (*_bot)->RequestUpdate();

        js = std::make_unique<nlohmann::json>(nlohmann::json::parse((*_bot)->GetJSON()));

        if (!js->at("result").empty())
        {
            std::size_t offset = 0;

            for (const auto &i : js->at("result"))
            {
                if (offset == 0)
                    offset = i.at("update_id").get<std::size_t>();
                else
                    offset = std::min(i.at("update_id").get<std::size_t>(), offset);
            }

            offset += 1;

            (*_bot)->SetOffset(offset);
        }
    }

    if (js && js->at("ok").get<bool>() == false)
        return false;

    return (!js || js->at("ok").get<bool>());
}
