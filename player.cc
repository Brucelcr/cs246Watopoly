#include <iostream>

#include "player.h"
#include "dice.h"

Player::Player(std::string name, int startBalance) :
    name(name), balance(startBalance), position(0), inTimsLine(false), cups(0), properties() {
}


int Player::getPosition() {
    return position;
}

std::string Player::getName() {
    return name;
}

bool Player::isinTimsLine() {
    return inTimsLine;
}

void Player::move(int steps) {
    position = (position + steps) % 40;
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

    move(die1+die2);

}

