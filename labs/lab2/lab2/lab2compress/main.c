#include "hed.h"

int main() {
    setlocale(LC_ALL,"Rus");
    char file[] = "C:\\labsnew\\labs\\lab2\\files\\text.txt";
    char f[] = "C:\\labsnew\\labs\\lab2\\files\\compressed.txt";
    char f1[] = "C:\\labsnew\\labs\\lab2\\files\\data.txt";
    compress(file, f, f1);
    return 0;
}