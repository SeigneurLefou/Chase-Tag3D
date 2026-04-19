#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "utils.hpp"
# include "game.hpp"

class Player
{
	public:
		float	posx;
		float	posy;
		bool	init(float px, float py);
		bool	render(Game game, int square_size);
		void	key_move(Game game, vector<string> map);
};

bool	Player::init(float px, float py)
{
	posx = px;
	posy = py;
	return (SUCCESS);
}

bool	Player::render(Game game, int square_size)
{
	SDL_FRect	square;

	square.w = square_size;
	square.h = square_size;
	square.x = posx * square_size;
	square.y = posy * square_size;
	SDL_SetRenderDrawColor(game.renderer, 200, 16, 16, 255);
	SDL_RenderFillRect(game.renderer, &square);
	return (SUCCESS);
}

void	Player::key_move(Game game, vector<string> map)
{
    float	next_x;
    float	next_y;
	next_x = posx;
	next_y = posy;

    if (game.key_table[SDL_SCANCODE_A])
		next_x -= SPEED;
    if (game.key_table[SDL_SCANCODE_D])
		next_x += SPEED;
    if (game.key_table[SDL_SCANCODE_W])
		next_y -= SPEED;
    if (game.key_table[SDL_SCANCODE_S])
		next_y += SPEED;
    if (next_x >= 0 && next_x < game.map_width - 1 && next_y >= 0 && next_y < game.map_height - 1)
    {
        if (map[(int)next_y][(int)next_x] == 0) 
        {
            posx = next_x;
            posy = next_y;
        }
    }
}

#endif
