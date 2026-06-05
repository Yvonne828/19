#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include "ship.h"
using namespace std;

class Board {
private:
    static const int SIZE = 10;
    char grid[SIZE][SIZE];
    Ship ships[5];
    int shipCount;

public:
    Board();

    bool placeShip(int r, int c, int l, bool isHorizontal, string shipName);
    void display(bool hideShips = false);
    bool attack(int r, int c);

    bool allSunk();
    bool isAlreadyAttacked(int r, int c);
};

#endif