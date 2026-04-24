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

Node* addAtBeg(Node* tempHead,int Value){
    Node* TempNode = (Node*)malloc(sizeof(Node));
    TempNode->val = Value;
    TempNode->next = tempHead;
    
    return TempNode;
}

Node* ReversingAlinkedList(Node* AccHead){
    
    Node* Prev = NULL;
    Node* Current = AccHead;
    Node* Next = NULL;
    
    while(Current != NULL){
        Next = Current->next;
        Current->next = Prev;
        Prev = Current;
        Current = Next;
        //printf("%x\n",Prev);
    }
    return Prev;
}

int main()
{
    Node* Head = NULL;
    
    /*
    Node* node1 = (Node*)malloc(sizeof(Node));
    Node* node2 = (Node*)malloc(sizeof(Node));
    
    node1->val = 10;
    node1->next = node2;
    
    node2->val = 2;
    node2->next = NULL;
    
    Node* ptr = node1;
    */
    
    for(int i=1;i<10;i++){
        Head = addAtBeg(Head,i);
    }
    
    Node* ptr = Head;
    
    while(ptr != NULL){
        printf("%d->",ptr->val);
        
        ptr = ptr->next;
    }
    
    printf("\n List After Reversal \n");
    
    Head = ReversingAlinkedList(Head);
    
    ptr = Head;
    
    
    while(ptr != NULL){
        printf("%d->",ptr->val);
        ptr = ptr->next;
    }

    return 0;
}
