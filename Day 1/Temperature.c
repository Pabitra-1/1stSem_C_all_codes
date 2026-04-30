#include<stdio.h>
#include<conio.h>
int main(){
    float fer,cel;
    printf("Enter the temperature in Celcious : ");
    scanf("%f",&cel);
    printf("Equivalent Fahrenheit = %f",1.8*cel+32);
    printf("\nEnter the temperature in Fahrenheit : ");
    scanf("%f",&fer);
    printf("Equivalent celcious = %f",(fer-32)/1.8);


    getch();
}