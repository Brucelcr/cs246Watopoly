#ifndef Property_H  
#define Property_H
#include <string>

using namespace std;

class Property {
    private: 
        string name;
        bool mortgaged;
        string owner;
        int improvements;
        int cost; // purchase cost
        int impCost; // improvement cost
        int *tuition; // how much money to take
        string block;
    public:
        Property(string, int, int, int[6], string);
        string getName();
        int calculateRent();
        void setOwner(string newOwner);
        string getOwner();
        bool isMortgaged();
        void mortgage();
        void unmortgage();
        int getImprovements();
        int getImprovementCost();
        int getCost() const;
        bool operator==(const Property& other) const;
};

#endif
