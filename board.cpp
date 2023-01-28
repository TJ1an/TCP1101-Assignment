#include "alien/alien.h"
#include "zombie/zombie.h"
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

void ShowGameBoard(int rows, int columns, int zombie)
{
    cout << ".: Alien Vs Zombie :." << endl;
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
    // Display alien stats
    displayAlien();
    // Display zombie (not sure)
}

void CreateBoard(int rows, int columns, int zombie)
{
    srand((unsigned)time(NULL));
    // List (and probability) of rock and powerup generation
    // "r" for Rock and "!" for powerup
    char Obj[] = {'^', 'v', '<', '>', ' ', ' ', ' ', 'h', 'r', ' ', 'p',' ',' ',' ',' '};
    int noOfObj = size(Obj);
    int zombieSpawns = 0;
    int count = 49; // Starts at '1' (for zombie spawning)

    for (int row = 0; row < rows; ++row)
        for (int col = 0; col < columns; ++col)
        {
            // Rock and Powerup randomizer
            int noObj = rand() % noOfObj;
            board[row][col] = Obj[noObj];
        }
    board[rows / 2][columns / 2] = 'A'; // Spawns Alien

    // Zombie(s) Object Created into zombieList
    std::vector<Zombie*> zombieList;
    for(int i = 0; i < zombie; i++) {
        Zombie* zomb = new Zombie();
        zombieList.push_back(zomb);
    }

    while(zombieSpawns < zombie) {  // Spawns zombies based on input
        //All possible zombie entities
        srand((unsigned) time(NULL));
        char entities[] = {'1','2','3','4','5','6','7','8','9'}; 
        int x = rand() % rows; // Randomizes x,y dimensions
        int y = rand() % columns;
        //Iterates through entity array for possible entities
        bool gotEntity = false;
        for (int i = 0; i < sizeof(entities); i++) { 
            if (board[x][y] == entities[i]){
                gotEntity = true;
                break;
            }
        }

        if ( gotEntity || board[x][y] == 'A'){ //Rerolls x,y dimensions if entities are present in point.
            x = rand() % rows;
            y = rand() % columns;
        }
        //Executes commands if no entities on point.
        else { 
            // Places zombie based on randomizer
            board [x][y] = char(count); 
            zombieSpawns++;
            count++;
            // Saves location and fully creates zombie entity (including stats)
            zombieList[zombieSpawns]->Location(x,y);
            zombieList[zombieSpawns]->Stats();
        }    
    }
    ShowGameBoard(rows, columns, zombie);
    int x = rows/2, y = columns/2;
    // Starts the game
    while(true) {
        MoveAlien(x, y, rows, columns);
        ShowGameBoard(rows, columns, zombie);
    }
    ShowGameBoard(rows, columns, zombie);
    int x = rows/2, y = columns/2;
    while(true) {
    MoveAlien(x, y, rows, columns);
    ShowGameBoard(rows, columns, zombie);
    }
}

void GameSettings(int &rows, int &columns, int zombie)
{
    char yesorno;
    cout << "Default game settings  \n"<< endl;
    cout << "---------------------- \n"<< endl;
    cout << "Board rows : " << rows << endl;
    cout << "Board columns : " << columns << endl;
    cout << "Zombie count : " << zombie << endl;
    cout << " " << endl;
    cout << "Do you want to change the game settings? (y/n) => ";
    cin >> yesorno;

    if (yesorno == 'y')
    {
        int newRows;
        int newColumns;
        int newZombies;
        ClearScreen();
        cout << "Board Settings \n" << endl;
        cout << "Max: Both numbers are ODD and less than 3 Zombies" << endl;
        cout << "------------------------------------------------- \n"<< endl;
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
        zombie = newZombies;
        //Resizing the board 
        board.resize(rows);
        for (int i = 0; i < rows; ++i)
        {
            board[i].resize(columns);
        }
        cout << "\nSettings Updated" << endl;
        Pause();
        ClearScreen();
        CreateBoard(rows, columns, zombie);
        ShowGameBoard(rows, columns, zombie);
        
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