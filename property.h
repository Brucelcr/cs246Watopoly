#ifndef Property_H  
#define Property_H
#include <string>

using namespace std;

class Property {
    private: 
        bool mortgaged;
        string owner;
        int improvements;
        int cost; // purchase cost
        int *tuition; // how much money to take
        string block;
    public:
        Property(int, int*, string);
        int calculateRent();
        void setOwner(string newOwner);
        string getOwner();
        bool isMortgaged();
        void mortgage();
        void unmortgage();
        int getImprovements();
};

#endif
