/******************************************************************************
finding maximum in array using pointer
*******************************************************************************/
#include <stdio.h>

int main()
{
    int result, i;
    int *ptr;
    int array[]={20, 4, 32 ,15, 29};
    
    ptr=array;
    result=*ptr;
    for(i=0;i<5;i++){
        if(result<*ptr)
            result=*ptr;
        ptr++;
    }
    
    printf("%d\n",result);

    return 0;
}
