#include "Board.h"
#include <iostream>
#include <string>
using namespace std;

Board::Board() {
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            grid[i][j]='~';
        }
    }
}

void Board::display(){
    cout<<"  "<<"1 2 3 4 5 6 7 8 9 10"<<endl;
    cout<<"  "<<"--------------------"<<endl;
    for(int i=0;i<SIZE;i++){
        char rowTable='A'+i;
        cout<<rowTable<<"|";
        for(int j=0;j<SIZE;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Board::placeShip(int r, int c, int l, int h){
    if(h){
        for(int i=0;i<l;i++){
            grid[r][c+i]='S';
        }
    }
    else{
        for(int i=0;i<l;i++){
            grid[r+i][c]='S';
        }
    }
}

bool Board::attack(int r, int c){
    if (grid[r][c]=='S'){
        grid[r][c]='X';
        return true;
    }
    else if(grid[r][c]=='~'){
        grid[r][c]='O';
        return false;
    }
    else{
        return false;
    }
}

