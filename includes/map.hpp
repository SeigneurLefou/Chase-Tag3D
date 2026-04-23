#ifndef MAP_HPP
#define MAP_HPP

#include "utils.hpp"

class Map 
{
    public:
        vector<string> data;
        int width, height;

		void	init(int w, int h);
        void	render(SDL_Renderer *renderer, int square_size);
};

#endif
