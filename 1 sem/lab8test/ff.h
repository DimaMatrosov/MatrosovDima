#include <stdlib.h>
#include <stdio.h>
struct str
{
    int len;
    char *string;
    int max_len;
};
int str_len(char *str);
void insert_sort(struct str *arr, int len);
void print_str(int argc, struct str *list);
void argc_text(int argc);
int max_word_len(const char *str, int len);