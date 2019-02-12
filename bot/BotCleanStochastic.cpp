/* Bot Clean Stochastic

Implemented by Sin Yong Teng

*/

#include<iostream>
#include<vector>
using namespace std;

void nextMove(int posr, int posc, vector <string> board) {
       int Pposx,Pposy;
    
    //find position of p and m
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
         if(board[j][i]=='d'){
             Pposx=i;
             Pposy=j;
         }
        }      
    }
    
    
    //compute displacement
    int disX=(Pposx-posc);//0-1=-1 negative go left, positive go right
    int disY=(Pposy-posr);//2-1=1 positive go down, negative go up
    
    //Define direction
    if(disX==0 && disY==0){
        cout<<"CLEAN\n";
    }
    else{
        while(disX!=0 || disY!=0){
        if(disX!=0){
        if(disX<0){
            cout<<"LEFT\n";
            disX=disX+1;
            break;
        }
        else if(disX>0){
            cout<<"RIGHT\n";
            disX=disX-1;
            break;
        }
    }
    if(disY!=0){
        if(disY<0){
            cout<<"UP\n";
            disY=disY+1;
            break;
        }
        else if(disY>0){
            cout<<"DOWN\n";
            disY=disY-1;
            break;
        }
    }
    
    } 
    }
   
    
}

int main(void) {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;
        cin >> s;
        board.push_back(s);
    }
    nextMove(pos[0], pos[1], board);
    return 0;
}