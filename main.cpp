// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TxxL 
// Names: MEMBER_NAME_1 | MEMBER_NAME_2 | MEMBER_NAME_3 
// IDs: MEMBER_ID_1 | MEMBER_ID_2 | MEMBER_ID_3 
// Emails: MEMBER_EMAIL_1 | MEMBER_EMAIL_2 | MEMBER_EMAIL_3 
// Phones: MEMBER_PHONE_1 | MEMBER_PHONE_2 | MEMBER_PHONE_3 
// ********************************************************* 

// TODO: Fill in the missing information above and delete this line.
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