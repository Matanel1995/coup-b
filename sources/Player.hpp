//#ifdef PLAYER_H
//#define PLAYER_H
#pragma once

#include <iostream>
#include <string>

#include "Game.hpp"

using namespace std;
namespace coup{
    class Game;
    class Player{
        public:
            Game *game;
            Player(Game &game, const string & name, const string role);
            int money;
            string Name;
            string Prole;
            string lastAction;
            int turnPos;
            bool isAlive;
            //Function to return the role of the player
            string role();
            //Virtual function the the income becouse each role have different income.
            virtual void income();
            void foreign_aid();
            //Function to return the number of coins 
            int coins();
            //Function to kill other player
            void coup(Player& player);
    };
}
//#endif