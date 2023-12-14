#include <stdio.h>
#include <conio.h>
main()
{
    float a[10][11], x[10], s, t;
    int i, j, n, k;
    printf("\nEnter the no. of unknowns..");
    scanf("%d", &n);
    printf("\nEnter the values..\n");
    for (i = 0; i < n; i++)
        for (j = 0; j <= n; j++)
            scanf("%f", &a[i][j]);
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
        {
            t = a[j][i] / a[i][i];
            for (k = 0; k <= n; k++)
                a[j][k] = a[j][k] - a[i][k] * t;
        }
    printf("\nThe upper triangular matrix is..\n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j <= n; j++)
            printf(" %.4f\t", a[i][j]);
    }
    for (i = n - 1; i >= 0; i--)
    {
        s = 0;
        for (j = i + 1; j < n; j++)
            s = s + a[i][j] * x[j];
        x[i] = (a[i][n] - s) / a[i][i];
    }
    printf("\n\n\tThe solution is...\n");
    for (i = 0; i < n; i++)
        printf("\tX[%d]:-> %.4f\n", i + 1, x[i]);
    return (0);
}