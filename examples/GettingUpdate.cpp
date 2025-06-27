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
        auto bot = make_unique<SmartTgBotPP::bot>(argv[1]);

        if (!bot->ok())
            throw runtime_error("Failed to initialize bot!");

        auto watcher = make_unique<SmartTgBotPP::watcher>(*bot);

        while (watcher->watch())
        {
            if (bot->ok() && !bot->GetUpdate().empty())
            {
                cout << "Update ID: " << bot->GetUpdate().GetUpdateID() << endl;
                cout << "Update text: " << bot->GetUpdate().GetMessage().GetText() << endl;
            }
        }
    }
    catch (const exception &ex)
    {
        cout << ex.what() << endl;
    }

    return EXIT_SUCCESS;
}
