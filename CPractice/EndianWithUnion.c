/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef union node{
    unsigned int Val;
    struct{
        unsigned char a;
        unsigned char b;
        unsigned char c;
        unsigned char d;
    }ByteAcc;
}Node;

int main()
{
    Node ActualValue = {.Val = 0x12345678};
    
    printf("%x\n",ActualValue.Val);
    printf("%x\n",ActualValue.ByteAcc.a);
    printf("%x\n",ActualValue.ByteAcc.b);
    printf("%x\n",ActualValue.ByteAcc.c);
    printf("%x\n",ActualValue.ByteAcc.d);
    
    unsigned int EndianConv = ActualValue.ByteAcc.d |ActualValue.ByteAcc.c<<8U |ActualValue.ByteAcc.b<<16U | ActualValue.ByteAcc.a<<24U;
    
    printf("%x\n",EndianConv);

    return 0;
}