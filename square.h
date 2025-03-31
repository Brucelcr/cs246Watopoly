#ifndef Square_H  
#define Square_H
#include "player.h"
#include "property.h"
#include <vector>
#include <string>

using namespace std;

class Square {
    public: 
        Square(bool, Property);
        Square(string, bool);
        int calculateRent(vector<Player> players);
        string getName();
        string getPlayers();
        void setPlayers(string counter);
        Property getProperty();
        string landOn();
    private:
        vector <string> players;
        bool isProperty;
        Property building;
};

#endif
