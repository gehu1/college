#include <stdio.h>
#include <math.h>
float f(float x)
{
    return (x * x * x - x - 11);
}
float df(float x)
{
    return (3 * x * x - 1);
}
main()
{
    float x1, x2, x3, x4, x0, aerr, flag = 0;
    int i, maxitr;
    do
    {
        printf("\nEnter the values of x1 and x2");
        scanf("%f%f", &x1, &x2);
        if (f(x1) * f(x2) < 0)
        {
            printf("\nThe Root lies between %f and %f", x1, x2);
            flag = 0;
        }
        else
        {
            printf("\nWrong values of x1 and x2");
            flag = 1;
        }
    } while (flag == 1);
    if (f(x1) * f(x2) < 0)
    {
        if (fabs(f(x1)) < fabs(f(x2)))
            x0 = x1;
        else
            x0 = x2;
    }
    printf("\nEnter the no of iterations and tolerance limit:");
    scanf("%d%f", &maxitr, &aerr);
    x4 = x0;
    for (i = 1; i <= maxitr; i++)
    {
        x3 = x4 - (f(x4)) / df(x4);
        printf("\n%d iteration ,X3 = %f", i, x3);
        x4 = x3 - (f(x3)) / df(x3);
        if (fabs(x3 - x4) <= aerr)
        {
            printf("\nThe root is = %f\nNo. of iterations is =%d", x4, i + 1);
            return 0;
        }
    }
    return (0);
}