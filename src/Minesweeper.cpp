#include "Game.cpp"
#include "Square.cpp"
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

int main()
{

    Game g(3, 3, 1);
    g.startGame();

    // char play, choice;
    // while (play != 'n')
    // {
    //     cout << "Welcome, would you like to play a game? y or n" << endl;
    //     cin >> play;
    //     Game g;
    //     switch (play)
    //     {
    //     case 'y':
    //         cout << "press y" << endl;
    //         cin >> play;
    //         g.startGame();
    //         break;
    //     case 'n':
    //         cout << "Goodbye!" << endl;
    //         break;
    //     default:
    //         cout << "Please enter a valid choice" << endl;
    //         break;
    //     }
    //     g.endGame();
    // }
}
