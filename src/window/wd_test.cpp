#include "wd_test.hpp"

int main()
{
	bool		is_running;
	SDL_Window*	window;
	SDL_Event	event;

	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		return (EXIT_FAILURE);
	}
	window = SDL_CreateWindow(
		"Hello Window", 800, 300,
		0
	);
	if (!window)
	{
		perror("window");
		return (EXIT_FAILURE);
	}
	is_running = true;
	while (is_running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT)
				is_running = false;
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (EXIT_SUCCESS);
}
