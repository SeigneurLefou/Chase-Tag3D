#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "utils.hpp"
# include "game.hpp"

class Player
{
	public:
		int		id;
		int		posx;
		int		posy;
		bool	init(int fd, int px, int py);
		bool	render(Game game);
		void	key_move(Game game, vector<string> map);
};

#endif
