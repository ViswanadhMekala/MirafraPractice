/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define BitClear(x,y) (x &= ~(1<<y))
#define BitSet(x,y) (x |= (1<<y))
int main()
{
    int t = 7;
    printf("%d\n",t);
    BitClear(t,0);
    printf("%d\n",t);
    BitSet(t,0);
    printf("%d\n",t);

    return 0;
}