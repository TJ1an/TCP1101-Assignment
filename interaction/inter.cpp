#include <string>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "../zombie/zombie.h"
#include "../alien/alien.h"
using namespace std;

extern vector< vector<char> > board;

void zombieAttack(std::vector<Zombie>zombieList,Alien &alien,int i) {
    // Notes alien position
    int x1 = alien.ali_dimX;
    int y1 = alien.ali_dimY;
    // Notes zombie stats and position
    int range = zombieList[i].zombieRange;
    int attack = zombieList[i].zombieAttack;
    int x2 = zombieList[i].zom_dimX;
    int y2 = zombieList[i].zom_dimY;

    // If Alien in range
    double distance = sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
    if (distance <= range) {
        cout << "Alien has been attacked by Zombie " << i+1 << "!" <<endl;
        cout << attack << " damage taken." << endl;
        alien.alienHealth-=attack;
    }
}

void alienAttack(std::vector<Zombie>&zombieList,Alien &alien)
{
    int x1 = alien.ali_dimX;
    int y1 = alien.ali_dimY;
    double nearest = std::numeric_limits<double>::max(); // initialize to a large number
    int closestIndex = -1;

    for (int i = 0; i < zombieList.size(); i++) {
        int x2 = zombieList[i].zom_dimX;
        int y2 = zombieList[i].zom_dimY;
        double distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

        if (distance < nearest) {
            nearest = distance;
            closestIndex = i;
        }
    }
    zombieList[closestIndex].zombieHealth = zombieList[closestIndex].zombieHealth - alien.alienAttack;
    cout << " " << endl;
    cout << "Alien attacks Zombie "<< closestIndex + 1 << " for " << alien.alienAttack << " damage." endl;
    cout << " " << endl;
}
