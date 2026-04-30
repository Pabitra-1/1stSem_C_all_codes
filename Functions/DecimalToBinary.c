#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{

    int num;
    printf("Enter a number : ");
    scanf("%d", &num);
    int arr[100];
    int i;
    int n = num;
    for (i = 0; num > 0; i++)
    {
        arr[i] = num % 2;
        num /= 2;
    }
    printf("Binary represantation of %d = ", n);
    i--;

    while (i >= 0)
    {
        printf("%d", arr[i]);
        i--;
    }
    return 0;
}
