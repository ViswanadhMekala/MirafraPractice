/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

int main()
{
    // Dynamic initialization of structure with values
    Node* Head =(Node*)malloc(sizeof(Node));
    Head->value = 76;
    Head->next = NULL;
    
    // Structure variable initialization with members
    Node node1 = {45,NULL};
    
    // Structure variable initialization with designated initialization
    Node node2 = {.value = 50, .next = NULL};
    
    // Adding node1 to the Head
    Head->next = &node1;
    
    // Adding node2 to the Head list
    Head->next->next = &node2;
    
    // Taking the temporary variable for list access
    Node* temp = Head;
    
    while(temp){
        printf("%d->",temp->value);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}