#include "game.h"
#include <iostream>
using namespace std;

int main() {
    Game game;
    
    game.initGame();
    
    while (!game.isGameOver()) {
        game.playTurn();
    }
    
    cout << "Game over. Exiting..." << endl;
    return 0;
}
