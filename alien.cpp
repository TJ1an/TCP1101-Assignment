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

void MoveAlien(int &x, int &y, int rows, int columns, int health, int attack)
{
    string direction;
    int alienHealth;
    int alienAttack;
    health = alienHealth;
    attack = alienAttack;
    cout << "Alien Health: " << alienHealth;
    cout << " Alien Attack: " << alienAttack << endl;
    cout << "Enter the direction you want to move the alien (up, down, left, right): ";
    cin >> direction;
    if (direction == "up")
    {
        while(true)
        {
            if (x - 1 >= 0 && board[x - 1][y] == ' ')
            {
                board[x][y] = '.';
                x--;
                board[x][y] = 'A';
            }
            else if(x - 1 >= 0 && board[x - 1][y] == 'h')
            {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';          
            alienHealth = alienHealth + 20;
            cout << " " << endl;
            cout << "You gained 20 Health!" << endl;
            break;
            }
            else if(x - 1 >= 0 && board[x - 1][y] == '<')
            {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';          
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "You gained 20 Attack!" << endl;
            break;
            }
            else if(x - 1 >= 0 && board[x - 1][y] == '>')
            {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';          
            alienAttack = alienHealth + 20;
            cout << " " << endl;
            cout << "You gained 20 Attack!" << endl;
            break;
            }
            else if(x - 1 >= 0 && board[x - 1][y] == '^')
            {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';          
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "You gained 20 Attack!" << endl;
            break;
            }
            else if(x - 1 >= 0 && board[x - 1][y] == 'v')
            {
            board[x][y] = '.';
            x--;
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
    else if (direction == "down") {
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
            alienAttack = alienHealth + 20;
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
    else if (direction == "left") {
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
            alienAttack = alienHealth + 20;
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
    else if (direction == "right")
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
            alienAttack = alienHealth + 20;
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