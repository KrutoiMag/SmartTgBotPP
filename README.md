# SmartTgBotPP
### Requirements
- Compiler that supports C++17!
- [libcurl](https://libcurl.se/) installed on your OS!
- [xmake](https://xmake.io/)'s executable in your PATH!
### Sample
```cpp
#include "../includes/SmartTgBotPP.hpp"

#include <cstdlib>
#include <iostream>
#include <memory>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    auto bot = std::make_unique<SmartTgBotPP::bot>("BOT_TOKEN");
    auto watcher = std::make_unique<SmartTgBotPP::watcher>(*bot);

    while (watcher->watch())
    {
        if (!bot->GetUpdate().GetMessage().GetText().empty())
            bot->SendMessage(bot->GetUpdate().GetMessage().GetChat().GetID(),
                             SmartTgBotPP::message(bot->GetUpdate().GetMessage().GetText()));
    }

    return EXIT_SUCCESS;
}
```
### Building project
```shell
xmake build SmartTgBotPP
```
### Running a test program
```shell
xmake run test
```
---
[LICENSE](LICENSE)
