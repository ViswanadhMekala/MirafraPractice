/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define SIZEOF_OP(x) ({__typeof__(x)y;(char*)(&y+1) - (char*)&y;})

int main()
{
    int t[2];
    //int t;
    
    printf("%d\n",SIZEOF_OP(t));

    return 0;
}