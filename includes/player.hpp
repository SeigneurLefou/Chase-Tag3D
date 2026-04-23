#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "utils.hpp"
# include "map.hpp"

class Player
{
	public:
		int		id;
		int		posx;
		int		posy;
		bool	key_table[SDL_SCANCODE_COUNT];
		bool	init(int fd, int px, int py);
		bool	render(SDL_Renderer *renderer, int square_size);
		void	key_move(Map &map, int square_size);
};

#endif
