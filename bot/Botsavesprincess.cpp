/* Bot saves princess

Implemented by Sin Yong Teng

*/

#include <iostream>
#include <vector>
using namespace std;

void displayPathtoPrincess(int n, vector <string> grid){
    
    int Pposx,Pposy,Mposx,Mposy;
    //find position of p and m
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
         if(grid[j][i]=='p'){
             Pposx=i;
             Pposy=j;
         }
         else if(grid[j][i]=='m'){
             Mposx=i;
             Mposy=j;
         }
        }      
    }

    
    //compute displacement
    int disX=(Pposx-Mposx);//0-1=-1 negative go left, positive go right
    int disY=(Pposy-Mposy);//2-1=1 positive go down, negative go up
    
    //Define direction
    while(disX!=0 || disY!=0){
        if(disX!=0){
        if(disX<0){
            cout<<"LEFT\n";
            disX=disX+1;
        }
        else if(disX>0){
            cout<<"RIGHT\n";
            disX=disX-1;
        }
    }
    if(disY!=0){
        if(disY<0){
            cout<<"UP\n";
            disY=disY+1;
        }
        else if(disY>0){
            cout<<"DOWN\n";
            disY=disY-1;
        }
    }
    
    }
    

}

int main(void) {
    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);        
    }

    displayPathtoPrincess(m,grid);

    return 0;
}