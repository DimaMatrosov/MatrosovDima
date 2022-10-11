#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	int k, s, n, row, g, m;
	float array[100], array_max, sum; 
	srand(time(NULL));
	printf("Select the method of entering array elements(1-in manual, 2-using a random)\n");
	while (scanf_s("%d", &s) != 1 || s > 2 || s <= 0 || getchar() != '\n')
	{
		rewind(stdin);
		printf("Wrong input. Try again\n");
		printf("Choose again:");
	}
	printf("Input number of elements\n");
	while (scanf_s("%d", &n) != 1 || n > 100 || n <=0  || getchar() != '\n')
	{
		rewind(stdin);
		printf("Wrong input. Try again\n");
		printf("Input number:");
	}
	switch (s)
	{
	case 1:
	{
		printf("Input elemnts of array:\n");
		

		for (row = 0; row < n; row++)
		{
			while (scanf_s("%f", &array[row]) != 1 || getchar() != '\n')
			{
				rewind(stdin);
				printf("Wrong input. Try again\n");
				printf("Input element:");
			}	
		}
		break;
	}
	case 2:
	{
		for (row = 0; row < n; row++)
			array[row] = rand() - rand() % rand() * (double)rand() / rand();//rand()*200 -100
		break;
	}
	}
	printf("surse array\n");
	for (row = 0; row < n; row++)
		printf("%.1f\t", array[row]);
	printf("\n");
	printf("Input k - remoavel procedure\n");
	while (scanf_s("%d", &k)!= 1|| k > 100 || k <= 0 || getchar() != '\n')
	{
		rewind(stdin);
		printf("Wrong input. Try again\n");
		printf("Input k:");
	}
	printf("resulting array\n");
	m = 0;
	int  static_n = n;

	for (row = 0; row < static_n; row++)
	{
		if (!((row + 1) % k))
		{
			for (int j = row - m; j < n; j++)
			{
				array[j] = array[j + 1];
			}
			m++;
		n--;
		}
	}
    for (row = 0; row < n; row++) 
	{
		printf("%.1f\t", array[row]);
	}
	return 0;
}
