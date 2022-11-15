#include "Grid.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

Grid::Grid() : _height(9), _width(9), _mines(10)
{
    std::cout << "Default grid created" << std::endl;
    Grid(_height, _width, _mines);
}

Grid::Grid(const int height, const int width, const int mines)
    : _height{height}, _width{width}, _mines{mines}, _grid_squares{}
{
    std::cout << "Creating custom grid " << _height << ", " << _width << ", " << _mines << std::endl;
};
// TODO - remove bombClicked flag
void Grid::printGrid(bool bombClicked)
{
    cout << "  ";
    for (int j = 0; j < _width; j++)
    {
        std::cout << "  " << j << " ";
    }
    cout << endl;
    for (int i = 0; i < size(); i++)
    {
        if (i % _width == 0)
        {
            for (int j = 0; j < _width; j++)
            {
                std::cout << "----";
            }
            cout << "---" << endl;

            cout << i / _width << " | ";
        }
        if (bombClicked && _grid_squares[i]._bomb)
        {
            cout << "*";
        }
        else if (_grid_squares[i]._flagged)
        {
            std::cout << "F";
        }
        else if (!_grid_squares[i]._clicked)
        {
            cout << " ";
        }
        else
        {
            std::cout << _grid_squares[i]._number;
        }
        cout << " | ";
        if (i % _width == _width - 1)
        {
            std::cout << std::endl;
        }
    }
    for (int i = 0; i < _width; i++)
    {
        std::cout << "----";
    }
    cout << "---" << endl;
}

int Grid::size()
{
    return _height * _width;
}

/*
    Populates grid with Squares, and squares with mines
*/
void Grid::fill()
{
    int minesRemaining = _mines;
    for (int i = 0; i < _height * _width; i++)
    {

        Square s{0};
        if (minesRemaining > 0)
        {
            s._bomb = true;
            minesRemaining--;
        }
        _grid_squares.push_back(s);
    }
}
/*
    Shuffles grid squares using time seed
*/
void Grid::shuffle()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(_grid_squares.begin(), _grid_squares.end(), std::default_random_engine(seed));
}

/*
    Determines if square lies within grid bounds
*/
bool Grid::inBounds(int x, int y)
{
    if (x >= 0 && x < _width && y >= 0 && y < _height)
    {
        return true;
    }
    return false;
}

int Grid::getIndex(int x, int y)
{
    return x + (y * _width);
}

int Grid::getIndex(Square *s)
{
    for (int i = 0; i < _grid_squares.size(); i++)
    {
        if (s == &_grid_squares[i])
        {
            return i;
        }
    }
    return -1;
}

/*
    Generates cell numbers for adjacent squares
*/
void Grid::calculateNumbers()
{

    for (int i = 0; i < _grid_squares.size(); i++)
    {
        Square *s = &_grid_squares[i];
        int surroundingBombs = 0;
        int x = getX(i);
        int y = getY(i);
        if (s->_bomb)
        {
            continue;
        }
        std::vector<Square *> nearbySquares = adjacentSquares(getIndex(x, y));

        for (Square *t : nearbySquares)
        {
            if (t->_bomb)
            {
                surroundingBombs++;
            }
        }
        s->_number = surroundingBombs;
    }
}

/*
    Flags square
*/
void Grid::flagSquare(int x, int y)
{
    _grid_squares[getIndex(x, y)].toggleFlag();
}

/*
    Returns true if square has bomb
    Returns false if square doesn't contain bomb
*/
bool Grid::squareHasBomb(int x, int y)
{
    return _grid_squares[getIndex(x, y)]._bomb;
}

void Grid::squareIndexes()
{
    for (int i = 0; i < _grid_squares.size(); i++)
    {
        _grid_squares[i]._index = i;
    }
}

std::vector<Square *> Grid::adjacentSquares(int index)
{
    int x = getX(index);
    int y = getY(index);
    int adjacentIndex[] = {x - 1, y - 1, x, y - 1, x + 1, y - 1, x - 1, y, x + 1, y, x - 1, y + 1, x, y + 1, x + 1, y + 1};
    std::vector<Square *> squares;
    for (int i = 0; i < (sizeof(adjacentIndex) / sizeof(*adjacentIndex)); i += 2)
    {
        int aX = adjacentIndex[i];
        int aY = adjacentIndex[i + 1];
        if (inBounds(aX, aY))
        {
            Square *s = &_grid_squares[getIndex(aX, aY)];
            squares.push_back(s);
        }
    }
    return squares;
}

int Grid::getX(int index)
{
    return index % _width;
}
int Grid::getY(int index)
{
    return index / _width;
}

void Grid::clickSquare(int x, int y)
{

    Square *s = &_grid_squares[getIndex(x, y)];
    if (!s->_flagged)
    {
        if (s->_number == 0 && !s->_clicked)
        {
            clickNearbySquares(s, x, y);
        }
        s->click();
    }
    else
    {
        cout << "Clicked flagged square" << endl;
    }
}

void Grid::clickNearbySquares(Square *s, int x, int y)
{
    std::vector<Square *> squareQueue = adjacentSquares(getIndex(x, y));
    for (int i = 0; i < squareQueue.size(); i++)
    {
        if (!squareQueue[i]->_clicked)
        {
            if (squareQueue[i]->_number == 0)
            {
                for (Square *d : adjacentSquares(getIndex(squareQueue[i])))
                {
                    squareQueue.push_back(d);
                }
            }
            squareQueue[i]->click();
        }
    }
}