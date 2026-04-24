/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

struct sStack{
    int items[100];
    int sTop;
};

int main()
{
    struct sStack myStack;
    myStack.sTop = -1;
    
    int NumbersTobeAdded = 0;
    printf("Enter the number of elements to be added into the stack is (should be less than 100): ");
    scanf("%d",&NumbersTobeAdded);
    
    while(NumbersTobeAdded){
        printf("\nAdd the Element into the stack : ");
        int Temp;
        scanf("%d",&Temp);
        myStack.items[++myStack.sTop] = Temp;
        NumbersTobeAdded--;
    }
    
    NumbersTobeAdded = 0;
    printf("\nEnter the number of elements to be popped from the stack is : ");
    scanf("%d",&NumbersTobeAdded);
    
    while(NumbersTobeAdded){
        int Temp = (myStack.sTop >= 0)?(myStack.items[myStack.sTop--]):INT_MIN;
        printf("\nThe Element removed from the stack : %d",Temp);
        NumbersTobeAdded--;
    }
    

    return 0;
}