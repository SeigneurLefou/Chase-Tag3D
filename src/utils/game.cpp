#include "game.hpp"

bool	Game::init(Map &map, int w, int h)
{
	width = w;
	height = h;
	square_size = min(w, h) / min(map.width, map.height);
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("SDL_Init : %s", SDL_GetError());
		return (FAILURE);
	}
	window = SDL_CreateWindow(
		"Window", w, h, 0
	);
	if (!window)
	{
		SDL_Log("SDL_CreateWindow : %s", SDL_GetError());
		return (FAILURE);
	}
	renderer = SDL_CreateRenderer(window, NULL);
	if (!renderer)
	{
		SDL_Log("SDL_CreateRenderer : %s", SDL_GetError());
		return (FAILURE);
	}
	is_running = true;
	return (SUCCESS);
}

void Game::handle_events() // Player &player)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_EVENT_QUIT) is_running = false;
		if (event.key.scancode == SDL_SCANCODE_ESCAPE) is_running = false;
/*
		if (event.type == SDL_EVENT_KEY_DOWN)
			player.key_table[event.key.scancode] = true;
		if (event.type == SDL_EVENT_KEY_UP)
			player.key_table[event.key.scancode] = false;
*/
	}
}
