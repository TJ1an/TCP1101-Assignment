#include "alien.h"
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

void ShowGameBoard(int rows, int columns)
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

void CreateBoard(int rows, int columns)
{
    srand((unsigned)time(NULL));

    // List (and probability) of rock and powerup generation
    // "r" for Rock and "!" for powerup
    char Obj[] = {'^', 'V', '<', '>', ' ', ' ', ' ', 'h', ' ', ' ', ' ', 'p'};
    int noOfObj = size(Obj);
    for (int row = 0; row < rows; ++row)
        for (int col = 0; col < columns; ++col)
        {
            // Rock and Powerup randomizer
            int noObj = rand() % noOfObj;
            board[row][col] = Obj[noObj];
        }
    board[rows / 2][columns / 2] = 'A'; // Spawns Alien
    ShowGameBoard(rows, columns);
    int x = rows / 2, y = columns / 2;
    int alienattack = 0;
    int alienhealth = alienHealth();
    while (true)
    {
        MoveAlien(x, y, rows, columns, alienhealth, alienattack);
        ShowGameBoard(rows, columns);
    }
}

void GameSettings(int &rows, int &columns)
{
    char yesorno;
    cout << "Default game setttings  \n"<< endl;
    cout << "---------------------- \n"<< endl;
    cout << "board rows : " << rows << endl;
    cout << "board columns : " << columns << endl;
    cout << " " << endl;
    cout << "do you want to change the game settings? (y/n) => ";
    cin >> yesorno;

    if (yesorno == 'y')
    {
        int newRows;
        int newColumns;
        ClearScreen();
        cout << "Board Settings \n" << endl;
        cout << "-------------- \n"<< endl;
        //Input the new rows and columns
        cout << "Board rows : ";
        cin >> newRows;
        cout << "Board columns : ";
        cin >> newColumns;
        //Accepts odd numbers ONLY
        while(!(newRows%2==1 && newColumns%2==1)){
            cout << "Both numbers are not ODD" <<endl;
            cout << "Board rows : ";
            cin >> newRows;
            cout << "Board columns : ";
            cin >> newColumns;
        }
        rows = newRows;
        columns = newColumns;
        //Resizing the board 
        board.resize(rows);
        for (int i = 0; i < rows; ++i)
        {
            board[i].resize(columns);
        }
        cout << "\nSettings Updated" << endl;
        Pause();
        ClearScreen();
        CreateBoard(rows, columns);
        ShowGameBoard(rows, columns);
        
    }
    else if (yesorno == 'n')

    {
        board.resize(rows);
        for (int i = 0; i < rows; ++i)
        {
            board[i].resize(columns);
        }
        ClearScreen();
        CreateBoard(5, 5);
        ShowGameBoard(5, 5);
    }
    else
    {
        cout << "Ever considered puttin y/n only? " << endl;
    }
}