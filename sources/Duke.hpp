#pragma once
#include <iostream>
#include <string>

#include "Player.hpp"

using namespace std;

namespace coup{
    class Duke:public Player{
        public:
            Duke(Game &game, const string &name);
            //Function to collect taxes
            void tax();
            //Function to block foreign_aid
            void block(Player &player);
    };
}