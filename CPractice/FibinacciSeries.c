#include <stdio.h>
int fibinacci(int num){
    if(num == 0) return 0;
    if(num == 1) return 1;
    
    return fibinacci(num-1)+fibinacci(num-2);
}

int main()
{
    for(int i=0;i<10;i++){
        int b = fibinacci(i);
        printf("%d\t",b);
    }
    return 0;
}
