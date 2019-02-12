/* Bot saves princess 2

Implemented by Sin Yong Teng

*/

#include <iostream>
#include <vector>
using namespace std;

void nextMove(int n, int r, int c, vector <string> grid){
     int Pposx,Pposy;
    //find position of p and m
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
         if(grid[j][i]=='p'){
             Pposx=i;
             Pposy=j;
         }
        }      
    }
 
    //compute displacement
    int disX=(Pposx-c);//0-1=-1 negative go left, positive go right
    int disY=(Pposy-r);//2-1=1 positive go down, negative go up
    
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

int main(void) {

    int n, r, c;
    vector <string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}