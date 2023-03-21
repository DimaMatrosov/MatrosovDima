#include "hed.h"

int main() {
    setlocale(LC_ALL,"Rus");
    char file[] = "C:\\labsnew\\labs\\lab2\\files\\text.txt";
    char comp[] = "C:\\labsnew\\labs\\lab2\\files\\compressed.txt";
    char f1[] = "C:\\labsnew\\labs\\lab2\\files\\data.txt";
    fclose(fopen(f1, "wb"));
    compress(file, comp, f1);
    return 0;
}