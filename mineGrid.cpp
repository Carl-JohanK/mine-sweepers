#include "mineGrid.h"

mineGrid::mineGrid(int cx, int cy)
{
    this->cordx = cx;
    this->cordy = cy;
    setDisplay("[ ]");
    this->num = 0;
    this->isBomb = false;
}

void mineGrid::setDisplay(const std::string& d)
{
    this->display = d;
}

std::string mineGrid::getDisplay()
{
    return display;
}

int mineGrid::getNum()
{
    return this->num;
}
void mineGrid::setNum()
{
    this->num++;
}

int mineGrid::getCordx()
{
    return this->cordx;
}
int mineGrid::getCordy()
{
    return this->cordy;
}

bool mineGrid::getIsBomb()
{
    return this->isBomb;
}
void mineGrid::setIsBomb()
{
    this->isBomb = !this->isBomb;
}