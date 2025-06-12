#include "../includes/bot.hpp"
#include "../includes/chat.hpp"
#include "../includes/nlohmann/json.hpp"
#include "../includes/user.hpp"

#include <assert.h>
#include <cstdio>
#include <curl/curl.h>
#include <curl/easy.h>
#include <memory>
#include <optional>
#include <stdexcept>
#include <utility>

namespace STBPP = SmartTgBotPP;

inline const void ParseResultUpdateID(const std::string &raw)
{
}

inline const void ParseResultMessageText(const std::string &raw)
{
}

inline const void ParseResultMessageID(const std::string &raw)
{
}

inline const void ParseResultMessageFrom(const std::string &raw)
{
}

inline const void ParseResultMessageDate(const std::string &raw)
{
}

class bla
{
  public:
    explicit bla(void) = default;

    bla &operator=(const bla &_bla);
};

inline const SmartTgBotPP::chat ParseResultMessageChat(const nlohmann::json &raw)
{
    auto output = std::make_unique<SmartTgBotPP::chat>();

    if (raw.contains("first_name"))
        output->SetFirstName(raw.at("first_name"));
    if (raw.contains("id"))
        output->SetID(raw.at("id").get<int>());

    return *output;
}

inline const void ParseResultMessage(const nlohmann::json &raw)
{
    ParseResultMessageChat(raw);
    ParseResultMessageDate(raw);
    ParseResultMessageFrom(raw);
}

inline const std::vector<SmartTgBotPP::update> ParseResult(const std::string &raw)
{
    auto output = std::make_unique<std::vector<SmartTgBotPP::update>>();

    if (nlohmann::json::accept(raw))
    {
        auto tmp = std::make_unique<nlohmann::json>(nlohmann::json::parse(raw));

        if (tmp->contains("result"))
        {
            for (const auto &i : tmp->at("result"))
            {
                auto tt = std::make_unique<SmartTgBotPP::update>();

                if (i.contains("update_id"))
                {
                    tt->SetUpdateID(tmp->at("result")[0].at("update_id").get<std::size_t>());
                }
                if (i.contains("message"))
                {
                    auto json = std::make_unique<nlohmann::json>(i.at("message"));
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

                output->push_back(*tt);
            }
            // if (tmp->at("result").contains("message_id"))
            // ParseResultUpdateID(tmp->at("result").at("message_id").get<int>());
        }
    }

    return *output;
}

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

STBPP::bot::~bot()
{
    curl_global_cleanup();
}

STBPP::TCVOID STBPP::bot::SetToken(STBPP::TCSTR &BotToken)
{
    this->BotToken = BotToken;
}

STBPP::TCVOID SmartTgBotPP::bot::SetOffset(const std::size_t &offset)
{
    this->offset = offset;
}

const bool STBPP::bot::SendMessage(const std::string &ChatID, const message &_message) const
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

    return *handle;
}

std::vector<STBPP::update> STBPP::bot::RequestUpdates(void)
{
    auto handle = std::make_unique<CURL *>(curl_easy_init());

    std::string temp;

    std::unique_ptr<CURLcode> res;

    if (*handle)
    {
        curl_easy_setopt(
            *handle, CURLOPT_URL,
            std::string("https://api.telegram.org/bot" + BotToken + "/getUpdates?offset=" + std::to_string(offset))
                .c_str());
        curl_easy_setopt(*handle, CURLOPT_WRITEFUNCTION, libCURLGetRaw);
        curl_easy_setopt(*handle, CURLOPT_WRITEDATA, &temp);

        res = std::make_unique<CURLcode>(curl_easy_perform(*handle));

        if ((*res) != CURLE_OK)
        {
            throw std::runtime_error("Failed to establish connection!");
        }

        curl_easy_cleanup(*handle);
    }
    else
    {
        // ERROR
        throw std::runtime_error("Failed to initialize libcurl!");
    }

    CurrentUpdates = std::make_shared<std::vector<update>>(ParseResult(temp));

    return *CurrentUpdates;
}

std::vector<STBPP::update> STBPP::bot::GetUpdates(void)
{
    return *CurrentUpdates;
}
