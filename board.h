#define Board_H
#include <string>

using namespace std;

class Board {
    public:
        Board();
        void drawBoard();
    private: 
        string board;
        string improvements[22]; // will move into properties as well(?)
        string owner[22]; // will retrieve from properties
        string players; // will move into square
        void updateBoard();
};
