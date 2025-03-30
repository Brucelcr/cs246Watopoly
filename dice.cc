#include "dice.h"
#include <cstdlib> 
#include <ctime>


int Dice::roll() {
    std::srand(std::time(0));
    return (std::rand() % 6) + 1; // range from 1 to 6
} 
