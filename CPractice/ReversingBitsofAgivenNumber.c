/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    unsigned int a = 0x12345678;
    
    printf("%x\n",a);
    
    for(int i=0,j=31;i<j;i++,j--){
        if(((a>>i)&1U) != ((a>>j)&1U)){
            unsigned int temp = ((a>>i)&1U) ^ ((a>>j)&1U) ;
            a ^= temp << i;
            a ^= temp << j;
        }
    }
    printf("%x\n",a);

    return 0;
}

/*
unsigned int reverse_bits(unsigned int n) {
    // Swap adjacent bits
    n = ((n >> 1) & 0x55555555) | ((n << 1) & 0xAAAAAAAA);
    // Swap adjacent 2-bit pairs
    n = ((n >> 2) & 0x33333333) | ((n << 2) & 0xCCCCCCCC);
    // Swap adjacent nibbles (4-bit)
    n = ((n >> 4) & 0x0F0F0F0F) | ((n << 4) & 0xF0F0F0F0);
    // Swap adjacent bytes (8-bit)
    n = ((n >> 8) & 0x00FF00FF) | ((n << 8) & 0xFF00FF00);
    // Swap adjacent 16-bit words
    n = (n >> 16) | (n << 16);
    return n;
}

int main() {
    unsigned int a = 0x12345678;
    printf("Original: %08x\n", a);
    printf("Reversed: %08x\n", reverse_bits(a)); // Output: 1e6a2c48
    return 0;
}
*/
