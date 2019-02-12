/******************************************************************************

Variable shadowing
*******************************************************************************/
#include <stdio.h>


int var=1; /*Global variable*/

void testfunction(int var){
    printf("Var= %d at the start 1 of myfunction\n", var);
    {
        int var=3;
        printf("Var=%d in sub-block 1\n", var);
    }
    printf("Var= %d at the start 2 of myfunction\n", var);
}



int main()
{
    testfunction(var+1);
    printf("Var=%d in main",var);
    

    return 0;
}
