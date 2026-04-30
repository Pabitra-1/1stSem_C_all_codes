#include <stdio.h>
int main()
{
    char str[100];
    int freq[256] = {0}, i, max = 0;
    char ch;
    printf("Enter a string: ");
    scanf("%s", str);
    for (i = 0; str[i] != '\0'; i++)
    {
        freq[(int)str[i]]++;
    }
    for (i = 0; i < 256; i++)
    {
        if (freq[i] > max)
        {
            max = freq[i];
            ch = i;
        }
    }
    printf("Most frequent character: %c (%d times)\n", ch, max);
    return 0;
}