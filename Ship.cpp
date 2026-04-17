#include"Ship.h"
#include<string>
#include<iostream>
using namespace std;

Ship::Ship(){
    name="";
    size=0;
    health=0;
}

Ship::Ship(string n, int s, int h){
    name=n;
    size=s;
    health=h;
}

void Ship::setName(string n){
    name=n;
}

void Ship::setSize(int s){
    size=s;
}

void Ship::setHealth(int h){
    health=h;
}

string Ship::getName(){
    return name;
}

int Ship::getSize(){
    return size;
}

int Ship::getHealth(){
    return health;
}

void Ship::takeHit(){
    if(health>=0){
        health--;
    }
}

void Ship::isSunk(){
    if(health<=0){
        cout<<name<<" has been sunked!"<<endl;
    }
}
