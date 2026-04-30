#include <stdio.h>
#include <string.h>
#include <math.h>
int fact(int n ){
    if(n==1) return 1;
    return n*fact(n-1);
}
int ncr(int n,int r){
    return fact(n)/(fact(n-r)*fact(r));
}
  
int main()
{
  int n,r;
  printf("Enter nCr : ");
  scanf("%d%d",&n,&r);
  if(n<=0 || r<0){
    printf("Mathematical Error !! ");
    return 0;
  }
    printf("%dC%d is : %d",n,r,ncr(n,r));
    return 0;
}
