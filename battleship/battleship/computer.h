#pragma once
#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
#include "board.h"
using namespace std;

class AI {
private:
    static const int SHIP_COUNT = 5;
    static const int SHIP_SIZES[5];
    static const string SHIP_NAMES[5];

public:
    AI();
    void placeShips(Board& board);

    // 攻擊目標棋盤，打中繼續直到落空；回傳是否對方全滅
    bool takeTurn(Board& targetBoard);
};

#endif