# Part 1

## Video Demo

Please provide the YouTube link to your [Video Demo](https://youtube.com).

## Minimum Requirements

### Completed

List all the features completed.

1. Cool Feature #1
2. Cool Feature #2
3. *add more*

### To Do

List all the features not yet done. Remove this section if there is no incomplete requirements.

1. Cool Feature #1
2. *add more*

## Additional Features

Describe the additional features that has been implemented.

## Contributions

List down the contribution of each group members.

For example:

### Chong Yi Jing

1. Originally implemented the board borders generation. 
2. Added the object/powerup generation algorithm for the board.
3. Added spawning for Alien on board.
4. Added feature to reject even numbers for board generation.
5. Added zombie spawning algorithm while considering various use-cases. 
6. Added zombie class and implemented code to record zombie data. As well as randomize and display stats.

### Steve Rogers

1. Zombie movement and attack behaviour.
2. *add more*

### Dr. Strange

1. Implement all game objects.
2. *add more*

## Problems Encountered & Solutions

Describe the problems encountered and provide the solutions / plan for the solutions.
### Chong Yi Jing

1. Encountered issues with rand() function to randomly spawn/select objects and powerups for the board since there was a seeding issue where the "seed" remained the same resulting in the same "randomized" output. To solve this issue I implemented srand((unsigned)time(NULL)) before the rand() function to input a random "seed" before executing the code hence giving more random outputs.

2. Originally added the code to spawn in Alien thinking it had to be spawned at the bottom center of the row. Tried spawning but the code didn't run/ alien didn't generate. To fix this issue, I had just realized while using vectors that the indexing start at 0, hence I realized I had set the Alien's x-axis to be the [x-1]. All of this, just to realize I just had to spawn the Alien at the center of the board.

3. Had countless issues trying to implement the zombie spawning. I originally added so that the zombies would spawn as 'Z' while considering the case of overlapping entities on the board. I added a function to "reroll" the spawnpoint if there were entities on the point.

4. Eventually added numbering to spawn in the zombies, but had to also consider the numbering overlapping causing zombies to not spawn properly. To solve this I made a for loop with boolean to iterate through the possible types of entities in an array to confirm if there are entities within a point. If there were, it would randomize the x,y dimensions and run the loop again, if there weren't it would spawn the zombie onto the point and deduct the number of zombies to be spawned by one.

5. After fully implementing the zombie spawning, I had to consider implementing the Zombie class into the equation. To do this a Zombie class vector was used in this, also added multiple functions and variables to record the x,y dimensions for each time a zombie is spawned by the algorithm as well as running a function for randomizing stats to record under each "Zombie" object as well. Learnt alot about the use of vectors and classes while implementing this.
