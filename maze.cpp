#include "maze.h"
#include <fstream>

Maze::Maze(Creature &c) {
  map = {
    {'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x',' ','x'},
    {'x',' ',' ',' ',' ',' ','x',' ',' ',' ',' ',' ',' ',' ','x','x','x','x',' ','x'},
    {'x',' ','x','x','x','x','x',' ',' ','x','x','x','x',' ',' ',' ','x','x',' ','x'},
    {'x',' ','x','x','x','x','x',' ','x','x','x','x','x','x','x',' ','x','x',' ','x'},
    {'x',' ','x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x','x',' ','x','x',' ','x'},
    {'x',' ','x','x','x','x','x','x','x','x','x','x',' ','x','x',' ',' ',' ',' ','x'},
    {'x','x','x','x','x','x','x','x','x','x','x','x',' ','x','x','x','x','x','x','x'}
  };

  width = 20;
  height = 7;
  exitCol = 18;
  exitRow = 0;
  entCol = 12;
  entRow = 6;

  c.row = entRow;
  c.col = entCol;
  map[c.row][c.col] = 'c';
}

Maze::Maze(const std::string &fileName, Creature &c) {
  std::ifstream mapFile;
  mapFile.open(fileName);
  mapFile >> width >> height;
  mapFile >> exitRow >> exitCol;
  mapFile >> entRow >> entCol;

  map = std::vector<std::vector<char>>(height, std::vector<char>(width, ' ')); 
  mapFile.get();
  for (int r = 0; r < height; r++) {
    for (int c = 0; c < width; c++) {
      char data = mapFile.get();
      map[r][c] = data;
    }
    mapFile.get();
  }
  mapFile.close();

  c.row = entRow;
  c.col = entCol;
  map[c.row][c.col] = 'c';
}


bool Maze::atExit(Creature &creature) {
  if (creature.getRow() == exitRow && creature.getCol() == exitCol) {
    map[creature.getRow()][creature.getCol()] = 'c';
    return true;
  }
  return false;
}

bool Maze::isWall(int row, int col) {
  if (row < 0 || row >= height || col < 0 || col >= width) {
    return true;
  }
  
  return map[row][col] == 'x'? true : false;
}

bool Maze::isPath(int row, int col) {
  if (row < 0 || row >= height || col < 0 || col >= width) {
    return false;
  }
  
  return map[row][col] == 'p'? true : false;
}

void Maze::markVisited(int row, int col) {
  map[row][col] = 'p';
}

void Maze::printMaze() {
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      std::cout << map[row][col];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}