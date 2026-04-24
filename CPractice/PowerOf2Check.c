#include <stdio.h>
#include <stdlib.h>


int main() {
   
   int a = 4;
   if((a & (a-1)) == 0){
       printf("the number is power of 2");
   }
   else{
       printf("the number is Not a power of 2");
   }
   
    return 0;
}
