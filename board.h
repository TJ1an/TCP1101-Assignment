#ifndef BOARD_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define BOARD_H

#include <vector>
#include "zombie/zombie.h"
#include "alien/alien.h"
using namespace std;

int Pause();
int ClearScreen();

void changeTrail(int &x, int &y, int rows, int columns);
bool ifWin(Zombie zomb);
void autoKill(Zombie &zomb);

void turnDisplay(Zombie &zomb, Alien &alien, int turn);
void ShowGameBoard(int rows, int columns, int zombie, Zombie &zomb, Alien &alien);
void playGame(int rows, int columns, int zombie, Alien &alien, Zombie &zomb, vector<vector<char>> &board);
void CreateBoard(int rows, int columns, int zombie, Alien &alien, Zombie &zomb, vector<vector<char>> &board);
void loadGame(int &rows, int &columns, int &zombie, Alien &alien, Zombie &zomb, vector<vector<char>> &board);
void GameSettings(int &rows, int &columns, int &zombie, Alien &alien, Zombie &zomb, vector<vector<char>> &board);

#endif