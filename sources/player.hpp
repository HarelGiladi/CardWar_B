#ifndef P
#define P



#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "card.hpp"
using namespace std;

namespace ariel{
    class Player{
        private:
        std::string name;
        int cardsTaken = 0;
        int winnings = 0;
        vector<Card> cStack;   
        

        public:
        Player();
        Player(string name);
        std::string getName()const;
        int stacksize();    
        int cardesTaken();  
        int getWinnings();
        void increaseWinnings();
        void increaseCradsTaken();
        void increaseCardsTakenDraw();
        void increaseCardsTakenByOne();
        void addCardToStack(Card card);
        Card playCard();
    };
}

#endif 

