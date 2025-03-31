#ifndef Game_H
#define Game_H
#include "board.h"
#include <string>
#include <memory>
#include <vector>

class Player; 

class Game{

    Board* gameboard;
public:

    Game();
    ~Game();
    Game(Board* board);

    void initGame();

    void playTurn();

    bool loadGame(const std::string &filename);

    bool saveGame(const std::string &filename);

    bool isGameOver() const;

private:
    void nextPlayer();
    std::vector<std::unique_ptr<Player>> players;

    int currentPlayerIndex;
    bool gameOver;

    
};

#endif
