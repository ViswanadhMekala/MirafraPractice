#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    // 1. Create nodes
    struct Node* head = malloc(sizeof(struct Node));
    struct Node* second = malloc(sizeof(struct Node));
    struct Node* third = malloc(sizeof(struct Node));

    head->data = 10;
    second->data = 20;
    third->data = 30;

    // 2. Link nodes
    head->next = second;
    second->next = third;

    // 3. CREATE THE LOOP: Point the last node back to 'second'
    third->next = second; 

    struct Node* Temp1 = head;
    struct Node* Temp2 = head;
    while((Temp1 != NULL)&&(Temp2 != NULL)){
        Temp1= Temp1->next;
        Temp2=Temp2->next->next;
        if(Temp1 == Temp2){
            printf("There is a loop in thelinked list");
            break;
        }
    }

    return 0;
}
