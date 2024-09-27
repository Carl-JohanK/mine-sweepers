#pragma once
#include <string>

class mineGrid
{
public:
    mineGrid(int cx, int cy);
    void setDisplay(const std::string& d);
    std::string getDisplay();
    int getNum();
    void setNum();
    int getCordx();
    int getCordy();
    bool getIsBomb();
    void setIsBomb();

private:
    bool isBomb;
    int num;
    std::string display;
    int cordx;
    int cordy;

};