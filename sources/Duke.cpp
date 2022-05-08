#include "Duke.hpp"

using namespace coup;

Duke::Duke(Game &game, const string &name):Player(game,name,"Duke") {

}

void Duke::tax(){
    if(this->game->players().size() == 1){
        throw std::runtime_error("Cant play with 1 player!");
    }
    if(this->game->isPlayerTurn(*this)){
        this->game->gameRuning = true;
        this->money+=3  ;
        this->game->updateTurn();
    }
    else{
        throw invalid_argument("Not your turn!");
    }
}

void Duke::block(Player &player){
    // if its the duke turn and the player last move was foreign_aid we can block
    if(player.lastAction == "foreign_aid"){
        player.money -=2;
    }
    else{
        throw runtime_error("Last action was not foreign_aid!");
    }
}