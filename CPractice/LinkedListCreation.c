/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
    struct node* prev;
}Node;

int main()
{
    Node* node1 = (Node*)malloc(sizeof(Node));
    
    node1->value = 2;
    node1->next = NULL;
    node1->prev = NULL;
    
    
    Node* Head = node1;
    while(Head != NULL){
        printf("%d\n",Head->value);
        Head = Head->next;
    }
    
    Head = node1;
    while(Head != NULL){
        printf("%d\n",Head->value);
        Head = Head->prev;
    }

    return 0;
}
