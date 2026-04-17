#ifndef WD_TEST_H
# define WD_TEST_H

# include <SDL3/SDL.h>
# include <SDL3/SDL_main.h>
# include <SDL3/SDL_timer.h>
# include <iostream>
# include <vector>

using namespace std;

typedef struct s_game
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	size_t			map_width;
	size_t			map_height;
	size_t			screen_width;
	size_t			screen_height;
}			t_game;

bool	init_game(t_game *game);
void	render_map(t_game game, vector<string> map);

#endif
