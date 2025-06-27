#pragma once

#ifndef SMARTTGBOTPP_PHOTOSIZE_HPP
#define SMARTTGBOTPP_PHOTOSIZE_HPP

#include <string>

namespace SmartTgBotPP
{
    class PhotoSize
    {
        std::string FileID, FileUniqueID;
        std::size_t width = 0, height = 0, FileSize = 0;

      public:
        explicit PhotoSize() = default;
        explicit PhotoSize(const PhotoSize &_PhotoSize);
        explicit PhotoSize(const std::string &FileID, const std::string &FileUniqueID, const std::size_t &width,
                           const std::size_t &height, const std::size_t &FileSize = 0);

        const void SetFileID(const std::string &FileID), SetFileUniqueID(const std::string &FileUniqueID),
            SetWidth(const std::size_t &width), SetHeight(const std::size_t &height),
            SetFileSize(const std::size_t &FileSize);

        const std::string &GetFileID() const, &GetFileUniqueID() const;

        const std::size_t &GetWidth() const, &GetHeight() const, &GetFileSize() const;
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_PHOTOSIZE_HPP
