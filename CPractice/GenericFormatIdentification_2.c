/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define GETFRM(x) (_Generic((x),\
    _Bool:   "bool   : %d\n",   \
    char:    "char   : %c\n",   \
    int:     "int    : %d\n",   \
    float:   "float  : %f\n",   \
    double:  "double : %g\n",  \
    char *:  "string : %s\n",   \
    void *:  "pointer: %p\n",   \
    default: "other  : unknown type\n" \
))

int main()
{
    int ca = 1234;
    char cb = 'V';
    float cc = 0.12345;
    double cd = 0.0000129345;
    char* string = "Viswanadh";
    
    printf(GETFRM(ca),((__typeof__(ca))ca));
    printf(GETFRM(cb),((__typeof__(cb))cb));
    printf(GETFRM(cc),((__typeof__(cc))cc));
    printf(GETFRM(cd),((__typeof__(cd))cd));
    printf(GETFRM('V'), 'V'); 
    printf(GETFRM((char)'V'), 'V'); 
    printf(GETFRM(string),((__typeof__(string))string));
	return 0;
}
