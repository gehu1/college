#include <stdio.h>
#include <conio.h>
main()
{
    float a[10][11], t;
    int i, j, n, k;
    printf("\nEnter the no. of unknowns..");
    scanf("%d", &n);
    printf("\nEnter the values..\n");
    for (i = 0; i < n; i++)
        for (j = 0; j <= n; j++)
            scanf("%f", &a[i][j]);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (j != i)
            {
                t = a[j][i] / a[i][i];
                for (k = 0; k <= n; k++)
                    a[j][k] = a[j][k] - a[i][k] * t;
            }
    printf("\nThe diagonal matrix is..\n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j <= n; j++)
            printf(" %.4f ", a[i][j]);
    }
    printf("\n\n\tThe solution is...\n");
    for (i = 0; i < n; i++)
        printf("\tX[%d]:-> %.4f\n", i + 1, a[i][n] / a[i][i]);
    return 0;
}