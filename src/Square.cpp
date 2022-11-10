#include "Square.h"
#include <iostream>

Square::Square()
{
}
Square::Square(int number) : _number(number)
{
    _clicked = false;
    _flagged = false;
    _bomb = false;
}

void Square::toggleFlag()
{
    _flagged = !_flagged;
    std::cout << "Flag changed " << _flagged << std::endl;
}

void Square::click()
{
    _clicked = true;
}