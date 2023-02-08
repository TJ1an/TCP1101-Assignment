#ifndef ALIEN_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define ALIEN_H
#include "../zombie/zombie.h"
int alienhp();
void MoveAlien(int &x, int &y, int rows, int columns, int zombie, Zombie zomb);
void moveleft(int &x, int &y, int rows, int columns, int zombie, Zombie zomb);
void moveright(int &x, int &y, int rows, int columns, int zombie, Zombie zomb);
void moveup(int &x, int &y, int rows, int columns, int zombie, Zombie zomb);
void movedown(int &x, int &y, int rows, int columns, int zombie, Zombie zomb);
void rockrandomobject(int &x, int &y, int rows, int columns, int zombie, Zombie zomb);
void changeArrow(int &x, int &y, int rows, int columns);
void myPause();
void displayAlien();
#endif