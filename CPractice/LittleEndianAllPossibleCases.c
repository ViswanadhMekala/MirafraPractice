#include <stdio.h>
#include <stdlib.h>

union var{
    unsigned int Data;
    struct{
        unsigned char a;
        unsigned char b;
        unsigned char c;
        unsigned char d;
    }BitFields;
};

int main()
{
    unsigned int a = 0x12345678;
    printf("%x\n",a);
    
    unsigned char* ptr = (unsigned char*)&a;
    
    unsigned char temp = *(ptr+0);
    *(ptr+0) = *(ptr+3);
    *(ptr+3) = temp;
    
    temp = *(ptr+1);
    *(ptr+1) = *(ptr+2);
    *(ptr+2) = temp;
    
    printf("%x\n",a);
    
    a = (a&0xFF000000)>>24 | (a&0x000000FF)<<24 | (a&0x00FF0000)>>8 | (a&0x0000FF00)<<8 ;
    printf("%x\n",a);
    
    union var Store = {0xABCDEF12};
    printf("%x\n",Store.Data);
    
    printf("%x",Store.BitFields.a);
    printf("%x",Store.BitFields.b);
    printf("%x",Store.BitFields.c);
    printf("%x\n",Store.BitFields.d);
    
    Store.Data = Store.BitFields.a<<24 | Store.BitFields.b<<16 | Store.BitFields.c<<8 | Store.BitFields.d;
    
    printf("%x\n",Store.Data);
    
    printf("%x",Store.BitFields.a);
    printf("%x",Store.BitFields.b);
    printf("%x",Store.BitFields.c);
    printf("%x",Store.BitFields.d);
    
    return 0;
}
