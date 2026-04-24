#include "client.hpp"

string get_server_ip(int argc, char **argv) {
	return (argc > 1) ? argv[1] : "127.0.0.1";
}

int main(int argc, char **argv)
{
	GameClient	client;
	char		buffer[BUFFER_SIZE];
	char		user_input[BUFFER_SIZE];

	if (!client.connectToServer(get_server_ip(argc, argv))) {
		return EXIT_FAILURE;
	}

	user_input[0] = 0;
	cout << "Connected to the server, enter your input :" << endl;

	while (client.is_connected())
	{
		user_input[0] = client.key_hook();
		if (client.is_connected() && !client.sendInput(user_input))
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
