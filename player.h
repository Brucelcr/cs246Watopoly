#include <string>
#include <vector>
#include "property.h"
#include "dice.h"

class Player {
    private:
        std::string name;
        int balance;
        int position;
        bool inTimsLine;
        int cups;
        std::vector<Property*> properties;
        void removeProperty(Property* prop);

    public:
        Player(std::string name, int startBalance);

        int getPosition();
        std::string getName();
        void showAssets();
        bool isinTimsLine();

        void move(int steps);
        void pay(Player* payee, int amount);
        void paySchool(int amount);
        void receive(int amount);
        
        // roll a dice twice and move steps
        void rollDice(); 


}