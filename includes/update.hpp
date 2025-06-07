#pragma once

#ifndef SMARTTGBOTPP_UPDATE_HPP
#define SMARTTGBOTPP_UPDATE_HPP

#include "message.hpp"

namespace SmartTgBotPP
{
    class update
    {
        int UpdateID = 0;
        message _message, EditedMessage, ChannelPost, EditedChannelPost;

      public:
        explicit update(void) = default;
        explicit update(const int UpdateID, const message &_message());

        const void SetUpdateID(const int &UpdateID), SetMessage(const message &_message),
            SetEditedMessage(const message &EditedMessage), SetChannelPost(const message &ChannelPost),
            SetEditedChannelPost(const message &EditedChannelPost);

        const int &GetUpdateID(void) const;

        const message &GetMessage(void) const;
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_UPDATE_HPP
