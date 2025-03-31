#ifndef Property_H  
#define Property_H
#include <string>

using namespace std;

class Property {
    private: 
        bool mortgaged;
        string owner;
    public:
        Property();
        int calculateRent();
        void setOwner(string newOwner);
        string getOwner();
        bool isMortgaged();
        void mortgage();
        void unmortgage();
        int improvements;
        int value();
};

#endif
