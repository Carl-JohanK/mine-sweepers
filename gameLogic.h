#pragma once
#include <vector>
#include "mineGrid.h"
void surroundings(int surroundx, int surroundy, std::vector<mineGrid*> gridItems);
void addMines(std::vector<mineGrid*> gridItems);
void displayMap(std::vector<mineGrid*> gridItems, int width);
bool makeMove(int x, int y, std::vector<mineGrid*> gridItems);
void flipAllZero(int x, int y, std::vector<mineGrid*> gridItems);