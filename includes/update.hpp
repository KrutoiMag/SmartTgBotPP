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
        bool _empty = true;

      public:
        explicit update() = default;
        explicit update(const int UpdateID, const message &_message());

        const void SetUpdateID(const std::size_t &UpdateID), SetMessage(const message &_message),
            SetEditedMessage(const message &EditedMessage), SetChannelPost(const message &ChannelPost),
            SetEditedChannelPost(const message &EditedChannelPost), SetEmpty(const bool &value);

        const std::size_t &GetUpdateID(void) const;

        message &GetMessage(void);

        const bool &empty() const;
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_UPDATE_HPP
