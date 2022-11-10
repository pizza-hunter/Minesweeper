#include "Game.h"
#include "Grid.cpp"
#include <iostream>

using namespace std;

Game::Game() : _grid{9, 9, 9}
{
    cout << "Game object created (standard)" << endl;
}
Game::Game(const int height, const int width, const int mines)
    : _grid{height, width, mines}
{
    cout << "Game oject created (custom)" << endl;
}

void Game::startGame()
{
    cout << "Game started" << endl;
    createGrid();
}

void Game::endGame()
{
    cout << "Game ended!" << endl;
}

void Game::createGrid()
{
    _grid.fill();
    _grid.shuffle();
    _grid.calculateNumbers();
    _grid.printGrid();
}
