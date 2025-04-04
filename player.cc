#include <iostream>
#include <vector>
#include <algorithm>

#include "player.h"


Player::Player(std::string name, int startBalance, char piece, Board* gameboard) :
    name(name), piece(piece), balance(startBalance), position(0),
    inTimsLine(false), turnsinLine(0), cups(0), gameboard(gameboard) {
}


int Player::getPosition() const {
    return position;
}

std::string Player::getName() const {
    return name;
}

int Player::getBalance() const {
    return balance;
}

bool Player::isinTimsLine() const {
    return inTimsLine;
}

int Player::getTurnsInTims() const {
    return turnsinLine;
}

int Player::getTotalWorth() const {
    int total = balance;

    // Add property values and improvements
    for (const auto& property : properties) {
        // Base property value
        total += property->getCost();

        // Add improvement values (50% of improvement cost)
        if (!property->isMortgaged()) {
            total += property->getImprovements() * (property->getImprovementCost() / 2);
        }

        // Subtract mortgage debt if applicable
        if (property->isMortgaged()) {
            total -= property->getCost() / 2;  // Mortgage value already received
        }
    }

    return total;
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
    payee->receiveMoney(amount);
}

void Player::paySchool(int amount) {
    balance -= amount;
}

void Player::receiveMoney(int amount) {
    balance += amount;
}

void Player::rollDice() {
    Dice dice;
    int die1 = dice.roll();
    int die2 = dice.roll();

    move(die1 + die2);

}

void Player::addProperty(std::shared_ptr<Property> property) {
    properties.push_back(property);
    property->setOwner(name);
}

void Player::removeProperty(std::shared_ptr<Property> property) {
    properties.erase(std::remove(properties.begin(), properties.end(), property), properties.end());
    property->setOwner(" ");
}

std::shared_ptr<Property> Player::stringToProperty(std::string property) {
    for(const std::shared_ptr<Property>& p : properties) {
        if (p->getName() ==  property) {
            return p;
        }
    }
    return nullptr;
}

void Player::declareBankruptcy() {
    properties.clear();
    balance = 0;
    std::cout << name << " has declared bankruptcy! All properties returned to the bank." << std::endl;
}

void Player::trade(Player& other, std::shared_ptr<Property> give, std::shared_ptr<Property> receive, int giveMoney, int receiveMoney) {
    if (give == nullptr) {
        cout << "You don't own this building! Trade failed." << endl;
        return;
    } else if (receive == nullptr) {
        cout << "They don't own this building! Trade failed." << endl;
        return;
    } else if (giveMoney > balance) {
        cout << "You don't have enough money! Trade failed." << endl; 
    } else if (receiveMoney > other.balance) {
        cout << "They don't have enough money! Trade failed." << endl; 
    }

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

    if (giveMoney) {
        balance -= giveMoney;
        pay(&other, giveMoney);
    }

    if (receiveMoney) {
        balance -= giveMoney;
        pay(&other, giveMoney);
    }

    std::cout << name << " traded with " << other.getName() << std::endl;
}

void Player::buyImprovement(const std::shared_ptr<Property>& property) {
    if (property->getOwner() != name) {
        std::cout << "Buy Improvement fail: You don't own this property" << std::endl;
        return;
    }

    paySchool(property->getImprovementCost()); // change method name if needed
    property->getImprovements(); 

}


void Player::sellImprovement(const std::shared_ptr<Property>& property) {
    if (property->getOwner() != name) {
        std::cout << "Sell Improvement fail: You don't own this property" << std::endl;
        return;
    }

    int refund = property->getImprovementCost() / 2; // 50% refund
    property->getImprovements();
    receiveMoney(refund);

}

void Player::mortgage(std::shared_ptr<Property> property) {
    if (property->getOwner() != name) {
        std::cout << "Cannot mortgage property that you don't own" << std::endl;
        return;
    }
    property->mortgage();
}

void Player::unmortgage(std::shared_ptr<Property> property) {
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

void Player::setPosition(int newPos) {
    position = newPos;
    gameboard->drawBoard();
}


void Player::resetTimsStatus() {
    inTimsLine = false;
}

void Player::incrementTimsTurns(){
    turnsinLine++;
}

void Player::sendToTims() {
    setPosition(10);
    inTimsLine = true;
    turnsinLine = 0;
}

bool Player::hasMonopoly(string code) const {
    int count = 0;
    for(const std::shared_ptr<Property>& p : properties) {
        if (p->getBlock() == code) {
            count++;
        }
        if (count == p->getNumInSet()) {
            return true;
        }
    }
    return false;
}

Player::Player(std::string name)
    : Player(name, 1500, 'A', nullptr) { }
