# Creature Escapes a Maze

This is a toy program for demonstrating a recursive backtracking algorithm. The idea is that there is a creature trapped in a maze. In order to find its way out, the creature must solve the maze. It is possible to create a custom maze in a textfile.

# Maze File Format

In the maze file format the x is a wall and space is a hallway. 

Line1: width and height of the maze.</br>
Line2: row and column coordinate of maze exit.</br>
Line3: row and column coordinate of maze entrance.</br>
The following lines are the maze's walls and hallways.</br>

    20 7
    0 18
    6 12
    xxxxxxxxxxxxxxxxxx x
    x     x       xxxx x
    x xxxxx xxxxx   xx x
    x xxxxx xxxxxxx xx x
    x x          xx xx x
    x xxxxxxxxxx xx    x
    xxxxxxxxxxxx xxxxxxx

# Limitation of the Program

The program doesn't do error checking on the maze input file. The maze is always rectangular. It is also assumed that the given maze width, height, coordinate of the exit and entrance match given maze. 
