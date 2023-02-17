#ifndef INTER_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define INTER_H

#include <vector>
#include "../alien/alien.h"
#include "../zombie/zombie.h"

void zombieAttack(std::vector<Zombie>zombieList,Alien &alien,int i);

#endif