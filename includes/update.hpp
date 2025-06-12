#pragma once

#ifndef SMARTTGBOTPP_UPDATE_HPP
#define SMARTTGBOTPP_UPDATE_HPP

#include "message.hpp"

namespace SmartTgBotPP
{
    class update
    {
        std::size_t UpdateID = 0;
        message _message, EditedMessage, ChannelPost, EditedChannelPost;

      public:
        explicit update() = default;
        explicit update(const int UpdateID, const message &_message());

        const void SetUpdateID(const std::size_t &UpdateID), SetMessage(const message &_message),
            SetEditedMessage(const message &EditedMessage), SetChannelPost(const message &ChannelPost),
            SetEditedChannelPost(const message &EditedChannelPost);

        const std::size_t &GetUpdateID(void) const;

        message &GetMessage(void);
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_UPDATE_HPP
