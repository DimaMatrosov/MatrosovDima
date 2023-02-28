#include <stdio.h>
#include <stdlib.h>
void mergeSort(int *array, int left, int right);

int main() {
    int *A, n;
    A = (int*)malloc(n * sizeof(int));
    printf("input num of elem\n");
    scanf("%d", &n);
    for (int row = 0; row < n; row++)
        A[row] = rand()%20-10;
    for (int row = 0; row < n; row++)
        printf("%d\t",A[row]);
printf("\n");
    mergeSort(A,0, n-1);

    for (int row = 0; row < n; row++)
        printf("%d\t",A[row]);
    return 0;
}
void mergeSort(int *array, int left, int right)
{
    int center = (left + right) / 2;
    if (left == right)
        return;
    mergeSort(array, left, center);
    mergeSort(array, center + 1, right);
    int i = left, j = center + 1, k = 0;
    int* b = (int*)malloc((right - left + 1) * sizeof(int));
    while (i <= center && j <= right)
    {
        if (array[j] < array[i]){
            b[k++] = array[j++];
        }
        else{
            b[k++] = array[i++];
        }
    }
    for (; i <= center; i++, k++)
        b[k] = array[i];
    for (; j <= right; j++, k++)
        b[k] = array[j];
    for (i = left, k = 0; i <= right; i++, k++)
        array[i] = b[k];
}