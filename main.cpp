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
    
    int shipLength[]={5, 3};
    for(int i=0;i<2;i++){
        char rowLetter;
        int colNumber;
        int direction;
        
        cout<<"---部署---"<<endl;
        cout<<"正在放置"<<shipLength[i]<<"的船"<<endl;
        cout<<"請輸入放置起點（如A1）"<<endl;
        cin>>rowLetter>>colNumber;
        cout<<"請選擇放置方向（1為水平、0為鉛直）";
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
        cout<<"請輸入攻擊座標（輸入Q離開）";
        cin>>rowLetter>>colNumber;
        
        if(input=="Q" or input=="q"){
            break;
        }
        
        int r=rowLetter-'A';
        int c=colNumber-1;
        
        if(r>=0 and r<10 and c>=0 and c<10){
            bool hit=enemyBoard.attack(r, c);
            if(hit){
                cout<<"===擊中！==="<<endl;
            }
            else{
                cout<<"===落空==="<<endl;
            }
        }
        else{
            cout<<"===打歪囉！==="<<endl;
        }
        
    }
}
