#ifndef C
#define C
#include <iostream>
using namespace std;

namespace ariel{
    class Card{
        private:
        int value;
        string suit;


        public:
        Card(int value, string shape);
        int getValue();
        string getSuit();
        string toString();
    };
}
#endif 