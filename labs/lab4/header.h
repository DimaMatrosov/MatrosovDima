#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct TREE{
    char *data;
    struct TREE *yes;
    struct TREE *no;
} TREE;

TREE *createTree(const char *data);

TREE *readTree(FILE *fp);

void movingTree(TREE* tree);

TREE *addTree(char *data);

void saveTree(TREE* tree, FILE *fp);
void freeTree(TREE* node);
