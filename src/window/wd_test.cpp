#include "wd_test.hpp"

void	render_game(Game game, Player player, vector<string> map)
{
	int			square_size;
	SDL_FRect	square;

	square_size = min(game.screen_height / game.map_height, game.screen_width / game.map_width);
	square.x = 0;
	square.y = 0;
	square.w = square_size;
	square.h = square_size;
	for (size_t y = 0; y < game.map_height; y++)
	{
		square.y = y * square_size;
		for (size_t x = 0; x < game.map_width; x++)
		{
			square.x = x * square_size;
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
	player.render(game, square_size);
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

	if (game.init(800, 800) == FAILURE)
		return (FAILURE);
	game.map_width = 7;
	game.map_height = 7;
	if (player.init(game.map_width / 2, game.map_height / 2) == FAILURE)
		return (FAILURE);
	for (size_t y = 0; y < game.map_height; y++)
	{
		for (size_t x = 0; x < game.map_width; x++)
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
			{
				cout << "Key : " << event.key.scancode << endl;
				game.key_table[event.key.scancode] = 1;
			}
			if (event.type == SDL_EVENT_KEY_UP)
			{
				cout << "Key : " << event.key.scancode << endl;
				game.key_table[event.key.scancode] = 0;
			}
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
