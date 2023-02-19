#include "alien/alien.h"
#include "zombie/zombie.h"
#include "interaction/inter.h"
#include "board.h"
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

extern vector<vector<char>> board;

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

void changeTrail(int &x, int &y, int rows, int columns)
{
    srand((unsigned)time(NULL));
    char objects[] = {'h', '<', '>', '^', 'v', 'r', 'p', ' ',' '};
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

bool ifWin(Zombie zomb) {
    int kill = 0;
    for (int i = 0; i < zomb.zombieList.size(); i++) {
        if (zomb.zombieList[i].zombieHealth <= 0) {
            kill++;
        }
    }
    if (kill == zomb.zombieList.size()) {
        return true;
    } else {
        return false;
    }
}

void resetBoard(int &rows, int &columns, int &zombie, Alien &alien, Zombie &zomb, vector<vector<char>> &board) 
{
    Alien newAlien;
    Zombie newZomb;
    vector<vector<char>> newboard;
    rows = 5;
    columns = 13;
    zombie = 3;
    alien = newAlien;
    zomb = newZomb;
    board = newboard;
}

void autoKill(Zombie &zomb) { //Admin function to kill all zombies after a turn to test
    for (int i = 0; i < zomb.zombieList.size(); i++) {
        zomb.zombieList[i].zombieHealth = 0;
    }
    cout << endl;
    cout << "All zombies have been killed" << endl;
    myPause();
}

void ShowGameBoard(int rows, int columns, int zombie, Zombie &zomb, Alien &alien)
{
    //For ".: Alien Vs Zombie :." text tries to center itself
    for (int spaces = 0; spaces <= (((columns + 1) + ((columns - 1) * 3)) / 2) - 10; ++spaces)
    {
        cout << " ";
    }
    cout << " .: Alien Vs Zombie :." << endl;

    for (int row = 0; row < rows; ++row)
    {
        // Displaying the top border
        cout << " ";
        for (int col = 0; col < columns; ++col)
        {
            cout << "+---";
        }
        cout << "+";
        cout << endl;
        // Displaying content (including their LEFT and RIGHT borders)
        for (int col = 0; col < columns; ++col)
        {
            cout << " | ";
            cout << board[row][col];
        }
        cout << " | ";

        // Displaying the row number
        cout << " " << row + 1;

        cout << endl;
        
    }
    // Displaying the final bottom border
    cout << " ";
    for (int col = 0; col < columns; ++col)
    {
        cout << "+---";
    }

    // Displaying the final "+" edge for the board
    cout << "+"; 
    cout << endl;

    // Displaying the column number
        // First row code
    cout << "  ";
    for (int columnNumber1 = 0; columnNumber1 < columns; ++columnNumber1)
    {
        cout << " " << (columnNumber1 + 1) / 10 << "  ";
    }
    cout << endl;

        // Second row code
    cout << "  ";
    for (int columnNumber2 = 1; columnNumber2 <= columns; ++columnNumber2) 
    {
        if (columnNumber2 < 10){
        cout << " " << columnNumber2 << "  ";
        }

        else if (columnNumber2 >= 10) {
            cout << " " << columnNumber2 % 10 << "  ";
        }
    }
    cout << endl;
    cout << endl;
    // Display alien stats
    cout << " ";
    displayAlien(alien);
    cout << endl;
    // Generates and displays zombie stats
    zomb.readAndDisplay(zomb.zombieList);
    cout << endl;
    
}

void playGame(int rows, int columns, int zombie, Alien &alien, Zombie &zomb, vector<vector<char>> &board) 
{
    // Sets alien location
    int x = alien.ali_dimX;
    int y = alien.ali_dimY;
    // Starts the game
    bool alive = true;
    while (true) {
        // Alien turn
        MoveAlien(alien, x, y, rows, columns, zombie, zomb, board);
        alien.coordinates(alien,x,y);
        ShowGameBoard(rows, columns, zombie, zomb, alien);
        myPause();
        // Auto kill zombies 
        autoKill(zomb);
        // Check if win
        bool win = ifWin(zomb);
        if (win) {
            ClearScreen();
            cout << "Y   Y    OOO    U   U         W   W   W   III   N   N   !" << endl;
            cout << "Y   Y   O   O   U   U         W   W   W    I    NN  N   !" << endl;
            cout << " Y Y    O   O   U   U         W   W   W    I    N N N   !" << endl;
            cout << "  Y     O   O   U   U          W  W  W     I    N  NN    " << endl;
            cout << "  Y      OOO     UUU            WW WW     III   N   N   !" << endl;
            cout << endl;
            myPause();
            break;
        }
        
        // Zombie Turn
        for (int i = 0; i < size(zomb.zombieList); i++) {
            ClearScreen();
            srand((unsigned) time(NULL));
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            cout << endl;
            // If zombie alive
            if (zomb.zombieList[i].zombieHealth > 0) { 
                zombieAttack(zomb.zombieList, alien, i); // Attack
                if (alien.alienHealth <= 0) { // Check if Alien dead
                    alive = false;
                    break;
                } 
                zomb.moveZombie(zomb.zombieList, i, rows, columns); // Move
            }
            cout << endl;
            myPause();
        }
        if (!alive) { // Defeat screen
            ClearScreen();
            cout << "Y   Y    OOO    U   U         DDD   III   EEE   DDD    !" << endl;
            cout << "Y   Y   O   O   U   U         D  D   I    E     D  D   !" << endl;
            cout << " Y Y    O   O   U   U         D  D   I    EEE   D  D   !" << endl;
            cout << "  Y     O   O   U   U         D  D   I    E     D  D    " << endl;
            cout << "  Y      OOO     UUU          DDD   III   EEE   DDD    !" << endl;
            cout << endl;
            myPause();
            break;
        }
        // Reset trail into objects
        ClearScreen();
        ShowGameBoard(rows, columns, zombie, zomb, alien);
        changeTrail(x, y, rows, columns);
        cout << " " << endl;
        cout << "Trail is reset!" << endl;
        cout << " " << endl;
        myPause();
        ClearScreen();
        ShowGameBoard(rows, columns, zombie, zomb, alien);
    }
    // Checks if play again
    while (true) {
        cout << "Would you like to play again? (y/n)" << endl;
        cout << "=> ";
        string again;
        cin >> again;
        if (again == "y") {
            ClearScreen();
            cout << "Alright let's kill some zombies!"<< endl;
            // Reinitiate values
            resetBoard(rows, columns, zombie, alien, zomb, board);
            // Runs new game
            myPause();
            GameSettings(rows, columns, zombie, alien, zomb, board);
        } else if (again == "n") {
            ClearScreen();
            cout << "Thanks for playing!"<< endl;
            myPause();
            abort();
        } else {
            cout << "That's not a valid input."<< endl;
            cout << " " << endl;
        }
    }
}

void CreateBoard(int rows, int columns, int zombie, Alien &alien, Zombie &zomb, vector<vector<char>> &board)
{
    // Creates  board template
    board.resize(rows);
    for (int i = 0; i < rows; ++i)
    {
        board[i].resize(columns);
    }
    
    srand((unsigned)time(NULL)); // Initialise the rng
    // Alien location set
    int x = rows/2;
    int y = columns/2;

    // List (and probability) of rock and powerup generation
    // "r" for rock, "p" for pod, "^","v",">","<" are arrows and "h" are healthpacks.
    char Obj[] = {'^', 'v', '<', '>', ' ', 'p', 'p', 'h', 'r', ' ',' ',' ',' ',' '};
    int zombieSpawns = 0; // Number of zombies spawned
    int count = 49; // Starts at '1' (for zombie spawning)
    // Generates objects in board
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col)
        {
            // Randomize objects
            int noObj = rand() % size(Obj);
            board[row][col] = Obj[noObj];
        }
    }

    // Alien stats set
    alien.alienStat(alien, rows, columns);
    alien.coordinates(alien, x, y);
    // Spawns Alien on board
    board[rows / 2][columns / 2] = 'A';

    // Creates zombies into a vector
    zomb.GenerateZombie(zombie);

    // Spawns zombies based on input
    while(zombieSpawns < zombie) {  
        //All possible zombie entities
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
            // Places zombie on board based on randomizer
            board[x][y] = char(count); 
            // Saves location and fully creates zombie entity 
            zomb.Location(x,y,zomb.zombieList,zombieSpawns);
            zomb.Stats(zomb.zombieList,zombieSpawns);
            // Increases key variables
            zombieSpawns++;
            count++;
        }    
    }
}

