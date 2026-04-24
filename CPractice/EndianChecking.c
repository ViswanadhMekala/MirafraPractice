#include <stdio.h>

int main(){
    int a = 1;
    unsigned char* ptr = (unsigned char*)&a;
    
    if(*ptr == 1){
        printf("Little endian");
    }
    else{
        printf("Bug Endian");
    }
}