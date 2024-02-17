#include "picture.h"
#include "pixel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Allocation correcte d'une Picture en mémoire*/
Picture * InitPicture(unsigned x, unsigned y)
{
    Picture * picture = malloc(sizeof(Picture));
    Pixel * pixel = (Pixel *)malloc(sizeof(Pixel) * x * y);
    if(pixel == NULL)
    {
        printf("ERREUR Allocatoin Memoire Pixel\n");
        free(picture);
        exit(EXIT_FAILURE);
    }
    picture->hight = y;
    picture->width = x;
    picture->pixel = pixel;
    return picture;
}

/* Supprime correctement l'Picture*/
void FreePicture(Picture ** picture)
{
    free((*picture)->pixel);
    free(*picture);
    *picture = NULL;
}
/* get width of a picture*/
unsigned GetPictureWidth(Picture * picture)
{
    return picture->width;
}

/* get hight of a picture*/
unsigned GetPictureHight(Picture * picture)
{
    return picture->hight;
}




/* Sortie de l'Picture en forat portable bitmap*/
void WritePicture(Picture * picture, char ** name)
{
    FILE * fout;
    char * fileName = malloc(sizeof(char) * (strlen(*name) + 5));
    strcpy(fileName, *name);
    strcat(fileName, ".pbm\0");

    fout = fopen(fileName, "w");

    unsigned hight = GetPictureHight(picture);
    unsigned width = GetPictureWidth(picture);

    fprintf(fout, "P3\n%u %u\n255\n", width, hight);


    
    for (unsigned j = 0; j < hight; j++)
    {
        for (unsigned i = 0; i < width; i++)
        {
            fprintf(fout, "%hhu %hhu %hhu\n",GetPicturePixelValue(picture, i, j, 'r'),
            GetPicturePixelValue(picture, i, j, 'g'),
            GetPicturePixelValue(picture, i, j, 'b'));
            
        }
        
    }
    fclose(fout);
    free(fileName);
}

char GetPicturePixelValue(Picture * picture, unsigned x, unsigned y, char canal)
{
    unsigned width = GetPictureWidth(picture);
    Pixel * pixel = &(picture->pixel[x + (width * y)]);
    return GetPixelValue(pixel, canal);
}

void SetPicturePixelValue(Picture * picture, unsigned x, unsigned y, char canal, char value)
{
    unsigned width = GetPictureWidth(picture);
    Pixel * pixel = &(picture->pixel[x + (width * y)]);
    SetPixelValue(pixel, canal, value);
}

