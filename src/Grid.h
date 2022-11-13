#pragma once

#include "Square.h"
#include <vector>
class Grid
{
private:
    std::vector<Square> _grid_squares;
    const int _mines;
    bool inBounds(int x, int y);
    int gridIndex(int x, int y);

public:
    const int _height;
    const int _width;
    Grid();
    Grid(const int height, const int width, const int mines);
    void printGrid(bool bombClicked);
    int size();
    void fill();
    void shuffle();
    void calculateNumbers();
    void flagSquare(int x, int y);
    bool squareHasBomb(int x, int y);
};
