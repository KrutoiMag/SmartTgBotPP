#include "../includes/bot.hpp"
#include "../includes/nlohmann/json.hpp"

#include <assert.h>
#include <cstdio>
#include <curl/curl.h>
#include <curl/easy.h>
#include <memory>

namespace STBPP = SmartTgBotPP;

inline size_t libCURLGetRaw(void *buffer, std::size_t size, std::size_t nmemb, std::string *data)
{
    data->append((char *)buffer, size * nmemb);
    return size * nmemb;
}

inline void init()
{
    curl_global_init(CURL_GLOBAL_ALL);
}

STBPP::bot::bot()
{
    init();
}

STBPP::bot::bot(STBPP::TCSTR &BotToken) : BotToken(BotToken)
{
    bot();
}

STBPP::TCVOID STBPP::bot::SetToken(STBPP::TCSTR &BotToken)
{
    this->BotToken = BotToken;
}

STBPP::TCVOID STBPP::bot::SendMessage(const std::string &ChatID, const message &_message) const
{
    auto handle = std::make_unique<CURL *>(curl_easy_init());

    if (*handle)
    {
        std::string postfileds = "chat_id=" + ChatID + "&text=" + _message.GetText(),
                    URL = "https://api.telegram.org/bot" + BotToken + "/sendMessage";
        curl_easy_setopt(*handle, CURLOPT_POSTFIELDS, postfileds.c_str());
        curl_easy_setopt(*handle, CURLOPT_URL, URL.c_str());

        auto res = std::make_unique<CURLcode>(curl_easy_perform(*handle));

        if (!res)
        {
            perror("ERROR0");
        }

        curl_easy_cleanup(*handle);
    }
    else
    {
        perror("ERROR1");
    }
}

STBPP::TCPAIR<STBPP::update> STBPP::bot::GetUpdate(void) const
{
    auto handle = std::make_unique<CURL *>(curl_easy_init());

    std::string temp;

    std::unique_ptr<CURLcode> res;

    if (*handle)
    {
        curl_easy_setopt(*handle, CURLOPT_URL,
                         std::string("https://api.telegram.org/bot" + BotToken + "/getUpdates").c_str());
        curl_easy_setopt(*handle, CURLOPT_WRITEFUNCTION, libCURLGetRaw);
        curl_easy_setopt(*handle, CURLOPT_WRITEDATA, &temp);

        res = std::make_unique<CURLcode>(curl_easy_perform(*handle));

        if (!res)
        {
            perror("Error 1");
        }

        curl_easy_cleanup(*handle);
    }
    else
    {
        perror("Error 0");
    }

    auto output = std::make_unique<update>();

    if (nlohmann::json::accept(temp))
    {
        auto json = std::make_unique<nlohmann::json>(nlohmann::json::parse(temp));

        if (json->contains("ok") && json->at("ok").get<bool>() == true)
        {
            if (json->at("result").is_array())
            {
                output->SetUpdateID(json->at("result")[0].at("update_id").get<int>());
            }
        }
    }

    return TCPAIR<update>(*handle, *output);
}
