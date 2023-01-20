#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

vector< vector<char> > board;

int ClearScreen()
{
#if defined(_WIN32)
    return std::system("cls");
#elif defined(__linux__) || defined(__APPLE__)
    return std::system("clear");
#endif
}

int Pause()
{
#if defined(_WIN32)
    return std::system("pause");
#elif defined(__linux__) || defined(__APPLE__)
    return std::system(R"(read -p "Press any key to continue . . . " dummy)");
#endif
}

void CreateBoard(int rows,int columns)
{
    for (int row = 0; row < rows; ++row)
        for (int col = 0; col < columns; ++col)
        {
            int random_number = std::rand() % 2;
            if (random_number)
                board[row][col] = '*';
            else
                board[row][col] = 'r';
        }
}

void ShowGameBoard(int rows, int columns)
    {
        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < columns; ++col)
            {
                std::cout << board[row][col];
            }
            std::cout << std::endl;
        }

            
    }

void GameSettings(int& rows, int& columns)
{
    char yesorno;
    std::cout << "Default game setttings  \n"
              << std::endl;
    std::cout << "---------------------- \n"
              << std::endl;
    std::cout << "board rows : " << rows << std::endl;
    std::cout << "board columns : " << columns << std::endl;
    std::cout << " " << std::endl;
    std::cout << "do you want to change the game settings? (y/n) => ";
    std::cin >> yesorno;

    if (yesorno == 'y')
    {
        int newRows;
        int newColumns;
        ClearScreen();
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
        std::cout << "bruh" << std::endl;
    }
}

int main()
{
    int kRows = 5;
    int kColumns = 5;
    GameSettings(kRows, kColumns);
   
}