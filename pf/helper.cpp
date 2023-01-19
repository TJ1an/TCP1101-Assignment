#include "helper.h"
#include <cstdlib>
#include <iostream>


namespace pf
{
    const int kRows = 5;
    const int kColumns = 5;
    char kBoard[kRows][kColumns];

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

    void CreateGameBoard()
    {
        for (int row = 0; row < kRows; ++row)
        for (int col = 0; col < kColumns; ++col)
        {
            int random_number = std::rand() % 2;
            if (random_number)
                kBoard[row][col] = '*';
            else
                kBoard[row][col] = 'r';
        }
    }

    void ShowGameBoard()
    {
        for (int row = 0; row < kRows; ++row)
        {
            for (int col = 0; col < kColumns; ++col)
            {
                std::cout << kBoard[row][col];
            }
            std::cout << std::endl;
        }

            
    }

    void GameSettings(){
        char yesorno;
        std::cout << "Default game setttings  \n" << std::endl;
        std::cout << "---------------------- \n" << std::endl;
        std::cout << "board rows : " << kRows << std::endl;
        std::cout << "board columns : "<< kColumns << std::endl;
        std::cout << " " << std::endl;
        std::cout << "do you want to change the game settings? (y/n) => ";
        std::cin >> yesorno;

        if (yesorno == 'y'){
            int newRows;
            int newColumns;
            ClearScreen();
             std::cout << "board rows : ";
             std::cin >> newRows;
             std::cout << "board columns : ";
             std::cin >> newColumns;
        }
        else if (yesorno == 'n')
        {
         ClearScreen();
         CreateGameBoard();
         ShowGameBoard(); 
        }
        else
        {
          std::cout << "bruh" << std::endl;    

        }
        
        }
    }
