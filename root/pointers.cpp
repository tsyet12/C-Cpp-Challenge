/******************************************************************************

       Sin Yong Teng's Attempt to use C++ pointers (sad attempt)

*******************************************************************************/

#include <iostream>

void cubewithpointer(int *n);
void cubenopointer(int n);


int main(){

    
    int a;
    int *aPtr;
    //&aPtr=0x7ffe57d157ac;
    
    a=5;
    aPtr= &a;
    printf("address= %p,pointer= %p", &a, aPtr);
    printf("\naddress= %d,pointer= %d", a, *aPtr);
    printf("\naddress= %p,pointer= %p", &*aPtr, *&aPtr);
    cubenopointer(a);
    
    printf("\naddress= %p,pointer= %p", &a, aPtr);
    printf("\nWith pointer address= %d,pointer= %d", a, *aPtr);
    printf("\naddress= %p,pointer= %p", &*aPtr, *&aPtr);
    
    
    cubewithpointer(&a);
    printf("\naddress= %p,pointer= %p", &a, aPtr);
    printf("\nWith pointer address= %d,pointer= %d", a, *aPtr);
    printf("\naddress= %p,pointer= %p", &*aPtr, *&aPtr);
    return 0;
}

void cubewithpointer(int *n){
    *n = *n**n;
}

void cubenopointer(int n){
    n=n*n;
}

