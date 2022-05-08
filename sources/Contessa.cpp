#include "Contessa.hpp"
#include "Assassin.hpp"

using namespace coup;

Contessa::Contessa(Game &game, const string &name):Player(game,name,"Contessa"){

}

void Contessa::block(Player &player){
    if(player.lastAction == "coup" && player.isAlive == true){
        game->lastKilled->isAlive = true;
        game->lastKilled = NULL;
    }
    else{
        throw std::invalid_argument("Can block only coup");
    }
}