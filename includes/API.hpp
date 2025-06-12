#pragma once

#ifndef SMARTTGBOTPP_API_HPP
#define SMARTTGBOTPP_API_HPP

#include <string>

namespace SmartTgBotPP
{
    using TSTR = std::string;
    using TCSTR = const TSTR;
    using TCVOID = const void;
    using TCBOOL = const bool;

    template <class T> using TPAIR = std::pair<TCBOOL, T>;

    template <class T> using TCPAIR = const std::pair<bool, T>;
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_API_HPP
