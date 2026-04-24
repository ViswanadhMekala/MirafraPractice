#include <stdio.h>
#include <stdlib.h>


int main() {
   
   int x = 4;
   int Result = 0;
   int interRes = 0;
   int Index = 0;
   
   int Temp = x;
   while(Temp){
       interRes = (interRes << 1) | (Temp%2);
       Temp = Temp>>1;
       Index++;
   }
   
   Temp = interRes;
   while(Temp|| Index>0){
       Result = (Result << 1) | (Temp%2);
       Temp = Temp>>1;
       Index--;
   }
   
   printf("%d\n",x);
   printf("%d\n",interRes);
   printf("%d\n",Result);
   return 0;
}
