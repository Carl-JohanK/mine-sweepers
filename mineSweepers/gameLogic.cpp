#include <vector>
#include "mineGrid.h"
#include "gameLogic.h"
#include <iostream>
#include <sstream>

void surroundings(int surroundx, int surroundy, std::vector<mineGrid*> gridItems) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (mineGrid* gi : gridItems) {
                if (gi->getCordx() == surroundx && gi->getCordy() == surroundy) {
                    gi->setNum();
                    break;
                }
            }
            surroundx++;
        }
        surroundx -= 3;
        surroundy++;
    }
}


void addMines(std::vector<mineGrid*> gridItems) {
bool added = false;
while (!added) {
    int randMine = (rand() % gridItems.size());
    if (!gridItems.at(randMine)->getIsBomb()) {
        gridItems.at(randMine)->setIsBomb();

        //gridItems.at(randMine)->setDisplay("[X]"); //för att se och testa minorna

        int surroundx = gridItems.at(randMine)->getCordx() - 1;
        int surroundy = gridItems.at(randMine)->getCordy() - 1;

        surroundings(surroundx, surroundy, gridItems);
        added = true;
        }
    }

}

void displayMap(std::vector<mineGrid*> gridItems, int width) {
    int colom = 1;
    std::cout << "   ";
    for (int i = 1; i <= width; i++) {
        if(i < 10) std::cout << " " << i << " ";
        else std::cout << i << " ";
    }
    for (mineGrid* gi : gridItems) {
        if (gi->getCordx() == 1) {
            if (colom > 9) std::cout << std::endl << colom << " ";
            else std::cout << std::endl << " " << colom << " ";
            colom++;
        }
        std::cout << gi->getDisplay();
    }
    std::cout << std::endl;
}

bool makeMove(int x, int y, std::vector<mineGrid*> gridItems) {
    std::stringstream stream;
    int emptySpace = 0;
    for (mineGrid* gi : gridItems) {
        if (gi->getCordx() == x && gi->getCordy() == y) {
            if (gi->getDisplay() != "[F]") {
                std::string flag;
                std::cout << "do you want to flag(yes/no)";
                std::cin >> flag;

                if (flag == "yes") {
                    gi->setDisplay("[F]");
                }
            }
            if (gi->getDisplay() == "[F]") {
                std::cout << "this space is flaged\n\n";
            }
            else if (gi->getNum() == 0) {
                flipAllZero(x, y, gridItems);
            }
            else {
                stream << gi->getNum();
                std::string str = "[" + stream.str() + "]";
                gi->setDisplay(str);
            }

            if (gi->getIsBomb() && gi->getDisplay() != "[F]") {
                gi->setDisplay("[*]");
                std::cout << "game over!\nyou stept on a mine";
                return false;
            }
        }
        if (gi->getDisplay() == "[ ]") emptySpace++;
    }
    if (emptySpace == 0) {
        std::cout << "congratulations you successfully disarmed all the mines\nyou win";
        return false;
    }
    return true;
}

void flipAllZero(int x, int y, std::vector<mineGrid*> gridItems) {
    x -= 1;
    y -= 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (mineGrid* gi : gridItems) {
                if (gi->getCordx() == x && gi->getCordy() == y && gi->getDisplay() == "[ ]") {
                    std::stringstream stream;
                    stream << gi->getNum();
                    std::string str = "[" + stream.str() + "]";
                    gi->setDisplay(str);
                    if (gi->getNum() == 0) flipAllZero(x, y, gridItems);
                    break;
                }
            }
            x++;
        }
        x -= 3;
        y++;
    }
}
