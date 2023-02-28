#include "ff.h"
int main(int argc, char *argv[]) {
    int *len;
    argc_text(argc);
    char *list = calloc(argc - 1, sizeof(char));

    for (int i = 1; i < argc; i++) {
        len[i] = str_len(argv[i]);
        list[i] = calloc(len[i], sizeof(char));
        list[i]= argv[i];

    }
    printf("Strings from args and their length:\n");
    for (int i = 1; i < argc; i++) {
        printf("%s %d\n", &list[i], len[i]);
    }
    printf("\nStrings after sorting:\n");
    insert_sort(list, &argc);
    for (int i = 1; i < argc; i++) {
        printf("%s %d\n", &list[i], len[i]);
    }
    return 0;
}