/******************************************************************************

       Sin Yong Teng's Attempt to use C++ Variable Size Array

*******************************************************************************/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, q;
    cin>>n>>q;
    vector<vector <int> > a;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        vector <int> kvector;
        for(int j=0;j<k;j++){
            int kvalue;
            cin>>kvalue;
            kvector.push_back(kvalue);
        }
        a.push_back(kvector);
    }

    for(int k=0;k<n;k++){
        int i,j;
        cin>>i>>j;
        cout<<a[i][j]<<endl;
    }
    return 0;
}


}
