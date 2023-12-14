#include <stdio.h>
#include <math.h>
float f(float x) {
    return (x * x * x * x - x - 10);
}
void bisect(float *x, float x1, float x2, int *itr) {
    *x = (x1 + x2) / 2;
    ++(*itr);
    printf("\n%d iteration, The value of x is %f", *itr, *x);
}
int main() {
    int itr = 0, maxitr, flag = 0;
    float aerr, x, x1, x2, x3;
    printf("Enter the values of x1 and x2: ");
    scanf("%f%f", &x1, &x2);
    do {
        if (f(x1) * f(x2) < 0) {
            printf("\nThe Root lies between %f and %f", x1, x2);
            flag = 0;
        } else {
            printf("\nWrong values of x1 and x2");
            printf("\nEnter the values of x1 and x2: ");
            scanf("%f%f", &x1, &x2);
            flag = 1;
        }
    } while (flag == 1);
    printf("\nEnter the number of iterations and allowed error: ");
    scanf("%d%f", &maxitr, &aerr);
    bisect(&x, x1, x2, &itr);
    do {
        if (f(x1) * f(x) < 0)
            x2 = x;
        else
            x1 = x;
        bisect(&x3, x1, x2, &itr);
        if (fabs(x3 - x) < aerr) {
            printf("\nThe root of the equation is %f after %d iteration", x1, itr);
            return 0;
        }
        x = x3;
    } while (itr < maxitr);
    printf("\nSolution does not converge, fewer iterations");
    return 0;
}