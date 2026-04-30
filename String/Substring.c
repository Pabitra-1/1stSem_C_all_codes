#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int i, j, len;
    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);
    printf("All substrings:\n");
    for (i = 0; i < len; i++)
    {
        for (j = 1; j <= len - i; j++)
        {
            printf("%.*s\n", j, &str[i]);
        }
    }
    return 0;
}