#include "../includes/bot.hpp"

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

STBPP::TCPAIR STBPP::bot::GetUpdates(void) const
{
    auto handle = std::make_unique<CURL *>(curl_easy_init());

    std::string temp;

    std::unique_ptr<CURLcode> res;

    if (*handle)
    {
        curl_easy_setopt(*handle, CURLOPT_URL,
                         "https://api.telegram.org/bot7637934556:AAElfYnafoO2C3RIDFU_kjspp5p8bDb78x4/getUpdates");
        curl_easy_setopt(*handle, CURLOPT_WRITEFUNCTION, libCURLGetRaw);
        curl_easy_setopt(*handle, CURLOPT_WRITEDATA, &temp);

        res = std::make_unique<CURLcode>(curl_easy_perform(*handle));

        if (!res)
        {
            perror("Error 1");
        }

        curl_easy_cleanup(*handle);

        printf("%b", *res);
    }
    else
    {
        perror("Error 0");
    }

    return TCPAIR(*handle, temp);
}
