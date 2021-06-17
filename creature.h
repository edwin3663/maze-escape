#ifndef CREATURE_H
#define CREATURE_H

#include "maze.h"
class Maze;

class Creature {
private:
  int row;
  int col;

  friend class Maze;
public:
  Creature();
  
  Creature(int row, int col); 

  void moveNorth(Maze &maze);

  void moveEast(Maze &maze);

  void moveSouth(Maze& maze);

  void moveWest(Maze& maze);

  int getRow();

  int getCol();
};

#endif
