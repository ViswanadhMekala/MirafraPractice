/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b =temp;
    //printf("\n%d\n",*a);
}

int getPartitions(int a[],int start,int end){
    int Pivot = a[end];
    int i = start-1;
    
    for(int j=start;j<end;j++){
        if(a[j]<Pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    
    swap(&a[i+1],&a[end]);
    
    return i+1;
}

void quickSort(int a[], int start,int end){
    if(start<end){
        
        int Partition = getPartitions(a,start,end);
        
        quickSort(a,start,Partition-1);
        quickSort(a,Partition+1,end);
        
    }
}

int main()
{
    int a[]     = {10,9,8,7,6,5,4,3,2,1};
    int sizeA   = sizeof(a)/sizeof(a[0]);
    for(int i=0;i<sizeA;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    quickSort(a,0,sizeA-1);
    
    for(int i=0;i<sizeA;i++){
        printf("%d ",a[i]);
    }
    
    return 0;
}