#ifndef ZOMBIE_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define ZOMBIE_H
#include <vector>

class Zombie {
public:
    // Functions
    void Stats(std::vector<Zombie>&zombieList, int i);
    void GenerateZombie(int count);
    void readAndDisplay(std::vector<Zombie>zombieList);
    void moveZombie(std::vector<Zombie>&zombieList,int i, int rows, int columns);
    void Location(int x, int y,std::vector<Zombie>&zombieList, int i);
    
    // Variables
    int zombieHealth;
    int zombieAttack;
    int zombieRange;
    int zom_dimX, zom_dimY;
    std::vector<Zombie>zombieList;  // List of zombies
};

bool gotEntityObject(int x,int y);
void moveUp(int x, int y, int i);
void moveDown(int x, int y, int i);
void moveLeft(int x, int y, int i);
void moveRight(int x, int y, int i);
bool Blank(int x, int y, int rows, int columns);

#endif