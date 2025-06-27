#pragma once

#ifndef SMARTTGBOTPP_DOCUMENT_HPP
#define SMARTTGBOTPP_DOCUMENT_HPP

#include "../includes/PhotoSize.hpp"

#include <memory>
#include <string>

namespace SmartTgBotPP
{
    class document
    {
        std::string FileID, FileUniqueID, FileName, MimeType;
        std::size_t FileSize = 0;
        std::shared_ptr<PhotoSize> thumbnail;

      public:
    };
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_DOCUMENT_HPP
