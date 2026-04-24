#include <stdio.h>

/**
 * Alternative Recursive Logic
 * @param n: The remaining bits to process
 * @param rev: The result we are building (start at 0)
 * @param steps: How many bit positions are left (7 for your case)
 */
void reverseRecursive(unsigned int* n, unsigned int start, int last,unsigned numt) {
    if(start >= last){
        return;
    }
    
    *n |= (((numt>>last)&0x1u)<<start) | (((numt>>start)&0x1u)<<last);
    start++;
    last--;
    reverseRecursive(n,start,last,numt);
}

int main() {
    unsigned int num = 78; // Binary: 1001110
    unsigned int result = 0;
    reverseRecursive(&result, 0, 7,num);
    
    printf("Original: %u\n", num);
    printf("Original: %b\n", num);
    printf("Reversed: %u\n", result); // Output: 57
    printf("Reversed: %b\n", result); // Output: 57
    return 0;
}
