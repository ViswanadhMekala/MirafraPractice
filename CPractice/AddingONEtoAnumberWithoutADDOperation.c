#include <stdio.h>

int main(){
    unsigned int a = 1;
    
    printf("%x",a);
    
    a = -(~a);
    
    printf("\n%x",a);
}