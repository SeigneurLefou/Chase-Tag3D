#include "server.hpp"

int main()
{
    GameServer  server;

    if (!server.init())
    {
        return (1);
    }

    cout << "Server on port " << PORT << endl;
    server.runNetwork();

    return (0);
}
