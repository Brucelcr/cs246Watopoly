#ifndef Property_H  
#define Property_H
#include <vector>
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
        int numInSet;
    public:
        Property(string, int, int, int[6], string, int);
        string getName() const;
        void setOwner(string newOwner);
        string getOwner() const;
        bool isMortgaged() const;
        void mortgage();
        void unmortgage();
        int getImprovements() const;
        int getImprovementCost() const;
        int getCost() const;
        int* getTuition() const;
        string getBlock() const;
        int getNumInSet() const;
        bool operator==(const Property& other) const;
};

#endif
