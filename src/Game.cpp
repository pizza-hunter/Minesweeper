#include "Game.h"
#include "Grid.h"
#include <iostream>

using namespace gme;
using namespace std;
void game::startGame()
{
    char choice;
    cout << "Game started" << endl;
    createGrid();
}

void game::endGame()
{
    cout << "Game ended!" << endl;
}

void game::createGrid()
{
    Grid(9, 9, 10);
}