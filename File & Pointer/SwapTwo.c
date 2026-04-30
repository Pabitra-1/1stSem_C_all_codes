#include<stdio.h>
int main(){
    int num1,num2;
    int *ptr1,*ptr2;
    printf("Enter two Numbers : ");
    scanf("%d%d",&num1,&num2);
    ptr1=&num1;
    ptr2=&num2;
    printf("Before swap first number : %d\tSecond Number : %d",num1,num2);
        *ptr1^=*ptr2;//Using X-OR 
        *ptr2^=*ptr1;
        *ptr1^=*ptr2;
    
    printf("\nAfter swap first number : %d\tSecond Number : %d",*ptr1,*ptr2);

    return 0;
}