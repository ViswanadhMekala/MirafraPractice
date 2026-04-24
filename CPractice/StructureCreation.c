/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}Node;

int main()
{
    Node* node1 = (Node*)malloc(sizeof(Node));
    Node* node2 = (Node*)malloc(sizeof(Node));
    
    node1->val = 10;
    node1->next = node2;
    
    node2->val = 2;
    node2->next = NULL;
    
    Node* ptr = node1;
    while(ptr != NULL){
        printf("%d\n",ptr->val);
        
        ptr = ptr->next;
    }

    return 0;
}
