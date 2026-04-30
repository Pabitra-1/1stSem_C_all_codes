#include <stdio.h>
#include <string.h>
#include <math.h>

  void find(int a, int b, int c){
      int temp;
      if(a>b) temp=a;
      else temp=b;
      if(temp>c) printf("Largest among them is : %d",temp);
      else printf("Largest among them is : %d",c);
  }
int main()
{
  int a,b,c;
  printf("Enter 3 numbers : ");
 scanf("%d%d%d",&a,&b,&c);
 find(a,b,c);
    return 0;
}
