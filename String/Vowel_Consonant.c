#include<stdio.h>
#include<string.h>
int main(){
        char str[100];
        int i=0;
        printf("Enter first string : ");
        scanf("%s",str);
        int vowel=0;
      
      while (str[i]!='\0')
      {
        if(str[i]=='a' || str[i]=='e' ||str[i]=='i' ||str[i]=='o' ||str[i]=='u' || str[i]=='U' 
            ||str[i]=='A' ||str[i]=='E' ||str[i]=='I' ||str[i]=='O' ){
                vowel++;
            }
            i++;
      }
      printf(" No. of vowel %d, No. of consonant %d",vowel,strlen(str)-vowel);
      
        
        

    return 0;
}