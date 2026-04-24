/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void combineMerge(int a[],int start,int mid, int end){
    int i,j,k;
    
    int n1 = mid-start +1;
    int n2 = end-mid;
    
    int* L1 =(int*)malloc(n1*sizeof(int));
    int* L2 =(int*)malloc(n2*sizeof(int));
    
    for(i=0;i<n1;i++)L1[i]=a[start+i];
    for(j=0;j<n2;j++)L2[j]=a[mid+1+j];
    i=0;
    j=0;
    k=start;
    while((i<n1)&&(j<n2)){
        if(L1[i]>L2[j]){
            a[k++] = L2[j++];
        }
        else{
            a[k++] = L1[i++];
        }
    }
    while((i<n1)){
        a[k++] = L1[i++];
    }
    while(j<n2){
        a[k++] = L2[j++];
    }
    free(L1);
    free(L2);
    L1 = NULL;
    L2 = NULL;
    
}

void mergesort(int a[], int start,int end){
    if(start<end){
        int mid = (start + (end-start)/2);
        
        mergesort(a,start,mid);
        mergesort(a,mid+1,end);
        
        combineMerge(a,start,mid,end);
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
    mergesort(a,0,sizeA-1);
    
    for(int i=0;i<sizeA;i++){
        printf("%d ",a[i]);
    }
    
    return 0;
}