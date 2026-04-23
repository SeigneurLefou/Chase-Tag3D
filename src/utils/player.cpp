#include "player.hpp"

bool	Player::init(int fd, int px, int py)
{
	id = fd;
	posx = px;
	posy = py;
	memset(key_table, 0, SDL_SCANCODE_COUNT * sizeof(bool));
	return (SUCCESS);
}

bool	Player::render(SDL_Renderer *renderer, int square_size)
{
	SDL_FRect	square;

	square.w = square_size;
	square.h = square_size;
	square.x = posx;
	square.y = posy;
	SDL_SetRenderDrawColor(renderer, 200, 16, 16, 255);
	SDL_RenderFillRect(renderer, &square);
	return (SUCCESS);
}

void	Player::key_move(Map &map, int square_size)
{
	int	next_x;
	int	next_y;

	next_x = posx;
	next_y = posy;
	if (key_table[SDL_SCANCODE_A])
		next_x = max(next_x - SPEED, 0);
	if (key_table[SDL_SCANCODE_D])
		next_x = min(next_x + SPEED, (map.width - 1) * square_size);
	if (key_table[SDL_SCANCODE_W])
		next_y = max(next_y - SPEED, 0);
	if (key_table[SDL_SCANCODE_S])
		next_y = min(next_y + SPEED, (map.height - 1) * square_size);
	posx = next_x;
	posy = next_y;
}
