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
    board[x][y] = char('0' + (i+1));
    cout << "Zombie " << i+1 << " moved UP." << endl;
}

void moveDown(int x, int y, int i) {
    board[x][y] = ' ';
    x++;
    board[x][y] = char('0' + (i+1));
    cout << "Zombie " << i+1 << " moved DOWN." << endl;
}

void moveLeft(int x, int y, int i) {
    board[x][y] = ' ';
    y--;
    board[x][y] = char('0' + (i+1));
    cout << "Zombie " << i+1 << " moved LEFT." << endl;
}

void moveRight(int x, int y, int i) {
    board[x][y] = ' ';
    y++;
    board[x][y] = char('0' + (i+1));
    cout << "Zombie " << i+1 << " moved RIGHT." << endl;
}

bool isStuck(int x, int y,bool blankUp, bool blankDown, bool blankLeft, bool blankRight) {
    // Existing boolean to verify presence
    bool gotUp = false;
    bool gotDown = false;
    bool gotLeft = false;
    bool gotRight = false;
    // Checks surrounding (if got no blank)
    if (!(blankUp)) {
        gotUp = gotEntityObject(x-1,y);
    }
    if (!(blankDown)) {
        gotDown = gotEntityObject(x+1,y);
    }
    if (!(blankLeft)) {
        gotLeft = gotEntityObject(x,y-1);
    }
    if (!(blankRight)) {
        gotRight = gotEntityObject(x,y+1);
    }
    // Delivers verdict
    // 0 blank
    if (gotUp && gotDown && gotLeft && gotRight) {
        return true;
    // 1 blank
    } else if (gotUp && gotDown && gotLeft && blankRight) {
        return true;
    } else if (gotUp && gotDown && blankLeft && gotRight){
        return true;
    } else if (gotUp && blankDown && gotLeft && gotRight){
        return true;
    } else if (blankUp && gotDown && gotLeft && gotRight){
        return true;
    // 2 blank
    } else if (gotUp && blankDown && blankLeft && gotRight){
        return true;
    } else if (gotUp && blankDown && gotLeft && blankRight){
        return true;
    } else if (blankUp && gotDown && blankLeft && gotRight){
        return true;
    } else if (blankUp && gotDown && gotLeft && blankRight){
        return true;
    // Not stuck
    } else {
        return false;
    }
}

bool Blank(int x, int y, int rows, int columns) {
    bool empty;
    if (x <= rows && y <= columns) {
        empty = false;
    } else {
        empty = true;
    }
    return empty;
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

void Zombie::moveZombie(std::vector<Zombie>&zombieList,int i,int rows, int columns) {
    string movements[] = {"up","down","left","right"};
    bool turnIncomplete = true;
    // Taking zombie position
    int x = zombieList[i].zom_dimX;
    int y = zombieList[i].zom_dimY;

    // Checking for non-existent(blank) spots
    bool blankUp = Blank(x-1,y,rows-1,columns-1);
    bool blankDown = Blank(x+1,y,rows-1,columns-1);
    bool blankLeft = Blank(x,y-1,rows-1,columns-1);
    bool blankRight = Blank(x,y+1,rows-1,columns-1);

    //  //To check if zombie stuck
    //  bool stuck = isStuck(x,y,blankUp,blankDown,blankLeft,blankRight);
    //  // Exit if stuck
    //  if (stuck) {
    //      cout << "Zombie " << i+1 << " is stuck." <<endl;
    //      return;
    //  }

    // Loop to make sure zombie moves
    while (turnIncomplete) {
        // Randomizer and reroller (if only specific spot is blocked)
        string move = movements[rand()%size(movements)];
        // Movement cases (Move UP)
        if (move == "up" && !blankUp ) { 
            bool gotEntity = gotEntityObject(x-1,y);
            if (gotEntity == false) {
                moveUp(x,y,i);
                Location(x,y,zombieList,i);
                turnIncomplete = false;
            } else {}

        // Move DOWN        
        } else if  (move == "down" && !blankDown) { 
            bool gotEntity = gotEntityObject(x+1,y);
            if (gotEntity == false) {
                moveDown(x,y,i);
                Location(x,y,zombieList,i);
                turnIncomplete = false;
            } else {}

        // Move LEFT    
        } else if (move == "left" && !blankLeft) { 
            bool gotEntity = gotEntityObject(x,y-1);
            if (gotEntity == false) {
                moveLeft(x,y,i);
                Location(x,y,zombieList,i);
                turnIncomplete = false;
            } else {}

        // Move RIGHT
        } else if (move == "right" && !blankRight) { 
            bool gotEntity = gotEntityObject(x,y+1);
            if (gotEntity == false) {
                moveRight(x,y,i);
                Location(x,y,zombieList,i);
                turnIncomplete = false;
            } else {}
        }
    }
}

void Zombie::Location(int x, int y,std::vector<Zombie>&zombieList, int i) {
    zombieList[i].zom_dimX = x;
    zombieList[i].zom_dimY = y;   
}


