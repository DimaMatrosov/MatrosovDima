#include<stdio.h>
int main()
{
	int x = 1;
	double ctgX = 0, X;
	int n;
	printf("Input x\n");
	while (scanf_s("%d", &x) != 1 || x%360 == 0)
	{
		rewind(stdin);
		printf("Wrong input. Try again\n");
		printf("Input x\n");
	}
	printf("Input precision\n");
	while (scanf_s("%d", &n) !=1)
	{
		rewind(stdin);
		printf("Wrong input. Try again\n");
		printf("Input precision\n");
	}
	X = (x * 3.14159265) / 180;
	double a1 = 1, b1 = 1, power1 = X * X, cosX = 1;
	for (int i = 2; i < n; i++)
	{
		a1 *= (-1) * power1;
		b1 *= (i - 1) * i;
		cosX += a1 / b1;
	}
	double a2 = X, b2 = 1, power2 = X * X, sinX = a2 / b2;
	for (int i = 2; i < n; i++)
	{
		a2 *= (-1) * power2;
		b2 *= (i + 1) * i;
		sinX += a2 / b2;
	}
	ctgX = cosX / sinX;
	printf("ctg= %lf\n", ctgX);
	scanf_s;
	return 0;
}
