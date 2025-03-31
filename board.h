#ifndef Board_H  
#define Board_H
#include "property.h"
#include <string>

using namespace std;

class Board {
    public:
        Board();
        void drawBoard();
        Property getProperty(); 
        void auction();
    private: 
        string board;
        void updateBoard();
        string viewImprovements(int index);
};

#endif
