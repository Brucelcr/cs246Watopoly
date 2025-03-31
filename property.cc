#include "property.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Property::Property(string name, int cost, int impCost, int tuition[6], string block, int numInSet) : name(name), mortgaged(false), 
owner(" "), improvements(0), cost(cost), impCost(impCost), tuition(tuition), block(block), numInSet(numInSet) {};

string Property::getName() const {
    return name;
}

void Property::setOwner(string newOwner) {
    owner = newOwner;
}

string Property::getOwner() const {
    return owner;
}

bool Property::isMortgaged() const {
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

int Property::getImprovements() const {
    return improvements;
}

int Property::getImprovementCost() const {
    return impCost;
}

int Property::getCost() const {
    return cost;
}

int* Property::getTuition() const {
    return tuition;
}

bool Property::operator==(const Property& other) const {
    return (name == other.name);
}

string Property::getBlock() const {
    return block;
}

int Property::getNumInSet() const {
    return numInSet;
}
