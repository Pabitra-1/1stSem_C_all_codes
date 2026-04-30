#include <stdio.h>

main()
{
    int n;
    printf("Enter no. of rows: ");
    scanf("%d", &n);
    for (int i = n; i>0; i--)
    {
        for(int j = 0 ; j<=n ; j++){
            if(j>=i) printf("*");
            else printf(" ");


        }
        printf("\n");
    
    }
    return 0;
}