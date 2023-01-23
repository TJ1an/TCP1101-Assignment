#include "alien/alien.h"
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

vector<vector<char>> board;

int ClearScreen()
{
#if defined(_WIN32)
    return system("cls");
#elif defined(__linux__) || defined(__APPLE__)
    return system("clear");
#endif
}

int Pause()
{
#if defined(_WIN32)
    return system("pause");
#elif defined(__linux__) || defined(__APPLE__)
    return system(R"(read -p "Press any key to continue . . . " dummy)");
#endif
}

void ShowGameBoard(int rows, int columns, int Zombie)
{
    for (int row = 0; row < rows; ++row)
    {
        // Displaying the top border
        for (int col = 0; col < columns; ++col)
        {
            cout << "+-";
        }
        cout << "+";
        cout << endl;
        // Displaying content (including their LEFT and RIGHT borders)
        for (int col = 0; col < columns; ++col)
        {
            cout << "|";
            cout << board[row][col];
        }
        cout << "|";
        cout << endl;
    }
    // Displaying the final bottom border
    for (int col = 0; col < columns; ++col)
    {
        cout << "+-";
    }
    cout << "+";
    cout << endl;
}

void CreateBoard(int rows, int columns, int Zombie)
{
    srand((unsigned)time(NULL));

    // List (and probability) of rock and powerup generation
    // "r" for Rock and "!" for powerup
    char Obj[] = {'^', 'v', '<', '>', ' ', ' ', ' ', 'h', 'r', 'r', 'p',' ',' ',' ',' '};
    int noOfObj = size(Obj);
    int zombieSpawns = 0;
    for (int row = 0; row < rows; ++row)
        for (int col = 0; col < columns; ++col)
        {
            // Rock and Powerup randomizer
            int noObj = rand() % noOfObj;
            board[row][col] = Obj[noObj];
        }
    board[rows / 2][columns / 2] = 'A'; // Spawns Alien
    // Zombie Spawning
    while (zombieSpawns < Zombie) { //Spawns a maximum number of Zombies
        int x = rand() % rows;
        int y = rand() % columns;
        if (board[x][y] == 'Z' ){ //Rerolls x,y dimensions if Zombie is present in point.
            x = rand() % rows;
            y = rand() % columns;
        }
        else {
            board [x][y] = 'Z'; //Places zombie based on radomizer
        }
        zombieSpawns++;
    }
    ShowGameBoard(rows, columns, Zombie);
    int x = rows / 2, y = columns / 2;
    while (true)
    {
        MoveAlien(x, y, rows, columns);
        ShowGameBoard(rows, columns, Zombie);
    }
}

void GameSettings(int &rows, int &columns, int Zombie)
{
    char yesorno;
    cout << "Default game setttings  \n"<< endl;
    cout << "---------------------- \n"<< endl;
    cout << "board rows : " << rows << endl;
    cout << "board columns : " << columns << endl;
    cout << "zombie count : " << Zombie << endl;
    cout << " " << endl;
    cout << "do you want to change the game settings? (y/n) => ";
    cin >> yesorno;

    if (yesorno == 'y')
    {
        int newRows;
        int newColumns;
        int newZombies;
        ClearScreen();
        cout << "Board Settings \n" << endl;
        cout << "-------------- \n"<< endl;
        //Input the new rows and columns
        cout << "Board rows : ";
        cin >> newRows;
        cout << "Board columns : ";
        cin >> newColumns;
        cout << "No of zombies : ";
        cin >> newZombies;
        //Board dimensions accepts odd numbers ONLY + Max 3 Zombies ONLY
        while(!(newRows%2==1 && newColumns%2==1 && newZombies<=3)){
            cout << "Both numbers are not ODD or Zombies beyond 3" <<endl;
            cout << "Board rows : ";
            cin >> newRows;
            cout << "Board columns : ";
            cin >> newColumns;
            cout << "No of zombies : ";
            cin >> newZombies;
        }
        rows = newRows;
        columns = newColumns;
        Zombie = newZombies;
        //Resizing the board 
        board.resize(rows);
        for (int i = 0; i < rows; ++i)
        {
            board[i].resize(columns);
        }
        cout << "\nSettings Updated" << endl;
        Pause();
        ClearScreen();
        CreateBoard(rows, columns, Zombie);
        ShowGameBoard(rows, columns, Zombie);
        
    }
    else if (yesorno == 'n')

    {
        board.resize(rows);
        for (int i = 0; i < rows; ++i)
        {
            board[i].resize(columns);
        }
        ClearScreen();
        CreateBoard(5, 5, 1);
        ShowGameBoard(5, 5, 1);
    }
    else
    {
        cout << "Ever considered puttin y/n only? " << endl;
    }
}