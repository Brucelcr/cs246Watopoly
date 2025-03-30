#include "game.h"
#include <iostream>
#include <fstream>
using namespace std;

Game::Game() : currentPlayerIndex(0), gameOver(false){
    cout << "Object created. CPL = 0, game not over" << endl;
}

Game::~Game(){
    cout << "Object Destroyed" << endl;
}

void Game::playTurn(){
    if(gameOver){
        cout << "The game is over." << cout;
        return;
    }
    cout << "Processing current player's turn >>>" << endl;

    nextPlayer();

}

bool Game::loadGame(const string &filename){
    cout << "Loading from file: " << f ilename << endl;
    ifstring f(filename);
    if(!f){
        cerr << "file not open" << filename << endl;
        return false;
    }

    f >> currentPlayerIndex;
    f >> gameOver;

    f.close();
    cout << "Game loaded successfully. Current player index: " 
         << currentPlayerIndex << ", Game over: " << (gameOver ? "true" : "false") << endl;
    return true;

}
