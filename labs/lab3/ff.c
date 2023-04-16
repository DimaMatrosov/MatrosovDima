#include "hed.h"

void check(BMPHeader header,BMPInfoHeader infoHeader) {
    if (header.type[0] != 'B' || header.type[1] != 'M') {
        printf("File is not BMP.\n");
    }
    if (infoHeader.bitsPerPixel != 24) {
        printf("Image must be 24 bits per pixel.\n");
    }
}

void menu(unsigned char* imageData,int imageSize, FILE* BMP, BMPInfoHeader infoHeader, BMPHeader header) {
        int choice = 0;
        printf("choose the option:\n");
        printf("1. Convert to negative.\n");
        printf("2. Convert to Black and Gray.\n");
        scanf_s("%d", &choice);
        if (choice == 1) {
            unsigned char *negativeImageData = (unsigned char *) malloc(sizeof(unsigned char) * imageSize);
            memcpy(negativeImageData, imageData, sizeof(unsigned char) * imageSize);
            BmpToNegative(negativeImageData, imageSize);
            char outFilename[100] = "negative.bmp";
            BMP = fopen(outFilename, "wb");
            WriteInBMP(header, infoHeader, BMP, negativeImageData, imageSize);
            printf("Image saved as %s\n", outFilename);
            free(negativeImageData);
        }
         if (choice == 2) {
            unsigned char *grayImageData = (unsigned char *) malloc(sizeof(unsigned char) * imageSize);
            memcpy(grayImageData, imageData, sizeof(unsigned char) * imageSize);
            BmpToGrayBlack(grayImageData, imageSize);
            char outFilename[100] = "blackGray.bmp";
            BMP = fopen(outFilename, "wb");
            WriteInBMP(header, infoHeader, BMP, grayImageData, imageSize);
            printf("Image saved as %s\n", outFilename);
            free(grayImageData);
        }
        fclose(BMP);
        free(imageData);
}

void WriteInBMP(BMPHeader header, BMPInfoHeader infoHeader, FILE* BMP, unsigned char *imageData, int imageSize) {
    if (BMP == NULL) {
        printf("Error: BMP file pointer is NULL.\n");
        return;
    }
    fwrite(&header.type, sizeof(header.type), 1, BMP);
    fwrite(&header.size, sizeof(header.size), 1, BMP);
    fwrite(&header.reserved1, sizeof(header.reserved1), 1, BMP);
    fwrite(&header.reserved2, sizeof(header.reserved2), 1, BMP);
    fwrite(&header.offset, sizeof(header.offset), 1, BMP);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, BMP);
    fwrite(imageData, sizeof(unsigned char), imageSize, BMP);
}

/*void BmpToNegative(unsigned char *imageData, int imageSize) {
    for (int i = 0; i < imageSize; i += 3) {
        imageData[i] = 255 - imageData[i];
        imageData[i + 1] = 255 - imageData[i + 1];
        imageData[i + 2] = 255 - imageData[i + 2];
    }
}*/
void BmpToNegative(unsigned char *imageData, int imageSize) {
    for (int i = 0; i < imageSize; i++)
        imageData[i] = 255 - imageData[i];
}

void BmpToGrayBlack(unsigned char *imageData, int imageSize) {
    for (int i = 0; i < imageSize; i += 3) {
        //unsigned char gray = (unsigned char)((float)imageData[i] * 0.11 + (float)imageData[i + 1] * 0.59 + (float)imageData[i + 2] * 0.3);
        unsigned char gray = (unsigned char) ((float) imageData[i] * 0.3 + (float) imageData[i + 1] * 0.5 + (float) imageData[i + 2] * 0.1);
        imageData[i] = gray;//r
        imageData[i + 1] = gray;//g
        imageData[i + 2] = gray;//b
    }
}

void ifFile(FILE* BMP){
    if (!BMP) {
        printf("Wrong open\n");
        exit(1);
    }
}
