#include "../alien/alien.h"
#include "../zombie/zombie.h"
#include "../board.h"
#include <fstream>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

#include <jsoncons/json.hpp>
namespace jc = jsoncons;

struct SaveData {
    int rows, columns, zombies_count;
    Alien alien;
    Zombie zomb;
    vector<vector<char>> board;
};

JSONCONS_ALL_MEMBER_TRAITS(SaveData, rows, columns, zombies_count, alien, zomb, board);

JSONCONS_ALL_MEMBER_TRAITS(Alien, set, alienHealth, alienAttack, ali_dimX, ali_dimY);

JSONCONS_ALL_MEMBER_TRAITS(Zombie, set, zombieHealth, zombieAttack, zombieRange, zom_dimX, zom_dimY, zombieList);

void saveStats(int rows, int columns, int zombies, Alien alien, Zombie zomb, vector<vector<char>> &ex_board) {
    string userFileName;
    cout << " " << endl;
    cout << "Insert filename for your savefile: "; // Asks the user what filename they want to use
    cin >> userFileName;
    string completeFilename = userFileName + ".json"; // Adds .json at the end of said filename

    ofstream SaveFile(completeFilename); // Create and open a file under user's desired name
    vector<vector<int>> b{{1, 2, 3},{5, 15}};
    SaveData data = SaveData {
        rows, columns, zombies, alien, zomb, ex_board
    };
    string encoded;
    jc::encode_json(data, encoded, jc::indenting::indent); // Encode the data into indented JSON
    SaveFile << encoded; // Push the encoded data into the file
    SaveFile.close();
}

void loadStats(int &rows, int &columns, int &zombie, Alien &ex_alien, Zombie &ex_zomb, vector<vector<char>> &ex_board) {
    string inputSavefile;
    cout << "Enter the savefile's filename (without the file format): ";
    cin >> inputSavefile;
    string outputSavefile = inputSavefile + ".json";

    ifstream SaveFile(outputSavefile); // Create and open a JSON file called savefile.json
    
    auto data = jc::decode_json<SaveData>(SaveFile);

    // Feed the data back into the menu loop variables
    rows = data.rows;
    columns = data.columns;
    zombie = data.zombies_count;
    ex_alien = data.alien;
    ex_zomb = data.zomb;
    ex_board = data.board;
    cout << "Data loaded successfully!" << endl;
    Pause();
}

void savePrompt(int rows, int columns, int zombies, Alien alien, Zombie zomb, vector<vector<char>> &ex_board) {
    string saveGamePrompt;
    cout << "Do you want to save the game before exiting? (y/n)" << endl;
    cout << "=> ";
    cin >> saveGamePrompt;
    if (saveGamePrompt == "y") {
        saveStats(rows, columns, zombies, alien, zomb, ex_board);
        //return savePrompt();
        myPause();
        cout << "Thanks for playing!" << endl;
        abort();
    } else if (saveGamePrompt == "n") {
        ClearScreen();
        cout << " " << endl;
        cout << "Thanks for playing!" << endl;
        cout << " " << endl;
        abort();
    } else {
        cout << "Invalid input. Please retry." << endl;
        Pause();
        return savePrompt(rows, columns, zombies, alien, zomb, ex_board);
    }
}