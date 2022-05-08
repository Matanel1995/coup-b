#pragma once
#include <iostream>

#include "Player.hpp"

using namespace std;

namespace coup{
    class Assassin:public Player{
        public:
            Assassin(Game &game, const string &name);
            Player *removerdPlayer;
            unsigned int removePlayerIndex;
    };
}