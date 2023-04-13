#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
#include <iostream>
#include <stack>
#include <vector>
#include <stdexcept>
#include <string>
#include <random>
#include <algorithm>

using namespace std;
using namespace ariel;

Game::Game(Player &player1_, Player &player2_): pl1(player1_), pl2(player2_){ handOutCards();}

int Game::getRounds(){return this->rounds;}

void Game::increaseRounds(){rounds++;}

void Game::printLastTurn(){cout << gameLog.back() << endl;}

void Game::handOutCards(){
    string spade = "Spades";
    string heart = "Hearts";
    string diamond = "Diamonds";
    string club = "Clubs";

    vector<Card> deck;
    unsigned long i =1 ;
    while( i <= 13){
        deck.push_back(Card(i, spade));
        deck.push_back(Card(i, heart));
        deck.push_back(Card(i, diamond));
        deck.push_back(Card(i, club));
        i++;
    }   
    //random suffle i use stackoverflow
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);
    i =0;
    while(i < 26){pl1.addCardToStack(deck[i]);i++;}
    i =26;
    while(i < 52){pl2.addCardToStack(deck[i]);i++;}

}


int Game::turnResult(Card card1, Card card2){
    if (card1.getValue() == card2.getValue()){ 
        return 0;
    }
    else if (card1.getValue() == 1 && card2.getValue() != 2){    
        return 1;
    }
    else if (card1.getValue() != 2 && card2.getValue() == 1){    
        return -1;
    }
    else if(card1.getValue() > card2.getValue()){    
        return 1;
    }
    else if (card1.getValue() < card2.getValue()){
        return -1;
    }
    else{
        throw std::runtime_error("ERROR- cards compration invalid(check cards code)");
    }
}


void Game::playAll(){
    if (pl1.stacksize() == 0 && pl2.stacksize() == 0){
        throw std::runtime_error("ERROR- no cards left in the deck");
    }
    while(pl1.stacksize() > 0 && pl2.stacksize() > 0){
        playTurn();
    }
    int sum = pl1.stacksize() + pl1.cardesTaken() + pl2.stacksize() + pl2.cardesTaken();
    

}



//i worte this with the help of stackoverflow
void Game::printStats(){
    double winRate = static_cast<double>(pl1.getWinnings()) /getRounds(); 
    cout << pl1.getName() << " Stat are : " << "Win Rate- " << winRate <<"; "
        << "Cards Won- " << pl1.cardesTaken()<< "." << endl;

    winRate = static_cast<double>(pl2.getWinnings()) /getRounds();
    cout << pl2.getName() << " Stat are: " << "Win Rate- " << winRate <<"; "
        << "Cards Won- " << pl2.cardesTaken()<< "." << endl;

    //i used win rate for saving memory
    winRate = static_cast<double>(draws) /getRounds();
    cout << "Draw Rate: "<< winRate << ", Total number of draws: " << draws <<endl;
}

void Game::printLog(){
    unsigned long int i =0;
    while(i < gameLog.size()){
        cout<<gameLog[i]<<endl;
        i++;
    }

}

void Game::printWiner(){
    if (pl1.cardesTaken() > pl2.cardesTaken()){
        cout << pl1.getName()<< " is the winner!!" <<endl;
    }
    else if (pl1.cardesTaken() < pl2.cardesTaken()){
        cout << pl2.getName() << " is the winner!!" <<endl;
    }
    else{cout << "tie!!" << endl; }
}

void Game::playTurn(){
    if (rounds>26){throw std::runtime_error("ERROR- max rounds already played");}
    if (&pl1 == &pl2){throw std::invalid_argument("ERROR- most be two diffrent players");}
    if (pl1.cardesTaken() + pl2.cardesTaken() == 52){throw std::runtime_error("ERROR- all the cards was taken game over");}

    Card cp1= pl1.playCard();
    Card cp2= pl2.playCard();
    int res = turnResult(cp1, cp2);

    string state = pl1.getName()+" played "+ cp1.toString() +"; and  "+
                pl2.getName()+" played "+cp2.toString() + ". ";
    
    if (res == -1){
        pl2.increaseCradsTaken();
        pl2.increaseWinnings();
        increaseRounds();
        gameLog.push_back(state + pl2.getName()+" wins.");
        return;
    }
    else if (res == 1){
        pl1.increaseCradsTaken();
        pl1.increaseWinnings();
        increaseRounds();
        gameLog.push_back(state + pl1.getName()+" wins.");
        return;
    }
    
    else{
        int ties = 0;
        int i =0;
        while(res == 0){
            state = state + ". Draw. ";
            ties++;
            i=0;
            //we only need to check one player becuse in our contions the stack of both of them should be the same in size.
            if (pl1.stacksize() == 0){
                while( i < ties-1){pl1.increaseCradsTaken();pl2.increaseCradsTaken();i++;}
                pl1.increaseCardsTakenByOne();
                pl2.increaseCardsTakenByOne();
                increaseRounds();
                return;
            }
            else if (pl1.stacksize() == 1){
                pl1.playCard();
                pl2.playCard();
                while(i< ties){ pl1.increaseCradsTaken();pl2.increaseCradsTaken();i++;}
                return;
            }

            else if(pl1.stacksize() >= 2 ){
                pl1.playCard();
                pl2.playCard();
            }
            Card cp11= pl1.playCard();
            Card cp22= pl2.playCard();
            res = turnResult(cp11, cp22);
            state = state + pl1.getName()+" played "+ cp11.toString() +"; "+
                pl2.getName()+" played "+cp22.toString();
        }

        draws = draws + ties;
        i=1;
        if (res == 1){
            pl1.increaseCradsTaken();
            while(i <= ties){pl1.increaseCardsTakenDraw();increaseRounds();i++;}
            gameLog.push_back(state+". "+pl1.getName()+" wins.");
            pl1.increaseWinnings();
            return;
        }
        else if (res == -1){
            pl2.increaseCradsTaken();
            while(i <= ties){ pl2.increaseCardsTakenDraw();increaseRounds(); i++; }
            gameLog.push_back(state+". "+pl2.getName()+" wins.");
            pl2.increaseWinnings();
            return;
        }
    }
}