#include "computer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int    computer::SHIP_SIZES[5] = { 5, 4, 3, 3, 2 };
const string computer::SHIP_NAMES[5] = {
    "Carrier (5)", "Battleship (4)", "Cruiser (3)", "Submarine (3)", "Destroyer (2)"
};

computer::computer() {
    srand(time(0));
}

void computer::placeShips(Board& board) {
    for (int i = 0; i < SHIP_COUNT; i++) {
        bool placed = false;
        while (!placed) {
            int  r = rand() % 10;
            int  c = rand() % 10;
            bool h = rand() % 2;
            placed = board.placeShip(r, c, SHIP_SIZES[i], h, SHIP_NAMES[i]);
        }
    }
}

bool computer::takeTurn(Board& targetBoard) {
    bool hit = true;
    while (hit) {
        int r, c;
        do {
            r = rand() % 10;
            c = rand() % 10;
        } while (targetBoard.isAlreadyAttacked(r, c));

        char rowLabel = 'A' + r;
        cout << "  Computer attacks: " << rowLabel << (c + 1) << endl;

        hit = targetBoard.attack(r, c);
        if (hit)
            cout << "  Computer HIT your ship! Computer gets another turn!" << endl;
        else
            cout << "  Computer missed." << endl;

        if (targetBoard.allSunk()) return true;
    }
    return false;
}