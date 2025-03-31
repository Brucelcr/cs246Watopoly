#include "game.h"
#include "player.h"
#include <iostream>
#include <fstream>
using namespace std;



bool isNum(const string &s) {
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return !s.empty();
}


Game::Game() : currentPlayerIndex(0), gameOver(false){
    cout << "Object created. CPL = 0, game not over" << endl;
}

Game::~Game(){
    cout << "Object Destroyed" << endl;
}

void Game::initGame() {
    int numPlayers;
    cout << "Enter number of players (2-6): ";
    cin >> numPlayers;
    while (numPlayers < 2 || numPlayers > 6) {
        cout << "Invalid number. Please enter a number between 2 and 6: ";
        cin >> numPlayers;
    }
    
    players.clear();
    
    for (int i = 0; i < numPlayers; ++i) {
        string name;
        cout << "Enter name for player " << (i + 1) << ": ";
        cin >> name;
        players.push_back(make_unique<Player>(name));
    }
    
    currentPlayerIndex = 0;
    gameOver = false;
}

void Game::playTurn() {
    if (gameOver) {
        cout << "The game is over." << endl;
        return;
    }

    Player* current = players[currentPlayerIndex].get();
    cout << "It's " << current->getName() << "'s turn." << endl;

    string command;
    while (true) {
        cout << "Enter command (roll / trade / quit): ";
        cin >> command;

        if (command == "roll") {
            cout << players[currentPlayerIndex]->getName() << "rolled the dice" << endl;

            break;
        }

        else if (command == "trade") {
            string targetName, giveStr, receiveStr;
            cin >> targetName >> giveStr >> receiveStr;

            Player* target = nullptr;
            for (auto& p : players) {
                if (p->getName() == targetName && p.get() != current) {
                    target = p.get();
                    break;
                }
            }

            if (!target) {
                cout << "Trade failed: target player not found." << endl;
                continue;
            }

            bool giveIsMoney = isNum(giveStr);
            bool receiveIsMoney = isNum(receiveStr);

            if (giveIsMoney && receiveIsMoney) {
                cout << "Invalid trade: cannot trade money for money." << endl;
                continue;
            }

            shared_ptr<Property> giveProp = nullptr;
            shared_ptr<Property> receiveProp = nullptr;

            if (giveIsMoney && !receiveIsMoney) {
                int money = stoi(giveStr);
                if (current->getBalance() < money) {
                    cout << "You don't have enough money!" << endl;
                    continue;
                }
                current->pay(target, money);  
                receiveProp = target->stringToProperty(receiveStr);
                if (!receiveProp) continue;
            }

            else if (!giveIsMoney && receiveIsMoney) {
                int money = stoi(receiveStr);
                if (target->getBalance() < money) {
                    cout << target->getName() << " doesn't have enough money!" << endl;
                    continue;
                }
                giveProp = current->stringToProperty(giveStr);
                if (!giveProp) continue;
                target->pay(current, money);
            }

            else {
                giveProp = current->stringToProperty(giveStr);
                receiveProp = target->stringToProperty(receiveStr);
                if (!giveProp || !receiveProp) continue;
            }

            current->trade(*target, giveProp, receiveProp);  
        }

        else if (command == "quit") {
            gameOver = true;
            return;
        }

        else {
            cout << "Unknown command." << endl;
        }
    }

    nextPlayer();
}

bool Game::loadGame(const string &filename){
    cout << "Loading from file: " << filename << endl;
    ifstream inf(filename);
    if(!inf){
        cerr << "file not open" << filename << endl;
        return false;
    }

    inf >> currentPlayerIndex;
    inf >> gameOver;

    inf.close();
    cout << "Game loaded successfully. Current player index: " 
         << currentPlayerIndex << ", Game over: " << (gameOver ? "true" : "false") << endl;
    return true;

}

bool Game::saveGame(const string &filename){
    cout << "Saving game to file: " << filename << endl;
    ofstream outf(filename);
    if(!outf){
        cerr << "not able to write to file" << endl;
        return false;
    }

    outf << currentPlayerIndex << endl;
    outf << gameOver << endl;

    outf.close();
    cout << "Game saved successfully." << endl;
    return true;
}

bool Game :: isGameOver() const{
    return gameOver;
}

void Game::nextPlayer(){
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    cout << "Switching to next player. Now it's " << players[currentPlayerIndex]->getName() << "'s turn." << endl;
}
