#pragma once
class Square
{
private:
public:
    bool _clicked;
    bool _flagged;
    int _number;
    bool _bomb;
    int _index;
    Square();
    Square(int number);
    void toggleFlag();
    void click();
};