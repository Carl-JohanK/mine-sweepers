#include "gameGrid.h"
#include "gameLogic.h"

gameGrid::gameGrid(int height, int width)
{
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            gridItems.push_back(new mineGrid(j, i));
        }
    }

    for (int i = 0; i < height + width; i++) {
        addMines(gridItems);
    }
}

gameGrid::~gameGrid()
{
    for (mineGrid* i : gridItems) {
        delete(i);
    }
}

void gameGrid::displayField(int width)
{
    displayMap(gridItems, width);
}

bool gameGrid::playerMove(int x, int y)
{
    return makeMove(x, y, gridItems);
}
