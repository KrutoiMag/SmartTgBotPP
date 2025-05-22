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
    using TPAIR = std::pair<TCBOOL, TSTR>;
    using TCPAIR = const TPAIR;
} // namespace SmartTgBotPP

#endif // SMARTTGBOTPP_API_HPP
