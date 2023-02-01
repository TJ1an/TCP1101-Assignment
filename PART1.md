# Part 1

## Video Demo

[Video Demo](https://youtu.be/H_yS6C7VfJ8).

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
List all the features completed.

1. Game Board
    - Display of board and Alien stats are complete.
2. Alien
    - Movement is implemented correctly and stops when in contact with borders/objects.
    - Can interact with "arrow","health","rock","empty" and "trails".
3. Zombies
    - MAX(9) unique zombie can spawn on the board.
    - Their stats (which include Health, Attack, Range, X and Y dimensions) are recorded.
4. Game Objects
    - Arrow, health, rock and empty path are functioning correctly.
5. Game Controls
    - Up, Down, Left, Right are Completed.

### To Do

List all the features not yet done. Remove this section if there is no incomplete requirements.
1. Board
    - Clearing of previous board.
    - Arrow pointer for each "entities" turn.
2. Alien
    - Interaction with pod.
    - Alien interaction with Zombie
3. Zombies
    - Display of Zombie stats under Alien Stats.
    - Random movement of zombie.
    - Interaction of zombie on field and with Alien
4. Game Objects
    - Pod is yet to be implemented.
    - Changing trail into random objects after every round
5. Game Controls
    - Help option
    - Save option
    - Load option
    - Quit option
6. Additional features (coming soon)
    - Decoy potion
    - Powerup/Ultimate skill system (to be considered)
    - Portals
    - Super dash (triggered when you use the arrow function 3x in a ROW or more) (to be considered)

## Additional Features

-

## Contributions

### Chong Yi Jing

1. Originally implemented the board borders generation. 
2. Added the object/powerup generation algorithm for the board.
3. Added spawning for Alien on board.
4. Added feature to reject even numbers for board generation.
5. Added zombie spawning algorithm while considering various use-cases. 
6. Added zombie class and implemented code to record zombie data. As well as randomize and display stats.

### Khoo Jen-Au

1. Helped with zombie creation spawning and applies them into a class
2. Bug fixes, typing errors.
3. Added the main menu where we have the selection for the game.
4. Added board row and column numbers.
5. Finished the main UI fo the game.

### Ian Leong Tsung Jii
1. Implemented randomizer for randomizing alien's health.
2. Implemented randomizer for alien to interact with a random object when it hits rock.
3. Added alien interaction with rock, healthpack, left right up and down arrows.
4. Added trails that alien leaves behind when it moves.
5. Added game settings to change the values of row, column and zombie.


## Problems Encountered & Solutions
*WIP = Work in Progress
1. In the main menu, it will break if the input is not an integer. WIP.
2. The rock breaking mechanic isn't fully functional. WIP.

### Chong Yi Jing

1. Encountered issues with rand() function to randomly spawn/select objects and powerups for the board since there was a seeding issue where the "seed" remained the same resulting in the same "randomized" output. To solve this issue I implemented srand((unsigned)time(NULL)) before the rand() function to input a random "seed" before executing the code hence giving more random outputs.

2. Originally added the code to spawn in Alien thinking it had to be spawned at the bottom center of the row. Tried spawning but the code didn't run/ alien didn't generate. To fix this issue, I had just realized while using vectors that the indexing start at 0, hence I realized I had set the Alien's x-axis to be the [x-1]. All of this, just to realize I just had to spawn the Alien at the center of the board.

3. Had countless issues trying to implement the zombie spawning. I originally added so that the zombies would spawn as 'Z' while considering the case of overlapping entities on the board. I added a function to "reroll" the spawnpoint if there were entities on the point.

4. Eventually added numbering to spawn in the zombies, but had to also consider the numbering overlapping causing zombies to not spawn properly. To solve this I made a for loop with boolean to iterate through the possible types of entities in an array to confirm if there are entities within a point. If there were, it would randomize the x,y dimensions and run the loop again, if there weren't it would spawn the zombie onto the point and deduct the number of zombies to be spawned by one.

5. After fully implementing the zombie spawning, I had to consider implementing the Zombie class into the equation. To do this a Zombie class vector was used in this, also added multiple functions and variables to record the x,y dimensions for each time a zombie is spawned by the algorithm as well as running a function for randomizing stats to record under each "Zombie" object as well. Learnt alot about the use of vectors and classes while implementing this.

### Khoo Jen-Au

1. Originally, some of the variable names were all started in Uppercase by the other group mates, which were causing a little problem when creating creating and referencing the zombie class (more on that later). So to create less confusion, I changed them all into lowercase.

2. Implemented a way so that every zombie that spawns on the board gets added into their own "Zombie" class. Somehow had a problem where the zombies are unable to generate due to my code interfering with it, so I slightly modified the variables I was using and used a vector array to save each zombies' stats. Which the code are then simplified by other group mates even more.

3. At one point the board was unable to generate the row and column numbers properly and is interfering with the board generation. So I rewrote the code by making sure the loops print out the values after the board was done generating. For example, I let the row numbers generate after each board row was generated, and used two lines instead of one for the columns number at the bottom of the board so it fits within the size of the board and doesn't go off-scale.

4. For the main menu, there was an issue where the inputs allows anything to be input, which will crash the program. So I added a switch case to prevent any other inputs being inserted. Even though it still doesn't fully work at this point, I have plans where I can change it into an if-else statement to prevent such cases.

### Ian Leong Tsung Jii

1. Initially used arrays for board generation but found out that values inside the array has to be constant, because of that I switched to vectors as they are more scalable.

2. I wanted to use the same vector, board, in another file but it doesn't work. Found out I had to put an "extern" to make it visible across multiple files.

3. Encountered an issue where "system("pause")" doesn't work, therefore I made my own pause function called myPause as an alternative.

4. Encountered an issue where the function for random health generation for alien returns the same value everytime. It turns out we had to add srand((unsigned)time(NULL)) before the rand() function in order to get more random results.
