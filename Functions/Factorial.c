#include <stdio.h>
#include <string.h>
#include <math.h>
int fact(int n ){
    if(n==1) return 1;
    return n*fact(n-1);
}
  
int main()
{
  int num;
  printf("Enter a number : ");
  scanf("%d",&num);
    printf("Factorial of %d is %d",num,fact(num));
    return 0;
}
