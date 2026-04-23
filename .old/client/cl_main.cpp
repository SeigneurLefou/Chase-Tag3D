#include "client.hpp"

string get_server_ip(int argc, char **argv) {
    return (argc > 1) ? argv[1] : "127.0.0.1";
}

int main(int argc, char **argv)
{
    GameClient	client;
    char		buffer[BUFFER_SIZE];
    char		user_input[BUFFER_SIZE];
	string		msg;

    if (!client.connectToServer(get_server_ip(argc, argv))) {
        return EXIT_FAILURE;
    }

    cout << "Connected to the server, enter your input :" << endl;

    while (client.is_connected())
	{
        if (fgets(user_input, BUFFER_SIZE, stdin))
		{
			client.disconnect();
			break;
		}
        msg = user_input;
        if (!msg.empty() && msg.back() == '\n')
			msg.pop_back();
        if (client.is_connected() && !client.sendInput(msg))
		{
			client.disconnect();
			break;
		}

        if (client.is_connected() && client.receiveUpdate(buffer, BUFFER_SIZE) <= 0)
		{
            cout << "Serveur disconnected." << endl;
			client.disconnect();
			break;
		}
        if (client.is_connected())
			cout << "Receive : " << buffer << endl;
    }
    return EXIT_SUCCESS;
}
