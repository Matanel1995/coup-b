#include "Game.hpp"
using namespace std;
using namespace coup;
constexpr int Max_Players = 6;

//Constructor
Game::Game(){
    //creating new vector with size of 6 (MAX PLAYERS)
    this->gamePlayers = new vector<Player*>[Max_Players];
    this->currTurn =0;
    this->gameRuning = false;
    this->lastForAid = NULL;
    this->lastKilled = NULL;
    this->lastStolen = NULL;
}

//Distractor
Game::~Game(){
    // delete the players vector
    delete[] this->gamePlayers;
}

void Game::addPlayer(Player *player)const{
    if(this->gameRuning){// == true
        throw std::runtime_error("Game allready started!");
    }
    if(this->gamePlayers->size() >= Max_Players){
        throw invalid_argument("Game allready have max players!");
    }
    this->gamePlayers->push_back(player);
    player->turnPos = this->gamePlayers->size();
}

void Game::revivePlayer(Player *player)const{
    this->gamePlayers->insert(this->gamePlayers->begin()+(player->turnPos -1),player);
}

bool Game::isPlayerTurn(const Player &player)const{
    // if(this->gamePlayers->at(this->currTurn) != &player){return false;}
    // else{return true;}
    if(player.isAlive){//== true
        return(this->gamePlayers->at(this->currTurn % this->gamePlayers->size()) == &player);
    }
    throw std::invalid_argument("Player no longer in game");
}

void Game::updateTurn(){
    while (true){
        this->currTurn++;
        if(this->gamePlayers->at(this->currTurn % this->gamePlayers->size())->isAlive){
            break;
        }
    }
}

void Game::removePLayer(Player &player)const{
    // check if the player is in the game if so remove him
    for(unsigned int i=0; i< this->gamePlayers->size();i++){
        if(this->gamePlayers->at(i) == &player){
            this->gamePlayers->erase(this->gamePlayers->begin()+ i);
            break;
        }
    }
    throw invalid_argument("Player cannot be deleted, the player not in the game allready");
}

vector<string> Game::players()const{
    vector<string> temp;
    // copy the players name (currently in game) and return new vector
    for(unsigned int i=0; i< this->gamePlayers->size();i++){
        if(this->gamePlayers->at(i)->isAlive){ // == true
            temp.push_back(this->gamePlayers->at(i)->Name);
        }
    }
    return temp;
}

string Game::turn()const{
    // return the name of the player with the turn
    return this->gamePlayers->at(currTurn)->Name;
}

string Game::winner()const{
    if(!this->gameRuning){  //== false
        throw std::runtime_error("Game not started yet!");
    }
    int counter=0;
    Player* winner = NULL;
    for(unsigned int i=0; i< this->gamePlayers->size();i++){
        if(this->gamePlayers->at(i)->isAlive){//== true
            counter++;
            winner = this->gamePlayers->at(i);
        }
    }
    if(counter == 1){
        return winner->Name;
    }
    throw runtime_error("No one won the game yet!");
}