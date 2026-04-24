#include <stdio.h>
#include <stdlib.h>


int main() {
   
   char str1[20] = "   -42abc";
   int result = 0;
   int index = 0;
   int signCheck = 1;
   
   while((str1[index] == ' ')||(str1[index] == '\n')||(str1[index] == '\t')){
       index++;
   }
   
   if((str1[index] == '-')||(str1[index] == '+')){
       if((str1[index] == '-')){
           signCheck = -1;
       }
       index++;
   }
   
   while((str1[index] >= '0')&&(str1[index] <= '9')){
       result = result*10 + str1[index]-'0';
       index++;
   }
   
  result *= signCheck;
   
   printf("%s\n",str1);
   printf("%d\n",result);
   
    return 0;
}
