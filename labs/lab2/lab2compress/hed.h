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
} str;

void push_back(Node **head, char *word, int count);

void merge(Node *a, Node *b, Node **c);

void split_linked_list(Node *src, Node **low, Node **high);

void merge_sort(Node **head);

str *split(char *input, char *delimiter);

void swap_words(str *text, char *word1, char *word2);

char *multi_tok(char *input, char *delimiter);

char *file_read(char path[]);

int check(Node *head, char *word);

int count_profit(Node *a, Node *b);

void mark_used(Node *head, char *word);

void replace_words(Node *head, str *split_text, char data[]);

void count_repeats(str *split_text, Node **head);

void compress(char file[], char comp[], char data[]);
