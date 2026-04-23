#include "map.hpp"

void	Map::init(int w, int h)
{
	string	line;

	width = w;
	height = h;
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			line.push_back(0);
		}
		data.push_back(line);
		line.clear();
	}
}

void	Map::render(SDL_Renderer *renderer, int square_size)
{
	SDL_FRect	square;

	square.x = 0;
	square.y = 0;
	square.w = square_size;
	square.h = square_size;
	for (int y = 0; y < height; y++)
	{
		square.y = y * square_size;
		for (int x = 0; x < width; x++)
		{
			square.x = x * square_size;
			switch (data[y][x])
			{
				case 1:
					SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
					break;
				default:
					SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
			}
			SDL_RenderFillRect(renderer, &square);
		}
	}
}
