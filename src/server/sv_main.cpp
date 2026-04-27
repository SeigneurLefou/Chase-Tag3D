#include "main_server.hpp"

bool	sv_main(unordered_map<int, Player> &players, mutex &p_mutex)
{
	Server  server;

	if (!server.init())
	{
		return (FAILURE);
	}

	cout << "Server on port " << PORT << endl;
	server.run_network(players, p_mutex);

	return (SUCCESS);
}

int main()
{
	Game						game;
	Map							map;
	unordered_map<int, Player>	players;
	mutex						players_mutex;
	thread						server_thread(sv_main, ref(players), ref(players_mutex));

	server_thread.detach();
	map.init(16, 16);
	if (!game.init(map, 800, 800)) return FAILURE;

	while (game.is_running)
	{
		game.handle_events();
		players_mutex.lock();
		for (auto& [id, player] : players)
			player.key_move(map, game.square_size);
		players_mutex.unlock();

		SDL_SetRenderDrawColor(game.renderer, 16, 16, 16, 255);
		SDL_RenderClear(game.renderer);
		
		map.render(game.renderer, game.square_size);
		players_mutex.lock();
		for (auto& [id, player] : players)
			player.render(game.renderer, game.square_size);
		players_mutex.unlock();
		
		SDL_RenderPresent(game.renderer);
		SDL_Delay(16);
	}
	return SUCCESS;
}
