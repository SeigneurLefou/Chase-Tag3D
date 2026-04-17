#include "wd_test.hpp"

bool	init_game(t_game *game)
{
	game->screen_width = 800;
	game->screen_height = 800;
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("SDL_Init : %s", SDL_GetError());
		return (EXIT_FAILURE);
	}
	game->window = SDL_CreateWindow(
		"Hello Window", game->screen_width, game->screen_height, 0
	);
	if (!game->window)
	{
		SDL_Log("SDL_CreateWindow : %s", SDL_GetError());
		return (EXIT_FAILURE);
	}
	game->renderer = SDL_CreateRenderer(game->window, NULL);
	if (!game->renderer)
	{
		SDL_Log("SDL_CreateRenderer : %s", SDL_GetError());
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	render_map(t_game game, vector<string> map)
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
		cout << "[";
		square.y = y * square_size;
		for (size_t x = 0; x < game.map_width; x++)
		{
			square.x = x * square_size;
			switch (map[y][x])
			{
				case 1:
					SDL_SetRenderDrawColor(game.renderer, 200, 200, 200, 255);
					cout << "1";
					break;
				case 2:
					SDL_SetRenderDrawColor(game.renderer, 200, 16, 16, 255);
					cout << "2";
					break;
				default:
					SDL_SetRenderDrawColor(game.renderer, 16, 16, 16, 255);
					cout << "0";
			}
			SDL_RenderFillRect(game.renderer, &square);
		}
		cout << "]" << endl;
	}
}

int main()
{
	bool		is_running;
	SDL_Event	event;
	t_game		game;
	vector<string>	map;
	string			line;
	char manual_map[7][7] = {
		{0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 0, 1, 1, 0},
		{0, 1, 0, 0, 0, 1, 0},
		{0, 0, 0, 2, 0, 0, 0},
		{0, 1, 0, 0, 0, 1, 0},
		{0, 1, 1, 0, 1, 1, 0},
		{0, 0, 0, 0, 0, 0, 0},
	};

	if (init_game(&game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	game.map_width = 7;
	game.map_height = 7;
	for (size_t y = 0; y < game.map_height; y++)
	{
		for (size_t x = 0; x < game.map_width; x++)
		{
			line.push_back(manual_map[y][x]);
		}
		map.push_back(line);
		line.clear();
	}
	is_running = true;
	while (is_running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT)
				is_running = false;
		}
		SDL_SetRenderDrawColor(game.renderer, 16, 16, 16, 255);
		SDL_RenderClear(game.renderer);
		render_map(game, map);
		SDL_RenderPresent(game.renderer);
		SDL_Delay(16);
	}
	SDL_DestroyRenderer(game.renderer);
	SDL_DestroyWindow(game.window);
	SDL_Quit();
	return (EXIT_SUCCESS);
}
