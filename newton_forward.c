#include <stdio.h>
int main()
{
	int i, j, n;
	float a[10][10], y, x, u1, u, k = 1;
	printf("\nEnter the no. of observations");
	scanf("%d", &n);
	printf("\nEnter the values X and Y:");
	for (j = 0; j < n; j++)
		for (i = 0; i < 2; i++)
			scanf("%f", &a[j][i]);
	for (j = 2; j < n + 1; j++)
		for (i = 0; i < n + 1 - j; i++)
			a[i][j] = a[i + 1][j - 1] - a[i][j - 1];
	printf("\nDifference table is as..");
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < n + 1 - i; j++)
			printf("\t%.3f", a[i][j]);
	}
	printf("\nEnter the value of X");
	scanf("%f", &x);
	u = (x - a[0][0]) / (a[1][0] - a[0][0]);
	u1 = u;
	y = a[0][1];
	for (i = 2; i < n + 1; i++)
	{
		y = y + (u1 * (a[0][i] / k));
		u1 = u1 * (u - (i - 1));
		k *= i;
	}
	printf("\nValue of Y is %.3f", y);
	return 0;
}