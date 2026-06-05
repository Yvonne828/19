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

    // 新增：顯示時是否要隱藏船的位置（敵方棋盤用）
    bool placeShip(int r, int c, int l, bool isHorizontal, string shipName);
    void display(bool hideShips = false);
    bool attack(int r, int c);

    // 新增：判斷所有船是否都沉了
    bool allSunk();
    bool isAlreadyAttacked(int r, int c);
};

#endif