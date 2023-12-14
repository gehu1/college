#include <stdio.h>
#include <conio.h>
float f(float x)
{
    return (1 / (1 + x * x));
}
main()
{
    int i, n;
    float a[10], h, ll, ul, s1, s2 = 0, y;
    printf("\nEnter the no. of observations less than 10..");
    scanf("%d", &n);
    printf("\nEnter the upper and lower limit..");
    scanf("%f%f", &ul, &ll);
    h = (ul - ll) / n;
    for (i = 0; i <= n; i++)
    {
        a[i] = f(ll);
        ll += h;
    }
    printf("\nObservations are...\n");
    printf(" X =");
    for (i = 0; i <= n; i++)
        printf(" %d ", i);
    printf("\n Y =");
    for (i = 0; i <= n; i++)
        printf(" %.4f", a[i]);
    s1 = a[0] + a[n];
    for (i = 1; i < n; i++)
        s2 = s2 + a[i];
    s2 = s2 * 2;
    y = h * (s1 + s2) / 2;
    printf("\n\nIntegrated value is..%.4f", y);
    return (0);
}