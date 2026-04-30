#include <stdio.h>
#include <conio.h>
main()
{
    int i, j, k, n;
    printf("Enter no. of rows: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = n - i; j >= 1; j--)
            printf(" ");
        for (k = 1; k <= i; k++)
            printf("%d ", i);
        printf("\n");
    }
    return 0;
}