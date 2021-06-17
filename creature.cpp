#include "creature.h"


Creature::Creature() {
  row = 0;
  col = 0;
}

Creature::Creature(int row, int col) {
  row = row;
  col = col;
}

void Creature::moveNorth(Maze &maze) {
  if (!maze.isWall(row - 1, col)) {
    row--;
    //std::cout << row << " " << col << std::endl;
  }
}

void Creature::moveEast(Maze &maze) {
  if (!maze.isWall(row, col + 1)) {
    col++;
    //std::cout << row << " " << col << std::endl;
  }
}

void Creature::moveSouth(Maze &maze) {
  if(!maze.isWall(row + 1, col)) {
    row++;
    //std::cout << row << " " << col << std::endl;
  }
}

void Creature::moveWest(Maze &maze) {
  if (!maze.isWall(row, col - 1)) {
    col--;
    //std::cout << row << " " << col << std::endl;
  }
}

int Creature::getRow() {
  return row;
}

int Creature::getCol() {
  return col;
}
