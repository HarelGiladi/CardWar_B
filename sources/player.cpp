#include "player.hpp"
#include <string>
#include <exception>
#include <vector>

using namespace std;
using namespace ariel;

    Player::Player(){this->name = "harel is eating shawarma"; }
    
    Player::Player(string name_){this->name=name_;}

    std::string Player::getName()const{return this->name;}
    
    int Player::cardesTaken(){return this->cardsTaken;}

    int Player::getWinnings(){return this->winnings;}

    void Player::increaseCradsTaken(){cardsTaken+=2;}

    void Player::increaseCardsTakenDraw(){cardsTaken+=4;   }

    void Player::increaseWinnings(){winnings++;}

    void Player::increaseCardsTakenByOne(){this->cardsTaken++;}

    void Player::addCardToStack(Card card){this->cStack.push_back(card);}

    Card Player::playCard(){
        Card temp = cStack.back();
        cStack.pop_back();
        return temp;
    }

    int Player::stacksize(){
        int temp = cStack.size();
        if (temp<=52 && temp>=0){return this->cStack.size();}
        else{throw std::runtime_error("ERROR- cStack size invalid");}   
    }


    