#ifndef GAME_HPP
# define GAME_HPP

# include "utils.hpp"
# include "player.hpp"
# include "map.hpp"

class Game
{
	public:
		SDL_Window		*window;
		SDL_Renderer	*renderer;
		int				width;
		int				height;
		int				square_size;
		bool			is_running;
		bool			init(Map &map, int sw, int sh);
		void			handle_events(); // Player &player);
};

#endif
