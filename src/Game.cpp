#include "Game.h"
#include "Grid.cpp"
#include <iostream>

using namespace std;

Game::Game() : _grid{9, 9, 9}, _mineClicked{false}
{
    cout << "Game object created (standard)" << endl;
}
Game::Game(const int height, const int width, const int mines)
    : _grid{height, width, mines}, _mineClicked{false}
{
    cout << "Game oject created (custom)" << endl;
}

void Game::startGame()
{
    cout << "Game started" << endl;
    createGrid();

    while (!_mineClicked)
    {
        _grid.printGrid(_mineClicked);
        playerTurn();
    }
    _grid.printGrid(_mineClicked);
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
}

void Game::playerTurn()
{
    int choiceX = -3;
    int choiceY = -3;
    char choiceMove;
    while (choiceX < 0 || choiceX > _grid._width - 1)
    {
        cout << "\nX: ";
        cin >> choiceX;
    }
    while (choiceY < 0 || choiceY > _grid._height - 1)
    {
        cout << "Y: ";
        cin >> choiceY;
    }
    while (choiceMove != 'c' && choiceMove != 'f')
    {
        cout << "c or f: ";
        cin >> choiceMove;
    }
    if (choiceMove == 'f')
    {
        _grid.flagSquare(choiceX, choiceY);
    }
    else
    {
        _mineClicked = _grid.squareHasBomb(choiceX, choiceY);
    }
}