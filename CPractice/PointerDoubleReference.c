/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int target = 42;
    int *p = &target;
    int **ptr = &p;  // Declaration (no extra parens needed)
    
    // Usage:
    printf("%d\n", *(*ptr)); // Prints 42
    printf("%d\n", **(int**)ptr); // Prints 42
    return 0;
}
