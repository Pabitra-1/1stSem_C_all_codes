#include<stdio.h>
int main(){
    int num1,num2;
    int *ptr1,*ptr2;
    printf("Enter two Numbers : ");
    scanf("%d%d",&num1,&num2);
    ptr1=&num1;
    ptr2=&num2;
    printf("%d",*ptr1+*ptr2);

    

    return 0;
}