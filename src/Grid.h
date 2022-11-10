#pragma once

#include "Square.h"
#include <vector>
class Grid
{
private:
    std::vector<Square> _grid_squares;
    const int _height;
    const int _width;
    const int _mines;
    bool inBounds(int x, int y);

public:
    Grid();
    Grid(const int height, const int width, const int mines);
    void printGrid();
    int size();
    void fill();
    void shuffle();
    void calculateNumbers();
};
