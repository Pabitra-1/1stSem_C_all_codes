#include<stdio.h>
#include<string.h>

int main(){
   
    char ch[100];
    printf("Enter a string : ");
    fgets(ch,sizeof(ch),stdin);
    int j = strlen(ch);
    j--;

    
    int i = 0;
    while(i<j){
        char c = ch[i];
        ch[i]=ch[j];
        ch[j] = c;
        i++;
        j--;
    }
    printf("String aftre Reversing : ");
    puts(ch);
 
    
   
    return 0;
}