#include "pixel.h"
#include <stdio.h>
#include <stdlib.h>

char GetPixelValue(Pixel *pixel, char canal)
{
    unsigned value = 0;
    switch (canal)
    {
    case 'r':
        value = pixel->red;
        break;
    case 'g':
        value = pixel->green;
        break;
    case 'b':
        value = pixel->blue;
        break;

    default:
        printf("ERREUR color not defined");
        exit(EXIT_FAILURE);
    }
    return value;
}

void SetPixelValue(Pixel *pixel, char canal, char value)
{
    switch (canal)
    {
    case 'r':
        pixel->red = value;
        break;
    case 'g':
        pixel->green = value;
        break;
    case 'b':
        pixel->blue = value;
        break;

    default:
        printf("ERROR color not defined");
        exit(EXIT_FAILURE);
    }
}

void SetPixelsValue(Pixel * pixel, char r, char g, char b)
{
    pixel->red = r;
    pixel->green = g;
    pixel->blue = b;
}