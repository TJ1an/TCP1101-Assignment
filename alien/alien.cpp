#include "../board.h"
#include "alien.h"
#include "../help/help.h"
#include "../saveload/saveload.h"
#include "../zombie/zombie.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

extern vector<vector<char>> board;
// Alien Stats

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

void changeArrow(Alien &alien, int &x, int &y, int rows, int columns, int zombies, Zombie zomb) // prompts the user to enter row and column values to change arrow direction
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
        cout << "That is not an arrow!" << endl;
        cout << "Please try again" << endl;
        cout << " " << endl;
        changeArrow(alien,x,y,rows,columns,zombies,zomb);
    }
}

void moveup(Alien &alien, int &x, int &y, int rows, int columns, int zombie, Zombie zomb)
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
            alien.alienHealth = alien.alienHealth + 20;
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
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
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "You hit a rock!" << endl;
            cout << " " << endl;
            rockrandomobject(alien, x, y, rows, columns, zombie, zomb);
            cout << " " << endl;
            break;
        }
        else if (x - 1 >= 0 && board[x - 1][y] == '<') // Left boost/dash
        {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';
            alien.alienAttack = alien.alienAttack + 20;
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "Alien finds a left arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            moveleft(alien, x, y, rows, columns, zombie, zomb);
            myPause();
            break;
        }
        else if (x - 1 >= 0 && board[x - 1][y] == '>') // Right boost/dash
        {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';
            alien.alienAttack = alien.alienAttack + 20;
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "Alien finds a right arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            moveright(alien, x, y, rows, columns, zombie, zomb);
            break;
        }
        else if (x - 1 >= 0 && board[x - 1][y] == '^') // Up boost/dash
        {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';
            alien.alienAttack = alien.alienAttack + 20;
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "Alien finds an up arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            moveup(alien, x, y, rows, columns, zombie, zomb);
            myPause();
            break;
        }
        else if (x - 1 >= 0 && board[x - 1][y] == 'v') // Down boost/dash
        {
            board[x][y] = '.';
            x--;
            board[x][y] = 'A';
            alien.alienAttack = alien.alienAttack + 20;
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "Alien finds a down arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            movedown(alien, x, y, rows, columns, zombie, zomb);
            myPause();
            break;
        }
        else
        {
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "Alien hits a wall!" << endl;
            cout << " " << endl;
            myPause();
            break;
        }
    }
}

void movedown(Alien &alien, int &x, int &y, int rows, int columns, int zombie, Zombie zomb)
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
            alien.alienHealth = alien.alienHealth + 20;
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
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
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "You hit a rock!" << endl;
            cout << " " << endl;
            rockrandomobject(alien, x, y, rows, columns, zombie, zomb);
            cout << " " << endl;
            break;
        }
        else if (x + 1 < rows && board[x + 1][y] == '<')
        {
            board[x][y] = '.';
            x++;
            board[x][y] = 'A';
            alien.alienAttack = alien.alienAttack + 20;
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "Alien finds a left arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            moveleft(alien, x, y, rows, columns, zombie, zomb);
            myPause();
            break;
        }
        else if (x + 1 < rows && board[x + 1][y] == '>')
        {
            board[x][y] = '.';
            x++;
            board[x][y] = 'A';
            alien.alienAttack = alien.alienAttack + 20;
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "Alien finds a right arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            moveright(alien, x, y, rows, columns, zombie, zomb);
            myPause();
            break;
        }
        else if (x + 1 < rows && board[x + 1][y] == '^')
        {
            board[x][y] = '.';
            x++;
            board[x][y] = 'A';
            alien.alienAttack = alien.alienAttack + 20;
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "Alien finds an up arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            moveup(alien, x, y, rows, columns, zombie, zomb);
            myPause();
            break;
        }
        else if (x + 1 < rows && board[x + 1][y] == 'v')
        {
            board[x][y] = '.';
            x++;
            board[x][y] = 'A';
            alien.alienAttack = alien.alienAttack + 20;
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "Alien finds a down arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            movedown(alien, x, y, rows, columns, zombie, zomb);
            myPause();
            break;
        }
        else
        {
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "Alien hits a wall!" << endl;
            cout << " " << endl;
            myPause();
            break;
        }
    }
}
void moveleft(Alien &alien, int &x, int &y, int rows, int columns, int zombie, Zombie zomb)
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
            alien.alienHealth = alien.alienHealth + 20;
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
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
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "You hit a rock!" << endl;
            cout << " " << endl;
            rockrandomobject(alien, x, y, rows, columns, zombie, zomb);
            cout << " " << endl;
            break;
        }
        else if (y - 1 >= 0 && board[x][y - 1] == '<')
        {
            board[x][y] = '.';
            y--;
            board[x][y] = 'A';
            alien.alienAttack = alien.alienAttack + 20;
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "Alien finds a left arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            moveleft(alien, x, y, rows, columns, zombie, zomb);
            myPause();
            board[x][y] = '.';
            y--;
            board[x][y] = 'A';
            alien.alienAttack = alien.alienAttack + 20;
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "Alien finds a right arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            moveright(alien, x, y, rows, columns, zombie, zomb);
            myPause();
            break;
        }
        else if (y - 1 >= 0 && board[x][y - 1] == '^')
        {
            board[x][y] = '.';
            y--;
            board[x][y] = 'A';
            alien.alienAttack = alien.alienAttack + 20;
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "Alien finds an up arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            moveup(alien, x, y, rows, columns, zombie, zomb);
            myPause();
            break;
        }
        else if (y - 1 >= 0 && board[x][y - 1] == 'v')
        {
            board[x][y] = '.';
            y--;
            board[x][y] = 'A';
            alien.alienAttack = alien.alienAttack + 20;
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "Alien finds a down arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            movedown(alien, x, y, rows, columns, zombie, zomb);
            myPause();
            break;
        }
        else
        {
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "Alien hits a wall!" << endl;
            cout << " " << endl;
            myPause();
            break;
        }
    }
}
void moveright(Alien &alien, int &x, int &y, int rows, int columns, int zombie, Zombie zomb)
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
            alien.alienHealth = alien.alienHealth + 20;
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
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
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "You hit a rock!" << endl;
            cout << " " << endl;
            rockrandomobject(alien, x, y, rows, columns, zombie, zomb);
            cout << " " << endl;
            break;
        }
        else if (y + 1 < columns && board[x][y + 1] == '<')
        {
            board[x][y] = '.';
            y++;
            board[x][y] = 'A';
            alien.alienAttack = alien.alienAttack + 20;
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "Alien finds a left arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            moveleft(alien, x, y, rows, columns, zombie, zomb);
            myPause();
            break;
        }
        else if (y + 1 < columns && board[x][y + 1] == '>')
        {
            board[x][y] = '.';
            y++;
            board[x][y] = 'A';
            alien.alienAttack = alien.alienAttack + 20;
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "Alien finds a right arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            moveright(alien, x, y, rows, columns, zombie, zomb);
            myPause();
            break;
        }
        else if (y + 1 < columns && board[x][y + 1] == '^')
        {
            board[x][y] = '.';
            y++;
            board[x][y] = 'A';
            alien.alienAttack = alien.alienAttack + 20;
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "Alien finds an up arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            moveup(alien, x, y, rows, columns, zombie, zomb);
            myPause();
            break;
        }
        else if (y + 1 < columns && board[x][y + 1] == 'v')
        {
            board[x][y] = '.';
            y++;
            board[x][y] = 'A';
            alien.alienAttack = alien.alienAttack + 20;
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "Alien finds a down arrow" << endl;
            cout << "You gained 20 Attack!" << endl;
            cout << " " << endl;
            movedown(alien, x, y, rows, columns, zombie, zomb);
            myPause();
            ClearScreen();
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << " " << endl;
            cout << "Alien hits a wall!" << endl;
            cout << " " << endl;
            myPause();
            break;
        }
    }
}

