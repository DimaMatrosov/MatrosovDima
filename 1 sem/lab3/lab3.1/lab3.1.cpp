#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	int k, n, num_max, row;
	float array[100], array_max, sum, firstplus;
	srand(time(NULL));
	printf("Select the method of entering array 087687564elements(1-in manual, 2-using a random)\n");
		while (scanf_s("%d", &k) != 1 || getchar() != '\n'|| k > 2 || k <= 0 )
	{
			rewind(stdin);
			printf("Wrong input. Choose again:");
	}
	
	printf("Input number of elements\n");
	while (scanf_s("%d", &n) != 1 || n > 100 || n <= 0 || getchar() != '\n')
	{
		rewind(stdin);
		printf("Wrong input. Try again\n");
		printf("Input number:");
	}
	
	switch (k)
	{
	case 1:
	{
		printf("Input elemnts of array:\n");
		for (row = 0; row < n; row++)
		{
			while (scanf_s("%f", &array[row]) != 1 || getchar() != '\n')
			{
				rewind(stdin);
				printf("Wrong input. Choose again:");
			}
		}
		break;
	}
	
	case 2:
	{
		for (row = 0; row < n; row++)
			array[row] = rand()%200-100;
		break;
	}
	}
	
	printf("surse array\n");
	for (row = 0; row < n; row++)
		printf("%.2f\t", array[row]);
	printf("\n");
	
	array_max = 0;
	num_max = 0;
	sum = 0;
	for (row = 0; row < n; row++)
	{
		if (array[row] < 0)
			array[row] = -array[row];
		if (array_max < 0)
			array_max = -array_max;
	}
	for (row = 0; row < n; row++)
	{
		if (array[row] > array_max)
		{
			array_max = array[row];
			num_max = row;
		}
	}


	printf("%d -the nuber of the max modulo\n", num_max + 1);
	firstplus = 0;
	for (row = 0; row < n; row++)
	{
		if (firstplus)
		{
			sum += array[row];
		}
		if (array[row] > 0)
		{
			firstplus = 1;
		}
	}
	printf("%.2f - sum of elements after firstplus", sum);
	return 0;
}


