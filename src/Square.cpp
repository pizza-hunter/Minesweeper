#include "Square.h"
#include <iostream>

Square::Square(){
    std::cout << "Square created (default)" << std::endl;
}
Square::Square(int number = 0){
    std::cout << "Square created custom" << std::endl;
}

void Square::toggleFlag(){
    _flagged = !_flagged;
    std::cout << "Flag changed " << _flagged << std::endl;
}