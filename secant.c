#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float x)
{
    return (x * x * x - x * x - 11);
}
main()
{
    int maxitr, i,itr;
    float x1, x2, x3, temp, aerr;
    char ch;
    printf("\nEnter the suitable values of x1 & x2:");
    scanf("%f%f", &x1, &x2);
    printf("\n\nEnter the no of iteration steps");
    scanf("%d", &itr);
    printf("\n\nEnter the error");
    scanf("%f", &aerr);
    x3 = (x1 + f(x2) -
          x2 * f(x1)) /
         (f(x2) - f(x1));
    for (i = 1; i <= itr; i++)
    {
        x1 = x2;
        x2 = x3;
        x3 = (x1 + f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
        printf("\n\n%d iteration,X3 = %f", i, x3);
        if (fabs(x3 - x2) <= aerr)
        {
            printf("\n\nThe root is =%f\nNo. of iterations is=%d", x3, i);
        }
    }
}