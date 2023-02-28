#include "ff.h"
int str_len(const char *str)
{
    int len = 0;
    while (*(str + len) != '\0')
        len++;
    return len;
}
void insert_sort(str *arr, int len) {
    for (int i = 1; i < len; i++) {
        str key = arr[i];
        int j;
        for (j = i - 1; j > 0 && arr[j].len < key.len; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}
void print_str(int argc, str *list)
{
    printf("Strings from args and their length:\n");
    for (int i = 1; i < argc; i++)
    {
        printf("%s %d\n", list[i].string, list[i].len);
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
int max_word_len(const char *str, int len)
{
    int max = 0;
    int word_len = 0;
    for (int i = 0; i <= len; i++)
    {
        word_len++;
        if (str[i] == ' ' || str[i] == '\0')
        {
            if (word_len > max)
                max = word_len;
            word_len = 0;
        }
    }
    return max - 1;
}
