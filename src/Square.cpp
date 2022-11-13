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
}

void Square::click()
{
    _clicked = true;
}