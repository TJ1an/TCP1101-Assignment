#ifndef ZOMBIE_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define ZOMBIE_H

class Zombie {
public:
    void Stats(int zombieHealth, int zombieAttack, int zombieRange);
    void moveZombie();
private:
    int zombieHealth;
    int zombieAttack;
    int zombieRange;
    int zom_dimX;
    int zom_dimY;
};

#endif