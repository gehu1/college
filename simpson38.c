#include <stdio.h>
#include <conio.h>
float f(float x)
{
    return (1 / (1 + x * x));
}
int main()
{
    int i, n;
    float a[10], h, ll, ul, s1, s2 = 0, s3 = 0, y;
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
    printf(" X :->");
    for (i = 0; i <= n; i++)
        printf(" %d ", i);
    printf("\n Y :->");
    for (i = 0; i <= n; i++)
        printf(" %.4f", a[i]);
    s1 = a[0] + a[n];
    for (i = 1; i < n; i++)
    {
        if (i % 3 != 0)
            s2 = s2 + a[i];
        else
            s3 = s3 + a[i];
    }
    s2 = s2 * 3;
    s3 = s3 * 2;
    y = 3 * h * (s1 + s2 + s3) / 8;
    printf("\n\nIntegrated value is..%.4f", y);
    getch();
    return (0);
}