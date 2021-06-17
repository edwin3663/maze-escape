#include "creature.h"
#include "maze.h"

bool goNorth(Maze&, Creature&);
bool goWest(Maze&, Creature&);
bool goSouth(Maze&, Creature&);
bool goEast(Maze&, Creature&);


bool goNorth(Maze &m, Creature &c) {
  int row = c.getRow();
  int col = c.getCol();
  bool success = false;
  //std::cout << row << " " << col << std::endl;

  if (!m.isWall(row - 1, col) && !m.isPath(row - 1, col)) {
    c.moveNorth(m);
    m.markVisited(row, col);

    if (m.atExit(c)) {
      success = true;
    } else {
      success = goNorth(m, c);
      if (!success) {
        success = goWest(m, c);
        if (!success) {
          success = goEast(m, c);
          if (!success) {
            m.markVisited(row, col);
            c.moveSouth(m);
          }
        }
      }
    }
  }
  return success;
}

bool goWest(Maze &m, Creature &c) {
  int row = c.getRow();
  int col = c.getCol();
  bool success = false;
  //std::cout << row << " " << col << std::endl;

  if (!m.isWall(row, col - 1) && !m.isPath(row, col - 1)) {
    c.moveWest(m);
    m.markVisited(row, col);

    if (m.atExit(c)) {
      success = true;
    } else {
      success = goWest(m, c);
      if (!success) {
        success = goSouth(m, c);
        if (!success) {
          success = goNorth(m, c);
          if (!success) {
            m.markVisited(row, col);
            c.moveEast(m);
          }
        }
      }
    }
  }
  return success;
}

bool goSouth(Maze &m, Creature &c) {
  int row = c.getRow();
  int col = c.getCol();
  bool success = false;
  //std::cout << row << " " << col << std::endl;

  if (!m.isWall(row + 1, col) && !m.isPath(row + 1, col)) {
    c.moveSouth(m);
    m.markVisited(row, col);

    if (m.atExit(c)) {
      success = true;
    } else {
      success = goSouth(m, c);
      if (!success) {
        success = goEast(m, c);
        if (!success) {
          success = goWest(m, c);
          if (!success) {
            m.markVisited(row, col);
            c.moveNorth(m);
          }
        }
      }
    }
  }
  return success;
}

bool goEast(Maze &m, Creature &c) {
  int row = c.getRow();
  int col = c.getCol();
  bool success = false;
  //std::cout << row << " " << col << std::endl;

  if (!m.isWall(row, col + 1) && !m.isPath(row, col + 1)) {
    c.moveEast(m);
    m.markVisited(row, col);

    if (m.atExit(c)) {
      success = true;
    } else {
      success = goEast(m, c);
      if (!success) {
        success = goNorth(m, c);
        if (!success) {
          success = goSouth(m, c);
          if (!success) {
            m.markVisited(row, col);
            c.moveWest(m);
          }
        }
      }
    }
  }
  return success;
}


int main(int argc, char* argv[]) {
  Creature c; 
  Maze m("myMaze.txt",c);

  m.printMaze();

  goNorth(m, c);

  m.printMaze();

  return 0;
}
