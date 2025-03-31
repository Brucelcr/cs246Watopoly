#ifndef Square_H  
#define Square_H
#include "property.h"
#include <string>

using namespace std;

class Square {
    public: 
        Square(string, bool, Property);
        string getName();
        string getPlayers();
        Property getProperty();
        string landOn(); // Guys, what does this function do, I don't remember???
    private:
        string name;
        string players[6];
        Property building;
        bool isProperty;
};

#endif
