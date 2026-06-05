#pragma once
#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "computer.h"
using namespace std;

class Game {
private:
    Board playerBoard;
    Board enemyBoard;
    computer    computer;
    int   round;

    static const int    SHIP_COUNT = 5;
    static const int    SHIP_SIZES[5];
    static const string SHIP_NAMES[5];

    void placePlayerShips();
    bool playerTurn();   
    bool aiTurn();       

    bool parseCoord(const string& token, int& r, int& c);

public:
    Game();
    void run();  // 啟動遊戲
};

#endif