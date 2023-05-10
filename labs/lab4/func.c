#include "header.h"

TREE *createTree(const char *data) {
    TREE *tree = malloc(sizeof(TREE));
    tree->data = strdup(data);
    tree->yes = NULL;
    tree->no = NULL;
    return tree;
}

TREE *readTree(FILE *fp) {
    char data[255];
    fgets(data, sizeof(data), fp);
    data[strlen(data)-1] = '\0';
    if (data[0] == '-')
        return NULL;
    TREE *tree = createTree(data);
    tree->yes = readTree(fp);
    tree->no = readTree(fp);
    return tree;
}

void movingTree(TREE *tree) {
    printf("%s", tree->data);
    char s1;
    scanf_s("%c", &s1);
    rewind(stdin);
    if (s1 == 'y') {
        if (tree->yes == NULL) {
            printf("end");
            return;
        }
        tree = tree->yes;
    }
    else if (s1 == 'n') {
        if (tree->no == NULL) {
            TREE *newTREE = addTree(tree->data);
            memcpy(tree, newTREE, sizeof(TREE));
            if (newTREE != NULL) {
                free(newTREE);
            }
            return;
        }
        tree = tree->no;
    }
    movingTree(tree);
}

TREE *addTree(const char *data) {
    char object[255];
    printf("Who is that?");
    scanf_s("%s",object);
    char question[255];
    printf("distinctive question ");
    scanf_s("%s",question);
    //gets(question);
    TREE *tree = createTree(question);
    tree->yes = createTree(object);
    tree->no = createTree(data);
    return tree;
}

void saveTree(TREE* tree, FILE *fp){
    if (tree == NULL){
        fputs("-\n", fp);
        return;
    }
    fputs(tree->data, fp);
    fputs("\n", fp);
    saveTree(tree->yes, fp);
    saveTree(tree->no, fp);
}

void freeTree(TREE* node){
    if(node == NULL){
        return;
    }
    freeTree(node->no);
    freeTree(node->yes);
    free(node->data);
    free(node);
}