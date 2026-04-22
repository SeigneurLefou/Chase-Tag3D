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
		void			handle_events()
};

#endif
