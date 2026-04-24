/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int a[]= {10,9,8,7,6,5,4,3,2,1};
    int sizeArray = sizeof(a)/sizeof(int);
    for(int i=0;i<sizeArray;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    
    for(int i=1;i<sizeArray;i++){
        for(int j=i;j>0;j--){
            if(a[j]<a[j-1]){
                int TempVa = a[j];
                a[j] = a[j-1];
                a[j-1] = TempVa;
            }
        }
    }
    
    for(int i=0;i<sizeArray;i++){
        printf("%d\t",a[i]);
    }

    return 0;
}