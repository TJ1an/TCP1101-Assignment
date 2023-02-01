#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "zombie.h"
using namespace std;

extern vector< vector<char> > board;

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

void Zombie::GenerateZombie(int count) {
    for (int i = 0; i < count; i++){
        Zombie zomb;
        zombieList.push_back(zomb);
    }
}
void Zombie::readAndDisplay(int count) {
    for (int i = 0; i < count; i++) {
        Zombie zomb = zombieList[i]; // Reading zombieList
        cout << " HP: " << zomb.zombieHealth
        << " Attack: " << zomb.zombieAttack
        << " Range: " << zomb.zombieRange << endl;
    }    
}

void Zombie::moveZombie() {

} 

void Zombie::Location(int x, int y) {
    this->zom_dimX = x;
    this->zom_dimY = y;
}





