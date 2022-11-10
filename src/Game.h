#pragma once

#include "Grid.h"

class Game
{
private:
    void createGrid();
    Grid _grid;

public:
    Game();
    Game(const int height, const int width, const int mines);
    void startGame();
    void endGame();
};