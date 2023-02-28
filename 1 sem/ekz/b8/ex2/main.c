#include "ff.h"
int main(int argc, char *argv[]) {
    argc_text(argc);

    if (!(argc - 1)) {
        printf("Provide strings in args!");
        return 0;
    }

    str *list = calloc(argc - 1, sizeof(str));

    for (int i = 1; i < argc; i++) {
        list[i].len = str_len(argv[i]);
        list[i].string = calloc(list[i].len, sizeof(char));
        list[i].string = argv[i];

    }
    printf("Strings from args and their length:\n");
    for (int i = 1; i < argc; i++) {
        printf("%s %d\n", list[i].string, list[i].len);
    }
    printf("\nStrings after sorting:\n");
    insert_sort(list, argc);
    for (int i = 1; i < argc; i++) {
        printf("%s %d\n", list[i].string, list[i].len);
    }
    return 0;
}