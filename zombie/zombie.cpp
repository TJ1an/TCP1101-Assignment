#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
//#include "board.h"
#include "zombie.h"
using namespace std;

extern vector< vector<char> > board;


void zombieSpawn() {
    
}

void Zombie::Stats(int zombieHealth, int zombieAttack, int zombieRange) {
    srand((unsigned)time(NULL));
    //Range of Stats
    int zombieHPs[] = {100,150,200,250};
    int zombieATKs[] = {5,10,15,20};
    int zombieRGs[] = {1,2,3,4};
    //Randomizer
    int randomHP= zombieHPs[rand()% size(zombieHPs)];
    int randomATK= zombieATKs[rand()% size(zombieATKs)];
    int randomRG= zombieRGs[rand()% size(zombieRGs)];
    //Stats
    zombieHealth= randomHP;
    zombieAttack= randomATK;
    zombieRange= randomRG;
}

void Zombie::moveZombie() {
    
} 