#ifndef ZOMBIE_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define ZOMBIE_H
#include <vector>

class Zombie {
public:
    // Functions
    void Stats();
    void GenerateZombie(int count);
    void readAndDisplay(int count);
    void moveZombie();
    void Location(int x, int y);
    
    // Variables
    int zombieHealth;
    int zombieAttack;
    int zombieRange;
    int zom_dimX, zom_dimY;
    std::vector<Zombie>zombieList;  // List of zombies
};

#endif