#include <stdio.h>
#include <stdlib.h>


int main() {
   
   char str1[20] = "Hi";
   char str2[] = "Hello";
   
   printf("%s\n",str1);
   
   int temp = 0;
   while(str1[temp] != '\0'){
       temp++;
   }
   
   char* tempPtr = str2;
   while(*tempPtr != '\0'){
       str1[temp++] = *tempPtr;
       tempPtr++;
   }
   
   printf("%s\n",str1);
   
    return 0;
}
