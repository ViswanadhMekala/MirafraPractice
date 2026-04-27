#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sbrk

int main()
{
    int* a = (int*)malloc(sizeof(int));
    int* b = (int*)malloc(sizeof(int));
    
    if(a-b > 0){
        printf("Heap is growing Downwards");
    }
    else{
        printf("Heap is growing Upwards");
    }
    
    void* initial_break = sbrk(1);
    int *Some = (int*)malloc(4); // Allocate a large chunk
    void* new_break = sbrk(1);

    if (new_break > initial_break) {
        printf("\nSystem heap grew UPWARDS\n");
    } else {
        printf("\nsbrk didn't move (likely used mmap or existing space)\n");
    }
    return 0;
}
