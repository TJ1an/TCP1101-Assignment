#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "zombie.h"

using namespace std;

extern vector< vector<char> > board;

void Zombie::Stats(std::vector<Zombie>&zombieList, int i) {
    //Range of Stats
    int zombieHPs[] = {100,150,200,250};
    int zombieATKs[] = {10,15,20,25};
    int zombieRGs[] = {1,2,3};
    //Randomizer
    int randomHP= zombieHPs[rand()% size(zombieHPs)];
    int randomATK= zombieATKs[rand()% size(zombieATKs)];
    int randomRG= zombieRGs[rand()% size(zombieRGs)];
    //Stats
    zombieList[i].zombieHealth = randomHP;
    zombieList[i].zombieAttack = randomATK;
    zombieList[i].zombieRange = randomRG;
}

void Zombie::GenerateZombie(int count) {
    for (int i = 0; i < count; i++){
        Zombie zomb;
        zombieList.push_back(zomb);
    }
}

void Zombie::readAndDisplay(std::vector<Zombie>zombieList) {
    for (int i = 0; i < size(zombieList); i++)
    cout << "Zombie " << i+1 
    << " HP: " << zombieList[i].zombieHealth
    << " Attack: " << zombieList[i].zombieAttack
    << " Range: " << zombieList[i].zombieRange << endl;
}

void Zombie::moveZombie() {

} 

void Zombie::Location(int x, int y,std::vector<Zombie>&zombieList, int i) {
    zombieList[i].zom_dimX = x;
    zombieList[i].zom_dimY = y;   
}





