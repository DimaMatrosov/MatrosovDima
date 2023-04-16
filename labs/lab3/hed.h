#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    unsigned char type[2];
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset;
} BMPHeader;

typedef struct {
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bitsPerPixel;
    unsigned int compression;
    unsigned int imageSize;
    int xPixelsPerMeter;
    int yPixelsPerMeter;
    unsigned int colorsUsed;
    unsigned int importantColors;
} BMPInfoHeader;

void menu(unsigned char* imageData,int imageSize, FILE* BMP, BMPInfoHeader infoHeader, BMPHeader header);
void check(BMPHeader header,BMPInfoHeader infoHeader);
void BmpToGrayBlack(unsigned char *imageData, int imageSize);
void BmpToNegative(unsigned char *imageData, int imageSize);
void WriteInBMP(BMPHeader header, BMPInfoHeader infoHeader, FILE* BMP, unsigned char *imageData, int imageSize);
void ifFile(FILE* BMP);