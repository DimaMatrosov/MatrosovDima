#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
typedef struct Node {
    char *word;
    int count;
    int len;
    int used;
    struct Node *next;
} Node;

typedef struct {
    int len;
    char **str;
} string;

void merge(Node *a, Node *b, Node **c);

void split_linked_list(Node *src, Node **low, Node **high);

void mergeSort(Node **head);

string *split(char *input, char *delimiter);

void swap_words(string *text, char *word1, char *word2);

char *multi_tok(char *input, char *delimiter);

char *file_read(char file[]);

void decompress( char comp[], char decomp[], char data[]);