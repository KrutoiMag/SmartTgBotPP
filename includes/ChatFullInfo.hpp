// https://core.telegram.org/bots/api#chatfullinfo

#pragma once

#ifndef SMARTTGBOTPP_CHATFULLINFO_HPP
#define SMARTTGBOTPP_CHATFULLINFO_HPP

#include "chat.hpp"

#include <string>

namespace SmartTgBotPP
{
    class ChatFullInfo : public chat
    {
        int AccentColorId = 0, MaxReactionCount = 0;

      public:
        explicit ChatFullInfo(void) = default;
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_CHATFULLINFO_HPP
