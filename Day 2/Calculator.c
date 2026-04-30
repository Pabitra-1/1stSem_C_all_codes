#include<stdio.h>
#include<conio.h>
int main(){
  char ch;
  double num1,num2;
   printf("Enter The First Number : ");
   scanf("%lf",&num1);
   printf("Enter operator (+,-,*,/) : ");
   scanf(" %c",&ch);
   printf("Enter The Second Number : ");
   scanf("%lf",&num2);
   switch (ch)
   {
   case '+':
    printf("%.1lf+%.1lf = %.1lf",num1,num2,num1+num2);
    break;
   case '-':
    printf("%.1lf - %.1lf = %.1lf",num1,num2,num1-num2);
    break;
   case '*':
    printf("%.1lf*%.1lf = %.1lf",num1,num2,num1*num2);
    break;
   case '/':
   if(num2!=0){

       printf("%.1lf/%.1lf = %.1lf",num1,num2,num1/num2);
       break;
    }
    else printf("Divison no possible as dinominator is Zero");
   
   default:
   printf("Enter a valid operator");
    break;
   }
   
   
   




    getch();
}