void loadGame(int &rows, int &columns, int &zombie, Alien &alien, Zombie &zomb, vector<vector<char>> &board)
{
    // Code Execution
    ClearScreen();
    ShowGameBoard(rows, columns, zombie, zomb, alien);
    playGame(rows, columns, zombie, alien, zomb, board);
}

void GameSettings(int &rows, int &columns, int &zombie, Alien &alien, Zombie &zomb, vector<vector<char>> &board)
{
    ClearScreen();
    char yesorno;
    cout << "Default game settings  \n"<< endl;
    cout << "---------------------- \n"<< endl;
    cout << "Board rows : " << rows << endl;
    cout << "Board columns : " << columns << endl;
    cout << "Zombie count : " << zombie << endl;
    cout << " " << endl;
    cout << "Do you want to change the game settings? (y/n, input \"n\" if you loaded data) => ";
    cin >> yesorno;

    if (yesorno == 'y')
    {   
        // Board dimensions and data
        int newRows;
        int newColumns;
        int newZombies;
        // Execute first display
        ClearScreen();
        cout << "Board Settings \n" << endl;
        cout << "Max: Both numbers are ODD and less than 9 Zombies" << endl;
        cout << "------------------------------------------------- \n"<< endl;
        //Input the new rows and columns
        cout << "Board rows : ";
        cin >> newRows;
        cout << "Board columns : ";
        cin >> newColumns;
        cout << "No of zombies : ";
        cin >> newZombies;
        //Board dimensions accepts odd numbers ONLY + Max 9 Zombies ONLY
        while(!(newRows%2==1 && newColumns%2==1 && newZombies<=9)){
            cout << "Both numbers are not ODD or Zombies beyond 9" <<endl;
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
        cout << "\nSettings Updated" << endl;
        Pause();
        // Code Execution
        ClearScreen();
        CreateBoard(rows, columns, zombie, alien, zomb, board);
        ShowGameBoard(rows, columns, zombie, zomb, alien);
        playGame(rows, columns, zombie, alien, zomb, board);
        
    }
    else if (yesorno == 'n')
    {   
        // Code Execution
        ClearScreen();
        CreateBoard(rows, columns, zombie, alien, zomb, board);
        ShowGameBoard(rows, columns, zombie, zomb, alien);
        playGame(rows, columns, zombie, alien, zomb, board);
    }
    else
    {
        cout << "Invalid input" << endl;
    }
}