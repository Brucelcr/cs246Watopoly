#include "property.h"
#include "square.h"
#include <iostream>
#include <string>

Square::Square(bool isProperty, Property building) : isProperty(isProperty), building(building) {};

Square::Square(string name, bool isProperty) : isProperty(isProperty), building(Property(name, 0, 0, 0, "None")) {};

string Square::getName() {
    return building.getName();
}

string Square::getPlayers() {
    string out = "";
    int size = sizeof(players) / sizeof(players[0]);
    string white((7-size), ' ');
    for (string player : players) { // Note: I intend for nonactive players to be indicated by a space (" ")
        out = out + player;
    }
    return out + white;
}

Property Square::getProperty() {
    return building;
}

string Square::landOn() {
    cout << "???" << endl;
    return "???";
}