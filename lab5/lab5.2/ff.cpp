#include "Header.h"
void choose_type_input(int* p)
{
    srand(time(NULL));
    printf("Select method of input elements(1-in manual, 2-using a random)\n");
    while (scanf_s("%d", p) != 1 || getchar() != '\n' || *p > 2 || *p <= 0)
    {
        rewind(stdin);
        printf("Wrong input. Choose again:");
    }
}

void print_array(int n, int** A)
{
    printf("Matrix:\n");
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; *(*(A + row) + col) != -1; col++)
            printf("%d\t ", *(*(A + row) + col));
        printf("-1\n");
    }
}

void print_new(int row, int col, int **A)
{

    printf("%d\t ", *(*(A + row) + col));
}
void number(int* k)
{
    while (scanf_s("%d", k) != 1 || *k <= 0 || *k > 100 || getchar() != '\n')
    {
        printf("Wrong input. Try again: \n");
        rewind(stdin);
    }
}

int last(int** A, int row)
{
    for (int col = 0;; col++)
        if (*(*(A + row) + col) == -1)
            return col + 1;
}

void deleting(int n, int k, int** A)
{
    printf("New matrix:\n");
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < last(A, row); col++)
        {
            if (col< k)
            {
                overexposure(row, k, A);
                print_new(row,col,A);
            }
        }
        printf("\n");
    }
}

int** operation(int n, int p)
{
    int m;
    int**A;
        A = (int**)malloc(n * sizeof(int*));
        for (int row = 0; row < n; row++) {
            printf("Input the number of elements in %d row  ", row + 1);
            number(&m);
            *(A + row) = (int *) malloc(m * sizeof(int));
            printf("Input elemnts in row(-1 will be added automatically)\n");
            input(p, m, row, A);
            *(*(A + row) + m - 1) = -1;
        }
        return A;
}

void input(int p, int m,int row, int **A)
{
    if (p == 1)
    {
        for (int col = 0; col < m - 1; col++)
        {
            while (scanf_s("%d", *(A + row) + col) != 1 || *(*(A + row) + col) == -1 || getchar() != '\n')
            {
                printf("Wrong! Try again: \n");
                rewind(stdin);
            }
        }
    }
    else
    {
        for (int col = 0; col < m - 1; col++)
            *(*(A + row) + col) = 1 + rand() % 100;
    }
}

void overexposure(int row, int k, int** A)
{
    *(A + row) = (int*)realloc(*(A + row), k * sizeof(int));
}

