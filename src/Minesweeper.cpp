// #include "game.h"
#include "Game.cpp"
#include <iostream>

using namespace gme;
int main()
{
    char play, choice;
    game g;
    while (play != 'n')
    {
        cout << "Welcome, would you like to play a game? y or n" << endl;
        cin >> play;
        switch (play)
        {
        case 'y':
            g.startGame();
            break;
        case 'n':
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Please enter a valid choice" << endl;
            break;
        }
    }

    g.endGame();
    return 0;
}