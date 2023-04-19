#include "hed.h"


void check(Header header,InfoHeader infoHeader) {
    if (header.type[0] != 'B' || header.type[1] != 'M') {
        printf("File is not BMP.\n");
    }
    if (infoHeader.bitsPerPixel != 24) {
        printf("Image must be 24 bits per pixel.\n");
    }
}

void menu(unsigned char* imageData,int imageSize, FILE* BMP, InfoHeader infoHeader, Header header) {
        int choice = 0;
        printf("choose the option:\n");
        printf("1. negative\n");
        printf("2. Black and Gray\n");
        printf("3. gamma correction\n");
        printf("4. median filter\n");
        scanf_s("%d", &choice);
        if (choice == 1) {
            unsigned char *negativeImageData = (unsigned char *) malloc(sizeof(unsigned char) * imageSize);
            memcpy(negativeImageData, imageData, sizeof(unsigned char) * imageSize);
            Negative(negativeImageData, imageSize);
            char outFilename[MAGIC] = "negative.bmp";
            fopen_s(&BMP, outFilename, "wb");
            if (!BMP) {
                printf("Wrong open\n");
                exit(1);
            }
            WriteIn(header, infoHeader, BMP, negativeImageData, imageSize);
            printf("Image saved as %s\n", outFilename);
            free(negativeImageData);
            fclose(BMP);
        }
         if (choice == 2) {
            unsigned char *grayImageData = (unsigned char *) malloc(sizeof(unsigned char) * imageSize);
            memcpy(grayImageData, imageData, sizeof(unsigned char) * imageSize);
            GrayBlack(grayImageData, imageSize);
            char outFilename[MAGIC] = "blackGray.bmp";
            fopen_s(&BMP, outFilename, "wb");
             if (!BMP) {
                 printf("Wrong open\n");
                 exit(1);
             }
            WriteIn(header, infoHeader, BMP, grayImageData, imageSize);
            printf("Image saved as %s\n", outFilename);
            free(grayImageData);
            fclose(BMP);
         }
         if (choice == 3) {
             double gamma;
             gammaParam(&gamma, "choose the value of gamma parameter (from 0.5 to 2.2): \0", 0.5, 2.2);

             unsigned char *gammaCorrectionBMP = (unsigned char *) malloc(sizeof(unsigned char) * imageSize);
             memcpy(gammaCorrectionBMP, imageData, sizeof(unsigned char) * imageSize);

             gammaCorrection(gammaCorrectionBMP, imageSize, gamma);

             char outFilename[MAGIC] = "gammaCorrected.bmp";
             fopen_s(&BMP ,outFilename, "wb");

             WriteIn(header, infoHeader, BMP, gammaCorrectionBMP, imageSize);

             printf("Image saved as %s\n", outFilename);
             fclose(BMP);
             free(gammaCorrectionBMP);
         }
         if (choice == 4) {
             unsigned char* medianFiltered = (unsigned char*) malloc(sizeof (unsigned char) * imageSize);
             memcpy(medianFiltered, imageData, sizeof (unsigned char) * imageSize);
             medianFilter(medianFiltered, &infoHeader);
             char outFilename[100] = "medianFiltered.bmp";
             fopen_s(&BMP ,outFilename, "wb");
             WriteIn(header, infoHeader, BMP, medianFiltered, imageSize);
             printf("Image saved as %s\n", outFilename);
             fclose(BMP);
             free(medianFiltered);
         }
        free(imageData);
}

void WriteIn( Header header, InfoHeader infoHeader, FILE* BMP, const unsigned char *imageData, int imageSize) {
    if (BMP == NULL) {
        printf("Error: BMP file pointer is NULL.\n");
        return;
    }
    fwrite(&header.type, sizeof(header.type), 1, BMP);
    fwrite(&header.size, sizeof(header.size), 1, BMP);
    fwrite(&header.reserved1, sizeof(header.reserved1), 1, BMP);
    fwrite(&header.reserved2, sizeof(header.reserved2), 1, BMP);
    fwrite(&header.offset, sizeof(header.offset), 1, BMP);
    fwrite(&infoHeader, sizeof(InfoHeader), 1, BMP);
    fwrite(imageData, sizeof(unsigned char), imageSize, BMP);
}

void Negative(unsigned char *imageData, int imageSize) {
    for (int i = 0; i < imageSize; i++)
        imageData[i] = 255 - imageData[i];
}

void GrayBlack(unsigned char *imageData, int imageSize) {
    for (int i = 0; i < imageSize; i += 3) {
        //unsigned char gray = (imageData[i] + imageData[i + 1] + imageData[i + 2]) / 3;
        unsigned char gray = (unsigned char) ((float) imageData[i] * 0.3 + (float) imageData[i + 1] * 0.5 + (float) imageData[i + 2] * 0.1);
        imageData[i] = gray;//r
        imageData[i + 1] = gray;//g
        imageData[i + 2] = gray;//b
    }
}

void gammaParam(double* gamma, char* string, double low, double high){

    printf("%s", string);
    while(scanf_s("%lf", gamma)!= 1 || *gamma < low || *gamma > high){
        printf("error, incorrect input of parameter.");
        rewind(stdin);
        printf("%s", string);
    }
}

void medianFilter(unsigned char *imageData, InfoHeader *infoHeader) {

    int width = infoHeader->width;
    int height = infoHeader->height;
    int bytesPerPixel = infoHeader->bitsPerPixel / 8;

    unsigned char *buffer = (unsigned char *) malloc(sizeof(unsigned char) * width * height * bytesPerPixel);
    memcpy(buffer, imageData, sizeof(unsigned char) * width * height * bytesPerPixel);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cycles(x, y, infoHeader, imageData, buffer);
        }
    }
    free(buffer);
}

void cycles(int x, int y, const InfoHeader* infoHeader, unsigned char* imageData, const unsigned char* buffer){

    int width = infoHeader->width;
    int height = infoHeader->height;
    int bytesPerPixel = infoHeader->bitsPerPixel / 8;

    int sumRed = 0;
    int sumGreen = 0;
    int sumBlue = 0;
    int count = 0;

    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            int yy = y + dy;
            int xx = x + dx;
            if (yy >= 0 && yy < height && xx >= 0 && xx < width) {
                int index = ((yy * width) + xx) * bytesPerPixel;
                sumRed += buffer[index];
                sumGreen += buffer[index + 1];
                sumBlue += buffer[index + 2];
                count++;
            }
        }
    }
    int index = ((y * width) + x) * bytesPerPixel;
    imageData[index] = (unsigned char)(sumRed / count);
    imageData[index + 1] = (unsigned char)(sumGreen / count);
    imageData[index + 2] = (unsigned char)(sumBlue / count);
}

void gammaCorrection(unsigned char* imageData, int imageSize, double gamma){
    for(int i = 0; i < imageSize; i++){
        imageData[i] = (unsigned char)(255 * pow(imageData[i] / 255.0, gamma));
    }
}