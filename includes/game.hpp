#ifndef GAME_HPP
# define GAME_HPP

# include "utils.hpp"

class Game
{
	public:
		SDL_Window		*window;
		SDL_Renderer	*renderer;
		size_t			map_width;
		size_t			map_height;
		size_t			screen_width;
		size_t			screen_height;
		bool			key_table[SDL_SCANCODE_COUNT];
		bool			is_running;
		bool	init(size_t sw, size_t sh);
		void	key_hook();
};

bool	Game::init(size_t sw, size_t sh)
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
		"Hello Window", sw, sh, 0
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

#endif
