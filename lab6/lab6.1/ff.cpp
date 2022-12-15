#include "hed.h"
void print_array(int n, int p, int* A)
{
    switch (p)
    {
        case 1:
        {
            printf("Array:\n");
            for (int i = 0; i < n; i++)
                printf("%d\t", *(A + i));
            printf("\n");
            break;
        }
        case 2:
        {
            break ;
        }
    }

}
void choose_type_input(int* p)
{
    printf("Select the method of entering array elements(1-in manual, 2-using a random)\n");
    while (scanf_s("%d", p) != 1 || getchar() != '\n' || *p > 2 || *p <= 0)
    {
        rewind(stdin);
        printf("Wrong input. Choose again:");
    }
}
void scan_array(int n, int p, int* A)
{
    switch (p)
    {
        case 1:
        {
            printf("Input elemnts of array:\n");
            for (int i = 0; i < n; i++)
                while (scanf_s("%d", (A + i)) != 1 || getchar() != '\n')
                {
                    printf("Wrong input. Try again: ");
                    rewind(stdin);
                }
            break;
        }
        case 2:
        {
            for (int i = 0; i < n; i++)
                *(A + i) = rand() % 20 - 10;
            break;
        }
    }


}
void num_element(int* k)
{
    while(scanf_s("%d", k) != 1 || *k <= 0 || *k > 100000 || getchar() != '\n')
    {
        printf("Wrong input. Try again: \n");
        rewind(stdin);
    }
}
void sort1(int *A, int n)
{
    clock_t start = clock();
    for(int i = 0; i < n - 1; i++)
    {
        int i1 = i;
        for(int j = i + 1; j < n; j++)
            if(*(A + i) < 0 && *(A+i1) > *(A + j))
                i1=j;
        int m = *(A + i);
        *(A+i) = *(A + i1);
        *(A + i1) = m;
    }
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    printf("Time 1: %.2f msec.\n", 1000*elapsed);

}
void sort2(int *A, int n)
{
    clock_t start = clock();
    for(int i = 0; i < n-1; i++)
    {
        int q = i;
        for(int j = n-1; j > i; j--)
            if(*(A + i) < 0 && *(A+(j-1)) > *(A + j))
                q = j;
        int m = *(A + i);
        *(A+i) = *(A + q);
        *(A + q) = m;
    }
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    printf("Time buble: %.2f msec.\n", 1000*elapsed);
}
void sort3(int *A, int n)
{
    clock_t start = clock();
    for(int i = n - 1; i >= 0; i--)
    {
        int i1 = i;
        for(int j = n; j >i +1; j--)
            if(*(A + i) < 0 && *(A+i1) > *(A + j))
                    i1=j;
        int m = *(A + i);
        *(A+i) = *(A + i1);
        *(A + i1) = m;
    }
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    printf("Time 2: %.2f msec.\n", 1000*elapsed);
}
void memory(int **A, int n)
{
    *A = (int*)malloc(n * sizeof(int));
}