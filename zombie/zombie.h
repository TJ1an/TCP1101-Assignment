#ifndef ZOMBIE_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define ZOMBIE_H
#include <vector>

class Zombie {
public:
    // Functions
    void Stats(std::vector<Zombie>&zombieList, int i);
    void GenerateZombie(int count);
    void readAndDisplay(std::vector<Zombie>zombieList);
    void moveZombie();
    void Location(int x, int y,std::vector<Zombie>&zombieList, int i);
    
    // Variables
    int zombieHealth;
    int zombieAttack;
    int zombieRange;
    int zom_dimX, zom_dimY;
    std::vector<Zombie>zombieList;  // List of zombies
};

#endif