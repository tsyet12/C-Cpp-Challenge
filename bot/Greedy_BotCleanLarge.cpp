#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

void next_move(int posr, int posc, int dimh, int dimw, vector <string> board) {
 //push position of dirty squares to two vectors
    std::vector<int> dirtposX;
    std::vector<int> dirtposY;
    for(int i=0;i<dimw;i++){
        for(int j=0;j<dimh;j++){
         if(board[j][i]=='d'){
             dirtposX.push_back(i);
             dirtposY.push_back(j);
         }
        }      
    }
    
    //compute displacement of bot and each dirt
    std::vector<double> displacement;
    for(int z=0;z<dirtposX.size();z++){
        displacement.push_back(sqrt(pow(posc-dirtposX[z],2)+pow(posr-dirtposY[z],2)));
    }
    
    //Greedyily move to the next dirt
    int greedyindex = std::min_element(displacement.begin(),displacement.end()) - displacement.begin();  
    
    //
    //compute displacement
    int disX=(dirtposX[greedyindex]-posc);//0-1=-1 negative go left, positive go right
    int disY=(dirtposY[greedyindex]-posr);//2-1=1 positive go down, negative go up
    
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
    int dim[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    cin>>dim[0]>>dim[1];
    for(int i=0;i<dim[0];i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], dim[0], dim[1], board);
    return 0;
}