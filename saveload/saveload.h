#ifndef SAVELOAD_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define SAVELOAD_H



void loadStats(int &rows, int &columns, int &zombie, Alien &ex_alien, Zombie &ex_zomb, std::vector<std::vector<char>> &ex_board);
void saveStats(int rows, int columns, int zombies, Alien alien, Zombie zomb, std::vector<std::vector<char>> &ex_board);
void savePrompt(int rows, int columns, int zombies, Alien alien, Zombie zomb, std::vector<std::vector<char>> &ex_board);
#endif