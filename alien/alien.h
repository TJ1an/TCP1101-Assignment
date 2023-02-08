#ifndef ALIEN_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define ALIEN_H
#include <vector>
#include "../zombie/zombie.h"

int alienhp();

class Alien {
public:
    // Variables
    int alienHealth;
    int alienAttack;
    int ali_dimX, ali_dimY;

    void coordinates(Alien &alien, int x, int y) {
        alien.ali_dimX = x;
        alien.ali_dimX = y;
    };
    void alienStat(Alien &alien, int rows, int columns ) {
        alien.alienHealth = alienhp();
        alien.alienAttack = 0;
        alien.ali_dimX = rows/2;
        alien.ali_dimY = columns/2;
    };
};

void displayAlien(Alien &alien);
void MoveAlien(Alien &alien,int &x, int &y, int rows, int columns);
void moveleft(Alien &alien,int &x, int &y, int rows, int columns);
void moveright(Alien &alien,int &x, int &y, int rows, int columns);
void moveup(Alien &alien,int &x, int &y, int rows, int columns);
void movedown(Alien &alien,int &x, int &y, int rows, int columns);
void rockrandomobject(Alien &alien,int &x, int &y, int rows, int columns);
void changeArrow(Alien &alien,int &x, int &y, int rows, int columns);
void myPause();
void displayAlien();

#endif