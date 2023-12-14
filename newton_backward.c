#include <stdio.h>
#include <conio.h>
main()
{
    int i, j, n;
    float a[10][10], y, x, u1, u, k = 1;
    printf("\nEnter the no. of observations");
    scanf("%d", &n);
    printf("\nEnter the values :");
    for (j = 0; j < n; j++)
        for (i = 0; i < 2; i++)
            scanf("%f", &a[j][i]);
    for (j = 2; j < n + 1; j++)
        for (i = j - 1; i < n; i++)
            a[i][j] = a[i][j - 1] - a[i - 1][j - 1];
    printf("\nDifference table is as..");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < 2 + i; j++)
            printf("\t%.3f", a[i][j]);
    }
    printf("\nEnter the value of X");
    scanf("%f", &x);
    u = (x - a[n - 1][0]) / (a[1][0] - a[0][0]);
    u1 = u;
    y = a[n - 1][1];
    for (j = 2; j < n + 1; j++)
    {
        y = y + (u1 * (a[n - 1][j] / k));
        u1 = u1 * (u + (j - 1));
        k *= j;
    }
    printf("\nValue of Y%.3f", y);
    return (0);
}