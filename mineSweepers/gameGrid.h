#pragma once
#include <vector>
#include "mineGrid.h"

class gameGrid
{
public:
	gameGrid(int height, int width);
	~gameGrid();
	void displayField(int width);
	bool playerMove(int x, int y);

private:
	int height;
	int width;
	std::vector<mineGrid*> gridItems;

};