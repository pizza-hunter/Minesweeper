#include "Square.h"
#include <vector>
class Grid
{
private:
    std::vector<square> grid_squares;
    unsigned int height;
    unsigned int width;
    unsigned int mines;

public:
    Grid(const unsigned int height, const unsigned int width, const unsigned int mines);
};