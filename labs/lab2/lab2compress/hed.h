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

Node *getLast(Node *head);

typedef struct {
    int len;
    char **str;
} string;

void pushBack(Node **head, char *word, int count);

void merge(Node *a, Node *b, Node **c);

void split_linked_list(Node *src, Node **low, Node **high);

void mergeSort(Node **head);

string *split(char *input, char *delimiter);

void swap_words(string *text, char *word1, char *word2);

char *multi_tok(char *input, char *delimiter);

char *file_read(char path[]);

int check(Node *head, char *word);

int count_profit(Node *a, Node *b);

void mark_used(Node *head, char *word);

void replace_words(Node *head, string *split_text, char *file);

void count_repeats(string *split_text, Node **head);

void compress(char file[], char f[], char f1[]);

void decompress(char file[]);