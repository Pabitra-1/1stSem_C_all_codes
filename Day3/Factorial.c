
#include <stdio.h>
#include <conio.h>
main()
{
    int n, x, f = 1;
    printf("\n\t Enter a number: ");
    scanf("%d", &n);
    x = n;
    while (n >= 1)
    {
        f = f * n;
        n--;
    }
    printf("\n\t Factorial of %d is %d", x, f);
    return 0;
}