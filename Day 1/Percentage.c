#include<stdio.h>
#include<conio.h>
int main(){
   float beng,eng,phy,chem,math;
   printf("Enter Bengali's marks : ");
   scanf("%f",&beng);
   
   printf("Enter English's marks : ");
   scanf("%f",&eng);
   printf("Enter Physics's marks : ");
   scanf("%f",&phy);
   printf("Enter Chemistry's marks : ");
   scanf("%f",&chem);
   printf("Enter Math's marks : ");
   scanf("%f",&math);
   printf("Average is : %f",( beng+eng+math+phy+chem)/5);

    getch();
}