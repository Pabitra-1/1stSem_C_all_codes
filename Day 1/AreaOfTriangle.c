#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
    float s1,s2,s3;
    float s;
    printf("Enter 3 sides of triangle : ");
    scanf("%f%f%f",&s1,&s2,&s3);
    s=(s1+s2+s3)/2;
    printf("Area of the triangle is : %f",sqrt(s*(s-s1)*(s-s2)*(s-s3)));

    getch();
}