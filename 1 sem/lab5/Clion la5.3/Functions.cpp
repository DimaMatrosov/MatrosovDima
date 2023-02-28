#include "Functions.h"
void choose_type_input(int* p)
{
    printf("Select the method of entering array elements(1-in manual, 2-using a random)\n");
    while (scanf_s("%d", p) != 1 || getchar() != '\n' || *p > 2 || *p <= 0)
    {
        rewind(stdin);
        printf("Wrong input. Choose again:");
    }
}

void print_array(int n, int m, int** A)
{
    printf("Matrix:\n");
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
            printf("%5d ", *(*A + row * m + col));
        printf("\n");
    }
}

void scan_array_rand(int n, int m, int** A)
{
     srand(time(NULL));
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
            *(*A + row * m + col) = rand()% 20 - 10;
    }
}

void scan_array(int n, int m, int** A)
{
    printf("Input elemnts of matrix:\n");
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
            while (scanf_s("%d", &*(*A+row*m+col)) != 1 || getchar() != '\n')
            {
                printf("Wrong input. Try again: ");
                rewind(stdin);
            }
    }
}

 void number(int* k)
{
    while (scanf_s("%d", k) != 1 || *k <= 0 || *k > 100 || getchar() != '\n')
    {
        printf("Wrong input. Try again: \n");
        rewind(stdin);
    }
}

void type_input(int p, int n, int m, int** A)
{
    switch (p)
    {
        case 1:
        {
            scan_array(n, m, A);
            break;
        }
        case 2:
        {
            scan_array_rand(n, m, A);
            break;
        }
    }
}

void neg_col(int m, int n, int** A)
{
    int s = 0, b = m;
    for (int col = 0; col < m; col++){
        int k = 0;
        for (int row = 0; row < n; row++){
            if (*(*A + row * m + col) < 0)
                k++;
        }
        if (k == n){
            for (int row = 0; row < n; row++)
                *(*A + row * m + col) = *(*A + row * m + (col + 1));
            s++;
            b--;
        }
    }
    if(s == 0)
        printf("no negative columns\n");
    else{
        if(b==0){
            printf("All col are negative");
        }
        else {
            overexposure(A, n, b);
            printf("New ");
            print_array(n, b, A);
        }
    }
}

int** memory( int n, int m)
{
    int** A;
    A = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        *(A + i) = (int*)malloc(m * sizeof(int));
    }
    return A;
}

void overexposure(int **A,int n, int b)
{
    for (int row = 0; row < n; row++)
        *A = (int*)realloc(*A, b * sizeof(int));
}


