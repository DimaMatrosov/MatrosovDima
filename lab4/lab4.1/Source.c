void printMatrix(int R, int C, int A[100][100])
{
	for (int row = 0; row < R; row++)
	{
		for (int col = 0; col < C; col++)
		{
			printf("%d\t", A[row][col]);
		}
		printf("\n");
	}
}