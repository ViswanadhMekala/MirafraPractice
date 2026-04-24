/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    unsigned char input = 0;
    
    printf("Enter the Number between 1 to 127 for parity Calculation\n");
    scanf("%hhu",&input);
    
    printf("Input before parity addition is : %d\n",input);
    int CalPar = 0;
    for(int i=0;i<7;i++){
        if((input >> i)&01U){
            CalPar++;
        }
    }
    
    CalPar = ((CalPar % 2U) != 0)?1:0;
    
    input = input | (CalPar << 7U) ;// Adds the parity to the user input
    printf("Input after parity addition is : %d\n",input);

    return 0;
}