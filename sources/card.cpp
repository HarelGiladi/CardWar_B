#include "card.hpp"
#include "string"
using namespace std;
using namespace ariel;

Card::Card(int value, string suit){
    this->value = value;
    this->suit = suit;
}

int Card::getValue(){
    return this->value;
}

string Card::getSuit(){
    return this->suit;
}


string Card::toString(){
    string numericVal = "";

    switch (this->value) {
        case 1:
            numericVal = "Ace";
            break;
        case 11:
            numericVal = "Jack";
            break;
        case 12:
            numericVal = "Queen";
            break;
        case 13:
            numericVal = "King";
            break;
        default:
            numericVal = to_string(this->value);
    
    }
    return numericVal+" of "+this->suit;

    
}

