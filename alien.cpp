#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

extern vector< vector<char> > board;

void alienStats()
{
    srand((unsigned) time(NULL)); 
    int alienHealth[]={50,100,150,200,250};
    int randomAlienHealth = rand() % size(alienHealth);
    cout << "Alien Health: ";
    cout << alienHealth[randomAlienHealth] << endl;
}


void MoveAlien(int &x, int &y, int rows, int columns) {
    string direction;
    alienStats();
    cout << "Enter the direction you want to move the alien (up, down, left, right): ";
    cin >> direction;
    if (direction == "up") {
        while(true)
        if (x - 1 >= 0 && board[x - 1][y] != 'r') {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';
        }
        else {
            cout << "Invalid move" << endl;
        break;
        }
    }
    else if (direction == "down") {
        while(true)
        if (x + 1 < rows && board[x + 1][y] != 'r') {
            board[x][y] = '.';
            x++;
            board[x][y] = 'A';
        }
        else {
            cout << "Invalid move" << endl;
        break;
        }
    }
    else if (direction == "left") {
        while(true)
        if (y - 1 >= 0 && board[x][y - 1] != 'r') {
            board[x][y] = '.';
            y--;
            board[x][y] = 'A';
        }
        else {
            cout << "Invalid move" << endl;
        break;
        }
    }
    else if (direction == "right") {
        while(true)
        if (y + 1 < columns && board[x][y + 1] != 'r') {
            board[x][y] = '.';
            y++;
            board[x][y] = 'A';
        }
        else {
            cout << "Invalid move" << endl;
        break;
        }
    }
    else {
        cout << "Invalid input" << endl;
    }
}