#include "property.h";
#include "square.h";
#include <iostream>;
#include <string>;

Square::Square(string name, bool isProperty) {};

string Square::getName(int index) {
    return name[index];
}

string Square::getPlayers() {
    string out = "";
    for (string player : players) { // Note: I intend for nonactive players to be indicated by a space (" ")
        out = out + player;
    }
    return out;
}

property Square::getProperty() {
    property building;
    // I dunno
    return building
}

string Square::landOn() {
    cout << "???" << endl;
    return "???";
}