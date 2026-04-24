#include <stdio.h>
#include <stdlib.h>

void stringRevers(char srr[],int start, int end){
    if(start < end){
        char temp = srr[start];
        srr[start] = srr[end];
        srr[end] = temp;
        start++;
        end--;
        stringRevers(srr,start,end);
    }
    return;
}
int main() {
   char sr[] = "HelloHiHowAreYou";
   printf("%s\n",sr);
   int SizeA = (sizeof(sr)/sizeof(sr[0]))-2;
   stringRevers(sr,0,SizeA);
   printf("%s\n",sr);
    return 0;
}
