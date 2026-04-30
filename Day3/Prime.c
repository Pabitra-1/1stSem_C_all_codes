#include <stdio.h>
#include <conio.h>
main()
{
    int n, i;
    printf("\n\t Enter a number: ");
    scanf("%d", &n);
    for (i = 2; i <= n - 1; i++)
    {
        if (n % i == 0)
            break;
    }
    if (i == n)
        printf("\n\t %d is a Prime No.", n);
    else
        printf("\n\t %d is Not a prime no.", n);
    return 0;
}