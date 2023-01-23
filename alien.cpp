#include "board.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "alien.h"
using namespace std;

extern vector< vector<char> > board;

int alienHealth()
{
    srand((unsigned) time(NULL));
    int alienHealths[] = {100,150,200,250};
    int randomAlienHealth = alienHealths[rand() % size(alienHealths)];
    int alienhealth = randomAlienHealth;
    return alienhealth;
}

int alienAttack = 0;

void MoveAlien(int &x, int &y, int rows, int columns, int health)
{
    string direction;
    int alienHealth;
    health = alienHealth;
    cout << "Alien Health: " << alienHealth;
    cout << " Alien Attack: " << alienAttack << endl;
    cout << "Enter the direction you want to move the alien (up, down, left, right): ";
    cin >> direction;

    if (direction == "up") // UP Input
    {
        while(true)
        {
            if (x - 1 >= 0 && board[x - 1][y] == ' ') //Empty path
            {
                board[x][y] = '.';
                x--;
                board[x][y] = 'A';
            }
            else if(x - 1 >= 0 && board[x - 1][y] == 'h') //Path with healthpack
            {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';          
            alienHealth = alienHealth + 20;
            cout << " " << endl;
            cout << "You gained 20 Health!" << endl;
            break;
            }
            else if(x - 1 >= 0 && board[x - 1][y] == '<') //Left boost/dash
            {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';          
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "You gained 20 Attack!" << endl;
            break;
            }
            else if(x - 1 >= 0 && board[x - 1][y] == '>') //Right boost/dash
            {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';          
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "You gained 20 Attack!" << endl;
            break;
            }
            else if(x - 1 >= 0 && board[x - 1][y] == '^') //Up boost/dash
            {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';          
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "You gained 20 Attack!" << endl;
            break;
            }
            else if(x - 1 >= 0 && board[x - 1][y] == 'v') //Down boost/dash
            {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';          
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "You gained 20 Attack!" << endl;
            break;
            }
            else //Invalid move
            {
                cout << "Invalid move" << endl;
                break;
            }
        }
    }
    else if (direction == "down") { //DOWN Input
        while(true)
        {
            if (x + 1 < rows && board[x + 1][y] == ' ')
            {
                board[x][y] = '.';
                x++;
                board[x][y] = 'A';
            }
            else if(x + 1 < rows && board[x + 1][y] == 'h')
            {
            board[x][y] = '.';
            x++;
            board[x][y] = 'A';
            alienHealth = alienHealth + 20;
            cout << " " << endl;
            cout << "You gained 20 Health!" << endl;
            break;
            }
            else if(x + 1 < rows && board[x + 1][y] == '<')
            {
            board[x][y] = '.';
            x++;
            board[x][y] = 'A';          
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "You gained 20 Attack!" << endl;
            break;
            }
            else if(x + 1 < rows && board[x + 1][y] == '>')
            {
            board[x][y] = '.';
            x++;
            board[x][y] = 'A';          
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "You gained 20 Attack!" << endl;
            break;
            }
            else if(x + 1 < rows && board[x + 1][y] == '^')
            {
            board[x][y] = '.';
            x++;
            board[x][y] = 'A';          
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "You gained 20 Attack!" << endl;
            break;
            }
            else if(x + 1 < rows && board[x + 1][y] == 'v')
            {
            board[x][y] = '.';
            x++;
            board[x][y] = 'A';          
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "You gained 20 Attack!" << endl;
            break;
            }
            else
            {
                cout << "Invalid move" << endl;
                break;
            }
    }
    }
    else if (direction == "left") { //LEFT Input
        while(true)
        {
            if (y - 1 >= 0 && board[x][y - 1] == ' ')
            {
                board[x][y] = '.';
                y--;
                board[x][y] = 'A';
            }
            else if(y - 1 >= 0 && board[x][y - 1] == 'h')
            {
            board[x][y] = '.';
            y--;
            board[x][y] = 'A';
            alienHealth = alienHealth + 20;
            cout << " " << endl;
            cout << "You gained 20 Health!" << endl;
            break;
            }
            else if(y - 1 >= 0 && board[x][y - 1] == '<')
            {
            board[x][y] = '.';
            y--;
            board[x][y] = 'A';          
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "You gained 20 Attack!" << endl;
            break;
            }
            else if(y - 1 >= 0 && board[x][y - 1] == '>')
            {
            board[x][y] = '.';
            y--;
            board[x][y] = 'A';          
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "You gained 20 Attack!" << endl;
            break;
            }
            else if(y - 1 >= 0 && board[x][y - 1] == '^')
            {
            board[x][y] = '.';
            y--;
            board[x][y] = 'A';          
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "You gained 20 Attack!" << endl;
            break;
            }
            else if(y - 1 >= 0 && board[x][y - 1] == 'v')
            {
            board[x][y] = '.';
            y--;
            board[x][y] = 'A';          
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "You gained 20 Attack!" << endl;
            break;
            }
            else
            {
                cout << "Invalid move" << endl;
            break;
            }
        }
    }
    else if (direction == "right") //RIGHT Input
    {
        while(true)
        {
            if (y + 1 < columns && board[x][y + 1] == ' ')
            {
                board[x][y] = '.';
                y++;
                board[x][y] = 'A';
            }
            else if(y + 1 < columns && board[x][y + 1] == 'h')
            {
            board[x][y] = '.';
            y++;
            board[x][y] = 'A';
            alienHealth = alienHealth + 20;
            cout << " " << endl;
            cout << "You gained 20 Health!" << endl;
            break;
            }
            else if(y + 1 < columns && board[x][y + 1] == '<')
            {
            board[x][y] = '.';
            y++;
            board[x][y] = 'A';          
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "You gained 20 Attack!" << endl;
            break;
            }
            else if(y + 1 < columns && board[x][y + 1] == '>')
            {
            board[x][y] = '.';
            y++;
            board[x][y] = 'A';          
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "You gained 20 Attack!" << endl;
            break;
            }
            else if(y + 1 < columns && board[x][y + 1] == '^')
            {
            board[x][y] = '.';
            y++;
            board[x][y] = 'A';          
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "You gained 20 Attack!" << endl;
            break;
            }
            else if(y + 1 < columns && board[x][y + 1] == 'v')
            {
            board[x][y] = '.';
            y++;
            board[x][y] = 'A';          
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "You gained 20 Attack!" << endl;
            break;
            }
            else
            {
                cout << "Invalid move" << endl;
            break;
            }
        }
    }
    else
    {
        cout << "Invalid input" << endl;
    }
}