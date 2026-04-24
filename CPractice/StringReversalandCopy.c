/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
    char s[]="Hello";
    char dup[10],dup1[10];
    int sizeS = sizeof(s)/sizeof(char);
    dup[sizeS-1] = '\0';
    dup1[sizeS-1] = '\0';
    
    printf("%d\n",sizeS);
    
    
    for(int i=0;((dup[i]=s[sizeS-i-2])&&(i<(sizeS-2)));i++){
        ;
    }
    printf("%s\n",s);
    printf("%s\n",dup);
    
    for(int i=0;(dup1[i]=s[i])!= '\0';i++){
        ;
    }
    printf("%s\n",dup1);
    
    for(int i=0,j=strlen(s)-1;i<j;s[i]^=s[j],s[j]^=s[i],s[i]^=s[j],i++,j--);
    printf("%s\n",s);

    return 0;
}