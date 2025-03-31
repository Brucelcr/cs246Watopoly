#include "property.h"
#include <iostream>
#include <string>

using namespace std;

Property::Property(int cost, int tuition[6], string block) : cost(cost), tuition(tuition), 
block(block), mortgaged(false), owner(" "), improvements(0) {};

int Property::calculateRent() {
    if (block != "None", "Residences", "Gym") {
        return tuition[improvements];
    }
    return 0;
}

void Property::setOwner(string newOwner) {
    owner = newOwner;
}

string Property::getOwner() {
    return owner;
}

bool Property::isMortgaged() {
    return mortgaged;
}

void Property::mortgage() {
    if (mortgaged) {
        cout << "Property is already mortgaged." << endl;
        return;
    }
    mortgaged = true;
}

void Property::unmortgage() {
    if (!mortgaged) {
        cout << "Property isn't mortgaged." << endl;
        return;
    }
    mortgaged = false;
}

int Property::getImprovements() {
    return improvements;
}

