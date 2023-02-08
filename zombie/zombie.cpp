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
            gotEntity = true; //True when entity spotted
            break;
        }
    }
    return gotEntity;    
}

void moveUp(int x, int y, int i) {
    board[x][y] = ' ';
    x--;
    board[x][y] = char('0' + (i+1));
    //cout << "Zombie " << i+1 << " moved UP." << endl;
}

void moveDown(int x, int y, int i) {
    board[x][y] = ' ';
    x++;
    board[x][y] = char('0' + (i+1));
    //cout << "Zombie " << i+1 << " moved DOWN." << endl;
}

void moveLeft(int x, int y, int i) {
    board[x][y] = ' ';
    y--;
    board[x][y] = char('0' + (i+1));
    //cout << "Zombie " << i+1 << " moved LEFT." << endl;
}

void moveRight(int x, int y, int i) {
    board[x][y] = ' ';
    y++;
    board[x][y] = char('0' + (i+1));
    cout << "Zombie " << i+1 << " moved RIGHT." << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//PAUSE (Shelved)                                                                              //                 
//bool isStuck(int x, int y,bool blankUp, bool blankDown, bool blankLeft, bool blankRight) {   //                                                                                                                                         
//    // Existing boolean to verify presence                                                   //                                                                                         
//    bool gotUp = false;                                                                      //                                                                     
//    bool gotDown = false;                                                                    //                                                                     
//    bool gotLeft = false;                                                                    //                                                                     
//    bool gotRight = false;                                                                   //                                                                         
//    // Checks surrounding (if got no blank)                                                  //                                                                                         
//    if (!(blankUp)) {                                                                        //                                                                 
//        gotUp = gotEntityObject(x-1,y);                                                      //                                                                                     
//    }                                                                                        //                                                 
//    if (!(blankDown)) {                                                                      //                                                                     
//        gotDown = gotEntityObject(x+1,y);                                                    //                                                                                     
//    }                                                                                        //                                                 
//    if (!(blankLeft)) {                                                                      //                                                                     
//        gotLeft = gotEntityObject(x,y-1);                                                    //                                                                                     
//    }                                                                                        //                                                 
//    if (!(blankRight)) {                                                                     //                                                                     
//        gotRight = gotEntityObject(x,y+1);                                                   //                                                                                         
//    }                                                                                        //                                                 
//    // Delivers verdict                                                                      //                                                                     
//    // 0 blank                                                                               //                                                             
//    if (gotUp && gotDown && gotLeft && gotRight) {                                           //                                                                                                 
//        return true;                                                                         //                                                                 
//    // 1 blank                                                                               //                                                             
//    } else if (gotUp && gotDown && gotLeft && blankRight) {                                  //                                                                                                         
//        return true;                                                                         //                                                                 
//    } else if (gotUp && gotDown && blankLeft && gotRight){                                   //                                                                                                         
//        return true;                                                                         //                                                                 
//    } else if (gotUp && blankDown && gotLeft && gotRight){                                   //                                                                                                         
//        return true;                                                                         //                                                                 
//    } else if (blankUp && gotDown && gotLeft && gotRight){                                   //                                                                                                         
//        return true;                                                                         //                                                                 
//    // 2 blank                                                                               //                                                             
//    } else if (gotUp && blankDown && blankLeft && gotRight){                                 //                                                                                                         
//        return true;                                                                         //                                                                 
//    } else if (gotUp && blankDown && gotLeft && blankRight){                                 //                                                                                                         
//        return true;                                                                         //                                                                 
//    } else if (blankUp && gotDown && blankLeft && gotRight){                                 //                                                                                                         
//        return true;                                                                         //                                                                 
//    } else if (blankUp && gotDown && gotLeft && blankRight){                                 //                                                                                                         
//        return true;                                                                         //                                                                 
//    //  stuck                                                                                //                                                         
//    } else {                                                                                 //                                                         
//        return false;                                                                        //                                                                 
//    }                                                                                        //                                                 
//}                                                                                            //                                             
/////////////////////////////////////////////////////////////////////////////////////////////////                                             

bool Blank(int x, int y, int rows, int columns) {
    // Verifies if position is valid (within the board)
    bool empty;
    if (x <= rows && y <= columns) { // Inside board
        empty = false;
    } else { // Outside board
        empty = true;
    }
    return empty; // Returns verdict
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
    << " Range: " << zombieList[i].zombieRange 
    << " X: " << (zombieList[i].zom_dimX)+1
    << " Y: " << (zombieList[i].zom_dimY)+1 << endl;
}

void Zombie::moveZombie(std::vector<Zombie>&zombieList,int i,int rows, int columns) {
    string movements[] = {"up","down","left","right"};
    bool turnIncomplete = true;
    // Taking zombie position
    int x = zombieList[i].zom_dimX;
    int y = zombieList[i].zom_dimY;

    // Checking for non-existent(blank) spots
    bool blankUp = Blank(x-1,y,rows-1,columns-1); // Rows and columns minus one because zero-indexed
    bool blankDown = Blank(x+1,y,rows-1,columns-1);
    bool blankLeft = Blank(x,y-1,rows-1,columns-1);
    bool blankRight = Blank(x,y+1,rows-1,columns-1);

    // Stuck = blocked by entity
    // If all boolean stuck is true, it's fully stuck
    bool stuckUp = false;
    bool stuckDown = false;
    bool stuckLeft = false;
    bool stuckRight = false;

    // Loop to make sure zombie moves
    while (turnIncomplete) {
        // Randomizer and reroller (if specific spot is blocked)
        string move = movements[rand()%size(movements)];

        // Movement cases 
        // Move UP
        if (move == "up" && !blankUp && !stuckUp) { 
            bool gotEntity = gotEntityObject(x-1,y);
            if (gotEntity == false) {
                moveUp(x,y,i);
                x--;
                Location(x,y,zombieList,i);
                turnIncomplete = false;
            } else {
                stuckUp = true;
            }
        // Move DOWN        
        } else if  (move == "down" && !blankDown && !stuckDown) { 
            bool gotEntity = gotEntityObject(x+1,y);
            if (gotEntity == false) {
                moveDown(x,y,i);
                x++;
                Location(x,y,zombieList,i);
                turnIncomplete = false;
            } else {
                stuckDown = true;
            }
        // Move LEFT    
        } else if (move == "left" && !blankLeft && !stuckLeft) { 
            bool gotEntity = gotEntityObject(x,y-1);
            if (gotEntity == false) {
                moveLeft(x,y,i);
                y--;
                Location(x,y,zombieList,i);
                turnIncomplete = false;
            } else {
                stuckLeft = true;
            }
        // Move RIGHT
        } else if (move == "right" && !blankRight && !stuckRight) { 
            bool gotEntity = gotEntityObject(x,y+1);
            if (gotEntity == false) {
                moveRight(x,y,i);
                y++;
                Location(x,y,zombieList,i);
                turnIncomplete = false;
            } else {
                stuckRight = true;
            }
        // Fully stuck
        } else if (stuckUp && stuckDown && stuckLeft && stuckRight) {
            cout << "Zombie " << i+1 << " is stuck." <<endl;
            return;
        }
    }
}

// void Zombie::Attack(std::vector<Zombie>zombieList,int i,int rows, int columns) {
//     // Notes zombie range and position
//     int range = zombieList[i].zombieRange;
//     int x = zombieList[i].zom_dimX;
//     int y = zombieList[i].zom_dimY; 
//     // Alien scanning algorithm
//     for (int i = 1; i <= range; i++){
//         for (int j = 1; i <= range; i++) {
//             if (board[x+i][y] == 'A' || board[x-i][y] == 'A' ||
//                 board[x][y+j] == 'A' || board[x][y-j] == 'A' ||
//                 board[x+i][y+j] == 'A' || board[x-i][y-j] == 'A' ||
//                 board[x+i][y-j] == 'A' || board[x-i][y+j] == 'A' )
//         }
//     }
//     
// }

void Zombie::Location(int x, int y,std::vector<Zombie>&zombieList, int i) {
    zombieList[i].zom_dimX = x;
    zombieList[i].zom_dimY = y;   
}


