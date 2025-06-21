#include "../includes/InlineKeyboardMarkup.hpp"

SmartTgBotPP::InlineKeyboardMarkup::InlineKeyboardMarkup(const InlineKeyboardMarkup &_InlineKeyboardMarkup)
{
    ButtonRows = _InlineKeyboardMarkup.ButtonRows;
}

const void SmartTgBotPP::InlineKeyboardMarkup::InsertRow()
{
    ButtonRows.emplace_back();
}

const void SmartTgBotPP::InlineKeyboardMarkup::InsertButtonInRow(const std::size_t &RowID,
                                                                 const InlineKeyboardButton &_InlineKeyboardButton)
{
    ButtonRows.at(RowID).emplace_back(std::make_optional<std::unique_ptr<InlineKeyboardButton>>(
        std::make_unique<InlineKeyboardButton>(_InlineKeyboardButton)));
}

const std::size_t SmartTgBotPP::InlineKeyboardMarkup::GetRowsCount() const
{
    return ButtonRows.size();
}

const std::size_t SmartTgBotPP::InlineKeyboardMarkup::GetButtonsCountInRow(const std::size_t &RowID) const
{
    return ButtonRows.at(RowID).size();
}

const std::optional<std::shared_ptr<SmartTgBotPP::InlineKeyboardButton>> &SmartTgBotPP::InlineKeyboardMarkup::
    GetButtonFromRow(const std::size_t &RowID, const std::size_t &ButtonID) const
{
    return ButtonRows.at(RowID).at(ButtonID);
}
