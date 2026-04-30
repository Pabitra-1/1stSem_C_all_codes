#include<stdio.h>
int main(){
    int arr[7]={1,2,3,4,5,6,7};
    int *ptr=&arr[6];
    printf("Array in reverse order : ");
    for(int i = 0 ; i<7 ; i++){
        printf("%d ",*ptr);
        ptr--;
    }


    
    return 0;
}