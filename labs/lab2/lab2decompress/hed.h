#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    int len;
    char **str;
} string;

string *split(char *input, char *delimiter);

void swap_words(string *text, char *word1, char *word2);

char *multi_tok(char *input, char *delimiter);

char *file_read(char file[]);

void decompress( char comp[], char decomp[], char data[]);