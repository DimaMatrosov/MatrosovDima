#include"hed.h"
void choose_type_input(int* p)
{
    printf("Select the method of entering array elements(1-in manual, 2-using a random)\n");
    while (scanf_s("%d", p) != 1 || getchar() != '\n' || *p > 2 || *p <= 0)
    {
        rewind(stdin);
        printf("Wrong input. Choose again:");
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
void scan_array_rand(int n, int m, int** A)
{
    srand(time(NULL));
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
            A[row][col] = rand()% 20 - 10;
    }
}
void print_array(int n, int m, int** A)
{
    printf("Matrix:\n");
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
            printf("%5d ", *(*(A + row) + col));
        printf("\n");
    }
}
void memory( int n, int m, int*** A)
{
    *A = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        *(*A + i) = (int*)malloc((m+1) * sizeof(int));
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

 void sum(int n, int m, int** A)
    {
    for (int i = 0; i < n; i++)
            {
                int s = 0;
                for (int j = 0 ; j < m; j++)
                    if (j % 2 == 1) {
                        s += *(*(A + i) + j);
                    }
                *(*(A + i) + m) = s;
                printf("sum%d:%d\n", i+1, *(*(A + i) + m));
            }
    }

void sort(int n,int m, int** A)
{
    int flg;
    for (int gap = n / 2; gap > 0; gap /= 2)
        do{
            flg = 0;
            for (int i = 0, j = gap; j < n; i++, j++){
                if (*(*(A + i) + m) < *(*(A + j) + m)){
                    for (int col = 0; col <= m; col++){
                        int q = *(*(A + j) + col);
                        *(*(A + j) + col) = *(*(A + i) +col);
                        *(*(A + i) + col) = q;
                    }flg = 1;
                }
            }
        }while (flg);
}
