#include "Captain.hpp"
#include <algorithm>

using namespace coup;

Captain::Captain(Game &game, const string &name):Player(game,name,"Captain"){

}

void Captain::block(Player &player){
    if(player.lastAction != "steal"){
        throw std::invalid_argument("Can block only steal");
    }
    // check if the stolen player and the stealing player still alive
    if(game->lastStolen->isAlive && player.isAlive){
        player.money-=2;
        game->lastStolen->money +=2;
        game->lastStolen = NULL;
    }
}

void Captain::steal(Player &player){
    if(this->game->players().size() == 1){
        throw std::runtime_error("Cant play with 1 player!");
    }
    if(this->game->isPlayerTurn(*this)){
        this->game->gameRuning = true;
        if(player.isAlive){
            this->money += min(2,player.money);
            player.money -= min(2,player.money);
            this->stolenCoins = min(2,player.money);
            this->game->lastStolen = &player;
            this->lastAction = "steal";
            this->game->updateTurn();
        }
        else{
            throw std::invalid_argument("Cant steal player not in the game!");
        }
    }
    else{
        throw std::invalid_argument("Not your turn");
    }
}