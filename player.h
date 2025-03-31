#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "property.h"
#include "dice.h"
#include "board.h"

class Player {
private:
    std::string name;
    int balance;
    int position;
    bool inTimsLine;
    int cups;
    std::vector<Property*> properties;
    void removeProperty(Property* prop);
    Board* gameboard;

public:
    Player(std::string name, int startBalance, Board* gameboard);

    int getPosition() const;
    std::string getName()const;
    // void showAssets();
    bool isinTimsLine()const;

    void move(int steps);
    void pay(Player* payee, int amount);
    void paySchool(int amount);
    void receive(int amount);

    // roll a dice twice and move steps
    void rollDice();

    void declareBankruptcy();
    void trade(Player& other, Property* give, Property* receive);
    void buyImprovement(Property* property);
    void sellImprovement(Property* property);
    void mortgage(Property* property);
    void unmortgage(Property* property);

    void addCup();
    void removeCup();

    void setPosition(int newPos);
    void incrementTimsTurns();
    void resetTimsStatus();





};

#endif