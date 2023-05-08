#include "header.h"

int main(){
    printf("choose a Naruto character\n");
    FILE *fp = fopen("tree.txt", "r");

    TREE* tree = readTree(fp);
    fclose(fp);

    movingTree(tree);
    fp = fopen("tree.txt", "w");
    saveTree(tree, fp);
    fclose(fp);
    freeTree(tree);
}