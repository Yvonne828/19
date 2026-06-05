#pragma once
#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
#include "board.h"
using namespace std;

class computer {
private:
    static const int SHIP_COUNT = 5;
    static const int SHIP_SIZES[5];
    static const string SHIP_NAMES[5];

public:
    computer();
    void placeShips(Board& board);

    bool takeTurn(Board& targetBoard);
};

#endif