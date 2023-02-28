#include <stdlib.h>
#include <stdio.h>
typedef struct
{
    int len;
    char *string;
} str;
int str_len(const char *str);
void insert_sort(str *arr, int len);
void print_str(int argc, str *list);
void argc_text(int argc);