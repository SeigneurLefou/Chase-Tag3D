#include "main_server.hpp"

int main()
{
	Game			game;
	Map				map;
	vector<Player>	players;
	Player			tmp_player;

	map.init(16, 16);
	if (!game.init(map, 800, 800)) return FAILURE;

	tmp_player.init(0, 0, 0);
	players.push_back(tmp_player);

	while (game.is_running)
	{
		game.handle_events();
		// game.handle_events(players[0]);
		// for (size_t i=0; i < players.size(); i++)
			// players[i].key_move(map, game.square_size);

		SDL_SetRenderDrawColor(game.renderer, 16, 16, 16, 255);
		SDL_RenderClear(game.renderer);
		
		map.render(game.renderer, game.square_size);
		for (size_t i=0; i < players.size(); i++)
			players[i].render(game.renderer, game.square_size);
		
		SDL_RenderPresent(game.renderer);
		SDL_Delay(16);
	}
	return SUCCESS;
}
