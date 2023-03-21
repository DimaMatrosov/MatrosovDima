#include "hed.h"

void decompress(char comp[], char decomp[], char data[]) {
    char *text = file_read(comp);
    if (text == NULL)
        exit(0);
    string *compressed_text = split(text, " ");

    FILE *fp = fopen(comp, "rb");
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    printf("Size: %d\n", size);
    text = file_read(data);
    if (text == NULL)
        exit(0);
    string *compressed_data = split(text, "\n");
    fp = fopen(data, "rb");
    fseek(fp, 0, SEEK_END);
    int data_size = ftell(fp);
    printf("Data size: %d\n", data_size);
    printf("Total size: %d\n", size + data_size);

    for (int i = 0; i < compressed_data->len; i++) {
        string *words = split(compressed_data->str[i], " ");
        if (words->len != 2)
            continue;

        swap_words(compressed_text, words->str[0], words->str[1]);
    }
    fclose(fopen(decomp, "w"));
    fp = fopen(decomp, "ab");
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
