#ifndef Game_H
#define Game_H

#include <string>
#include <memory>
#include <vector>

class Player; 

class Game{
public:

    Game();
    ~Game();

    void initGame();

    void playTurn();

    bool loadGame(const std::string &filename);

    bool saveGame(const std::string &filename);

    bool isGameOver() const;
    std::vector<std::unique_ptr<Player>> players;

private:
    void nextPlayer();

    int currentPlayerIndex;
    bool gameOver;

    
};

#endif
