#ifndef Game_H
#define Game_H

#include <string>

class Game{
public:
    void playTurn();

    bool loadGame(const std::string &filename);

    bool saveGame(const std::string &filename);

    bool isGameOver() const;

private:
    void nextPlayer();
    bool gameOver;
    int currentPlayerIndex;


    
};

#endif
