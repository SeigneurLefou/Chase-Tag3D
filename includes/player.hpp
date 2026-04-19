#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "utils.hpp"
# include "game.hpp"

class Player
{
	public:
		int		posx;
		int		posy;
		bool	init(int px, int py);
		bool	render(Game game);
		void	key_move(Game game, vector<string> map);
};

bool	Player::init(int px, int py)
{
	posx = px;
	posy = py;
	return (SUCCESS);
}

bool	Player::render(Game game)
{
	SDL_FRect	square;

	square.w = game.square_size;
	square.h = game.square_size;
	square.x = posx + game.center_offset;
	square.y = posy + game.center_offset;
	SDL_SetRenderDrawColor(game.renderer, 200, 16, 16, 255);
	SDL_RenderFillRect(game.renderer, &square);
	return (SUCCESS);
}

void	Player::key_move(Game game, vector<string> map)
{
    int	next_x;
    int	next_y;

	next_x = posx;
	next_y = posy;
    if (game.key_table[SDL_SCANCODE_A])
		next_x = max(next_x - SPEED, 0);
    if (game.key_table[SDL_SCANCODE_D])
		next_x = min(next_x + SPEED, game.screen_width - game.square_size);
    if (game.key_table[SDL_SCANCODE_W])
		next_y = max(next_y - SPEED, 0);
    if (game.key_table[SDL_SCANCODE_S])
		next_y = min(next_y + SPEED, game.screen_height - game.square_size);
	cout << "X : " << next_x << ", Y : " << next_y << endl;
	posx = next_x;
	posy = next_y;
}

#endif
