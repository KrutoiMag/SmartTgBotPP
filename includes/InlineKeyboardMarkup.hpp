#pragma once

#ifndef SMARTTGBOTPP_INLINEKEYBOARDMARKUP_HPP
#define SMARTTGBOTPP_INLINEKEYBOARDMARKUP_HPP

#include "../includes/InlineKeyboardButton.hpp"

#include <memory>
#include <optional>
#include <vector>

namespace SmartTgBotPP
{
    class InlineKeyboardMarkup
    {
        std::vector<std::vector<std::optional<std::shared_ptr<InlineKeyboardButton>>>> ButtonRows;

      public:
        InlineKeyboardMarkup() = default;
        explicit InlineKeyboardMarkup(const InlineKeyboardMarkup &_InlineKeyboardMarkup);

        const void InsertRow();

        const void InsertButtonInRow(const std::size_t &RowID, const InlineKeyboardButton &_InlineKeyboardButton);

        const std::size_t GetRowsCount() const;

        const std::size_t GetButtonsCountInRow(const std::size_t &RowID) const;

        const std::optional<std::shared_ptr<InlineKeyboardButton>> &GetButtonFromRow(const std::size_t &RowID,
                                                                                     const std::size_t &ButtonID) const;
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_INLINEKEYBOARDMARKUP_HPP
