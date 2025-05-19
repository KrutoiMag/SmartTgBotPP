#include "../includes/bot.hpp"

#include <curl/curl.h>
#include <memory>

namespace STB = SmartTgBotPP;

void init();

size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp);

STB::bot::bot()
{
    init();
}

STB::bot::bot(STB::TCSTR &BotToken) : BotToken(BotToken)
{
}

STB::TCVOID STB::bot::SetToken(STB::TCSTR &BotToken)
{
    this->BotToken = BotToken;
}

void init()
{
    curl_global_init(CURL_GLOBAL_ALL);

    auto handle = std::make_unique<CURL *>(curl_easy_init());

    curl_easy_setopt(*handle, CURLOPT_URL, "https://api.telegram.org/bot");
}

size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
}
