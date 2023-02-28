#include "hed.h"
void print_array(int n, int* A)
{
    printf("Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", *(A + i));
    printf("\n");
}
void scan_array(int n, int* A)
{
    printf("Input elemnts of array:\n");
    for (int i = 0; i < n; i++)
        while (scanf_s("%d", (A + i)) != 1 || getchar() != '\n')
        {
            printf("Wrong input. Try again: ");
            rewind(stdin);
        }
}
void num_element(int* k)
{
    while(scanf_s("%d", k) != 1 || *k <= 0 || *k > 100 || getchar() != '\n')
    {
        printf("Wrong input. Try again: \n");
        rewind(stdin);
    }
}
void count(int *A, int n)
{
    int i = n - 1;
    for (int q = 2 * n -1; q > 0; q--)
    {
        *(A+q) = *(A+i) * *(A+i);
        q--;
        *(A+q) = *(A+i);
        i--;
    }
}
void memory(int **A, int n)
{
    *A = (int*)malloc(n * sizeof(int));
}
void overexposure(int** A, int n)
{
    *A = (int*)realloc(*A, 2*n * sizeof(int));
}