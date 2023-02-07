#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "zombie.h"
using namespace std;

extern vector< vector<char> > board;

bool gotEntityObject(int x,int y) {
    char EntityObject[] = {'1','2','3','4','5','6','7','8','9','A'}; //Possible entities
    //Iterates through entity array for possible entities
    bool gotEntity = false;
    for (int i = 0; i < sizeof(EntityObject); i++) { 
        if (board[x][y] == EntityObject[i]){
            gotEntity = true;
            break;
        }
    }
    return gotEntity;
}

void moveUp(int x, int y, int i) {
    board[x][y] = ' ';
    x--;
    board[x][y] = i+1;
}

void moveDown(int x, int y, int i) {
    board[x][y] = ' ';
    x++;
    board[x][y] = i+1;
}

void moveLeft(int x, int y, int i) {
    board[x][y] = ' ';
    y--;
    board[x][y] = i+1;
}

void moveRight(int x, int y, int i) {
    board[x][y] = ' ';
    y++;
    board[x][y] = i+1;
}

bool isStuck(int x, int y) {
    // Checks surrounding 
    bool gotUp = gotEntityObject(x-1,y);
    bool gotDown = gotEntityObject(x+1,y);
    bool gotLeft = gotEntityObject(x,y-1);
    bool gotRight = gotEntityObject(x,y+1);
    // Delivers verdict
    if (gotUp && gotDown && gotLeft && gotRight) {
        return true;
    } else {
        return false;
    }
}

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

void Zombie::moveZombie(std::vector<Zombie>&zombieList,int i) {
    string movements[] = {"up","down","left","right"};
    bool moveIncomplete = true;
    // Taking zombie position
    int x = zombieList[i].zom_dimX;
    int y = zombieList[i].zom_dimY;

    //To check if zombie stuck
    bool stuck = isStuck(x,y);

    // Exit if stuck
    if (stuck) {
        cout << "Zombie " << i+1 << " is stuck." <<endl;
        return;
    }

    // Loop to make sure zombie moves
    while (moveIncomplete) {
        // Randomizer and reroller (if only specific spot is blocked)
        string move = movements[rand()%size(movements)];
        // Movement cases (Move UP)
        if (move == "up") { 
            bool gotEntity = gotEntityObject(x-1,y);
            if (gotEntity = false) {
                moveUp(x,y,i);
                Location(x,y,zombieList,i);
                moveIncomplete = false;
            } else {}

        // Move DOWN        
        } else if  (move == "down") { 
            bool gotEntity = gotEntityObject(x+1,y);
            if (gotEntity = false) {
                moveDown(x,y,i);
                Location(x,y,zombieList,i);
                moveIncomplete = false;
            } else {}

        // Move LEFT    
        } else if (move == "left") { 
            bool gotEntity = gotEntityObject(x,y-1);
            if (gotEntity = false) {
                moveLeft(x,y,i);
                Location(x,y,zombieList,i);
                moveIncomplete = false;
            } else {}

        // Move RIGHT
        } else if (move == "right") { 
            bool gotEntity = gotEntityObject(x,y+1);
            if (gotEntity = false) {
                moveRight(x,y,i);
                Location(x,y,zombieList,i);
                moveIncomplete = false;
            } else {}
        }
    }
}

void Zombie::Location(int x, int y,std::vector<Zombie>&zombieList, int i) {
    zombieList[i].zom_dimX = x;
    zombieList[i].zom_dimY = y;   
}


