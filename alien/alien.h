#ifndef ALIEN_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define ALIEN_H
#include <vector>
#include "../zombie/zombie.h"

int alienhp();

class Alien {
public:
    // Variables
    bool set;
    int alienHealth;
    int alienAttack;
    int ali_dimX, ali_dimY;

    void coordinates(Alien &alien, int x, int y) {
        alien.ali_dimX = x;
        alien.ali_dimY = y;
    };
    void alienStat(Alien &alien, int rows, int columns ) {
        alien.alienHealth = alienhp();
        alien.alienAttack = 0;
    };
};

void displayAlien(Alien &alien);
void MoveAlien(Alien &alien,int &x, int &y, int rows, int columns, int zombies, Zombie &zomb, std::vector<std::vector<char>> &ex_board);
void moveleft(Alien &alien,int &x, int &y, int rows, int columns, int zombies, Zombie &zomb);
void moveright(Alien &alien,int &x, int &y, int rows, int columns, int zombies, Zombie &zomb);
void moveup(Alien &alien,int &x, int &y, int rows, int columns, int zombies, Zombie &zomb);
void movedown(Alien &alien,int &x, int &y, int rows, int columns, int zombies, Zombie &zomb);
void rockrandomobject(Alien &alien,int &x, int &y, int rows, int columns, int zombies, Zombie &zomb);
void changeArrow(Alien &alien,int &x, int &y, int rows, int columns, int zombies, Zombie &zomb);
void myPause();
void displayAlien();

#endif