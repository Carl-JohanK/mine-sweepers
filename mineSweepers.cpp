// mineSweepers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <sstream>
#include "gameGrid.h"


int main()
{
    srand(time(0));

    std::cout << "* * * mine sweepers * * *" << std::endl;

    int height;
    int width;

    std::cout << "chose the height(max: 30): ";
    std::cin >> height;
    if (height <= 2 || height > 30) {
        height = 5;
        std::cout << "invalid height, height is set to 5";
    }
    std::cout << "chose the width(max: 30): ";
    std::cin >> width;
    if (width <= 2 || width > 30) {
        width = 5;
        std::cout << "invalid width, width is set to 5";
    }

    gameGrid* game = new gameGrid(height, width);

    int x = 0;
    int y = 0;
    bool gameLoop = true;

    while (gameLoop) {
        game->displayField(width);
        std::cout << "select a row:";
        std::cin >> x;
        if (x > width) {
            x = 1;
            std::cout << "row not fonnd";
        }
        std::cout << "select a colom:";
        std::cin >> y;
        if (y > height) {
            x = 1;
            std::cout << "colom not fonnd";
        }
        gameLoop = game->playerMove(x, y);
    }
    
    delete(game);
}



