#include "ff.h"
int str_len(const char *str)
{
    int len = 0;
    while (*(str + len) != '\0')
        len++;
    return len;
}
void insert_sort(char *arr, int **len) {
    for (int i = 1; i < len[i]; i++) {
        char key = arr[i];
        int j;
        for (j = i - 1; j > 0 && len[j] < len[i]; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}
void argc_text(int argc)
{
    if (!(argc - 1))
    {
        printf("No args!");
        exit(0);
    }
}

