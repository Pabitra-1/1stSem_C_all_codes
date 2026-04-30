#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
    long int bs;
    printf("Enter Your Basic Salary : ");
    scanf("%ld",&bs);
    printf("Gross salary : %ld",((bs*5)/100)+((bs*10)/100)+bs);




    getch();
}