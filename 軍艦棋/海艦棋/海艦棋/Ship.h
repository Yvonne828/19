#ifndef SHIP_H
#define SHIP_H
#include<string>
#include<iostream>
using namespace std;

class Ship{
    private:
        string name;
        int size;
        int health;
    public:
        Ship();
        Ship(string n, int s, int h);
        void setName(string n);
        void setSize(int s);
        void setHealth(int h);
        string getName();
        int getHealth();
        int getSize();
        
        void takeHit();
        void isSunk();

};
#endif//


