#pragma once
#include <iostream>
#include <string>

#include "Player.hpp"

namespace coup{
    class Captain:public Player{
        public:
            Captain(Game &game, const string &name);
            //Function to block foreign_aid
            void block(Player &player);
            Player *StolenPLayer;
            // Function to steal from player
            void steal(Player &player);
    };
}