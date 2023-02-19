# Alien VS Zombie

## Contributors
- Ian Leong Tsung Jii
- Chong Yi Jing
- Khoo Jen Au

## Compilation Instructions
```g++ -I./lib -I./lib/jsoncons -I./lib/jsoncons/include alien/alien.cpp main.cpp board.cpp zombie/zombie.cpp help/help.cpp saveload/saveload.cpp interaction/inter.cpp -o game -static-libgcc -static-libstdc++ -O3```

## User Manual
After compling, you are now in! There are 3 selections which include "1. Play", "2. Load", "3. Help", and "4. Quit".
- 1. Play: You can start playing the game.
- 2. Load: Loads a game from a savefile you saved.
- 3. Help: Shows thew help menu on how the game essentially works.
- 4. Quit: Exits the game with the text "Thanks for playing".
 
If you choose the "Play" selection, you can decide to maintain the default board dimensions and zombie count. If not, this can be modified. By accepting the modification option.

After that process, you're now in the game. Good luck, have fun!

## Progress Log
- [Part 1](PART1.md)
- [Part 2](PART2.md)