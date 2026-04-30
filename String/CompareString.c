#include <stdio.h>

int size(char *ch)
{
    int n = 0;
    for (int i = 0; ch[i] != '\0'; i++)
    {
        n++;
    }
    return n;
}
int main()
{
    char str1[100], str2[100];
    printf("Enter first string : ");
    scanf("%s", str1);
    printf("Enter second string : ");
    scanf("%s", str2);
    int s1 = 0, s2 = 0;
    s1 = size(str1);
    s2 = size(str2);
    if (s1 != s2)
    {
        printf("Strings are not equal");
        return 0;
    }
    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] != str2[i])
        {
            printf("Strings are not equal");
            return 0;
        }
    }
    printf("Strings are  equal");

    return 0;
}