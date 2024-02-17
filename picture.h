#include "pixel.h"

typedef struct Picture
{
    int hight;
    int width;
    struct Pixel * pixel;

}Picture;

char GetPicturePixelValue(Picture * picture ,unsigned x, unsigned y, char canal);

void SetPicturePixelValue(Picture * picture ,unsigned x, unsigned y, char canal, char value);

Picture * InitPicture(unsigned x, unsigned y);

void FreePicture(Picture ** picture);

void WritePicture(Picture * picture, char ** name);

unsigned GetPictureWidth(Picture * picture);

unsigned GetPictureHight(Picture * picture);

