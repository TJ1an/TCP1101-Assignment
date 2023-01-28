#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "zombie.h"
using namespace std;

extern vector< vector<char> > board;


void zombieSpawn() {
    
}

void Zombie::Stats() {
    //Range of Stats
    int zombieHPs[] = {100,150,200,250};
    int zombieATKs[] = {10,15,20,25};
    int zombieRGs[] = {1,2,3};
    //Randomizer
    int randomHP= zombieHPs[rand()% size(zombieHPs)];
    int randomATK= zombieATKs[rand()% size(zombieATKs)];
    int randomRG= zombieRGs[rand()% size(zombieRGs)];
    //Stats
    this->zombieHealth= randomHP;
    this->zombieAttack= randomATK;
    this->zombieRange= randomRG;
}

void Zombie::Location(int x, int y) {
    this->zom_dimX = x;
    this->zom_dimY = y;
}

void Zombie::displayStats() {
    cout << "HP: " <<zombieHealth << " ATK: " << zombieAttack << " R: "<< zombieRange << " dimX: " <<  zom_dimX << " dimY: "<< zom_dimY <<endl;
}

void Zombie::moveZombie() {
    
} 

