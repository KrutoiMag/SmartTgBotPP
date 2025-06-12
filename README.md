# SmartTgBotPP
### Dependencies:
- [libcurl](https://libcurl.se/) installed on your OS!
- [xmake](https://xmake.io/)'s executable in your PATH!
### Sample
```cpp
#include "../includes/SmartTgBotPP.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <memory>

using namespace std;

int main(void)
{
    std::ios::sync_with_stdio(false);

    try
    {
        SmartTgBotPP::bot bot("ENTER YOUR BOT TOKEN HERE!");
        SmartTgBotPP::watcher watcher(bot);
        SmartTgBotPP::message message;

        message.SetText("Hi!");

        while (watcher.watch())
        {
            cout << bot.GetUpdate()->GetMessage().GetChat().GetID() << endl;
            bot.SendMessage(std::to_string(bot.GetUpdate()->GetMessage().GetChat().GetID()), message);
        }
    }
    catch (exception &ex)
    {
        cout << ex.what();
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
