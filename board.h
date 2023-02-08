#ifndef BOARD_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define BOARD_H
#include "zombie/zombie.h"
int Pause();
int ClearScreen();
void ShowGameBoard(int rows, int columns, int zombie, Zombie zomb);
void CreateBoard(int rows, int columns);
void GameSettings(int &rows, int &columns, int Zombie);
#endif