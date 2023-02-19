# Part 2

## Video Demo

Please provide the YouTube link to your [Video Demo](https://youtu.be/q33nvp2EJR8).

## Minimum Requirements
1. Game Board
2. Game Characters
    - Attributes
    - Movement and Attack
3. Multiple Zombies
4. Game Objects
5. Game Controls
6. Saving and Loading Feature
### Completed
1. Game Board
    - Display of board and Alien stats are complete.
    - Board rows, columns and number of zombies are adjustable (rows and columns must be odd numbered while MAX(9) unique zombies.)
    - Clearing of previous board.
    - Arrow pointer for each "entities" turn.
2. Alien
    - Movement is implemented correctly and stops when in contact with borders/objects.
    - Can interact with "arrow","health","rock","empty" and "trails".
    - Interaction with pod.
    - Alien interaction with Zombie (will move into Zombie position if it kills it)
3. Zombies
    - Their stats (which include Health, Attack, Range, X and Y dimensions) are recorded.
    - Display of Zombie stats under Alien Stats.
    - Random movement of zombie.
    - Interaction of zombie on field and with Alien
4. Game Objects
    - Arrow, health, rock and empty path are functioning correctly.
    - Pod is yet to be implemented.
    - Changing trail into random objects after every round
5. Game Controls
    - Up, Down, Left, Right are Completed.
    - Help option
    - Save option
    - Load option
    - Quit option
6. Game Flow
    - Characters do not overlap.
    - Each character takes turns to move and each move is explained what occurs.
    - Game ends when Alien or zombie is defeated.
    - Can choose to play again with board loaded up again or exit.
### To Do

List all the features not yet done. Remove this section if there is no incomplete requirements.

1. Cool features (coming soon)
    - Decoy potion
    - Powerup/Ultimate skill system (to be considered)
    - Portals/wormhole (like pacman)
"We were too ambitious" - Ian Leong 2023

## Contributions

### Chong Yi Jing

1. Made zombies able to move and is able to skip turn if stuck.
2. Added capability for zombies to attack Alien if in range (by calculating distance of alien from zombie).
3. Implemented the alien class to record data more accurately and integrated it with alien code.
4. Implemented code to determine if alien/zombies win.
5. Reformatted structure of board.cpp and main.cpp for efficiency and makes it easier to build functions on top of it.
6. Fixed display of Entity (alien, zombie) stats as well as arrow indicator for each turn.

### Khoo Jen-Au

1. Zombie movement and attack behaviour.
2. *add more*

### Ian Leong Tsung Jii

1. Implemented all game objects.
2. Implemented alien interaction with zombie, zombie takes damage when hit by alien.
3. Implemented code so that the gameboard refreshes after every move.
4. Implemented arrow command to change the the direction of arrows on the board. 
5. Implemented code so that "." or trail resets after each round.

## Problems Encountered & Solutions

Describe the problems encountered and provide the solutions / plan for the solutions.
### Chong Yi Jing

1. I had a big issue determining in which direction the zombie would move, in many cases the zombie had to determine if it was within the boundaries of the board and the presence of entities around it. To solve this issue, I implemented booleans to check for it's surrounding such as if it's within boundaries as well as if there were entities before executing its movement code.

2. Additionally, I wasn't sure on what to do if the zombie was fully stuck. Eventually I added code to determine if possible movements are blocked, in this case each time it would trigger a boolean. If all booleans were triggered, the zombie would be fully stuck and cannot move.

3. As for zombie attacks, I was dumbfounded on what to do, initially I tried to scan nearly every single point on the board (within range), instead I eventually opted out to integrate the position of the zombie and the position of alien to determine if alien is within attacking distance using mathematical formulas.

4. While trying to adding code to make the game replayable, I noticed how messy the overall foundation of the code was, particularly main.cpp and board.cpp, these two files were the main files which dictated the vast majority of the code. To combat this, I decided to reformat the code on both of these files so that there were more functions to carry out more specific actions, such as loading the board, being able to display as well as a proper game loop. Eventually I was able to restructure the code and it runs more smoothly and makes it far easier to build upon.

5. Towards the end, I've also noticed that there isn't an arrow to indicate each turn. At first I wasn't too sure on  how to do that as the display of alien and zombie stats were inside of ShowGameBoard(), to combat this, I've created a new function altogether to particularly display the turn indicators and entity stats. This function in particular would be paired with ShowGameBoard() to display what you see now in the current game.

### Khoo Jen-Au 


### Ian Leong Tsung Jii

1. I had some trouble where alien would continue moving even when it should have stopped. Turn out I forgot a break in one of the lines of code.

2. Before this, the gameboard would only refresh after each round, after alien and zombies have moved. I added a myPause() function and used ClearScreen() in the game flow so that it refreshes
after every move.

3. There was also a bug where "Press ENTER to continue..." would appear multiple times after each move. Turns out I had some redundant myPause() functions in my lines of code. I removed it and it worked as intended.