#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	int k, s, n, row;
	int array_1[30], array_2[30], array_3[30];
	srand(time(NULL));

	printf("Select the method of entering array elements(1-in manual, 2-using a random)\n");
	while (scanf_s("%d", &s) != 1 || s > 2 || s <= 0 || getchar() != '\n')
	{
		rewind(stdin);
		printf("Wrong input\n");
		printf("Choose again:");
	}

	switch (s)
	{
	case 1:
	{
		printf("Input first 30 numbers:\n");
		for (row = 0; row < 30; row++)
		{
			while (scanf_s("%d", &array_1[row]) != 1 || array_1[row] < 0 || array_1[row] > 10 || getchar() != '\n')
			{
				rewind(stdin);
				printf("Wrong input. \n");
				printf("Input again:");
			}
		}
		printf("Input second 30 numbers:\n");
		for (row = 0; row < 30; row++)
		{
			while (scanf_s("%d", &array_2[row]) != 1 || array_2[row] < 0 || array_2[row] > 10 || getchar() != '\n')
			{
				rewind(stdin);
				printf("Wrong input. \n");
				printf("Input again:");
			}
		}
		break;
	}
	case 2:
	{
		for (row = 0; row < 30; row++)
			array_1[row] = rand() % 10;
		for (row = 0; row < 30; row++)
			array_2[row] = rand() % 10;
		break;
	}
	}

	printf("firsr number\n");
	for (row = 0; row < 30; row++)
		printf("%d", array_1[row]);
	printf("\n");

	printf("second number\n");
	for (row = 0; row < 30; row++)
		printf("%d", array_2[row]);
	printf("\n");

		if (array_1[0] > array_2[0])
		{
			for (row = 29; row >= 0; row--)
			{
				if (array_1[row] >= array_2[row])
				{
					 array_3[row] = array_1[row] - array_2[row];
				}
				else
				{
					array_3[row] = array_1[row] + 10 - array_2[row];
					array_1[row - 1] = array_1[row - 1] - 1;
				}
			}
			printf("resulting \n");
			for (row = 0; row < 30; row++)
				printf("%d", array_3[row]);
		}
		else
		{
			for (row = 29; row >= 1; row--)
			{
				if (array_2[row] >= array_1[row])
				{
					array_3[row]  = array_2[row] - array_1[row];
				}
				else
				{
					array_3[row] = array_2[row] + 10 - array_1[row];
					array_2[row - 1] = array_2[row - 1] - 1;
				}
			}
			array_3[0] = array_2[0] - array_1[0];
			printf("resulting: \n");
			printf("-");
			for (row = 0; row < 30; row++)
				printf("%d", array_3[row]);
		}
		return 0;
}
