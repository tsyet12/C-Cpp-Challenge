#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dist(int a,int b,int i,int j) {
    return(abs(a-i)+abs(b-j));
}

vector<pair<int,int>> c;
vector<bool> marked;
vector<vector<pair<int,int>>> g;
bool large=false;

pair<bool,int> dfs(int s,int nb,int nbmax) {
    int bb=false;
    int dmin=-1;
    int max_done=3;
    if(nb>0) max_done=2;
    if(nb>17) max_done=1;
    if(large) {
        max_done=2;
        if(nb>8) max_done=1;
    }
    if(nb==nbmax) return(make_pair(true,0));
    else {
        marked[s]=true;
        int done=0;
        int i=0;
        while((done<max_done)&&(i<g[s].size())) {
            int j=g[s][i].first;
            if(!(marked[j])) {
                done++;
                pair<bool,int> test=dfs(j,nb+1,nbmax);
                if(test.first) {
                    int a=c[s].first;
                    int b=c[s].second;
                    int x=c[j].first;
                    int y=c[j].second;
                    int d=dist(a,b,x,y);
                    d+=test.second;
                    if(dmin==-1) dmin=d;
                    else dmin=min(dmin,d);
                    bb=true;
                }
            }
            i++;
        }
        marked[s]=false;
        return(make_pair(bb,dmin));
    }
}

void next_move(int x, int y, int n, int m, vector <string> t) {
    if(n>10) large=true;
    if(t[x][y]=='d') cout << "CLEAN";
    else {
        int a=0,b=0,mini=-1,nb=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(t[i][j]=='d') nb++;
            }
        }
        for(int i=0;i<nb;i++) marked.push_back(false);
        for(int i=0;i<nb;i++) {
            vector<pair<int,int>> test1;
            g.push_back(test1);
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(t[i][j]=='d') {
                    c.push_back(make_pair(i,j));
                }
            }
        }
        for(int ii=0;ii<nb;ii++) {
            int vmin1=-1;
            int dmin1=-1;
            int vmin2=-1;
            int dmin2=-1;
            int vmin3=-1;
            int dmin3=-1;
            int i=c[ii].first;
            int j=c[ii].second;
            for(int jj=0;jj<nb;jj++) {
                if(ii!=jj) {
                    int i1=c[jj].first;
                    int j1=c[jj].second;
                    int d=dist(i,j,i1,j1);
                    g[ii].push_back(make_pair(jj,d));
                }
            }
            sort(g[ii].begin(),g[ii].end(),[](pair<int,int> aa,pair<int,int> bb) {
                return(aa.second<bb.second);
            });
        }
        vector< pair<int,int> > trie;
        trie.clear();
        for(int k=0;k<nb;k++) {
            int i=c[k].first;
            int j=c[k].second;
            int d=dist(x,y,i,j);
            trie.push_back(make_pair(k,d));
        }
        sort(trie.begin(),trie.end(),[](pair<int,int> aa,pair<int,int> bb) {
                return(aa.second<bb.second);
        });
        int siz=trie.size();
        for(int kk=0;kk<min(4,siz);kk++) {
            int k=trie[kk].first;
            int d=trie[kk].second;
            for(int i=0;i<nb;i++) marked[i]=false;
            pair<bool,int> test=dfs(k,1,nb);
            d+=test.second;
            if(test.first) {
                if((mini==-1)||(d<mini)) {
                    mini=d;
                    a=c[k].first;
                    b=c[k].second;
                }
            }
        }
        if(x<a) cout << "DOWN";
        else if(x>a) cout << "UP";
        else if(y<b) cout << "RIGHT";
        else if(y>b) cout << "LEFT";
        else cout << "WTF";
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