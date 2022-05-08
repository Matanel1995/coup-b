#include "Contessa.hpp"
#include "Assassin.hpp"

using namespace coup;

Contessa::Contessa(Game &game, const string &name):Player(game,name,"Contessa"){

}

void Contessa::block(Player &player){
    if(player.lastAction == "coup" && player.isAlive){
        if(player.role() == "Assassin" && player.coupWithSeverCoins){
            throw std::invalid_argument("Cant block 7 coins coup by assassins!");
        }
        game->lastKilled->isAlive = true;
        game->lastKilled = NULL;
    }
    else{
        throw std::invalid_argument("Can block only coup");
    }
}