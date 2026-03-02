// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
//   int num ; 
//   printf("Enter a number : ");
//   scanf("%d",&num);
//   if(num==0) printf("Zero");
//   if(num<0){
//       printf("Minus");
//       num=-num;
      
//   }
//   if(num>=100){
//       int h = num/100;
//       if(h==1) printf("One Hundred");
//       else if(h==2) printf("Two Hundred");
//       else if(h==3) printf("Three Hundred");
//       else if(h==4) printf("Four Hundred");
//       else if(h==5) printf("Five Hundred");
//       else if(h==6) printf("Six Hundred");
//       else if(h==7) printf("Seven Hundred");
//       else if(h==8) printf("Eight Hundred");
//       else if(h==9) printf("Nine Hundred");
//     num%=100;
    
      
//   }
//   if(num>=11 && num<=19){
//       int h = num/100;
//       if(num==11) printf("One Eleven");
//       else if(num==12) printf("One Twelve");
//       else if(num==13) printf("One Thirteen");
//       else if(num==14) printf("One Fourteen");
//       else if(num==15) printf("One Fifteen");
//       else if(num==16) printf("One Sixteen");
//       else if(num==17) printf("One Seventeen");
//       else if(num==18) printf("One Eightteen");
//       else if(num==19) printf("One Nineteen");
  
    
      
//   }
//   else {
//       if(num>=20){
//       int h = num/10;
//         if(h==2) printf("One Twinty");
//       else if(h==3) printf("One Thirty");
//       else if(h==4) printf("One Fourty");
//       else if(h==5) printf("One Fifty");
//       else if(h==6) printf("One Sixty");
//       else if(h==7) printf("One Seventy");
//       else if(h==8) printf("One Eighty");
//       else if(h==9) printf("One Ninety");
  
    
      
//   }
//     if(num==1) printf("One");
//       else if(num==2) printf("Two");
//       else if(num==3) printf("Three");
//       else if(num==4) printf("Four");
//       else if(num==5) printf("Five");
//       else if(num==6) printf("Six");
//       else if(num==7) printf("Seven");
//       else if(num==8) printf("Eight");
//       else if(num==9) printf("Nine");
//       else if(num==10) printf("Ten");
  
  
  
//   }
                        //code 2
  
//   int a,b,temp;
//   printf("Enter two numbers : ");
//   scanf("%d%d",&a,&b);
//   if(a<0) a=-a;
//   if(b<0) b=-b;
// while(b!=0){
//     temp=b;
//     b=a%b;
//     a=temp;
    
// }
//   printf("GCD = %d",a);
  
  
                     //CODE 3
                     
//     int a,b;
//   printf("Enter two numbers : ");
//   scanf("%d%d",&a,&b);
//   a=a^b;
//   b=a^b;
//   a=a^b;
//   printf("After swap a = %d, b = %d",a,b);
  
                    //  CODE 4
                    
                    
                    int num , original,digit,temp;
                    int count = 0;
                    int sum=0;
                    int power,i;
                     printf("Enter a numbers : ");
                      scanf("%d",&num);
                      original=num;
                      temp = num;
                      while(temp!=0){
                          digit=temp%10;
                          
                          power=0;
                          for(i=1; i<=count ; i++){
                              power*=digit;
                          }
                          sum+=power;
                          temp/=10;
                          
                      }
                      if(sum==original){
                    printf("%d is an Armstrong num",original);
                          
                      }
            else  printf("%d is an Armstrong num",original);
  

    return 0;
}
