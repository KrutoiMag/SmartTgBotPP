#include "../includes/update.hpp"

// SmartTgBotPP::update::update(const update &_update)
// {
//     UpdateID = _update.UpdateID;
//     _message = _update._message;
//     EditedMessage = _update.EditedMessage;
//     ChannelPost = _update.ChannelPost;
//     EditedChannelPost = _update.EditedChannelPost;
// }

const void SmartTgBotPP::update::SetUpdateID(const std::size_t &UpdateID)
{
    this->UpdateID = UpdateID;
}

const void SmartTgBotPP::update::SetMessage(const message &_message)
{
    this->_message = _message;
}

const std::size_t &SmartTgBotPP::update::GetUpdateID(void) const
{
    return UpdateID;
}

SmartTgBotPP::message &SmartTgBotPP::update::GetMessage(void)
{
    return _message;
}
