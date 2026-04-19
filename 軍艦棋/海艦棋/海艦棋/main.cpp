#include<iostream>
#include<string>
#include"Ship.h"
#include"Board.h"
using namespace std;


int main(){
    Board enemyBoard;
    enemyBoard.placeShip(0, 0, 0, true);
    
    string input;
    cout<<"=＝=Game Start==="<<endl;
    
    int shipLength[]={5, 4, 3, 3, 2};
    for(int i=0;i<5;i++){
        char rowLetter;
        int colNumber;
        int direction;
        
        cout<<"---deploy---"<<endl;
        cout<<"placing"<<shipLength[i]<<"的船"<<endl;
        cout<<"Please enter the placement starting point (e.g., A1)."<<endl;
        cin>>rowLetter>>colNumber;
        cout<<"Please select the placement direction (1 for horizontal, 0 for vertical)";
        cin>>direction;
        
        int r=rowLetter-'A';
        int c=colNumber-1;
        bool isHor =(direction==1);
        
        enemyBoard.placeShip(r, c, shipLength[i], isHor);
        
    }
    
    while(true){
        char rowLetter;
        int colNumber;
        enemyBoard.display();
        cout<<"Please enter the attack coordinates (type Q to exit).";
        cin>>rowLetter>>colNumber;
        
        if(input=="Q" or input=="q"){
            break;
        }
        
        int r=rowLetter-'A';
        int c=colNumber-1;
        
        if(r>=0 and r<10 and c>=0 and c<10){
            bool hit=enemyBoard.attack(r, c);
            if(hit){
                cout<<"===Hit! ==="<<endl;
            }
            else{
                cout<<"===Failed==="<<endl;
            }
        }
        else{
            cout<<"===Oops, missed!=="<<endl;
        }
        
    }
}
