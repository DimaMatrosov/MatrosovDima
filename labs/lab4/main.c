#include "header.h"

int main(){
    printf("Choose a Naruto character\n");
    FILE *fp;
    fopen_s(&fp, "tree.txt", "r");
    if (!fp) {
        printf("Wrong open\n");
        exit(1);
    }
    TREE* tree = readTree(fp);
    fclose(fp);

    movingTree(tree);
    fopen_s(&fp, "tree.txt", "w");
    if (!fp) {
        printf("Wrong open\n");
        exit(1);
    }
    saveTree(tree, fp);
    fclose(fp);
    freeTree(tree);
    return 0;
}