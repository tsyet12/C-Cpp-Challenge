/* Bot Clean Partially Observable

Implemented by Sin Yong Teng

*/

#include<iostream>
#include<vector>

const int CBPO_MAJOR_VERSION = 1;
const int CBPO_MINOR_VERSION = 0;

using namespace std;
#define GRID_SIZE  5
#define V_D 1 

bool dirt_in_view(int row, int col, vector<string>& board) 
{
    if(board[row][col] == 'd') {
		cout <<"CLEAN" << endl; return true;
		}
    else if(row>0 && board[row-1][col]=='d'){
		cout <<"UP"<<endl; return true;
		}
    else if(row>0 && col<GRID_SIZE-1 && board[row-1][col+1]=='d') {
		cout<<"UP"<<endl; return true;
		}
    else if(col<GRID_SIZE-1 && board[row][col+1]=='d'){
		cout<<"RIGHT"<<endl; return true;
		}
    else if(row<GRID_SIZE-1 && col<GRID_SIZE-1 && board[row+1][col+1]=='d'){
		cout<<"RIGHT"<<endl; return true;
		}
    else if(row<GRID_SIZE-1 && board[row+1][col]=='d'){
		cout<<"DOWN"<<endl; return true;
		}
    else if(row<GRID_SIZE-1 && col>0 && board[row+1][col-1]=='d'){
		cout<<"DOWN"<<endl; return true;
		}
    else if(col>0 && board[row][col-1]=='d'){
		cout<<"LEFT"<<endl; return true;
		}
    else if(row>0 && col>0 && board[row-1][col-1]=='d'){
		cout<<"LEFT"<<endl; return true;
		}
    
    return false;
};

void next_move(int row, int col, vector<string>& board) 
{
    int mean;
    if(!dirt_in_view(row, col, board))
    {
        mean = (GRID_SIZE/2)+1;
        if(row < mean && col < GRID_SIZE-1){
			cout << "RIGHT" << endl;
			}
        else if(row < GRID_SIZE-1 && col > mean){
			cout << "DOWN" << endl;
			}
        else if(row > mean && col > V_D){
			cout << "LEFT" << endl;
			}
        else {
			cout << "UP" << endl;
			}
    }
};
int main(void) {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}