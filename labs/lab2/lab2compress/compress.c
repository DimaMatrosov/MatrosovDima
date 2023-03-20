#include "hed.h"

void compress(char file[], char f[],char f1[]) {

    char *text = file_read(file);
    if (text == NULL)
        exit(0);

    FILE *fp = fopen(file, "rb");
    fseek(fp, 0 , SEEK_END);
    int size = ftell(fp);
    printf("Size: %d\n", size);

    string *split_text = split(text, " ");

    Node *head = NULL;
    count_repeats(split_text, &head);

    replace_words(head, split_text, file);

    //char *f2 = calloc(strlen(file) + 10, sizeof(char));
    //strcat(strcat(compressed_name, file), ".compressed");
    /*strcat(compressed_name, file);
    strcat(compressed_name, "compressed");*/
    //FILE *f2 = fopen(f, "rb");
    fclose(fopen(f, "w"));
    fp = fopen(f, "ab");
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

    char *data_name = calloc(strlen(file) + 10, sizeof(char));
    strcat(strcat(data_name, file), ".data");

    fp = fopen(data_name, "rb");
    fseek(fp, 0L, SEEK_END);
    int data_size = ftell(fp);
    printf("Data size: %d\n", data_size);
    printf("Total size: %d\n", size + data_size);
    printf("File compressed!\n");
}