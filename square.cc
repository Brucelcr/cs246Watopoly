#include "player.h"
#include "property.h"
#include "square.h"
#include <iostream>
#include <string>

Square::Square(bool isProperty, Property building) : isProperty(isProperty), building(building) {};

Square::Square(string name, bool isProperty) : isProperty(isProperty), building(Property(name, 0, 0, 0, "None", 0)) {};

Player stringToPlayer(string c, vector<Player> players) {
    for(const Player &p : players) {
        if (p.getName() ==  c) {
            return p;
        }
    }
    throw runtime_error("No matching player found for: " + c);
}

int Square::calculateRent(vector<Player> players) {
    if (building.getBlock() != "None" && building.getBlock() != "Residences" &&  building.getBlock() !="Gym") {
        if (building.getOwner() != " ") {
            if (stringToPlayer(building.getOwner(), players).hasMonopoly(building.getBlock()) && building.getImprovements() == 0) {
                return building.getTuition()[building.getImprovements()] * 2;
            }
        }
        return building.getTuition()[building.getImprovements()];
    }
    return 0;
}

string Square::getName() {
    return building.getName();
}

string Square::getPlayers() {
    string out = "";
    int size = players.size();
    string white((7-size), ' ');
    for (string player : players) { // Note: I intend for nonactive players to be indicated by a space (" ")
        out = out + player;
    }
    return out + white;
}

void Square::setPlayers(string counter) {
    players.push_back(counter);
}

Property Square::getProperty() {
    return building;
}

string Square::landOn() {
    cout << "???" << endl;
    return "???";
}