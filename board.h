#ifndef BOARD_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define BOARD_H
int Pause();
int ClearScreen();
void ShowGameBoard(int rows, int columns);
void CreateBoard(int rows, int columns);
void GameSettings(int &rows, int &columns);
#endif