#include "ff.h"
int str_len(char *str)
{
    int len = 0;
    while (*(str + len) != '\0')
        len++;
    return len;
}
void insert_sort(struct str *list, int len)
{
    printf("\n After sorting. ");
    for (int i = 1; i < len; i++)
    {
        struct str key = list[i];
        int j;
        for  (j = i - 1; j > 0 && list[j].max_len < key.max_len; j--)
        {
            list[j + 1] = list[j];
        }
        list[j + 1] = key;
    }
}
void print_str(int argc, struct str *list)
{
    printf("Strings from args and their length:\n");
    for (int i = 1; i < argc; i++)
    {
        printf("%s  %d\n", list[i].string, list[i].max_len);
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
