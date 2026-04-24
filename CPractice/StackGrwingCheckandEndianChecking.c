#include <stdio.h>

int main(){
    /*int a = 1;
    unsigned char* ptr = (unsigned char*)&a;
    
    if(*(ptr) == 1){
        printf("Little endian");
    }
    else{
        printf("Big Endian");
    }
    */
    unsigned char array;
    unsigned char array1;
    
    printf("0:Element Address is %p\n",&array);
    printf("1:Element Address is %p\n",&array1);
    
    if((&array - &array1)> 0){
        printf("Stack is growing downwards");
    }
    else{
        printf("Stack is growing Upwards");
    }
}