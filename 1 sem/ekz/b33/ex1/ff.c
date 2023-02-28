#include "ff.h"
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



void b33(int A[100][100], int N){
    printf("Min element area 2: ");
    int min = A[N/2][N/2];
    for (int col = N/2; col < N; col++)
        for (int row = N - 1 - col; row <= col; row++)
            if (A[row][col] < min)
                min = A[row][col];
    printf("%d", min);
}