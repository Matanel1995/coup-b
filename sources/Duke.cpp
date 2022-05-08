#include "Duke.hpp"

using namespace coup;

Duke::Duke(Game &game, const string &name):Player(game,name,"Duke") {

}

void Duke::tax(){
    if(this->game->isPlayerTurn(*this)){
        this->money+=3  ;
        this->game->updateTurn();
    }
    else{
        throw invalid_argument("Not your turn!");
    }
}

void Duke::block(Player &player){
    // if its the duke turn and the player last move was foreign_aid we can block
    // if(this->game->isPlayerTurn(*this)){
    if(player.lastAction == "foreign_aid"){
        player.money -=2;
    }
    else{
        throw runtime_error("Last action was not foreign_aid!");
    }
    // }
    // else{
    //     throw runtime_error("This is not your turn!");
    // }

}