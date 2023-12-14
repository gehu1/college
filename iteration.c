#include <stdio.h>
#include <math.h>
float f(float x)
{
    return (x * x * x - 4 * x - 9);
}
float q(float x)
{
    return (pow((4 * x + 9), (1.0 / 3.0)));
}
float qp(float x)
{
    return ((4.0 / 3.0) * (1 / (pow((4 * x + 9), (2.0 / 3.0)))));
}
main()
{
    float x1, x2, x3, x0, aerr;
    int i, itr;
    printf("\nEnter the roots");
    scanf("%f%f", &x1, &x2);
    if (qp(x1) < 1 && qp(x2) < 1)
        printf("\nFunction is correct");
    else
    {
        printf("\nCreate New function");
        return (0);
    }
    if (f(x1) * f(x2) < 0)
    {
        if (fabs(f(x1)) < fabs(f(x2)))
            x0 = x1;
        else x0 = x2;
    }
    printf("\nEnter the no of iterations and tolerance limit:");
    scanf("%d%f", &itr, &aerr);
    for (i = 1; i <= itr; i++)
    {
        x3 = q(x0);
        printf("\n%d iteration ,X3 = %f", i, x3);
        if (fabs(x3 - x0) < aerr)
        {
            printf("\nThe root is = %f\nNo. of iterations is = %d", x3, i);
            return (0);
        }
        x0 = x3;
    }
    return (0);
}