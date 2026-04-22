#include "main_server.hpp"

int main()
{
    Game			game;
    Map				map;
	vector<Player>	players;
	Player			tmp_player;

    if (!game.init(800, 600)) return FAILURE;
    map.init(800, 600);

	tmp_player.init(0, 400, 400);
	players.push_back

    while (game.is_running)
    {
        game.handle_events(); 
        
        localPlayer.key_move(game.key_table, game.screen_width, game.screen_height);
        game.key_hook();

        SDL_SetRenderDrawColor(game.renderer, 16, 16, 16, 255);
        SDL_RenderClear(game.renderer);
        
        map.render(game.renderer, game.square_size);
		for (size_t i=0; players[i]; i++)
        	players.render(game.renderer, game.square_size);
        
        SDL_RenderPresent(game.renderer);
        SDL_Delay(16);
    }
    return SUCCESS;
}
