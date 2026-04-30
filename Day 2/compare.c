#include<stdio.h>
#include<conio.h>
int main(){
   int num1,num2;
   printf("Enter The First Number : ");
   scanf("%d",&num1);
   printf("Enter The Second Number : ");
   scanf("%d",&num2);
   
  
   
   if (num1>=num2)
   {
    if(num1==num2) printf("Result is %d == %d",num1,num2);
    else printf("Result is %d > %d",num1,num2);
   }
   else printf("Result is %d < %d",num1,num2);
   
   
   




    getch();
}