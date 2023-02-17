#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "../board.h"
#include "./help.h"
using namespace std;

void helpMenu() {
    helpPage1();
    cout << endl;
    Pause();
    ClearScreen();
    helpPage2();
    cout << endl;
    Pause();
    ClearScreen();
    helpPage3();
    cout << endl;
    Pause();
    ClearScreen();
    helpPage4();
    cout << endl;
    Pause();
    ClearScreen();
    helpPage5();
    cout << endl;
    Pause();
}

void helpPage1()
{
    cout << ".: Help Tutorial Screen :." << endl;
    cout << endl;
    cout << "Welcome to Alien Vs Zombie! In this tutorial, you will learn the basic funtions and inputs of this game." << endl;
    cout << "Alien Vs Zombie is a strategy game where you are an alien who moves on a board and tries to survive the zombie invasion." << endl;
    cout << endl;
    cout << "This is your board. It may vary in size depending on the dimensions you set before each game." << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << "   .: Alien Vs Zombie :." << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "| |p| | |1|h|<| | |>|<|v| | 1" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "| |p| | | |v| | |>| | | |3| 2" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "|h| | |p| |h|A| | | |r| | | 3" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "|<|p|2|<|>|^| | |<| |p| | | 4" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "| |<| |<| |h| | |p|<| |h|>| 5" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << " 0 0 0 0 0 0 0 0 0 1 1 1 1" << endl;
    cout << " 1 2 3 4 5 6 7 8 9 0 1 2 3" << endl;
    cout << endl;
    cout << "Page 1/5" << endl;
}

void helpPage2()
{
    cout << ".: Help Tutorial Screen :." << endl;
    cout << endl;
    cout << "   .: Alien Vs Zombie :." << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "| |p| | |1|h|<| | |>|<|v| | 1" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "| |p| | | |v| | |>| | | |3| 2" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "|h| | |p| |h|A| | | |r| | | 3" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "|<|p|2|<|>|^| | |<| |p| | | 4" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "| |<| |<| |h| | |p|<| |h|>| 5" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << " 0 0 0 0 0 0 0 0 0 1 1 1 1" << endl;
    cout << " 1 2 3 4 5 6 7 8 9 0 1 2 3" << endl;
    cout << endl;
    cout << "There are elements on the board. Which will be categorised under 2 categories: \"Characters\" and \"Elements\"" << endl;
    cout << "The characters on the board are:" << endl;
    cout << "\"A\" is the Alien, which spawns in the middle of the board." << endl;
    cout << "The numbers \"1\", \"2\" and \"3\" are the respective zombies, there could be up to 9 zombies depending how many you set each game." << endl;
    cout << endl;
    cout << "Page 2/5" << endl;
}

void helpPage3()
{
    cout << ".: Help Tutorial Screen :." << endl;
    cout << endl;
    cout << "   .: Alien Vs Zombie :." << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "| |p| | |1|h|<| | |>|<|v| | 1" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "| |p| | | |v| | |>| | | |3| 2" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "|h| | |p| |h|A| | | |r| | | 3" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "|<|p|2|<|>|^| | |<| |p| | | 4" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "| |<| |<| |h| | |p|<| |h|>| 5" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << " 0 0 0 0 0 0 0 0 0 1 1 1 1" << endl;
    cout << " 1 2 3 4 5 6 7 8 9 0 1 2 3" << endl;
    cout << endl;
    cout << "Here are the elements that are part of the game:" << endl;
    cout << "\"h\" is a healthpack which you can collect to gain 20 health." << endl;
    cout << "\"p\" is a pod where you can use it to attack zombies. It instantly inflicts 10 damage to a Zombie when hit by Alien." << endl;
    cout << "\"^\", \"v\", \"<\", \">\" are dash arrows. If an alien steps on it, it will change its direction according to the direction of the arrow and advance that way." << endl;
    cout << "The dash arrows also increase the Alien attack damage by 20." << endl;
    cout << "There are also rocks on the board, labelled as \"r\", where it serves as an obstacle which the Alien can break." << endl;
    cout << endl;
    cout << "Page 3/5" << endl;
}

void helpPage4()
{
    cout << ".: Help Tutorial Screen :." << endl;
    cout << endl;
    cout << "   .: Alien Vs Zombie :." << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "| |p| | |1|h|<| | |>|<|v| | 1" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "| |p| | | |v| | |>| | | |3| 2" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "|h| | |p| |h|A| | | |r| | | 3" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "|<|p|2|<|>|^| | |<| |p| | | 4" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "| |<| |<| |h| | |p|<| |h|>| 5" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << " 0 0 0 0 0 0 0 0 0 1 1 1 1" << endl;
    cout << " 1 2 3 4 5 6 7 8 9 0 1 2 3" << endl;
    cout << endl;
    cout << "When in a game, you will have to decide where to move the Alien in order to survive." << endl;
    cout << "You can choose whether to go \"up\", \"down\", \"left\", or \"right\". Type in the direction and the Alien will head to that direction." << endl;
    cout << endl;
    cout << "Page 4/5" << endl;
}

void helpPage5()
{
    cout << ".: Help Tutorial Screen :." << endl;
    cout << endl;
    cout << "   .: Alien Vs Zombie :." << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "| |p| | |1|h|<| | |>|<|v| | 1" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "| |p| | | |v| | |>| | | |3| 2" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "|h| | |p| |h|A| | | |r| | | 3" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "|<|p|2|<|>|^| | |<| |p| | | 4" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "| |<| |<| |h| | |p|<| |h|>| 5" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << " 0 0 0 0 0 0 0 0 0 1 1 1 1" << endl;
    cout << " 1 2 3 4 5 6 7 8 9 0 1 2 3" << endl;
    cout << endl;
    cout << "You may also change any arrow's direction on your board by using the \"arrow\" command" << endl;
    cout << "The game will ask which arrow on the board (specifically the coordinates) that you want to change." << endl;
    cout << "Follow the instructions and you will be able to change it to your needs." << endl;
    cout << "This will be useful if you want to chain your movement to attack a zombie, dealing lots of damage." << endl;
    cout << endl;
    cout << "Page 5/5" << endl;
}