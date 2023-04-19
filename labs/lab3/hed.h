#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAGIC 100

typedef struct {
    unsigned char type[2];
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset;
} Header;

typedef struct {
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bitsPerPixel;
    unsigned int compression;
    unsigned int imageSize;
    int xPixelsPerMeter;//по горизонтали
    int yPixelsPerMeter;//по вертикали
    unsigned int colorsUsed;
    unsigned int importantColors;
} InfoHeader;

void menu(unsigned char* imageData,int imageSize, FILE* BMP, InfoHeader infoHeader, Header header);
void check(Header header, InfoHeader infoHeader);
void GrayBlack(unsigned char *imageData, int imageSize);
void Negative(unsigned char *imageData, int imageSize);
void WriteIn(Header header, InfoHeader infoHeader, FILE* BMP, const unsigned char *imageData, int imageSize);
void gammaParam(double* gamma, char* string, double low, double high);
void gammaCorrection(unsigned char* imageData, int imageSize, double gamma);
void medianFilter(unsigned char *imageData, InfoHeader *infoHeader);
void cycles(int x, int y, const InfoHeader* infoHeader, unsigned char* imageData, const unsigned char* buffer);