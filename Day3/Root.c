#include <stdio.h>
#include <conio.h>
#include <math.h>
main()
{
    double a, b, c, discriminant, root1, root2, real, imag;
    printf("\n\n\t Enter coefficients a,b,c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    discriminant = b * b - 4 * a * c;
    if (a != 0)
    {
        if (discriminant > 0)
        {
            root1 = (-b + sqrt(discriminant)) / (2 * a);
            root2 = (-b - sqrt(discriminant)) / (2 * a);
            printf("\n\t Roots are real and unequal.");
            printf("\n\t root1= %.2lf \n\t root2= %.2lf", root1, root2);
        }
        else if (discriminant == 0)
        {
            root1 = root2 = -b / (2 * a);
            printf("\n\t Roots are real and equal.");
            printf("\n\t root1 = root2 = %.2lf", root1);
        }
        else
        {
            real = -b / (2 * a);
            imag = sqrt(-discriminant) / (2 * a);
            printf("\n\t Roots are imaginary.");
            printf("\n\t root1= %.2lf + %.2lfj \n\t root2= %.2lf - %.2lfj", real, imag, real, imag);
        }
    }
    else
        printf("\n\t Equation is linear.");
    getch();
}