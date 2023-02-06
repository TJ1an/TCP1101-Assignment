#include "../board.h"
#include "alien.h"
#include "../help/help.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

extern vector<vector<char>> board;

int alienAttack = 0;
int alienHealth = alienhp();

void myPause()
{
    cout << "Press ENTER to continue...";
    cin.clear();
    cin.sync();
    cin.get();
}

int alienhp()
{
    srand((unsigned)time(NULL));
    int alienHealths[] = {100, 150, 200, 250};
    int randomAlienHealth = alienHealths[rand() % size(alienHealths)];
    int alienhealth = randomAlienHealth;
    return alienhealth;
}

void changeTrail(int &x, int &y, int rows, int columns)
{
    srand((unsigned)time(NULL));
    char objects[] = {'h', '<', '>', '^', 'v', 'r', ' ', ' '};
    int objectsSize = sizeof(objects);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (board[i][j] == '.')
            {
                board[i][j] = objects[rand() % objectsSize];
            }
        }
    }
}

void changeArrow(int &x, int &y, int rows, int columns) // prompts the user to enter row and column values to change arrow direction
{
    int numrows;
    int numcolumns;
    cout << "Enter row: ";
    cin >> numrows;
    cout << "Enter columns: ";
    cin >> numcolumns;
    char selection;
    if (board[numrows - 1][numcolumns - 1] == '<' || board[numrows - 1][numcolumns - 1] == '>' || board[numrows - 1][numcolumns - 1] == '^' || board[numrows - 1][numcolumns - 1] == 'v')
    {
        cout << "Chose a direction (<,^,>,v): ";
        cin >> selection;
        board[numrows - 1][numcolumns - 1] = selection;
    }
    else
    {
        cout << " " << endl;
        cout << "bruh" << endl;
        cout << " " << endl;
    }
}

void moveup(int &x, int &y, int rows, int columns)
{
    while (true)
    {
        if (x - 1 >= 0 && board[x - 1][y] == ' ') // Empty path
        {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';
        }
        else if (x - 1 >= 0 && board[x - 1][y] == '.') // Trail path
        {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';
        }
        else if (x - 1 >= 0 && board[x - 1][y] == 'h') // Path with healthpack
        {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';
            alienHealth = alienHealth + 20;
            cout << " " << endl;
            cout << "Alien finds a Healthpack!" << endl;
            cout << "You gained 20 Health!" << endl;
            cout << " " << endl;
            myPause();
            break;
        }
        else if (x - 1 >= 0 && board[x - 1][y] == 'r') // Path with rock
        {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';
            cout << " " << endl;
            cout << "You hit a rock!" << endl;
            cout << " " << endl;
            myPause();
            rockrandomobject(x, y, rows, columns);
            cout << " " << endl;
            break;
        }
        else if (x - 1 >= 0 && board[x - 1][y] == '<') // Left boost/dash
        {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "Alien finds a left arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            myPause();
            moveleft(x, y, rows, columns);
            break;
        }
        else if (x - 1 >= 0 && board[x - 1][y] == '>') // Right boost/dash
        {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "Alien finds a right arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            myPause();
            moveright(x, y, rows, columns);
            break;
        }
        else if (x - 1 >= 0 && board[x - 1][y] == '^') // Up boost/dash
        {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "Alien finds an up arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            myPause();
            moveup(x, y, rows, columns);
            break;
        }
        else if (x - 1 >= 0 && board[x - 1][y] == 'v') // Down boost/dash
        {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "Alien finds a down arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            myPause();
            movedown(x, y, rows, columns);
            break;
        }
        else
        {
            cout << " " << endl;
            cout << "Alien hits a wall!" << endl;
            cout << " " << endl;
            myPause();
            break;
        }
    }
}

