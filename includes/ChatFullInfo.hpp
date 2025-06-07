// https://core.telegram.org/bots/api#chatfullinfo

#pragma once

#ifndef SMARTTGBOTPP_CHATFULLINFO_HPP
#define SMARTTGBOTPP_CHATFULLINFO_HPP

#include <string>

namespace SmartTgBotPP
{
    class ChatFullInfo
    {
        int id = 0, AccentColorId = 0, MaxReactionCount = 0;

        std::string type, title, username, FirstName, LastName;

        bool IsForum = false;

      public:
	const int GetID(void) const;
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_CHATFULLINFO_HPP
