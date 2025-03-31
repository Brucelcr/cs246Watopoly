#ifndef Property_H  
#define Property_H
#include <string>

using namespace std;

class Property {
    public:
        Property();
        int calculateRent();
        void setOwner(string newOwner);
        string getOwner();
        bool isMortgaged();
        void mortgage();
        void unmortgage();
        int improvements;
    private: 
        bool mortgaged;
        string owner;
};

#endif
