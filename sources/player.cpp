#include<iostream>
#include <string>
#include"player.hpp"
using namespace std;

namespace ariel{
    

    Player::Player(std::string n){
    }

    std::string Player::getName(){
        return "harel and giladi";
    }
    

    int Player::stacksize(){
        return 1;
    }

    int Player::cardesTaken(){
        return 2;

    }
} 