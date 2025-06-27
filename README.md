# SmartTgBotPP

### Requirements

- Compiler that supports C++17!
- [libcurl](https://libcurl.se/) installed on your OS!
- [xmake](https://xmake.io/)'s executable in your PATH!
- [nlohmann/json](https://github.com/nlohmann/json) installed on your system!

### Sample

```cpp
#include "../includes/SmartTgBotPP.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
        {
            if (argc > 2)
                throw runtime_error("Too much arguments!");
            else
                throw runtime_error("Too few arguments, need to provide a bot token!");
        }

        ios::sync_with_stdio(false);

        auto bot = std::make_unique<SmartTgBotPP::bot>(argv[1]);
        auto watcher = std::make_unique<SmartTgBotPP::watcher>(*bot);

        while (watcher->watch())
        {
            if (!bot->GetUpdate().empty() && !bot->GetUpdate().GetMessage().GetText().empty())
            {
                cout << "A new message from User in Your bot: " << bot->GetUpdate().GetMessage().GetText() << endl;
                bot->SendMessage(bot->GetUpdate().GetMessage().GetChat().GetID(),
                                 SmartTgBotPP::message(bot->GetUpdate().GetMessage().GetText()));
            }
        }
    }
    catch (const exception &ex)
    {
        cout << ex.what() << endl;
    }

    return EXIT_SUCCESS;
}
```

Wanna some more examples? &mdash; Checkout an [examples](examples) folder!

### Building project

```shell
xmake
```

### Running a test program

```shell
xmake run test BOT_TOKEN
```

---
[LICENSE](LICENSE)
