#include "../includes/watcher.hpp"

#include <algorithm>
#include <chrono>
#include <memory>
#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>

using STBPPW = SmartTgBotPP::watcher;

const inline std::optional<SmartTgBotPP::update> ParseGetUpdatesRequestResult(const std::string &RawJSON)
{
    std::unique_ptr<SmartTgBotPP::update> output;

    if (nlohmann::json::accept(RawJSON))
    {
        auto tmp = std::make_unique<nlohmann::json>(nlohmann::json::parse(RawJSON));

        if (tmp->contains("ok") && tmp->at("ok").get<bool>() == true)
        {
            auto tt = std::make_unique<SmartTgBotPP::update>();

            if (!tmp->at("result").empty())
            {
                if (tmp->at("result")[0].contains("update_id"))
                {
                    tt->SetUpdateID(tmp->at("result")[0].at("update_id").get<std::size_t>());
                }
                if (tmp->at("result")[0].contains("message"))
                {
                    auto json = std::make_unique<nlohmann::json>(tmp->at("result")[0].at("message"));
                    if (json->contains("message_id"))
                    {
                    }
                    if (json->contains("from"))
                    {
                        auto usr = std::make_unique<SmartTgBotPP::user>();
                        if (json->at("from").contains("id"))
                        {
                            usr->SetID(json->at("from").at("id").get<std::size_t>());
                        }
                        tt->GetMessage().SetUser(*usr);
                    }
                    if (json->contains("chat"))
                    {
                        auto t = std::make_unique<SmartTgBotPP::chat>();

                        if (json->at("chat").contains("id"))
                            t->SetID(json->at("chat").at("id").get<std::size_t>());

                        tt->GetMessage().SetChat(*t);
                    }
                    if (json->contains("text"))
                    {
                        tt->GetMessage().SetText(json->at("text").get<std::string>());
                    }
                }

                output = std::make_unique<SmartTgBotPP::update>(*tt);
            }
            // if (tmp->at("result").contains("message_id"))
            // ParseResultUpdateID(tmp->at("result").at("message_id").get<int>());
        }
    }

    if (output)
        return std::make_optional(*output);

    return std::nullopt;
}

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

    return (!js || ([&]() -> bool {
        if (js->at("ok").get<bool>())
        {
            if (!js->at("result").empty())
                (*_bot)->GetUpdate().SetEmpty(false);
            else
                (*_bot)->GetUpdate().SetEmpty(true);

            return true;
        }

        return false;
    })());
}
