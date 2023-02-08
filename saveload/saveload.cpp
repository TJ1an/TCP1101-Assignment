#include "../alien/alien.h"
#include "../zombie/zombie.h"
#include "../board.h"
#include <fstream>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

void saveStats(){
    ofstream SaveFile("savefile.txt"); // Create and open a text file called savefile.txt
    SaveFile << "";
}

void savePrompt() {
    string saveGamePrompt;
        cout << "Do you want to save the game before exiting? (y/n)" << endl;
        cout << "=> ";
        cin >> saveGamePrompt;
        if (saveGamePrompt == "y") {
            cout << "This is still WIP" << endl;
            return savePrompt();
        }

        else if (saveGamePrompt == "n") {
            ClearScreen();
            cout << " " << endl;
            cout << "Thanks for playing!" << endl;
            cout << " " << endl;
            abort();
        }

        else {
            cout << "Invalid input. Please retry." << endl;
            Pause();
            return savePrompt();
        }
}