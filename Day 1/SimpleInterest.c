#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
 float p,r,t;
 printf("Enter Principle : ");
 scanf("%f",&p);
 printf("Enter Rate : ");
 scanf("%f",&r);
 printf("Enter Time : ");
 scanf("%f",&t);
 printf("Simple interest is : %f",(p*r*t)/100);
 printf("\nCompound interest is : %f",p*pow((1+r/100),t)-p);



    getch();
}