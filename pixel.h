#ifndef PIXEL_H
#define PIXEL_H

typedef struct Pixel
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
}Pixel;

/* Get pixel value from canal (rgb)*/
char GetPixelValue(Pixel * pixel, char canal);

/* Set pixel canal value (rgb)*/
void SetPixelValue(Pixel *pixel, char canal, char value);

void SetPixelsValue(Pixel * pixel, char r, char g, char b);

#endif