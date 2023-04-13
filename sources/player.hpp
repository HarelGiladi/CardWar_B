#ifndef P
#define P

#include <string>
#include <stdio.h>

namespace ariel{



class Player{
    private:

        std::string name;
        //we need it for part 2
        // int stacksize;
        // int cardtaken;

    public:

        
        Player(std::string name);

        std::string getName();

        int stacksize();

        int cardesTaken();   

};
}
#endif 