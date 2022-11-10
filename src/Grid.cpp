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

void Grid::printGrid()
{
    for (int i = 0; i < size(); i++)
    {
        if (i % _width == 0)
        {
            for (int j = 0; j < _width; j++)
            {
                std::cout << "----";
            }
            cout << "-" << endl;

            cout << "| ";
        }
        if (_grid_squares[i]._bomb)
        {
            std::cout << "*";
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
    cout << "-";
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

/*
    Generates cell numbers for adjacent squares
*/
void Grid::calculateNumbers()
{

    for (int i = 0; i < _grid_squares.size(); i++)
    {
        Square *s = &_grid_squares[i];
        int surroundingBombs = 0;
        int x = i % _width;
        int y = i / _width;
        if (s->_bomb)
        {
            continue;
        }

        // adjacentindex grouped in twos, loop steps two for x and y values
        int adjacentIndex[] = {x - 1, y - 1, x, y - 1, x + 1, y - 1, x - 1, y, x + 1, y, x - 1, y + 1, x, y + 1, x + 1, y + 1};
        for (int j = 0; j < (sizeof(adjacentIndex) / sizeof(*adjacentIndex)); j += 2)
        {
            if (inBounds(adjacentIndex[j], adjacentIndex[j + 1]))
            {
                if (_grid_squares[(adjacentIndex[j] + (adjacentIndex[j + 1] * _height))]._bomb)
                {
                    surroundingBombs++;
                }
            }
        }
        s->_number = surroundingBombs;
    }
}
