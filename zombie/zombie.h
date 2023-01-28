#ifndef ZOMBIE_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define ZOMBIE_H

class Zombie {
public:
    // Functions
    void Stats();
    void Location(int zom_dimX, int zom_dimY);
    void moveZombie();
    void displayStats();
    // Variables
    int zombieHealth;
    int zombieAttack;
    int zombieRange;
    int zom_dimX, zom_dimY;
};

#endif