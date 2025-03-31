#include "nonproperty.h"
#include "dice.h"
#include <iostream>
#include <random>
#include <cmath>

// Base NonProperty class
NonProperty::NonProperty(const std::string& name, int position)
    : Square(name, false), position(position) {
}

void NonProperty::passBy(Player& player) {
    if (getName() == "COLLECT OSAP") {
        player.receiveMoney(200);
        std::cout << player.getName() << " passed COLLECT OSAP and received $200\n";
    }
}

// Collect OSAP implementation
CollectOSAP::CollectOSAP(int position)
    : NonProperty("COLLECT OSAP", position) {
}

void CollectOSAP::landOn(Player& player) {
    player.receiveMoney(200);
    std::cout << player.getName() << " landed on COLLECT OSAP and received $200\n";
}

// Tuition implementation
Tuition::Tuition(int position)
    : NonProperty("TUITION", position) {
}

void Tuition::landOn(Player& player) {
    std::cout << player.getName() << " must pay tuition:\n";
    std::cout << "1. $300 flat fee\n";
    std::cout << "2. 10% of total assets ($" << player.getTotalWorth() * 0.1 << ")\n";

    int choice;
    while (true) {
        std::cin >> choice;
        if (choice == 1) {
            player.paySchool(300);
            break;
        }
        else if (choice == 2) {
            player.paySchool(std::ceil(player.getTotalWorth() * 0.1));
            break;
        }
        std::cout << "Invalid choice. Enter 1 or 2: ";
    }
}

// GoToTims implementation
GoToTims::GoToTims(int position)
    : NonProperty("GO TO TIMS", position) {
}

void GoToTims::landOn(Player& player) {
    player.setPosition(10); // DC Tims Line position
    player.sendToTims();
    std::cout << player.getName() << " was sent to DC Tims Line!\n";
}

// DC Tims Line implementation
DC_Tims_Line::DC_Tims_Line(int position)
    : NonProperty("DC TIMS LINE", position) {
}

void DC_Tims_Line::landOn(Player& player) {
    if (player.isinTimsLine()) {
        std::cout << player.getName() << " is still in DC Tims Line ("
            << player.getTurnsInTims() << " turns)\n";
    }
    else {
        std::cout << player.getName() << " is visiting DC Tims Line\n";
    }
}

// Goose Nesting implementation
GooseNesting::GooseNesting(int position)
    : NonProperty("GOOSE NESTING", position) {
}

void GooseNesting::landOn(Player& player) {
    std::cout << player.getName() << " was attacked by geese but survived!\n";
}

// Coop Fee implementation
CoopFee::CoopFee(int position)
    : NonProperty("COOP FEE", position) {
}

void CoopFee::landOn(Player& player) {
    player.paySchool(150);
    std::cout << player.getName() << " paid $150 COOP FEE\n";
}

// SLC implementation
SLC::SLC(int position)
    : NonProperty("SLC", position) {
}

void SLC::landOn(Player& player) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::discrete_distribution<> dist({
        3, // back 3
        4, // back 2
        4, // back 1
        3, // forward 1
        4, // forward 2
        4, // forward 3
        1, // go to tims
        1  // OSAP
    });

    // 1% chance for Roll Up the Rim cup
    if ((rand() % 100) == 0) { // check active cup number here
        player.addCup();
        std::cout << player.getName() << " got a Roll Up the Rim cup! \n";
    }

    int result = dist(gen);
    int movement = 0;
    std::string message;

    switch (result) {
    case 0: movement = -3; message = "moved back 3 spaces"; break;
    case 1: movement = -2; message = "moved back 2 spaces"; break;
    case 2: movement = -1; message = "moved back 1 space"; break;
    case 3: movement = 1;  message = "moved forward 1 space"; break;
    case 4: movement = 2;  message = "moved forward 2 spaces"; break;
    case 5: movement = 3;  message = "moved forward 3 spaces"; break;
    case 6:
        player.setPosition(10); // DC Tims Line
        player.sendToTims();
        message = "was sent to DC Tims Line";
        break;
    case 7:
        player.setPosition(0); // Collect OSAP
        message = "advanced to COLLECT OSAP";
        break;
    }

    if (result < 6) {
        player.move(movement);
    }

    std::cout << player.getName() << " drew SLC card and " << message << "\n";
}

// Needles Hall implementation
NeedlesHall::NeedlesHall(int position)
    : NonProperty("NEEDLES HALL", position) {
}

void NeedlesHall::landOn(Player& player) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::discrete_distribution<> dist({ 
        1, // -200
        2, // -100
        3, // -50
        6, // 25
        3, // 50
        2, // 100
        1  // 200
    }); 

    // 1% chance for Roll Up the Rim cup
    if ((rand() % 100) == 0) { // check active cup number here
        player.addCup();
        std::cout << player.getName() << " got a Roll Up the Rim cup! \n";
        return;
    }

    int result = dist(gen);
    int amount = 0;

    switch (result) {
    case 0: amount = -200; break;
    case 1: amount = -100; break;
    case 2: amount = -50; break;
    case 3: amount = 25; break;
    case 4: amount = 50; break;
    case 5: amount = 100; break;
    case 6: amount = 200; break;
    }

    if (amount > 0) {
        player.receiveMoney(amount);
        std::cout << player.getName() << " gained $" << amount << " at Needles Hall\n";
    }
    else {
        player.paySchool(-amount);
        std::cout << player.getName() << " lost $" << -amount << " at Needles Hall\n";
    }

    
}