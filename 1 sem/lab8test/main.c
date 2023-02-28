#include "ff.h"
int main(int argc, char *argv[])
{
    argc_text(argc);
    struct str *list = calloc(argc - 1, sizeof(struct str));
    for (int i = 1; i < argc; i++)
    {
        list[i].len = str_len(argv[i]);
        list[i].string = calloc(list[i].len, sizeof(char));
        list[i].string = argv[i];
        list[i].max_len = max_word_len(argv[i], list[i].len);
    }
    print_str(argc, list);
    insert_sort(list, argc);
    print_str(argc, list);
    free(list);
    free(argv);
    return 0;
}