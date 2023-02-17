// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT2L
// Names: CHONG YI JING | KHOO JEN-AU | IAN LEONG TSUNG JII
// IDs: 1211101114 | 1211102910 | 1211101591
// Emails: 1211101114@student.mmu.edu.my | 1211102910@student.mmu.edu.my | 1211101591@student.mmu.edu.my
// Phones: +601121143315 | +60166732470 | +60192835699 
// ********************************************************* 

#include "board.h"
#include "alien/alien.h"
#include "zombie/zombie.h"
#include "help/help.h"
#include "saveload/saveload.h"
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

void menuLoop();

int main()
{   
    menuLoop();
    return 0;
}

void menuLoop() {
    double menuSelection = 0;
    int kRows = 5;
    int kColumns = 13;
    int kZombie = 3;
    Alien kAlien;
    Zombie kZomb;
    vector<vector<char>> kBoard;
    kAlien.set = false;
    kZomb.set = false;

    bool running = true;
    while(running) {
        ClearScreen();
        cout << ".: Alien Vs Zombie :." << endl;
        cout << endl;
        cout << "   1. Play" << endl;
        cout << "   2. Load" << endl;
        cout << "   3. Help Tutorial" << endl;
        cout << "   4. Quit" << endl;
        cout << endl;
        cout << "Insert number on which action you want to perform (1, 2, 3, 4)." << endl;
        cout << "=> ";
        cin >> menuSelection;

        if (menuSelection == 1)
        {
            ClearScreen();
            GameSettings(kRows, kColumns, kZombie, kAlien, kZomb, kBoard);
        }
        else if (menuSelection == 2)
        {
            ClearScreen();
            loadStats(kRows, kColumns, kZombie, kAlien, kZomb, kBoard);
        }
        else if (menuSelection == 3)
        {
            ClearScreen();
            helpMenu();
        }
        else if (menuSelection == 4)
        {
            ClearScreen();
            savePrompt(kRows, kColumns, kZombie, kAlien, kZomb, kBoard);
            running = false;
            abort();
        }
        else
        {
            cout << "Invalid input. Please retry.";
            cout << endl;
            Pause();
        }
    }
}