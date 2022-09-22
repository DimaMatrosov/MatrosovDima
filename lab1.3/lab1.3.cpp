#include<stdio.h>
int main()
{
	int a, b, c, N;
	printf("input a\n");
	scanf_s("%d", &a);
	printf("input b\n");
	scanf_s("%d", &b);
	printf("input c\n");
	scanf_s("%d", &c);
	printf("input N\n");
	scanf_s("%d", &N);
	printf("\n");
	if (a % N == 0)
	{
		printf("%d", N);
		printf(" dev %d\n", a);
	}
	if (b % N == 0)
	{
		printf("%d", N);
		printf(" dev %d\n", b);
	}
	if (c % N == 0)
	{
		printf("%d", N);
		printf(" dev %d\n", c);
	}
	return 0;
}