#include <stdio.h>

int main()
{

    int num, original, digit, temp;
    int count = 0;
    int sum = 0;
    int power, i;
    printf("Enter a numbers : ");
    scanf("%d", &num);
    original = num;
    temp = num;
    while (temp != 0)
    {
        digit = temp % 10;

        power = 0;
        for (i = 1; i <= count; i++)
        {
            power *= digit;
        }
        sum += power;
        temp /= 10;
    }
    if (sum == original)
    {
        printf("%d is an Armstrong number", original);
    }
    else
        printf("%d is not an Armstrong number", original);

    return 0;
}