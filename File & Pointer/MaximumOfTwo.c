#include<stdio.h>
int main(){
    int num1,num2;
    int *ptr1,*ptr2;
    printf("Enter two Numbers : ");
    scanf("%d%d",&num1,&num2);
    ptr1=&num1;
    ptr2=&num2;
//    printf((*ptr1>*ptr2) ? "Maximum is %d",*ptr1:"Maximum is %d",*ptr2);//using ternary operator
if(*ptr1>*ptr2){
    printf("Maximum is %d",*ptr1);
}
else if (*ptr1<*ptr2)
{
    printf("Maximum is %d",*ptr2);
    
}
else printf("Both are equal");


    

    return 0;
}