void rockrandomobject(Alien &alien, int &x, int &y, int rows, int columns, int zombie, Zombie zomb)
{
    srand((unsigned)time(NULL));
    char objects[] = {'h', '<', '>', '^', 'v'};
    char randomobjects = objects[rand() % size(objects)];
    char randomobject = randomobjects;
    switch (randomobject)
    {
    case 'h':
        alien.alienHealth = alien.alienHealth + 20;
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
        moveleft(alien, x, y, rows, columns, zombie, zomb);
        break;
    case '>':
        cout << " " << endl;
        cout << "Alien finds a right arrow" << endl;
        cout << " " << endl;
        myPause();
        moveright(alien, x, y, rows, columns, zombie, zomb);
        break;
    case '^':
        cout << " " << endl;
        cout << "Alien finds an up arrow" << endl;
        cout << " " << endl;
        myPause();
        moveup(alien, x, y, rows, columns, zombie, zomb);
        break;
    case 'v':
        cout << " " << endl;
        cout << "Alien finds a down arrow" << endl;
        cout << " " << endl;
        myPause();
        movedown(alien, x, y, rows, columns, zombie, zomb);
        break;
    }
}

void displayAlien(Alien &alien) 
{
    cout << "Alien Health: " << alien.alienHealth;
    cout << " Alien Attack: " << alien.alienAttack;
    cout << " X: " << (alien.ali_dimX)+1;
    cout << " Y: " << (alien.ali_dimY)+1 <<endl;
}
void MoveAlien(Alien &alien, int &x, int &y, int rows, int columns, int zombie, Zombie zomb)
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
            moveup(alien, x, y, rows, columns, zombie, zomb);
            ClearScreen();
            break;
        }
    }
    else if (direction == "down")
    { // DOWN Input
        while (true)
        {
            movedown(alien, x, y, rows, columns, zombie, zomb);
            ClearScreen();
            break;
        }
    }
    else if (direction == "left")
    { // LEFT Input
        while (true)
        {
            moveleft(alien, x, y, rows, columns, zombie, zomb);
            ClearScreen();
            break;
        }
    }
    else if (direction == "right") // RIGHT Input
    {
        while (true)
        {
            moveright(alien, x, y, rows, columns, zombie, zomb);
            ClearScreen();
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
        ShowGameBoard(rows, columns, zombie, zomb, alien);
        MoveAlien(alien, x, y, rows, columns, zombie, zomb);
    }
    else if (direction == "arrow")
    {
        changeArrow(alien, x, y, rows, columns, zombie, zomb);
        ClearScreen();
    }
    else if (direction == "quit")
    {   
        savePrompt();
    }
    else
    {
        cout << " " << endl;
        cout << "Invalid input!" << endl;
        cout << " " << endl;
        myPause();
        ClearScreen();
        ShowGameBoard(rows, columns, zombie, zomb, alien);
        MoveAlien(alien, x, y, rows, columns, zombie, zomb);
    }
}
