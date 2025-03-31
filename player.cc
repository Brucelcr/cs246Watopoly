#include <iostream>

#include "player.h"


Player::Player(std::string name, int startBalance, Board* gameboard) :
    name(name), balance(startBalance), position(0), inTimsLine(false), cups(0), gameboard(gameboard) {
}


int Player::getPosition() const {
    return position;
}

std::string Player::getName() const {
    return name;
}

bool Player::isinTimsLine() const {
    return inTimsLine;
}

void Player::move(int steps) {
    position = (position + steps) % 40;
    gameboard->drawBoard();

}

void Player::pay(Player* payee, int amount) {
    if (balance < amount) {
        std::cout << "No enough money to pay" << std::endl;
        return;
    }

    balance -= amount;
    payee->receive(amount);
}

void Player::paySchool(int amount) {
    balance -= amount;
}

void Player::receive(int amount) {
    balance += amount;
}

void Player::rollDice() {
    Dice dice;
    int die1 = dice.roll();
    int die2 = dice.roll();

    move(die1 + die2);

}

void Player::declareBankruptcy() {
    std::cout << name << " has declared bankruptcy! All properties returned to the bank." << std::endl;
    properties.clear();
    balance = 0;
}

void Player::trade(Player& other, Property* give, Property* receive) {
    if (give) {
        give->setOwner(other.getName());
        properties.erase(std::remove(properties.begin(), properties.end(), give), properties.end());
        other.properties.push_back(give);
    }
    if (receive) {
        receive->setOwner(name);
        other.properties.erase(std::remove(other.properties.begin(), other.properties.end(), receive), other.properties.end());
        properties.push_back(receive);
    }
    std::cout << name << " traded with " << other.getName() << std::endl;
}

void Player::buyImprovement(Property* property) {

}

void Player::sellImprovement(Property* property){

}

void Player::mortgage(Property* property) {
    if (property->getOwner() != name) {
        std::cout << "Cannot mortgage property that you don't own" << std::endl;
        return;
    }
    property->mortgage();
}

void Player::unmortgage(Property* property) {
    if (property->getOwner() != name) {
        std::cout << "Cannot unmortgage property that you don't own" << std::endl;
        return;
    }
    property->unmortgage();
}

void Player::addCup() {
    cups++;
}
void Player::removeCup() {
    if (cups == 0) {
        std::cout << "No enough Tims Cup" << std::endl;
        return;
    }
    cups--;
}

void Player::setPosition(int newPos){
    position = newPos;
}

void Player::resetTimsStatus(){
    inTimsLine = false;
}

