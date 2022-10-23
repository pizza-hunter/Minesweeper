#include "Grid.h"
#include <iostream>
#include <vector>

Grid::Grid() : _height(9), _width(9), _mines(10){
    std::cout << "Default grid created" << std::endl;
}

Grid::Grid(const unsigned int height, const unsigned int width, const unsigned int mines) 
: _height{height}, _width{width}, _mines{mines}{
    std::cout << "Grid created " << _height << ", " << _width << ", " << _mines << std::endl;
    for(int i = 0; i < _height; i++){
        _grid_squares[i] = std::vector<int>(_width);
        for(int j = 0; j < _width; j++){
            _grid_squares[i][j] = 1;
        }
    }
};

void Grid::printGrid(){
    std::cout << "printing grid" << std::endl;
    for(int i = 0; i < _height; i++){
        for(int j = 0; j < _width; j++){
            std::cout << _grid_squares[i][j];
        }
        std::cout << std::endl;
    }
}