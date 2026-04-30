#include<stdio.h>
#include<string.h>

int main(){
   
    char ch[100];
    char ch2[100];
    printf("Enter a string : ");
  scanf("%s",ch);
   int i = 0;
    while(ch[i]!='\0'){
       ch2[i]=ch[i];
       i++;
    }
    printf("String aftre Copy : %s",ch2);

 
    
   
    return 0;
}