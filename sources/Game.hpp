//#ifdef GAME_H
//#define GAME_H
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"
#include <stdexcept>

using namespace std;
namespace coup{
    class Player;
    class Game{
        public:
        vector<Player*>* gamePlayers;
        unsigned int currTurn;
        bool gameRuning;
        // Players pointers for each operation
        Player* lastStolen;
        Player* lastKilled;
        Player* lastForAid;
        // constructor and distractor
        Game();
        ~Game();
        // function to return all players names
        vector<string> players()const;
        //Function to add new player to the game
        void addPlayer(Player *player)const;
        //Function to revive player into a role
        void revivePlayer(Player *player)const;
        //
        bool isPlayerTurn(const Player &player)const;
        //Function to remove player from the Game
        void removePLayer(Player &player)const;
        //function to update the curr turn
        void updateTurn();
        // Function to return player that it is his turn name  
        string turn()const;
        // Function to return the name of the winner in this game
        string winner()const;
    };
}
//#endif