void movedown(int &x, int &y, int rows, int columns)
{
    while (true)
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
        else if (x + 1 < rows && board[x + 1][y] == 'h')
        {
            board[x][y] = '.';
            x++;
            board[x][y] = 'A';
            alienHealth = alienHealth + 20;
            cout << " " << endl;
            cout << "Alien finds a Healthpack!" << endl;
            cout << "You gained 20 Health!" << endl;
            cout << " " << endl;
            myPause();
            break;
        }
        else if (x + 1 < rows && board[x + 1][y] == 'r') // Path with rock
        {
            board[x][y] = '.';
            x++;
            board[x][y] = 'A';
            cout << " " << endl;
            cout << "You hit a rock!" << endl;
            cout << " " << endl;
            myPause();
            rockrandomobject(x, y, rows, columns);
            cout << " " << endl;
            break;
        }
        else if (x + 1 < rows && board[x + 1][y] == '<')
        {
            board[x][y] = '.';
            x++;
            board[x][y] = 'A';
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "Alien finds a left arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            myPause();
            moveleft(x, y, rows, columns);
            break;
        }
        else if (x + 1 < rows && board[x + 1][y] == '>')
        {
            board[x][y] = '.';
            x++;
            board[x][y] = 'A';
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "Alien finds a right arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            myPause();
            moveright(x, y, rows, columns);
            break;
        }
        else if (x + 1 < rows && board[x + 1][y] == '^')
        {
            board[x][y] = '.';
            x++;
            board[x][y] = 'A';
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "Alien finds an up arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            myPause();
            moveup(x, y, rows, columns);
            break;
        }
        else if (x + 1 < rows && board[x + 1][y] == 'v')
        {
            board[x][y] = '.';
            x++;
            board[x][y] = 'A';
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "Alien finds a down arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            myPause();
            movedown(x, y, rows, columns);
            break;
        }
        else
        {
            cout << " " << endl;
            cout << "Alien hits a wall!" << endl;
            cout << " " << endl;
            myPause();
            break;
        }
    }
}
void moveleft(int &x, int &y, int rows, int columns)
{
    while (true)
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
        else if (y - 1 >= 0 && board[x][y - 1] == 'h')
        {
            board[x][y] = '.';
            y--;
            board[x][y] = 'A';
            alienHealth = alienHealth + 20;
            cout << " " << endl;
            cout << "Alien finds a Healthpack!" << endl;
            cout << "You gained 20 Health!" << endl;
            cout << " " << endl;
            myPause();
            break;
        }
        else if (y - 1 >= 0 && board[x][y - 1] == 'r') // Path with rock
        {
            board[x][y] = '.';
            y--;
            board[x][y] = 'A';
            cout << " " << endl;
            cout << "You hit a rock!" << endl;
            cout << " " << endl;
            myPause();
            rockrandomobject(x, y, rows, columns);
            cout << " " << endl;
            break;
        }
        else if (y - 1 >= 0 && board[x][y - 1] == '<')
        {
            board[x][y] = '.';
            y--;
            board[x][y] = 'A';
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "Alien finds a left arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            myPause();
            moveleft(x, y, rows, columns);
            break;
        }
        else if (y - 1 >= 0 && board[x][y - 1] == '>')
        {
            board[x][y] = '.';
            y--;
            board[x][y] = 'A';
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "Alien finds a right arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            myPause();
            moveright(x, y, rows, columns);
            break;
        }
        else if (y - 1 >= 0 && board[x][y - 1] == '^')
        {
            board[x][y] = '.';
            y--;
            board[x][y] = 'A';
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "Alien finds an up arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            myPause();
            moveup(x, y, rows, columns);
            break;
        }
        else if (y - 1 >= 0 && board[x][y - 1] == 'v')
        {
            board[x][y] = '.';
            y--;
            board[x][y] = 'A';
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "Alien finds a down arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            myPause();
            movedown(x, y, rows, columns);
            break;
        }
        else
        {
            cout << " " << endl;
            cout << "Alien hits a wall!" << endl;
            cout << " " << endl;
            myPause();
            break;
        }
    }
}
void moveright(int &x, int &y, int rows, int columns)
{
    while (true)
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
        else if (y + 1 < columns && board[x][y + 1] == 'h')
        {
            board[x][y] = '.';
            y++;
            board[x][y] = 'A';
            alienHealth = alienHealth + 20;
            cout << " " << endl;
            cout << "Alien finds a Healthpack!" << endl;
            cout << "You gained 20 Health!" << endl;
            cout << " " << endl;
            myPause();
            break;
        }
        else if (y + 1 < columns && board[x][y + 1] == 'r') // Path with rock
        {
            board[x][y] = '.';
            y++;
            board[x][y] = 'A';
            cout << " " << endl;
            cout << "You hit a rock!" << endl;
            cout << " " << endl;
            myPause();
            rockrandomobject(x, y, rows, columns);
            cout << " " << endl;
            break;
        }
        else if (y + 1 < columns && board[x][y + 1] == '<')
        {
            board[x][y] = '.';
            y++;
            board[x][y] = 'A';
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "Alien finds a left arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            myPause();
            moveleft(x, y, rows, columns);
            break;
        }
        else if (y + 1 < columns && board[x][y + 1] == '>')
        {
            board[x][y] = '.';
            y++;
            board[x][y] = 'A';
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "Alien finds a right arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            myPause();
            moveright(x, y, rows, columns);
            break;
        }
        else if (y + 1 < columns && board[x][y + 1] == '^')
        {
            board[x][y] = '.';
            y++;
            board[x][y] = 'A';
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "Alien finds an up arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            myPause();
            moveup(x, y, rows, columns);
            break;
        }
        else if (y + 1 < columns && board[x][y + 1] == 'v')
        {
            board[x][y] = '.';
            y++;
            board[x][y] = 'A';
            alienAttack = alienAttack + 20;
            cout << " " << endl;
            cout << "Alien finds a down arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            myPause();
            movedown(x, y, rows, columns);
            break;
        }
        else
        {
            cout << " " << endl;
            cout << "Alien hits a wall!" << endl;
            cout << " " << endl;
            myPause();
            break;
        }
    }
}

