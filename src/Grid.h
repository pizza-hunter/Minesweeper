#ifndef GRID_H
#define GRID_H

#include "Square.h"
#include <vector>
class Grid
{
private:
    std::vector<std::vector<int>> _grid_squares;
    const unsigned int _height;
    const unsigned int _width;
    const unsigned int _mines;

public:
    Grid();
    Grid(const unsigned int height, const unsigned int width, const unsigned int mines);
    void printGrid();
};

#endif