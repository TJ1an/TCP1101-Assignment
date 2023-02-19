#include "alien/alien.h"
#include "zombie/zombie.h"
#include "interaction/inter.h"
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

void CreateBoard(int rows, int columns, int zombie, Alien &ex_alien, Zombie &ex_zomb, vector<vector<char>> &ex_board)
{
    srand((unsigned)time(NULL)); // Initialise the rng
    //Create Alien
    Alien alien;
    // Alien location set
    int x = rows/2;
    int y = columns/2;

    // Zombie(s) Object Created into zombieList
    Zombie zomb;
    if(!ex_alien.set || !ex_zomb.set || !ex_board.size() || !(ex_board.size() == rows && ex_board[0].size() == columns)) { // No data loaded/Invalid data loaded
        // List (and probability) of rock and powerup generation
        // "r" for Rock and "!" for powerup
        char Obj[] = {'^', 'v', '<', '>', ' ', 'p', 'p', 'h', 'r', ' ',' ',' ',' ',' '};
        int noOfObj = size(Obj);
        int zombieSpawns = 0; // Number of zombies spawned
        int count = 49; // Starts at '1' (for zombie spawning)

        for (int row = 0; row < rows; ++row)
            for (int col = 0; col < columns; ++col)
            {
                // Rock and Powerup randomizer
                int noObj = rand() % noOfObj;
                board[row][col] = Obj[noObj];
            }
        // Alien stats set
        alien.set = true;
        alien.alienStat(alien, rows, columns);
        alien.coordinates(alien, x, y);
        // Spawns Alien on board
        board[rows / 2][columns / 2] = 'A';

        zomb.set = true;
        zomb.GenerateZombie(zombie);

        while(zombieSpawns < zombie) {  // Spawns zombies based on input
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
        // Pass the generated data to the menu loop for saving purposes
        ex_alien = alien;
        ex_zomb = zomb;
        ex_board = board;
    }
    else { // Valid data loaded -> restore
        alien = ex_alien;
        zomb = ex_zomb;
        board = ex_board;
        x = alien.ali_dimX;
        y = alien.ali_dimY;
    }
    
    ShowGameBoard(rows, columns, zombie, zomb, alien);
    // Starts the game
    bool playing = true;
    while(playing) {
        bool alive = true;
        while (true) {
            // Alien turn
            MoveAlien(alien, x, y, rows, columns, zombie, zomb, board);
            alien.coordinates(alien,x,y);
            ShowGameBoard(rows, columns, zombie, zomb, alien);
            myPause();

            // Auto kill zombies 
            //autoKill(zomb);

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

                playing = false;
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
                return;
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
        while (true) {
            cout << "Would you like to play again? (y/n)" << endl;
            cout << "=> ";
            string again;
            cin >> again;
            if (again == "y") {
                ClearScreen();
                cout << "Alright let's kill some zombies!"<< endl;
                myPause();
                return;

            } else if (again == "n") {
                ClearScreen();
                cout << "Thanks for playing!"<< endl;
                myPause();
                playing = false;
                abort();
            } else {
                cout << "That's not a valid input."<< endl;
                cout << " " << endl;
            }
        }
    }
}

void GameSettings(int &rows, int &columns, int &zombie, Alien &ex_alien, Zombie &ex_zomb, vector<vector<char>> &ex_board)
{
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
        // Entities
        Alien alien;
        Zombie zomb;
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
        //Board dimensions accepts odd numbers ONLY + Max 3 Zombies ONLY
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
        //Resizing the board 
        board.resize(rows);
        for (int i = 0; i < rows; ++i)
        {
            board[i].resize(columns);
        }
        cout << "\nSettings Updated" << endl;
        Pause();
        ClearScreen();
        CreateBoard(rows, columns, zombie, ex_alien, ex_zomb, ex_board);
        ShowGameBoard(rows, columns, zombie, zomb, alien);
        
    }
    else if (yesorno == 'n')

    {   
        // Entities
        Zombie zomb;
        Alien alien;
        // Code execution
        board.resize(rows);
        for (int i = 0; i < rows; ++i)
        {
            board[i].resize(columns);
        }
        ClearScreen();
        CreateBoard(rows, columns, zombie, ex_alien, ex_zomb, ex_board);
        ShowGameBoard(rows, columns, zombie, zomb, alien);
    }
    else
    {
        cout << "Invalid input" << endl;
    }
}