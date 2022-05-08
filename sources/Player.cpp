#include "Player.hpp"
//#include "Assassin.hpp"

constexpr int CoupRegCost = 7;
constexpr int CoupAssCost = 3;

using namespace coup;


Player::Player(Game &game, const string &name, const string role){
    this->money = 0;
    this->Prole = role;
    this->Name = name;
    this->lastAction = "";
    this->game = &game;
    this->isAlive = true;
    // after init all parameters i will add the player to the game 
    this->game->addPlayer(this);

}
string Player::role(){
    return this->Prole;
}

void Player::income(){
    if(this->game->isPlayerTurn(*this)){
        this->money++;
        this->lastAction = "income";
        //cout << this->game->currTurn << endl;
        this->game->updateTurn();
    }
    else{
        throw runtime_error("Not your turn!");
    }
}

void Player::foreign_aid(){
    if(this->game->isPlayerTurn(*this)){
        this->money+=2;
        this->lastAction = "foreign_aid";
        //cout << this->game->currTurn << endl;
        this->game->updateTurn();
    }
    else{
        throw runtime_error("Not your turn!");
    }
}

int Player::coins(){
    return this->money;
}

void Player::coup(Player & player){
    if(this->game->isPlayerTurn(*this)){
        if(player.isAlive == true){
            if(this->role() == "Assassin"){ // can coup with 3 coins!
                if(this->coins() >= CoupAssCost){
                    this->money -=CoupAssCost;
                    player.isAlive = false;
                    this->lastAction = "coup";
                    this->game->lastKilled = &player;
                    this->game->updateTurn();
                }
                else{
                    throw std::invalid_argument("Assassins need at least 3 coins to coup!");
                }
            }
            else{ // need 7 coins to coup
                if(this->coins() >= CoupRegCost){
                    this->money-= CoupRegCost;
                    player.isAlive = false;
                    this->lastAction = "coup";
                    this->game->lastKilled = &player;
                    this->game->updateTurn();
                }
                else{
                    throw std::invalid_argument("Player need to have a least 7 coins to coup!");
                }
            }
        }
        else{
            throw std::invalid_argument("Cant coup player, player not in the game!");
        }
    }
    else{
        throw std::invalid_argument("Not your turn");
    }

}
