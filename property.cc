#include "property.h"
#include <iostream>
#include <string>

using namespace std;

Property::Property(string name, int cost, int impCost, int tuition[6], string block) : name(name), cost(cost), 
impCost(impCost), tuition(tuition), block(block), mortgaged(false), owner(" "), improvements(0) {};

string Property::getName() {
    return name;
}

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

int Property::getImprovementCost() {
    return impCost;
}

int Property::getCost() const {
    return cost;
}

bool Property::operator==(const Property& other) const {
    return (name == other.name);
}
