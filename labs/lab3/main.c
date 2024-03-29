#include "hed.h"

int main() {

    char fileName[MAGIC];
    Header header;
    InfoHeader infoHeader;
    printf("file name:");
    scanf_s("%s", fileName);
    FILE* BMP;
    fopen_s(&BMP, fileName, "rb");
    if (!BMP) {
        printf("Wrong open\n");
        exit(1);
    }
    fread(&header.type, sizeof(header.type), 1, BMP);
    fread(&header.size, sizeof(header.size), 1, BMP);
    fread(&header.reserved1, sizeof(header.reserved1), 1, BMP);
    fread(&header.reserved2, sizeof(header.reserved2), 1, BMP);
    fread(&header.offset, sizeof(header.offset), 1, BMP);
    fread(&infoHeader, sizeof(InfoHeader), 1, BMP);
    check(header,infoHeader);

    int rowSize = ((infoHeader.width * infoHeader.bitsPerPixel + 31) / 32) * 4;
    int imageSize = rowSize * infoHeader.height;
    unsigned char* imageData = (unsigned char*) malloc(imageSize * sizeof(unsigned char));
    fread(imageData, sizeof(unsigned char), imageSize, BMP);
    fclose(BMP);
    menu(imageData, imageSize, BMP, infoHeader, header);
    return 0;
}