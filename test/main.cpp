#include "../includes/SmartTgBotPP.hpp"
#include "../includes/user.hpp"

#include <cstdlib>
#include <iostream>

using namespace std;

int main(void)
{
    std::ios::sync_with_stdio(false);

    SmartTgBotPP::bot bot("7637934556:AAElfYnafoO2C3RIDFU_kjspp5p8bDb78x4");
    SmartTgBotPP::watcher watcher(bot);
    SmartTgBotPP::user user;

    user.SetFirstName("BU");

    cout << user.GetFirstName() << endl;

    while (watcher.watch())
    {
	    cout << bot.GetUpdates().second << endl;
    }

    return EXIT_SUCCESS;
}
