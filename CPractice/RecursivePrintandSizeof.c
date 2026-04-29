#include <stdio.h>

#define sizeofA(x) ({__typeof__(x)y; (char*)(&y+1)-(char*)&y;})

void RecursivePrint(int value){
    if(value == 0){
        return;
    }
    else{
        RecursivePrint(value-1);
        printf("%d\n",value);
    }
    
    // This stops when value hits 0, otherwise it keeps going
    // (value > 0) && (RecursivePrint(value - 1), printf("%d\n", value));
}

int main()
{
    int a=100;
    printf("Size of the variable is :%d\n",sizeofA(a));
    RecursivePrint(a);

    return 0;
}
