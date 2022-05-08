#include "Game.hpp"
using namespace std;
using namespace coup;
constexpr int Max_Players = 6;

//Constructor
Game::Game(){
    //creating new vector with size of 6 (MAX PLAYERS)
    this->gamePlayers = new vector<Player*>[Max_Players];
    this->currTurn =0;
}

//Distractor
Game::~Game(){
    // delete the players vector
    delete[] this->gamePlayers;
}

void Game::addPlayer(Player *player){
    if(this->gamePlayers->size() > 5){
        throw invalid_argument("Game allready have max players!");
    }
    this->gamePlayers->push_back(player);
    player->turnPos = this->gamePlayers->size();
}

void Game::revivePlayer(Player *player){
    this->gamePlayers->insert(this->gamePlayers->begin()+(player->turnPos -1),player);
}

bool Game::isPlayerTurn(const Player &player){
    if(this->gamePlayers->at(this->currTurn) != &player){return false;}
    else{return true;}
}

void Game::updateTurn(){
    if(this->currTurn == this->gamePlayers->size() -1){currTurn = 0;}
    else{this->currTurn++;}
}

void Game::removePLayer(Player &player){
    // check if the player is in the game if so remove him
    for(unsigned int i=0; i< this->gamePlayers->size();i++){
        if(this->gamePlayers->at(i) == &player){
            this->gamePlayers->erase(this->gamePlayers->begin()+ i);
            break;
        }
    }
    throw invalid_argument("Player cannot be deleted, the player not in the game allready");
}

vector<string> Game::players(){
    vector<string> temp;
    // copy the players name (currently in game) and return new vector
    for(unsigned int i=0; i< this->gamePlayers->size();i++){
        if(this->gamePlayers->at(i)->isAlive == true){
            temp.push_back(this->gamePlayers->at(i)->Name);
        }
    }
    return temp;
}

string Game::turn(){
    // return the name of the player with the turn
    return this->gamePlayers->at(currTurn)->Name;
}

string Game::winner(){
    if(this->gamePlayers->size() == 1){
        return this->gamePlayers->at(0)->Name;
    }
    throw runtime_error("No one won the game yet!");
}