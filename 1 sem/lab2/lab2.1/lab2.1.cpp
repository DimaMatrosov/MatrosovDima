

#include<stdio.h>
int main()
{
	int k1, k3, k5, m, n;
	printf("m:");
	while (scanf_s("%d", &m) !=1)
	{
		rewind(stdin);
		printf("Wrong input. Try again\n");
		printf("Input m:");
	}
	k1 = 0;
	n = 0;
	for (k5 = 0; k5 <= m/5; k5++)
		for (k3 = 0; k3 <= 10 - k5; k3++)
		{
			k1 = 10 - k5 - k3;
			if (k1 != 0 && k5 * 5 + k3 * 3 + k1 == m)
			{
				printf("%d*5+%d*3+%d*1=%d\n", k5, k3, k1, m);
				n++;
			}
		}
	if (n==0) 
	{
		printf("imposible to decpmpose");
	}
	return 0;
}