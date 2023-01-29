#include "../board.h"
#include "alien.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

extern vector< vector<char> > board;

int alienhp()
{
    srand((unsigned) time(NULL));
    int alienHealths[] = {100,150,200,250};
    int randomAlienHealth = alienHealths[rand() % size(alienHealths)];
    int alienhealth = randomAlienHealth;
    return alienhealth;
}

int alienAttack = 0;
int alienHealth = alienhp();

void moveup(int &x, int &y, int rows, int columns)
{
    while(true)
        {
            if (x - 1 >= 0 && board[x - 1][y] == ' ') //Empty path
            {
                board[x][y] = '.';
                x--;
                board[x][y] = 'A';
            }
            else if (x - 1 >= 0 && board[x - 1][y] == '.') //Trail path
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
            moveleft(x, y, rows, columns);
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
            moveright(x, y, rows, columns);
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
            moveup(x, y, rows, columns);
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
            movedown(x, y, rows, columns);
            break;
            }
            else //Invalid move
            {
                cout << "Invalid move" << endl;
                break;
            }
        }
    }

void movedown(int &x, int &y, int rows, int columns)
{
    while(true)
        {
            if (x + 1 < rows && board[x + 1][y] == ' ')
            {
                board[x][y] = '.';
                x++;
                board[x][y] = 'A';
            }
            else if (x + 1 < rows && board[x + 1][y] == '.')
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
            moveleft(x, y, rows, columns);
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
            moveright(x, y, rows, columns);
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
            moveup(x, y, rows, columns);
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
            movedown(x, y, rows, columns);
            break;
            }
            else
            {
                cout << "Invalid move" << endl;
                break;
            }
    }
}
void moveleft(int &x, int &y, int rows, int columns){
while(true)
        {
            if (y - 1 >= 0 && board[x][y - 1] == ' ')
            {
                board[x][y] = '.';
                y--;
                board[x][y] = 'A';
            }
            else if (y - 1 >= 0 && board[x][y - 1] == '.')
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
            moveleft(x, y, rows, columns);
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
            moveright(x, y, rows, columns);
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
            moveup(x, y, rows, columns);
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
            movedown(x, y, rows, columns);
            break;
            }
            else
            {
                cout << "Invalid move" << endl;
            break;
            }
        }
}
void moveright(int &x, int &y, int rows, int columns){
while(true)
        {
            if (y + 1 < columns && board[x][y + 1] == ' ')
            {
                board[x][y] = '.';
                y++;
                board[x][y] = 'A';
            }
            else if (y + 1 < columns && board[x][y + 1] == '.')
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
            moveleft(x, y, rows, columns);
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
            moveright(x, y, rows, columns);
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
            moveup(x, y, rows, columns);
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
            movedown(x, y, rows, columns);
            break;
            }
            else
            {
                cout << "Invalid move" << endl;
            break;
            }
        }
}
void displayAlien(){
    cout << "Alien Health: " << alienHealth;
    cout << " Alien Attack: " << alienAttack << endl;
}
void MoveAlien(int &x, int &y, int rows, int columns)
{   
    string direction;
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
            else if (x - 1 >= 0 && board[x - 1][y] == '.') //Trail path
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
            moveleft(x, y, rows, columns);
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
            moveright(x, y, rows, columns);
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
            moveup(x, y, rows, columns);
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
            movedown(x, y, rows, columns);
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
            else if (x + 1 < rows && board[x + 1][y] == '.')
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
            moveleft(x, y, rows, columns);
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
            moveright(x, y, rows, columns);
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
            moveup(x, y, rows, columns);
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
            movedown(x, y, rows, columns);
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
            else if (y - 1 >= 0 && board[x][y - 1] == '.')
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
            moveleft(x, y, rows, columns);
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
            moveright(x, y, rows, columns);
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
            moveup(x, y, rows, columns);
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
            movedown(x, y, rows, columns);
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
            else if (y + 1 < columns && board[x][y + 1] == '.')
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
            moveleft(x, y, rows, columns);
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
            moveright(x, y, rows, columns);
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
            moveup(x, y, rows, columns);
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
            movedown(x, y, rows, columns);
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