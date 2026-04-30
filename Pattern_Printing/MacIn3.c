#include <stdio.h>
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

main()
{
    int n1, n2, n3;
    printf("Enter Three numbers : ");
    scanf("%d%d%d", &n1, &n2, &n3);
    n1 = max(n1, n2);
    n3 = max(n1, n3);
    printf("Maximum is %d ", n3);

    return 0;
}