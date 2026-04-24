#include <stdio.h>
#include <stdlib.h>
union TempVal{
    unsigned int x;
    struct {
        unsigned char a;
        unsigned char b;
        unsigned char c;
        unsigned char d;
    }byte_t;
};

int main() {
   unsigned int x = 0x12345678;
   printf("%x\n",x);
   
   // using bitwise operations 
   x = (x&0xFF000000)>>24 | (x&0x000000FF)<<24 | (x&0x00FF0000)>>8 |  (x&0x0000FF00)<<8 ;
   printf("%x\n",x);
   
   
   // using Unions
   union TempVal Temp;
   Temp.x = 0x12345678;
   printf("%x\n",Temp.x);
   
   unsigned int Y= 0;
   Y = Temp.byte_t.d|Temp.byte_t.c<<8 |Temp.byte_t.b<<16| Temp.byte_t.a<<24;
   printf("%x\n",Y);
   
   
   // using pointers;
   
   unsigned int v = 0x12345678;
   printf("%x\n",v);
   unsigned char* vPtr = (unsigned char*)&v;
   unsigned char TemChar = 0;
   
   TemChar = *(vPtr+0);
   *(vPtr) = *(vPtr+3);
   *(vPtr+3) = (TemChar & 0xFF);
   
   TemChar = *(vPtr+1);
   *(vPtr+1) = *(vPtr+2);
   *(vPtr+2) = (TemChar & 0xFF);
   printf("%x = Last\n",v);
   
    return 0;
}
