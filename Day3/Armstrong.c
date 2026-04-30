#include <stdio.h>
#include <conio.h>
main()
{
    int n, r, s = 0, t;
    printf("\n\tEnter a number: ");
    scanf("%d", &n);
    t = n;
    while (n > 0)
    {
        r = n % 10;
        s = s + (r * r * r);
        n = n / 10;
    }
    if (s == t)
        printf("%d is an Armstrong No.", t);
    else
        printf("%d is Not An Armstrong No.", t);
    return 0;
}