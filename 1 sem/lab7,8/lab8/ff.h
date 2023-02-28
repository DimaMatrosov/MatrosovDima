#include <stdlib.h>
#include <stdio.h>
typedef struct
{
    int len;
    char *string;
    int max_len;
} str;
int str_len(char *str);
void insert_sort(str *arr, int len);
void print_str(int argc, str *list);
void argc_text(int argc);
int max_word_len(const char *str, int len);