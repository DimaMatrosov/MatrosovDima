#include "hed.h"

int main() {
    setlocale(LC_ALL,"Rus");
    char file[] = "../lab2/files/text.txt";
    decompress(file);
    return 0;
}