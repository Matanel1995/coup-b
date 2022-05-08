#include "Ambassador.hpp"
#include "Captain.hpp"

using namespace coup;

Ambassador::Ambassador(Game &game, const string &name):Player(game,name,"Ambassador"){

}

void Ambassador::transfer(Player &player1, Player &player2){
    if(this->game->players().size() == 1){
        throw std::runtime_error("Cant play with 1 player!");
    }
    if(this->game->isPlayerTurn(*this)){
        this->game->gameRuning = true;
        if(player1.isAlive && player2.isAlive){
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
    if(this->game->players().size() == 1){
        throw std::runtime_error("Cant play with 1 player!");
    }
    if(player.lastAction == "steal"){
        //return the money to the stolen player
        cout << player.coins() << endl;
        this->game->lastStolen->money += player.stolenCoins;
        player.money-= player.stolenCoins;
        cout << player.coins() << endl;
        this->game->lastStolen =NULL;
    }
    
}