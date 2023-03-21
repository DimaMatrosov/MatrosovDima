#include "hed.h"

void compress(char file[], char comp[],char data[]) {

    char *text = file_read(file);
    if (text == NULL)
        exit(0);

    FILE *fp = fopen(file, "rb");
    fseek(fp, 0 , SEEK_END);
    int size = ftell(fp);
    printf("Size: %d\n", size);

    str *split_text = split(text, " ");

    Node *head = NULL;
    count_repeats(split_text, &head);
    fclose(fopen(data, "w"));
    replace_words(head, split_text, data);

    fclose(fopen(comp, "w"));
    fp = fopen(comp, "ab");
    if (fp == NULL)
        exit(0);
    for (int i = 0; i < split_text->len; i++) {
        fputs(split_text->str[i], fp);
        if (i != split_text->len - 1)
            fputs(" ", fp);
    }
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    printf("New size: %d\n", size);
    fclose(fp);
    fp = fopen(data, "rb");
    fseek(fp, 0, SEEK_END);
    int data_size = ftell(fp);
    fclose(fp);
    printf("Data size: %d\n", data_size);
    printf("Total size: %d\n", size + data_size);
    printf("File compressed!\n");
}