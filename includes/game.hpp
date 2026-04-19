#ifndef GAME_HPP
# define GAME_HPP

# include "utils.hpp"

class Game
{
	public:
		SDL_Window		*window;
		SDL_Renderer	*renderer;
		int				map_width;
		int				map_height;
		int				screen_width;
		int				screen_height;
		int				square_size;
		int				center_offset;
		bool			key_table[SDL_SCANCODE_COUNT];
		bool			is_running;
		bool			init(int sw, int sh);
		void			key_hook();
		bool			resize_window();
		void			normalize_screen_size();
};

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

#endif
