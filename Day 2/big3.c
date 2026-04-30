#include<stdio.h>
#include<conio.h>
int main(){
   int num1,num2,num3;
   printf("Enter The First Number : ");
   scanf("%d",&num1);
   printf("Enter The Second Number : ");
   scanf("%d",&num2);
   printf("Enter The Third Number : ");
   scanf("%d",&num3);
   
  if(num1>num2 && num1>num3) printf("The bigest number is %d  ",num1);
  else if (num2>num1 && num2>num3) printf("The bigest number is %d  ",num2);
  else if (num1 == num2 || num2==num3 || num3==num1) printf("All are equal %d : ",num1);
  
  
  else printf("The bigest number is %d  ",num3);





    getch();
}