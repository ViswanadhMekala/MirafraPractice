#include <stdio.h>
#include <stdlib.h>


int main() {
   
   char str1[20] = "Hi";
   char str2[10];
   
   for(int i=0; (str2[i]=str1[i]) != '\0';i++);
   printf("%s\n",str1);
   printf("%s\n",str2);
   
    return 0;
}
