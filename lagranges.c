#include <stdio.h>
#include <conio.h>
main()
{
    float x[6], y[6], x0, q = 1, sum = 0;
    int i, j, n;
    printf("\nEnter the no. of observations");
    scanf("%d", &n);
    printf("\nenter the values of X");
    for (i = 0; i < n; i++)
        scanf("%f", &x[i]);
    printf("\nEnter the values of y");
    for (i = 0; i < n; i++)
        scanf("%f", &y[i]);
    printf("\nEnter the corresponding value of X");
    scanf("%f", &x0);
    for (i = 0; i < n; i++)
    {
        q = 1;
        for (j = 0; j < n; j++)
            if (i != j)
                q = (q * (x0 - x[j])) / (x[i] - x[j]);
        sum += q * y[i];
    }
    printf("\nThe value of Y for f(%.3f) = %.3f", x0, sum);
    return (0);
}