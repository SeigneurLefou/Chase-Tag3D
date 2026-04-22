#include "game.hpp"

bool	Game::init(int sw, int sh)
{
	memset(key_table, 0, SDL_SCANCODE_COUNT);
	screen_width = sw;
	screen_height = sh;
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("SDL_Init : %s", SDL_GetError());
		return (FAILURE);
	}
	window = SDL_CreateWindow(
		"Window", sw, sh, 0
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

void	Game::key_hook()
{
	if (key_table[SDL_SCANCODE_ESCAPE])
		is_running = false;
}

void	Game::normalize_screen_size()
{
	screen_width = map_width * square_size;
	screen_height = map_height * square_size;
}

bool	Game::resize_window()
{
	return (SDL_SetWindowSize(window, screen_width, screen_height));
}

void Game::handle_events()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT) is_running = false;
        if (event.type == SDL_EVENT_KEY_DOWN) key_table[event.key.scancode] = true;
        if (event.type == SDL_EVENT_KEY_UP) key_table[event.key.scancode] = false;
    }
}
