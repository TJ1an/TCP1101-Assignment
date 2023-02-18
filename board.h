#ifndef BOARD_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define BOARD_H
#include <vector>
#include "zombie/zombie.h"
#include "alien/alien.h"
int Pause();
int ClearScreen();
void ShowGameBoard(int rows, int columns, int zombie, Zombie &zomb, Alien &alien);
void CreateBoard(int rows, int columns, int zombie, Alien &ex_alien, Zombie &ex_zomb, std::vector<std::vector<char>> &ex_board);
void GameSettings(int&, int&, int&, Alien&, Zombie&, std::vector<std::vector<char>> &ex_board);
#endif