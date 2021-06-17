#ifndef Maze_H
#define Maze_H

#include "creature.h"
#include <iostream>
#include <vector>
#include <string>

class Creature;

class Maze {
private:
  std::vector<std::vector<char>> map;
  int width;
  int height;
  int entRow;
  int entCol;
  int exitRow;
  int exitCol;

  Maze() {};
public:
  // Creates a default maze
  Maze(Creature &c);

  Maze(const std::string &fileName,Creature &c);

  bool atExit(Creature &creature);

  bool isWall(int row, int col);

  bool isPath(int row, int col);

  void markVisited(int row, int col);

  void printMaze();
};


#endif
