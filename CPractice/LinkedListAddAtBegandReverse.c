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

Node* addatBegining(Node* temp, int Value){
    Node* TempHead = (Node*)malloc(sizeof(Node));
    TempHead->value = Value;
    TempHead->next = temp;
    
    return TempHead;
}

Node* reverseLinkedList(Node* toRevHead){
    Node* Prev = NULL;
    Node* Curr = toRevHead;
    Node* Next = NULL;
    
    while(Curr){
        Next = Curr->next;
        Curr->next = Prev;
        Prev = Curr;
        Curr = Next;
    }
    return Prev;
}

int main()
{
    Node* Head = NULL;
    
    Head = addatBegining(Head,23);
    Head = addatBegining(Head,26);
    Head = addatBegining(Head,28);
    Head = addatBegining(Head,21);
    Head = addatBegining(Head,20);
    
    // Taking the temporary variable for list access
    Node* temp = Head;
    
    while(temp){
        printf("%d->",temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
    
    Head = reverseLinkedList(Head);
    
    temp = Head;
    
    while(temp){
        printf("%d->",temp->value);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}