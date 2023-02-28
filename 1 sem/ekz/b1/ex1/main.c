#include <stdio.h>
#include <stdlib.h>
int main()
{
    int* array;
    int length = 0;
    printf("length: ");
    scanf_s("%d", &length);
    array = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        printf("[%d] element is: ", i + 1);
        scanf_s("%d", &array[i]);
    }
    for (int i = 0; i < length; i++) {
        printf("%d  ", array[i]);
    }

    for (int i = 0; i < length; i++) {
        if (array[i] % 2 == 0)
        {
            for (int k = i; k < length; k++)
            {
                array[k] = array[k + 1];
            }
            i--;
            length--;
            array = (int*)realloc(array, length * sizeof(int));
        }
    }
    printf("\n");
    for (int i = 0; i < length; i++) {
        printf("%d  ", array[i]);
    }
    return 0;
}