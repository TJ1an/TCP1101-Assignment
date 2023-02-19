#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "zombie.h"
using namespace std;

extern vector< vector<char> > board;

bool gotEntityObject(int x,int y, std::vector<Zombie> zombieList) {
    //Creates list of entities based on zombieList
    vector<char> entities;
    for (int i = 0; i < zombieList.size(); i++) {
        entities.push_back(char(49+i));
    }
    entities.push_back('A');
    //Iterates through entity array for possible entities
    bool gotEntity = false;
    for (int i = 0; i < entities.size(); i++) { 
        if (board[x][y] == entities[i]){
            gotEntity = true; //True when entity spotted
            break;
        }
    }
    return gotEntity;    
}

void moveUp(int x, int y, int i) {
    board[x][y] = ' ';
    x--;
    board[x][y] = char(49+i);
    cout << "Zombie " << i+1 << " moved UP." << endl;
}

void moveDown(int x, int y, int i) {
    board[x][y] = ' ';
    x++;
    board[x][y] = char(49+i);
    cout << "Zombie " << i+1 << " moved DOWN." << endl;
}

void moveLeft(int x, int y, int i) {
    board[x][y] = ' ';
    y--;
    board[x][y] = char(49+i);
    cout << "Zombie " << i+1 << " moved LEFT." << endl;
}

void moveRight(int x, int y, int i) {
    board[x][y] = ' ';
    y++;
    board[x][y] = char(49+i);
    cout << "Zombie " << i+1 << " moved RIGHT." << endl;
}

bool Blank(int x, int y, int rows, int columns) {
    // Verifies if position is valid (within the board)
    bool outsideBoard;
    // Makes sure x inside (0,rows) and y inside (0,columns)
    if (0 <= x && x <= rows && 0 <= y && y <= columns) { // Inside board
        outsideBoard = false;
    } else { // Outside board
        outsideBoard = true;
    }
    return outsideBoard; // Returns verdict
}

void Zombie::Stats(std::vector<Zombie>&zombieList, int i) {
    //Range of Stats
    int zombieHPs[] = {100,150,200};
    int zombieATKs[] = {10,15,20};
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

void Zombie::readAndDisplay(std::vector<Zombie>zombieList, int i) {
    cout << " Zombie " << i+1; 
    if (zombieList[i].zombieHealth >= 100) {
        cout << " HP: " << zombieList[i].zombieHealth;
    } else {
        cout << " HP:  " << zombieList[i].zombieHealth;
    }
    cout << " Atk:  " << zombieList[i].zombieAttack
    << " Range: " << zombieList[i].zombieRange << endl;

    // Display zombie location for reference
    // if ((zombieList[i].zom_dimX) + 1 < 10) {
    //     cout << " X:  " << (zombieList[i].zom_dimX) + 1;
    // }
    // else {
    //     cout << " X: " << (zombieList[i].zom_dimX) + 1;
    // }
    // if (zombieList[i].zom_dimY < 10) {
    //     cout << " Y:  " << (zombieList[i].zom_dimY) + 1;
    // }
    // else {
    //     cout << " Y: " << (zombieList[i].zom_dimY) + 1;
    // }
    // cout << endl;
    
}

void Zombie::moveZombie(std::vector<Zombie>&zombieList,int i,int rows, int columns) {
    string movements[] = {"up","down","left","right"};
    // Taking zombie position
    int x = zombieList[i].zom_dimX;
    int y = zombieList[i].zom_dimY;

    // Checking for non-existent(blank) spots
    bool blankUp = Blank(x-1,y,rows-1,columns-1); // Rows and columns minus one because zero-indexed
    bool blankDown = Blank(x+1,y,rows-1,columns-1);
    bool blankLeft = Blank(x,y-1,rows-1,columns-1);
    bool blankRight = Blank(x,y+1,rows-1,columns-1);

    // Stuck = blocked by entities
    // If all boolean stuck is true, it's fully stuck
    bool stuckUp = false;
    bool stuckDown = false;
    bool stuckLeft = false;
    bool stuckRight = false;

    // Loop to make sure zombie moves
    while (true) {
        int count = 0;
        // Randomizer and reroller (if specific spot is blocked)
        string move = movements[rand()%size(movements)];

        // Movement cases 
        // Move UP
        if (move == "up" && !stuckUp) { 
            bool gotEntity = gotEntityObject(x-1,y,zombieList);
            if (gotEntity == false && !blankUp ) {
                moveUp(x,y,i);
                x--;
                Location(x,y,zombieList,i);
                return;
            } else {
                stuckUp = true;
            }
        // Move DOWN        
        } else if  (move == "down" && !stuckDown) { 
            bool gotEntity = gotEntityObject(x+1,y,zombieList);
            if (gotEntity == false && !blankDown ) {
                moveDown(x,y,i);
                x++;
                Location(x,y,zombieList,i);
                return;
            } else {
                stuckDown = true;
            }
        // Move LEFT    
        } else if (move == "left" && !stuckLeft) { 
            bool gotEntity = gotEntityObject(x,y-1,zombieList);
            if (gotEntity == false && !blankLeft ) {
                moveLeft(x,y,i);
                y--;
                Location(x,y,zombieList,i);
                return;
            } else {
                stuckLeft = true;
            }
        // Move RIGHT
        } else if (move == "right" && !stuckRight) { 
            bool gotEntity = gotEntityObject(x,y+1,zombieList);
            if (gotEntity == false && !blankRight ) {
                moveRight(x,y,i);
                y++;
                Location(x,y,zombieList,i);
                return;
            } else {
                stuckRight = true;
            }
        } 
        // Fully stuck
        if (stuckUp && stuckDown && stuckLeft && stuckRight) {
            cout << "Zombie " << i+1 << " is stuck." <<endl;
            return;
        }
        count++;
        if (count == 30) {
            cout << "Error in code" << endl;
            return;
        }
    }
}

void Zombie::Location(int x, int y,std::vector<Zombie>&zombieList, int i) {
    zombieList[i].zom_dimX = x;
    zombieList[i].zom_dimY = y;   
}


