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

    Game g(5, 5, 5);
    g.startGame();
    // int w = 5;
    // int h = 9;
    // int counter = 0;

    // Grid g(w, h, 1);
    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < w; j++)
    //     {
    //         cout << "c: " << counter;
    //         cout << " i: " << g.gridIndex(j, i) << endl;
    //         counter++;
    //     }
    // }

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