void rockrandomobject(int &x, int &y, int rows, int columns)
{
    srand((unsigned)time(NULL));
    char objects[] = {'h', '<', '>', '^', 'v'};
    char randomobjects = objects[rand() % size(objects)];
    char randomobject = randomobjects;
    switch (randomobject)
    {
    case 'h':
        alienHealth = alienHealth + 20;
        cout << " " << endl;
        cout << "Alien finds a Healthpack!" << endl;
        cout << "You gained 20 Health!" << endl;
        cout << " " << endl;
        myPause();
        break;
    case '<':
        cout << " " << endl;
        cout << "Alien finds a left arrow" << endl;
        cout << " " << endl;
        myPause();
        moveleft(x, y, rows, columns);
        break;
    case '>':
        cout << " " << endl;
        cout << "Alien finds a right arrow" << endl;
        cout << " " << endl;
        myPause();
        moveright(x, y, rows, columns);
        break;
    case '^':
        cout << " " << endl;
        cout << "Alien finds an up arrow" << endl;
        cout << " " << endl;
        myPause();
        moveup(x, y, rows, columns);
        break;
    case 'v':
        cout << " " << endl;
        cout << "Alien finds a down arrow" << endl;
        cout << " " << endl;
        myPause();
        movedown(x, y, rows, columns);
        break;
    }
}

void displayAlien()
{
    cout << "Alien Health: " << alienHealth;
    cout << " Alien Attack: " << alienAttack << endl;
}
void MoveAlien(int &x, int &y, int rows, int columns)
{
    string direction;
    cout << "- Input a direction you want to move the alien by using \"up\", \"down\", \"left\", \"right\"" << endl;
    cout << "- Change an arrow's direction using the command \"arrow\"" << endl;
    cout << "- For an brief tutorial, use the \"help\" command" << endl;
    cout << "=> ";
    cin >> direction;

    if (direction == "up") // UP Input
    {
        while (true)
        {
            moveup(x, y, rows, columns);
            ClearScreen();
            changeTrail(x, y, rows, columns);
            break;
        }
    }
    else if (direction == "down")
    { // DOWN Input
        while (true)
        {
            movedown(x, y, rows, columns);
            ClearScreen();
            changeTrail(x, y, rows, columns);
            break;
        }
    }
    else if (direction == "left")
    { // LEFT Input
        while (true)
        {
            moveleft(x, y, rows, columns);
            ClearScreen();
            changeTrail(x, y, rows, columns);
            break;
        }
    }
    else if (direction == "right") // RIGHT Input
    {
        while (true)
        {
            moveright(x, y, rows, columns);
            ClearScreen();
            changeTrail(x, y, rows, columns);
            break;
        }
    }
    else if (direction == "help")
    {
        ClearScreen();
        helpPage1();
        cout << endl;
        myPause();
        ClearScreen();
        helpPage2();
        cout << endl;
        myPause();
        ClearScreen();
        helpPage3();
        cout << endl;
        myPause();
        ClearScreen();
        helpPage4();
        cout << endl;
        myPause();
        ClearScreen();
        helpPage5();
        cout << endl;
        myPause();
        ClearScreen();
    }
    else if (direction == "arrow")
    {
        changeArrow(x, y, rows, columns);
        ClearScreen();
    }
    else if (direction == "quit")
    {
        cout << " " << endl;
        cout << "Thanks for playing!" << endl;
        cout << " " << endl;
        myPause();
        abort();
    }
    else
    {
        cout << " " << endl;
        cout << "Invalid input!" << endl;
        cout << " " << endl;
    }
}
