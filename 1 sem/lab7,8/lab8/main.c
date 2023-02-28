#include "ff.h"
int main(int argc, char *argv[])
{
    argc_text(argc);
    str *list = calloc(argc - 1 , sizeof(str));
    for (int i = 0;  i < argc-1; i++)
    {
        list[i].len = str_len(argv[i+1]);
        list[i].string = calloc(list[i].len, sizeof(char));
        list[i].string = argv[i+1];
        list[i].max_len = max_word_len(argv[i+1], list[i].len);
    }
    print_str(argc, list);
    insert_sort(list, argc);
    print_str(argc, list);
    free(list);
    return 0;
}