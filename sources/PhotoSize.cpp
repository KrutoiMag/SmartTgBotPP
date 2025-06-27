#include "../includes/PhotoSize.hpp"

SmartTgBotPP::PhotoSize::PhotoSize(const PhotoSize &_PhotoSize)
{
    PhotoSize(_PhotoSize.FileID, _PhotoSize.FileUniqueID, _PhotoSize.width, _PhotoSize.height, _PhotoSize.FileSize);
}

SmartTgBotPP::PhotoSize::PhotoSize(const std::string &FileID, const std::string &FileUniqueID, const std::size_t &width,
                                   const std::size_t &height, const std::size_t &FileSize)
{
    this->FileID = FileID;
    this->FileUniqueID = FileUniqueID;
    this->width = width;
    this->height = height;
    this->FileSize = FileSize;
}

const void SmartTgBotPP::PhotoSize::SetFileID(const std::string &FileID)
{
    this->FileID = FileID;
}

const void SmartTgBotPP::PhotoSize::SetFileUniqueID(const std::string &FileUniqueID)
{
    this->FileUniqueID = FileUniqueID;
}

const void SmartTgBotPP::PhotoSize::SetWidth(const std::size_t &width)
{
    this->width = width;
}

const void SmartTgBotPP::PhotoSize::SetHeight(const std::size_t &height)
{
    this->height = height;
}

const void SmartTgBotPP::PhotoSize::SetFileSize(const std::size_t &FileSize)
{
    this->FileSize = FileSize;
}
