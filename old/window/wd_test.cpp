#include "wd_test.hpp"

void	render_game(Game game, Player player, vector<string> map)
{
	int			square_size;
	SDL_FRect	square;

	square.x = 0;
	square.y = 0;
	square.w = game.square_size;
	square.h = game.square_size;
	for (int y = 0; y < game.map_height; y++)
	{
		square.y = y * game.square_size + game.center_offset;
		for (int x = 0; x < game.map_width; x++)
		{
			square.x = x * game.square_size + game.center_offset;
			switch (map[y][x])
			{
				case 1:
					SDL_SetRenderDrawColor(game.renderer, 200, 200, 200, 255);
					break;
				default:
					SDL_SetRenderDrawColor(game.renderer, 16, 16, 16, 255);
			}
			SDL_RenderFillRect(game.renderer, &square);
		}
	}
	player.render(game);
}

int main()
{
	SDL_Event		event;
	vector<string>	map;
	Game			game;
	Player			player;
	string			line;
	char manual_map[7][7] = {
		{0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 0, 1, 1, 0},
		{0, 1, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 1, 0},
		{0, 1, 1, 0, 1, 1, 0},
		{0, 0, 0, 0, 0, 0, 0},
	};

	if (game.init(1000, 1000) == FAILURE)
		return (FAILURE);
	game.map_width = 7;
	game.map_height = 7;
	game.square_size = min(game.screen_height / game.map_height, game.screen_width / game.map_width);
	game.normalize_screen_size();
	game.center_offset = min(game.screen_width - game.map_width * game.square_size, game.screen_height - game.map_height * game.square_size) / 2;
	if (player.init((game.map_width) / 2 * game.square_size, game.map_height / 2 * game.square_size) == FAILURE)
		return (FAILURE);
	for (int y = 0; y < game.map_height; y++)
	{
		for (int x = 0; x < game.map_width; x++)
		{
			line.push_back(manual_map[y][x]);
		}
		map.push_back(line);
		line.clear();
	}
	while (game.is_running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT)
				game.is_running = false;
			if (event.type == SDL_EVENT_KEY_DOWN)
				game.key_table[event.key.scancode] = 1;
			if (event.type == SDL_EVENT_KEY_UP)
				game.key_table[event.key.scancode] = 0;
		}
		player.key_move(game, map);
		game.key_hook();
		SDL_SetRenderDrawColor(game.renderer, 16, 16, 16, 255);
		SDL_RenderClear(game.renderer);
		render_game(game, player, map);
		SDL_RenderPresent(game.renderer);
		SDL_Delay(16);
	}
	SDL_DestroyRenderer(game.renderer);
	SDL_DestroyWindow(game.window);
	SDL_Quit();
	return (SUCCESS);
}
