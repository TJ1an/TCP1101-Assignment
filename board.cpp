#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

vector< vector<char> > board;

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

void CreateBoard(int rows,int columns)
{
    srand((unsigned) time(NULL));
    for (int row = 0; row < rows; ++row)
        for (int col = 0; col < columns; ++col)
        {
            int random_number = rand() % 2;
            if (random_number){
                board[row][col] = '*';
            }
            else{
                board[row][col] = 'r';
            }
        }
}

void ShowGameBoard(int rows, int columns)
    {
        for (int row = 0; row < rows; ++row)
        {
            //Displaying the top border
            for (int col = 0; col < columns; ++col)
            {
                cout << "+-";
            }
            cout << "+";
            cout << endl;
            //Displaying content (including their LEFT and RIGHT borders)
            for (int col = 0; col < columns; ++col)
            {
                cout << "|";
                cout << board[row][col];
            }
            cout << "|";
            cout << endl;
        }
        //Displaying the final bottom border
            for (int col = 0; col < columns; ++col)
            {
                cout << "+-";
            }
            cout << "+";
            cout << endl;            
    }

void GameSettings(int& rows, int& columns)
{
    char yesorno;
    cout << "Default game setttings  \n"
            << endl;
    cout << "---------------------- \n"
            << endl;
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
        std::cout << "Board Settings \n"
              << std::endl;
        std::cout << "-------------- \n"<< std::endl;
        std::cout << "board rows : ";
        std::cin >> newRows;
        std::cout << "board columns : ";
        std::cin >> newColumns;
        rows = newRows;
        columns = newColumns;
        board.resize(rows);
        for (int i = 0; i < rows; ++i)
        {
          board[i].resize(columns);
        }
        CreateBoard(rows, columns);
        cout << "\nSettings Updated" << endl;
        Pause();
        cout << endl;
        ShowGameBoard(rows, columns);
    }
    else if (yesorno == 'n')
    
    {
        board.resize(rows);
        for (int i = 0; i < rows; ++i)
        {
            board[i].resize(columns);
        }
        CreateBoard(5, 5);
        ShowGameBoard(5, 5);
    }
    else
    {
        cout << "bruh" << endl;
    }
}