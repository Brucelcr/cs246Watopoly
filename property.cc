#include "property.h"
#include <iostream>
#include <string>

using namespace std;

Property::Property() : mortgaged(false), owner(" "), improvements(0) {};

int Property::calculateRent() {
    // uhh do value calcs, I'll set up values in a sec.
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



