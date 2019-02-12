#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

void next_move(int posr, int posc, int dimh, int dimw, vector <string> board) {
 //push position of dirty squares to two vectors
    std::vector<int> dirtposX;
    std::vector<int> dirtposY;
    
    if(board[posr][posc]=='d'){
        cout<<"CLEAN"<<endl;
        return;
    }
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
    std::vector<double> lookahead1;
    
    if(dimh<12){
        for(int z=0;z<dirtposX.size();z++){
            std::vector<double> temp;
            for(int i=0;i<dirtposX.size();i++){
                std::vector<double> temp1;
    
                    for(int k=0;k<dirtposX.size();k++){
                        std::vector<double> temp2;
                        for(int j=0;j<dirtposX.size();j++){
                            std::vector<double> temp3;
                            
                            
                                
                             for(int f=0;f<dirtposX.size();f++){
                                std::vector<double> temp4;
                                for(int q=0;q<dirtposX.size();q++){
                                   
                                
                                    temp4.push_back(abs(dirtposX[f]-dirtposX[q])+abs(dirtposY[q]-dirtposY[f]));
                                }
                                temp3.push_back(abs(dirtposX[f]-dirtposX[j])+abs(dirtposY[j]-dirtposY[f])+*std::min_element(temp4.begin(),temp4.end()));
                            
                           
                                
                            temp2.push_back(abs(dirtposX[k]-dirtposX[j])+abs(dirtposY[j]-dirtposY[k])+*std::min_element(temp3.begin(),temp3.end()));
                            
                            }
                            
                        }
                        
                        temp1.push_back(abs(dirtposX[k]-dirtposX[i])+abs(dirtposY[i]-dirtposY[k])+*std::min_element(temp2.begin(),temp2.end()));
                    }
                    temp.push_back(abs(dirtposX[z]-dirtposX[i])+abs(dirtposY[i]-dirtposY[z])+*std::min_element(temp1.begin(),temp1.end()));
            }
            double score1=*std::min_element(temp.begin(),temp.end());
            displacement.push_back(abs(posc-dirtposX[z])+abs(posr-dirtposY[z])+score1);
        }
    }
    else{
        for(int z=0;z<dirtposX.size();z++){
        std::vector<double> temp;
        for(int i=0;i<dirtposX.size();i++){
            std::vector<double> temp1;

                for(int k=0;k<dirtposX.size();k++){
                    
                    temp1.push_back(abs(dirtposX[k]-dirtposX[i])+abs(dirtposY[i]-dirtposY[k]));
                }
                temp.push_back(abs(dirtposX[z]-dirtposX[i])+abs(dirtposY[i]-dirtposY[z])+*std::min_element(temp1.begin(),temp1.end()));
        }
        double score1=*std::min_element(temp.begin(),temp.end());
        displacement.push_back(abs(posc-dirtposX[z])+abs(posr-dirtposY[z])+score1);
    }
    }
    //Greedyily move to the next dirt
    int greedyindex = std::min_element(displacement.begin(),displacement.end()) - displacement.begin();  
    
    //
    //compute displacement
    int disX=(dirtposX[greedyindex]-posc);//0-1=-1 negative go left, positive go right
    int disY=(dirtposY[greedyindex]-posr);//2-1=1 positive go down, negative go up
    
    //Define direction
        if(disX!=0){
        if(disX<0){
            cout<<"LEFT\n";
            disX=disX+1;
            return;
        }
        else if(disX>0){
            cout<<"RIGHT\n";
            disX=disX-1;
            return;
        }
    }
    if(disY!=0){
        if(disY<0){
            cout<<"UP\n";
            disY=disY+1;
            return;
        }
        else if(disY>0){
            cout<<"DOWN\n";
            disY=disY-1;
            return;
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