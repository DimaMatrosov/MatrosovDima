#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	int k, C, R, row, sum, col, A[100][100], c;
	srand(time(NULL));
	printf("Select the method 777777777 of entering array elements(1-in manual, 2-using a random)\n");
	while (scanf_s("%d", &k) != 1 || getchar() != '\n' || k > 2 || k <= 0)
	{
		rewind(stdin);
		printf("Wrong input. Choose again:");
	}

	printf("Input number of columns\n");
	while (scanf_s("%d", &C) != 1 || C > 100 || C <= 0 || getchar() != '\n')
	{
		rewind(stdin);
		printf("Wrong input. Try again\n");
		printf("Input number:");
	}
	
	printf("Input number of rows\n");
	while (scanf_s("%d", &R) != 1 || R > 100 || R <= 0 || getchar() != '\n')
	{
		rewind(stdin);
		printf("Wrong input. Try again\n");
		printf("Input number:");
	}

	switch (k)
	{
	case 1:
	{
		printf("Input elemnts of matrix:\n");
		for (row = 0; row < R; row++)
		{
			for (col = 0; col < C; col++)
				while (scanf_s("%d", &A[row][col]) != 1 || getchar() != '\n')
				{
					rewind(stdin);
					printf("Wrong input. Try again:");
				}
		}
		break;
	}

	case 2:
	{
		for (row = 0; row < R; row++)
		{
			for (col = 0; col < C; col++)
			A[row][col] = rand() % 20 - 10;
		}
		break;
	}
	}
	printf("matrix:\n");
	printMatrix(R, C, A);

	printf("characterictics:\n");
	for (row = 0; row < R; row++)
	{
		A[row][C] = 0;
		for (col = 0; col < C; col++)
		{
			if ((A[row][col] > 0) && (A[row][col] % 2 == 0))
				A[row][C] += A[row][col];
		}
		printf("%d\t", A[row][C]);
	}
	printf("\n");
	
	int min, min_row, B[100];
	for (int q = 0; q < R; q++)
	{
		min = A[q][C];
		min_row = q;
		for (row = q; row < R; row++)
		{
			if (A[row][C] < min)
			{
				min = A[row][C];
				min_row = row;
			}
		}
		for (col = 0; col <= C; col++)
		{
			B[col] = A[min_row][col];
		}
		for (row = min_row; row >= q; row--) 
		{
			for (col = 0; col <= C; col++) 
			{
				A[row][col] = A[row - 1][col];
			}
		}
		for (col = 0; col <= C; col++)
		{
			A[q][col] = B[col];
		}
	}
	printf("Modified matrix:\n");
	printMatrix(R, C, A);
		return 0;
}
