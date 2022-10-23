#ifndef SQUARE_H
#define SQUARE_H

class Square
{

private:
    int _number;
    bool _bomb;
    bool _clicked;
    bool _flagged;
public:
    Square();
    Square(int number);
    void toggleFlag();
};

#endif