#include <stdio.h>
#include <stdlib.h>

void cntBitFunction(int Value, int* CntValue){
    if(Value <= 0){
        return;
    }
    if(Value&0x1U){
        (*CntValue)++;
    }
    cntBitFunction(Value>>1,CntValue);
}

int main() {
   
   unsigned int x = 78;
   unsigned int BitCnt = 0;
   cntBitFunction(x,&BitCnt);
   
   printf("%b\n",x);
   printf("%d\n",x);
   printf("%d\n",BitCnt);
   return 0;
}
