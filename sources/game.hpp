#ifndef G
#define G

#include <iostream>
#include "player.hpp"
#include "card.hpp"

namespace ariel{
    class Game{
        private:
        Player &pl1;
        Player &pl2;
        string winner;
        vector<string> gameLog;
        void handOutCards();
        int draws = 0;
        int rounds = 0;
        
        public:
        Game(Player& player1, Player& player2);    
        int getDraws();
        int getRounds();
        //we need this func for the new rules that 2 beats ace
        int turnResult(Card card1, Card card2);
        void playTurn();
        void printLastTurn();
        void printWiner();
        void printLog();
        void printStats();
        void playAll();
        void increaseRounds();
    };
}
#endif 