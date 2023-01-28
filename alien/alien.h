#ifndef ALIEN_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define ALIEN_H
int alienhp();
void MoveAlien(int &x, int &y, int rows, int columns);
void moveleft(int &x, int &y, int rows, int columns);
void moveright(int &x, int &y, int rows, int columns);
void moveup(int &x, int &y, int rows, int columns);
void movedown(int &x, int &y, int rows, int columns);
void rockrandomobject(int &x, int &y, int rows, int columns);
void displayAlien();
#endif