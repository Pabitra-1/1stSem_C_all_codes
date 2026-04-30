#include<stdio.h>
int main(){
        char str[100],str2[100];
        int i=0,j=0;
        printf("Enter first string : ");
        scanf("%s",str);
        printf("Enter second string : ");
        scanf("%s",str2);
        while (str[i]!='\0')
        {
            i++;
        }
        while (str2[j]!='\0')
        {
            str[i]=str2[j];
            i++;
            j++;
        }
        str[i]='\0';
        printf("Conctinated string is %s",str);
        
        

    return 0;
}