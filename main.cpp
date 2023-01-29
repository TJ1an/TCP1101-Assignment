// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT2L
// Names: CHONG YI JING | KHOO JEN-AU | MEMBER_NAME_3 
// IDs: 1211101114 | 1211102910 | MEMBER_ID_3 
// Emails: 1211101114@student.mmu.edu.my | 1211102910@student.mmu.edu.my | MEMBER_EMAIL_3 
// Phones: +601121143315 | +60166732470 | MEMBER_PHONE_3 
// ********************************************************* 

// TODO: Fill in the missing information above and delete this line.
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
    int kColumns = 5;
    int kZombie = 1;
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
        GameSettings(kRows, kColumns, kZombie);
        break;

        case 2:
        cout << "test 2 works"<< endl;
        break;

        case 3:
        cout << "Thanks for playing." << endl;
        abort();

        default:
        cout << "Invalid input. Please retry.";
        cout << endl;
        return main();
    }
}