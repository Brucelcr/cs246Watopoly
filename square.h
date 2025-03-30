#define Square_H
#include property.h
#include <string>

using namespace std;

class Square {
    public: 
        Square(string name, bool isProperty);
        string getName();
        string getPlayers();
        // property getProperty(); // I'm not sure how we want to do this actually, how do we want to link properties to their respective square?
        string landOn(); // Guys, what does this function do, I don't remember???
    private:
        string name; // using an array for both lines i.e. COLLECT OSAP
        string players[6];
        bool isProperty;

}