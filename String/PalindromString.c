#include<stdio.h>
#include<string.h>

int main(){
   
    char ch[100],rev[100];
    printf("Enter a string : ");
   scanf("%s",ch);
    strcpy(rev,ch);
    strrev(rev);
    printf((strcmp(rev,ch)==0 ? "Pallindrom" : "Not Pallindrom"));
   
 
    
   
    return 0;
}