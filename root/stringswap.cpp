/******************************************************************************

       Sin Yong Teng's Attempt to use C++ String Swap

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

void printRemain(string s, int size){
    for(int i=1;i<size;i++){
        cout<<s[i];
    }
}

int main() {
	int am,bm;
    string a,b;

    cin>>a;
    cin>>b;
    am=a.size();
    bm=b.size();
    cout<<am<<" "<<bm<<endl;
    cout<<a+b<<endl;
    cout<<b[0];
    printRemain(a,am);
    cout<<" ";
    cout<<a[0];
    printRemain(b,bm);
    return 0;
}

