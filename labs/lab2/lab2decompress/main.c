#include "hed.h"

int main() {
    setlocale(LC_ALL,"Rus");
    char comp[] = "C:\\labsnew\\labs\\lab2\\files\\compressed.txt";
    char decomp[] = "C:\\labsnew\\labs\\lab2\\files\\decompressed.txt";
    char data[] = "C:\\labsnew\\labs\\lab2\\files\\data.txt";
    decompress(comp, decomp, data);
    return 0;
}