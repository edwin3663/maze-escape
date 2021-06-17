# Creature Escapes a Maze

This is a toy program for demonstrating a recursive backtracking algorithm. The idea is that there is a creature trapped in a maze. In order to find its way out, the creature must solve the maze. It is possible to create a custom maze in a textfile.

# Maze File Format

In the maze file format the x is a wall and space is a hallway. 

Line1: width and height of the maze.</br>
Line2: row and column coordinate of maze exit.</br>
Line3: row and column coordinate of maze entrance.</br>
The following lines are the maze's walls and hallways.</br>

  20 7</br>
  0 18</br>
  6 12</br>
  xxxxxxxxxxxxxxxxxx x</br>
  x     x       xxxx x</br>
  x xxxxx xxxxx   xx x</br>
  x xxxxx xxxxxxx xx x</br>
  x x          xx xx x</br>
  x xxxxxxxxxx xx    x</br>
  xxxxxxxxxxxx xxxxxxx</br>

# Limitation of the Program

The program doesn't do error checking on the maze input file. The maze is always rectangular. It is also assumed that the given maze width, height, coordinate of the exit and entrance match given maze. 
