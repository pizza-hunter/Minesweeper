#include "Game.h"
#include "Grid.cpp"
#include <iostream>

using namespace std;

Game::Game(){
    cout << "Game object created" << endl;
}

void Game::startGame()
{
    char choice;
    cout << "Game started" << endl;
    createGrid();
}

void Game::endGame()
{
    cout << "Game ended!" << endl;
}

void Game::createGrid()
{
    Grid _grid = Grid(9,9,10);
    _grid.printGrid();
}