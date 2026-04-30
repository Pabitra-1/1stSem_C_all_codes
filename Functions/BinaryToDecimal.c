#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int num;

    printf("Enter a number : ");
    scanf("%d", &num);
    int s = 0;
    int ans = 0;
    int n = num;
    while (num > 0)
    {
        if (num % 10 != 0)
        {

            ans = ans + pow(2, s);
        }
        s++;
        num /= 10;
    }
    printf("Decimal represantation of %d =%d ", n, ans);

    return 0;
}
