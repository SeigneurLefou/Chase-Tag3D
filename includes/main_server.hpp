#ifndef MAIN_SERVER_HPP
#define MAIN_SERVER_HPP

#include "game.hpp"
#include "player.hpp"
#include "map.hpp"
#include "server.hpp"
#include "utils.hpp"

bool	sv_main(unordered_map<int, Player> &players, mutex &p_mutex);

#endif
