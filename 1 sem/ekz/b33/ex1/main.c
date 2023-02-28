#include "ff.h"
int main()
{
    int k, N, row, col, A[100][100];
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

    b33(A, N);// ответ на билет

    return 0;
}
