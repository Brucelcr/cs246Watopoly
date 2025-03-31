#ifndef Square_H  
#define Square_H
#include "player.h"
#include "property.h"
#include <string>

using namespace std;

class Square {
    public: 
        Square(bool, Property);
        Square(string, bool);
        int calculateRent(vector<Player> players);
        string getName();
        string getPlayers();
        Property getProperty();
        string landOn(); // Guys, what does this function do, I don't remember???
    private:
        string players[6];
        bool isProperty;
        Property building;
};

#endif
