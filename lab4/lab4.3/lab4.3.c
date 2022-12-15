#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void printMatrix(int N, int A[100][100]);
int main()
{
	int k, N, row, col, A[100][100], min;
	srand(time(NULL));
	printf("Select the method of entering array elements(1-in manual, 2-using a random)\n");
	while (scanf_s("%d", &k) != 1 || getchar() != '\n' || k > 2 || k <= 0)
	{
		rewind(stdin);
		printf("Wrong input. Choose again:");
	}

	printf("Input number of columns and rows\n");
	while (scanf_s("%d", &N) != 1 || N > 100 || N <= 0 || getchar() != '\n')
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
		for (row = 0; row < N; row++)
		{
			for (col = 0; col < N; col++)
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
		for (row = 0; row < N; row++)
			for (col = 0; col < N; col++)
				A[row][col] = rand() % 20 - 10;
		break;
	}
	}

	printMatrix(N, A);

	printf("Min element area 2: ");
	min = A[N/2][N/2];
	for (col = N/2; col < N; col++)
		for ( row = N - 1 - col; row <= col; row++)
			if (A[row][col] < min)
			    min = A[row][col];
	printf("%d", min);
	return 0;
}
void printMatrix(int N, int A[100][100])
{
	printf("Matrix:\n");
	for (int row = 0; row < N; row++)
		for (int col = 0; col < N; col++)
		{
			printf("%d\t", A[row][col]);
			if (col == N - 1)
				printf("\n\n");
		}
}