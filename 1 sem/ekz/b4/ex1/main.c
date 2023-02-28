#include <stdio.h>
#include <stdlib.h>
void reverse(int *A, int K)
{
    for (int i = 0, j = K - 1; i < j; ++i, --j)
    {
        int tmp = *(A+i);
        *(A+i) = *(A+j);
        *(A+j) = tmp;
    }
}
int main()
{
    int len, K;
    int *A;
    printf("input num of elem\n");
    scanf_s("%d", &len);
    A = (int*)malloc(len * sizeof(int));
    printf("input elem");
    for(int i = 0; i < len; i++)
        scanf_s("%d", &*(A +i));
    for(int i = 0; i < len; i++)
        printf("%d  ", *(A +i));
    printf("\ninput K\n");
    scanf_s("%d", &K);

    reverse(A, K);
    reverse(A+K, len - K);
    reverse(A, len);

    for(int i = 0; i < len; i++)
        printf("%d  ", *(A +i));
    return 0;
}//итак, нужно преобразовать массив ab в bа. Предположим, что у нас есть функция reverse,
 //переставляющая элементы некоторой части массива в противоположном порядке.
 // В исходном состоянии массив имеет вид ab. Вызвав эту функцию для первой части, получим а r b
 // (прим. редактора:а r — это модифицированная часть a, к которой применили фукнцию перестановки reverse).
 // Затем вызовем ее для второй части: получим а r b r . Затем вызовем функцию для всего массива,
 // что даст (а r b r ) r , а это в точности соответствует bа.





