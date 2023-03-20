#include "hed.h"

void decompress(char file[], char f[], char f1[]) {
    char *text = file_read(f);
    if (text == NULL)
        exit(0);
    string *compressed_text = split(text, " ");

    FILE *fp = fopen(f, "rb");
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    printf("Size: %d\n", size);

    char *data_name = calloc(strlen(file) + 10, sizeof(char));
    strcat(strcat(data_name, file), ".data");
    text = file_read(data_name);
    if (text == NULL)
        exit(0);
    string *compressed_data = split(text, "\n");

    fp = fopen(data_name, "rb");
    fseek(fp, 0, SEEK_END);
    int data_size = ftell(fp);
    printf("Data size: %d\n", data_size);
    printf("Total size: %d\n", size + data_size);

    for (int i = 0; i < compressed_data->len; i++) {
        string *words = split(compressed_data->str[i], " ");
        if (words->len != 2) continue;
        swap_words(compressed_text, words->str[0], words->str[1]);
    }

    char *decompressed_name = calloc(strlen(file) + 10, sizeof(char));
    strcat(strcat(decompressed_name, file), ".decompressed");

    fclose(fopen(f1, "w"));

    fp = fopen(f1, "ab");
    if (fp == NULL)
        exit(0);

    for (int i = 0; i < compressed_text->len; i++) {
        fputs(compressed_text->str[i], fp);
        if (i != compressed_text->len - 1) fputs(" ", fp);
    }
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fclose(fp);

    printf("New size: %d\n", size);
    printf("File decompressed!\n");
}
