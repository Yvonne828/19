#include "game.h"
#include <iostream>
#include <cctype>
using namespace std;

const int    Game::SHIP_SIZES[5] = { 5, 4, 3, 3, 2 };
const string Game::SHIP_NAMES[5] = {
    "Carrier (5)", "Battleship (4)", "Cruiser (3)", "Submarine (3)", "Destroyer (2)"
};

Game::Game() : round(1) {}

bool Game::parseCoord(const string& token, int& r, int& c) {
    if (token.empty()) return false;
    r = toupper(token[0]) - 'A';
    string numPart = token.substr(1);
    if (numPart.empty())
        cin >> numPart;   
    for (char ch : numPart)
        if (!isdigit(ch)) return false;
    c = stoi(numPart) - 1;
    return true;
}

void Game::placePlayerShips() {
    cout << "\n=== Place Your Ships ===" << endl;
    for (int i = 0; i < SHIP_COUNT; i++) {
        playerBoard.display(false);
        bool placed = false;
        while (!placed) {
            int r, c, direction;
            cout << "\nPlacing: " << SHIP_NAMES[i]
                << "  (length = " << SHIP_SIZES[i] << ")" << endl;
            cout << "Enter starting coordinate (e.g., A 1): ";
            string token;
            cin >> token;

            if (!parseCoord(token, r, c) || r < 0 || r >= 10 || c < 0 || c >= 10) {
                cout << "  Invalid coordinate! Use format A1~J10." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            cout << "Direction (1 = horizontal, 0 = vertical): ";
            cin >> direction;
            bool isH = (direction == 1);

            placed = playerBoard.placeShip(r, c, SHIP_SIZES[i], isH, SHIP_NAMES[i]);
            if (!placed)
                cout << "  Invalid position! Out of bounds or overlapping. Try again." << endl;
        }
    }
    cout << "\nAll ships placed!" << endl;
}

bool Game::playerTurn() {
    cout << "\n[Your turn]" << endl;
    bool keepAttacking = true;
    while (keepAttacking) {
        cout << "\nEnemy Board:" << endl;
        enemyBoard.display(true);   
        cout << "Enter attack coordinate (e.g., A 1), or Q to quit: ";
        string token;
        cin >> token;

        if (token == "Q" || token == "q") {
            cout << "You surrendered. Game over." << endl;
            exit(0);
        }

        int r, c;
        if (!parseCoord(token, r, c) || r < 0 || r >= 10 || c < 0 || c >= 10) {
            cout << "  Invalid coordinate! Use format A1~J10." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;  
        }
        if (enemyBoard.isAlreadyAttacked(r, c)) {
            cout << "  Already attacked here! Choose another coordinate." << endl;
            continue;   
        }

        bool hit = enemyBoard.attack(r, c);
        if (hit) {
            cout << "  *** HIT! You get another turn! ***" << endl;
            keepAttacking = true;
        }
        else {
            cout << "  Miss. Computer's turn." << endl;
            keepAttacking = false;
        }

        if (enemyBoard.allSunk()) return true;
    }
    return false;
}

bool Game::aiTurn() {
    cout << "\n[Computer's turn]" << endl;
    bool won = computer.takeTurn(playerBoard);
    cout << "\nYour Board:" << endl;
    playerBoard.display(false);
    return won;
}


void Game::run() {
    cout << "==============================" << endl;
    cout << "     BATTLESHIP GAME          " << endl;
    cout << "==============================" << endl;

    placePlayerShips();
    computer.placeShips(enemyBoard);

    cout << "\n=== Game Start! ===" << endl;

    while (true) {
        cout << "\n--- Round " << round++ << " ---" << endl;

        if (playerTurn()) {
            cout << "\n=============================" << endl;
            cout << "  YOU WIN! All enemy ships sunk!" << endl;
            cout << "  Total rounds: " << round - 1 << endl;
            cout << "=============================" << endl;
            break;
        }

        if (aiTurn()) {
            cout << "\n=============================" << endl;
            cout << "  GAME OVER! Computer wins." << endl;
            cout << "  Total rounds: " << round - 1 << endl;
            cout << "=============================" << endl;
            break;
        }
    }
}