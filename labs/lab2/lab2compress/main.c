#include "hed.h"

int main() {
    setlocale(LC_ALL,"Rus");
    char file[] = "C:\\labsnew\\labs\\lab2\\files\\text.txt";
    char comp[] = "C:\\labsnew\\labs\\lab2\\files\\compressed.txt";
    char data[] = "C:\\labsnew\\labs\\lab2\\files\\data.txt";
    compress(file, comp, data);
    return 0;
}