#include "property.h"
#include "square.h"
#include <iostream>
#include <string>

Square::Square(string name, bool isProperty, Property building) : name(name), isProperty(isProperty), building(building) {};

Square::Square(string name, bool isProperty) : name(name), isProperty(isProperty), building(Property(0, 0, 0, "None")) {};

string Square::getName() {
    return name;
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