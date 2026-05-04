
#include <stdio.h>

int a[]= {8,2,5,1,6,8,5,8};

int main()
{
    int SizeofArray = sizeof(a)/sizeof(int);
    printf("Array Before Sort\n");
    for(int i = 0;i<SizeofArray;i++){
        printf("%d ",a[i]);
    }
    printf("\nArray After Sort \n");
    int Temp = SizeofArray;
    while(Temp >= 1){
        for(int j=1;j<SizeofArray;j++){
            if(a[j-1]>a[j]){
                int t = a[j];
                a[j] = a[j-1];
                a[j-1] = t;
            }
        }
        
        Temp--;
    }
    
    for(int i = 0;i<SizeofArray;i++){
        printf("%d ",a[i]);
    }

    return 0;
}
