#ifndef GAME_H
#define GAME_H

#include "Grid.h"


class Game
{
private:
    void createGrid();
    Grid _grid;
public:
    Game();
    void startGame();
    void endGame();
};


#endif