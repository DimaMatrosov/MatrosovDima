#include <stdio.h>
#include <stdlib.h>
void sort(int *A, int n);
// Отсортировать четные по значению элементы массива, не меняя расположения остальных.
int main() {
    int *A, n;

    printf("Input number of elements\n");
    while(scanf_s("%d", &n) != 1 || n <= 0 || n > 1000 || getchar() != '\n')
    {
        printf("Wrong input. Try again: \n");
        rewind(stdin);
    }
    A = (int*)malloc(n * sizeof(int));
    printf("Input elemnts of array:\n");
    for (int i = 0; i < n; i++)
        while (scanf_s("%d", &A[i] ) != 1 || getchar() != '\n')
        {
            printf("Wrong input. Try again: ");
            rewind(stdin);
        }
    sort(A, n);


    printf("Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", *(A + i));
    return 0;
}
void sort(int *A, int n){
    for(int i = 0; i < n - 1; i++)
    {
        int i1 = i;
        for(int j = i + 1; j < n; j++)
            if(*(A + i)%2 ==0 && *(A+j)%2 == 0 && *(A+i1) > *(A + j))
                i1=j;
        int m = *(A + i);
        *(A+i) = *(A + i1);
        *(A + i1) = m;
    }
}

