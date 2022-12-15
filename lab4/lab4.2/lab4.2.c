#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void printMatrix(int R, int C, float A[100][100]);
int main()
{
	int k, C, R, row, col, B[100];
	float A[100][100];
	srand(time(NULL));
	printf("Select the method of entering array elements(1-in manual, 2-using a random)\n");
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
				while (scanf_s("%f", &A[row][col]) != 1 || getchar() != '\n')
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
			for (col = 0; col < C; col++)
				A[row][col] = rand() % 150-50;
		break;
	}
	}
	printf("matrix:\n");
	printMatrix(R, C, A);
	
	printf("negative line numbers:\n(if 0 then are no negative elements)\n");
	for (row = 0; row < R; row++)
	{
		int s = 0;
		for (col = 0; col < C; col++)
		{
			if (A[row][col] < 0)
				s++;
		}
		if (s == 0)
			B[row] = 0; 
		else
			B[row] = row + 1;
	}

	for (row = 0; row < R; row++)
	printf("%d\t", B[row]);

	for (int q = 0; q <= row; q++)
	{
		if (B[q]!=0)
		{	for (row = 0; row < R; row++)
			
				A[row][q] = A[row][q] / 2;
		}
	}
	printf("\n");
	printf("Modified matrix:\n");
	printMatrix(R, C, A);

	return 0;
}
void printMatrix(int R, int C, float A[100][100])
{
	for (int row = 0; row < R; row++)
	{
		for (int col = 0; col < C; col++)
			printf("%.1f\t", A[row][col]);
		printf("\n");
	}
}
