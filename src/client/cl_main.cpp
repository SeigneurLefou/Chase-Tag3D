#include "client.hpp"

string get_server_ip(int argc, char **argv) {
	return (argc > 1) ? argv[1] : "127.0.0.1";
}

int main(int argc, char **argv)
{
	Client	client;
	char	buffer[BUFFER_SIZE];

	SDL_SetRenderDrawColor(client.renderer, 16, 16, 16, 255);
	SDL_RenderClear(client.renderer);
	SDL_RenderPresent(client.renderer);
	if (!client.connectToServer(get_server_ip(argc, argv))) {
		return EXIT_FAILURE;
	}

	cout << "Connected to the server, enter your input :" << endl;

	while (client.is_connected())
	{
		client.key_hook();
		if (client.is_connected() && !client.sendInput())
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
		SDL_Delay(16);
	}
	return EXIT_SUCCESS;
}
