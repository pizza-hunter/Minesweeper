#include "Game.cpp"
#include "Square.cpp"
#include <iostream>

using namespace std;
int main()
{
    char play, choice;
    while (play != 'n')
    {
        cout << "Welcome, would you like to play a game? y or n" << endl;
        cin >> play;
        Game g;
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
        g.endGame();
    }

    return 0;
}