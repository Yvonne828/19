#ifndef BOARD_H
#define BOARD_H
#include<iostream>
#include<string>
using namespace std;

class Board{
    private:
        static const int SIZE=10;
        char grid[SIZE][SIZE];
    public:
        Board();
        void placeShip(int r, int c, int l, int h);
        void display();
        bool attack(int r, int c);
};

#endif
