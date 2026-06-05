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
    AI    ai;
    int   round;

    static const int    SHIP_COUNT = 5;
    static const int    SHIP_SIZES[5];
    static const string SHIP_NAMES[5];

    // 內部流程
    void placePlayerShips();
    bool playerTurn();   // 回傳 true 代表玩家贏了
    bool aiTurn();       // 回傳 true 代表 AI 贏了

    // 輔助：解析座標，支援 "A1" / "A 1" / "a1"
    bool parseCoord(const string& token, int& r, int& c);

public:
    Game();
    void run();  // 啟動整場遊戲
};

#endif