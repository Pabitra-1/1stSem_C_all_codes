#include <stdio.h>
#include <conio.h>
 int main()
{
    int i, n, s = 0;
    printf("\n\tEnter a number: ");
    scanf("%d", &n);
    for (i = 1; i < n; i++)
    {
        if (n % i == 0)
            s = s + i;
    }
    if (s == n)
        printf("\n\t%d is a perfect no.", n);
    else
        printf("\n\t%d is a not a perfect no.", n);
  return 0;
}