#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>
#include "property.h"
#include "dice.h"
#include "board.h"

class Player {
private:
    std::string name;
    char piece; // symbol representing player: G, B, D, P ...
    int balance;
    int position;
    bool inTimsLine;
    int turnsinLine;
    int cups;
    std::vector<std::shared_ptr<Property>> properties;
    Board* gameboard;

public:
    Player(std::string name, int startBalance, char piece, Board* gameboard);
    Player(std::string name); // to pass in into game.cc

    int getPosition() const;
    std::string getName()const;
    int getBalance() const;
    void showAssets();
    bool isinTimsLine()const;
    int getTurnsInTims()const;
    int getTotalWorth() const; // return total worth (including your savings, printed prices of all buildings you own, and costs of each improvement)


    void move(int steps); // update position and draw board
    void setPosition(int newPos); // set to newPos and draw board
    void pay(Player* payee, int amount);
    void paySchool(int amount);
    void receiveMoney(int amount);

    void rollDice(); // roll a dice twice and move steps

    void addProperty(std::shared_ptr<Property> property); // add to vector and update owner
    void removeProperty(std::shared_ptr<Property> property);
    std::shared_ptr<Property> stringToProperty(std::string property);
    void declareBankruptcy();
    void trade(Player& other, std::shared_ptr<Property> give, std::shared_ptr<Property> receive, int giveMoney, int receiveMoney);

    void buyImprovement(const std::shared_ptr<Property>& property);
    void sellImprovement(const std::shared_ptr<Property>& property);
    void mortgage(std::shared_ptr<Property> property);
    void unmortgage(std::shared_ptr<Property> property);

    void addCup();
    void removeCup();
    void incrementTimsTurns();
    void resetTimsStatus();
    void sendToTims();


    bool hasMonopoly() const; // check if player have all properties in a block





};

#endif
