#include "wd_test.hpp"

int main()
{
	bool		is_running;
	SDL_Window*	window;
	SDL_Renderer*	renderer;
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
	renderer = SDL_CreateRenderer(window, NULL);
	if (!renderer)
	{
		perror("renderer");
		return (EXIT_FAILURE);
	}
	is_running = true;
	while (is_running)
	{
		std::cout << "loop" << std::endl;
		while (SDL_PollEvent(&event))
		{
			std::cout << "event loop" << std::endl;
			if (event.type == SDL_EVENT_QUIT)
				is_running = false;
		}
	}
		std::cout << "loop" << std::endl;
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (EXIT_SUCCESS);
}
