#include <stdio.h>
#include <stddef.h> // Header for size_t

/* 
 * The portable "Pure C" sizeof macro:
 * 1. (&x + 1) moves to the next address based on the type of 'x'.
 * 2. Casting to (char*) forces the subtraction to happen byte-by-byte.
 * 3. Casting the final result to (size_t) makes it compatible with standard C.
 */
#define MY_SIZEOF(x) ((size_t)((char*)(&(x) + 1) - (char*)&(x)))

void RecursivePrint(int value) {
    // Short-circuit logic: behaves like 'if (value > 0)'
    (value > 0) && (RecursivePrint(value - 1), printf("%d\n", value));
}

int main() {
    int a = 100;
    double d = 3.14;
    char c = 'A';

    // Print sizes using the portable %zu specifier
    printf("Size of int variable:    %zu bytes\n", MY_SIZEOF(a));
    printf("Size of double variable: %zu bytes\n", MY_SIZEOF(d));
    printf("Size of char variable:   %zu byte\n\n", MY_SIZEOF(c));

    printf("Starting recursive print from 1 to %d:\n", a);
    RecursivePrint(a);

    return 0;
}

