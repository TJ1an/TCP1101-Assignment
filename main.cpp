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
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{   
    int menuSelection;
    int kRows = 5;
    int kColumns = 13;
    int kZombie = 3;
    cout << " " << endl;
    cout << ".: Alien Vs Zombie :." << endl;
    cout << "1. Play" << endl;
    cout << "2. Load" << endl;
    cout << "3. Quit" << endl;
    cout << endl;
    cout << "Insert number on which action you want to perform (1, 2, 3)." << endl;
    cout << "=> ";
    cin >> menuSelection;
    switch (menuSelection)
    {
        case 1:
        ClearScreen();
        GameSettings(kRows, kColumns, kZombie);
        break;

        case 2:
        ClearScreen();
        cout << "test 2 works"<< endl;
        return main();

        case 3:
        ClearScreen();
        cout << "Thanks for playing." << endl;
        abort();

        default:
        ClearScreen();
        cout << "Invalid input. Please retry.";
        cout << endl;
        return main();
    }
}