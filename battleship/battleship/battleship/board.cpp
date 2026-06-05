#include "board.h"
#include <iostream>
#include <string>
using namespace std;

Board::Board() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            grid[i][j] = '~';
    shipCount = 0;
}

bool Board::placeShip(int r, int c, int l, bool isHorizontal, string shipName) {
    // 邊界檢查
    if (isHorizontal) {
        if (c + l > SIZE) return false;
    }
    else {
        if (r + l > SIZE) return false;
    }
    if (r < 0 || r >= SIZE || c < 0 || c >= SIZE) return false;

    // 重疊檢查
    for (int i = 0; i < l; i++) {
        int checkR = isHorizontal ? r : r + i;
        int checkC = isHorizontal ? c + i : c;
        if (grid[checkR][checkC] != '~') return false;
    }

    // 放置船並記錄
    ships[shipCount] = Ship(shipName, l);
    for (int i = 0; i < l; i++) {
        int placeR = isHorizontal ? r : r + i;
        int placeC = isHorizontal ? c + i : c;
        grid[placeR][placeC] = '0' + shipCount;  
    }
    shipCount++;
    return true;
}

void Board::display(bool hideShips) {
    cout << "   1 2 3 4 5 6 7 8 9 10" << endl;
    cout << "  ------------------------" << endl;
    for (int i = 0; i < SIZE; i++) {
        char rowLabel = 'A' + i;
        cout << rowLabel << " |";
        for (int j = 0; j < SIZE; j++) {
            char c = grid[i][j];
            if (hideShips && c >= '0' && c <= '9') {
                cout << "~ ";   
            }
            else if (c >= '0' && c <= '9') {
                cout << "S ";   
            }
            else {
                cout << c << " ";
            }
        }
        cout << endl;
    }
}

bool Board::attack(int r, int c) {
    char cell = grid[r][c];

    if (cell >= '0' && cell <= '9') {
        int idx = cell - '0';
        ships[idx].takeHit();
        grid[r][c] = 'X';

        if (ships[idx].isSunk()) {
            cout << "  *** " << ships[idx].getName() << " has been sunk! ***" << endl;
        }
        return true;
    }
    else if (cell == '~') {
        grid[r][c] = 'O';
        return false;
    }
    return false;  
}

bool Board::allSunk() {
    for (int i = 0; i < shipCount; i++) {
        if (!ships[i].isSunk()) return false;
    }
    return true;
}

bool Board::isAlreadyAttacked(int r, int c) {
    return grid[r][c] == 'X' || grid[r][c] == 'O';
}