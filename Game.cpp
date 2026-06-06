#include "Game.hpp"

Game::Game(std::string title, std::string shortDescription, int popularity){
    this->title = title;
    this->shortDescription = shortDescription;
    this->popularity = popularity;
}
Game::~Game(){};

std::string Game::getTitle(){
    return title;
}
std::string Game::getShortDescription(){
    return shortDescription;
}
int Game::getPopularity(){
    return popularity;
}