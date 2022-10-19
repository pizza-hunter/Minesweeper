#include "Game.h"
#include <iostream>

using namespace gme;
using namespace std;
void game::startGame()
{
    char choice;
    cout << "Game started" << endl;
    cout << "Choose which game to play:\nBeginner: b\nIntermediate: i" << endl;
    cin >> choice;
    switch (choice)
    {
    case 'b':
        cout << "Beginner game created" << endl;
        break;
    case 'i':
        cout << "Intermediate game created" << endl;
        break;
    default:
        cout << "Please enter a valid choice" << endl;
    }
}

void game::endGame()
{
    cout << "Game ended!" << endl;
}

void game::createGrid()
{
}