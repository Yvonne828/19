#include "ship.h"
#include <string>
#include <iostream>
using namespace std;

Ship::Ship() {
    name = "";
    size = 0;
    health = 0;
}

// 修改：建構子直接用 size 設定 health
Ship::Ship(string n, int s) {
    name = n;
    size = s;
    health = s;
}

void Ship::setName(string n) { name = n; }
void Ship::setSize(int s) { size = s; }
void Ship::setHealth(int h) { health = h; }

string Ship::getName() { return name; }
int    Ship::getSize() { return size; }
int    Ship::getHealth() { return health; }

void Ship::takeHit() {
    if (health > 0)
        health--;
}

// 修改：回傳 bool
bool Ship::isSunk() {
    return health <= 0;
}