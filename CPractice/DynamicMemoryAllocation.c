/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int** var = (int**)malloc(2*sizeof(int*));
    var[0] = (int*)malloc(2*sizeof(int));
    var[1] = (int*)malloc(2*sizeof(int));
    
    printf("%d\n",sizeof(var[0]));
    printf("%d\n",sizeof(var[1]));
    printf("%d\n",sizeof(var));

    return 0;
}
