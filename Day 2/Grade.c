#include<stdio.h>
#include<conio.h>
int main(){
   int num1;
   printf("Enter The Marks : ");
   scanf("%d",&num1);
   if (num1<=100 && num1>=90) printf("Grade == O");
   else if (num1<90 && num1>=80) printf("Grade == E");
   else if (num1<80 && num1>=70) printf("Grade == A");
   else if (num1<70 && num1>=60) printf("Grade == B");
   else if (num1<60 && num1>50) printf("Grade == C");
   else if (num1==50) printf("Grade == D");
   else if ( num1<0 || num1>100) printf("Enter a Valid Number");
  
   
   else printf("Fail");
   
   




    getch();
}