#include "wd_test.h"

int main()
{
	SDL_Window	*window; 
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "error initializing SDL: %s\n", SDL_GetError());
		return (EXIT_FAILURE);
	}
	window = SDL_CreateWindow("Window",
						SDL_WINDOWPOS_CENTERED,
						SDL_WINDOWPOS_CENTERED,
						640, 480,
						SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_FULLSCREEN_DESKTOP);
	if (NULL == window)
	{
		fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
		return EXIT_FAILURE;
	}
	while (1)
		;
    SDL_DestroyWindow(window);
	SDL_Quit();
	return (EXIT_SUCCESS);
}
