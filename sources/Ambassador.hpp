#pragma once
#include <string>
#include <iostream>

#include "Player.hpp"

using namespace std;

namespace coup{
    class Ambassador:public Player{
        public:
            Ambassador(Game &game, const string &name);
            //Function to tranfer money between 2 players
            void transfer(Player &player1, Player &player2);
            //Function to block foreign_aid
            void block(Player &player);
    };
}