#include "Game.h"
using namespace std;

int main() {
    cout << "======================================" << endl;
    cout << "          BATTLESHIP                  " << endl;
    cout << "======================================" << endl;
    cout << "[Goal]" << endl;
    cout << "  Sink all enemy ships to win!" << endl;
    cout << "[Board]" << endl;
    cout << "  ~  Ocean (not attacked)" << endl;
    cout << "  S  Your ship" << endl;
    cout << "  X  Hit" << endl;
    cout << "  O  Miss" << endl;
    cout << "[Ships]" << endl;
    cout << "  Length 5 x1, Length 4 x1, Length 3 x2, Length 2 x1" << endl;
    cout << "[Controls]" << endl;
    cout << "  Coordinate: letter + number, e.g. A1, B10" << endl;
    cout << "  Direction: 1 = horizontal, 0 = vertical" << endl;
    cout << "  Enter Q to quit" << endl;
 
    Game game;
    game.run();
    return 0;
}