#include "Ambassador.hpp"
#include "Captain.hpp"

using namespace coup;

Ambassador::Ambassador(Game &game, const string &name):Player(game,name,"Ambassador"){

}

void Ambassador::transfer(Player &player1, Player &player2){
    if(this->game->isPlayerTurn(*this)){
        if(player1.isAlive == true && player2.isAlive == true){
            if(player1.money > 0){
                player1.money--;
                player2.money++;
                this->game->updateTurn();
            }
            else{
                throw std::invalid_argument("Cant trasfer money player 1 has non!");
            }
        }
        else{
            throw std::invalid_argument("One of the players not in the game!");
        }
    }
    else{
        throw std::invalid_argument("Not your turn!");
    }

}

void Ambassador::block(Player &player){
    
}