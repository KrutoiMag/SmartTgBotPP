#include "../includes/update.hpp"

const void SmartTgBotPP::update::SetUpdateID(const int &UpdateID)
{
    this->UpdateID = UpdateID;
}

const void SmartTgBotPP::update::SetMessage(const message &_message)
{
    this->_message = _message;
}

const int &SmartTgBotPP::update::GetUpdateID(void) const
{
    return UpdateID;
}

const SmartTgBotPP::message &SmartTgBotPP::update::GetMessage(void) const
{
    return _message;
}
