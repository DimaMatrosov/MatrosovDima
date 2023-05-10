#include "header.h"

int main(){
    printf("Choose a Naruto character\n");
    FILE *fp = fopen("tree.txt", "r");

    TREE* tree = readTree(fp);
    fclose(fp);

    movingTree(tree);
    fp = fopen("tree.txt", "w");
    saveTree(tree, fp);
    fclose(fp);
    freeTree(tree);
    return 0;
}